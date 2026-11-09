# 커널 소스 복원 작업계획 — 보관 §637–642

`02_plan/RECONSTRUCTION_PLAN.md` 의 §637–642(m68k M4 64 비트 정수 보조 함수 여섯과 공용 머리 `dword.h`(D145), `kernel_pmon.c`(D146))를 절 번호·내용 그대로 옮긴 보관본입니다(2026-10-31, D026 방식, 사용자 지시 “02_plan/RECONSTRUCTION_PLAN.md 문서를 알맞게 정리해주세요.”). 본문은 `---` 아래부터입니다.

---

## 637. M4-143 세부 계획 — 64 비트 정수 보조 함수 진단 D1(행 264·291·322; 07 변경 없음; 코딩 전, 2026-10-31)

확인한 사실(이번 세션; 원본 풀이 scratchpad `gnulib264.dis`·`gnulib291.dis`·`gnulib322.dis`, 로컬 `m68k-linux-gnu-objdump`; 수는 python):
- 세 행은 정확한 행(`exact` 1)이고 함수 일곱입니다(`06_reconstruction/m68k-functions.tsv`): 행 264 [0x4090d00, 0x4091080) 896 B = `__ashldi3` 76 + `__bdiv` 706 + 이름 없는 함수 0x409100e 114; 행 291 [0x40930fa, 0x4093192) 152 B = `__lshldi3` 76 + `__lshrdi3` 76; 행 322 [0x409aa2e, 0x409aaf6) 200 B = `__udivdi3` 100 + `__umoddi3` 100. 합 1248 B.
- §422 에서 이 넷(`__ashldi3`·`__lshrdi3`·`__udivdi3`·`__umoddi3`)은 도구 체인 `libcc.a` m68k 구성원과 NOT_MATCH 였고, `__bdiv`·`__lshldi3` 는 libcc 에 없으며 mk-108.1 에 정의가 없습니다. `01_resources` 에서 이 함수들의 몸체가 있는 글은 `next-gcc-2.7.2/libgcc2.c`(`__ashldi3`·`__lshrdi3`·`__udivdi3`·`__umoddi3` 만; `__bdiv`·`__lshldi3` 없음)뿐입니다. 이름만 나오는 곳은 `darwin01/objc/spec_sys`(libsys 의 "GNU library" 목록 1488–1507·2899–2922), `next-gcc-2.7.2/config/next/nextstep.def`(`#define __lshldi3 _lshldi3` 같은 이름 바꿈 줄, 39–42 등), 01_resources 의 기록 파일입니다(§637.1). 같은 이름의 파일은 어느 참고 트리에도 없습니다(`find -iname`).
- 원본 바이트의 꼴: (1) 이동 함수 셋은 이동 수를 `fp@(20)`(64 비트 둘째 인자의 아래 낱말)에서 읽습니다; (2) `__ashldi3` 와 `__lshldi3` 는 76 B 가 모두 같습니다; (3) `__udivdi3`·`__umoddi3` 는 지역 배열 넷(fp−16 의 16 B, fp−24·−32·−40 의 8 B)을 두고 `__bdiv(a, b, q, r, 16, 8)` 를 부르며 둘은 3 바이트(호출 변위 1, 몫/나머지 오프셋 2)만 다릅니다; (4) `__bdiv` 는 `alloca` 꼴로 스택에서 둘을 떼고(`(크기+3)&-4`), 이름 없는 함수(0x409100e)를 `lea`+`jsr a2@` 로 두 번, `bsrl` 로 한 번 부르며, 이 함수는 이동 수 0 이면 `_bcopy`(0x4092d2c)를 부릅니다; (5) 앞 0 자리를 빼는 고리에서 자리 수가 0 이 되면 `10 / n` 을 계산해 n 에 넣습니다(0 나눗셈); (6) 지역 공간이 0 인 함수의 프레임 세움 `pea fp@; movel sp,fp`(바이트 `4856 2c4f`)는 원본 `__text` 에 2514 번 나오는 커널 컴파일러의 보통 꼴입니다(python 셈). 이 모양은 GCC 1.x `gnulib2.c` 계열로 보이지만, 그 글은 01_resources 에 없고 확인하지 않았습니다.
- 호출: `__bdiv` ← `__udivdi3`·`__umoddi3`, 이름 없는 함수 ← `__bdiv`, `__udivdi3` ← 0x408c09e(`_zsselect` 0x408bc40 안); `__ashldi3`·`__lshldi3`·`__lshrdi3`·`__umoddi3` 를 바로 부르는 곳(`jsr abs.l`·`bsr` 셋 꼴, python 전수)은 원본 `__text` 에 없습니다(간접 호출은 이 검사 밖).

사용자 결정(이 절에서 여쭘, 구현 때 D145 로 적음): (a) 참고 원문을 들이지 않고 원본 바이트만으로 씁니다(D024); (b) 파일은 함수마다 하나(`ashldi3.c`, `bdiv.c`(이름 없는 정적 함수 포함), `lshldi3.c`, `lshrdi3.c`, `udivdi3.c`, `umoddi3.c`).

방법(진단 D1; 07 은 바꾸지 않음): 진단은 행마다 한 파일로 합니다(정확한 행 그대로라 기존 도구로 됨). 함수별 파일 나눔은 구현 단계에서 하고, 그때 도구를 고칩니다(아래).
- spec `08_build/artifacts/m4p637/spec.json`: 바탕 `08_build/runs/tools/m0p636-a1-stage`, `m5_line` `08_build/artifacts/m5p494/final.cmd`, 객체 셋 `g264`(m4_id `m68k-264`)·`g291`(`m68k-291`)·`g322`(`m68k-322`), `x86_rel` 은 m68k 전용 파일의 관례대로 `machdep/i386/dkbad.c`(§614 `shutdown` 과 같음). 변이: `g264` D(`alloca`)·D2(D 에서 `alloca` 를 `__builtin_alloca` 로), `g291` D·D2(이동 수를 무시하는 윗 낱말 `long` 과 `int` 로), `g322` D. 진단 글은 scratchpad 초안 `p637/g264_D.c`·`g291_D.c`·`g322_D.c` 를 `08_build/artifacts/m4p637/src/` 로 옮깁니다(머리 없음, 공용체 `dword_t`·정적 함수 이름 `shift_digits` 는 진단 이름; C 이름은 컴파일러가 붙이는 앞 `_` 를 뺀 `_ashldi3`·`_bdiv` 등).
- run `m4p637-p1`(REGISTRY 에 없음을 먼저 확인): `P stage` → `P cmd` → `K prepare/launch/wait` → `P compare`(`09_validation/reconstruction/m4-m68k-probe-p637-p1-20261031.json`) → 행마다 `m68k_funcbytes.py`(행 264 는 `0x409100e=_shift_digits`; 기록 `m4-m68k-funcbytes-p637-<변이>-20261031.json`).

측정: 종료 상태·경고, 함수별 길이·바이트 차이·재배치 대상, `l1_verdict`, 원본에 없는 미정의 기호(없어야 함; `_bcopy`·`__bdiv` 는 원본에 있음; `_alloca` 가 미정의로 나오면 D 는 내장이 아님). 0 자리 수에서의 `10 / n` 은 C 로는 정의되지 않은 동작이므로 `divul` 과 흐름이 그대로 나오는지 바이트로 봅니다.

판정(미리 정함; 07 은 바꾸지 않음): 결과를 적고, 다른 부분은 다음 진단에서 고칩니다. 모두 같으면 구현 계획(§638 이후)을 세웁니다: (1) `m4_m68k_probe.span` 이 정확한 행도 함수 표 경계에서 나눌 수 있게("partial", 지금은 `exact != '1'` 만 허용), (2) `m4_m68k_status` 가 나뉜 정확한 행을 받아들인 조각들이 빈틈없이 덮을 때만 그 행(행 수·`bytes_min`)을 셈. 지금 받아들인 나뉜 행(219·244·245·246·306·323·324)은 모두 `exact` 0 이라 이 규칙으로 바뀌는 수가 없음을 python 으로 확인했습니다. 바이트로 가려지지 않는 꼴(정적 함수 이름, 공용체·인자 이름, 이동 수 인자의 형)은 구현 전에 여쭙니다.

### 637.1 교차검토(codex `gpt-6.1-sol`, task kcee3rkxi) 판정과 계획 수정

제 잘못 둘: (1) 초안의 C 이름 `__bdiv` 등은 NeXT 컴파일러가 앞에 `_` 를 붙여 `___bdiv` 가 되므로 원본 기호 `__bdiv` 와 맞지 않습니다. (2) "이 이름은 spec_sys 와 libgcc2.c 에만 나옴" 은 틀렸습니다. 처음 grep 출력에 `nextstep.def` 가 있었는데 적지 않았습니다.

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| C 이름에 `_` 가 하나 더 붙음; `0x409100e=_shift_digits` 여야 funcbytes 가 짝지음 | `symbols.tsv:84,86`(`__ashldi3`·`__bdiv`), `:3057` `_trap`(C `trap`); `m68k_funcbytes.py:111–112,175–180` 이름을 글자 그대로 비교 | ✅ 초안 C 이름을 `_ashldi3`·`_bdiv`·`_lshldi3`·`_lshrdi3`·`_udivdi3`·`_umoddi3` 로, 매핑을 `_shift_digits` 로, 미정의 기대를 "없음" 으로 고침 |
| 크기·주소·`exact`·바이트 같음·다른 오프셋(0x4d·0x51·0x55)·2514 | 이번 세션 python 출력(76/706/114, 76/76, 100/100, 합 1248, 다른 오프셋 77·81·85 = 0x4d·0x51·0x55, 2514) | ✅ 수는 그대로. "프레임 없는" 을 "지역 공간이 0 인 함수의 프레임 세움" 으로 고침 |
| `__bdiv` 초안의 포인터·산술은 바이트와 맞음(최종 호출 인자 포함); `mulsl` 을 보고 부호 곱으로 바꾸지 말 것 | 제가 `gnulib264.dis:52–289` 를 줄마다 읽고 초안과 맞춘 것과 같음 | ⏭️ 행동 바뀜 없음(바이트가 판정) |
| `10 / n` 은 C 로 정의되지 않음 — 생성 코드를 바이트로 확인할 것 | `gnulib264.dis:66–71` 읽음 | ✅ 측정에 넣음 |
| 이동 수 `fp@(20)` 은 `long long` 둘째 인자를 증명하지 않음; 무시하는 윗 낱말 + 낱말 크기 수도 가능 | 두 꼴 모두 `fp@(20)` 을 읽음(인자 자리 셈) | ✅ `g291` D2 를 더함; 형은 구현 전 여쭘 |
| 정적 함수의 K&R `unsigned short carry_in`(fp+22) 이 맞음 | `gnulib264.dis:296–302` 읽음(`movew fp@(22),d0`); 호출 쪽은 `asrl` 결과를 `movel d0,sp@-` 로 마스크 없이 넣음(`:277–278`) | ✅ 그대로 둠 |
| 나눗셈 둘의 초안이 맞음; 그 밖의 꼴(포인터 커서, 비트 검사 꼴, 함수 포인터)은 가설 | 초안과 `gnulib322.dis` 대조(이번 세션) | ⏭️ D1 결과를 본 뒤 필요하면 씀 |
| `__udivdi3` 호출 자리 0x408c09e 는 `_zsselect`(0x408bc40) 안; 직접 호출 검사는 간접 호출을 다루지 않음 | `symbols.tsv:3614` 읽음(`_zsselect` 0x408bc40) | ✅ 글을 고침 |
| `nextstep.def` 에도 이름이 있음(`#define __lshldi3 _lshldi3` 등) | `nextstep.def:38–42` 읽음 | ✅ "몸체가 있는 글" 과 "이름만 나오는 곳" 으로 나눠 고침 |
| spec 구조는 지금 도구로 됨; `span()` 은 정확한 행 나눔을 `:176` 에서 막음; 나중 규칙은 빈틈없는 반열린 구간 덮음으로만 한 번 셀 것 | `m4_m68k_probe.py:69,150–184` 읽음; 기존 나뉜 행 일곱이 모두 `exact` 0(이번 세션 python) | ✅ 구현 계획에 그 조건(경계·겹침 검사 유지, 길이 합이 아니라 구간 덮음, 한 번만)을 적음 |

