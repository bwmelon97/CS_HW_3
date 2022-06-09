fuzzer_store_png_palette

```bash
➜ src (main) ✗ ./fuzzer_store_png_palette -detect_leaks=0 ./seeds
INFO: Running with entropic power schedule (0xFF, 100).
INFO: Seed: 1906769748
INFO: Loaded 1 modules   (253 inline 8-bit counters): 253 [0x558678bd23f0, 0x558678bd24ed), 
INFO: Loaded 1 PC tables (253 PCs): 253 [0x558678bd24f0,0x558678bd34c0), 
INFO:       28 files found in ./seeds
INFO: -max_len is not provided; libFuzzer will not generate inputs larger than 4096 bytes
INFO: seed corpus: files: 28 min: 1b max: 1070b total: 6679b rss: 30Mb
=================================================================
==97232==ERROR: AddressSanitizer: stack-buffer-overflow on address 0x7ffdc91f2928 at pc 0x558678b8dc43 bp 0x7ffdc91f2550 sp 0x7ffdc91f2548
READ of size 8 at 0x7ffdc91f2928 thread T0
    #0 0x558678b8dc42 in store_idat_plte /home/CS_HW_3/src/pngparser.c:950:60
    #1 0x558678b8e85d in store_png_palette /home/CS_HW_3/src/pngparser.c:1012:3
    #2 0x558678b8ebac in store_png /home/CS_HW_3/src/pngparser.c:1039:5
    #3 0x558678b83930 in LLVMFuzzerTestOneInput /home/CS_HW_3/src/fuzzer_store_png_palette.c:13:5
    #4 0x558678aac3d3 in fuzzer::Fuzzer::ExecuteCallback(unsigned char const*, unsigned long) (/home/CS_HW_3/src/fuzzer_store_png_palette+0x403d3) (BuildId: e09239236ad88b30f385de6d4d85c8c2783fb266)
    #5 0x558678aabb29 in fuzzer::Fuzzer::RunOne(unsigned char const*, unsigned long, bool, fuzzer::InputInfo*, bool, bool*) (/home/CS_HW_3/src/fuzzer_store_png_palette+0x3fb29) (BuildId: e09239236ad88b30f385de6d4d85c8c2783fb266)
    #6 0x558678aad798 in fuzzer::Fuzzer::ReadAndExecuteSeedCorpora(std::vector<fuzzer::SizedFile, std::allocator<fuzzer::SizedFile> >&) (/home/CS_HW_3/src/fuzzer_store_png_palette+0x41798) (BuildId: e09239236ad88b30f385de6d4d85c8c2783fb266)
    #7 0x558678aadc82 in fuzzer::Fuzzer::Loop(std::vector<fuzzer::SizedFile, std::allocator<fuzzer::SizedFile> >&) (/home/CS_HW_3/src/fuzzer_store_png_palette+0x41c82) (BuildId: e09239236ad88b30f385de6d4d85c8c2783fb266)
    #8 0x558678a9bfd2 in fuzzer::FuzzerDriver(int*, char***, int (*)(unsigned char const*, unsigned long)) (/home/CS_HW_3/src/fuzzer_store_png_palette+0x2ffd2) (BuildId: e09239236ad88b30f385de6d4d85c8c2783fb266)
    #9 0x558678ac5cc2 in main (/home/CS_HW_3/src/fuzzer_store_png_palette+0x59cc2) (BuildId: e09239236ad88b30f385de6d4d85c8c2783fb266)
    #10 0x7faf6d446d8f in __libc_start_call_main csu/../sysdeps/nptl/libc_start_call_main.h:58:16
    #11 0x7faf6d446e3f in __libc_start_main csu/../csu/libc-start.c:392:3
    #12 0x558678a90a14 in _start (/home/CS_HW_3/src/fuzzer_store_png_palette+0x24a14) (BuildId: e09239236ad88b30f385de6d4d85c8c2783fb266)

Address 0x7ffdc91f2928 is located in stack of thread T0 at offset 40 in frame
    #0 0x558678b8378f in LLVMFuzzerTestOneInput /home/CS_HW_3/src/fuzzer_store_png_palette.c:6

  This frame has 1 object(s):
    [32, 40) 'test_img' (line 12) <== Memory access at offset 40 overflows this variable
HINT: this may be a false positive if your program uses some custom stack unwind mechanism, swapcontext or vfork
      (longjmp and C++ exceptions *are* supported)
SUMMARY: AddressSanitizer: stack-buffer-overflow /home/CS_HW_3/src/pngparser.c:950:60 in store_idat_plte
Shadow bytes around the buggy address:
  0x1000392364d0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x1000392364e0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x1000392364f0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x100039236500: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x100039236510: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
=>0x100039236520: f1 f1 f1 f1 00[f3]f3 f3 00 00 00 00 00 00 00 00
  0x100039236530: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x100039236540: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x100039236550: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x100039236560: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x100039236570: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
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
==97232==ABORTING
MS: 0 ; base unit: 0000000000000000000000000000000000000000
0x5b,0x0,0x0,0x0,
[\000\000\000
artifact_prefix='./'; Test unit written to ./crash-e5132d2015f3f9dbb4ec2449bac2514b9fe5ffe8
Base64: WwAAAA==
```