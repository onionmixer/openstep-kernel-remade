# 104차 범위와 검증 방법

## 허용 자료와 변경

원본 x86 mach_kernel, 해당 Ghidra full-pass5 ASM/C/metadata, 원본 심볼/section,
기존 원본 분석 보고서와 정책만 사용했다. 01_resources/07_kernel 및 다른 커널 코드,
외부 문서·웹·저장소는 열지 않았다. 과거 외부 소스 비교 결론은 신규 의미 근거가 아니다.
원본/DB/export/확정 보고서는 불변으로 두고 이번 디렉터리만 추가했다.
실행·에뮬레이션·소스 구현·복원·빌드·포팅은 수행하지 않았다.

Ghidra 스킬의 해독/참조/원본 대조 절차를 기존 export와 원본 바이트에 적용했다.
live Ghidra/IDA DB 조작은 하지 않았다. 신규 독립 계획 검토를 받은 것으로 처리하지 않는다.
inline Python은 정적 decode/assertion/수치 검증용이며 커널 실행 모델이 아니다.

## 선택 본문

- 0x15ab9c initKernelStacks, 0x15abe0 freeStack, 0x15ad60 newStack, 0x15ae5c allocStack.
- 0x15b098 canSwap, 0x15b0dc doSwapout, 0x15b19c swapoutStack, 0x15b2b4 swapinStack.
- 0x168b28 stack_init, 0x168b50 stack_finalize, 0x168afc stack_usage,
  0x15b494 stack_collect, 0x15b49c stack_statistics, 0x166a5c stack_privilege.
- 0x18e0e4 start_initial_context, 0x18cbcc ldt_init,
  0x173e90 kmem_free, 0x173d1c kmem_alloc_wired.
- 이전 결과의 연결부: 0x186f20 __switch_tss, 0x186f74 __stack_attach,
  0x1639ec thread_continue, 0x18d208 stack_attach, 0x18d238 stack_detach,
  0x15b398 stack_alloc_try, 0x15b470 stack_free, 0x15b43c stack_alloc.
- metadata에 분리된 기존 fragment 0x15b455. panic 다음 fallthrough 바이트이며
  별도 일반 함수나 실제 panic 복귀 성공으로 세지 않았다.

선택 본문의 명령은 모두 raw decode했다. 새 의미 검토 대상의 ASM/C를 대조하고,
이미 검토한 연결부의 C/metadata도 다시 해시 대조했다. 단순 재해시를 신규 전체 의미 검토로
합산하지 않는다. 선택 목록 밖 조사 명령에는 selected_whole_body=false를 명시했다.

## 재검증

1. 103차 checkpoint 고정 SHA와 그 파일 크기/해시, 이전 입력과 보존 항목을 다시 검사한다.
   현재 정책의 원본 분석 범위 밖 항목은 열지 않고 제외 이유를 남긴다.
2. mach_kernel SHA, Mach-O magic/CPU/segment/section/file mapping을 검사한다.
   파일에 없는 zerofill global은 section만 기록하고 파일 초기값을 부여하지 않는다.
3. 선택 ASM의 각 명령 길이만큼 원본을 읽어 Capstone 4.0.2 x86-32로 단일 명령 해독한다.
   metadata body의 byte 집합과 명령 집합 일치, 중복 없음, 직접 분기 head를 검사한다.
4. 핵심 명령 텍스트·호출 대상·WORD operand·잠금 호출 순서·VM 상태 미검사 구간,
   추가 NOP-tolerant TEST loop를 원본으로 확인한다. 조건부 geometry와 DWORD/WORD/BYTE
   연산, descriptor flag의 BYTE 전 범위 사례를 Python으로 계산한다.
5. full-pass5 ASM 전체의 파일 해시를 manifest와 검사한 뒤 지정 직접 CALL와
   명시 global displacement 쓰기만 조사한다. 주소 alias·bulk 초기화·간접 호출은 제외한다.
6. evidence/preservation JSON을 새 계산 결과와 정확히 대조하고 문서 링크와 최종 파일
   크기/해시를 checkpoint에 기록한다. 마지막에는 fresh 재실행으로 다시 검사한다.

Python 계산 결과: 일반 26 + fragment 1 본문, head 1124, byte 3450,
direct branch 107, direct CALL 64, indirect transfer 4, warning 14,
핵심 명령 156, 현재 입력 89, 기존 보존 922, global 객체 22.
strict adjacent load/TEST/JNZ 패턴은 0, NOP를 제외한 같은 레지스터 TEST backedge는 1이다.
두 기준을 섞거나 이 집계를 모든 lock loop의 수라고 부르지 않는다.

전체 ASM 모집단 해시:
`742617851f014a94309d47296900fc5e27b5ad5a862f588590559fe5f334471d`.
이 해시는 sorted path/size/SHA 객체 목록을 Python JSON으로 직렬화한 SHA-256이다.
입력 파일 내용이 보존되었다는 검사이지 모집단 전체 의미의 독립 검증이 아니다.

## 유보

cache list/count/state의 전체 writer와 IRQ/lock 전제, reserve의 모든 수명,
VM page alignment/backing/fault/remove/rollback, pageable return status의 실제 영향,
stack debug runtime 설정, descriptor/CPU/continuation 유효성은 미완료다.
원본 코드에서 자체 검사가 없다는 사실을 즉시 취약점·충돌·hang으로 바꾸지 않는다.
자료 생성·정적 assertion 통과·독립 검토·실제 실행 성공은 별도 판정이다.

[결과](README.md) · [원본 증거](object-lifetime-evidence.json) · [남은 분석](OPEN_ITEMS.md)
