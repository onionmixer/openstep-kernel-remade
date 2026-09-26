# 95차 — 원본 copy/string/fu/su 복구 슬롯과 직접 소비자

## 판정과 범위

OPENSTEP x86 원본의 비-PC 복사 helper 및 복구 fragment를 재대조했다.
짧은 message/within 복사의 정상 종료가 복구 슬롯 해제를 건너뛰는 점,
문자열의 실제 복사량과 보고 길이가 달라지는 조건, BYTE 부호 확장이 uio 반환에
영향을 주는 조건을 원본 명령으로 확인했다. 실제 실행 재현이나 전체 커널 완료를 뜻하지 않는다.

원본 SHA-256: `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`.
외부 소스·복원 코드·live DB 변경·동적 실행은 사용하지 않았다.
Ghidra 스킬의 본문·호출 참조 검토 절차를 기존 export에 적용하고,
디컴파일러의 타입/반환형보다 Python/Capstone 원본 재디코드와 명령 순서를 우선했다.
독립 계획 교차검토는 새로 수신하지 않았으며 통과로 간주하지 않는다.

자료: [범위](SCOPE.md), [명령·참조·계산 증거](object-lifetime-evidence.json),
[기존 파일 보존](preservation.json), [검증 체크포인트](checkpoint.json),
[남은 분석](OPEN_ITEMS.md), [이전 94차](../continuous-review-20260913-94/README.md).

Python 집계: 일반 본문 18개와 fragment 12개, 합계 30개 본문의 882개 명령/2,399바이트.
직접 분기 128개, 직접 CALL 22개, 간접 전이 0개, 디컴파일 경고 3개를 보존했다.
별도의 IPC get 인자 창 6개/98개 명령은 이 본문 수치에 합산하지 않았다.
핵심 operand 문자열 147개, 복구 계약 12개, 참조 행 109개,
문자열 3개, 전역 경계 2개, 입력 101개 및 기존 보존 파일 861개를 대조했다.
이는 선택 범위의 검증 수치이지 커널 전체 의미 분석 coverage가 아니다.

## 1. thread+0x74 등록·해제와 fragment 프레임

아래 setup은 바로 앞 명령이 `active_threads` 주소 `0x1e8b54`에서 읽은 thread를
기준으로 하는 DWORD store이다. 같은 숫자의 PCB/uthread 필드와 혼동하지 않았다.
clear와 fragment는 thread 전역을 다시 읽는다. 문맥 전환·중첩을 포함한
동일 thread 보장은 이 지역 명령만으로 확정하지 않는다.

| helper entry | 등록 store | 정상 clear | 복구 entry | 정상/복구 공통 epilogue |
|---|---|---|---|---|
| copyinmsg `0x189b34` | `0x189b51` | `0x189bf5` | `0x189c00` | `0x189c11` |
| copywithin `0x189c1c` | `0x189c2a` | `0x189cc4` | `0x189cd0` | `0x189ce1` |
| copyoutmsg `0x189e8c` | `0x189ea9` | `0x18a00a` | `0x18a018` | `0x18a029` |
| copystr `0x18a034` | `0x18a04b` | `0x18a07a` | `0x18a088` | `0x18a099` |
| copyinstr `0x18a0a4` | `0x18a0bb` | `0x18a0eb` | `0x18a0f8` | `0x18a109` |
| copyoutstr `0x18a114` | `0x18a12b` | `0x18a15b` | `0x18a168` | `0x18a179` |
| fuword `0x18a184` | `0x18a190` | `0x18a19f` | `0x18a1ac` | 복구 `0x18a1bd` |
| fubyte `0x18a1c4` | `0x18a1cf` | `0x18a1de` | `0x18a1ec` | 복구 `0x18a1fd` |
| fuibyte `0x18a204` | `0x18a20f` | `0x18a21e` | `0x18a22c` | 복구 `0x18a23d` |
| suword `0x18a244` | `0x18a252` | `0x18a261` | `0x18a270` | 복구 `0x18a281` |
| subyte `0x18a288` | `0x18a296` | `0x18a2a5` | `0x18a2b4` | 복구 `0x18a2c5` |
| suibyte `0x18a2cc` | `0x18a2da` | `0x18a2e9` | `0x18a2f8` | 복구 `0x18a309` |

