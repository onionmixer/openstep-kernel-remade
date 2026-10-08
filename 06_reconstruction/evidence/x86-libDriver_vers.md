# x86 `vers.c` 데이터만 있는 목적 파일 — `x86-libDriver_vers` (plan 397·398, 2026-10-08)

원본: `03_original/x86/binaries/mach_kernel` SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. 이 객체는 `__text` 가 없습니다.

- 원본 절(재빌드 L1 배치): __TEXT,__const=0x1d647c+160.
- 07 파일: `07_kernel/src/driverkit/libDriver/vers.c`(SHA-256 `d398b7dd7fc1fe48942625e463b2e881ebbe58c7831b2e45f403d4d850a2efe1`).
- 바탕: `vers_string -l libDriver` 출력(Darwin 0.1 driverkit-1/libDriver/Makefile:612; 실기 vers_string 확인).
- 고친 것: 정적 `SGS_VERS[160]`(기호 없음)을 원본 바이트대로 썼습니다.
- 링크 자리: 원본 데이터 순서(plan 397 항목 12; Darwin conf/files·files.i386·Makefile.template 의 차례와 같음).
- 진단(07 손대지 않음): s6p397-vd1(plan 397 항목 8).
- 최종: 07 에서 재빌드 s6l1-g2ba(행 402, 06_reconstruction/l2_build_forms-s6p398.tsv; 꼴 plan398-template:x86-IODirectDevice), L1 `09_validation/reconstruction/s6l1-g2ba-l1-402.json` **OBJECT_MATCH** (`--place __TEXT,__const=0x1d647c`), `cc -M` 의존 모두 07.
- diff: `06_reconstruction/evidence/x86-libDriver_vers.diff`(/dev/null 대비, 원문 없음).
