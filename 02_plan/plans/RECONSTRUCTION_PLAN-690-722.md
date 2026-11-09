# 커널 소스 복원 작업계획 — 보관 §690–722

`02_plan/RECONSTRUCTION_PLAN.md` 의 §690–722(다른 세션의 m68k `ev_mouse` 단위 진단, §722 에서 중단되어 §730–736 으로 이어짐)를 절 번호·내용 그대로 옮긴 보관본입니다(2026-11-09, D026 방식, 사용자 지시 “RECONSTRUCTION_PLAN.md 문서에서 진행이 완료된 내용은 기존의 규칙처럼 정리해주세요.”). 본문은 `---` 아래부터입니다.

---

## 690. M4 다음 단위 조사 계획 — `ev_mouse.c` 경계와 진단 설계 (07 변경 없음)

§689 뒤의 후보로 이벤트 묶음의 `m68k-217` 을 우선 조사합니다. 재고표는 정확한 구간 [0x406a0d0, 0x406a86a) 을 표시하고, 함수 표는 이 구간에 13 항목을 표시합니다. NeXTMach mk-108.1 `nextdev/ev_mouse.c` 는 후보 참고 글이며 원본의 증거가 아닙니다. 특히 함수 표에는 `evsetup_screens` 가 있으므로 참고 글을 그대로 원본의 구성으로 가정하지 않습니다.

방법(읽기 전용 조사; 실험 소스와 07 변경 전에 교차검토):
1. Python 으로 재고·함수 표의 범위, 연속성, 크기 합과 기호를 독립 확인하고 결과를 scratch 에 보존합니다. 원본 바이트와 기존 디스어셈블·기호표를 함수별로 대조해 함수 경계, 호출과 자료 참조를 읽습니다. IDA 또는 Ghidra 는 읽기 보조로만 쓰며 그 해석을 원본 바이트와 구분합니다.
2. 같은 이름의 참고 파일들을 찾아 출처·revision·해시를 기록하고, NeXTMach 후보의 함수 순서와 원본을 비교합니다. SDK 머리와 §689 의 `ev.c` 선언을 읽어 필요한 자료형·공유 변수의 후보를 따로 적습니다. 컴파일·링크된 코드에서 확인하지 못한 파일 귀속, 자료 소유, 형과 이름은 가설로 표시합니다.
3. 코드·자료·문자열·BSS 및 기존 공유 머리에 미치는 영향과 남은 불확실성을 조사합니다. 결과에 따라 새 진단 계획을 별도로 작성하며 변형, 스테이지 기준, run ID, 원본 바이트 비교 방법과 성공·실패 판정을 실행 전에 명시합니다. 함수가 맞아도 자료와 미정의·COMMON·BSS 는 별도 검증합니다.
4. 진단 계획 역시 코딩 전에 Codex 서브 에이전트에게 교차검토받고, 주장마다 직접 확인해 판정표를 남깁니다. 새 공유 머리를 도입하거나 변경해야 한다면 M5 와 수락된 M4 회귀 및 x86 입력 불변 관문을 계획에 포함합니다. 바이트로 구별되지 않는 구현 선택은 사용자 결정을 받습니다.

관문: 이 절의 교차검토와 독립 검증을 마치기 전에는 진단 생성기·변형·07 소스를 작성하거나 빌드를 실행하지 않습니다. 조사만으로 객체 경계 또는 자료 소유를 정할 수 없으면 추정으로 기록하고 진단 계획에서 대안을 나누어 검사합니다.

### 690.1 교차검토와 독립 판정

Codex 서브 에이전트 `gpt-6.1-terra` 가 읽기 전용으로 검토했습니다. 회신 자체는 증거로 쓰지 않았습니다.

| 주장 | 독립 검증 | 판정 |
|---|---|---|
| 행 217 의 정확한 텍스트 구간은 원래 소스 객체의 귀속 증명이 아님 | `m68k-text-unmapped.tsv` run 218 의 11–15: 앞 `MoveTheCursor`, 안의 네 함수, 뒤 `evdispatch` 묶음이 미배정임을 직접 확인 | ✅ 양쪽 경계와 안의 미배정 조각의 귀속은 가설로 유지합니다. |
| 행 218 은 정확하지 않고 뒤에 이름 없는 함수도 있음 | `m68k-m4-inventory.tsv` 행 218 과 `m68k-functions.tsv` 의 `_evretry` 뒤 두 항목을 직접 확인 | ✅ 경계 대안을 배제하지 않고 조사합니다. |
| §689 의 회귀, zerofill, COMMON 과 M7 의무를 후속 계획에 옮겨야 함 | §689.1–689.2 와 `m68k-ev.md` 의 validation·M7 obligations 확인 | ✅ 진단·수락 단계에 각각 적용합니다. 정적 BSS 후보와 기존 수락 배치의 겹침, 의존 SHA·스테이지·컴파일 명령, stderr, M5·M4 회귀, x86 입력, 미정의·COMMON 및 M7 의무를 빠뜨리지 않습니다. |

독립 조사: `scratch/p690/inventory.json` 은 함수 표의 13 항목이 [0x406a0d0, 0x406a86a) 에 빈틈없이 이어지고 크기 합이 1946 B 임을 Python 으로 확인했습니다. 이것은 표의 구간 확인이지 원래 객체 귀속의 증명이 아닙니다. NeXTMach 후보 SHA-256 은 `1fa70b646c61eee0e377a68129e7ab435b1ef28f3b97ba05b8fccb0d8cd4f427`, checkout revision 은 `f6bdb9c3268f0eadc545d41bcc0564453b17001e` 입니다. 원본 otool 판독을 `scratch/p690/original-otool.txt` 에 보존했습니다. 이 절은 조사 계획이며 구현이나 수락 판정이 아닙니다.

### 690.2 조사 중간 기록

- 원본 바이트를 `scratch/p688/odis.py` 로 읽어 68040 objdump 결과를 `scratch/p690/original-objdump.txt` 에 보존했습니다. 범위에는 앞 `MoveTheCursor` 와 뒤 `evdispatch`·`evretry` 및 이름 없는 함수 둘도 포함합니다. 기존 otool 과 별도로 바이트가 표시됩니다.
- `_evsetup_screens` 는 원본 0x406a40a 에서 시작합니다. 기계 명령은 첫 인수의 +4·+8·+12·+16·+20 을 읽고, 원본 기호 `_evScreen`·`_evScreenSize`·`_totalShmemSize` 를 참조합니다. SDK `struct evioSetScreen` 의 필드 순서와 `EvScreen` 을 진단 후보로 삼을 근거가 있지만, 자료형·소스 표현과 객체 귀속을 이 사실만으로 확정하지 않습니다.
- `_InitMouse` 는 원본에서 `_adb_mouse_present` 를 부릅니다(0x406a78c 의 호출 목적지와 원본 기호표를 대조). 참고 `ev_mouse.c` 와 동일하다고 가정하면 안 됩니다. SDK 공유 화면 구조와 관련 호출도 1997 코드를 별도로 판독해야 합니다.
- 남은 일: 13 함수와 양쪽 미배정 함수의 호출·자료 참조 및 자료 소유를 더 읽고, 진단할 최소 단위·명세와 사전 판정을 정한 별도 계획을 작성합니다. 그 계획을 다시 교차검토하고 주장별로 검증한 뒤에만 진단 소스를 만듭니다. 아직 진단 빌드나 07 변경은 하지 않았습니다.

## 691. `evsetup_screens` 단독 진단 계획 (코딩 전, 07 변경 없음)

목적: §690 의 전체 객체를 축소해 수락하는 것이 아니라, 1997 화면 자료형과 함수 꼴의 가설을 먼저 시험합니다. 원본 함수 표는 [0x406a40a, 0x406a49e), 148 B 를 표시합니다. 행 217 을 나눈 부분 구간으로 기록하며 이 단독 시험으로 원본 객체 귀속, 다른 함수, 정적 자료 또는 M4 수락을 주장하지 않습니다.

바이트에서 확인한 순서(`scratch/p690/original-objdump.txt` 및 원본 기호표): 첫 인수의 +8 을 인덱스로 보관; `_evScreen` 이 0 이면 첫 인수 +4 값의 40 배를 `_evScreenSize` 에 두고 `_kalloc` 뒤 `_bzero` 를 호출하고 `_totalShmemSize` 에 3282 를 저장; `_evScreen` 의 인덱스 40 배 위치에 첫 인수 +16·+20 의 두 long 과 +12 의 long 을 각각 +12·+16 및 +8 에 저장; +8 값을 `_totalShmemSize` 에 더해 첫 인수 +0 에 씁니다. 40 과 3282 는 Python 으로 산출·SDK ABI 진단과 대조해야 하는 수치이며, 소스 타입과 산술 표현은 가설입니다. 함수 리턴형도 원본만으로 확정하지 않습니다.

방법(교차검토와 독립 판정 이후에만 진단 작성):
1. 07 트리는 고치지 않습니다. `08_build/artifacts/m4p691/` 에 SDK `evio.h` 의 `EvScreen`·`EvOffsets`·`EvGlobals` 와 `struct evioSetScreen` 을 사용한 C89 진단 A 를 둡니다. 위 명령 순서에 따라 `extern` 전역 셋, `kalloc`·`bzero`, 배열 인덱스와 구조체 필드를 사용합니다. `sizeof` 의 대상, 인수형·리턴형·캐스트 등은 진단 선택지이며 원본 소스로 단정하지 않습니다. 변형은 새 스테이지 밖의 공유 머리를 바꾸지 않습니다.
2. `m4_m68k_probe.py` 명세: base `08_build/runs/tools/m0p689-a1-stage`, M5 줄 `08_build/artifacts/m5p494/final.cmd`, 객체 `evsetup`, `x86_rel` `machdep/i386/dkbad.c`, 단일 A, `m4_id` 는 명시 범위와 `rows: []`, `partial: ["m68k-217"]`, 근거 문자열은 단독 함수 진단임을 밝힙니다. 명령 생성 전 Python 으로 `span()` 을 호출해 범위·부분 행 단언과 SDK 필드·구조체 크기를 별도 ABI probe 또는 기존 대상 도구 기록으로 확인합니다. 동일 이름 run 의 부재와 스테이지 manifest 를 다시 확인합니다.
3. 새 run `m4p691-p1` 에서 stage → cmd → kr_run prepare/launch/wait → probe compare; 원본과 비교하는 `m68k_funcbytes.py 0x406a40a 0x406a49e <object> <record>` 를 사용합니다. 명령·exit·stderr·의존 경로·객체 및 비교 기록을 보존합니다. 자동 비교 도구가 외부 참조 재배치를 제대로 처리하는지 원본 기호와 객체의 재배치 목록으로 확인합니다.
4. 미리 정한 판정: 컴파일이 실패하면 오류와 의존을 기록하고 변경 전 별도 계획을 세웁니다. 성공해도 함수별 바이트와 모든 재배치 대상이 일치해야 함수 코드의 진단 일치로만 기록합니다. 불일치일 때는 원본 명령과 컴파일 결과를 비교하고 새 계획·교차검토 후 다음 변형으로 갑니다. 일치해도 나머지 함수·자료·BSS·경계·최종 구현은 미검증입니다.
5. 이 단독 진단은 수락·상태표·PROVENANCE 변경을 하지 않습니다. 이후 전체 객체 후보 계획에서 §690.1 의 회귀·M7 관문과 바이트로 구별되지 않는 선택에 대한 사용자 확인을 수행합니다.

### 691.1 교차검토와 독립 판정 (진단 코딩 전)

Codex 서브 에이전트 `gpt-6.1-terra` 회신을 원본과 도구에서 직접 대조했습니다.

| 주장 | 독립 검증 | 판정 |
|---|---|---|
| 명시 구간을 `m4_m68k_probe.span()` 이 부분 행으로 받음 | inventory 첫 주석을 건너뛰어 Python 으로 호출, `[0x406a40a, 0x406a49e)`, 완전 행 없음, 부분 행 217 반환 | ✅ 처음 검사에서 주석을 헤더로 읽어 `KeyError` 가 났고 올바른 입력으로 다시 검사했습니다. |
| 참조 없는 `compare` 는 종료 코드만으로 성공을 뜻하지 않음 | `m4_m68k_probe.py` 의 `diag_gate` 와 `if 'refs'` 아래 `gate`·exit 경로를 읽음 | ✅ 명시적인 `diag_gate`·stderr·의존과 결과 검사가 필요합니다. |
| funcbytes 는 재배치 필드를 가리고 지원하지 않는 종류를 거부하며 실패 참조만 기록 | `m68k_funcbytes.py` 의 relocation type 검사, mask, `refs_differ` 와 결과 기록을 읽음 | ✅ raw relocation 목록의 폭·종류·PC 상대·addend·대상을 독립 대조합니다. |
| SDK `EvScreen` 은 volatile 이며 구조체 형과 결과 표현은 원본으로 확정 불가 | SDK `evio.h` 정의 및 원본 objdump 확인 | ✅ 실제 2.7 대상 ABI 와 지정한 진단 꼴을 측정합니다. |
| 기존 689 스테이지에 SDK 머리가 있음 | manifest 와 파일 해시를 Python 으로 대조: 둘 다 `334bd9aec4f408bd3fd9a1259c9f448a125e3857b86bcf8d815de5efcebe40ac` | ✅ 실제 의존 목록에도 같은 출처가 나와야 합니다. |
| 할당 실패·인덱스 검사 없이 호출하고 3282 저장은 조건 안에 있음 | 원본 명령 0x406a41a–0x406a45a 직접 대조 | ✅ 진단에 검사를 추가하지 않습니다. |

Python 산술: `(1+4)*8 = 40`, `int('0xcd2',16) = 3282`, 끝−시작 = 148. 이는 명령 해석이며 SDK `sizeof` 라는 사실은 별도 ABI 검사 전까지 가설입니다. 기존 `m0-abi-m68k-20261009.json` 은 일반 ABI 측정이지 이 SDK 형의 크기 측정이 아닙니다.

§691 보완: 단일 A 는 `void evsetup_screens(struct evioSetScreen *arg)`, `extern EvScreen *evScreen`, `extern int evScreenSize, totalShmemSize` 를 진단 선택으로 고정합니다. 조건 안에서 `evScreenSize = arg->totalScreens * sizeof(EvScreen)`, `evScreen = (EvScreen *)kalloc(evScreenSize)`, `bzero((void *)evScreen, evScreenSize)`, `totalShmemSize = sizeof(EvOffsets) + sizeof(EvGlobals)`; 그 뒤 `evScreen[arg->screenIndex].bounds = arg->screenBounds`, 같은 항목의 `shmemSize = arg->screenShmemSize`, `totalShmemSize += evScreen[arg->screenIndex].shmemSize`, `arg->totalShmemSize = totalShmemSize` 순입니다. 함수 안에 검사를 추가하지 않습니다. 타입·식은 진단 선택일 뿐 원본으로 확정하지 않습니다.

진단 성공에는 `diag_gate.commands_ok`·`no_i386_headers`, stderr 비어 있음, 스테이지·의존 해시, 단일 함수와 정해진 범위, funcbytes `same=1`, `total=1`, `object_only=[]` 및 raw relocation 대조가 모두 필요합니다. 독립 ABI 검사의 구체적인 방법과 판정을 먼저 계획·교차검토하고 대상 컴파일러로 확인할 때까지 진단 코드를 쓰지 않습니다.

## 692. 이벤트 SDK m68k ABI 조사 계획 (코딩 전)

목적: §691 진단의 전제인 SDK 자료형 크기와 필드 위치를 실제 `cc-744.13 -arch m68k -g -O2` 로 측정합니다. 원본 소스 형이나 원본 객체 소유를 확정하는 시험이 아닙니다. 기존 m68k ABI 기록은 이 형을 직접 측정하지 않았습니다.

계획(이 계획의 교차검토 및 주장별 독립 판정 후에만 소스·명령 작성):
1. `08_build/artifacts/m4p692/` 에 SDK `bsd/dev/m68k/evio.h` 를 포함한 진단 전용 C 파일을 둡니다. 외부 `const` 또는 writable 정수 배열의 초기값으로 `sizeof(EvScreen)`, `sizeof(EvOffsets)`, `sizeof(EvGlobals)`, 그 마지막 둘의 합, `sizeof(struct evioSetScreen)` 와 `struct evioSetScreen` 의 다섯 필드 및 `EvScreen` 의 `shmemSize`·`bounds` 위치를 순서대로 기록합니다. 위치 표현은 `((unsigned long)&(((형 *)0)->필드))` 를 진단 대상으로 쓰며, GCC 2.7 에서 상수 초기화가 거부되거나 relocation 이 남으면 그 결과를 실패로 기록하고 우회하지 않습니다. 숫자와 필드 순서는 명세에도 남깁니다.
2. 689 스테이지와 기존 `dkbad.c` m68k `-g -O2` 컴파일 줄·동일 include/define 를 쓰되, 진단 파일만 별도 추가합니다. 스테이지 manifest 와 SDK 의존 SHA 를 기록하고 `-M` 의존 출력에 i386 경로가 없어야 합니다. 모든 소스·명령은 로컬 무시 대상 artifacts 에 두고 07 은 바꾸지 않습니다. 새 run ID `m4p692-p1` 의 사용 여부를 REGISTRY 와 실제 run 경로 양쪽에서 다시 확인합니다.
3. `kr_run.py prepare/launch/wait` 로 실기에서 컴파일하고 종료 코드·전체 stderr·의존 경로·대상 도구 해시를 보존합니다. 호스트 Python 의 기존 Mach-O 파서로 배열 기호와 `__data` 를 찾아 대상 big-endian 4 B 정수들을 읽고, 데이터 relocation 이 없음을 확인합니다. 대상 도구·명령·입력 SHA·배열값·검사 결과를 JSON 으로 보존합니다. `collect` 는 전체 명령 성공 및 예상 출력 확인에만 사용하며 원본 일치의 증거로 삼지 않습니다.
4. 미리 정한 관문: 명령 성공과 stderr 0, 의존 출처·해시 정확, i386 경로 0, 배열 길이·기호·절 경계 유효, relocation 0 이고 값이 `[40, 8, 3274, 3282, 24, 0, 4, 8, 12, 16, 8, 12]` 이어야 §691 의 ABI 전제에 부합합니다. 이 값들은 원본 명령·SDK 선언에서 도출한 예상이며 Python 으로 크기와 합을 별도로 확인합니다. 하나라도 실패하면 관문 실패를 기록하고 별도 수정 계획·교차검토를 세우며 §691 을 실행하지 않습니다.

### 692.1 교차검토와 독립 판정 및 구체화

Codex 서브 에이전트 `gpt-6.1-terra` 의 주장을 직접 대조했습니다.

| 주장 | 독립 검증 | 판정 |
|---|---|---|
| const 여부와 읽을 절을 고정해야 함 | §692 는 const 또는 writable 이면서 `__data` 만 지정 | ✅ 아래처럼 writable 로 고정합니다. |
| 스테이지·명령 생성 경로가 빠짐 | `m4_m68k_probe.py` 의 stage·cmd 구현과 §692 대조 | ✅ 기존 도구의 구체 명세를 아래에 둡니다. |
| collect 는 입력·도구·출력 무결성도 검사하고 stage 를 out 으로 이동 | `kr_run.py:collect` 직접 확인 | ✅ 성공 관문에 포함하고 게시 후 out 을 읽습니다. 실패 시 stage 로그를 보존합니다. |
| 두 명령의 stderr 와 의존 출처를 각각 검사해야 함 | `cmd_cmd` 가 compile·`-M` 두 명령을 만들고 collect 는 stderr 빈 값을 검사하지 않음 | ✅ 각 stderr 의 바이트 길이 0, 의존 파일의 manifest 출처·해시와 SDK 포함을 별도 검사합니다. |
| 예상 값은 대상 ABI 실측 전 가설 | SDK 선언과 §412.1 대조 | ✅ Python 결과 `scratch/p690/abi_expected.json`; 12 개 값, 48 B 는 예상입니다. |
| 오프셋 상수 초기화의 지원을 확인해야 함 | `probes/c_layout.c:8`, §412.1 의 이전 실제 대상 탐침과 대조 | ✅ 같은 표현을 쓰되 이번 대상에서도 컴파일·relocation 을 확인합니다. |

수정된 §692 절차: `unsigned int ev_abi[]` 하나(외부 writable, 12 원소)를 지정된 순서로 초기화합니다. `sizeof(unsigned int)` 와 `sizeof(ev_abi)` 는 배열 값과 객체 크기·기존 ABI 기록으로 대조하고, 비 STABS 외부 정의 `_ev_abi` 와 그 기호의 절 내 범위를 확인합니다. 배열 범위와 겹치는 relocation 이 없어야 합니다.

명세는 `m4_m68k_probe.py stage`·`cmd` 를 사용하며 plan 692, base `m0p689-a1-stage`, M5 `m5p494/final.cmd`, 객체 `evabi`, 후보 A, §691 의 명시 단독 범위와 `x86_rel` 을 사용합니다(이 범위는 명령 생성용 메타데이터일 뿐 ABI 객체를 원본 함수와 비교하거나 수락하지 않음). 스테이지 `08_build/runs/tools/m4p692p1-stage`, 명령 `08_build/artifacts/m4p692/probe.cmd`, run `m4p692-p1`, 출력 `Q692__evabi_A.o` 입니다. 스테이지 manifest 는 기준 파일 전부와 후보 소스 하나의 SHA 만 더해져야 합니다. compile·`-M` 각각 rc 0·stderr 크기 0, 의존 출력 비어 있지 않고 SDK 머리 포함, 각 의존이 스테이지 manifest 와 일치하고 i386 경로가 없어야 합니다. collect 의 검증에 성공한 `out` 의 객체만 판독하고 실패 때는 `stage/_log`·상태를 보존합니다. `/bin/cc` 해시는 실기·VM 비교 기록과 연결하며 m68k 백엔드 해시도 이전 툴체인 기록과 조회해 비교합니다. 모든 검사는 Python 기록에 남깁니다.

추가 교차검토 및 직접 확인: `kr_run.py` 의 `ALLOWED_TOOLS` 에 m68k 백엔드가 없으므로 collect 가 백엔드 해시를 검증한다고 볼 수 없습니다. 실행 전후 gcds 읽기 조회로 `m0-toolchain-cross-20261009.json` 의 `/lib/m68k/` 파일 일곱에 대해 실기 `krsha256` 해시·크기를 재고 이전 기록과 각각 비교합니다. 조회 실패·누락·차이가 있으면 관문 실패로 남기고 ABI 결과를 받지 않습니다. gcds 출력은 사이트 정보가 나오지 않도록 걸러 보존합니다. `-M` 의 `src/src/...` 는 맨 앞 `src/` 를 제거해 스테이지 manifest 와 대조합니다(`m4_m68k_probe.py` 의 기존 방식). `sizeof(unsigned int)` 는 별도 배열 원소가 아니므로 기존 ABI 기록과 배열 크기로 간접 확인하며 직접 측정했다고 쓰지 않습니다.

### 692.2 ABI 결과

- 실기 `m4p692-p1`: compile·`-M` 종료 0, 두 stderr 0 B, collect 의 입력·도구·출력 무결성 검사 통과. 스테이지는 기준과 같고 진단 소스 하나만 더해졌습니다. SDK 머리를 포함한 모든 의존의 출처·SHA 가 manifest 와 맞고 i386 경로는 없습니다.
- 실기 m68k 백엔드 일곱 파일의 해시·크기는 실행 전후 기존 §409 기록과 같습니다. 최초 sandbox 안의 gcds 조회는 응답이 없어 제한 밖에서 읽기 조회를 재실행했습니다.
- 원본 함수 비교가 아닌 SDK 대상 ABI 측정입니다. 외부 배열 `_ev_abi` 는 `__DATA,__data` 48 B 전부를 차지하고 그 범위의 relocation 은 0, Python 으로 읽은 12 값은 미리 정한 `[40, 8, 3274, 3282, 24, 0, 4, 8, 12, 16, 8, 12]` 와 같습니다. 별도 `llvm-objdump-14 --macho -s` 출력도 Python 으로 읽어 같은 값임을 확인했습니다(`scratch/p690/abi-llvm.txt`).
- 검사 기록 `09_validation/reconstruction/m4-m68k-evabi-p692-20261102.json`, SHA-256 `4d81947f2027421b47869a0868edd734c167695c880a09b4951a082f11f7bcea`, 모든 명시 검사 `ok`. 따라서 §691 의 ABI 전제는 통과합니다. 07 소스·M4 상태표는 바꾸지 않았습니다.

### 691.2 진단 A 결과

실기 `m4p691-p1`: compile·`-M` 의 rc 0, stderr 각 0 B, `diag_gate.commands_ok`·`no_i386_headers` 참입니다. 기록 `09_validation/reconstruction/m4-m68k-probe-p691-p1-20261102.json`. 목적 파일 `__text` 는 170 B 로 원본 함수의 148 B 와 다릅니다(차이 22 B, Python). `m4-m68k-funcbytes-p691-A-20261102.json` 은 0/1, object-only 없음이며 크기가 다르므로 함수의 relocation 비교는 수행되지 않았습니다. 수락·상태 변경은 없습니다.

원본과 후보의 기계어를 직접 비교했습니다(`scratch/p690/original-objdump.txt`, `evsetup-A.objdump.txt`, raw relocation `evsetup-A.relocs.json`). 원본은 첫 인수 +8 을 조건 전에 레지스터에 보관하고, 화면의 주소 계산을 한 번 수행합니다. A 는 +8 을 조건 뒤에 세 번 읽고 화면 위치를 세 번 계산합니다. 이것은 명령의 관찰이고 지역 변수의 원래 이름이나 선언을 증명하지 않습니다. 크기가 달라 아직 어떤 소스 선택도 확정하지 않습니다.

## 693. `evsetup_screens` 진단 B·C 계획 (코딩 전)

§691 A 의 위 차이를 재는 두 진단입니다. 07 을 바꾸지 않고 A 의 SDK 머리·전역 선언·연산 순서와 형은 그대로 유지합니다.

- B: 함수 시작에서 `register int screenIndex = arg->screenIndex;` 를 선언·초기화하고 이후 세 곳에서 `arg->screenIndex` 대신 `screenIndex` 를 씁니다.
- C: B 에 더해 조건문 뒤 `EvScreen *screen` 에 `&evScreen[screenIndex]` 를 한 번 대입하고 이후 `screen->bounds`, `screen->shmemSize` 를 씁니다. 선언은 C89 블록 시작에 둡니다. 이것들은 진단 가설이며 원래 소스에 지역 변수가 있었다는 결론이 아닙니다.

명세는 §691 과 같은 베이스·M5 줄·명시 범위·대조 함수 및 `x86_rel`, 새 plan 693, B·C 각 파일, 새 run `m4p693-p1` 을 사용합니다. 실행 전에 REGISTRY·run 경로·스테이지 경로가 비어 있는지 확인하고, §691.1 과 같은 stderr·의존·재배치·함수 바이트 관문을 적용합니다. 길이가 달라도 이를 숨기거나 판정을 완화하지 않습니다. 후보가 모두 틀리면 원본과 컴파일된 명령을 다시 읽고 새 계획·교차검토를 세웁니다. 후보가 일치해도 객체 귀속과 다른 함수·자료·최종 소스는 미검증이며, 같은 바이트를 내는 선택지는 구현 전에 사용자에게 여쭙습니다.

이 계획은 진단 파일을 작성하기 전에 Codex 서브 에이전트에게 교차검토받고 주장별로 독립 검증합니다.

### 693.1 교차검토와 독립 판정

Codex 서브 에이전트 `gpt-6.1-terra` 회신을 직접 대조했습니다.

