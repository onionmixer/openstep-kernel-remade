# 커널 소스 복원 작업계획 — 보관 §730–739

`02_plan/RECONSTRUCTION_PLAN.md` 의 §730–739(m68k M4 `ev_mouse.c`(D165), `nextdbg.c`(D166))를 절 번호·내용 그대로 옮긴 보관본입니다(2026-11-09, D026 방식, 사용자 지시 “RECONSTRUCTION_PLAN.md 문서에서 진행이 완료된 내용은 기존의 규칙처럼 정리해주세요.”). 본문은 `---` 아래부터입니다.

---

## 730. M4-197 세부 계획 — m68k `ev_mouse` 단위의 `evsetup_screens` 2 B: 컴파일러 중간 표현으로 `lea` 와 `addal` 가르기 (07 변경 없음; 코딩 전, 2026-11-03)

고른 까닭(python 으로 센 값): 수락한 M4 객체가 66 개이고 행 수는 88/188(128652 B, 59.60%) 입니다. 남은 행의 최소 바이트 87222 B 가운데 FPSP 23306 B(참고 글 없음, 사용자 결정 대기), `zs.c`·`video.c` 구역(1997 판이 NeXTMach 와 크게 다름: 원본 함수 표의 [0x4089ce8, 0x408d686) 가 64 항목인데 NeXTMach `zs.c` 는 32 함수), `nextdbg.c`(1997 이름 대부분이 참고 글에 없음), `snd_link`(1997 판이 크게 다름, 미룸), `locore.s`(1985 행 어셈블리, 조건부 많음), `tty_pty` 꼬리(344 B; 원본 디스어셈블리로 본 추정으로 정적 `pt_soft` 배열(14 B 칸)을 다른 번역 단위가 참조해야 해서 계정 처리 결정이 먼저 필요)입니다. 이벤트 코드(행 216–218 [0x4069eb8, 0x406aa70), `MoveTheCursor`·`ev_mouse`·`evdispatch` 등)는 다른 세션의 §690–722 가 12/13 함수까지 진단했고 마지막 막힘이 `evsetup_screens` 의 2 B 입니다(§718 통합 12/13, §719 로 비재배치 104 B 는 같음을 확인). 방금 §728 에서 레지스터 선택 차이를 컴파일러 중간 표현으로 풀었으므로 같은 방법을 이 2 B 에 씁니다.

사실(열어 확인함):
- 원본 `evsetup_screens`(0x406a40a, 148 B)는 0x406a478 에서 4 B `lea a0@(0x0:b,d0:l:1),a0`(`41f00800`)를 쓰고, 진단 D·G·H(146 B)는 2 B `addal d0,a0` 를 씁니다(`m4-m68k-p716-checks-20261102.json`, 계획 §716.2·§719.2).
- 공개 GCC 2.7.2.3 `config/m68k/m68k.md:2148–2210` 의 `addsi3`: 대안 `"=m,?a,?a,r"` / `"%0,a,rJK,0"` / `"dIKLs,rJK,a,mrIKLs"`; `operands_match_p(0,1)` 이 아니면 `lea %1@(0,%2:l),%0`, 맞으면 `addl`/`addw`. 즉 `lea` 는 `operands[0]` 과 `operands[1]` 이 다를 때 나옵니다(대안 번호가 아니라 최종 피연산자로 정해짐, §730.1). 어느 대안이 골라지는지는 연산 순서·피연산자 레지스터·`reload.c find_reloads` 의 비용 비교로 정해집니다(아직 읽지 않음; 공개 `reload.c` 를 가져와 읽을 예정).
- 원본은 `screenIndex` 를 주소 레지스터 a3 에 두고(`lea a3@(0,a3:l:4),a3` 로 ×5, `movel a3,d0; asll #3,d0` 로 ×40) 그 d0 를 두 저장(`a0@(0xc,d0:l)`, `a0@(0x10,d0:l)`)과 `lea` 에 다시 씁니다.

방법(07 변경 없음; scratch 와 `08_build/artifacts/m4p730`):
1. 진단 D(`08_build/artifacts/m4p694/evsetup_D.c`)를 §728 의 `RUNIN` 방식(`-dr -dj -ds -dc -dl -dg -dJ -df`)으로 컴파일하는 실기 run `m4p730-d1`. 덤프 옵션을 붙인 객체가 기존 D 객체를 재현하는지(`canon`·`obj_sig`)부터 봅니다.
2. python 으로 `.rtl`→`.combine`→`.lreg`→`.greg` 에서 `evScreen[screenIndex]` 주소 계산 insn 을 찾아 연산 순서(`plus` 피연산자), 의사 레지스터 번호와 `.greg` 의 `Reloads for insn` 를 읽습니다. 어느 패스에서 `addal` 꼴이 정해지는지 가립니다.
3. 공개 `reload.c`(`find_reloads` 의 대안 비용·교환)와 `m68k.md` 를 읽어 `lea`(둘째·셋째 대안)가 골라지는 조건을 찾고, 그 조건을 낳을 소스 차이를 가설로 세웁니다. 원본에 없는 기능은 더하지 않습니다.
4. 가설마다 변형을 새 run(`m4p730-p1`…)으로 시험합니다. 판정(미리 정함): `evsetup_screens` 가 148 B 이고 바이트와 재배치 대상까지 같으면 해결입니다(참조 10 곳은 §716.1 의 원본 목표).
5. 풀리지 않으면 멈추고 보고합니다. 기준을 늦추지 않습니다. 해결되어도 이 단계는 07·상태표를 바꾸지 않습니다(`ev_mouse` 단위의 자료 소유 문제 등 §693·§717–722 의 열린 질문은 남음).

### 730.1 §730 codex 교차검토(`gpt-6.1-sol`) 판정과 계획 수정 (코딩 전, 2026-11-03)

먼저 제 잘못: 계획에 "`lea` 는 reload 가 `?a` 대안(벌점 6)을 골랐을 때"라고 썼습니다. `reload.c` 는 `?` 를 `reject += 3`, `!` 를 `reject = 300` 으로 세고(2725–2731 행), reload 없이 맞는 첫 대안을 바로 고릅니다(3220–3230 행). 위 문장을 고쳤습니다. 또 이 절의 "reload.c 를 가져와 읽을 예정"은 이미 `scratch/p725/gccsrc/reload.c` 에 있습니다(제가 가져옴).

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 원본 `lea a0@(0,d0:l:1),a0` 는 0x406a478, 함수 148 B | `image.txt` 134595–134604 행을 열음(0406a478), 함수 시작 0406a40a | ✅ |
| `addsi3` 대안 문자열과 출력 규칙; 대안 번호가 아니라 `operands_match_p(0,1)` 가 출력 결정 | `m68k.md` 2148–2210 을 앞서 열음 | ✅ |
| 수치(66, 88/188, 87222, FPSP 23306, `locore.s` 1985) | 제가 앞서 python 으로 같은 값 | ✅ |
| `m68k.md:6115` 의 후순위 `lea %a1,%0` 패턴(`address_operand`, `:QI`), 단순 `plus` 는 `addsi3` 에 먼저 잡힘 | 6112–6120, 6150–6156 행을 열음 | ✅ |
| `reload.c`: `?` +3, `!` =300, 무reload 첫 대안 즉시 선택, `%` 교환은 비교환 대안을 다 본 뒤 | 2720–2735, 3205–3232, 3262–3290 행을 열음 | ✅ |
| 귀결: `a0 ← d0+a0` 이면 셋째 대안이 맞아 `lea`, `a0 ← a0+d0` 이면 둘째 대안이 맞아 `addl` | 위 코드와 `addsi3` 출력 규칙에서 따짐(`reload.c:3220` 가 즉시 선택) | ✅ 추론이고 실제 RTL 순서는 덤프로 확인 |
| `.greg` 에 `Reloads for insn` 문구를 전제하면 안 됨(`reload1.c:1421` 형식은 `Need N reg…`) | 1419–1432 행을 열음 | ✅ (§728 에서도 그렇게 읽음) |
| "104 B" 는 객체 크기가 아니라 제외 영역을 뺀 대응 바이트 수 | §719.2 문구와 일치 | ✅ |
| 단독 함수에서 풀어도 통합 TU 에서 다시 확인 | 동의 | ✅ 계획에 추가 |

귀결로 가설이 좁아졌습니다: 원본은 `plus` 의 피연산자 순서가 `(plus 오프셋 evScreen)`(첫째가 d0, 둘째가 a0)이고 진단은 `(plus a0 d0)` 입니다. 덤프에서 순서가 정해지는 패스(`expand`/`cse`/`combine`)를 찾고, 순서를 바꿀 소스 차이를 가설로 세웁니다. 공개 GCC 2.7.2.3 은 NeXT cc 의 확정 구현이 아니라 후보입니다(변형 판정은 항상 원본 바이트와의 비교로). 해결 뒤 통합 TU(§718 의 A)에서 다시 확인합니다.

### 730.2 덤프 결과와 변형 계획 (코딩 전; 2026-11-03)

덤프 run `m4p730-d1`(D·G, `RUNIN` 덤프): 성공. (D 객체 재현은 다음 단계에서 `canon`·`obj_sig` 로 확인; 기존 D 객체 파일 `m4p694-p1` 은 디스크에 없어 `m4p716-p1` 의 D 와 견줌.)

관찰(`.rtl`·`.cse`·`.combine`·`.greg` 의 `evsetup_screens`, python):
- 첫 저장(`evScreen[screenIndex].bounds = …`, insn 62)의 주소는 `(plus (plus (reg 44) (reg 40)) 12)`: 오프셋 44 가 앞, 기저(evScreen 값, 40)가 뒤입니다. 둘째 계산 `screen = &evScreen[screenIndex]`(insn 71)는 `.rtl` 에서 `(plus (reg 49) (reg 48))`(기저 49 = evScreen 다시 읽음이 앞, 오프셋 48 이 뒤)이고, cse 뒤 `(plus (reg 40) (reg 44))`, 할당 뒤 `(plus (reg a0) (reg d0))` 입니다 — 목적지 a0 가 첫 입력과 같아 `addl`(2 B)로 나옵니다. 원본의 `lea a0@(0,d0:l),a0` 는 `(plus (reg d0) (reg a0))` 즉 오프셋이 첫째일 때 나옵니다(§730.1: 무reload 첫 대안 선택, `addsi3` 출력 규칙).
- 소스 쪽 근거(공개 GCC 2.7.2.3, 모두 열음): `c-typeck.c:2992–2998` 가 `&*x` 를 `x` 로 줄이므로 `&evScreen[i]` 는 값 문맥의 `PLUS_EXPR(evScreen, i*40)` 입니다. `expr.c` 의 `PLUS_EXPR` 는 `modifier` 가 `EXPAND_SUM`·`EXPAND_INITIALIZER` 가 아니거나 `mode != ptr_mode` 이면 `binop`(피연산자 순서 그대로)로 가고(`expr.c:5237–5239`), `EXPAND_SUM` 일 때는 `MULT_EXPR` 가 `(mult reg const)` 를 돌려주며(`expr.c:5347` 이후) `PLUS` 가 "곱셈을 앞에"(`both_summands` 끝의 `GET_CODE (op1) == MULT` 교환)로 배열합니다. 그래서 주소 식이 `EXPAND_SUM` 으로 펼쳐지는 문맥(`INDIRECT_REF` 의 주소 `expr.c:4555`)에서는 오프셋이 첫째가 됩니다.
- 가설 H7: 원본은 `screen` 지역 변수 없이 `evScreen[screenIndex]` 를 세 번 직접 쓴다(`.bounds` 저장, `.shmemSize` 저장, `totalShmemSize += …shmemSize`). 두 번 쓰이는 주소 `(오프셋 + 기저)` 가 `lea` 로 한 번 계산될 것으로 예상한다(근거 코드는 아직 못 찾음, §730.3). 오프셋이 첫째이다.

변형 묶음(진단; 07 변경 없음; 기반은 `evsetup_D.c`의 머리·`if (!evScreen)` 블록·마지막 줄 그대로):
- S1: `screen` 변수 없이 `evScreen[screenIndex].shmemSize = arg->screenShmemSize; totalShmemSize += evScreen[screenIndex].shmemSize;`
- S2: S1 이고 `register int screenIndex` 를 `int screenIndex` 로.
- S3: `screen` 변수를 두되 `&evScreen[screenIndex]` 대신 `(EvScreen *)((volatile char *)evScreen + screenIndex * sizeof (EvScreen))` 가 아니라 첫 저장을 `screen->bounds` 로 바꾸는 순서 변형은 원본 순서(저장 뒤 `lea`)와 달라 제외 — 따라서 S3 은 두지 않음.
판정(미리 정함): `evsetup_screens` 148 B 이고 바이트와 재배치 대상까지 같으면 해결입니다. 아니면 덤프(`.rtl`)로 피연산자 순서·cse 결과를 다시 읽어 새 가설을 세웁니다. 코딩 전 codex 로 가설 H7 의 소스 고리만 좁게 검토합니다.

### 730.3 §730.2 codex 교차검토(`gpt-6.1-sol`) 판정 (코딩 전, 2026-11-03)

먼저 제 잘못: §730.2 가 "`EXPAND_SUM` 이 아니면 binop" 이라고 일반화했고, H7 의 "공통 계산되어 `lea` 가 된다"를 근거 코드 없이 단정에 가깝게 썼습니다. 둘 다 위에서 고쳤습니다(H7 은 예상으로 낮춤).

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| RTL: insn 56/60/61/62/68/70/71, `.cse`·`.greg` 의 `(plus …)` 순서 | 앞서 python 으로 `.rtl`·`.cse`·`.greg` 를 읽은 값과 같음(오프셋 44 가 앞인 저장 주소, 기저 49 가 앞인 insn 71, 할당 뒤 `(plus a0 d0)`) | ✅ |
| `&*` 상쇄(`c-typeck.c:2992`), 포인터 첨자는 `INDIRECT_REF(PLUS_EXPR)`(`1490`), 포인터 덧셈은 기저가 앞 | 1488–1492, 2985–3000 행을 열음 | ✅ |
| `PLUS_EXPR` 가 합 RTL 경로에 남는 조건과 binop 조건(`expr.c:5195`, `5237`) | 5192–5198, 5235–5240 을 열음 | ✅ (위 잘못 1) |
| 곱셈을 앞으로 바꾸는 교환(`5288–5293`), `EXPAND_SUM` 곱의 `(mult reg const)`(`5362–5383`) | 5286–5294 와 5347–5390 을 열음 | ✅ |
| `INDIRECT_REF` 주소는 `EXPAND_SUM`(`4555`), `ADDR_EXPR` 는 `EXPAND_CONST_ADDRESS`(`6280`) | 4540–4590, 6260–6330 을 열음 | ✅ (`COMPONENT_REF` 4790 은 열지 않음 → 계획에는 "COMPONENT_REF 의 안쪽 객체" 문장을 남겼으므로 아래 ⚠️) |
| m68k `LEGITIMIZE_ADDRESS` 는 `(plus (mult …) base)` 에서 곱셈만 `force_operand`, 합 전체를 공통 레지스터로 뽑지 않음(`m68k.h:1260`) | 1255–1285 행을 열음 | ✅ |
| `find_best_addr` 는 이미 있는 동치식으로만 바꾸고 새 `SET` 을 만들지 않음(`cse.c:2667`) | 2664–2672 만 열음(함수 전체는 읽지 않음) | ⚠️ 부분 확인 |
| `combine` 은 H7 의 반복 주소 추출을 뒷받침하지 않음; `explow.c` 가 없어 `memory_address` 본체는 미검증 | 저는 `combine.c:45·2447` 을 열지 않았음, `explow.c` 부재는 `ls` 로 보면 맞음(받지 않은 파일) | ⚠️ / ✅ |
| S1 이 indexed addressing 만 쓸 가능성 | 동의(실험으로 확인) | ✅ |
| `EvScreen` 은 `volatile struct` typedef(`evio.h:109`); 포인터 변수 volatile 은 비현실적 | 107–111 행을 열음 | ✅ |
| signed/unsigned 형을 조사할 근거는 있으나 순서를 뒤집는 근거는 아직 없음 | 동의 | ⏭️ 보류 |

⚠️ 행(`COMPONENT_REF` 4790, `cse.c` 함수 전체, `combine.c`)은 열지 않아 계획에서 근거로 쓰지 않습니다. `COMPONENT_REF` 문장은 근거 줄 번호를 지웁니다. 실험은 계획대로 S1·S2 를 돌립니다(H7 이 틀려도 비용이 작음).

### 730.4 S1·S2 결과와 가설 H8, 다음 묶음 (run `m4p730-p1`, 2026-11-03; 07 변경 없음)

결과: S1·S2 모두 `__text` 146 B 로 원본 148 B 와 다르고(`m4-m68k-funcbytes-p730-{S1,S2}-20261103.json`) `addal d0,a0`(`d1c0`)도 `lea a0@(0,d0:l)`(`41f00800`)도 없습니다(python 으로 바이트 탐색). S1 의 풀이(`objdump`)는 기저를 a1, 오프셋을 a0 에 두고 `a1@(0xc,a0:l)`·`a1@(8,a0:l)` 의 색인 주소만 씁니다. H7 은 기각입니다(원본은 기저 a0, 오프셋 d0 이고 `screen` 포인터를 `lea` 로 만듭니다).

새 소스 근거(`optabs.c:399–421` 을 열음): `expand_binop` 은 교환 가능 연산에서 `target == op1` 이거나 `op1` 이 REG 이고 `op0` 가 REG 가 아니면(상수 `op0` 도) 피연산자를 바꿉니다. `flag_force_mem` 이면 먼저 `force_not_mem` 으로 MEM 을 레지스터로 끌어옵니다(`optabs.c:371–374`). 그래서 D 처럼 `evScreen` 이 레지스터에 있고 `target` 이 `screen` 이면 순서는 나무 순서(기저, 오프셋) 그대로입니다. `(오프셋, 기저)` 순서가 되려면 나무의 순서가 오프셋이 첫째이거나(정수 덧셈: `screenIndex * sizeof (EvScreen) + (int) evScreen` — 포인터 덧셈은 `c-typeck.c` 가 포인터를 첫째로 놓음) `target` 이 둘째 피연산자여야 합니다.

가설 H8: 원본 소스의 주소 계산은 오프셋을 첫째로 하는 정수 덧셈 꼴이다.
묶음(진단): T2 `screen = (EvScreen *)(screenIndex * sizeof (EvScreen) + (int)evScreen);`, T3 `screen = (EvScreen *)((int)evScreen + screenIndex * sizeof (EvScreen));`(대조: 기저 첫째), T4 `screen = (EvScreen *)((char *)evScreen + screenIndex * sizeof (EvScreen));`(대조: 포인터 첫째). 나머지는 D 와 같습니다. 판정(미리 정함): 148 B 이고 바이트·재배치 대상이 같으면 해결. 형 변환 `(int)` 포인터는 이 소스의 모양을 단정하지 않는 진단용이며, 해결되면 구현 선택 전에 사용자께 여쭙니다(§693).

### 730.5 H8 확인: `evsetup_screens` 148 B 일치 (run `m4p730-p2`, 2026-11-03; 07 변경 없음)

결과(함수 기록 `m4-m68k-funcbytes-p730-{T2,T3,T4}-20261103.json`):
- **T2** `screen = (EvScreen *)(screenIndex * sizeof (EvScreen) + (int)evScreen);` → `evsetup_screens` **148 B, 바이트와 재배치 대상까지 SAME(1/1)**.
- T3(기저 첫째 정수 덧셈)·T4(`(char *)` 기저 첫째)는 146 B(`addal`), 대조군으로 기대대로입니다.
즉 `lea` 를 낳는 것은 `(plus 오프셋 기저)` 순서이고, 그 순서는 소스 덧셈의 피연산자 순서(오프셋이 첫째인 정수 덧셈)에서 옵니다(`optabs.c:399–421` 의 교환 규칙, `c-typeck.c` 의 포인터 첫째 배치).

한계: 이 소스 모양이 원본의 실제 소스라는 증거는 없고, 같은 바이트를 내는 다른 모양(예: `unsigned`, 오프셋을 먼저 지역 변수로 계산 후 `(int)evScreen` 에 더함)이 있을 수 있습니다. 구현 선택은 §693 의 사용자 확인 조건을 지킵니다. 통합 TU(§718 A)에서의 영향은 다음 단계에서 확인합니다. 07·상태표는 바꾸지 않았습니다.

### 730.6 통합 TU 확인 계획 (코딩 전; 2026-11-03)

§718 A(`evmouse_A.c`, 13 함수 전문 연결)에서 `evsetup_screens` 의 `screen = &evScreen[screenIndex];` 한 줄만 T2 꼴로 바꾼 A2 를 새 run `m4p730-p3` 에서 컴파일합니다. 판정(미리 정함): `m68k_funcbytes.py`(임시 앵커 일곱은 §718 기록의 `mapping` 그대로) 13/13 이고 `object_only` 없음, 외부 정의·COMMON·UNDF 집합이 §718 과 같음. 어긋나면 어느 함수가 달라졌는지 기록하고 멈춥니다. 이 확인은 07·상태표를 바꾸지 않으며 수락이 아닙니다(자료 소유·§693 사용자 확인이 남음).

### 730.7 통합 TU 결과 (run `m4p730-p3`, 2026-11-03; 07 변경 없음)

먼저 제 잘못: §730 의 방법 4 에 "참조 10 곳은 §716.1 의 원본 목표" 라고 썼으나 이번 판정은 `m68k_funcbytes.py` 의 재배치 대상 비교(같은 이름·같은 목표)로 했고, §716.1 의 열 곳 개별 대조(위치·폭·type·pcrel)는 단독 T2 에 다시 하지 않았습니다. 해결 선언을 "바이트와 `funcbytes` 의 재배치 대상 비교" 로 한정합니다.

결과: A2(= §718 A 에서 `screen = &evScreen[screenIndex];` 한 줄만 T2 꼴로 바꿈)는 컴파일 경고 0, 임시 앵커 일곱(§718 기록의 `mapping`)으로 **13/13 SAME, object-only 없음**이고, 외부 정의 13·COMMON 0·UNDF 49 로 §718.1 의 사전 집합 수와 같습니다(python; 비교할 §718 객체 파일은 디스크에 없어 이름 집합 일치는 수만 확인). 함수 기록 `m4-m68k-funcbytes-p730-A2-20261103.json`, probe 기록 `m4-m68k-probe-p730-p3-20261103.json`. 이 결과는 서로 맞는 진단일 뿐 수락이 아닙니다. 남은 것: 익명 자료·BSS 의 소유와 이름(TU 지역 자료 가설 §720–722), 이름 없는 보조 함수, 헤더 COMMON, 인접 행 216(`MoveTheCursor`)·218(`evdispatch` 등)과의 경계, 공유 머리 변경 회귀, §693 사용자 확인.

## 731. M4-198 세부 계획 — m68k `ev_mouse`(행 217) 익명 자료를 번역 단위 안의 별개 `static` 으로 두는 통합 진단 E (07 변경 없음; 코딩 전, 2026-11-03)

