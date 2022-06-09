#### Name

heap-buffer-overflow

#### Description

The function `fopen` needs the first parameter as a valid `char*`, especially which follows the Linux file name restriction. However, the input `filename` can be any Byte array, so it should be checked if it is valid file name input, before calling the function `fopen`. 

#### Affected Lines

In `pngparser.c:546`

```c
FILE *input = fopen(filename, "rb");
```



#### Expected vs Observed

I observed a heap-buffer-overflow error when I gave the data of `pop_00.bin` to `load_png` as a `filename` parameter.

#### Steps to Reproduce

##### Command

```
./fuzzer_load_png_name ./poc_00.bin
```

##### Proof-of-Concept Input (if needed)

Attach `poc_00.bin` in the same directory with `fuzzer_load_png_name`.

#### Suggested Fix Description

Before calling the function `fopen` with the variable `filename`, check `filename` is following the Linux file name restriction. And if it doesn't follow the restriction, raise an error.

```c
// Add stdbool header file at the head of file.
#include <stdbool.h>

// pngparser.c:548
FILE *input = NULL;
int i = 0;
while(filename[i] != '\0') {
  /* if filename is not followed linux file name restriction,
   * raise an error.
   * ref: https://www.cyberciti.biz/faq/linuxunix-rules-for-naming-file-and-directory-names/
   */

  bool file_name_rule =
    filename[i] > 0x30 && filename[i] < 0x39 ||   // 숫자
    filename[i] > 0x41 && filename[i] < 0x5A ||   // 대문자
    filename[i] > 0x61 && filename[i] < 0x7A ||   // 소문자
    filename[i] == 0x2E                      ||   // . (dot)
    filename[i] == 0x5F;                          // _ (underbar)

  if ( !file_name_rule ) {
    goto error;
  }

  i += 1;
}
if (i == 0 || i > 255) {
  /* if filename length is 0 or larger than 255, goto error */
  goto error;
}
input = fopen(filename, "rb");

/////////////////////////////////////////////

// Add condition that checks 'input is defined' before call fclose in error block.
error:
  if (input) {
    fclose(input);
  }
```

