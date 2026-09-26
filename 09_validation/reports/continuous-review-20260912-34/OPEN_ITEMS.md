# 보고서34 이후 잔여 분석

[보고서33 잔여 목록](../continuous-review-20260911-33/OPEN_ITEMS.md)의 전체 의무를 유지한다.
이 보고서는 합성 caller/tick/PD empty queue 입력하에서 신규 wired PT backing
회수를 실제 fault/write/remove 이후에 연결한 제한된 사례다. 전체 boot에서 해당
입력이 자연스럽게 만들어지거나 모든 물리 소유권이 정당함을 증명하지 않는다.

## 우선 후속 검토

- 반환된 PG/EXT/map entry의 실제 재사용과 수명, 이전 user/KVA 접근과 stale alias.
  PT frame이 이미 0이라는 사실을 zero routine 실행 또는 이후 재사용 안전성과 혼동하지 않는다.
- PD free 회수, active PT aging, 여러 항목/경합, tick wraparound와 signed gate.
- 감사기 일반 메모리 EA/값/GPR/flags·분기 조건의 독립 의미 검증. 현 보완은
  관찰 GC 명령의 쓰기 개수/폭, 보호 주소, ESP/EBP/CALL/RET에 한정한다.
- 기존 전체 소비자에 동일 감사 취약점이 있는지 새 보고서에서 읽기 전용 회귀.
  이번33 회귀는 stack만이다. MOVZX 등의 명령 및32 pushal/IRETD/CPU frame은
  별도 계획·원본 검토·반례 검증이 필요하다. 이전 확정 파일은 수정하지 않는다.

## 유지되는 전체 의무

- 여러 PV/alias/교체, 다중·비연속 페이지와 VM 경계 copy, 실제 object/map/pmap/
  zone 생성, memory discovery/전체 ownership.
- 자원 부족/zone 성장/pageout/대기·재시도/경합, pager I/O/COW/shadow/copy/
  busy/absent/error/map 변경/policy와 동시성.
- native IDT/error/frame/RF/CPL/FS/recover 수명, 문맥 전환·scheduler/startup/boot,
  장치/MMIO/비동기 IRQ와 실제 TLB/cache/hardware 검증.
- ABI/타입/함수 경계·분리 조각·CPU 부작용/전체 소비자 회귀, 동일 원본 IDA
  독립 대조·실패/교정 후 재추출, 공개 소스 계보와 복원 명세.
- 정확한 GCC 2.7.x/NeXT target 및 도구 고정, 실제 compiler/ABI probe, 전체
  소스 컴파일·Mach-O 링크·부팅. 현대 컴파일러는 대체 검증이 아니다.
- x86 이후 SPARC와 후속 CPU의 범위 확정 및 독립 분석·GCC 2.7 빌드/부팅.

바이너리만으로 원래 주석·매크로·파일 구성을 유일하게 복원할 수 있다고 보장하지 않는다.
자료 확보/제한된 경로 검증과 온전한 커널 소스 복원 완료를 구분한다.
