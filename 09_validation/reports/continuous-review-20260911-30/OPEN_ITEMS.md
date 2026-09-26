# 보고서30 이후 잔여 분석

[보고서29 잔여 의무](../continuous-review-20260911-29/OPEN_ITEMS.md)를 모두 유지한다.
이번 결과는 준비된 PT의 원본 회수·재사용 및 실제 kernel VA 고갈 경로다.

우선 계속할 범위:

- 신규 PT의 실제 kmem wired allocation 성공. kernel map/object/entry zone,
  실제 free page·zero-fill·wiring·kernel PTE·extension zone·user PDE 설치를
  원본으로 연결하고 out VA/반환0만으로 성공을 대신하지 않는다.
- zone backing 신규 성장, physical-page 부족의 pageout/scheduler 대기·재시도,
  zone NULL/자원 실패와 실제 진행 조건.
- 동시에 다른 실행 주체가 먼저 PT를 만든 뒤의 extension/kernel mapping 정리,
  GC/pmap_update의 재사용되지 않은 PT 해제 및 전체 소유권·계수.
- dirty PTE 제거의 phys→vm_page 조회와 clean/modified 처리. 이번에는 FS read와
  reference 상태만 검증했다. 원본 pmap 수준 wired flag/count 시험은 실제
  vm_page 전체 wiring 수명이나 신규 wired allocation 증거가 아니다.
- 여러 PV mapping/node의 제거·대체·할당·회수, 실제 pager I/O, COW/shadow/copy,
  busy/absent/error, map 변경/재검사와 실제 경합.
- 보고서29 fault 경로에 이번 PDE 확장/회수를 포함한 전체 연결. 이번 PT 시험은
  pmap 함수 직접 호출과 원본 FS read이고 새 trap-frame 통합 시험이 아니다.

전체 startup/boot/memory 구성과 실제 object/map/pmap 생성, native CPU IDT/error/frame,
CPL/스택/전체 문맥 전환, VM 경계·비연속 물리 페이지 복사, FS/recover 수명,
장치·동시성·실제 TLB/cache, ABI/타입/함수 경계 및 분리 조각, CPU 부작용 모델
통합·전체 소비자 회귀, 동일 원본 IDA 대조·교정안 재추출, 공개 소스 계보·복원 명세도
남아 있다. GCC 2.7 실제 구현/컴파일/링크/부팅과 후속 아키텍처 역시 미완료다.

원본 신규 성공의 다음 선행조건은 [PT 계약](PT_CONTRACTS.md)에 주소별로 기록했다.
코딩 전 독립 검토와 root의 원본/Python 재검증 원칙을 계속 적용한다. 전체 목표를
이번 유한 사례의 성공으로 축소하거나 완료 처리하지 않는다.
