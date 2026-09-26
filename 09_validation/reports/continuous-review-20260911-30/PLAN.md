# 보고서30 계획 — PT 회수·재사용과 신규 VA 확보 실패

코딩 전 `/root/vm_contract_review27`의 읽기 전용 독립 검토를 받고 root가
정본 ASM으로 재확인했다. 모든 계산은 Python. 전체 잔여 분석 의무는 보고서29를
계승하며, 이 실행 단계가 원본 PT의 전체 생성/소유권 증명이 되지는 않는다.

## 원본에서 확인한 서로 다른 계약

- pmap_expand 0x190cfc의 free PT 경로는 PT를 zero-fill하지 않는다. 원본
  remove 0x18f7f8은 present 매핑만 제거하고 기존 NP PTE 잔여 비트는 건너뛴다.
  free PT의 조건을 전체 byte zero로 바꾸지 않는다.
- PT descriptor의 PV VA는 실제 kernel mapping과 일치해야 한다. 성공 reuse에서
  당장 필요하지 않더라도 경쟁 정리/GC는 이를 kmem_free 주소로 사용한다.
- kmem_alloc_wired의 vm_map_find 실패는 반환 1로 축약된다. expand는 반환하지만
  pmap_enter는 PDE를 재검사한다. 물리 페이지 부족은 wait=1인 allocate_pages에서
  wake/sleep/retry하며 이 VA 부족 실패와 같지 않다.
- 신규 성공에는 kernel map/object, map-entry zone, free page, wiring/kernel PTE,
  extension zone이 필요하다. kernel_pmap의 PDE 부재는 panic이다. extension zalloc
  NULL을 정상 ENOMEM으로 가정할 근거도 없다.

## 이번 실행 단계

1. 보고서29 setup을 읽기 전용으로 재사용하되 원본 page alloc을 추가 실행해
   대상 data frame이 free queue에 남아 있는 상태로 매핑하지 않는다.
2. 기존 합성 PT backing에 유효한 kernel PV VA/owner와 wired PTE·국소 통계를
   준비한다. 이것은 전체 kernel_pmap 생성의 증명이 아닌 명시적인 준비다.
   추가 사전 검토에서 free queue 초기화가 필수임을 재확인했다. free sentinel
   0x1f7ad8/0x1f7adc 자기 링크, free count 0x1f7ad4=0, total PT count
   0x1f7ad0=1을 최초 deallocate 전에 설정한다. 그렇지 않으면 0인 tail을
   원본이 역참조할 수 있다. 코드는 이미 이 조건을 명시적으로 준비한다.
3. 빈 active PT를 원본 deallocate helper로 free queue에 넣는다. pmap_enter가
   원본 expand/free PT dequeue/PDE 설치를 거쳐 managed data mapping을 만든다.
4. 원본 FS scalar read로 실제 mapping을 확인한다. dirty write는 하지 않는다.
   원본 pmap_remove가 PV·PTE·통계와 마지막 PT를 회수하게 한 뒤 다른 section VA에
   같은 PT를 재사용한다. wired/unwired, A/B root, NP residue 유무를 대조한다.
   dirty 제거의 phys→vm_page 테이블과 전체 fault 프레임 연결은 별도 미검증이다.
   추가 실행 코딩 전 별도 교차검토: residue 보존만으로 NP-skip 실행을 주장하지
   않기 위해 section의 첫 VM 묶음을 원본 pmap_remove로 실제 스캔한다. target
   mapping은 다른 위치에 유지한다. 원본 0x18f8b4→0x18f8b9 분기, deallocate
   helper의 removed/wired=0/0, PT active 유지, TLB counter 증가를 검산한다.
5. 별도 fresh fixture에서 유효하지만 가용 VA가 없는 kernel map을 준비한다.
   free PT 없는 원본 expand의 vm_map_find 실패→kmem 반환→expand 복귀를 관찰한다.
   pmap_enter 반복은 다음 expand 진입의 정해진 관찰 경계에서 중지하며 함수가
   실패로 종료했다고 주장하지 않는다. 호출 mock/도중 입력 교정은 금지한다.
6. 독립 raw Mach-O/trace/byte-state 검산, 잘못된 증거 거절, 코드 후 독립 검토,
   결정성 재실행 및 보존 해시 확인 후 보고서를 확정한다.

## 다음 단계도 그대로 유지

신규 PT의 실제 wired page 할당/zero/kernel mapping/zone extension 할당 성공,
zone backing 성장, allocation 실패/대기, 동시 확장 경쟁 정리, 전체 pmap/object
생성과 GC는 끝난 것으로 취급하지 않는다. free-list 성공을 신규 성공의 대체로
삼지 않는다. 원본 바이너리·DB·exports·reference·이전 보고서·07_kernel 보존.