| 주장 | 독립 검증 | 판정 |
|---|---|---|
| 원본은 인덱스 한 번, A 는 세 번 읽음 | 원본과 A objdump 의 인수 +8 및 주소 연산을 읽음 | ✅ 원본은 호출 전 0x406a416, A 는 조건 뒤 세 곳입니다. |
| `EvScreen` 은 volatile typedef | SDK `evio.h` 의 typedef 확인 | ✅ C 의 `EvScreen *screen` 은 대상이 volatile 인 포인터입니다. |
| B·C 와 A 의 의미가 언제나 같지는 않음 | B 는 외부 호출 전 인덱스를 포착하고 C 는 포인터를 한 번 포착함 | ✅ 별칭 또는 호출 중 변경에 따라 차이가 날 수 있으므로 의미 동등성을 가정하지 않습니다. |
| 각 변형의 경로와 검사를 지정해야 함 | §693 과 probe 도구의 variant별 compile·`-M` 구성 대조 | ✅ 아래에 고정합니다. |

C 선언은 함수 블록 시작에 `register int screenIndex = arg->screenIndex; EvScreen *screen;`, 포인터 대입은 if 뒤 `screen = &evScreen[screenIndex];` 로 둡니다. B·C 는 `08_build/artifacts/m4p693/evsetup_B.c`·`evsetup_C.c`, spec `spec.json`, stage `08_build/runs/tools/m4p693p1-stage`, 명령 `probe.cmd`, run `m4p693-p1`, probe 기록 `09_validation/reconstruction/m4-m68k-probe-p693-p1-20261102.json`, 함수 기록 `m4-m68k-funcbytes-p693-{B,C}-20261102.json` 입니다. REGISTRY·run·stage·manifest·artifact 경로 부재를 Python 으로 다시 확인합니다. 각 컴파일·`-M` 의 rc·stderr·SDK 의존·manifest SHA·i386 부재와 `diag_gate` 를 확인합니다. 크기 불일치 시 funcbytes 의 재배치 비교는 수행되지 않으므로 그 결과를 명시하고, 일치한 후보만 raw relocation 전체와 원본 목표를 독립 대조합니다.

### 693.2 결과와 다음 조사

실기 `m4p693-p1`: 네 명령 모두 종료 0·stderr 0 B, `diag_gate` 둘 모두 참입니다. 각 `-M` 의 머리 38 개가 스테이지 manifest 의 SHA 와 같고 SDK 머리를 포함하며 i386 경로가 없습니다(Python). B 의 코드 146 B, C 는 144 B 로 원본 148 B 와 다릅니다(차이 각각 −2 B·−4 B, Python). 두 funcbytes 기록 모두 0/1, object-only 없음; 길이가 달라 재배치 일치는 판정하지 않았습니다. B·C 는 서로 다른 객체입니다. 07·상태표는 바꾸지 않았습니다.

바이트가 표시된 후보 disassembly 는 `scratch/p690/evsetup-{B,C}.objdump.txt`, raw relocation 은 같은 이름의 `.relocs.json` 에 보존했습니다. 원본은 screen 인덱스 계산 뒤 bounds 두 long 을 indexed store 하고 나서 화면 포인터를 계산합니다. B 는 indexed store 전에 인덱스를 주소 레지스터로 옮기고 계속 indexed 접근하며, C 는 bounds 복사 전에 전체 화면 포인터를 계산합니다. 표현과 레지스터 배정에 관한 가설을 더 살펴 다음 진단 계획을 별도로 세우고 교차검토합니다. 이 진단만으로 원래 소스의 형이나 객체 귀속을 확정하지 않습니다.

## 694. `evsetup_screens` 진단 D 계획 (코딩 전)

관찰: §693 B 는 원본처럼 첫 인수를 보관하지만, 화면 포인터를 bounds 저장 뒤에 계산하지 않습니다. 원본의 명령상 포인터 계산 시점을 시험할 후보 D 를 둡니다. B 의 함수 블록 시작에 `EvScreen *screen;` 을 더하고 bounds 저장은 B 그대로, 바로 다음에 `screen = &evScreen[screenIndex];` 를 대입해 나머지 두 `shmemSize` 참조를 `screen->shmemSize` 로 바꿉니다. `EvScreen` 의 volatile 은 유지합니다. 재읽기·별칭에 따라 B·C 와 의미가 다를 수 있으며 원래 소스라고 단정하지 않습니다.

명세는 plan 694, §693 의 base·M5 줄·범위·대조 함수, 별도 진단 파일 `08_build/artifacts/m4p694/evsetup_D.c`, stage `08_build/runs/tools/m4p694p1-stage`, run `m4p694-p1`, probe 기록 `09_validation/reconstruction/m4-m68k-probe-p694-p1-20261102.json`, funcbytes `m4-m68k-funcbytes-p694-D-20261102.json` 입니다. 선행 경로와 REGISTRY 의 부재를 Python 으로 확인하고, §693.1 과 같은 compile·의존·stderr·manifest·원본 함수 바이트 및 raw relocation 관문을 적용합니다. 기존 `m0p689-a1-stage` 이외 공유 머리와 07 파일은 건드리지 않습니다.

판정은 실행 전에 고정합니다. 길이가 다르거나 바이트·참조가 하나라도 다르면 원본 일치가 아닙니다. 모두 같아도 이 함수의 진단 결과이며 원래 소스·객체 경계·다른 함수·자료·최종 수락을 증명하지 않습니다. 변경 전 Codex 서브 에이전트 교차검토와 각 주장 독립 검증을 실시합니다.

### 694.1 교차검토와 독립 판정

Codex 서브 에이전트 `gpt-6.1-terra` 주장별 확인입니다.

| 주장 | 직접 검증 | 판정 |
|---|---|---|
| 원본은 bounds 저장 뒤 같은 base+offset 으로 화면 포인터를 계산하고 B·C 는 다름 | 원본 0x406a45a–0x406a482 와 `evsetup-{B,C}.objdump.txt` 대조 | ✅ D 는 이를 유도하는 가설이며 컴파일러 결과는 측정해야 합니다. |
| `EvScreen` 대상은 volatile 이나 전역 `evScreen` 포인터는 아님 | SDK `evio.h:109` 와 B 의 선언 확인 | ✅ 읽는 시점·별칭은 실제로 허용되는 조건에 따라 의미에 영향을 줄 수 있으므로 동등성을 가정하지 않습니다. |
| 성공 판정에 funcbytes·명령·의존·collect·재배치 검사가 각각 필요 | `m4_m68k_probe.py` 의 `diag_gate`, `m68k_funcbytes.py` 의 길이 불일치 분기, `kr_run.py:collect` 확인 | ✅ 아래 절차로 명시합니다. |
| 단일 함수 일치는 소스·전체 객체·동작 동등성을 입증하지 않음 | 원본 링크 이미지와 함수별 도구 범위를 확인 | ✅ 수락은 별도입니다. |

추가 관문: 각 compile·`-M` rc 0, stderr 각각 0 B, `diag_gate.commands_ok`·`no_i386_headers` 참, 모든 의존 manifest SHA 일치와 SDK 포함; `funcbytes` 는 `same=1`, `total=1`, `object_only=[]`. 길이 불일치면 참조 비교가 생략됨을 명시합니다. 일치 시 원시 relocation 의 위치·폭·type·pcrel·extern·기호명·addend 와 원본 링크된 참조 목표를 독립 대조합니다(기호 번호 자체는 비교하지 않음). stage 상태에서 probe·funcbytes 를 실행한 뒤 `collect` 로 입력·도구·출력 무결성을 검증하며 실패하면 후보 일치로 인정하지 않습니다. REGISTRY, run, stage, stage manifest, artifact 경로는 모두 비어 있음을 재검사합니다.

### 694.2 결과

`m4p694-p1` 은 compile·`-M` 종료 0, stderr 각 0 B, `diag_gate` 둘 참, SDK 를 포함한 의존 38 머리의 manifest SHA 일치 및 i386 경로 0 입니다(Python). `collect` 의 입력·도구·출력 무결성 검사도 통과했습니다. probe 기록 `09_validation/reconstruction/m4-m68k-probe-p694-p1-20261102.json`, funcbytes 기록 `m4-m68k-funcbytes-p694-D-20261102.json`.

D 의 `__text` 는 146 B 로 원본의 148 B 보다 2 B 짧습니다(Python). funcbytes 는 0/1, object-only 없음이며 길이 차이로 relocation 대상은 비교하지 않았습니다. 원본과 D 의 disassembly(`scratch/p690/original-objdump.txt`, `evsetup-D.objdump.txt`)를 읽으면 bounds 저장 뒤 원본은 indexed `lea` 로 화면 포인터를 만들고 D 는 `addal` 을 씁니다. 원시 relocation 10 개는 `scratch/p690/evsetup-D.relocs.json` 에 보존했으나, 이 길이 불일치 후보의 참조 일치는 아직 판정하지 않았습니다. 다음에는 이 명령 선택을 원본 바이트와 대상 컴파일러로 더 조사할 별도 계획을 세웁니다. 함수·객체 수락과 07 소스 변경은 없습니다.

## 695. `evsetup_screens` 진단 E·F 계획 (코딩 전)

D 의 포인터 산술을 표현한 방식에 따른 명령 선택을 측정합니다. 둘 다 D 의 나머지 코드를 그대로 쓰고 `EvScreen` 대상의 volatile 은 유지합니다. E 는 `EvScreen *screen` 선언을 `register EvScreen *screen` 으로 바꿉니다. F 는 D 의 포인터 대입만 `screen = (EvScreen *)((volatile char *)evScreen + screenIndex * sizeof(EvScreen));` 로 바꿉니다. F 의 바이트 단위 포인터 산술이 유효하려면 해당 영역과 인덱스가 C 포인터 산술의 범위 안에 있어야 합니다. 두 꼴이 모든 입력·별칭·동시 접근에서 D 와 같다고 가정하지 않으며, 가능한 원본 소스라는 주장도 하지 않습니다.

명세는 §694 와 같은 base·컴파일 줄·명시 범위·함수이며 plan 695, 별도 파일 `08_build/artifacts/m4p695/evsetup_{E,F}.c`, spec·cmd, stage `08_build/runs/tools/m4p695p1-stage`, run `m4p695-p1`, 기록 `09_validation/reconstruction/m4-m68k-probe-p695-p1-20261102.json` 및 `m4-m68k-funcbytes-p695-{E,F}-20261102.json` 입니다. 경로·REGISTRY 재검사 뒤 stage·cmd·prepare·launch·wait·compare·funcbytes·collect 순으로 실행합니다. 각 후보에 §694.1 의 rc·stderr·의존 SHA·원본 함수·재배치·collect 관문을 개별 적용합니다. 불일치면 원본과 disassembly 를 보존하고 새 계획을 세웁니다. 일치하더라도 단독 함수 진단으로만 취급합니다. 작성 전 Codex 서브 에이전트 검토와 주장별 독립 검증이 필요합니다.

### 695.1 교차검토와 독립 판정

Codex 서브 에이전트 `gpt-6.1-terra` 의 회신을 직접 대조했습니다.

| 주장 | 직접 검증 | 판정 |
|---|---|---|
| 원본은 bounds 저장 뒤 indexed `lea`, D 는 `addal` | 원본과 D objdump 의 해당 명령을 열어 확인 | ✅ register 는 명령을 보장하지 않으므로 진단 결과로만 판정합니다. |
| F 에서 음수 `screenIndex` 와 unsigned `sizeof` 곱의 변환에 주의 | SDK `screenIndex` 는 int, C 의 `sizeof` 는 unsigned 크기 형임을 확인 | ✅ 유효 객체 표현·정렬·곱셈 범위 및 변환을 확인하지 않고 D 와 의미가 같다고 하지 않습니다. |
| typedef 의 volatile 은 대상에 적용되고 포인터 변수 자체는 volatile 이 아님 | `evio.h` 의 정의와 D 선언을 직접 확인 | ✅ E·F 에서 대상 volatile 을 유지합니다. |
| 크기 일치만으로 충분하지 않으며 raw relocation·링크 목표·collect 를 따로 확인 | §694.1 과 함수 비교 도구의 길이 분기·relocation 처리 대조 | ✅ 그대로 적용합니다. |

추가 바이트 조사(Python): D 와 원본을 D 의 10 relocation 필드를 가리고 포인터 계산 명령의 길이 차이를 정렬해 비교하면, 해당 명령 이외의 가리지 않은 바이트 차이는 없습니다. 원본 포인터 명령은 `41f00800`, D 는 `d1c0` 입니다. 이 비교는 relocation 목적지를 검증하지 않으며 길이 차이 후보를 일치로 만들지 않습니다.

보충 검토: 실기에서 수행하는 것은 진단 객체의 compile·`-M` 뿐이며 객체를 실행하거나 커널을 교체하지 않습니다(`m4_m68k_probe.py:cmd_cmd` 와 §694 명령 확인). `collect` 는 m68k 백엔드를 자동 검증하지 않으므로, §692 와 같이 이번 실행 전후 일곱 백엔드 파일의 실기 SHA·크기를 별도 읽어 기존 기록과 비교하고 불일치·조회 실패면 진단 성공으로 인정하지 않습니다.

### 695.2 결과

`m4p695-p1` 의 네 명령은 모두 종료 0·stderr 0 B 이고 `diag_gate` 둘 모두 참입니다. 두 의존 목록의 머리 각각 38 개는 manifest SHA 와 일치하고 SDK 머리를 포함하며 i386 경로가 없습니다(Python). `collect` 무결성 검사도 통과했고 실기 m68k 백엔드 일곱 파일의 SHA·크기는 실행 전후 §409 기록과 같습니다.

E·F 의 코드 길이는 각 146 B, 원본 148 B 보다 2 B 짧습니다(Python). funcbytes 는 각각 0/1, object-only 없음이며 길이 불일치로 relocation 대상을 비교하지 않았습니다. `m4-m68k-probe-p695-p1-20261102.json` 은 E 와 F 의 canon·obj_sig 가 같다고 기록하며, 별도 Python 검사 `m4-m68k-p695-checks-20261102.json` 은 D·E·F 의 `__text` 바이트가 같음을 확인했습니다. 이는 세 소스가 모든 실행 조건에서 동등하다는 뜻이 아닙니다. 원본 함수 일치와 객체 수락은 아직 없고 07 은 변경하지 않았습니다.

## 696. `ev_mouse` 기다림 커서 함수 셋의 진단 계획 (코딩 전)

§695 의 단일 함수 미일치는 남겨 두고 전체 `ev_mouse` 객체를 향해 다른 함수도 조사합니다. 함수 표의 `ShowWaitCursor`, `HideWaitCursor`, `AnimateWaitCursor` 는 연속 [0x406a394, 0x406a40a) 에 있습니다. 재고 행 217 의 일부이며 원래 객체의 귀속은 확정하지 않습니다. 원본 objdump 와 기호표를 대조하면 셋은 모두 이름 없는 0x406a9d4 를 호출하고 `evg` 를 참조하며, Show 와 Animate 는 기다림 시간 전역도 참조합니다. `evg` 의 +64·+28 은 §692 의 구조체 크기 측정만으로는 위치가 증명되지 않으므로 SDK 선언과 후보 코드가 생성하는 바이트로 시험하며, 필드 이름은 진단 가설입니다. 이름 없는 호출 대상의 기능·소스 객체도 미확정입니다.

진단 A: SDK `EvGlobals` 의 `waitCursorUp`·`frame`, 07 `ev.c` 와 같은 `extern EvGlobals *evg`, `extern short waitFrameRate, waitFrameTime, waitSusTime, waitSustain`, 진단에서만 외부 이름 `ev_wait_frame` 을 둡니다. 세 함수는 원본 명령 순서대로 각각 (1) `evg->waitCursorUp = 1; ev_wait_frame(1); waitFrameTime = waitFrameRate + 1; waitSusTime = waitSustain;` (2) `evg->waitCursorUp = 0; ev_wait_frame(0);` (3) `ev_wait_frame(evg->frame + 1); waitFrameTime = waitFrameRate;` 로 씁니다. 이름·형·원래 소스·실행 동등성은 가설입니다. 07 소스·공유 머리·상태표는 바꾸지 않습니다.

명세는 plan 696, §694 base·M5 줄·`x86_rel`, 명시 범위와 `rows: []`, `partial: ["m68k-217"]`, 새 후보 `08_build/artifacts/m4p696/wait_A.c`, stage `08_build/runs/tools/m4p696p1-stage`, run `m4p696-p1` 입니다. 런·스테이지·manifest·artifact·REGISTRY 를 실행 전 확인합니다. compile·`-M` 각 rc·stderr, SDK 의존 SHA, i386 경로 0, `diag_gate`, collect 무결성, 실기 m68k 백엔드 전후 SHA·크기는 §695 관문을 적용합니다. `probe` 의 원본에 없는 UNDF 는 진단의 `_ev_wait_frame` 정확히 하나만 허용하는 예상 결과로 기록하며 이를 실제 원본 심볼이라고 주장하지 않습니다.

`m68k_funcbytes.py 0x406a394 0x406a40a <object> <record> 0x406a9d4=_ev_wait_frame` 로 각 함수를 비교하고 후보 객체 raw relocation 위치·폭·type·pcrel·extern·기호·addend 를 원본 명령 필드에서 구한 링크 목표와 독립 대조합니다. 원본 링크 이미지에 원래 relocation 이 남았다는 가정은 하지 않습니다. 함수별 길이와 바이트·참조가 전부 맞고 원본에 없는 다른 정의·미정의가 없을 때만 셋의 진단 일치로 적습니다. 길이가 다르면 해당 함수의 relocation 은 funcbytes 가 대조하지 않았다고 적습니다. 일부나 전부 틀리면 원본과 생성 명령을 비교하고 새 계획을 수립합니다. 모든 일치는 단독 진단이며 전체 객체·실행 동등성·정적 자료·수락을 증명하지 않습니다. 진단 코드 작성 전 Codex 서브 에이전트 교차검토와 각 주장 독립 검증을 수행합니다.

### 696.1 교차검토와 독립 판정

Codex 서브 에이전트 `gpt-6.1-terra` 회신을 직접 확인했습니다.

| 주장 | 직접 검증 | 판정 |
|---|---|---|
| Hide 는 시간 전역을 참조하지 않음 | 원본 0x406a3ca–0x406a3e4 명령 전체 확인 | ✅ §696 의 잘못된 문장을 고쳤습니다. |
| 외부 주소 앵커는 `orig_target` 에서 쓰임 | `m68k_funcbytes.py` 의 `dmap`·`orig_target` 확인 | ✅ 임시 이름은 진단 앵커로만 씁니다. |
| probe `undefined_not_in_original` 은 원본 이름 전체와 차집합이며 임시 이름 때문에 `full_span` 은 거짓 | `m4_m68k_probe.py` 의 `names`·`undef`·`full` 확인 | ✅ 해당 필드 정확히 `_ev_wait_frame` 하나, 진단 `full_span=false` 를 기대합니다. 원본 실제 미정의 목록으로 해석하지 않습니다. |
| 원본은 링크 이미지이므로 원본 relocation 보존을 가정하면 안 됨 | 원본 비교 도구가 명령 필드와 원본 이미지를 읽는 구현 확인 | ✅ 원본 링크 목표와 후보 raw relocation 을 구분해 대조합니다. |

Python 으로 함수 표를 확인한 결과 함수 셋이 빈틈없이 이어지고 크기 합과 구간은 118 B 로 같습니다. 추가 관문: 객체 외부 비 STABS 정의는 세 함수 정확히, UNDF 는 `_ev_wait_frame`, `_evg`, `_waitFrameRate`, `_waitFrameTime`, `_waitSusTime`, `_waitSustain` 정확히여야 합니다. funcbytes 는 `same=3`, `total=3`, `object_only=[]` 여야 진단 일치입니다. 다른 결과는 모두 기록하고 수락하지 않습니다.

### 696.2 진단 결과

실기 `m4p696-p1`: 두 명령 rc 0·stderr 0 B, `diag_gate` 둘 참, SDK 를 포함한 모든 의존이 manifest SHA 와 같고 i386 경로는 없습니다. `collect` 의 입력·도구·출력 무결성 검사를 통과했으며 실기 m68k 백엔드 일곱 파일은 전후 §409 기록과 같습니다. probe 의 `undefined_not_in_original` 은 예상대로 `_ev_wait_frame` 하나입니다. 따라서 probe 의 `full_span=false`·`judgement=no` 는 실제 객체 수락 판정으로 쓰지 않습니다.

함수별 기록 `09_validation/reconstruction/m4-m68k-funcbytes-p696-A-20261102.json` 은 임시 앵커 `0x406a9d4=_ev_wait_frame` 조건에서 3/3, object-only 없음입니다. 별도 Python 검사 `09_validation/reconstruction/m4-m68k-p696-checks-20261102.json`(SHA-256 `81f51f8382f90c25cb657fafb8c78c580196a8b581efe58c1d4e9037ed39db25`)은 예상 정의·미정의 집합, 후보 raw relocation 12 개의 폭·종류·기호·addend 및 원본 필드의 링크 목표를 대조해 모두 맞았습니다. 그 가운데 호출 셋이 0x406a9d4 를 가리킵니다. 이 이름은 진단용이고 호출 대상의 소스 귀속·원래 이름은 아직 모릅니다.

판정: 미리 정한 관문을 통과해 세 함수의 진단 코드·참조 일치를 확인했습니다. 07 구현, 데이터·BSS, 전체 `ev_mouse` 경계와 객체 수락은 하지 않았습니다. §695 의 `evsetup_screens` 미일치도 남아 있습니다.

## 697. 이름 없는 기다림 프레임 보조 함수 진단 (코딩 전)

§696 의 세 함수가 부르는 0x406a9d4 의 코드 [0x406a9d4, 0x406aa0c) 를 조사합니다. 함수 표의 이름 없는 단일 항목이며 Python 으로 56 B 입니다. `m4_m68k_probe.span()` 에서 처음 `m68k-218` 만 부분 행으로 넣자 `m68k-219` 가 겹친다는 assertion 으로 실패했습니다. 재고를 직접 확인하면 두 행의 가능한 범위가 겹치므로 둘 다 `partial` 로 지정했을 때 통과합니다. 이것은 가능한 구간의 겹침이며 219 의 수락된 `fd_cmds` 에 이 함수가 속한다는 뜻이 아닙니다.

원본 명령은 첫 인수를 읽고 `evg` +28 에 인수가 3 보다 크면 1, 아니면 인수를 저장한 뒤 `evdispatch(3, currentScreen, 0)` 에 해당하는 인수 셋을 쌓아 호출합니다(`scratch/p690/original-objdump.txt`, 원본 기호표). 부호 있는 비교의 입력 형과 `frame` 필드의 SDK 대응은 진단 가설입니다. 이름 `ev_wait_frame` 은 §696 의 임시 앵커이며 원래 이름이 아닙니다.

진단 A·B 는 동일 SDK 머리·`extern EvGlobals *evg`, `extern int currentScreen`, `extern void evdispatch(int, int, int)`, `void ev_wait_frame(int frame)` 을 사용합니다. A 는 `evg->frame = frame > 3 ? 1 : frame;`, B 는 `if (frame > 3) frame = 1; evg->frame = frame;` 다음에 둘 다 `evdispatch(3, currentScreen, 0);` 를 둡니다. 값의 비교·대입과 읽기의 순서가 다를 수 있으므로 둘의 모든 조건에서의 의미 동등성은 가정하지 않습니다. 07·공유 머리·상태표는 바꾸지 않습니다.

plan 697, §696 과 같은 base·컴파일 줄·명시 범위 방식, `rows: []`, `partial: ["m68k-218", "m68k-219"]`, 변형 A·B, stage `08_build/runs/tools/m4p697p1-stage`, run `m4p697-p1` 입니다. 경로와 REGISTRY 부재를 재검사하고 §696 과 같은 m68k 백엔드 전후 해시·컴파일·의존·stderr·manifest·collect 관문을 적용합니다. 함수 범위에는 원본 이름이 없으므로 probe 는 `_ev_wait_frame` 을 추가 정의로 보고 `full_span=false` 가 예상됩니다. 객체 외부 정의는 그 이름 하나, UNDF 는 `_evg`, `_currentScreen`, `_evdispatch` 정확히여야 합니다. funcbytes 에 `0x406a9d4=_ev_wait_frame` 을 주고 함수의 바이트·참조 및 후보 raw relocation 과 원본 링크 목표를 개별 확인합니다.

미리 정한 판정: 각 후보에 `same=1`, `total=1`, `object_only=[]`, 정확한 기호 집합과 raw relocation 대조가 모두 통과해야 진단 일치입니다. 실패·경고·길이 차이는 완화하지 않고 기록합니다. 일치하더라도 객체 귀속·원본 소스·모든 입력에서의 의미 동등성·전체 객체 수락을 뜻하지 않습니다. 작성 전 Codex 서브 에이전트 교차검토와 주장별 독립 검증을 실시합니다.

### 697.1 교차검토와 독립 판정

Codex 서브 에이전트 `gpt-6.1-terra` 의 회신을 직접 확인했습니다.

| 주장 | 직접 검증 | 판정 |
|---|---|---|
| `cmpl`·`blt` 는 3 보다 큰 signed 인수에서 1 을 저장하고 인수는 역순으로 쌓임 | 원본 0x406a9da–0x406aa04 명령 확인 | ✅ SDK 필드·C 프로토타입은 진단 가설로 둡니다. 두 후보의 호출을 명시했습니다. |
| 218·219 둘 다 가능한 범위가 겹침 | 재고표와 `span()` Python 직접 실행 확인 | ✅ 수락된 fd_cmds 의 실제 명시 구간 귀속과 혼동하지 않습니다. |
| 범위 안 익명 항목은 함수 매핑이 필요 | `m68k_funcbytes.py` 의 `ofs` 이름 대입 확인 | ✅ `0x406a9d4=_ev_wait_frame` 을 사용합니다. |
| probe 필드는 전체 기호 검사가 아님 | `m4_m68k_probe.py` 의 `ext`·`undef` 필터와 `macho_obj` 파싱을 읽음 | ✅ raw 비 STABS 외부 정의·UNDF 집합을 따로 확인합니다. |
| 길이가 다르면 funcbytes 는 relocation 을 비교하지 않음 | `m68k_funcbytes.py` 의 길이 분기 확인 | ✅ 길이 불일치 후보는 미비교로 기록하고, 일치한 후보는 원본 링크 목표와 raw relocation 을 별도 대조합니다. |

### 697.2 결과

실기 `m4p697-p1` 의 네 명령은 rc 0·stderr 0 B, `diag_gate` 둘 참이며 `collect` 의 입력·도구·출력 무결성 검사를 통과했습니다. SDK 머리를 포함한 각 의존 목록은 manifest SHA 와 같고 i386 경로가 없으며, m68k 백엔드 일곱 파일은 실행 전후 §409 기록과 같습니다.

A 는 56 B 로 원본 함수와 같고, 임시 이름 `0x406a9d4=_ev_wait_frame` 을 지정한 funcbytes 기록은 1/1, object-only 없음입니다. `m4-m68k-p697-checks-20261102.json`(SHA-256 `8d1ef94f09c9ade3a45e660578008d94a30dde57d70457afa9fc3ef05746fcf4`) 의 독립 검사에서 예상 외부 정의·UNDF 집합과 후보 relocation 세 개의 원본 링크 목표가 모두 맞았습니다. raw relocation 은 `scratch/p690/helper-A.relocations.json` 에 보존했습니다. probe 의 `full_span=false` 는 이름 없는 원본에 진단 이름을 넣었기 때문이며 수락 판정이 아닙니다.

B 는 48 B 로 원본보다 8 B 짧고 funcbytes 0/1 입니다(Python). 길이 차이로 B 의 relocation 대상은 비교하지 않았습니다. 따라서 A 에 대해 함수 진단 일치만 기록합니다. 원래 정적 이름과 귀속, 07 구현·자료·객체 수락은 미결이며 §696 의 세 호출과의 연결은 원본 주소로만 확인된 상태입니다.

## 698. `TermMouse`·`ResetMouse` 진단 계획 (코딩 전)

