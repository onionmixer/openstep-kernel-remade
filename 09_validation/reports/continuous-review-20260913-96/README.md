# 96차 — PC emulation 복구 경로와 디컴파일 프레임 누락

## 결과와 증거 수준

95차에서 남겨 둔 PC 계열 literal recovery store 후보 36개를 원본으로 대조했다.
각 store의 arg1 기준 객체, 보호하는 FS 접근, 정상 clear와 복구 fragment 연결을 기록했다.
이 목록의 지역 경로 검토는 진행했지만, 모든 alias writer·PC subsystem·native trap 동작을
완료한 것은 아니다. 원본 전체 분석 목표도 미완료다.

중요한 신규 결과는 `0x1a3160`의 **C export에서 guest frame 초기화 저장이 누락된 점**이다.
원본 ASM의 EIP/CS/EFLAGS/error 저장을 C 출력이 충실히 표현하지 않는다.
또한 원본 자체의 일부 프레임은 CS를 WORD로만 저장하고 더 넓은 범위를 전송한다.
두 문제를 디컴파일 누락과 원본 저장 폭의 문제로 구분했다.

원본 SHA-256: `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`.
Ghidra 스킬의 본문·참조·간접 전이 검토 절차를 기존 export에 적용했다.
원본 재디코드·주소/폭/개수/산식/해시는 Python으로 처리했다. 다른 코드, 01_resources,
07_kernel, live DB 변경, 구현/빌드/커널 실행은 사용하지 않았다.
새 독립 계획 교차검토를 수신하지 않았으며, 이를 통과로 세지 않았다.

자료: [범위](SCOPE.md), [원본 명령·분기·산식 증거](object-lifetime-evidence.json),
[보존 해시](preservation.json), [체크포인트](checkpoint.json),
[남은 분석](OPEN_ITEMS.md), [이전 보고서](../continuous-review-20260913-95/README.md).
프레임 누락 대조 대상: [원본 ASM export](../../../04_ghidra/exports/x86/full-pass5/functions/001a3160.asm),
[변경하지 않은 C export](../../../04_ghidra/exports/x86/full-pass5/functions/001a3160.c).

Python 집계는 일반 본문 19개와 synthetic fragment 40개, 합계 59개 본문의
2,752개 명령/8,840바이트다. 직접 분기 423개, 직접 CALL 39개, 간접 CALL 1개,
핵심 operand 문자열 185개, recovery 계약 36개, fragment exit 그룹 40개를 확인했다.
참조 행 64개, 분기 표 256개 slot, 명시적 stack frame 폭 감사 2개,
입력 184개와 기존 보존 파일 867개를 대조했다.
경고 314개는 C 출력의 경고 **행** 수이며 중복 주소/fragment 맥락을 포함한다.
314개의 독립된 바이너리 결함 또는 누락 함수라는 의미가 아니다.

## 1. thread와 PC 레코드의 +0x74 구분

catch_trap `0x187068`은 `0x187080`에서 전역 `0x1e8b54`의 thread를 EDI로 읽고,
`0x1870dc/0x1870dd/0x1870de`에서 (thread,saved_state)를 PCexception에 전달한다.
PCexception의 REAL/PROT 호출도 arg1을 그대로 전달한다. REAL의 간접 CALL은
(arg1,state,prefix_count,flags), PROT의 하위 호출은 arg1을 첫 인자로 전달한다.
이 관찰한 호출 경로에서 recovery store의 base는 thread다. 임의의 외부 호출·alias까지
형식적으로 닫았다는 뜻은 아니다.

PC 상태 접근은 thread+0x28 → PCB, PCB+0xec → 포인터, 그 포인터의 첫 DWORD → M,
M+0x84의 index를 사용한다. index가 unsigned 7 이하이면 레코드 R은
`M+0x88+index*0x84`이다. Python으로 stride는 132바이트임을 확인했다.
일부 경로는 포인터가 없거나 index가 범위를 벗어나 R=0이 된 뒤에도 R 필드를 접근한다.
이를 정상적인 NULL 허용 계약으로 해석하지 않는다. 초기화·등록 불변식은 후속 검토다.

