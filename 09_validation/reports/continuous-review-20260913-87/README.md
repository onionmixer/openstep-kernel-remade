# 87차 원본 분석 — disk class·반환 ABI·요청 제출

## 결과와 검증 경계

86차의 instance-method 후보를 원본 class 레코드와 연결하고, ObjC lookup/super,
논리 디스크의 주소·길이 변환, SCSI 요청 생성과 enqueue 호출까지 대조했다.
실제 객체 등록·동적 dispatch 및 비동기 완료는 아직 입증되지 않았다.

Python으로 14개 본문의 735개 instruction head, 1,978바이트를 원본과 대조했다.
직접 분기 83개, 직접 CALL 40개, 간접 전달 5개, Ghidra 경고 8개를 보존했다.
본문 바이트 합집합·명령 길이·직접 target을 검사하고 중요 operand 138개를 별도 확인했다.
이것은 모든 operand의 자동 의미 검증이나 native 실행 검증이 아니다.
class 레코드 6개, method list 8개/entry 124개, selector slot 15개,
selector 참조 288행, category window 2개, superclass slot 3개를 기록했다.
입력 49개와 기존 보존 파일 813개를 해시 대조했다. 수치는 전부 Python 결과다.

기계 판독 증거는 [object-lifetime-evidence.json](object-lifetime-evidence.json),
변경 경계는 [SCOPE.md](SCOPE.md), 잔여 항목은 [OPEN_ITEMS.md](OPEN_ITEMS.md)에 있다.
선행 연결은 [86차 보고서](../continuous-review-20260913-86/README.md)를 참조한다.
파일 검증 결과는 [checkpoint.json](checkpoint.json), 이전 파일의 보존 해시는
[preservation.json](preservation.json)에 기록한다.

## 정적 class 소유권과 runtime 경계

`0x1cd868`의 원본 명령은 class `+0x1c`의 method-list pointer,
list `+0`의 next, `+4`의 signed count, `+8`부터 시작하는 entry를 읽는다.
entry stride는 `0xc`, selector는 entry `+0`, IMP는 `+8`이다.
현재 list가 끝나면 next list로, 모든 list에서 실패하면 class `+4`로 이동한다.
이 원본 reader와 일치하는 file-backed 레코드만 아래에 연결했다.

| 원본 class 주소·이름 | 파일의 superclass 이름 | 이번 후보 IMP |
|---|---|---|
| `0x1fa0b4` IODevice | Object | errno `0x1a4a20` |
| `0x1fa104` IODisk | IODevice | blockSize `0x1a5724`, errno `0x1a5d60` |
| `0x1fa12c` IOLogicalDisk | IODisk | read `0x1a5e9c`, write `0x1a5f74` |
| `0x1fa154` IODiskPartition | IOLogicalDisk | read `0x1a6e64`, write `0x1a6f34` |
| `0x1fa244` IOBufDevice | IODirectDevice | errno `0x1a9568` |
| `0x1fa384` SCSIDisk | IODisk | read `0x1ac7fc`, write `0x1ac85c` |

이 목록은 원본 정적 metadata의 연결이다. IOBufDevice의 errno 후보를 디스크
receiver의 실제 메서드로 간주하지 않는다. 기록한 class window의 모든 DWORD에
외부 구조체 정의를 대입하지 않았다.

특히 class `+4`는 파일에서 **superclass 이름 문자열 주소**다.
super 호출부가 읽는 `0x1fa108`, `0x1fa158`, `0x1fa248`도 같은 필드다.
runtime lookup은 이를 class pointer로 읽으므로 초기화·fixup 근거 없이
파일의 문자열 주소를 실행 시 class 주소로 사용할 수 없다.

category 영역도 일괄 12바이트 entry로 해석하지 않았다.
`0x1f83fc`의 유효 list는 `_diskParamCommon:length:deviceOffset:bytesToMove:`
→ `0x1a6288`을 담고, `__category`의 `0x207790`이 이 list를 가리킨다.
직전 문자열은 `private`, `IOLogicalDisk`다.
`0x1f88f8`의 list에는 `deviceRwCommon:block:length:buffer:client:pending:actualLength:`
→ `0x1ad61c`, alloc/enqueue/free 후보가 있고, `0x2078d0`이 이를 가리킨다.
직전 문자열은 `Private`, `SCSIDisk`다. 이 bounded window는 category 등록 순서,
override 정책, 실제 메서드 선택을 증명하지 않는다.

## lookup 및 super ABI

