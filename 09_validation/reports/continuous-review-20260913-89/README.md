# 89차 — doSdBuf의 전송·재시도·완료 계약

## 결과와 증거

setup 실패의 자체 완료와 outer 함수의 조기 반환을 연결하고, 일반 전송의 재시도,
마지막 actualLength/status 저장과 sdIoComplete 호출까지 원본으로 대조했다.
IOSCSIController 기본 executeRequest는 실제 전송 없이 상수 100을 반환한다.
따라서 이 정적 기본 IMP만으로 실제 하드웨어 전송을 입증하지 않는다.

Python으로 13개 본문, 1,087개 instruction head, 3,224바이트를 대조했다.
직접 분기 110개, 직접 CALL 70개, 간접 분기 3개, Ghidra 경고 1개를 보존하고,
중요 operand 수는 증거 JSON에 기록했다. jump table 3개/entry 37개,
method list 2개/entry 28개, selector slot 27개/참조 567행,
진단 이름 table 3개/entry 50개, 별도 문자열 24개와 global 경계 3개를 기록했다.
입력 46개 및 기존 보존 파일 825개의 해시를 확인했다.
이 수치는 이번 선택 범위이며 전체 kernel 의미 검증률이 아니다.

[증거 JSON](object-lifetime-evidence.json), [범위](SCOPE.md),
[잔여 작업](OPEN_ITEMS.md), [검증 결과](checkpoint.json),
[보존 해시](preservation.json), [88차 연결](../continuous-review-20260913-88/README.md).

## 원본 대상과 구조 경계

SCSIDisk `Thread` category list `0x1f8990`의 doSdBuf `0x1ad8b0`,
setup `0x1ae510`, CDB 생성 `0x1ae488`, sense `0x1ae600`, 로그 `0x1ae348`을 검토했다.
IOSCSIController class `0x1fa35c`, method list `0x1fc82c`에서 기본 execute,
상태 변환, DMA alignment, 버퍼 할당 및 초기화를 연결했다.
파일의 superclass 필드는 IODirectDevice 이름 주소이며 runtime class pointer로 단정하지 않는다.

아래에서 R은 88차 큐 요청, S는 doSdBuf stack `EBP-0x54`의 별도 전송 요청,
T는 R `+0x14`의 선택적 별도 요청 포인터다. R/S/T/B를 같은 구조체로 취급하지 않는다.
S의 크기 84바이트, S `+0x1c` DWORD 상태, `+0x20` BYTE 상태,
`+0x24` DWORD 실제 길이, `+0x38`의 sense 복사 시작은 원본 접근과 Python offset 계산으로
확인했다. 외부 header의 타입·상수 정의를 가져오지 않았다.

## setup과 자체 오류 완료

`setupScsiReq:scsiReq:`는 self.blockSize를 읽고 bzero(S,0x54)를 호출한 뒤,
self `+0x188/+0x189` BYTE를 S `+0/+1`에 저장한다.

- 명령 0/1: S `+0xe`를 각각 1/0으로 쓰고 CDB 생성에 readFlag 1/0을 전달한다.
  R `+0x14`를 0으로 만들며 S.length `+0x10`에 blockSize*R.blockCount의 DWORD 곱,
  `+0x14`에 0x1e, BYTE `+0x18`에 mask 1을 OR하고 EAX=0을 반환한다.
- 명령 2–4: T가 가리키는 첫 WORD와 self `+0x188` WORD를 비교한다.
  같으면 CLD/REP MOVSD로 T에서 S로 84바이트를 복사하고 0을 반환한다.
  T 자체의 NULL 검사나 읽기 범위 검사는 없다.
- 불일치: T `+0x1c`에 DWORD 7, R.status에 `0xfffffd3e`(-706)를 쓰고
  sdIoComplete:(R)을 호출한 **뒤** EAX=7을 반환한다. R.actualLength를 자체에선 새로 쓰지 않는다.
- 명령 >4(unsigned): 초기 S 필드 작성 뒤 0을 반환한다. 이 helper 자체가 모든 명령을
  거부하는 것은 아니다. worker의 명령 분기·caller 전제가 별도로 필요하다.

doSdBuf는 setup 결과 비영이면 `0x1ad931`에서 곧바로 epilogue로 가며 R을 다시
읽거나 자체 sdIoComplete를 호출하지 않는다. 선택한 setup IMP의 오류 경로는 이미
완료했으므로, 이 조기 반환을 단순 '완료 누락'으로 볼 수 없다.
반대로 동적 override가 비영 반환 전에 완료한다는 보장은 이 정적 후보로 얻지 못한다.

