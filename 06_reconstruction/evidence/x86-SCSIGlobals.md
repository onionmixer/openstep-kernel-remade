# x86 `SCSIGlobals.m` 데이터만 있는 목적 파일 — `x86-SCSIGlobals` (plan 397·398, 2026-10-08)

원본: `03_original/x86/binaries/mach_kernel` SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. 이 객체는 `__text` 가 없습니다.

- 원본 절(재빌드 L1 배치): __DATA,__data=0x1e5184+424; __TEXT,__cstring 875 B (literal, checked by content).
- 07 파일: `07_kernel/src/driverkit/libDriver/Kernel/SCSIGlobals.m`(SHA-256 `818bdb2f2e3effa850799924ff6bd2688cbe8210b8aaf3b7f942fad6816d59e1`).
- 바탕: Darwin 0.1 driverkit-1/libDriver/Kernel/SCSIGlobals.m(D030 작성, 머리 교체).
- 고친 것: 본문 그대로, 머리 주석만 바꿨습니다. ObjC 모듈을 내지 않습니다(원본 모듈 76 에도 없음).
- 링크 자리: 원본 데이터 순서(plan 397 항목 12; Darwin conf/files·files.i386·Makefile.template 의 차례와 같음).
- 진단(07 손대지 않음): s6p397-sg1(plan 397 항목 8).
- 최종: 07 에서 재빌드 s6l1-g2ba(행 399, 06_reconstruction/l2_build_forms-s6p398.tsv; 꼴 plan398-template:x86-SCSIGeneric), L1 `09_validation/reconstruction/s6l1-g2ba-l1-399.json` **OBJECT_MATCH**, `cc -M` 의존 모두 07.
- diff: `06_reconstruction/evidence/x86-SCSIGlobals.diff`(참조 원문 대비).