2차 자기검사: ✅ 행의 근거는 모두 이번 세션에 열거나 돌린 것입니다(`symbols.tsv`·`m68k_funcbytes.py`·`nextstep.def`·`gnulib*.dis`·python 출력).

### 637.2 결과(run `m4p637-p1`, 2026-10-31)

- 명령 열 모두 종료 0·경고 0, 의존 목록에 i386 머리 0, 원본에 없는 미정의 기호 0(`m4-m68k-probe-p637-p1-20261031.json`).
- `g291` D: **OBJECT_MATCH**(152 B, `__lshldi3`·`__lshrdi3` 바이트 같음; funcbytes `m4-m68k-funcbytes-p637-g291_D-20261031.json`). `g291` D2(이동 수를 무시하는 `long` + `int` 로)는 156 B 로 4 B 깁니다 — 이 꼴은 바이트로 배제되고 `long long` 이 맞는 후보입니다(다른 꼴을 모두 배제한 것은 아님; §638.1).
- `g322` D: **OBJECT_MATCH**(200 B, `__udivdi3`·`__umoddi3` 바이트 같음; `-g322_D-`).
- `g264` D·D2: 896 B, canon·`obj_sig` 가 서로 같음(`alloca` 가 내장으로 컴파일됨; `_alloca` 미정의 없음). `__ashldi3`·`_shift_digits` 같음, `__bdiv` 706 B 중 10 바이트 다름(재배치 대상 차이 0; `-g264-D-`·`-g264-D2-`). 다른 곳은 한 군데입니다: 두 자리 피제수를 만드는 else 갈래 [0x4090eae, 0x4090ec0) 안의 0x4090eb2–0x4090ebd. 원본은 `u0[j] << 16 | u1[j]` 를 d0 에서 만들어 d5 로 옮기고, 제수를 d1 에서 `andil #65535` 로 넓혀 `divull d1,d2:d5` 를 합니다. 우리는 피제수를 `acc`(d2)에 옮겨 만들고 제수를 d0 에 `clrl`+`movew` 로 넓힙니다. 원본은 이 피제수를 `acc` 가 아닌 따로인 값으로 둔 꼴로 보입니다. 0 자리 수의 `10 / n`(`divull d6,d7,d7`)은 원본과 같게 나왔습니다.

## 638. M4-144 세부 계획 — `__bdiv` 진단 E(두 자리 피제수; 07 변경 없음; 코딩 전, 2026-10-31)

확인한 사실: §637.2 의 차이는 `__bdiv` else 갈래 안 0x4090eb2–0x4090ebd 한 곳입니다(funcbytes 함수 오프셋 0x166–0x171, python 으로 주소 환산). 원본은 `(u0[j] << 16) | u1[j]` 를 d0 에서 만들어 d5 로 옮긴 뒤 `divull d1,d2:d5` 를 합니다. D 는 이 값을 `acc` 에 넣어 d2 로 옮겨 만듭니다(`acc` 는 빼기 고리의 누적값과 같은 변수).

방법(run `m4p638-p1`, 바탕 `m0p636-a1-stage`, spec `08_build/artifacts/m4p638/spec.json`(`plan` 638, `m5_line` `08_build/artifacts/m5p494/final.cmd`), 객체 `g264`(m4_id `m68k-264`, `x86_rel` `machdep/i386/dkbad.c`)): D 에서 그 else 갈래만 바꾼 변이 셋을 scratchpad `p637/g264_E1.c`–`E5` 에서 `08_build/artifacts/m4p638/src/` 로 옮깁니다.
- E1: 블록 지역 `unsigned long num = ((unsigned long)u0[j] << 16) | u1[j];` 뒤 `qhat = num / *v0; rhat = num % *v0;`
- E2: 변수 없이 같은 식을 몫·나머지에 두 번 씀
- E3: 함수 첫머리에 `num` 을 더 선언하고(E1 과 같은 식) 갈래 안에서 대입
- E4: 블록 지역 `num`·`den = *v0` 으로 나눗셈(§638.1)
- E5: `qhat` 에 피제수를 먼저 넣고 `rhat = qhat % *v0; qhat /= *v0;`(§638.1)

측정: 종료·경고, `l1_verdict`(`compare` 기록 `m4-m68k-probe-p638-p1-20261031.json`), funcbytes(`0x409100e=_shift_digits`, 기록 `m4-m68k-funcbytes-p638-<변이>-20261031.json`), 원본에 없는 미정의 0.

판정(미리 정함; 07 은 바꾸지 않음): OBJECT_MATCH 이고 세 함수가 모두 같은 변이를 찾습니다. 여럿이 맞으면 바이트로 가려지지 않는 꼴로 보고 구현 전에 여쭙니다. 하나도 맞지 않으면 결과를 적고 다음 진단을 세웁니다.

### 638.1 교차검토(codex `gpt-6.1-sol`) 판정과 계획 수정

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 원본은 d0 의 피제수를 d5 로 옮겨 `divull d1,d2:d5`; 다른 바이트는 0x4090eb2–0x4090ebd | `gnulib264.dis:162–167` 읽음; funcbytes `__bdiv` 첫 다름 오프셋 0x166–0x171 을 python 으로 0x4090eb2·0x4090ebd 로 환산 | ✅ §637.2·§638 글을 고침 |
| §637.2 의 측정(상태·크기·D=D2·g291 D2 156 B)은 맞음 | 이번 세션 `compare`·funcbytes 출력 | ✅ 바꿈 없음 |
| g291 D2 의 배제는 `long long` 을 유일하게 정하지 않음 | D2 는 꼴 하나만 시험함(초안 두 파일 읽음) | ✅ "맞는 후보" 로 고침 |
| E1–E3 는 else 갈래(E3 은 선언도)만 다르고 뜻이 같음 | 이번 세션 `diff g264_D.c g264_E1.c`·`E3` 출력; E2 는 같은 식을 두 번 읽음(사이에 쓰기 없음) | ✅ |
| spec 에 `plan` 638·`m5_line` 을 적고 compare 기록 이름을 밝힐 것; `m4p638-p1` 은 안 쓰임 | `m4_m68k_probe.py:59`(필수 키); `REGISTRY` 끝 줄 `m4p637-p1` | ✅ 글에 넣음 |
| 꼴 둘 더(블록 지역 `num`·`den`; `qhat` 에 피제수를 먼저) | 코드 생성 가설일 뿐 | ⚖️ E4·E5 로 더함(바이트가 판정) |

2차 자기검사: ✅ 행의 근거는 이번 세션에 연 `gnulib264.dis`·funcbytes 기록·`m4_m68k_probe.py`·`REGISTRY` 와 python 출력입니다.

### 638.2 결과(run `m4p638-p1`, 2026-10-31)

- 명령 열 모두 종료 0·경고 0, 원본에 없는 미정의 0(`m4-m68k-probe-p638-p1-20261031.json`).
- **E1·E2·E3·E4: OBJECT_MATCH**(896 B, 세 함수 모두 바이트 같음; funcbytes `m4-m68k-funcbytes-p638-E1`…`-E4-20261031.json`). 넷은 canon 이 서로 같고 `obj_sig` 만 다릅니다(`-g` 의 변수 기록 차이). E5(`qhat` 에 피제수를 먼저)는 874 B 로 NOT_MATCH 입니다.
- 판정(미리 정한 대로): 피제수를 `acc` 가 아닌 따로인 값으로 다루는 꼴은 바이트가 정하고, E1–E4 사이의 고름은 바이트로 가려지지 않으므로 구현 전에 여쭙니다. §637 과 합쳐 일곱 함수 모두 맞는 꼴을 찾았습니다(행 291 D, 행 322 D, 행 264 E1–E4).

## 639. M4-145 D145 구현 계획 — 07 64 비트 정수 보조 함수 여섯 파일과 공용 머리(행 264·291·322, OBJECT_MATCH; 코딩 전, 2026-10-31)

사용자 결정(D145 로 적음): ① 참고 원문을 들이지 않고 원본 바이트만으로 씀(D024); ② 함수마다 한 파일; ③ `__bdiv` 의 두 자리 피제수는 E1(블록 지역 `num`); ④ 정적 함수 이름 `shift_digits`; ⑤ 64 비트 공용체는 새 공용 머리 하나; ⑥ "모양은 GCC 1.x `gnulib2.c` 계열로 보이나 그 글은 들이지도 대조하지도 않음, 라이선스 판단은 사용자 몫" 을 파일 머리와 기록 모두에 적음. 바이트가 정한 것: 이동 수 인자 `long long`(§637.2 D2 배제, 후보), 피제수를 `acc` 와 따로 둠(§638.2).

