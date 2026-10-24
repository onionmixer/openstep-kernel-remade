# 커널 소스 복원 작업계획 — 보관 §495–508

`02_plan/RECONSTRUCTION_PLAN.md` 의 §495–508(m68k M4 시작: 목록화, 컴파일 경로, `checksum_16`·`dkbad`·`ufs_machdep`·`vm_unix`·`cons`·`bus`·`nbic`·`next_table`; 결정 D103–D106)을 절 번호·내용 그대로 옮긴 보관본입니다(2026-10-24, D026 방식, 사용자 지시 “02_plan/RECONSTRUCTION_PLAN.md 문서를 알맞게 정리”). §505 안의 "505.3" 머리는 원문 그대로 `##` 수준입니다(§505 의 일부). 본문은 `---` 아래부터입니다.

---

## 495. M4-1 세부 계획 — m68k 머신 의존부 목록화와 작업 순서(07 변경 없음; 코딩 전, 2026-10-24)

배경: M5 공통부 208 객체 가운데 206 이 코드 검증되었습니다(§494). 다음 단계는 M4(머신 의존부)입니다. M4 대상은 M2 표 `06_reconstruction/m68k-objects.tsv`(§423) 가운데 M5 208(§429 정의: `m68k-text-objects.tsv` 의 contiguous 237 중 소스가 `.c` 이고 `/i386/` 밖) 이 아닌 항목입니다. 이 절은 무엇을 어떤 순서로 할지 정하는 표만 만듭니다. 컴파일도 07 변경도 없습니다.

확인한 사실(이번 세션, python):
- `m68k-objects.tsv` 396 행(id 중복 없음): 종류 x86 237·file 106·unassigned 33·data-only 11·data-unlinked 5·bracket 4.
- §429 정의를 다시 적용하면 M5 208, M4 188 행입니다. M4 = file 106·unassigned 33·x86 29·data-only 11·data-unlinked 5·bracket 4.
- x86 종류 가운데 M5 밖 29: `start.s`, `/i386/` 의 C 소스(`intr`·`mem`·`cons`·`i386_init`·`unix_startup`·`vm_machdep` 등), `/i386/libc/` 의 문자열 함수, ObjC 소스 `kmDevice.m`·`SCSIDiskKern.m`·`SCSIGenericKern.m`·`swapgeneric.m`, `driverkit/memcpy.c`.
- file 106 의 이름(NeXTMach 파일 경로)은 모두 `01_resources/upstream/nextmach/mk-108.1` 에 있습니다. 디렉터리별로 nextdev 33·fpsp 44·next 23·nextif 3·vm 1·bsd 1·kern 1 입니다.
- `m68k-functions.tsv`(§424) 3570 행 가운데 M4 객체에 든 함수는 1053(215874 B), M5 객체는 2309(399030 B), `object_id` 가 빈 것은 208(63606 B)입니다.

방법(새 도구 `10_tools/reconstruction/m4_m68k_inventory.py`; 입력 표만 읽고 출력 둘만 씀):
- 출력: `06_reconstruction/m68k-m4-inventory.tsv`, 기록 `09_validation/reconstruction/m4-m68k-inventory-20261024.json`(입력 SHA-256, 집계, 검사 결과).
- 행마다(M4 188): id, 종류, 이름, 경계(정확 여부), 바이트 최소·최대, 함수 수·이름 있는 함수 수(`m68k-functions.tsv` 의 `object_id`), x86 대응 07 경로(x86 종류만).
- NeXTMach 정의 대응: §420 의 색인(`m2_m68k_unmapped.build_set`·`index`·`resolve`, 빌드 집합 `conf/files`·`files.NeXT`·locore·scb·fpsp)을 그대로 씁니다. 객체의 함수 이름마다 정의 파일을 찾아, 가장 많이 나온 파일을 후보 파일로, 그 파일에서 정의된 이름 수/이름 있는 함수 수를 대응률로 적습니다. 언어는 후보 파일의 확장자(.c·.s·.sa)이고, 후보가 없으면 `unknown` 입니다.
- 묶음(미리 정함):
  - A 어셈블리(후보 파일이 `.s`·`.sa`)
  - B `next/` C
  - C `nextdev/`·`nextif/` C
  - D 그 밖의 NeXTMach C(`vm/`·`bsd/`·`kern/`)
  - E x86 이름 대응 29 가운데 후보 NeXTMach 파일이 없는 것
  - F bracket 4
  - G unassigned 가운데 후보 NeXTMach 파일이 없는 것
  - H 자료 전용(data-only·data-unlinked 16)
  - x86 종류·unassigned·bracket 이라도 후보 NeXTMach 파일이 정해지면 그 언어·디렉터리 묶음(A–D)에 넣고, 원래 종류는 열로 남깁니다.
- 묶음별 집계(python): 행 수, 바이트 최소·최대 합, 정확 경계 수, 대응률 100% 인 행 수.
- 참고 글은 옮기지 않고 경로·줄 번호만 적습니다(§420 과 같음).

검사(미리 정함; 하나라도 어긋나면 멈추고 보고):
1. 출력 행 = 188, id 가 M4 집합과 정확히 같음(M5 208 과 겹침 0).
2. 묶음은 행마다 하나, 묶음 합 = 188.
3. file 종류 106 행은 후보 파일이 이름(경로)과 같아야 합니다. 다르면 행 목록을 기록하고 멈추지 않되, 이유를 결과에 적습니다(M2 의 file 이름은 약한 후보였기 때문, §420).
4. 함수 수 합 = 1053, 바이트 합 = 215874(이번 세션 python 값과 같음).
5. 도구를 두 번 돌려 두 출력 SHA-256 이 같음.

이 절 뒤(따로 계획): 묶음과 대응률로 첫 대상을 고르고, m68k 전용 파일의 컴파일 경로(머리 집합, 컴파일 줄 꼴, `as` 경로)를 시험하는 진단을 계획합니다.

### 495.1 교차검토(codex `gpt-6.1-sol`) 판정과 계획 수정

제 오류가 둘 있습니다.
- 위 "확인한 사실" 의 `driverkit/memcpy.c` 는 틀렸습니다. `m68k-text-objects.tsv` 에 `x86-memcpy` 가 두 행(n 6 `machdep/i386/libc/memcpy.c` contiguous, n 201 `driverkit/memcpy.c` absent)이고, 제가 사전으로 이은 탓에 뒤 행을 골랐습니다. M5 밖 x86 종류 29 의 memcpy 는 `machdep/i386/libc/memcpy.c` 입니다.
- "M4 객체에 든 함수 1053" 은 진입점 수입니다. 함수 후보 1030(213022 B)과 자료 이름 23(2852 B)입니다.

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 396·종류별 수·M5 208·M4 188·file 디렉터리별 수·1053/215874·2309/399030·208/63606 이 맞음; file 106 은 서로 다른 경로 88 | python 재계산 | ✅ |
| `driverkit/memcpy.c` 는 absent 이고 맞는 출처는 `machdep/i386/libc/memcpy.c`; 이름으로 이으면 사전이 엉뚱한 행을 고름 | python: `x86-memcpy` 두 행, contiguous 안에서는 중복 0 | ✅ 제 오류. contiguous 로 거른 뒤 정확히 한 행이 대응해야 함 |
| C 정의는 `_` 를 붙여, 어셈블리 라벨은 적힌 그대로 색인됨; FPSP 이름은 `_` 가 없음(`decbin`) | `m2_m68k_unmapped.py:65,70,73`; `m68k-functions.tsv` 3372 행 `decbin`(자료 이름, m68k-327) | ✅ 이름은 적힌 그대로 씀 |
| `_bcmp`·`_strlen` 은 C 와 어셈블리 정의가 함께 있어 모호 | `bsd/subr_xxx.c:184`·`next/libc.s:28,471`, python `index` 출력 | ✅ |
| 비 static 우선은 휴리스틱; `_busdone` 은 `bus.c` 를 고르고 `od.c` 의 static 은 버림; 조건부 컴파일은 평가하지 않음 | python `index`: `bus.c:54` 와 `od.c:1472`(static; codex 의 1468 은 그 앞 주석 구역), `resolve` → bus.c | ✅ 후보는 약한 후보(§420)로 표시 |
| 대응률은 이름 있는 진입점 단위(별칭 중복 제거)여야 함; m68k-004 는 별칭 30·진입점 28/50 | python: 별칭 30, 진입점 28 | ✅ 진입점 단위로 셈 |
| A–H 가 모든 행을 덮지 못함: file 13 행은 후보 없음(m68k-236·239·363 등) | python: 13 행, 모두 이름 있는 진입점 0 | ✅ 묶음 I 를 더함 |
| bracket 넷 가운데 셋(`in_bootp`·`pmap`·`trap`)은 C 후보가 생겨 F 에는 하나만 남음 | python: `machine_clock` 만 후보 없음 | ✅ F 를 "후보 없는 bracket" 으로 정의 |
| 검사 보강: 중복·대응 안 되는 이음, 매달린 `object_id`, 후보 동률, 정의 안 된 묶음, 경계 오류, 대응률 > 분모, 함수 표 전체 맞춤, NeXTMach·도구 해시 | 설계 | ✅ 아래에 고정 |
| file 행 불일치를 일괄 허용하면 다른 오류가 지나감 | 설계; python 으로 지금 불일치 0 | ✅ 불일치가 하나라도 있으면 멈춤(더 엄격하게) |
| 비정확 경계 M4 74 행; `object_id` 는 `[start_hi, end_lo)` 로만 줌(`_start` 도 빠짐) | python 74; `m2_m68k_functions.py:280–286` `obj_of`; 표 3 행 `_start` 의 `object_id` 빈칸 | ✅ 빈 `object_id` 208 을 따로 진단 |
| FPSP 는 빌드에서 미리 만든 `fpsp/fpsp.o`(`.sa` 변환 → 조립 → `ld -r`) | `conf/files.NeXT:79`, `fpsp/Makefile:15–16,26–27` | ✅ 빌드 단위 열을 둠 |
| 약한 후보 표시(§420) 유지 | 보관 계획 409–436 의 932 행 | ✅ |

계획 수정(실행 전 고정):
- 이음: x86 종류 행은 `m68k-text-objects.tsv` 의 contiguous 행과 정확히 하나가 대응해야 합니다. 아니면 멈춥니다.
- 진입점 셈: 종류(함수 후보·자료 이름)와 confirmed 를 나눠 적습니다.
- 이름 해석: 이름은 적힌 그대로 씁니다. 진입점마다 상태를 적습니다(해석됨·없음·모호·이름 없음). 후보 파일은 해석된 진입점이 가장 많은 파일입니다. 1 위가 둘 이상이면 `tie` 로 두고 묶음은 후보 없음 쪽으로 보냅니다. 대응률 = 후보 파일로 해석된 진입점 수 / 이름 있는 진입점 수입니다. NeXTMach 후보는 모두 약한 후보(§420)입니다.
- 묶음(우선순위 순서, 행마다 처음 맞는 하나):
  - H 자료 전용(data-only·data-unlinked)
  - A 후보 파일이 `.s`·`.sa`
  - B 후보 파일이 `next/` 의 `.c`
  - C 후보 파일이 `nextdev/`·`nextif/` 의 `.c`
  - D 그 밖의 후보 `.c`
  - I 후보 없는 file 종류(M2 의 약한 file 이름만 있음)
  - E 후보 없는 x86 종류
  - F 후보 없는 bracket
  - G 후보 없는 unassigned
- 열 추가: 빌드 단위(`fpsp/*.sa` → `fpsp/fpsp.o`; `next/locore.s`·`next/scb.s` → `locore.o`; 그 밖은 후보 파일), 같은 후보 경로를 가진 행 수, §423 `basis`(정적 다리 표시 포함).
- 기록에 `object_id` 가 빈 진입점 208 의 진단을 둡니다. 진입점마다 그 주소를 `[start_lo, end_hi)` 에 품는 M4·M5 행 목록입니다.
- 입력 해시: 세 표, `m2_m68k_unmapped.py`, 이 도구, NeXTMach 빌드 집합 파일 목록과 각 SHA-256.

검사(위 1–5 를 바꿈; 하나라도 어긋나면 멈춤):
1. 출력 188 행, id 가 M4 집합과 같고 M5 와 겹침 0, x86 종류 이음은 모두 한 행.
2. 묶음은 행마다 정의된 하나, 묶음 합 188.
3. file 종류 가운데 후보가 있는 행은 후보 파일이 이름과 같음(불일치 0).
4. 함수 표 맞춤: M4·M5·빈 `object_id` 진입점 수 합 = 3570, 바이트 합 = 678510, M4 = 1053/215874(함수 후보 1030/213022, 자료 이름 23/2852). 표의 모든 `object_id` 는 객체 표에 있음.
5. 경계: 모든 행 `start_lo ≤ start_hi`, `end_lo ≤ end_hi`, 바이트 최소 ≤ 최대(자료 전용은 빈칸 허용). 대응률 분자 ≤ 분모.
6. 두 번 돌린 출력 SHA-256 이 같음.

### 495.2 결과(2026-10-24)

- 도구 `10_tools/reconstruction/m4_m68k_inventory.py`. 출력 `06_reconstruction/m68k-m4-inventory.tsv`(SHA-256 `1fa0b9503ab3838113b0ca55f550da22757f7d9711d10b9e25a92c666a21462f`)와 기록 `09_validation/reconstruction/m4-m68k-inventory-20261024.json`.
- 검사 1–6 모두 통과했습니다. scratchpad 에 한 번 더 돌린 출력과 TSV 가 같고, 기록 JSON 도 출력 경로 말고는 같습니다.
- 묶음(행 수, 바이트 최소–최대, 정확 경계 수):

| 묶음 | 뜻 | 행 | 바이트 | 정확 |
|---|---|---|---|---|
| A | 어셈블리 후보(`.s`·`.sa`) | 51 | 28300–61618 | 23 |
| B | `next/` C | 26 | 31342–31780 | 24 |
| C | `nextdev/`·`nextif/` C | 35 | 129856–179122 | 17 |
| D | 그 밖의 C(`vm/vm_unix.c`·`bsd/tty_pty.c`·`kern/thread.c`) | 3 | 2314–2388 | 2 |
| E | 후보 없는 x86 종류 | 10 | 2940–3534 | 7 |
| F | 후보 없는 bracket(`machine_clock`) | 1 | 1204 | 1 |
| G | 후보 없는 unassigned | 33 | 19918–37800 | 24 |
| H | 자료 전용 | 16 | — | — |
| I | 후보 없는 file 종류(이름 있는 진입점 0) | 13 | 0–21872 | 0 |

- x86 이름 대응 29 가운데 19 는 NeXTMach 후보가 생겼습니다. 문자열 함수 7 과 `memcpy` 는 `next/libc.s`, `intr` 은 `next/locore.s`, `mem`·`cons`·`checksum_16`·`dkbad`·`in_cksum`·`kern_machdep`·`ufs_machdep`·`unix_startup` 은 `next/` 의 C 입니다. `kmDevice`·`SCSIDiskKern`·`SCSIGenericKern` 은 `nextdev/km.c`·`sd.c`·`sg.c` 이고, m68k 에는 ObjC 가 없습니다. 후보가 없는 10 은 i386 전용 이름(`APM_i386`·`i386_init`·`kdp_machdep`·`miniMonMachdep`·`swapgeneric` 등)입니다.
- `object_id` 가 빈 진입점 208 가운데 193 은 M4 행의 `[start_lo, end_hi)` 안에, 15 는 M5 행 안에 있습니다(비정확 경계 탓).
- 빌드 단위는 57 개(115 행)입니다. `fpsp/fpsp.o` 는 36 행 52264 B(최대), `locore.o` 는 3 행 8182 B 입니다. 한 소스가 여러 행인 경우가 있습니다(`next/mem.c` 3 행 등).
- 모든 행이 정확 경계이고 대응률 100% 인 빌드 단위는 21 개, 29416 B 입니다. 작은 것부터 `nextdev/snd_rcv.c` 24, `next/checksum_16.c` 86, `next/dkbad.c` 92, `nextdev/nbic.c` 94, `next/nextdbgasm.s` 136, `next/machargs.c` 172, `next/us_timer.c` 188, `next/in_cksum.c` 212, `nextdev/bus.c` 228 B … `nextdev/np.c` 9116 B 입니다.
- 한계: NeXTMach 후보는 약한 후보입니다(§420; 같은 이름 정의 기준, 조건부 컴파일 평가 없음). 대응률 100% 는 이름이 그 파일에 정의되어 있다는 뜻일 뿐, 1990 년 글이 1997 년 바이트와 같다는 뜻이 아닙니다.

다음(따로 계획): 위 21 개 가운데 작은 `next/` C 몇 개로 m68k 전용 파일의 컴파일 경로를 진단합니다. 머리 집합(NeXTMach `next/*.h` 의 필요 여부와 SDK 와의 관계), 컴파일 줄 꼴(M5 의 x86 줄이 없음), 07 에서 둘 자리(07 본 트리 `machdep/m68k` 또는 `v183.34/m68k` 덮어쓰기)를 정합니다. 둘 자리는 사용자 결정 사항입니다.

## 496. M4-2 세부 계획 — m68k 전용 C 파일의 컴파일 경로 진단(작은 `next/` 넷; 07 변경 없음; 코딩 전, 2026-10-24)

배경: §495 의 첫 대상 후보 21 개 가운데, 머리가 `sys/`·`machine/spl.h` 뿐이고 07 에 x86 대응 파일이 있는 넷으로 M4 의 컴파일 경로를 시험합니다.

확인한 사실(이번 세션):
- 대상 넷(§495 목록, 모두 묶음 B, 정확 경계, 대응률 100%, x86 종류):
  - `m68k-265` `x86-checksum_16` 86 B: NeXTMach `next/checksum_16.c`(머리 `sys/types.h`). 07 x86 `machdep/i386/checksum_16.c` 의 출처는 Darwin 0.1(PROVENANCE 98 행).
  - `m68k-271` `x86-dkbad` 92 B: `next/dkbad.c`(`sys/param.h`·`sys/buf.h`·`sys/dkbad.h`). 07 x86 은 NeXTMach `next/dkbad.c` 바탕(587 행).
  - `m68k-272` `x86-in_cksum` 212 B: `next/in_cksum.c`(`sys/types.h`·`sys/mbuf.h`). 07 x86 은 작성(D024, 607 행).
  - `m68k-321` `x86-ufs_machdep` 372 B: `next/ufs_machdep.c`(`sys/*`·`machine/spl.h`). 07 x86 은 NeXTMach `next/ufs_machdep.c` 바탕(585 행).
- 여덟 파일 모두 따옴표 `#include`/`#import` 가 없습니다(grep 0).
- m68k 스테이징 `m0p494-a1-stage`(888 파일)에 `src/machdep/i386/` 104 파일이 있고, `machine/spl.h`·`sys/dkbad.h`·`sys/mbuf.h`·`sys/types.h` 는 `07_kernel/nextdev`(SDK 사본)에서 옵니다. `next/` 머리는 없습니다.
- x86 컴파일 줄(`s6l4-g1a.cmd`)은 넷 모두 하나씩이고, 정의는 M5 와 같은 표준 집합입니다.
- 원본 m68k 커널에는 소스 경로 문자열이 없습니다(`machdep/`·`m68k/`·`next/`·`.c` 0 건). 07 에서 둘 자리는 바이트로 정해지지 않습니다.

방법(새 도구 `10_tools/reconstruction/m4_m68k_probe.py`, 명세 `08_build/artifacts/m4p496/spec.json`, 둘 다 git 밖 산출물만 씀):
- 변형(대상마다 둘):
  - N: NeXTMach `next/<f>.c` 원문 그대로. 스테이징 사본을 `src/src/m4probe/next/<f>.c` 에 둡니다(무시되는 `08_build/runs` 안).
  - X: 07 x86 `machdep/i386/<f>.c` 를 그대로(스테이징에 이미 있는 자리).
- 스테이징: `m0p494-a1-stage` 를 복사하고 N 파일 넷만 더합니다. 다른 파일 항목이 바뀌지 않았는지 매니페스트로 확인합니다.
- 컴파일 줄: 대상의 x86 줄에 §429 규칙(`-arch i386`→`m68k`, `-g -O3 -fno-omit-frame-pointer`→`-g -O2`, `-fwritable-strings` 뺌; 각각 정확히 한 번)을 적용합니다. 그 결과 `-D`·`-I` 집합이 M5 m68k 줄(`m5p494-a1`)과 같은지 확인합니다. `-c` 와 `-o stage/Q496__<f>_<V>.o` 만 바꿉니다.
- run `m4p496-p1`(`kr_run.py`). 명령마다 종료 코드와 오류 첫 줄을 기록합니다. 실패도 결과입니다(빠진 머리 목록).
- 비교:
  - 컴파일된 객체마다 L1(`m0_m68k_cause.run_l1`, `--place-from-image`)의 판정·사유를 적습니다.
  - 원본에 없는 미정의 기호를 적습니다.
  - N·X 가 같은 객체인지(canon·obj_sig)를 적습니다.
  - OBJECT_MATCH 가 아니면 실기 `otool -tv` 목록을 원본 함수와 숫자를 가린 명령 열로 맞대어(§490 방식) 차이 줄 수를 적습니다.
- 기록 `09_validation/reconstruction/m4-m68k-probe-p496-20261024.json`(입력·도구·명세 SHA-256, 명령, 결과). NeXTMach 원문은 기록하지 않습니다.

판정(미리 정함; 진단이므로 07 은 바꾸지 않음):
- OBJECT_MATCH(또는 사유가 bss 하나)인 변형은 그 대상의 후보 꼴입니다. 07 에 넣는 일은 둘 자리(사용자 결정)와 함께 따로 계획합니다.
- 맞지 않으면 차이를 적고 원인 후보만 기록합니다.
- 컴파일 실패는 빠진 머리·정의의 목록으로 남깁니다.

관문(어긋나면 멈추고 보고):
1. 스테이징 매니페스트가 바탕과 N 파일 넷 말고 같음.
2. 여덟 컴파일 줄이 위 규칙으로 만들어지고 `-D`·`-I` 집합이 M5 줄과 같음.
3. run 상태 파일이 여덟 명령을 모두 담음(종료 코드는 결과로 기록).
4. `kr_run` 결과 SHA 검증 통과.

### 496.1 교차검토(codex `gpt-6.1-sol`) 판정과 계획 수정

