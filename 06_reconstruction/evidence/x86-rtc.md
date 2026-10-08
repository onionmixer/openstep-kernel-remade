# x86 `src/machdep/i386/rtc.c` (plan 277 (S5-P267), 2026-10-04)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. plan 277 (S5-P267). Final run `s5p267-it1`; 07 file SHA-256 `2687c863c6f0b03c018f4ca279b5aa46d62995158c4dc58c2280da171f691f44`; diff `x86-rtc.diff`.

- Object [0x194e44, 0x19554c) 1800 B, 8 functions (_rtcinit, _rtcget, _rtcput, _yeartoday, _hexdectodec, _dectohexdec, _readtodc, _writetodc). Front `c3 00 00 00`, back `55 89 e5 b8`, next symbol 0x19554c.
- Final L1 `09_validation/reconstruction/s5p267-it1-l1-rtc-F-20261002.json`: __text/__const 0 byte differences; __DATA,__bss unreferenced, not placed. Grade **P**.

Object extent [0x194e44, 0x19554c) 1800 B, 8 functions (rtcinit, rtcget, rtcput, yeartoday, hexdectodec, dectohexdec, readtodc, writetodc); front kdasm object, next ev.c (_defaultEventSources). __DATA,__data 52 B at 0x1e36a8 (first_rtcopen_ever, month[12]) verified by L1d. Direct callers in the original (python E8 search): readtodc 0x1877ec, 0x187a6b; writetodc 0x187c1c; no direct call to rtcput (inlined in writetodc). References by file name: Mach4 i386/kernel/i386at/rtc.c (base) and rtc.h (verbatim), Darwin 0.1 bsd/dev/i386/rtc.c (code reference), no NeXTMach file. Scratch s5p267-w3 matched; the codex review of plan 277 confirmed the edits and asked for the bss and caller wording to be weakened (verified, fixed). it1 (s5p267-it1) from 07: 8 functions MATCH, __text and __data 0 differences, relcheck 0; grade P only because the unreferenced static __bss cannot be placed.

## plan 397·398 고침(2026-10-08)
- 참조 없는 `static unsigned char rtc[RTC_NREG];`(Mach4 rtc.c:55) 를 주석 줄로 바꿨습니다. 원본 `__bss` 의 rtc 자리(autoconf_i386 끝 0x1e7749 ~ kmDevice 0x1e774c)가 3 B 뿐이라 14 B 배열이 들어갈 수 없습니다(plan 397 0 (g)). 등급 P → **A**(objects_confirmed 로 옮김).
- 진단(07 손대지 않음): s6p397-rt1. 최종: 07 에서 재빌드 s6l1-g1a(행 354, 06_reconstruction/l2_build_forms-s6p398.tsv), L1 `09_validation/reconstruction/s6l1-g1a-l1-354.json` OBJECT_MATCH, `cc -M` 의존 모두 07. 07 파일 SHA-256 `950d01baf3fbe089595ffd35979c076d947ccff9fb2a5c6504bd73a04fa25836`.
- diff `06_reconstruction/evidence/x86-rtc.diff` 를 다시 만들었습니다.