원본 함수 표와 바이트에서 두 연속 함수 [0x406a7a8, 0x406a7e6), 합 62 B 를 확인했습니다(Python). `TermMouse` 는 `_screens` 가 0 이 아니면 세 인수 1·`_currentScreen`·0 으로 `_evdispatch` 를 부르고, `ResetMouse` 는 `_autoDimmed` 가 0 이 아니면 `_UndoAutoDim` 을 부른 뒤 항상 `_InitMouseVars` 를 부릅니다. 함수표·원본 기호와 objdump 를 대조했습니다. 참고 NeXTMach `nextdev/ev_mouse.c` 의 같은 이름 함수는 다른 조건과 호출을 포함하므로 원본과 동일하다고 가정하지 않습니다.

진단 A 는 `<sys/types.h>` 와 파일 안 `extern int screens, currentScreen, autoDimmed; extern void evdispatch(int, int, int), UndoAutoDim(void), InitMouseVars(void);` 와 `void TermMouse(void) { if (screens) evdispatch(1, currentScreen, 0); }`, `void ResetMouse(void) { if (autoDimmed) UndoAutoDim(); InitMouseVars(); }` 를 둡니다. 인수형·리턴형과 전역 소유는 진단 가설입니다. 진단용 소스는 무시 대상 artifacts 에만 두고 07·공유 머리·상태표는 바꾸지 않습니다.

plan 698, §696 과 같은 base·컴파일 줄, 명시 범위와 `rows: []`, `partial: ["m68k-217"]`, stage `08_build/runs/tools/m4p698p1-stage`, run `m4p698-p1` 입니다. REGISTRY·경로 확인 후 §697 처럼 실기 백엔드 전후 해시, compile·`-M` rc·stderr, 의존 manifest SHA, i386 경로 0, collect 를 확인합니다. funcbytes 로 두 함수 전체와 참조를 비교하고 객체 raw relocation 의 폭·type·PC 상대·기호·addend 를 원본 링크 목표에 독립 대조합니다. 추가 진단 앵커는 쓰지 않습니다.

미리 정한 관문: 비 STABS 외부 정의는 `_TermMouse`·`_ResetMouse` 정확히, UNDF 는 `_screens`, `_currentScreen`, `_autoDimmed`, `_evdispatch`, `_UndoAutoDim`, `_InitMouseVars` 정확히; `same=2`, `total=2`, `object_only=[]`; 원본에 없는 UNDF 0, 나머지 진단 관문과 raw relocation 이 모두 맞아야 함수 둘의 진단 일치입니다. 그렇지 않으면 차이를 기록하고 기준을 완화하지 않습니다. 일치해도 원래 소스, 자료 소유, 객체 경계·전체 수락의 증거는 아닙니다. 코딩 전 Codex 서브 에이전트 교차검토와 주장별 독립 검증을 실시합니다.

### 698.1 교차검토와 독립 판정

Codex 서브 에이전트 `gpt-6.1-terra` 회신을 직접 검증했습니다.

| 주장 | 직접 검증 | 판정 |
|---|---|---|
| 두 함수의 범위·분기·호출 및 심볼 | 원본 objdump·기호표·함수표와 Python 크기 합 62 B 대조 | ✅ 타입과 원본 소유는 가설입니다. |
| 원본 참조 필드는 여섯 | 원본 링크 이미지 필드 6 곳을 Python 으로 읽어 절대값 또는 PC 상대 목표 산출 | ✅ 범위 시작 기준 오프셋 `0x6, 0x10, 0x1a, 0x28, 0x30, 0x36`, 목표는 각각 `_screens`, `_currentScreen`, `_evdispatch`, `_autoDimmed`, `_UndoAutoDim`, `_InitMouseVars` 입니다. 후보 raw relocation 의 위치·폭·종류·기호·addend·목표를 이 목록과 대조합니다. |
| 명시 범위는 부분 행 217 | `span()` 을 Python 으로 호출해 경계와 부분 행 확인 | ✅ 실행 전에 경로와 REGISTRY 를 다시 검사합니다. |
| `diag_gate` 와 collect 관문을 직접 적어야 함 | `m4_m68k_probe.py` 와 `kr_run.py:collect` 확인 | ✅ `diag_gate.commands_ok`·`no_i386_headers` 참, 각 stderr 0 B, 모든 의존 manifest SHA 일치 및 collect 의 입력·도구·출력 무결성 검사를 요구합니다. |

### 698.2 결과

실기 `m4p698-p1` 의 두 명령 rc 0·stderr 0 B, `diag_gate` 둘 참, 의존 manifest SHA 일치·i386 경로 0, `collect` 입력·도구·출력 무결성 검사가 통과했습니다. 실기 m68k 백엔드 일곱 파일의 SHA·크기도 실행 전후 §409 기록과 같습니다.

`m4-m68k-funcbytes-p698-A-20261102.json` 은 두 함수 2/2, object-only 없음입니다. 독립 검사 `09_validation/reconstruction/m4-m68k-p698-checks-20261102.json`(SHA-256 `b707e24fc9ca339a46c0f3ecfdca93e166981c1acdcd17287eddf5ab26970b9e`)은 외부 정의·UNDF 집합과 미리 지정한 원본 참조 필드 여섯 각각에 대해 후보 relocation 위치·폭·type·PC 상대·기호·addend 및 링크 목표가 일치함을 확인했습니다. 원본에 없는 UNDF 는 없습니다.

probe 의 `OBJECT_MATCH` 는 이 두 함수만 떼어 측정한 범위에 대한 진단 결과입니다. 원래 소스 객체의 귀속이나 전체 `ev_mouse` 객체 수락으로 해석하지 않습니다. 07 소스·상태표를 바꾸지 않았으며, 데이터·BSS 와 나머지 함수는 계속 조사합니다.

## 699. `StartCursor` 단독 진단 계획 (코딩 전)

원본 함수 표의 [0x406a7e6, 0x406a86a) 는 132 B 이고 행 217 일부입니다(Python `span`). 원본 바이트·기호표에서 다음 순서를 관찰합니다: `_screens` 가 0 이면 -1; 아니면 `_evg` +24 의 long 을 이름 없는 0x406aa0c 에 전달해 결과를 `_currentScreen` 에 저장하고 음수면 -1; `_evScreen` 의 인덱스 40 배 +12 와 +16 의 long 둘을 `_cursorPin` 에 저장한 뒤 +2·+6 의 word 를 각각 1 줄임; `_SetCurBrightness(_curBright)`, `_evdispatch(2, currentScreen, 0)` 호출 후 0 반환. 본문에서 호출자의 인수 슬롯을 읽는 명령은 관찰되지 않습니다. 이것만으로 원래 선언에 인수가 없었다고 할 수 없습니다. 자료형, 오프셋의 SDK 이름, 이름 없는 함수의 원래 이름·소속은 진단 가설입니다.

진단 A 는 `<sys/types.h>`·SDK `evio.h`, `extern EvGlobals *evg; extern EvScreen *evScreen; extern Bounds cursorPin; extern int screens, currentScreen, curBright; extern int ev_point_to_screen(Point); extern void SetCurBrightness(int), evdispatch(int, int, int);` 를 둡니다. `int StartCursor(void)` 안에서 위 순서대로 `if (!screens) return -1; currentScreen = ev_point_to_screen(evg->cursorLoc); if (currentScreen < 0) return -1; cursorPin = evScreen[currentScreen].bounds; cursorPin.maxx--; cursorPin.maxy--; SetCurBrightness(curBright); evdispatch(2, currentScreen, 0); return 0;` 를 씁니다. 함수 호출·volatile 읽기·별칭 순서는 컴파일 결과로 확인하며 원래 소스라고 주장하지 않습니다. 07·공유 머리·상태표는 바꾸지 않습니다.

plan 699, §698 base·컴파일 줄, `rows: []`, `partial: ["m68k-217"]`, stage `08_build/runs/tools/m4p699p1-stage`, run `m4p699-p1` 을 사용합니다. 경로·REGISTRY 를 재확인하고 백엔드 전후 SHA, 각 compile·`-M` rc·stderr, 모든 의존 manifest SHA·SDK 포함·i386 경로 0, probe `diag_gate`, collect 무결성 검사를 합니다. `m68k_funcbytes.py 0x406a7e6 0x406a86a <object> <record> 0x406aa0c=_ev_point_to_screen` 과 후보 raw relocation 및 원본 링크 목표의 독립 대조를 수행합니다. 임시 `_ev_point_to_screen` 은 probe 의 `undefined_not_in_original` 에 예상되며 실제 원본 심볼이 아닙니다.

미리 정한 관문: 외부 비 STABS 정의 `_StartCursor` 하나, UNDF 는 `_evg`, `_evScreen`, `_cursorPin`, `_screens`, `_currentScreen`, `_curBright`, `_ev_point_to_screen`, `_SetCurBrightness`, `_evdispatch` 정확히; 함수 `same=1`, `total=1`, `object_only=[]`, 모든 참조의 후보 relocation 폭·종류·PC 상대·기호·addend 와 원본 목표 일치 및 위 실행 관문 통과입니다. 불일치·경고·길이 차이는 완화하지 않고 기록하며 길이가 다르면 funcbytes 의 relocation 은 미비교입니다. 일치해도 진단뿐이며 객체·자료 수락을 뜻하지 않습니다. 코딩 전에 Codex 서브 에이전트 교차검토와 주장별 직접 검증을 실시합니다.

### 699.1 교차검토와 독립 판정

Codex 서브 에이전트 `gpt-6.1-terra` 회신을 직접 확인했습니다.

| 주장 | 직접 검증 | 판정 |
|---|---|---|
| 원본 분기·호출·반환과 인수 슬롯 미참조 | 함수 전체 원본 objdump 확인 | ✅ 원래 원형이 인수 없음이라는 뜻은 아닙니다. |
| `Bounds` 의 +2·+6 은 `maxx`·`maxy` 후보 | SDK `evio.h` 의 short 필드 순서 및 §692 ABI 일반 크기와 대조 | ✅ 최종 원래 소스 형이 아니라 SDK 진단 형입니다. |
| 범위 밖 주소 앵커를 도구가 지원 | `m68k_funcbytes.py` 의 `dmap` 확인 | ✅ 임시 이름으로만 사용합니다. |
| 원본 참조 필드는 13 개 | 원본 링크 이미지의 필드와 PC 상대 목표를 Python 으로 읽어 심볼표와 대조 | ✅ 시작 기준 오프셋 `0x8, 0x10, 0x1a, 0x22, 0x2c, 0x42, 0x48, 0x4e, 0x54, 0x5a, 0x60, 0x68, 0x72` 입니다. `_cursorPin` 참조는 addend 각각 0·4·2·6 이고, 익명 호출은 0x406aa0c 입니다. 후보 raw relocation 의 위치·폭·type·pcrel·extern·기호·addend 와 원본 목표를 각각 대조합니다. |

REGISTRY·run·stage·manifest·artifact 부재를 코딩·실행 전에 재확인합니다. probe 에 임시 이름 하나가 생기므로 `full_span=false` 는 예상이며 별도 raw 기호와 함수 검사를 우선합니다.

### 699.2 결과

실기 `m4p699-p1` 의 두 명령 rc 0·stderr 0 B, `diag_gate` 둘 참, SDK 포함 의존의 manifest SHA 일치·i386 경로 0, collect 무결성 검사가 통과했습니다. m68k 백엔드 일곱 파일의 SHA·크기는 전후 §409 기록과 같았습니다. probe 의 `undefined_not_in_original` 은 예상한 `_ev_point_to_screen` 하나로, 원본 이름이 아닌 임시 앵커입니다.

함수별 기록 `09_validation/reconstruction/m4-m68k-funcbytes-p699-A-20261102.json` 은 `0x406aa0c=_ev_point_to_screen` 조건에서 1/1, object-only 없음입니다. 독립 검사 `09_validation/reconstruction/m4-m68k-p699-checks-20261102.json`(SHA-256 `e7803500b6f2cf890d3d46de062581ebaa2a773cc5701631d56bfc744479822a`) 은 정의·UNDF 집합과 미리 열거한 원본 참조 필드 13 곳에 대한 후보 raw relocation 의 위치·폭·type·pcrel·extern·기호·addend·링크 목표를 모두 확인했습니다.

단독 함수 진단 코드·참조 일치입니다. 인수가 사용되지 않는다는 바이트 관찰만으로 원래 선언을 확정하지 않으며, 임시 보조 함수의 이름·귀속, 자료·전체 객체 수락 및 07 구현은 미결입니다.

## 700. 이름 없는 화면 선택 보조 함수 진단 (코딩 전)

§699 의 0x406aa0c 호출 대상은 함수 표의 이름 없는 [0x406aa0c, 0x406aa70), 100 B 항목입니다(Python). `span()` 에서는 가능한 재고 범위가 겹치는 `m68k-218`·`m68k-219` 둘 다 partial 로 지정해야 합니다. §697 과 같이 이것은 수락된 `fd_cmds` 의 귀속을 바꾸지 않습니다.

원본 명령은 인수 long 을 보관하고 `_screens+2` 의 word 를 읽어 하나 줄여 `0xffff` 와 비교한 뒤, `_evScreen` 배열의 인덱스 40 배 위치 +12·+14·+16·+18 의 signed word 와 인수의 두 signed word 를 차례로 비교합니다. 통과하면 인덱스를 반환하고, 아니면 `dbf` 로 역방향 탐색해 -1 을 반환합니다. SDK `Point`·`Bounds`·`EvScreen` 과의 대응은 진단 가설입니다. NeXTMach `nextdev/ev_cursor.c:254` 의 `PointToScreen` 은 정방향 탐색이므로 그 글을 원본 사실로 쓰지 않습니다. 익명 이름 `_ev_point_to_screen` 은 §699 의 진단 앵커일 뿐 원본 이름이 아닙니다.

진단 A·B 는 SDK `evio.h`, `extern EvScreen *evScreen; extern int screens; int ev_point_to_screen(Point p)` 와 `short i` 를 씁니다. A 는 `for (i = screens - 1; i >= 0; i--)`, B 는 `for (i = screens; i-- != 0;)` 로 시작하고 둘 다 본문에서 `p.x >= evScreen[i].bounds.minx && p.x < evScreen[i].bounds.maxx && p.y >= evScreen[i].bounds.miny && p.y < evScreen[i].bounds.maxy` 이면 `return i`, 반복 뒤 `return -1` 입니다. 이 두 반복은 모든 입력에서 같지 않을 수 있고 포인터 범위·short 변환도 별도 전제입니다. 범위 밖 인덱스가 유효하다고 가정하거나 입력값을 원본 사실로 정하지 않습니다.

plan 700, §697 과 같은 base·컴파일 줄·두 partial 행, stage `08_build/runs/tools/m4p700p1-stage`, run `m4p700-p1`, 후보 A·B 별도 소스·기록입니다. REGISTRY·경로를 재검사하고 m68k 백엔드 전후 해시, compile·`-M` rc·stderr, 모든 의존 manifest SHA·SDK 포함·i386 경로 0, `diag_gate`, collect 를 확인합니다. 원본 이름이 없으므로 probe 의 `extra_names` 는 `_ev_point_to_screen` 하나이고 `full_span=false` 가 예상됩니다. raw 비 STABS 외부 정의는 그 이름 하나, UNDF 는 `_screens`·`_evScreen` 정확히입니다. funcbytes 에 `0x406aa0c=_ev_point_to_screen` 을 주어 `same=1`, `total=1`, `object_only=[]` 인 후보만 일치 후보로 보고 raw relocation 위치·폭·type·pcrel·extern·기호·addend 및 원본 링크 목표를 독립 대조합니다. 길이 차이면 함수 relocation 은 미비교로 기록합니다.

모든 관문이 맞아도 이름·자료 소유·객체 귀속·전체 수락·모든 입력에서의 의미 동등성은 미결입니다. 두 꼴이 같은 바이트를 내면 실제 구현 선택 전에 사용자에게 여쭙니다. 진단 작성 전 Codex 서브 에이전트 교차검토와 각 주장 독립 검증을 수행합니다.

### 700.1 교차검토와 독립 판정

Codex 서브 에이전트 `gpt-6.1-terra` 회신을 직접 대조했습니다.

| 주장 | 직접 검증 | 판정 |
|---|---|---|
| 원본은 처음 0xffff 만 선검사하고 이후 `dbf` 로 하위 word 를 감소 | 원본 0x406aa18–0x406aa24·0x406aa60 명령 확인 | ✅ A 의 `i >= 0` 은 음수 시작값을 탐색하지 않아 모든 입력에서 원본과 같지 않습니다. B 의 short 범위 밖 변환은 구현 정의이며 유효 범위 밖 객체 접근은 정당화하지 않습니다. |
| 경계 비교는 x 하한·상한, y 하한·상한 순이고 상한은 배타적 | 원본 `cmpw`·`bgt`·`ble` 와 SDK 필드 순서 확인 | ✅ 진단 조건에 반영되어 있습니다. |
| 이름 없는 범위는 두 가능한 partial 행과 겹침 | inventory 와 `span()` Python 실행 확인 | ✅ 객체 귀속은 미확정입니다. |
| funcbytes 의 same 만으로 relocation 누락이 없는지 증명 불가 | 도구의 후보 relocation 필드 masking 분기 확인 | ✅ 원본 필드를 사전 열거해 양방향 대조합니다. |

원본 참조 필드는 Python 으로 산출한 범위 시작 기준 `0xe` = `_screens+2` 와 `0x1c` = `_evScreen` 둘입니다. 일치 후보의 raw relocation 위치·폭·type·pcrel·extern·기호·addend·링크 목표가 이 목록과 정확히 같아야 합니다. 후보 A 의 `screens - 1` 은 `INT_MIN` 에서 signed overflow 가능성이 있으므로 특정 값에 대한 동등성 주장 없이 진단으로만 사용합니다. 각 경로와 REGISTRY 부재를 작성 전에 다시 확인합니다.

probe 의 `undefined_not_in_original` 은 빈 목록이어야 하며, 위 두 relocation 은 각각 4 B·type 0·extern·비 PC 상대, 기호와 addend 는 `_screens`+2·`_evScreen`+0 이어야 합니다. 원본은 링크 이미지이므로 이 relocation 들이 원본에 보존되었다고 주장하지 않습니다.

### 700.2 결과

실기 `m4p700-p1`: 네 명령 rc 0·stderr 0 B, `diag_gate` 둘 참, 두 의존 목록 모두 SDK 포함·manifest SHA 일치·i386 경로 0, collect 의 입력·도구·출력 무결성 검사 통과. m68k 백엔드 일곱 파일의 SHA·크기도 실행 전후 §409 기록과 같습니다.

후보 B 는 `0x406aa0c=_ev_point_to_screen` 을 지정한 함수별 비교 `m4-m68k-funcbytes-p700-B-20261102.json` 에서 1/1, object-only 없음입니다. 독립 검사 `09_validation/reconstruction/m4-m68k-p700-checks-20261102.json`(SHA-256 `158b8f5ba246fd3d76d0e7b6b19f37919747db71239804fcd3db9e0522d3da82`) 은 B 의 외부 정의·UNDF 집합, 원본에 없는 UNDF 0, 미리 지정한 raw relocation 두 곳의 위치·형식·기호·addend 와 원본 링크 목표를 확인해 모두 통과했습니다. 이름 없는 원본에 진단 이름을 붙였으므로 probe 의 `full_span=false` 는 예상입니다.

후보 A 는 96 B 로 원본 100 B 보다 4 B 짧고 0/1 이며 relocation 대상은 비교하지 않았습니다(Python). B 는 해당 도구체인에서 원본 코드·참조가 일치하는 진단입니다. 범위 밖 인덱스의 유효성, 원래 소스·정적 이름·객체 귀속, 전체 `ev_mouse` 와 자료의 수락은 여전히 증명하지 않습니다. 07·상태표는 바꾸지 않았습니다.

## 701. `ev_unregister_screen` 진단 계획 (코딩 전)

원본 함수 표의 [0x406a522, 0x406a59a) 는 120 B, 행 217 일부입니다(Python `span`). 원본은 `_evg` 가 0 이면 -1 을 반환합니다. 아니면 인수에서 256 을 빼고 음수 또는 `_screens` 이상이면 -1; 그 외에는 `_evdispatch(1, currentScreen, 0)` 을 부르고 `_evScreen` 의 선택 항목 +28·+24·+32·+36 을 이 순서로 long 0 으로 쓴 뒤 `_evdispatch(2, currentScreen, 0)` 을 부르고 0 을 반환합니다. 원본 명령 및 기호표 확인입니다. SDK `EvScreen` 의 `move`·`hide`·`show`·`level`, `SCREENTOKEN` 및 C 형은 진단 대응 가설이며 원래 소스·객체 귀속의 증명은 아닙니다.

후보 A·B 는 `<sys/types.h>`·SDK `evio.h`, `extern EvGlobals *evg; extern EvScreen *evScreen; extern int screens, currentScreen; extern void evdispatch(int, int, int);` 와 `int ev_unregister_screen(int token)` 을 사용합니다. 두 후보 모두 `if (!evg) return -1; token -= SCREENTOKEN; if (token < 0 || token >= screens) return -1; evdispatch(1, currentScreen, 0);` 다음 4 필드를 원본 순서대로 0 으로 놓고 `evdispatch(2, currentScreen, 0); return 0;` 입니다. A 는 `evScreen[token].move` 등 각 배열 접근을 직접 쓰고, B 는 위 첫 dispatch 뒤 `EvScreen *screen` 에 `&evScreen[token]` 을 담아 `screen->` 로 필드를 씁니다(C89 선언은 블록 시작). typedef 의 volatile 대상은 유지합니다. 외부 호출·별칭 조건에 따라 두 후보의 접근 시점이 다를 수 있으므로 모든 상황에서 의미가 같다고 가정하지 않습니다.

plan 701, §700 과 같은 base·컴파일 줄, 명시 범위와 `rows: []`, `partial: ["m68k-217"]`, stage `08_build/runs/tools/m4p701p1-stage`, run `m4p701-p1` 입니다. REGISTRY·run·stage·manifest·artifact 경로를 재확인하고 실기 m68k 백엔드 전후 SHA·크기, compile·`-M` rc·빈 stderr, SDK 포함 의존 manifest SHA, i386 경로 0, `diag_gate`, collect 무결성을 확인합니다. 각 후보의 외부 비 STABS 정의는 `_ev_unregister_screen` 하나, UNDF 는 `_evg`, `_evScreen`, `_screens`, `_currentScreen`, `_evdispatch` 정확히여야 합니다. funcbytes 의 `same=1`, `total=1`, `object_only=[]` 및 원본에 없는 UNDF 0 과 raw relocation·원본 목표의 독립 대조가 모두 통과해야 함수 진단 일치입니다. 길이가 다르면 해당 후보의 relocation 은 미비교로 기록합니다.

원본 링크 이미지에서 Python 으로 미리 읽은 참조 필드는 함수 시작 기준 `0xe` `_evg`, `0x1e` `_screens`, `0x2c` `_currentScreen`, `0x36` `_evdispatch`, `0x3e` `_evScreen`, `0x60` `_currentScreen` 입니다. 후보 relocation 위치·폭·type·pcrel·extern·기호·addend 와 원본 링크 목표를 완전 대조합니다. 일치해도 객체 귀속·전체 수락·모든 입력에서의 의미 동등성은 미결이며, 바이트가 같은 선택지는 실제 구현 전 사용자에게 여쭙니다. 작성 전 Codex 서브 에이전트 교차검토와 주장별 직접 검증을 수행합니다.

### 701.1 교차검토와 독립 판정

Codex 서브 에이전트 `gpt-6.1-terra` 의 회신을 직접 확인했습니다.

| 주장 | 직접 검증 | 판정 |
|---|---|---|
| 원본 분기·호출·네 저장 순서 및 여섯 참조 | objdump 와 Python 으로 원본 링크 필드 여섯을 읽고 기호표와 대조 | ✅ 참조 위치 집합과 목표를 양방향으로 대조합니다. |
| `token -= SCREENTOKEN` 은 일부 정수값에서 signed overflow 가능 | C signed int 의 범위 조건과 후보 식 대조 | ✅ 원본의 32 비트 기계어가 모든 C 입력에서 같은 의미라고 주장하지 않습니다. |
| SDK 형의 volatile 은 대상 구조체에 적용 | SDK `evio.h` 의 typedef·전역 선언 확인 | ✅ 포인터 자체의 volatile 과 구별하고 후보를 진단으로만 씁니다. |
| 원본의 dispatch 주소는 한 번 적재되고 두 번 간접 호출됨 | 0x406a556 `lea` 와 두 `jsr` 직접 확인 | ✅ 원본에는 해당 참조가 한 필드이며 후보 raw relocation 을 별도 확인합니다. |

일치 후보는 위 여섯 위치 전체에 대해 각 4 B·type 0·extern·비 PC 상대·addend 0 과 예상 기호·원본 목표를 만족해야 합니다. 원본에 relocation 이 보존되었다고 가정하지 않습니다. 후보는 각각 `08_build/artifacts/m4p701/unreg_A.c`·`unreg_B.c`, probe `09_validation/reconstruction/m4-m68k-probe-p701-p1-20261102.json`, funcbytes `m4-m68k-funcbytes-p701-{A,B}-20261102.json` 으로 기록합니다.

### 701.2 결과

실기 `m4p701-p1`: 네 명령 rc 0·stderr 0 B, `diag_gate` 둘 참, 두 의존 목록 모두 SDK 포함·manifest SHA 일치·i386 경로 0, collect 입력·도구·출력 무결성 검사 통과. m68k 백엔드 일곱 파일의 SHA·크기도 실행 전후 §409 기록과 같습니다.

후보 A 는 `m4-m68k-funcbytes-p701-A-20261102.json` 에서 1/1, object-only 없음입니다. 독립 검사 `09_validation/reconstruction/m4-m68k-p701-checks-20261102.json`(SHA-256 `a621a2c93b1a8f29fcc9116889bcee4a62ddc2891c4e0ed29cb0db9d4f8e324a`) 은 A 의 외부 정의·UNDF 집합, 원본에 없는 UNDF 0 및 미리 지정한 raw relocation 여섯 곳과 원본 링크 목표를 모두 확인했습니다. probe 의 `OBJECT_MATCH` 는 이 단독 함수 범위의 진단 결과입니다.

후보 B 는 118 B 로 원본 120 B 보다 2 B 짧고 0/1 이며 길이 차이로 relocation 대상은 비교하지 않았습니다(Python). A 에 대한 함수 코드·참조 진단 일치만 기록하며 원래 소스·객체 귀속·자료와 전체 수락은 미결입니다. 07·상태표는 바꾸지 않았습니다.

## 702. `ev_register_screen` 단독 진단 계획 (코딩 전)

원본 함수 표 [0x406a49e, 0x406a522) 는 132 B, 행 217 일부입니다(Python `span`). 원본은 `_evg` 가 0 이면 -1; `_screens` 가 0 이면 `_evs` 의 long 을 이름 없는 자료 0x40b1278 에 저장; `_evScreen[_screens]` 의 주소를 첫 인수가 가리키는 곳에 두고, 다음 다섯 인수를 화면 항목 +0·+28·+24·+32·+36 에 저장합니다. 항목 +8 이 0 이 아니면 이름 없는 자료의 값을 +4 에 넣고, +8 을 그 자료에 더한 뒤 `_screens` 의 증가 전 값 +256 을 반환합니다. 원본 objdump·기호표에서 관찰했습니다. 0x40b1278 은 원본 `__data` 에 있으며 4 B 값은 0 입니다. 원래 이름·크기·소속은 확인되지 않았습니다.

