fuzzer_load_png

convert_rgb_alpha_to_image /home/CS_HW_3/pngparser.c:453:46

heap-buffer-overflow


```bash
==55403==ERROR: AddressSanitizer: heap-buffer-overflow on address 0x602000035ef1 at pc 0x557f701d5bf2 bp 0x7ffecbb0db40 sp 0x7ffecbb0db38
WRITE of size 1 at 0x602000035ef1 thread T0
    #0 0x557f701d5bf1 in convert_rgb_alpha_to_image /home/CS_HW_3/pngparser.c:453:46
    #1 0x557f701d6db1 in load_png /home/CS_HW_3/pngparser.c:668:10
    #2 0x557f701d3873 in LLVMFuzzerTestOneInput /home/CS_HW_3/fuzzer_load_png.c:15:7
    #3 0x557f700fc3d3 in fuzzer::Fuzzer::ExecuteCallback(unsigned char const*, unsigned long) (/home/CS_HW_3/fuzzer_load_png+0x403d3) (BuildId: 33bbbd1e260ddef05fdcf73cc2787112caa21a5f)
    #4 0x557f700fbb29 in fuzzer::Fuzzer::RunOne(unsigned char const*, unsigned long, bool, fuzzer::InputInfo*, bool, bool*) (/home/CS_HW_3/fuzzer_load_png+0x3fb29) (BuildId: 33bbbd1e260ddef05fdcf73cc2787112caa21a5f)
    #5 0x557f700fd319 in fuzzer::Fuzzer::MutateAndTestOne() (/home/CS_HW_3/fuzzer_load_png+0x41319) (BuildId: 33bbbd1e260ddef05fdcf73cc2787112caa21a5f)
    #6 0x557f700fde95 in fuzzer::Fuzzer::Loop(std::vector<fuzzer::SizedFile, std::allocator<fuzzer::SizedFile> >&) (/home/CS_HW_3/fuzzer_load_png+0x41e95) (BuildId: 33bbbd1e260ddef05fdcf73cc2787112caa21a5f)
    #7 0x557f700ebfd2 in fuzzer::FuzzerDriver(int*, char***, int (*)(unsigned char const*, unsigned long)) (/home/CS_HW_3/fuzzer_load_png+0x2ffd2) (BuildId: 33bbbd1e260ddef05fdcf73cc2787112caa21a5f)
    #8 0x557f70115cc2 in main (/home/CS_HW_3/fuzzer_load_png+0x59cc2) (BuildId: 33bbbd1e260ddef05fdcf73cc2787112caa21a5f)
    #9 0x7fd288749d8f in __libc_start_call_main csu/../sysdeps/nptl/libc_start_call_main.h:58:16
    #10 0x7fd288749e3f in __libc_start_main csu/../csu/libc-start.c:392:3
    #11 0x557f700e0a14 in _start (/home/CS_HW_3/fuzzer_load_png+0x24a14) (BuildId: 33bbbd1e260ddef05fdcf73cc2787112caa21a5f)

0x602000035ef1 is located 0 bytes to the right of 1-byte region [0x602000035ef0,0x602000035ef1)
allocated by thread T0 here:
    #0 0x557f70198a4e in malloc (/home/CS_HW_3/fuzzer_load_png+0xdca4e) (BuildId: 33bbbd1e260ddef05fdcf73cc2787112caa21a5f)
    #1 0x557f701d5732 in convert_rgb_alpha_to_image /home/CS_HW_3/pngparser.c:432:13
    #2 0x557f701d6db1 in load_png /home/CS_HW_3/pngparser.c:668:10
    #3 0x557f701d3873 in LLVMFuzzerTestOneInput /home/CS_HW_3/fuzzer_load_png.c:15:7
    #4 0x557f700fc3d3 in fuzzer::Fuzzer::ExecuteCallback(unsigned char const*, unsigned long) (/home/CS_HW_3/fuzzer_load_png+0x403d3) (BuildId: 33bbbd1e260ddef05fdcf73cc2787112caa21a5f)
    #5 0x557f700fbb29 in fuzzer::Fuzzer::RunOne(unsigned char const*, unsigned long, bool, fuzzer::InputInfo*, bool, bool*) (/home/CS_HW_3/fuzzer_load_png+0x3fb29) (BuildId: 33bbbd1e260ddef05fdcf73cc2787112caa21a5f)
    #6 0x557f700fd319 in fuzzer::Fuzzer::MutateAndTestOne() (/home/CS_HW_3/fuzzer_load_png+0x41319) (BuildId: 33bbbd1e260ddef05fdcf73cc2787112caa21a5f)
    #7 0x557f700fde95 in fuzzer::Fuzzer::Loop(std::vector<fuzzer::SizedFile, std::allocator<fuzzer::SizedFile> >&) (/home/CS_HW_3/fuzzer_load_png+0x41e95) (BuildId: 33bbbd1e260ddef05fdcf73cc2787112caa21a5f)
    #8 0x557f700ebfd2 in fuzzer::FuzzerDriver(int*, char***, int (*)(unsigned char const*, unsigned long)) (/home/CS_HW_3/fuzzer_load_png+0x2ffd2) (BuildId: 33bbbd1e260ddef05fdcf73cc2787112caa21a5f)
    #9 0x557f70115cc2 in main (/home/CS_HW_3/fuzzer_load_png+0x59cc2) (BuildId: 33bbbd1e260ddef05fdcf73cc2787112caa21a5f)
    #10 0x7fd288749d8f in __libc_start_call_main csu/../sysdeps/nptl/libc_start_call_main.h:58:16

SUMMARY: AddressSanitizer: heap-buffer-overflow /home/CS_HW_3/pngparser.c:453:46 in convert_rgb_alpha_to_image
Shadow bytes around the buggy address:
  0x0c047fffeb80: fa fa 00 05 fa fa 00 05 fa fa 00 05 fa fa 00 05
  0x0c047fffeb90: fa fa 00 05 fa fa 00 05 fa fa fd fa fa fa fd fa
  0x0c047fffeba0: fa fa fd fd fa fa fd fd fa fa 00 05 fa fa 06 fa
  0x0c047fffebb0: fa fa 00 05 fa fa 06 fa fa fa 00 05 fa fa 06 fa
  0x0c047fffebc0: fa fa 00 05 fa fa 06 fa fa fa 00 05 fa fa 06 fa
=>0x0c047fffebd0: fa fa fd fa fa fa 00 05 fa fa 00 00 fa fa[01]fa
  0x0c047fffebe0: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
  0x0c047fffebf0: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
  0x0c047fffec00: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
  0x0c047fffec10: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
  0x0c047fffec20: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
Shadow byte legend (one shadow byte represents 8 application bytes):
  Addressable:           00
  Partially addressable: 01 02 03 04 05 06 07 
  Heap left redzone:       fa
  Freed heap region:       fd
  Stack left redzone:      f1
  Stack mid redzone:       f2
  Stack right redzone:     f3
  Stack after return:      f5
  Stack use after scope:   f8
  Global redzone:          f9
  Global init order:       f6
  Poisoned by user:        f7
  Container overflow:      fc
  Array cookie:            ac
  Intra object redzone:    bb
  ASan internal:           fe
  Left alloca redzone:     ca
  Right alloca redzone:    cb
==55403==ABORTING
MS: 1 ChangeBinInt-; base unit: 41d80f4911ffb240439c1aa7d4cb4f97f2a68ad7
artifact_prefix='./'; Test unit written to ./crash-8fddfdb8040a783c5537bc34bd77d6a344d1647b
```