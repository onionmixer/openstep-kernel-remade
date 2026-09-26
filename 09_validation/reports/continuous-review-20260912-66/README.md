# Port 파괴·대기 해제·메시지 정리의 원본 대조

보고서 65의 space 정리 경로에서 이어지는 port 파괴와 선택된 직접 호출을 정적으로 검토했다. **port_destroy는 항상 즉시 port를 죽이는 함수가 아니며, thread_go도 항상 실행 큐에 넣는 함수가 아니다.** 또한 Ghidra C의 lock 주변 메모리 접근 순서를 원본과 동일하다고 가정하면 안 된다.

이번 결과는 원본 전체 의미 분석 완료가 아니다. 문서·정적 증거만 추가했고 원본·참고 소스·DB·export·기존 보고서·07_kernel은 변경하지 않았다. Ghidra 스킬에 따라 보존된 본문·디컴파일·메타데이터를 대조하되 원본 바이트를 판단 기준으로 삼았다. 신규 독립 계획 검토·동적 실행·구현·GCC 2.7 실컴파일은 수행하지 않았다.

## 증거와 범위

[정적 증거](port-destruction-evidence.json)에 원본 Mach-O 주소/파일 offset, 명령어 바이트와 독립 디코딩, 직접 분기·호출 대상, 간접 분기 표, 필드 계산, 입력 해시를 보존했다. [보존 목록](preservation.json)은 이전 확정 자료를 잇는다. 계산은 모두 Python으로 수행했다.

| 본문 | 시작 주소 | instruction heads | 본문 바이트 |
|---|---|---:|---:|
| ipc_port_destroy | 0x14cb80 | 236 | 651 |
| ipc_port_check_circularity | 0x14ce18 | 106 | 271 |
| ipc_mqueue_changed | 0x14a728 | 25 | 55 |
| ipc_thread_dequeue | 0x151c24 | 23 | 72 |
| ipc_kmsg_dequeue | 0x146f68 | 21 | 46 |
| ipc_kmsg_destroy | 0x146fe0 | 61 | 152 |
| thread_go | 0x159000 | 54 | 147 |
| ipc_notify_port_destroyed | 0x14b4dc | 45 | 126 |
| ipc_notify_port_destroyed_compat | 0x14b7bc | 46 | 133 |
| ipc_notify_send_once | 0x14b5d4 | 38 | 107 |
| ipc_kobject_destroy | 0x1583d4 | 33 | 67 |

Python 집계 결과는 11개 본문, 688개 instruction heads, 1827바이트, 직접 분기 88개, 직접 호출 47개다. 본문 범위는 메타데이터의 비연속 구간을 그대로 사용했다. thread_go의 15개 DWORD 분기 표 60바이트는 코드 본문에 합산하지 않았다. 선택된 C 출력의 명시적 WARNING은 0개지만, 아래의 순서·동기화 해석 문제는 실제로 존재한다. 경고가 없다는 사실은 정확성 증명이 아니다.

## ipc_port_destroy: backup 이전과 실제 파괴를 구분

참고 소스의 진입 조건은 port가 active·locked이고 caller가 소비될 reference를 보유하며 다른 lock은 없다는 것이다. pset 없음, mscount/seqno 초기화 등 assert도 존재한다. 원본 함수는 이 조건을 검사하지 않는다. receiver 관련 필드는 진입 시 유효한 space로 취급하지 않으며, 선행 clear_receiver 경로는 [보고서 59](../continuous-review-20260912-59/README.md) 및 [보고서 65](../continuous-review-20260912-65/README.md)와 연결된다.

backup(+0x28)이 있으면 0x14cb97에서 슬롯을 비우고 receiver_name(+0x10), destination/receiver(+0xc)를 0으로 만든 뒤 0x14cbae에서 port를 unlock한다. backup pointer의 low bit가 compat 표지다. compat는 low bit를 지운 send right, 일반 경로는 send-once right로 처리한다.

- circularity가 false이면 compat 알림(0x14cbcb) 또는 일반 알림(0x14cbf6)을 호출하고 곧바로 반환한다. 뒤의 active 해제·메시지 drain·마지막 caller reference release를 이 호출 프레임에서는 실행하지 않는다.
- circularity가 true이면 backup의 send 또는 send-once 권한을 release(0x14cbd9/0x14cc01)하고 port를 다시 lock한 뒤 실제 파괴로 진행한다.
- false는 단순 판정 결과가 아니다. circularity 함수가 destination reference를 추가하고 port를 in-transit으로 만든다. 그러나 알림 할당 실패는 receive right를 다시 release하여 파괴로 이어질 수 있으므로, 조기 반환만 보고 port가 반드시 살아남는다고 결론 내릴 수 없다.