진단 A 는 SDK `evio.h`, `extern EvGlobals *evg; extern EvScreen *evScreen; extern int screens; extern void *evs; extern char *ev_shmem_cursor;` 와 첫 인수 `EvScreen **out`, 둘째 `void *priv`, 뒤 네 인수는 SDK `EvScreen` 의 move·hide·show·level 함수 포인터와 같은 형을 쓰는 `int ev_register_screen(...)` 입니다. `EvScreen *screen` 을 C89 블록 시작에 선언합니다. 원본 순서대로 `if (!evg) return -1; if (!screens) ev_shmem_cursor = evs; screen = &evScreen[screens]; *out = screen;` 뒤 `screen->priv`, `move`, `hide`, `show`, `level` 에 인수를 대입하고, `if (screen->shmemSize) screen->shmemPtr = ev_shmem_cursor; ev_shmem_cursor += screen->shmemSize; return screens++ + SCREENTOKEN;` 을 씁니다. 이름 없는 자료의 임시 외부 이름과 포인터 형, 인수형·자료 소유·별칭·산술의 유효 범위는 진단 가설입니다. 실제 원본 소스나 모든 입력에서의 동등성을 주장하지 않습니다.

plan 702, §701 과 같은 base·컴파일 줄, 명시 구간·`rows: []`·`partial: ["m68k-217"]`, stage `08_build/runs/tools/m4p702p1-stage`, run `m4p702-p1` 입니다. 실행 전 경로·REGISTRY 확인, 실기 백엔드 전후 SHA, compile·`-M` 의 rc·stderr, SDK 포함 의존 manifest SHA·i386 경로 0, `diag_gate` 및 collect 무결성을 확인합니다. probe 의 `undefined_not_in_original` 은 진단 이름 `_ev_shmem_cursor` 정확히 하나가 예상됩니다. raw 비 STABS 외부 정의는 `_ev_register_screen`, UNDF 는 `_evg`, `_evScreen`, `_screens`, `_evs`, `_ev_shmem_cursor` 정확히여야 합니다.

funcbytes 는 범위 밖 주소 앵커 `0x40b1278=_ev_shmem_cursor` 로 `same=1`, `total=1`, `object_only=[]` 를 요구합니다. 원본 링크 필드의 함수 시작 기준 오프셋은 Python 에서 `0xa` `_evg`, `0x16` `_screens`, `0x20` `_evs`, `0x24` 임시 자료, `0x30` `_evScreen`, `0x5e`·`0x6a` 임시 자료, `0x70`·`0x7c` `_screens` 입니다. 후보 raw relocation 위치 집합·폭·type·pcrel·extern·기호·addend 와 원본 목표를 독립 대조합니다. 값·자료 정의 위치·BSS/데이터 소유까지 확인했다는 뜻은 아닙니다. 길이 불일치면 relocation 대상은 미비교로 적고, 하나라도 실패하면 원본 일치로 기록하지 않습니다. 일치해도 단일 함수 진단일 뿐이며 구현·전체 객체 수락은 별도입니다. 작성 전 Codex 서브 에이전트 교차검토와 각 주장 독립 검증을 수행합니다.

### 702.1 교차검토와 독립 판정

Codex 서브 에이전트 `gpt-6.1-terra` 의 회신을 직접 대조했습니다.

| 주장 | 직접 검증 | 판정 |
|---|---|---|
| 원본 인수·저장 순서와 아홉 참조 | 원본 objdump 와 Python 원본 필드 읽기 대조 | ✅ `shmemSize` 는 검사와 더하기에서 각각 읽고 더하기는 조건 밖입니다. |
| SDK 콜백의 첫 인수는 `struct _evScreen *` 이며 `EvScreen` typedef 는 volatile | SDK `evio.h:109–119` 확인 | ✅ 아래처럼 정확히 SDK 형을 쓰며 volatile 을 함수 포인터의 매개변수에 추가하지 않습니다. |
| 범위 밖 임시 앵커는 다음 원본 심볼 전까지 적용됨 | `m68k_funcbytes.py:dmap` 과 Python 으로 다음 기호 0x40b128c 확인 | ✅ 앵커는 0x40b1278 한 주소의 크기·소유를 증명하지 않습니다. raw 참조 아홉은 모두 정확한 목표·addend 를 따로 검증합니다. |
| 선택적 할당 뒤 덧셈이 조건 밖임 | 원본 0x406a4f4–0x406a50c 확인 | ✅ 후보에서 같은 순서로 둡니다. |
| 임시 UNDF 로 probe full_span 은 거짓 | `m4_m68k_probe.py` 의 undef·full 계산 확인 | ✅ 단독 함수 검사와 객체 수락을 구분합니다. |

진단 인수형은 차례대로 `EvScreen **out`, `void *priv`, `int (*move)(struct _evScreen *, Point, int)`, `int (*hide)(struct _evScreen *)`, `int (*show)(struct _evScreen *, Point, int)`, `int (*level)(struct _evScreen *, int)` 으로 고정합니다. 일치 후보의 아홉 raw relocation 은 각 4 B·type 0·extern·비 PC 상대·addend 0 이고 §702 의 정확한 위치·기호·원본 목표 집합이어야 합니다. `screens++` 의 signed overflow, 화면·shared-memory 포인터 산술의 유효 범위 및 별칭은 별도 전제이며 원본의 모든 입력과 동등하다고 주장하지 않습니다. REGISTRY·run·stage·manifest·artifact 경로는 작성 전 다시 확인합니다. 실기는 compile·`-M` 만 사용합니다.

### 702.2 결과

실기 `m4p702-p1` 의 두 명령은 rc 0·stderr 0 B, `diag_gate` 둘 참, SDK 포함 의존 manifest SHA 일치·i386 경로 0, collect 입력·도구·출력 무결성 검사를 통과했습니다. m68k 백엔드 일곱 파일 SHA·크기는 전후 §409 기록과 같습니다. probe 의 원본에 없는 UNDF 는 예상대로 진단 이름 `_ev_shmem_cursor` 하나입니다.

함수별 기록 `09_validation/reconstruction/m4-m68k-funcbytes-p702-A-20261102.json` 은 `0x40b1278=_ev_shmem_cursor` 조건에서 1/1, object-only 없음입니다. 독립 검사 `09_validation/reconstruction/m4-m68k-p702-checks-20261102.json`(SHA-256 `bafb3ca47e7f6d2abda80c7ee7300fd0134ac3b5d153a2ed2252782eedfeec2e`) 은 외부 정의·UNDF 집합과 미리 열거한 아홉 후보 raw relocation 의 위치·폭·type·pcrel·extern·기호·addend 및 원본 링크 목표를 모두 확인했습니다.

이는 함수 코드·참조의 진단 일치입니다. 0x40b1278 자료의 실제 이름·소유·원래 정의와 전체 객체·자료 수락은 미결이며 07·상태표는 바꾸지 않았습니다.

## 703. `InitMouseVars` 단독 진단 계획 (코딩 전)

원본 함수 [0x406a59a, 0x406a668) 는 206 B 로 함수표의 행 217 일부입니다. 원본 objdump 와 기호표에서 클릭 시간·거리·상태, 자동 어둡게 값, 마우스 방향·배율 배열을 초기화하는 순서를 확인했습니다. 원본 `__data` 0x40b1260 부터 24 B 는 `00000005 0002 0003 0004 0005 0006 0002 0004 0006 0008 000a` 이고(Python big-endian), 함수는 첫 long, 그 하위 word, 두 short 배열을 읽습니다. 이 자료의 정의 객체와 원래 이름은 미확정입니다. NeXTMach `nextdev/ev_mouse.c:432` 의 후보와 달리 원본에는 초기 cursor 이미지 설정이 관찰되지 않으며 새 `dimmedBrightness=15` 저장이 있습니다. 참고 글은 후보이며 원본 사실은 바이트로만 판정합니다.

진단 A 는 SDK `evio.h` 의 `Point`·`EvGlobals` 와 §689 및 NeXTMach `ev_vars.h` 이름의 extern 변수를 쓰되, 이름 없는 세 자료에 진단 전용 extern `int ev_init_num; short ev_init_thresholds[]; short ev_init_factors[];` 를 둡니다. `void InitMouseVars(void)` 는 `short i;` 를 선언하고 원본 순서로 `clickTimeThresh=30; clickSpaceThresh.x=clickSpaceThresh.y=3; clickTime=-30; clickLoc.x=clickLoc.y=-3; clickState=1; autoDimTime=evg->VertRetraceClock+120600; autoDimPeriod=120600; dimmedBrightness=15; buttonsTied=1; mouseHandedness=0; numMouseScales=ev_init_num;` 을 수행합니다. 이어 `for (i=ev_init_num; i-- != 0;)` 에서 `mouseScaleThresholds[i]=ev_init_thresholds[i]; mouseScaleFactors[i]=ev_init_factors[i];` 순으로 복사하고 `mouseDelX=mouseDelY=0;` 을 둡니다. 상수의 원래 매크로·이름·형, 배열 크기·소유, short 축소 및 범위 밖 인덱스 유효성은 가설입니다. overflow 또는 잘못된 포인터 범위에 대한 동등성을 주장하지 않습니다.

plan 703, §702 base·컴파일 줄, 명시 구간과 `rows: []`, `partial: ["m68k-217"]`, stage `08_build/runs/tools/m4p703p1-stage`, run `m4p703-p1` 입니다. 경로·REGISTRY 확인, 백엔드 전후 SHA, compile·`-M` rc·stderr, SDK 포함 의존 manifest SHA·i386 경로 0, `diag_gate`, collect 관문은 §702 와 같습니다. `m68k_funcbytes.py 0x406a59a 0x406a668 <object> <record> 0x40b1260=_ev_init_num 0x40b1264=_ev_init_thresholds 0x40b126e=_ev_init_factors` 로 함수 바이트·참조를 확인합니다. probe 의 원본에 없는 UNDF 는 세 진단 이름 정확히; raw 비 STABS 외부 정의 `_InitMouseVars` 하나와 UNDF 집합을 별도로 검사합니다.

원본 링크 필드 후보는 Python 으로 추출한 시작 기준 `0xc,0x14,0x1c,0x24,0x2c,0x34,0x3c,0x42,0x52,0x5c,0x64,0x6c,0x72,0x78,0x7c,0x82,0x90,0x96,0x9c,0xa2,0xba,0xc0` 의 22 곳이며 각 목표와 원본 명령 경계를 직접 검증합니다. `same=1`, `total=1`, `object_only=[]`, 정확한 정의·UNDF·원본 필드와 후보 raw relocation 위치·폭·type·pcrel·extern·기호·addend·목표 양방향 일치, 모든 실기 관문을 만족해야 함수 진단 일치입니다. 길이가 다르면 relocation 미비교로 기록합니다. 일치해도 정적 자료 정의와 객체 소유·07 구현·전체 수락은 아닙니다. 코딩 전 Codex 서브 에이전트 교차검토와 주장별 직접 검증을 수행합니다.

### 703.1 교차검토와 독립 판정

Codex 서브 에이전트 `gpt-6.1-terra` 회신을 직접 대조했습니다.

| 주장 | 직접 검증 | 판정 |
|---|---|---|
| 반복 초기값은 이름 없는 long 하위 word 를 읽고 DBF 를 씀 | 원본 0x406a61a–0x406a64e 와 원본 필드 Python 출력 확인 | ✅ `0x78` 은 임시 `_ev_init_num+0`, `0x7c` 는 `_numMouseScales`, `0x82` 는 임시 `_ev_init_num+2` 입니다. 첫 회신의 0x7c 표기는 틀렸고 후속 정정도 직접 검증했습니다. |
| 참조 22 위치와 목표 | 원본 바이트에서 주소 값들을 Python 으로 읽고 objdump 명령 경계·기호표에 대조 | ✅ 4 B 절대 필드이며 임시 배열과 Point 의 비영 addend 를 포함해 각각 검증합니다. |
| 후보 반복문은 short 축소·범위 밖 입력에서 원본과 일반적으로 같다고 볼 수 없음 | C 정수 변환과 원본 word/DBF 명령을 확인 | ✅ 대상 컴파일러의 바이트만 비교하고 비정상 인덱스의 유효성을 가정하지 않습니다. |
| click 전역은 `long`, `Point`, 나머지는 `int`·배열 `short` 후보 | §689 선언, NeXTMach `ev_vars.h` 와 SDK `Point` 확인 | ✅ 진단 선언을 아래에 고정합니다. 원본 선언의 증명은 아닙니다. |

진단 선언: `extern long clickTimeThresh, clickTime; extern Point clickSpaceThresh, clickLoc; extern int clickState, autoDimTime, autoDimPeriod, dimmedBrightness, buttonsTied, mouseHandedness, numMouseScales, mouseDelX, mouseDelY; extern short mouseScaleThresholds[], mouseScaleFactors[]; extern EvGlobals *evg;` 와 §703 의 임시 세 자료입니다. UNDF 는 이 이름들과 임시 세 이름의 정확한 집합이어야 하며, probe `undefined_not_in_original` 은 임시 이름 세 개만이어야 합니다. 후보 raw relocation 22 곳은 모두 4 B·type 0·extern·비 PC 상대이며, 원본 목표와 일치하는 기호·addend 를 검사합니다. `_ev_init_num+2`, `_clickSpaceThresh+2`, `_clickLoc+2` 도 확인합니다. REGISTRY·run·stage·manifest·artifact 의 부재를 작성 직전 재확인합니다.

임시 UNDF 세 개 때문에 probe `full_span=false` 는 예상이며 함수별 진단 관문과 구별합니다. §703 의 raw 필드 목록은 원본과 후보 양방향 정확히 같은 위치 집합이어야 하고, 주소가 같은지만 보지 않고 각 기호·addend 를 따로 대조합니다.

### 703.2 결과

실기 `m4p703-p1` 의 두 명령 rc 0·stderr 0 B, `diag_gate` 둘 참, SDK 포함 의존 manifest SHA 일치·i386 경로 0, collect 입력·도구·출력 무결성 검사가 통과했습니다. m68k 백엔드 일곱 파일 SHA·크기는 전후 §409 기록과 같습니다. probe 의 원본에 없는 UNDF 는 예상한 세 진단 이름뿐입니다.

함수별 기록 `09_validation/reconstruction/m4-m68k-funcbytes-p703-A-20261102.json` 은 0x40b1260·0x40b1264·0x40b126e 세 임시 자료 앵커 조건에서 1/1, object-only 없음입니다. 독립 검사 `09_validation/reconstruction/m4-m68k-p703-checks-20261102.json`(SHA-256 `828eddf7a780bfa012316b580830cefbb2cf618d8e1fed86113af382089778d7`) 은 정의·UNDF 집합, 원본 자료 24 B 및 미리 열거한 후보 raw relocation 22 곳의 위치·폭·type·pcrel·extern·기호·addend 와 원본 링크 목표를 확인했습니다.

함수 코드·참조의 진단 일치이며, 임시 자료의 원래 이름·정의 객체와 배열의 실제 소유, 07 구현·전체 객체 수락은 미결입니다. 07·상태표는 바꾸지 않았습니다.

## 704. `InitMouse` 단독 진단 계획 (코딩 전)

원본 함수 [0x406a668, 0x406a7a8) 는 함수표의 행 217 일부이고 320 B 입니다(Python). 원본은 인수에서 낮은 word 를 써 역방향으로 40 B 간격 큐 항목의 5 위치를 초기화하고, 이어 인수 전체를 써 마지막 항목과 LLELast·LLETail·LLEHead 를 설정합니다. 그 뒤 버튼·이벤트 번호·플래그·시계·커서 위치, 이름 있는 화면·압력·마우스 전역과 `evg` bitfield 를 초기화하고 `_adb_mouse_present` 의 결과를 이름 없는 BSS 0x40b4fb6 에 저장한 후 `_InitMouseVars` 를 부릅니다. 원본 objdump·기호표에서 확인했습니다. SDK `EvGlobals`·`NXEQElement` 와의 대응, 전역 형, 이름 없는 BSS 의 원래 이름·소유는 진단 가설입니다. 인수 및 인덱스가 유효 범위라는 보장은 바이트만으로 없습니다.

진단 A 는 SDK `evio.h`, `extern EvGlobals *evg; extern int screens, sessionPressure, sessionPrecision, autoDimmed, mouseDelX, mouseDelY; extern unsigned char lastPressure; extern short rightENum, leftENum; extern int ev_adb_mouse; extern int adb_mouse_present(void); extern void InitMouseVars(void);` 와 `void InitMouse(int n)` 을 둡니다. `short i` 로 `for (i=n; i-- != 0;)` 에서 순서대로 `evg->lleq[i].event.type=0`, `.time=0`, `.flags=0`, `.sema=0`, `.next=i+1` 을 쓰고, `evg->LLELast = evg->lleq[n-1].next = 0; evg->LLEHead = evg->LLETail = evg->lleq[evg->LLELast].next;` 를 둡니다. 이어 원본 순서로 `buttons=0`, `eNum=13`, `eventFlags=0`, `VertRetraceClock=1`, `cursorLoc.x=cursorLoc.y=100`; `screens=0; sessionPressure=0; sessionPrecision=0; lastPressure=0;`; `dontCoalesce=0; dontWantCoalesce=0; wantPressure=0; wantPrecision=0;`; `leftENum=rightENum=0; mouseRectValid=0; movedMask=0; cursorSema=0; autoDimmed=0; mouseDelX=mouseDelY=0; ev_adb_mouse=adb_mouse_present(); InitMouseVars();` 를 둡니다. `evg` 접두가 필요한 필드는 SDK 의 이름을 씁니다. 폭·순서·volatile bitfield 배치는 대상 바이트로 판정하며 원래 소스라고 가정하지 않습니다.

plan 704, §703 base·컴파일 줄, `rows: []`, `partial: ["m68k-217"]`, stage `08_build/runs/tools/m4p704p1-stage`, run `m4p704-p1`, 하나의 진단 소스를 씁니다. 작성 전 경로·REGISTRY 확인, 실기 m68k 백엔드 전후 SHA, compile·`-M` rc·stderr, SDK 포함 의존 manifest SHA·i386 경로 0, `diag_gate`, collect 검사를 합니다. 비 STABS 외부 정의는 `_InitMouse`; UNDF 는 `_evg`, `_screens`, `_sessionPressure`, `_sessionPrecision`, `_lastPressure`, `_rightENum`, `_leftENum`, `_autoDimmed`, `_mouseDelY`, `_mouseDelX`, `_adb_mouse_present`, `_ev_adb_mouse`, `_InitMouseVars` 정확히; probe 의 원본에 없는 이름은 `_ev_adb_mouse` 하나가 예상입니다.

함수별 비교는 `0x40b4fb6=_ev_adb_mouse` 앵커를 둡니다. 원본 링크 참조 필드는 Python 으로 확인한 함수 시작 기준 `0x18,0x40,0x8e,0x94,0x9a,0xa0,0xb2,0xc4,0xd6,0xe8,0xee,0xf4,0x106,0x114,0x11a,0x120,0x126,0x12c,0x132` 의 19 곳입니다. 앞의 17 개 절대 자료 참조와 2 개 PC 상대 호출의 위치·폭·type·pcrel·extern·기호·addend 와 원본 링크 목표를 후보 raw relocation 과 양방향으로 독립 대조합니다(목록에는 두 호출이 중간·끝에 섞여 있음). `same=1`, `total=1`, `object_only=[]`, 정확한 기호 집합과 모든 실기·참조 관문을 충족해야 단일 함수 진단 일치입니다. 길이 불일치면 relocation 미비교로 기록합니다. 이름 없는 BSS 의 정의·배치·소유와 07 구현·전체 객체 수락은 별도입니다. 코딩 전 Codex 서브 에이전트 검토와 주장별 직접 검증을 수행합니다.

### 704.1 교차검토와 독립 판정

Codex 서브 에이전트 `gpt-6.1-terra` 회신을 직접 대조했습니다.

| 주장 | 직접 검증 | 판정 |
|---|---|---|
| 큐의 40 B 간격과 5 저장 위치 및 이후 volatile 필드 재독 | 원본 0x406a674–0x406a6d2 와 SDK 큐 선언 확인 | ✅ 후보 필드 대응은 진단 가설이며 생성된 바이트를 검사합니다. |
| bitfield 마스크 순서 `fd, fb, ef, f7, fe` | 원본 0x406a70c–0x406a768 와 SDK 선언 대조 | ✅ 기계어 결과로 대응을 확인하며 형의 원래 출처는 확정하지 않습니다. |
| 참조 19 위치와 이름 | 원본 바이트에서 Python 으로 절대 필드와 두 PC 상대 호출 목표를 산출하고 기호표 대조 | ✅ 정확한 위치 집합과 기호·addend·목표를 양방향 확인합니다. |
| PC 상대 addend 는 객체 필드 주소 보정이 필요 | `m68k_funcbytes.py` 의 external pcrel 처리 확인 | ✅ raw word 를 0 으로 가정하지 않고 보정 결과를 검사합니다. |
| 임시 이름으로 probe full_span 은 거짓 | `m4_m68k_probe.py` undef·full 계산 확인 | ✅ 진단과 객체 수락을 구별합니다. |

원본 `__bss` 앵커 0x40b4fb6 은 다음 원본 이름 0x40b5648 전까지 넓게 매핑됩니다(Python). 이는 자료 크기나 소유의 근거가 아니므로 raw relocation 위치 `0x12c` 의 정확한 목표·addend 를 따로 확인합니다. 19 곳은 모두 후보에서 4 B·type 0·extern, `0x126`·`0x132` 만 PC 상대이며 각 기호 addend 0 을 기대합니다. 후보의 유효한 n 범위·short 축소와 배열 접근은 별도로 검증되어야 합니다.

### 704.2 진단 A 결과

실기 `m4p704-p1` 은 compile·`-M` rc 0·stderr 각 0 B, `diag_gate`, SDK 포함 의존 manifest SHA·i386 경로 0, collect 및 백엔드 전후 해시 검사가 통과했습니다(`m4-m68k-p704-checks-20261102.json`). A 는 322 B 로 원본 320 B 보다 2 B 길고 funcbytes 0/1 입니다(Python). 크기 차이로 relocation 은 비교하지 않았습니다.

원본과 후보 disassembly(`scratch/p690/original-objdump.txt`, `initmouse-A.objdump.txt`)를 열면 원본은 커서 x·y 에 각각 즉시값 100 을 씁니다. A 의 `x=y=100` 은 volatile y 에 100 을 쓴 후 y 를 다시 읽어 x 에 쓰며 이 영역이 원본보다 깁니다. 다른 차이가 없다는 주장은 아직 하지 않습니다.

## 705. `InitMouse` 진단 B 계획 (코딩 전)

§704 A 의 나머지는 그대로 두고 `evg->cursorLoc.x=evg->cursorLoc.y=100;` 한 줄만 `evg->cursorLoc.x=100; evg->cursorLoc.y=100;` 두 줄로 바꾼 B 를 시험합니다. volatile 접근 순서·재독이 다르므로 A 와 모든 상황에서 동등하다고 가정하지 않습니다. 원본 소스의 철자도 확정하지 않습니다.

plan 705, §704 base·컴파일 줄·구간·임시 BSS 앵커 및 19 참조 목록을 그대로 사용합니다. 새 stage `08_build/runs/tools/m4p705p1-stage`, run `m4p705-p1`, 변형 B 입니다. 실행 전 경로·REGISTRY 를 검사하고 §704.1 의 실기 백엔드 전후 SHA, compile·`-M` rc·stderr, 의존 manifest SHA·SDK·i386, `diag_gate`, collect, 정확한 기호 집합 및 funcbytes·raw relocation 양방향 대조 관문을 그대로 적용합니다. 일치해도 단일 함수 진단이며 자료의 원래 소유·전체 객체 수락은 미결입니다. 진단 작성 전 Codex 서브 에이전트 교차검토와 각 주장 직접 검증을 실시합니다.

### 705.1 교차검토와 독립 판정

Codex 서브 에이전트 `gpt-6.1-terra` 회신을 직접 확인했습니다.

| 주장 | 직접 검증 | 판정 |
|---|---|---|
| 원본은 x 후 y 에 즉시 100, A 는 y 저장·재독 후 x 저장 | 원본과 A objdump 및 volatile `EvGlobals` typedef 확인 | ✅ B 가 원하는 명령을 낼지는 실측합니다. |
| A 의 커서 영역 뒤 relocation 위치는 원본보다 2 B 뒤 | A raw relocation 과 §704 원본 위치 목록을 Python 으로 대조 | ✅ 앞의 두 위치는 같고 이후 위치는 2 B 뒤입니다. 위치만으로 목표 일치를 주장하지 않습니다. |
| PC 상대 raw displacement 는 필드 주소를 더해 addend 를 검사 | `m68k_funcbytes.py` 의 pcrel 처리 확인 | ✅ B raw relocation 검증에 적용합니다. |
| 백엔드 해시와 stderr 는 collect 가 자동으로 모두 검사하지 않음 | `kr_run.py` tool 목록·collect 및 probe 진단 gate 확인 | ✅ 각각 별도로 검사합니다. |

추가 Python 바이트 대조에서 A relocation 필드를 가리고 커서 영역의 길이 차이를 정렬하면 다른 가리지 않은 바이트 차이는 없었습니다. 이는 A 의 relocation 대상 검증이나 B 의 성공을 뜻하지 않습니다. B 의 목표 참조는 §704 에서 미리 정한 19 위치·기호·addend 와 정확히 같아야 합니다.

### 705.2 결과

실기 `m4p705-p1` 의 compile·`-M` rc 0·stderr 0 B, `diag_gate` 둘 참, SDK 포함 의존 manifest SHA 일치·i386 경로 0, collect 입력·도구·출력 무결성 검사가 통과했습니다. m68k 백엔드 일곱 파일 SHA·크기는 전후 §409 기록과 같습니다. probe 의 원본에 없는 이름은 예상한 `_ev_adb_mouse` 하나입니다.

함수별 기록 `09_validation/reconstruction/m4-m68k-funcbytes-p705-B-20261102.json` 은 임시 앵커 `0x40b4fb6=_ev_adb_mouse` 조건에서 1/1, object-only 없음입니다. 독립 검사 `09_validation/reconstruction/m4-m68k-p705-checks-20261102.json`(SHA-256 `522846dcf5f402b0c029e1141d67ee390f28c527c85120b89569f99aed9d31c8`) 은 정의·UNDF 집합과 미리 열거한 후보 raw relocation 19 곳의 위치·폭·type·pcrel·extern·기호·addend 및 원본 링크 목표를 모두 확인했습니다.

이는 함수 코드·참조의 진단 일치입니다. 임시 BSS 의 원래 이름·정의·배치와 유효 입력 범위, 07 구현·전체 객체 수락은 미결이며 07·상태표는 바꾸지 않았습니다.

## 706. `mouse_motion` 단독 진단 계획 (코딩 전)

원본 함수 [0x406a29c, 0x406a394) 는 248 B, 행 217 일부입니다(Python). 원본은 `evg` +20 이 0 일 때만 진행하고, +52 의 bit 17 이 0 이면 마우스 x·y 절댓값 합을 배율 문턱과 비교합니다. 이름 없는 BSS 0x40b4fb6 이 0 이 아닌지에 따라 문턱을 0 또는 1 bit 왼쪽으로 이동합니다. 배열 0 에서 시작해 조건에 맞는 항목을 찾고 앞 항목의 배율을 x·y 에 곱합니다. 이어 movedMask 에서 bit 16·17 을 지우고 위치에 이동량을 더해 `_MoveTheCursor` 에 넘긴 뒤 이동량을 0 으로 둡니다. 원본 바이트·기호에서 읽은 사실이며 `Point`, 마스크 이름, 변수 형·계산식은 SDK·참고 글과의 진단 대응입니다. signed overflow·음수 shift·배열 범위 밖 접근을 C 에서 정당화하지 않으며 모든 입력의 동작 동등성은 미검증입니다.