제 오류가 둘 있습니다.
- 관문 2 는 실행 전부터 맞지 않습니다. `checksum_16` 의 x86 줄(`s6l4-g1a.cmd`)에는 `-Isrc/components/driverkit-1` 이 없습니다(코드 검토와 별도로 python 으로 먼저 찾았고, 회신도 같음). §429 규칙은 파일마다 자기 x86 줄을 쓰는 것이므로, M5 줄과 같을 것을 요구한 것이 잘못입니다.
- "원본에 소스 경로 문자열이 없다" 는 제가 찾은 낱말(`machdep/`·`m68k/`·`next/`·`nextdev/`·`.c`·`.s`)에 대해서만 맞습니다.

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 대상 넷의 id·크기·출처·머리·따옴표 include 0·스테이징 내용이 맞음 | §495 목록·PROVENANCE 98·585·587·607 행, grep, 매니페스트(python) | ✅ |
| `checksum_16` 줄에 `-Isrc/components/driverkit-1` 이 없어 관문 2 가 멈춤; 나머지 셋은 같음; `-D` 는 넷 모두 같음 | python: 변환 뒤 집합 비교 | ✅ 관문을 고침(아래) |
| 줄의 `-I` 는 순서도 비교해야 함 | 설계(앞선 경로가 이김) | ✅ M5 줄과의 차이를 순서 있는 목록으로 기록 |
| `_checksum_16`·`_isbad`·`_in_cksum`·`_allocbuf`·`_bfree` 는 원본에서 하나씩 정의됨 | `03_original/m68k/inventory/symbols.tsv` 320·1340·1000·170·220 행(python) | ✅ |
| 배치는 첫 외부 기호가 아니라 절의 모든 비 STABS 기호가 한 delta 로 모여야 함; 같은 이름이 여럿이면 버림 | `l1_compare.py:80–83`(`symbol`), `:468–479`(`placements_from_image`) | ✅ 계획 문구를 고침 |
| 원본 `_in_cksum` 은 바로 뒤 `_oc_cksum` 을 부르고, NeXTMach `in_cksum.c` 에는 그 호출이 없음 | 원본 목록 `bsr 0x40928a8` 3 회(0x40927fa·0x4092844·0x4092890), `_oc_cksum` = `m68k-273`(§495 G), NeXTMach grep 0 | ✅ N `in_cksum` 이 안 맞는 것은 예상된 구조 차이로 미리 적음 |
| X `in_cksum.c` 에 i386 인라인 어셈블리 | `07_kernel/src/machdep/i386/in_cksum.c:25` | ✅ 실패는 "아키텍처 전용 어셈블리" 로 따로 분류 |
| X `checksum_16` 은 무조건 `NXSwapShort` 를 쓰고 m68k 에서도 바이트를 바꿈 | `checksum_16.c:41`, 스테이징 `architecture/m68k/byte_order.h:15–19` | ✅ 기록 |
| N·X 가 `dkbad`·`ufs_machdep` 는 같은 글이고, 나머지 둘은 다름 | python 문자열 비교 | ✅ 기록(같은 글이면 한 변형으로 봄) |
| `kr_run collect` 는 종료 코드 0 이 아니거나 EXPECT 객체가 없으면 게시하지 않음 | `kr_run.py:327–329`, `:340–345` | ✅ 아래 방식으로 고침 |
| `run_l1` 은 `--ranges` 를 주지 않고, L1 은 다시 만든 절 크기만큼만 비교 → 앞부분만 맞아도 맞음이 될 수 있음 | `m0_m68k_cause.py:140–147`, `l1_compare.py:322`(`img.read(addr, s['size'])`) | ✅ 크기·함수 집합 관문을 더함 |
| bss 하나 사유는 따로 잠정으로 | `l1_compare.py:315–318` | ✅ 판정을 나눔 |
| `machine/spl.h` 는 `ARCH_INCLUDE` 로 아키텍처를 고름; 실제 머리 폐포는 확인 안 됨 | 스테이징 `bsd/machine/spl.h:9–11`, `ARCH_INCLUDE.h` | ✅ `-M` 명령을 더해 확인 |
| 원본의 정적 참조 감사는 확인 안 됨 | 설계 | ⚖️ 이번 객체는 정적 함수가 없음(§495: 이름 없는 진입점 0); 맞음 판정에 L1 참조 검증을 그대로 씀 |

계획 수정(실행 전 고정):
- 관문 2: 컴파일 줄은 대상마다 자기 x86 줄에 §429 치환을 정확히 한 번씩 적용해 만듭니다. M5 m68k 줄과의 `-D`·`-I` 차이는 순서 있는 목록으로 기록하고 멈추지 않습니다. 단 `-arch i386`·i386 경로·i386 정의가 남으면 멈춥니다.
- 명령: 변형마다 `-c … -o` 컴파일 하나와, `-o` 를 빼고 `-M` 을 넣은 의존 목록 명령 하나를 둡니다(16 명령).
- 실행·수집: `kr_run.py prepare/launch/wait` 뒤 `collect` 를 부르지 않습니다. 도구가 게시 전 run 디렉터리를 읽습니다. `collect` 의 검사 가운데 종료 코드 0 과 EXPECT 존재를 뺀 나머지를 모두 합니다.
  - 도구 해시 같음, 비정규 파일·하드 링크 없음, 상태 줄 수 = 명령 수
  - 스테이징 파일 집합 = `output.manifest`, 파일마다 해시·크기 같음
- 결과 분류: 종료 0(경고 수 기록), 머리·정의 없음, 아키텍처 전용 어셈블리, 그 밖의 오류.
- 의존 목록: 변형마다 `architecture/m68k`·`architecture/i386` 경로 수와 07 밖 출처를 적습니다. `architecture/i386` 이 하나라도 있으면 그 변형의 비교 결과를 "i386 머리 섞임" 으로 표시합니다.
- 맞음 판정(더 엄격하게):
  - 후보 꼴: L1 OBJECT_MATCH
  - 잠정 후보: 사유가 정확히 `['__DATA,__bss: unverified']`
  - 둘 다 아래를 모두 만족해야 합니다.
    - `__TEXT,__text` 크기가 §495 목록의 정확 바이트와 같음
    - 객체의 외부 텍스트 기호 집합이 원본 범위의 이름 집합과 같음(`m68k-functions.tsv`)
    - 원본에 없는 미정의 0
- N `in_cksum` 이 맞지 않는 것은 미리 예상한 구조 차이(`_oc_cksum` 호출 없음)로 기록합니다.

### 496.2 결과(2026-10-24)

- 도구 `10_tools/reconstruction/m4_m68k_probe.py`, 명세 `08_build/artifacts/m4p496/spec.json`, 스테이징 `m4p496-stage`(892 파일 = 바탕 888 + N 넷; 관문 1 통과), run `m4p496-p1`(16 명령; 게시하지 않고 읽음; `collect` 의 나머지 검사 통과). 기록 `09_validation/reconstruction/m4-m68k-probe-p496-20261024.json`.
- 관문 2: 넷 모두 §429 치환이 한 번씩 맞았습니다. M5 줄과의 차이는 `checksum_16` 에 `-Isrc/components/driverkit-1` 이 없는 것 하나입니다.
- 의존 목록 8 개 모두 i386 머리가 0 이고, `bsd/m68k/*` 와 `architecture/m68k/byte_order.h` 가 쓰였습니다.
- 결과(L1, 텍스트 크기·외부 기호 집합·원본에 없는 미정의 확인):

| 대상 | N(NeXTMach `next/`) | X(07 x86 `machdep/i386`) |
|---|---|---|
| `checksum_16`(86 B) | OBJECT_MATCH, 후보 꼴 | NOT_MATCH, 100 B(무조건 `NXSwapShort`; Darwin 바탕) |
| `dkbad`(92 B) | OBJECT_MATCH, 후보 꼴 | OBJECT_MATCH(N 과 글이 같고 객체도 같음) |
| `in_cksum`(212 B) | NOT_MATCH, 550 B(미리 예상한 구조 차이: 원본은 `_oc_cksum` 을 부름) | 컴파일 실패(i386 레지스터 이름 `esi`·`edx` 등의 `asm`, 분류 asm) |
| `ufs_machdep`(372 B) | OBJECT_MATCH, 후보 꼴 | OBJECT_MATCH(N 과 글이 같고 객체도 같음) |

- 경고는 16 명령 모두 0 입니다.
- M4 의 m68k 전용 C 는 x86 줄에 §429 치환을 한 컴파일 경로로 원본과 맞출 수 있습니다. 세 대상(550 B)이 NeXTMach `next/` 원문 그대로 원본과 같았습니다.
- `oc_cksum` 은 참고 트리 가운데 Darwin 0.1 `machdep/i386/in_cksum.c`(i386 인라인 어셈블리)에만 있습니다(grep). m68k `in_cksum` 과 `_oc_cksum`(§495 `m68k-273`, unassigned)은 따로 다룹니다.

07 에 넣는 일은 둘 자리가 원본 바이트로 정해지지 않으므로(원본에 경로 문자열 없음, §496 확인) 사용자 결정 뒤에 따로 계획합니다.

사용자 결정 D103(2026-10-24): M4 의 m68k 전용 C 소스는 "07 본 트리 src/machdep/m68k" 에 둡니다(제 추천 `v183.34/m68k/src/machdep/m68k` 대신). x86 파일과 글이 같은 `dkbad.c`·`ufs_machdep.c` 도 "m68k 사본을 따로 둠 (Recommended)" 입니다. 원본에 경로 문자열이 없어 바이트로 정해지지 않는 선택입니다(§496).

## 497. M4-3 D103 구현 계획 — 07 `src/machdep/m68k` 의 첫 세 파일(`checksum_16.c`·`dkbad.c`·`ufs_machdep.c`; 코딩 전, 2026-10-24)

배경: §496 에서 NeXTMach mk-108.1 `next/` 의 세 파일이 원문 그대로 m68k 원본과 같았습니다(OBJECT_MATCH, 텍스트 크기·외부 기호 집합 일치). D103 에 따라 07 본 트리 `src/machdep/m68k/` 에 m68k 사본을 둡니다.

확인한 사실(이번 세션):
- `01_resources/upstream/nextmach` 의 HEAD 는 `f6bdb9c3268f0eadc545d41bcc0564453b17001e`(PROVENANCE 의 NeXTMach 행들과 같은 커밋)이고 작업 트리 변경은 0 입니다.
- NeXTMach `next/dkbad.c`·`next/ufs_machdep.c` 는 07 x86 `machdep/i386/dkbad.c`·`ufs_machdep.c` 와 글이 같습니다(python). 두 x86 파일은 NeXTMach 원문을 그대로 쓰고 고지는 파일 안에 있습니다(PROVENANCE 585·587 행, MODIFICATIONS 181·182 행 "none (NeXTMach text unchanged)").
- `next/checksum_16.c` 에는 저작권 고지 줄이 없습니다(파일 머리 확인).
- x86 스테이징(`stage_headers.py`)은 소스 목록에서 출발한 머리 폐포만 모으므로 `.c` 만 있는 새 디렉터리를 집지 않을 것으로 봅니다. 확인은 아래 x86gate 로 합니다.
- 07 트리를 훑는 도구(`m3_m68k_generated`·`m5_x86_srcvar`·`m5_m68k_srcvar`·`m5_m68k_nsq`·`l2_link`·`l2_forms`)는 07 본 트리가 아니라 스테이징·run 을 훑습니다(grep).
- m68k 스테이징(`stage_m68k.py stage`)은 x86 g1a 스테이징 + SDK + `v183.34` 덮어쓰기로만 만들어집니다. 07 본 트리의 새 `.c` 는 지금 들어가지 않습니다.

방법:
1. 07 파일 셋: NeXTMach `mk-108.1/next/<f>.c` 를 바이트 그대로 `07_kernel/src/machdep/m68k/<f>.c` 로 복사합니다. 복사 뒤 SHA-256 이 원본 파일과 같아야 합니다. 표시 줄은 넣지 않습니다(x86 의 NeXTMach 그대로 파일과 같은 방식; 출처는 PROVENANCE·MODIFICATIONS·파일 안 고지).
2. `stage_m68k.py`:
   - `M4SRC = '07_kernel/src/machdep/m68k'` 를 두고, `PLAN >= 497` 일 때만 그 아래 `.c` 를 스테이징 `src/machdep/m68k/` 에 넣습니다. 넣는 자리에 이미 파일이 있으면 멈춥니다. 덮어쓰기 트리보다 먼저 넣습니다(D068 순서: m68k 덮어쓰기 → common → 07 본 트리).
   - 매니페스트에 `m4_sources` 목록을 남깁니다. 497 보다 앞선 `--plan` 의 스테이징은 바뀌지 않습니다.
   - `EXCEPTS[497] = dict(EXCEPTS[494])`(x86 객체 변화 없음). 문서 줄 셋을 고칩니다. x86 접두어는 s6ll 그대로입니다.
3. 확인:
   - `--plan 497 x86gate 08_build/artifacts/m4p497/x86gate`: 일곱 묶음 모두 `same` true 이고 v183 경로 0 이어야 합니다. 이것으로 x86 스테이징·명령 입력이 바뀌지 않았음을 확인합니다. x86 컴파일 입력이 그대로이므로 x86 전체 재빌드는 하지 않습니다.
   - `--plan 497 stage m0p497-a1-stage`: `m0p494-a1-stage` 와의 파일 항목 차이는 새 파일 셋뿐이어야 합니다.
4. m68k 최종 확인(run `m4p497-a1`):
   - `m4_m68k_probe.py` 에 변형 값 `@<rel>`(스테이징의 `src/<rel>` 을 그대로 컴파일)과 명세 키 `refs`(대상별 REF 객체 경로·SHA-256; 객체의 canon·obj_sig 가 REF 와 같은지 기록)를 더합니다. 기존 동작은 그대로입니다.
   - 대상 셋, 변형 하나(`F`: `@machdep/m68k/<f>.c`). REF 는 §496 run `m4p496-p1` 의 N 객체입니다.
   - 관문: 명령 종료 0·경고 0, i386 머리 0, 판정 `candidate`(OBJECT_MATCH, 텍스트 크기·외부 기호 집합 일치, 원본에 없는 미정의 0), REF 해시 재확인과 canon·obj_sig 같음.
5. 기록:
   - PROVENANCE 새 행 셋(source_id `nextmach`, URL·커밋, `mk-108.1/next/<f>.c`; 고지 칸은 `dkbad`·`ufs_machdep` 가 "notices in the file (D013)", `checksum_16` 이 "no notice in the NeXTMach file"; 바꿈 칸에 "m68k copy, NeXTMach text unchanged (D103)" 와 파일 SHA-256). 행 수와 경로 중복 0 을 python 으로 확인합니다.
   - MODIFICATIONS 새 행 셋, DECISIONS D103
   - 근거 문서 `06_reconstruction/evidence/m68k-checksum_16.md`·`m68k-dkbad.md`·`m68k-ufs_machdep.md`
   - 상태 절: M4 의 진행(목록 188 행 가운데 3 행, 빌드 단위 57 가운데 3)
   - `functions.tsv` 는 x86 행만 있으므로 고치지 않습니다.

### 497.1 교차검토(codex `gpt-6.1-sol`) 판정과 계획 수정

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| x86 스테이징은 명시된 소스와 include 폐포만 따르고 디렉터리를 훑지 않음; 다만 `.c` 라도 명시 소스·include 로 들어올 수는 있음 | `stage_headers.py:319`(`select`), `:345`(`closure`) 읽음; 제 grep(07 트리 훑는 도구 없음) | ✅ x86gate 로 실측 |
| x86gate 는 매니페스트만 비교하고 명령(forms 표에서 만들어짐)은 보지 않음 | `stage_m68k.py:433–461`, `l2_rebuild.py:49–53`(`FORMS` 읽음)·`:100–106`(`lines_for`) | ✅ 명령 관문을 더함 |
| 지금 forms 표 해시가 s6ll 기록과 같음 | s6ll G1 기록 4 행 `647a1e68…` 과 지금 파일 SHA-256(python 이 아닌 `sha256sum` 출력 대조) | ✅ 실행 때 python 으로 다시 대조 |
| 계획 632 행 "07 을 고칠 때마다 x86 전체 재빌드" 를 고쳐야 함 | 632 행 읽음 | ✅ 결과 뒤 "x86 입력이 바뀌지 않는 07 추가는 x86gate·명령 대조로 확인" 으로 고침 |
| 스테이징 설계는 맞음; `m4_sources` 칸도 `PLAN >= 497` 에서만 둘 것 | `stage_m68k.py:374–411` | ✅ |
| `cmd`·`compare` 는 M5 205 줄만 다뤄 새 소스를 확인하지 않음 → 따로 확인 필요 | `stage_m68k.py:413–431, 463–480` | ✅ 이미 4 단계에 있음 |
| 표시 없는 그대로 사본은 AGENTS(D013)와 x86 선례에 맞음; `checksum_16` 은 고지 없음을 적으면 됨 | `AGENTS.md:6`, PROVENANCE 585·587, MODIFICATIONS 181 | ✅ 근거 문서에 함수별 NeXTMach 줄을 적음 |
| 입력 사슬을 묶을 것: p496 N 입력 = 고정 NeXTMach = 07 = 새 스테이징 = run 사본 | 설계 | ✅ 관문에 더함 |
| `refs` 는 선택 키로, 있으면 모든 대상에 필요하고 관문 실패 시 종료 코드 1 | `m4_m68k_probe.py` 판정 줄은 기록만 함 | ✅ |
| i386 머리 계수가 `architecture/i386` 만 셈 | `m4_m68k_probe.py:192` | ✅ §496 에서는 제가 따로 `i386` 낱말 전체를 셌으나(0), 도구도 넓힘 |
| 기록에 결과 JSON 이름과 해시·관문 결과를 둘 것; `07_kernel/README.md`·`v183.34/README.md` 에 D103 을 적을 것 | `07_kernel/README.md:23`, `v183.34/README.md:3` 읽음 | ✅ |

계획 수정(실행 전 고정):
- 3 에 x86 명령 관문을 더합니다.
  - forms 표·expect 표·`l2_rebuild.py` 의 SHA-256 이 s6ll 기록(일곱 묶음 기록의 `forms_sha256` 등)과 같아야 합니다.
  - `l2_rebuild.py` 의 `rows`·`lines_for` 로 다시 만든 일곱 묶음의 명령이 `08_build/runs/tools/s6ll-<g>.cmd` 와 run ID 말고 같아야 합니다.
  - 기록 `09_validation/reconstruction/m4-x86-inputs-p497-20261024.json`.
- 4 의 관문에 입력 사슬을 더합니다. §496 기록의 N 입력 SHA-256 = 고정 NeXTMach 파일 = 07 파일 = `m0p497-a1-stage` 파일 = run `m4p497-a1` 의 입력 사본이어야 합니다.
- 도구: `refs` 는 선택 키입니다. 있으면 모든 대상에 있어야 하고, 관문(종료 0·경고 0·i386 머리 0·candidate·REF 같음)이 하나라도 실패하면 종료 코드 1 입니다. i386 머리는 의존 경로에 `i386` 이 든 머리 파일 모두를 셉니다.
- 결과 기록 `09_validation/reconstruction/m4-m68k-p497-final-20261024.json`. `07_kernel/README.md`·`07_kernel/v183.34/README.md` 에 D103(m68k 전용 소스는 07 본 트리 `src/machdep/m68k`, m68k 스테이징이 `--plan >= 497` 에서 넣음)을 적습니다.

### 497.2 결과(2026-10-24)

- 1: `07_kernel/src/machdep/m68k/` 에 NeXTMach `next/checksum_16.c`·`dkbad.c`·`ufs_machdep.c` 를 바이트 그대로 복사했습니다. SHA-256 은 각각 `dbc35e13…`·`b2fe57db…`·`d0558fcb…` 입니다.
- 2: `stage_m68k.py` 에 `M4SRC`·`EXCEPTS[497]`·문서 줄을 더했습니다(541 → 559 행). `--plan 497` 에서만 새 소스를 넣고, 매니페스트에 `m4_sources` 를 둡니다.
- 3:
  - x86 입력: `m4_x86_inputs.py s6ll` 이 일곱 묶음 모두 같다고 판정했습니다(forms 표 경로·SHA-256, 다시 만든 명령, 소스 목록; 기록 `09_validation/reconstruction/m4-x86-inputs-p497-20261024.json`). `l2_rebuild.py`·forms·expect 표는 커밋 이후 바뀌지 않았습니다(`git status` 0).
  - `--plan 497 x86gate`: 일곱 묶음 모두 `same` true, v183 경로 0.
  - `--plan 494 stage` 를 다시 만든 매니페스트가 `m0p494-a1-stage` 와 같습니다(앞선 계획의 재현성).
  - `--plan 497 stage m0p497-a1-stage`: 891 파일, `m0p494-a1-stage` 와의 파일 항목 차이는 새 파일 셋뿐입니다.
- 4: run `m4p497-a1`(6 명령; 기록 `09_validation/reconstruction/m4-m68k-p497-final-20261024.json`). 관문 `commands_ok`·`no_i386_headers`·`all_candidates`·`refs_equal` 모두 true 입니다.
  - 세 객체 모두 OBJECT_MATCH 입니다. 텍스트 크기와 외부 기호 집합이 원본 범위와 같고, §496 객체와 canon·obj_sig 가 같습니다.
  - 입력 사슬(§496 N 입력 = 고정 NeXTMach = 07 = 스테이징 = run 사본)이 세 파일 모두 하나의 SHA-256 입니다(python).
- 5: PROVENANCE 1099 → 1102 행(경로 중복 0), MODIFICATIONS 645 → 648 행, DECISIONS D103(106 → 107 행), 근거 문서 `06_reconstruction/evidence/m68k-checksum_16.md`·`m68k-dkbad.md`·`m68k-ufs_machdep.md`, `07_kernel/README.md`·`07_kernel/v183.34/README.md` 에 D103 을 적었습니다.
- M4 진행: 목록 188 행 가운데 3 행, 빌드 단위 57 가운데 3, 텍스트 550 B(M4 최소 바이트 215874 B 의 0.25%)가 OBJECT_MATCH 입니다.

## 498. M4-4 세부 계획 — 남은 첫 대상 C 15 개의 머리 공백표와 M5 객체 꼬리 확인(진단; 07·도구 동작 변경 없음; 코딩 전, 2026-10-24)

배경: §495 의 첫 대상 후보(빌드 단위 21) 가운데 §497 에서 셋을 넣었습니다. `in_cksum`(구조 차이)과 어셈블리 둘(`nextdev/monitor.s`·`next/nextdbgasm.s`)을 빼면 C 15 개가 남습니다. 이 가운데 14 개는 NeXTMach 원문 그대로는 m68k 스테이징에서 머리를 찾지 못합니다. 머리를 어떻게 공급할지(SDK 의 OPENSTEP 경로·NeXTMach 머리·구성 머리)는 D021/D022 와 맞물린 결정이므로, 먼저 사실 표를 만듭니다.

확인한 사실(이번 세션, python; NeXTMach 파일의 최상위 `#import`/`#include <…>` 를 M5 m68k 줄의 `-I` 순서로 `m0p497-a1-stage` 에서 찾음):
- C 15 개: `nextdev/snd_rcv.c`·`nbic.c`·`next/machargs.c`·`us_timer.c`·`nextdev/bus.c`·`bsd/tty_pty.c`·`next/mem.c`(3 행)·`next_table.c`·`cons.c`·`nextdev/snd_device.c`·`next/autoconf.c`·`vm/vm_unix.c`·`nextif/in_bootp.c`(2 행)·`nextdev/fd_subr.c`·`nextdev/np.c`. 여러 행인 단위도 주소가 이어집니다.
- 찾지 못한 서로 다른 머리 48 개:
  - 25 개는 스테이징에 같은 이름의 i386 아닌 파일이 다른 경로로 있습니다(예: `next/cpu.h` → `bsd/m68k/cpu.h`, `nextdev/nbicreg.h` → `architecture/m68k/nbicreg.h`, `next/cons.h` → `bsd/m68k/cons.h`).
  - 19 개는 NeXTMach 에만 있습니다(예: `next/scr.h`·`next/mmu.h`·`nextdev/snd_var.h`·`next/pmon.h`).
  - 4 개(`sound.h`·`show_space.h`·`mach_ldebug.h`·`mallocdebug.h`)는 파일이 없습니다. NeXTMach `conf/files*` 의 옵션 이름에서 만들어지는 구성 머리입니다. `fd.h`·`np.h`(따옴표)도 같은 옵션 이름입니다. 07 `generated` 에는 x86 구성의 `pty.h` 만 있습니다.
