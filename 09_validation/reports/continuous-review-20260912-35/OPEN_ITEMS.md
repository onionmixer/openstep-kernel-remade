# 보고서35 이후 잔여 분석

[보고서34 전체 잔여 의무](../continuous-review-20260912-34/OPEN_ITEMS.md)를 유지한다.
이번에 검토한 것은 기존31–34 기록의 제한된 write cardinality/실제 stack 흐름이다.
기존 증거의 신뢰성 범위를 보완했으며 전체 복원 목표를 축소하지 않는다.

## 감사 검증의 남은 경계

- 31 이전 소비자의 trace/stack/memory 의미 회귀. inventory는 검토 대상을 찾는
  lexical/AST 목록이며 취약점 전수 검출이나 전수 안전성 판정이 아니다.
- 모든 GPR 산술·flags·실제 분기 조건·일반 메모리 EA/값·읽기/쓰기 부작용.
  이번 known 추적은 POP/POPAD로 얻은 값과 일부 stack 관련 EBX에 한정한다.
- 기존32 fault 이전 copy prologue의 stack 쓰기 기록은 handler의 writes에 없다.
  마지막 NP store는 실패한 head다. 이번 cardinality는 injected 이후 handler만
  대상으로 하며 prefault 전체 쓰기를 독립 검증했다고 주장하지 않는다.
- 전체 세그먼트/descriptor/privilege/frame/RF/NT/VM/IRETD 실CPU 규칙과 비동기
  이벤트. current NT/VM·CS/SS 지원 전제와 raw EIP/CS/EFLAGS 대조는 일반
  EFLAGS 실행모델이나 실제 IDT 예외 전달 증명이 아니다.
- checkpoint 사이 알려진 값이 unknown으로 내려가는 구간, 명시적 일반 stack
  store의 EA/값 provenance, PUSH의 미추적 GPR 값에 대한 더 강한 검증.
- 동일 원본 IDA 독립 대조와 실패/함수경계·ABI 교정 후 재추출.

## 이어갈 실제 커널 분석

반환된 PG/EXT/map entry의 재사용·수명과 stale alias, PD free/active PT aging/
tick wraparound, 여러 PV/alias/교체, 다중·비연속 VM 경계 접근, 실제 object/map/
pmap/zone 생성·memory discovery/전체 ownership이 남아 있다.
자원 부족/zone 성장/pageout/대기·재시도/경합, pager/COW/shadow/copy/busy/absent/
error/map 변경/policy, scheduler/문맥전환/전체 boot/장치/MMIO/IRQ/실제TLB/cache도 남는다.

전체 ABI/타입/함수경계·조각과 공개 소스 계보·복원 명세, GCC2.7 정확한 도구 고정/
실compiler probe/전체 컴파일·Mach-O 링크·부팅, x86 이후 SPARC와 후속 CPU별
독립 분석·빌드 검증도 완료하지 않았다. 원래 주석/매크로/파일배치의 유일 복원은
바이너리만으로 보장할 수 없다. 현재 단계는 구현 전 분석이다.