R+0x68은 emulation의 가상 interrupt 상태에 사용되고,
R+0x74는 pending 상태의 검사/OR에 쓰인다. 예를 들어 `0x1a279f`, `0x1a29b5`,
`0x1a3ab1`의 OR와 `0x1a14e2`의 비교는 **thread recovery slot의 변경/검사가 아니다**.
동일 offset만 검색해서 두 객체를 하나의 필드로 간주하지 않았다.

## 2. literal store 36개와 정상 해제

각 후보는 DWORD의 literal recovery entry를 thread+0x74에 기록한다.
보호 구간 안에는 FS BYTE/WORD/DWORD read 또는 WORD/DWORD write가 있으며,
선택한 각 구간의 정상 종료에는 명시적인 slot=0 store가 있다.
등록과 정상 clear 사이에 CALL은 없다. 후보를 포함한 parent 본문에는
이전 +0x74 값을 source operand로 읽어 저장·복원하는 명령이나 CLD/STD/CLI/STI가 없다.
따라서 앞선 copy helper의 짧은 성공 경로와 같은 clear 우회를 이 목록에서 발견했다고
보고하지 않는다. 정상 clear가 중첩 trap/임의 alias/native 상태까지 보장한다는 뜻도 아니다.

| parent entry | recovery target들 | 보호 접근의 역할 |
|---|---|---|
| `0x1a1b60` | `0x1a1bdc`, `0x1a1c70`, `0x1a1ce8`, `0x1a1d5c` | REAL marker fetch 및 stack 인자 읽기 |
| `0x1a1d9c` | `0x1a1e2c` | REAL DWORD flags push |
| `0x1a1e70` | `0x1a1eec` | REAL DWORD flags pop |
| `0x1a1f8c` | `0x1a202c` | REAL 넓은 복귀 frame 읽기 |
| `0x1a20d4` | `0x1a215c`, `0x1a22e0`, `0x1a230c` | INT 인자 fetch, frame write, vector fetch |
| `0x1a2384` | `0x1a2520`, `0x1a2548` | REAL 예외 frame write와 vector fetch |
| `0x1a25a4` | `0x1a2614` | REAL opcode/prefix BYTE fetch |
| `0x1a27b0` | `0x1a2860` | REAL WORD flags push |
| `0x1a28a0` | `0x1a2940` | REAL WORD flags pop |
| `0x1a29dc` | `0x1a2a9c` | REAL 좁은 복귀 frame 읽기 |
| `0x1a2b40` | `0x1a2bf0`, `0x1a2c4c`, `0x1a2cf0`, `0x1a2d68`, `0x1a2dfc`, `0x1a2e74`, `0x1a2f08`, `0x1a2f7c` | PROT descriptor/marker/stack 인자 읽기 |
| `0x1a2fc8` | `0x1a303c`, `0x1a311c` | descriptor read와 error 포함 좁은 frame write |
| `0x1a3160` | `0x1a3200`, `0x1a32dc`, `0x1a339c`, `0x1a3450`, `0x1a34fc`, `0x1a35b4`, `0x1a3660`, `0x1a3718` | gate/segment descriptor와 조건별 frame write |
| `0x1a37c0` | `0x1a3834`, `0x1a388c` | PROT descriptor/opcode fetch |

setup/정상 clear의 정확한 주소와 FS 명령·폭은 증거 JSON의 slot_contracts에 각각 기록했다.
별도의 synthetic continuation `0x1a1e64`, `0x1a2354`, `0x1a2590`, `0x1a2894`도
추가했다. recovery entry만 선택하면 이 종료 코드들이 빠진다.

## 3. 복구는 독립 함수 반환이 아니다

이 fragment들은 enclosing helper의 EBP와 보존 레지스터를 사용한다.
초기 thread arg를 유지한 레지스터 또는 [EBP+8] 재로드를 통해 clear하고,
다른 fragment나 원래 본문으로 분기/fallthrough한다. fragment의 void C 서명이나
단독 디컴파일 결과를 정상 ABI 함수로 해석하지 않는다.

