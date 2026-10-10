# v183.34 덮어쓰기 트리 (D064·D068)

1997 년 m68k·SPARC 커널(판 183.34)을 다시 만들 때, x86 트리(`07_kernel/src`·`generated` 등)와 다른 파일만 이곳에 둡니다.

- `m68k/`·`sparc/`: 아키텍처별 차이. 07 과 같은 경로(`generated/…`, `src/machdep/m68k/…` 등)를 씁니다.
- `common/`: 두 아키텍처에 공통인 183.34 차이(지금은 없음).
- m68k 빌드는 m68k → common → 07 본 트리 순으로 파일을 고릅니다. 스테이징 도구는 `10_tools/reconstruction/stage_m68k.py` 입니다(바탕 스테이징 위에 common, m68k 를 차례로 덮어씀).
- x86 빌드(`stage_headers.py`, s6l4 계열)는 이 디렉터리를 읽지 않습니다.

## 생성 구성(계획 434)

`m68k/generated/` 의 머리는 `06_reconstruction/config_options-m68k.tsv` 에서 `python3 10_tools/reconstruction/gen_config_headers.py --arch m68k` 로 만듭니다(확인은 `--check`; 손으로 고치지 않음). 이 표에는 x86 표(`06_reconstruction/config_options.tsv`)와 다르거나 x86 표에 없는 값만 있고, m68k 의 실효 구성은 x86 표에 이 표를 덮어쓴 것입니다. `meta_features.h` 는 x86 것을 그대로 씁니다(`iplmeas.h` 는 SDK `bsd/m68k/spl.h`·`kernserv/m68k/spl.h` 가 직접 가져옴).

| 파일 | 값 | 상태 | 근거 |
|---|---|---|---|
| `generated/driverkit.h` | `DRIVERKIT 0` | confirmed | 계획 425 |
| `generated/iplmeas.h` | `NIPLMEAS 0` | hypothesis | 계획 426, 434 |
| `generated/gdb.h` | `GDB 1` | confirmed | 계획 427 |
| `generated/simple_clock.h` | `SIMPLE_CLOCK 1` | confirmed | 계획 432 |
| `generated/kernobjc.h` | `KERNOBJC 0` | confirmed | 계획 438 |

MIG 출력은 07 본 트리 것을 그대로 씁니다(근거: 계획 434 의 `-arch m68k` 재생성 대조).

## 인라인 spl(계획 426·433·435, D069·D070)

m68k 원본에는 `_spl*` 함수가 없습니다(spl 은 모두 인라인). 인라인 spl 은 SDK 사본을 고치지 않고 `machdep/m68k/machspl.h`(D069)와, BSD 머리만 거치는 두 소스 `src/bsd/rpc/subr_kudp.c`·`src/bsd/net/if_venip.c` 의 m68k 판(07 본 파일 + `#import <machine/spl.h>` 한 줄, D070)에서 가져옵니다. 두 `.c` 는 `stage_m68k.py` 가 스테이징 때 "07 본 파일 + 표시 줄 하나" 인지 검사합니다.

## m68k 전용 소스 줄(계획 437)

`src/bsd/kern/subr_prf.c` 의 m68k 판은 07 본 파일에 `plan 437 (m68k)` 표시 줄 5 개(NeXTMach 의 ROM Monitor `printf` 와 그 선언)를 끼운 것입니다. `src/mon/global.h` 는 그 줄이 쓰는 `struct mon_global` 의 부분 정의(작성, 원본 변위)이며, M4 에서 NeXTMach 전체 머리로 바꿀 후보입니다. 덮어쓰기 `.c` 는 모두 `stage_m68k.py` 의 파생 검사(등록된 표시·파일·줄 수)를 통과해야 합니다.

## `need_ast` 정의(계획 441, D071)

m68k 는 `MACHINE_AST` 이므로 07 본 `kern/ast.c` 의 정의(`#ifndef MACHINE_AST`)가 빠집니다. 원본에는 `_need_ast` 가 `__common` 에 있으므로, m68k 판 `src/kern/ast.c` 에 Mach4 `kern/ast.c:58` 의 정의 줄을 고지와 함께 묶음(`plan 441 (m68k)`)으로 끼웠습니다.

출처·고지: 파일마다 `07_kernel/PROVENANCE.tsv`·`07_kernel/MODIFICATIONS.md`.