고른 까닭: §730 으로 13 함수가 임시 외부 자료 앵커 조건에서 모두 맞았지만(A2, 13/13), 그 소스는 원본에 없는 이름 다섯(`ev_init_num`, `ev_init_thresholds`, `ev_init_factors`, `ev_shmem_cursor`, `ev_adb_mouse`)을 미정의 외부 기호로 쓰므로 수락 관문(원본에 없는 외부 이름 0)을 통과할 수 없습니다. §720 B(구조체 하나로 결합)는 `InitMouseVars`·`ev_register_screen` 이 달라졌고 §721 D(scale 만 구조체)는 `InitMouseVars` 가 달라졌으며 §721 C(cursor 만 local 정의)는 `ev_register_screen` 을 포함해 12/13(`evsetup_screens` 만 불일치)이었습니다. §722 E·F(별개 `static`)는 이전 세션이 이미 실행했습니다(run `m4p722-p1`, 함수 기록 `m4-m68k-funcbytes-p722-{E,F}-20261102.json`, E 는 12/13; 정식 검사 기록은 없음). §730 으로 `evsetup_screens` 가 풀렸으므로 같은 별개 `static` 꼴을 T2 와 함께 다시 시험합니다. 원본 바이트는 이 자료가 이 번역 단위의 것임을 시사합니다(python): `__data` 28 B [0x40b1260, 0x40b127c) 는 앞 객체 `ev_kbd` 의 `__data`(13 B, [0x40b1252, 0x40b125f)) 바로 뒤이고, 서로 다른 절대 주소 `0x40b1260`(long)·`0x40b1262`(word)·`0x40b1264`·`0x40b126e`·`0x40b1278` 로 접근되어 변수 경계가 구조체 하나보다 변수 다섯에 더 가깝습니다(§717). 이것은 추정이며 결정은 바이트가 합니다.

방법(진단; 07 변경 없음):
1. E = §730 의 A2(`08_build/artifacts/m4p730/src/evmouse_A2.c`)에서 다섯 `extern` 이름 선언을 지우고, 첫 함수 앞에 별개 `static` 정의를 둡니다: `static int ev_init_num = 5; static short ev_init_thresholds[5] = {2,3,4,5,6}; static short ev_init_factors[5] = {2,4,6,8,10}; static char *ev_shmem_cursor = 0; static int ev_adb_mouse;`(값은 §717 의 28 B `00000005 0002 0003 0004 0005 0006 0002 0004 0006 0008 000a 00000000` 과 `0x40b4fb6` 의 BSS 4 B). 함수 본문은 바꾸지 않습니다. 선언 줄 `extern int mouseDelX, mouseDelY, numMouseScales, ev_adb_mouse;` 에서는 `ev_adb_mouse` 만 뺍니다. 정의 순서는 `__data` 28 B 의 순서(수, 문턱값, 인수, cursor)이고, 순서가 컴파일러에서 뒤집히면 대조군 E_R 로 반대 순서를 시험합니다.
2. 실기 run `m4p731-p1`(E), 필요하면 `p2`(E_R). 판정(미리 정함, 완화하지 않음): (가) 13 함수 SAME(이름 없는 앵커 대신 로컬 심볼; 지역·scattered 재배치는 §720–721 처럼 별도 python 검사로 원본 목표와 양방향 대조), (나) `__data` 28 B 가 원본과 바이트별로 같음, (다) `__bss` 에 4 B, 위치 양립은 §720 의 방식으로(원본 0x40b4fb6 은 2 B 정렬), (라) 외부 정의 13·COMMON 0·미정의 44(§718.1 의 49 에서 다섯을 뺌). 이 44 에는 원본 기호표에 없는 `_ev_wait_frame`(0x406a9d4)·`_ev_point_to_screen`(0x406aa0c)가 남습니다(python: A2 의 미정의 49 가운데 원본에 없는 것은 이 둘과 다섯 자료 이름뿐). 이 둘은 행 218 쪽 이름 없는 함수라 이 진단에서는 정확한 예외 집합으로 허용하고, 수락 단계에서는 해당 함수들을 같은 번역 단위로 합쳐야 함을 남은 일로 적습니다. 하나라도 어긋나면 어느 쪽인지 적고 멈춥니다.
3. 통과해도 수락이 아닙니다: 이름 없는 보조 함수 둘(0x406a9d4 56 B, 0x406aa0c 100 B; 행 218 쪽), 행 216 `MoveTheCursor`·218 과의 경계, 헤더 COMMON, §693 의 사용자 확인(T2 꼴 등)이 남습니다.

위험(미리 적음): (가) 정적 변수의 정의를 함수 앞에 두면 `static` 접근이 구조체 결합 때와 달리 절대 주소 접근이 되어 §720 B 의 `InitMouseVars` 변화는 없을 수 있으나, `ev_register_screen` 은 cursor 의 로컬 정의에 따라 §721 C 에서 12/13(통과)이었으므로 조합 효과는 실측해야 합니다. (나) 컴파일러가 쓰이지 않는 정적 변수를 지울 수 있습니다(`ev_init_num` 등은 쓰이므로 해당 없음). (다) NeXT cc 가 `static char *p = 0;` 를 `__data` 에 두는 것은 §721 C 에서 확인했습니다.

### 731.1 §731 codex 교차검토(`gpt-6.1-sol`) 판정 (코딩 전, 2026-11-03)

먼저 제 잘못: (1) §731 이 "§722 의 별개 변수 진단은 실행하지 않았다"고 썼으나 이전 세션이 실행했습니다(`m4p722-p1` 의 `DONE`, REGISTRY 1 건, 함수 기록 E·F). (2) "§721 C·D 모두 코드가 달라졌다"는 틀렸습니다(C 는 `ev_register_screen` 이 SAME). (3) 판정 (라) "원본에 없는 이름 0" 은 이 편집만으로 불가능했습니다(`_ev_wait_frame`·`_ev_point_to_screen`). 세 곳을 §731 본문에서 고쳤습니다.

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 원본 28 B 바이트, `__data` 구간 [0x40ad964, 0x40b317c), ev_kbd 13 B 뒤 1 B 간격, `0x40b4fb6` 은 `__bss` 안에서 2 B 정렬 | 제가 python 으로 `macho.json`·원본에서 같은 28 B 와 `%2=0, %4=2` 를 얻음(앞서) | ✅ ("바로 뒤"는 1 B 간격 포함 표현으로 고침) |
| 다섯 이름의 모든 줄(120·283 의 `ev_adb_mouse` 중복, 256 의 혼합 선언) | 제가 python 으로 같은 줄 목록(120, 132, 207, 216, 224, 225, 255, 256, 270–273, 283, 318) | ✅ |
| §721 C: `static char *p = 0` 이 `__data` | §721.2 문구(4 B `__data` 에 `_trial_cursor`)와 일치 | ✅ |
| §722 가 이미 실행됨, E 의 `__data` 가 원본 28 B 와 같고 0·4·14·24 | REGISTRY 1건·`DONE`·함수 기록(E 12/13, mapping 의 `_trial_*`) 확인; `__data` 바이트 비교는 직접 열지 않음 | ✅ 실행 사실 / ⚠️ 28 B 일치는 열지 않아 계획에 옮기지 않음 |
| 미정의 44 에 `_ev_wait_frame`·`_ev_point_to_screen` 이 남음 | python: A2 미정의 49 중 원본에 없는 것 7 개(다섯 자료 + 이 둘) | ✅ |
| `ADDR=NAME` 매핑 필요, `funcbytes` 가 scattered 앵커 처리, 기존 `p720/p721 check.py` 는 scattered 를 주 대조에서 제외 | `m68k_funcbytes.py:198–210` 을 열음(scattered 처리 있음); `check.py` 는 열어 줄만 봄(내용 일부) | ✅ funcbytes / ⚠️ check.py 세부는 열지 않음 |
| `evsetup_screens` 가 새로 맞아 기존 검사 입력에서 빠짐; 제한 검사는 SAME 판정 대용 불가 | `evsetup_check` 가 서로 다른 명령을 제외한다는 §719.2 문구와 일치 | ✅ |
| (나)(다)에 로컬 심볼의 절·상대 위치·padding·재배치·zerofill 종류 추가, 개별 앵커만으론 한 배치의 성립을 못 봄 | 동의 | ✅ 아래 판정에 추가 |
| 쓰이는 정적은 지워지지 않는다는 서술은 근거 부족 | 동의(실측) | ✅ 위험 서술 고침 |

판정 보강(§731 에 더함): 로컬 정적 심볼의 `__data`/`__bss` 상대 위치(0·4·14·24, bss 0), 자료 padding, 자료 재배치 0, zerofill 종류를 python 으로 직접 확인하고, 정적 접근 재배치는 `funcbytes` 의 scattered/local 해석 결과(앵커 매핑 `0x40b1260=_ev_init_num` 등)와 객체 심볼 위치를 함께 봅니다. 07·공유 머리·상태표·PROVENANCE·MODIFICATIONS 는 바꾸지 않습니다. 통과해도 "해당 컴파일 조건의 통합 진단 성공"일 뿐입니다.

### 731.2 진단 E 결과 (run `m4p731-p1`, 2026-11-03; 07 변경 없음)

먼저 제 잘못: E 의 첫 판정 조건에 funcbytes 의 이름 매핑만 믿으면 변수 배치가 틀려도 SAME 이 나올 수 있다는 점(codex 지적)이 실제로 나타났습니다 — 반대 순서 대조군 ER 도 13/13 SAME 이지만 `__data` 가 원본과 다릅니다. 그래서 배치 판정은 `__data` 바이트와 심볼 상대 위치(python)로 따로 합니다.

결과(compile·`-M` rc 0, 경고 0, SDK 의존 정상; 함수 기록 `m4-m68k-funcbytes-p731-{E,ER}-20261103.json`, probe 기록 `m4-m68k-probe-p731-p1-20261103.json`):
- **E**(정의 순서 수·문턱값·인수·cursor, 그 뒤 `ev_adb_mouse`): 13/13 SAME, object-only 없음. `__text` 1946 B, `__data` 28 B(**원본 28 B 와 바이트별로 같음**, 자료 재배치 0), `__bss` 4 B. 로컬 심볼 상대 위치: `_ev_init_num` 0, `_ev_init_thresholds` 4, `_ev_init_factors` 14, `_ev_shmem_cursor` 24 (`__data`), `_ev_adb_mouse` 0 (`__bss`) — §720 이 계산한 목표 0·4·14·24 와 같습니다. 외부 정의 13, COMMON 0, 미정의 44 이고 원본 기호표에 없는 이름은 `_ev_wait_frame`·`_ev_point_to_screen` 둘뿐입니다(위 예외 집합과 같음). 객체 SHA-256 `fd41643b…`.
- **ER**(반대 순서): 함수는 13/13 이지만 `__data` 28 B 가 원본과 다르고(심볼 순서가 뒤집힘) 객체 `canon`·`obj_sig` 가 E 와 다릅니다. 즉 이 컴파일러는 정의 순서대로 `__data` 를 배치합니다(이 소스에서 실측).

판정(미리 정한 대로): (가) 13/13 ✅ (나) `__data` 28 B 같음 ✅ (다) `__bss` 4 B ✅(원본 0x40b4fb6 의 2 B 정렬과 양립 여부는 §720 처럼 추정; 링크 배치 증거 아님) (라) 외부 정의 13·COMMON 0·미정의 44, 원본에 없는 이름은 둘뿐 ✅. 통과했으나 이것은 **해당 컴파일 조건의 통합 진단 성공**입니다.

남은 일(`ev_mouse` 단위 수락까지): ① 원본에 없는 미정의 둘은 같은 번역 단위의 이름 없는 함수(0x406a9d4 56 B, 0x406aa0c 100 B; 행 218 쪽, 각각 §697·§700 에서 단독 진단)이므로 단위 범위를 [0x4069eb8, 0x406aa70)(행 216·217·218, 3000 B — 처음 적은 2744 B 는 틀린 수였고 §734 에서 python 으로 고침)로 넓혀 `static` 으로 합쳐야 합니다. ② 그 범위의 `MoveTheCursor`(536 B, §709–714 에서 0/1, 123 B 차이)와 `evdispatch`(296 B)·`evretry`(66 B)의 바이트 일치(앞의 둘은 단독 진단 기록 없음), ③ 헤더 COMMON, ④ 사용자 확인(§693: 정수 덧셈 꼴 T2, 정적 변수 이름과 모양).

## 732. M4-199 세부 계획 — m68k `MoveTheCursor`(행 216, 536 B) 의 남은 차이를 컴파일러 중간 표현으로 가르기 (07 변경 없음; 코딩 전, 2026-11-03)

고른 까닭: §731 로 `ev_mouse` 13 함수의 자료 문제는 진단상 풀렸고, 남은 큰 불일치는 행 216 `MoveTheCursor`(0/1, 비교 바이트 차이 123, §712 D·§713 E)입니다. NeXTMach 와 Darwin 0.1 어디에도 `MoveTheCursor` 가 없어(grep 0 건) 참고 글이 없고, 바이트와 컴파일러의 동작으로만 정해야 합니다. 지난 세션의 진단 A–E 는 원인 분석 없이 표현을 바꿔 보는 방식이었습니다.

사실(python 으로 원본 objdump `scratch/p690/original-objdump.txt` [0x4069eb8, 0x406a0d0) 155 명령과 D의 objdump 154 명령을 정규화해 비교; 절대 주소·분기 목표는 마스크):
- D 와 원본의 실질 차이는 네 곳뿐입니다. (가) 맨 앞 화면 주소 계산: 원본은 `moveal 0x40c3610,%a0; lea a0@(0,a0:l:4),a0; movel a0,d0; asll #3,d0; moveal d0,a1; addal 0x40c3630,a1; lea a1@(12),a0` 이고 D 는 `…lea a0@(0,a0:l:4),a0; moveal 0x40c3630,a1; lea a1@(0,a0:l:8),a1; lea a1@(12),a0`. (나) 화면 사각형 y 비교의 적재 순서: 원본 `movew fp@(10),d1` 뒤 `movew a1@(16),d0`, D 는 반대. (다) `cursorPin` y clamp 도 같은 순서 차이(원본 `movew fp@(10),d1` 뒤 `movew 0x40c3618,d0`, D 는 반대). (라) 위치 비교: 원본 `moveal 0x40c3640,a0; movel fp@(8),d0; cmpl a0@(24),d0; beq; movel d0,a0@(24)` 이고 D 는 `moveal …,a0; movel a0@(24),d0; movel fp@(8),d1; cmpl d0,d1; …; movel d1,a0@(24)`.
- §730 에서 얻은 규칙: 덧셈 `plus` 의 피연산자 순서가 `addal`/`lea` 선택과 메모리 피연산자 합치기를 정합니다(`addsi3`: `operands[0]≠operands[1]` 이면 `lea`; 그 밖에 `r,0,mrIKLs` 대안은 둘째 피연산자가 메모리여도 됨). (가)의 원본 `moveal d0,a1; addal mem,a1` 은 최종 명령 구성과 양립하는 가설이며(`operands[0]=operands[1]=a1`, `operands[2]=MEM`), reload 전에 `(plus MEM 오프셋)` 이었다가 교환되었을 가능성(`reload.c:3273`, `optabs.c:399`)도 배제하지 못합니다(§732.1). D 는 기저를 레지스터로 적재하고 오프셋의 `<<3` 이 `lea` 의 배율 8 로 합쳐졌습니다.

방법(07 변경 없음):
1. D(`08_build/artifacts/m4p712/move_D.c`)를 §728·§730 방식으로 덤프 컴파일하는 실기 run `m4p732-d1`. 덤프 옵션 객체가 기존 D 객체를 재현하는지(`canon`·`obj_sig`) 먼저 봅니다.
2. python 으로 `.rtl`→`.cse`→`.combine`→`.greg` 에서 (가)~(라) 각각의 insn 을 읽어 어느 패스에서 순서·형태가 정해지는지 가립니다.
3. 공개 GCC 2.7.2.3 소스(`expr.c`, `optabs.c`, `cse.c`, `combine.c`, `jump.c`)에서 원인을 찾아 가설을 세우고 최소 변형으로 시험합니다. (가)는 §730 의 T2 꼴(오프셋 첫째 정수 덧셈)을 먼저 시험합니다. (나)(다)는 비교 조건의 쓰는 방향(`p.y < miny` 대 `!(p.y >= miny)`)과 `jump.c` 의 비교 교환 규칙을, (라)는 `*(int *)&p` 와 `evg->cursorLoc` 의 읽기 방식(volatile 여부, 구조체 대입)을 봅니다.
4. 판정(미리 정함): `MoveTheCursor` 536 B 이고 바이트와 재배치 대상(`funcbytes`; 임시 앵커 `0x406aa0c=_ev_point_to_screen`, `0x406a86a=_evdispatch`)이 같으면 해결입니다. 조건부이며 원본 소스를 확정하지 않고, 구현 선택은 §693 에 따라 사용자께 여쭙습니다. 풀리지 않으면 멈추고 보고합니다. 기준을 낮추지 않습니다.

### 732.1 §732 codex 교차검토(`gpt-6.1-sol`) 판정 (코딩 전, 2026-11-03)

먼저 제 잘못: (1) §732 가 (가)의 원본 RTL 순서를 "(plus 오프셋 (mem))" 이라고 단정에 가깝게 썼습니다. 최종 명령 구성과 양립할 뿐 reload 전 순서는 모릅니다(위에서 고침). (2) 계획 3 단계가 `jump.c` 의 비교 교환을 (나)(다)의 후보로 든 것은 근거가 약합니다: `swap_condition` 은 조건 코드 변환일 뿐이고(`jump.c:2780` 열음), 적재 순서는 `expr.c compare()` 가 피연산자 0→1 순서로 펼치며 `compare_from_rtx` 는 상수가 첫째일 때만 바꿉니다(`expr.c:9608–9660` 열음). 그러므로 (나)(다)의 순서 차이는 소스 표기 순서만으로는 설명되지 않아 덤프로 가려야 합니다. (3) `p.y < miny` 와 `!(p.y >= miny)` 는 `fold-const.c` 가 같은 비교로 접을 수 있어 구별력이 약한 실험입니다(codex 지적; `fold-const.c:2015·4229` 은 4229 의 `TRUTH_NOT_EXPR` 근처만 열음 → ⚠️ 접힘 여부는 덤프로 확인).

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 원본 155·D 154 명령, 정규화 후 차이는 raw 7 hunk, 문맥으로 묶으면 네 구간(가·나·다·라), 내부 분기 목표 27곳 일치 | 제가 python difflib 로 같은 네 구간을 얻음(가: 8–12, 나: 20–21, 다: 43–44, 라: 53–58) | ✅ (분기 27곳은 직접 재현하지 않음 → 계획에 옮기지 않음) |
| 최종 구성 `r,0,mrIKLs` 와 `add.l %2,%0`(`m68k.md:2232`) | `m68k.md:2228–2236` 을 열음 | ✅ |
| `compare()`/`compare_from_rtx()` 의 순서·상수 교환·`flag_force_mem` 0→1 | `expr.c:9606–9670` 을 열음 | ✅ |
| `Point` 는 `{short x, y}` 구조체, `EvGlobals` 는 volatile typedef 이고 `Point cursorLoc` 가 있음 | `evio.h:66–70`, `176–188` 을 열음 | ✅ (D 의 구조체 대입도 이미 volatile 접근) |
| E 는 해결 증거가 아님(두 레지스터 비교 유지) | `E objdump:59` 는 열지 않음, §713.2 문구와는 일치 | ⚠️ 직접 열지 않음 |
| 덤프 판독에 `.jump`·`.lreg`·`.jump2` 도 봐야 함; 앵커 이름 대응과 실제 재배치 검증을 구분; 통합 TU 에서 재검증; 공개 GCC 는 후보 | 동의 | ✅ 계획 3 단계에 반영 |

2 차 자기검사: ✅ 행은 이번 세션에 연 줄이거나 제가 돌린 python 입니다. 열지 않은 줄은 ⚠️ 로 두었고 어떤 문서에도 옮기지 않았습니다.

### 732.2 덤프 관찰과 변형 묶음 (run `m4p732-d1`, 2026-11-03; 07 변경 없음)

덤프 관찰(`.rtl`, python): D 의 y 비교(나·다)에서 원본과 다른 적재 순서는 소스 순서가 아니라 `.rtl` 에서 정해집니다. 화면 사각형 y 비교는 경계 적재 insn 45 뒤에 `p.y` 적재 insn 121 이 들어가 있고(`insn 121 prev 45 next 46`), 위 x 비교는 `p.x` 적재(37)가 경계 적재(38)보다 앞입니다. insn 121·123·126·128·130·132 는 uid 가 후반 값이라 함수 앞쪽 본문의 y 접근(`mem (plus (reg 24) 2)`)이 뒤늦게 고쳐 쓰인 결과로 보이며, 위치 비교 `*(int *)&p` 를 전개하는 시점(uid 133–139)에 막 앞서서 생성되었습니다. `p.x`(오프셋 0)는 제자리 `mem (reg 24)` 로, `p.y`(오프셋 2)는 새 insn 으로 앞 insn 사이에 삽입됩니다. 가설 H9: `&p` 를 늦게 취하는 D 의 위치 비교가 앞선 `p` 접근을 뒤늦게 메모리로 바꾸는 과정(`function.c` 의 변수 스택 이동 처리)을 일으켜 (나)(다) 순서를 바꾼다. 원본은 `p` 접근이 처음부터 메모리라 순서가 소스 순서 그대로다. (확인하지 않은 부분: 왜 앞 접근에 `p` 의 초기 복사 insn 이 없는지, 정확한 함수 이름; `function.c` 는 아직 가져오지 않음 → 공개 소스를 읽어 확인할 항목.)

묶음(진단): Y1 = D + 맨 앞 선언 `int *pp = (int *)&p;` 와 위치 비교의 `*(int *)&p` 를 `*pp` 로. Y2 = D 의 (가) 주소 계산을 §730 T2 꼴 `screenBounds = &((EvScreen *)(currentScreen * sizeof(EvScreen) + (int)evScreen))->bounds;`(`screenOffset` 제거)로. Y3 = Y1 + Y2. 판정(미리 정함): 정규화 비교(difflib)에서 차이 구간 개수가 줄어드는지, 최종적으로 536 B 바이트·재배치 대상 일치(`funcbytes`). 어긋나면 새 덤프를 읽습니다.

### 732.3 Y 묶음 결과와 Z 묶음 계획 (run `m4p732-p1`, 2026-11-03; 07 변경 없음)

결과(정규화 difflib; 함수 기록 `m4-m68k-funcbytes-p732-{Y1,Y2,Y3}-20261103.json`):
- Y1(맨 앞 선언 `int *pp = (int *)&p;`): (나)(다) 의 y 적재 순서 차이 구간이 **사라졌습니다**(차이 구간 7 → 4개: 시작부에 `lea %fp@(8),%a2` 한 줄이 늘고, (가), (라) 둘). 그러나 538 B(+2 B)입니다. H9(앞선 `&p` 가 p 접근 순서를 바꿈)는 지지되지만 `pp` 를 쓰면 포인터가 살아남아 불필요한 명령이 생깁니다.
- Y2(§730 T2 꼴): (가)는 D 와 똑같이 `moveal evScreen,a1; lea a1@(0,a0:l:8),a1; lea a1@(12),a0` 로 안 바뀜(536 B, 123 B 차이, 구간 7).
- Y3: Y1 과 같음.
따라서 (가)는 `<<3` 이 `lea` 배율로 합쳐지지 않고 `asll #3` 과 `addal mem,a1` 로 남는 모양이며, 오프셋 첫째 덧셈만으로는 안 됩니다(주소 문맥 `EXPAND_SUM` 이 어느 쪽이든 합쳐짐). 원본은 `a1`(화면 포인터)을 값으로 만든 뒤 `lea a1@(12),a0` 로 bounds 포인터를 만드는 모양이므로, 화면 포인터를 값 문맥에서 만드는 가설 H10 을 시험합니다.