확인한 사실(이번 세션):
- 07 `src/machdep/m68k/` 에 이 여섯 파일·머리는 없고, 스테이지(`m0p636-a1-stage` 976 파일)와 07 에 `dword` 이름은 없습니다(python·grep).
- `stage_m68k.py` 는 `07_kernel/src/machdep/m68k` 의 모든 파일이 `M4FILES` 에 있어야 하고(558 행) 그 파일은 `.c`·`.s` 여야 합니다(561 행). `M4HEADERS` 는 뿌리 `07_kernel/src` 를 받습니다(546 행, plan 554). x86 스테이지(`stage_headers.py`)는 x86 원천의 포함 닫힘만 들이므로 이 머리를 읽지 않습니다.
- `m4_m68k_probe.span` 은 정확한 행을 "partial" 로 받지 않습니다(176 행). `m4_m68k_status` 는 `rows` 로 덮은 행만 셉니다(147–148·157–163 행).
- 상태 기대(python): 객체 42 + 6 = 48(OBJECT_MATCH 39, CODE+BSS_INFERRED 9), 행 71 + 3 = 74/188, 덮은 바이트 69390 + 1248 = 70638(32.72%), `object_bytes` 86592 + 1248 = 87840, `rows_unassigned_before` 에 `m68k-264`·`m68k-291`·`m68k-322` 를 더함.

1. 도구(07 전, 각각 회귀):
   a. `stage_m68k.py`: `M4SRC` 의 `.c`·`.s` 아닌 파일은 어느 계획이든 `M4HEADERS` 표에 뿌리 `07_kernel/src`·경로 `machdep/m68k/<이름>` 으로 적힌 것만 허용(그 밖은 지금처럼 멈춤; `.c`·`.s` 가 모든 계획의 `M4FILES` 합으로 검사되는 것과 같은 방식). 스테이지에 복사하는 머리는 지금처럼 고른 계획의 `M4HEADERS` 뿐입니다(§639.1). `M4FILES[639] = M4FILES[636] + ['ashldi3.c', 'bdiv.c', 'lshldi3.c', 'lshrdi3.c', 'udivdi3.c', 'umoddi3.c']`, `M4HEADERS[639] = M4HEADERS[600] + [('machdep/m68k/dword.h', 'src/machdep/m68k/dword.h', '07_kernel/src')]`, `EXCEPTS[639] = dict(EXCEPTS[636])`, 머리말 목록에 639. 옛 계획의 목록은 그대로라 옛 스테이지는 바뀌지 않아야 합니다.
   b. `m4_m68k_probe.span`: 정확한 행도 "partial" 로 받음(나머지 검사 — 함수 표 경계, 빈틈 없음, 겹치는 행 목록 일치, 범위 끝이 그 행 안 — 는 그대로).
   c. `m4_m68k_status`: 모든 기록·객체를 다 읽은 뒤 한 번에, 나뉜 정확한 행마다 그것을 "partial" 로 적은 받아들인 객체들(기록이 달라도)의 구간을 그 행의 반열린 구간 [시작, 끝) 으로 잘라 빈틈없이 덮을 때만 한 번 셈(행 수와 `bytes_min`; 길이 합이 아니라 구간 덮음으로 판단; 이미 `rows` 로 센 행이면 멈춤; 객체 구간 겹침 검사와 "row twice" 검사는 그대로). 요약에 `rows_tiled` 목록을 더함(`partial_rows` 에는 지금처럼 남음). `exact` 0 인 나뉜 행은 지금처럼 세지 않음. 덮음 판정 함수는 python 으로 빈틈·겹침·기록이 다른 조각·기록 차례를 뒤집음·온 행과 조각이 함께인 경우를 시험합니다.
   회귀: 지금 `ACCEPTED` 로 상태 도구를 돌려 표(tsv)가 `m68k-m4-status.tsv` 와 같고 요약은 `rows_tiled` [] 말고 같음; 받아들인 기록 37 개(나뉜 행이 있는 것은 §538·§559·§563·§566·§579·§618) 명세의 모든 `m4_id` 에 대해 옛·새 `span` 결과가 같음을 python 으로 확인.
2. 07 파일(생성 scratchpad `gen_p639.py`):
   - `src/machdep/m68k/dword.h`: `dword_t` 공용체(`long long ll`, `struct { long high, low; } s`, m68k 낱말 차례) 하나와 머리 주석.
   - `ashldi3.c`·`lshldi3.c`·`lshrdi3.c`·`udivdi3.c`·`umoddi3.c`: `#import <machdep/m68k/dword.h>` 와 진단 D(§637)의 그 함수; `udivdi3.c`·`umoddi3.c` 는 `extern void _bdiv();`. `bdiv.c`: 진단 E1(§638)의 `_bdiv`·`shift_digits`(`bcopy`·`shift_digits` 선언 포함, 공용체 없음).
   - 머리 주석(파일마다): 경로, 원본 범위와 함수, "written from the original bytes (D024, D145)", 결정 ⑥ 의 문장, plan 639. 함수 줄에 `plan 639 (D024, D145): from the original bytes 0x…` 표시. 주석을 뺀 토큰이 진단 글의 그 함수 부분(머리는 공용체 typedef 를 넣은 꼴)과 같아야 합니다(python).
3. 회귀: `--plan 636` 재생성 = 보관본; 새 스테이지 `m0p639-a1-stage` 와 636 보관본의 차이는 새 파일 일곱과 키 `plan`·`m4_sources`·`m4_headers`·`files`; M5 205(`m5-636.cmd` 와 새 줄, 두 run 의 객체·stderr 같음, `compare` 의 `differ_unexpected`·`lost` 빔); x86(`m4_x86_inputs.py s6ln`, `--plan 639 x86gate`).
4. 확인 run `m4p639-p1`(바탕 `m0p639-a1-stage`): 객체 여섯, 각 F = `@machdep/m68k/<이름>.c`, L = 그 함수의 진단 글에서 공용체 typedef 대신 F 와 같은 `#import <machdep/m68k/dword.h>` 를 두고(`bdiv` 는 머리 없음) 줄 번호가 F 와 같도록 맞춤 주석 줄을 넣은 꼴(같은 머리라야 STABS 수·줄 기술자가 같음; §639.1). `m4_id` 는 명시 구간(`{"range", "rows": [], "partial": [행], "basis"}`): `ashldi3` [0x4090d00, 0x4090d4c)·`bdiv` [0x4090d4c, 0x4091080) 행 264, `lshldi3` [0x40930fa, 0x4093146)·`lshrdi3` [0x4093146, 0x4093192) 행 291, `udivdi3` [0x409aa2e, 0x409aa92)·`umoddi3` [0x409aa92, 0x409aaf6) 행 322; `x86_rel` `machdep/i386/dkbad.c`. 판정: 종료 0·경고 0·i386 0, 객체마다 F·L `OBJECT_MATCH` 사유 없음·`full_span`·`candidate`, F = L 은 canon 과 문자열 표 앞 바이트(`n_strx`·문자열 표 크기 말고)로(§636.2 의 방법), funcbytes 모든 함수 같음(`bdiv` 는 `0x409100e=_shift_digits`). `-E` 토큰 run `m4p639-e2`: `P cmd` 는 `-E` 를 만들지 않으므로 §636 처럼 `preproc.cmd` 를 따로 만듦(`-c`→`-E`, `.o`→`.i`); F·L 의 `#` 줄 뺀 토큰이 같고, 진단 글(typedef 를 파일 안에 둔 꼴)의 그 함수 부분 `-E` 토큰과도 같음.
5. 최종 run `m4p639-a1`(명세 `08_build/artifacts/m4p639/spec.json`: F 만, `refs` = p1 의 L 객체와 SHA): `gate.ok`. 확인 기록 `m4-m68k-p639-checks-20261031.json`: 객체마다 `__text` 크기, 자료 절 없음(있으면 적음), 재배치 대상(funcbytes), 외부 정의가 원본 주소에, `bdiv` 의 지역 `_shift_digits` 가 `__bdiv`+706, 미정의 기호가 모두 원본에 있음, 컴파일 줄이 M5 줄과 같음, 의존 파일에 i386 머리 없음.
6. 상태표: 근거 `06_reconstruction/evidence/m68k-<객체>.md` 여섯(상태 도구가 객체마다 요구)을 먼저 쓰고 `ACCEPTED` 에 한 줄. 상태 도구 두 번, 기대는 위 python 값.
7. 기록: PROVENANCE 일곱 행(일곱 칸, 출처 `authored`, 결정 ⑥ 문장), MODIFICATIONS, DECISIONS D145, 계획·HANDOFF·메모리.

관문: 명령 종료 0, 경고 0, i386 0, 회귀 같음, 상태 도구가 멈추지 않음. 미리 정한 판정 기준은 결과를 본 뒤 바꾸지 않습니다(바꿔야 하면 여쭙니다).

### 639.1 교차검토(codex `gpt-6.1-sol`, task k7jh4llti) 판정과 계획 수정

