# x86 `counters.c` 데이터만 있는 목적 파일 — `x86-counters` (plan 397·398, 2026-10-08)

원본: `03_original/x86/binaries/mach_kernel` SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. 이 객체는 `__text` 가 없습니다.

- 원본 절(재빌드 L1 배치): __DATA,__data=0x1deb44+20.
- 07 파일: `07_kernel/src/kern/counters.c`(SHA-256 `a05e343173d2a2edde79862584f21ba914d915fed5a56e0ecc59c9bce918e050`).
- 바탕: Mach4 kernel/kern/counters.c.
- 고친 것: `#include <mach_counters.h>` 한 줄을 주석으로 바꿨습니다(07 에 없음; MACH_COUNTERS 는 `<kern/counters.h>` → `<mach/features.h>`).
- 링크 자리: 원본 데이터 순서(plan 397 항목 12; Darwin conf/files·files.i386·Makefile.template 의 차례와 같음).
- 진단(07 손대지 않음): s6p397-ct1·ct2(plan 397 항목 8).
- 최종: 07 에서 재빌드 s6l1-g1a(행 393, 06_reconstruction/l2_build_forms-s6p398.tsv; 꼴 plan398-template:x86-ast), L1 `09_validation/reconstruction/s6l1-g1a-l1-393.json` **OBJECT_MATCH**, `cc -M` 의존 모두 07.
- diff: `06_reconstruction/evidence/x86-counters.diff`(참조 원문 대비).
