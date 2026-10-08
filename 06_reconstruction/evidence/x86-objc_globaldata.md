# x86 `objc-globaldata.m` 데이터만 있는 목적 파일 — `x86-objc_globaldata` (plan 397·398, 2026-10-08)

원본: `03_original/x86/binaries/mach_kernel` SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. 이 객체는 `__text` 가 없습니다.

- 원본 절(재빌드 L1 배치): __DATA,__data=0x1e55b8+44.
- 07 파일: `07_kernel/src/objc-runtime/objc-globaldata.m`(SHA-256 `7915ed651a20376bf417fa4836b7245d0c5d9d809c62396cf5f95a2c073370f2`).
- 바탕: Darwin 0.1 objc-1 objc-globaldata.m(D030·D047 작성, 머리 교체).
- 고친 것: 본문 그대로(SHLIB 정의 안 함), 머리 주석만 바꿨습니다.
- 링크 자리: 원본 데이터 순서(plan 397 항목 12; Darwin conf/files·files.i386·Makefile.template 의 차례와 같음).
- 진단(07 손대지 않음): s6p397-gd1(plan 397 항목 8).
- 최종: 07 에서 재빌드 s6l1-g4a(행 400, 06_reconstruction/l2_build_forms-s6p398.tsv; 꼴 plan398-template:x86-objc_globaltext), L1 `09_validation/reconstruction/s6l1-g4a-l1-400.json` **OBJECT_MATCH**, `cc -M` 의존 모두 07.
- diff: `06_reconstruction/evidence/x86-objc_globaldata.diff`(참조 원문 대비).
