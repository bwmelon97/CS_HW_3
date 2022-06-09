#include "pngparser.h"
#include <stdio.h>

// LibFuzzer stub
//
int LLVMFuzzerTestOneInput(const uint8_t *Data, size_t Size) {
    
    /* if Data is not finished with '\0', it is invaild string */
    if (Size == 0 || Data[Size - 1] != '\0') {
        return 0;
    }
    
    struct image *img = NULL;

    if (store_png(Data, &img, NULL, 0) == 0) {
        free(img);
    }

    // Always return 0
    return 0;
}
