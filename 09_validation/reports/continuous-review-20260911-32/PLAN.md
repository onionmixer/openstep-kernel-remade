# NP fault와 신규 PT 할당의 원본 연결 — 코딩 전 계획

대상은 보고서29의 단일-byte 익명 write fault와 보고서31의 실제 신규 wired PT
할당 사이의 미검증 연결이다. 각 단독 시험의 성공을 통합 성공으로 간주하지 않는다.
기존 보고서, 원본 binary/DB/exports/reference와 07_kernel은 변경하지 않는다.

## 사전조건과 독립 검토

`/root/vm_contract_review27`이 원본 free queue 순서와 잠금 조건을 읽기 전용으로
검토했다. 최초 전체 검토 요청은 도구 오류로 완료되지 않았으며, 완료된 검토와
미완료 요청을 구분한다. root가 다음 명령을 직접 다시 읽어 확인했다.

- vm_page_alloc 0x17b27c–0x17b2af는 free head를 제거한다.
- vm_page_free 0x17b549–0x17b5de는 tabled page의 hash/memq와 resident WORD를
  제거한다. addfree 0x17b6a3–0x17b6cd는 free tail에 추가한다.
- 임시 PG 할당은 KO object lock을 보유한다. 각각의 free는 해당 object lock과
  global queue lock을 보유하며, 내부에서 획득하는 free/hash lock은 미리 잡지 않는다.
- vm_fault는 pmap_enter 호출 전에 0x17342d에서 data object lock을 놓고,
  복귀 후 0x173463에서 다시 획득한다. kernel wired allocator의 KO lock은 별개다.
- vm_fault 0x172041과 wire_fast 0x1738a4는 같은 fault counter를 증가시킨다.
  vm_fault zero counter 0x1729e9는 wired allocator의 zero-fill과 구별한다.

보고서31 setup의 PG-only free queue에서 원본으로 PG를 잠시 할당하고 data PAGE,
PG를 차례로 해제한다. 직접 queue 포인터를 재배열하지 않는다. Python 계산 결과:

| 준비 경계 | free_count | data object resident | kernel object resident |
|---|---:|---:|---:|
| 보고서31 setup | 1 | 1 | 0 |
| PG 임시 할당 | 0 | 1 | 1 |
| PAGE 해제 | 1 | 0 | 1 |
| PG 해제 | 2 | 0 | 0 |

마지막 FIFO는 PAGE→PG다. KO.last_alloc=KVA, data object.last_alloc 및 해제된
page의 stale object/offset은 원본 이력으로 남기며 0으로 덮지 않는다.
data frame과 PT frame의 범위는 겹치지 않고 hash bucket도 구별된다.

## 실행 및 판정

원본 copyout/copyoutmsg의 실제 NP write event를 관찰한다. 예외 frame 생성은
보고서29와 같은 명시적 합성 경계이며 native CPU IDT/frame 검증으로 주장하지 않는다.
이후 원본 stub/kerneltrap/vm_fault의 data page 할당과 zero-fill, 신규 PT 물리 페이지
할당과 zero-fill/wiring, kernel PTE/PV, extension/user PDE, user PTE를 추적한다.
원본 IRETD 후 fault 당시 레지스터/flags를 복원하고 원래 byte copy가 실제 완료되어야 한다.

첫 진단 이후 A/B root, copyout/copyoutmsg, hardware-page 내 offset, flags,
zone lock 방식의 조합을 새 fixture로 실행한다. 모든 계산·해시·검산은 Python이다.
원본 호출을 mock하지 않고, frame 주입 이후 API PTE 교정이나 임의 CR3 flush를 하지 않는다.

새 통합 증거에는 준비 호출, fault 관찰/주입 전후, handler trace와 writes의 위치,
두 allocator 인자/반환, 두 zero-fill, wiring/PV/PTE/PDE, saved frame과 재시작을
기록한다. 독립 audit와 훼손 대조, 재현·보존이 끝나기 전에는 확정 결과로 표시하지 않는다.

결합 시험의 코딩 전 후속 검토에서 반복 PC를 단일값으로 축약하지 말 것,
PAGE/PG allocator 반환 지점과 두 zero 완료, nested pmap 호출 중 data object/page
보존, IRETD 전과 실제 재시작 store 후를 구별할 것을 지적받았다. root가 위 원본
호출/복귀와 0x1734a5 activate·0x1734bd busy 해제·0x1734d6 paging 감소를 확인했다.
최종 user PTE의 하드웨어 A/D는 보고서31과 달리 실제 재시작 접근으로 생길 수 있다.
두 zero-fill의 store 수와 vm_fault 전용 zero counter를 혼동하지 않는다.

전체 startup/ownership/zone 성장/자원 부족·스케줄러·경합/native CPU/다중-byte
경계 복사/장치/IDA/ABI/소스 계보 및 GCC 2.7 구현·빌드·부팅 등
[전체 잔여 의무](../continuous-review-20260911-31/OPEN_ITEMS.md)는 그대로 유지한다.
