# IPC space 수명과 dead-space 권한 정리

## 검토 결과와 범위

space 생성의 기본 free-list/ref 초기화와 파괴 시 active/growing 대기·권한 정리·최종 ref 반환을 연결했다. 정상 space와 special space는 초기화 범위가 다르다. dead-space cleanup은 entry/node 메모리 해제나 reverse hash 제거를 대신하지 않으며 caller가 그 순서를 책임진다. `ipc_right_clean`의 Ghidra regparm 인자와 정수 반환은 원본 ABI로 채택할 수 없다.

원본은 OPENSTEP x86 mk-183.34.4, SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`이다. Ghidra 스킬을 보존 export의 읽기 전용 대조에 적용했다. 계산·해시·범위/주소 매핑·집계는 모두 Python으로 수행했다. [정적 증거](space-lifecycle-evidence.json)에 원본 바이트, Ghidra listing, 독립 decoding, 분기/call, stack-slot 및 register-only wait를 기록했다.

| 함수 | 주소 | instruction heads | body bytes |
| --- | --- | ---: | ---: |
| space_create | `0x15071c` | 80 | 248 |
| space_create_special | `0x15081c` | 21 | 68 |
| space_destroy | `0x150860` | 169 | 421 |
| right_clean | `0x14df98` | 147 | 434 |
| pset_destroy | `0x14da98` | 42 | 110 |
| port_release_receive | `0x14d168` | 25 | 57 |
| ipc_bootstrap | `0x146dc0` | 84 | 277 |
| ipc_init | `0x146ed8` | 30 | 93 |

Python 집계: 8개 본문, 598개 명령어, 1708 bytes, 직접 branch 67개, CALL 49개. caller window 2개에 명령어 19개를 추가 대조했다. 입력 fingerprint 38개와 이전 파일 702개를 확인했다. 경고 3개는 right_clean/ipc_init의 panic non-return과 bootstrap의 겹치는 전역 심볼 주석이다. 이를 함수 의미나 ABI 정확성의 자동 판정으로 사용하지 않는다.

참고는 보존 Darwin `ipc_space.c/.h`, `ipc_right.c`, `ipc_init.c`, `ipc_pset.c`, `ipc_port.c`이다. 원본 offset/동작과 소스 계약을 구분했으며 동일 빌드 소스·컴파일 옵션이 증명된 것은 아니다. 원본 및 기존 증거는 변경하지 않았다.

## bootstrap과 일반 생성의 입력

ipc_bootstrap은 port 다중 접근 lock, timestamp lock/data를 초기화한 뒤 space/tree-entry/port/pset zone을 만든다. 원본 zinit 인자에서 element size는 각각 `0x48/0x20/0x50/0x1c`이며 Python 계산값은 72/32/80/28 bytes이다. 최대 byte 크기는 각 전역 max와 element size의 곱으로 계산한다. 그 뒤 각 zone에 `zchange(zone,0,0,1,0)`을 호출한다. 전역 object_zones의 port와 pset slot은 각각 `0x1f6230`, `0x1f6234`에 저장된다. Ghidra의 전역 overlap 경고를 두 독립 object가 아니라 이 배열 slot 관계와 대조했다.

`0x146eae`, `0x146eb8`에서 kernel/reply special space를 만들고, table_init → notify_init → hash_init → marequest_init 순으로 호출한다. special-space 생성의 실패값을 검사하는 branch는 원본에 없다. 참조 소스에는 성공 assert가 있다. zone 실패나 부팅 완료를 이 caller만으로 보장하지 않는다.

`ipc_task_init`의 보존 window는 `0x1593f7`에서 global ipc_table_entries를 읽어 `0x1593fe`에서 space_create에 첫 descriptor 포인터로 전달한다. 실패는 panic이다. [보고서 64](../continuous-review-20260912-64/README.md)의 기본 초기화 조건이면 그 descriptor의 size는 4이다. 이 결합은 기본 생성 경로의 양의 초기 크기를 뒷받침하지만 모든 caller/변경된 전역에 대한 보장은 아니다.

setup_main의 `0x15c89b` IPC bootstrap 호출은 같은 직선 window의 `0x15c8c0` ipc_init 호출보다 앞선다. 사이에는 다른 subsystem 초기화 호출이 있다. 그 호출들의 정상 반환 및 앞선 page-size 설정까지 이어지는 native 부팅 검증은 미완료이다.

## 일반 space_create

인자는 `(initial_descriptor, spacep)`이다. space zone zalloc 실패는 6, table_alloc(initial.size*16) 실패는 준비 space만 zfree하고 6을 반환한다. 실패 경로에서는 spacep를 쓰지 않는다. 성공 경로는 table 전체를 bzero하고 모든 entry.bits에 `0xff000000`, next에 index+1을 저장한 뒤 마지막 next를 0으로 만든다. type/object/request의 실제 권한은 아직 없다.

table[0]은 free-list head 역할이고 일반 권한으로 할당되지 않는다. 기본 size=4의 조건부 산술에서 next는 `0→1→2→3→0`, object/hash는 0이고 첫 get은 index 1의 generation wrap을 통해 이름 `0x100`을 만든다. 이는 실제 runtime dump가 아니라 원본 초기화와 get의 산술 결합이다. initial size가 0인지 확인하는 branch는 없으며 마지막 next 저장은 `table + size*16 - 8`이다. caller가 유효한 양의 크기 descriptor를 넘겨야 한다.

space에는 ref lock=0, refs=2, namespace lock=0, active=1, growing=0, table/size, next descriptor=`initial+1`을 저장한다. refs=2는 참고 소스에서 caller reference와 active reference로 설명된다. tree_init은 tree.root만 비우며, tree_total/small/hash와 notify는 별도로 0을 저장한다. space 구조체 전체를 zeroing한 것은 아니다. 모든 필드를 완성한 뒤 `0x15080b`에서 spacep에 포인터를 쓴다.

원본에서는 notify를 0으로 만들지만 자동으로 notify port를 생성하지 않는다. 참조 소스의 `!NeXT` 조건부 port 생성과 실패 복구 경로를 원본 기능으로 추가해서는 안 된다. allocator 또는 descriptor의 수명이 보장된다는 전제도 전체 호출 경로에서 확인해야 한다.

## special space는 빈 일반 space가 아니다

space_create_special은 zone에서 space를 얻고 ref lock=0, refs=1, namespace lock=0, active=0만 저장한다. table/size/growing/tree/notify를 초기화하거나 table을 할당하지 않는다. 실패는 6이며 출력은 유지, 성공은 spacep를 쓰고 0이다.

참조 소스는 special space를 naked receive right의 소유 위치를 나타내는 placeholder로 설명한다. 일반 active namespace처럼 table을 순회할 수 없고, destroy는 이미 inactive인 경로에서 반환하므로 special space의 ref를 자동 소비하지 않는다. 별도의 참조 수명 계약이 필요하다. 미초기화 필드들이 우연히 0일 것이라는 allocator 가정은 하지 않는다.

## space_destroy: inactive 전환과 growing 대기

namespace lock을 잡고 기존 active를 읽은 뒤 `0x150887`에서 active=0을 저장한다. unlock 후 이전 active가 0이면 즉시 반환하며 active ref도 줄이지 않는다. 유효하게 살아 있는 space에 대한 inactive 확인 경로이지, 이미 free된 포인터에 반복 destroy가 안전하다는 뜻은 아니다.

이전 active가 있으면 namespace lock을 다시 잡고 growing을 검사한다. growing 동안 assert_wait(space,0) → unlock → thread_block_with_continuation(NULL) → relock → growing 재검사를 반복한다. growing=0이면 unlock하고 나서 table/size를 읽는다. 정상 초기화/유효 포인터와 lock 획득·helper 반환을 전제로, active를 내린 뒤 진행 중인 table 확장이 끝나기를 기다리는 구조이다.

[보고서 63](../continuous-review-20260912-63/README.md)의 grow_table은 확보 후 relock하여 growing=0으로 만들고, inactive이면 새 table을 버리고 wakeup한다. destroy는 그 상태 변경을 기다린 후 기존 table을 정리한다. 해당 caller/callee 순서의 정적 연결을 확인한 것이며 lost wakeup·동시 grow/destroy의 native 실행과 scheduler 계약까지 증명한 것은 아니다.

현재 선정 본문에서 register-only spin 8개를 확인했다. load 주소는 `0x150870`, `0x1508a0`, `0x1508dc`, `0x1509c8`, `0x14dffc`, `0x14e030`, `0x14daac`, `0x14d170`이다. 안쪽 `75fc`는 MOV가 아니라 TEST로 돌아가므로 메모리를 다시 읽지 않는다. 따라서 Ghidra의 메모리 재읽기 while을 그대로 진행성 모델로 채택하지 않는다. 실제 hang 관찰이나 전역 경합 안전성 검증은 아니다.

## table·tree 정리와 마지막 active ref

namespace가 dead이고 growing이 끝난 뒤 정리는 namespace unlock 상태로 수행된다. table은 index 순으로 type!=NONE인 entry만 right_clean(space, reconstructed_name, entry)한다. 이름은 index 부분과 bits의 generation byte를 합친다. table free 크기는 저장된 space.size를 직접 쓰지 않고 `(space.next-1)->size << 4`에서 가져온다. 이 descriptor와 table size의 일치가 필요하다.

`0x150950`에서 table을 free한 뒤 tree traversal을 시작한다. tree node가 pure SEND type이면 `0x150980`에서 global reverse hash를 먼저 제거한다. 그 뒤 `0x15098b`에서 right_clean을 호출하고 `0x150999`의 traverse_next(tree,1)로 node 자체를 해제한다. full traversal이 0을 반환하면 finish를 호출한다. 정상 경로에는 중간 break가 없다. 이 순서는 권한 정리 후 object 참조가 사라질 수 있으므로 global hash 제거에서 object를 먼저 사용하는 계약과 맞는다.

table의 local hash를 entry마다 제거하지는 않는다. table 전체가 폐기되기 때문이다. tree_total/small을 모두 0으로 보정하거나 table/notify 포인터를 NULL로 만드는 저장도 없다. dead-space 접근 배제와 남은 ref의 역할이 필요하다.

notify가 0 또는 -1이 아니면 release_send한다. 마지막에는 namespace lock이 아닌 space ref lock(`+0`)으로 refs를 줄이고 unlock한다. 새 ref가 0일 때만 space zone에 zfree한다. 초기 refs=2에 다른 참조 변화가 없는 조건이면 active ref를 내려 1이 남는다는 Python 산술 결과다. compat request 등 별도 ref 변화가 있을 수 있으므로 실행 전체의 ref 수를 이 예로 단정하지 않는다.

## right_clean의 ABI와 entry 소유권

Ghidra C는 `int __regparm1 ...` 형태에 추가 register 인자를 붙였지만 원본 caller `0x150928`, `0x15098b`는 `(space,name,entry)`를 stack에 push한다. 원본은 EBP `+8/+0xc/+0x10`의 stack slot을 사용한다. Python operand 검사와 전체 본문·caller 수동 대조를 함께 수행했다.

DEAD_NAME 경로는 EAX를 정의하지 않고 반환하므로 incidental incoming EAX가 남는다. 다른 경로에는 XCHG/하위 callee의 EAX가 남을 수 있다. 이를 status나 추가 입력 계약으로 해석하지 않는다. 참조 소스의 void 함수와 부합한다. 이는 임의의 alias를 통한 인자 전달에 대한 일반 증명이 아니라 이 원본 함수의 직접 데이터 흐름에 대한 판정이다.

right_clean은 dead/unlocked space의 권한을 정리하지만 entry 자체를 dealloc하거나 reverse hash에서 제거하지 않는다. namespace active 검사도 본문에 없고 caller 계약이다. cached type mask는 `0x1f0000`이며 허용 type 외에는 panic한다.

| type | 원본 경로 |
| --- | --- |
| DEAD_NAME `0x100000` | 바로 반환; object/request NULL 같은 assert 검사 없음 |
| PORT_SET `0x80000` | pset lock 후 pset_destroy로 전달 |
| SEND `0x10000` | port 상태/요청 정리 후 send count·ref 처리 |
| RECEIVE `0x20000` | port_clear_receiver 다음 port_destroy |
| SEND_RECEIVE `0x30000` | send count 처리 후 receive 파괴 경로 |
| SEND_ONCE `0x40000` | port unlock 후 notify_send_once로 참조 전달 |

port lock 후 object bits의 sign bit로 active를 판단한다. inactive port는 refs만 감소시키고 unlock하며 마지막 ref이면 object type으로 zone을 골라 zfree한다. type word는 unlock 후 `0x14e061`에서 읽는다. inactive 경로에서는 entry.request를 지우거나 dncancel을 호출하지 않는다. 이 요청의 별도 종료 처리는 port_destroy 등 다른 경로의 계약이다.

active port에서 request가 있으면 dncancel(port,name,index)을 호출하고 entry.request=0을 저장한다. COMPAT bit가 있으면 space_release(space)를 호출하고 notification target을 0으로 만든다. 그러지 않으면 dncancel 반환 target을 나중에 port_deleted 알림에 사용한다. cached type는 lock 이전에 얻었지만 COMPAT bit는 이 위치에서 entry를 다시 읽는다.

SEND가 포함되면 port.srights를 줄인다. 마지막 send이고 nsrequest가 있으면 nsrequest를 떼고 mscount를 저장한다. RECEIVE가 있으면 clear_receiver와 port_destroy에 잠긴 port를 넘긴다. SEND_ONCE이면 직접 sorights를 감소시키지 않고 unlock 후 notify_send_once에 참조를 넘긴다. 순수 SEND의 active 경로는 refs를 줄이고 unlock하지만 마지막 ref 확인/free는 하지 않는다. 각 type의 정상 소유권 불변조건에 의존한다.

그 뒤 저장된 nsrequest로 no_senders, 저장된 dncancel target으로 port_deleted 순으로 알림 helper를 호출한다. entry.bits/object 전체를 zeroing하거나 marequest_cancel을 호출하는 단계는 없다. 하위 port_destroy/알림의 최종 소비·오류를 이번 본문만으로 완료 판정하지 않는다.

## dead-space에서 MAREQUEST를 직접 취소하지 않는 이유

참조 소스는 dead space에서 MAREQUEST bit가 이미 해제된 request의 흔적으로 남을 수 있어 그 bit만 보고 취소하면 안 된다고 설명한다. 원본 right_clean에도 marequest_cancel 호출이 없다. [보고서 60](../continuous-review-20260912-60/README.md)의 marequest_destroy는 dead space이면 entry flag를 정리하지 않는 별도 경로를 가진다.

따라서 right_clean의 bit 미삭제를 곧바로 누락/누수로 판정하거나 무조건 cancel을 추가하면 안 된다. request 자체의 생성·취소·destroy 호출 횟수와 space ref 연결은 여전히 전역 검증이 필요하다. active port의 COMPAT dncancel/space_release는 이 MAREQUEST 문제와 별도의 ref 회수이다.

## pset_destroy와 naked receive 반환

pset_destroy는 caller가 active pset lock과 ref를 보유한다는 계약이다. `0x14da9f`에서 active bit를 내리고 pset의 mqueue(`+0x10`)를 잠근 뒤 mqueue_changed(queue,`0x10004009`)를 호출한다. queue unlock, pset refs 감소, pset unlock 후 마지막 ref이면 zone free한다. pset에 남은 member port를 순회하여 떼어내는 동작은 본문에 없다. 참조 소스는 member 제거와 그 메시지 이동이 나중에 이루어진다고 설명한다. mqueue의 실제 대기자 처리와 이후 member 수명은 미완료다.

release_receive는 naked receive port를 잠그고 `0x14d184`에서 destination(`+0xc`)을 EBX에 저장한 다음 port_destroy를 호출한다. 이후 저장된 destination이 NULL이 아니면 object_release한다. 원래 port를 파괴한 뒤 그 필드를 다시 읽지 않는다. active/receiver_name==NULL 검사는 소스 assert이며 원본에 없다. destination ref 및 port_destroy의 실제 소비를 모두 연결한 최종 수명 검증은 다음 범위다.

## ipc_init의 imported prototype 주의

`0x146ede`부터 task_create에 실제로 push되는 인자는 NULL, FALSE, ipc_soft_task 출력 주소이다. Ghidra가 표시하는 ledger 타입과 추가 in_stack 인자는 이 caller에서 준비되지 않는다. 원본 task_create callee의 전수 ABI 판정은 별도로 남기며, 이 호출을 Ghidra의 확장된 prototype대로 복원해서는 안 된다.

실패는 panic이고 성공하면 task `+0xc`에서 map을 읽어 ipc_soft_map에 저장한다. 이어 kmem_suballoc(kernel_map,&min,&max,ipc_kernel_map_size,TRUE)을 호출해 ipc_kernel_map에 저장한 뒤 ipc_host_init을 호출한다. 이 경로에는 suballoc 포인터 NULL 검사, soft map의 page-zero 예약, 추가 kernel_copy_map suballoc이 없다. 참고 Darwin에는 page-zero 예약 및 별도 kernel_copy_map 생성 코드가 있으므로 그 동작을 원본에 자동 채택하지 않는다.

## 다음 경계

다음은 port_destroy의 receive/backup/대기자/메시지/dead-name 정리와 알림 소비, mqueue_changed 및 wait/wakeup의 상태 계약이다. bootstrap은 table_init 호출까지 확인했지만 native 부팅 성공이나 모든 기본값 유지까지 증명하지 않았다. 전체 [OPEN_ITEMS](OPEN_ITEMS.md)를 유지한다.

신규 독립 계획 검토 미확보 상태에서 문서와 정적 증거만 추가했다. 새 실행 검증 프로그램·동적 실행·커널 구현·GCC 2.7 실컴파일·Mach-O 링크·부팅은 하지 않았다. 전체 원본 의미 분석 목표는 진행 중이다.