각 helper 자체에는 CALL/CLD/STD, 이전 슬롯 값의 저장·복원 명령이 없다.
앞의 복사/문자열 fragment는 17바이트이며 slot=0, EAX=`0xe`를 기록한 후
enclosing helper의 epilogue로 fallthrough한다. fu/su fragment는 21바이트이며
slot=0, EAX=`0xffffffff`, MOV ESP,EBP / POP EBP / RET로 끝난다.
후자도 prologue 없이 기존 EBP를 소비하므로 독립적으로 호출 가능한 함수 ABI가 아니다.
93차의 trap 소비자는 저장 EIP/CS/DF를 조정하지만 이 helper의 EBP 프레임을 재구성하지 않는다.
stale slot이 실제 어느 trap에서 소비되는지, 그때 프레임이 유효한지는 미확정이다.

## 2. message/within copy의 짧은 성공 경로

signed length가 15 이하인 분기는 길이 0도 포함한다. 정상 전송을 마치면
`0x189b6a→0x189c11`, `0x189c42→0x189ce1`, `0x189eff→0x18a029`로 이동한다.
모두 EAX=0을 반환하지만 위 표의 정상 clear를 실행하지 않는다.
길이가 양수이고 긴 경로가 정상 종료하면 clear를 통과한다.
이는 92차 copyin/copyout과 별도로 해당 message/within 원본에서 확인했다.

copyinmsg의 REP는 FS source→ES destination이다. copywithin은 기본 DS source→ES
destination이며 scalar tail은 기본 DS를 사용한다. CLD가 없으므로 REP의 전진 복사는
호출 시 DF=0이라는 전제를 필요로 한다. 두 긴 경로는 source를 DWORD 경계에 맞춘
prefix, DWORD REP, 남은 BYTE 순이며 tail은 해당하는 +2, +1, +0 순으로 접근한다.
copywithin에 overlap 판정이나 명시적인 후진 memmove 경로가 있다고 해석하지 않는다.

copyoutmsg는 REP 없이 기본 DS source→FS destination의 scalar BYTE/WORD/DWORD를
사용한다. 짧은 경로는 길이의 낮은 비트에 따른 BYTE/WORD 뒤 DWORD loop,
긴 경로는 source alignment prefix 뒤 부분 DWORD 및 16바이트 묶음, 마지막 tail이다.
부분 unroll은 남은 길이 `& 0xc`, 완전 묶음은 남은 길이의 16바이트 단위,
tail은 `& 3`에 대응한다. 원본의 분기 중간 진입을 일반적인 C loop로 단순화하지 않았다.

음수 길이를 자체적으로 거절하지 않는다. 예컨대 Python DWORD 해석으로
`0x80000000`은 signed `-2147483648`이므로 copyinmsg/within의 짧은 분기로 들어가지만
REP ECX는 `2147483648`이다. 이것은 인자 가정에 따른 지역 결과이며 실제 IPC caller의
할당 성공·인자 허용·native 도달성을 입증한 것이 아니다.
복사 중 fault의 부분 전송량이나 rollback을 이 helper가 별도 반환한다고 볼 근거도 없다.

## 3. 문자열의 종료·보고 길이 계약

세 문자열 함수의 count 구조는 같다. ESI=입력 한도 n, EDX=n-1로 시작한다.
signed n<=0이면 데이터 접근을 생략한다. 양수이면 BYTE를 읽고 쓰고 포인터를 증가시킨다.
NUL이면 EDX 감소 전에 빠져나온다. non-NUL이면 감소 전 EDX를 EAX에 복사하고
EDX를 감소시킨 뒤 EAX>0일 때 반복한다. 출력 count 포인터가 non-NULL이면
`n-EDX`를 DWORD로 저장한 다음 slot=0, EAX=0으로 끝난다.

copyinstr의 핵심 주소는 `0x18a0c2` 초기화, `0x18a0d5` NUL 분기,
`0x18a0d7/0x18a0d9/0x18a0dc` 감소/반복, `0x18a0e4` count store,
`0x18a0eb` clear, `0x18a0f2` 성공 반환이다. copystr은 DS→DS,
copyinstr은 FS→DS, copyoutstr은 DS→FS이다.

| fault 없는 입력 조건 | 실제 복사 BYTE 수 | 보고 count DWORD | EAX |
|---|---:|---:|---:|
| n=0 | 0 | 1 | 0 |
| n=-1 | 0 | 1 | 0 |
| n=1, 첫 BYTE non-NUL | 1 | 2 | 0 |
| n=4, 첫 NUL이 마지막 BYTE | 4 | 4 | 0 |
| n=4, 모두 non-NUL | 4 | 5 | 0 |
| n=1024, 모두 non-NUL | 1024 | 1025 | 0 |

