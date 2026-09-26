# 잔여 작업 — 보고서36 진행 중

이 문서는 이전 [전체 잔여 의무](../continuous-review-20260912-35/OPEN_ITEMS.md)를
대체하거나 축소하지 않는다. 자료 확보, 한정된 원본 실행 검증, 실제 커널 복원 완료를 구별한다.

## 이번 경계에서 남은 것

- 실제 GC→copyout/copyoutmsg의 두 번째 fault→기존 DATA lookup→새 PT→IRETD→retry.
  현재 vector8 진단에서 중단한다. direct pmap_enter 보조 성공으로 대체하지 않는다.
- hook/manual CPU frame과 실제 IDT 예외 전달의 차이, 반복 fault 실행기 상태,
  RF/CPL/스택/segment cache 등 CPU 계약. 숨은 필드 조작 없이 검증 경계를 설계한다.
- 새 감사의 민감 필드 밖 GPR/flags/effective-address/모든 중간 산술·분기 조건.
  원본 바이트 기반 trace 경로 합법성은 완전한 CPU 의미 증명이 아니다.
- 다양한 resource shortage·wait/retry·zone 성장·소유권 경합·pageout 환경의 재사용.
  이번 seed는 단일 CPU·고정 객체/zone/물리 자원 전제다.

## 계속 유지되는 전체 범위

PD/PT aging과 tick 경계, multi-PV/alias/replacement, 실제 map/object/pmap 생성,
boot/물리 메모리 발견, pager I/O·COW/shadow/busy/absent/error/map 변경,
스케줄러·context switch·FS recover 수명, 다중 바이트/VM 경계/read fault,
장치·MMIO·interrupt·실제 TLB/cache, ABI/타입/함수 경계·누락 fragment,
IDA 독립 대조와 export 실패 재검토, 공개 소스 계보 및 복원 근거 추적이 남아 있다.

GCC 2.7의 실제 선택/ABI probe/전체 compile·Mach-O link·boot 검증은 미완료다.
현대 컴파일러 검사로 이를 대신하지 않는다. 후속 SPARC 및 기타 CPU 대상도 별도다.
원본 주석·매크로·파일 배치는 바이너리만으로 유일하게 복원된다고 주장할 수 없다.