묶음(진단): Z1 = D + 함수 첫 문장 `(void)&p;`(`pp` 변수 없이 앞선 `&p` 만; 코드를 만들지 않을 것으로 예상하지만 실측), Z3 = D 의 (가)를 `screen = &evScreen[currentScreen]; screenBounds = &screen->bounds;`(`EvScreen *screen` 지역 변수; 값 문맥의 포인터 덧셈) 로, Z4 = Z1 + Z3. 판정(미리 정함): 차이 구간 수가 줄고 최종 536 B 바이트·재배치 일치. 모르는 것: `(void)&p;` 가 컴파일러에서 코드 없이 `p` 를 메모리로 옮기는 효과(파싱 시점의 `mark_addressable`)를 내는지 — 실측으로 확인.

### 732.4 Z 묶음 결과와 W 묶음 계획 (run `m4p732-p2`, 2026-11-03; 07 변경 없음)

결과(`scratch/p730/cmpmove.py` 정규화 비교; 함수 기록 `m4-m68k-funcbytes-p732-{Z1,Z3,Z4}-20261103.json`): **Z1(= D + 첫 문장 `(void)&p;`)은 (나)(다)의 y 적재 순서 차이를 536 B 그대로 없앴습니다**(차이 구간 7 → 3: (가) 하나, (라) 둘). 가설 H9 가 코드 증가 없이 확인되었습니다: `p` 를 메모리에 두는 `&p` 가 첫 사용보다 앞서면 접근 순서가 소스 순서 그대로입니다. Z3(`screen = &evScreen[currentScreen]; screenBounds = &screen->bounds;`)은 (가)를 바꾸지 못했고(여전히 `moveal evScreen,a1; lea a1@(0,a0:l:8),a1`) Z4 = Z1 과 같은 결과입니다.

(라) 분석(원본 `movel fp@(8),d0; cmpl a0@(24),d0; beq; movel d0,a0@(24)`): 비교의 한 피연산자가 레지스터에서 바로 메모리(`cursorLoc`)를 비교합니다. D 는 `cursorLoc` 를 `volatile int` 로 읽어 먼저 레지스터로 적재(volatile 은 `combine` 이 다른 명령에 합치지 않음)합니다. 가설 H11: 원본의 `cursorLoc` 읽기는 `volatile` 이 없는 `int` 읽기이고(`(int *)&evg->cursorLoc` 는 형 변환으로 volatile 을 떼므로 가능), 피연산자 순서는 `p` 가 앞이다.

묶음(진단): 기반은 Z1. W1 = 비교를 `*(int *)&p == *(int *)&evg->cursorLoc` 로, W2 = 순서를 `*(int *)&evg->cursorLoc == *(int *)&p` 로(둘 다 volatile 없음), W3 = `*(int *)&p == *(volatile int *)&evg->cursorLoc`(대조). 나머지는 Z1 과 같습니다. 판정(미리 정함): (라) 두 구간이 사라지는지(정규화 비교), 536 B. 남는 (가)는 별도 분석(결합 패스 덤프).

### 732.5 W·V 묶음 결과와 현재 상태 (run `m4p732-p3`·`p4`·덤프 `d2`, 2026-11-03; 07 변경 없음)

먼저 제 잘못: §732.3 에서 Z3 를 "(가)를 바꿀 것"으로 계획했으나 바뀌지 않았고, §732.4 의 V 묶음(오프셋 첫째 덧셈, 값 문맥 포인터 덧셈, 정수 기저 첫째, 배열 첨자 둘 다)도 (가)를 바꾸지 못했습니다. 원인을 확정하지 못한 채 표기만 바꾼 것입니다.

결과:
- **W1·W2**(Z1 + 위치 비교를 `volatile` 없는 int 비교 `*(int *)&p == *(int *)&evg->cursorLoc` 또는 반대 순서): (라)의 두 구간이 **사라졌습니다**. 차이 구간 3 → **1**(남은 것은 (가)뿐), `__text` 534 B(원본 536 B 와 2 B 차이, 정규화 비교 153 대 155 명령). W3(`volatile int` 로 읽기, 대조군)은 (라)가 그대로 남습니다. 해석: 원본의 위치 읽기는 volatile 이 아니고(`(int *)&evg->cursorLoc` 형 변환으로 volatile 이 떨어짐) 피연산자 순서와 무관하게 `combine` 이 메모리 읽기를 `cmpl` 에 합칩니다.
- **(나)(다)**: Z1 의 `(void)&p;` 한 문장으로 해결(코드 증가 없음).
- **(가) 남음**: 원본 `movel a0,d0; asll #3,d0; moveal d0,a1; addal 0x40c3630,a1`(12 B) 대 후보 `moveal 0x0,a1; lea a1@(0,a0:l:8),a1`(10 B). 덤프(`m4p732-d2`, W1 `.combine`/`.greg`)에서 후보는 `combine` 이 `(ashift 37 3)` 를 `(plus (mult 37 8) 39)` 로 합쳐 `lea` 패턴(generic `lea %a1,%0`, md 6118) 로 인식하며, 기저 `evScreen` 의 적재는 합쳐지지 못하고 따로 남습니다. 원본은 반대로 기저 적재(`mem`)가 덧셈에 합쳐졌고 시프트가 따로 남았습니다. `combine` 이 어느 쪽 이전 명령을 먼저 시도하는지는 `LOG_LINKS` 순서(피연산자 방문 순서)에 달린 것으로 보이나 아직 `combine.c`·`flow.c` 로 확인하지 않았습니다(⚠️ 미확인 가설 H12).

현재 최선 소스: `08_build/artifacts/m4p732/src/move_W1.c`(D + 첫 문장 `(void)&p;` + 위 비교). 차이: (가) 한 구간, 2 B. 다음 단계: H12 를 `combine.c` 의 링크 순서와 시도 규칙으로 검토하고, 앞의 어떤 소스 표현이 기저 적재를 덧셈에 먼저 합치게 하는지 시험합니다(코딩 전 계획·codex 검토 필요). 이 결과는 진단이며 수락이 아닙니다.

## 733. M4-200 세부 계획 — `MoveTheCursor` (가): `combine` 의 LOG_LINKS 시도 순서와 기저 적재의 위치 (07 변경 없음; 코딩 전, 2026-11-03)

고른 까닭: §732.5 에서 `MoveTheCursor` 의 원본 차이는 (가) 한 구간(2 B)만 남았습니다: 원본 `movel a0,d0; asll #3,d0; moveal d0,a1; addal evScreen,a1`, 후보 W1 `moveal evScreen,a1; lea a1@(0,a0:l:8),a1`. 가설 H12 를 공개 GCC 소스로 확인했습니다.

사실(공개 GCC 2.7.2.3, 모두 열음):
- `combine.c:571–573` 은 각 insn 에 대해 `LOG_LINKS (insn)` 을 처음부터 차례로 `try_combine (insn, 링크 insn, 0)` 하고 처음 성공하면 `goto retry` 합니다.
- `flow.c:2072–2091` 은 `propagate_block` 이 뒤에서 앞으로 훑을 때 정의 insn 이 자기 자신을 "다음 사용 insn" 의 `LOG_LINKS` 앞에 끼웁니다(`LOG_LINKS (y) = gen_rtx (INSN_LIST, VOIDmode, insn, LOG_LINKS (y))`). 뒤에서 앞으로 훑으므로 나중 정의가 먼저 끼워지고, 더 이른 정의가 리스트 맨 앞에 옵니다. 결과: **한 insn 의 정의 insn 들 가운데 가장 이른 것이 먼저 합쳐 보아집니다.**
- 덤프 `m4p732-d2` 의 W1 에서 combine 진입 전 `.flow` 의 insn 35 는 `(set 40 (plus 39 38))` 이고 링크는 `(insn_list 29 (insn_list 34 …))` 입니다: 29(`(ashift 37 3)`, 오프셋)가 34(기저 `evScreen` 적재)보다 앞이라 먼저 합쳐집니다(§733.1 에서 고침: 처음 쓴 "28 이 먼저"는 combine 이후의 링크였음). 시프트가 흡수된 결과 덧셈은 `(plus (mult 37 8) 39)` 가 되어 `lea` 패턴(md 6118)에 맞고 기저 적재는 합쳐지지 못합니다. 28 은 별도 insn(×5)으로 남습니다.
- 기저 적재 insn(34)이 오프셋 계산(28, 29)보다 뒤인 까닭: `expand_expr` 가 전역 `evScreen` 을 MEM 으로만 돌려주고(적재 insn 없음), `expand_binop` 이 `flag_force_mem` 으로 `force_not_mem` 할 때 비로소 적재 insn 을 냅니다(`optabs.c:371–374`); 그때는 오프셋 insn 들이 이미 나온 뒤입니다(앞서 `.rtl` 에서 확인).

가설 H13: 원본에서는 `evScreen` 이 오프셋 계산보다 **먼저 레지스터로 적재**되어 있었고(예: 지역 포인터 `es = evScreen` 이 앞서 대입), 그래서 적재 insn 이 `LOG_LINKS` 맨 앞에 와 덧셈에 먼저 합쳐지고(`addal mem,a1`), 시프트는 합쳐지지 못한 채 `asll #3` 로 남는다.
묶음(진단; 기반 W1 = `08_build/artifacts/m4p732/src/move_W1.c`): H1 = 선언부 `EvScreen *es = evScreen;`(초기화 선언) + `screenBounds = &es[currentScreen].bounds;`; H2 = 같은 지역 변수를 `if (!screens) return;` 뒤 첫 대입문으로(`es = evScreen;`); H3 = H1 과 같으나 `screenBounds = &((EvScreen *)(currentScreen * sizeof(EvScreen) + (int)es))->bounds;`. 나머지는 W1 과 같습니다. 판정(미리 정함): 정규화 비교(`scratch/p730/cmpmove.py`)에서 차이 구간이 0 이고 536 B, `funcbytes`(앵커 `0x406aa0c=_ev_point_to_screen`, `0x406a86a=_evdispatch`) 일치. 일치해도 원래 소스가 이 모양이라는 증거는 아니며 §693 에 따라 사용자께 여쭙습니다. 한계: 지역 변수가 레지스터를 차지해 다른 부분의 할당이 바뀔 수 있음(실측으로 확인).

### 733.1 §733 codex 교차검토(`gpt-6.1-sol`) 판정 (코딩 전, 2026-11-03)

먼저 제 잘못: (1) §733 이 combine 이후 링크 `[28,34]` 를 "시프트가 먼저 합쳐진 증거"로 썼습니다. combine 진입 전 `.flow` 는 `[29,34]` 이고 29 가 시프트입니다(위에서 고침). (2) H1·H3 는 `es` 적재를 `if (!screens)` 앞에 두므로 덧셈과 다른 기본 블록이 되어 직접 `LOG_LINKS` 가 생기지 않습니다(`flow.c:2087` 의 `BLOCK_NUM (y) == blocknum`). H13 의 직접 시험은 H2 이고 H1·H3 은 대조군입니다.

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| `propagate_block` 은 끝에서 처음으로(`flow.c:1436`), 정의가 사용 insn 링크 선두에 삽입(2076–2091), combine 은 선두부터 시도(571) | `flow.c:1436–1439`, `2085–2090` 을 열고 combine 571 은 앞서 읽음 | ✅ |
| 같은 기본 블록에서만 링크(`BLOCK_NUM (y) == blocknum`) | `flow.c:2087` 을 열음 | ✅ |
| `.flow` insn 35 의 링크 `[29,34]`, 29 가 `ashift(37,3)`; `.combine` 은 `[28,34]`; `.rtl` 순서 28→29→34→35 | 제가 python 으로 `.flow`·`.combine`·`.rtl` 을 읽어 같은 값을 얻음 | ✅ |
| 시프트가 PLUS 안에서 MULT 로 바뀌고(`combine.c:5418`) `MEM + MULT` 는 `lea` 패턴의 주소 조건(`m68k.h:1182`)을 못 맞춘다 | 두 줄을 열었으나 5418 은 `next_code` 계산, 1182 는 `GO_IF_INDEXABLE_BASE` 라벨 정의여서 주장한 내용이 아님 | ❌ 인용 줄이 틀림 → 계획에 옮기지 않음(이 설명은 소스 근거 없이 "양립"이라고만 둠) |
| 일반 호출은 CSE 메모리 등가를 무효화(`cse.c:7241`), W1 `.cse` 가 호출 뒤에서 `evScreen` 을 다시 읽음 | `cse.c` 7241 은 열지 않음; `.cse` 는 제가 보지 않음 | ⚠️ 미확인, 계획에 옮기지 않음 |
| `es` 가 호출을 가로질러 보존되지 않는다 | W1 의 `evScreen` 사용처를 grep 으로 확인(4 행 선언, 17 행 화면 주소, 35 행 `cursorPin` 대입) | ✅ |
| 정규화 비교는 주소를 가리므로 정규화 일치만으로 수락 불가, 통합 TU 재검증 필요 | 동의 | ✅ |

2 차 자기검사: ✅ 행의 근거는 이번 세션에 연 줄이거나 제가 돌린 python 출력입니다. ❌·⚠️ 행은 어떤 문서에도 근거로 옮기지 않았습니다.

### 733.2 H 묶음 결과와 H4·H5 계획 (run `m4p732-p5`, 2026-11-03; 07 변경 없음)

결과(`cmpmove.py`): H1·H3(`es` 를 `if (!screens)` 앞에서 적재; 기본 블록이 달라 직접 링크 없음)은 W1 과 같은 `lea` 꼴(534 B, 대조군으로 기대대로). **H2**(`if (!screens) return;` 뒤 첫 대입문 `es = evScreen;` 와 `screenBounds = &es[currentScreen].bounds;`)는 **536 B, 정규화 비교 차이 구간 1 개**로 줄었습니다: 시프트가 `lea` 배율로 합쳐지지 않고 원본처럼 `movel a0,d0; asll #3,d0` 로 남았고(H13 확인: 적재가 오프셋보다 앞이면 적재가 먼저 합쳐지고 시프트가 남음), 남은 차이는 마지막 두 명령의 피연산자 방향뿐입니다 — 원본 `moveal d0,a1; addal 0x40c3630,a1`, H2 `moveal 0x0,a1; addal d0,a1`(크기 같음).

해석(소스 근거: `reload.c:3220` 무reload 첫 대안 선택, `reload.c:3273` 교환 시도는 비교환 대안 조사 뒤; `m68k.md:2148–2210` `addsi3`): 덧셈이 `(plus (mem) (reg 오프셋))` 이면 비교환 대안이 먼저 맞으므로 메모리를 목적지 레지스터로 적재하고 오프셋을 더하며(`moveal mem,a1; addal d0,a1`, H2), `(plus (reg 오프셋) (mem))` 이면 오프셋을 목적지로 복사한 뒤 메모리를 더합니다(`moveal d0,a1; addal mem,a1`, 원본). 가설 H14: 원본의 덧셈은 오프셋이 첫째이다(§730 의 T2 와 같은 종류). 묶음(진단): H4 = H2 의 주소를 `screenBounds = &((EvScreen *)(currentScreen * sizeof(EvScreen) + (int)es))->bounds;`(오프셋 첫째), H5 = `(int)es + currentScreen * sizeof(EvScreen)`(기저 첫째, 대조). 판정(미리 정함): 차이 구간 0 이고 536 B, `funcbytes` 일치.

### 733.3 H4 결과: `MoveTheCursor` 536 B 일치 (run `m4p732-p6`, 2026-11-03; 07 변경 없음)

결과(함수 기록 `m4-m68k-funcbytes-p732-{H4,H5}-20261103.json`): **H4 = 536 B, 정규화 비교 차이 구간 0, `funcbytes` 1/1 SAME(바이트와 재배치 대상; 임시 앵커 `0x406aa0c=_ev_point_to_screen`, `0x406a86a=_evdispatch`)**. H5(기저 첫째 대조)는 H2 와 같은 방향(`moveal mem,a1; addal d0,a1`)으로 3 B·참조 1곳이 다릅니다(대조군으로 기대대로). H14(덧셈 오프셋 첫째)가 확인되었습니다.

H4 의 소스 요점(원래 소스라는 증거는 아님): ① 함수 첫 문장 `(void)&p;`(p 를 처음부터 메모리에 둠) ② `if (!screens) return;` 뒤 첫 대입 `es = evScreen;`(기저를 오프셋 계산 앞에서 적재; 같은 기본 블록이어야 함) ③ `screenBounds = &((EvScreen *)(currentScreen * sizeof(EvScreen) + (int)es))->bounds;`(오프셋 첫째) ④ 위치 비교는 `volatile` 없는 `*(int *)&p == *(int *)&evg->cursorLoc`. 소스 `08_build/artifacts/m4p732/src/move_H4.c`.

원인 정리(소스 근거 포함): (가)는 세 단계의 결과입니다. (i) `combine` 은 한 insn 의 `LOG_LINKS` 중 가장 이른 정의부터 합칩니다(`flow.c:2076–2091`, `combine.c:571`); (ii) `expand_binop` 은 전역 `evScreen` 적재를 오프셋 계산 뒤에 내므로(`optabs.c:371–374`) 첫 문장을 `es = evScreen;` 로 앞당겨야 적재가 먼저 합쳐지고 시프트가 `asll` 로 남음; (iii) 덧셈 피연산자 방향이 `reload` 의 대안 선택을 정함(`reload.c:3220`, `m68k.md:2148`).

다음: 통합 TU(§731 E + `MoveTheCursor` H4, 원본 순서)에서 14/14 인지 확인합니다(진단; 수락 아님).

### 733.4 통합 TU I1: `MoveTheCursor` + 13 함수 (run `m4p732-p7`, 2026-11-03; 07 변경 없음)

I1 = §731 E 의 앞(별개 `static` 자료 정의) 바로 뒤에 `MoveTheCursor` H4 를 원본 순서대로 둔 소스(`08_build/artifacts/m4p732/src/evmouse_I1.c`). 결과(compile·`-M` rc 0, 경고 0; 함수 기록 `m4-m68k-funcbytes-p733-I1-20261103.json`, probe 기록 `m4-m68k-probe-p733-p7-20261103.json`; 임시 앵커는 이름 없는 함수 둘과 자료 다섯):
- **14/14 SAME**(바이트와 재배치 대상), object-only 없음. `__text` 2482 B(= [0x4069eb8, 0x406a86a) 2482 B, python).
- `__data` 28 B 원본과 바이트별로 같음, `__bss` 4 B. 외부 정의 14, COMMON 0, 미정의 43, 원본 기호표에 없는 이름은 `_ev_wait_frame`·`_ev_point_to_screen` 둘뿐(`MoveTheCursor` 가 같은 단위로 들어와 `_MoveTheCursor` 는 미정의에서 빠짐). 객체 SHA-256 `14bc8aab…`.
이것은 해당 컴파일 조건의 통합 진단 성공이며 수락이 아닙니다. 남은 것: ① 이름 없는 함수 둘(0x406a9d4 56 B, 0x406aa0c 100 B)과 `evdispatch`(296 B)·`evretry`(66 B)를 같은 번역 단위에 편입해 범위를 [0x4069eb8, 0x406aa70) 3000 B(처음 적은 2744 B 는 틀린 수; §734 에서 고침)로 확장하고 바이트 일치시키기(`evdispatch`·`evretry` 는 단독 진단 기록이 없음), ② 헤더 COMMON, ③ §693 사용자 확인(T2 꼴 덧셈, `(void)&p;` 첫 문장, `es = evScreen;` 지역 변수, 별개 `static` 자료의 이름과 모양 등 바이트로 가려지지 않는 선택).

## 734. M4-201 세부 계획 — m68k `ev_mouse` 단위의 `evdispatch`(296 B)·`evretry`(66 B) 단독 진단 (07 변경 없음; 코딩 전, 2026-11-05)

먼저 제 잘못: §731 과 §733.4 와 HANDOFF 가 단위 범위 [0x4069eb8, 0x406aa70) 의 크기를 2744 B 라고 적었습니다. python 으로 다시 계산하면 3000 B(= 2482 + 296 + 66 + 56 + 100)입니다. 위 두 절의 그 줄과 HANDOFF 를 고쳤습니다.

고른 까닭: §733 의 통합 TU I1 로 단위의 앞 14 함수는 진단상 풀렸습니다. 남은 것은 이름 없는 보조 함수 둘(§697·§700 에서 단독 진단)과 `evdispatch`·`evretry` 이고, 뒤의 둘은 단독 진단이 한 번도 없었습니다. NeXTMach 와 Darwin 0.1 에는 이 C 함수가 없어(대소문자를 가려 `evdispatch`·`evretry` 를 `01_resources` 의 텍스트 파일에서 grep: 0 건, 이진 파일은 Darwin driverkit 의 `.index.store` 와 `driverkit-139.1-1.tar.gz` 만 걸림; 대소문자를 가리지 않으면 Darwin driverkit 의 Objective-C 메서드 `evDispatch:command:`(`EventDriver.h:214`, `EventDriver.m:1387`, 호출 `EventInput.m:446–460`)가 나오며 이는 다른 코드) 바이트로만 정해야 합니다.

사실(python `scratch/p734/facts.py` 와 원본 objdump `scratch/p690/original-objdump.txt` 의 [0x406a86a, 0x406a9d4) 를 읽음):
- `evdispatch` [0x406a86a, 0x406a992) 296 B, `evretry` [0x406a992, 0x406a9d4) 66 B, 합 362 B 입니다.
- `evdispatch` 의 읽기: 인수 셋(`d3`=명령, `d4`=화면 번호, `fp@(16)`=셋째). 화면 포인터 `a2` = `evScreen` + 화면 번호 × 40(`moveal d4,a3; lea a3@(0,d4:l:4),a3` 로 ×5 한 뒤 `lea a0@(0,d0:l:8)`). 명령이 3 을 넘으면(`bccs` 부호 없는 비교) `a2@(20)` 바이트의 0x60 비트(= `EvRetry.cursor`)가 0 일 때 앞 덩어리를 건너뜁니다. 앞 덩어리: `cursor = 표[cursor][명령 & 3]`(표 시작 0x40b127c + cursor × 4 에 바이트 색인), 그 값에 따라 2 → `a2@(32)`(`show`), 3 → `a2@(28)`(`move`), 1 → `a2@(24)`(`hide`) 을 부르고(show·move 는 `(esp, evg->cursorLoc, evg->frame)` 세 인수, hide 는 `(esp)` 한 인수; 함수 포인터가 0 이면 안 부름), 반환값 `d2` 가 0 이면 `cursor` 를 0 으로 비웁니다. 뒤 덩어리: 명령이 4 이면 셋째 인수를 정적 4 B(0x40b4fb2) 에 저장하고, 아니면 `retry.level`(`a2@(20)` 의 부호 비트)이 0 이면 건너뜁니다. 그 뒤 `a2@(36)`(`level`)이 있으면 `retry.level = level(esp, 정적값)` 하고 `retry.level` 을 `d2` 에 OR 합니다. 마지막에 `evRetryMask`(0x40c362c) 에서 `1 << 화면` 비트를 지우고 `d2` 가 0 이 아니면 켜서 저장합니다. `a2@(20)` 바이트 접근마다 다시 읽는 것은 `EvScreen` 이 `volatile struct` 라서(SDK `evio.h:111–119`, `typedef volatile struct _evScreen`)로 보입니다.
- `evretry` 의 읽기: `i = 0; m = evRetryMask; m 이 0 이 아니고 i < screens(부호 없는 비교 `bccs`)인 동안 { m 의 0 비트가 1 이면 `evdispatch(0, i, 0)`; i++; m >>= 1(`lsrl`, 논리 시프트) }`.
- 원본 자료: 표는 `__data` 의 0x40b127c, 16 B `00010203 01010002 02000202 03010203` 이고(앞의 익명 자료 28 B [0x40b1260, 0x40b127c) 바로 뒤, 다음은 이름 있는 `_vol_check_delay` 0x40b128c) 정적 4 B 는 `__bss` 의 0x40b4fb2 로 `ev_adb_mouse`(0x40b4fb6) 바로 앞입니다. 둘 다 원본 기호표에 이름이 없습니다. 그러므로 통합 TU 의 `__data` 는 28 + 16 = 44 B, `__bss` 는 4 + 4 = 8 B 가 될 것입니다(통합은 이 단독 진단 뒤).

