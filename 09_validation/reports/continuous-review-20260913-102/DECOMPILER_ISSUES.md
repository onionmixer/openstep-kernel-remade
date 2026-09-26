# 102차 디컴파일·원본 대조 주의점

## 실제로 다른 표현

- `check_for_ast` 0x1929e8의 0x192a04/0x192aa6 CLI가 C에서 사라진다.
  snapshot을 단순 전역 변수 계산으로만 옮기면 IRQ 전제를 잃는다.
  자체 STI가 없다는 사실만으로 하위 호출까지 포함한 최종 IF를 확정하지 않는다.
- `__call_with_stack` 0x186f7c는 ESP+4 목적지와 ESP+8 새 스택을 읽고
  ESP/EBP 교체 후 JMP EAX한다. C는 두 번째 입력과 스택 교체를 누락하고
  간접 jump를 call로 취급했다는 warning과 함께 정상 return처럼 표시한다.
- `thread_halt_self` 두 변형의 C는 `_ipc_thread_terminate()`, `_thread_hold()`,
  `_splx()`, `_thread_wakeup_prim()`, `_thread_block_with_continuation()`의 실제 PUSH 인자를
  호출 인자 대신 임시 stack 변수에 흩어 놓는다. 원본의 호출 인자와 continuation 선택을 따른다.
- 같은 self halt C의 reaper 잠금 획득은 LOCK/UNLOCK 표기만 남기고 1을 XCHG하는
  원본 획득·재시도 표현이 불완전하다. 원본에서 획득과 해제를 별도로 확인한다.
- `thread_invoke`의 continuation 뒤 `return 1`과 IPC 정리의 부수적 EAX 반환을
  native 호출의 완전한 정상 반환 계약으로 승격하지 않는다.

## 타입·분류 오독 방지

- 참조 수 T+0x24, hold 수 T+0x40, wait 결과 T+0x44, wait 표식 T+0x48은 서로 다르다.
  self 종료 enqueue 자체에는 interrupt deallocate처럼 참조를 1로 만드는 쓰기가 없다.
- thread_dispatch는 상태 DWORD에서 bit 8/9만 제거하고 비교한다.
  전체를 low nibble switch라고 표현하면 상위 비트 조건이 달라진다.
- event의 signed 음수 처리에는 NOT이 쓰인다. `abs()`나 단순 unsigned modulo로 바꾸지 않는다.
- need_ast의 snapshot 제거와 문맥 교체 mask는 서로 다른 산식이다.
  전자는 현재값 AND NOT snapshot, 후자는 AND 0xbffffffc 후 새 T+0x17c OR다.
- clear_wait와 inline wakeup의 표는 정상 상태 분류가 같아도 default 경로가 다르다.
  clear_wait는 자체 정리 없이 빠지고 inline wakeup은 panic한다.

## 분석 경계

9개 fragment의 원본은 panic 뒤 stack adjustment와 fallthrough다.
독립 정상 반환 함수나 panic의 실제 반환 증거로 취급하지 않는다.
register-only TEST로 되돌아가는 50개 spin 패턴은 원본 관찰이며,
C가 메모리를 반복해서 읽는 표현을 실제 원본 명령으로 대체하지 않는다.
네이티브 deadlock을 실행해 입증한 결과도 아니다.

기계 명령·폭·표·C 발췌는 [증거](object-lifetime-evidence.json)에,
호출·동시성 미완료는 [남은 분석](OPEN_ITEMS.md)에 보존한다.
