fuzzer_store_png_rgba

```bash
AddressSanitizer:DEADLYSIGNAL
=================================================================
==72094==ERROR: AddressSanitizer: SEGV on unknown address 0x000000000008 (pc 0x55e187ae38b6 bp 0x7ffd5bfe4c50 sp 0x7ffd5bfe49b0 T0)
==72094==The signal is caused by a READ memory access.
==72094==Hint: address points to the zero page.
    #0 0x55e187ae38b6 in convert_color_palette_to_image /home/CS_HW_3/src/pngparser.c:387:70
    #1 0x55e187ae525b in convert_data_to_image /home/CS_HW_3/src/pngparser.c:487:12
    #2 0x55e187ae5360 in parse_png_no_interlace /home/CS_HW_3/src/pngparser.c:503:10
    #3 0x55e187ae5560 in parse_png /home/CS_HW_3/src/pngparser.c:519:12
    #4 0x55e187ae693c in load_png /home/CS_HW_3/src/pngparser.c:694:10
    #5 0x55e187ae08dc in LLVMFuzzerTestOneInput /home/CS_HW_3/src/fuzzer_store_png_rgba.c:13:9
    #6 0x55e187a093d3 in fuzzer::Fuzzer::ExecuteCallback(unsigned char const*, unsigned long) (/home/CS_HW_3/src/fuzzer_store_png_rgba+0x403d3) (BuildId: 677be6d34ff1b931631dd1f769a188f17cdc833c)
    #7 0x55e187a08b29 in fuzzer::Fuzzer::RunOne(unsigned char const*, unsigned long, bool, fuzzer::InputInfo*, bool, bool*) (/home/CS_HW_3/src/fuzzer_store_png_rgba+0x3fb29) (BuildId: 677be6d34ff1b931631dd1f769a188f17cdc833c)
    #8 0x55e187a0a319 in fuzzer::Fuzzer::MutateAndTestOne() (/home/CS_HW_3/src/fuzzer_store_png_rgba+0x41319) (BuildId: 677be6d34ff1b931631dd1f769a188f17cdc833c)
    #9 0x55e187a0ae95 in fuzzer::Fuzzer::Loop(std::vector<fuzzer::SizedFile, std::allocator<fuzzer::SizedFile> >&) (/home/CS_HW_3/src/fuzzer_store_png_rgba+0x41e95) (BuildId: 677be6d34ff1b931631dd1f769a188f17cdc833c)
    #10 0x55e1879f8fd2 in fuzzer::FuzzerDriver(int*, char***, int (*)(unsigned char const*, unsigned long)) (/home/CS_HW_3/src/fuzzer_store_png_rgba+0x2ffd2) (BuildId: 677be6d34ff1b931631dd1f769a188f17cdc833c)
    #11 0x55e187a22cc2 in main (/home/CS_HW_3/src/fuzzer_store_png_rgba+0x59cc2) (BuildId: 677be6d34ff1b931631dd1f769a188f17cdc833c)
    #12 0x7fea4fdced8f in __libc_start_call_main csu/../sysdeps/nptl/libc_start_call_main.h:58:16
    #13 0x7fea4fdcee3f in __libc_start_main csu/../csu/libc-start.c:392:3
    #14 0x55e1879eda14 in _start (/home/CS_HW_3/src/fuzzer_store_png_rgba+0x24a14) (BuildId: 677be6d34ff1b931631dd1f769a188f17cdc833c)

AddressSanitizer can not provide additional info.
SUMMARY: AddressSanitizer: SEGV /home/CS_HW_3/src/pngparser.c:387:70 in convert_color_palette_to_image
==72094==ABORTING
MS: 1 ShuffleBytes-; base unit: 2d5ff885f157e7321b0f50c06272f3da682963af
artifact_prefix='./'; Test unit written to ./crash-9399210952d01f9b68f051b265100fe12c657b1c
```