대부분은 EAX=0을 설정하고 enclosing epilogue로 가지만, 다음 차이가 중요하다.

- `0x1a1bdc/0x1a1c70/0x1a1ce8`은 `0x1a1d5c`로 모여 clear/EAX=0 뒤 종료한다.
- `0x1a22e0/0x1a230c`는 clear 후 `0x1a2354`로 간다. INT 처리에서 먼저 증가한
  saved EIP의 낮은 WORD에서 prefix_count+2를 빼고 zero-extend하여 저장한 뒤 EAX=0이다.
  앞서 발생한 guest stack의 부분 write를 되돌리는 코드는 아니다.
- `0x1a2520/0x1a2548`은 clear 후 `0x1a2590`의 EAX=0으로 종료한다.
  앞의 INT 경로와 달리 이 fragment에 EIP 감소가 있다고 해석하지 않는다.
- opcode fetch 실패 `0x1a2614`는 clear 후 REAL 본문의 `0x1a2678`로 이동한다.
  handled flag는 아직 0이고 fallback `0x1a2384`를 호출한다. 즉 단순 errno 반환 stub가 아니다.
- descriptor read 복구 `0x1a2bf0` 등은 EAX=0 후 본문의 TEST/JE로 failure에 진입한다.
  정상 descriptor read는 별도로 EAX=1을 만들며 그 뒤의 본문을 실행한다.
- `0x1a3200`은 EAX=0/TEST/JE `0x1a3768`을 포함한다.
  `0x1a3450/0x1a35b4/0x1a3718`의 frame write 실패도 같은 false 반환 경로로 간다.
  이미 기록한 guest memory의 전체 rollback을 제공한다고 볼 수 없다.

93차에서 확인한 trap recovery 소비자는 저장 EIP/CS/DF를 바꾸지만 helper의
원래 EBP 프레임을 새로 만들지 않는다. 실제 중첩 trap에서 이 프레임/레지스터가 유효한지와
active thread 동일성은 계속 별도 전제로 유지한다.

## 4. REAL opcode dispatch와 접근 폭

REAL dispatcher `0x1a25a4`는 state+0x30이 0xd일 때 opcode fetch를 진행한다.
입력 opcode BYTE에 0x70을 BYTE 폭으로 더한 값을 zero-extend하여
`0x1e4b80 + index*4`의 함수 포인터를 읽고 `0x1a2668`에서 간접 CALL한다.
원본에서 전 범위 256 DWORD/1024바이트를 읽었다. 끝 주소는 `0x1e4f80`이며
그 위치에는 다음 원본 심볼 `_pseudo_inits`가 있다. 파일의 nonzero slot은 다음과 같다.

| opcode BYTE | 원본 target | 이 보고서에서 관찰한 동작 |
|---|---|---|
| 0x9c | `0x1a27b0` | WORD flags push, 내부 flags & 1 조건에서 DWORD helper 호출 |
| 0x9d | `0x1a28a0` | WORD flags pop, 같은 조건에서 DWORD helper 호출 |
| 0xcd | `0x1a20d4` | INT 인자 fetch와 예외 frame/vector 처리 |
| 0xcf | `0x1a29dc` | 좁은 복귀 frame, 같은 조건에서 넓은 helper 호출 |
| 0xfa | `0x1a26c8` | saved EIP 진행, R+0x68=0 |
| 0xfb | `0x1a2734` | saved EIP 진행, R+0x68의 전환 및 R+0x74 pending OR |

prefix 0x66은 내부 flag의 낮은 bit를 OR하고 0xf0은 count만 진행시킨다.
반복 0x66을 XOR 토글로 표현하지 않는다. fetch offset은 Python 계산으로 0..14이며,
그 범위를 prefix만 소진하면 fallback으로 간다. 그 밖의 opcode에 대한 표의 NULL entry도
fallback이다. 원본 파일의 표가 runtime에 변경되지 않는지까지 확인한 것은 아니다.

