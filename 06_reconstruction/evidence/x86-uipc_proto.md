# x86 `uipc_proto.c` 데이터만 있는 목적 파일 — `x86-uipc_proto` (plan 397·398, 2026-10-08)

원본: `03_original/x86/binaries/mach_kernel` SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. 이 객체는 `__text` 가 없습니다.

- 원본 절(재빌드 L1 배치): __DATA,__data=0x1db228+181.
- 07 파일: `07_kernel/src/bsd/kern/uipc_proto.c`(SHA-256 `ded3587802b252b2943b6ae3552b774fae7cfdfb9357285b8fb5a027575a6fdb`).
- 바탕: NeXTMach mk-108.1 bsd/uipc_proto.c.
- 고친 것: 고친 것 없음(원문 그대로).
- 링크 자리: 원본 데이터 순서(plan 397 항목 12; Darwin conf/files·files.i386·Makefile.template 의 차례와 같음).
- 진단(07 손대지 않음): s6p397-up1(plan 397 항목 8).
- 최종: 07 에서 재빌드 s6l1-g1a(행 388, 06_reconstruction/l2_build_forms-s6p398.tsv; 꼴 plan398-template:x86-uipc_mbuf), L1 `09_validation/reconstruction/s6l1-g1a-l1-388.json` **OBJECT_MATCH**, `cc -M` 의존 모두 07.
- diff: `06_reconstruction/evidence/x86-uipc_proto.diff`(참조 원문 대비).