## CDB 바이트와 길이의 서로 다른 폭

`genRwCdb`는 readFlag BYTE 비영이면 opcode BYTE 0x28, 아니면 0x2a를 기록한다.
CDB byte 1의 하위 mask 0x1f는 보존하고, self `+0x189` BYTE를 5비트 왼쪽으로
민 결과를 BYTE 폭으로 OR한다. block DWORD는 byte 2–5에 상위 바이트부터 기록한다.
count는 입력의 **WORD만** 읽고 byte 7–8에 상위/하위 순서로 기록한다.
byte 6/9는 자체에선 쓰지 않는다. setup의 bzero를 통한 초기화와 독립 호출을 구분해야 한다.

S.length는 전체 R.blockCount DWORD 곱인데 CDB count는 low WORD다.
예를 들어 Python 계산상 count=0x10000, blockSize=512이면 S.length=0x2000000,
CDB count bytes=0이다. 이러한 실제 입력의 허용 여부, controller의 max-transfer 검사,
명령 바이트 0의 외부 프로토콜 의미는 여기서 입증하지 않았다.
자체 count 상한·곱 overflow·LUN 범위 검사가 없다는 지역 사실만 기록한다.

## doSdBuf 주 전송과 retry

진입 시 R `+0x34/+0x38/+0x3c`를 각각 10/5/10으로 설정한다.
setup이 정상 반환하면 stack sense의 첫 BYTE에서 mask 0x80만 지우고,
`[self+0x184]`에 executeRequest:(S) buffer:(R+0xc) client:(R+0x10)을 보낸다.
이 본문 자체에는 buffer/client 변환이나 DMA mapping이 없으며 입력 값을 전달한다.

controller 결과가 0이고 명령 0/1이면 blockSize를 **다시 조회**하여
S.actualLength와 R.blockCount*blockSize DWORD를 비교한다.
불일치면 R `+0x38`을 감소시키고 signed 양수일 때 동일 R로 재시도한다.
부분 전송량을 R.block/buffer/count에 반영해 다음 구간으로 이동하는 코드는 이 본문에 없다.
로그의 "Received" 인자는 현재 S.actualLength가 아니라 **이전 R.actualLength**에서 읽는다.
마지막 길이와 진단에 출력된 길이를 혼동하지 않아야 한다.

전송 성공/길이 일치 시 self BYTE `+0x18a`의 mask 2가 설정되어 있으면 명령 0/1에
통계 메시지를 보내며, 실제 길이와 stack의 시간 관련 DWORD들을 전달한다.
이들의 단위·구조체 타입·실제 통계 IMP는 이번에 확정하지 않았다.

controller 결과 비영이며 R.flags&2이면 세부 retry를 건너뛰고 최종 처리로 간다.
그 밖의 unsigned 상태 분류는 다음과 같다.

| controller 상태 | 원본 지역 처리 |
|---|---|
| 1, 7–9, 14–19, 100 | fatal 진단 후 최종 처리 |
| 2, 3, 13 | S의 BYTE 상태를 해석하는 분기 |
| 나머지 비영 | R `+0x38` 감소, 남으면 일반 retry |

BYTE 상태가 8이면 R `+0x34` 감소 후 남을 때 IOSleep(1000), retry다.
2이면 controller 상태 2에서는 S `+0x38`에서 stack sense로 26바이트를 복사한다.
다른 경우 reqSense를 호출하며, 그 결과가 비영이면 로그 뒤 최종 처리한다.
이때 EBX는 원래 전송 결과가 아니라 **reqSense 결과**로 교체된다.
BYTE 상태가 2/8 모두 아니면 진단 뒤 controller 상태를 13으로 바꾼다.

sense의 BYTE `+2` 하위 nibble을 원본 jump table `0x1adb6c`로 분기한다.

| nibble | 원본 지역 처리 |
|---|---|
| 0, 1, 3, 4 | `+0x38` 감소, 남으면 retry |
| 2 | `+0x3c` 감소, 남으면 IOSleep(1000), retry |
| 6 | `+0x38` 감소, 남으면 retry |
| 7 | 진단 뒤 controller 상태 0x11로 최종 처리 |
| 5 또는 >7 | 진단 뒤 controller 상태 2로 최종 처리 |