참고 후보(원본에 대한 사실이 아님): ① 07 의 `src/driverkit/libDriver/Kernel/EventIO.m:196–206` `EventCoalesceDisplayCmd` 의 `coalesce[4][4]` 를 `EVNOP=0 … EVMOVE=3` 으로 풀면 위 16 B 와 같습니다(python: `equal True`). ② SDK `ev_types.h:165` `typedef enum {EVNOP, EVHIDE, EVSHOW, EVMOVE, EVLEVEL} EvCmd;`(명령 0–4, `EVLEVEL`=4). ③ `EventDriver.m:1361–1394` 의 `evDispatch:command:` 가 `EVMOVE`, `EVSHOW`, `EVHIDE`, `EVLEVEL` 순으로 `switch` 합니다. 이 셋은 x86 판 글(또는 SDK 머리)이며 m68k 원본의 소스가 아닙니다. 바이트 대조 없이 쓰지 않습니다.

코드 모양에 대한 관찰(가설): 원본의 `moveal a2@(28),a1; bras 0x406a8f0` 뒤 `moveal a2@(32),a1`, 그다음 공통 `tstl a1 … jsr a1@` 배치는 같은 꼬리를 가진 두 가지(`move`, `show`) 본문을 `jump.c` 의 교차 점프(cross-jump)가 하나로 합친 모양이거나 소스가 함수 포인터 변수를 먼저 정하는 모양일 수 있습니다. 어느 쪽인지는 컴파일해 봐야 압니다(⚠️ 교차 점프가 `-O2` 에서 켜지는지는 공개 GCC 2.7.2.3 `jump.c`·`toplev.c` 로 아직 확인하지 않음).

방법(07 변경 없음; 이 절의 코드는 진단 소스뿐):
1. 진단 소스 열하나(`08_build/artifacts/m4p734/src/evd_V0.c … V10.c`; 아래 §734.1 의 교차검토 뒤 아홉에서 고침), 모두 `<sys/types.h>`·`<bsd/dev/m68k/evio.h>`, `extern EvGlobals *evg; extern EvScreen *evScreen; extern int screens, evRetryMask;`, 정적 `static char evCoalesce[4][4]`(위 표; 비 `const` 라서 `__data`)와 `static int evBrightness`(`__bss`), `void evdispatch(EvCmd cmd, int screen, int arg)`, `void evretry(void)`. `EvScreen` 이 `volatile struct` 라서 `esp->move` 같은 함수 포인터 필드는 쓸 때마다 읽으므로, 원본처럼 한 번만 읽으려면 지역 변수에 담아 검사·호출해야 합니다(`proc`·`hproc`·`lproc`; 형은 필드와 같은 `int (*)(struct _evScreen *, Point, int)` 등). SDK 구조체의 함수 포인터 인수 형(`struct _evScreen *`)과 `esp` 형(`volatile`)이 달라 경고가 날 수 있으며 경고는 기록만 하고 판정에는 쓰지 않습니다.
   기준 B = `EvScreen *esp = &evScreen[screen]; int err = 0;` `if (cmd < EVLEVEL || esp->retry.cursor) { esp->retry.cursor = evCoalesce[esp->retry.cursor][cmd & 3]; switch (esp->retry.cursor) { case EVMOVE: proc = esp->move; if (proc) err = (*proc)(esp, evg->cursorLoc, evg->frame); break; case EVSHOW: (같은 꼴, esp->show); case EVHIDE: hproc = esp->hide; if (hproc) err = (*hproc)(esp); break; } if (!err) esp->retry.cursor = 0; }` 뒤 `if (cmd == EVLEVEL) evBrightness = arg; if (cmd == EVLEVEL || esp->retry.level) { lproc = esp->level; if (lproc) { esp->retry.level = (*lproc)(esp, evBrightness); err |= esp->retry.level; } }` 뒤 `{ int bit = 1 << screen; int mask = evRetryMask & ~bit; if (err) mask |= bit; evRetryMask = mask; }`, `evretry` 는 `unsigned i, m; for (i = 0, m = evRetryMask; m && i < screens; i++, m >>= 1) if (m & 1) evdispatch(EVNOP, i, 0);`.
   - V0 = 대조군: 기준에서 함수 포인터를 지역 변수에 담지 않고 `if (esp->move) err = (*esp->move)(…)` 꼴(필드를 두 번 읽음; 교차검토 전 V1 과 같음).
   - V1 = 기준 B.
   - V2 = B 의 마스크 갱신만 `evRetryMask &= ~(1 << screen); if (err) evRetryMask |= 1 << screen;`.
   - V3 = 마스크 갱신만 `if (err) evRetryMask |= 1 << screen; else evRetryMask &= ~(1 << screen);`.
   - V4 = `move`·`show` 를 포인터 변수 `proc` 하나로 정해 한 곳에서 호출(`case EVMOVE: proc = esp->move; goto call; case EVSHOW: proc = esp->show; call: if (proc) err = …; break;`).
   - V5 = 레벨 분기를 원본 순서 그대로 `if (cmd == EVLEVEL) evBrightness = arg; else if (!esp->retry.level) goto done;` 로 쓰고 호출 덩어리 뒤에 `done:` 를 둠(교차검토 제안).
   - V6 = `evretry` 만 `while` 꼴(`i = 0; m = evRetryMask; while (m && i < screens) { …; i++; m >>= 1; }`).
   - V7 = 마스크 갱신만 `int bit = 1 << screen; evRetryMask = (evRetryMask & ~bit) | (err ? bit : 0);`.
   - V8 = 화면 포인터만 `esp = (EvScreen *)(screen * sizeof(EvScreen) + (int)evScreen);`(§730 T2 꼴).
   - V9 = 화면 포인터만 `esp = evScreen + screen;`.
   - V10 = 레벨 덩어리만 `if (cmd == EVLEVEL || esp->retry.level) { if (cmd == EVLEVEL) evBrightness = arg; … }`.
2. 실기 run `m4p734-p1`(base `08_build/runs/tools/m0p689-a1-stage`, 컴파일 줄 `08_build/artifacts/m5p494/final.cmd`, 객체 이름 `evdisp`, 범위 [0x406a86a, 0x406a9d4), 행 `m68k-217`·`m68k-218`), 명세 `08_build/artifacts/m4p734/spec.p1.json`. 먼저 REGISTRY 에 `m4p734-p1` 이 없음을 python 으로 확인합니다.
3. 각 변형에 `m68k_funcbytes.py 0x406a86a 0x406a9d4 <객체> <기록> 0x40b127c=_evCoalesce 0x40b4fb2=_evBrightness` 를 돌려 두 함수의 바이트·재배치 대상 일치를 보고, 일치하지 않으면 정규화 difflib(`scratch/p734/cmpfn.py`; `cmpmove.py` 를 두 함수에 맞게 일반화한 것)로 어느 구간이 다른지 가릅니다. `__data` 16 B 와 `__bss` 4 B 가 원본과 같은지도 봅니다.
4. 판정(미리 정함): 한 변형이라도 두 함수가 `funcbytes` 에서 모두 같고(362 B), `__data` 가 원본 16 B 와 바이트별로 같고, `__bss` 가 4 B 이면 이 단독 진단은 성공입니다. 이는 소스가 원본이라는 증거가 아니라 조건부 일치이며 구현 선택은 §693 에 따라 사용자께 여쭙습니다. 일치하는 변형이 없으면 차이 구간으로 가설을 다시 세우고 새 계획으로 이어 가며, 기준을 낮추지 않습니다.

모르는 것: 함수 인수 `cmd` 의 형(부호 없는 비교가 나오므로 `EvCmd` 나 `unsigned`), 같은 번역 단위의 앞선 `extern void evdispatch(int, int, int)` 선언과 정의 사이의 형 충돌(통합 단계에서 다룸), `evretry` 의 `i`·`m` 의 정확한 형, `evBrightness`·`evCoalesce` 의 원래 이름(원본에 없음; 사용자 결정).

### 734.1 §734 codex 교차검토(`gpt-6.1-sol`) 판정 (코딩 전, 2026-11-05)

먼저 제 잘못: (1) 계획의 아홉 변형이 모두 `if (esp->level)` 과 `(*esp->level)(…)` 로 `volatile` 함수 포인터 필드를 두 번 읽어, 원본이 `a1` 에 한 번 적재해 검사·호출하는 모양과 처음부터 맞지 않았습니다(`move`·`show`·`hide` 도 같음). (2) `lea` 피연산자를 `a3@(a3*4)` 로 옮겨 적었습니다(실제 `a3@(0,d4:l:4)`). (3) 계획을 쓸 때 "소스 0 건" 이라고 썼던 grep 은 대소문자를 가리지 않은 결과를 잘못 읽은 것이었고, 코덱스에 보내기 전에 고쳤습니다(위 본문).

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 함수 포인터 필드가 `volatile` 이라 두 번 읽고, 원본은 `a1` 을 한 번 적재 후 검사·호출 | `evio.h:109–119`(`typedef volatile struct _evScreen`), `original-objdump.txt:758–763`(`moveal a2@(36),a1; tstl a1; beqs; …; jsr a1@`) 을 열음. 계획 본문의 V1–V9 가 모두 필드를 두 번 읽는 표기임도 확인 | ✅ 채택: 지역 변수로 캐시하는 기준 B, 필드 두 번 읽기는 대조군 V0 |
| `cse.c:1942–1946` 가 volatile MEM 을 CSE 에 기록하지 않음 | `cse.c:1942–1946` 을 열음(`canon_hash` 안, `MEM_VOLATILE_P (x)` → `do_not_record = 1`) | ✅ 줄은 맞음(GCC 2.7.2.3 공개 사본; 컴파일러 실측은 아님) |
| `jump.c:2469–2470` 의 교차 점프가 명령 패턴 일치를 요구 | `jump.c:2469–2470` 을 열음(`find_cross_jump`, 2371 에서 시작, `rtx_renumbered_equal_p`) | ✅ 줄은 맞음 |
| 레벨 분기는 `cmd == 4` 이면 저장하고 합류하며 그 외에만 `retry.level` 을 검사, 이를 `else if` 로 쓰는 후보 | `original-objdump.txt:750–758` 을 열음 | ✅ V5 로 채택(추정 부분은 실측으로 가름), V1·V10 의 반복 검사 꼴도 유지 |
| `lea` 피연산자는 `a3@(0,d4:l:4)` | `original-objdump.txt:688` 을 열음 | ✅ 위 본문을 고침 |
| (EvScreen 오프셋·`EvRetry` 비트 위치) 지적 없음 | 제가 python 으로 20/24/28/32/36·마스크 0x80/0x60 을 다시 계산하고 `evio.h`·`EvGlobals` 에서 `cursorLoc` 24, `frame` 28 을 확인 | ✅ |

2 차 자기검사: ✅ 행은 이번 세션에 연 줄이거나 제가 돌린 python 입니다. 코덱스가 말한 "교차 점프로 합쳐질 수 있다"는 추정이며 NeXT 컴파일러 실측 전에는 사실이 아닙니다.

### 734.2 p1 결과와 W 묶음 계획 (run `m4p734-p1`, 2026-11-05; 07 변경 없음)

결과(`scratch/p734/cmpfn.py` 정규화 difflib, 주소 마스크; 함수 기록 `m4-m68k-funcbytes-p734-{V0,V1}-20261105.json`, probe 기록 `m4-m68k-probe-p734-p1-20261105.json`; 컴파일 11 개 모두 rc 0):
- **`evretry` 66 B 는 V0–V10 모두 SAME**(`funcbytes`: V0·V1 에서 확인; `for`/`while` 두 꼴은 같은 코드: V5 와 V6 의 `canon` 이 같음).
- V0(대조군, 필드를 두 번 읽음)은 `evdispatch` 324 B 로 크게 다릅니다(`moveml` 에 `a3` 없음 등, 정규화 차이 구간 11). 교차검토 지적이 실측으로도 맞았습니다.
- **V1(기준 B)은 `evdispatch` 296 B(원본과 같은 길이), 두 함수 합 362 B 를 objdump 한 줄 수가 125(원본과 같음; 이 수는 폭 때문에 나뉜 주소 바이트 줄을 한 줄 포함하며, 실제 명령은 `evdispatch` 100 + `evretry` 24 = 124 — §734.3), `__data` 16 B 가 원본 `00010203010100020200020203010203` 과 같고 `__bss` 4 B**입니다. 정규화 차이 구간은 여섯이고 그 가운데 둘은 절대 주소 필드(`addal #…`, 정적 `0x40b4fb2` 의 위치 주소; 이 마스크가 못 가리는 재배치 자리)입니다. 진짜 차이는 `hide`(`a2@(24)`)와 `level`(`a2@(36)`) 함수 포인터를 담는 주소 레지스터뿐입니다: 원본 `a1`, 후보 `a0`. `move`·`show` 의 공통 꼬리(`moveal a2@(28),a1; bras …; moveal a2@(32),a1; tstl a1 …`)와 `lea` 로 만든 화면 주소, 표 색인, 마스크 갱신 `moveq #1,d0; movel d0,d1; asll d4,d1; movel d1,d0; notl d0; andl mem,d0; … orl d1,d0; movel d0,mem` 은 V1 에서 이미 원본과 같습니다. `funcbytes` 의 `evdispatch` 는 `bytes 6 refs 0`(바이트 6 B 차이, 재배치 대상은 같음).
- 변형별: 마스크 갱신 V2(두 문장)는 +6 B, V3(if/else)는 −2 B, V7(삼항)은 +6 B 로 맞지 않고 M1(지역 `mask`)만 맞습니다. 화면 포인터 V8(T2 꼴)·V9(`evScreen + screen`)은 `clrl %d2` 의 위치가 달라집니다(V8 과 V9 는 서로 같은 코드). 레벨 분기 V10(중첩 `cmd == EVLEVEL`)은 분기 모양이 달라지고, V5(`else if … goto done`)는 V1 과 같은 코드입니다. `move`·`show` 를 `goto` 로 합친 V4 도 V1 과 같은 코드입니다(교차 점프로 합쳐지는지 소스가 합치는지 이 실험으로는 가려지지 않음). 컴파일 경고: `passing arg 1 discards 'volatile' from pointer target type` 이 호출 넷에 각각(V0 제외 대부분 4 개). 그래서 probe 기록의 `diag_gate.commands_ok` 는 false 입니다(관문이 경고 0 을 요구; 기대한 결과이며 판정에 쓰지 않음). `canon` 비교: V1 = V4 = V5 = V6 (같은 코드), V1 대 V10·V2·V3·V7·V8·V9 는 다름(probe 기록의 쌍 목록).

해석(가설 H20): 원본은 `hide`·`move`·`show`·`level` 네 호출 모두 같은 주소 레지스터 `a1` 을 쓰므로 함수 포인터를 하나의 지역 변수에 담아 네 곳에서 쓴 것일 수 있습니다. V1 은 `proc`(`move`·`show` 용)과 `hproc`·`lproc` 을 따로 두어, `proc` 만 `evg` 포인터(`a0`)와 겹쳐 `a1` 을 받고 나머지는 `a0` 이 됩니다. 인수 개수가 서로 다른 네 호출을 한 변수로 부르는 한 방법은 원형 없는 함수 포인터 `int (*proc)();` 이고(유일한 방법은 아님 — §734.3), 그러면 호출 인수의 원형 대조가 없어져 위 경고도 사라집니다(§734.3 의 줄 근거).

묶음(진단; 같은 기준 B, 바꾸는 곳만):
- W1 = `proc`·`hproc`·`lproc` 대신 `int (*proc)();` 하나로 네 곳(`move`, `show`, `hide`, `level`)을 `proc = esp->…; if (proc) err = (*proc)(…)` 꼴로. 레벨은 `proc = esp->level; if (proc) { esp->retry.level = (*proc)(esp, evBrightness); err |= esp->retry.level; }`.
- W2 = W1 + 레벨 분기 V5 꼴(`else if (!esp->retry.level) goto done;`).
- W3 = 변수를 따로 두되 모두 원형 없는 `int (*proc)(); int (*hproc)(); int (*lproc)();`(경고가 없어지는지, 변수 하나라는 가설과 원형 없음을 가름).
판정(미리 정함): 한 변형이라도 `evdispatch` 296 B·`evretry` 66 B 가 `funcbytes` 에서 둘 다 SAME 이고 `__data`·`__bss` 가 원본과 같으면 단독 진단 성공(조건부)입니다. 아니면 남은 차이로 새 가설을 세우며 기준을 낮추지 않습니다. 새 run `m4p734-p2`(REGISTRY 부재를 python 으로 확인).

### 734.3 §734.2 codex 교차검토(`gpt-6.1-sol`) 판정과 W 묶음 수정 (코딩 전, 2026-11-05)

먼저 제 잘못: (1) §734.2 가 "125 명령(evdispatch)"이라고 썼으나 125 는 두 함수 합이고 폭 때문에 나뉜 주소 바이트 줄 하나를 포함합니다. python 으로 `objdump -w` 를 함수 경계에서 나눠 세면 `evdispatch` 100, `evretry` 24, 합 124 입니다(위 본문을 고침). (2) "원형 없는 함수 포인터여야 한다"는 과한 단정이었습니다.

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 125 는 두 함수 합이고 연속 바이트 줄 포함, 실제 evdispatch 100 / evretry 24 | python `objdump -w` 를 [0x406a86a,0x406a992)·[0x406a992,0x406a9d4) 로 나눠 셈: 100, 24, 합 124 | ✅ 위 본문 수정 |
| 비교 여섯 구간은 주소 둘(addal, 4fb2/017a)과 hide·level 의 a1→a0 넷 | 제가 `cmpfn.py` 출력(V1)에서 같은 여섯을 이미 확인 | ✅ |
| 레지스터 배정 근거: local-alloc 은 live 구간의 사용 레지스터를 합쳐 제외(`local-alloc.c:2101–2111`, 선택 2158–2176), global 은 hard reg 충돌 제외와 다른 pseudo 선호 회피(`global.c:937–950`), 한 pseudo 의 분리된 live range 충돌 누적(`global.c:1254–1256`) | 네 구간을 열음(2101–2111 `used` 합산, 2158–2176 `reg_alloc_order` 순회, global.c 937–950 `hard_reg_conflicts`·선호 회피 주석, 1252–1257 `hard_reg_conflicts[ialloc]` 누적) | ✅ 줄은 맞음. 다만 V1 의 실제 배정 원인까지 증명하는 근거는 없음(codex 도 인정) → H20 은 "설명 가능한 가설" |
| "원형 없는 포인터여야 한다"는 과함; 원형 있는 `EvMoveProc proc` 하나에 캐스트로 담아 쓸 수 있음(`expr.c:5118–5130` 같은 모드 변환은 값을 그대로 돌려줌) | `expr.c:5118–5130` 을 열음(`mode == TYPE_MODE(...)` 이면 `op0` 반환) | ✅ 줄은 맞음 → 변형 W4 로 채택(변수 하나와 원형 제거를 분리해 시험) |
| 원형이 없으면 `type == 0` 이라 `convert_for_assignment` 대신 기본 승격(`c-typeck.c:1544–1548`, `1617`, `1642`, `1736–1756`), volatile 경고는 대입 변환 안(`4123–4131`) | 1542–1549(`convert_arguments (TYPE_ARG_TYPES (fntype)…`), 1612–1618(`type = typetail ? … : 0`), 1734–1740 을 열음; 4123–4131 은 앞서 4054–4058 근처와 4127–4130 의 경고 문구를 grep 으로 확인 | ✅ 줄은 맞음. 표현을 "호출 인수의 원형 대조가 없어진다"로 한정(`require_complete_type` 등은 남음) |
| 비 `volatile` 구조체 경유 직접 호출 후보: 필드 `volatile` 은 구조체에서 전파(`c-typeck.c:1288–1293`), volatile MEM 은 CSE 에서 제외(`cse.c:1942–1951`) | 1286–1294 를 열어 `TREE_THIS_VOLATILE (datum)` → `ref` 확인; cse.c 1942–1946 은 앞서 열음 | ✅ 변형 W5 로 채택(`a1` 배정으로 이어질지는 추측) |
| 선언 순서·호출 결과 변수는 약한 후보, 결과 변수는 근거 없음 | `stmt.c`·`global.c:605–607`·`calls.c:2031–2039`·`m68k.h:787–790` 은 열지 않음 | ⚠️ 줄 인용은 옮기지 않음; 선언 순서만 약한 후보 W6 로 시험(근거 없이 실측용) |

2 차 자기검사: ✅ 행은 이번 세션에 연 줄 또는 제가 돌린 python 입니다. ⚠️ 행의 줄은 계획에 인용하지 않았습니다.

W 묶음(기준 B, 바꾸는 곳만; 모두 `diag only`): W1 = 네 호출 모두 `int (*proc)();` 하나. W2 = W1 + 레벨 분기 V5 꼴. W3 = 변수 셋을 따로 두되 모두 원형 없는 `int (*proc)(); int (*hproc)(); int (*lproc)();`. W4 = 원형 있는 `EvMoveProc proc;` 하나에 `proc = (EvMoveProc)esp->hide;` 처럼 캐스트로 담고 `err = ((EvHideProc)proc)(esp);` 로 되돌려 부름(레벨도 `EvLevelProc` 캐스트). W5 = 지역 함수 포인터 없이 비 `volatile` 구조체로 형 변환해 검사·호출(`if (((struct _evScreen *)esp)->hide) err = (*((struct _evScreen *)esp)->hide)(esp);` 꼴, 네 곳 모두). W6 = V1 에서 `EvLevelProc lproc; EvHideProc hproc; EvMoveProc proc;` 순서로 선언만 뒤집음. 판정은 §734.2 와 같습니다(미리 정함; 기준을 낮추지 않음). run `m4p734-p2`.

### 734.4 W 묶음 결과: `evdispatch`·`evretry` 단독 진단 성공 (run `m4p734-p2`, 2026-11-05; 07 변경 없음)

