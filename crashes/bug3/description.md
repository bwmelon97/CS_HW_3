fuzzer_load_png_name

load_png /home/CS_HW_3/pngparser.c:547:17

heap-buffer-overflow

``` bash
➜ CS_HW_3 (main) ✗ ./fuzzer_load_png_name -detect_leaks=0 ./seeds 
INFO: Running with entropic power schedule (0xFF, 100).
INFO: Seed: 1570469724
INFO: Loaded 1 modules   (287 inline 8-bit counters): 287 [0x55ec581f4230, 0x55ec581f434f), 
INFO: Loaded 1 PC tables (287 PCs): 287 [0x55ec581f4350,0x55ec581f5540), 
INFO:        2 files found in ./seeds
INFO: -max_len is not provided; libFuzzer will not generate inputs larger than 4096 bytes
=================================================================
==68008==ERROR: AddressSanitizer: heap-buffer-overflow on address 0x602000000011 at pc 0x55ec5813df2a bp 0x7ffe2f7b8ad0 sp 0x7ffe2f7b8298
READ of size 2 at 0x602000000011 thread T0
    #0 0x55ec5813df29 in __interceptor_fopen (/home/CS_HW_3/fuzzer_load_png_name+0xacf29) (BuildId: 14e3b32a9ac14ecdce962af45a31a9a310dcc03c)
    #1 0x55ec581ab123 in load_png /home/CS_HW_3/pngparser.c:547:17
    #2 0x55ec581a8858 in LLVMFuzzerTestOneInput /home/CS_HW_3/fuzzer_load_png_name.c:9:9
    #3 0x55ec580d13d3 in fuzzer::Fuzzer::ExecuteCallback(unsigned char const*, unsigned long) (/home/CS_HW_3/fuzzer_load_png_name+0x403d3) (BuildId: 14e3b32a9ac14ecdce962af45a31a9a310dcc03c)
    #4 0x55ec580d2630 in fuzzer::Fuzzer::ReadAndExecuteSeedCorpora(std::vector<fuzzer::SizedFile, std::allocator<fuzzer::SizedFile> >&) (/home/CS_HW_3/fuzzer_load_png_name+0x41630) (BuildId: 14e3b32a9ac14ecdce962af45a31a9a310dcc03c)
    #5 0x55ec580d2c82 in fuzzer::Fuzzer::Loop(std::vector<fuzzer::SizedFile, std::allocator<fuzzer::SizedFile> >&) (/home/CS_HW_3/fuzzer_load_png_name+0x41c82) (BuildId: 14e3b32a9ac14ecdce962af45a31a9a310dcc03c)
    #6 0x55ec580c0fd2 in fuzzer::FuzzerDriver(int*, char***, int (*)(unsigned char const*, unsigned long)) (/home/CS_HW_3/fuzzer_load_png_name+0x2ffd2) (BuildId: 14e3b32a9ac14ecdce962af45a31a9a310dcc03c)
    #7 0x55ec580eacc2 in main (/home/CS_HW_3/fuzzer_load_png_name+0x59cc2) (BuildId: 14e3b32a9ac14ecdce962af45a31a9a310dcc03c)
    #8 0x7f7e16280d8f in __libc_start_call_main csu/../sysdeps/nptl/libc_start_call_main.h:58:16
    #9 0x7f7e16280e3f in __libc_start_main csu/../csu/libc-start.c:392:3
    #10 0x55ec580b5a14 in _start (/home/CS_HW_3/fuzzer_load_png_name+0x24a14) (BuildId: 14e3b32a9ac14ecdce962af45a31a9a310dcc03c)

0x602000000011 is located 0 bytes to the right of 1-byte region [0x602000000010,0x602000000011)
allocated by thread T0 here:
    #0 0x55ec5816da4e in malloc (/home/CS_HW_3/fuzzer_load_png_name+0xdca4e) (BuildId: 14e3b32a9ac14ecdce962af45a31a9a310dcc03c)
    #1 0x7f7e16650a0b in operator new(unsigned long) (/lib/x86_64-linux-gnu/libstdc++.so.6+0xaea0b) (BuildId: 725ef5da52ee6d881f9024d8238a989903932637)
    #2 0x55ec580d2630 in fuzzer::Fuzzer::ReadAndExecuteSeedCorpora(std::vector<fuzzer::SizedFile, std::allocator<fuzzer::SizedFile> >&) (/home/CS_HW_3/fuzzer_load_png_name+0x41630) (BuildId: 14e3b32a9ac14ecdce962af45a31a9a310dcc03c)
    #3 0x55ec580d2c82 in fuzzer::Fuzzer::Loop(std::vector<fuzzer::SizedFile, std::allocator<fuzzer::SizedFile> >&) (/home/CS_HW_3/fuzzer_load_png_name+0x41c82) (BuildId: 14e3b32a9ac14ecdce962af45a31a9a310dcc03c)
    #4 0x55ec580c0fd2 in fuzzer::FuzzerDriver(int*, char***, int (*)(unsigned char const*, unsigned long)) (/home/CS_HW_3/fuzzer_load_png_name+0x2ffd2) (BuildId: 14e3b32a9ac14ecdce962af45a31a9a310dcc03c)
    #5 0x55ec580eacc2 in main (/home/CS_HW_3/fuzzer_load_png_name+0x59cc2) (BuildId: 14e3b32a9ac14ecdce962af45a31a9a310dcc03c)
    #6 0x7f7e16280d8f in __libc_start_call_main csu/../sysdeps/nptl/libc_start_call_main.h:58:16

SUMMARY: AddressSanitizer: heap-buffer-overflow (/home/CS_HW_3/fuzzer_load_png_name+0xacf29) (BuildId: 14e3b32a9ac14ecdce962af45a31a9a310dcc03c) in __interceptor_fopen
Shadow bytes around the buggy address:
  0x0c047fff7fb0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x0c047fff7fc0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x0c047fff7fd0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x0c047fff7fe0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x0c047fff7ff0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
=>0x0c047fff8000: fa fa[01]fa fa fa fa fa fa fa fa fa fa fa fa fa
  0x0c047fff8010: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
  0x0c047fff8020: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
  0x0c047fff8030: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
  0x0c047fff8040: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
  0x0c047fff8050: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
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
==68008==ABORTING
MS: 0 ; base unit: 0000000000000000000000000000000000000000


artifact_prefix='./'; Test unit written to ./crash-da39a3ee5e6b4b0d3255bfef95601890afd80709
Base64: 
```