제 잘못 둘: (1) 머리 허용 규칙을 "그 계획의 `M4HEADERS`" 로 적어, `dword.h` 가 생기면 옛 계획(497–636)의 스테이지 재생성이 멈춥니다. (2) L 에 typedef 를 파일 안에 두면 F(머리를 읽음)와 STABS 가 달라져 F = L 비교가 깨집니다.

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 계획별 허용이면 옛 계획 스테이지가 `on_dir` 검사에서 멈춤; 모든 표에 적힌 머리를 허용하고 복사는 고른 계획 것만 | `stage_m68k.py:557–558`(`.c` 는 모든 계획 `M4FILES` 의 합으로 검사) 읽음 | ✅ 1a 를 고침 |
| 덮음 셈은 모든 기록을 읽은 뒤 한 번에; 빈틈·겹침·다른 기록·차례·온 행+조각 시험 | `m4_m68k_status.py:146–148`(객체 고리 안 "row twice"), `:157` 읽음 | ✅ 1c 를 고침 |
| F/L 바이트 관문에 STABS 가 걸림(`obj_sig` 는 STABS 수, 문자열 표 앞 바이트는 기술자까지) | `l2_prefix_diff.py:48–53`(`stabs` 수) 읽음 | ⚖️ 머리 줄 맞춤 대신 L 도 같은 머리를 `#import` 하게 고침(머리 STABS 가 같아짐); 줄 맞춤은 그대로 |
| 받아들인 기록은 37 개이고 나뉜 행 기록은 §538·§559·§563 도 있음 | `m4_m68k_status.py` `ACCEPTED` 37 줄, 상태 tsv 의 `partial_rows` 칸(§637 에서 python 으로 읽은 일곱 행의 객체: `nextdbgasm`·`snd_dspcmd`·`snd_dspdev`·`snd_dspqueue`·`fd_cmds`·`vm_machdep`) | ✅ 1 회귀 글을 고침. 숫자 37 은 구현 때 python 으로 다시 셈 |
| `P cmd` 는 `-E` 를 만들지 않음 — §636 처럼 `preproc.cmd` 를 따로 | `08_build/artifacts/m4p636/confirm/preproc.cmd` 있음(ls) | ✅ 4 에 적음 |
| `refs` 는 객체마다; 근거 문서도 객체마다; `bdiv` funcbytes 는 매핑 유지 | 계획 5·6 에 이미 있음; `m68k_funcbytes.py:111–112` | ✅ 매핑을 4 에 적음 |
| 수(76·820·76·76·100·100, 합 1248; 48·39·9, 74/188, 70638, 32.72%, 87840)와 세 행은 정확한·미배정 행; 새로 덮은 세 행도 `partial_rows` 에 남음 | §639 의 python 출력(이번 세션); `m4_m68k_status.py:161` 읽음 | ✅ `partial_rows` 문장을 1c 에 넣음 |
| 머리 자리·소비 도구에 다른 막힘 없음; 상태의 머리 해시 검사가 새 머리도 지킴 | `grep` 으로 `M4FILES`·`M4HEADERS`·`machdep/m68k` 를 읽는 도구 다섯(`stage_m68k` 와 옛 계획 도구 넷 — 07 이 아니라 옛 스테이지를 읽음) | ✅ 바꿈 없음. 상태의 머리 해시 검사는 구현 뒤 실제로 돌려 확인 |
| `<machdep/m68k/dword.h>` 는 `-Isrc/src` 로 풀림; 진단의 선언 꼴을 그대로 둘 것 | M5 줄의 `-Isrc/src`(이번 세션 출력); 기존 `#import <machdep/m68k/eventc.h>` 선례 | ✅ 2 에 이미 있음 |

2차 자기검사: ✅ 행의 근거는 이번 세션에 연 `stage_m68k.py`·`m4_m68k_status.py`·`l2_prefix_diff.py`·`m68k_funcbytes.py`·`preproc.cmd`·M5 줄과 python 출력입니다.

### 639.2 결과(2026-10-31)

- 1 도구: `stage_m68k.py` 731 → 739 행(`M4FILES[639]`·`M4HEADERS[639]`·`EXCEPTS[639]`, `M4SRC` 머리 허용 규칙, 머리말), `m4_m68k_probe.py` 480 → 479 행(정확한 행 나눔 허용, 머리말), `m4_m68k_status.py` 178 → 199 행(`tiled_rows`, `rows_tiled`, `ACCEPTED` 한 줄). `tiled_rows` 시험(python): 두 조각·차례 뒤집음·셋·행 밖으로 나간 조각을 잘라 덮음은 덮음, 빈틈·한 조각·`exact` 0 은 아님, 겹침은 멈춤. 받아들인 기록 37 개의 객체 42 개 모두 새 `span` 결과(범위·행)가 상태표와 같고, 이 계획 전 `ACCEPTED` 로 돌린 상태표(tsv)가 그대로, 요약은 `rows_tiled` [] 만 더해짐.
- 2 07: `ashldi3.c`·`lshldi3.c`·`lshrdi3.c` 38 행, `udivdi3.c`·`umoddi3.c` 36 행, `bdiv.c` 130 행, `dword.h` 19 행(scratchpad `gen_p639.py`; 머리를 펼친 주석 뺀 토큰이 진단 글의 그 부분과 같음).
- 3 회귀: `--plan 636` 재생성(`m0p636-r639-stage`)의 manifest 가 보관본과 바이트까지 같고 트리 해시 어긋남 0; `m0p639-a1-stage`(983 파일)는 새 파일 일곱과 키 `plan`·`m4_headers`·`m4_sources`·`files` 만 다름. `--plan 636 cmd` 가 §636 의 `m5-636.cmd` 와 같고 `m5-639.cmd` 는 636→639 만 다름. M5 205(run `m3p639-b636`·`m3p639-cc1`): 객체 205·stderr 205 같음, `compare`(`m3-m68k-p639-compare-20261031.json`·`-b636-`) `differ_unexpected`·`lost` 빔, 요약 차이는 `stage_vs_test_stage` 에 새 파일 일곱뿐. x86: `m4-x86-inputs-p639-20261031.json` `ok`, `--plan 639 x86gate` 일곱 묶음 같음·`v183.34` 경로 0.
- 4 확인 run `m4p639-p1`(`m4-m68k-probe-p639-p1-20261031.json`): 명령 24 개 종료 0·경고 0·i386 0, 객체 여섯의 F·L 모두 `OBJECT_MATCH` 사유 없음·`full_span`·`candidate`, F = L(canon·`obj_sig`); 문자열 표 앞 바이트 차이는 `n_strx` 뿐(파일 길이 같음), 기호 이름은 원천 경로를 바꿔 넣으면 같음. funcbytes(`m4-m68k-funcbytes-p639-<객체>-F/L-20261031.json`) 모든 함수 같음. L 은 진단 글의 코드 줄을 07 줄 번호에 둔 꼴(scratchpad `gen_p639L.py`, 코드 줄이 진단 글에 차례대로 있음을 python 으로 확인). `-E` run `m4p639-e2`(`m4-m68k-p639-e2-20261031.json`): 열두 출력 stderr 0, F·L·진단 글(typedef 포함 그 부분)의 C 토큰이 모두 같음(173·173·173·186·186·748), i386 줄 0.
- 5 최종 run `m4p639-a1`(`m4-m68k-p639-final-20261031.json`, SHA `26e09799…`): `gate.ok`(명령·i386·candidate·REF 같음). funcbytes `m4-m68k-funcbytes-p639-a1-<객체>-20261031.json` 모든 함수 같음. 확인 `m4-m68k-p639-checks-20261031.json`(`ok` 참): 객체마다 `__TEXT,__text` 한 절(76·820·76·76·100·100), 외부 정의가 원본 주소에, `bdiv` 의 지역 기호는 `_shift_digits`(+706) 하나, 미정의는 `_bcopy`(bdiv)·`__bdiv`(udivdi3·umoddi3)로 모두 원본에 있음, 재배치 `bdiv` 3·나눗셈 둘 1·이동 셋 0, 컴파일 줄의 `-D`·`-I` 가 M5 줄과 같음.
- 6 상태(`m4-m68k-status-p639-20261031.json`, 표 44 → 50 행; 두 번 돌려 같음): 객체 48(OBJECT_MATCH 39, CODE+BSS_INFERRED 9), 행 74/188, 덮은 바이트 70638(32.72%), `object_bytes` 87840, `rows_tiled` `m68k-264`·`m68k-291`·`m68k-322`, `rows_unassigned_before` 에 세 행 더함 — 미리 계산한 값과 같음. 근거 `06_reconstruction/evidence/m68k-{ashldi3,bdiv,lshldi3,lshrdi3,udivdi3,umoddi3}.md`.
- 7 기록: PROVENANCE 1191 → 1198 행(일곱 칸, 경로 겹침 없음, `authored`), MODIFICATIONS 727 → 734 행, DECISIONS D145(148 → 149 행).

판정(미리 정한 대로): 관문을 모두 통과해 받아들였습니다(D145).

## 640. M4-146 세부 계획 — 행 276 PMON 함수(`kernel_pmon.c`) 진단 A–D(07 변경 없음; 코딩 전, 2026-10-31)

고른 까닭: 남은 정확한 행 가운데 작고(566 B) 자료 주인이 분명합니다. §532(보관본 `plans/RECONSTRUCTION_PLAN-525-538.md:344`)에서 "참고 글 없음" 으로 미뤘지만, 본문은 원본 바이트로 쓸 수 있습니다(D024, D145 와 같은 처리).

