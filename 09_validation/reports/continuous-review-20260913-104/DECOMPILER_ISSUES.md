# 104차 디컴파일 표현과 원본 동작의 차이

아래는 원본 바이트와 대조한 해석상의 주의점이다. 오류가 아닌 단순 추상화나
이미 C에도 보이는 조건부 위험은 따로 구분한다. 분석 DB/C export는 수정하지 않았다.

## CPU 쓰기 누락과 selector의 상수화

start_initial_context 0x18e0e4의 C에는 0x18e128 MOV CR3,EAX와
0x18e1c2 MOV CR0,EAX가 없다. 원본은 CR3를 무조건 게시하고 CR0에 0x8을 합쳐 쓴다.
따라서 C만으로 CPU 부작용을 추론하면 누락된다.
LLDT 0x18e16e와 LTR 0x18e1b6은 각각 메모리 WORD operand인데 C는
LocalDescriptorTableRegister(0x20)/TaskRegister(0x18)로 표현한다.
파일의 해당 값은 일치하지만 runtime selector 불변성까지 의미하지 않는다.

## stack_finalize의 인자·반환과 lock 반복

C는 undefined4 __regparm1 stack_finalize(param_1,param_2)로 표현한다.
원본 0x168b53은 `[EBP+8]`을 스택 주소로 소비한다. freeStack의 호출도
0x15ad1e LEA, 0x15ad21 PUSH, 0x15ad22 CALL로 물리 스택 인자를 전달한다.
당시 EAX에도 같은 주소가 있었다는 사실은 별도의 필수 regparm 인자를 증명하지 않는다.
debug가 꺼진 경로의 EAX 잔여값을 의미 있는 API 반환이라고 확정하지 않는다.

C의 `while (_stack_usage_lock != 0)`는 메모리를 매번 다시 검사하는 듯 보인다.
실제 0x168b80은 EAX를 한 번 load하고, NOP 뒤 0x168b88 TEST EAX,EAX,
0x168b8a JNZ 0x168b88로 돌아간다. backedge 안에는 메모리 load가 없다.
XCHG 뒤 XOR/TEST/JZ의 별도 retry도 원본 그대로 보존했다.
이는 정적 분기 사실이며 debug 설정·진입 상태·IRQ와 전체 lock 동시성을 닫지 않은
실제 deadlock 판정이 아니다. 기존 strict 인접 패턴 검사가 NOP를 사이에 둔 사례를
세지 않는 한계를 이번의 별도 NOP-tolerant 결과로 명시했다.

## kmem_alloc_wired의 반환 폭

C의 반환형은 undefined1이다. 원본 map_find 실패 경로는 SETNZ AL 뒤
AND EAX,0xff로 DWORD 결과를 정규화한다. 하위 할당 실패에는 MOV EAX,6,
성공에는 XOR EAX,EAX가 있으며 caller는 TEST EAX,EAX를 사용한다.
BYTE형 C를 실제 호출 ABI/상위 비트 불확정성의 근거로 쓰지 않는다.
VM 상태 미검사와 성공 출력 게시 순서는 원본과 C 모두에서 보이는 별도 계약 문제다.

## 특수 context helper의 정상 C 호출/return 표현

현재 start_initial_context 호출 지점 C에는 __switch_tss(0,B,0)의 세 인자가 보인다.
그러나 helper 자체 C의 추정 서명과 정상 return 표현만으로 이 ABI를 판단할 수 없다.
원본은 POP에 맞춰 스택 offset을 바꾸고 세 번째 인자를 EAX로 전달하며 새 ESP/EIP로
JMP한다. 첫 trampoline은 PUSH EAX/CALL EBX이고 반환 뒤 HLT loop가 있다.
새 문맥 준비에 따라 도달성이 달라지므로 C epilogue 존재를 정상 복귀 증거로 삼지 않는다.

## 디컴파일 오류로 오인하지 않을 원본 조건

- allocStack의 count!=0/head==sentinel 후 NULL 기반 상태 쓰기는 원본에도 있다.
  C가 만들어낸 가짜 NULL 분기라고 제거하지 않는다. 실제 불일치 발생은 미확정이다.
- freeStack의 cache unlock 후 조건 검사·목록 제거는 원본에도 있고 C에도 보인다.
  편의상 전체 함수를 하나의 critical section으로 다시 읽지 않는다.
- kmem_free의 H 인자는 원본에도 있다. 조건부 페이지 반올림으로 같은 전체 페이지가
  되므로 임의로 pagebase 인자로 교정할 이유로 삼지 않는다.
- swapinStack의 상태 0 load/store와 signed magic 표현은 원본 바이트와 대조했다.
  의미 없는 듯한 store를 임의 삭제하지 않는다. magic의 signed/unsigned 수치는 Python으로 계산했다.
- stack_statistics는 두 번째 출력의 기존 값과 비교한다. 자체 0 초기화가 C에서만
  빠진 것이 아니라 원본에도 없다. 호출자 초기화 여부는 후속 검토 대상이다.
- stack_collect는 원본도 no-op이다. 이름을 보고 누락된 GC 동작을 보충하지 않는다.
- stack_init/stack_finalize는 debug 조건부이며 cache 재사용은 자체 초기화를 하지 않는다.
  함수 이름만으로 zeroing·fresh contents·overflow 보호를 보장하지 않는다.

경고 14줄은 [기계 판독 증거](object-lifetime-evidence.json)에 원문 보존했다.
경고 수는 오류 수와 같지 않으며 경고 부재도 정확한 ABI·수명·동시성의 증명이 아니다.

[결과](README.md) · [남은 분석](OPEN_ITEMS.md)