REAL 주소 계산은 `(segment16 << 4) + offset16`이다. 포인터 갱신은 WORD 단위로
wrap할 수 있지만, 각 FS WORD/DWORD 명령 내부를 BYTE별 wrap으로 분해하지 않는다.
Python에서 최대 시작 주소는 0x10ffef이며 최대 DWORD 마지막 BYTE 주소는 0x10fff2다.
이는 해당 산식의 값일 뿐 FS descriptor/실제 map/A20/물리 주소의 관찰 결과가 아니다.

flags pop의 DWORD 경로는 `&0x70fd7 |0x20202`, WORD 경로는 `&0xfd7 |0x20202`다.
R+0x80의 mask 0x1 조건에서 기존 TF 관련 bit를 보존하는 별도 단계가 있고,
입력 flags에서 R+0x70의 0x7000 부분과 R+0x68의 상태도 갱신한다.
이 명령을 host CPU의 실제 CLI/STI 실행으로 바꾸어 설명하지 않는다.

marker 처리 `0x1a1b60`과 `0x1a2b40`은 DWORD fetch의 낮은 WORD 0xc4c4를 검사하고
그 다음 BYTE로 분기한다. 0xfa/0xfc/0xfd 경로는 각각 20/10/20바이트를 WORD loop로 읽은 뒤
`0x1a18c8/0x1a1918/0x1a1968`로 전달한다. 0xfe는 `0x1a1ad4` 호출 및 R+0x58=4,
그 밖의 marker 인자는 레코드 필드 설정과 `0x1a1750` 호출로 연결된다.
이 callee들의 전체 monitor/state 전이는 이번 완료 범위에 포함하지 않는다.

## 5. PROT descriptor와 saved-state 갱신 순서

PROT marker/opcode 접근은 selector의 bit 0x4를 검사하고 WORD selector>>3으로
index를 만든다. M+0x38의 table base와 M+0x3c의 bound를 사용해 descriptor 시작 offset을
검사하고, FS DWORD 두 번으로 descriptor를 읽는다. gate 경로 `0x1a3160`은
M+0x30/M+0x34의 다른 base/bound를 먼저 사용한다.
관찰한 검사는 **start offset < bound**이다. bound의 writer·단위·정렬 전제 없이 이를
모든 descriptor BYTE의 안전한 경계 검사로 확대하지 않는다.

descriptor의 분리된 base BYTE/WORD를 합쳐 주소를 만들며, descriptor의 0x40 bit에 따라
offset mask가 0xffff 또는 0xffffffff다. WORD loop에서는 매 iteration의 시작 offset을
mask한 뒤 FS WORD를 접근한다. RPL/segment limit/권한 등 하드웨어와의 완전한 동등성을
이 지역 산식에서 추정하지 않는다.

`0x1a3160`의 gate type 낮은 0x1f 부분은 6/7/0xe/0xf만 허용한다.
gate의 상위 bit와 대상 descriptor의 `(type &0x18)==0x18`, 상위 bit 검사도 있다.
6/0xe는 성공 후 가상 interrupt 상태를 clear하고, 7/0xf는 같은 clear를 하지 않는다.
frame은 조건별로 6/12바이트 또는 error 포함 8/16바이트다.
guest stack write가 정상 종료된 뒤 saved SP를 갱신하며, 이후 saved EIP/CS,
조건부 TF 및 R+0x68을 갱신하고 EAX=1을 반환한다. 실패 시 EAX=0이더라도
guest memory와 callee가 이미 변경한 상태까지 모두 원복되었다는 뜻은 아니다.

`0x1a37c0`의 INT 처리에서는 saved EIP를 먼저 2만큼 진행하고 `0x1a3160`을 호출한다.
반환이 0이면 descriptor의 폭 조건에 맞춰 EIP를 2만큼 되돌린다.
이는 국소 EIP 보정이지 guest frame의 부분 write rollback이 아니다.
0xfa/0xfb 처리는 R+0x68/pending 상태와 saved EIP를 조정한다.

