# Namespace 권한 파괴: 반환값과 이미 수행된 정리

**ipc_right_destroy의 실패 반환은 변경 없음과 동의어가 아니다.** inactive port의 compat 경로는 port reference와 namespace entry를 정리한 뒤 KERN_INVALID_NAME을 반환한다. 또한 이 함수는 user-reference 하나를 감소시키는 deallocate가 아니라 해당 name의 권한 entry를 파괴하는 경로다.

보고서 67의 checkpoint·파일을 재검증했다. 이전 턴은 cleanup 의미와 원본 증거를 확정한 실제 진전이다. 이번에는 Ghidra 스킬을 보존 ASM/C/메타데이터의 읽기 전용 대조에 적용하고, 모든 계산을 Python으로 수행했다. 문서·정적 증거만 추가했으며 원본·참고 소스·DB·export·기존 확정 보고서·07_kernel은 변경하지 않았다. 새 독립 계획 검토·새 실행 검증 프로그램·동적 실행·GCC 2.7 실컴파일은 수행하지 않았다.

## 증거 범위

[정적 증거](right-destroy-evidence.json)에 원본 Mach-O VA/file mapping, 명령어 바이트·독립 디코딩, 직접 분기·호출, type 분류·필드 계산과 입력 해시를 담았다. [보존 목록](preservation.json)은 이전 확정 자료를 잇는다.

| 함수 | 주소 | instruction heads | 본문 바이트 |
|---|---|---:|---:|
| ipc_right_destroy | 0x14e154 | 216 | 657 |
| ipc_hash_delete | 0x1469a0 | 36 | 70 |
| mach_port_destroy | 0x155250 | 30 | 63 |
| ipc_notify_port_deleted | 0x14b3ec | 42 | 117 |
| ipc_notify_no_senders | 0x14b55c | 42 | 117 |

Python 집계는 본문 5개, instruction heads 366개, 본문 1024바이트, 직접 분기 45개, 호출 28개다. right_destroy의 panic 호출에 대한 non-return WARNING 1개를 보존했다. 이는 전체 커널의 의미 coverage나 모든 호출 대상의 완결을 뜻하지 않는다.

## 진입 계약과 type dispatch

실제 인자는 `(space,name,entry)`다. 참고 소스의 진입 계약은 space active·write-locked이며 정상 반환 시 namespace lock을 푼다는 것이다. 원본에는 active·entry/name 일치·object/request 유효성에 대한 assert 검사들이 없다. 시작 시 entry bits를 저장하고 type=`bits & 0x1f0000`을 ESI에 보관한다.

허용되는 type은 SEND(0x10000), RECEIVE(0x20000), SEND_RECEIVE(0x30000), SEND_ONCE(0x40000), PORT_SET(0x80000), DEAD_NAME(0x100000)이다. 다른 조합은 0x14e3e1의 panic 호출로 간다. 원본에는 그 뒤 정상 epilogue 바이트도 존재하지만, panic이 정상 반환하는 검증 모델을 가정해서 성공 API로 처리하면 안 된다. panic 자체의 시스템 정지 동작은 이번 범위 밖이다.

이 함수는 low-word urefs를 기준으로 반복하거나 하나 감소시키지 않는다. name이 가진 entry 전체를 정리하고, SEND가 포함되면 해당 entry에 대응하는 port send-right 보유분을 감소시킨다. `ipc_right_dealloc`과 대체 가능한 API가 아니다.

## DEAD_NAME과 PORT_SET

DEAD_NAME은 entry_dealloc(0x14e1c5) 후 namespace unlock(0x14e1cf), 성공 반환이다. entry.object/request를 직접 0으로 만드는 코드가 이 분기에는 없다. 참고 소스가 요구하는 기존 object/request=0, MAREQUEST 없음 조건이 중요하다.

PORT_SET은 pset pointer를 저장하고 entry.object=0(0x14e1db) → entry_dealloc(0x14e1eb) → pset lock → namespace unlock(0x14e20d) → pset_destroy(0x14e211) 순서다. namespace entry가 제거된 뒤에도 보관한 pset reference가 유효해야 한다. pset_destroy가 reference를 소비하고 pset을 unlock하는 경로는 [보고서 65](../continuous-review-20260912-65/README.md)와 연결된다. 이 분기 역시 request를 직접 0으로 설정하지 않으므로 request 없음은 caller 불변식이다.

