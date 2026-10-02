# x86 `kern_machdep.c` — `_check_cpu_subtype`, `_grade_cpu_subtype` (S5-P2, 2026-10-01)

원본 SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`.

## 헤더 환경(가설, 계획 18·18.1)
- 소스·헤더는 Darwin 0.1 트리 배치 그대로: `07_kernel/src/`(kernel), `07_kernel/components/architecture/`. 채택 21 파일과 SHA-256: `x86-kern_machdep.files.json`, 라이선스 표기 조사: `x86-kern_machdep.notices.json`(20 개 APSL 머리말, `components/architecture/i386/ansi.h` 는 UC Berkeley 표기만).
- 옵션 `-arch i386 -static -fno-common -fwritable-strings -traditional-cpp -nostdinc`, 정의 `-DARCH_PRIVATE -D_KERNEL -DKERNEL -DKERNEL_PRIVATE -DDRIVER_PRIVATE -DKERNEL_BUILD -DNeXT -D_NEXT_SOURCE`(Darwin `conf/Makefile.template:103–105`, `$(IDENT)` 는 S4 몫·`$(MACHINE_DEFINES)` 는 빈 값), include `-I07_kernel/generated`(빈 자리) `-Isrc -Isrc/bsd -Isrc/bsd/include -Isrc/machdep -Icomponents -Icomponents/architecture`.
- 전처리 기록(`s5p2-pre-2`, `09_validation/reconstruction/s5p2-preprocess-20261001.json`): 읽힌 파일 21(소스 1 + 헤더 20), `__APPLE__` 유무로 매크로 차이는 `__APPLE__` 하나·전처리 텍스트 동일(`identical_text: true`). 조건식에 쓰였으나 정의되지 않은 식별자 17 개(`undefined_conditionals`)는 모두 컴파일러·표준·다른 아키텍처 매크로이고 커널 설정 옵션은 없다. `-nostdinc` 에서 `<stdarg.h>` 는 "No include path in which to find stdarg.h"(`s5p2-stdarg-1`, 게시 안 됨, 로그만). 빈 파일에서도 미리 정의되는 매크로 27 개(`NeXT`, `__i386__`, `NX_CURRENT_COMPILER_RELEASE` 등).

## 빌드(`s5p2-build-1`, 입력 = `07_kernel` 스냅샷)
- `-O2`·`-O3`·`-O4`·`-O2 -D__APPLE__` 네 목적 파일이 모두 같은 SHA-256(앞 16 자리 `b7e5bff76c05ca97`). 07_kernel 스냅샷에서도 읽힌 파일 21.

## 대조
- 목적 파일 `__text` 365 B, 심볼 `_check_cpu_subtype` 0 · `_grade_cpu_subtype` 144, 외부 `_machine_slot`. 원본은 `_check_cpu_subtype` 0x18cac8 · `_grade_cpu_subtype` 0x18cb24(간격 92 B), Ghidra `_grade_cpu_subtype` 끝 0x18cbca(166 B).
- 이름으로 배치하면 두 함수가 서로 다른 Δ 를 줘 배치 거부(목적 파일 안 간격 144 ≠ 원본 92): 저장된 L1 결과 `09_validation/reconstruction/s5p2-l1-{O2,O3,O4,O2apple}-20261001.json` 은 모두 `NOT_MATCH`(`__TEXT,__text: unverified`). 함수별 강제 배치 진단도 DIFF 였으나 그 출력은 보존하지 않았다(수치 인용 안 함).
- 원본 `_check_cpu_subtype` 역어셈블(capstone, 0x18cac8–0x18cb23, `x86-kern_machdep.check_cpu_subtype.disasm.txt`): `machine_slot[0].cpu_subtype`(`_machine_slot` 0x1e8e00 + `cpu_subtype` 오프셋 8 = 0x1e8e08, `cpu_number()` 는 상수 0 으로 접힘) 로 분기 — 386(3)·486(4)/486SX(0x84)·586(5) 세 경우와 그 밖 0 반환. 586 은 요청 4·5·0x84·3 허용. Darwin 판은 같은 경우들에 더해 `default:` 에 `CPU_SUBTYPE_INTEL_MODEL`/`FAMILY` 비교 분기가 있다 → **Darwin 0.1 판이 원본보다 나중 판**(가설, 차이 위치가 이 분기로 설명됨). NeXTMach `mk-108.1/next/kern_machdep.c` 는 m68k 용으로 대안이 아니다.
- `_grade_cpu_subtype` 의 차이는 아직 분석하지 않음.

## 결론
헤더 환경은 의도대로 작동(채택 21 파일만으로 전처리·컴파일)하지만 이 파일의 후보 소스는 원본과 판이 달라 L1 일치하지 않는다. 계획 18 의 6 에 따라 소스를 원본에 맞추는 수정은 하지 않았다(별도 결정). 확정 목적 파일 없음.

## S5-P3: 복원 수정 H1 (2026-10-01, 결정 D014, 계획 19)
- 원본 동작: 두 함수 모두 Darwin 판의 네 `case` 와 같고 그 밖 subtype 은 0. 근거 — 역어셈블 `x86-kern_machdep.check_cpu_subtype.disasm.txt`, `x86-kern_machdep.grade_cpu_subtype.disasm.txt`; unicorn 실행 144 쌍 차이 0(`09_validation/reconstruction/s5p3-semantics-emu-20261001.json`).
- 수정: 두 `default:` 아래 Intel family/model 분기 삭제(check → `break;`, grade → `return 0;`), 머리말 뒤 수정 표시 주석 1 줄. diff `x86-kern_machdep.diff`, 기록 `07_kernel/MODIFICATIONS.md`. 수정 후 파일 SHA-256 `0d4c7b6acb1abf9c61ace77705dba2eadd16a1217aa66872e0925cc3fdc035f6`.
- 빌드 `s5p3-build-1`(입력 `07_kernel`, 명령 `08_build/runs/tools/s5p3-build.cmd`): `-O2`·`-O3`·`-O4` 목적 파일 동일(SHA-256 `3f9350dceba43f986863548c395ec06276662595924caa43d9c854e00722e7d8`).
- 예측(계획 19) 대 결과: `__text` 258 B ✓, `_grade_cpu_subtype` 오프셋 92 ✓, 외부 참조 `_machine_slot` 만 ✓, 재배치 2 ✓.
- L1(`--place-from-image`, Ghidra 몸체 범위): 두 함수 MATCH(바이트 차이 0, 참조 각 1 개 일치), 목적 파일 OBJECT_MATCH, 배치 0x18cac8 (`09_validation/reconstruction/s5p3-l1-{O2,O3,O4}-20261001.json`).
- 경계 증명서: 목적 파일 `__text` 정렬 2^2, 끝 0x18cbca. 앞 틈 0x18cac5–0x18cac8 `00`×3, 뒤 틈 0x18cbca–0x18cbcc `00`×2 — 둘 다 최소 정렬 채움과 같음(Python). → 목적 파일 **A**(`objects_confirmed.tsv`), 두 함수 `compared/high`.
- 변형 B(`default:` 삭제)는 빌드하지 않음: 변형 A 가 일치했고 diff 가 더 작다(계획 19 의 선택 기준).
