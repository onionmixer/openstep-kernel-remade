# 105차 이후 남은 원본 분석

RW lock field/전환/recursive·sleep 계약과 host 통계의 max 초기화는 원본에서 연결했다.
전체 원본 커널의 의미·경계·ABI·동시성 검토는 미완료다.

## 다음 우선 항목

1. **VM 계약**: 0x173ebc wired backing helper,
   vm_map_pageable 0x175b2c와 vm_map_remove 0x1765ac의 반환/실패/rollback,
   map/object/page/pmap 수명을 원본으로 검토한다. 104차의 상태 미검사와
   잠금 보유 중 VM 호출의 실제 결과를 아직 단정할 수 없다.
2. **VM lock caller의 recursive 수명**: 지정 직접 호출
   0x174541/0x174560, 0x175ff0/0x17603e,
   0x1776c0, 0x177885/0x1778b3/0x1778c7의 전체 caller를 확인한다.
   set_recursive가 write-bit 검사만 한다는 사실을 소유권 검증 전체로 간주하지 않는다.
   모든 lock mode/count/upgrade caller, 최고 count·wrap 도달성도 남아 있다.
3. **IRQ/pending callback과 실제 진행성**: SPL pending slot/record의 전체 writer와
   유효 수준, PIC mask shadow/포트 처리, callback 재진입 및 IRQ frame을 연결한다.
   thread_sleep의 splx-before-interlock-release 순서와 register-only TEST loop가
   실제 실행에 미치는 영향은 아직 미완료다.
4. **cache/waiter/reserve 불변식**: freeStack unlock 후 scan/removal, cache count/head/state,
   stack 고갈 flag/event, reserve T+0x30의 전체 소유권·최종 해제를 닫는다.
   RW lock 경합 event와 스택 고갈 event는 구분했지만 전체 caller 직렬화는 미확정이다.
5. **통계/RPC**: host_stack_usage 직접 호출 0x171bcd의 전체 메시지/host 변환·출력 계약,
   debug flag/max의 alias writer와 실제 측정 범위를 확인한다. 이번 caller의 max 초기화는
   확인했지만 통계 전체가 atomic snapshot/물리 residency를 제공한다는 뜻은 아니다.
6. **간접 도달성과 일반 memory helper**: direct CALL 미검출 함수를 미사용으로 단정하지
   않는다. 주소 테이블/간접 호출/함수 밖 코드, memset의 일반 값·크기·alignment·wrap
   계약은 정확한 lock_init zero 요청 검증과 별도로 남겨 둔다.

[104차 목록](../continuous-review-20260913-104/OPEN_ITEMS.md)의 최초 context 준비,
GDT/LDT/TSS/CR3/TLB/CR0/FPU와 continuation 수명, priority/runq/processor/idle/binding,
AST/IPC/thread/task 종료·callback/map 수명은 유지한다.
전체 영역·entry·경계·ABI·경고·실패와 VM COW/shadow/pager/PV,
VFS/UFS/NFS/RPC/XDR, IPC/MIG/BSD/network, DriverKit/kernserv/ObjC/MMIO/DMA도 미완료다.

다음도 다른 코드 없이 원본 OPENSTEP만 분석한다. 계산은 전부 Python으로 수행하며,
구현·복원·빌드·포팅으로 확대하지 않는다. 신규 독립 계획 검토 미수신 제한을 유지한다.

[이번 결과](README.md) · [범위](SCOPE.md)
