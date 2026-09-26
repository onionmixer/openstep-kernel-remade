# 보고서26 코딩 전 계획 — resident 매핑 권한 교정과 fault 재시작

보고서25는 권한 거절 및 권한 허용 분기까지만 검증했다. 다음에는 이미 resident인
페이지를 원본 VM 조회로 찾고, 원본 pmap_enter의 같은 물리 매핑 RO→RW 경로를
거쳐 실제 fault 명령으로 돌아가는 연결을 시험한다. pager I/O/page-in이나 부재
페이지 할당 성공으로 축소·대체·확대 해석하지 않는다.

## 코딩 전 독립 검토

`/root/trap_plan_review`가 파일 수정·시험 없이 원본 ASM·바이트·공개 소스를 읽었다.
root도 pmap_enter, vm_page_insert/lookup/activate, lookup_done, object_deallocate,
spl 계열과 VM fault의 관련 원본 분기를 직접 읽었다. 의견은 실행 가능성 증명이 아니다.

검토자가 제시하고 root가 원본으로 대조한 주요 계약:

- object ref_count+0x18와 resident_count+0x1a는 원본 WORD. 공개 헤더의 int를
  그대로 복사하지 않는다. copy/shadow·busy/absent/error/wanted·COW는 제외한다.
- 원본 vm_page_insert를 fault 전에 실행하여 hash·memq·tabled bit·resident count를
  만든다. object/page/pmap의 나머지 합성 입력과 원본 생성 결과를 구분한다.
- 활성 사용자 pmap으로 설정하고 실제 INVLPG FS 및 원본 PTE store를 관찰한다.
  비활성으로 꾸며 invalidation을 우회하지 않는다. 같은 물리 frame 경로는 PV/
  page-table 신규 할당 증거가 아니다.
- fault 후 PTE 수정 API나 원본 함수 반환 mock을 사용하지 않는다. 명시적
  same-CPL CPU frame 주입 경계는 유지하며 native IDT 전달과 구별한다.
- vm_fault=0 뒤 recover helper를 호출하지 않아야 한다. saved EIP/CS/EFLAGS는
  그대로이고 IRETD는 관찰한 fault 명령으로 돌아가 재실행해야 한다.
- 성공에서 DF를 임의로 해제하지 않는다. 짧은 copy의 recover 잔존 규약을 유지한다.
- 버퍼·다른 root·frame·caller·lock·참조/paging 수·page queue와 원본 PTE 쓰기
  순서 및 invalidation을 검증한다. SPL의 pending callback/I/O 조건도 기록한다.

## 게이트와 보존

처음에는 fresh 단일 사례로 실제 원본 경로를 관찰하고, 실패하면 trace와 CPU/객체
상태를 새 보고서에 보존한다. 모델 오류와 CPU backend 한계를 원본 결함으로
판정하지 않는다. 통과 후 독립 산술/trace 검산과 재현을 수행한다.

모든 계산은 Python. 이전 보고서·원본 바이너리·Ghidra/IDA DB·reference sources·
07_kernel은 변경하지 않는다. 전체 잔여 분석 목록을 계승하고, 이번 범위 통과로
전체 분석·GCC 2.7 구현/빌드·부팅 완료를 선언하지 않는다.

## 추가 코딩 전 검토 반영

통계는 전체 PTE 개수에서 추정하지 않는다. 같은 물리·동일 wired 경로에서 pmap
resident/wired 통계는 미사용 합성 입력이며 불변·미접근을 검사한다. 전체 root의
소유권·PV·통계 정합은 미검증이다. object_init의 미초기화 template는 사용하지
않고 합성 object를 명시한다. vm_page_insert는 fault 전 object lock/page busy
상태에서 호출하고, 그 뒤 준비 경계에서 해제하여 fault 관찰을 시작한다.
SPL은 실제 초기 IPL과 같은 값으로 복원되는 조건을 확인하고 callback/OUT의
미실행을 검사한다. 이 추가안도 독립 검토자가 읽기 전용으로 검토했으며 root가
원본 lock/insert/pmap 통계 helper 명령을 직접 대조했다.

## active 초기 queue 확장의 코딩 전 검토

최초 unqueued 대조를 유지하면서 원본 vm_page_activate로 초기 active 상태를 만든
대조를 추가한다. insert 뒤 object lock/page busy를 유지하고, queue lock 아래
activate한 다음 queue lock을 해제한다. 그 뒤 fault 전 준비 경계에서 object
lock/busy를 해제하고 copy caller를 다시 설정한다. 독립 검토자는 이 순서를
읽기 전용으로 확인했다. root는 원본 activate와 dequeue 명령을 직접 대조했다.
dequeue는 page 자신의 next/prev를 지우지 않으므로, 중간에는 header=self/count0/
active bit 해제를 검사하고 마지막에 active header/pageq/count 복원을 검사한다.
