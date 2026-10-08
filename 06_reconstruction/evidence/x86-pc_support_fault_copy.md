# x86 `machdep/i386/pc_support/PCinit.c` and `machdep/i386/fault_copy.c` (S5-P38, 2026-10-02)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. Sources: Darwin 0.1
`kernel-1.tar.gz` (SHA-256 `0c19349be454d7162f497b55a7735b443f5506694215e2f3f5f026b597a54a01`), files copied
unchanged. "Verbatim" applies to these sources; the header environment includes earlier restored 07 headers.
Plan 64, 64.1, 64.2. Run IDs `s5p39-*`.

- PCinit: original [0x1a0e48, 0x1a139d) 1365 B, 7 functions, text only (59 relocations). Gaps: front 2 x `00`
  (`ret` 0x1a0e45), back 3 x `00` (`_PCexception` 0x1a13a0). The compiler prints 4 pointer/integer warnings.
- fault_copy: original [0x189a5c, 0x18a30d) 2225 B, 14 functions, text only (56 relocations). The tail
  0x18a2f8-0x18a30c (no symbol) is the `do_fault` recovery path of `_suibyte` (0x18a2da stores 0x18a2f8 as the
  recovery address). Gaps: front 0 (confirmed `dbl_fault` ends at 0x189a5c with its own `90 90`), back 3 x `00`
  (`_fp_configure` 0x18a310). L1 compares the whole `__text` section, not only the Ghidra ranges.
- Diagnostic `s5p39-pre-1` and final 07_kernel build `s5p39-build-1` give the same `-O3` objects
  (`667a6de1a60caf71…`, `024a788987295d8f…`); the variant without `-fno-common` is identical; `-O2` differs.
  OBJECT_MATCH 7/7 and 14/14. Grade **A** for both. O3 matching shows reproducibility, not that O3 was the only
  possible historical setting.
- Headers named in the line markers of the two `.i` files and adopted verbatim with this change:
  `bsd/i386/signal.h`, `bsd/sys/errno.h` (also carries a University of California notice),
  `machdep/i386/pc_support/PCmiscInline.h`, `PCprivate.h`, `PCpublic.h`. Their bytes equal the staged copies used
  by the build, so no other object is affected.

## plan 397·398 고침(2026-10-08)
- 마지막 #import 뒤에 `#import <bsd/dev/i386/PCKeymap.c>` 를 넣었습니다(D058). 원본 `__TEXT,__const` 0x1d58e4 의 참조 없는 키맵 둘째 사본 882 B 가 이 객체의 const 가 됩니다(kbd_entries.m 도 바이트로는 같아 사용자가 골랐고, PCPointer.m 은 ObjC 클래스 이름 절이 바뀌어 맞지 않음). Darwin 원문 그대로였던 파일이 이번에 처음 고쳐졌습니다.
- 진단(07 손대지 않음): s6p397-kp1·kp2·kp3. 최종: 07 에서 재빌드 s6l1-g1a(행 53, 06_reconstruction/l2_build_forms-s6p398.tsv), L1 `09_validation/reconstruction/s6l1-g1a-l1-053.json` OBJECT_MATCH (`--place __TEXT,__const=0x1d58e4`), `cc -M` 의존 모두 07. 07 파일 SHA-256 `73455f42e79d5d6b00e1c58a1e41f825252427f4e12468b3588194ce715bdc01`.
- diff `06_reconstruction/evidence/x86-PCinit.diff` 를 다시 만들었습니다.
