# x86 `machdep_call.c` 데이터만 있는 목적 파일 — `x86-machdep_call` (plan 397·398, 2026-10-08)

원본: `03_original/x86/binaries/mach_kernel` SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. 이 객체는 `__text` 가 없습니다.

- 원본 절(재빌드 L1 배치): __DATA,__data=0x1e2424+84.
- 07 파일: `07_kernel/src/machdep/i386/machdep_call.c`(SHA-256 `d4326d11938711b02a06e8c6fa769f036d255e443e63a3ef1f848cc14acdd9a6`).
- 바탕: Darwin 0.1 kernel/machdep/i386/machdep_call.c.
- 고친 것: 고친 것 없음(원문 그대로, APSL 고지 유지).
- 링크 자리: 원본 데이터 순서(plan 397 항목 12; Darwin conf/files·files.i386·Makefile.template 의 차례와 같음).
- 진단(07 손대지 않음): s6p397-mc1(plan 397 항목 8).
- 최종: 07 에서 재빌드 s6l1-g1a(행 394, 06_reconstruction/l2_build_forms-s6p398.tsv; 꼴 plan398-template:x86-machdep), L1 `09_validation/reconstruction/s6l1-g1a-l1-394.json` **OBJECT_MATCH**, `cc -M` 의존 모두 07.
- diff: `06_reconstruction/evidence/x86-machdep_call.diff`(참조 원문 대비).
