# x86 `conf.c` 데이터만 있는 목적 파일 — `x86-conf` (plan 397·398, 2026-10-08)

원본: `03_original/x86/binaries/mach_kernel` SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. 이 객체는 `__text` 가 없습니다.

- 원본 절(재빌드 L1 배치): __DATA,__data=0x1e2cf4+2476.
- 07 파일: `07_kernel/src/bsd/dev/i386/conf.c`(SHA-256 `8863a3cd1511918efe0d0310d5564927e7a1369e4106e476dca6ec01e85b6bd1`).
- 바탕: 원본 바이트로 작성(D024); Darwin 0.1 kernel/bsd/dev/i386/conf.c 는 칸 배치만 참고.
- 고친 것: `bdevsw` 24 × 24 B·`cdevsw` 43 × 44 B 를 SDK `<sys/conf.h>` 구조(6·11 필드)로 썼습니다. Darwin 의 isdisk·chrtoblk 등 함수는 원본에 없습니다.
- 링크 자리: 원본 데이터 순서(plan 397 항목 12; Darwin conf/files·files.i386·Makefile.template 의 차례와 같음).
- 진단(07 손대지 않음): s6p397-cf1(plan 397 항목 8).
- 최종: 07 에서 재빌드 s6l1-g1a(행 395, 06_reconstruction/l2_build_forms-s6p398.tsv; 꼴 plan398-template:x86-cons), L1 `09_validation/reconstruction/s6l1-g1a-l1-395.json` **OBJECT_MATCH**, `cc -M` 의존 모두 07.
- diff: `06_reconstruction/evidence/x86-conf.diff`(/dev/null 대비, 원문 없음).