실제 파괴의 순서는 다음과 같다.

1. port+0x4c의 blocked **sender** queue에서 thread를 제거한다. 각 thread+0x98에 0을 저장(0x14cc39)한 뒤 thread_go를 호출한다. 이 루프는 port lock을 보유한 상태다.
2. 0x14cc53에서 active bit를 지운다. timestamp lock을 획득한 뒤 이전 timestamp를 읽고 증가시킨다. timestamp lock을 풀고 이전 값을 port+0xc에 저장한 뒤 port lock을 푼다.
3. port+0x24의 no-senders request가 있으면 0x14cc9c에서 **send-once 알림**으로 소비한다. 여기서 no-senders 알림을 보내는 것은 아니다. 이 본문은 해당 슬롯을 먼저 0으로 만들지 않는다.
4. port+0x40의 message queue lock을 얻고 port+0x44의 메시지를 dequeue한다. 각 메시지마다 queue unlock → port object reference release(0x14ccdb) → 메시지 remote_port(+0x1c)=0(0x14cce0) → kmsg_destroy(0x14cce8) → queue relock 순서다. 먼저 소비한 destination reference를 메시지 cleanup이 다시 소비하지 않도록 remote field를 비운다. queued message의 remote가 실제 해당 port라는 assert는 참고 소스에만 있다.
5. dead-name request table을 순회하고 해제한다. 필요하면 kobject별 정리 함수를 호출한 뒤 0x14ce09의 object_release로 caller reference를 소비한다.

receiver thread queue는 port+0x48이며 sender queue(+0x4c)와 다르다. 이 함수는 receiver queue에 mqueue_changed를 호출하지 않는다. 참고 소스는 message drain 시 receiver queue가 비어 있다는 assert를 요구한다. 따라서 이 본문 하나가 sender와 receiver 모두를 깨운다고 기술하면 틀리며, 선행 clear_receiver/pset 경로의 조건이 필요하다.

### Timestamp의 C 표현은 원본 순서를 보존하지 않는다

원본은 0x14cc6a의 timestamp lock XCHG와 재시도 검사를 통과한 **뒤** 0x14cc77에서 global 0x1f623c를 읽는다. 0x14cc7c에서 증가, 0x14cc84에서 timestamp unlock, 0x14cc8d에서 port timestamp 저장, 0x14cc92에서 port unlock이다.

Ghidra C는 이전 timestamp 읽기를 timestamp-lock 대기보다 앞으로 옮기고 lock 획득의 실제 XCHG/재시도도 불완전하게 표현한다. 복원 C로 그대로 사용할 수 없다. 이는 시간값의 초기화·wraparound·모든 사용자·native 동시성이 검증되었다는 뜻은 아니다.

### Dead-name table의 compat 분기

port+0x2c에서 table을 얻고 table+4의 size descriptor를 사용한다. index는 1부터 count 미만, 슬롯 stride는 8이며 name(+4)이 0인 슬롯은 건너뛴다. 사용 슬롯의 첫 DWORD low bit가 0이면 notify_dead_name(word, name)를 호출한다. word가 유효한 send-once right라는 assert는 원본에 없다.

태그가 있으면 word & 0xfffffffe를 space로 사용한다. lookup_write 실패 시 space_release만 한다. 성공 후 entry.object가 dying port와 다르면 namespace lock을 풀고 알림을 생략한다. 일치하면 space+0x44의 notify port를 copy_send하여 **EBX에 보관**(0x14cd7f)한 다음 right_destroy(space,name,entry)를 호출한다. 이후 0/-1 검사는 right_destroy의 반환값이 아니라 보관한 notify port에 적용된다. right_destroy의 상태는 이 caller에서 검사하지 않는다.

유효한 보관 notify port에는 port_deleted_compat를 보내고 tagged branch의 space reference를 release한다. table 해제 시 descriptor count를 다시 읽어 count*8을 ipc_table_free에 넘긴다. table 슬롯과 port의 dnrequests pointer를 전부 0으로 정리하는 루틴은 아니다. right_destroy 내부의 namespace unlock·권한 변화·실패 경로 및 다른 알림 본문까지 이번에 완결한 것은 아니다.