진단 이름은 원본 내 문자열에만 근거한다. sense 포맷의 외부 규칙을 확인한 표가 아니다.
이 nibble 분기 자체는 sense의 첫 BYTE valid bit나 수신 길이를 검증하지 않는다.
재시도 통계도 self `+0x18a` mask 2에서 read/write/other selector로 나뉜다.

Python의 유한 budget 계산에서 동일 종류의 최대 주 전송 시도는 10/5/10회이고,
각 retry가 해당 counter 하나를 감소시키고 외부 변경이 없다는 조건에서 혼합 상한은 23회다.
추가 reqSense 전송, callback 자체의 반복/블로킹, 동적 override가 R을 변경하는 경우는
이 산술 범위 밖이며, 이를 전체 native 실행 시간이나 종료 증명으로 사용하지 않는다.

## 최종 상태와 완료

최종 gate는 R의 세 counter 중 하나라도 **0**이면 EBX=`0xfffffd36`(-714)로 강제한다.
따라서 short-count fatal 경로에서 일시적으로 설정한 15나 로그의 상태가 반드시
최종 R.status가 되는 것은 아니다. 양수 초기값과 원본 decrement 외 writer가 없다는
조건에서 counter 소진이 이 gate로 이어진다.

counter가 남아 있고 controller 상태가 비영이면 controller의 returnFromScStatus를 호출한다.
0이면 0을 유지한다. 선택한 IOSCSIController 기본 변환 `0x1abf58`의 원본 jump table은:

| 입력 | 반환 DWORD |
|---|---|
| 0 | 0 |
| 7 | 0xfffffd3e |
| 8 | 0xfffffd42 |
| 9 | 0xfffffd38 |
| 14 | 0xfffffd37 |
| 17 | 0xfffffd31 |
| 18 | 0xfffffd30 |
| 19 | 0xfffffd41 |
| 23 | 0xfffffd2c |
| 나머지 | 0xfffffd36 |

비영 최종 결과의 통계는 self mask 2에서 read/write/other로 나뉘며,
other에 한하여 R.flags&2이면 error 통계를 건너뛴다.
그 후 T가 비NULL이면 S.status DWORD→T `+0x1c`, S.BYTE 상태→T `+0x20`,
S.actualLength DWORD→T `+0x24`를 복사한다.
R `+0x24`에 마지막 S.actualLength, R `+0x28`에 변환 결과를 저장하고
sdIoComplete:(R)을 호출한다. 이 호출 뒤 자체 R 재접근은 없다.

S는 setup마다 다시 만들어지므로 여러 시도의 전송량을 누적한 값이 아니다.
controller가 쓴 actualLength의 상한이나 성공 시 완전성은 아직 별도 계약이 필요하다.
88차의 완료 helper가 이 값을 B.request에서 빼는 것과 연결되지만, 실제 override·
버퍼 수명·원본 메모리 전제가 확인되기 전에는 종단 간 안전성을 선언하지 않는다.

## reqSense의 별도 할당·전송·복사

`0x1ae600`은 controller의 allocateBufferOfLength:(26) actualStart:&raw
actualLength:&allocatedSize를 호출하고, 반환 aligned pointer와 raw/size를 구분해 보존한다.
S를 bzero(84)로 초기화하고 CDB opcode 3, CDB의 요청량 BYTE 26, target/lun BYTE,
방향 BYTE 1을 설정한다. getDMAAlignment가 채운 출력의 offset 8 DWORD A를 읽는다.
A<=1이면 S.length=26, 아니면 DWORD `(A+25)&(-A)`다. S `+0x14`에는 0x14,
BYTE `+0x18`에는 mask 1을 설정한다.

IOVmTaskSelf `0x1a9238`은 helper `0x17e3a8`의 EAX를 그대로 전달한다.
helper는 `[[0x1f748c]+0xc]`를 반환한다. global 원본 이름은 `_IOTask_kern`이나,
`__common` 영역의 실제 값과 pointed object의 유효성을 읽거나 확정하지 않았다.
이 값을 sense 전송의 client 인자로 전달한다.

executeRequest 반환은 EBX에 보존하지만 **성공 여부를 검사하지 않고** CLD/REP MOVSD와
MOVSW로 aligned buffer에서 사용자 제공 출력으로 26바이트를 복사한다.
그 후 IOFree(raw, allocatedSize)를 호출하고 보존한 결과를 반환한다.
aligned buffer의 자체 사전 초기화, allocation NULL 검사, 실제 수신량>=26 확인은 없다.
S를 지우는 bzero와 별도 데이터 buffer의 초기화는 다르다.
controller 실패/짧은 전송에서의 읽기 유효성·내용은 추가 검증 대상으로 남긴다.