결과(함수 기록 `09_validation/reconstruction/m4-m68k-funcbytes-p734-{W1…W6}-20261105.json`, probe 기록 `m4-m68k-probe-p734-p2-20261105.json`; 임시 앵커 `0x40b127c=_evCoalesce`, `0x40b4fb2=_evBrightness`; 컴파일 6 개 모두 rc 0):
- **W1·W2·W4 는 `funcbytes` 2/2 SAME**(`evdispatch` 296 B, `evretry` 66 B, 바이트와 재배치 대상 모두 같음), `__text` 362 B, `__data` 16 B 가 원본 `00010203010100020200020203010203` 과 바이트별로 같고 `__bss` 4 B. 정규화 비교의 차이 구간은 주소 필드 둘뿐입니다. W1 = W2 = W4 의 `canon` 이 같습니다.
- W3(변수 셋을 따로 두되 모두 원형 없음), W5(비 `volatile` 구조체로 형 변환해 직접 호출), W6(선언 순서만 뒤집음)은 `evdispatch` 가 6 B 다릅니다(`hide`·`level` 의 `a1` 대 `a0`). 그러므로 가설 H20 이 이 실험에서 지지됩니다: 네 호출이 **같은 하나의 함수 포인터 변수**를 쓰면 원본의 `a1` 이 나오고, 원형 유무는 영향이 없습니다(W4 는 원형 있는 `EvMoveProc` 하나에 캐스트). 레지스터 배정의 정확한 원인(`local-alloc.c`·`global.c` 의 어느 단계인지)은 이 실험으로는 가리지 않았습니다.
- 컴파일 경고: W1·W2·W3 는 0 개, W4·W5·W6 은 `passing arg 1 discards 'volatile' …` 4 개씩(원형이 있는 포인터 호출). 원형 없는 `int (*proc)();` 에서 경고가 없는 것은 §734.3 의 줄 근거와 맞습니다. (`diag_gate.commands_ok` 는 W4–W6 의 경고 때문에 false 이며 판정에 쓰지 않음.)

바이트로 가려지지 않는 선택(§693 에 따라 구현 단계에서 사용자께 여쭈어야 함): ① 함수 포인터 변수가 `int (*proc)();`(W1) 인지 원형 있는 포인터 하나에 캐스트(W4)인지 — 같은 바이트, 경고 0 대 4. ② 레벨 분기 표기(W1 의 반복 검사 대 W2 의 `else if … goto done`) — 같은 바이트. ③ `move`·`show` 를 따로 쓰기(V1)와 `goto` 로 합치기(V4)는 같은 코드(V1 = V4 `canon`). ④ `evretry` 의 `for` 대 `while`(V1 = V6 `canon`). ⑤ 인수 `cmd` 의 형(`EvCmd` 로 부호 없는 비교가 나왔고, 같은 번역 단위의 앞선 `extern void evdispatch(int, int, int)` 선언과의 충돌은 통합에서 다룸). ⑥ 정적 이름 `evCoalesce`·`evBrightness`(원본에 이름 없음). 마스크 갱신은 지역 `mask` 를 쓰는 꼴(M1)만 맞았고(`evRetryMask &=`/`|=` 두 문장은 +6 B, if/else 는 −2 B, 삼항은 +6 B), 화면 포인터는 `&evScreen[screen]` 꼴(P0)만 맞았습니다(T2 꼴·`evScreen + screen` 은 `clrl %d2` 위치가 다름). 이 선택들은 원본 소스의 증거가 아닙니다.

이것은 단독 진단 성공(조건부)이며 수락이 아닙니다. 남은 일: ① 이름 없는 함수 둘(0x406a9d4 56 B, 0x406aa0c 100 B)을 같은 번역 단위에 편입, ② 통합 TU(I1 + `evdispatch`·`evretry` + 이름 없는 둘)를 [0x4069eb8, 0x406aa70) 3000 B 로 14 → 18 함수 일치(표 16 B 는 `__data` 28 B 뒤, 정적 4 B 는 `ev_adb_mouse` 앞), ③ 헤더 COMMON, ④ 사용자 확인(§693 과 위 ①–⑥). 앞의 이름 없는 둘은 §697·§700 에서 단독 진단했으나 통합 컴파일은 아직 없습니다.

## 735. M4-202 세부 계획 — m68k `ev_mouse` 단위의 통합 TU I2: 14 함수 + `evdispatch`·`evretry` + 이름 없는 보조 함수 둘 = 18 함수 (07 변경 없음; 코딩 전, 2026-11-05)

고른 까닭: §733 의 I1(14 함수)과 §734 의 W1(`evdispatch`·`evretry`), §697 의 A(`ev_wait_frame`)·§700 의 B(`ev_point_to_screen`)가 각각 단독으로 원본과 같습니다. 이제 한 번역 단위로 합쳐도 같은지 확인합니다. 합치면 새로 생기는 문제는 (1) 자료 배치(표 16 B 가 `__data` 28 B 바로 뒤, 정적 4 B 가 `ev_adb_mouse` 앞), (2) `evdispatch` 의 형(앞선 `extern void evdispatch(int, int, int)` 선언과 `EvCmd` 정의의 충돌), (3) 이름 없는 보조 함수 둘이 `static` 인지 외부 함수인지입니다.

사실(python 으로 원본 함수 표 `06_reconstruction/m68k-functions.tsv` 와 objdump 확인):
- [0x4069eb8, 0x406aa70) 에 함수 18 개, 크기 합 3000 B 입니다. 순서(주소순)는 `MoveTheCursor` 536, 460, 248, 54, 26, 38, 148(`evsetup_screens`), 132, 120, 206, 320, 34, 28, 132, `evdispatch` 296, `evretry` 66, 이름 없는 56, 이름 없는 100 입니다.
- 이름 없는 둘로 가는 호출은 모두 `bsrl`(6 B, 32 비트 변위)입니다: `bsrl 0x406aa0c` 둘(0x4069f12, 0x406a7fe), `bsrl 0x406a9d4` 셋(0x406a3a8, 0x406a3da, 0x406a3f6)(`scratch/p690/original-objdump.txt` 30·365·379·388·654행). `evdispatch` 로 가는 호출도 `bsrl` 이고 그 함수는 외부 심볼입니다. 이름 없는 둘이 `static` 이면 짧은 분기가 나올 것이라는 처음 가정은 근거가 없었고 §735.1 에서 반증되었습니다(수락된 `fd_cmds.c` 의 `static` 함수 호출도 원본에서 `bsrl` 입니다). 그래서 `static` 여부는 호출 바이트로 가려지지 않을 수 있고, I2a·I2b 는 같은 바이트가 나올 것으로 예상합니다. 원본 심볼 표에 두 이름이 없는 것은 외부 이름이 strip 되었거나 `static` 이기 때문일 수 있고 바이트로는 구별되지 않을 수 있습니다.
- 원본 `__data` 는 [0x40b1260, 0x40b1260+28+16) 44 B(앞 28 B + 표 16 B), `__bss` 는 0x40b4fb2 와 0x40b4fb6 에 4 B 씩 총 8 B 입니다.

방법(07 변경 없음):
1. 소스 `08_build/artifacts/m4p735/src/evmouse_I2a.c`·`evmouse_I2b.c` 를 §733.4 의 `evmouse_I1.c` 에서 python 으로 만듭니다. 공통 변경: ① 맨 앞 정적 자료 정의를 `ev_init_num`, `ev_init_thresholds`, `ev_init_factors`, `ev_shmem_cursor`, `evCoalesce`(표; §734 의 정의), `evBrightness`(`static int`), `ev_adb_mouse` 순서로(초기값이 있는 정적은 정의 순서대로 `__data` — `ev_shmem_cursor = 0` 도 `__data`, 초기값이 없는 정적은 정의 순서대로 `__bss`). ② `evdispatch` 선언을 모두 `extern void evdispatch(EvCmd, int, int)` 로 바꿈(앞선 호출의 정수 상수 인수는 그대로). ③ 끝에 §734 W1 의 `evdispatch`·`evretry`, §697 A 의 `ev_wait_frame`, §700 B 의 `ev_point_to_screen` 을 이 순서로 덧붙임(`evRetryMask` 는 `extern int`). I2a = 이름 없는 둘을 외부 함수로(선언 `extern`, 정의에 `static` 없음). I2b = 이름 없는 둘을 `static` 으로(앞 선언·정의 모두 `static`).
2. 실기 run `m4p735-p1`(base `08_build/runs/tools/m0p689-a1-stage`, 컴파일 줄 `08_build/artifacts/m5p494/final.cmd`, 객체 이름 `evmouse3`, 범위 [0x4069eb8, 0x406aa70), 행 `m68k-216`·`m68k-217`, 부분 행 `m68k-218`·`m68k-219`; `span()` 이 겹침을 검사). REGISTRY 부재를 python 으로 먼저 확인합니다.
3. 판정은 `m68k_funcbytes.py 0x4069eb8 0x406aa70 <객체> <기록> <앵커…>` 의 18/18 SAME(I2a: 이름 없는 둘에 `0x406a9d4=_ev_wait_frame`, `0x406aa0c=_ev_point_to_screen`; I2b 의 `static` 함수도 같은 두 앵커를 넘김: 객체의 비 외부 `__text` 심볼도 이름으로 짝지어지나 매핑이 없으면 `object=None`), `__text` 3000 B, `__data` 44 B 와 `__bss` 8 B 가 원본과 같음(앵커 `0x40b1260=_ev_init_num`, `0x40b1264=_ev_init_thresholds`, `0x40b126e=_ev_init_factors`, `0x40b1278=_ev_shmem_cursor`, `0x40b127c=_evCoalesce`, `0x40b4fb2=_evBrightness`, `0x40b4fb6=_ev_adb_mouse`), COMMON 0, 원본 기호표에 없는 미정의 이름 0. 크기 합만으로는 순서를 못 가르므로 python 으로 객체 심볼 표를 읽어 절 안 오프셋을 직접 검사합니다: `__data` 의 `ev_init_num` +0, `ev_init_thresholds` +4, `ev_init_factors` +14, `ev_shmem_cursor` +24, `evCoalesce` +28; `__bss` 의 `evBrightness` +0, `ev_adb_mouse` +4(원본 0x40b4fb2·0x40b4fb6 의 차이 4 와 같아야 함; 원본 `__bss` 는 파일 바이트가 없어 값은 비교하지 않음). 합친 소스는 만든 뒤 python 으로 `evdispatch(int, int, int)` 형 선언이 남아 있지 않은지 전수 검사합니다(§697 A 원문에도 그 선언이 있음).
4. 판정(미리 정함): 두 변형 중 하나라도 위가 모두 성립하면 통합 진단 성공(조건부; 수락 아님)입니다. 둘 다 안 되면 차이 구간으로 가설을 세워 새 계획으로 이어 가며 기준을 낮추지 않습니다. 구현 선택(§693, §734.4 ①–⑥, 그리고 이름 없는 둘의 `static` 여부)은 구현 단계에서 사용자께 여쭙니다.


### 735.1 §735 codex 교차검토(`gpt-6.1-sol`) 판정 (코딩 전, 2026-11-05)

먼저 제 잘못: (1) "영 초기화 정적은 `__bss`" 라고 썼으나 이 저장소의 NeXT cc 는 `static T x = 0;` 을 `__data` 에 둡니다(`ev_shmem_cursor` 가 `__data` +24 에 있는 I1 이 증거; 앞서 이미 알던 사실이었음). 초기값이 없는 정적만 `__bss` 입니다. (2) I2b 의 `static` 함수에도 이름 매핑이 필요한데 빠뜨렸습니다. (3) `static` 이면 짧은 분기가 나온다는 가정은 근거 없이 쓴 추측이었습니다.

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| `funcbytes` 는 비외부 `__text` 심볼도 수집하고 이름으로 짝지으며, 이름 없는 원본 항목은 `ADDR=NAME` 으로만 이름을 얻고, 매핑이 없으면 `object=None` | `m68k_funcbytes.py:148–153`(tsyms 수집), `176–188`(`n not in objnames` → `row['object'] = None`), 앞서 `113–116` 을 열음 | ✅ 위 3 단계에 I2b 앵커 반영 |
| `m68k.md:5935–5952` 의 비 PIC 호출은 static 을 구분하지 않음 | 5935–5952 를 열음(`jbsr %0`) | ✅ |
| 수락된 `fd_cmds` 에서 static `fc_wait_intr` 호출이 원본에서도 `bsrl` | `fd_cmds.c:53`(`static fd_return_t fc_wait_intr`), `185`(호출)을 열고, 원본 `0x406ad28` 의 6 바이트를 python 으로 읽음: `61 ff 00 00 06 60` | ✅ (그 호출이 정확히 0x406ad28 인지는 이 검증에서 대응 확인하지 않음 → 근거는 "static 호출도 `bsrl` 인 사례가 있다"로 한정) |
| `ev_shmem_cursor = 0` 은 `__data` | I1 객체와 `evmouse_I1.c:58` 은 앞서 §733.4 에서 `__data` 28 B 가 원본과 같다고 확인한 사실과 일치 | ✅ 위 본문 고침 |
| 이름별 앵커 비교는 변수 배치를 보증하지 않으니 절 안 오프셋을 직접 검사하고 `__bss` 순서(`evBrightness` +0, `ev_adb_mouse` +4)를 확인 | 동의; 원본 `__bss` 는 `macho.json` 에서 `file_offset` 0 | ✅ 3 단계에 반영 |
| ③ 에서 §697 A 원문을 붙이면 `evdispatch(int, int, int)` 선언 충돌이 재발 | `helper_A.c:5` 를 열음(`extern void evdispatch(int, int, int);`) | ✅ 합친 소스 전수 검사를 3 단계에 추가 |

2 차 자기검사: ✅ 행은 이번 세션에 연 줄이거나 제가 돌린 python 입니다. `fd_cmds` 호출의 정확한 주소 대응은 확인하지 않았음을 표에 적었습니다.

### 735.2 결과: 통합 TU 18/18 SAME (run `m4p735-p1`, 2026-11-05; 07 변경 없음)

결과(컴파일 rc 0·경고 0·stderr 0 B; 함수 기록 `m4-m68k-funcbytes-p735-{IA,IB}-20261105.json`, probe 기록 `m4-m68k-probe-p735-p1-20261105.json`, 독립 검사 기록 `m4-m68k-p735-checks-20261105.json`; 변형 이름은 probe 규칙(`^[A-Z][A-Z0-9]*$`) 때문에 I2a → `IA`, I2b → `IB`):
- **두 변형 모두 `funcbytes` 18/18 SAME**(바이트와 재배치 대상), object-only 없음. `__text` 3000 B = 원본 18 함수 합.
- `__data` 44 B 가 원본 [0x40b1260, +44) 와 바이트별로 같고, `__bss` 8 B. python 으로 읽은 절 안 오프셋: `__data` 의 `ev_init_num` +0, `ev_init_thresholds` +4, `ev_init_factors` +14, `ev_shmem_cursor` +24, `evCoalesce` +28, `__bss` 의 `evBrightness` +0, `ev_adb_mouse` +4 가 기대와 같음(원본 `__bss` 는 파일 바이트가 없어 값은 비교하지 않음).
- 미정의 41 개가 모두 원본 기호표에 있고(원본에 없는 이름 0), COMMON(값이 0 이 아닌 미정의) 0.
- IA(보조 함수 둘 외부): 외부 정의 18, probe 의 `extra_names` 는 `_ev_point_to_screen`·`_ev_wait_frame`(원본 기호표에 없는 이름) → `judgement: no`, `full_span: false`. **IB(보조 함수 둘 `static`): 외부 정의 16, `extra_names` 없음, `full_span: true`, `judgement: provisional`**(`l1_reasons` 는 `__bss` 미검증뿐). IA 와 IB 의 `canon` 이 같습니다(바이트 같음).
- 해석: 원본 기호표에 이 두 이름이 없다는 사실과 합치려면 두 함수는 `static`(IB)이라고 보는 쪽이 설명이 간단합니다(외부 이름이었다면 strip 되었어야 함). 다만 호출 바이트는 같아(§735.1) 바이트만으로는 가려지지 않으므로 구현 선택으로 사용자께 여쭙습니다.

제 잘못 하나: 명세의 `m4_id` 를 처음에 `rows` 216·217 / `partial` 218·219 로 적었다가 probe 의 `span()` 검사(행 218 은 범위 안에 통째로 있음)가 거부해, run 뒤에 `rows` 216·217·218 / `partial` 219 로 고쳤습니다. 컴파일 명령은 `m4_id` 에 의존하지 않습니다(고치기 전 명세는 `scratch/` 에 보관).

이것은 통합 진단 성공(조건부)이며 수락이 아닙니다. 다음 단계(수락 쪽): ① 사용자 결정(§693 의 T2 꼴·`(void)&p;`·`es` 지역 변수·정적 이름·모양, §734.4 ①–⑥, 이름 없는 둘의 `static`), ② 07 `src/machdep/m68k/ev_mouse.c` 구현 계획(범위 [0x4069eb8, 0x406aa70), 행 216·217·218 + 부분 행 219, 출처·고지·헤더 COMMON·known_warnings 처리), ③ 단위 수락 절차(stage, 검사, 상태표).

## 736. M4-203 구현 계획 — 07 `src/machdep/m68k/ev_mouse.c`(명시 구간 [0x4069eb8, 0x406aa70) 3000 B, 함수 18, 행 216·217·218 + 부분 행 219; 코딩 전, 2026-11-05)

고른 까닭: §735 로 통합 진단 18/18 SAME(`__text` 3000 B, `__data` 44 B, `__bss` 8 B)이 나왔고, 바이트로 가려지지 않는 선택을 사용자께 여쭈어 확정했습니다(2026-11-05; D165 로 적을 것):
- 함수 포인터는 원형 없는 `int (*proc)();` 하나(경고 0).
- 이름 없는 보조 함수 둘은 `static`(`static void ev_wait_frame(int)`, `static int ev_point_to_screen(Point)`).
- 정적 자료의 이름: 원본 `__data` 앞 28 B 는 NeXTMach `ev_mouse.c:98–100` 의 `initNumMouseScales`·`initMouseScaleThresholds`·`initMouseScaleFactors` 와 값·순서가 같고(python: 5, {2,3,4,5,6}, {2,4,6,8,10}, 뒤 4 B 0 의 28 B 와 바이트 일치) 그 이름을 씁니다. NeXTMach 에 없는 나머지는 진단 이름입니다: 0 포인터 정적 `ev_shmem_cursor`, ADB 마우스 플래그 `ev_adb_mouse`(`__bss`), 표 `evCoalesce`(`__data`, 16 B), 밝기 `evBrightness`(`__bss`, 4 B), 보조 함수 `ev_wait_frame`·`ev_point_to_screen`. (처음 질문이 이 세 정적을 "§731 에서 정한 이름"이라고 잘못 소개해 다시 여쭈었습니다.)
- `evdispatch` 의 첫 인수는 `EvCmd`(SDK `ev_types.h:165`), 레벨은 `if (cmd == EVLEVEL) …; if (cmd == EVLEVEL || esp->retry.level) …`, `move`·`show` 는 case 를 따로, `evretry` 는 `for`.
- 바이트가 강제하는 세 표기를 그대로 씀: `evsetup_screens` 의 정수 덧셈 오프셋 먼저 `(EvScreen *)(screenIndex * sizeof (EvScreen) + (int)evScreen)`, `MoveTheCursor` 의 첫 문장 `(void)&p;` 와 `if (!screens) return;` 뒤 `es = evScreen;`, `*(int *)&p == *(int *)&evg->cursorLoc`(원본 소스의 증거가 아님, 주석에 이유를 적음).

기반과 출처(결정 D013·D024·D104·D158 의 방식, §729 `ev_kbd.c` 와 같음): NeXTMach `mk-108.1/nextdev/ev_mouse.c`(585 행)의 머리 고지와 수정 목록을 그대로 두고, 1997 바이트가 정하는 바뀜을 넣습니다. 바이트에서 읽은 사실(§734–735 와 §690–722): 18 함수 중 NeXTMach 에 이름이 있는 것은 `process_mouse_event`·`mouse_motion`·`showWaitCursor`·`hideWaitCursor`·`animateWaitCursor`(1997 은 대문자 시작)·`ev_register_screen`·`ev_unregister_screen`·`InitMouseVars`·`InitMouse`·`TermMouse`·`ResetMouse`·`StartCursor` 열둘이고(python 토큰 유사도 0.19–0.88 로 1997 본문은 모두 다름), `MoveTheCursor`·`evsetup_screens`·`evdispatch`·`evretry`·`ev_wait_frame`·`ev_point_to_screen` 여섯은 새 함수입니다. NeXTMach 에만 있는 `HideCursor`·`ShowCursor`·`ObscureCursor`·`RevealCursor`·`ShieldCursor`·`UnShieldCursor`·`SetMouseMoved`·`ClearMouseRect`·`SetMouseRect`·`touchBounds`·`offsetBounds`·`boundBounds`·`SetCursor` 와 커서 그림 자료(`arrowData` 등)는 1997 단위에 없고 원본 기호표에도 없습니다(python 으로 `symbols.tsv` 를 이름별로 확인; 정적일 수 있으므로 "단위 [0x4069eb8, 0x406aa70) 에 없다"가 정확한 주장이고 다른 객체에 있는지는 이 계획이 가리지 않음). 그 줄들은 지우고 지운 자리에 `NeXTMach line(s) N removed` 표시를 둡니다.

방법(§729 의 순서):
1. 진단 N1: `08_build/artifacts/m4p736/src/ev_mouse_N1.c` = NeXTMach 파일에 위 바뀜을 넣은 하나의 파일(실제 포함 파일 `<sys/types.h>`·`<kern/kalloc.h>`·`<bsd/dev/m68k/evio.h>` 등, 필요한 `ev_vars.h` 이름은 `ev_kbd.c` 처럼 파일 안 블록). 실기 run `m4p736-p1` 에서 §735.2 와 같은 관문: 컴파일 경고 0, `funcbytes` 18/18 SAME, `__text` 3000 B, `__data` 44 B 원본과 같음, `__bss` 8 B, 절 안 오프셋, COMMON 0, 원본에 없는 미정의 0. 경고가 있으면 known_warnings 로 쓸지 사용자께 여쭙니다.
2. 생성기 `gen_p736.py`(`gen_p729.py` 를 이 파일에 맞게)로 표시(`plan 736` 줄, BEGIN/END 구간, 머리 주석, 지운 줄 표시)를 넣은 F 와 주석을 지운 L 을 만들고, 원본 검사기로 표시 없는 줄이 NeXTMach 줄과 같은지 확인합니다.
3. 스테이징(`stage_m68k.py --plan 736`: `M4FILES`·`M4HEADERS`·`EXCEPTS`), x86 입력·게이트 회귀, M5 `m3p736-ccK` 회귀, 확인 run `m4p736-p2`(F, L), `-E` run, 최종 run `a1`(`refs` = L 객체, zerofill 로 `__bss` 8 B 를 `CODE+BSS_INFERRED`), 상태 도구(ACCEPTED 튜플, 두 번 돌려 앞 행이 그대로인지), 증거 `m68k-ev_mouse.md`·`.diff`, PROVENANCE 한 행(일곱 칸), MODIFICATIONS 행, DECISIONS D165, 계획 결과 절, HANDOFF, 기억.
4. 판정(미리 정함): 관문을 모두 통과해야 수락합니다. 기대: 객체 66 → 67, `OBJECT_MATCH` 51 은 그대로·`CODE+BSS_INFERRED` 15 → 16, 덮은 행 88 → 91/188(행 216·217·218 이 범위 안에 통째로 들어 덮임, 219 는 부분 행; §736.1 이 한때 90 으로 고쳤으나 틀린 고침이었음 — §736.3; 최종 수는 상태 도구의 python 출력으로 확인). 하나라도 안 맞으면 기준을 낮추지 않고 멈춰 보고합니다.