진단 A 는 SDK `evio.h`, `extern EvGlobals *evg; extern int mouseDelX, mouseDelY, numMouseScales, ev_adb_mouse; extern short mouseScaleThresholds[], mouseScaleFactors[]; extern void MoveTheCursor(Point, int);` 를 두고, 마스크는 16·17 bit 로 정의합니다. `Point p; int x,y,index,shift;` 를 C89 블록 시작에 선언합니다. `if (!evg->cursorSema)` 안에서 `if (!(evg->movedMask & (1 << 17)))` 이면 x·y 각각 `(mouseDelX < 0) ? -mouseDelX : mouseDelX` 및 y 대응, `x += y; shift = ev_adb_mouse != 0;`, `if (x > (mouseScaleThresholds[0] << shift))` 에서 index 를 1 부터 `numMouseScales` 미만까지 증가시키며 `x <= (mouseScaleThresholds[index] << shift)` 이면 break, 그 뒤 index 를 줄여 각 이동량에 factor 를 곱합니다. 그 다음 `evg->movedMask &= ~((1 << 16) | (1 << 17)); p.x=evg->cursorLoc.x+mouseDelX; p.y=evg->cursorLoc.y+mouseDelY; MoveTheCursor(p, evg->movedMask); mouseDelX=mouseDelY=0;` 을 둡니다. 이는 컴파일러 시험용 가설입니다. 참고 NeXTMach `ev_mouse.c:180` 의 다른 조건·커서 처리를 그대로 복사하지 않습니다.

plan 706, §705 base·컴파일 줄, 명시 범위·`rows: []`·`partial: ["m68k-217"]`, stage `08_build/runs/tools/m4p706p1-stage`, run `m4p706-p1` 입니다. 작성 전 경로·REGISTRY 확인, 실기 m68k 백엔드 전후 SHA, compile·`-M` rc·stderr, SDK 포함 의존 manifest SHA·i386 경로 0, `diag_gate` 및 collect 를 확인합니다. 예상 외부 정의 `_mouse_motion` 하나, UNDF `_evg`, `_mouseDelX`, `_mouseDelY`, `_ev_adb_mouse`, `_mouseScaleThresholds`, `_mouseScaleFactors`, `_numMouseScales`, `_MoveTheCursor` 정확히이며 원본에 없는 이름은 진단 `_ev_adb_mouse` 하나입니다. funcbytes 에 `0x40b4fb6=_ev_adb_mouse` 를 주어 바이트와 참조를 검사합니다.

Python 으로 원본에서 찾은 참조는 시작 기준 절대 필드 `0xa,0x24,0x2e,0x3a,0x48,0x58,0x62,0x7c,0x8a,0x90,0x9e,0xa4,0xaa,0xc2,0xd0,0xe4,0xea` 와 PC 상대 호출 필드 `0xde` 입니다. 각 원본 명령 경계·기호·addend 를 직접 검증하고 후보 raw relocation 위치·폭·type·pcrel·extern·기호·addend 및 원본 링크 목표와 양방향 대조합니다. 함수 `same=1`, `total=1`, `object_only=[]`, 정확한 기호 집합·raw 참조·실기 관문이 모두 맞아야 단일 함수 진단 일치입니다. 크기 차이가 나면 funcbytes 의 relocation 은 미비교입니다. 일치해도 BSS 소유·원래 소스·전체 객체 수락은 미결입니다. 작성 전 Codex 서브 에이전트 교차검토와 주장별 직접 검증을 실시합니다.

### 706.1 교차검토와 독립 판정

Codex 서브 에이전트 `gpt-6.1-terra` 회신을 원본·SDK·도구로 직접 대조했습니다.

| 주장 | 직접 검증 | 판정 |
|---|---|---|
| bit 17 이 켜져 있으면 배율만 건너뛰고 이후 마스크·이동·초기화는 실행 | 원본 0x406a2b2–0x406a2ba 와 0x406a344 이후 확인 | ✅ 후보 조건에 반영되어 있습니다. |
| 문턱은 signed short 확장·shift·signed 비교, 같은 값이면 배율 미적용 또는 반복 종료 | 원본 0x406a2e2–0x406a312 확인 | ✅ 유효 범위·signed shift·overflow 는 별도 전제입니다. |
| movedMask 저장 후 volatile 값을 다시 읽어 호출에 넘김 | 원본 0x406a34a–0x406a378, SDK volatile typedef 확인 | ✅ 진단에서 별도 필드 읽기를 유지합니다. |
| 원본 참조 18 곳과 비영 addend | 원본 필드 Python 읽기와 기호표 대조 | ✅ `_mouseScaleThresholds+2`, `_mouseDelX+2`, `_mouseDelY+2` 를 포함해 양방향 검사합니다. |
| 길이가 다르면 funcbytes 는 relocation 을 건너뜀 | `m68k_funcbytes.py` 길이 분기 확인 | ✅ 미비교로 기록합니다. |

정확한 원본 참조 대응: `0xa` `_evg`, `0x24` X, `0x2e` Y, `0x3a` 임시 BSS, `0x48` thresholds, `0x58` numMouseScales, `0x62` thresholds+2, `0x7c` factors, `0x8a`·`0x90` X, `0x9e`·`0xa4` Y, `0xaa` evg, `0xc2` X+2, `0xd0` Y+2, `0xde` `_MoveTheCursor` PC 상대, `0xe4` Y, `0xea` X 입니다. 각 후보 relocation 은 4 B·type 0·extern 이고 0xde 만 PC 상대이며 앞의 +2 셋 외 addend 0 을 기대합니다. 진단 임시 BSS 는 넓은 앵커 범위를 허용하므로 정확한 원본 목표를 별도 대조합니다.

추가로 `INT_MIN` 단항 마이너스, 절댓값 합·factor 곱·위치 계산의 signed overflow, 음수 문턱의 signed left shift 및 범위 밖 short 변환은 C 에서 별도 제약이 필요합니다. `numMouseScales` 가 작아도 문턱 0 과 factor 0 을 읽을 수 있으므로 배열 실제 저장 범위·초기화·호출 조건을 따로 확인해야 합니다. 이 진단은 그 전제를 증명하지 않습니다.

### 706.2 결과

실기 `m4p706-p1` 의 compile·`-M` rc 0·stderr 0 B, `diag_gate` 둘 참, SDK 포함 의존 manifest SHA 일치·i386 경로 0, collect 입력·도구·출력 무결성 검사가 통과했습니다. m68k 백엔드 일곱 파일 SHA·크기는 전후 §409 기록과 같습니다. probe 의 원본에 없는 이름은 예상한 `_ev_adb_mouse` 하나입니다.

함수별 기록 `09_validation/reconstruction/m4-m68k-funcbytes-p706-A-20261102.json` 은 임시 앵커 `0x40b4fb6=_ev_adb_mouse` 조건에서 1/1, object-only 없음입니다. 독립 검사 `09_validation/reconstruction/m4-m68k-p706-checks-20261102.json`(SHA-256 `8e53e5d263888474c2d3e5c4c22b4f11dd1a1bb91e13d72daad97d8e688e5b07`) 은 정의·UNDF 집합과 미리 열거한 후보 raw relocation 18 곳의 위치·폭·type·pcrel·extern·기호·addend 및 원본 링크 목표를 모두 확인했습니다.

이는 함수 코드·참조의 진단 일치입니다. 임시 BSS 의 원래 이름·소유, 값의 유효 범위, 07 구현·전체 객체 수락은 미결이며 07·상태표는 바꾸지 않았습니다.

## 707. `process_mouse_event` 단독 진단 계획 (코딩 전)

원본 함수 [0x406a0d0, 0x406a29c) 는 460 B, 행 217 일부입니다(Python). 원본 명령은 `_buttonsTied`·`_mouseHandedness` 에 따라 인수의 버튼 비트를 조정하고, `evg` 의 버튼 상태와 달라진 왼쪽·오른쪽 버튼에 `LLEventPost` 를 호출합니다. 왼쪽 내림·올림에서 `_lastPressure` 에 각각 255·0 을 저장하고, 왼쪽 이벤트 뒤 `evg` +51 의 한 bit 를 다른 bit 에 복사한 뒤 `eventFlags` 의 0x100 을 조건에 따라 조정합니다. 그 뒤 `evg` +20 을 1 로 두고 인수의 두 7-bit 이동량을 부호 확장해 `_mouseDelX`·`_mouseDelY` 에서 빼며 +20 을 0 으로 둡니다. 이 해석은 원본 objdump·기호표와 §689 SDK 구조를 대조한 가설이며 형·원래 소스·입력 유효성은 확정하지 않습니다.

진단 A 는 07 `nextdev/kmreg.h` 의 `struct mouse` 와 SDK `evio.h`, `extern EvGlobals *evg; extern int buttonsTied, mouseHandedness, mouseDelX, mouseDelY; extern unsigned char lastPressure; extern void LLEventPost(int, Point, NXEventData *);` 를 사용합니다. NeXTMach mk-108.1 `nextdev/ev_mouse.c:123–174` 를 함수 순서의 후보로 보고 원본 바이트에 맞춰 `eventGlobals` 를 `evg` 로, `EVSETSEMA/EVCLEARSEMA` 를 `evg->cursorSema=1/0` 으로 대체합니다. 왼쪽 down 직전 `lastPressure=255`, up 직전 `lastPressure=0`, 왼쪽 변화 처리 끝에 `evg->dontCoalesce=evg->dontWantCoalesce; if (evg->dontCoalesce) evg->eventFlags |= NX_NONCOALSESCEDMASK; else evg->eventFlags &= ~NX_NONCOALSESCEDMASK;` 를 추가합니다. 다른 이벤트 순서·버튼 조정 및 수동 부호 확장 식은 참고 후보의 꼴로 둡니다. 진단 파일은 NeXTMach 출처와 원래 저작권 고지를 보존하고 무시 대상 artifacts 에만 둡니다. 실제 구현 채택 시 파일별·함수별 출처와 변경을 별도로 기록합니다.

plan 707, §706 base·컴파일 줄, 명시 구간·`rows: []`·`partial: ["m68k-217"]`, stage `08_build/runs/tools/m4p707p1-stage`, run `m4p707-p1` 입니다. 작성 전 경로·REGISTRY 확인; 실기 백엔드 전후 SHA, compile·`-M` rc·stderr, SDK·kmreg 의존 manifest SHA·i386 경로 0, `diag_gate`, collect 를 검사합니다. raw 비 STABS 외부 정의 `_process_mouse_event`, UNDF 는 `_buttonsTied`, `_mouseHandedness`, `_evg`, `_lastPressure`, `_LLEventPost`, `_mouseDelX`, `_mouseDelY` 정확히, 원본에 없는 UNDF 0 이어야 합니다. funcbytes `same=1`, `total=1`, `object_only=[]` 와 원본 필드·후보 relocation 양방향 일치가 필요합니다.

Python 으로 원본에서 찾은 참조 필드는 함수 시작 기준 절대 `0xe,0x2c,0x5c,0x84,0x9a,0xaa,0xc0,0xd6,0xf0,0x116,0x148,0x166,0x178,0x19e,0x1b4,0x1ba`, `_LLEventPost` PC 상대 `0x94,0xba,0x142,0x160` 입니다. 각 4 B·type 0·extern, 네 호출만 PC 상대, addend 0 과 정확한 기호·원본 목표를 후보 raw relocation 에서 독립 대조합니다. 크기 불일치면 함수 relocation 은 미비교로 기록합니다. 모든 기준 통과도 단일 함수 진단이지 자료·BSS·전체 객체 수락이 아니며, 정수 overflow·변환·volatile 및 이벤트 구조의 유효 범위는 별도입니다. 작성 전 Codex 서브 에이전트 교차검토와 주장별 직접 검증을 수행합니다.

### 707.1 교차검토와 독립 판정

Codex 서브 에이전트 `gpt-6.1-terra` 회신을 원본·SDK·도구로 직접 확인했습니다.

| 주장 | 직접 검증 | 판정 |
|---|---|---|
| tied·handedness 버튼 조정과 pressure 저장·호출 순서 | 원본 0x406a0dc–0x406a19c 및 NeXTMach 후보 대조 | ✅ 오른쪽 이벤트에는 pressure 저장이 없습니다. |
| `evg` +51 의 bit 2 → bit 1 복사와 flags 0x100 변경 | 원본 0x406a1aa–0x406a1e0 및 SDK bitfield 선언 확인 | ✅ 필드 이름·비트 배치는 대상 컴파일 바이트로 판정합니다. |
| 이동량은 각 바이트의 7 bit 를 부호 확장하며 semaphore 는 조건 밖 | 원본 0x406a246–0x406a28e 및 07 `struct mouse` 확인 | ✅ 정수 overflow 와 입력 포인터·동시성은 별도 전제입니다. |
| 원본 링크 참조 20 곳 | objdump 명령 경계와 Python 으로 읽은 필드·목표 대조 | ✅ 후보 raw relocation 20 개의 위치·형식·기호·addend·원본 목표를 독립 검사합니다. 원본 링크 이미지가 relocation 메타데이터를 보존했다는 뜻은 아닙니다. |
| 참고 머리의 저작권 고지와 출처를 보존해야 함 | NeXTMach 원본 파일 머리 및 `AGENTS.md` 확인 | ✅ 진단 파일에 원래 머리 고지를 보존하며 실제 07 채택은 별도 provenance·변경 기록을 필요로 합니다. |

진단 소스는 07 에 없는 변형이며 실제 구현으로 채택하지 않습니다. 작성 직전 REGISTRY·run·stage·manifest·artifact 경로 부재를 재검사하고, 원본 부호 확장의 int 연산·배열 및 event 구조 유효 범위를 보장하지 못한다는 제한을 유지합니다.

### 707.2 진단 A 결과

실기 `m4p707-p1` 은 compile·`-M` rc 0·stderr 0 B, `diag_gate` 둘 참, 의존 55 머리의 manifest SHA 일치·i386 경로 0, collect 및 m68k 백엔드 전후 해시 검사가 통과했습니다(`09_validation/reconstruction/m4-m68k-p707-checks-20261102.json`). funcbytes `m4-m68k-funcbytes-p707-A-20261102.json` 은 함수 바이트·참조 1/1, object-only 없음입니다.

하지만 raw 비 STABS 외부 정의에는 계획의 함수 외에 COMMON 여섯 `_alert_key`·`_km`·`_km_coni`·`_tthiwat`·`_tthog`·`_ttlowat` 이 있습니다. `kmreg.h` 의 전역 선언 및 그 머리가 포함하는 `sys/tty.h` 를 직접 확인했습니다. 미리 정한 외부 정의 집합 관문에 실패했으므로 A 를 진단 일치로 판정하지 않습니다. probe 의 단독 범위 `OBJECT_MATCH` 도 이 관문을 대신하지 않습니다. 기준을 결과에 맞춰 완화하지 않고 필요한 구조만 분리하는 새 진단을 계획합니다.

## 708. `process_mouse_event` 진단 B 계획 (코딩 전)

§707 A 의 함수 본문·SDK 머리·extern 은 그대로 두되 `#include <nextdev/kmreg.h>` 만 제거하고 해당 머리의 `struct mouse` 선언 한 개를 진단 파일 안에 옮깁니다. 07 `nextmach/nextdev/kmreg.h:100–107` 과 참고 NeXTMach mk-108.1 `nextdev/kmreg.h` 의 같은 선언을 직접 대조하고 원래 파일의 저작권 고지와 출처를 진단 파일에 유지합니다. `u_int` bitfield 의 순서·폭은 그대로이며 공유 머리와 07 은 변경하지 않습니다. 이 분리는 A 의 함수 코드에 영향을 주지 않을 것이라는 가설이지 의미 동등성·원래 소스 구조의 증명이 아닙니다.

plan 708, §707 의 base·컴파일 줄·단일 함수 범위·20 원본 필드와 정확한 기호 집합, stage `08_build/runs/tools/m4p708p1-stage`, run `m4p708-p1` 을 사용합니다. REGISTRY·경로 확인, 실기 백엔드 전후 SHA, compile·`-M` rc·stderr, 의존 manifest SHA·i386 경로 0, `diag_gate`, collect 를 검사합니다. 진단 원본 A 의 함수 본문은 바꾸지 않고 선언만 분리했음을 텍스트로 확인합니다. raw 비 STABS 외부 정의는 `_process_mouse_event` 하나, COMMON 0, UNDF 는 §707 의 일곱 이름 정확히여야 합니다. funcbytes `same=1`, `total=1`, `object_only=[]`, 후보 raw relocation 20 곳의 위치·폭·type·pcrel·extern·기호·addend 와 원본 목표 양방향 대조가 모두 통과해야 단일 함수 진단 일치입니다. 길이 차이면 relocation 은 미비교입니다. 원래 헤더 구성·객체 귀속·자료 소유·모든 입력에서의 의미 동등성·전체 수락은 미결입니다. 작성 전 Codex 서브 에이전트 교차검토와 주장별 직접 검증을 수행합니다.

### 708.1 교차검토와 독립 판정

Codex 서브 에이전트 `gpt-6.1-terra` 의 회신을 직접 대조했습니다.

| 주장 | 직접 검증 | 판정 |
|---|---|---|
| A 는 COMMON 여섯으로 사전 외부 정의 관문을 통과하지 못함 | raw Mach-O 비 STABS 기호와 `m4-m68k-p707-checks` 확인 | ✅ probe `OBJECT_MATCH` 와 구분합니다. |
| A 에 없는 kmreg 별도 고지·출처를 B 에 명시해야 함 | A 파일 머리, upstream `kmreg.h` 첫 고지·HISTORY·Git remote 확인 | ✅ B 에 upstream 고지·HISTORY 및 `https://github.com/johnsonjh/NeXTMach.git`, commit `f6bdb9c3268f0eadc545d41bcc0564453b17001e`, `mk-108.1/nextdev/kmreg.h:100–106` 을 기록합니다. |
| `u_int` 정의 머리와 선언·함수 본문의 동일성을 확인해야 함 | A 의 `<sys/types.h>`, 07 및 upstream 의 `struct mouse` 를 Python 으로 추출해 바이트 동일 확인 | ✅ B 는 `<sys/types.h>` 를 유지하고 선언 전문·함수 본문을 각각 Python 으로 대조합니다. |
| 순수 UNDF 와 COMMON 을 분리하고 raw relocation 증거가 필요 | `macho_obj` 출력과 funcbytes 의 참조 처리 확인 | ✅ COMMON 0·순수 UNDF 정확 집합과 20 위치의 양방향 raw 검사 기록을 남깁니다. |

컴파일·의존성 검사는 해당 진단의 실기 컴파일을 확인할 뿐 전체 GCC 2.7 호환성이나 모든 입력의 의미 동등성을 검증하지 않습니다. `struct mouse` 의 upstream 정확한 행은 100–106 이며 앞 절의 100–107 은 빈 줄을 포함한 범위입니다.

### 708.2 진단 B 결과

실기 `m4p708-p1` 의 compile·`-M` rc 0·stderr 0 B, `diag_gate` 둘 참, SDK 포함 의존 manifest SHA 일치·i386 경로 0, collect 및 m68k 백엔드 전후 해시 검사가 통과했습니다. A 와 함수 본문은 같고 분리한 구조 선언 및 원래 고지를 upstream 과 대조했습니다. raw 비 STABS 외부 정의는 `_process_mouse_event` 하나, COMMON 0, UNDF 는 사전 지정한 일곱 이름 정확히이며 원본에 없는 UNDF 는 없습니다.

`09_validation/reconstruction/m4-m68k-funcbytes-p708-B-20261102.json` 은 함수 바이트·참조 1/1, object-only 없음입니다. 독립 검사 `09_validation/reconstruction/m4-m68k-p708-checks-20261102.json` (SHA-256 `4eeb184bb80809129bd3b2c87e50cf3809849d6ce464b8ed0f4016a163701d8f`) 은 미리 열거한 후보 raw relocation 20 곳의 위치·폭·type·pcrel·extern·기호·addend 및 원본 링크 목표를 모두 확인했습니다. 진단 A 는 §707.2 의 정의 집합 관문 실패로 남습니다.

이는 단일 함수 코드·참조의 진단 일치입니다. 원래 머리 구성·객체 귀속·자료 소유·입력 유효성 및 전체 객체 수락은 미결이며 07 구현·상태표는 바꾸지 않았습니다.

## 709. `MoveTheCursor` 단독 진단 계획 (코딩 전)

원본 함수 표의 [0x4069eb8, 0x406a0d0) 는 536 B 이고 재고 `m68k-216` 전체의 미배정 구간입니다. 앞 `ev_kbd` 및 뒤 `ev_mouse` 어느 객체의 소속인지 결정하지 않습니다. 원본 명령에서 `_screens` 가 0 이면 종료하고, 현재 화면 경계를 벗어나면 0x406aa0c 를 호출해 음수 결과일 때 `cursorPin` 에 맞춰 두 short 좌표를 각각 제한합니다. 기존 `evg` 위치와 같으면 종료하며, 다르면 위치를 저장합니다. 새 화면 결과가 비음수면 기존 화면에 `evdispatch(1, old, 0)`, 화면·pin 갱신 후 `evdispatch(2, new, 0)` 를, 아니면 `evdispatch(3, current, 0)` 를 실행합니다. 이후 `evg` 이동 마스크 및 버튼의 bit 조건에 따라 이벤트 6·7·5 중 최대 하나를 차례로 선택하고, mouseRect 유효 bit 가 켜져 있으며 새 점이 사각형 밖이면 이벤트 9 를 보낸 뒤 bit 를 지웁니다. 화면 및 mouseRect 경계의 하한은 포함, 상한은 배타적이고 pin 상한은 포함됩니다. 명령에서 두 번째 인수 슬롯 읽기는 보이지 않지만 원래 원형은 확정할 수 없습니다. 필드명·자료형·호출 대상의 의미는 SDK 및 이전 진단과의 대응 가설입니다.

진단 A 는 §699 의 SDK 머리와 `extern EvGlobals *evg; extern EvScreen *evScreen; extern Bounds cursorPin; extern int screens, currentScreen; extern int ev_point_to_screen(Point); extern void evdispatch(int,int,int), LLEventPost(int,Point,NXEventData *);` 를 사용합니다. `void MoveTheCursor(Point p, int mask)` 의 `int newscreen=-1` 로 시작하고 원본 순서에 따라 화면 bounds 의 `minx <= p.x && p.x < maxx && miny <= p.y && p.y < maxy` 를 반대로 검사합니다. 화면을 찾지 못할 때 x·y 각각 `p.x < cursorPin.minx ? cursorPin.minx : (p.x > cursorPin.maxx ? cursorPin.maxx : p.x)` 형태로 clamp 합니다. 위치 비교는 진단용 `*(int *)&p == *(volatile int *)&evg->cursorLoc` 이고 다르면 `evg->cursorLoc=p` 를 씁니다. 전환 분기에서는 `evdispatch`, `currentScreen`, `cursorPin` 대입·상한 감소·`evdispatch` 순서를 따릅니다. 이후 먼저 `if (evg->movedMask)` 로 volatile 값을 읽고 그 안에서 `evg->movedMask` 를 매 조건에서 다시 직접 읽으며 bit 6 및 buttons bit 2, bit 7 및 buttons bit 0, bit 5 순서의 `if/else if` 에서 각각 `LLEventPost(6/7/5,p,0)` 를 사용합니다. `mouseRectValid` 와 별도 bounds 필드로 사각형 밖을 검사한 뒤 bit 를 다시 확인하여 `LLEventPost(9,evg->cursorLoc,0); evg->mouseRectValid=0;` 를 실행합니다. `mask` 는 후보 원형의 미사용 인수입니다. 명시적 pointer cast 는 대상 컴파일 진단 가설이며 C 별칭 규칙·정렬과 동시 접근을 보장하지 않습니다. 참조 NeXTMach `nextdev/ev_cursor.c:52–126` 은 동작 순서가 달라 원본 사실로 취급하지 않고 그 텍스트를 복사하지 않습니다.

plan 709, §708 의 base·컴파일 줄, 명시 범위와 `rows: ["m68k-216"]`, stage `08_build/runs/tools/m4p709p1-stage`, run `m4p709-p1` 을 계획합니다. `span()` 으로 재고의 정확한 겹침을 사전 확인하고 경로·REGISTRY 부재, 실기 m68k 백엔드 전후 SHA, compile·`-M` rc·stderr, SDK 포함 의존 manifest SHA·i386 경로 0, `diag_gate` 및 collect 무결성을 확인합니다. 외부 비 STABS 정의는 `_MoveTheCursor` 하나, COMMON 0, UNDF 는 `_screens`, `_currentScreen`, `_evScreen`, `_cursorPin`, `_evg`, `_ev_point_to_screen`, `_evdispatch`, `_LLEventPost` 정확히이며 원본에 없는 이름은 임시 `_ev_point_to_screen` 하나가 예상됩니다. 함수 bytes 는 `0x406aa0c=_ev_point_to_screen` 조건에서 `same=1`, `total=1`, `object_only=[]` 를 요구합니다.

원본 링크 참조 필드 위치를 Python 과 명령 경계로 확인합니다. 절대 참조는 시작 기준 `0xe,0x18,0x28,0x6e,0x7a,0x8e,0x9a,0xaa,0xc6,0xd0,0xd8,0xde,0xf4,0xfa,0x100,0x106,0x11e,0x132,0x15e,0x182,0x1a6,0x1de,0x1fe`, PC 상대 호출은 `0x5c,0x128,0x19c,0x1f8` 입니다. 원본 `evdispatch` 의 앞 두 호출은 하나의 절대 주소 로드와 두 레지스터 간접 호출이고 세 번째가 별도 PC 상대 호출입니다. 후보 raw relocation 각각의 위치·폭·type·pcrel·extern·기호·addend 및 원본 목표를 양방향 대조합니다. 범위 길이가 다르면 funcbytes 의 relocation 은 미비교로 기록하고 불일치를 완화하지 않습니다. 완전 일치해도 원본 소스·원형·객체 귀속·자료 소유·유효 포인터와 동시성·모든 입력의 의미 동등성·전체 객체 수락은 미결입니다. 작성 전 Codex 서브 에이전트에 계획을 교차검토시키고 각 주장을 직접 검증합니다.

### 709.1 교차검토와 독립 판정

Codex 서브 에이전트 `gpt-6.1-terra` 의 주장과 계획을 원본 명령·도구·SDK 로 직접 대조했습니다.

| 주장 | 직접 검증 | 판정 |
|---|---|---|
| `m68k-216` 은 정확한 단일 재고 행 | `span()` 실행과 재고·함수 표 확인 | ✅ `rows` 에 지정하며 귀속 확정은 아닙니다. |
| 원본 참조 27 곳과 절대·PC 상대 분류 | objdump 명령 경계와 원본 필드·목표를 Python 으로 각각 확인 | ✅ 계획의 절대 23·PC 상대 4 와 일치합니다. |
| pin 참조에 addend 가 있음 | 원본 필드 목표와 §699 `cursorPin` 기준 주소를 Python 으로 대조 | ✅ `0x6e:+0`, `0x7a:+2`, `0x8e:+4`, `0x9a:+6`, `0xf4:+0`, `0xfa:+4`, `0x100:+2`, `0x106:+6`; 나머지 참조 addend 0 입니다. |
| movedMask 선행 volatile 읽기 필요 | 원본 0x4069fee–0x4069ff8 및 SDK volatile typedef 확인 | ✅ 위 후보 계획에 선행 `if` 를 추가했습니다. |
| 화면 전환의 앞 두 호출은 공통 주소 로드 후 간접 호출 | 원본 0x4069f86·0x4069f8c·0x4069fca 확인 | ✅ `0xd0` 절대 참조 하나이고 별도 `0x128` 은 PC 상대 호출입니다. |
| mouseRectValid 재검사는 사각형 밖에서만 실행 | 원본 0x406a05c–0x406a0a2 확인 | ✅ 진단 순서에 반영합니다. |

구조체 대입의 실제 명령과 별칭·volatile 처리, 직사각형 검사 분기 배치는 실기 컴파일 결과로 검증합니다. 원본의 4 B 위치 저장과 다르면 일치하지 않습니다.

### 709.2 진단 A 결과

실기 `m4p709-p1` 의 compile·`-M` rc 0·stderr 0 B, `diag_gate`, 의존 manifest SHA·SDK·i386 경로 및 collect, 백엔드 전후 해시 검사는 통과했습니다. raw 외부 정의·COMMON·UNDF 집합도 사전 조건과 같고, 원본에 없는 UNDF 는 임시 `_ev_point_to_screen` 하나입니다. 독립 환경·기호 검사 기록은 `09_validation/reconstruction/m4-m68k-p709-checks-20261102.json` (SHA-256 `57e5e5ac9465f400f91c75cf8f5eb496310ba55ad4c597e6e12bd9540e760fbc`) 입니다.