- `bsd/tty_pty.c` 는 찾지 못한 머리가 없습니다. 그러나 §495 행 `m68k-036`(344 B, `_ptsputc` 와 이름 없는 함수 하나)은 M5 객체 `x86-tty_pty`([0x4010140, 0x40110a0), 07 `bsd/kern/tty_pty.c`) 바로 뒤에 붙어 있습니다. M5 에서 `tty_pty` 는 텍스트가 검증되고 bss 만 추정된 객체입니다(§464). 원본의 `tty_pty.o` 가 `_ptsputc` 까지 담았을 가능성이 있습니다(NeXTMach 은 한 파일).

방법(새 도구 `10_tools/reconstruction/m4_m68k_headers.py`; 입력 표·NeXTMach·스테이징 매니페스트만 읽고 출력 둘만 씀):
1. 머리 공백표 `06_reconstruction/m68k-m4-headers.tsv`(단위·include 마다 한 행):
   - 열: 단위, M4 id, include 낱말·꼴(`<>`/`""`)·줄, 둘러싼 조건(`#if …` 줄 목록), 분류, 스테이징 경로(찾았으면), 같은 이름의 스테이징 후보(i386 경로 제외), NeXTMach 후보 경로
   - 분류(미리 정함; 처음 맞는 하나):
     - `resolves`: M5 줄 `-I` 순서로 스테이징에서 찾음. 따옴표 include 는 스테이징 소스 디렉터리(`src/<단위 디렉터리>/`)를 먼저 봄.
     - `config`: 낱말에서 `.h` 를 뺀 이름이 NeXTMach `conf/files`·`files.NeXT` 의 `optional`·`standard` 줄 낱말과 같음.
     - `sdk-other-path`: 같은 이름의 i386 아닌 파일이 스테이징에 있음.
     - `nextmach-only`: NeXTMach 트리에만 있음.
     - `none`
2. M5 꼬리 확인(같은 기록 JSON): 묶음 D 와 15 단위 가운데, 바로 앞(또는 뒤) 객체가 M5 객체이고 그 07 소스의 파일 이름이 단위 파일 이름과 같은 경우를 적습니다. 지금 아는 사례는 `tty_pty`(`m68k-035` → `m68k-036`) 입니다.
3. 집계(python): 분류별 행 수와 서로 다른 머리 수, 단위별 `resolves` 가 아닌 수.
4. 기록 `09_validation/reconstruction/m4-m68k-headers-p498-20261024.json`(입력 SHA-256, 집계, 꼬리 사례).

검사(어긋나면 멈춤):
1. 단위 15 개, 각 단위의 include 수가 python 정규식 셈과 같음.
2. 분류는 행마다 정의된 하나.
3. 분류 `resolves` 의 경로는 스테이징 매니페스트에 있음.
4. 두 번 돌린 출력 SHA-256 이 같음.

이 절은 07 을 바꾸지 않고 컴파일도 하지 않습니다. 결과로 머리 공급 방식(OPENSTEP 경로로 include 줄을 고칠지, NeXTMach 머리를 둘지, m68k 구성 머리 표에 옵션을 더할지)과 `tty_pty` 꼬리 처리를 계획하고, 바이트로 정해지지 않는 선택은 사용자께 여쭙니다.

### 498.1 교차검토(codex `gpt-6.1-sol`) 판정과 계획 수정

제 오류: "찾지 못한 서로 다른 머리 48 개(25/19/4)" 는 `<…>` include 만 센 값입니다. 따옴표 include `"fd.h"`·`"np.h"` 를 넣으면 50 개(25/19/6)입니다. "07 `generated` 에는 `pty.h` 만 있다" 는 일곱 구성 이름 가운데서만 맞습니다.

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 15 단위·여러 행 단위의 연속·`tty_pty` 의 인접이 맞음; 머리 수는 따옴표를 넣으면 50(25/19/6) | 제 python 출력(이번 세션)과 회신 대조 | ✅ 제 오류 정정 |
| 최상위 include 만 보면 중첩 include·거짓 조건 안 include 를 놓치거나 잘못 셈; `machargs.c` 의 `sound.h` 는 `#if DEBUG` 안 | NeXTMach `next/machargs.c:33–37` | ✅ 조건 줄을 모두 적고 "무조건/조건부" 를 나눔; 표는 직접 include 만이라고 밝힘 |
| 구성 머리는 `optional` 줄의 요구 낱말(`f_needs`)에서 만들어지고, `standard` 는 요구가 없으며 `device-driver`·`profiling-routine` 은 예약어; `cputypes.h`·`confdep.h` 는 따로 생성 | `src/config/mkmakefile.c:562–571, 598–606, 668–676, 340–345, 371–375`, `mkheaders.c:58–66` | ✅ 규칙을 좁힘(아래) |
| 따옴표 include 는 소스를 둘 자리에서 찾아야 함; M4 사본은 `src/machdep/m68k/` | `m0p497-a1-stage.manifest.json` 의 `m4_sources`, D103 | ✅ `src/machdep/m68k/` 를 먼저 봄 |
| `sdk-other-path` 는 SDK 가 아닌 프로젝트 머리도 담음(예: 07 `kern/clock.h`) | 매니페스트 1973 행 `src/kern/clock.h` | ✅ 이름을 `stage-other-path` 로, 후보마다 매니페스트 출처를 적음 |
| 꼬리 규칙은 `tty_pty` 만 잡고, `vm_unix`(x86 객체가 m68k 대응에서 split, M5 밖; 뒤 행 `m68k-205` 의 `_gc_init`·`_gc_control` 은 07 `vm_unix.c` 에 있음)·`kern/thread.c`(M5 `thread` 는 멀리 있음)·`next/machdep.c`(x86 `machdep` 이 m68k 대응에서 split) 관계를 놓침 | `m68k-text-objects.tsv` 160·73·342 행(파일 162·75·344 줄), `m68k-functions.tsv` 2353 줄, 07 `vm/vm_unix.c:684`, python(`m68k-205` 이름) | ✅ 관계 진단을 넓힘 |
| 파일 이름이 같다는 것은 내용이 같다는 증거가 아님(D021/D022) | `02_plan/DECISIONS.md` | ✅ 표는 후보만 적음 |

계획 수정(실행 전 고정):
- 머리 공백표는 직접 include 만 다룹니다(중첩은 이후 컴파일 진단에서 봄). 행마다 둘러싼 조건 줄 묶음(`#if`·`#ifdef`·`#ifndef`·`#elif`·`#else` 를 차례대로)과 `activity` = `unconditional`/`conditional` 을 적습니다. 조건 값은 평가하지 않습니다.
- 분류(처음 맞는 하나):
  - `resolves`: 따옴표 include 는 `src/machdep/m68k/` 를 먼저, 그다음 M5 줄 `-I` 순서로 스테이징에서 찾음. `<…>` 는 `-I` 순서만.
  - `config-candidate`: 이름이 `cputypes.h`·`confdep.h` 이거나, `.h` 를 뺀 이름이 NeXTMach `conf/files`·`files.NeXT` 의 `optional` 줄에서 `optional` 다음 첫 낱말(예약어 `device-driver`·`profiling-routine` 이 아닌 것)과 같음. 그 conf 줄을 근거로 적습니다.
  - `stage-other-path`: 같은 이름의 i386 경로가 아닌 파일이 스테이징에 있음(후보마다 매니페스트 출처).
  - `nextmach-only`: NeXTMach 트리에만 있음.
  - `none`
- 관계 진단(기록 JSON): 15 단위마다
  - 같은 파일 이름의 x86 객체(`m68k-text-objects.tsv` 의 모든 class: contiguous·split·absent 등)와 그 07 소스, M5 소속 여부
  - 앞뒤 객체(id·종류·이름)
  - 단위의 함수 이름 가운데 07 의 같은 이름 소스에 정의된 것
  - 모두 소유 후보이며 증명이 아닙니다.
- 검사 1 의 include 수는 `<…>`·`"…"` 를 모두 셉니다.

### 498.2 결과(2026-10-24)

- 도구 `10_tools/reconstruction/m4_m68k_headers.py`. 출력 `06_reconstruction/m68k-m4-headers.tsv`(SHA-256 `db7c6d10ccdaea8e016ea83900e25b5beb0cc43ba74223aa2f5bac9c64632831`)와 기록 `09_validation/reconstruction/m4-m68k-headers-p498-20261024.json`. 검사 1–3 통과, 두 번 돌린 출력이 같습니다(기록은 출력 경로 말고 같음).
- 직접 include 231 행의 분류:

| 분류 | 행 | 서로 다른 머리 | 그 가운데 무조건 include |
|---|---|---|---|
| resolves | 158 | 57 | 55 |
| config-candidate | 8 | 6 | 6 |
| stage-other-path | 42 | 25 | 20 |
| nextmach-only | 23 | 19 | 13 |
| none | 0 | 0 | 0 |

- 풀리지 않은 서로 다른 머리는 50 개입니다(§498.1 정정값 50 과 같음).
- 관계 진단(소유 후보):
  - `next/mem.c`·`next/cons.c`: x86 이름 대응 객체 `x86-mem`·`x86-cons`(contiguous, M5 밖)의 07 소스 `machdep/i386/mem.c`·`cons.c` 가 단위의 함수 이름을 정의합니다(`next/mem.c` 3/5, `next/cons.c` 7/7).
  - `vm/vm_unix.c`: x86 `x86-vm_unix` 는 m68k 대응에서 split(M5 밖)이고, 07 `vm/vm_unix.c` 가 22/22 이름을 정의합니다(§499.1 정정: 처음 기록은 반환형이 같은 줄에 있는 정의를 놓친 10/22). 뒤 행 `m68k-205`(unassigned, `_gc_init`·`_gc_control`)도 07 `vm_unix.c` 에 있습니다(§498.1).
  - `nextif/in_bootp.c`: x86 `x86-in_bootp` 는 m68k 대응에서 split(M5 밖)이고, 07 `bsd/netinet/in_bootp.c` 가 12/14 이름 를 정의합니다.
  - `bsd/tty_pty.c`: 앞 행이 M5 `x86-tty_pty` 이지만, 07 `tty_pty.c` 에는 `_ptsputc` 가 없습니다.
  - 나머지 10 단위는 07 에 같은 이름의 소스가 없습니다.

해석(다음 계획의 근거; 이 절의 판정 아님):
- `mem`·`cons`·`vm_unix`·`in_bootp` 는 07 소스(OPENSTEP 머리로 이미 맞춘 글)를 m68k 로 컴파일하는 쪽이 머리 문제를 피하는 첫 시험입니다(§496 의 X 변형과 같은 방식). 여러 행 단위는 이어진 범위 전체와 맞대야 하므로, `m4_m68k_probe.py` 에 여러 M4 id 를 받는 기능이 필요합니다.
- 나머지 10 단위와 `tty_pty` 꼬리는 머리 공급 방식(D021/D022 범위 안에서 OPENSTEP 경로로 include 줄을 고칠지, NeXTMach 머리를 둘지, m68k 구성 머리를 더할지)을 정한 뒤 다룹니다.

## 499. M4-5 세부 계획 — 07 에 같은 이름 소스가 있는 넷(`mem`·`cons`·`vm_unix`·`in_bootp`)의 m68k 컴파일 진단(07 변경 없음; 코딩 전, 2026-10-24)

배경: §498.2 관계 진단에서 네 단위는 07 에 같은 이름의 소스가 있고, 그 소스가 원본 함수 이름의 일부 또는 전부를 정의합니다. 07 소스는 OPENSTEP 머리에 이미 맞춘 글이므로, §496 의 X 변형처럼 m68k 로 컴파일해 원본과 맞대 봅니다.

확인한 사실(이번 세션, python):

| 단위 | M4 행(주소, 바이트) | 07 소스 | 07 에 없는 원본 이름 |
|---|---|---|---|
| `next/mem.c` | `m68k-227`·`228`(x86-mem)·`229`, [0x4072264, 0x407247e) 538 B, 이어짐 | `machdep/i386/mem.c` | `_mmmmap`·`_mmopen` |
| `next/cons.c` | `m68k-270`(x86-cons), [0x4092436, 0x4092778) 834 B | `machdep/i386/cons.c` | 없음 |
| `vm/vm_unix.c` | `m68k-204`, [0x4061b0e, 0x40622a4) 1942 B; 바로 뒤 `m68k-205`(unassigned, 136 B, `_gc_init`·`_gc_control`) | `vm/vm_unix.c` | 없음(§499.1 정정; 처음 적은 12 이름은 모두 07 에 정의됨) |
| `nextif/in_bootp.c` | `m68k-261`·`262`(bracket x86-in_bootp), [0x408fd9e, 0x4090c8a) 3820 B, 이어짐 | `bsd/netinet/in_bootp.c` | `_in_bootp_echo`·`_in_bootp_noecho` |

- 넷 모두 `s6l4-g1a.cmd` 에 x86 줄이 하나씩 있고, 07 소스가 `m0p497-a1-stage` 에 있습니다.
- `vm_unix`·`in_bootp` 의 x86 객체는 m68k 대응(§415)에서 split 이라 M5(contiguous)에 들지 않았습니다(§498.1).

방법(`m4_m68k_probe.py` 확장, 명세 `08_build/artifacts/m4p499/spec.json`, run `m4p499-p1`, 스테이징 `m0p497-a1-stage` 그대로):
- 도구 확장(기존 명세의 동작은 그대로):
  - 대상의 `m4_id` 에 id 목록을 허용합니다. 행들은 모두 정확 경계이고 주소가 이어져야 하며, 기대 범위는 그 합집합, 원본 이름은 행들의 이름 합집합입니다.
  - 선택 키 `m4_id_alt`: 다른 범위 가설 하나(예: `vm_unix` 의 `m68k-204`+`205`). 같은 객체에 대해 텍스트 크기·외부 기호 집합 일치를 따로 적습니다.
- 변형은 X 하나(`null`: 스테이징의 07 소스를 그대로)입니다. NeXTMach 원문(N)은 머리가 풀리지 않는 것이 §498 에서 이미 확인되었으므로 넣지 않습니다.
- 대상: `mem`(`[227, 228, 229]`), `cons`(`270`), `vm_unix`(`204`, alt `[204, 205]`), `in_bootp`(`[261, 262]`).
- 기록 `09_validation/reconstruction/m4-m68k-probe-p499-20261024.json`.

판정(미리 정함; 진단이므로 07 은 바꾸지 않음):
- `candidate`(OBJECT_MATCH + 텍스트 크기·외부 기호 집합 일치 + 원본에 없는 미정의 0)이면, 그 07 소스를 m68k 에서 그대로 쓸 수 있는 후보입니다. 07 반영(둘 자리 D103 과의 관계 포함)은 따로 계획합니다.
- 아니면 크기 차이·빠진 이름·L1 사유를 적고, 함수별 차이는 실기 `otool -tv` 로 원본과 숫자를 가린 명령 열로 맞댑니다(§490 방식; 진단).
- 이 넷이 맞지 않아도 그것으로 07 의 x86 판정은 바뀌지 않습니다(x86 은 원본과 바이트 동일).

관문(어긋나면 멈춤):
1. 컴파일 줄이 대상마다 자기 x86 줄에 §429 치환을 한 번씩 적용한 것.
2. run 디렉터리 검사(`collect` 의 나머지 검사) 통과.
3. 여러 행 대상의 행이 정확 경계이고 이어짐(도구 assert).

### 499.1 교차검토(codex `gpt-6.1-sol`) 판정과 계획 수정