## Port 권한 공통 전처리

entry.object를 EBX에 보관하고 알림용 local을 초기화한다. 진입 시 저장한 bits에 MAREQUEST(0x200000)가 있으면 0x14e240에서 marequest_cancel(space,name)을 먼저 호출한다. 이 helper는 요청을 최종 free하거나 entry bit를 직접 clear하는 함수가 아니다. 이후 entry 제거 및 나중의 marequest_destroy와 연결되는 수명은 [보고서 60](../continuous-review-20260912-60/README.md)에 기록되어 있다.

type이 **pure SEND와 정확히 일치할 때만** 0x14e25a에서 reverse hash를 제거한다. SEND_RECEIVE는 이 경로를 타지 않는다. 순서는 request cancel → pure SEND hash delete → port lock이다. hash 제거를 port 파괴 뒤로 옮기면 entry나 object의 수명·namespace 접근 조건이 달라질 수 있다.

## Inactive port: entry를 없앤 뒤 compat 오류 반환

port lock을 얻은 뒤 active sign bit가 꺼져 있으면 0x14e284에서 refs를 감소시키고 0x14e28a에서 unlock한다. 저장한 감소 결과가 0이면 type별 object zone으로 zfree한다. 이때 zone type word(+0xa)는 **unlock 후** 0x14e291에서 읽는다. 이 순서를 Ghidra 고수준 타입 설명만으로 바꿀 수 없으며, 최종 reference를 보유한 caller의 수명 조건을 전제로 해석해야 한다.

이후 entry.request=0(0x14e2aa), entry.object=0(0x14e2b1), entry_dealloc(0x14e2c1), namespace unlock(0x14e2cb) 순서다. 마지막에 **진입 시 저장한 COMPAT bit**를 검사하여 있으면 EAX=0xf, 없으면 0을 반환한다. 참고 kern_return.h에서 0xf는 KERN_INVALID_NAME이다.

여기서는 dncancel이나 active 경로의 no-senders/port-deleted 알림을 호출하지 않는다. COMPAT 오류를 rollback 가능 여부로 사용하거나, 오류니까 entry를 다시 정리해야 한다고 판단하면 안 된다. 이 경로에서 처리하지 않는 요청·space reference의 수명은 port 사망 및 request 처리 전체와 연결해야 하며, 이 본문만으로 누수 유무를 판정하지 않는다.

## Active port: namespace를 먼저 분리하고 port 정리

entry.request가 비영이면 dncancel(port,name,index)을 호출하고 request=0으로 만든다. 그 뒤 0x14e304에서는 진입 snapshot이 아니라 **현재 entry bits의 COMPAT bit**를 읽는다. COMPAT면 space_release(space)를 호출하고 일반 port-deleted 알림 대상을 0으로 만든다. request가 0이면 이 space_release도 호출하지 않는다. 원본은 dncancel이 돌려준 tagged word와 space가 실제로 일치하는지 비교하지 않으며, 참고 소스의 assert 조건에 해당한다.

그 다음 entry.object=0(0x14e327), entry_dealloc(0x14e337), namespace unlock(0x14e344)을 수행한다. **이후 원래 entry를 다시 읽지 않는다.** entry_dealloc은 table slot을 free-list로 돌려주거나 충돌 node로 대체할 수 있고 tree entry라면 node를 free할 수 있으므로, 저장한 type·port·알림 값으로 계속해야 한다. 관련 구현은 [보고서 61](../continuous-review-20260912-61/README.md)에 있다.

이 시점에는 namespace lock은 없고 port lock은 유지된다.

- SEND bit가 있으면 srights(+0x1c)를 감소시킨다. 이전 값이 1이고 nsrequest(+0x24)가 비영이면 요청을 local에 저장하고 슬롯을 0으로 만든 뒤 mscount(+0x18)도 저장한다. srights 양수 assert는 원본에 없다.
- RECEIVE bit가 있으면 clear_receiver(0x14e37d) → port_destroy(0x14e383)로 넘긴다. 이 호출들이 reference를 소비하고 unlock한다. backup port가 있으면 receive right가 알림으로 이전될 수 있으므로 반드시 즉시 port가 죽는다는 뜻은 아니다.
- RECEIVE가 없고 SEND_ONCE bit가 있으면 port unlock(0x14e39a) 후 notify_send_once(port)를 호출한다. sorights나 refs를 여기서 직접 감소시키지 않는다.
- 나머지 허용 경로인 pure SEND는 refs를 감소시키고 port를 unlock한다. 여기에는 refs==0에 대한 zfree 분기가 없다. 수신권 등 다른 reference가 존재한다는 정상 수명 조건을 무시해 이 분기를 범용 object release로 재사용하면 안 된다.

