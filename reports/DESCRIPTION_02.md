#### Name

heap-buffer-overflow

#### Description

```c
// Line 431
img->px = malloc(sizeof(struct pixel) * img->size_x * img->size_y);

// Line 452
img->px[idy * img->size_x + idx].green = inflated_buf[g_idx];

```

The allocated memory address by `malloc` in Line 431 is written by the statement of Line 452. It makes a 'heap-buffer-overflow' error.



#### Affected Lines

In `pngparser.c:667`, `pngparser.c:517`, `pngparser.c:501`, `pngparser.c:488`, `pngparser.c:452`

```c
// Line 667
*img = parse_png(ihdr_chunk, plte_chunk, inflated_buf, inflated_size);

// Line 517
return parse_png_no_interlace(ihdr_chunk, plte_chunk, inflated_buf,
                              inflated_size);

// Line 501
return convert_data_to_image(ihdr_chunk, plte_chunk, inflated_buf,
                             inflated_size);

// Line 488
return convert_rgb_alpha_to_image(ihdr_chunk, inflated_buf, inflated_size);

// Line 452 -> Heap buffer overflow occur !!
img->px[idy * img->size_x + idx].green = inflated_buf[g_idx];
```



#### Expected vs Observed

I observed a heap-buffer-overflow error when I create a png file with the data of `pop_02.bin` and call `load_png` with that png file.

#### Steps to Reproduce

##### Command

```bash
./fuzzer_load_png ./poc_02.bin
```

##### Proof-of-Concept Input (if needed)

Attach `poc_02.bin` in the same directory with `fuzzer_load_png`.

#### Suggested Fix Description