제 오류:
- §498 관계 진단은 함수 이름이 줄 첫머리에 올 때만 정의로 셌습니다. 그래서 `vm_unix` 를 10/22 로 적었고, 위 표에 "07 에 없는 이름" 12 개를 적었습니다. 12 개 모두 07 `vm/vm_unix.c` 에 정의되어 있습니다(예: 251 행 `int fubyte(addr)`, 312·380·411·446·499·588·601 행).
- `m4_m68k_headers.py` 의 판별을 고쳤습니다(`defined_in`: 반환형이 같은 줄이어도 되고, 괄호 짝 뒤가 `;`·`,` 인 원형은 뺌). 원형·K&R·여러 줄 원형 다섯 경우를 시험했습니다. §498 출력을 다시 만든 결과, TSV 는 같고 기록의 관계 진단에서 `vm_unix` 만 22/22 로 바뀌었습니다(검사 1–3 통과, 두 번 돌린 출력 같음). §498.2 와 위 표를 고쳤습니다. 기록 SHA-256 `3e3480a5fc0ac47e2514d3eb6d4a89594a0bcc68ecea462ad9992401941cbfd8`.

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 범위·연속·x86 줄·스테이징 사본·split 분류가 맞음 | 제 python 출력(§499 앞)과 회신 대조 | ✅ |
| `vm_unix` 의 "없는 이름" 12 개는 모두 07 에 있음 | `07_kernel/src/vm/vm_unix.c` 251·312·380·411·446·499·588·601 행 출력 | ✅ 제 오류 정정(위) |
| 네 소스에 인라인 asm·i386 머리 없음; `vm_unix` 의 fu/su C 판은 i386 에서만 빠짐(235 행), `!MACH_XP`(463 행), 스테이징 `MACH_XP 0` | grep(asm·i386·#if), 스테이징 `generated/mach_xp.h` | ✅ |
| L1 은 객체 절 길이만큼 비교하고 배치는 기호 하나로도 정해짐 → 작거나 큰 객체가 잘못 맞음으로 보일 수 있음; 함수별 비교 필요 | `l1_compare.py:321`(절 크기), `:467–479`(배치); L1 기록의 `sections`·`functions` 형식 확인 | ✅ 배치 주소 관문과 함수별 비교를 더함 |
| 여러 행 대상의 안전장치(빈 목록·중복·모르는 id·겹침, 주소순 정렬·정확한 이음, 중간의 x86·bracket 행 유지, 이름 합집합과 이름 없는 진입점 따로) | 설계; `in_bootp` 의 이름 없는 118 B 함수 0x4090a50(`m68k-functions.tsv` 출력) | ✅ |
| `exact` 는 경계가 좁혀졌다는 뜻이지 소유 증명이 아님 | `m4_m68k_inventory.py` 의 `exact` 계산 | ✅ 기록 문구에 반영 |
| `vm_unix` alt 범위는 2078 B 이고 `_gc_init`·`_gc_control` 은 07 에 있음 | python(1942+136), 07 `vm_unix.c:684–691` | ✅ |
| N 을 빼는 것은 이번 X 진단에서는 타당 | §498 표(무조건 include 가 풀리지 않음) | ✅ |
| `in_bootp`: 07 은 10 함수가 `static`(x86, §366)이고 `in_bootp` 가 맨 앞; m68k 원본은 그 함수들이 이름 있는 기호이고 `_in_bootp` 가 맨 끝 → 외부 기호 관문은 그대로는 통과 못 함 | 07 `in_bootp.c:78–100, 117`, `m68k-functions.tsv` 0x408feee–0x4090c8a 출력 | ✅ 예상된 구조 차이로 미리 적음 |
| 명령 성공·경고·i386 머리 관문이 `refs` 가 있을 때만 모임 | `m4_m68k_probe.py` 의 `gate` | ✅ 진단에서도 `diag_gate` 로 기록 |

계획 수정(실행 전 고정):
- 도구 `m4_m68k_probe.py`:
  - `m4_id` 는 문자열 또는 목록입니다. 빈 목록·중복·모르는 id 는 멈춥니다. 행을 주소순으로 정렬하고, 모든 행이 정확 경계(`exact`)이며 앞 행의 끝 = 다음 행의 시작이어야 합니다. 종류(file·x86·bracket)는 가리지 않습니다.
  - 원본 이름은 행들의 진입점 이름 합집합(별칭 중복 없음)이고, 이름 없는 진입점 수를 따로 적습니다.
  - `m4_id_alt`(선택)는 같은 규칙의 다른 범위 가설입니다. 크기·기호 일치를 따로 적습니다.
  - `full_span` 에 "L1 이 배치한 `__TEXT,__text` 주소 = 범위 시작" 을 더합니다.
  - `refs` 가 없어도 `diag_gate`(명령 성공·경고 0·i386 머리 0)를 기록합니다. 판정에는 쓰지 않습니다.
  - 새 하위 명령 `funcs SPEC RUN OTOOL_DIR RECORD`: 실기 `otool -tv` 목록(`<이름>_<V>.txt`)과 원본 목록 `08_build/artifacts/m0p414/otool-V10/image.txt`(SHA-256 기록)를 함수별로 맞댑니다.
    - 원본 함수는 범위 안의 `m68k-functions.tsv` 진입점입니다. 객체 함수는 목록의 라벨입니다.
    - 이름(별칭 포함)으로 짝을 짓고, 함수마다 원본·객체 명령 수, 숫자를 가린 명령 열이 같은지, 객체 기호의 외부/내부 여부, 짝 없는 원본·객체 함수를 적습니다.
- 대상과 변형은 §499 그대로입니다(X 하나). 판정도 그대로입니다. 이번 진단으로는 07 을 바꾸지 않습니다.

### 499.2 결과(2026-10-24)

- 도구 확장 뒤 §497 run 을 다시 비교(회귀 확인, 출력은 `08_build/artifacts/m4p499/regress-p497.json`)했습니다. 세 객체 모두 그대로 `candidate` 이고, 배치 주소 = 범위 시작, `gate` 통과입니다.
- run `m4p499-p1`(8 명령, 모두 종료 0). 기록 `09_validation/reconstruction/m4-m68k-probe-p499-20261024.json`, 함수별 비교 `09_validation/reconstruction/m4-m68k-funcs-p499-20261024.json`(실기 `otool -tv` 목록 `08_build/artifacts/m4p499/otool/`, 원본 목록 SHA-256 `9bf1c2c74f1b8a417561f98216d1f4ac6bd4cd988054c0aca670a44061476e7b`).
- 경고 두 건(`vm_unix.c:627` `kfree` 인자, `in_bootp.c:528` `in_bootp_getpacket` 인자)은 x86 빌드 s6ll(`s6ll-g1a` 로그 319·483)에도 똑같이 있는 07 원문의 경고입니다. 그래서 `diag_gate.commands_ok` 는 false 입니다. i386 머리는 0 입니다.

| 대상 | 텍스트(객체/가설 범위) | L1 | 배치 | 같은 함수(숫자 가림)/원본 함수 |
|---|---|---|---|---|
| `mem` | 492 / 538 B | NOT_MATCH ['__TEXT,__text: fail', '__TEXT,__text: 16 refs differ, 1 unverified'] | 0x4072282 | 2/5 |
| `cons` | 832 / 834 B | NOT_MATCH ['__TEXT,__text: unverified'] | None | 6/7 |
| `vm_unix` | 2078 / 1942 B | OBJECT_MATCH  | 0x4061b0e | 24/24 |
| `in_bootp` | 3470 / 3820 B | NOT_MATCH ['__TEXT,__text: unverified', '__DATA,__data: unverified'] | None | 7/15 |

- `vm_unix`: 07 `vm/vm_unix.c` 를 m68k 로 그대로 컴파일하면 OBJECT_MATCH 이고, 텍스트 2078 B 는 alt 범위(`m68k-204`+`m68k-205`, [0x4061b0e, 0x406232c))와 같습니다. 외부 기호 집합이 같고, 배치가 범위 시작이며, 24 함수가 모두 같습니다. 1 차 범위(`m68k-204` 만)로는 크기·기호가 다릅니다(`_gc_init`·`_gc_control` 이 더 있음). 재구성 객체 하나가 `m68k-204`·`m68k-205`(unassigned)를 정확히 덮으므로 `m68k-205` 를 `vm_unix` 에 귀속하는 후보입니다(원본에서 따로 된 파일이 같은 글을 냈을 가능성은 배제되지 않음; §500.1). 07 을 바꿀 필요가 없는 후보입니다. x86 객체가 m68k 대응에서 split 이라 M5 에 들지 않았던 공통 소스입니다.
- `cons`: 832/834 B, 배치가 정해지지 않았습니다. 7 함수 가운데 6 이 같고 `_cnopen` 만 다릅니다(명령 수 91 로 같음).
- `mem`: 07 x86 판에는 `_mmopen`·`_mmmmap` 이 없고 `_mmrw` 가 다릅니다(원본 126, 객체 138 명령). 미정의 `_kernacc` 는 원본에 없습니다. NeXTMach `next/mem.c` 쪽 글이 필요해 보입니다(머리 공급 뒤).
- `in_bootp`: 7/15. 07 은 x86 원본에 맞춘 `static`·순서(§366)이고, `_in_bootp_echo`·`_in_bootp_noecho`·이름 없는 118 B 함수가 없으며, `openconsole`·`closeconsole`·`processreply`·`promisctimeout`·`in_bootp` 가 다릅니다. 예상된 구조 차이(§499.1)에 더해 본문 차이도 있습니다.

다음:
- `vm_unix` 는 07 변경 없이 m68k 빌드 집합에 넣는 절차(목록 갱신과 최종 확인, `m68k-205` 귀속 기록)를 따로 계획합니다.
- `cons` 의 `_cnopen` 차이는 실기 목록 대조로 원인을 찾는 진단을 계획합니다.
- `mem`·`in_bootp` 는 m68k 판 글이 필요하므로 머리 공급 방식을 정한 뒤 다룹니다.

## 500. M4-6 세부 계획 — `vm_unix` 를 07 변경 없이 m68k M4 확정 객체로 받아들이고 M4 상태표를 만듦(코딩 전, 2026-10-24)

배경: §499 에서 07 `vm/vm_unix.c` 를 m68k 로 그대로 컴파일한 객체가 OBJECT_MATCH 였습니다(텍스트 2078 B = `m68k-204`+`m68k-205`, 24/24 함수). §499 는 진단이었으므로, 받아들임 조건을 미리 정한 최종 확인을 따로 합니다. M4 결과(§497 셋 + 이번)를 한곳에 모으는 표도 만듭니다.

확인한 사실(이번 세션):
- 07 `vm/vm_unix.c` SHA-256 `69ee5717…` 는 §499 run 의 입력 사본과 같습니다(python). §499 객체 SHA-256 은 `daf0470d…` 입니다.
- 이 파일의 x86 객체는 m68k 대응(§415)에서 split 이라 M5 208 에 들지 않았습니다(§498.1; x86 에서는 [0x17bd28, 0x17c4e0) 1976 B 의 연속 객체, `x86-vm_unix.md`). PROVENANCE 575 행(NeXTMach 바탕, x86 편집)은 그대로입니다. M5 에서 07 을 바꾸지 않고 m68k 와 맞은 객체는 PROVENANCE 를 고치지 않았습니다(선례; m68k 내용은 편집한 파일에만 있음).
- m68k 컴파일의 경고 2 줄(`device_dealloc` 안 `vm_unix.c:627` `kfree` 인자)은 x86 s6ll(`s6ll-g1a` 로그 319)의 경고와 글자까지 같습니다(python).
- 지금 `m4_m68k_probe.py` 의 `gate` 는 경고 0 을 요구합니다.
- M4·M5 의 진행을 모은 표는 없습니다. M4 결과는 계획 문서와 검증 기록에만 있습니다.

방법:
1. 도구 `m4_m68k_probe.py`: 선택 명세 키 `known_warnings`(`{대상: [줄, …]}`)를 더합니다. 있으면 `gate.commands_ok` 는 그 대상 컴파일의 `.err` 줄 목록이 등록한 줄과 정확히 같을 때만 참입니다. 의존 목록 명령과 등록하지 않은 대상은 지금처럼 경고 0 을 요구합니다. 기존 명세의 동작은 그대로입니다.
2. 최종 확인 run `m4p500-a1`(스테이징 `m0p497-a1-stage` 그대로):
   - 대상 `vm_unix`: `m4_id` = [`m68k-204`, `m68k-205`], 컴파일 줄은 자기 x86 줄(§429 치환), 변형 `F` = `@vm/vm_unix.c`.
   - `refs` = §499 객체 `Q499__vm_unix_X.o`(SHA-256 `daf0470d…`), `known_warnings` = 위 두 줄(s6ll 로그에서 가져온 그대로)
   - 관문: `gate.ok`(명령 성공·등록한 경고와 같음·i386 머리 0·`candidate`·REF 같음)
   - 입력 사슬: 07 = 스테이징 = run 사본 = §499 run 사본의 SHA-256
   - 기록 `09_validation/reconstruction/m4-m68k-p500-final-20261024.json`
3. M4 상태표(새 도구 `10_tools/reconstruction/m4_m68k_status.py`, 출력 `06_reconstruction/m68k-m4-status.tsv`·기록 `09_validation/reconstruction/m4-m68k-status-20261024.json`):
   - 입력은 받아들인 최종 기록 목록입니다(도구 안의 고정 목록: §497·§500 기록). 각 기록의 `gate.ok` 가 참이어야 합니다.
   - 객체마다 한 행: 이름, 07 소스, 덮는 §495 행, 범위, 바이트, 계획, 기록, L1, 객체 SHA-256.
   - 검사: 덮는 행이 서로 겹치지 않음, 각 객체의 행들이 이어져 객체 범위와 정확히 같음, 텍스트 크기 = 범위 바이트.
   - 집계(python): 덮은 §495 행 수/188, 바이트/M4 최소 바이트, 그 가운데 unassigned 였던 행(이번 `m68k-205`)
4. 기록: 근거 문서 `06_reconstruction/evidence/m68k-vm_unix.md`(07 파일 그대로, `m68k-205` 귀속 근거). 상태 절과 결과 절. 07 변경이 없으므로 PROVENANCE·MODIFICATIONS·x86 재빌드는 없습니다(x86 입력 불변).

### 500.1 교차검토(codex `gpt-6.1-sol`) 판정과 계획 수정

제 오류: §498.1·§499·§499.2·§500 에 "x86 에서 split" 이라고 적었습니다. `m68k-text-objects.tsv` 의 class 는 x86 객체 기호의 **m68k 대응 run** 을 나타냅니다(표 머리 `plan 415: … their m68k __text candidate runs`). x86 `vm_unix` 는 x86 에서 [0x17bd28, 0x17c4e0) 1976 B 의 연속 객체입니다(`06_reconstruction/evidence/x86-vm_unix.md` 5 행). 위 절들의 해당 문구를 "m68k 대응에서 split" 으로 고쳤습니다. §499.2 의 `m68k-205` 귀속 문구도 증거 범위에 맞게 약하게 고쳤습니다.

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 해시·경고 동일·결합 범위의 크기·기호·배치가 맞음; 두 행을 덮는 재구성 하나는 증명하나, 원본이 따로 된 파일이었을 가능성은 배제 못 함 | 이번 세션 python(해시·경고 줄 비교), §499 기록 | ✅ 귀속을 "재구성 객체 기준의 후보" 로 적음 |
| "x86 에서 split" 은 틀림(m68k 대응의 run 분할) | `x86-vm_unix.md:5`, `m68k-text-objects.tsv` 머리 | ✅ 제 오류 정정 |
| 07 을 바꾸지 않은 m68k 일치 파일의 PROVENANCE 선례(`queue.c`) | PROVENANCE 382 행(`kern/queue.c`, darwin01) 읽음 | ✅ 단 "모든 M5 파일이 그렇다" 는 전수 확인하지 않았으므로 문구를 "선례가 있음" 으로 한정 |
| 경고 예외는 대상의 컴파일 명령에만, 줄 목록 전체를 순서대로, 모르는 대상 키는 거부, `rc == 0` 유지, 의존 목록과 미등록 대상은 경고 0 | 현재 `gate`(`m4_m68k_probe.py`) 읽음 | ✅ |
| 상태표가 지난 기록의 `gate.ok` 만 믿으면 약함: 기록 해시 고정, 지금 소스·객체 해시, REF 해시·같음, §495 목록·함수 표, 명세·run 명령 연결, 객체 중복·범위 겹침 검사 필요; §497 기록은 범위·배치 칸이 없는 옛 형식 | §497 기록에 `range`·`placed_text` 없음(python), 회귀 기록에는 있음 | ✅ 아래에 고정 |
| 묶음·종류·근거 문서 연결을 표에 둘 것; 07 README 에 표를 적을 것; x86 근거 문서에서 m68k 근거로 연결 | `07_kernel/README.md`, `x86-vm_unix.md` | ✅ |
| x86 입력 불변은 소스 해시만이 아니라 forms·명령·스테이징으로 | §497 의 `m4_x86_inputs.py`·x86gate | ✅ 다시 돌림 |
| M4 는 "M5 선택 밖의 행" 이지 머신 의존 소스만이 아님; 받아들인 객체 수와 덮은 행 수를 나눌 것; 4 객체·5/188 행·2628 B(1.22%) | python 재계산(같은 값) | ✅ M5 집계(206/208)는 바꾸지 않음 |

계획 수정(실행 전 고정):
- `known_warnings`: `{대상 이름: [줄, …]}`. 대상 이름이 명세에 없으면 멈춥니다. 그 대상의 컴파일 명령 `.err` 의 줄 목록(순서 포함)이 정확히 같고 `rc == 0` 일 때만 통과합니다. 의존 목록 명령과 등록하지 않은 대상은 경고 0 입니다.
- 상태표 도구 `m4_m68k_status.py` 는 받아들인 기록을 (경로, SHA-256) 로 고정해 읽고, 기록마다 다음을 지금 다시 확인합니다. 하나라도 어긋나면 멈춥니다.
  - 기록 SHA-256 이 고정값과 같음, `gate.ok` 참
  - 07 소스의 지금 SHA-256 = 기록의 `source_sha256`(§497 기록은 같은 칸 사용)
  - run 의 객체 파일이 있고 SHA-256 = 기록의 `obj_sha256`; REF 파일 SHA-256 = 명세값, REF 와의 canon·obj_sig 같음 기록이 참
  - 명세 SHA-256 = 기록의 `spec_sha256`, run 명령 파일에 그 소스의 컴파일 줄이 하나
  - 범위·배치: 지금 §495 목록으로 범위를 다시 계산하고, L1 출력 파일(`08_build/artifacts/m4p<plan>/<run>/l1-<이름>-<V>.json`)의 `__TEXT,__text` 주소 = 범위 시작, 크기 = 범위 바이트
  - 객체 이름 중복 없음, 덮는 행 겹침 없음, 주소 범위 겹침 없음
- 표 열: 이름, 07 소스, 덮는 행(각 행의 §495 묶음·종류), 범위, 바이트, 계획, 기록, L1, 객체 SHA-256, 근거 문서. 집계: 받아들인 객체 수, 덮은 행 수/188, 바이트/M4 최소 바이트.
- x86 입력 불변: `m4_x86_inputs.py s6ll` 과 `stage_m68k.py --plan 497 x86gate` 를 다시 돌려 기록합니다.
- 기록 추가: `07_kernel/README.md` 에 상태표, `06_reconstruction/evidence/x86-vm_unix.md` 끝에 m68k 근거 문서로 가는 줄.
- 숫자: M5 집계(206/208)는 바꾸지 않습니다. M4 는 "받아들인 객체 수" 와 "덮은 §495 행 수" 를 따로 적습니다.

### 500.2 결과(2026-10-24)

- 1: `m4_m68k_probe.py` 에 `known_warnings` 를 더했습니다. §497 run 을 다시 비교한 회귀 확인(`08_build/artifacts/m4p500/regress-p497.json`)에서 `gate` 가 그대로 통과했습니다.
- 2: run `m4p500-a1`(2 명령). 기록 `09_validation/reconstruction/m4-m68k-p500-final-20261024.json`.
  - `gate` 모두 참입니다. 컴파일 stderr 는 등록한 두 줄과 같고, 의존 목록 경고는 0, i386 머리는 0 입니다.
  - OBJECT_MATCH 입니다. 텍스트 2078 B 가 범위 [0x4061b0e, 0x406232c) 와 같고 범위 시작에 배치되었습니다. §499 객체와 canon·obj_sig 가 같습니다.
  - 입력 사슬(07 = 스테이징 = run 사본 = §499 run 사본)이 하나의 SHA-256 `69ee5717…` 입니다(python).
- x86 입력 불변: `m4_x86_inputs.py s6ll` 이 일곱 묶음 모두 같다고 판정했습니다(`09_validation/reconstruction/m4-x86-inputs-p500-20261024.json`). `--plan 497 x86gate` 도 일곱 묶음 모두 `same` true, v183 경로 0 입니다. 07 의 추적 파일 변경은 기록 파일과 README 뿐입니다(`git status`).
- 3: 상태표 `06_reconstruction/m68k-m4-status.tsv`(도구 `10_tools/reconstruction/m4_m68k_status.py`, 기록 `09_validation/reconstruction/m4-m68k-status-20261024.json`, 출력 SHA-256 `c93094f8ae7fb7e0ecee04bde7556918c69db515240f4027d83b902404b6d9e0`).
  - 받아들인 기록 둘을 해시로 고정하고, 객체마다 소스·명세·run 명령·객체·REF·범위·L1 배치·근거 문서를 다시 확인했습니다. 두 번 돌린 출력이 같습니다.
  - 받아들인 객체 4 개(`vm_unix`·`checksum_16`·`dkbad`·`ufs_machdep`)이고, 덮은 §495 행은 5/188, 2628 B(M4 최소 바이트 215874 B 의 1.22%)입니다. unassigned 였던 행 `m68k-205` 가 `vm_unix` 에 귀속되었습니다.
- 4: 근거 문서 `06_reconstruction/evidence/m68k-vm_unix.md`, `x86-vm_unix.md` 끝에 m68k 연결 줄, `07_kernel/README.md` 에 상태표. 07 소스 변경이 없으므로 PROVENANCE·MODIFICATIONS 는 고치지 않았습니다.
- M5 집계(206/208)는 바꾸지 않았습니다. `vm_unix` 는 M5 선택(§429) 밖의 객체로 M4 쪽에서 셉니다.

## 501. M4-7 세부 계획 — `cons` 의 `_cnopen` 차이 진단: 비 POSIX 갈래의 `SCTTY` 설정(07 변경 없음; 코딩 전, 2026-10-24)

배경: §499 에서 07 x86 `machdep/i386/cons.c` 를 m68k 로 컴파일하면 7 함수 가운데 `_cnopen` 만 원본과 다르고(텍스트 832/834 B), L1 배치가 정해지지 않았습니다.

확인한 사실(§499 실기 목록 `08_build/artifacts/m4p499/otool/cons_X.txt` 와 원본 목록, python difflib; 숫자 가림):
- `_cnopen` 은 원본 91·객체 91 명령이고, 다른 곳은 셋입니다.
  - 원본은 `bset #6,a3@(0x28:w)` 를 0x4092578 에 하나 둡니다. 이 자리는 두 갈래가 함께 지나는 합류점입니다. POSIX 갈래는 0x40924ec 의 `bra 0x4092578` 로, 비 POSIX 갈래는 `enterpgrp` 호출 뒤(0x4092574 `addqw`)와 `beq 0x4092578`(0x4092564) 로 옵니다.
  - 객체는 `bset` 을 POSIX 갈래 끝(오프셋 0xb6)에만 두고, 비 POSIX 갈래 끝(0x146)에는 없습니다.
  - 그 결과 객체의 `bne` 하나가 짧은 형식(`0x146:b`)이 되어, 원본(`bne 0x409257e:w`)보다 2 B 짧습니다.
- `a3` 은 `pp`, `0x28` 은 `p_flag` 이고 `bset #6` 은 그 첫 바이트의 6 번 비트, 곧 `SCTTY`(`0x40000000`, 스테이징 `bsd/sys/proc.h:568`)입니다.
- 07 `cons.c` 에는 `pp->p_flag |= SCTTY;` 가 POSIX 갈래 안(83 행)에만 있고, 비 POSIX 갈래(`else if ((pp->p_flag & SCTTY) == 0) { … }`, 95 행 `enterpgrp` 로 끝남)에는 없습니다. 07 은 x86 원본과 바이트가 같으므로, x86 원본의 동작에는 이 설정이 없습니다(원본 C 글의 꼴까지 정해지지는 않음; §501.1). m68k 원본은 비 POSIX 갈래에서도 `SCTTY` 를 설정한 것으로 읽힙니다(두 갈래의 같은 꼬리를 컴파일러가 하나로 합친 모양).
- 07 `cons.c` 의 출처는 NeXTMach `next/cons.c` + Darwin 0.1(PROVENANCE 640 행)이고, 따옴표 include 는 없습니다(grep).

방법(`m4_m68k_probe.py`, 명세 `08_build/artifacts/m4p501/spec.json`, run `m4p501-p1`, 스테이징 `m0p497-a1-stage`):
- 변형(모두 07 x86 `cons.c` 에서 만든 사본을 `08_build/artifacts/m4p501/` 에 두고 스테이징 `src/m4probe/m4p501/` 로 복사):
  - K: 07 `cons.c` 그대로(대조; §499 객체와 STABS 말고 같아야 함)
  - C1: 95 행(`enterpgrp(pp, cons_tp->t_pgrp, 0);`) 뒤, 비 POSIX 갈래를 닫는 `}` 앞에 `pp->p_flag |= SCTTY;` 한 줄을 넣음
- 컴파일 줄은 `cons` 의 x86 줄(§429 치환)입니다. 대상 `m4_id` 는 `m68k-270` 입니다.
- 함수별 비교(`funcs`)를 위해 실기 `otool -tv` 목록을 받습니다.
- 기록 `09_validation/reconstruction/m4-m68k-probe-p501-20261024.json`, `m4-m68k-funcs-p501-20261024.json`.

판정(미리 정함; 진단이므로 07 은 바꾸지 않음):
- K 의 객체가 §499 객체와 canon·obj_sig 같음(대조 관문). 다르면 멈춥니다.
- C1 이 `candidate`(OBJECT_MATCH, 크기 834 B, 범위 시작 배치, 외부 기호 집합 같음, 원본에 없는 미정의 0)이고 7 함수 모두 같으면, m68k 판 `cons.c` 의 후보 꼴입니다. 07 반영(D103 의 `src/machdep/m68k/cons.c`, 작성 줄 표시)은 따로 계획하고, 같은 바이트를 내는 다른 꼴이 있으면 사용자께 여쭙니다.
- 맞지 않으면 남은 차이를 적습니다.

### 501.1 교차검토(codex `gpt-6.1-sol`) 판정과 계획 수정

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 두 목록의 차이는 숫자를 가린 명령 비교로 셋이 전부(옮겨진 `bset`, 짧아진 `bne`, 비 POSIX 끝의 `bset` 없음); `a3` = `u.u_procp`; `p_flag` 변위 0x28; `bset #6` 은 큰 끝 long 첫 바이트의 0x40 = `SCTTY` 0x40000000 | 제 difflib 출력(§501), 같은 함수의 `btst #6,a3@(0x28:w)`·`bne`(0x40924f0)이 07 `else if ((pp->p_flag & SCTTY) == 0)` 와 대응, python: STABS 비트 변위 320 → 0x28 | ✅ |
| C1 자리(95 행 뒤, 바깥 비 POSIX 블록 안)가 맞음: `t_pgrp == 0` 갈래도 스택 정리 뒤 `bset` 으로, 같은 pgrp 는 `beq` 로, 다른 `enterpgrp` 갈래는 흘러서 옴; POSIX 실패·이미 `SCTTY` 인 경우는 건너뜀 | 원본 목록 0x40924ec–0x409257e 읽음(§501 출력) | ✅ |
| 같은 범위를 지키는 다른 꼴: 성공 표시 변수로 끝에서 한 번 설정(C2) — 바이트가 같은지는 모름; 조건 없는 공통 문장은 POSIX 실패 경우까지 덮어 틀림 | 설계 | ✅ C2 를 더함 |
| 사본 자리는 STABS 만 바꿀 것으로 보이나 K 로 확인해야 함; canon+obj_sig 는 보수적 관문(obj_sig 는 STABS 수도 봄) | `m3_m68k_diag.canon`·`l2_prefix_diff.obj_sig` | ✅ |
| 도구의 `refs` 관문은 모든 변형이 REF 와 같아야 하므로 이번 대조(K 만 §499 와 같음)에 맞지 않음 | `m4_m68k_probe.py` 의 `gate` | ✅ `refs` 를 쓰지 않고, K↔§499 는 python 으로 따로 확인 |
| 함수 비교는 숫자를 가리므로 L1 바이트·참조 일치를 함께 볼 것; COMMON 기호(`_cons`·`_cons_tp` 등)의 이름·크기도 K 와 같아야 함 | 07 `cons.c:48`, 설계 | ✅ |
| "x86 원본에는 이 문장이 없다" 는 동작만 말할 수 있음 | — | ✅ §501 문구를 고침 |

계획 수정(실행 전 고정):
- 변형: K(그대로), C1(95 행 뒤 `pp->p_flag |= SCTTY;`), C2(`int ctty = 0;` 을 지역 변수로 두고, POSIX 안쪽 블록의 `pp->p_flag |= SCTTY;`(83 행)를 `ctty = 1;` 로, 비 POSIX 블록 끝에 `ctty = 1;`, `return` 앞에 `if (ctty) pp->p_flag |= SCTTY;`).
- 관문(python, `refs` 없이):
  - K 객체가 §499 객체(SHA-256 기록값)와 canon·obj_sig 같음. 다르면 멈춥니다.
  - 변형마다 COMMON·외부 정의 기호의 이름·크기를 K 와 비교해 기록합니다.
- 후보 판정: `candidate`(L1 OBJECT_MATCH, 834 B, 범위 시작 배치, 외부 기호 집합 같음, 원본에 없는 미정의 0) + `funcs` 7/7 + 짝 없는 함수 0 + COMMON 이 K 와 같음.
- C1·C2 가 둘 다 후보이고 객체가 같으면, 바이트로 구별되지 않는 꼴이므로 07 반영 전에 사용자께 여쭙니다.

### 501.2 결과(2026-10-24)

- 변형 파일 `08_build/artifacts/m4p501/cons_{K,C1,C2}.c`(07 `cons.c` 에서 python 으로 만듦; 07 과의 차이는 의도한 줄뿐임을 diff 로 확인). 스테이징 `m4p501-stage`(894 파일 = 바탕 891 + 셋), run `m4p501-p1`(6 명령 모두 종료 0, 경고 0, i386 머리 0).
- 기록 `09_validation/reconstruction/m4-m68k-probe-p501-20261024.json`, 함수별 비교 `m4-m68k-funcs-p501-20261024.json`(실기 목록 `08_build/artifacts/m4p501/otool/`).

| 변형 | 텍스트 | L1 | 배치 | 같은 함수 | 판정 |
|---|---|---|---|---|---|
| K | 832 B | NOT_MATCH ['__TEXT,__text: unverified'] | None | 6/7 | no |
| C1 | 834 B | OBJECT_MATCH  | 0x4092436 | 7/7 | candidate |
| C2 | 842 B | NOT_MATCH ['__TEXT,__text: unverified'] | None | 6/7 | no |

- 대조 관문: K 객체가 §499 객체(SHA-256 확인)와 canon·obj_sig 같습니다(python). 사본 자리 차이는 코드에 영향이 없습니다.
- COMMON(`_cons` 134 B, `_cons_tp` 4 B, `_tthiwat`·`_tthog`·`_ttlowat` 각 64 B)과 외부 정의 기호의 이름·크기가 C1·C2 모두 K 와 같습니다(python).
- C1(비 POSIX 블록 끝에 `pp->p_flag |= SCTTY;` 한 줄)은 미리 정한 후보 조건을 모두 만족합니다: L1 OBJECT_MATCH, 834 B, 범위 시작 배치, 외부 기호 집합 같음, 원본에 없는 미정의 0, 7/7 함수, 짝 없는 함수 0.
- C2(성공 표시 변수)는 842 B 로 다릅니다. 시험한 두 꼴 가운데 바이트가 같은 것은 C1 하나입니다. 시험하지 않은 다른 꼴(예: 안쪽 갈래마다 따로 설정)이 같은 바이트를 낼 수 있는지는 확인하지 않았습니다.

다음(따로 계획): D103 에 따라 07 `src/machdep/m68k/cons.c` 를 07 x86 `cons.c` + C1 의 작성 줄 하나(표시·D024)로 만들고, 스테이징·최종 확인·상태표·기록을 §497·§500 과 같은 방식으로 합니다.

## 502. M4-8 구현 계획 — 07 `src/machdep/m68k/cons.c`(x86 `cons.c` + 작성 한 줄; D103·D024; 코딩 전, 2026-10-24)

배경: §501 에서 07 x86 `machdep/i386/cons.c` 의 비 POSIX 블록 끝에 `pp->p_flag |= SCTTY;` 한 줄을 넣은 꼴(C1)이 m68k 원본과 같은 객체가 되었습니다(OBJECT_MATCH, 834 B, 7/7 함수, COMMON 같음). D103 에 따라 m68k 사본을 07 본 트리 `src/machdep/m68k/` 에 둡니다.

확인한 사실(이번 세션):
- 07 x86 `cons.c` 머리에는 NeXT 고지(1–7 행)와, `plan 400 (Darwin)` 표시 줄을 위한 Darwin 0.1 APSL 고지(12–37 행)가 있습니다. PROVENANCE 640 행의 출처는 `nextmach+darwin01`, 바뀜 칸은 cnopen/cnioctl 작성 줄(plan 276, D024)·plan 400·plan 404(D061)입니다. SHA-256 은 `29f8cd23…` 입니다.
- `stage_m68k.py` 는 `--plan 497` 이상에서 `07_kernel/src/machdep/m68k` 의 `.c` 를 모두 넣습니다(394–400 행). 그래서 파일을 더하면 이전 계획 번호의 스테이징이 바뀝니다. `m0p497-a1-stage` 는 세 파일 기준입니다.
- 07 x86 `cons.c` 는 x86 빌드가 쓰는 파일이고, 이번에는 고치지 않습니다(m68k 사본만 새로 만듦).

방법:
1. 07 파일: `07_kernel/src/machdep/m68k/cons.c` = 07 x86 `cons.c` 에 다음 둘만 더한 것.
   - 머리 고지들 뒤 설명 주석 한 덩이: "m68k copy of `machdep/i386/cons.c` (plan 502, D103); one line authored from the m68k original bytes (marked plan 502, D024)."
   - 95 행(`enterpgrp(pp, cons_tp->t_pgrp, 0);`) 뒤, 비 POSIX 블록 안에 `pp->p_flag |= SCTTY;	/* plan 502 (D024): the m68k original also sets SCTTY here */`
   - python 으로, 주석을 뺀 토큰이 §501 의 C1 사본과 같은지 확인합니다.
2. `stage_m68k.py`:
   - 디렉터리 전체 대신 계획별 등록 목록 `M4FILES = {497: [checksum_16.c, dkbad.c, ufs_machdep.c], 502: [위 셋 + cons.c]}` 를 둡니다. 스테이징은 `PLAN` 이하의 가장 큰 키의 목록만 넣습니다.
   - 디렉터리의 모든 `.c` 는 어느 키에든 등록되어 있어야 합니다(등록 빠짐을 막음). 목록의 파일이 없으면 멈춥니다.
   - `EXCEPTS[502] = dict(EXCEPTS[497])`, 문서 줄.
   - 확인: `--plan 497 stage` 를 다시 만든 매니페스트가 `m0p497-a1-stage` 와 같아야 합니다(재현성). `--plan 502 stage m0p502-a1-stage` 와 `m0p497-a1-stage` 의 파일 항목 차이는 `src/machdep/m68k/cons.c` 하나여야 합니다.
3. x86 입력 불변: `m4_x86_inputs.py s6ll`, `--plan 502 x86gate`. x86 이 쓰는 07 파일은 바뀌지 않습니다.
4. 최종 확인 run `m4p502-a1`(`m4_m68k_probe.py`):
   - 대상 `cons`, `m4_id` `m68k-270`, 줄 틀은 x86 `machdep/i386/cons.c` 줄(§429 치환), 변형 `F` = `@machdep/m68k/cons.c`.
   - `refs` = §501 C1 객체(SHA-256 기록값). 관문 `gate.ok`(경고 0 포함).
   - COMMON·외부 정의 기호를 REF 와 비교(python).
   - 입력 사슬: 07 m68k `cons.c` = 스테이징 = run 사본.
   - 기록 `09_validation/reconstruction/m4-m68k-p502-final-20261024.json`
5. 상태표: `m4_m68k_status.py` 의 `ACCEPTED` 에 §502 기록(경로·SHA-256)을 더해 다시 만듭니다. 이전 두 기록의 재확인도 그대로 통과해야 합니다.
6. 기록: PROVENANCE 새 행(`07_kernel/src/machdep/m68k/cons.c`, `nextmach+darwin01+authored`; 고지는 파일 안), MODIFICATIONS 새 행, diff `06_reconstruction/evidence/m68k-cons.diff`(07 x86 → m68k 사본), 근거 문서 `06_reconstruction/evidence/m68k-cons.md`, 상태 절과 결과 절. 사용자 결정이 아니므로 DECISIONS 는 고치지 않습니다.

### 502.1 교차검토(codex `gpt-6.1-sol`) 판정과 계획 수정

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 사본은 NeXT 고지·APSL 고지·`plan 400 (Darwin)` 줄을 그대로 지니므로 AGENTS·D061 에 맞음; 작성 줄 표시도 맞음 | 07 x86 `cons.c:1–47` 읽음 | ✅ |
| 출처 칸 `nextmach+darwin01+authored` 는 `+authored` 선례(`net2+authored`·`nextmach+authored`)와 맞음 | PROVENANCE 1016·1097 행; 출처 칸 분포(python `cut`) | ✅ 계획대로 |
| D024 는 작성 줄의 근거로 MODIFICATIONS 에 원본 주소를 요구 | `02_plan/DECISIONS.md` 28 행 | ✅ MODIFICATIONS 에 0x4092578(`bset`)·0x40924ec(`bra`)·0x4092564(`beq`) 를 적음 |
| 주석은 코드를 바꾸지 않음; 토큰 같음은 컴파일·REF 관문과 함께여야 충분; `obj_sig` 는 STABS 수만 보고 값은 보지 않음 → 객체 전체 해시는 달라질 수 있음 | 설계(§497·§500 에서 같은 관문 사용) | ✅ |
| `M4FILES` 는 구성원을 고정하나 파일 내용 변경은 막지 않음; `EXCEPTS[502]` 는 `--plan` 분기에 필요; `X86` 추가는 불필요; x86gate·compare 는 `m4_sources` 칸과 충돌 없음 | `stage_m68k.py:543`(분기), x86gate 는 x86 매니페스트만 읽음 | ✅ |
| 상태표 도구가 머리말·`plan` 을 500 으로 고정 | `m4_m68k_status.py:2,86,90` | ✅ 받아들인 기록의 가장 큰 계획 번호를 `updated_plan` 으로 함께 적음 |
| 07 README 에 계획별 등록 목록을 적을 것(선택) | `07_kernel/README.md` | ✅ |
| x86 `cons.c` 는 HEAD·s6ll 입력과 같고, 링크 커널은 원본과 같음 | (codex 의 python 확인) | ⏭️ 이 계획의 3 단계에서 x86 입력 관문으로 다시 확인 |

### 502.2 결과(2026-10-24)

- 1: `07_kernel/src/machdep/m68k/cons.c`(190 행, SHA-256 `70c13452aa744a06173301be562904c64d2da7485ec758d94917204cd486f9e5`) = 07 x86 `cons.c` + 설명 주석 한 덩이 + 작성 줄 하나(표시 `plan 502 (D024)`). 주석을 뺀 토큰이 §501 C1 과 같습니다(python). diff `06_reconstruction/evidence/m68k-cons.diff`.
- 2: `stage_m68k.py` 를 계획별 등록 목록 `M4FILES`(497: 세 파일, 502: 넷)로 바꾸고 `EXCEPTS[502]`·문서 줄을 더했습니다(559 → 567 행).
  - `--plan 497 stage` 를 다시 만든 매니페스트가 `m0p497-a1-stage` 와 같습니다.
  - `--plan 502 stage m0p502-a1-stage`(892 파일)와 `m0p497-a1-stage` 의 파일 항목 차이는 `src/machdep/m68k/cons.c` 하나입니다.
- 3: x86 입력 불변. `m4_x86_inputs.py s6ll` 이 일곱 묶음 모두 같다고 판정했습니다(`09_validation/reconstruction/m4-x86-inputs-p502-20261024.json`). `--plan 502 x86gate` 도 일곱 묶음 모두 같습니다. x86 `cons.c` 는 HEAD 와 같습니다(`git diff --quiet`).
- 4: run `m4p502-a1`(기록 `09_validation/reconstruction/m4-m68k-p502-final-20261024.json`). `gate` 모두 참입니다(경고 0, i386 머리 0, `candidate`, REF = §501 C1 객체와 canon·obj_sig 같음). COMMON·정의 기호도 REF 와 같고, 입력 사슬(07 = 스테이징 = run 사본)이 하나의 SHA-256 입니다(python).
- 5: 상태표를 다시 만들었습니다(`m4_m68k_status.py` 의 `ACCEPTED` 에 §502 기록 추가, `updated_plan` 502). 앞의 네 객체 행은 그대로이고 `cons` 가 더해졌습니다. 이전 기록의 재확인도 모두 통과했습니다. 첫 실행은 근거 문서가 없어 설계대로 멈췄고, 근거 문서를 쓴 뒤 다시 돌렸습니다. 두 번 돌린 출력이 같습니다.
  - 받아들인 M4 객체 5 개, §495 행 6/188, 3462 B(M4 최소 바이트 215874 B 의 1.6%).
- 6: PROVENANCE 새 행(1102 → 1103 행, 경로 중복 0), MODIFICATIONS 새 행(원본 주소 0x4092578·0x40924ec·0x4092564), 근거 문서 `06_reconstruction/evidence/m68k-cons.md`, `x86-cons.md` 끝에 연결 줄, `07_kernel/README.md` 에 등록 목록 설명.

## 503. M4-9 세부 계획 — 머리 공급 방식 진단(`bus`·`nbic`·`next_table`; 07 변경 없음; 코딩 전, 2026-10-24)

### 503.0 §498 표 정정(이 절 전에 함)
- §498 머리 공백표 231 행 가운데 47 행이 칸 수 12 였습니다(머리 11). NeXTMach 조건 줄의 탭(`#if<TAB>NSOUND > 0` 등)이 `conditions` 칸에 그대로 들어간 제 도구 결함입니다. 기록 JSON 의 집계는 메모리에서 셌으므로 영향이 없었습니다.
- `m4_m68k_headers.py` 가 칸 안의 탭을 공백으로 바꾸게 고치고, 표·기록을 다시 만들었습니다. 231 행 모두 11 칸이고, 탭 하나를 공백으로 합친 것 말고 내용이 같습니다(python). 기록은 도구 해시와 출력 해시(`ddf8236724cbecf06ea6ffe14d10c9bfae5a2d945f3fd1ff2a7c5452dfd41769`) 말고 같습니다. §498.2 에 적은 출력 해시 `db7c6d10…` 는 정정 전 값입니다.

### 503.1 계획

배경: §498 에서 남은 C 단위 대부분이 NeXTMach `next/`·`nextdev/` 머리를 찾지 못했습니다. x86 작업의 선례(D021 `--bsd-set`, D022)는 다음과 같습니다.
- BSD 머리는 SDK 를 먼저, 없으면 NeXTMach 를 씁니다. NeXTMach 채택 사본은 `07_kernel/nextmach/<mk-108.1 경로>` 에 두고 OPENSTEP 경로로 스테이징합니다(예: `nextdev/busvar.h` → `src/bsd/dev/busvar.h`, `stage_headers.py` 의 `NEXTMACH_RENAME`).
- 07 소스는 OPENSTEP 경로로 include 합니다(예: `07_kernel/src/conf/ioconf.c:9` `#import <dev/busvar.h>`).

M4 의 NeXTMach `.c` 에 이 방식을 어떻게 적용할지(include 줄을 고칠지, 옛 경로의 별칭 머리를 둘지, NeXTMach 머리 원문을 쓸지)는 바이트로 정해지지 않을 수 있습니다. 그래서 먼저 세 방식이 같은 객체를 내는지 시험합니다.

확인한 사실(이번 세션):
- 대상 셋(§495 묶음 B·C, 정확 경계, 대응률 100%)과 빠진 머리:
  - `nextdev/bus.c`(`m68k-211`, 228 B): `nextdev/busvar.h`
  - `nextdev/nbic.c`(`m68k-232`, 94 B): `next/scr.h`(NeXTMach 에만), `nextdev/nbicreg.h`(스테이징 `components/architecture/m68k/nbicreg.h`, SDK)
  - `next/next_table.c`(`m68k-303`, 628 B): `next/cpu.h`(스테이징 `src/bsd/m68k/cpu.h`, SDK), `next/scr.h`, `nextdev/busvar.h`
- NeXTMach 원문과 스테이징 후보의 비교(§503.2 에서 python 으로 다시 셈: 바이트 같음, 줄바꿈 수):
  - `nextdev/busvar.h` = 스테이징 `src/bsd/dev/busvar.h`(07 nextmach 채택본; 같음)
  - `nextdev/nbicreg.h` 34 줄 ≠ SDK `architecture/m68k/nbicreg.h` 34 줄
  - `next/cpu.h` 281 줄 ≠ SDK `bsd/m68k/cpu.h` 78 줄
  - `next/scr.h` 119 줄은 스테이징에 없음
- `us_timer.c` 는 `next/clock.h` 의 같은 이름 후보가 07 의 Mach `kern/clock.h` 라 내용이 다른 머리일 수 있어, 이번 대상에서 뺍니다. 구성 머리가 필요한 단위(`snd_rcv` 등)도 뺍니다.

방법(`m4_m68k_probe.py` 확장, 명세 `08_build/artifacts/m4p503/spec.json`, run `m4p503-p1`, 바탕 스테이징 `m0p502-a1-stage`):
- 도구 확장: 변형 값으로 `{"src": <경로|null|@rel>, "inc": [[<머리 상대 경로>, <파일>], …]}` 를 받습니다.
  - `inc` 파일은 스테이징 `src/m4probe/inc_<대상>_<V>/` 에 복사합니다.
  - 그 변형의 컴파일·의존 목록 줄에만 `-Isrc/src/m4probe/inc_<대상>_<V>` 를 기존 `-I` 들 **뒤**에 더합니다(스테이징에 있는 이름은 덮지 않음).
  - 기존 값(문자열·null)의 동작은 그대로입니다.
- 변형(대상마다; 소스 사본·별칭 파일은 `08_build/artifacts/m4p503/` 에 python 으로 만듦):
  - N(NeXTMach 머리): `.c` 는 NeXTMach 원문 그대로. 빠진 머리는 NeXTMach 원문 사본을 NeXTMach 경로로 둡니다(`next/scr.h`, `next/cpu.h`, `nextdev/nbicreg.h`, `nextdev/busvar.h`).
  - A(include 줄 고침): `.c` 의 빠진 include 줄만 스테이징 경로로 고칩니다(`nextdev/busvar.h` → `dev/busvar.h`, `nextdev/nbicreg.h` → `architecture/m68k/nbicreg.h`, `next/cpu.h` → `m68k/cpu.h`). 스테이징에 없는 `next/scr.h` 는 N 처럼 NeXTMach 사본을 둡니다.
  - B(별칭 머리): `.c` 는 그대로. 빠진 이름마다 그 경로에 스테이징 후보를 `#import` 하는 한 줄짜리 별칭 머리를 둡니다. `next/scr.h` 는 N 처럼 사본입니다.
- 기록 `09_validation/reconstruction/m4-m68k-probe-p503-20261024.json`. 맞지 않는 변형은 실기 `otool` 로 함수별 비교(`funcs`)를 합니다.

판정(미리 정함; 진단이므로 07 은 바꾸지 않음):
- 변형마다 컴파일 성공 여부와 첫 오류(빠진 정의 등), `candidate` 여부를 적습니다.
- 세 변형 사이의 객체 같음(canon·obj_sig)을 적습니다.
- 결과로 사용자께 여쭐 것:
  - NeXTMach 원문 머리와 SDK 머리 가운데 어느 쪽을 쓸지(내용이 다를 때 바이트가 가리는지)
  - include 줄을 고칠지, 별칭 머리를 둘지
  - NeXTMach 전용 머리(`next/scr.h` 등)를 07 어디에 둘지(예: x86 선례인 `07_kernel/nextmach/<경로>`)
  - 07 은 그 결정 뒤에 바꿉니다.

### 503.2 교차검토(codex `gpt-6.1-sol`) 판정과 계획 수정

제 오류: 계획의 줄 수·같음 비교를 `wc -l`·`cmp` 로 셌습니다(계산은 python 이 규칙). python 으로 다시 세어 같은 값을 얻었습니다: `busvar.h` 175/175 같음, `nbicreg.h` 34/34 다름, `cpu.h` 281/78 다름, `scr.h` 119(스테이징 없음).

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 단위별 빠진 머리·같음/다름·x86 선례(`NEXTMACH_RENAME`, `ioconf.c:9`)가 맞음; "SDK 먼저" 앞에 작성 비공개 머리·`KERNEL_STRIPPED` 예외가 있음 | python(위), `stage_headers.py:220–258` 읽음 | ✅ 문구 한정 |
| 뒤에 붙인 `-I` 는 스테이징 이름을 가리지 않음; A 의 고친 경로는 각각 한 곳으로 풀림 | 매니페스트와 M5 `-I` 순서로 python 확인(`dev/busvar.h`→`src/bsd/dev`, `architecture/m68k/nbicreg.h`→`components/architecture/m68k`, `m68k/cpu.h`·`machine/cpu.h`→`src/bsd/…`) | ✅ |
| N 은 "스테이징 위에 빠진 NeXTMach 머리만 얹은 것" 이지 NeXTMach 머리 환경 전체가 아님 | 설계 | ✅ 이름을 그렇게 적음 |
| `machine/cpu.h`(아키텍처 중립 철자)도 볼 것 | 스테이징 `bsd/machine/cpu.h`(ARCH_INCLUDE) | ✅ `next_table` 에 A2(`machine/cpu.h`) 를 더함 |
| `sys/user.h:345` 가 이미 `machine/cpu.h` 를 들이므로 두 `cpu.h` 가 함께 들어감; NeXTMach `next/cpu.h` 는 `master_cpu`·`dma_chip`·`slot_id` 등을 정의(임시 정의), SDK 는 `extern` | 스테이징 `sys/user.h:345`·`sys/param.h:48`, NeXTMach `next/cpu.h:44,66–70,83–98`, SDK `bsd/m68k/cpu.h:48–54` 읽음 | ✅ COMMON 비교 필수 |
| 컴파일 실패도 증거; 그때 객체 비교는 "없음" 으로 적고 "다름" 이라 하지 않음 | 설계 | ✅ |
| D021/D022·D039 가 이미 정책을 정함 → 결과는 그 안의 예외로 제시; 객체가 같다는 것은 이 단위·구성에서 구별되지 않는다는 뜻뿐; NeXTMach 공개는 D013 으로 허용 | `DECISIONS.md` 25–26·43 행, `AGENTS.md:6` | ✅ 질문 틀을 이에 맞춤 |
| 도구: 둘일 때만 짝 비교(`m4_m68k_probe.py:287`) → 모든 짝; 의존 출처를 바탕 매니페스트로만 셈 → 실제 스테이징 매니페스트로; N·B 가 같은 소스 사본 자리를 써서 충돌 → 변형별 자리 | 해당 줄 읽음, run `prepare.json` 의 `src` 칸 확인 | ✅ |
| 대조: 옛 명세(문자열·null 변형)의 결과가 그대로인지, `bus` 의 N/A/B 는 같아야 함 | 설계 | ✅ 관문으로 |

계획 수정(실행 전 고정):
- 도구:
  - 사전형 변형은 소스 사본을 `src/m4probe/v_<대상>_<V>/<파일 이름>` 에, 머리를 `src/m4probe/inc_<대상>_<V>/<경로>` 에 둡니다(변형별 자리라 충돌 없음).
  - 비교는 run `prepare.json` 의 `src` 스테이징 매니페스트로 의존 출처를 셉니다. 의존 목록마다 풀린 머리 경로·출처를 기록합니다.
  - 모든 변형 짝의 canon·obj_sig 같음을 기록하고, 컴파일 실패 짝은 "없음" 으로 적습니다.
  - 변형마다 COMMON·외부 정의 기호(이름·종류·크기)를 기록합니다.
- 대조 관문(어긋나면 멈춤):
  - 도구를 고친 뒤 §502 run(`m4p502-a1`, `@` 변형)과 §501 run(`m4p501-p1`, 문자열 변형)을 다시 비교해 판정·`gate`·짝 같음이 이전 기록과 같음
  - `bus` 의 N·A·B 객체가 서로 canon·obj_sig 같음(넣은 머리 바이트가 같으므로)
- 변형: N, A, B(세 대상 모두) + A2(`next_table` 만, `next/cpu.h` → `machine/cpu.h`).
- 결과 보고에서는 객체가 같음을 "이 단위·구성에서 구별되지 않음" 으로만 말합니다. 질문은 D021/D022·D039 의 틀 안에서, 예외가 필요한 곳(예: SDK `cpu.h` 대신 NeXTMach `next/cpu.h`)을 근거와 함께 여쭙니다.

실행 전 보충(§503): 세 단위는 x86 대응 줄이 없으므로, 컴파일 줄의 틀로 `machdep/i386/dkbad.c` 의 x86 줄을 씁니다(§496 에서 §429 치환 뒤 `-D`·`-I` 가 M5 m68k 줄과 정확히 같다고 확인한 줄). `-c` 소스와 `-o` 만 바꾸고, 사전형 변형에는 `-I` 하나를 뒤에 더합니다.

### 503.3 결과(2026-10-24)

- 대조 관문: 고친 도구로 §501 run·§502 run 을 다시 비교했습니다(`08_build/artifacts/m4p503/regress-p501.json`·`regress-p502.json`). 새 칸을 뺀 변형별 결과·명령·`gate`·`diag_gate` 가 이전 기록과 같습니다.
- run `m4p503-p1`(스테이징 `m4p503-stage` 917 파일 = 바탕 892 + 25, 20 명령 모두 종료 0, 경고 0, 의존 목록의 i386 머리 0). 기록 `09_validation/reconstruction/m4-m68k-probe-p503-20261024.json`.

| 대상 | 변형 | 텍스트(객체/원본) | L1 | 판정 | 변형끼리 |
|---|---|---|---|---|---|
| `bus` | N·A·B | 228 / 228 B | OBJECT_MATCH | candidate | 셋 모두 canon·obj_sig 같음 |
| `nbic` | N·A·B | 84 / 94 B | NOT_MATCH | no | 셋 모두 같음 |
| `next_table` | N·A·A2·B | 530 / 628 B | NOT_MATCH | no | 코드(canon)는 넷 모두 같음; obj_sig 는 N 만 다름 |

- `bus`: 머리를 어떻게 주어도 원본과 같은 객체입니다(`candidate`; 범위 시작 0x406632c 배치, 외부 기호 같음). 이 단위에서는 머리 공급 방식이 바이트로 구별되지 않습니다.
- `nbic`·`next_table`: 변형끼리 코드가 같고 원본과는 다릅니다. 원인은 머리가 아니라 1990 년 NeXTMach 글과 1997 년 원본의 소스 차이입니다(따로 진단).
- `next_table` 의 N 은 NeXTMach `next/cpu.h` 의 임시 정의 때문에 COMMON 10 개(`_board_rev`·`_cpu_type`·`_disk_chip`·`_dma_chip`·`_intr_mask`·`_intrmask`·`_machine_type`·`_master_cpu`·`_slot_id`·`_slot_id_bmap`)를 더 냅니다.
- 원본 기호표(`03_original/m68k/inventory/symbols.tsv`, 절 6 = `__DATA,__common`):
  - 위 가운데 `_disk_chip` 은 원본에 없습니다.
  - SDK `bsd/m68k/cpu.h` 에만 있는 `_cpu_rev`·`_cpu_clk`·`_mon_rev` 는 원본에 있습니다.
  - 원본의 기호 집합은 SDK(1997) `cpu.h` 와 맞고 NeXTMach(1990) `next/cpu.h` 와 맞지 않습니다. D021/D022(SDK 가 가진 이름은 SDK)를 바꿀 근거가 없고 오히려 뒷받침합니다.
- 바이트로 정해지지 않는 것(사용자 결정):
  - (1) NeXTMach `.c` 의 include 줄을 OPENSTEP 경로로 고칠지(A·A2; x86 선례 `ioconf.c` 의 `<dev/busvar.h>`), NeXTMach 경로의 별칭 머리를 둘지(B)
  - (2) NeXTMach 에만 있는 머리(`next/scr.h` 등)를 07 어디에 둘지

사용자 결정 D104(2026-10-24): M4 의 NeXTMach `.c` 를 07 에 넣을 때
- include 표기는 "m68k/ 경로로 고침" 입니다(제 추천 `machine/` 대신). SDK 에 같은 내용이 다른 경로로 있는 머리는 include 줄을 OPENSTEP 경로로 고치고, 아키텍처 머리는 `<m68k/…>`(예: `<m68k/cpu.h>`)로 적습니다. 아키텍처와 무관한 경로(예: `<dev/busvar.h>`, `<architecture/m68k/nbicreg.h>`)는 스테이징 경로 그대로입니다. 고친 줄은 파일에 표시하고 MODIFICATIONS 에 적습니다.
- NeXTMach 에만 있는 머리(`next/scr.h` 등)는 "07_kernel/nextmach/<경로> (Recommended)" 입니다(x86 선례와 같은 자리, NeXTMach mk-108.1 경로 그대로; m68k 스테이징이 넣음).
- 근거: §503 에서 세 표기가 시험한 세 단위의 코드 바이트를 바꾸지 않았고, `cpu.h` 는 SDK 판이 원본 기호 집합과 맞았습니다(D021/D022 유지).

## 504. M4-10 구현 계획 — 07 `src/machdep/m68k/bus.c`(NeXTMach `nextdev/bus.c` + include 한 줄 고침; D103·D104; 코딩 전, 2026-10-24)

배경: §503 에서 NeXTMach `nextdev/bus.c` 의 `#import <nextdev/busvar.h>` 를 `<dev/busvar.h>` 로 고친 꼴(A)이 m68k 원본과 같은 객체였습니다(OBJECT_MATCH, 228 B, 범위 시작 0x406632c 배치, 외부 기호 같음). D103(자리)·D104(include 표기)에 따라 07 에 넣습니다.

확인한 사실(이번 세션):
- NeXTMach `nextdev/bus.c` 는 71 줄(python)입니다. 머리에 SCCS 줄 `(c) 1987 NeXT` 만 있고 따로 된 고지 덩이는 없습니다. include 는 12 행 `#import <nextdev/busvar.h>` 를 빼고 모두 스테이징에서 풀립니다(§498).
- §503 A 사본 `08_build/artifacts/m4p503/src/bus_A.c`(SHA-256 `1b81fce5…`)는 run `m4p503-p1` 의 입력과 같고, 그 객체는 `12471a89…` 입니다.
- `dev/busvar.h` 는 m68k 스테이징에 `07_kernel/nextmach/nextdev/busvar.h`(D039, PROVENANCE 821 행)에서 들어옵니다. 새 머리는 필요 없습니다.
- `stage_m68k.py` 의 `M4FILES` 는 497·502 두 키입니다(§502).

방법(§502 와 같은 순서):
1. 07 파일 `07_kernel/src/machdep/m68k/bus.c` = NeXTMach `nextdev/bus.c` 에 다음 둘만 바꾼 것.
   - SCCS 줄 뒤에 설명 주석 한 덩이: "m68k: NeXTMach mk-108.1 nextdev/bus.c (plan 504, D103); the include line marked plan 504 uses the OPENSTEP path (D104)."
   - 12 행을 `#import <dev/busvar.h>	/* plan 504 (D104): NeXTMach <nextdev/busvar.h> */` 로.
   - 주석을 뺀 토큰이 §503 A 사본과 같은지 python 으로 확인합니다.
2. `stage_m68k.py`: `M4FILES[504]` = 502 목록 + `bus.c`, `EXCEPTS[504] = dict(EXCEPTS[502])`, 문서 줄.
   - `--plan 502 stage` 를 다시 만든 매니페스트가 `m0p502-a1-stage` 와 같아야 합니다.
   - `--plan 504 stage m0p504-a1-stage` 와 `m0p502-a1-stage` 의 파일 항목 차이는 `src/machdep/m68k/bus.c` 하나여야 합니다.
3. x86 입력 불변: `m4_x86_inputs.py s6ll`, `--plan 504 x86gate`.
4. 최종 확인 run `m4p504-a1`:
   - 대상 `bus`, `m4_id` `m68k-211`, 줄 틀은 `machdep/i386/dkbad.c` 의 x86 줄(§503 과 같음), 변형 `F` = `@machdep/m68k/bus.c`.
   - `refs` = §503 A 객체. `gate.ok`.
   - COMMON·정의 기호가 REF 와 같음(python).
   - 입력 사슬: 07 = 스테이징 = run 사본.
   - 기록 `09_validation/reconstruction/m4-m68k-p504-final-20261024.json`
5. 상태표: `ACCEPTED` 에 §504 기록을 더해 다시 만듭니다(앞 기록 재확인 통과, 근거 문서를 먼저 씀).
6. 기록:
   - PROVENANCE 새 행(출처 `nextmach`; 고지 칸 "SCCS line only in the NeXTMach file; no separate notice"; 바뀜 칸에 D104 include 줄)
   - MODIFICATIONS 새 행
   - diff `06_reconstruction/evidence/m68k-bus.diff`(NeXTMach → 07)
   - 근거 문서 `06_reconstruction/evidence/m68k-bus.md`
   - 상태 절과 결과 절

### 504.1 교차검토(codex `gpt-6.1-sol`) 판정과 계획 수정

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| SCCS `(c)` 줄을 그대로 두면 되고 따로 옮길 고지 덩이는 없음; 표시한 `<dev/busvar.h>` 는 D104 에 맞음 | NeXTMach `nextdev/bus.c:1` 읽음, D104 | ✅ |
| 줄 틀(dkbad 의 x86 줄)은 §503 명세에 이미 명시; "빌려 쓴 틀" 로 기록할 것 | `08_build/artifacts/m4p503/spec.json` 의 `x86_rel` | ✅ 근거 문서에 적음 |
| 단계와 관문은 충분 | §502 와 같은 관문 | ✅ |
| 기록에 REF 경로·전체 SHA, `ACCEPTED` 의 (경로, SHA), 저장소 URL·커밋·함수별 줄(`busgo` 19·`busdone` 54), 스테이징 차이·COMMON·입력 사슬 python 결과의 저장 자리를 명시할 것 | python: `busgo` 19 행·`busdone` 54 행 | ✅ 아래에 고정 |

계획 수정: python 확인 결과(스테이징 재현·차이, COMMON·정의 기호, 입력 사슬)를 `09_validation/reconstruction/m4-m68k-p504-checks-20261024.json` 에 저장합니다. 근거 문서에 REF 경로·SHA-256, 저장소 URL·커밋, `busgo`(19 행)·`busdone`(54 행)을 적습니다.

### 504.2 결과(2026-10-24)

- 1: `07_kernel/src/machdep/m68k/bus.c`(76 행, SHA-256 `7c0b4844c4d56f4fdc989316f2df512850a6e3681625d2577d28e3b9401f6d46`) = NeXTMach `nextdev/bus.c` + 설명 주석 + include 한 줄(`<dev/busvar.h>`, 표시 `plan 504 (D104)`). 주석을 뺀 토큰이 §503 A 사본과 같습니다(python). diff `06_reconstruction/evidence/m68k-bus.diff`.
- 2: `stage_m68k.py` 에 `M4FILES[504]`·`EXCEPTS[504]`·문서 줄을 더했습니다(567 → 569 행). `--plan 502` 스테이징을 다시 만든 매니페스트가 `m0p502-a1-stage` 와 같고, `--plan 504 stage m0p504-a1-stage`(893 파일)와의 차이는 `src/machdep/m68k/bus.c` 하나입니다.
- 3: x86 입력 불변. `m4_x86_inputs.py s6ll` ok(`09_validation/reconstruction/m4-x86-inputs-p504-20261024.json`), `--plan 504 x86gate` 일곱 묶음 같음.
- 4: run `m4p504-a1`(기록 `09_validation/reconstruction/m4-m68k-p504-final-20261024.json`). `gate` 모두 참입니다(경고 0, i386 머리 0, `candidate`, REF = §503 A 객체). 정의·COMMON 기호가 REF 와 같고, 입력 사슬이 하나의 SHA-256 입니다. python 확인 결과는 `09_validation/reconstruction/m4-m68k-p504-checks-20261024.json` 에 있습니다.
- 5: 상태표를 다시 만들었습니다(앞 다섯 객체 행 그대로, `bus` 추가, 두 번 돌린 출력 같음). 받아들인 M4 객체 6 개, §495 행 7/188, 3690 B(1.71%).
- 6: PROVENANCE 새 행(1103 → 1104 행, 경로 중복 0), MODIFICATIONS 새 행, 근거 문서 `06_reconstruction/evidence/m68k-bus.md`.

## 505. M4-11 세부 계획 — `nbic` 의 1997 년 꼴 진단(`nbic_bus_enable` 작성 + `nbic_configure` 고침; 07 변경 없음; 코딩 전, 2026-10-24)

배경: §503 에서 `nbic`(`m68k-232`)은 머리를 어떻게 주어도 84 B 로, 원본 94 B 와 다릅니다. 이번 세션에 원본 목록을 읽어 차이의 원인을 확인했습니다.

확인한 사실(이번 세션; 원본 목록 `08_build/artifacts/m0p414/otool-V10/image.txt`, 기호표 `03_original/m68k/inventory/symbols.tsv`, §503 객체의 실기 목록 `08_build/artifacts/m4p505/otool/nbic_A503.txt`):
- 원본 `_nbic_configure`(0x4072672–0x40726d0, 94 B):
  - `bsr 0x40725e2`(`_nbic_bus_enable`)의 결과가 0 이면 끝냅니다.
  - `probe_rl(0xf0fffff0)`(`_probe_rl` 0x4001898; 값은 SDK `architecture/m68k/nbicreg.h:17` `NBIC_IDR_BUS`)가 0 이면 끝냅니다.
  - `nbic_present = 1`, `printf("NBIC present\n")`.
  - `machine_type`(0x40b61ac, 바이트)이 0 또는 2 일 때만 `NBIC_IDR`·`NBIC_CR` 두 저장을 합니다.
  - NeXTMach 의 `*scr2 |= SCR2_OVERLAY` 가 없고, NeXTMach 의 `probe_rb(NBIC_CR)` 대신 위 호출입니다.
- 원본 `_nbic_bus_enable`(0x40725e2–0x4072672, 144 B; §495 의 `m68k-231`, unassigned, 묶음 G)은 어느 참고 트리에도 없습니다(파일 이름·함수 이름 전수 검색 0). 목록 해석:
  - 앞머리에서 `slot_id`(0x40c32d4, long)를 읽어 `slot_id + 0x0200d000`(NeXTMach `next/cpu.h:180` `P_SCR2`)과 `slot_id + 0x02200010`(이름 없음)을 계산합니다.
  - `machine_type` 이 0·2·8·9 가 아니면 0 을 돌려줍니다. 비교 순서(2 와 같음 → 큼이면 8·9 범위 → 0)는 gcc 의 switch 균형 나무 꼴입니다.
  - `dma_chip`(0x40c32d0, word)이 0x139(313)이면 `*P_SCR2 |= 0x80`(`SCR2_OVERLAY`)입니다.
  - 아니면 `*P_SCR2 &= ~0x80`, `*(slot_id + 0x02200010) &= ~0x300`, `*(u_char *)(slot_id + 0x02012000) = 0x88`(`slot_id` 를 다시 읽음)입니다.
  - 그 뒤 `bmap_chip`(0x40b67f8)이 0 이 아니면 +4 바이트에서 0x40 을 지웁니다. NeXTMach `next/bmap.h` 의 `struct bmap_chip` 에서 0x04 레지스터의 MSB 순 둘째 비트 `bm_lo` 입니다. 그리고 1 을 돌려줍니다.
- 원본 `__common`(절 6)에 `_nbic_present`·`_machine_type`·`_dma_chip`·`_slot_id`·`_bmap_chip`·`_scr2`·`_brightness` 가 있습니다. `_scr1` 은 원본 기호표에 없습니다. NeXTMach `nbic.c:12` 는 `int nbic_present = 0;`(초기값이 있어 `__data`)이고, §503 객체의 L1 사유 `__DATA,__data: fail` 은 이것과 맞습니다.
- NeXTMach `next/scr.h:115–117` 은 `scr1`·`scr2`·`brightness` 를, `next/bmap.h:55` 는 `bmap_chip` 을 임시 정의합니다. `scr.h:34–37` 의 기계 형 이름은 0–3 뿐이라 8·9 의 이름이 없습니다.
- m68k 목록에서는 같은 파일 안의 정적 함수 호출도 `bsr …:l` 이라 호출 꼴로 파일 경계를 알 수 없습니다(`swapfs` 의 `swapfs_release` 호출 0x40328b4 로 확인). NeXTMach `conf/files.NeXT:49–50` 은 `monitor.s` 바로 다음이 `nbic.c` 이고, 1997 년 원본은 그 사이에 `nbic_bus_enable` 이 있습니다.

가설(바이트로 증명되지 않음): 1997 년 `nextdev/nbic.c` 는 `nbic_bus_enable` 과 `nbic_configure` 를 이 순서로 담습니다. 이번 진단의 범위는 §495 두 행 `m68k-231`·`m68k-232`(0x40725e2–0x40726d0, 238 B)입니다.

방법(`m4_m68k_probe.py`, 명세 `08_build/artifacts/m4p505/spec.json`, run `m4p505-p1`, 바탕 스테이징 `m0p504-a1-stage`, 컴파일 줄 틀은 §503 과 같이 `machdep/i386/dkbad.c` 의 x86 줄):
- 변형의 소스는 `08_build/artifacts/m4p505/src/` 에 python 으로 만듭니다. NeXTMach `nbic.c` 의 머리 주석과 include 를 바탕으로 합니다.
- 공통(W·W2·W3):
  - include 는 D104 꼴입니다: `<sys/types.h>`, `<architecture/m68k/nbicreg.h>`, `<m68k/cpu.h>`(SDK: `extern u_short dma_chip`, `extern u_char machine_type`).
  - `int nbic_present;` 로 초기값을 뺍니다(원본 `__common`).
  - `nbic_bus_enable` 을 `nbic_configure` 앞에 둡니다.
- W(숫자 + 지역 extern):
  - `extern int slot_id;`, `extern volatile u_char *bmap_chip;` 을 선언합니다.
  - `nbic_bus_enable` 은 위 해석대로 씁니다. 지역 포인터 둘(`slot_id + 0x0200d000`, `slot_id + 0x02200010`)을 선언에서 초기화하고, `switch (machine_type) { case 0: case 2: case 8: case 9: break; default: return (0); }` 를 씁니다. `dma_chip == 313` 갈래, `bmap_chip[4] &= ~0x40`, `return (1)` 입니다.
  - `nbic_configure` 는 `if (nbic_bus_enable() && probe_rl(NBIC_IDR_BUS))` 안에서 `nbic_present = 1; printf(…);` 를 하고, `if (machine_type == 0 || machine_type == 2)` 일 때 두 저장을 합니다.
- W2: W 에서 `switch` 만 `if (machine_type != 0 && machine_type != 2 && (machine_type < 8 || machine_type > 9)) return (0);` 로 바꿉니다(바이트가 꼴을 가리는지).
- W3: W 와 같은 식을 NeXTMach 머리의 이름으로 씁니다. 변형별 `inc` 에 NeXTMach `next/cpu.h`·`next/scr.h`·`next/bmap.h` 사본을 둡니다. 쓰는 이름은 `P_SCR2`·`SCR2_OVERLAY`·`NeXT_CUBE`·`NeXT_X15`·`struct bmap_chip` 의 `bm_lo` 이고, 8·9·0x02200010·0x02012000·313 은 숫자로 둡니다. 텍스트가 W 와 같은지, 더 생기는 COMMON 이 무엇인지 봅니다.
- 비교: `compare`(L1 `--place-from-image`, 두 행 범위, 원본 이름, 원본에 없는 미정의), 변형마다 정의·COMMON 기호와 원본 `__common` 의 대조, 맞지 않으면 실기 `otool -tv` 로 `funcs`(함수별, 숫자를 가린 명령 열).
- 기록 `09_validation/reconstruction/m4-m68k-probe-p505-20261024.json`(+ `funcs` 기록). 변형 소스는 무시되는 `08_build/artifacts` 에만 둡니다.

판정(미리 정함; 진단이므로 07 은 바꾸지 않음):
- 텍스트가 원본과 같고 L1 이 OBJECT_MATCH(또는 사유가 자료·bss 미확정뿐)인 변형은 후보 꼴입니다.
- 후보가 나오면 바이트로 정해지지 않는 것을 여쭙습니다:
  - 머리 공급과 이름(W 처럼 숫자·지역 extern, 또는 W3 처럼 NeXTMach 머리 이름; W3 는 원본에 없는 COMMON 을 낳을 수 있음)
  - `nbic_bus_enable` 을 `nbic.c` 에 둘지
  - 그 뒤 07 에 넣는 구현 계획을 씁니다.
- 후보가 없으면 `funcs` 차이를 적고 다음 꼴을 따로 계획합니다.

관문(어긋나면 멈추고 보고): 스테이징 매니페스트 = 바탕 + 변형 파일, 컴파일 줄의 `-D`·`-I` 가 M5 m68k 줄과 같음, 모든 명령의 상태가 기록됨, 경고·i386 머리 기록.

### 505.1 교차검토(codex `gpt-6.1-sol`) 판정과 계획 수정

제 오류: 판정 규칙의 "사유가 자료·bss 미확정뿐" 은 도구 규칙과 다릅니다. `m4_m68k_probe.py:310–311` 은 `candidate` = OBJECT_MATCH, `provisional` = 사유가 정확히 `['__DATA,__bss: unverified']` 입니다. 도구 규칙을 따릅니다.

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 두 함수의 명령 해석이 맞음; 빠진 명령·잘못 읽은 갈래 없음; `switch` 는 "switch 낮춤 꼴과 맞음" 으로 낮춰 말할 것 | 원본 목록 0x40725e2–0x40726ce 를 이번 세션에 직접 읽음(위 해석) | ✅ 표현을 "switch 낮춤과 맞는 꼴" 로 |
| `nbic_configure` 는 값을 돌려주지 않음(끝에 d0 설정 없음) | 원본 목록 0x40726cc–0x40726ce `unlk; rts` | ✅ `void` 꼴 반환 없음(K&R 정의 그대로) |
| 주소 일곱의 이름·절이 맞음; `_scr1` 없음 | 이번 세션 python(기호표 값 대조) | ✅ |
| `slot_id` 는 "long" 이 아니라 "longword 읽기"; NeXTMach `int slot_id` | NeXTMach `next/cpu.h:95` 읽음 | ✅ `extern int slot_id;` |
| W3 에서 W 의 `extern volatile u_char *bmap_chip` 은 `next/bmap.h:55` 의 구조체 포인터 선언과 충돌 | `bmap.h:55` 읽음 | ✅ W3 는 머리의 선언을 씀(W 의 지역 extern 둘을 뺌) |
| NeXTMach 머리는 원본에 없는 `_disk_chip`·`_scr1` 을 임시 정의 | `next/cpu.h:66–67`, `scr.h:115` 읽음 | ✅ COMMON 관문으로 |
| 바이트 접근 꼴의 다른 후보(지역 임시 변수) | 설계 | ✅ W4 를 더함 |
| 도구: 옵션 비교는 기록만 함(`:172`), `refs` 가 없으면 `diag_gate` 실패에도 종료 0(`:332` 부근), `full_span` 은 COMMON 을 보지 않음(`:296`) | 해당 줄 읽음 | ✅ 아래 관문을 python 으로 따로 확인 |
| 두 함수가 한 파일이라는 가설의 세기가 맞음; 문자열 순서는 판정에 쓰이지 않음 | 설계 | ⏭️ 문자열 주장은 문서에 옮기지 않음 |

계획 수정(실행 전 고정):
- 변형:
  - W: 위와 같음. 지역 포인터는 `volatile int *` 이고, 바이트 저장은 `slot_id` 를 다시 쓰는 식(`*(volatile u_char *)(slot_id + 0x02012000) = 0x88`)입니다. `nbic_configure` 는 값을 돌려주지 않습니다.
  - W2: W 에서 기계 형 검사만 `if` 꼴입니다.
  - W3: W 의 식을 NeXTMach 이름으로 씁니다. `inc` 는 `next/cpu.h`·`next/scr.h`·`next/bmap.h` 사본이고, `slot_id`·`bmap_chip` 의 지역 extern 은 뺍니다(머리 선언). `bmap_chip->bm_lo = 0` 입니다.
  - W4: W 에서 `bmap_chip` 갈래만 `{ u_char c = bmap_chip[4]; bmap_chip[4] = c & ~0x40; }` 입니다.
- 판정: 도구의 `candidate`(OBJECT_MATCH + `full_span`)·`provisional`(bss 하나)을 따릅니다. 숫자를 가린 `funcs` 같음은 진단일 뿐 받아들임 근거가 아닙니다.
- 관문(python 으로 따로 확인, 어긋나면 멈춤):
  - 컴파일 줄마다 `-I`·`-D` 가 M5 m68k 줄과 같고, 사전형 변형만 자기 `-I` 하나가 더해짐
  - `diag_gate` 두 값이 모두 참(경고 0, i386 머리 0)
  - 변형마다 정의·COMMON 기호 가운데 원본 기호표에 없는 이름을 적음. 후보 판정과 별개로 W3 의 추가 COMMON(`_scr1`·`_disk_chip` 등)을 기록함

### 505.2 결과(2026-10-24)

- run `m4p505-p1`(스테이징 `m4p505-stage` 900 파일 = 바탕 893 + 7): 8 명령 모두 종료 0·경고 0, 의존 목록의 i386 머리 0(`diag_gate` 두 값 참). 컴파일 줄의 옵션은 M5 줄과 같습니다(`cmd` 출력 `[['nbic', [], [], True]]`).
- 기록 `09_validation/reconstruction/m4-m68k-probe-p505-20261024.json`, 함수별 `m4-m68k-funcs-p505-20261024.json`(실기 목록 `08_build/artifacts/m4p505/otool/`).

| 변형 | 텍스트(객체/원본) | L1 | 함수 같음(숫자 가림) | 원본에 없는 정의 기호 |
|---|---|---|---|---|
| W | 238 / 238 | NOT_MATCH(참조 3 다름, 바이트 차이 84, 첫 차이 +37) | 1/2(`nbic_configure`) | 없음 |
| W2 | 226 / 238 | NOT_MATCH | 1/2 | 없음 |
| W3 | 238 / 238 | NOT_MATCH(W 와 같은 사유) | 1/2 | `_disk_chip`·`_scr1` |
| W4 | 238 / 238 | NOT_MATCH | 1/2 | 없음 |

- W 와 W4 는 canon 이 같습니다(바이트 접근 꼴은 구별되지 않음).
- `nbic_configure` 는 네 변형 모두 원본과 같은 명령 열입니다.
- `nbic_bus_enable` 의 차이는 switch 비교 나무와 `return (0)` 의 자리뿐입니다.
  - 원본: `beq 본문; blt 8·9 검사; tstl; beq 본문; bra 끝의 clrl`, 8·9 검사 뒤 본문으로 떨어짐. 본문 끝 `moveq #1,d0; bra`, 함수 맨 끝 `clrl d0`(0x407266c).
  - W: `beq 본문; bge 0 검사; 9·8 검사; bra 본문; 0 검사 뒤 clrl d0; bra 끝`. `return (0)` 이 switch 바로 뒤입니다.
  - 해석: 원본 소스는 본문이 `case` 안에 있고 `return (0)` 이 본문 뒤에 오는 꼴로 보입니다.
- W2 의 크기가 다른 것은 기계 형 검사가 switch 낮춤 꼴이라는 해석과 맞습니다.
- W3 는 텍스트가 W 와 같은 크기·같은 사유이고, 원본에 없는 COMMON `_disk_chip`·`_scr1` 을 냅니다. NeXTMach 머리를 그대로 쓰면 원본 기호 집합과 어긋납니다.

## 505.3 추가 변형 계획(같은 진단의 연속; 07 변경 없음; 코딩 전)

- W5: W 의 `nbic_bus_enable` 을 다음 꼴로 바꿉니다(다른 곳은 W 와 같음).
  - `switch (machine_type) { case 0: case 2: case 8: case 9: <dma_chip 갈래>; <bmap_chip 갈래>; return (1); }`
  - switch 뒤 `return (0);`
- W6: W5 와 같되 switch 안 마지막에 `default: return (0);` 을 두고, switch 뒤 `return` 은 없습니다.
- 두 지역 포인터의 선언 초기화는 W 와 같습니다(원본도 switch 앞에서 계산).
- 같은 명세에 변형을 더해 새 run `m4p505-p2` 로 컴파일합니다. 판정·관문은 §505.1 과 같습니다.
- 하나가 `candidate` 이면 W3 의 결과(원본에 없는 COMMON)와 함께 바이트로 정해지지 않는 것을 여쭙습니다. 머리·이름 공급 방식과 `nbic_bus_enable` 을 `nbic.c` 에 둘지입니다.

### 505.4 교차검토(codex `gpt-6.1-sol`) 판정과 수정

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 차이는 비교 나무 배치·`return (0)` 자리뿐(원본 `blt` 는 machine_type > 2 로 감; 성공 범위 검사는 본문으로 떨어짐; W 는 `bra 본문` 이 더 있음); MMIO 본문 명령은 같음 | 두 목록을 이번 세션에 나란히 읽음(§505.2) | ✅ |
| `nbic_configure` 는 배치·재배치 뒤 같음(L1 함수 MATCH, 바이트 차이 0) | `l1-nbic-W.json` 함수 판정 python 출력: `DIFF`(84, 참조 3) / `MATCH`(0) | ✅ |
| W5·W6 이 알맞은 다음 시험(W5 먼저); case 순서 바꿈은 미룸; 실패하면 `if`/`goto` 꼴 하나 | 설계 | ✅ |
| 같은 명세를 고치지 말고 새 스테이징·새 산출물 이름을 쓸 것; `otool.sh` 는 같은 파일 이름에 씀 | `m4_m68k_probe.py:95–97`(대상이 있으면 거부), `otool.sh:2` 읽음 | ✅ p2 는 `08_build/artifacts/m4p505/p2/` 의 새 명세·스테이징 `m4p505-stage2`·새 기록 이름 |

수정: p2 명세는 대조 W(p1 과 canon 같아야 함) + W5 + W6 입니다. p1 명세·산출물은 그대로 둡니다(명세 SHA-256 기록).

### 505.5 p2 결과와 다음 변형 계획(07 변경 없음; 코딩 전)

- run `m4p505-p2`(새 명세 `08_build/artifacts/m4p505/p2/spec.json`, 스테이징 `m4p505-stage2` 896 파일 = 바탕 893 + 3): 6 명령 모두 종료 0·경고 0, i386 머리 0. 기록 `09_validation/reconstruction/m4-m68k-probe-p505b-20261024.json`, 실기 목록 `08_build/artifacts/m4p505/p2/otool/`.
- 대조 W 는 p1 의 W 와 canon·obj_sig 가 같습니다(재현). p1 명세 SHA-256 `7b7956bf…` 는 p1 기록과 같습니다.
- W5·W6 은 서로 같은 객체입니다. L1 은 `__TEXT,__text: fail` 하나이고, 참조 차이는 0 입니다. 바이트 차이는 1 개(+128, 원본 0x4072662)이고, `nbic_configure` 는 MATCH 입니다. 비교 나무와 `return (0)` 자리는 원본과 같아졌습니다.
- 남은 1 바이트는 `andi.b` 의 즉시값 워드입니다(python 으로 바이트를 직접 읽음).

| 객체 | +126 부터 4 바이트 |
|---|---|
| 원본 | `0200 ffbf` |
| W·W4·W5 | `0200 00bf`(`bmap_chip[4] &= ~0x40`, 바이트 꼴) |
| W3 | `0200 ffbf`(`bmap_chip->bm_lo = 0`, `next/bmap.h` 비트필드) |

- 해석: 원본은 `struct bmap_chip` 의 비트필드 꼴로 쓰였습니다. NeXTMach `next/bmap.h:55` 의 임시 정의 `bmap_chip` 은 원본 `__common` 에 있으므로, 이 머리는 원본에 없는 기호를 만들지 않습니다(`_scr1` 은 `scr.h`, `_disk_chip` 은 `next/cpu.h` 에서 옴).

다음 변형(같은 진단의 연속; 새 명세 `08_build/artifacts/m4p505/p3/spec.json`, 스테이징 `m4p505-stage3`, run `m4p505-p3`, 기록 `…-probe-p505c-…`):
- W7: W5 에서 `extern volatile u_char *bmap_chip;` 을 빼고 `#import <next/bmap.h>`(`inc` 에 NeXTMach 사본)를 더합니다. `bmap_chip` 갈래는 `bmap_chip->bm_lo = 0;` 입니다. 그 밖(숫자·`extern int slot_id`)은 W5 와 같습니다.
- W8: W5 의 흐름을 W3 의 이름·머리(`next/cpu.h`·`next/scr.h`·`next/bmap.h`)로 씁니다. 텍스트가 W7 과 같은지, 원본에 없는 COMMON 이 무엇인지 봅니다.
- 대조: W5(p2 의 W5 와 canon·obj_sig 같아야 함).
- 판정·관문은 §505.1 과 같습니다. W7 이 `candidate` 이고 원본에 없는 정의 기호가 없으면 진단을 마치고, 바이트로 정해지지 않는 것을 여쭙습니다.

### 505.6 교차검토(codex `gpt-6.1-sol`) 판정과 수정

제 오류: §505.5 표의 머리 "+126 부터 4 바이트" 는 원본·W5 에만 맞습니다. W·W4·W3 의 `andi.b` 는 +130 에 있습니다(앞선 python 출력 "andi.b imm at 130" 과 같음). 바이트 값(`ffbf`/`00bf`)은 맞습니다.

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| W5 의 재배치 밖 바이트 차이는 +128 하나(원본 `ff`, W5 `00`) | L1 기록(바이트 차이 1, 첫 차이 128, 참조 차이 0)과 이번 세션의 바이트 출력 | ✅ |
| 표의 오프셋은 W·W4·W3 에서 +130 | 이번 세션 python 출력 | ✅ 제 오류 |
| `ffbf` 는 비트필드 꼴과 "맞음" 일 뿐 원래 문법의 증명이 아님(다른 꼴 미시험) | 설계 | ✅ 표현을 낮춤 |
| `next/bmap.h` 의 최상위 정의는 `bmap_chip` 하나; 원본 `_bmap_chip` 은 `__common` | 이번 세션 python(90 행 중 55 행), 기호표 python | ✅ |
| p3 관문: W5 는 실패하는 대조(+128 하나)로 고정; W7 은 OBJECT_MATCH·`full_span`·참조 차이 0·예상 밖 정의 없음; COMMON 크기도 봄; 옵션·경고·i386 확인; W8 은 진단 | 설계 | ✅ 아래 관문으로 |

p3 관문(어긋나면 멈춤):
- 명령 6 개 종료 0·경고 0, i386 머리 0, 옵션이 M5 줄과 같고 사전형 `inc` 의 `-I` 만 더해짐
- 대조 W5 가 p2 의 W5 와 canon·obj_sig 같음
- W7: `judgement` 가 `candidate`(OBJECT_MATCH + `full_span`)이고, 정의 기호가 `_nbic_bus_enable`·`_nbic_configure`(SECT)·`_nbic_present`(COMMON 4)·`_bmap_chip`(COMMON 4) 이고, 원본 기호표에 모두 있음
- W8 은 진단(원본에 없는 COMMON 을 적음)

### 505.7 p3 결과와 진단 정리(2026-10-24)

- run `m4p505-p3`(명세 `08_build/artifacts/m4p505/p3/spec.json`, 스테이징 `m4p505-stage3` 900 파일 = 바탕 893 + 7; 기록 `09_validation/reconstruction/m4-m68k-probe-p505c-20261024.json`). 관문을 모두 통과했습니다.
  - 6 명령 종료 0·경고 0, i386 머리 0, 옵션이 M5 줄과 같음(사전형 `-I` 만 더해짐).
  - 대조 W5 는 p2 의 W5 와 canon·obj_sig 같음.
- **W7 은 `candidate`** 입니다. L1 OBJECT_MATCH, 사유 없음, `full_span`(238 B, 0x40725e2 배치, 원본 이름 둘)이고, 원본에 없는 미정의는 없습니다. 정의 기호는 `_nbic_bus_enable`·`_nbic_configure`(SECT), `_nbic_present`·`_bmap_chip`(COMMON 4)이고, 모두 원본 `__common` 에 4 바이트 간격·4 정렬로 있습니다(python).
- W8 은 텍스트가 W7 과 같고(canon 같음) 역시 OBJECT_MATCH 입니다. 그러나 원본에 없는 COMMON `_disk_chip`(NeXTMach `next/cpu.h`)·`_scr1`(`next/scr.h`)을 냅니다. 링크 때 원본 기호 집합과 어긋나므로 NeXTMach `next/cpu.h`·`next/scr.h` 를 그대로 들이는 꼴은 쓸 수 없습니다.
- 진단 요약(바이트가 정한 것):
  - `nbic_present` 는 초기값 없는 COMMON 입니다.
  - `nbic_bus_enable` 의 기계 형 검사는 본문을 `case 0: case 2: case 8: case 9:` 안에 두고 `return (0)` 을 뒤에 둔 switch 꼴입니다(W5·W6 은 같은 객체라 `default:` 유무는 구별되지 않음).
  - `bmap_chip` 은 `struct bmap_chip` 비트필드(`bm_lo = 0`)와 맞습니다(`andi.b` 즉시값 `ffbf`).
  - `nbic_configure` 는 `nbic_bus_enable() && probe_rl(NBIC_IDR_BUS)` 와 기계 형 0·2 검사입니다.
- 바이트로 정해지지 않는 것(사용자 결정):
  - (1) `nbic_bus_enable` 을 `nbic.c` 에 둘지. 근거는 인접, 1990 년 링크 순서(`monitor.s` → `nbic.c`), 이름 앞머리입니다.
  - (2) 이름 공급. W7(주소·기계 형은 숫자, `extern int slot_id;`, `struct bmap_chip` 만 NeXTMach `next/bmap.h`) 또는 NeXTMach `next/scr.h` 를 고친 사본(원본에 없는 `scr1` 임시 정의를 뺌, 표시)으로 `NeXT_CUBE`·`NeXT_X15`·`SCR2_OVERLAY` 이름을 쓰는 꼴입니다. 8·9·0x02200010·0x02012000·313 은 어느 쪽이든 이름이 없습니다.
  - `bmap.h` 의 자리·표기는 D104 를 따릅니다(사본 `07_kernel/nextmach/next/bmap.h`, include `<m68k/bmap.h>`).
- `slot_id`·`machine_type`·`dma_chip` 의 COMMON 정의를 어느 객체가 낼지는 이 객체의 일이 아닙니다(M7 링크에서 다룸).

사용자 결정 D105(2026-10-24): m68k `nbic` 은
- `nbic_bus_enable` 을 `nbic.c` 안에 `nbic_configure` 앞에 둡니다("nbic.c 에 둠 (Recommended)").
- 이름 공급은 W7 꼴입니다("W7: 숫자 + bmap.h 만 (Recommended)"). 주소·기계 형 값은 숫자, `extern int slot_id;` 를 파일에 선언, `struct bmap_chip` 만 NeXTMach `next/bmap.h`(D104: 사본 `07_kernel/nextmach/next/bmap.h`, include `<m68k/bmap.h>`).
- 근거: §505.7(W7·W8 텍스트 같음; NeXTMach `next/cpu.h`·`next/scr.h` 를 그대로 들이면 원본에 없는 COMMON `_disk_chip`·`_scr1`).

## 506. M4-12 D105 구현 계획 — 07 `src/machdep/m68k/nbic.c` 와 `07_kernel/nextmach/next/bmap.h`(코딩 전, 2026-10-24)

확인한 사실(이번 세션):
- 기준 객체(REF) = §505 p3 의 W7 객체 `08_build/runs/m4p505-p3/stage/Q505__nbic_W7.o`(SHA-256 `89dfef5c64c20f9c027425dff1ae70904af60788d73b2461e8a3698bc783c02b`), 소스 `08_build/artifacts/m4p505/src/nbic_W7.c`(SHA-256 `5b7d9235695cf3e905a5ac22a5771f3667d4065f348b244ba2d681cd0e2997ff`).
- NeXTMach `next/bmap.h` 는 90 줄이고, 최상위 정의는 55 행 `bmap_chip` 하나입니다. 1 행에 SCCS 줄 `(c) 1990 NeXT` 가 있고, 따로 된 고지 덩이는 없습니다. SDK 사본·07 에는 `bmap.h` 가 없습니다(파일 이름 검색 0).
- m68k 스테이징(`stage_m68k.py`)에는 NeXTMach 전용 머리를 들이는 장치가 없습니다. 지금 있는 것은 `M4FILES`(소스)·SDK 사본·덮어쓰기 트리입니다.
- x86 `stage_headers.py:240–255` 는 `07_kernel/nextmach/<경로>` 를 이름으로 먼저 찾습니다. x86 입력이 그대로인지 x86gate 와 `m4_x86_inputs.py` 로 확인해야 합니다.
- 상태표 도구 `m4_m68k_status.py` 는 기록마다 `08_build/artifacts/m4p<계획>/spec.json` 을 읽습니다. 두 행 `m4_id` 는 §500(`vm_unix`) 선례가 있습니다.

방법:
1. 07 파일 둘:
   - `07_kernel/nextmach/next/bmap.h` = NeXTMach `next/bmap.h` 그대로(python 복사, SHA-256 같음).
   - `07_kernel/src/machdep/m68k/nbic.c` = W7 글에서 다음만 바꾼 것.
     - NeXTMach 머리 주석(1–6 행) 뒤에 설명 주석 한 덩이: m68k 1997 꼴, `nbic_bus_enable` 은 원본 바이트에서 작성(D024), 이름 없는 값은 숫자(D105), `nbic_present` 초기값 없음.
     - `#import <next/bmap.h>` → `#import <m68k/bmap.h>`(D104).
     - 바뀐·작성 줄 끝에 `/* plan 506 (D105) */` 를 답니다(문자열 밖).
     - 주석을 뺀 토큰이 W7 에서 `next/bmap.h` → `m68k/bmap.h` 만 바꾼 것과 같은지 python 으로 확인합니다.
2. `stage_m68k.py`:
   - `M4FILES[506]` = 504 목록 + `nbic.c`.
   - 새 표 `M4HEADERS = {506: [('next/bmap.h', 'src/bsd/m68k/bmap.h')]}`: `07_kernel/nextmach/<앞>` 을 스테이징 `<뒤>` 에 넣습니다. 그 자리에 파일이 이미 있으면 멈춥니다. 매니페스트 출처를 적고, 문서 줄을 더합니다.
   - `EXCEPTS[506] = dict(EXCEPTS[504])`.
   - 회귀: `--plan 504 stage` 를 다시 만든 매니페스트가 `m0p504-a1-stage` 와 같아야 합니다.
   - `--plan 506 stage m0p506-a1-stage` 와 `m0p504-a1-stage` 의 파일 항목 차이는 `src/machdep/m68k/nbic.c`·`src/bsd/m68k/bmap.h` 둘이어야 합니다.
3. x86 입력 불변: `m4_x86_inputs.py s6ll`(기록 `m4-x86-inputs-p506-…`)과 `--plan 506 x86gate`(일곱 묶음 같음).
4. 최종 확인 run `m4p506-a1`(명세 `08_build/artifacts/m4p506/spec.json`):
   - 대상 `nbic`, `m4_id` [`m68k-231`, `m68k-232`], 줄 틀 `machdep/i386/dkbad.c`, 변형 `F` = `@machdep/m68k/nbic.c`, 바탕 `m0p506-a1-stage`.
   - `refs` = REF. `gate.ok`.
   - 정의·COMMON 기호가 REF 와 같음(python).
   - 입력 사슬 07 = 스테이징 = run 사본(소스와 `bmap.h` 둘 다).
   - 의존 목록에서 `m68k/bmap.h` 가 `src/bsd/m68k/bmap.h` 로 풀림.
   - 기록 `09_validation/reconstruction/m4-m68k-p506-final-20261024.json`, python 확인 `m4-m68k-p506-checks-20261024.json`.
5. 상태표: `ACCEPTED` 에 §506 기록을 더해 다시 만듭니다(앞 기록 재확인, 근거 문서를 먼저 씀; 두 번 돌린 출력 같음).
6. 기록:
   - PROVENANCE 새 행 둘
     - `nbic.c`: 출처 `nextmach+authored`; 고지는 파일 머리의 NeXTMach 저작권 줄; 함수별(`nbic_configure` NeXTMach 14–25 행 바탕 고침, `nbic_bus_enable` 작성 D024)
     - `bmap.h`: `nextmach`, 그대로
   - MODIFICATIONS 새 행 둘, DECISIONS D105, diff `06_reconstruction/evidence/m68k-nbic.diff`(NeXTMach → 07), 근거 문서 `06_reconstruction/evidence/m68k-nbic.md`
   - `07_kernel/README.md`·`v183.34/README.md` 에 m68k 스테이징이 NeXTMach 전용 머리를 들이는 방식 한 줄
   - 상태 절과 결과 절

### 506.1 교차검토(codex `gpt-6.1-sol`) 판정과 계획 수정

제 오류가 둘 있습니다.
- `bmap.h` 는 89 줄입니다(줄바꿈 89 개, 끝에 줄바꿈 있음; python). 90 은 `split('\n')` 의 원소 수였습니다.
- "`stage_headers.py:240–255` 가 `07_kernel/nextmach/<경로>` 를 이름으로 먼저 찾음" 은 과장입니다. 그 조회는 첫 디렉터리가 `NEXTMACH_DIRS`(`stage_headers.py:127–128`; `next` 없음)이거나 `NEXTMACH_RENAME` 에 있는 이름일 때만입니다. 그래서 새 `next/bmap.h` 는 지금의 x86 조회에 걸리지 않습니다. x86gate·`m4_x86_inputs.py` 는 그대로 관문으로 둡니다.

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| REF·소스 경로와 SHA-256 이 맞음; `bmap.h` 89 줄·최상위 객체 정의 하나·1 행 SCCS 줄 | python | ✅ 줄 수는 제 오류 |
| x86 조회 범위는 `NEXTMACH_DIRS`·`NEXTMACH_RENAME` 뿐 | `stage_headers.py:127–128,240–255` 읽음 | ✅ 제 오류 |
| `src/bsd/m68k/bmap.h` 자리는 맞고, `-I` 순서의 다른 후보 자리에 파일 없음 | 이번 세션 python(열한 자리 모두 없음) | ✅ |
| `--plan 506` 미만에서는 머리 선택을 건너뛸 것(키가 없음); 옛 매니페스트에 빈 칸을 더하지 말 것; 덮어쓰기가 같은 자리를 덮지 않음을 확인할 것 | `stage_m68k.py:404,433–436`(`m4_sources` 는 `PLAN >= 497` 일 때만) 읽음 | ✅ 아래 설계 |
| 상태표 도구는 07 소스 해시만 다시 봄(`m4_m68k_status.py:47–48`); 들인 머리의 해시도 다시 볼 것 | 해당 줄 읽음 | ✅ 도구 확장 |
| 고지·출처: NeXTMach 머리 주석 전체를 두고, URL·커밋·줄·해시·스테이징 대응·식별자 출처(`struct bmap_chip`·`bmap_chip`)를 적을 것 | `AGENTS.md:6`, PROVENANCE 821 행 꼴 | ✅ |
| 최종 줄의 `-D`·`-I` 가 M5 와 같고 진단용 `-I` 가 없음을 관문으로; `m4_x86_inputs.py` 에 `L2_FORMS`·`L2_EXPECT` 를 명시 | `m4_m68k_probe.py` cmd 출력 칸, §504 기록 | ✅ |

계획 수정(실행 전 고정):
- `stage_m68k.py`:
  - `M4HEADERS = {506: [('next/bmap.h', 'src/bsd/m68k/bmap.h')]}`.
  - `PLAN >= 506` 일 때만 `M4HEADERS[max(k ≤ PLAN)]` 를 SDK 사본 뒤·`M4FILES` 앞에 넣고, 매니페스트에 `m4_headers` 를 적습니다(그 밖 계획의 매니페스트 꼴은 그대로).
  - 덮어쓰기 트리에 같은 경로가 있으면 멈춥니다.
- `m4_m68k_status.py`: 기록의 명세 `base` 스테이징 매니페스트에 `m4_headers` 가 있으면, 그 항목마다 지금의 07 원본 해시가 매니페스트 해시와 같은지 다시 봅니다. 앞 다섯 기록은 바탕 매니페스트에 이 칸이 없어 결과가 그대로여야 합니다(관문).
- 4 의 관문에 더함: 최종 컴파일 줄의 옵션이 M5 줄과 같음(사전형 `-I` 없음), `m4_x86_inputs.py` 는 `L2_FORMS=06_reconstruction/l2_build_forms-s6p398.tsv L2_EXPECT=06_reconstruction/l2_expect-s6p398.json` 로 돌림.
- PROVENANCE 에 저장소 URL·커밋·줄(`nbic.c` 1–25, `bmap.h` 전체)·채택 해시·스테이징 대응(`next/bmap.h` → `src/bsd/m68k/bmap.h`, `<m68k/bmap.h>`)·식별자 출처를 적습니다.

### 506.2 결과(2026-10-24)

- 1: `07_kernel/src/machdep/m68k/nbic.c`(63 행, SHA-256 `a1400a52ac6919a49fc2ccec443f1f2de8a805d7a4cd4788eaaa902b2cd3440b`), `07_kernel/nextmach/next/bmap.h`(NeXTMach 와 같음, SHA-256 `8aca1917…`). 주석을 뺀 토큰(202 개)이 W7 에서 `next/bmap.h` → `m68k/bmap.h` 만 바꾼 것과 같습니다(python). diff `06_reconstruction/evidence/m68k-nbic.diff`(72 행).
- 2: `stage_m68k.py` 에 `M4FILES[506]`·`M4HEADERS`·`EXCEPTS[506]`·문서 줄을 더했습니다(569 → 589 행; 고치기 전 사본 `08_build/artifacts/m4p505/stage_m68k.py.before506`).
  - `--plan 504` 로 다시 만든 매니페스트가 `m0p504-a1-stage` 와 같습니다.
  - `--plan 506 stage m0p506-a1-stage`(895 파일)와의 차이는 `src/bsd/m68k/bmap.h`·`src/machdep/m68k/nbic.c` 둘이고, 매니페스트 `m4_headers` 는 `['src/bsd/m68k/bmap.h']` 입니다.
- 3: x86 입력 불변. `m4_x86_inputs.py s6ll` ok(`09_validation/reconstruction/m4-x86-inputs-p506-20261024.json`), `--plan 506 x86gate` 일곱 묶음 같음.
- 4: run `m4p506-a1`(기록 `09_validation/reconstruction/m4-m68k-p506-final-20261024.json`). `gate` 모두 참입니다(경고 0, i386 머리 0, `candidate`, REF = §505 W7 객체). python 확인(`m4-m68k-p506-checks-20261024.json`, `ok` 참):
  - 정의·COMMON 기호가 REF 와 같음
  - 입력 사슬(소스·`bmap.h`) 07 = 스테이징 = run 사본
  - 의존 목록의 `bmap.h` 는 `src/src/bsd/m68k/bmap.h` ← `07_kernel/nextmach/next/bmap.h` 하나
  - 옵션이 M5 줄과 같음
- 5: `m4_m68k_status.py` 에 들인 머리의 해시 재확인을 더하고(102 → 109 행), §506 기록을 `ACCEPTED` 에 더했습니다.
  - 상태표: 앞 여섯 객체 행 그대로, `nbic` 추가, 두 번 돌린 출력 같음
  - 받아들인 M4 객체 7 개, §495 행 9/188, 3928 B(1.82%; python)
- 6: PROVENANCE 새 행 둘(1104 → 1106 행, 경로 중복 0), MODIFICATIONS 새 행 둘(650 → 652 행), DECISIONS D105(108 → 109 행), 근거 문서 `06_reconstruction/evidence/m68k-nbic.md`, `07_kernel/README.md`·`v183.34/README.md` 각 한 줄.
- 남은 일(M7 링크): `slot_id`·`machine_type`·`dma_chip` 의 COMMON 정의를 어느 객체가 낼지.

## 507. M4-13 세부 계획 — `next_table` 의 1997 년 꼴 진단(07 변경 없음; 코딩 전, 2026-10-24)

배경: §503 에서 `next_table`(`m68k-303`, 628 B)은 머리 공급 방식과 무관하게 530 B 로, 원본과 다릅니다. 이번 세션에 원본 목록(`image.txt` 0x40951ec–0x4095460)과 §503 A 객체의 실기 목록(`08_build/artifacts/m4p507/otool/next_table_A503.txt`)을 나란히 읽었습니다.

확인한 사실(이번 세션):
- `_machine_table_setokay`(10 B)는 같은 꼴입니다(`moveq #-1,d0`).
- `_machine_table`(원본 618 B):
  - switch 의 case 는 13·14·16·0x4000·0x4002·0x4003 입니다. 비교 나무는 16 을 중심으로 갈라지고, 위쪽은 0x4002 를 중심으로 갈라집니다. 이 case 집합의 switch 낮춤과 맞습니다. NeXTMach 의 case 는 13·14·0x4000 셋입니다.
  - 본문 배치 순서는 13(`TBL_IOINFO`) → 14(`TBL_DISKINFO`) → 0x4000 → 0x4002 → 0x4003 → 16 → default(`clrl d0`)입니다. 13·14 의 본문과 공통 꼬리(`MIN`·copyin/bcopy/copyout·`u.u_error`)는 §503 A 와 같은 명령 열입니다(주소·변위 말고).
  - 0x4000: `lea _cpu_rev; size 1`. 0x4002: `lea _cpu_clk; size 1`. 0x4003: `lea _nbic_present; size 4`. NeXTMach 의 지역 `cpu_rev = scr1->s_cpu_rev` 가 없습니다.
  - 16: `bfextu _cpu_rev{#0,#4}`(위 4 비트 = NeXTMach `next/scr.h` 의 `MACHINE_TYPE(x)` = `x >> 4`)를 3·5·9 와 견주는 switch 낮춤 꼴(중심 5)입니다. 맞으면 32 바이트 지역의 첫 int 에 0, 아니면 1 을 넣고, `data` = 그 지역, `size` = 0x20 입니다.
  - 프레임은 `linkw #-0x54`(84 B) = `ti` 20 + `td` 28 + 32 바이트 지역 + `buff` 4 입니다(python). 32 바이트 지역은 `td` 바로 아래(0xffb0)이고, NeXTMach 의 `u_char cpu_rev` 자리입니다. §503 A 는 `linkw #-0x38` 입니다.
- 이름(원본 기호표): 0x40c96ce `_cpu_rev`, 0x40c96cc `_cpu_clk`, 0x40c3a1c `_nbic_present`. 모두 `__common` 입니다.
- SDK `bsd/m68k/table.h`(스테이징 `src/bsd/m68k/table.h`, `sys/table.h` → `machine/table.h` → ARCH_INCLUDE 로 들어옴)에 `TBL_NeXT_CPU_REV`(+0)·`TBL_FP_INFO`(+1)·`TBL_NeXT_CPU_REV2`(+2)·`TBL_NeXT_HAS_NeXTbus`(+3)가 있습니다.
- SDK `bsd/m68k/cpu.h:49–50` 에 `extern u_char cpu_rev; extern u_char cpu_clk;` 가 있습니다.
- id 16 의 이름과 32 바이트 구조체는 어느 참고 머리에도 없습니다(NeXTMach·Darwin `sys/table.h` 는 15 이하; 구조체 가운데 32 B 인 것 없음). x86 07 의 `machine_table` 은 `return (0)` 뿐입니다(`machdep/i386/machdep.c:290`).
- `nbic_present` 를 선언하는 머리는 없습니다.

방법(`m4_m68k_probe.py`, 명세 `08_build/artifacts/m4p507/spec.json`, run `m4p507-p1`, 바탕 `m0p506-a1-stage`, 줄 틀은 `machdep/i386/dkbad.c` 의 x86 줄):
- 대조 A: §503 A 사본 그대로(§503 A 객체와 canon·obj_sig 같아야 함). `next/scr.h` 사본이 필요해 `inc` 에 둡니다.
- T1(D104·D105 꼴): A 에서 다음만 바꿉니다.
  - `#import <next/scr.h>` 를 뺍니다(원본에 없는 `scr1` 임시 정의를 피함; `MACHINE_TYPE` 대신 `cpu_rev >> 4`).
  - include 뒤에 `extern int nbic_present;` 를 둡니다.
  - 지역 `u_char cpu_rev;` 를 `int info[8];` 로 바꿉니다(이름은 작성).
  - case `TBL_NeXT_CPU_REV` 는 `data = (caddr_t)&cpu_rev; size = sizeof (cpu_rev);` 입니다.
  - 그 뒤(`#ifdef DEBUG` 덩이 다음)에 `TBL_NeXT_CPU_REV2`(`&cpu_clk`)·`TBL_NeXT_HAS_NeXTbus`(`&nbic_present`) 두 case 와 `case 16:`(`switch (cpu_rev >> 4) { case 3: case 5: case 9: info[0] = 0; break; default: info[0] = 1; }`, `data = (caddr_t)info; size = sizeof (info);`)을 둡니다.
  - 나머지는 A 와 같습니다.
- 비교: `compare`(L1, `full_span`), 정의·COMMON 기호와 원본 기호표 대조, 맞지 않으면 실기 `otool` 과 `funcs`.
- 기록 `09_validation/reconstruction/m4-m68k-probe-p507-20261024.json`.

판정(미리 정함; 07 은 바꾸지 않음):
- T1 이 `candidate` 이고 원본에 없는 정의 기호가 없으면, 바이트로 정해지지 않는 것(id 16·32 바이트 지역의 이름과 꼴, `nbic_present` 선언 자리)을 여쭙고 구현 계획을 씁니다.
- 아니면 차이를 적고 다음 꼴을 따로 계획합니다.

관문(어긋나면 멈춤): 명령 종료 0·경고 0·i386 머리 0, 옵션이 M5 줄과 같음(사전형 `-I` 만 더해짐), 대조 A 가 §503 A 와 같음.

### 507.1 교차검토(codex `gpt-6.1-sol`) 판정과 계획 수정

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 원본 해석(case 집합·본문 순서·0x4000/0x4002/0x4003/16 본문·프레임)에 잘못 읽은 명령 없음 | 이번 세션 두 목록 직접 읽음 | ✅ |
| IOINFO 34·DISKINFO 53·꼬리 38·setokay 5 명령이 숫자를 가리면 A503 과 같음 | 이번 세션 python(34/53/38 같음) | ✅ |
| 저장 레지스터 영역 시작 0xff8c 가 원본 꼬리와 맞음 | 원본 목록 0x409544c `moveml a6@(0xff8c:w)` | ✅ |
| "`u_char cpu_rev` 자리" 는 선언 위치를 뜻해야 함(A503 은 그 바이트를 0xffcf 에 둠); 선언 순서가 자리를 보장하지 않음; 바이트가 정한 것은 "크기 0x20 인 돌려주는 지역" 이지 `int[8]` 이 아님 | 설계 | ✅ 표현을 낮춤; 객체에서 자리 확인 |
| `cpu_rev >> 4` 가 `bfextu` 가 될지는 미확인; 대체 꼴 `(cpu_rev & 0xf0) >> 4`, 비트필드 덮개 | 설계 | ✅ T2 를 같은 run 에 더함(덮개는 둘 다 실패할 때) |
| `DEBUG` 가 꺼져 있음을 확인할 것(`TBL_FP_INFO` 조건 덩이) | 스테이징 `generated/meta_features.h`·`src/bsd/sys`·`src/bsd/m68k` grep 0, 컴파일 줄 `-DDEBUG` 0 | ✅ |
| `refs` 는 모든 변형에 걸리므로 A 대조는 따로 python 으로 | `m4_m68k_probe.py` `refs` 처리(§505 에서 읽음) | ✅ `refs` 없이 돌리고 A↔§503 A 를 python 으로 |
| T1 판정은 OBJECT_MATCH + `full_span`, 정의·COMMON 이름과 크기, 예상 미정의까지; `funcs` 는 진단일 뿐 | 설계 | ✅ |
| `info[0]` 만 초기화됨(나머지 28 바이트는 정해지지 않은 스택 값) | 원본 목록(0xffb0 에 한 번만 씀) | ✅ 기록에 적음 |

계획 수정: 변형 = A(대조) + T1 + T2(T1 에서 `cpu_rev >> 4` 를 `(cpu_rev & 0xf0) >> 4` 로). `refs` 는 두지 않고, A 가 §503 A 객체(`08_build/runs/m4p503-p1/stage/Q503__next_table_A.o`)와 canon·obj_sig 가 같은지를 python 관문으로 봅니다. T1·T2 는 원본 기호표에 없는 정의·COMMON 이 없어야 합니다.

### 507.2 결과(2026-10-24)

- run `m4p507-p1`(명세 `08_build/artifacts/m4p507/spec.json`, 스테이징 `m4p507-stage` 899 파일 = 바탕 895 + 4; 기록 `09_validation/reconstruction/m4-m68k-probe-p507-20261024.json`). 관문을 모두 통과했습니다.
  - 6 명령 종료 0·경고 0, i386 머리 0, 옵션이 M5 줄과 같음
  - 대조 A 는 §503 A 객체와 canon·obj_sig 같음(python)
- **T1·T2 는 `candidate` 입니다.** L1 OBJECT_MATCH, 사유 없음, `full_span`(628 B, 0x40951ec 배치, 원본 이름 둘)이고, 원본에 없는 미정의는 없습니다. T1 과 T2 는 같은 객체입니다(`cpu_rev >> 4` 와 `(cpu_rev & 0xf0) >> 4` 는 바이트로 구별되지 않음).
- 정의·COMMON 기호는 모두 원본 기호표에 있습니다. A 는 `next/scr.h` 때문에 원본에 없는 `_scr1` 을 냅니다.
  - COMMON 11 개는 원본 `__common` 의 다음 기호까지 거리와 크기가 같습니다(python).
  - 5 개(`_bufpages`·`_nbuf`·`_tthiwat`·`_tthog`·`_ttlowat`)는 원본에서 절 4(`__DATA,__data`)에 있습니다. 머리의 임시 정의가 다른 객체의 초기화된 정의와 링크 때 합쳐지는 것이고, NeXTMach 원문 그대로인 A 도 같은 COMMON 을 냅니다.
- 32 바이트 지역은 첫 int(`info[0]`)만 씁니다. 나머지 28 바이트는 정해지지 않은 스택 값 그대로 돌려줍니다(원본도 같음).
- 바이트로 정해지지 않는 것(사용자 결정):
  - id 16 과 32 바이트 지역의 이름·꼴(이름 있는 머리 없음)
  - 기계 형 추출의 꼴(T1·T2)
  - `nbic_present` 선언 자리(머리 없음)

사용자 결정 D106(2026-10-24): m68k `next_table` 은 T1 꼴입니다("T1 (Recommended)"). 내용은 다음과 같습니다.
- `case 16:` 은 숫자로, 기계 형은 `cpu_rev >> 4` 로 씁니다. `next/scr.h` 를 들이지 않습니다.
- 32 바이트 지역은 `int info[8]` 입니다(이름은 작성).
- `extern int nbic_present;` 를 파일에 선언합니다.
- 0x4000–0x4003 은 SDK `m68k/table.h` 이름을 씁니다.
- 근거: §507.2(T1·T2 같은 객체, 이름 있는 머리 없음, D105 와 같은 방식).

## 508. M4-14 D106 구현 계획 — 07 `src/machdep/m68k/next_table.c`(코딩 전, 2026-10-24)

확인한 사실(이번 세션):
- REF = §507 T1 객체 `08_build/runs/m4p507-p1/stage/Q507__next_table_T1.o`(SHA-256 `bcd1bca45b86cba81d38766b6c2106769cfdd0f32474fbf8d1a0bb99a72929a7`), 소스 `08_build/artifacts/m4p507/src/next_table_T1.c`(SHA-256 `948f5f6dbe0ee424ef71b771e7aa77c9ecac403874ed2490d4f2918af7af1753`).
- T1 은 NeXTMach `next/next_table.c`(153 줄)에서 다음을 바꾼 글입니다(§507 diff).
  - include 두 줄(D104): `<next/cpu.h>` → `<m68k/cpu.h>`, `<nextdev/busvar.h>` → `<dev/busvar.h>`
  - `<next/scr.h>` 를 뺌
  - `extern int nbic_present;`
  - 지역 `int info[8]`
  - `TBL_NeXT_CPU_REV` 본문, 새 case 셋
- NeXTMach 파일 머리에 `Copyright (c) 1989 NeXT, Inc.` 고지 덩이(1–9 행)가 있습니다.
- 새 머리는 필요 없습니다. `dev/busvar.h` 는 D039 사본이고, `m68k/cpu.h`·`m68k/table.h` 는 SDK 입니다.

방법(§506 과 같은 순서):
1. 07 파일 `07_kernel/src/machdep/m68k/next_table.c` = T1 글에 다음을 더한 것(주석만).
   - 고지 덩이 뒤에 설명 주석 한 덩이를 둡니다.
   - 바뀐 줄 끝에 `/* plan 508 (D104) */`·`/* plan 508 (D106) */` 를 답니다(문자열 밖).
   - 주석을 뺀 토큰이 T1 과 같은지 python 으로 확인합니다.
2. `stage_m68k.py`: `M4FILES[508]` = 506 목록 + `next_table.c`, `EXCEPTS[508] = dict(EXCEPTS[506])`, 문서 줄. `M4HEADERS` 는 506 항목을 그대로 씁니다(최대 키 ≤ 계획).
   - 회귀: `--plan 506` 으로 다시 만든 매니페스트가 `m0p506-a1-stage` 와 같음
   - `--plan 508 stage m0p508-a1-stage` 와의 차이는 `src/machdep/m68k/next_table.c` 하나
3. x86 입력 불변: `L2_FORMS=06_reconstruction/l2_build_forms-s6p398.tsv L2_EXPECT=06_reconstruction/l2_expect-s6p398.json m4_x86_inputs.py s6ll`, `--plan 508 x86gate`.
4. 최종 run `m4p508-a1`(명세 `08_build/artifacts/m4p508/spec.json`, 변형 `F` = `@machdep/m68k/next_table.c`, `m4_id` `m68k-303`, `refs` = REF).
   - `gate.ok`
   - python 확인(`m4-m68k-p508-checks-20261024.json`): 정의·COMMON 기호가 REF 와 같음, 입력 사슬 07 = 스테이징 = run 사본, 옵션이 M5 줄과 같음
   - 기록 `09_validation/reconstruction/m4-m68k-p508-final-20261024.json`
5. 상태표: 근거 문서를 먼저 쓰고 `ACCEPTED` 에 더해 다시 만듭니다(앞 일곱 행 그대로, 두 번 돌린 출력 같음).
6. 기록: PROVENANCE 새 행(`nextmach+authored`, 고지, URL·커밋·줄·바뀐 것), MODIFICATIONS 새 행, DECISIONS D106, diff `06_reconstruction/evidence/m68k-next_table.diff`, 근거 문서 `m68k-next_table.md`, 상태 절과 결과 절.

### 508.1 교차검토(codex `gpt-6.1-sol`) 판정과 계획 수정

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| REF 해시·T1 의 바뀜·고지 1–9 행·새 머리 불필요가 맞음; `TBL_FP_INFO` 는 `DEBUG` 아래로 남음 | 이번 세션 python 해시·diff, NeXTMach 원문, §507.1 의 `DEBUG` 확인 | ✅ |
| 508 은 `M4HEADERS[506]` 을 이어 쓰고 `M4FILES[508]` 은 `nbic.c` 를 유지; 506 재스테이징은 그대로; 새 대상 디렉터리를 쓸 것 | `stage_m68k.py` 의 선택 규칙(§506 에서 씀), `cmd_stage` 의 존재 검사 | ✅ |
| "정의·COMMON 이 REF 와 같음" 은 이름·종류·COMMON 크기까지; T1 COMMON 16 개 = 원본 `__common` 11 + `__data` 5(`_bufpages`·`_nbuf` 4, `_tthiwat`·`_tthog`·`_ttlowat` 64); `__data` 쪽 합침은 M7 링크 의무로 적음 | §507.2 python(11 개 간격 같음, 5 개 절 4) | ✅ |
| 식별자 출처(SDK `m68k/table.h` 의 `TBL_NeXT_*`, 작성 `info`, 숫자 16)와 함수별 출처를 PROVENANCE 에 적을 것; 명세에 바탕·M5 줄·`x86_rel` 을 고정할 것 | PROVENANCE 1105 행 꼴(§506) | ✅ |
| 표시 주석은 문자열 밖·완결 줄 뒤; 문자열을 보존하는 토큰 비교 | §506 의 토큰 함수(문자열·문자 상수 보존, 주석 → 공백) | ✅ |

### 508.2 결과(2026-10-24)

- 1: `07_kernel/src/machdep/m68k/next_table.c`(186 행, SHA-256 `926e1db839efc6245fc7688547f676fe986897f8724bf0c75ef367c883e490ed`). 주석을 뺀 토큰(731 개)이 T1 과 같습니다(python; 문자열·문자 상수를 보존하고 주석을 공백으로 바꿈). diff `06_reconstruction/evidence/m68k-next_table.diff`(82 행).
- 2: `stage_m68k.py` 에 `M4FILES[508]`·`EXCEPTS[508]`·문서 줄을 더했습니다(589 → 591 행; 고치기 전 사본 `08_build/artifacts/m4p508/stage_m68k.py.before508`).
  - `--plan 506` 으로 다시 만든 매니페스트가 `m0p506-a1-stage` 와 같습니다.
  - `--plan 508 stage m0p508-a1-stage`(896 파일)와의 차이는 `src/machdep/m68k/next_table.c` 하나이고, `m4_headers` 는 그대로 `['src/bsd/m68k/bmap.h']` 입니다.
- 3: x86 입력 불변. `m4_x86_inputs.py s6ll` ok(`09_validation/reconstruction/m4-x86-inputs-p508-20261024.json`), `--plan 508 x86gate` 일곱 묶음 같음.
- 4: run `m4p508-a1`(기록 `09_validation/reconstruction/m4-m68k-p508-final-20261024.json`). `gate` 모두 참입니다(경고 0, i386 머리 0, `candidate`, REF = §507 T1 객체). python 확인(`m4-m68k-p508-checks-20261024.json`, `ok` 참):
  - 정의·COMMON 기호가 REF 와 같음(이름·종류·크기)
  - COMMON 16 개 = 원본 `__common` 11 + 원본 `__data` 5(M7 링크 의무)
  - 입력 사슬 07 = 스테이징 = run 사본
  - 옵션이 M5 줄과 같음
- 5: 상태표에 §508 기록을 더했습니다(`m4_m68k_status.py` 109 → 110 행). 앞 일곱 객체 행 그대로, `next_table` 추가, 두 번 돌린 출력 같음. 받아들인 M4 객체 8 개, §495 행 10/188, 4556 B(2.11%; python).
- 6: PROVENANCE 새 행(1106 → 1107 행, 경로 중복 0), MODIFICATIONS 새 행(652 → 653 행), DECISIONS D106(109 → 110 행), 근거 문서 `06_reconstruction/evidence/m68k-next_table.md`.
