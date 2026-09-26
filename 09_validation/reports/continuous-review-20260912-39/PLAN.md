# pmap_update 시간·aging 경계 — 구현 전 분석

보고서34가 남긴 tick wraparound/active PT aging을 원본 명령에서 조사한다.
보고서37–38의 native 예외 전달 미검증은 그대로 유지하며 이 시험으로 대체하지 않는다.

root는 Ghidra의00191144 ASM/C/JSON, 원본 Mach-O 바이트, Darwin0.1 i386 pmap.c의
pmap_update와 pmap_private.h의 pg_exten 선언을 직접 읽었다. Ghidra 스킬을 사용하며
원본 DB/export와07_kernel은 변경하지 않는다. 공개 소스와 원본 ABI의 대응은 필요한
필드/연산 단위에 한정하고 함수 전체가 동일하다고 단정하지 않는다.

## 확인할 계약

- sched_tick/last의32-bit 차이, signed JLE, SAR3, aging 표의 상한 분기.
- age byte 덧셈/잘림과 unsigned old>new, threshold>=(new age)의 구분.
- wired_count16bit/PDE present/refer에 따른 age reset 또는 유지.
- last=0 초기화와 마지막 last+=delta의32-bit 결과 및 wrap 후 재초기화.
- 음수 index는 원본에 하한 검사가 없다. 표 앞 읽기와 원래 map 밖 주소를 구분하며,
  인덱스를 clamp하거나 임의 RAM을 만들어 성공시키지 않는다.

## 실행 범위

Unicorn32-bit flat-segment 합성 환경에 원본 TEXT/DATA/OBJC를 로드한다. paging/IDT/
RF·실제 TLB를 검증하지 않는다. free PT/PD queue는 비어 있고 active PT는 합성 단일
extension 또는 빈 queue다. 실제 object/map 생성·자원부족·동시성도 미검증이다.

원본 pmap_update 진입부터 실행하여 회수 결정001912f6 전에 멈추거나, 회수하지 않는
경로는 원래RET까지 실행한다. 중단을 실제 pmap_remove/자원 회수 완료로 표현하지 않는다.
threshold 읽기에서 UC mapping 밖 접근이 발생하면 실제 관찰 실패로 기록하고,
원래 OPENSTEP의 high-segment/paging에서 같은 fault가 난다고 주장하지 않는다.

모든 age byte 값과 주요 양의 delta 경계를 교차하고, refer/wired/NP/zero/negative/
32-bit wrap/last=0 조건을 별도로 대조한다. Python의 독립 산술 모델과 원본 실행의
분기·threshold EA/값·age/PDE/last 및 쓰기를 비교한다. 입력/trace/실패는 모두 보존한다.
계산·크기·주소·해시·집계는 반드시 Python으로 수행한다.

vm_contract_review27에게 코딩 전 계획 교차검토를 요청했다. root의 독립 확인과
교차검토 의견을 구분해 기록하며, 전수CPU 의미 검증/전체 분석 완료를 주장하지 않는다.