범위 밖(정하지 않음): 단위 밖의 이름(`ev.c` 가 `extern` 으로 쓰는 ev 변수 30 개의 COMMON 정의 자리), `evdispatch` 선언이 다른 ev 파일의 `extern int evdispatch()`(예: `ev_kbd.c`)와 호환되는지는 호출 규약상 같아 링크 단계(M7)에서 다룹니다.

### 736.1 §736 codex 교차검토(`gpt-6.1-sol`) 판정과 계획 보강 (코딩 전, 2026-11-05)

먼저 제 잘못: (1) 기대 덮은 행을 91 로 썼으나 행 218 은 `exact` 0 이라 셈에 들지 않아 90 이어야 합니다(인벤토리 `m68k-m4-inventory.tsv` 의 `exact` 열을 python 으로 읽어 확인: 216 → 1, 217 → 1, 218 → 0; 위 본문을 고침). (2) 원래 헤더(`next/cpu.h`·`nextdev/kmreg.h` 등)와 파일 안 블록의 처리, 검사 목록, 출처 기록 대상이 §736 에 빠져 있었습니다. 아래로 보강합니다.

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| `next/cpu.h` 는 C 포함 금지(PROVENANCE 1114) | `PROVENANCE.tsv:1114` 를 열음(`ASSEMBLY ONLY: in C it tentatively defines master_cpu, dma_chip, …`) | ✅ C 포함하지 않음 |
| `nextdev/kmreg.h` 를 포함하면 COMMON(`km`·`alert_key`·`km_coni`) | `07_kernel/nextmach/nextdev/kmreg.h:190–195` 를 열음(`#if KERNEL`, `struct km km; … int alert_key;`) | ✅ 포함하지 않고 `struct mouse` 만 파일 안 블록(`kmreg.h:100–106` 의 07 사본 줄을 그대로; 진단 I2b 도 그렇게 씀) |
| `adb_mouse_present(void)` 선언을 07 에서 찾지 못함 | `grep -rn adb_mouse_present 07_kernel/src 07_kernel/nextmach 07_kernel/nextdev` 0 건, 진단 `evmouse_I2b.c:350` 의 선언을 열음 | ✅ 파일 안 선언으로 두고 출처를 "이 프로젝트의 재구성(원본 바이트의 호출)"로 구분 기록 |
| `EvGlobals`·`EvScreen` 은 SDK 사본 `evio.h:109` 를 씀 | 앞서 열음(`typedef volatile struct _evScreen`) | ✅ 포함 파일로 쓰고 인라인하지 않음 |
| 경고가 나면 먼저 원본 헤더의 선행 선언 누락을 확인; 예외로 채택하면 최종 F 의 stderr 를 명세에 고정(`m4_m68k_probe.py:385`, 정확 비교) | `m4_m68k_probe.py:383–392` 를 열음(`kw = s.get('known_warnings')`, `c['err_lines'] == kw[...]`) | ✅ 보강 |
| `bss_inferred: ["ev_mouse"]` 와 ACCEPTED 의 최종 기록·zerofill 기록 경로·SHA | `probe:385–392` 의 `provisional` 은 `bss_inferred` 에 든 객체만, `m4_m68k_status.py:148–152` 의 4 칸 항목(zerofill 기록 SHA 단언)을 열음 | ✅ 보강 |
| 공유 헤더 변경 시 재수락, PROVENANCE 1178 의 `kmreg.h` 선례 | `PROVENANCE.tsv:1178` 을 열음(`nextmach+authored`) | ✅ 이 계획은 공유 헤더를 바꾸지 않는 것을 전제로 하고, 바꾸게 되면 멈춰 여쭙습니다 |
| §729 와 같은 동일성 검사(F/L·L/N1 토큰, 머리 고지 보존, `canon`·`obj_sig`) | `scratch/p728/chk729.py`·`chk729p1.py`·`chk729final.py` 를 읽음 | ✅ 보강 |

보강한 계획:
- 포함 파일: `<next/cpu.h>`·`<nextdev/kmreg.h>` 는 C 에서 포함하지 않습니다. `struct mouse` 는 파일 안 블록(`kmreg.h:100–106` 사본의 줄 그대로, 줄 범위는 구현 때 NeXTMach 원본과 python 으로 대조). `<machine/machparam.h>`·`<vm/vm_param.h>`·`<vm/vm_kern.h>`·`<nextdev/ev_vars.h>` 는 N1 컴파일에서 필요한 것만 07 의 기존 사본·SDK 경로로 쓰고, 필요 없으면 지웁니다(지운 줄은 `removed` 표시). `ev_vars.h` 의 이름은 `ev_kbd.c` 처럼 파일 안 블록으로 두며 NeXTMach `ev_vars.h` 에 있는 선언은 그 줄을 그대로(줄 범위 기록), 없는 이름은 재구성으로 구분합니다. 선행 선언 누락 경고는 먼저 이 블록과 포함 파일로 풀고, 그래도 남을 때만 `known_warnings` 를 사용자께 여쭙습니다.
- 동일성 검사(`chk736*.py`): F 와 L 의 토큰 동일, L 과 N1 의 토큰 동일, NeXTMach 머리 고지 보존, 표시 없는 줄이 NeXTMach 줄인지, BEGIN/END 수, 07 파일 = F 의 SHA; 확인 run 의 `__text`·`__data` 바이트와 절 크기, 이름 집합(원본 기호표에 없는 외부·COMMON·미정의 0), F·L 의 `canon`·`obj_sig` 같음, F 와 N1 의 `canon` 같음.
- 스테이징 회귀: `stage_m68k.py` 새 스테이징과 이전 스테이징 재생성·보관본의 동일성, 허용 변경 목록(`M4FILES`·`M4HEADERS`·`EXCEPTS`), M5 205 줄 비교(`differ_unexpected` 와 `lost` 가 비어야 함), x86 입력(`m4_x86_inputs.py`)·x86gate 가 그대로임.
- BSS 수락: 최종 명세에 `bss_inferred: ["ev_mouse"]`, `refs` = 확인 run 의 L 객체, zerofill 기록(`m5_m68k_zerofill.py objs`) 경로·SHA 를 상태 도구의 `ACCEPTED` 4 칸 항목에 넣고, 상태 도구를 두 번 돌려 앞 행이 그대로인지 봅니다.
- 출처 기록: PROVENANCE 한 행(일곱 칸)에 NeXTMach 저장소 URL·고정 commit·`mk-108.1/nextdev/ev_mouse.c` 줄 범위, 가져온 `kmreg.h:100–106`(`struct mouse`)과 `ev_vars.h` 의 줄 범위, 새로 쓴 이름(`ev_shmem_cursor`·`ev_adb_mouse`·`evCoalesce`·`evBrightness`·`ev_wait_frame`·`ev_point_to_screen`)과 NeXTMach 이름 재사용(`initNumMouseScales` 등), 지운 NeXTMach 함수·자료, 고지 보존을 적고, MODIFICATIONS 에 같은 내용을 함수별로 씁니다.

2 차 자기검사: ✅ 행은 이번 세션에 연 줄 또는 제가 돌린 python 입니다.

### 736.2 진단 N1 결과: NeXTMach 바탕 한 파일이 18/18 SAME (run `m4p736-p1`, 2026-11-05; 07 변경 없음)

N1(`08_build/artifacts/m4p736/src/ev_mouse_N1.c`, 생성 `scratch/p736/gen_n1.py`) = NeXTMach `ev_mouse.c` 의 머리 고지·`Implementation Constants`·세 `init*` 정적·함수 앞 주석을 그대로 두고, 열두 함수를 진단 I2b 의 본문으로 바꾸고, NeXTMach 에만 있는 함수 13 개와 커서 그림 자료를 지우고, 새 함수 여섯과 새 정적 넷을 원본 주소 순서로 넣은 한 파일입니다. 포함 파일은 `<sys/types.h>`·`<sys/param.h>`·`<sys/systm.h>`·`<kern/kalloc.h>`·`<bsd/dev/m68k/evio.h>` 이고 `struct mouse` 는 파일 안 블록, `ev_vars.h` 이름은 파일 안 `extern` 블록입니다(§736.1 의 처리). NeXTMach 의 `next/cpu.h`·`nextdev/kmreg.h`·`machine/machparam.h`·`vm/vm_param.h`·`vm/vm_kern.h`·`nextdev/ev_vars.h` 포함 줄은 쓰지 않았고 컴파일은 통과했습니다.

결과(컴파일 rc 0·**경고 0**·stderr 0 B; 함수 기록 `m4-m68k-funcbytes-p736-N1-20261105.json`): **18/18 SAME**(바이트와 재배치 대상, object-only 없음), `__text` 3000 B, `__data` 44 B 가 원본 [0x40b1260, +44) 와 바이트별로 같고(오프셋 `initNumMouseScales` +0, `initMouseScaleThresholds` +4, `initMouseScaleFactors` +14, `ev_shmem_cursor` +24, `evCoalesce` +28), `__bss` 8 B(`evBrightness` +0, `ev_adb_mouse` +4), 미정의 41 개가 모두 원본 기호표에 있고 COMMON 0, 외부 정의 16(`ev_wait_frame`·`ev_point_to_screen` 은 `static`). 따라서 `known_warnings` 는 필요 없습니다. NeXTMach 의 `Implementation Constants` 매크로(`INITX` 등)는 진단 본문이 숫자를 직접 쓰므로 쓰이지 않은 채 그대로 남습니다(NeXTMach 줄이며 바이트에 영향 없음). 이것은 진단입니다. 다음: 생성기 `gen_p736.py` 로 표시를 넣은 F·L 을 만들고 §736 3 단계 이후를 진행합니다.

### 736.3 결과: m68k `ev_mouse.c` 수락 (CODE+BSS_INFERRED 18/18; D165; 2026-11-05)

먼저 제 잘못: §736.1 이 기대 덮은 행을 91 에서 90 으로 "고쳤"으나 틀린 고침이었습니다. 상태 도구는 범위 안에 통째로 든 행을 덮은 행으로 세며(행 218 포함) 정확한 행 여부로 거르지 않습니다. 실제 값은 88 → **91**/188(python: 상태 도구 출력)이고, 처음 기대가 맞았습니다. 인벤토리의 `exact` 열을 상태 도구의 셈 규칙으로 잘못 일반화했습니다. §736 본문과 D165·증거·PROVENANCE·MODIFICATIONS 의 해당 줄을 고쳤습니다.

결과:
- 07 `src/machdep/m68k/ev_mouse.c`(545 행, SHA-256 `2cce22bc…`) = 생성기 `gen_p736.py`(scratch)의 F. 증거 `06_reconstruction/evidence/m68k-ev_mouse.md`·`m68k-ev_mouse.diff`(NeXTMach 대비 907 줄), PROVENANCE 한 행(일곱 칸, 중복 없음; 1236 → 1237), MODIFICATIONS(763 → 764), DECISIONS D165(168 → 169).
- 소스 검사: F = L 토큰, L = N1 토큰, NeXTMach 와 54 hunk 에서 표시 없는 바뀐 줄 0(6 개 BEGIN/END 구역), 머리 고지 보존, 07 = F.
- 스테이징: `--plan 729` 재생성(1022)이 보관 `m0p729-a1-stage` 와 같고 새 `m0p736-a1-stage`(1023)는 `ev_mouse.c` 하나만 늘어남. x86 입력 변화 없음(키 0), x86 gate 는 `plan`·`tool_sha256` 만 다름, M5 205 줄 명령은 번호만 다름. M5 `m3p736-cc1`: 출력 617 개가 `m3p729-cc1` 과 `run.json` 만 다르고, `compare` 는 `differ_unexpected`·`lost` 비어 있고 `ev_mouse.c` 하나만 늘어남.
- 확인 run `m4p736-p2`(F, L): 경고 0, 18/18, 절 3000/44/8, `__data` 원본과 바이트 같음, COMMON 0·미정의 41(모두 원본에 있음), F = L = N1 의 `canon`·`obj_sig`. `-E` run `m4p736-e1`: F = L 토큰, stderr 0, i386 0.
- 최종 run `m4p736-a1`: `gate.ok`, L1 `NOT_MATCH`(이유 `__DATA,__bss: unverified` 하나, `provisional`), funcbytes 18/18. zerofill: `reference-inferred`, 후보 [0x40b4fb2, 0x40b4fba) 8 B, 앞서 받아들인 bss 후보 31 개와 겹침 0(python; `fd_subr` 가 바로 0x40b4fba 에서 이어짐). 확인 기록 `m4-m68k-p736-checks-20261105.json`(`ok`).
- 상태 도구(두 번 돌려 같음, 앞 행 그대로): 객체 66 → 67(OBJECT_MATCH 51, CODE+BSS_INFERRED 15 → 16), 덮은 행 88 → 91/188, 덮은 최소 바이트 128652 → 131430(60.88%), 객체 바이트 185236 → 188236(python: 128652 + 536 + 1946 + 296 = 131430, 185236 + 3000 = 188236). 기록 `m4-m68k-status-p736-20261105.json`.

판정: 미리 정한 관문을 모두 통과해 받아들였습니다(D165). 남은 것은 M7 의무(41 개 미정의와 COMMON 정의 자리, 정적 bss 의 최종 배치)와 다른 후보(`zs.c`, `nextdbg.c`, FPSP, `snd_link` …)입니다.

## 737. M4-204 조사 계획 — m68k `nextdbg.c`(행 304·305 와 행 306 앞부분, [0x4095460, 0x4096700) 4768 B, 함수 18) (07 변경 없음; 코딩 전, 2026-11-05)

고른 까닭(python 으로 센 값): §736 뒤 남은 행은 97 개, 최소 바이트 84444 B 입니다(인벤토리와 상태표; 덮은 행 91). 큰 것부터: `zs.c` 구역 9094 B(1997 판이 NeXTMach 와 크게 다르고 이름 없는 항목이 많음, §688 에서 미룸), `if_en.c`(행 260)·`ev_kbd`(행 215) 같은 부분 행은 받아들인 객체의 명시 구간이 이미 덮은 쪽이라 새 후보가 아니며(`snd_link`(행 246)는 미룸), 행 209 의 ADB 드라이버(`adb_initialize` … `adb_null`, [0x4064216, 0x4065bbc) 6566 B, 함수 21; NeXTMach 에도 Darwin 0.1 에도 소스가 없고 Darwin `bsd/dev/adb.h` 머리만 있음 — 이번 조사에서 새로 확인), FPSP(참고 글 없음, 사용자 결정 대기), `locore.s`(어셈블리, 조건부 많음), `snd_link`(미룸). `nextdbg.c` 는 NeXTMach `next/nextdbg.c`(978 행)가 있고, 원본의 문자열 13 개 가운데 5 개가 NeXTMach 글의 문자열과 완전히 같고(python: `dbg_trap returning, vecoff = %d\n`, `dbg_trap: bad user vecoff`, `stack frame screw-up\n`, `debugger screw-up\n`, `\ndebugging connection from %s on %s\n`), 둘(`rdmem: bad size\n`, `wrmem: bad size\n`)은 NeXTMach 의 `rdmem: bad size: 0x%x\n` 와 앞부분만 같습니다(`nextdbg.c:680·714`). NeXTMach 12 행에 `#pragma CC_OPT_OFF` 가 있고 원본 본문도 최적화를 끈 모양(`pea %fp@; moveal %sp,%fp`, 지역 변수를 모두 `fp@(-N)` 에 저장)이어서 레지스터 배정 문제는 적을 것으로 봅니다(⚠️ 가설).

사실(python: 함수 표 `06_reconstruction/m68k-functions.tsv`, 인벤토리, 원본 objdump `scratch/p737/original-objdump.txt`: [0x4095460, 0x4096700) 를 §737.1 에서 다시 만듦):
- 범위 [0x4095460, 0x4096700) 4768 B, 함수 18 개가 빈틈없이 이어지고 크기 합이 범위와 같습니다: `m68k_dbginit` 82 · `dbg_kresume` 120 · `dbg_panic` 32 · `dbg_trap` 838 · `dbg_dispatch` 68 · `kdbg_connect` 166 · `gdb_from_trap` 182 · `dbg_from_ether` 54 · `dbg_process` 1810 · `rdmem` 226 · `wrmem` 180 · 이름 없음 74(0x409630e) · 이름 없음 46(0x4096358) · `kdebug_send` 54 · 이름 없음 260(0x40963bc) · 이름 없음 50(0x40964c0) · `SENDEXC` 312 · `inet_aton` 214. 뒤는 이미 받아들인 `nextdbgasm`([0x4096700, 0x40967be)), 앞은 `next_table`(0x4095460 에서 끝남)입니다.
- 인벤토리 행: 304(정확, 82 B = `m68k_dbginit`), 305(`next/nextdbg.c`, `exact` 0, [0x40954b2, 0x4096386~0x40964f2), 최소 3796 B), 306(미배정, `exact` 0, 끝 0x4096736 — 받아들인 `nextdbgasm` 이 이미 일부를 덮은 부분 행). 307 은 `nextdbgasm` 이 덮음.
- NeXTMach `nextdbg.c` 의 함수 21 개(`nextdbginit`, `dbg_exit`, `dbg_trap`, `btoh`, `htobs`, `htob`, `kdbg`, `rdmem`, `wrmem`, `hookbuserr`, `unhookbuserr`, `dbg_kresume`, `kdbg_connect`, `putnib`, `putpkt`, `ack`, `getnib`, `getpkt`, `kdebug_send`, `gfunc`, `pfunc`) 가운데 원본 이름이 같은 것은 `dbg_kresume`·`dbg_trap`·`kdbg_connect`·`rdmem`·`wrmem`·`kdebug_send` 여섯이고, `nextdbginit` 은 1997 의 `m68k_dbginit` 과 역할이 대응하는 가설입니다(`nextdbg.c:189–210`: `vbp[DBG_BKPT]`(46) 를 `_dbg_trap` 으로 바꾸고 시리얼 장치를 정한 뒤 `kdbg()`; 원본 0x4095460 은 `vbr + 0xbc`(47)의 옛 값을 `0x40b5620` 에 저장하고 `0x4096736`(받아들인 `nextdbgasm` 의 `__dbg_trap`)을 써 넣은 뒤 `dbg_kresume`·`adb_watchdog(0)`·`dbg_process`·`adb_watchdog(1)` 를 부름 — 본문은 다름. 받아들인 `nextdbgasm.s:15–27` 의 `__m68k_dbginit` 이 C `_m68k_dbginit` 을 부르므로 새 C 본체는 밑줄 없이 `m68k_dbginit` 로 정의해야 합니다). 이름 없는 74 B(0x409630e)와 46 B(0x4096358)는 동작이 NeXTMach `hookbuserr`(`nextdbg.c:725–735`)·`unhookbuserr`(`:738–745`)와 대응합니다(`get_vbr` 호출 뒤 벡터 2·3 을 `0x40b5614`·`0x40b5618` 에 저장하고 `0x4096736` 을 설치 / 복원; 이름은 가설). 따라서 NeXTMach 와 같은 이름 여섯 + 동작 대응 셋(`nextdbginit`, `hookbuserr`, `unhookbuserr`) + 원본에만 있는 아홉(`dbg_panic`·`dbg_dispatch`·`gdb_from_trap`·`dbg_from_ether`·`dbg_process`·`SENDEXC`·`inet_aton`, 이름 없는 260 B(0x40963bc)·50 B(0x40964c0))입니다. `inet_aton` 은 BSD 의 `inet_aton` 으로 NeXTMach `nfs/nfs_bootsubr.c` 와 Darwin `Libc/net.subproj/inet_addr.c` 에 글이 있는 후보입니다. NeXTMach 에만 있는 열둘(`dbg_exit`·`btoh`·`htobs`·`htob`·`kdbg`·`putnib`·`putpkt`·`ack`·`getnib`·`getpkt`·`gfunc`·`pfunc`)은 1997 단위에 같은 이름이 없지만 그 일부(`gfunc`·`pfunc` 는 `SERIAL`·`NET` 갈래, `nextdbg.c:919·922·968·972`)가 새 함수와 관계가 있을지는 정하지 않았습니다.
- 원본의 자료 참조(python 이 objdump 에서 `0x4xxxxxx` 를 뽑아 절별로 나눔): `__cstring` 13 곳, `__bss` 12 곳(0x40b55cc, 0x40b5610–0x40b5638), `__common` 17 곳(이름 있는 심볼 7: `_machine_type`·`_dma_chip`·`_slot_id`·`_kdb_ipaddr`·`_client_pcb`·`_client_running`·`_dbg_connect_pkt`; 나머지 10 곳은 이름 있는 객체 안의 주소: `_en_pkt`+0x8·+0xc, `_kdb_net`+0x8, `_client_pcb`+0x4·0x40·0x46·0x48·0x4c·0x4e·0x56 — python 으로 `symbols.tsv` 와 견줌). 앞서 받아들인 07 파일이 이 단위의 일부 이름을 부릅니다(`grep`: `trap.c` 에 `gdb_from_trap`, `if_en.c` 에 `dbg_from_ether`, `m68k_init.c` 에 `inet_aton`).
- 문자열 13 개: `dbg_panic: %s\n`, `dbg_trap returning, vecoff = %d\n`, `dbg_trap: bad user vecoff`, `stack frame screw-up\n`, `debugger screw-up\n`, `old debugging info packet (%d) ignored\n`, `gdb_from_trap:pc %x sp %x sr %x faultaddr %x\n`, `connecting to debugger\n`, `\ndebugging connection from %s on %s\n`, `Bad length of data to process`, `kdbg unknown rq type %d\n`, `rdmem: bad size\n`, `wrmem: bad size\n`(원본 `__cstring` 0x40ac80b–0x40ac959).

방법(07 변경 없음; 이 절은 조사와 첫 진단의 계획):
1. 조사(읽기): 원본 18 함수를 하나씩 읽어 호출·자료·분기 모양을 `scratch/p737/` 에 기록하고, 짝이 있는 함수 일곱(`m68k_dbginit`↔`nextdbginit` 포함)은 NeXTMach 본문과 줄 단위로 견줍니다. 새 함수 열하나(이름 없음 넷 포함)는 바이트에서 읽은 사실과 `inet_aton` 후보 글만 씁니다. 무엇이 `static` 인지(원본 기호표에 이름이 없는 넷)는 §735 처럼 바이트로 가려지지 않으면 사용자께 여쭙니다.
2. 첫 진단 D1: `#pragma CC_OPT_OFF` 를 둔 한 파일(NeXTMach `nextdbg.c` 머리·`#include` 를 OPENSTEP 경로로, 짝이 있는 함수는 NeXTMach 본문에서 시작, 나머지는 원본 바이트로 쓴 본문)을 §736 의 N1 방식으로 실기 run `m4p737-p1` 에서 컴파일해 `m68k_funcbytes.py 0x4095460 0x4096700` 으로 함수별 일치를 봅니다(앵커: 이름 없는 넷과 정적 자료). 일치하지 않는 함수는 정규화 difflib(`cmpfn.py` 꼴)로 차이 구간을 읽고 차이마다 소스 가설을 세워 새 계획으로 시험합니다.
3. 판정(미리 정함): 18 함수가 모두 `funcbytes` 에서 같고 `__text` 4768 B, `__data`·`__bss` 크기와 절 안 오프셋·COMMON·원본에 없는 미정의 이름이 원본과 같으면 진단 성공(조건부; 수락 아님)입니다. 안 되면 기준을 낮추지 않고 차이로 다음 계획을 세웁니다. 구현 선택(`static`, 정적 이름, 형)은 구현 단계에서 사용자께 여쭙니다.

