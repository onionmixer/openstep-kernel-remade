# x86 `src/machdep/i386/i386_init.c` (plan 248 (S5-P233), 2026-10-03)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. plan 248 (S5-P233). Final run `s5p233-it3`; 07 file SHA-256 `6d7fdb67dd2514ab45bfe796ee662d168fb66df81566577715519232360a3077`; diff `x86-i386_init.diff`.

- Object [0x18aafc, 0x18b181) 1669 B, 11 functions (_i386_init, (static zero_fill_data), (static machine_configure), (static size_memory), _bios_extdata_addr, _alloc_cnvmem, _alloc_pages, _getargs, _isargsep, _argstrcpy, _getval). Front `5d c3 00 00`, back `00 00 00 55`, next symbol 0x18b184.
- Final L1 `09_validation/reconstruction/s5p233-it3-l1-i386_init-F-20261002.json`: __text 0 byte differences; __TEXT,__const 4 B 18 00 20 00 unreferenced (TSS_SEL/LDT_SEL operands of the unused inline ltr()/lldt() in cpu_inline.h, as for intr.c) -> unplaced; __DATA,__bss reference-inferred. Grade **P**.

Object extent [0x18aafc, 0x18b184) 1672 B (text 1669 B + 3 x 00); 8 named functions and 3 statics (zero_fill_data 0x18abd0, machine_configure 0x18ac28, size_memory 0x18acf8, not in the symbol table). __DATA,__data [0x1e19b4, 0x1e1a03) 79 B (kernargs, its strings, cnvmem, extmem, "__DATA", "alloc_pages") -- verified by L1. boot_file is a common (65 B). The codex review of plan 248 corrected four details (alloc_pages returns the old first_phys_addr; the AC test does not re-read EFLAGS; argstrcpy writes the NUL; strncmp uses cp - args), each verified against the bytes and adopted. it1 (s5p233-it1): all functions except machine_configure matched; variants s5p233-v1/v2 fixed it: a hlt loop `if (!is486_or_higher()) for (;;) hlt`, and is586 ending `if (pid.family != 5) return FALSE; return TRUE`. it3 from 07 (comments and the notice only, sections identical to it2): __text and __data 0 differences, relcheck 0, __bss reference-inferred.

## plan 400 고침(2026-10-08)
- plan 400: virtual_avail, virtual_end, mem_size defined (were extern); cpu_config, mem_region[2], num_regions added (as Darwin 0.1 i386_init.c:77-88)
- 공통 기호 정의만 늘어 `__text`·`__data` 바이트는 바뀌지 않았습니다: plan 400 재빌드(s6l2-*, 402 객체)에서 이 객체의 L1 이 plan 398 결과와 같습니다. 07 파일 SHA-256 `25c44daac30fe4d7af605c77a8cb348bc95d7fb1dad3f56ac99ff94aecb9986f`.
- diff `06_reconstruction/evidence/x86-i386_init.diff` 를 다시 만들었습니다.

## plan 404 고침(2026-10-08, D061)
- notice added: lines marked plan 400 (Darwin): Apple APSL 1.0 (notice in file; 07_kernel/LICENSES/APSL-1.0.txt). 주석만 바뀌었습니다(07 파일 SHA-256 `395a46da3598b5d38c8af9beef3977007cf3b665f26f5656c3a83176a278ca7c`); diff 를 다시 만들었습니다.