확인한 사실(이번 세션; 원본 풀이 scratchpad `pmon276.dis`, 로컬 `m68k-linux-gnu-objdump`; 수는 python):
- 행 `m68k-276` 은 정확한 행(`exact` 1)이고 [0x4092a1a, 0x4092c50) 566 B 에 함수 다섯입니다(`06_reconstruction/m68k-functions.tsv`): `_kpmon_null` 8, `_pmonlogevent` 204, `_pmonlogcontext` 104, `_pmonlogexec` 142, `_pmonlogcontextflush` 108(합 566). 앞은 `kern_machdep`(끝 0x4092a1a), 뒤는 `libc`(시작 0x4092c50) 입니다.
- 파일 이름: NeXTMach `conf/files.NeXT:15` `next/kernel_pmon.c optional debug`. NeXTMach `next/kernel_pmon.c`(28 행)는 `#ifdef PMON` 안에 `int pmon_flags[PMON_KERNEL_SOURCES_MAX];`·`void(*pmon_event_log_p)() = kpmon_null;`·빈 `kpmon_null()` 만 둡니다. `PMON` 은 `next/kernel_pmon.h:13–15` 에서 `DEBUG` 일 때만 정의됩니다. m68k 컴파일 줄(`m5p494/final.cmd`)에는 `-DDEBUG` 가 없습니다(07 `fd_subr` 는 `pmon_log_event` 빈 매크로로 코드가 원본과 같음 — CODE+BSS_INFERRED, `l1_verdict` NOT_MATCH 는 bss 미검증 때문; §640.1). `_pmonlogevent`·`_pmonlogcontext`·`_pmonlogexec`·`_pmonlogcontextflush`·`_vm_saved_context_*`·`_vm_flushed_thread`·`_periodic_vminfo` 는 `01_resources` 어디에도 없습니다(`grep -rIl` 0 건).
- `__data` [0x40b28da, 0x40b28ee) 20 B 는 이 객체 것으로 봅니다(근거가 강한 추정이고, 원본 번역 단위를 바이트로 되찾은 것은 아님; 파일 이름 `kernel_pmon.c` 도 같은 뜻의 재구성 이름): 원본 외부 기호 `_vm_saved_context_flushed`(0x40b28da)·`_vm_saved_context_thread`·`_vm_flushed_thread`·`_periodic_vminfo`(각 4 B, 값 0)·`_pmon_event_log_p`(0x40b28ea, 값 0x4092a1a = `_kpmon_null`). 앞 `clock` 의 `__data` 72 B 가 0x40b28da 에서 끝나고(`m68k-clock.md`), 뒤 `machargs` 의 `__data` 가 0x40b28ee 에서 시작하며(`m68k-machargs.md`), 그 사이 받아들인 객체(`machine_clock`·`cons`·`dkbad`·`in_cksum`·`kdp_machdep`·`kern_machdep`·`libc`·`lshldi3`·`lshrdi3`)에는 `__data` 가 없습니다(run `m4p622-r1`·`m4p639-a1` 객체의 절 크기). `_vm_flushed_thread`·`_periodic_vminfo` 를 가리키는 4 바이트 주소는 원본 `__text`·`__data` 에 없습니다(python 전수; 계산된 주소·간접 경로까지 배제하지는 못함).
- `__common`: `_vm_saved_context_data0`(0x40c947c, 2 B)·`_data1`(2 B)·`_name`(0x40c9480, 12 B) 는 원본에서 이 행만 글자 그대로의 주소로 씁니다(같은 한계). 자리가 `clock` 의 COMMON `_new_clock_chip`(0x40c9478) 바로 뒤, `machargs` 가 처음 언급하는 `_astune_calls`(0x40c948c) 앞이라 B2-1 규칙(§397·§399)과 맞습니다(m4p622-r1 객체의 기호표). `_pmon_flags` 는 다음 기호 `_vm_info_zone` 까지 160 B(int 40 개 자리; 원본 nlist 에 COMMON 요청 크기는 남지 않아 선언 크기는 미확인)인데 NeXTMach `PMON_KERNEL_SOURCES_MAX` 는 100(`next/pmon_ipc.h:139`, 400 B)입니다. 이 행은 `_pmon_flags` 를 쓰지 않고, 처음 언급자는 `kern_exec` 입니다(§445; 정의는 미뤄 둠).
- 호출: `_pmonlogexec` ← `kern_exec`(§445), `_pmonlogevent`·`_pmonlogcontextflush` ← `vm_fault`·`vm_pageout`(§446–447), `_pmonlogevent` ← 같은 파일의 `_pmonlogexec`·`_pmonlogcontextflush`(`lea` + `jsr a2@` 두 번). `_kpmon_null` 은 `_pmon_event_log_p` 의 초깃값으로만, `_pmonlogcontext` 를 가리키는 주소는 원본에 없습니다(python 전수).
- `_pmonlogevent` 의 시각 읽기는 m68k 덮어쓰기 `machdep/m68k/eventc.h` 의 `event_set_ts`(D091, §473) 와 같은 차례입니다: `splusclock`(`movew #0x2600,sr`), `eventc_latch` 읽고 버림, `eventc_h`·`_m`·`_l` 을 모아 `EVENT_MASK`, `event_middle` 맞춤, `high_val`(+4) ← `*event_high`, `low_val`(+0) ← `low | *event_middle`, `splx`. 기호 주소는 원본 기호표(`_eventc_h` 0x40c2b70 … `_event_middle` 0x40b2ba2)로 확인했습니다.
- 0x40c32c2·0x40c2c0e 는 `_vm_page_wire_count`(0x40c32c0)·`_vm_page_free_count`(0x40c2c0c, 둘 다 4 B int)의 아래 낱말입니다 → `unsigned short` 로 줄인 값. `(x << 16) | y` 는 `swap; clrw; orw` 이라 y 는 부호 늘림이 없습니다. 이름 꼬리 12 자를 고르는 고리 뒤 `_strncpy`(0x4093036, `libc`)를 `n = 12` 로 부릅니다.

방법(진단 A–D; 07 은 바꾸지 않음):
- spec `08_build/artifacts/m4p640/spec.json`: 바탕 `08_build/runs/tools/m0p639-a1-stage`, `m5_line` `08_build/artifacts/m5p494/final.cmd`, 객체 `pmon`(m4_id `m68k-276`, `x86_rel` `machdep/i386/dkbad.c`). 진단 글은 scratchpad `p640/pmon_A.c`…`pmon_D.c` 를 `08_build/artifacts/m4p640/src/` 로 옮깁니다.
  - A: `<next/kernel_pmon.h>`·`<kern/time_stamp.h>`·`<machdep/m68k/eventc.h>`·`<vm/vm_page.h>` 와 `extern char *strncpy();`, 자료는 원본 차례(0 넷, `pmon_event_log_p`), COMMON 셋(`unsigned short` 둘, `char [12]`), `pmon_flags` 정의 없음, `#ifdef PMON` 없음, `thread` 는 `int`, 꼬리 고리 `for (cp = name + 1; *cp; cp++) ;` + `i = 0; while (--cp > name && ++i < 12) ;`, 둘째 호출의 인자는 `((int *)buf)[0..2]`.
  - B: A 의 첫 고리를 `cp = name; while (*++cp) ;` 로.
  - C: A 의 `thread`·`vm_saved_context_thread` 를 `thread_t` 로(`<kern/thread.h>`).
  - D: A 에서 `<vm/vm_page.h>` 대신 지역 `extern int vm_page_wire_count, vm_page_free_count;`.
  - C0: C 에서 `<kern/thread.h>` 를 뺀 것(`thread_t` 는 A 의 머리 사슬 `vm/vm_page.h:72` → `kern/sched_prim.h:64` → `kern/kern_types.h:79` 로 이미 보임; 형만 바꾼 대조, §640.1).
  - E: A 의 `pmonlogcontextflush` 둘째 호출을 `tail = (int *)(vm_saved_context_name + 8);` 과 `tail[-2]`·`[1]`·`tail[0]` 으로(원본 `lea name+8,a0` 대조).
  - F: A 에서 `vm_saved_context_name` 을 `int [3]` 으로(`strncpy` 에 `(char *)`).
  - G: A 에서 `strncpy` 를 프로토타입 선언 `(char *, const char *, unsigned long)` 으로(`kernserv/prototypes.h:110` 과 같은 꼴).
- run `m4p640-p1`(REGISTRY 에 없음을 확인함): `P stage` → `P cmd` → `K prepare/launch/wait` → `P compare`(`09_validation/reconstruction/m4-m68k-probe-p640-p1-20261031.json`) → 변이마다 `m68k_funcbytes.py`(기록 `m4-m68k-funcbytes-p640-<변이>-20261031.json`).

측정: 종료 상태·경고, 함수별 길이·바이트 차이·재배치 대상, `l1_verdict`, `__data` 20 B(값과 재배치 `_kpmon_null`), COMMON 이름·크기, 원본에 없는 미정의 기호(없어야 함). 도구의 종료 상태는 일치 판정이 아니므로(`refs` 없는 `P compare` 는 `diag_gate` 만, `m68k_funcbytes.py` 는 차이가 있어도 0 으로 끝남) JSON 칸을 python 으로 읽어 판정합니다. COMMON·정의 기호는 `undefined_not_in_original` 로는 드러나지 않으므로 기록의 `defined_symbols` 를 따로 봅니다: 바깥 정의는 `__text` 다섯 함수와 `__data` 다섯 이름뿐이고, COMMON 은 `_vm_saved_context_data0`(2)·`_data1`(2)·`_name`(12) 셋뿐이어야 합니다. `__data` 는 L1 과 따로 python 으로 바이트·기호 차이·재배치 대상을 봅니다. 실제 컴파일 명령은 `x86_rel` 틀에서 나오므로 그 명령을 기록합니다.

판정(미리 정함; 07 은 바꾸지 않음): 결과를 적고, 다른 부분은 다음 진단에서 고칩니다. A 의 다섯 함수와 `__data` 가 모두 같으면 구현 계획을 세웁니다. 바이트로 가려지지 않는 꼴(B·C·D 가 A 와 같을 때의 선택, `pmon_flags` 정의를 둘지와 그 크기, `#ifdef PMON` 처리, `vm_flushed_thread`·`periodic_vminfo` 의 형, 인자 이름)은 구현 전에 여쭙니다.

### 640.1 교차검토(codex `gpt-6.1-sol`, task ku24lgses) 판정과 계획 수정

