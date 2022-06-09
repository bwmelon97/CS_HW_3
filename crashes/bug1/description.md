fuzzer_load_png에서 발견

```c
// pngparser.c:230
int read_png_chunk(FILE *file, struct png_chunk *chunk) {
  chunk->chunk_data = NULL;

  if (fread(chunk, sizeof(int32_t), 2, file) != 2) {
    goto error;
  }

  chunk->length = to_little_endian(chunk->length);

  if (chunk->length) {
    /* bug: out-of-memory */
    chunk->chunk_data = malloc(chunk->length);
    if (!chunk->chunk_data)
      goto error;

    if (fread(chunk->chunk_data, chunk->length, 1, file) != 1) {
      goto error;
    }
  }
```