# x86 `vers.c` 데이터만 있는 목적 파일 — `x86-vers` (plan 397·398, 2026-10-08)

원본: `03_original/x86/binaries/mach_kernel` SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. 이 객체는 `__text` 가 없습니다.

- 원본 절(재빌드 L1 배치): __DATA,__data=0x1e5650+110.
- 07 파일: `07_kernel/src/conf/vers.c`(SHA-256 `21e087c71b4b5a8b7dfcbc342369d51d21d4e769555284c3a3d17e58e9e41eef`).
- 바탕: Darwin 0.1 kernel/conf/tools/newvers 의 출력 꼴.
- 고친 것: `version_major` 4, `version_minor` 2, `version_variant` "", `version` "NeXT Mach 4.2: Tue Jan 26 11:21:50 PST 1999; root(rcbuilder):Objects/mk-183.34.4.obj~2/RELEASE_I386\n" 을 원본 바이트대로 썼습니다.
- 링크 자리: 원본 데이터 순서(plan 397 항목 12; Darwin conf/files·files.i386·Makefile.template 의 차례와 같음).
- 진단(07 손대지 않음): s6p397-vk1(plan 397 항목 8).
- 최종: 07 에서 재빌드 s6l1-g1a(행 397, 06_reconstruction/l2_build_forms-s6p398.tsv; 꼴 plan398-template:x86-init_main), L1 `09_validation/reconstruction/s6l1-g1a-l1-397.json` **OBJECT_MATCH**, `cc -M` 의존 모두 07.
- diff: `06_reconstruction/evidence/x86-vers.diff`(/dev/null 대비, 원문 없음).
