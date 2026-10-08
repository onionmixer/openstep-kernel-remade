# x86 `src/machdep/i386/machdep.c` (plan 241 (S5-P226), 2026-10-03)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. plan 241 (S5-P226). Final run `s5p226-it3`; 07 file SHA-256 `7ce75af0c789983b2ccacc7988bb8d46fbd3052c67b42c0408e00511f0c3dd95`; diff `x86-machdep.diff`.

- Object [0x18cc28, 0x18d206) 1502 B, 14 functions (_halt_thread, _reboot_mach, _led_msg, _mini_mon, _nmi_prf, _addupc, _halt_cpu, (static prettyPrint), _md_prepare_for_shutdown, _md_shutdown_devices, _md_do_shutdown, _machine_table_setokay, _machine_table, _us_spin). Front `c3 00 00 00`, back `00 00 55 89`, next symbol 0x18d208.
- Final L1 `09_validation/reconstruction/s5p226-it3-l1-machdep-F-20261002.json`: __text/__const 0 byte differences; __DATA,__bss reference-inferred only. Grade **P**.

Object extent [0x18cc28, 0x18d208) 1504 B: halt_thread, reboot_mach, led_msg, mini_mon, nmi_prf, addupc, halt_cpu, static prettyPrint, md_prepare_for_shutdown, md_shutdown_devices, md_do_shutdown, machine_table_setokay, machine_table, us_spin (nop alignment before us_spin, so one object is inferred). __DATA,__data [0x1e227c, 0x1e2422): mini_mon and halt strings including two empty strings (the second has no code reference; the dead-branch origin is inferred) -- verified by L1. The codex review of plan 241 confirmed the facts with two qualifications (adopted). it1: addupc differed (the original clears the parameter's pr_scale, not the loop variable's); it2: us_spin differed; variants s5p226-v1/v2 failed, s5p226-v3 x1 (unsigned counts tested with > 0) matched. it3 (s5p226-it3): __text and __data match, relcheck 0; __bss reference-inferred.

## plan 400 고침(2026-10-08)
- plan 400: int nmi_stay -> int nmi_cont, nmi_gdb, nmi_mon, nmi_help, nmi_halt, nmi_msg, nmi_stay, nmi_reboot, nmi_big (names from the original symbol table, the same line as Darwin 0.1 machdep/i386/machdep.c:109-110); _nmi_* run of the original __common
- 공통 기호 정의만 늘어 `__text`·`__data` 바이트는 바뀌지 않았습니다: plan 400 재빌드(s6l2-*, 402 객체)에서 이 객체의 L1 이 plan 398 결과와 같습니다. 07 파일 SHA-256 `6b5f311fd4b461960077804f6e726edb95ce69fd01130b93557cab67369383e2`.
- diff `06_reconstruction/evidence/x86-machdep.diff` 를 다시 만들었습니다.

## plan 404 고침(2026-10-08, D061)
- notice added: line marked plan 400 (Darwin): Apple APSL 1.0 (notice in file; 07_kernel/LICENSES/APSL-1.0.txt). 주석만 바뀌었습니다(07 파일 SHA-256 `e62e1be5010b45a26fc6e7b7b9500f8caac6c19132dd6d2e63ae30f81d4abd5d`); diff 를 다시 만들었습니다.
