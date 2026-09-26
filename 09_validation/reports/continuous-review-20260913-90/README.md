# 90차 — 원본 디스크 probe·controller 연결·전송 제한

OPENSTEP 원본 x86 커널의 장치 연결에서 raw I/O까지 이어지는 지역 경로를 확인했다.
다른 프로젝트 소스는 열거나 참고하지 않았다. 이번 결과는 **원본 분석의 진척**이며
전체 분석 완료, 실제 controller override 확정, 소스 복원 또는 native 안전성 검증이 아니다.

## 검증 범위

원본 SHA-256은 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`이다.
선택한 함수 17개, 명령어 1,160개, 본문 3,428바이트를 원본 파일에서 다시 decode했다.
직접 분기 99개·직접 호출 92개·간접 호출 1개, 중요 operand 검사 144개를 확인했다.
선택 C 출력의 명시적 WARNING 주석은 0개지만, 아래의 인자·반환·지역 변수 해석 문제는 남는다.
메서드 목록 6개/97개 항목, class/metaclass 4개, category 2개, protocol 1개,
selector slot 36개와 관련 참조 1,503행도 원본 근거로 보존했다.
계산·주소·해시·개수 산출은 Python만 사용했다.

[기계 판독 근거](object-lifetime-evidence.json), [검증 체크포인트](checkpoint.json),
[보존 해시](preservation.json), [범위와 방법](SCOPE.md), [미해결 항목](OPEN_ITEMS.md)을 함께 읽는다.
89차의 전송·완료 계약은 [직전 보고서](../continuous-review-20260913-89/README.md)에 있다.

## 1. controller 전달과 probe 순서

`0x1ac3d8`은 장치 설명 인자에 `directDevice`를 보내 얻은 결과를 controller로 사용한다.
`numberOfTargets`를 매 target 반복마다 재조회하고, 각 target에 lun 0–7을 시도한다.
기본 `numberOfTargets` IMP `0x1abf18`은 8을 반환한다. 실제 override/장치 수의 증거는 아니다.

재사용할 디스크가 없으면 SCSIDisk를 alloc하고 이름을 설정한 뒤 `initResources`를 호출한다.
그 다음 `_sd_idmap`의 `0x1e7324`와 전역 unit `0x1e5170`으로 `base + unit * 36`을 계산해
`setDevAndIdInfo:`에 넘긴다. 이 setter `0x1ac2e4`는 self `+0x118`에 포인터만 저장한다.
**표에 디스크 객체를 게시하는 동작은 이 setter 안에 없다.**
88차에서 확인한 worker 생성은 이 연결보다 먼저 수행된다. 실제 초기화 동기화는 별도 과제다.

`reserveTarget:lun:forOwner:`가 0이면 디스크 초기화에 unit·target·lun·controller를 전달한다.
초기화가 0이면 지역 성공 배열에 저장하고 전역 unit을 증가시킨다. 실패하면 예약을 해제하며,
초기화 결과 2에 대해서만 해당 target의 lun 반복을 중단한다. 예약 실패 시에도 미사용 디스크를
보관해 다음 시도에 재사용한다. 종료할 때 미사용 디스크가 남으면 free한다.

성공 디스크 각각에 self `+0x18a`의 마스크 `0x01`을 OR하고, kind 설정, `setIsPhysical:(1)`,
`registerDevice` 호출, 마스크 `0x02` OR 순서로 처리한다. **등록의 반환값을 검사하지 않는다.**
probe 반환은 등록 성공 수가 아니라 초기화 성공이 있었는지를 나타내는 0/1이다.
alloc 실패, 전역 unit 상한, unit 증가의 lock/rollback은 이 본문에서 확인되지 않는다.

target 반복의 비교는 BYTE를 MOVSX한 signed 값이지만 실제 명령 인자는 MOVZX한다.
고정된 반환 한계가 128 이상이라면 signed BYTE가 음수로 돌아가므로 정상적인 종료 상한이 되지 않는다.
기본값 8 경로와 구분해야 하며, 실제 override 값이나 실행 중 재현을 주장하지 않는다.
lun 반복이 정상적으로 유지되면 target당 성공 배열은 8개 포인터 범위 안이다.

## 2. SCSIDisk 초기화와 이름 생성

`0x1acbc8`은 검사 전에 controller DWORD를 self `+0x184`, target/lun BYTE를
`+0x188/+0x189`에 저장한다. getter `controller` (`0x1acbb8`)는 `+0x184`를 읽는다.
따라서 89차 executeRequest 수신자 필드까지 정적인 전달 연결은 확보했다.
장치 설명의 생성, 실제 directDevice IMP와 controller runtime class는 아직 확인하지 않았다.

이름 `sd%d`를 설정한 뒤 inquiry 영역 65바이트를 bzero하고 `sdInquiry:`를 호출한다.
그 반환값 1은 초기화 반환 2, 다른 비영 값은 3으로 바뀐다. 성공 반환 0인 경우에만
inquiry 첫 BYTE의 상위 `0xe0`이 0이고 하위 `0x1f`가 0/4/5/7인지 검사한다.
불허 값은 1을 반환한다. 이를 외부 프로토콜 구조체나 장치 종류 명세로 재해석하지 않았다.
다음 BYTE가 signed 음수이면 removable을 1로 설정하지만, 반대 경로에서 직접 0으로 지우지는 않는다.

필터 `0x1aceec(src,dst,count,capacity)`는 NUL을 건너뛰고 연속 공백을 합치며,
선두 공백 하나는 남긴다. NUL은 입력 종료가 아니며 이전 공백 상태를 초기화하지도 않는다.
출력에 NUL을 붙이지 않고 복사한 길이를 반환한다. count/capacity의 자체 검사는 0 여부뿐이다.

초기화는 inquiry offset 8/16/32에서 첫 번째로 8/16/4바이트, 두 번째로 8/16/32바이트를
필터에 준다. 두 번째 마지막 길이가 4가 아니라 32인 점을 원본 PUSH로 확인했다.
자체 공백 삽입과 NUL을 포함한 최대 출력은 각각 31/59바이트로, 정상적인 양의 입력 길이에서는
출력 용량 80바이트 이내다. 두 번째 입력의 마지막 exclusive offset은 64이다.

다만 필터 출력 길이가 0이어도 초기화는 `dst[-1]`을 읽어 공백 여부를 검사한다.
첫 pass는 출력 영역을 미리 지우지 않고, 둘째 pass의 80바이트 bzero도 그 앞 BYTE를 포함하지 않는다.
Ghidra의 `acStack_99 + 1` 배열 표현은 이 접근의 초기화 여부를 증명하지 못한다.
이는 원본의 선행 BYTE 읽기 사실이지, 곧바로 전체 스택 밖 접근이나 실행 중 결함의 확정은 아니다.

`Target %d LUN %d at %s`는 controller의 name 결과를 길이 인자 없는 sprintf에 준다.
인접 지역 영역까지 거리는 80바이트지만, controller name의 최대 길이는 확인되지 않았다.
`updateReadyState`, `scsiStartStop:(0) inhibitRetry:(1)`, `setFormattedInternal:(0)`,
`updatePhysicalParameters`의 반환값도 자체 성공 조건으로 사용하지 않는다.

끝에서는 먼저 push한 `init` selector를 스택에 남긴 채 `objc_getOrigClass("IODisk")`를 호출하고,
원래 객체와 반환 class를 묶어 `objc_msgSendSuper`에 전달한다. Ghidra가 selector를
getOrigClass의 추가 인자로 붙인 표현은 실제 호출 경계를 반영하지 못한다.
super 호출 결과를 EAX 0으로 덮어 반환한다. 그 init의 내부 필드 변경·실패·수명 계약은 아직 열려 있다.
초기화 실패 시 앞서 저장한 controller/target/lun/name을 자체 rollback하지 않는다.

## 3. IODisk 등록과 ID 조회 경계

`setIsPhysical:` (`0x1a57e8`)는 인자 low BYTE의 비영 여부를 self `+0x116` BYTE로 저장한다.
`registerDevice` (`0x1a5b58`)는 이 BYTE가 비영일 때에만 등록 본체를 실행한다.
이 setter와 registration IMP가 실제 선택되고 중간 변경이 없다면 probe의 인자 1이 이 분기를 만족한다.

등록 본체는 `+0x108`을 0으로, `+0x11c`를 새 NXLock 결과로 설정하고,
`+0x13c`부터 `+0x170`까지 14 DWORD를 0으로 만든 뒤 super 등록을 호출한다.
super 결과가 비영일 때 class의 `IOPhysicalDiskMethods` 적합 여부를 AL로 확인한다.
불일치 시 경고만 남기며 여전히 super 결과를 반환한다. 일치하면 self `+0x118`의 행에서
WORD `+0x22`, WORD `+0x20`을 각각 sign-extend해 `volCheckRegister(self,row22,row20)`를 호출한다.
이 호출의 결과는 무시한다. 이 본문 역시 행의 디스크 포인터를 직접 게시하지 않는다.

physical BYTE가 0인 입구 분기는 초기화되지 않은 지역값 대신 **입구 ESI를 EAX로 복사해 반환**한다.
Ghidra의 `unaff_ESI`는 이 명령 흐름과 일치한다. probe의 정상 setter 경로와 분리해서 다뤄야 한다.
새 lock의 실패 처리·super 등록 실패 후 cleanup도 이 본문에서 확인되지 않았다.

일반 조회 `0x1840ec`은 unit 0–15만 허용한다. part 0–6은 행 `+4+part*4`,
part 7은 major와 전역 `0x1e7564`가 다를 때만 행 첫 DWORD를 반환한다.
반면 물리 조회 `0x18414c`의 경계는 `CMP 0x10; JG`로, unit 16을 허용한다.
Python 주소 계산상 이 행 첫 DWORD는 정확히 `0x1e7564`이다.
이 차이는 인접 전역 주소 읽기의 근거이지 표의 실제 할당 크기나 runtime 값의 증명이 아니다.
sdread/sdwrite는 물리 조회를 먼저 호출하지만, 뒤에서 일반 조회 NULL을 검사해 실패 반환하므로
unit 16만으로 그 값을 controller 메시지 수신자로 쓰는 경로가 성립한다고 단정할 수 없다.

## 4. 전송 제한의 출처와 physio 소비

`sdopen`은 일반 조회와 isDiskReady 검사를 통과하면 전역 `0x1e756c`를 확인한다.
0일 때에만 이름 `sc0`을 `IOGetObjectForDeviceName`으로 찾고 그 객체의 `maxTransfer`를 캐시한다.
현재 열린 디스크의 controller를 조회하는 코드가 아니다. 캐시 값이 계속 0이면 다음 open도 재조회한다.
조회 오류에는 IOPanic을 호출하지만 반환 이후의 안전성은 IOPanic의 non-return 계약에 의존한다.
기본 maxTransfer IMP `0x1ac044`의 상수는 16,777,216바이트(16 MiB)다.
실제 sc0 override, 다른 controller와의 공통 한계, 전역 초기화와 동시 접근은 미확정이다.

제한 함수 `0x1840d0`은 unsigned 비교로 B `+0x14`를 캐시 값 이하로 줄인다.
양수·block 배수·최소 길이 검사는 없다. sdread/sdwrite는 이 함수 포인터와 `_sdstrategy`,
단위별 B 포인터, 읽기/쓰기 값 1/0, uio, blockSize를 `_physio` (`0x11eb50`)에 넘긴다.

physio는 현재 vector 길이를 B `+0x14`에 저장하고 제한 함수를 간접 호출한 뒤
**콜백 반환값이 아닌 B 필드를 다시 읽는다.** offset/blockSize를 unsigned DIV하여 B block을 만든다.
blockSize 0 검사나 offset의 나머지 검사는 이 본문에 없다. segment 값 1이면 flag `0x4000000`을 OR하고,
아니면 useracc/vslock/vsunlock 경로를 쓴다. 이어 physstrat에 제출한다.

완료 뒤 `chunk - B.residual`을 DWORD로 계산해 B data와 uio offset을 늘리고,
vector 길이와 uio residual을 줄인다. 그 뒤 B residual/error를 검사한다.
별도 residual 범위 검사는 없다. vector가 끝나고 오류가 없으면 uio의 vector 포인터를 8바이트
전진시키고 vector count를 감소시킨다. primitive 잠금, physstrat의 실제 완료 계약은 여기서 닫지 않았다.
캐시 0·residual 0·오류 없음이 유지되는 조건이면 양의 vector에서 진척이 없을 수 있지만,
이는 조건부 제어 흐름 지적이며 실제 controller 동작의 재현은 아니다.

89차 CDB count는 WORD였다. 캐시가 기본값이고 blockSize 512라고 가정하면 최대 32,768 blocks로
WORD 안에 들지만, blockSize 256이면 65,536 blocks의 low WORD는 0이 된다.
가정 blockSize 1000에서는 byte clamp 후 나머지가 216이다. 따라서 바이트 상한이 존재한다는
사실만으로 모든 geometry/모든 진입 경로의 CDB count와 길이 일치를 증명할 수 없다.

## 5. 정렬 임시 버퍼 경로 — 새로 연결한 미해결 계약

sdread/sdwrite는 물리 조회 객체에 `controller`, 그 결과에 `getDMAAlignment:`를 순서대로 보낸다.
Ghidra는 아래쪽 스택에 미리 놓은 selector/인자를 앞 호출에 합치므로 원본 PUSH/CALL로 구분했다.
16바이트 alignment 응답에서 읽기는 offset 0/8, 쓰기는 offset 4/12를 주소/길이 검사에 사용한다.
강제 page 정렬 옵션은 읽기 offset 0, 쓰기 offset 4를 page-size 전역으로 덮는다.
각 값이 1보다 클 때 `value-1` mask를 검사한다. power-of-two 보장과 reply 초기화는 별도 전제다.

정렬이 맞지 않으면 **첫 vector 길이**만큼 controller의 allocator를 호출해 첫 vector base를
반환 포인터로 바꾸고 segment 값을 1로 사용한다. 자체 alloc NULL 검사와 uio vector-count==1
검사는 없다. 다른 vector까지 같은 segment 값으로 처리해도 되는지는 상위 호출자 계약이 필요하다.

- 읽기: physio 반환값을 보존한 뒤, 정렬 버퍼를 썼으면 성공/부분 성공/실패 구분 없이
  저장해 둔 첫 vector의 원래 전체 길이를 원래 목적지에 bcopy 또는 copyout한다.
  copyout 반환값은 무시하고 raw allocation을 IOFree한 후 physio 결과를 반환한다.
- 쓰기: 첫 vector 전체 길이를 bcopy 또는 copyin한 뒤 physio를 호출한다.
  copyin 반환값은 자체 검사하지 않는다. physio 뒤 raw allocation을 IOFree한다.
- 두 경로 모두 이 본문에서 원래 vector base나 변경된 segment 값을 복원하지 않는다.
  사용 후 uio/iovec를 다시 읽는지, 임시 버퍼의 어떤 바이트가 유효한지, 실제 에러 전파가 어떤지는 미확정이다.

이 항목은 외부 구현으로 메우지 않는다. 모든 호출자에 단일 vector가 보장되는지,
짧은 전송과 copy fault의 실제 경로, allocation/physstrat 수명부터 원본에서 후속 확인한다.

## 판정

원본·기존 분석 자료·이전 보고서 831개 보존 항목과 현재 입력 58개를 해시로 재검사했다.
Ghidra 스킬의 함수 본문·참조 대조 절차가 호출 인자와 반환 해석의 검증 방법을 정했으며,
live DB 수정, 새 Python 파일, 에뮬레이터, 독립 검토 재요청, 동적 실행은 하지 않았다.
독립 계획 교차검토는 이번 차수에도 미수신이며 통과로 표시하지 않는다.
전체 원본 분석 목표는 여전히 미완료다.