내가 틀린 것: "07 `fd_subr` 가 … OBJECT_MATCH" 는 틀렸습니다. 상태표(`06_reconstruction/m68k-m4-status.tsv:10`)와 기록(`m4-m68k-p570-final-20261030.json:819–821`)은 `l1_verdict` NOT_MATCH, 까닭 `__DATA,__bss: unverified`(CODE+BSS_INFERRED, D128)입니다. 문장을 고쳤습니다. 결론(빈 매크로라 `-DDEBUG` 가 없다는 것)은 그대로입니다.

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| `fd_subr` 는 OBJECT_MATCH 가 아님 | 기록 815–823 행을 열어 봄, 상태표 10 행 `NOT_MATCH` | ✅ 채택(위) |
| `pmon_flags` 160 B 는 다음 기호까지의 자리일 뿐 선언 크기는 아님 | 원본 기호표에 COMMON 크기가 없음(최종 링크본; `symbols.tsv` 칸은 값·절뿐), python 0x40b611c − 0x40b607c = 160 | ✅ 문장을 "자리, 선언 크기 미확인" 으로 고침 |
| `__data` 주인·파일 이름은 강한 추정이지 되찾은 사실이 아님 | 인벤토리 행 276 `unassigned`, 근거가 순서·크기·참조뿐임을 내 사실 목록에서 다시 읽음 | ✅ 문장을 고침 |
| 글자 그대로의 주소가 없다는 것은 계산된 주소·간접 경로를 배제하지 않음 | 내 검색은 4 바이트 절대 주소만 봄(이번 세션 python) | ✅ 한계를 적음 |
| 다섯 함수 크기·합 566, `__data` 값(0 넷 + 0x4092a1a), COMMON 자리 2·2·12, `name+8`=0x40c9488, `pmon_flags[17]`=0x40b60c0 | python 으로 다시 셈(이번 세션 출력: 566·566, 0x40c9488·0x40c9484·0x40b60c0), 원본 `__data` 바이트를 읽음(앞 단계) | ✅ |
| `pmonlogexec` 의 `movel fp@(-4),sp@` 는 미룬 스택 정리(`addaw #28`)가 남긴 칸을 다시 쓰는 것이라 손으로 쓴 스택 조작이 아님 | python 으로 sp 를 따라감: 저장 −24, `strncpy` −36, 첫 호출 −56, 정리 뒤 −28, 둘째 호출 인자 −44…−28 | ✅ (A 는 그대로) |
| `moveaw` 는 부호 늘림이지만 아래 낱말만 쓰이므로 `unsigned short` 지역과 맞음 | `pmon276.dis` `movew %a2,%d1; orw %d1,%d0` 을 읽음 | ✅ |
| `thread_t` 는 A 의 머리 사슬로 이미 보임 → C 는 형과 머리를 함께 바꿈, C0 을 더할 것 | `vm/vm_page.h:72` `#include <kern/sched_prim.h>`, `sched_prim.h:64` `#include <kern/kern_types.h>`, `kern_types.h:79` `typedef struct thread * thread_t;` 를 열어 봄 | ✅ C0 을 더함 |
| `flush` 의 `lea name+8,a0` 꼴과 이름 자료의 형을 따로 시험할 것(E·F), `strncpy` 프로토타입 대조(G) | `pmon276.dis` 167–170 행, `kernserv/prototypes.h:110`, `bsd/strings.h:22` 를 열어 봄 | ⚖️ 부분 채택 — 같은 run 에 E·F·G 를 더함(값이 싸고 판정을 바꾸지 않음). A 가 맞으면 E·F·G 는 "가려지는가" 기록일 뿐 |
| probe 의 `full_span`·`candidate` 는 COMMON 크기를 보지 않음, `undefined_not_in_original` 은 더 생긴 정의를 못 봄 | `m4_m68k_probe.py:335–365` 를 열어 봄: `undef` 는 원본 이름에 없는 UNDF 만, `defined_symbols` 는 기록만 함 | ✅ 측정에 `defined_symbols` 판정을 더함 |
| 종료 상태는 일치 판정이 아님(`refs` 없으면 `diag_gate` 만; funcbytes 는 차이에도 0) | 같은 파일 378–402 행, `m68k_funcbytes.py:245–262` 를 열어 봄 | ✅ 측정에 적음 |
| `funcbytes` 는 `__text` 만 보므로 `__data` 를 따로 볼 것 | `m68k_funcbytes.py` 출력 칸(functions·object_only)이 `__text` 함수뿐임을 위 줄에서 봄 | ✅ 측정에 적음 |
| `vm_page.h`·`kern/thread.h` 가 COMMON 을 새로 만든다는 증거는 없음 | 앞 단계 python 검사(세 머리에서 `extern` 없는 선언 0), `thread.h:278–279` `extern` 을 열어 봄 | ✅ (실제 기호는 진단 기록으로 확인) |
| `08_build/artifacts/` 는 git 이 무시함 | `.gitignore:13` `/08_build/artifacts/*` | ✅ |
| 정확한 명령 흐름·레지스터 선택은 컴파일 전에는 미확인 | — | ⏭️ run 이 판정 |

2차 자기검사: ✅ 행마다 이번 세션에 연 파일·돌린 python 이 위 칸에 있습니다. `l1_compare.py` 의 `__data` 처리(codex 300–360 행 인용)는 열어 보지 않았으므로 근거로 쓰지 않고, `__data` 는 python 으로 따로 봅니다.

고친 방법: 변이 C0·E·F·G 를 더해 A–G 여덟 개를 run `m4p640-p1` 하나로 돌립니다. 판정 기준은 그대로이고, 측정 항목만 위처럼 늘렸습니다.

### 640.2 결과(run `m4p640-p1`, 2026-10-31)

- 명령 16 개 모두 종료 0·경고 0, 의존 목록에 i386 머리 0(`diag_gate` 둘 다 참), 원본에 없는 미정의 기호 0(`m4-m68k-probe-p640-p1-20261031.json`).
- 여덟 변이 모두 `__text` 570 B 로 원본보다 4 B 깁니다(`l1_verdict` NOT_MATCH). funcbytes(`m4-m68k-funcbytes-p640-<변이>-20261031.json`): A·B·C·C0·D·F·G 는 5 개 중 3 개가 같습니다 — `_kpmon_null`·`_pmonlogevent`·`_pmonlogcontextflush`. 다른 것은 `_pmonlogcontext`(106 대 104)·`_pmonlogexec`(144 대 142) 둘이고, 차이는 이름 꼬리 고리 하나뿐입니다(scratchpad `pmonA.dis` 와 `pmon276.dis` 를 python `difflib` 로 비교; 나머지 다른 줄은 재배치 자리와, 고리가 길어져 바뀐 분기 변위 — 예 0x4092b00 원본 `6750` 대 A `6752`; §641.1). `funcbytes` 는 길이가 다르면 바이트·재배치 비교를 건너뛰므로(`m68k_funcbytes.py:184`) 이 결론은 디스어셈블 비교에서 나온 것입니다. 원본은 `clrl d0; L: subqw #1,a0; cmpal a0,a1; bccs out; addql #1,d0; moveq #11,d1; cmpl d0,d1; bges L` 이고, A 의 `while (--cp > name && ++i < 12)` 는 비교를 고리 끝으로 돌려 `bras` 가 하나 더 생깁니다.
- E(`tail` 포인터)는 `_pmonlogcontextflush` 가 5 바이트·재배치 2 곳 달라 배제됩니다. A 의 `((int *)vm_saved_context_name)[0..2]` 가 원본의 `lea name+8,a0` 꼴을 그대로 냅니다.
- A·B·C0·F·G 는 canon·`obj_sig` 가 같고, C·D 는 canon 만 같습니다(C 는 기호표 차이, D 는 STABS 수만 다름 — A 335 대 D 254, 비 STABS 기호 22 개는 같음; §641.1). C 는 `<kern/thread.h>` 때문에 COMMON `_master_cpu`(4)가 더 생깁니다(C0 은 없음). 나머지 일곱은 COMMON 이 `_vm_saved_context_data0`(2)·`_data1`(2)·`_name`(12) 셋뿐이고, 바깥 SECT 정의는 다섯 함수와 `__data` 다섯 이름뿐입니다.
- `__data`(A, python): 20 B, 기호 `_vm_saved_context_flushed` +0·`_thread` +4·`_vm_flushed_thread` +8·`_periodic_vminfo` +12·`_pmon_event_log_p` +16, 값 0 넷과 +16 의 재배치 하나(`__text` 절 기준, 값 0 = `_kpmon_null`; 원본 값 0x4092a1a 는 행 시작) — 원본과 같습니다.

판정(미리 정한 대로): 07 은 바꾸지 않고, 꼬리 고리 꼴을 다음 진단(§641)에서 고칩니다.

## 641. M4-147 세부 계획 — 행 276 꼬리 고리 진단 H1–H3(07 변경 없음; 코딩 전, 2026-10-31)

바탕: §640 A(나머지 세 함수와 `__data` 가 원본과 같음). `_pmonlogcontext`·`_pmonlogexec` 두 곳의 `i = 0; while (--cp > name && ++i < 12) ;` 만 바꿉니다(두 곳 같은 꼴).
- H1: `for (i = 0; i < 12; i++) if (--cp <= name) break;` — 들어갈 때 `i < 12` 는 참으로 접히고, 본문 머리의 `--cp` 비교와 끝의 `i++`·`i < 12` 가 원본 차례와 같을 것으로 봅니다(미확인).
- H2: `i = 0; do { if (--cp <= name) break; } while (++i < 12);` — 원본 차례를 그대로 적은 꼴.
- H3: `for (i = 0; i < 12 && --cp > name; i++) ;`.
- 세 꼴과 A 는 같은 값을 냅니다(python 으로 이름 길이 1–59 를 원본 차례와 함께 흉내 냄: 모두 같음, 길이 1·11·12·13·20 에서 시작 0·0·0·1·8).

방법: spec `08_build/artifacts/m4p641/spec.json`(바탕 `m0p639-a1-stage`, `m5_line` 같음, 객체 `pmon` `m68k-276`, 변이 H1·H2·H3, 글은 scratchpad `p640/pmon_H1.c`… 를 `08_build/artifacts/m4p641/src/` 로), run `m4p641-p1`, 기록 `m4-m68k-probe-p641-p1-20261031.json`, 변이마다 funcbytes `m4-m68k-funcbytes-p641-<변이>-20261031.json`. 측정은 §640 과 같습니다(JSON 칸을 python 으로 판정, `defined_symbols`, `__data` 는 python).

판정(미리 정함): OBJECT_MATCH 이고 다섯 함수가 모두 같고 `__data`·COMMON 이 §640.2 와 같은 꼴이 하나라도 있으면 구현 계획을 세웁니다. 둘 이상이 같으면 canon·`obj_sig` 를 비교해 가려지지 않는 꼴은 여쭙니다. 하나도 맞지 않으면 07 은 바꾸지 않고 결과만 적습니다.

### 641.1 교차검토(codex `gpt-6.1-sol`, task kmdc893ct) 판정과 계획 수정