PROT wrapper `0x1a3ac4`는 trap 0xd에서 `0x1a37c0`, trap 6에서 `0x1a2b40`을 먼저 시도한다.
처리하지 못하면 monitor bitmap/필드 처리 및 `0x1a3160` 호출로 이어지고 최종 결과를
0/1로 정규화한다. `0x1a1750`이 일반적으로 return하는지 또는 saved-state를 바꾸는지는
이번 호출 순서 검토와 구분한다.

## 6. C export의 실제 초기화 누락

`0x1a3160.c`는 local_20/local_38 배열을 선언한 뒤 local_4c로 가리켜 WORD를 읽는다.
전체 C 텍스트에서 local_20의 출현은 선언과 두 pointer assignment,
local_38은 선언과 pointer assignment뿐이다. 증거 JSON에 해당 줄과 텍스트를 보존했다.
하지만 원본에는 다음 초기화 명령이 명확히 있다.

| 전송 frame | 원본 초기화 store | 원본에 기록되는 항목 |
|---|---|---|
| 12바이트 | `0x1a33b6`, `0x1a33c0`, `0x1a33ca` | saved EIP DWORD, CS WORD, flags DWORD |
| 6바이트 | `0x1a3517`, `0x1a3522`, `0x1a352d` | saved EIP/CS/flags의 WORD들 |
| 16바이트 | `0x1a3677`, `0x1a3680`, `0x1a368a`, `0x1a3694` | error DWORD, EIP DWORD, CS WORD, flags DWORD |

뒤따르는 가상 interrupt 상태 반영도 ASM의 별도 OR/AND로 확인해야 한다.
따라서 해당 C를 그대로 동작 설명이나 완전한 원본 의미 표현으로 사용할 수 없다.
export/DB를 고치거나 새로운 커널 코드를 작성하지 않았으며, 누락을 명시적 미해결 항목으로 남겼다.

## 7. 원본 CS 저장 폭과 미초기화 구간 — C 누락과 별개

원본의 12바이트 frame은 EBP-0x1c에서 시작하지만 CS는 EBP-0x18에 WORD로만 저장한다.
Python byte footprint 계산에서 **EBP-0x16, EBP-0x15**는 해당 초기화 store들이 쓰지 않는
전송 범위의 BYTE다. 16바이트 frame에서도 **EBP-0x2a, EBP-0x29**가 같은 위치에 해당한다.
이 함수 전체의 직접 EBP-relative MOV store 목록을 추가 검사해 그 BYTE들과 겹치는
명시적 MOV 초기화가 없음을 확인했다. 전송 loop는 두 경우 모두 WORD 단위로 frame 전체를 읽는다.

이는 유효하고 비중첩인 state/monitor 포인터라는 전제하의 원본 stack store 감사다.
실제 stack의 초기 내용·간접 alias writer·native 도달·정보 노출을 증명하지 않는다.
“C에서 빠졌다”는 이유로 원본 초기화가 전혀 없다고 결론내리거나,
반대로 원본 CS를 DWORD 초기화로 상상해 빈 BYTE를 채우지 않았다.

## 8. 경고와 남은 범위

`0x1a2bf0`의 C가 정상 성공 후손을 unreachable로 제거하는 것은, 그 fragment가 EAX=0으로
진입하는 맥락과 관련된다. enclosing `0x1a2b40`의 정상 read는 EAX=1이며
같은 본문 분기를 통과한다. fragment C의 제거 경고를 이유로 원본 ASM을 삭제하지 않는다.
`0x1a219e`, `0x1a3926`은 각각 바로 앞 MOVZX BYTE에서 유래한 ECX의 범위와
TEST/JGE를 대조했다. 이 제한된 incoming path의 음수 보정 경로는 실행되지 않지만,
전체 커널 경고를 모두 해소했다는 뜻은 아니다.

남은 literal 후보가 0이라는 판정은 **94차 exact-literal 목록 안에서만** 유효하다.
alias/절대주소/bulk/겹친 폭/함수 밖 writer, PC monitor·descriptor 등록과 수명,
stack reuse/중첩 trap/실제 IRQ·FS, 전체 decompiler 누락 ledger와 기타 kernel subsystem이 남아 있다.
