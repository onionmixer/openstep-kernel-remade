# 보고서33 이후 잔여 분석

[보고서32 잔여 의무](../continuous-review-20260911-32/OPEN_ITEMS.md)를 유지한다.
이번에 연결한 것은 실제 byte write 이후 대표 물리 페이지 조회와 dirty/reference
반영, 사용자 PTE/PV 제거, 빈 user PT의 free PT queue 이동이다.
합성 segment와 caller 입력을 사용했으며 전체 memory discovery/ownership이 아니다.

다음 연결은 신규 wired PT backing의 실제 회수다.

- `_pmap_update` `191144`의 sched_tick/이전 tick gate, free PT queue dequeue,
  extension zone 반환, descriptor backlink 제거, `kmem_free`와 PT 할당 계수 감소.
- user PT와 page-directory free queue를 구분하고 유효한 empty sentinel·전역 값이
  실제 초기화되는 조건을 확인한다. 합성 입력을 scheduler/boot 실행으로 세지 않는다.
- kernel map 삭제 → wired mapping 제거 → PG unwire/물리 lookup → kernel object
  page/hash/resident/free queue와 reference 수명까지 연결한다. DATA page는 별도다.
- `1913ec`의 `_pmap_collect`는 이 바이너리에서 단순 반환이다. 함수 이름만으로
  backing GC가 수행된다고 가정하지 않는다. 위 경로는 이번에는 정적 사전 읽기만 했다.

여러 PV node/alias/매핑 교체, 여러 페이지·비연속 물리 메모리/VM 경계 copy,
실제 object/map/pmap/zone 생성, 자원 부족/zone 성장/pageout/대기·재시도/경합,
pager I/O/COW/shadow/copy/busy/absent/error/map 변경/policy 검증은 남아 있다.
native IDT/error/frame/RF/CPL/FS/recover 수명, 전체 문맥 전환·startup/boot/장치/
비동기 인터럽트/동시성/실제 TLB/cache도 미완료다.

ABI/타입/함수 경계·분리 조각·CPU 부작용 통합/전체 소비자 회귀, 동일 원본 IDA
독립 대조·교정 후 재추출, 공개 소스 계보와 복원 명세 및 실제 GCC 2.7 구현/
컴파일/링크/부팅·후속 아키텍처 분석 의무도 계속 유지한다.
전체 목표를 완료하지 않는다.
