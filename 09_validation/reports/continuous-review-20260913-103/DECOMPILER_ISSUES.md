# 103차 디컴파일 대조 주의점

- **thread_select 순서**: 0x163589의 queue count 쓰기는 0x1635b3 unlock 전이다.
  C는 같은 global의 감소를 unlock 뒤에 표시한다. 이 차이는 lock 보호 범위 판단에 중요하다.
- **switch helper ABI**: __switch_tss 0x186f20의 C 선언은 두 인자지만 원본은
  세 번째 stack 인자를 EAX로 새 문맥에 전달한다. ESP 교체·복원 register·JMP를 일반 C 호출/return으로 대체하지 않는다.
- **switch_context 반환**: void C 선언만으로 반환값을 무시하지 않는다.
  실제 새 문맥에서 전달되는 EAX와 thread_invoke의 dispatch 인자를 연결한다.
- **CR3/CR0**: stack_handoff/switch_context C는 실제 CR3 비교·쓰기와 CR0 쓰기를
  생략하거나 CR0 OR을 반환식으로 바꾼다. 원본 명령을 우선한다.
- **LLDT/LTR**: C의 고정 selector 값과 달리 raw는 memory WORD를 읽는다.
  파일 값 0x20/0x18과 runtime 값의 불변성을 구분한다.
- **trampoline**: __stack_attach 0x186f74의 입력은 EAX에서 PUSH되고 목적지는 EBX다.
  C의 __regparm3 한 인자 선언을 전체 ABI 증명으로 세지 않는다. 반환 뒤 HLT가 C에서 빠진다.
- **dequeue NULL 분기**: 같은 레지스터 비교가 연이어 있어 자체 조건이 모순되는 분기다.
  C에 NULL 대입이 있다는 이유만으로 실제 NULL 반환 경로를 선언하지 않는다.
- **priority**: bucket index의 unsigned 보정과 T+0x58 저장값 및 signed 선점 비교를 구분한다.
  지역 index=31을 thread priority=31 쓰기로 바꾸지 않는다.
- **lock 표현**: 일부 global lock 획득은 C의 LOCK/UNLOCK만으로는 원본 XCHG/재시도를 온전히 표현하지 못한다.
  또한 register-only spin back edge를 반복 메모리 읽기로 수정하지 않는다.

원본과 C의 차이는 전체 C를 폐기하거나 실제 장애를 확정한다는 뜻이 아니다.
5개 fragment는 panic 뒤 fallthrough 확인이며 독립 callable ABI로 보지 않는다.
경고 행의 수는 독립 결함 수가 아니다.

[명령·C 발췌](object-lifetime-evidence.json) · [남은 분석](OPEN_ITEMS.md)
