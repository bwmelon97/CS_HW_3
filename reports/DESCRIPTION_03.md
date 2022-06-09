#### Name

access NULL pointer 

#### Description

```c
struct image *convert_color_palette_to_image(png_chunk_ihdr *ihdr_chunk,
                                             png_chunk_plte *plte_chunk,
                                             uint8_t *inflated_buf,
                                             uint32_t inflated_size) { }
```

When the function `convert_color_palette_to_image` receieves `plte_chunk` as NULL, `AddressSanitizer: SEGV on unknown address 0x000000000008` error occurs at the line 385.

#### Affected Lines

In `pngparser.c:667`, `pngparser.c:501`, `pngparser.c:485`, `pngparser.c:385`

```c
// Line 385: plte_chunk is NULL !!
struct plte_entry *plte_entries = (struct plte_entry *)plte_chunk->chunk_data;

// Line 485
return convert_color_palette_to_image(ihdr_chunk, plte_chunk, inflated_buf,
                                      inflated_size);

// Line 501
return convert_data_to_image(ihdr_chunk, plte_chunk, inflated_buf,
                             inflated_size);

// Line 667
*img = parse_png(ihdr_chunk, plte_chunk, inflated_buf, inflated_size);
```

#### Expected vs Observed

I observed a NULL pointer access error when I created a test image with the data of `poc_03.bin` and stored the test image using the `store_png` function.

#### Steps to Reproduce

##### Command

```
./fuzzer_store_png_rgba ./poc_03.bin
```

##### Proof-of-Concept Input (if needed)

Attach `poc_03.bin` in the same directory with `fuzzer_store_png_rgba`.

#### Suggested Fix Description