그러나 `09_validation/reconstruction/m4-m68k-funcbytes-p709-A-20261102.json` 은 크기 536 B 로 같아도 0/1, 비교 바이트 차이 129 및 정렬 위치 기준 참조 차이 8 을 보고해 함수 일치 관문에 실패했습니다. 코드 배치가 다른 경우 위치 기준 참조 불일치를 원본 참조 자체의 실제 의미 차이라고 단정할 수 없습니다. 전체 후보 raw relocation 과 원본 명령의 양방향 관문도 통과로 기록하지 않습니다. 후보 objdump `scratch/p690/move-p709-A-objdump.txt` 에서는 첫 화면 사각형 계산부터 원본과 레지스터·명령 배치가 다릅니다. 다음 진단은 이 첫 차이의 C 표현과 휘발성 읽기 순서를 원본과 직접 대조해 계획해야 합니다. 07 구현·상태표·객체 귀속은 변경하지 않았습니다.

## 710. `MoveTheCursor` 화면 bounds 포인터 진단 계획 (코딩 전)

§709 A 와 원본의 첫 차이에서 원본은 `_currentScreen` 으로 `_evScreen` 요소의 주소를 계산하고 그 주소를 유지해 bounds 의 네 short 를 읽습니다. A 는 첫 좌표 읽기를 먼저 배치하고 인덱스 주소 지정 방식이 다릅니다. SDK 에서 `EvScreen` 은 volatile typedef 이므로 bounds 의 volatile 읽기를 보존해야 합니다. 생성 코드만으로 원래 C 표현이나 자료의 동시성 의미를 확정하지 않습니다.

진단 B 는 §709 A 의 함수 초기에 `volatile Bounds *screenBounds;` 를 C89 선언하고 `if (!screens) return;` 다음 `screenBounds = &evScreen[currentScreen].bounds;` 를 한 번 실행합니다. 첫 화면 사각형 비교의 네 `evScreen[currentScreen].bounds` 참조만 `screenBounds->` 로 바꾸고 나머지 본문·선언·조건은 그대로 둡니다. 현재 화면 인덱스와 배열 포인터를 한 번 읽는 가설이며, 화면 인덱스·포인터의 동시 변경이 허용되는 상황까지 A 와 동등하다는 주장은 아닙니다. 원본의 네 bounds 읽기와 인덱스·포인터 횟수 및 순서는 실기 결과로 확인합니다.

plan 710, §709 의 base·컴파일 줄·정확한 `m68k-216` 범위, stage `08_build/runs/tools/m4p710p1-stage`, run `m4p710-p1` 을 씁니다. 코딩 전 Codex `gpt-6.1-terra` 교차검토 및 주장별 직접 검증, 경로·REGISTRY 부재, 실기 백엔드 전후 SHA, compile·`-M` rc·stderr, SDK 포함 의존 manifest SHA·i386 경로 0, `diag_gate`, collect 를 확인합니다. 기호 집합·임시 앵커·27 참조 위치와 addend 는 §709 와 같은 엄격한 관문이며, `same=1`, `total=1`, `object_only=[]` 및 raw relocation 27 곳의 위치·폭·type·pcrel·extern·기호·addend·원본 목표가 모두 일치해야 단일 함수 진단 일치입니다. 길이가 다르면 funcbytes relocation 은 미비교로 기록합니다. 불일치여도 첫 차이 및 실제 생성 명령을 보존하며 관문을 완화하지 않습니다. 원래 소스·함수 원형·객체 귀속·자료 소유·포인터 유효성 및 동시성·전체 객체 수락은 미결입니다.

### 710.1 교차검토와 독립 판정

Codex 서브 에이전트 `gpt-6.1-terra` 의 주장을 원본 objdump·후보 objdump·SDK 와 직접 대조했습니다. `EvScreen` 은 volatile 구조체 typedef 이고 `Bounds` 의 네 필드는 short 이므로 `volatile Bounds *` 는 읽기의 volatile 자격을 유지합니다. 원본은 화면 인덱스로 요소 주소를 계산한 다음 bounds 를 읽으며 A 는 좌표를 먼저 읽고 인덱스 주소 지정 방식으로 접근합니다. 이 변경으로 동일 명령이 나온다는 보장은 없습니다.

원본 0x4069f40 에서는 y 좌표를 pin 하한보다 먼저 읽지만 A 에서는 반대이며, 원본 0x4069f60 이후 위치 비교·저장과 A 의 레지스터 사용도 다릅니다. 두 차이를 직접 확인했으며 B 는 첫 bounds 계산만 바꾸므로 나머지 차이가 남을 수 있습니다. §709 의 기호·환경·참조 관문 및 동시성 한계를 유지합니다.

### 710.2 진단 B 결과

실기 `m4p710-p1` 의 compile·`-M` rc 0·stderr 0 B, `diag_gate`, 의존 manifest SHA·SDK 포함·i386 경로 0, collect, 백엔드 전후 해시 및 raw 외부 정의·COMMON·UNDF 관문은 통과했습니다. 독립 환경·기호 검사 `09_validation/reconstruction/m4-m68k-p710-checks-20261102.json` 의 SHA-256 은 `1d2a530bf29feda9ccca7f2802037c50bfd7297b5f6323d4c003349d65d45b72` 입니다.

`09_validation/reconstruction/m4-m68k-funcbytes-p710-B-20261102.json` 은 함수 크기 536 B, 0/1, 비교 바이트 차이 123 및 정렬 위치 기준 참조 차이 7 을 보고하므로 단일 함수 일치 관문에 실패했습니다. 참조가 서로 다른 명령 위치에 배치된 경우 정렬 위치 기준 참조 차이는 의미 차이의 증명이 아니며, 전체 raw relocation 양방향 관문은 통과로 판정하지 않습니다.

후보 objdump `scratch/p690/move-p710-B-objdump.txt` 와 원본을 대조하면 B 는 처음 `_currentScreen` 을 읽은 뒤 인덱스를 계산한다는 점에서 원본과 순서가 같지만, 원본은 shift 와 `addal` 을 쓰고 B 는 인덱스 주소를 `lea` 로 계산하며 y 좌표 읽기 배치도 다릅니다. 이후 clamp·위치 비교의 차이도 별도 조사해야 합니다. B 는 진단 후보에 머물며 원래 구현·동시성·객체 귀속을 확정하지 않습니다. 07 구현·상태표는 변경하지 않았습니다.

## 711. `MoveTheCursor` 바이트 단위 화면 주소 진단 계획 (코딩 전)

§710 B 는 원본과 달리 `_evScreen` 을 로드한 뒤 인덱스 scale LEA 로 주소를 결합합니다. 원본은 먼저 인덱스의 5 배를 만든 뒤 3 bit shift 하고 `_evScreen` 을 `addal` 로 더합니다. 두 표현 모두의 실제 생성 명령은 대상 컴파일로만 판단합니다. SDK ABI 진단 §692 의 `EvScreen` 크기 40 B·`bounds` 위치 12 B 를 재확인합니다.

진단 C 는 §710 B 의 선언에 C89 `long screenOffset;` 를 추가하고 `screenBounds` 대입을 다음 두 문장으로 바꿉니다: `screenOffset = currentScreen * (long)sizeof(EvScreen);` 와 `screenBounds = &((EvScreen *)((volatile char *)evScreen + screenOffset))->bounds;`. 그 외 함수 본문은 B 와 동일하게 둡니다. `EvScreen` 은 volatile typedef 이며 `volatile char *` 산술 뒤 멤버 접근의 volatile 자격을 유지합니다. 포인터 산술 자체는 volatile 접근이 아닙니다. 부호 곱셈 overflow, 할당 영역 밖의 바이트 포인터 산술 및 정렬·객체 유효성은 별도 전제입니다. 이 진단은 원본 소스 표현이나 여러 입력에서의 의미 동등성에 대한 결론이 아닙니다.

plan 711, §710 과 같은 base·컴파일 줄·`m68k-216` 범위, stage `08_build/runs/tools/m4p711p1-stage`, run `m4p711-p1` 입니다. 작성 전 Codex `gpt-6.1-terra` 계획 교차검토와 주장별 직접 검증을 수행하고 경로·REGISTRY, 실기 m68k 백엔드 전후 SHA, compile·`-M` rc·stderr, SDK 포함 모든 의존 manifest SHA·i386 경로 0, `diag_gate` 와 collect 를 검사합니다. 외부 기호·COMMON·임시 앵커, 27 원본 참조 위치·addend 및 함수 바이트·raw relocation 의 엄격한 일치 관문은 §709 그대로입니다. 길이가 다르면 funcbytes relocation 은 미비교이며, 일치하지 않으면 크기·차이·첫 생성 명령을 기록하고 raw 일치를 주장하지 않습니다. 기존 진단과의 텍스트 차이를 확인합니다. 최초 화면 bounds 계산만 바꾸므로 y 좌표 읽기·clamp·위치 비교 및 다른 분기는 별개입니다. 실제 소스·객체 귀속·데이터 소유·동시성·전체 객체 수락은 미결입니다.

### 711.1 교차검토와 독립 판정

Codex 서브 에이전트 `gpt-6.1-terra` 의 주장을 SDK·원본 명령 및 §692.2 실기 ABI 기록과 대조했습니다. `EvScreen` 은 volatile typedef 이고 `bounds` 주소는 `volatile Bounds *` 에 맞으며 캐스트한 바이트 포인터로 산술한 뒤에도 멤버 읽기는 volatile 입니다. 산술 자체를 volatile 접근이라고 주장하지 않도록 계획 문구를 정정했습니다. §692.2 대상 ABI 실측은 SDK 형의 크기 40 B 와 bounds 위치 12 B 를 확인하지만 원본 C 형을 증명하지 않습니다. `(long)sizeof` 에 의해 unsigned 승격을 피한다는 것은 C 식의 형에 대한 진단 선택이며 그 기록만으로 `long` 의 크기를 별도 실측했다고 주장하지 않습니다.

원본과 B 의 주소 계산 명령 차이를 objdump 로 직접 확인했고, 선언 하나와 대입 표현 하나만 바꿉니다. 컴파일러가 원래 인덱스 식으로 최적화하거나 다른 읽기 순서를 택할 수 있으므로 실측이 필요합니다. 27 참조 관문과 포인터 유효성·정렬·overflow 및 동시성의 미결 조건을 유지합니다.

### 711.2 진단 C 결과

실기 `m4p711-p1` 의 compile·`-M` rc 0·stderr 0 B, `diag_gate`, SDK 포함 의존 manifest SHA·i386 경로 0, collect 및 백엔드 전후 해시가 통과했습니다. 외부 정의·COMMON·UNDF 는 사전 조건과 같으며, B 에 지정한 선언·대입 표현 외 변경이 없음을 텍스트로 확인했습니다. 기록 `09_validation/reconstruction/m4-m68k-p711-checks-20261102.json` 의 SHA-256 은 `584e7d1719597eea9e833100bf4a772849fdf9cc85b13b937a364bad944b489f` 입니다.

후보 C 의 `__text` 536 B 는 B 와 바이트별로 동일하고, 후보 raw relocation 의 위치·길이·type·pcrel·extern·scattered 및 해석된 기호 목록도 같습니다. `__text` SHA-256 은 두 후보 모두 `dcd8c076ea2bc9193419d235190d676969cd1a3c3be1612f4f8d55e2db54726f` 입니다. 이는 해당 대상 컴파일 조건에서 두 진단이 같은 코드와 정규화한 참조 항목을 생성했다는 결과이며 전체 객체나 모든 입력의 의미 동등성 증명은 아닙니다.

함수 비교 `09_validation/reconstruction/m4-m68k-funcbytes-p711-C-20261102.json` 은 0/1, 원본 대비 비교 바이트 차이 123 및 정렬 위치 기준 참조 차이 7 이므로 사전 일치 관문에 실패했습니다. 원본 relocation 전체 양방향 관문은 통과로 주장하지 않습니다. 이 표현 변경만으로 첫 주소 계산 차이는 해소되지 않았으며 다른 코드 표현 또는 좌표 읽기 차이를 별도 진단해야 합니다. 07 구현·상태표·객체 귀속은 바꾸지 않았습니다.

## 712. `MoveTheCursor` 위치 비교 피연산자 진단 계획 (코딩 전)

§711 C 와 원본을 비교하면 화면 경계 이후 위치 비교에서 원본은 `evg` 주소를 읽고 인수의 위치 long 을 데이터 레지스터에 적재한 뒤 메모리의 위치와 비교하며, 달라지면 같은 레지스터를 위치에 저장합니다. C 는 인수와 volatile 위치를 서로 다른 레지스터에 적재해 비교하고 인수 레지스터를 저장합니다. 원본 objdump 와 §710 B·§711 C 의 동일한 진단 `__text` 로 확인했으며 레지스터 배치만으로 원래 C 형이나 표현은 결정할 수 없습니다.

진단 D 는 §711 C 의 `if (*(int *)&p == *(volatile int *)&evg->cursorLoc) return;` 만 `if (*(volatile int *)&evg->cursorLoc == *(int *)&p) return;` 로 바꿉니다. 비교에서 volatile 위치 접근은 한 번이고 인수는 비volatile 이지만 C 의 피연산자 평가 순서는 보장되지 않아 실제 생성 명령은 실기에서 확인합니다. 포인터 cast 의 정렬·유효 객체·별칭·int 크기·Point 배치와 동시 접근은 여전히 미해결입니다. 값 비교의 대칭성만으로 모든 가능한 C 실행이나 원래 소스와의 동등성을 주장하지 않습니다.

plan 712, §711 base·컴파일 줄·정확한 `m68k-216` 범위, stage `08_build/runs/tools/m4p712p1-stage`, run `m4p712-p1` 입니다. 진단 소스 작성 전 Codex `gpt-6.1-terra` 교차검토·각 주장 직접 검증을 실시합니다. 경로·REGISTRY, 실기 백엔드 전후 SHA, compile·`-M` rc·stderr, SDK 포함 모든 의존 manifest SHA·i386 경로 0, `diag_gate`, collect 및 예상 외부 정의·COMMON·UNDF 는 §711 과 같은 관문입니다. 소스 차이가 비교 피연산자의 교환뿐임을 검사합니다. `0x406aa0c=_ev_point_to_screen` 임시 앵커에서 함수 바이트 `same=1`, `total=1`, `object_only=[]` 및 §709 의 원본 참조 27 곳·addend 에 대한 후보 raw relocation 양방향 검증이 모두 통과해야 단일 함수 일치입니다. 길이가 다르면 funcbytes relocation 은 미비교입니다. 실패 시 실제 크기·생성 명령 및 차이를 기록하고 관문을 완화하지 않습니다. 화면 주소 계산, y 읽기, 원래 소스·객체 귀속·자료 소유·동시성·전체 객체 수락은 미결입니다.

### 712.1 교차검토와 독립 판정

Codex 서브 에이전트 `gpt-6.1-terra` 의 주장을 원본 및 §710 B objdump 와 SDK 의 `EvGlobals` volatile 선언에 대조했습니다. 원본은 인수의 4 B 를 레지스터에 읽고 메모리와 비교한 뒤 그 레지스터로 저장하며 B 는 두 레지스터로 읽어 비교합니다. 계획된 비교식은 소스 수준에서 volatile int 읽기 하나를 유지하지만 C 는 두 피연산자의 평가 순서를 지정하지 않습니다. 접근의 정렬·별칭·유효 객체·크기 및 동시성 전제는 별도로 남습니다. 피연산자 교환만 적용됐는지 확인하고, 대상 오브젝트의 실제 비교·읽기·저장 명령과 원본을 대조합니다. 함수 크기 불일치 시 relocation 은 미비교이며 전체 raw 원본 관문을 통과로 취급하지 않습니다.

### 712.2 진단 D 결과

실기 `m4p712-p1` 의 compile·`-M` rc 0·stderr 0 B, `diag_gate`, SDK 포함 의존 manifest SHA·i386 경로 0, collect 및 백엔드 전후 해시가 통과했습니다. 외부 정의·COMMON·UNDF 는 사전 조건과 같고 소스 차이는 비교 피연산자 교환뿐입니다. 독립 검사 `09_validation/reconstruction/m4-m68k-p712-checks-20261102.json` 의 SHA-256 은 `07b1ab5a70335cc5e45c15c87ffac557d71399fa8ef10400ba4e320f8f61144b` 입니다.

함수 비교 `09_validation/reconstruction/m4-m68k-funcbytes-p712-D-20261102.json` 은 536 B, 0/1, 비교 바이트 차이 123 및 정렬 위치 기준 참조 차이 7 이므로 사전 일치 관문에 실패했습니다. 원본 전체 raw relocation 양방향 관문도 통과로 판정하지 않습니다. 동일한 차이 개수만으로 같은 기계어라고 판단하지 않고 `__text` 를 직접 비교한 결과 C 의 SHA-256 `dcd8c076ea2bc9193419d235190d676969cd1a3c3be1612f4f8d55e2db54726f`, D 의 `2159a34c7d19bb9ff3c14ebf6f4200e761e9c6c857adb1f4cb800a2f5d371c7a` 로 서로 다릅니다.

D 의 objdump `scratch/p690/move-p712-D-objdump.txt` 는 위치 메모리를 d0, 인수 위치를 d1 에 읽어 d1 과 d0 를 비교하고 d1 을 저장합니다. 원본의 인수 d0 로드 및 메모리 직접 비교·d0 저장과 다릅니다. 피연산자 교환이 대상 코드에 영향을 줬으나 원하는 원본 명령을 재현하지 못한 관찰입니다. 정렬 위치 기준 참조 차이는 코드 배치 차이로 생길 수 있으며 의미 차이라고 단정하지 않습니다. 07 구현·상태표·객체 귀속은 변경하지 않았습니다.

## 713. `MoveTheCursor` 위치 값 보관 진단 계획 (코딩 전)

§712 D 는 원본의 위치 long 직접 메모리 비교와 같은 레지스터 저장을 재현하지 못했습니다. 원본 0x4069f60–0x4069f72 는 `evg` 주소 로드, 인수 long 로드, 메모리 위치와 직접 비교, 다른 경우 같은 long 의 저장 순입니다. 이는 원본 명령에서 관찰한 사실이며 C 소스의 형·원형을 증명하지 않습니다.

진단 E 는 §712 D 의 C89 선언부에 `int packed;` 를 더하고, 위치 비교와 뒤따르는 구조체 대입 두 문장을 `packed = *(int *)&p; if (packed == *(volatile int *)&evg->cursorLoc) return; *(volatile int *)&evg->cursorLoc = packed;` 로 바꿉니다. 나머지 코드는 D 그대로입니다. 같은 인수 값을 비교와 저장에 쓰도록 표현한 코드 생성 가설입니다. 소스에서 `evg` 는 비교와 저장에 각각 평가되며 구조체 대입을 volatile int 저장으로 바꾸므로 읽기·쓰기 폭과 횟수, 재읽기·별칭·동시성 의미가 D 또는 원본과 모든 실행에서 동등하다고 가정하지 않습니다. Point 에 대한 int 접근의 정렬·유효형·별칭·int 와 Point 크기·표현도 미해결이며 07 에 채택하지 않습니다.

plan 713, §712 base·컴파일 줄·`m68k-216` 범위, stage `08_build/runs/tools/m4p713p1-stage`, run `m4p713-p1` 입니다. 작성 전 Codex `gpt-6.1-terra` 교차검토 및 주장별 직접 검증; REGISTRY·경로 부재, 실기 백엔드 전후 SHA, compile·`-M` rc·stderr, SDK 포함 의존 manifest SHA·i386 경로 0, `diag_gate`, collect 및 소스 변경 범위·기호 집합을 확인합니다. `0x406aa0c=_ev_point_to_screen` 임시 앵커에서 함수 바이트 `same=1`, `total=1`, `object_only=[]` 와 §709 의 원본 필드 27 곳·addend 에 대한 raw relocation 양방향 검증을 모두 만족해야 단일 함수 일치입니다. 길이 차이면 funcbytes relocation 은 미비교입니다. 대상 objdump 에서 위치 읽기·쓰기 폭·횟수, 포인터 로드와 레지스터 재사용을 원본과 대조합니다. 실패 시 결과와 차이를 보존하며 기준을 완화하지 않습니다. 화면 주소·좌표 읽기, 실제 소스·객체 귀속·자료 소유·동시성·전체 객체 수락은 미결입니다.

### 713.1 교차검토와 독립 판정

Codex 서브 에이전트 `gpt-6.1-terra` 의 주장을 원본 및 §712 objdump 와 SDK 선언에 직접 대조했습니다. 원본 비교와 저장은 같은 a0 기준이고 인수 d0 값을 재사용합니다. D 의 교체 대상 두 문장 및 SDK 의 short 좌표와 volatile `EvGlobals` 선언을 확인했습니다. E 는 소스 수준에서 비교 시 volatile int 읽기 하나와 불일치 시 쓰기 하나를 표현하며 `evg` 식을 각각 평가합니다. 같은 a0 사용, 접근 폭·원자성·동시성 및 평가 순서는 소스만으로 확정하지 않고 컴파일 결과와 전제를 분리합니다. packed 의 소스 선행 로드가 원본의 `evg` 선행 로드로 생성된다는 보장도 없습니다. 27 참조 및 환경 관문을 유지합니다.

### 713.2 진단 E 결과

실기 `m4p713-p1` 의 compile·`-M` rc 0·stderr 0 B, `diag_gate`, SDK 포함 의존 manifest SHA·i386 경로 0, collect 및 백엔드 전후 해시가 통과했습니다. 외부 정의·COMMON·UNDF 는 사전 조건과 같고 소스 차이는 계획된 선언과 두 문장의 교체뿐입니다. 독립 검사 `09_validation/reconstruction/m4-m68k-p713-checks-20261102.json` 의 SHA-256 은 `ff62a9c4c184831613ecef5799012afc01843ac324b43ea3908175126c68730b` 입니다.

함수 비교 `09_validation/reconstruction/m4-m68k-funcbytes-p713-E-20261102.json` 은 536 B, 0/1, 비교 바이트 차이 123 및 정렬 위치 기준 참조 차이 7 이며 사전 일치 관문에 실패했습니다. 원본의 전체 raw relocation 양방향 관문도 통과로 판정하지 않습니다. `__text` SHA-256 은 E `b7bc7ce10678484b99d55d999631ff91443d24d0d7e80c3093eeb43a83981bc4`, D `2159a34c7d19bb9ff3c14ebf6f4200e761e9c6c857adb1f4cb800a2f5d371c7a` 로 달라 차이 개수가 같아도 동일한 기계어는 아닙니다.

E 의 objdump `scratch/p690/move-p713-E-objdump.txt` 는 인수 long 을 d1 에 먼저 읽고 `evg` 포인터를 a0 에 읽어 위치 long 을 d0 로 로드한 뒤 레지스터를 비교하고 불일치 시 같은 a0 기준으로 d1 을 저장합니다. 원본과 동일한 위치 읽기·쓰기 폭과 동일 a0 기준 저장을 보이나 읽기 순서와 메모리 직접 비교·레지스터 배치는 다릅니다. 이는 유효 C 접근·원자성·동시성의 증명이 아닙니다. 07 구현·상태표·객체 귀속은 바꾸지 않았습니다.

## 714. `MoveTheCursor` 원본 귀속 근거 조사 계획 (분석 전)

§709–713 의 단일 함수 컴파일 진단은 원래 객체 소속을 결정하지 못했습니다. 더 강한 근거가 있는지 원본 Mach-O 심볼·debug 기록·직접 호출 후보를 조사합니다. `03_original/m68k/binaries/mach_kernel` 과 inventory 의 SHA 를 보존하고 원본 `__TEXT,__text` 의 파일 범위·가상 범위를 Mach-O 파서 및 inventory 와 대조합니다. 전체 심볼의 STABS 여부와 `_MoveTheCursor`, 앞 `_AllKeysUp`, 뒤 `_process_mouse_event` 의 심볼 형·섹션·주소, 인접 재고 행의 가능한 경계를 기록합니다. 이름 정렬된 심볼 순서를 객체 순서로 해석하지 않습니다.

원본 텍스트를 68040 objdump 로 선형 디스어셈블하여 `0x4069eb8` 에 대한 직접 분기·호출 표기를 검색하고, 각 후보의 원본 바이트·명령 형태·PC 상대 목표를 Python 으로 독립 검산합니다. 진단 범위 밖 타깃은 발견된 직접 명령에 한정합니다. 추가로 원본 초기화된 섹션에서 주소의 big-endian 4 B 패턴을 바이트 단위로 검색하여 각 섹션·파일 오프셋·가상 주소와 주변 바이트를 기록하되, 임의 일치·데이터·명령 중간 값일 수 있으므로 참조 또는 호출로 자동 분류하지 않습니다. 실행 중 간접 호출, 미분석 명령 경계·데이터 혼재, 다른 표현의 포인터, 링커의 relocation 제거와 debug 제거로 인해 부재나 완전한 호출 그래프를 주장하지 않습니다. 12_archive 는 원본 증거로 쓰지 않습니다.

코딩 전 Codex `gpt-6.1-terra` 에 계획을 교차검토시키고 원본 파서·도구 출력과 대조합니다. Python 으로만 주소·크기·개수·차이를 계산하며 입력 SHA·도구 식별·원시 출력 SHA·검색 범위·검증 결과를 `09_validation/reconstruction/` 에 기록합니다. 증거가 결정적이지 않으면 `m68k-216` 은 미배정으로 두고 07·상태표를 변경하지 않습니다. 호출 관계만으로 원래 파일 귀속을 확정하지 않습니다.

### 714.1 교차검토와 독립 판정

Codex 서브 에이전트 `gpt-6.1-terra` 의 지적을 원본 inventory·Mach-O 파서·기존 함수 표와 대조했습니다. 선형 디스어셈블은 텍스트 내 자료나 잘못된 명령 정렬로 뒤의 실제 명령을 놓칠 수 있습니다. 발견한 각 직접 호출은 원본 바이트·분기 변위 계산과 기존 IDA 기반 기록 또는 함수 시작을 기준으로 한 별도 objdump 로 대조합니다. big-endian 주소 바이트 검색은 개별 파일 저장 섹션 안에서만 수행하며 절 경계에 걸친 값·zerofill·상대 주소·다른 인코딩은 포괄하지 않습니다. `__text` 의 linked-image relocation 수 0 을 원래 입력 객체에 relocation 이 없었다는 주장으로 확대하지 않습니다.

원본 Mach-O 의 raw load command 를 직접 읽어 `LC_SYMTAB` 의 각 nlist 에서 `n_type & 0xe0` 를 독립 집계하고 parser·TSV 와 교차 대조합니다. 원본 근방의 현재 재고는 함수 이름·주소를 제공할 뿐 객체 경계의 증거가 아닙니다. 서브 에이전트의 두 호출 후보는 검색 후 원본 데이터와 기존 독립 관찰을 직접 대조하며 전수 주장에 사용하지 않습니다. `03_original` 의 파일명 검색은 해당 트리에서만 수행하고 보편적인 대체 자료 부재로 확대하지 않습니다.

### 714.2 원본 귀속 근거 조사 결과

원본 Mach-O raw `LC_SYMTAB` 의 nlist 를 독립적으로 읽어 parser·inventory 와 대조한 결과 3,809 항목 중 `n_type & 0xe0` 가 비영인 STABS 는 0 입니다(Python). `_MoveTheCursor` 는 0x4069eb8 의 외부 `__text` 심볼이고 앞 `_AllKeysUp`, 뒤 `_process_mouse_event` 와 인접하지만 심볼과 인접성은 객체 귀속을 결정하지 않습니다. linked 이미지의 단일 `__text` 섹션은 relocation 수 0 이며 원래 객체의 relocation 부재를 뜻하지 않습니다.

