# x86 `objc_vers.c` 데이터만 있는 목적 파일 — `x86-objc_vers` (plan 397·398, 2026-10-08)

원본: `03_original/x86/binaries/mach_kernel` SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. 이 객체는 `__text` 가 없습니다.

- 원본 절(재빌드 L1 배치): __TEXT,__const=0x1d6754+170.
- 07 파일: `07_kernel/src/objc-runtime/objc_vers.c`(SHA-256 `6fe821121246077e6bb51d1d6eee34db362c783cc995df9298a62111a4633d5f`).
- 바탕: `vers_string -c objc` 출력과 Darwin 0.1 objc common.make:201–203 의 sed 이름 바꿈(실기 /usr/bin/vers_string 확인).
- 고친 것: `objc_VERS_STRING[160]`·`objc_VERS_NUM[10]` 을 원본 바이트대로 썼습니다.
- 링크 자리: 원본 데이터 순서(plan 397 항목 12; Darwin conf/files·files.i386·Makefile.template 의 차례와 같음).
- 진단(07 손대지 않음): s6p397-vo1(plan 397 항목 8).
- 최종: 07 에서 재빌드 s6l1-g4a(행 401, 06_reconstruction/l2_build_forms-s6p398.tsv; 꼴 plan398-template:x86-objc_zone), L1 `09_validation/reconstruction/s6l1-g4a-l1-401.json` **OBJECT_MATCH**, `cc -M` 의존 모두 07.
- diff: `06_reconstruction/evidence/x86-objc_vers.diff`(/dev/null 대비, 원문 없음).