`0x1cd868`은 최초 class가 `0x1d6728`이면 `0x1cd25c`를 반환한다.
그 밖에는 class `+0x10`의 bit 2가 설정되고 bit 4가 없을 때 name `+8`로
`objc_getClass(0x1ced1c)` 및 `0x1cd284`를 호출한 다음 list 탐색에 진입한다.
초기화 helper 자체와 재진입·실패 정책은 이번에 닫지 않았다.

메서드를 찾으면 `0x1cd76c(최초 class, entry)`를 호출하고 entry `+8`을 반환한다.
superclass에서 찾은 경우에도 cache helper의 class 인자는 최초 class다.
끝까지 없으면 allocator 경유로 `0xc`바이트 entry를 만들고 selector, 빈 type 문자열,
`0x1cebb0` IMP를 기록한 뒤 cache helper를 호출하고 그 forwarding IMP를 반환한다.
자체 allocation NULL 검사나 forwarding 완료 증거는 없다.
Ghidra C에서 allocator의 크기 인자가 앞선 호출에 붙어 보이는 부분은
`PUSH 0xc` 뒤의 zone 호출, `PUSH EAX`, 간접 CALL의 실제 stack 순서로 구분한다.

`objc_msgSendSuper(0x1cea70)`의 첫 인자는 `{receiver, 시작 class}`를 가리킨다.
cache hit/miss 모두 기존 첫 인자 stack slot을 receiver로 바꾸고,
임시 ESI/EDI를 복구한 뒤 **JMP EAX**로 IMP에 넘어간다.
selector와 나머지 인자를 보존하는 tail dispatch이며, Ghidra의 무인자 CALL/void
표현으로 대체할 수 없다. cache probing은 selector&mask와 순차 충돌 재탐색이다.
multithread mask가 0인 경로는 XCHG lock을 획득하며, hit/miss 모두 IMP 이전에
messageLock을 0으로 쓴다. 이 함수 안에는 일반 msgSend의 nil-return guard가 없다.
cache 초기화·포화 방지·lock의 전역 배타성·외부 helper 동작은 미확정이다.

## wrapper의 인자와 반환값

`blockSize(0x1a5724)`는 receiver `+0x10c` DWORD를 읽을 뿐이다.

IOLogicalDisk read는 매개변수 변환 selector를
`(self, selector, block, length, &deviceOffset, &bytesToMove)`로 호출한다.
결과 EAX가 0인 경우에만 receiver `self+0x184`로 변환된 offset/length와
원래 buffer/pending/client를 전달한다. 비영 결과는 그대로 반환하며,
하위 read 결과도 EAX 그대로 반환한다. Ghidra의 `void` 선언은 이 사실을 놓친다.
write는 먼저 `isWriteProtected` 결과의 **AL만** 검사하여 비영이면 `0xfffffd31`(-719)을
반환한다. 그 밖에는 같은 변환·전달 흐름이며 자체 pending 완료는 없다.
`self+0x184`의 비NULL·수명 보장도 자체 검사에서 얻을 수 없다.

IODiskPartition read/write는 receiver `+0x1a8` BYTE가 0이면 name과 원본
"no valid label" 로그 문자열을 사용하고 `0xfffffd3e`(-706)를 반환한다.
비영이면 receiver와 class `+4`에서 읽은 시작 class로 super 구조를 만들고
원래 인자를 그대로 전달한다. 이 flag의 writer·label 유효성 전체는 별도다.

SCSIDisk read/write wrapper는 아래 인자 순서로 공통 selector를 호출한다.
`(self, selector, read=0/write=1, block, length, buffer, client, pending, actualLength=0)`.
원래 pending과 client의 stack 위치를 새 selector의 순서에 맞춰 바꾸며, EAX는
호출 뒤 수정하지 않는다. 두 함수의 `void` 디컴파일 결과만으로 반환 계약을 정하면 안 된다.

## errno 변환 — 외부 errno 이름을 붙이지 않은 원본 값

IODevice `0x1a4a20`의 signed 비교 분기를 분할하면 다음과 같다.

| 입력 signed 값 | 반환 DWORD |
|---|---|
| 0 | 0 |
| -702, -701 | 12 |
| -704 | 6 |
| -718, -717, -716, -709, -708, -707, -705 | 13 |
| -706 | 22 |
| -711 | 45 |
| -719 | 30 |
| -725, -722 | 16 |
| 나머지 | 5 |

각 정수 변환과 반환 instruction 주소는 JSON에 보존했다. 이 본문 자체에서는
비영 입력을 0으로 변환하지 않는다. IODisk `0x1a5d60`은 -1102/-1100→6,
-1101→22를 추가하고 나머지는 super 호출이다. IOBufDevice `0x1a9568`은
-801→1, -800→58을 추가하고 나머지는 super 호출이다.
이 정적 표로 모든 동적 override가 비영 반환한다고 일반화하지 않는다.
86차 sdstrategy의 low-WORD 저장·flag 설정·biodone은 실제 선택된 errno IMP가
확정되어야 종단 간 연결된다.

