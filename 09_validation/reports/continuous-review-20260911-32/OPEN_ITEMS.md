# 보고서32 이후 잔여 분석

[보고서31 전체 의무](../continuous-review-20260911-31/OPEN_ITEMS.md)를 유지한다.
이번에는 익명 단일-byte NP write fault와 실제 신규 PT 할당, 명시적 frame 경계 뒤의
원본 IRETD/복사 재시작을 연결했다. 기존 PDE를 준비하거나 pmap 직접 호출만 한
결과와 구분한다. native CPU frame과 전체 ownership은 여전히 미검증이다.

다음 주요 연결:

- 실제 쓰기로 dirty가 된 data PTE 제거: phys→vm_page lookup, clean/modified와
  reference 처리, PV 제거 및 PT retirement. 실제 VM physical segment table의
  생성 조건과 합성 lookup 준비는 구분해야 한다.
- 새 wired PT backing의 수명: user mapping 제거 후 free PT, GC/pmap_update에서
  extension/zone·kernel object page·wired mapping 해제와 전체 계수/소유권.
- 여러 PV node, 매핑 교체·회수와 alias, 여러 페이지·비연속 물리 메모리,
  VM 경계의 다중-byte copy 및 read fault.
- 실제 object/map/pmap/zone 생성과 zone backing 성장, 자원 부족/pageout/scheduler
  대기·재시도, 다른 실행 주체가 먼저 PT를 만든 경우의 정리와 동시성.
- pager device/vnode I/O, COW/shadow/copy, busy/absent/error, map 변경/재검사,
  비영 policy/sequential 등 기존 미검증 경로.

native IDT/error/frame/RF/CPL·스택·전체 문맥 전환, FS/recover 수명, 전체 startup/
boot/memory 발견/장치/비동기 인터럽트 및 실제 TLB/cache 검증도 남아 있다.
ABI/타입/함수 경계·분리 조각, CPU 부작용 모델 통합과 전체 소비자 회귀, 동일 원본
IDA 독립 대조·교정 후 재추출, 공개 소스 계보와 추적 가능한 복원 명세를 유지한다.

GCC 2.7 실제 구현/컴파일/링크/부팅 및 후속 아키텍처는 별도 미완료 단계다.
다음 코드도 독립 코딩 전 검토와 원본/Python 재검증을 거친다. 전체 목표는 완료하지 않는다.
