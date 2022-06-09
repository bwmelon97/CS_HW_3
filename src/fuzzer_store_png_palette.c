#include "pngparser.h"
#include <stdio.h>

// LibFuzzer stub
//
int LLVMFuzzerTestOneInput(const uint8_t *Data, size_t Size) {
    // plte_chunk is 4 byte length
    if (Size <= 0 || Size % 4 != 0) {
        return 0;
    }
    
    struct image *test_img = NULL;
    store_png("out.png", &test_img, Data, (Size / 4));
    free(test_img);

    // Always return 0
    return 0;
}
