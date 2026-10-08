# x86 `init_sysent.c` 데이터만 있는 목적 파일 — `x86-init_sysent` (plan 397·398, 2026-10-08)

원본: `03_original/x86/binaries/mach_kernel` SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. 이 객체는 `__text` 가 없습니다.

- 원본 절(재빌드 L1 배치): __DATA,__data=0x1da034+1476.
- 07 파일: `07_kernel/src/bsd/kern/init_sysent.c`(SHA-256 `753be421cffa5a1fd1dfb5f7c4946d2ced8a1eb31d50c36a2b368658e2ab884b`).
- 바탕: NeXTMach mk-108.1 bsd/init_sysent.c.
- 고친 것: 항목 23(`_setuid`)·52(`sigpending`)·139(nosys)·147–154(`setsid`, nosys 둘, getsockname, nosys, `setprivexec`, `getposix`, `setposix`)·174–183(nosys, `gc_control`, `add_profil`, nosys 둘, `waitpgrp`, `_utime`, `_setgid`, `uname`, `setpgid`)을 원본 표대로 바꾸고 끝의 181 항목을 뺐습니다(184 항목, `_nsysent` 184).
- 링크 자리: 원본 데이터 순서(plan 397 항목 12; Darwin conf/files·files.i386·Makefile.template 의 차례와 같음).
- 진단(07 손대지 않음): s6p397-is1·is2·is3(plan 397 항목 8).
- 최종: 07 에서 재빌드 s6l1-g1a(행 386, 06_reconstruction/l2_build_forms-s6p398.tsv; 꼴 plan398-template:x86-init_main), L1 `09_validation/reconstruction/s6l1-g1a-l1-386.json` **OBJECT_MATCH**, `cc -M` 의존 모두 07.
- diff: `06_reconstruction/evidence/x86-init_sysent.diff`(참조 원문 대비).

## plan 404 고침(2026-10-08, D061)
- notice added: lines marked plan 397 (Darwin): Apple APSL 1.0 (notice in file; 07_kernel/LICENSES/APSL-1.0.txt). 주석만 바뀌었습니다(07 파일 SHA-256 `a3f509b4dc9912c93576083b67becb8cce745d5b020ef84e2fcde5d1fd00e9ae`); diff 를 다시 만들었습니다.