## 기본 controller와 alignment 초기화

IOSCSIController 기본 executeRequest `0x1abf34`는 EAX=100으로 즉시 반환하며
자체 메모리 전송이나 S.actualLength 쓰기가 없다. 기본 getDMAAlignment `0x1ac050`은
출력 DWORD 네 개에 모두 1을 쓴다. 실제 장치가 이 기본 구현을 사용하는지,
subclass/module override가 무엇인지는 아직 미확정이다.

초기화 `0x1abaec`는 queue sentinel `+0x128/+0x12c`를 설정하고 self.class 결과에
deviceStyle 메시지를 보낸다. deviceStyle selector를 stack에 남겨 중첩 호출하는 원본을
Ghidra C는 class의 추가 인자와 selector 없는 두 번째 호출처럼 표현한다.
deviceStyle==0일 때 super initFromDeviceDescription이 0이면 0을 반환한다.
정상일 때 startIOThread 결과가 비영이면 self.free 후 0을 반환한다.
super의 비영 반환으로 self 레지스터를 교체하는 코드는 없다.

이후 원본 global `0x1e516c`로 setUnit, 증가, `sc%d` 이름 생성, setName/setDeviceKind를
호출한다. 자체 global 증가 lock이나 rollback은 없다.
getDMAAlignment 출력 네 DWORD의 **unsigned 최대값**을 self `+0x230`에 쓰며,
최대값이 1이면 0으로 정규화한다. 2의 거듭제곱 검사나 overflow 제한은 없다.

allocateBuffer 후보 `0x1ac1fc`는 P=`self+0x230`일 때 DWORD `n+2*P`를 IOMalloc에
요청한다. 실제 raw pointer와 총 할당량을 output에 먼저 쓰고, P<=1이면 raw를 반환한다.
P>1이면 DWORD `(raw+P-1)&(-P)`를 반환한다. 자체 NULL·overflow·power-of-two 검사는 없다.
실제로는 IOMalloc 뒤 `+0x230`을 다시 읽으므로, 위 두 식에서 같은 P를 쓰려면
호출 사이 값의 안정성도 필요하다. 이 함수 자체에는 그 필드를 보호하는 lock이 없다.
초기화와 base alignment가 그대로 쓰이는 경우 P=0이지만 동적 override에서는 별도 검증이 필요하다.
JSON의 유한 예시는 정상 mask 정렬과 비정상/overflow 입력을 구분하며 실제 발생을 주장하지 않는다.

## 진단 코드도 원본과 구분

logOpInfo는 명령 0/1을 Read/Write 문자열로, 2/3을 T의 opcode에 대한 이름 lookup으로,
4를 Eject 문자열로 표시한다. 그 밖에는 panic을 호출한다.
read/write에서 sense pointer가 있고 첫 BYTE의 sign bit가 설정되면 BYTE 3–6을 조합한
값을 출력하며, 아니면 R.block/count를 출력한다. 실제 sense 유효성 검증과 같지 않다.
doSdBuf의 초기 sense BYTE에서 sign bit를 지우는 작업과 이 진단 guard를 연결했다.

IOFindNameForValue `0x1a553c`는 value/name-pointer 쌍을 8바이트씩 읽고 name==NULL을
종료자로 쓴다. 못 찾으면 공유 주소 `0x1e8688`에 "%d(d) (UNDEFINED)"를 sprintf하고
그 주소를 반환한다. 자체 lock이나 caller별 buffer는 없다.
원본 status/sense/opcode 이름 table의 NUL 포함 최대 길이는 Python 결과 각각 32/30/24,
fallback signed DWORD 형식의 계산상 최대는 27바이트다. logOpInfo의 op 영역 40바이트와
비교할 수 있지만 sprintf/strcpy 구현·공유 fallback 동시 접근까지 검증한 것은 아니다.

## 판정

doSdBuf와 알려진 setup/sense/변환 후보의 지역 완료 흐름을 연결했다.
남은 핵심은 실제 controller receiver 및 override, DMA/VM buffer 계약, 명령·크기
제한과 오류 경로의 native 수명이다. 새 보고서의 검증 통과는 전체 kernel 분석 완료가 아니다.
