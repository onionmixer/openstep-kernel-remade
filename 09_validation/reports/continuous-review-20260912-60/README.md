# IPC 요청 취소·최종 파괴·알림 권한의 원본 계약

## 결과와 근거 범위

dead-name 요청 슬롯 취소, message-accepted 요청 생성/취소/파괴, space/object 참조 해제와 알림 실패 시 권한 해제를 원본 본문으로 연결했다. **취소와 파괴는 다르며, 실패가 항상 무변경을 뜻하지도 않는다.** 특히 marequest 취소는 요청을 해시에서 분리하고 이름만 0으로 바꾸며, 보유 참조와 요청 allocation의 최종 처리는 destroy가 담당한다.

[원본 증거](request-evidence.json)에 본문 12개/명령어 643개/1631바이트와 관련 window 3개/48개 명령어를 보존했다. Python에서 원본 Mach-O mapping, 보존 decoder 읽기·명령 길이, Ghidra 본문 byte 범위와 직접 분기 목적지를 대조했다. 입력 fingerprint 59개와 이전 산출물 672개의 해시를 확인했다. 원본 SHA-256은 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`이다.

Ghidra 스킬을 보존 ASM/C의 읽기 전용 검토에 적용했다. 모든 계산은 Python으로 수행했다. 신규 독립 계획 검토 미확보 상태를 유지하며 새 검증 프로그램·동적 실행·DB/원본/`07_kernel` 수정·GCC 2.7 실빌드는 하지 않았다. 본문을 읽고 바이트를 대조한 사실을 최종 전달·전체 allocator·동시성의 검증으로 확대하지 않는다.

## dead-name 요청 슬롯 취소

`_ipc_port_dncancel` (`0x14c650`)는 `(port,name,index)` 중 **name 인자를 본문에서 읽지 않는다**. port+0x2c의 요청 table을 가져와 `table + index*8`의 첫 DWORD를 반환용으로 저장한다. 슬롯+4 name=0, 슬롯 첫 DWORD=기존 free-list head, table 첫 DWORD=index 순으로 free list에 돌려놓는다.

이 함수에는 lock 획득/해제, port active, index 범위, table null, 슬롯 name 일치의 runtime 검사가 없다. 참고 Darwin 소스의 assert는 원본 검사라는 증거가 아니다. 호출자가 port locked/active와 유효 슬롯을 보장해야 한다.

반환하는 것은 취소 슬롯에 저장되어 있던 word이며, 여기서 그 권한의 ref를 감소시키거나 알림을 보내지 않는다. 일반 요청에서는 send-once 권한을 caller로 돌려주지만, [보고서 57](../continuous-review-20260912-57/README.md)의 compat 요청에는 tagged space 값이 저장되는 경로가 있으므로 모든 반환 word를 보통 port pointer로 취급하면 안 된다. [보고서 59](../continuous-review-20260912-59/README.md)의 compat 처리에서 space_release를 하고 일반 알림 대상을 0으로 바꾸는 순서와 연결된다. 이 태그/요청 전체 생성·성장·소멸 경로의 전수 검증은 아직 남는다.

## 참조 해제와 알림용 권한 획득

`_ipc_space_release` (`0x1506d8`)는 **space+0의 ref lock**으로 space+4 ref를 감소시킨다. namespace에 사용하는 space+8 lock과 다르다. 감소 결과를 저장하고 ref lock을 풀고, 저장한 감소 결과가 0이면 ipc_space_zone으로 zfree한다. 이 함수 자체가 space를 비활성화하거나 table/tree를 파괴하는 것은 아니다.

`_ipc_object_release` (`0x14b86c`)도 object+0 lock, object+4 ref 감소, unlock, 마지막 ref일 때 zfree 순이다. zone index는 object+0xa word & `0x7fff`로 선택하며 그 읽기는 unlock 뒤이다. active 여부나 zone index 유효 범위를 여기서 검사하지 않는다. generic object release를 send 권한 수 감소나 receive 파괴와 같은 동작으로 보아서는 안 된다.

두 함수 모두 ref가 양수인지 runtime 검사하지 않는다. Python 산술상 0에서 감소하면 DWORD 최대값으로 wrap되어 free 분기로 가지 않는다. 이것은 precondition 필요성의 산술 확인이며 실제 ref 0 호출이 관측되었다는 뜻이 아니다.

`_ipc_port_copy_send` (`0x14cfa4`)는 0과 `0xffffffff` 입력을 그대로 반환한다. 그 외 port를 lock한 뒤 active이면 refs와 srights를 증가시켜 같은 port를 반환하고, inactive이면 ref 변화 없이 `0xffffffff`를 반환한다. 어느 분기든 획득한 port lock은 푼다. 기존 port의 ref를 소비하는 함수가 아니며, 현재 srights>0 여부는 본문에서 추가 확인하지 않는다.

`_ipc_port_lookup_notify` (`0x14cf28`)는 caller가 space를 locked/active로 유지한다는 전제에서 entry lookup을 하고 RECEIVE bit가 있어야 성공한다. port lock 아래 refs와 **sorights**를 증가시킨 뒤 unlock하고 port를 반환한다. entry가 없거나 RECEIVE가 없으면 0이다. mscount/srights는 증가시키지 않는다. active 및 receiver/name의 일치 assert는 원본 runtime 비교가 아니므로 receive-entry 불변조건을 별도 확인해야 한다.

## message-accepted 요청의 생성

`_ipc_marequest_create` (`0x14a1ac`)의 원본 인자는 `(space,port,notify_name,marequestp)`다. 먼저 zone에서 요청을 할당한다. 실패하면 `0x1000000e`(NO_NOTIFY), space가 dead이면 새 요청을 해제하고 `0x1000000b`(INVALID_NOTIFY)이다. 출력 포인터는 성공하기 전에는 쓰지 않는다.

space lock을 잡고 `ipc_right_reverse(space,port,&name,&entry)`를 호출한다. 성공하면 callee에서 받은 port lock을 즉시 풀고 entry의 MAREQUEST bit를 검사한다. 이미 설정되어 있으면 space unlock과 새 요청 zfree 후 `0x10000006`(NOTIFY_IN_PROGRESS)이다. 이 순서는 notify 권한을 새로 만들기 전이다.

notify_name이 비제로이면 lookup_notify로 send-once 권한을 얻고, 실패 시 space unlock/새 요청 해제를 한다. notify_name=0은 soright=0인 compat 경로이다. reverse가 성공한 경우 entry MAREQUEST bit 설정→space_reference→요청의 space/name/soright 저장→bucket lock 아래 head 삽입 순이다. reverse가 실패한 경우에도 요청 생성은 성공할 수 있으며 space_reference와 space/name=0/soright 저장만 하고 bucket에 넣지 않는다. 이 경로에서는 next 필드를 초기화하지 않지만, 이후 name=0인 destroy 경로는 next를 읽지 않는다. 이를 모든 소비자가 안전하다는 전수 증명으로 확대하지 않는다.

공통 성공은 space unlock 후 marequestp에 요청 포인터 저장, 0 반환이다. 요청은 space 참조 및 비제로 soright를 보유하며, caller가 요청의 최종 수명을 책임진다. reverse 자체와 모든 생성 caller는 이번 단계에서 새로 전수 검증한 범위가 아니다.

## 취소와 최종 파괴의 연결

요청 필드는 space+0, name+4, soright+8, next+0xc이며 hash bucket stride는 8바이트다. 생성/취소/파괴는 같은 hash 식 `((space >> 4) + (name >> 8) + (name & 0xff)) & mask`를 DWORD 연산으로 사용한다. 실제 table 초기화 및 mask 값의 모든 실행 상태는 미검증이다.

`_ipc_marequest_cancel` (`0x14a360`)는 caller의 space lock을 전제로 bucket만 lock한다. space/name이 맞는 노드를 찾고 이전 link를 next로 바꾼 뒤 bucket unlock, 요청 name=0 저장 순이다. 요청을 zfree하지 않고 space/soright ref도 해제하지 않는다. entry MAREQUEST bit를 여기서 지우지도 않는다. caller의 entry 제거/변환과 연결해야 한다.

원본은 탐색 실패로 node가 null이어도 `0x14a3bf`에서 node+0xc를 읽는다. 따라서 “못 찾으면 조용히 반환하는 취소 API”가 아니다. Ghidra C와 참고 소스의 assert를 근거로 안전한 not-found 처리라고 복원하면 안 된다. 항목 존재와 caller 직렬화의 불변조건이 필요하다. Ghidra의 int 반환은 마지막 unlock XCHG의 incidental EAX로, 의미 있는 성공/실패 코드가 아니다. 참고 선언은 void다.

`_ipc_marequest_destroy` (`0x14a49c`)는 요청의 space를 lock한 뒤 name과 soright를 읽는다.

| 상태 | destroy의 처리 |
| --- | --- |
| name=0 | bucket/entry 정리를 건너뛴다. 취소 또는 reverse 실패로 생성된 요청의 경로다. |
| name≠0, space active | bucket에서 space/name으로 찾아 제거하고 entry lookup 후 MAREQUEST bit를 지운다. soright=0이면 space+0x44 notify port의 send 권한을 복사한다. |
| name≠0, space dead | bucket에서는 제거하지만 entry lookup은 하지 않고 알림에 사용할 name을 0으로 둔다. |

그 후 space unlock→space_release→요청 zfree→저장한 값으로 알림 처리 순이다. soright가 비제로이면 일반 msg_accepted를 호출하며 name=0이어도 호출한다. soright=0인 compat는 복사한 notify가 0/`0xffffffff`가 아닐 때만 알린다. 따라서 취소된 일반 요청은 name=0 알림 경로가 남지만, 취소된 compat 요청은 이 destroy에서 notify 복사를 하지 않아 compat 알림을 보내지 않는다.

destroy의 bucket 탐색에도 not-found 복구가 없다. 또한 같은 space/name으로 찾은 노드가 전달된 요청과 같은지 runtime 비교하지 않으며, entry lookup 반환값도 null 확인 없이 bit를 지운다. 참고 소스에는 그 불변조건에 대한 assert가 있지만 원본 검사는 아니다. 같은 key의 중복·rename·최종 호출 횟수의 전수 검증이 남는다.

kmsg 관련 원본 window도 대조했다. `_ipc_kmsg_clean`은 kmsg+0xc가 비제로이면 destroy를 호출하고, 확인한 window에서는 슬롯을 0으로 만들지 않는다. `_ipc_mqueue_receive`는 queue unlock 이후 요청을 destroy하고 **kmsg+0xc=0을 저장**한다. 일반 clean을 임의 반복 호출해도 안전한 idempotent 정리로 취급할 근거는 없다. window는 이 연결만 입증하며 clean 전체나 queue 전체 동작의 새 검증은 아니다.

## 알림 wire 형태와 allocation 실패

원본 일반 `_ipc_notify_msg_accepted` (`0x14b464`)와 compat (`0x14b73c`)는 모두 kalloc 52바이트, kmsg+8=52, +0xc=0, +0x10=0 후 `0x1f6290` template의 32바이트를 kmsg+0x14로 복사한다. REP MOVSD 앞의 CLD를 확인했다. 목적지 port는 kmsg+0x1c, 알릴 name은 +0x30에 저장한다.

template는 런타임 초기화 대상이다. `_ipc_notify_init`의 관련 store window로 도출한 값은 다음과 같다. 실제 부팅에서 initializer가 실행되었다거나 이 값이 현재 메모리에 있다는 관측은 아니다.

| 필드 | initializer 이후 값 |
| --- | --- |
| bits / size | `0x12` / 32 |
| remote / local | 0 / 0 |
| type·reserved 필드 / message id | 1 / `0x42` (66) |
| name descriptor / payload | `0x1001200f` / 0 |

descriptor 상위 word의 AND/OR 정리는 Python으로 전체 word 입력 범위를 계산했으며 결과는 `0x1001`로 고정된다. 일반 알림은 template의 SEND_ONCE bits `0x12`를 유지한다. compat는 동일 template를 복사한 뒤 bits를 SEND `0x11`로 덮어쓴다. 둘 다 `ipc_mqueue_send(kmsg,0x10000,0,0)`을 호출하며 반환값을 검사하지 않는다. 성공적으로 전달되거나 최종 소비되는지는 queue 구현과 runtime 상태의 별도 계약이다.

allocation 실패는 로그 후 일반 알림이 `ipc_port_release_sonce`, compat가 `ipc_port_release_send`를 호출한다. 해당 release 본문도 이번에 확인했다.

- release_sonce (`0x14d108`): port refs 감소 후 active이면 sorights 감소/port unlock. inactive이면 unlock 후 감소 ref가 0일 때 zone free. active 경로에는 마지막 ref free가 따로 없다.
- release_send (`0x14d050`): port refs 감소 후 inactive이면 위와 같은 마지막 ref free. active이면 srights 감소, 마지막 sender이고 nsrequest가 있으면 이를 분리하고 mscount 저장, port unlock 후 no_senders 호출.

이 함수들은 null/dead sentinel이나 ref/right 수 양수 여부를 자체 검사하지 않는다. Ghidra의 int 반환은 경로별 incidental 값이고 참고 선언은 void이며, 알림 caller도 이를 상태로 쓰지 않는다. active receive의 수명, 최종 zero ref, no_senders 연쇄 및 zfree 내부는 남은 검증이다.

## 참고 소스와 원본의 명확한 차이

Darwin `ipc_marequest_destroy`는 compat 처리 이후 일반 soright 경로에서 **panic**한다. 원본 `0x14a5ad`는 `_ipc_notify_msg_accepted`를 호출한다. 따라서 이 참고 함수를 그대로 가져오면 정상 동작 범위가 달라진다.

Darwin compat 알림은 별도 compat template 및 sender 필드를 사용하지만 원본은 위의 공통 template+bits overwrite와 원본 kmsg layout을 사용한다. 참조 소스의 이름·주석·구조체만으로 원본 ABI나 알림 형식을 대신하지 않는다. 현재 source fingerprint를 보존했으며 정확한 원본 빌드 provenance는 미확정이다.

## 락과 남은 검증

이번 본문에서도 register-only TEST/JNZ spin 패턴 11곳을 원본으로 대조했다. [보고서 59](../continuous-review-20260912-59/README.md)의 경합 진행성 제한이 그대로 적용된다. “lock을 통과한 뒤의 순서”를 실제 경쟁 상태의 정상 완료로 판정하지 않는다.

[미완료 항목](OPEN_ITEMS.md)을 유지한다. 특히 요청 rename/생성 caller/최종 호출 수, entry/hash 소멸, pset/mqueue wakeup, queue 전달과 알림 연쇄는 계속 분석해야 한다. 전체 의미 분석이나 GCC 2.7 실빌드·부팅 완료가 아니다.