보관한 nsrequest가 있으면 no_senders(nsrequest,saved_mscount)를 먼저, 보관한 dnrequest가 있으면 port_deleted(dnrequest,name)를 다음에 호출한다. mscount는 receiver clear가 값을 초기화하거나 port_destroy가 object를 정리하기 **전에 저장한 값**이다. 두 알림 단계는 더 이상 port를 읽지 않는다. 알림 실패를 검사해 반환 상태를 바꾸지도 않는다.

## Namespace wrapper와 반환 상태의 전달

mach_port_destroy(space,name)는 space==NULL이면 0x10(KERN_INVALID_TASK)을 반환한다. 아니면 lookup_write(space,name,&entry)를 호출하고 실패 상태를 그대로 반환한다. 성공 시 right_destroy(space,name,entry)를 호출하고 EAX를 그대로 caller로 돌려준다. wrapper가 추가 namespace unlock을 하지 않는 것은 callee가 이를 소비하는 계약과 맞는다.

반면 [보고서 66](../continuous-review-20260912-66/README.md)의 port_destroy compat dead-name caller는 notify port를 copy_send하여 EBX에 보관하고 right_destroy를 호출한 뒤 그 반환 상태를 무시한다. 후속 알림 검사 대상은 saved notify port다. 같은 callee라도 오류 전파 여부가 caller마다 다르며, 위의 파괴 후 KERN_INVALID_NAME 규약과 모순되지 않는다.

## Hash dispatch의 정확한 entry 판정

ipc_hash_delete는 index=`name >> 8`을 계산한다. index < space.table_size(+0x18)이고 entry가 정확히 space.table(+0x14)+index*16일 때만 local_delete(space,object,index,entry)를 호출한다. 나머지는 global_delete(space,object,name,entry)다. 이름 범위만으로 local entry라고 간주하면 안 된다.

원본에서 이 wrapper는 lock·reference·object/entry free를 직접 수행하지 않으며 callee 상태를 검사하지 않는다. namespace lock과 reverse hash membership이 caller 조건이다. 기존 보고서의 local/global deletion 부작용과 미사용 ABI 인자 검토를 유지한다.

## Port-deleted / no-senders 알림 본문

두 함수는 kalloc(0x34)을 사용한다. 실패하면 printf 이후 release_sonce(destination)을 호출한다. 성공하면 kmsg+8=0x34, +0xc/+0x10=0을 저장하고 +0x14로 template 8 DWORD, 즉 32바이트를 복사한다. port-deleted template는 0x1f62d0, no-senders는 0x1f62b0이다. 원본 0x14b439와 0x14b5a9에 각각 명시적 CLD가 있다.

destination은 kmsg+0x1c, name 또는 mscount는 +0x30에 저장한다. payload 값은 이 함수에서 새로 조회하거나 계산하지 않고 caller 인자를 사용한다. 두 함수 모두 ipc_mqueue_send(kmsg,0x10000,0,0)를 호출하고 반환 상태를 검사하지 않는다. template 초기화·ID·descriptor layout과 send-always 경로의 전체 ownership은 아직 이 본문만으로 검증하지 않았다.

## 동기화 및 남은 경계

right_destroy에서 확인한 register-only busy loop의 load 주소는 0x14e1f4, 0x14e264다. JNZ 바이트 75fc는 memory load가 아니라 각각 0x14e1f6, 0x14e266의 TEST EAX로 돌아간다. Ghidra C의 memory-reload while를 원본 동기화와 동일시하지 않으며 native 경합 진행성은 여전히 미검증이다.

이번에 권한 파괴의 type별 제어 흐름·ABI·reference/entry 처리 순서·알림과 반환 상태를 연결했지만 모든 생성자·caller·경합의 수명 증명은 아니다. [남은 작업](OPEN_ITEMS.md)에 따라 message queue 송수신과 전이적 ownership 분석을 이어가야 한다. 전체 원본 분석과 GCC 2.7 최종 복원·부팅 목표는 계속 미완료다.