표는 Python의 한도/레지스터 폭 산식이다. 출력 포인터가 없으면 count store는 생략된다.
한도를 소진해도 자체적으로 NUL을 추가하거나 별도의 길이 초과 오류를 반환하지 않는다.
count store 당시에도 복구 주소가 등록되어 있다. 데이터 fault가 count store보다 먼저
발생하면 정상 count 갱신을 거치지 않는다. count 포인터 fault 및 부분 store의 원자성은
별도 문제이며, 이 보고서는 전체 rollback 또는 정확한 부분 복사량을 주장하지 않는다.

## 4. pn_get / pn_set의 실제 소비

pn_get `0x11c9a0`은 `0x400` 크기를 할당하고 pn+0/pn+4에 버퍼,
pn+8에 0을 저장한다. 자체적인 할당 NULL 검사 없이 segment 인자가 0이면 copyinstr,
그 밖에는 copystr을 동일 한도와 &pn[+8]로 호출한다.

성공 status일 때에도 `0x11ca00`은 보고 count가 **정확히 0x400인지** 검사한다.
같을 때만 `0x11ca0c`에서 buf+0x3ff가 NUL인지 확인하고, non-NUL이면 status=0x3f다.
그 뒤 `0x11ca1a`에서 pn+8을 항상 감소시키며, status가 비영이면 pn_free를 호출한다.

따라서 유효하고 읽기 가능한 첫 1024 BYTE가 모두 non-NUL이고 fault가 없다는 조건에서는
helper count=1025, exact-count 검사 불일치, 마지막 BYTE 검사 생략,
최종 pn+8=1024, status=0이다. helper가 NUL을 추가하지도 않는다.
마지막 BYTE가 NUL이면 count=1024로 검사를 통과하고 최종 길이는 1023이다.
이는 원본 호출과 조건문의 연결이지 native 경로 재현·후속 out-of-bounds의 증명이 아니다.
count 갱신 전 copy fault이면 초기 0이 무조건 감소된 후 pn_free로 전달될 수 있다.

pn_set `0x11ca34`은 pn+4를 pn+0으로 되돌리고 copystr(...,0x400,&pn[+8]) 후
pn+8을 감소시킨다. 자체 last-BYTE 검사나 error cleanup이 없다.
`0x11ca53` 뒤 epilogue는 EAX를 덮어쓰지 않는다. C export의 void 표현과 달리
기계적으로 helper 반환 EAX가 보존된다. fault 전 count가 갱신되지 않았으면 이전 값이
감소되는 조건도 남는다. 이 값을 모든 caller가 어떻게 사용하는지는 후속 범위다.

## 5. 단일 값 접근과 BYTE uio 소비자

fuword는 FS DWORD 값을 반환하므로 정상 데이터 `0xffffffff`와 fault sentinel이 겹친다.
fubyte/fuibyte는 FS BYTE를 읽은 뒤 각각 `0x18a1e5`/`0x18a225`에서
**MOVSX EAX,DL**을 사용한다. 정상 범위는 -128..127이고 BYTE 0xff는 정상이어도 -1이다.
suword는 FS DWORD, subyte/suibyte는 인자의 낮은 BYTE를 FS에 쓰고 정상 EAX=0이다.
fu/su fault fragment의 EAX는 모두 `0xffffffff`다. 이름의 i만으로 다른 segment를 추정하지 않는다.

uwritec `0x10a4d8`은 signed resid<=0이면 -1을 반환한다. 벡터 선택 시 count>0을
요구하고, 길이가 정확히 0인 벡터를 넘긴다. 음수 벡터 길이는 같은 skip 조건이 아니다.
segment 0/2는 fubyte/fuibyte, segment 1은 직접 **MOVZX** BYTE read다.
`0x10a560/0x10a562`의 TEST/JL은 helper가 반환한 음수 전체를 -1 처리하고,
선택한 벡터의 base++, len--, resid--, offset++보다 먼저 빠져나간다.
따라서 유효한 BYTE 0x80..0xff도 segment 0/2에서는 이 조건에 해당한다.
Python 전 BYTE 집계로 128개 값이며 segment 1의 직접 read는 같은 부호 확장을 하지 않는다.
앞선 빈 벡터를 넘기며 uio 포인터/count가 이미 바뀔 수 있어 전체 상태 불변은 주장하지 않는다.
잘못된 segment는 panic 경로다. panic이 반환하지 않는다는 decompiler 경고를
정상 caller 입력 보장의 증거로 삼지 않았다.