## Circularity: lock을 잡고 destination을 연결하는 함수

port==dest이면 즉시 true다. 그렇지 않으면 port lock을 얻고 dest try-lock을 시도한다. dest가 inactive, receiver_name 비영, destination 없음 중 하나면 fast success 경로로 간다. try-lock 실패 또는 in-transit dest이면 필요한 lock을 풀고 global multiple lock(0x1f6238)을 얻는다.

slow path는 dest부터 in-transit 연결을 따라가며 각 port lock을 유지한다. 끝의 base==port이면 circularity가 확인되어 global lock을 풀고 chain의 lock을 해제한 뒤 true를 반환한다. 다르면 chain 전체를 잠근 상태에서 port도 lock하고 global lock을 해제한다.

성공 경로는 0x14cf00에서 dest+4의 reference를 증가시키고 0x14cf03에서 port+0xc=dest를 저장한다. 이어 port부터 base까지 lock을 해제하고 false를 반환한다. 따라서 readonly validation, 권한 복제 없음, reference 변화 없음으로 모델링할 수 없다. source가 요구하는 port-in-limbo 및 기존 chain의 불변식은 원본 assert로 강제되지 않는다. 임의의 손상된 순환 구조를 안전하게 탐지하는 일반 graph 검사로 사용할 수 없다.

여기에도 C 순서 문제가 있다. circular branch는 0x14ced0에서 next를 읽고 0x14ced5에서 현재 port unlock을 한다. 성공 branch도 0x14cf0c에서 next를 읽고 0x14cf11에서 unlock한다. Ghidra C는 두 루프 모두 next 읽기를 unlock 뒤에 표현한다. 원본의 **next 저장 후 unlock** 순서를 보존해야 한다.

## 큐 제거와 thread_go의 실제 상태 변화

ipc_thread_dequeue는 queue head가 NULL이면 그대로 반환한다. singleton이면 head를 NULL로 한다. 다중 원소에서는 thread+0x90(next), +0x94(prev)로 이웃과 head를 연결하고 제거된 thread의 next/prev를 자기 자신으로 만든다. 자체 lock, ith_state 변경, reference release는 없다.

ipc_kmsg_dequeue도 head/이웃을 연결하지만 메시지 next(+0), prev(+4)를 자기 자신으로 재설정하지 않는다. 제거 후 링크를 무조건 self로 예상하면 안 된다. 역시 자체 lock·free·reference 정리는 없다.

ipc_mqueue_changed(queue,mr)는 queue+8의 receiver threads를 반복 dequeue하고 각 thread+0x98에 mr을 저장한 뒤 thread_go를 부른다. queue lock은 caller 조건이며, 이 함수가 메시지 body나 queued message를 정리하지는 않는다.

thread_go는 splsched → thread+0x20 lock → 필요하면 reset_timeout(thread+0x118) → state별 처리 → thread unlock → splx 순서다. timeout 여부는 thread+0x144에서 검사한다. IPC 결과(+0x98), scheduler state(+0x4c), wait_result(+0x44)는 서로 다른 필드다.

원본 0x159048의 DEC 후 unsigned 비교가 0x159058의 DWORD 표 접근을 제한한다. 표는 파일 offset 364632에서 별도로 읽어 모든 target이 본문 instruction head인지 확인했다. 참고 thread.h의 WAIT=1, SUSP=2, RUN=4, UNINT=8과 원본 low-state별 분기를 대조했다.

| state & 0xf | target | 수행 내용 |
|---|---|---|
| 0x1, 0x9, 0xb | 0x159094 | WAIT 해제, RUN 설정, wait_result=0, thread_setrun(thread,1) |
| 0x3, 0x5, 0x7, 0xd, 0xf | 0x1590b4 | WAIT 해제, wait_result=0, thread_setrun 호출 없음 |
| 나머지 | 0x1590c1 | state/wait_result 변경 없음 |

상위 state bits는 유지한다. default도 앞선 timeout reset의 영향은 받을 수 있다. 이 함수 호출만으로 즉각적인 context switch나 해당 thread의 실제 실행을 보장할 수 없으며, thread_setrun/reset_timeout과 interrupt level의 전이적 동작은 별도 분석 대상이다.

## ipc_kmsg_destroy: 중첩 cleanup을 큐에 모은다

