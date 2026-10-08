# x86 `src/machdep/i386/cons.c` (plan 276 (S5-P266), 2026-10-04)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. plan 276 (S5-P266). Final run `s5p266-it1`; 07 file SHA-256 `64eb984be25f66d9a40e2e7b89eb237e35866797848d55b460238cd624d078d2`; diff `x86-cons.diff`.

- Object [0x1948f8, 0x194bf2) 762 B, 7 functions (_cnopen, _cnread, _cnwrite, _cnioctl, _cnselect, _cngetc, _cnputc). Front `5d c3 00 00`, back `00 00 55 89`, next symbol 0x194bf4.
- Final OBJECT_MATCH (`09_validation/reconstruction/s5p266-it1-l1-cons-F-20261002.json`). Grade **A**.

Object extent [0x1948f8, 0x194bf4) 764 B (762 B text + 00 00): cnopen, cnread, cnwrite, cnioctl, cnselect, cngetc, cnputc; front autoconf_i386, next mmread (mem.c). The object references only cdevsw (conf.c), active_u and cons_tp; that it defines no __data is an inference (the build output has only __text). References by file name: NeXTMach next/cons.c (base; same function set, no cnclose), Darwin 0.1 bsd/dev/i386/cons.c and bsd/dev/ppc/cons.c (4.4BSD interfaces, unused), Mach4 kernel/device/cons.c (different design, unused). Scratch s5p266-w2 OBJECT_MATCH. The codex review of plan 276 confirmed the extent, the cnopen/cnioctl addresses and the placement; it noted that no-__data is an inference and that Darwin ppc/cons.c was missing from the reference list (both verified and fixed). it1 (s5p266-it1) from 07 OBJECT_MATCH, relcheck 0 mismatches.

## plan 400 고침(2026-10-08)
- plan 400: struct tty cons, *cons_tp defined (were extern; cons Darwin 0.1 bsd/dev/i386/cons.c:47, cons_tp D059)
- 공통 기호 정의만 늘어 `__text`·`__data` 바이트는 바뀌지 않았습니다: plan 400 재빌드(s6l2-*, 402 객체)에서 이 객체의 L1 이 plan 398 결과와 같습니다. 07 파일 SHA-256 `58db13988d123c553d53036734ea613e05ec5b1852fc2c5b0b541bd39a3e6db4`.
- diff `06_reconstruction/evidence/x86-cons.diff` 를 다시 만들었습니다.

## plan 404 고침(2026-10-08, D061)
- notice added: line marked plan 400 (Darwin), cons part: Apple APSL 1.0 (notice in file; 07_kernel/LICENSES/APSL-1.0.txt). 주석만 바뀌었습니다(07 파일 SHA-256 `29f8cd2375330c095f93fa5431ebcc9eec5a1ccb56873344a27392adf25b1772`); diff 를 다시 만들었습니다.
