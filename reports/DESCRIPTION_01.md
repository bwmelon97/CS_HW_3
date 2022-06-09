#### Name

READ memory address 0X00000000 (Null)

#### Description

```c
// Line 999
FILE *output = fopen(filename, "wb");
```

The function `fopen` might return the NULL value. In that case, this NULL value is used as a memory address in the remaining part of the function `store_png`. So we should check if the pointer `output` is NULL, and if it is NULL, the function `store_png` should return.

#### Affected Lines

In `pngparser.c:1001` and `pngparser.c:717`

```c
// Line 1001
store_filesig(output);

// Line 717
return fwrite("\211PNG\r\n\032\n", 8, 1, output) != 1;
```

#### Expected vs Observed

I observed the log  `AddressSanitizer: SEGV on unknown address 0x000000000000` when I gave the data of `pop_01.bin` to `store_png` as a `filename` parameter.

#### Steps to Reproduce

##### Command

```
./fuzzer_store_png_name ./poc_01.bin
```

##### Proof-of-Concept Input (if needed)

Attach `poc_01.bin` in the same directory with `fuzzer_store_png_name`.

#### Suggested Fix Description

Check if the `output` is not NULL, which is the return value of function `fopen`. And if it is NULL, return the value 1 so that the remaining part of the function does not execute.

```c
int store_png(const char *filename, struct image *img, struct pixel *palette,
              uint8_t palette_length) {
  int result = 0;
  FILE *output = fopen(filename, "wb");
  /* check if output is null */
  if(!output) {
    return 1;
  }
  store_filesig(output); 
  ...
}
```