모르는 것: 최적화를 끈 코드가 NeXT cc 의 기본 `-O` 에서 `#pragma CC_OPT_OFF` 만으로 나오는지(`m4_m68k_probe.py:194–219` 는 x86 컴파일 줄을 m68k `-g -O2` 로 바꿔 쓰고 M5 줄은 `-D`·`-I` 비교에만 쓰므로 `-O2` 에 pragma 가 얹힙니다; 선례는 `07_kernel/src/kern/mach_net.c:165–167` 의 `#if m68k #pragma CC_OPT_OFF`(D096, 계획 479)이며 m68k 에서 pragma 가 효과를 냈는지는 그 증거 §479 를 따름), `dbg_process` 1810 B 의 본문(UDP 디버그 프로토콜로 보임), 새 함수의 이름 있는 형(`struct`)·헤더(`kdb_net`, `nextdbgpcb`, `sf_4wd`)가 07 에 있는지, `COMMON` 10 곳의 이름(원본 기호표에 없음).

### 737.1 §737 codex 교차검토(`gpt-6.1-sol`) 판정 (코딩 전, 2026-11-05)

먼저 제 잘못: (1) "문자열 7 개가 NeXTMach 글에 그대로"라고 썼으나 완전히 같은 것은 5 개이고 둘은 앞부분만 같습니다(끝 개행을 뗀 부분 문자열로 센 값이 7 이었음). (2) `facts.py` 와 `original-objdump.txt` 의 시작 주소를 0x40954b2 로 잡아 `m68k_dbginit`(0x4095460, 82 B)를 빼고 17 함수로 센 채 계획에 18 함수·4768 B 를 썼습니다(사실의 수는 맞고 근거 파일이 어긋났음; 두 파일을 [0x4095460, 0x4096700) 로 다시 만들었습니다). (3) 이름 없는 넷이 모두 "새 함수"라고 했으나 둘은 `hookbuserr`·`unhookbuserr` 와 동작이 대응하고, NeXTMach 에만 있는 함수를 "시리얼 전용"이라 한 것은 틀렸습니다(`gfunc`·`pfunc` 는 `SERIAL`·`NET` 갈래). (4) COMMON "이름 없는 10 곳"은 이름 있는 객체 안의 주소였습니다. (5) probe 가 M5 줄을 그대로 쓴다고 썼으나 x86 줄을 바꿔 씁니다. (6) `tty` 선례는 없고 실제 선례는 `mach_net.c` 입니다.

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 완전 일치 문자열은 5, 끝 개행 뗀 부분 문자열은 7; `rdmem`·`wrmem` 은 `bad size: 0x%x` | python 으로 `__cstring` 13 개와 NeXTMach 리터럴을 디코딩해 견줌(exact 5, prefix-ish 7), `nextdbg.c:680·714` 를 열음 | ✅ 본문 고침 |
| 이름 없는 74 B·46 B 는 `hookbuserr`·`unhookbuserr` 와 동작 대응, `gfunc`·`pfunc` 는 `SERIAL`/`NET` 갈래 | `nextdbg.c:725–745` 와 `919·922·968·972` 를 열음; 원본 objdump 의 해당 함수는 아래 §737.2 에서 읽음 | ✅ 대응은 가설(이름), 본문 고침 |
| 지정 objdump 에 `_m68k_dbginit` 없음; 원본은 `vbr+0xbc`(47), NeXTMach `DBG_BKPT` 46, 짝은 역할 가설 | 새 objdump([0x4095460, 0x4096700), 1394 행)에서 `<_m68k_dbginit>` 가 1 행; `nextdbg.c:179` 를 열음(`DBG_BKPT 46`) | ✅ 본문 고침 |
| COMMON 10 곳은 `en_pkt`·`kdb_net`·`client_pcb` 의 안쪽 주소 | python 으로 `symbols.tsv` 에서 바로 앞 심볼과 차이를 구함(`_en_pkt`+0x8·0xc, `_kdb_net`+0x8, `_client_pcb`+0x4…0x56) | ✅ 본문 고침 |
| probe 는 x86 줄을 바꿔 씀(`m4_m68k_probe.py:194–219`), M5 줄은 `-D`·`-I` 비교 | 194–200·209–220 을 열음 | ✅ 본문 고침 |
| 선례는 `mach_net.c:165–167`(`#if m68k #pragma CC_OPT_OFF`, D096), `m5p479/final.cmd` 는 `-g -O2`, `tty` 선례 없음 | `mach_net.c:163–168` 을 열고 `m5p479/final.cmd` 의 머리를 읽음 | ✅ 본문 고침 |
| `pea + move` 프롤로그 선택은 `optimize` 와 무관(`m68k.c:99–111`)하므로 프롤로그만으로 최적화 해제를 판정할 수 없음 | 공개 GCC 소스 `config/m68k/m68k.c` 는 이번에 열지 않음 | ⚠️ 미확인 → "프롤로그만으로 단정하지 않음"으로 약화(저장·즉시 재로드가 비최적화와 양립한다는 정도만 적음) |
| 새 C 본체는 `m68k_dbginit`(밑줄 없음); `nextdbgasm.s:15–27` 의 `__m68k_dbginit` 이 `_m68k_dbginit` 을 부름; `dbgstack` 은 `if_en.c:280` 에 이미 정의 | `nextdbgasm.s:14–17·27` 을 열음; `dbgstack` 의 `if_en.c:280` 은 열지 않음 | ✅(앞부분) / ⚠️(`dbgstack`: 구현 때 python grep 으로 확인) |
| `next/cpu.h` 는 C 포함 금지(`PROVENANCE.tsv:1114`), `kmreg.h` 는 COMMON; 공유 헤더 변경 시 소비자 재수락 | 앞선 §736.1 에서 열었음; NeXTMach `next/nextdbg.h:21–38` 은 `struct kdb_net {…} kdb_net;`(tentative 정의 = COMMON) | ✅ 헤더 처리 추가 |
| 경고 관문: `diag_gate` 는 경고 0 요구, `refs` 관문은 `known_warnings` 와 정확히 같으면 허용; `funcbytes` 는 참조한 문자열만 보증하고 `__cstring` 절 전체는 안 봄 | `m4_m68k_probe.py:381–391` 를 앞서 열음; `__cstring` 절 전체 비교는 §735·§736 에서도 쓰지 않았음을 확인 | ✅ 판정에 절 전체 비교를 추가 |

2 차 자기검사: ✅ 행은 이번 세션에 연 줄·명령 출력이며 ⚠️ 행의 줄은 인용하지 않았습니다.

보강한 계획: ① 판정 3 에 `__cstring` 절 전체([0x40ac80b…])와 함수가 참조하는 문자열 13 개의 원본 바이트 일치를 추가하고, `__data`·`__bss`·`COMMON` 이름·크기(객체별)는 확인하되 최종 병합과 배치는 M7 의무로 구분합니다. ② 헤더: `next/cpu.h`·`nextdev/kmreg.h` 는 C 에서 포함하지 않고, `kdb_net`·`nextdbgpcb`·`sf_4wd` 의 정의는 NeXTMach `next/nextdbg.h` 등을 파일 안 블록으로 두되 tentative 정의가 COMMON 을 만들지 않게 `extern` 으로 둡니다(이미 받아들인 07 파일의 정의 자리와 겹치지 않는지 `grep` 으로 확인; 공유 헤더는 바꾸지 않음). ③ 경고는 먼저 선행 선언 누락을 의심하고(§729), 남으면 사용자께 `known_warnings` 를 여쭙습니다. ④ 최적화 해제는 `#pragma CC_OPT_OFF`(파일 안 `#if m68k` 로 감싸는 §479 꼴과 NeXTMach 12 행 꼴)를 시험해 바이트로 판정합니다.

### 737.2 진단 결과: 18 함수 가운데 17 개가 SAME (runs `m4p737-p1`–`p11`, 2026-11-05; 07 변경 없음)

방법(§737 1·2 단계): NeXTMach `nextdbg.c` 의 구조체·정적 자료·같은 이름 함수를 바탕(`scratch/p737/gen_d0.py`→`gen_d1.py`→`gen_d3/d4/d6.py`)으로 한 진단 파일을 만들고, 새 함수는 원본 바이트에서 읽어 씁니다. 실기 run 마다 변형 여럿을 한꺼번에 컴파일하고 `m68k_funcbytes.py 0x4095460 0x4096700 …`(앵커: 이름 없는 `0x409630e`·`0x4096358`·`0x40963bc`·`0x40964c0` 와 정적 bss 열둘)와 정규화 difflib(`scratch/p737/cmpf.py`)로 함수별로 견줬습니다. 컴파일은 `#pragma CC_OPT_OFF` 로 최적화가 꺼졌고(`warning: optimization turned off` 한 줄이 난다 — 수락 때 `known_warnings` 후보) 모두 rc 0 입니다.

결과(최선 변형 `08_build/artifacts/m4p737/src/nextdbg_D6A.c`, run `m4p737-p11`, 함수 기록 `m4-m68k-funcbytes-p737-D6A-20261105.json`, probe 기록 `m4-m68k-probe-p737-p11-20261105.json`): **17/18 SAME**(바이트와 재배치 대상, object-only 없음). 원본에 없는 미정의 이름 0. 안 맞는 것은 `dbg_process`(1810 B)뿐이고 아직 쓰지 않았습니다(`__text` 2958 B 대 4768 B).

진행의 요점:
- D0(NeXTMach 글 그대로, `m4p737-p2`): `hookbuserr`·`unhookbuserr`·`dbg_kresume` 는 거의 같고 `rdmem`·`wrmem`·`dbg_trap` 에서 `if (rmtdebug)` 디버그 출력과 `exit` 가 1997 에 없음을 확인했습니다.
- D1(`p3`–`p6`): 11 → 14/18. 1997 바뀜: `printf` 대신 `nmi_prf`(원본 0x4093e4a), `exit` 대신 `dbg_panic`(자료 아님: 문자열 `rdmem: bad size\n` 등을 그대로 넘김), `VEC_BRKPT` 가 47(`vbr+0xbc`), `dbg_trap` 첫머리와 끝의 `adb_watchdog(0/1)`, longjmp 대신 `dbg_dispatch()` 호출, 신호 종류·고장 주소·벡터 번호를 정적(`0x40b5630`·`0x40b5634`·`0x40b5638`)에 저장(프레임 형별 +8·+12·+20·+32·+60·+92 와 고장 주소 오프셋 +8·+16 은 점프 표 `0x4095634`·`0x4095746` 를 python 으로 읽어 정함), `wrmem` 이 `cache_push()` 를 두 번 부름, `if` 의 조기 `return` 꼴(`if (!x) return;` 가 `bnes L; bras end` 를 냄).
- D3/D4(`p7`–`p9`): `kn_ri`·`kn_ti`·패킷 `seq` 가 포인터 형(`char *`)이어야 `lea`·`cmpal`·`lea a0@(1),a3` 가 나옴; 패킷 머리에 필드 접근(`q->code`)이어야 `movel x,a0@(4)`; `SENDEXC`·`kdebug_send`·`dbg_ack` SAME; `inet_aton` 은 `register char *cp; register char *p;`(a0, a1), 문장 순서 `p = &u; val = 0; cp = str;`, `val = val * 10; val += *cp - '0';` 에서 SAME.
- D5/D6(`p10`·`p11`): `dbg_recv` 는 `for (;;)`·`while (1)` 로는 점프 사슬이나 시험용 분기가 달라 260 B 가 안 되고, **`again:` 라벨과 `goto again`**(조건 분기가 되돌아가는 곳)을 쓸 때 SAME.

바이트로 가려지지 않는 선택(구현 단계에서 사용자께 여쭙기): `goto` 꼴, 정적 이름(`dbg_nest`·`dbg_from_net`·`dbg_sig`·`dbg_fault_addr`·`dbg_vecoff`, 보조 `dbg_recv`·`dbg_ack`), 이름 없는 함수 넷의 `static` 여부(`hookbuserr`·`unhookbuserr` 는 NeXTMach 에서 `static`), `kn_ri` 등을 `char *` 로 둔 형(경고 `comparison between pointer and integer` 가 남음), `dbg_recv` 의 쓰지 않는 지역 변수와 `kdbg_connect` 의 쓰지 않는 지역 둘(프레임 크기가 바이트로 정함), `kdb_net`·`en_pkt` 선언 모양.

남은 일: ① `dbg_process`(1810 B; 패킷 종류 8–21 의 `switch`, 종류 9 는 `dma_chip` 313·`machine_type` 3 에 따른 메모리 영역 표를 만듦, 점프 표 `0x4095ae0`(14)·`0x4095ce8`(5)) 읽기와 진단, ② 합친 TU 18/18 과 `__bss` 절 안 오프셋·COMMON 이름과 크기·`__cstring` 절 전체 비교(§737.1 보강), ③ 사용자 결정, ④ 07 `src/machdep/m68k/nextdbg.c` 구현·수락(`nextdbgasm` 의 `__m68k_dbginit` 과 밑줄 구분, `next/cpu.h` C 포함 금지, 공유 헤더 불변).

## 738. M4-205 세부 계획 — m68k `nextdbg` 단위의 `dbg_process`(0x4095a66, 1810 B) 진단 (07 변경 없음; 코딩 전, 2026-11-06)

고른 까닭: §737.2 로 18 함수 가운데 17 개가 SAME 이고 남은 것이 `dbg_process` 하나입니다(원본 objdump `scratch/p737/original-objdump.txt` 의 `<_dbg_process>` 구간).

원본에서 읽은 구조(python 으로 점프 표를 읽음: 표 1 은 `0x4095ae0` 부터 4 B 항목 14 개 = 패킷 종류 8–21, 표 2 는 `0x4095ce8` 부터 5 개 = `machine_type` 1–5; 아래는 가설이며 바이트로 확인):
- 머리: 프레임 36 B, `moveml d2/a2-a3`. 프레임 36 B 의 슬롯 아홉 가운데 일곱이 쓰임(슬롯 `fp@(-4)` 응답 머리(`en_pkt[2]`+42), `-8` 오류값, `-12` 반복 수, `-16`·`-20` 쓰지 않음, `-24` 문자열 포인터, `-28` `&kdb_net`, `-32` 요청 머리(`pkt`+42), `-36` 영역 표 쓰기 포인터이자 18·19 의 벡터 표 포인터와 13 의 자료 포인터로도 쓰는 `int *` 하나). `kdb_net` 의 세 번째 칸(`@8`)이 0 이거나 `pkt` 가 0 이면 곧바로 반환, 아니면 `nmi_prf("connecting to debugger\n")`(0x40ac8d4) 뒤 되풀이(맨 위 `0x4095aae`, 맨 끝 `braw 0x4095aae`).
- 되풀이 안에서 `switch (요청->@4)`(종류 8–21), 끝 공통 꼬리는 `dbg_ack()`(0x40964c0) → `dbg_recv(0)`(0x40963bc)의 반환을 `pkt` 에 저장하고 맨 위로. `SENDEXC()`(0x40964f2) 뒤는 `dbg_ack` 를 건너뛰고 `dbg_recv(0)` 로 곧장 갑니다(`braw 0x409615c`).
- 종류별(표 1): 8(`0x4095b18`): `index(요청+24, ':')` 로 `cp` 를 얻어 있으면 `*cp = 0`, `nmi_prf("\ndebugging connection from %s on %s\n", 요청+24, cp+1)`, `kdb_net@4 = 0`, 응답`@4 = 2`; 9(`0x4095b7a`): 응답`@16 = 1`, 응답`@4 = 5`; 10·그 밖(`0x409612e`): `nmi_prf("kdbg unknown rq type %d\n", 응답->@4)` 뒤 오류 꼬리(`0x4096144`: 응답`@4 = 22`, 응답`@20 = 0`; 12·13 의 `rdmem`/`wrmem` 실패도 여기로); 11(`0x4095b92`): 메모리 영역 표를 응답`+24` 부터 3 개 한 벌(시작·크기·종류)씩 채움: 고정 다섯 벌 `(slot_id, 0x20000, 1)`, `(slot_id+0x1000000, 0x20000, 1)`, `(slot_id+0x2000000, 0xC0040, 3)`, `(slot_id+0x2100000, 0x1E000, 3)`, `(slot_id+0x4000000, 크기, 3)` 이고 이 크기는 `dma_chip != 313` 이면 0x8000000, 같고 `machine_type == 3` 이면 0x2000000, 그 밖에는 0x4000000; 그다음 `switch (machine_type)`: 3 은 `slot_id` 를 더하지 않는 네 벌 `(0x4000000, 0x8000000, 3)`, `(0xC000000, 0x10000000, 3)`, `(0x24000000, 0x28000000, 3)`, `(0x2C000000, 0x30000000, 3)`, 1·2 는 없음, 그 밖(4·5 포함)은 `(slot_id+0x2200000, 0x9000, 3)`, `(slot_id+0x2210000, 4, 3)`, `(slot_id+0x3E00000, 0x80000, 3)` 세 벌; 모든 경로의 마지막 한 벌 `(0x10000000, 0x4000000, 3)`; 끝에 응답`@20 =` 쓴 바이트 수(1·2 는 72, 3 은 120, 그 밖은 108), 응답`@4 = 6`; 12(`0x4095f3a`): 요청`@16 > 512` 이면 `dbg_panic("Bad length of data to process")`, 4 바이트씩 `rdmem(요청@12 + i, 4, 응답+24+i)`, 실패면 오류 꼬리, 성공이면 응답`@4 = 3`, 응답`@20 = 요청@16`; 13(`0x4095fd2`): 요청`@20 != 512` 이면 같은 `dbg_panic`, 4 바이트씩 `wrmem(요청@12 + i, 4, *(요청+24+i))`, 실패면 오류 꼬리, 성공이면 응답`@4 = 1`, 응답`@20 = 0`; 14(`0x4096074`): `bcopy(client_pcb.regs, 응답+24, 72)`, 응답`@20 = 72`, 응답`@4 = 4`; 15(`0x40960aa`): `bcopy(요청+24, client_pcb.regs, 72)`, 응답`@4 = 1`, 응답`@20 = 0`; 16·17(`0x4095e8a`): 응답`@4 = 1`, 응답`@20 = 0`; 20(`0x4095ea0`): `kdb_net@8 = 0`, `dbg_from_net`(0x40b562c)`= 1` 뒤 18·19(`0x4095eae`)로 이어짐; 18·19: 응답`@4 = 1`, 응답`@20 = 0`, `dbg_ack()`, `client_pcb.sf.sf_sr` 의 최상위 비트가 켜져 있으면 벡터 9 를 `oldtrace`(0x40b561c)에 저장하고 `__dbg_trap`(0x4096736)을 넣고 `trace_expected`(0x40b5624)`= 1`, `dbg_kresume()`(0x40954b2), `dbg_from_net` 이 켜져 있으면 끄고 `pkt = dbg_connect_pkt; dbg_connect_pkt = 0;` 뒤 되풀이 끝(`braw 0x409616a`), 아니면 `SENDEXC()` 뒤 `dbg_recv`; 21(`0x40960dc`): 요청`@20` 이 0 이 아니고 511 이하이면 `*((char *)요청 + 요청@20 + 24) = 0` 뒤 `mon_call((char *)요청 + 24)`(0x4093762), 아니면 `mon_boot(0)`(0x40936a4).
- 응답 머리(`@0` 순서 번호 포인터, `@4` 종류, `@12` 주소, `@16` 길이, `@20` 응답 길이, `@24` 자료)는 §737.2 의 `struct dbg_hdr`(`seq`, `code`, `fault`@12, `vecoff`@16)를 넓힌 꼴로 씁니다. 자료 참조: 정적 `0x40b562c`(`dbg_from_net`), `0x40b561c`(`oldtrace`), `0x40b5624`(`trace_expected`), COMMON `_slot_id`(0x40c32d4)·`_dma_chip`(0x40c32d0, `movew` 로 읽고 313 과 비교)·`_machine_type`(0x40b61ac, `moveb`; `clrl d1; moveb d0,d1` 로 확장하므로 `unsigned char` 후보)·`_kdb_net`·`_client_pcb`·`_dbg_connect_pkt`.

방법(07 변경 없음): ① `nextdbg_D6A.c` 에 `dbg_process` 를 위 해석대로 쓴 D7 을 만들고, `struct dbg_hdr` 를 `addr`(@12)·`len`(@16)·`dlen`(@20)·자료(@24)로 넓히며(`SENDEXC` 는 같은 바이트여야 함), `index`·`mon_call`·`mon_boot`·`slot_id`·`dma_chip`·`machine_type` 를 선언해 실기 run `m4p738-p1` 에서 `funcbytes` 와 `cmpf.py` 로 `dbg_process` 의 차이 구간을 읽습니다. ② 차이마다 소스 가설(`switch` 식 형, `register` 지역, 식 순서, 라벨 `goto`, `for`/`while`)을 세워 변형 묶음으로 시험합니다. ③ 판정(미리 정함): `dbg_process` 1810 B 가 `funcbytes` 에서 SAME 이고 나머지 17 개도 SAME 이면 18/18 입니다; 안 되면 기준을 낮추지 않고 차이로 다음 계획을 세웁니다. 정적 이름·`goto` 꼴·형 등 바이트로 가려지지 않는 선택은 구현 단계에서 사용자께 여쭙습니다.

### 738.1 §738 codex 교차검토(`gpt-6.1-sol`) 판정 (코딩 전, 2026-11-06)

먼저 제 잘못: (1) 종류 11 의 표를 모두 `slot_id`+상수라고 뭉뚱그렸으나 `machine_type == 3` 의 네 벌과 마지막 벌은 `slot_id` 를 더하지 않고, 상수·크기·종류와 `dma_chip == 313` 조건식도 빠뜨렸습니다(위 본문을 고침). (2) `-36` 슬롯을 쓰기 포인터로만 적었으나 벡터 표 포인터와 종류 13 의 자료 포인터로도 씁니다. (3) 프레임에서 "지역 아홉 개"라고 적은 것은 선언 수가 아니라 슬롯 수입니다(쓰이는 것은 일곱).

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 종류 11: `machine_type == 3` 네 벌과 마지막 벌은 `slot_id` 를 안 더함; 조건식 | 앞서 objdump 를 직접 읽어 같은 해석을 얻음(0x4095d00–0x4095e4e, 0x4095c7c–0x4095cb2); python 으로 상수 19 개를 16 진수로 확인 | ✅ 본문 고침; 벌 수는 고정 5(조건 크기 포함) + 마지막 1 = 6(72 B), `machine_type` 3 은 +4 = 10(120 B), 그 밖은 +3 = 9(108 B)로 제 해석과 일치(12 B 씩; python 으로 곱셈 확인 6·12=72, 10·12=120, 9·12=108) |
| `-36` 은 벡터 표·자료 읽기 포인터로도 쓰임 | 원본 0x4095ed6–0x4095ee8 과 0x4096016–0x409601e 를 열음 | ✅ 본문 고침 |
| 쓰이는 슬롯은 -4·-8·-12·-24·-28·-32·-36, -16·-20 은 참조 없음 | python 으로 `%fp@(-N)` 을 센 출력: -4 26, -8 3, -12 12, -24 4, -28 3, -32 17, -36 85, (-16·-20 없음) | ✅ |
| 종류 12 는 signed `i < 요청@16`(길이 -1 이면 반복 0, 5 이면 8 바이트), 종류 13 은 `i <= 511` signed, 둘 다 `i += 4`, 종류 21 도 signed `bgts` | `cmpil #512 bles`·`cmpl d0,d1 bgts`·`cmpil #511 bles` 를 앞서 읽음 | ✅ 필드 형은 signed `int`, 반복 조건 `i <= 511`(13)·`req->len > i`(12) 로 고정 |
| `funcbytes` SAME 은 함수 바이트·재배치 대상만 보증, COMMON 크기·정적 초기값은 검사하지 않음 | `m68k_funcbytes.py:190·254` 는 열지 않았으나 §737.1 에서 이미 같은 결론으로 절 전체 비교를 판정에 넣음 | ✅ 판정 3 에 `__bss` 오프셋·COMMON·`__cstring` 절 전체 비교를 포함(§737.1) |