내가 틀린 것: §640.2 의 "나머지 다른 줄은 재배치 자리" 는 너무 넓었습니다. 고리가 길어져 바뀐 짧은 분기 변위도 있습니다(0x4092b00 원본 `6750` 대 A `6752`). 문장을 고쳤습니다. 결론(차이는 꼬리 고리 하나)은 그대로입니다.

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 0x4092b00 의 `beqs` 가 원본 `6750`, A `6752` 로 재배치가 아닌 변위 차이 | scratchpad `pmon276.dis`·`pmonA.dis` 72 행을 열어 봄 | ✅ 채택(위) |
| `funcbytes` 는 길이가 다르면 바이트·재배치 비교를 건너뜀 → 빈 차이 칸은 "같음" 이 아니라 "안 봄" | `m68k_funcbytes.py:180–186` 을 열어 봄 | ✅ §640.2 에 적음 |
| D 의 `obj_sig` 차이는 STABS 수뿐(A 335, D 254) | python(`macho_obj`): STABS 335·254, 비 STABS 기호 22 개 목록 같음 | ✅ §640.2 를 고침 |
| C 의 `_master_cpu` 는 `kern/thread.h` → `cpu_number.h` 의 임시 정의 | 이번 세션 앞 단계에서 C 의 `defined_symbols` 에 `_master_cpu` COMMON 4 를 봄; 머리 사슬 줄은 열지 않음 | ⏭️ 행동 바뀌지 않음(C 는 C0 과 같은 꼴이라 구현 후보가 아님), 문서에는 머리 사슬을 적지 않음 |
| `__data` 같음은 재배치를 적용한 같음(풀리지 않은 바이트는 +16 이 0) | 앞 단계 python 출력(객체 `__data` 전부 0, 재배치 +16 절 1) | ✅ §640.2 의 글이 이미 그렇게 적음 |
| H2 가 가장 유력, H1 도 그럴 만함, H3 은 약함(모두 미확인) | — | ⏭️ run 이 판정 |
| 길이 0 이름: 첫 고리가 `name[1]` 부터 읽으므로 빈 문자열에서는 C 로 정의되지 않음; 모든 꼴이 이 동작을 지킴, `strlen` 꼴로 바꾸지 말 것 | `pmon276.dis` 79–84(`lea a1@(1),a0`)와 A 57 행을 다시 읽음; 내 python 흉내는 길이 1 이상만 봄 | ✅ 동작을 바꾸지 않음(구현 글에도 원본 차례 그대로) |
| H1–H3 이 다 틀리면 `goto` 꼴을 시험할 것 | — | ⏭️ 그때 정함(이번 run 에는 넣지 않음) |
| probe 의 candidate 판정은 정의 목록을 강제하지 않으니 COMMON·`__data` 판정을 계속 따로 할 것 | §640.1 에서 `m4_m68k_probe.py:335–365` 를 열어 확인함 | ✅ 그대로 함 |

2차 자기검사: ✅ 행의 근거는 이번 세션에 연 줄과 python 출력입니다.

계획은 바꾸지 않고 H1–H3 을 돌립니다.

### 641.2 결과(run `m4p641-p1`, 2026-10-31)

- 명령 6 개 모두 종료 0·경고 0, i386 머리 0, 원본에 없는 미정의 기호 0(`m4-m68k-probe-p641-p1-20261031.json`).
- **H1·H3: OBJECT_MATCH**, `__text` 566 B, `full_span`, `judgement` `candidate`, funcbytes 5/5 같음(`m4-m68k-funcbytes-p641-H1-20261031.json`·`-H3-`). COMMON 은 `_vm_saved_context_data0`(2)·`_data1`(2)·`_name`(12) 셋, 바깥 SECT 정의 10 개(§640.2 와 같음). `__data`(python): 재배치 하나(+16, `__text`)를 원본 자리(0x4092a1a)로 풀면 원본 20 B 와 같고 기호 다섯이 +0…+16 에 있습니다.
- H1 과 H3 은 canon 이 같고 `obj_sig` 는 STABS 수만 다릅니다(337 대 333; 비 STABS 기호 22 개). 바이트로 가려지지 않습니다.
- H2(`do … while (++i < 12)`)는 A 와 같은 꼴로 570 B(`_pmonlogcontext` 106·`_pmonlogexec` 144)라 배제됩니다. codex 가 가장 유력하다고 본 꼴이 틀렸습니다(§641.1 의 예측은 미확인으로 적어 둠).

판정(미리 정한 대로): 맞는 꼴이 둘(H1·H3)이므로, 바이트로 가려지지 않는 꼴과 함께 구현 전에 여쭙습니다. §640 의 A/B/C0/F/G(canon·`obj_sig` 같음)와 D(STABS 수만 다름)의 차이도 같은 처지입니다.

## 642. M4-148 D146 구현 계획 — 07 `src/machdep/m68k/kernel_pmon.c`(행 276, OBJECT_MATCH; 코딩 전, 2026-10-31)

사용자 결정(D146 으로 적음): ① 꼬리 고리는 H1 `for (i = 0; i < 12; i++) if (--cp <= name) break;`; ② `pmon_flags` 는 이 파일에 `int pmon_flags[40];`(NeXTMach `PMON_KERNEL_SOURCES_MAX` 100 대신; 원본 `__common` 의 160 B 자리; 주석에 근거); ③ `#ifdef PMON` 은 두고 그 앞에 `#define PMON 1`(표시); ④ `thread` 인자와 `vm_saved_context_thread` 는 `thread_t`(C0 꼴). 그 밖은 진단 A 꼴(`vm_flushed_thread`·`periodic_vminfo` `int`, 이름 자료 `char [12]`, `<vm/vm_page.h>`, `extern char *strncpy();`, 첫 고리 `for (cp = name + 1; *cp; cp++) ;`). 바이트가 정한 것: A·H2 의 고리 꼴과 E 의 `tail` 꼴은 배제(§640.2·§641.2), `pmonlogevent` 는 덮어쓰기 `eventc.h` 의 `event_set_ts`, 둘째 호출 인자 `((int *)…)[0..2]`.

확인한 사실(이번 세션):
- 07 `src/machdep/m68k/` 에 `kernel_pmon.c` 는 없습니다. `stage_m68k.py` 는 머리 표를 계획 번호 이하의 가장 큰 항목으로 고르고(548 행) 원천 목록도 그렇게 고르므로(567 행), 새 머리 없이 `M4FILES[642]` 한 줄이면 됩니다. pmon 머리 넷은 `M4HEADERS[570]` 부터 들어 있습니다(135–138 행).
- 생성 초안(scratchpad `gen_p642.py`, 결과 `p642/kernel_pmon.c` 132 행, `p642/kernel_pmon_L.c`): NeXTMach `next/kernel_pmon.c` 1–12 행(고지·HISTORY)과 13·15·17(크기만 바꿈)·19·20·22–23·26 행을 그대로 쓰고 나머지는 표시한 1997 글입니다. 주석 뺀 토큰이 F = L 이고, 컴파일한 진단 H1 과의 차이는 결정한 것뿐입니다: `# define PMON 1`·`# ifdef PMON`·`# endif PMON`, `int pmon_flags [ 40 ] ;`, `int` → `thread_t` 세 곳(python `difflib`).
- 상태 기대(python): 객체 48 + 1 = 49(OBJECT_MATCH 40, CODE+BSS_INFERRED 9), 행 74 + 1 = 75/188, 덮은 바이트 70638 + 566 = 71204(32.98%), `object_bytes` 87840 + 566 = 88406, `rows_unassigned_before` 에 `m68k-276` 을 더함.

1. 도구: `stage_m68k.py` 에 `M4FILES[642] = list(M4FILES[639]) + ['kernel_pmon.c']`, `EXCEPTS[642] = dict(EXCEPTS[639])`, 머리말 계획 목록에 642. 머리 표는 바꾸지 않습니다.
2. 07 파일: `gen_p642.py --write`(이미 있으면 멈춤). 파일 머리 주석, 바꾼 줄마다 `plan 642 (D146)`, 원본 바이트로 쓴 네 함수(`pmonlogevent`·`pmonlogcontext`·`pmonlogexec`·`pmonlogcontextflush`)마다 `plan 642 (D024, D146): from the original bytes 0x…` 표시. `kpmon_null`(NeXTMach 22–23 행)·`pmon_event_log_p`(20 행)는 NeXTMach 글 그대로라 표시하지 않고, `pmon_flags` 는 NeXTMach 17 행에서 크기만 바꿔 표시합니다. 생성기는 문자열·문자 상수와 복합 연산자를 한 토큰으로 읽는 lexer 로 F·L 의 토큰과 토큰 줄 번호가 같음을 assert 하고, 컴파일한 H1 글을 §641 기록의 `source_sha256` 에 묶어 H1 → F 토큰 차이가 결정한 목록과 같음을 assert 합니다(§642.1).
3. 회귀: `--plan 639` 재생성(`m0p639-r642-stage`)의 manifest 가 보관본(`m0p639-a1-stage`)과 바이트까지 같음; 새 스테이지 `m0p642-a1-stage` 는 이 파일과 키 `plan`·`m4_sources`·`files` 만 다름; `--plan 639 cmd` 가 `m4p639/m5-639.cmd` 와 같고 `m5-642.cmd` 는 639→642 만 다름; M5 205(run `m3p642-b639`·`m3p642-cc1`) 객체·stderr 같음, `compare`(`m3-m68k-p642-compare-20261031.json`·`-b639-`) `differ_unexpected`·`lost` 빔; x86 `m4-x86-inputs-p642-20261031.json` `ok`·`--plan 642 x86gate` 일곱 묶음 같음.
4. 확인 run `m4p642-p1`(바탕 `m0p642-a1-stage`, 객체 `kernel_pmon` `m68k-276` — 상태 도구가 근거 `m68k-<객체>.md` 를 요구하므로 객체 이름을 파일 이름과 같게 함(§642.1), `x86_rel` `machdep/i386/dkbad.c`): F = `@machdep/m68k/kernel_pmon.c`, L = `08_build/artifacts/m4p642/src/kernel_pmon_L.c`(F 의 코드 줄을 같은 줄 번호에 두고 주석 줄은 맞춤 주석, 같은 머리). 판정: 종료 0·경고 0·i386 0, F·L `OBJECT_MATCH` 사유 없음·`full_span`·`candidate`, funcbytes 5/5, F = L(canon·`obj_sig`; 문자열 표 앞 차이는 `n_strx` 와 문자열 표 크기뿐), COMMON 은 `_pmon_flags`(160)·`_vm_saved_context_data0`(2)·`_data1`(2)·`_name`(12) 넷뿐이고 요청 크기가 이 값과 같음(D146), 바깥 SECT 정의는 함수 다섯과 `__data` 다섯뿐, `__data` 는 재배치를 원본 자리로 풀면 원본 20 B 와 같음(python). `-E` run `m4p642-e2`: F·L 토큰 같음, 진단 H1 과의 차이는 `pmon_flags` 선언과 `thread_t` 세 곳뿐(전처리 지시는 사라짐), stderr 0, i386 경로 0.
5. 최종 run `m4p642-a1`(명세 `08_build/artifacts/m4p642/spec.json`: F 만, `refs` = p1 의 L 객체와 SHA): `gate.ok`. 확인 기록 `m4-m68k-p642-checks-20261031.json`: 절은 `__text` 566·`__data` 20 뿐(`__cstring`·`__bss` 없음), 재배치 대상(funcbytes), 바깥 정의가 원본 주소에(함수 다섯, 자료 다섯), COMMON 넷이 원본에 있고 요청 크기가 D146 값 2·2·12·160 과 같으며 원본에서 다음 기호까지의 자리(2·2·12·160)를 넘지 않음(자리는 선언 크기의 증거가 아님; `pmon_flags` 크기는 D146 결정), 미정의 기호가 모두 원본에 있음, 컴파일 줄이 M5 줄과 같음, 의존 파일에 i386 머리 없음.
6. 상태: 근거 `06_reconstruction/evidence/m68k-kernel_pmon.md` 와 NeXTMach 대비 diff `m68k-kernel_pmon.diff` 를 먼저 쓰고 `ACCEPTED` 에 한 줄. 상태 도구 두 번, 기대는 위 python 값.
7. 기록: PROVENANCE 한 행(일곱 칸, `nextmach+authored`; D013 대로 저장소 URL·커밋 `f6bdb9c3…`·경로:줄 — 고지·HISTORY 1–12, `#import` 13, `#ifdef`/`#endif` 15·26, `pmon_flags` 17(크기 바꿈), `kpmon_null` 선언 19·정의 22–23, `pmon_event_log_p` 20 — 과 원본 바이트로 쓴 네 함수·1997 자료 이름을 함수·식별자별로; 고지는 파일에 그대로), MODIFICATIONS, DECISIONS D146, 계획·HANDOFF·메모리. M7 의무: COMMON 넷의 합침(`_pmon_flags` 는 `kern_exec`·`vm_fault`·`vm_pageout` 이 UNDF 로 언급, 처음 언급자 `kern_exec`), `strncpy`·`event_*`·`vm_page_*` 는 다른 객체.

