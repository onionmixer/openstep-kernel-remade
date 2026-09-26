# 신규 PT 원본 wired 할당 성공 — 검증 계획

상태: 코딩 전 독립 검토를 받은 계획. 실행 성공·전체 분석 완료는 아직 주장하지 않는다.
보고서30 및 이전 확정 자료를 수정하지 않고 신규 보고서 안에서만 작업한다.

## 대상과 성공 조건

원본 `pmap_expand`의 free PT 없음 분기에서 `kmem_alloc_wired`, map entry의
할당/삭제/재삽입, 물리 페이지 할당/zero-fill, 실제 VM wiring과 kernel pmap_enter,
extension zalloc, 물리 역변환과 descriptor 등록, user PDE 설치를 이어 실행한다.
별도 pmap_enter 호출자 사례에서는 사용자 PTE 설치까지 확인한다.
반환 0 또는 기존 free PT 재사용만으로 신규 성공을 판정하지 않는다.

준비는 기존 bootstrap/high-CS 시험 기반의 명시적 합성 kernel map/object/zone과
detached free-page seed다. 실제 map/object/zone 생성·zone backing 성장·전체 boot
ownership은 여전히 미검증이다. 함수 patch/mock, 호출 도중 API 상태 교정은 금지한다.

## 코딩 전 Codex 교차검토와 root 확인

`/root/vm_contract_review27`의 읽기 전용 검토 의견을 받았으며 그대로 신뢰하지 않는다.
root가 보존 ASM에서 확인한 조건:

- `vm_map_insert` 0x174968 이후는 map+0x2c 비영일 때만 prot/max/inherit/wired를
  초기화한다. map+0x20에 따른 entry-zone 선택과 공급 zone이 일치해야 한다.
- `kmem_alloc_wired` 0x173d9b 이후 kernel_object offset은 선택된 KVA다.
- `vm_fault_wire_fast` 0x1738bf–0x17390c의 object offset/protection 및
  page busy/absent/page_lock 조건을 확인한다. 0x173944의 실제 vm_page_wire와
  0x17b7ac/0x17b7b2의 global/WORD count 갱신을 관찰한다.
- `zalloc` 0x16b3b7 이후 free pop, `zfree` 0x16b8d0 이후 재삽입,
  map delete 0x176587 → insert 0x17492e의 실제 element 재사용을 기록한다.
- KVA는 DS 논리 주소다. kernel root의 low KVA와 active root의 high alias가
  같은 PTE를 참조하는지 Python walk로 확인하고 해당 KVA만 NP로 준비한다.
  물리 frame의 high direct alias는 유지한다. 준비 후 원본 CR3 write를 실행한다.
- 0x190de5의 물리 역변환, 0x190e06의 backlink, 0x190ef4의 PDE stores까지
  관찰한다. zalloc NULL은 원본에서 확인 없이 사용하므로 정상 자원 선행조건과 구분한다.

## 검증 및 보존

Python으로 주소/크기/계수/모델/해시를 계산한다. 명시적 초기 상태, 실제 호출 인자,
원본 명령 trace, CPU writes, 중요 시점의 전체 관련 상태를 저장한다.
첫 실행 진단 후 독립 raw-binary/상태 모델 audit 및 훼손 대조, 재현, 입력/산출물 해시와
원본·이전 보고서 보존 검증을 추가한다. 이 검증들이 끝나기 전 보고서는 작업 중이다.

전체 잔여 의무는 [보고서30](../continuous-review-20260911-30/OPEN_ITEMS.md)을 유지한다.
특히 실제 자원 부족·스케줄러·경합 정리·GC, 전체 fault 통합, native CPU 예외와
GCC 2.7 구현/빌드/부팅 및 후속 아키텍처는 이번 성공 여부와 별개다.