## 논리 매개변수 변환 `0x1a6288`

먼저 self.name을 얻고 `[self+0x184]`에 `isDiskReady:(1)`을 보낸다.
-1102는 즉시 반환하고 다른 비영 값은 stringFromReturn 로그 뒤 그대로 반환한다.
0이면 self.blockSize를 L, self.diskSize를 S로 읽는다.

`length / L`의 unsigned DIV에서 나머지가 있으면 -706이다. 자체 L==0 검사는 없다.
요청 block K와 몫 N의 DWORD 덧셈 뒤 unsigned `S < wrapped(K+N)`일 때만
끝 범위를 조정한다. 그 조건에서 S<=K이면 -706, 아니면 N=S-K로 줄인다.
합의 carry 검사는 없다. 길이 0도 독립적으로 거부하지 않는다.

이어 L을 receiver `+0x18c`의 P로 unsigned DIV한다. 이 나눗셈은 나머지를 검사하지
않고 몫 Q를 사용한다. 출력은 DWORD 곱·합으로 `deviceOffset=K*Q+[self+0x188]`,
`bytesToMove=N*Q*P`다. 두 output store 뒤 EAX=0이다.
P==0, L이 P의 배수인지, 곱·합 overflow인지, output pointer 유효성은 자체 보장하지 않는다.

JSON의 유한 Python 예시는 정상 변환, 끝에서 길이 축소, 비정수 비율의 나머지 소실,
합의 wrap, 길이 0의 경계 조건을 구분한다. 예를 들어 L=768/P=512에서는
나머지 256을 버리는 원본 DIV가 있지만, 그러한 실제 device 설정이 허용된다는 뜻은 아니다.
상위 검사와 geometry writer가 확인되기 전에는 실행 중 결함으로 판정하지 않는다.

## SCSI 공통 제출 `0x1ad61c`

`isDiskReady:(1)` -1102는 즉시 반환, 다른 비영은 로그 후 보존한다.
0이면 `isFormatted`의 AL을 검사하여 0일 때 -1101을 반환한다.
blockSize로 length를 나눈 나머지가 있으면 **-1**이다. 논리 helper의 -706과 다르다.
L==0 검사는 자체에 없다. diskSize 끝 범위는 DWORD 합·unsigned 비교로 위와 같은
축소 형태이며 범위 밖이면 -706이다.

그 다음 `allocSdBuf:(pending)` 결과 R을 NULL 검사 없이 사용한다.
R `+0`에 read/write 값, `+4`에 block, `+8`에 조정한 block count,
`+0xc`에 buffer, `+0x10`에 client를 저장하고 BYTE `+0x20`에 bit 1을 OR한다.
이어 `enqueueSdBuf:(R)`를 호출하고 EAX를 ESI에 보존한다.

pending이 비영이면 바로 그 ESI를 반환하며 자체 actualLength store/free는 없다.
pending==0이면 enqueue 결과와 무관하게 R `+0x24`를 actualLength 출력 포인터에
저장하고 `freeSdBuf:(R)` 호출 후 보존한 enqueue 결과를 반환한다.
완료 대기·실제 I/O·pending 보관·수명 책임은 alloc/enqueue/free 내부의 증거가 필요하다.
특히 비동기 wrapper의 actualLength=0은 pending 비영 분기가 유지된다는 조건 아래에서만
이 함수의 출력 dereference를 피한다. 이 본문에 직접 biodone 호출은 없다.

로그 오류 분기에서 `stringFromReturn` 결과는 먼저 stack에 남고, 그 뒤 name 메시지가
실행된다. Ghidra C는 이를 name 메시지의 추가 인자처럼 표현하고 IOLog 인자를 누락한다.
원본 `0x1ad668` PUSH와 `0x1ad675`의 제한된 stack 복구, `0x1ad680` CALL 순서를
따라 로그 인자를 판단해야 한다.

## 판정

이번에는 정적 소유권·상속 이름과 실제 runtime pointer를 분리했고, wrapper의
반환 ABI 및 공통 제출 전의 원본 분기를 구체화했다. enqueue 후보 `0x1ad774`,
alloc `0x1ad828`, free `0x1ad880`과 이후 완료·buffer WORD/residual/biodone 연결은
다음 검토 대상이다. 등록·category fixup·장치 설정과 native 경합을 해결하지 않은 채
전역 안전성·동작 동등성·전체 분석 완료를 선언하지 않는다.