원본 `__text` 선형 objdump 에서 목표 0x4069eb8 로 표시된 직접 분기 후보는 0x406883c 와 0x406a378 입니다. 두 명령의 원본 바이트·PC 상대 목표를 Python 으로 검산하고 기존 IDA 기반 명령 경계 기록과 대조했으며 함수 후보 표에서는 각각 `_evioctl`, `_mouse_motion` 에 속합니다. 이 호출 관계는 기능 연관성을 뒷받침할 뿐 `MoveTheCursor` 의 원래 파일을 지정하지 않습니다. 선형 디스어셈블은 텍스트 내부 데이터·잘못된 정렬 및 간접 호출 등을 완전히 다루지 못하므로 전체 호출의 완전성은 미확인입니다.

파일에 저장된 개별 섹션 내부에서 원본 주소의 big-endian 4 B 연속 패턴은 발견하지 못했습니다. 이 결과는 경계 간·zerofill·상대 주소·다른 인코딩을 배제한 검색에 한정되며 간접 참조 부재를 증명하지 않습니다. `03_original` 파일명 검색에서는 현 m68k 이미지 외 여러 아키텍처 이미지와 universal 이미지가 보였지만, 파일명만으로 동일 배포의 debug 자료 부재를 단정하지 않습니다.

전체 검색의 입력·도구·범위 및 결과는 `09_validation/reconstruction/m4-m68k-p714-survey-20261102.json` (SHA-256 `41676e4b6a3584654d62b843274e612715ac9df19dc1fbbc77d85baee6923d3d`), 두 후보의 바이트·변위·IDA 기록 대조는 `09_validation/reconstruction/m4-m68k-p714-checks-20261102.json` (SHA-256 `b19e8895e2d7870588ea8400a55050956050c605e1aa34081b018256c5873c60`) 에 보존했습니다. 근거는 귀속을 결정하기에 부족하므로 `m68k-216` 을 미배정으로 유지하고 07·상태표는 바꾸지 않았습니다.

## 715. `m68k-217` 단위 통합 준비 감사 계획 (코딩 전)

§690–708 은 `m68k-217` 의 함수를 나눠 진단했지만 각 결과가 같은 번역 단위에서 함께 성립하거나 자료 소유가 정해졌음을 증명하지 않습니다. 다음 구현 단계 전에 함수 표의 정확한 범위와 각 단독 기록의 관계를 기계적으로 대조해, 실제 원본 일치 범위·미통과 함수·임시 앵커 및 남은 통합 관문을 명시합니다.

Python 으로 inventory 행·함수 표에서 `m68k-217` 의 함수와 구간을 읽고 정렬·연속성·행 경계·중복을 검사합니다. §696 A, §698 A, §699 A, §701 A, §702 A, §703 A, §705 B, §706 A, §708 B 의 함수별 바이트 기록 및 독립 검증 기록을 원본 SHA·함수 이름·시작/끝·object-only·기록별 성공 관문과 연결합니다. §701 은 공통 관문 및 A 관문을 별도 읽고 B 의 실패와 구별합니다. §695 E/F 와 §694 D 는 길이 불일치 및 relocation 미비교를 확인해 `_evsetup_screens` 를 미통과로 남깁니다. 임시 앵커를 각 함수 기록에서 직접 추출해 기록하며 이미 성공한 단독 결과를 객체 전체 일치로 환산하지 않습니다.

문서 §689–708 및 관련 기록에서 초기 데이터·BSS·익명 보조 함수·헤더 COMMON·공유 파일 변경 회귀·전체 링크와 원본 함수 경계의 가정을 별도 미결로 정리합니다. `MoveTheCursor` 는 인접한 미배정 `m68k-216` 이므로 217 에 합치지 않습니다. 작업 전 Codex `gpt-6.1-terra` 교차검토 후 주장과 파일 구조를 직접 확인합니다. 모든 주소·크기·개수 계산은 Python 으로 하고 입력·기록 SHA 와 결과를 `09_validation/reconstruction/` 에 보존합니다. 단독 진단의 부분적 일치는 07 구현 승인·자료 소유·전 객체 수락이나 GCC 전체 호환성의 증거가 아닙니다.

### 715.1 교차검토와 독립 판정

Codex 서브 에이전트 `gpt-6.1-terra` 의 검토를 해당 JSON 구조와 원본 함수 표로 직접 대조했습니다. §701 의 공통 관문과 A 관문·`A_ok` 를 함께 검사하고 B 의 실패를 분리합니다. 함수별 JSON 의 `plan` 은 비교 도구 계획 521 이므로 실기 변형을 식별하는 데 쓰지 않고 파일명·오브젝트 SHA·독립 검사 SHA 를 연결합니다. 다중 함수 기록도 각 이름·원본 시작·크기·계산한 끝·바이트 및 참조 차이 여부를 검사합니다.

매핑은 각 함수 기록의 임시 앵커로 남기며 `+2` 등 세부 참조는 독립 raw relocation 관문을 통해 확인합니다. 길이 불일치 후보의 빈 relocation 결과를 성공으로 읽지 않습니다. §707 A 는 COMMON 여섯으로 실패이고 §708 B 만 성공 후보입니다. §697·700 은 이 행 밖 보조 함수로 별도이며 SDK ABI 진단은 원본 C 형이나 객체 소유를 확정하지 않습니다.

### 715.2 통합 준비 감사 결과

원본 함수 표와 재고의 `m68k-217` 구간은 13 함수가 빈틈없이 연결됩니다(Python). 각 함수 기록의 원본 범위, 실제 수집 오브젝트 SHA, 독립 검증 기록 및 임시 매핑을 대조한 결과 12 함수는 각각 지정된 단독 진단의 바이트·참조 관문을 통과했습니다. 나머지 `_evsetup_screens` 는 §694 D·§695 E/F 모두 원본 148 B 대 후보 146 B 이므로 실패이며 그 비교에서 relocation 은 미검사입니다. 감사의 계산과 입력 SHA 는 `09_validation/reconstruction/m4-m68k-p715-audit-20261102.json` (SHA-256 `31d779142dc31f9fa2af665ed34d711634efd9a1debe9307405894f2e8a6a5b7`) 에 보존했습니다.

원본 0x406a478 은 요소 주소 계산에 indexed `lea`, D 는 해당 위치에 `addal` 을 사용하며 D·E·F 의 코드가 동일하다는 기존 결과를 원본 및 후보 objdump 와 다시 확인했습니다. 다음 함수 진단에서는 이 지점의 레지스터 수명과 volatile 접근 순서에 영향을 주는 구분 가능한 표현을 먼저 계획·교차검토해야 합니다.

12 개는 **서로 분리해 컴파일한 함수의 조건부 진단 결과**이며 전체 번역 단위에서 동일 코드가 나오는지는 미확인입니다. 익명 주소·보조 함수의 이름과 소유, 초기 자료·BSS, 머리 포함에 따른 COMMON, 공유 머리 변경의 회귀 및 전체 링크는 계속 미결입니다. 인접 `m68k-216` 의 `MoveTheCursor` 를 이 단위에 합치지 않았고 07 구현·상태표는 변경하지 않았습니다.

## 716. `evsetup_screens` 주소 산술·레지스터 수명 진단 계획 (코딩 전)

§715 감사에서 행 `m68k-217` 의 유일한 미통과 함수는 `evsetup_screens` 입니다. §695 D/E/F 는 bounds 저장 뒤 원본의 indexed `lea` 대신 `addal` 을 내고 원본보다 2 B 짧았습니다. 원본과 D 의 명령 및 마스킹 비교는 해당 명령 이외의 비재배치 바이트가 같다는 관찰이나 길이 차이로 원본과 relocation 이 같다는 증거는 아닙니다.

두 실기 후보를 §694 D 에서 각각 독립 생성합니다. G 는 C89 선언부에 `register int offset;` 를 두고 bounds 대입 다음 `offset = screenIndex * (int)sizeof(EvScreen); screen = (EvScreen *)((volatile char *)evScreen + offset);` 로 포인터를 계산합니다. H 는 선언부에 `register volatile char *base; register int offset;` 를 두고 초기화 if 뒤 `base = (volatile char *)evScreen; offset = screenIndex * (int)sizeof(EvScreen);`, bounds 저장을 `((EvScreen *)(base + offset))->bounds = arg->screenBounds;`, 그 뒤 `screen = (EvScreen *)(base + offset);` 로 둡니다. 나머지 실행 순서와 머리는 D 와 같습니다. G 는 offset 수명과 signed 곱을, H 는 추가로 포인터를 포착하는 시점을 바꾸는 가설입니다. H 의 비volatile 전역 포인터 포착은 별칭·호출·동시성에 따라 D 와 다를 수 있고, 두 후보의 signed overflow·유효 객체 범위·정렬·캐스트도 별도 전제입니다. `EvScreen` 대상의 volatile 은 보존하며 컴파일 결과가 `lea` 를 선택할지 예단하지 않습니다.

plan 716, §695 의 base·M5 컴파일 줄·단일 함수 범위와 10 원본 참조, stage `08_build/runs/tools/m4p716p1-stage`, run `m4p716-p1`, 후보 G·H 를 사용합니다. 코드 작성 전 Codex `gpt-6.1-terra` 교차검토 및 직접 검증, REGISTRY·경로 부재, 실기 백엔드 전후 SHA, 각 compile·`-M` rc·stderr, SDK 포함 의존 manifest SHA·i386 경로 0, `diag_gate` 및 collect 를 확인합니다. 각 후보별 외부 정의·COMMON·UNDF 집합을 고정하고 함수 bytes `same=1`, `total=1`, `object_only=[]` 및 raw relocation 위치·폭·type·pcrel·extern·기호·addend 와 원본 링크 목표의 양방향 대조가 모두 통과해야 단일 함수 진단 일치입니다. 길이가 다르면 함수 relocation 은 미비교입니다. 동일 바이트를 내는 후보가 있어도 의미 동등성이나 원래 소스를 단정하지 않고 구현 선택 전에 기존 §693 사용자 확인 조건을 지킵니다. 07·상태표는 바꾸지 않습니다.

### 716.1 교차검토와 독립 판정

Codex 서브 에이전트 `gpt-6.1-terra` 의 주장을 원본·D objdump, SDK typedef 및 기존 후보 소스에 직접 대조했습니다. G/H 는 기존 B–F 와 구별되나 H 가 이전 C 와 같은 기계어를 낼 가능성은 실측 전 미정입니다. `register volatile char *base` 는 가리키는 대상의 volatile 을 뜻하고 포인터 산술 자체는 volatile 접근이 아닙니다. H 의 전역 포인터 포착 시점, G/H 의 signed 곱·포인터 유효성·정렬 제한을 유지합니다.

사전 기호 관문은 각 후보 raw 비 STABS 외부 정의 `_evsetup_screens` 하나, COMMON 0, UNDF `_bzero`, `_evScreen`, `_evScreenSize`, `_kalloc`, `_totalShmemSize` 정확히, 원본에 없는 UNDF 0 입니다. Python 으로 원본 명령 경계와 목표를 재검산한 4 B·type 0·extern 참조: 절대 `0x12:_evScreen`, `0x26:_evScreenSize`, `0x34:_evScreen`, `0x3a:_evScreenSize`, `0x4c:_totalShmemSize`, `0x52:_evScreen`, `0x7e:_totalShmemSize`, `0x84:_totalShmemSize`; PC 상대 `0x2e:_kalloc`, `0x42:_bzero` 입니다. 각각 addend 0 이며 링크 목표는 순서대로 `0x40c3630`, `0x40c3634`, `0x404a200`, `0x40c3630`, `0x40c3634`, `0x4092e12`, `0x40c36e4`, `0x40c3630`, `0x40c36e4`, `0x40c36e4` 입니다. 후보 생성 명령의 volatile 접근 순서도 직접 확인합니다.

### 716.2 진단 G·H 결과

실기 `m4p716-p1` 의 네 compile·`-M` 명령 rc 0·stderr 0 B, `diag_gate`, 각 SDK 포함 의존 manifest SHA·i386 경로 0, collect 및 m68k 백엔드 전후 해시가 통과했습니다. 두 후보 모두 사전 외부 정의·COMMON·UNDF 집합에 부합합니다. 기록 `09_validation/reconstruction/m4-m68k-p716-checks-20261102.json` 의 SHA-256 은 `1e331433425241fd0589134e9f746deeeb8598acca22ecc4289437a104e3c813` 입니다.

G·H 의 `__text` 는 각각 146 B 로 원본 148 B 와 달라 함수 비교는 0/1, relocation 대상은 미비교입니다. 두 후보의 `__text` 바이트는 D 와 같고 SHA-256 은 `9b15780091cae71fcf0d66f5cdbc184b2e7b6eea1d604914e7e35b10e0d016e7` 입니다. `scratch/p690/evsetup-p716-{G,H}.objdump.txt` 에서 모두 bounds 저장 뒤 `addal` 과 그 후의 shmem 저장·읽기를 확인했습니다. 동일 text 바이트가 완전한 객체·relocation·의미의 동등성을 뜻하지 않으며 probe 는 G/H 의 객체 signature 가 다르다고 보고했습니다.

사전 바이트 및 raw relocation 관문은 통과하지 못했습니다. 동일 바이트를 내는 표현이 늘었을 뿐 원본 소스나 함수 구현 선택은 미정이고, §693 의 사용자 확인 조건을 적용할 구현 선택 단계에도 이르지 않았습니다. 07·상태표는 변경하지 않았습니다.

## 717. 이벤트 익명 자료의 원본 바이트·참조 범위 감사 (분석 전)

§702–706 의 임시 앵커 `0x40b1260`, `0x40b1264`, `0x40b126e`, `0x40b1278`, `0x40b4fb6` 은 단일 함수 비교를 위한 이름이지 원본 변수의 실제 이름·경계·소속이 아닙니다. 전체 단위 통합에 앞서 원본 Mach-O 에서 앵커가 들어가는 절의 종류·파일 범위·인접 기호 및 실제 파일 바이트를 독립 대조하고 관련 참조 후보를 가능한 범위에서 조사합니다.

Python 으로 Mach-O parser 와 `macho.json` 을 대조해 각 앵커의 절·가상/파일 위치를 확인합니다. 파일 저장 절에서 `0x40b1260` 부터 `0x40b127c` 전까지 원본 바이트와 big-endian long/short 진단 해석을 기록하되 형·배열 크기는 확정하지 않습니다. zerofill 절인 경우 파일 바이트를 읽거나 디스크의 우연한 내용을 초기값으로 취급하지 않습니다. 인접 named 심볼 및 §714 의 raw nlist debug 판정을 기호표에 대조합니다.

§714 에 보존한 원본 전체 `__text` 68040 선형 objdump 를 범위 제한 없이 검색하여 위 앵커 각각 및 0x40b1262 같은 부분 주소를 표기한 명령 후보를 수집하고 원본 바이트를 독립 확인합니다. 별도로 파일에 저장된 각 섹션 내부에서 0x40b1260–0x40b127b 와 0x40b4fb6 의 big-endian 4 B 주소 패턴을 바이트 단위로 찾아 섹션·위치·주변 원본 바이트를 기록합니다. 텍스트 주소 패턴은 디스어셈블 명령·함수 표와 대조하되 인라인 데이터나 명령 중간의 우연한 일치일 수 있어 자동으로 모든 항목을 참조로 인정하지 않습니다. indexed 접근의 base 와 실제 런타임 인덱스 범위를 구분하고 동적 접근 범위를 추정하지 않습니다. 선형 디스어셈블 정렬 실패·섹션 경계·zerofill·다른 주소 인코딩·간접 참조 및 런타임 수정은 검색 밖이므로 부재와 완전성을 주장하지 않습니다. linked 이미지의 결과는 원래 객체의 경계·소유를 결정하지 못합니다.

코딩 전 Codex `gpt-6.1-terra` 교차검토와 각 주장별 원본 검증을 수행하고 Python 으로만 주소·길이·개수를 산출합니다. 원본 및 도구·재고 SHA, 원시 바이트·검색 범위·후보·한계를 `09_validation/reconstruction/` 에 남깁니다. 결정적 증거가 없으면 임시 자료·보조 함수 소유는 미결로 유지하며 07 구현·상태표를 변경하지 않습니다.

### 717.1 교차검토와 독립 판정

Codex 서브 에이전트 `gpt-6.1-terra` 의 제안을 원본 Mach-O 절 목록·명령 및 parser 와 직접 대조했습니다. 원본 `LC_SEGMENT` 와 section 을 raw 로 다시 읽어 section type (`flags & 0xff`), vmaddr/vmsize, fileoff/filesize, 파일 길이 및 해당 절의 범위를 검사하고 inventory·parser 와 대조합니다. 0x40b1260–0x40b127b 전체가 파일 저장 `__data` 에, 0x40b4fb6 이 zerofill `__bss` 에 들어가는지 확인하며 BSS 는 파일 오프셋을 산출하지 않습니다.

검색 대상을 첫 범위의 모든 수치 주소와 BSS long 접근이 관찰된 `0x40b4fb6`–`0x40b4fb9` 로 고정합니다. 개별 절의 마지막 가능한 4 B 시작점까지 겹친 hit 를 허용합니다. 4 B 절대 패턴 및 objdump 의 16 진수 숫자 표기만을 조사하며 심볼+addend·다른 크기·PC 상대·계산된 base+offset 및 간접 접근은 누락될 수 있습니다. hit 의 파일 위치·주소·문맥을 보존하고, 직접 명령으로 분류할 때 원본 bytes 와 독립 함수 경계·기존 진단 명령을 확인하며 접근 폭·읽기/쓰기 또는 미상을 별도 기록합니다. 대상 구간과 초기 값의 해석은 선언 경계를 증명하지 않으며 BSS 는 실행 중 달라질 수 있습니다.

### 717.2 원본 자료·참조 감사 결과

raw Mach-O segment·section 과 parser·inventory 를 대조한 결과 `0x40b1260`–`0x40b127b` 는 파일 저장 `__DATA,__data` 안에 있고 28 B 원본은 `00000005000200030004000500060002000400060008000a00000000` 입니다(Python). 마지막 4 B 는 0 이지만 이 구간을 하나의 원래 변수나 배열이라고 단정하지 않습니다. `0x40b4fb6`–`0x40b4fb9` 는 zerofill `__DATA,__bss` 에 있고 파일 오프셋이나 파일에 저장된 초기 바이트가 없습니다. 실행 중 값은 달라질 수 있습니다.

지정한 수치 주소의 4 B big-endian 패턴은 파일 저장 절 전체에서 아홉 후보가 나왔고 모두 `__text` 안입니다. §714 전체 선형 objdump 와 기존 함수 범위 기반 objdump, 원본 opcode·주소 필드를 대조해 아홉을 확인했습니다. `0x40b1278` 은 long 저장·읽기·read-modify-write, `0x40b1260` 은 long 읽기, `0x40b1262` 는 word 읽기, `0x40b1264`·`0x40b126e` 는 주소 계산으로 관찰됩니다. 이어 0x406a642·0x406a648 에서 각각 해당 레지스터 기반 indexed word 읽기가 있으나 가능한 런타임 인덱스 범위나 배열 선언 크기는 증명하지 않습니다. `0x40b4fb6` 은 `_mouse_motion` 에서 long 검사, `_InitMouse` 에서 long 저장으로 관찰됩니다. 표기·선형 디코딩 및 간접 접근의 검색 한계는 §717.1 그대로입니다.

원본 바이트·검색 범위·절과 후보 목록은 `09_validation/reconstruction/m4-m68k-p717-survey-20261102.json` (SHA-256 `f570f2d0865d53b551ccc0781c1145f1cf2f2f50e59cd79142a5e6bf71362b27`), 원본 명령과 주소 필드의 독립 대조는 `09_validation/reconstruction/m4-m68k-p717-checks-20261102.json` (SHA-256 `621d8d49bae8f6b0ba731f2b8879dd911f72c14dc5eab4010b49bf2de892554c`) 에 보존했습니다. 관찰된 접근은 원래 이름·정의 객체·정확한 소유를 결정하지 못하므로 임시 앵커를 유지하고 07·상태표는 바꾸지 않았습니다.

## 718. `m68k-217` 번역 단위 통합 진단 계획 (코딩 전)

§715 의 12 함수는 서로 다른 파일에서 컴파일한 조건부 결과이며 §716 `evsetup_screens` 도 일치하지 않습니다. 각 함수가 함께 있을 때 정의·외부 참조와 코드가 어떻게 변하는지 측정합니다. 이는 07 구현을 선택하거나 전체 객체 수락을 주장하기 위한 진단이 아닙니다.

진단 A 는 기존 파일 전문을 원본 함수 순서로 잇습니다: §708 B `process_B.c`, §706 A `motion_A.c`, §696 A `wait_A.c`, 미일치 기준선 §694 D `evsetup_D.c`, §702 A `register_A.c`, §701 A `unreg_A.c`, §703 A `mousevars_A.c`, §705 B `initmouse_B.c`, §698 A `term_A.c`, §699 A `start_A.c`. 각 파일의 머리·선언·함수 본문을 보존하고 변환하지 않으며 Python 생성기가 원본 각 파일 SHA 와 이어 붙인 정확한 바이트를 대조합니다. §708 B 에 들어있는 NeXTMach `ev_mouse.c` 고지와 `kmreg.h` 고지·URL·commit·경로를 함께 보존합니다. 나머지 진단 원본의 기존 출처와 고지도 지우지 않습니다. 기존 익명 자료·함수는 정의하지 않고 임시 외부 이름으로만 남깁니다. 07·공유 머리·상태표는 변경하지 않습니다.

plan 718, §716 base·M5 컴파일 줄, 정확한 재고 행 `m68k-217`, stage `08_build/runs/tools/m4p718p1-stage`, run `m4p718-p1` 입니다. REGISTRY·경로, 실기 백엔드 전후 SHA, compile·`-M` rc·stderr, SDK 포함 모든 의존 manifest SHA·i386 경로 0, `diag_gate`, collect 를 확인합니다. `m68k_funcbytes.py` 에 §715 의 일곱 임시 주소 앵커를 명시하고 13 함수 각각의 이름·원본/후보 길이·바이트 및 참조를 기록합니다. 길이가 다른 함수는 relocation 미비교입니다. `evsetup_screens` 는 이미 실패한 D 를 포함하므로 전체 일치를 기대하거나 수락하지 않습니다. 같은 TU 에서 내부 호출이 relocation 없이 직접 인코딩될 수 있으므로 각 원본·후보의 해당 호출과 raw relocation 을 별도 해석하며, 미검사 참조를 성공으로 세지 않습니다.

각 단독 객체의 raw 외부 정의·UNDF 를 Python 으로 합산한 사전 예상은 외부 정의 13 함수, COMMON 0, 순수 UNDF 49 이름이며 `_InitMouseVars` 는 내부 정의로 전환됩니다. 정확한 집합은 교차검토 후 명시합니다. 임시 앵커의 실제 이름·자료 경계·소속, 전체 TU 의 data/BSS, 전 객체 raw relocation 양방향 검증, 링크, 원본 소스 및 의미 동등성은 미결입니다. 코딩 전 Codex `gpt-6.1-terra` 교차검토와 주장별 독립 검증을 수행합니다.

### 718.1 교차검토와 독립 판정

Codex 서브 에이전트 `gpt-6.1-terra` 의 주장을 진단 파일·각 raw 객체·원본 함수 표와 대조했습니다. 함수 순서는 원본 재고 순서이며 전문 연결로 NeXTMach 두 고지·출처를 유지합니다. 앞 절의 고지를 지운다는 표현은 오기여서 지우지 않는다고 수정했습니다. 각 입력은 끝 newline 을 확인하고 구분자 없이 바이트 그대로 결합합니다. 여러 번 포함한 SDK 헤더와 extern 선언의 충돌 및 COMMON 발생은 실기 컴파일·raw 기호에서 판정합니다. 각 함수의 원래 단독 결과가 통합에서도 유지된다고 가정하지 않습니다.

사전 raw 비 STABS 외부 정의는 `_AnimateWaitCursor`, `_HideWaitCursor`, `_InitMouse`, `_InitMouseVars`, `_ResetMouse`, `_ShowWaitCursor`, `_StartCursor`, `_TermMouse`, `_ev_register_screen`, `_ev_unregister_screen`, `_evsetup_screens`, `_mouse_motion`, `_process_mouse_event` 정확히, COMMON 0, 순수 UNDF 는 `_LLEventPost`, `_MoveTheCursor`, `_SetCurBrightness`, `_UndoAutoDim`, `_adb_mouse_present`, `_autoDimPeriod`, `_autoDimTime`, `_autoDimmed`, `_buttonsTied`, `_bzero`, `_clickLoc`, `_clickSpaceThresh`, `_clickState`, `_clickTime`, `_clickTimeThresh`, `_curBright`, `_currentScreen`, `_cursorPin`, `_dimmedBrightness`, `_evScreen`, `_evScreenSize`, `_ev_adb_mouse`, `_ev_init_factors`, `_ev_init_num`, `_ev_init_thresholds`, `_ev_point_to_screen`, `_ev_shmem_cursor`, `_ev_wait_frame`, `_evdispatch`, `_evg`, `_evs`, `_kalloc`, `_lastPressure`, `_leftENum`, `_mouseDelX`, `_mouseDelY`, `_mouseHandedness`, `_mouseScaleFactors`, `_mouseScaleThresholds`, `_numMouseScales`, `_rightENum`, `_screens`, `_sessionPrecision`, `_sessionPressure`, `_totalShmemSize`, `_waitFrameRate`, `_waitFrameTime`, `_waitSusTime`, `_waitSustain` 정확히입니다. 이는 기존 단독 객체들의 합집합에서 내부 정의를 뺀 예상이며 실제 TU 결과가 다르면 관문 실패로 기록합니다. 원본 `_InitMouseVars` 직접 호출은 `_InitMouse` +0x130, `_ResetMouse` +0x12 에 있습니다(Python). 통합 결과에서 함수 길이가 유지되면 두 지점의 opcode 와 PC 상대 목표를 원본과 별도 검산하고, relocation 이 있으면 raw 형식과 목표를, 없으면 인코딩된 상대 변위를 확인합니다. 길이나 호출 형태가 달라 정렬할 수 없으면 미검증으로 기록합니다. 일반 funcbytes 가 relocation 없는 필드를 참조로 해석하지 않는다는 점을 직접 확인했습니다.

### 718.2 통합 진단 결과

실기 `m4p718-p1` 의 compile·`-M` rc 0·stderr 0 B, `diag_gate`, SDK 포함 의존 manifest SHA·i386 경로 0, collect 및 실기 백엔드 전후 해시가 통과했습니다. 지정한 기존 진단 열 파일이 변경 없이 순서대로 결합됐고 두 NeXT 고지를 보존함을 확인했습니다. raw 비 STABS 외부 정의 13, COMMON 0, 순수 UNDF 49 는 사전 집합과 정확히 같습니다(Python). 일곱 임시 이름은 실제 원본 이름으로 확정된 것이 아닙니다.

함수별 `09_validation/reconstruction/m4-m68k-funcbytes-p718-A-20261102.json` 은 임시 앵커 조건에서 12/13, object-only 없음입니다. `_evsetup_screens` 는 원본 148 B 대 후보 146 B 로 남아 그 함수의 relocation 비교는 미수행이며, 전체 진단 일치 및 객체 수락은 실패입니다. 나머지 12 함수의 원본 필드와 후보 raw relocation 125 곳은 이전 독립 진단의 위치·폭·type·pcrel·기호·addend 및 원본 목표를 통합 객체에서 양방향 대조해 통과했습니다(Python). `_InitMouse` 와 `_ResetMouse` 의 `_InitMouseVars` 호출 둘은 각각 opcode `61ff`, `__text` 에 대한 로컬 PC 상대 relocation 으로 바뀌며 후보 대상과 원본 대상이 각자의 함수 시작을 가리킴을 별도 검산했습니다.