2 차 자기검사: ✅ 행의 근거는 이번 세션에 연 objdump 줄이거나 python 출력입니다.

### 738.2 결과: `nextdbg` 단위 18/18 SAME (runs `m4p738-p1`–`p7`, 2026-11-06; 07 변경 없음)

방법: §738 의 해석대로 `dbg_process` 를 쓴 D7 을 `nextdbg_D6A.c` 에 더해(`scratch/p737/gen_d7.py`→`gen_d8/d9/da/db.py`) 실기 run 마다 변형 여럿을 컴파일하고 `m68k_funcbytes.py 0x4095460 0x4096700 …` 와 정규화 difflib(`cmpf.py`)로 차이를 읽었습니다. 모두 rc 0, 경고는 `optimization turned off` 한 줄뿐입니다.

결과(최선 변형 `08_build/artifacts/m4p737/src/nextdbg_DBA.c`, run `m4p738-p7`, 함수 기록 `m4-m68k-funcbytes-p738-DBA-20261106.json`): **18/18 SAME**(바이트와 재배치 대상, object-only 없음). python 으로 읽은 객체 자료(앞서 §737.1 이 정한 추가 조건): `__text` 4768 B, `__cstring` 351 B 가 원본 [0x40ac80b, +351) 와 바이트별로 같고, `__bss` 112 B 의 열두 정적 심볼 오프셋이 원본 0x40b55cc 기준 값(0, 68, 72, 76, 80, 84, 88, 92, 96, 100, 104, 108)과 같으며(원본 끝 0x40b563c 와 112 B 가 같음), COMMON 은 `client_pcb` 162 B(원본 기호표에서 다음 심볼까지 164 B = 4 B 정렬)·`client_running` 4 B(간격 4 B), 미정의 22 개가 모두 원본 기호표에 있습니다. 외부 정의 14(`m68k_dbginit` 등), 나머지 넷(`hookbuserr`·`unhookbuserr`·`dbg_recv`·`dbg_ack`)은 `static`.

D7(`p2`, 처음 시도)부터 1814 B 에 차이 14 구간이었고, 아래 네 가지로 풀렸습니다:
- 영역 표 길이 `reply->dlen = (char *)wp - ((char *)reply + 24)`(또는 `reply->data` 로 쓴 `(char *)wp - reply->data`): 같은 식을 `(char *)wp - 24 - (char *)reply` 로 쓰면 컴파일러의 식 정리(`fold-const.c` 의 `associate`)가 `wp - (reply + 24)` 로 바꿔 순서가 달라집니다(공개 GCC 2.7.2.3 소스는 후보, 증거는 바이트 비교).
- 종류 12 의 반복: `for (i = 0; i < req->len; i += 4) { if (rdmem(req->addr + i, 4, …)) goto error; … }`(오류값 변수에 담지 않음; 종류 13 은 `err = wrmem(…)` 로 담음).
- 종류 20·18·19 의 추적 비트 블록 뒤에 빈 `else ;`(원본에 다음 명령으로 가는 `braw` 가 있음).
- 종류 21: `req->data[req->dlen] = 0; mon_call(req->data);`(자료 칸 `char data[512]` 를 쓴 배열 첨자; `*((char *)req + req->dlen + 24)` 꼴은 적재 순서가 달라 맞지 않음).
`struct dbg_hdr` 는 `char *seq; int code; int pad; char *addr; int len; int dlen; char data[512];` 입니다.

바이트로 가려지지 않는 선택(구현 단계에서 사용자께 여쭙기): §737.2 의 목록에 더해 `dbg_hdr` 필드 이름(`seq`·`code`·`addr`·`len`·`dlen`·`data`)과 `char *` 형, 종류 번호의 이름(숫자 그대로 둘지 상수로 쓸지), 영역 표 상수(숫자), `else ;`, 쓰지 않는 지역 둘(프레임 36 B), `goto error`/`goto recv`/`goto again` 라벨 이름과 꼴.

이것은 진단 성공(조건부)이며 수락이 아닙니다. 남은 일: ① 함수 순서(원본 주소순: `m68k_dbginit` … `dbg_from_ether`, `dbg_process`, `rdmem`, `wrmem`, `hookbuserr`, `unhookbuserr`, `kdebug_send`, `dbg_recv`, `dbg_ack`, `SENDEXC`, `inet_aton`)와 정적 정의 순서를 맞춘 통합 TU 진단과 헤더 처리(`next/cpu.h`·`kmreg.h` 를 C 에서 포함하지 않음, `kdb_net`·`en_pkt`·`client_pcb` 선언, 이미 받아들인 07 파일의 정의와 겹침 확인), ② 사용자 결정, ③ 07 `src/machdep/m68k/nextdbg.c` 구현·수락(`nextdbgasm.s` 의 `__m68k_dbginit` 과 C `m68k_dbginit` 의 밑줄 구분, `known_warnings` 의 `optimization turned off` 한 줄, 행 304·305 덮음·306 부분).

## 739. M4-206 구현 계획 — 07 `src/machdep/m68k/nextdbg.c`(명시 구간 [0x4095460, 0x4096700) 4768 B, 함수 18, 행 304·305 + 부분 행 306; 코딩 전, 2026-11-06)

고른 까닭: §738.2 로 18 함수가 진단에서 18/18 SAME 입니다. 그 뒤 진단 N1(`08_build/artifacts/m4p739/src/nextdbg_N1.c`, 생성 `scratch/p739/gen_n1.py`; NeXTMach `next/nextdbg.c` 의 머리 고지·`#pragma CC_OPT_OFF`·`NO_IPLMEAS`/`<machine/spl.h>`·`VEC_*`…`SR_T` 매크로(`VEC_BRKPT` 만 47)·`jmpbuf`…`trace_expected` 정의를 그대로 두고, 함수 열여덟을 원본 주소순으로 놓은 한 파일; 포함 파일 `<sys/types.h>`·`<sys/param.h>`·`<machine/spl.h>` 뿐)를 실기 run `m4p739-p1` 에서 컴파일해 확인했습니다(함수 기록 `m4-m68k-funcbytes-p739-N1-20261106.json`, probe 기록 `m4-m68k-probe-p739-p1-20261106.json`): 컴파일 rc 0·경고는 `src/src/m4probe/v_nextdbg_N1/nextdbg_N1.c:12: warning: optimization turned off` 한 줄(pragma 가 내는 안내), **18/18 SAME**, `__text` 4768 B, `__cstring` 351 B(원본과 바이트 같음), `__bss` 112 B, COMMON `client_pcb` 162 B·`client_running` 4 B, probe `l1_verdict` `NOT_MATCH` 이유는 `__DATA,__bss: unverified` 하나뿐, `full_span: true`, `judgement: provisional`, 원본에 없는 미정의 이름 0, i386 포함 경로 0.

기반과 출처(D013·D024·D104 방식, §736 `ev_mouse.c` 와 같음): NeXTMach `mk-108.1/next/nextdbg.c`(978 행)의 머리 고지(1–10 행, `Copyright (c) 1990, NeXT Inc.` 와 HISTORY)와 `#pragma CC_OPT_OFF`(12 행)를 그대로 두고, 같은 줄 그대로 남는 것(`NO_IPLMEAS`·`<machine/spl.h>`, `VEC_*`·`R_*`·`SR_T` 매크로, `jmpbuf`·`sf_*` 구조체·`nextdbgpcb`·정적 자료 정의, `hookbuserr`·`unhookbuserr`·`dbg_kresume` 의 글)를 표시 없이 두며, 바뀐 줄과 새 함수는 `plan 739` 표지와 BEGIN/END 구역, 지운 줄은 표지 주석으로 적습니다. NeXTMach 와 짝이 있는 함수(`nextdbginit`→`m68k_dbginit`, `dbg_trap`, `rdmem`, `wrmem`, `hookbuserr`, `unhookbuserr`, `dbg_kresume`, `kdbg_connect`, `kdebug_send`)는 바뀐 쪽이 많고(`printf`→`nmi_prf`, `exit`→`dbg_panic`, 벡터 47, `adb_watchdog`, `dbg_dispatch`), 새 함수는 `dbg_panic`·`dbg_dispatch`·`gdb_from_trap`·`dbg_from_ether`·`dbg_process`·`dbg_recv`·`dbg_ack`·`SENDEXC`·`inet_aton`(BSD 의 `inet_aton`; NeXTMach `nfs/nfs_bootsubr.c` 와 Darwin `Libc/net.subproj/inet_addr.c` 에 글이 있는 후보이나 이 파일의 본문은 원본 바이트로 쓴 꼴) 아홉입니다. NeXTMach 에만 있는 `dbg_exit`·`btoh`·`htobs`·`htob`·`kdbg`·`putnib`·`putpkt`·`ack`·`getnib`·`getpkt`·`gfunc`·`pfunc`·`kern_stext` 줄·`isxdigit` 등 매크로·`rmtdebug`·`<next/cpu.h>` 등 포함 줄은 1997 단위에 없어 지웁니다(`next/cpu.h` 는 C 포함 금지, PROVENANCE `1114`; `nextdev/kmreg.h` 는 쓰지 않음).

사용자 결정이 필요한 선택(바이트로 가려지지 않음; AskUserQuestion 으로 여쭙기): ① §737.2·§738.2 의 소스 꼴(`goto again`·`goto error`·`goto recv`, 빈 `else ;`, 쓰지 않는 지역 변수, `if (!x) return;` 꼴)을 그대로 쓸지, ② 이름: 구조체 `struct kdb_n`(`kn_ri`·`kn_ti`·`kn_locked`)·`dbg_pkt`·`dbg_hdr`(`seq`·`code`·`addr`·`len`·`dlen`·`data`), 정적 `dbg_nest`·`dbg_from_net`·`dbg_sig`·`dbg_fault_addr`·`dbg_vecoff`, 정적 함수 `dbg_recv`·`dbg_ack`(NeXTMach 에 이름이 있는 칸 `ri`·`ti`·`locked` 는 NeXTMach 이름을 쓰는 안), ③ 패킷 종류 번호와 영역 표 상수를 숫자 + 주석으로 둘지 상수 이름을 만들지, ④ 컴파일 경고 한 줄 `optimization turned off` 를 최종 명세의 `known_warnings` 로 정확히 기록할지(선례 `snd_unix`, `m4p646`).

방법(§736 의 순서):
1. 생성기 `gen_p739.py`(`gen_p736.py` 를 이 파일에 맞게)로 N1 에 표시를 넣은 F 와 주석을 지운 L 을 만들고(사용자 결정이 정해지면 이름·꼴을 반영해 N1 부터 다시 만들어 진단으로 다시 18/18 확인), 원본 검사기(`chk739.py`)로 F = L 토큰, L = N1 토큰, 표시 없는 줄이 NeXTMach 줄인지, NeXTMach 머리 고지 보존, BEGIN/END 수, 07 = F 를 확인합니다.
2. `stage_m68k.py`: `M4FILES[739] = list(M4FILES[736]) + ['nextdbg.c']`, `M4HEADERS[739] = list(M4HEADERS[736])`(새 머리 없음), `EXCEPTS[739] = dict(EXCEPTS[736])`, 머리말 `--plan` 목록에 739. 회귀: `--plan 736` 재생성이 보관 `m0p736-a1-stage` 와 같고 새 스테이지는 `src/machdep/m68k/nextdbg.c` 하나만 늘며, M5 205 줄 명령은 번호만 다르고, M5 `m3p739-cc1` 출력이 `m3p736-cc1` 과 `run.json` 만 다르고, x86 입력과 x86 게이트가 그대로여야 합니다.
3. 확인 run `m4p739-p2`(F, L): 경고는 위 한 줄뿐(F 와 L 의 줄 번호가 다를 수 있으므로 `known_warnings` 는 최종 F 의 줄을 그대로 적음), 18/18, 절 크기·`__cstring` 351 B 원본과 바이트 같음·`__bss` 오프셋·COMMON 이름과 크기, 원본에 없는 미정의 0, F = L = N1 의 `canon`·`obj_sig`. `-E` run `m4p739-e1`: F = L 전처리 토큰.
4. 최종 run `m4p739-a1`(`refs` = p2 의 L 객체, `bss_inferred: ["nextdbg"]`, `known_warnings`) 과 zerofill(후보 [0x40b55cc, 0x40b563c) 112 B; 앞서 받아들인 bss 자리와 겹침을 python 으로 확인), 확인 기록, 최종 객체의 함수별 비교 기록(`m68k_funcbytes.py … m4-m68k-funcbytes-p739-nextdbg-a1-20261106.json`, 최종 객체 SHA 연결)과 통합 확인 기록(`m4-m68k-p739-checks-20261106.json`), 증거 `m68k-nextdbg.md`·`.diff`(상태 도구가 문서의 존재를 단언하므로 상태 도구보다 먼저), 상태 도구(`ACCEPTED` 4 칸 항목, 두 번 돌려 같음), PROVENANCE 한 행(일곱 칸), MODIFICATIONS, DECISIONS D166, 계획 결과 절, HANDOFF, 기억.
5. 판정(미리 정함): 관문을 모두 통과해야 수락합니다. 기대(python 으로 확인): 객체 67 → 68, `CODE+BSS_INFERRED` 16 → 17, 덮은 행 91 → 93(행 304·305), 덮은 최소 바이트 131430 → 131430 + 82 + 3796 = 135308 B(인벤토리 `bytes_min` 값; 상태 도구 출력으로 확인). 하나라도 안 맞으면 기준을 낮추지 않고 멈춰 보고합니다.

위험(미리 적음): (가) 합친 한 파일의 `#endif\t0` 같은 NeXTMach 줄이 `-traditional-cpp` 에서 경고를 내는지(N1 컴파일은 경고 한 줄뿐이라 문제 없음). (나) `if_en.c`·`m68k_init.c`·`trap.c` 가 이 단위의 이름(`dbg_from_ether`, `gdb_from_trap`, `inet_aton`)을 부르므로 이름 충돌이 없어야 합니다(정의가 둘이 되지 않는지 `grep`; `m68k_dbginit` 는 07 C 파일이 부르지 않고 `nextdbgasm.s:27` 의 `jsr _m68k_dbginit` 만 부름). (다) `nextdbgasm.s` 의 `__m68k_dbginit`(밑줄 둘)은 새 C `_m68k_dbginit` 과 심볼이 다릅니다. (라) COMMON `dbg_connect_pkt`·`kdb_net`·`en_pkt` 는 이 파일이 `extern` 으로만 씀(정의 자리는 M7 의무).

### 739.1 §739 codex 교차검토(`gpt-6.1-sol`) 판정 (코딩 전, 2026-11-06)

먼저 제 잘못: (1) 상태 도구와 증거 문서의 순서를 뒤집어 적었습니다(`m4_m68k_status.py:199–200` 이 `06_reconstruction/evidence/m68k-<객체>.md` 의 존재를 단언함; §736 에서 같은 단언에 걸렸었음). (2) 최종 객체에 결부된 함수별 비교 기록을 빠뜨렸습니다. (3) 호출자 목록에 `m68k_dbginit` 를 넣었으나 07 의 C 파일은 부르지 않습니다. (4) 머리 고지 줄 범위는 1–10 행입니다.

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 증거 문서가 먼저 있어야 상태 도구가 통과 | §736 에서 같은 `AssertionError: 06_reconstruction/evidence/m68k-ev_mouse.md` 를 직접 겪음 | ✅ 본문 고침 |
| 최종 객체의 `funcbytes` 기록과 SHA 연결이 필요(선례 `m4-m68k-funcbytes-p736-ev_mouse-a1-20261105.json`) | §736 의 절차와 `m4_m68k_probe.py` 의 최종 gate 가 함수별 기록을 만들지 않음을 확인 | ✅ 본문 고침 |
| `m68k_dbginit` 호출은 `nextdbgasm.s:27` 뿐 | `grep -rIlw m68k_dbginit 07_kernel/src` 결과 이름 있는 파일 없음(asm 은 `_` 붙은 심볼이라 `-w` 검색에 안 걸림), `nextdbgasm.s:15–27` 을 열음 | ✅ 본문 고침 |
| 머리 고지 1–10 행 | NeXTMach `nextdbg.c` 1–12 행을 `cat -A` 로 열음(10 행 ` */`, 12 행 `#pragma CC_OPT_OFF`) | ✅ 본문 고침 |
| 기대값(93 행, 135308 B)과 bss 겹침 없음, `known_warnings` 형식 | codex 는 오류를 지적하지 않았고, 제가 python 으로 따로 확인: 행 304 `bytes_min` 82(`exact` 1)·행 305 3796(`exact` 0)로 91+2=93, 131430+3878=135308; zerofill 후보 33 개와 겹침 0 이고 [0x40b55cc, 0x40b563c) 가 `m68k_init`(0x40b55cc 에서 끝) 과 `nextdbgasm`(0x40b563c 에서 시작) 사이에 정확히 들어감; 선례 `08_build/artifacts/m4p646/spec.json` 의 `known_warnings` 는 `{객체: [stderr 줄…]}` 꼴이고 줄 번호·경로가 그대로 들어감 | ✅ (codex 침묵은 근거로 쓰지 않음) |

2 차 자기검사: ✅ 행은 이번 세션에 연 줄이거나 제가 돌린 python·명령 출력입니다.

### 739.2 결과: m68k `nextdbg.c` 수락 (CODE+BSS_INFERRED 18/18; D166; 2026-11-06)

사용자 결정(AskUserQuestion; D166): 바이트가 강제한 표기(`goto again`·`goto error`·`goto recv`·빈 `else ;`·쓰지 않는 지역 변수)를 그대로 씀; 이름은 `kdb_net` 의 세 칸에 NeXTMach 필드 이름 `ri`·`ti`·`locked` 와 나머지 프로젝트 이름; 패킷 종류·응답 코드는 `DBG_RQ_*`·`DBG_RP_*`, 영역 표 상수는 숫자; 컴파일 경고는 처음에 "다른 처리"(컴파일 줄에서 최적화 끄기)를 고르셨으나 시험(`m4p739-p2`·`p3a`·`p3b`·`p3c`)에서 `-O0` 18 중 1, `-O1` 0, 최적화 플래그 없음 1, pragma + `-w` 5 로 원본 바이트가 나오지 않아 약속대로 멈추고 다시 여쭈었고 "pragma + known_warnings" 로 재결정하셨습니다.

먼저 제 잘못: (1) 처음 시험 때 `m4p739-p3O1`·`p3ON` 처럼 대문자가 든 run ID 를 써서 `kr_run.py prepare` 가 거부했습니다(ID 는 소문자만; 만든 빈 스테이지와 명령 파일을 지우고 `p3a`·`p3b` 로 다시 함). (2) 확인 검사 도구를 복사하며 `ev_mouse` 의 bss 후보 값(0x40b4fb2…)을 그대로 두어 처음에 `zerofill` 검사가 거짓으로 나왔고(`ok: False`) 값과 크기(112 B)를 고쳐 다시 돌렸습니다(수락 판정에는 영향 없음; 원본 기록은 `[0x40b55cc, 0x40b563c)` 로 맞았음).

결과:
- 07 `src/machdep/m68k/nextdbg.c`(821 행, SHA-256 `f7811200…`) = 생성기 `gen_p739.py`(scratch)의 F. 증거 `06_reconstruction/evidence/m68k-nextdbg.md`·`m68k-nextdbg.diff`(NeXTMach 대비 1311 줄), PROVENANCE 한 행(일곱 칸, 중복 없음; 1237 → 1238), MODIFICATIONS(764 → 765), DECISIONS D166(169 → 170).
- 소스 검사: F = L 토큰, L = N3 토큰, NeXTMach 와 85 hunk 에서 표시 없는 바뀐 줄 0, 머리 고지·pragma(1–12 행) 보존, 07 = F.
- 스테이징: `--plan 736` 재생성(1023)이 보관 `m0p736-a1-stage` 와 같고 새 `m0p739-a1-stage`(1024)는 `nextdbg.c` 하나만 늘어남. x86 입력 변화 없음, x86 gate 는 `plan`·`tool_sha256` 만 다름, M5 `m3p739-cc1`: 출력 617 개가 `m3p736-cc1` 과 `run.json` 만 다르고 `compare` 의 `differ_unexpected`·`lost` 비어 있음.
- 확인 run `m4p739-p5`(F, L): 컴파일 줄마다 pragma 안내 한 줄, 18/18, 절 4768/351/112, `__cstring` 원본과 바이트 같음, COMMON 2(`client_pcb` 162 B·`client_running` 4 B)·미정의 22 모두 원본 기호표에 있음, F = L = N3 의 `canon`·`obj_sig`. `-E` run `m4p739-e1`: F = L 전처리 토큰, stderr 0.
- 최종 run `m4p739-a1`: `gate.ok`(`known_warnings` 줄이 정확히 같음), L1 `NOT_MATCH`(이유 `__DATA,__bss: unverified` 하나, `provisional`), funcbytes 18/18. zerofill: `reference-inferred`, 후보 [0x40b55cc, 0x40b563c) 112 B, 앞서 받아들인 bss 후보 33 개와 겹침 0(python; `m68k_init` 와 `nextdbgasm` 사이에 정확히 들어감). 확인 기록 `m4-m68k-p739-checks-20261106.json`(`ok`).
- 상태 도구(두 번 돌려 같음, 앞 행 그대로): 객체 67 → 68(OBJECT_MATCH 51, CODE+BSS_INFERRED 16 → 17), 덮은 행 91 → 93/188, 덮은 최소 바이트 131430 → 135308(62.68%), 객체 바이트 188236 → 193004(python: 131430 + 82 + 3796 = 135308, 188236 + 4768 = 193004; 미리 계산한 기대와 같음).

판정: 미리 정한 관문을 모두 통과해 받아들였습니다(D166). 남은 것은 M7 의무(COMMON `kdb_net`·`en_pkt`·`dbg_connect_pkt` 등 정의 자리, 정적 bss 의 최종 배치)와 다른 후보(`zs.c`, ADB 구역(행 209, 소스 없음), FPSP, `snd_link`, `locore.s`, `tty_pty` 꼬리)입니다.