0x146fe9는 global 0x1e8b54의 **값을 thread pointer로 읽고**, thread+0xa4를 정리용 queue로 사용한다. global 주소 자체에 0xa4를 더한 고정 큐로 해석하지 않는다. 이 mapping의 CPU별/current-thread context와 migration은 이번 정적 본문만으로 완결하지 않았다.

진입 시 큐가 비었는지를 저장한 뒤 받은 kmsg를 ring에 넣는다. 이미 큐가 차 있었다면 append 후 반환한다. 큐가 비어 있던 바깥 호출만 head를 반복 처리한다. 0x147029에서 kmsg_clean을 호출하는 동안 대상은 아직 큐에 있으며, clean에서 추가된 메시지를 보존하도록 그 뒤에 링크를 읽고 제거한다. kmsg+8이 signed 양수면 kfree(kmsg,size), 그 외에는 ipc_kmsg_free(kmsg)를 호출한다.

참고 소스의 설명과 함께 보면 중첩 메시지 파괴를 큐로 모아 recursion을 제한하는 구조다. 모든 호출이 반환 전에 자기 메시지를 직접 free한다는 계약은 아니다. 동일 메시지의 중복 enqueue 안전성이나 idempotence를 뜻하지도 않는다. kmsg_clean의 권한/OOL 메모리 정리 및 특수 kmsg_free 내부는 후속 범위로 남긴다.

## 선택 알림과 kobject dispatch

port-destroyed 일반·compat는 kalloc(0x34)을 사용한다. 실패 시 printf 이후 backup 권한을 release하고 receive right를 release한다. 일반은 release_sonce, compat는 release_send다. 성공 시 kmsg+8=0x34, +0xc/+0x10=0을 저장하고 template 0x1f62f0에서 8 DWORD를 +0x14로 복사한다. 양쪽 모두 REP MOVSD 전에 명시적 CLD가 있다. remote(+0x1c)에 backup, +0x30에 이전할 port를 기록한다. compat는 header bits(+0x14)를 0x80000011로 덮어쓴다.

send-once 알림은 kalloc(0x2c), template 0x1f6310에서 6 DWORD 복사이며 역시 명시적 CLD가 있다. 실패하면 release_sonce를 한다. 선택된 알림 함수는 성공 경로에서 ipc_mqueue_send(kmsg,0x10000,0,0)를 호출하고 반환 상태를 검사하지 않는다. template의 원본 초기화와 메시지 ID·descriptor layout, send-always 옵션의 전이적 소유권 보장은 아직 이 보고서에서 검증하지 않았다.

참고 Darwin 소스의 compat는 별도 compat template를 사용하는 반면 이 원본은 일반 template와 header override를 사용한다. 후대 source의 notification layout/초기화를 그대로 채택할 근거가 아니다.

ipc_kobject_destroy는 port+8의 low word를 읽어 0x8이면 vm_object_destroy(port), 0x9이면 vm_object_pager_wakeup(port), 0x11이면 netipc_ignore(0,port)를 호출한다. 그 외에는 직접 정리 없이 반환한다. 읽은 Darwin 함수에는 VM 관련 case가 없으므로, 참고 소스만 복사하면 원본의 dispatch를 누락한다. 다만 이 보고서는 dispatch까지만 확인했으며 호출 대상의 pager/VM/network cleanup 전체를 증명하지 않는다.

## Register-only busy loop와 검증 한계

원본에서 memory load → TEST EAX,EAX → JNZ TEST 형태가 9곳 확인됐다. load 주소는 0x14cc0f, 0x14cc5c, 0x14ccac, 0x14ccf0, 0x14ce30, 0x14ce78, 0x14ce94, 0x14cee4, 0x159014이다. 각각 JNZ의 원본 바이트는 75fc이며, busy 분기는 memory load가 아니라 register TEST로 돌아간다. Ghidra C의 메모리 재읽기 while로 원본 동기화를 대체해서는 안 된다. 모든 lock 형태를 탐지했다는 집계가 아니며 native 경합의 진행성/정상성은 증명하지 않는다.

원본 해시와 본문 바이트, 분기 target, switch 표, source/export 입력 및 기존 보존 자료를 재검증한다. 이 절차는 소유권·경합·실기 부팅의 독립 증명은 아니다. [남은 작업](OPEN_ITEMS.md)의 메시지 cleanup·send·권한 destroy와 스케줄러 연결 분석을 계속해야 하며 전체 목표는 미완료다.