관문: 명령 종료 0, 경고 0, i386 0, 회귀 같음, 상태 도구가 멈추지 않음. 미리 정한 판정 기준은 결과를 본 뒤 바꾸지 않습니다(바꿔야 하면 여쭙니다).

### 642.1 교차검토(codex `gpt-6.1-sol`, task k9v94f4jm) 판정과 계획 수정

내가 틀린 것: 계획의 객체 이름 `pmon` 과 근거 파일 이름 `m68k-kernel_pmon.md` 가 어긋나 상태 도구가 멈췄을 것입니다(`m4_m68k_status.py:159–160` 이 `06_reconstruction/evidence/m68k-<객체>.md` 를 assert). 객체 이름을 `kernel_pmon` 으로 바꿨습니다. 또 생성기의 토큰 비교가 약했습니다(아래).

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 상태 도구는 `m68k-<객체>.md` 를 요구 → `pmon` 이면 `m68k-pmon.md` | `m4_m68k_status.py:159–160` 을 열어 봄 | ✅ 채택: 객체 이름을 `kernel_pmon` 으로 |
| 생성기의 `strip` 은 `x += 1;` 과 `x + = 1;`, 주석 모양이 든 문자열 둘을 같게 봄; L 생성이 `*` 로 시작하는 줄을 버림; H1 차이는 출력만 함 | 옛 `strip` 으로 python 재현: 둘 다 `True` | ✅ 채택: lexer(문자열·문자 상수, 복합 연산자, 토큰 줄 번호)로 바꾸고 L 의 코드 줄을 lexer 가 본 줄로 정함; 고친 lexer 로 같은 두 예가 `False`, `'\''`·`*p` 를 바르게 읽음; H1 글을 §641 기록 `source_sha256` 에 묶고 차이 목록을 assert. F·L 해시는 그대로(`a9a484cb…`·`c1921192…`) |
| D013 은 저장소 URL·커밋·경로:줄·고지를 파일·함수·식별자 단위로 요구; `kpmon_null`·`pmon_event_log_p` 는 NeXTMach 그대로이고 `pmon_flags` 는 17 행에서 크기만 바뀜 | `DECISIONS.md:17` 을 열어 봄, NeXTMach `kernel_pmon.c` 17·19·20·22–23 행(생성기 assert), `git rev-parse HEAD` = `f6bdb9c3268f0eadc545d41bcc0564453b17001e` | ✅ 단계 2·7 을 고침 |
| §642 의 도구 줄(548·567, 135–138), NeXTMach 남긴 줄, 132 행, H1 → F 차이, 상태 기대(49·40/9·75·71204·32.98%·88406)는 맞음 | 이번 세션에 연 줄과 python 출력(앞 단계) | ✅ |
| C0 은 고리가 옛 꼴이라 F 의 바이트 기준이 아님; F 는 컴파일 전 미확인 | §640.2 C0 570 B | ✅ (확인 run 이 판정) |
| COMMON 요청 크기를 D146 값과 같게 요구할 것; 자리는 선언 크기의 증거가 아님 | §640.1 판정과 같음 | ✅ 단계 4·5 를 고침 |
| `#define PMON 1` 은 모든 머리 뒤라 머리의 `DEBUG` 갈래를 바꾸지 않음; `DEBUG` 이면 같은 값 재정의 | F 25–31 행, NeXTMach `kernel_pmon.h:13–15` | ✅ 행동 바뀌지 않음 |
| L 은 F 에서 만든 것이라 독립 증거가 아님(원본 비교와 H1 연결이 증거) | 생성기 구조 | ✅ 그렇게 적음(L 은 주석·줄 맞춤 대조) |
| `pmon_flags` 에 대해서는 D136 이 아니라 D146 이 근거 | D136 은 공유 머리의 COMMON 규칙 | ✅ 단계 5 를 고침 |

2차 자기검사: ✅ 행의 근거는 이번 세션에 연 줄·돌린 python 입니다.

### 642.2 결과(2026-10-31)

- 1 도구: `stage_m68k.py` 739 → 741 행(`M4FILES[642]`·`EXCEPTS[642]`, 머리말 목록에 642), `m4_m68k_status.py` 199 → 200 행(`ACCEPTED` 한 줄).
- 2 07: `src/machdep/m68k/kernel_pmon.c` 132 행, SHA `a9a484cb…`(scratchpad `gen_p642.py --write`; lexer 로 F·L 토큰·토큰 줄 같음, H1 → F 토큰 차이가 결정한 목록과 같음을 assert).
- 3 회귀: `--plan 639` 재생성(`m0p639-r642-stage`)의 manifest 가 보관본과 바이트까지 같고 트리 해시 어긋남 0; `m0p642-a1-stage`(984 파일, 트리 어긋남 0)는 새 파일 하나와 키 `plan`·`m4_sources`·`files` 만 다름. `--plan 639 cmd` 가 `m4p639/m5-639.cmd` 와 같고 `m5-642.cmd` 는 411 줄 모두 639→642 만 다름. M5 205(run `m3p642-b639`·`m3p642-cc1`): 객체 205 같음, 나머지 출력도 같고 `run.json` 만 다름; `compare`(`m3-m68k-p642-compare-20261031.json`·`-b639-`) `differ_unexpected`·`lost` 빔, 요약 차이는 `stage_vs_test_stage` 에 새 파일 하나. x86: `m4-x86-inputs-p642-20261031.json` `ok`, `--plan 642 x86gate` 일곱 묶음 같음.
- 4 확인 run `m4p642-p1`(`m4-m68k-probe-p642-p1-20261031.json`): 명령 4 개 종료 0·경고 0·i386 0, F·L `OBJECT_MATCH` 사유 없음·`full_span`·`candidate`, funcbytes 5/5(`-F/L-`), F = L(canon·`obj_sig`); 문자열 표 앞 차이는 `n_strx` 와 문자열 표 크기 칸(8380 대 8384)뿐, 기호 이름은 원천 경로(34·35 자)를 바꿔 넣으면 같음. COMMON 은 `_pmon_flags` 160·`_vm_saved_context_data0` 2·`_data1` 2·`_name` 12 넷뿐. `-E` run `m4p642-e2`(`m4-m68k-p642-e2-20261031.json`, `ok`): F = L 4115 토큰, F 에서 `int pmon_flags[40];` 를 빼고 그 뒤의 `thread_t` 셋(이 파일의 것뿐)을 `int` 로 읽으면 H1(4109)과 같음, stderr 0, i386 0. 처음 적은 허용 목록은 difflib 출력 차례를 짐작해 적은 것이라 정렬만 달라 거짓이 나왔고, 같은 기준(차이는 그 선언과 `thread_t` 셋뿐)을 정확한 변환 비교로 다시 적었습니다(기준은 바꾸지 않음).
- 5 최종 run `m4p642-a1`(`m4-m68k-p642-final-20261031.json`, SHA `c02240e6…`): `gate.ok`, 5/5(`m4-m68k-funcbytes-p642-a1-20261031.json`). 확인 `m4-m68k-p642-checks-20261031.json`(`ok` 참): 절 `__text` 566·`__data` 20 뿐, 텍스트 재배치 31, 바깥 정의 10 개가 원본 주소에, 지역 기호 없음, `__data` 는 재배치 하나(+16 → 0x4092a1a)를 풀면 원본과 같음, COMMON 넷이 D146 크기와 같고 원본 절 6 에 있으며 자리를 넘지 않음, 미정의 9 개 모두 원본에 있음, 컴파일 줄이 M5 줄과 같음, 의존 59 개·사슬 문제 없음·i386 0. 우리 객체의 COMMON 기호 차례는 `_vm_saved_context_data0`·`_data1`·`_name` 으로 원본 `__common` 차례와 같음.
- 6 상태(`m4-m68k-status-p642-20261031.json`, 표 50 → 51 행; 두 번 돌려 같음): 객체 49(OBJECT_MATCH 40, CODE+BSS_INFERRED 9), 행 75/188, 덮은 바이트 71204(32.98%), `object_bytes` 88406, `rows_unassigned_before` 에 `m68k-276` — 미리 계산한 값과 같음. 근거 `06_reconstruction/evidence/m68k-kernel_pmon.md`, diff `m68k-kernel_pmon.diff`.
- 7 기록: PROVENANCE 1198 → 1199 행(일곱 칸, 경로 겹침 없음, `nextmach+authored`, 줄 범위·식별자별 출처), MODIFICATIONS 734 → 735 행, DECISIONS D146(149 → 150 행).

판정(미리 정한 대로): 관문을 모두 통과해 받아들였습니다(D146).
