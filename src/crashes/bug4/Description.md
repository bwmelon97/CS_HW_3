fuzzer_store_png_name



```bash
➜ src (main) ✗ ./fuzzer_store_png_name -detect_leaks=0 ./seeds 
INFO: Running with entropic power schedule (0xFF, 100).
INFO: Seed: 1450385016
INFO: Loaded 1 modules   (253 inline 8-bit counters): 253 [0x55b9eb3773b0, 0x55b9eb3774ad), 
INFO: Loaded 1 PC tables (253 PCs): 253 [0x55b9eb3774b0,0x55b9eb378480), 
INFO:       72 files found in ./seeds
INFO: -max_len is not provided; libFuzzer will not generate inputs larger than 4096 bytes
INFO: seed corpus: files: 72 min: 1b max: 1070b total: 4390b rss: 30Mb
AddressSanitizer:DEADLYSIGNAL
=================================================================
==39047==ERROR: AddressSanitizer: SEGV on unknown address 0x000000000000 (pc 0x7f0ef2fbcfc2 bp 0x7ffcd8abb0c0 sp 0x7ffcd8aba850 T0)
==39047==The signal is caused by a READ memory access.
==39047==Hint: address points to the zero page.
    #0 0x7f0ef2fbcfc2 in fwrite libio/./libio/iofwrite.c:37:3
    #1 0x55b9eb286def in __interceptor_fwrite (/home/CS_HW_3/src/fuzzer_store_png_name+0x75def) (BuildId: 2f1f5f080e5e4a054f1a81f52899351e8a608c1b)
    #2 0x55b9eb32f0a5 in store_filesig /home/CS_HW_3/src/pngparser.c:747:10
    #3 0x55b9eb333ba2 in store_png /home/CS_HW_3/src/pngparser.c:1031:3
    #4 0x55b9eb32898d in LLVMFuzzerTestOneInput /home/CS_HW_3/src/fuzzer_store_png_name.c:15:9
    #5 0x55b9eb2513d3 in fuzzer::Fuzzer::ExecuteCallback(unsigned char const*, unsigned long) (/home/CS_HW_3/src/fuzzer_store_png_name+0x403d3) (BuildId: 2f1f5f080e5e4a054f1a81f52899351e8a608c1b)
    #6 0x55b9eb250b29 in fuzzer::Fuzzer::RunOne(unsigned char const*, unsigned long, bool, fuzzer::InputInfo*, bool, bool*) (/home/CS_HW_3/src/fuzzer_store_png_name+0x3fb29) (BuildId: 2f1f5f080e5e4a054f1a81f52899351e8a608c1b)
    #7 0x55b9eb252798 in fuzzer::Fuzzer::ReadAndExecuteSeedCorpora(std::vector<fuzzer::SizedFile, std::allocator<fuzzer::SizedFile> >&) (/home/CS_HW_3/src/fuzzer_store_png_name+0x41798) (BuildId: 2f1f5f080e5e4a054f1a81f52899351e8a608c1b)
    #8 0x55b9eb252c82 in fuzzer::Fuzzer::Loop(std::vector<fuzzer::SizedFile, std::allocator<fuzzer::SizedFile> >&) (/home/CS_HW_3/src/fuzzer_store_png_name+0x41c82) (BuildId: 2f1f5f080e5e4a054f1a81f52899351e8a608c1b)
    #9 0x55b9eb240fd2 in fuzzer::FuzzerDriver(int*, char***, int (*)(unsigned char const*, unsigned long)) (/home/CS_HW_3/src/fuzzer_store_png_name+0x2ffd2) (BuildId: 2f1f5f080e5e4a054f1a81f52899351e8a608c1b)
    #10 0x55b9eb26acc2 in main (/home/CS_HW_3/src/fuzzer_store_png_name+0x59cc2) (BuildId: 2f1f5f080e5e4a054f1a81f52899351e8a608c1b)
    #11 0x7f0ef2f66d8f in __libc_start_call_main csu/../sysdeps/nptl/libc_start_call_main.h:58:16
    #12 0x7f0ef2f66e3f in __libc_start_main csu/../csu/libc-start.c:392:3
    #13 0x55b9eb235a14 in _start (/home/CS_HW_3/src/fuzzer_store_png_name+0x24a14) (BuildId: 2f1f5f080e5e4a054f1a81f52899351e8a608c1b)

AddressSanitizer can not provide additional info.
SUMMARY: AddressSanitizer: SEGV libio/./libio/iofwrite.c:37:3 in fwrite
==39047==ABORTING
MS: 0 ; base unit: 0000000000000000000000000000000000000000
0x0,
\000
artifact_prefix='./'; Test unit written to ./crash-5ba93c9db0cff93f52b521d7420e43f6eda2784f
Base64: AA==
```