독립 검사 `09_validation/reconstruction/m4-m68k-p718-checks-20261102.json` 의 SHA-256 은 `8cf9005779bdf9721578a3a26439cb20847312965855fb52518e61dacec0b72e` 입니다. 함수 결합이 조건부 진단 결과에 미치는 영향을 확인한 것이며 실제 원본 객체 귀속·임시 자료 정의·BSS 소유·전 객체 relocation·전체 링크·의미 동등성은 미결입니다. 07·상태표는 바꾸지 않았습니다.

## 719. 길이가 다른 `evsetup_screens` 후보의 참조 대조 계획 (분석 전)

§694 D 와 §718 통합 A 의 `evsetup_screens` 는 원본보다 2 B 짧아서 일반 함수 비교의 relocation 검사가 생략됐습니다. §695 의 relocation 마스킹 비교만으로는 각 후보 참조가 원본 목표를 가리키는지 알 수 없습니다. 원본과 두 후보의 알려진 명령 경계에 따라 별도 매핑을 고정해 각 참조를 검증합니다. 이 조사는 크기가 다른 함수를 원본 일치로 수락하지 않습니다.

원본 함수 시작 기준 `0x6e` 의 4 B `41f00800` 과 후보의 2 B `d1c0` 을 각각 별도 명령으로 기록하고, 그 전 필드는 같은 오프셋, 원본 명령 이후 필드는 후보 오프셋이 2 작은 대응으로 고정합니다. §716.1 의 원본 10 참조를 각각 후보 raw relocation 의 위치·4 B 폭·type 0·extern·PC 상대 여부·기호·addend 및 원본 링크 목표와 대조하고 양방향으로 추가·누락을 확인합니다. §718 에서는 정확한 `_evsetup_screens` 후보 심볼의 시작을 기준으로 합니다. 원본과 후보의 relocation 필드 및 서로 다른 명령 영역을 제외한 나머지 바이트를 이 명령 경계 매핑으로 비교하고 비교되지 않은 영역을 별도로 명시합니다. 명령 opcode 와 직전·직후 경계는 원본과 각 후보 objdump 및 bytes 로 직접 확인합니다.

조사 전 Codex `gpt-6.1-terra` 교차검토 및 주장별 독립 검증을 수행합니다. Python 으로만 주소·길이·오프셋·개수를 계산하고 원본·후보 객체·도구·증거 SHA, 개별 원본 목표와 raw relocation, 비재배치 비교 범위 및 실패 결과를 `09_validation/reconstruction/` 에 기록합니다. 이 제한된 참조·바이트 관문이 통과해도 원본 전체 바이트 일치, 두 명령의 모든 상황에서의 의미 동등성, 원래 소스·객체 귀속 및 수락을 뜻하지 않습니다. 07·상태표는 바꾸지 않습니다.

### 719.1 교차검토와 독립 판정

Codex 서브 에이전트 `gpt-6.1-terra` 의 대응표를 §716.1, 원본·D objdump 와 parser 에 직접 대조했습니다. 원본 필드 `0x12,0x26,0x2e,0x34,0x3a,0x42,0x4c,0x52` 는 후보의 같은 위치이며 원본 `0x7e,0x84` 는 각각 후보 `0x7c,0x82` 입니다. PC 상대 둘은 `_kalloc`, `_bzero` 입니다. 원본 0x6e–0x71 과 후보 0x6e–0x6f 의 서로 다른 명령을 뺀 앞뒤 범위가 각각 대응합니다.

각 후보의 함수 심볼과 `__text` 범위에서 모든 relocation 의 **전체 필드 구간**을 확인하고 함수 경계 교차·중복·겹침·섹션 밖 항목을 실패로 처리합니다. 원본·각 후보 opcode 와 인접 명령을 확인한 뒤 대상 필드와 서로 다른 명령만 가리고 나머지 각 바이트를 정확히 한 번 비교합니다. 기존 도구에서 PC 상대 원본 목표는 원본 필드 주소 + signed 필드값, 후보 외부 PC relocation 의 addend 는 signed 저장값 + 후보의 **섹션 내 필드 주소**임을 확인했습니다. 통합 객체에서는 함수 상대 위치를 쓰면 안 됩니다. 심볼 테이블 인덱스는 각 후보에서 해석합니다. 10 필드의 위치·형식·기호·addend·목표 또는 양방향 집합, 분기 목표, 바이트와 경계 중 하나라도 다르거나 확인할 수 없으면 해당 관문 실패 또는 미검증으로 기록합니다. 원본 링크 이미지에 원래 객체 relocation 이 보존됐다는 뜻은 아닙니다.

### 719.2 제한된 참조·바이트 대조 결과

단독 D 와 §718 통합 A 각각에서 `evsetup_screens` 함수 경계 및 raw relocation 필드의 전체 범위·겹침을 확인했습니다. 사전 지정한 원본 참조 10 곳은 두 후보에서 모두 정확한 대응 위치, 4 B·type 0·extern·PC 상대 여부, 기호·addend 와 원본 링크 목표로 검증됐고 추가·누락은 없습니다. 통합 객체의 PC 상대 addend 는 섹션 기준 필드 위치로 계산했습니다(Python). 원본 조건 분기의 목표도 후보와 같은 함수 상대 위치로 확인했습니다.

각 후보에서 원본의 indexed `lea` 4 B 와 후보 `addal` 2 B, 각 relocation 필드를 제외하고 나머지 대응 바이트 104 B 를 빠짐없이 비교한 결과 차이가 없었습니다. 이 비교에서 제외한 서로 다른 명령은 그대로 남아 있고 전체 함수 바이트는 일치하지 않습니다. 두 명령의 모든 입력에 대한 의미 동등성, 원본 소스·객체 귀속 및 최종 수락은 검증하지 않았습니다.

원본·오브젝트·검사기 SHA, 범위와 10 개별 참조는 `09_validation/reconstruction/m4-m68k-p719-checks-20261102.json` (SHA-256 `0b9123d5c776324cdbb7c5ff8e9ccb998b27e06d8f6c9fd52aa16d79c9a17950`) 에 남겼습니다. 앞 절들의 일반 funcbytes 결과가 relocation 을 미비교로 보고한 사실은 바꾸지 않으며, 이번에 별도 정렬 검사를 수행한 것임을 구분합니다. 07·상태표는 변경하지 않았습니다.

## 720. 이벤트 익명 자료의 TU-local 배치 가설 진단 (코딩 전)

§717 원본 초기 바이트와 long/word 참조는 익명 자료의 소유·선언을 결정하지 못합니다. §718 통합 소스의 임시 외부 자료를 한 진단 번역 단위 안에 정의했을 때 실제 NeXT m68k 컴파일러가 자료·BSS·코드 참조를 어떻게 생성하는지 시험합니다. 이는 원본이 같은 구조체·정적 변수 또는 같은 객체 소유였다는 가설을 입증하지 않습니다.

진단 B 는 §718 A 에 저작권·출처 고지와 함수 순서를 유지하고, 다섯 임시 외부 자료 선언 `ev_init_num`, `ev_init_thresholds`, `ev_init_factors`, `ev_shmem_cursor`, `ev_adb_mouse` 를 제거한 후 다음 C89 진단 정의를 첫 함수 전에 둡니다: `static struct { int n; short threshold[5]; short factor[5]; char *cursor; } trial = { 5, {2,3,4,5,6}, {2,4,6,8,10}, 0 }; static int trial_adb;`. 함수의 기존 다섯 이름을 각각 `trial.n`, `trial.threshold`, `trial.factor`, `trial.cursor`, `trial_adb` 로 일관되게 치환하고 나머지는 바꾸지 않습니다. 이름과 하나의 구조체 결합은 진단 표현만을 뜻합니다. 기존 `evsetup_screens` 기준선은 여전히 실패입니다.

§717 의 28 B 범위에서 목표 상대 위치는 n `0`, n 하위 word `2`, threshold `4`, factor `14`, cursor `24` 이며 Python 으로 계산합니다. 이 구조의 target `sizeof`·멤버 offset·int/short/pointer 크기와 정렬은 실제 오브젝트 및 필요한 대상 ABI 측정으로 확인하며 사전에 원본 형으로 취급하지 않습니다. `trial_adb` 의 원본 임시 앵커 `0x40b4fb6` 은 Python 계산상 4 B 정렬이 아니고 2 B 정렬입니다. 후보 zerofill 크기·정렬과 이 주소의 양립성을 검사하되 가정에 맞게 packed 속성·강제 배치·패딩을 추가하지 않습니다. `static` 이 코드 최적화·접근 폭·심볼 제거를 바꿀 수 있으므로 예측하지 않고 관찰합니다.

plan 720, §718 과 같은 base·M5 줄·`m68k-217` 범위, stage `08_build/runs/tools/m4p720p1-stage`, run `m4p720-p1` 입니다. 작성 전 Codex `gpt-6.1-terra` 교차검토와 직접 검증을 수행합니다. 경로·REGISTRY, 실기 백엔드 전후 SHA, compile·`-M` rc·stderr, SDK 포함 의존 manifest SHA·i386 경로 0, `diag_gate`, collect, 소스 변경 범위 및 고지를 확인합니다. raw Mach-O 의 모든 data/BSS 절·정렬·크기·bytes·relocation·비 STABS 심볼을 읽어 목표 바이트와 별도 대조하고 임시 정의로 사라지는 UNDF 와 새 로컬 기호를 기록합니다. 지역 relocation 은 extern 비트·섹션 번호·원시 값·목표를 실제 형식으로 해석하며 extern relocation 이라고 가정하지 않습니다. 13 함수 각각의 크기·바이트·참조, §718 의 내부 호출 두 곳 및 §719 의 길이 다른 함수 참조는 별도 비교합니다. 구조나 앵커가 다르면 억지로 매핑하지 않고 미검증으로 기록합니다.

전체 TU 의 진단 결과가 달라도 소유나 전체 수락을 확정하지 않습니다. 원본 데이터 배치, 대상 ABI·C 별칭·정렬·인덱스 유효성, static 최적화·동시성 및 보조 함수 소속을 독립적으로 유지하고 07·공유 머리·상태표를 바꾸지 않습니다.

### 720.1 교차검토와 독립 판정

Codex 서브 에이전트 `gpt-6.1-terra` 의 주장을 §718 소스·기호·§717 원본 자료와 Python 으로 직접 대조했습니다. `ev_adb_mouse` 는 두 extern 에 나오며 하나는 `mouseDelX`, `mouseDelY`, `numMouseScales` 와 공유하므로 해당 이름만 제거합니다. `ev_init_thresholds` 와 `ev_init_factors` 는 같은 선언에 있고 `ev_init_num`, `ev_shmem_cursor` 는 별도입니다. 나머지 선언과 함수 본문의 지정된 치환 외 텍스트는 바꾸지 않습니다.

사전 raw 외부 정의 예상은 §718.1 의 13 함수 정확히, COMMON 0, UNDF 는 §718.1 의 49 이름에서 `_ev_adb_mouse`, `_ev_init_factors`, `_ev_init_num`, `_ev_init_thresholds`, `_ev_shmem_cursor` 를 뺀 44 이름 정확히입니다(Python). 이 예상과 다르면 사실을 기록하며 원본 소유에 대한 반증이나 자동 성공으로 해석하지 않습니다. 로컬 심볼·절·최적화는 실측합니다. §717 원본 자료 상대 위치 및 BSS 주소의 4/2 정렬 나머지 2/0 을 Python 으로 재확인했습니다.

구조체의 내부·말미 padding, 멤버 실제 오프셋, 추가 자료·relocation 과 zerofill 변형을 별도로 검사합니다. BSS 섹션 정렬만이 아니라 후보 변수의 섹션 내 오프셋과 가정한 섹션 시작 위치를 함께 사용하고, 양립해도 원본 링크 배치나 소유의 증거로 확대하지 않습니다. 각 함수는 코드 크기·relocation 형태가 바뀔 수 있어 이전 진단의 12/13 결과를 그대로 이식하지 않습니다. source 생성·검사는 선언과 단어 경계를 고정해 수행합니다.

### 720.2 TU-local 자료 가설 진단 결과

실기 `m4p720-p1` 의 compile·`-M` rc 0·stderr 0 B, `diag_gate`, SDK 포함 의존 manifest SHA·i386 경로 0, collect 및 백엔드 전후 해시가 통과했습니다. 소스가 계획된 선언 제거·다섯 이름 치환·진단 정의 추가만으로 생성됐으며 두 NeXT 고지가 보존됐음을 확인했습니다. raw 외부 정의 13, COMMON 0, UNDF 44 는 사전 예상 집합과 같습니다.

대상 객체의 `__data` 는 28 B, 정렬 지수 1, relocation 0 이며 §717 에서 관찰한 28 B 와 바이트별로 같습니다. local `_trial` 은 이 절 시작에 있고 후보 raw relocation 에서 자료 기준 `+0`, `+4`, `+14`, `+24` 를 관찰했습니다. local `_trial_adb` 는 크기 4 B 의 zerofill `__bss` 시작에 있고 그 절의 정렬 지수는 1 입니다. 이 후보의 변수 오프셋과 2 B 섹션 정렬 가정은 원본 임시 주소 0x40b4fb6 과 양립하지만 원본에 그렇게 배치됐다는 증거는 아닙니다. 후보의 scattered·local relocation 과 실제 대상 위치는 `09_validation/reconstruction/m4-m68k-p720-localrefs-20261102.json` (SHA-256 `753476ee448b23fdb5c708719a5e05010be86e0286c718177562796059171f7a`) 에 남겼습니다.

함수별 `m4-m68k-funcbytes-p720-B-20261102.json` 은 임시 `_trial`·`_trial_adb` 및 두 보조 함수 앵커에서 10/13 입니다. `_evsetup_screens` 는 148/146 B 로 기존 불일치, `_ev_register_screen` 은 132/142 B 로 길이 차이, `_InitMouseVars` 는 206 B 로 같지만 바이트·정렬 위치 기준 참조가 다릅니다. 앞의 길이 다른 함수 둘은 일반 funcbytes 에서 relocation 을 비교하지 않았습니다. 이 결과는 정적 결합 가설이 해당 컴파일 조건에서 코드 생성을 바꿨음을 보이며, 원래 소유에 대한 반증이나 모든 입력의 의미 판정은 아닙니다.

일치한 10 함수의 후보 raw relocation 94 곳은 원본 목표·기호·형식과 양방향으로 별도 대조했고 `_InitMouseVars` 내부 호출도 포함합니다. 길이 다른 `evsetup_screens` 는 §719 와 같은 제한된 정렬 검사에서 참조 10 곳과 나머지 대응 비재배치 104 B 가 일치했으나 서로 다른 명령을 제외했으므로 전체 일치가 아닙니다(`m4-m68k-p720-evsetup-20261102.json`, SHA-256 `8c7fe45b13f7922883ec9b58abf3d2041dc003df7befa3cf8f522a1ff4260eed`). register 및 변경된 InitMouseVars 의 모든 원본 참조 대응은 미검증입니다. 환경·기호·자료와 94 참조 검사 `09_validation/reconstruction/m4-m68k-p720-checks-20261102.json` 의 SHA-256 은 `bd264b0a5774ee167370f33fcf6b313aa384c8dd4775d070a2d21f7105094991` 입니다. 전체 TU 일치·자료 소유·객체 수락은 미결이며 07·상태표는 바꾸지 않았습니다.

## 721. 익명 자료의 개별 TU-local 영향 분리 진단 (코딩 전)

§720 B 와 §718 A 의 함수별 objdump 를 대조하면 `InitMouseVars` 에서 A 는 n 의 long 과 하위 word 를 별도 절대 주소로 읽지만 B 는 구조체 base 를 계산하고 간접 참조합니다. `ev_register_screen` 에서 B 는 cursor 에 대한 주소 계산·간접 읽기와 레지스터 사용·보존이 달라집니다. 이는 대상 컴파일 결과이지 static 자체, alias 분석 또는 구조체 결합 중 어느 하나가 원인이라는 증명은 아닙니다.

§718 A 에서 서로 독립된 두 후보를 만듭니다. C 는 `extern char *ev_shmem_cursor;` 만 제거하고 첫 함수 앞에 `static char *trial_cursor = 0;` 를 두어 함수 내 `ev_shmem_cursor` 만 `trial_cursor` 로 교체합니다. 나머지 네 자료 앵커 선언·참조는 외부로 둡니다. D 는 `extern int ev_init_num;` 과 `extern short ev_init_thresholds[], ev_init_factors[];` 만 제거하고 `static struct { int n; short threshold[5]; short factor[5]; } trial_scale = { 5, {2,3,4,5,6}, {2,4,6,8,10} };` 를 같은 위치에 두어 함수 내 세 이름을 대응 멤버로 교체합니다. cursor 와 BSS 자료는 외부로 둡니다. 그 외 소스·고지·함수 순서 및 §694 D 의 미일치 기준선은 유지합니다. C 는 cursor 의 local 정의, D 는 scale 자료의 local 결합이라는 서로 다른 가설이고 원래 이름·객체 소유·형·경계를 확정하지 않습니다.

plan 721, §718 base·M5 줄·`m68k-217` 범위, stage `08_build/runs/tools/m4p721p1-stage`, run `m4p721-p1` 을 사용합니다. 코딩 전 Codex `gpt-6.1-terra` 교차검토 및 독립 검증; REGISTRY·경로·각 소스 치환 범위·저작권 고지, 실기 m68k 백엔드 전후 SHA, 각 compile·`-M` rc·stderr, SDK 포함 의존 manifest SHA·i386 경로 0, `diag_gate`, collect 를 확인합니다. raw 외부 정의는 §718.1 의 함수 13, COMMON 0, UNDF 는 §718 의 49 에서 C 는 `_ev_shmem_cursor` 하나, D 는 `_ev_init_num`, `_ev_init_thresholds`, `_ev_init_factors` 셋을 제거한 집합을 사전 예상합니다. 다르면 관문 실패로 기록하며 컴파일러의 최적화나 원본 소유에 대한 단정은 하지 않습니다.

각 후보의 자료·BSS 섹션·정렬·bytes·모든 local/scattered relocation 을 측정하고 각 함수 bytes·크기·참조를 비교합니다. C 는 §718 의 `0x40b1278` 앵커만 `_trial_cursor` 로 바꾸고 나머지는 유지합니다. D 는 §718 의 세 scale 앵커 `0x40b1260/0x40b1264/0x40b126e` 를 제거하고 `0x40b1260=_trial_scale` 하나로 대체해 후속 주소를 base+4 및 base+14 로 정규화하며, cursor·BSS·보조 함수 앵커는 유지합니다. 앵커는 진단 편의이지 실제 크기·소유가 아닙니다. §718 의 내부 호출 둘을 포함해 길이가 유지된 함수의 raw relocation 은 개별 원본 목표·type·폭·기호·addend 를 양방향 확인하고 크기가 다른 함수는 미검사로 기록합니다. §719 방식의 `evsetup_screens` 제한된 참조 검사도 별도입니다. 전체 13 함수·원본 객체 일치나 07 채택은 예상하지 않습니다. static 정의의 최적화, 0 초기값의 절, 멤버 padding·정렬·범위, C 접근의 유효성·동시성 및 실제 원본 소유는 실측 또는 미결로 둡니다. 07·상태표를 바꾸지 않습니다.

### 721.1 교차검토와 독립 판정

Codex 서브 에이전트 `gpt-6.1-terra` 의 지적을 §718 소스·SDK·funcbytes 구현으로 직접 확인했습니다. C 에서 cursor 선언 한 곳과 본문 세 곳, D 에서 두 선언 줄과 `InitMouseVars` 본문의 세 이름을 바꿉니다. D 는 세 scale 앵커를 그대로 유지하면 없는 심볼을 가리키므로 위 계획을 base 하나와 `+4/+14` 방식으로 정정했습니다. `EvScreen` 과 `EvGlobals` 는 volatile 대상 typedef 이고 cursor 포인터 객체는 별도 비volatile 이므로 이 진단에서 구조체 전체를 volatile 로 바꾸지 않습니다.

길이가 같아도 명령과 필드 경계가 바뀔 수 있어 위치 기준 비교의 불일치를 그대로 기록하고 raw 대응을 독립적으로 확정할 수 없으면 미검증으로 둡니다. 각 relocation 의 전체 필드 범위·겹침·섹션 경계를 검사하며 내부 PC 상대 항목은 대상 섹션 기준으로 해석합니다. 0 초기화 cursor 의 절과 로컬 심볼은 실제 산출물을 확인하고 원래 객체 소유·동시성 의미를 추론하지 않습니다.

### 721.2 개별 자료 진단 결과

실기 `m4p721-p1` 의 네 compile·`-M` 명령 rc 0·stderr 0 B, `diag_gate`, SDK 포함 의존 manifest SHA·i386 경로 0, collect 및 백엔드 전후 해시가 통과했습니다. 두 소스의 계획된 치환 외 변경이 없고 원래 고지가 보존됨을 재생성 대조로 확인했습니다. 각 raw 외부 정의·COMMON·UNDF 집합도 사전 예상과 같습니다.

C 는 4 B `__data` 에 local `_trial_cursor` 를 0 으로 두었고, 함수별 진단은 12/13 입니다. `ev_register_screen` 을 포함한 12 함수의 raw relocation 125 곳과 내부 호출을 원본 목표와 양방향 대조해 통과했습니다. D 는 24 B `__data` 에 local `_trial_scale` 을 두었고 §717 초기 바이트의 앞 24 B 와 같습니다. 함수별 진단은 11/13 이며 `InitMouseVars` 는 §720 과 같이 크기는 같아도 코드·위치 기준 참조가 달랐습니다. 나머지 11 함수의 raw relocation 103 곳을 양방향 대조해 통과했습니다. 두 후보 모두 `evsetup_screens` 는 원본 148 B 대 146 B 여서 전체 일치가 아닙니다.

두 후보의 `evsetup_screens` 에 §719 와 같은 별도 정렬 검사를 적용하면 각각 참조 10 곳과 나머지 비재배치 104 B 가 맞지만 다른 명령은 제외되므로 함수 전체 일치가 아닙니다(`m4-m68k-p721-evsetup-20261102.json`, SHA-256 `fd2c344d637ef36250a008648adb32da540de66153da7ee3ab3c4eb6e66c15a1`). 두 후보의 local/scattered 참조 각 다섯 곳은 `m4-m68k-p721-localrefs-20261102.json` (SHA-256 `d6d9b8961fb054526cad7405c2300e02aafa996dd4356023c743ef90d6199ad1`), 환경·기호·일치 함수 참조 검사는 `09_validation/reconstruction/m4-m68k-p721-checks-20261102.json` (SHA-256 `209ea4663949b2fe205d68a721890dec6edbfa61f71ecfe4eab2e36fc6f74e89`) 에 보존했습니다.

C 와 D 의 결과는 해당 컴파일 조건에서 cursor 단독 지역화와 scale 결합의 영향이 다르다는 관찰입니다. §720 전체 결합에서 나타난 변화의 유일한 원인을 입증하거나 원본 자료의 이름·소유·동시성 의미를 결정하지 않습니다. 07·상태표는 변경하지 않았습니다.

## 722. 배율 초기 자료 분리 정의 진단 계획 (코딩 전)

§721 C 에서는 cursor 지역화만으로 12 함수의 조건부 진단이 유지됐고 D 의 단일 scale 구조체에서는 `InitMouseVars` 의 주소 계산이 달라졌습니다. 원본에서 관찰한 초기값과 접근을 보존하면서도 자료 정의를 별개 변수로 표현하면 대상 컴파일러가 어떻게 배치·코드 생성하는지 확인합니다. 이는 원본에서 변수가 분리돼 있었다는 근거나 실제 객체 소유를 결정하는 단계가 아닙니다.

서로 독립된 두 후보를 둡니다. E 는 §721 C 를, 대조군 F 는 §718 A 를 각각 기준으로 `extern int ev_init_num;` 과 `extern short ev_init_thresholds[], ev_init_factors[];` 를 제거하고 첫 함수 앞에 C89 `static int trial_num = 5; static short trial_threshold[5] = {2,3,4,5,6}; static short trial_factor[5] = {2,4,6,8,10};` 을 각각 선언·정의합니다. `InitMouseVars` 의 세 외부 이름을 대응 정적 변수로 치환하고 나머지 소스·고지·cursor 의 해당 기준선 표현·BSS extern·함수 순서를 보존합니다. E 의 기존 local cursor 정의는 세 scale 정의 뒤로 두며 F 의 cursor 는 외부로 유지합니다. E 의 비교 앵커는 `0x40b1260=_trial_num`, `0x40b1264=_trial_threshold`, `0x40b126e=_trial_factor`, `0x40b1278=_trial_cursor`, `0x40b4fb6=_ev_adb_mouse`, `0x406a9d4=_ev_wait_frame`, `0x406aa0c=_ev_point_to_screen`; F 는 이 중 cursor 만 `_ev_shmem_cursor` 로 둡니다. 이는 비교용 가설이며 심볼·절 배치가 다르면 무리하게 매핑하지 않고 미검증으로 기록합니다.

plan 722, §721 base·M5 줄·`m68k-217` 범위, stage `08_build/runs/tools/m4p722p1-stage`, run `m4p722-p1` 입니다. 작성 전 Codex `gpt-6.1-terra` 교차검토 및 각 주장 독립 검증; 경로·REGISTRY, 소스 변화·원래 고지, 실기 백엔드 전후 SHA, compile·`-M` rc·stderr, SDK 포함 의존 manifest SHA·i386 경로 0, `diag_gate` 및 collect 를 검사합니다. raw 외부 정의는 §718.1 의 13 함수 정확히, COMMON 0, UNDF 는 §718 의 49 에서 E 는 `_ev_shmem_cursor`, `_ev_init_num`, `_ev_init_thresholds`, `_ev_init_factors` 를 빼고 F 는 마지막 세 개만 뺀 집합을 사전 예상합니다. 사전 예상과 달라지면 사실을 기록하며 완화하지 않습니다.

원본 §717 의 28 B 와 실제 `__data` 전체 bytes·정렬·로컬 심볼별 주소·상대 순서·padding·data relocation 을 대조하며 선언 순서와 실제 배치가 같다고 가정하지 않습니다. zerofill 및 local/scattered relocation 의 섹션·대상도 개별 검증합니다. 각 함수 bytes·길이·임시 앵커 참조, 길이 일치 함수의 전체 raw relocation 과 내부 호출을 원본 목표와 독립 대조합니다. §719 식의 `evsetup_screens` 제한된 대조도 별도입니다. 길이·필드가 다르면 미검증으로 남기며 단일 함수 진단 일치도 원본 자료 정의·소유·C 접근 범위·동시성·전체 객체 수락을 뜻하지 않습니다. 실제 구현 선택 전 §693 사용자 확인 조건을 유지하고 07·상태표는 바꾸지 않습니다.

### 722.1 교차검토와 독립 판정

Codex 서브 에이전트 `gpt-6.1-terra` 의 회신을 §721 C·§718 A 소스 및 사전 기호 집합에 대조했습니다. E 의 cursor 정의는 scale 정의 뒤로 옮기며 F 에서는 cursor 를 외부로 둡니다. 세 파일 범위 초기화는 C89 진단 형태이지만 실제 섹션 순서·멤버 크기·정렬은 대상 객체로만 판정합니다.

F 의 cursor 는 정의하지 않으므로 28 B 전체 데이터 일치를 성공 조건으로 삼지 않고 세 scale 심볼의 실측 범위·바이트와 원본 대응 구간을 비교하며 cursor 4 B 는 별도 미검증으로 표시합니다. E 도 실제 전 절·심볼·padding 을 측정합니다. `trial_num` 하위 word 는 해당 객체의 `+2` 목표로 확인하고, 지역·scattered relocation 의 절·r_value·필드 값·폭·type·PC 상대 및 실제 목표를 검증합니다. 배치가 다를 때 인위적인 padding 또는 강제 정렬로 맞추지 않습니다. 자료·함수의 같은 TU 소속과 원본 선언·별칭·동시성은 계속 미결입니다.