ureadc `0x10a448`은 벡터 길이<=0 또는 resid<=0이면 다음 벡터로 진행하며 count=0에서
panic으로 간다. resid=0을 자체의 조용한 성공 종료로 해석하지 않는다.
segment 0/2는 subyte/suibyte, segment 1은 직접 BYTE write다.
helper 음수 반환은 선택 벡터 진행 전에 EAX=0xe로 변환된다.
그 밖의 segment 분기는 BYTE write 없이 공통 진행부로 간다.
유효 segment/caller 불변식, panic의 실제 제어 흐름, 빈 벡터의 선행 변경은 별도 검토 대상이다.

## 6. IPC message get/put과 get caller의 한계 조건

ipc_kmsg_get `0x14758c`의 자체 gate는 unsigned size>=24, 4의 배수,
signed adjustment<=0이다. size<=0xec이면 전역 cache `0x1f6258` 또는 kalloc(0x100),
그 밖에는 DWORD size+0x14 할당을 사용한다. 할당 실패 반환은 0x1000000d다.
실제 copyinmsg 길이는 `0x14761d/0x147620`의 **size+adjustment**이고 destination은 record+0x14다.
오류이면 capacity에 따라 일반/장치/네트워크 release 또는 -1 sentinel의 비해제 분기를 거쳐
0x10000002를 반환한다. 성공이면 record+0x10=adjustment, record+0x18=size,
*out=record, EAX=0이다. 초기 gate 오류는 0x10000008이다.

get 자체 gate만 고려한 size=24, adjustment=-12 → copy length=12 예시는 산술적으로
가능하지만, 조사한 실제 직접 caller가 이를 공급한다고 결론내리지 않았다.
export의 get 직접 참조에 대응하는 인자 창 6개를 원본으로 추가 확인했다.

| caller | get CALL 주소 | 관찰한 adjustment |
|---|---|---|
| mach_msg_send | `0x1525d6` | 0 |
| mach_msg_trap | `0x1535b7`, `0x1539d8`, `0x153bde` | 0 |
| msg_send_trap | `0x1542fe` | N - ((N+3) & 0xfffffffc) |
| msg_rpc_trap | `0x1545e2` | 같은 반올림 차이 |

후자의 실제 마스크 명령은 `0x1542dd`의 AND CL,0xfc와 `0x1545c1`의 AND BL,0xfc다.
상위 BYTE를 보존하므로 표의 DWORD 마스크 산식과 대응하지만 DWORD 폭의 AND 명령은 아니다.
이 폭을 최종 대조에서 명시적으로 구분했다. 반올림 결과는 caller에서 unsigned <=0x2000을 검사한다.
get의 최소 크기 gate까지 통과하면 반올림 차이는 -3..0, 실제 복사 길이 최소는 21이므로
이 제한된 두 caller에서는 비음수 길이<=15 예시가 배제된다. 반올림 wrap으로 0이면
get의 최소 크기 gate가 거절한다. 앞의 adjustment=0 caller에서도 비음수 size>=24이면
긴 복사지만, 높은 비트가 설정된 size의 signed 해석/할당/native 허용까지 증명한 것은 아니다.
조사한 인자 창 밖의 전체 caller CFG나 간접 호출까지 완료로 세지 않는다.

ipc_kmsg_put `0x1476ec`은 record+0x10=0을 copyoutmsg보다 먼저 기록한다.
copy 오류를 0x10004008로 변환한 뒤에도 capacity=0x100이고 cache가 비었으면
cache에 넣거나, 그 밖에는 capacity별 release 분기로 간다. -1 sentinel은 비해제 분기다.
오류일 때 객체를 반드시 보관해 재시도한다거나 이미 기록한 사용자 데이터를 되돌린다고
해석할 수 없다. 자체 length 최소/부호/객체 경계 검사는 없으며 put caller의 길이 불변식,
cache의 잠금/수명/실제 소유권은 아직 열려 있다.

## 7. 완료로 세지 않은 것

94차 exact-literal 후보 50개 중 이번에 helper base를 확인한 store는 12개,
92차 copyin/out은 2개, 미검토 PC 계열 후보는 36개다.
이 후보 분할은 +0x74 literal store 목록 안의 진전일 뿐 모든 writer의 발견 증명이 아니다.
alias-derived store, 절대주소·bulk·겹치는 폭·함수 밖 instruction, template/runtime writer와
실제 중첩·IRQ/DF/FS/ES·trap 프레임은 별도 추적을 계속해야 한다.
원본 전체의 함수/영역 coverage·ABI·디컴파일 실패·VM·IPC·VFS·드라이버 분석도 남아 있다.
