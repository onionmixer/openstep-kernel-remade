# 남은 원본 분석 — 범위 축소 없음

## 이번 경로 다음 단계

- 실제 aging 회수 이후 다음 eligible update에서 동일 상태의 PT backing 해제를 연결한다. 기존 report34의 public-remove 이후 GC 증거와 이번 상태의 차이도 독립 확인해야 한다.
- 비어 있지 않은 free-PD queue: alloc_count 유지/해제 분기, 전체 backing 소유권, 재시작 순회.
- 여러 active/free PT, 여러 PV와 alias, replacement, 정상 tick의 연속 호출 및 wrap/sentinel 상태 진행. adversarial tick 결과를 실제 scheduler 도달성으로 간주하지 않는다.
- native IDT/RF/frame/IRETD와 실제 회수 후 재fault/retry 연결. 기존 QEMU strict RF 실패 및 설치된 패키지 소스 미확보는 해결된 것으로 취급하지 않는다.

## 전체 목표의 별도 미완료 영역

부트 메모리 탐색·실제 map/object/pmap/zone 생성, shortage/pageout/pager/COW/shadow/busy/absent/error/wait/race, scheduler/context/FPU/recover lifetime, 다중 바이트·비연속 VM/read fault, 장치/MMIO/interrupt/native TLB/cache 검증이 남아 있다.

IPC/MIG/BSD/VFS/UFS/network/DriverKit/kernserv의 체계적 의미 분석, 전체 함수별 untouched/partial/complete 근거 원장, 타입·ABI·함수 경계·인공 fragment·경고 검토, 독립 IDA 바이트/DB/export 대조, 공개 소스 함수/타입 provenance도 전체 범위에 포함된다.

GCC 2.7 정확한 툴체인 선정·실컴파일·Mach-O 링크·부팅 회귀 및 후속 아키텍처별 검증은 수행하지 않았다. 자료 확보 완료를 의미 분석이나 복원 소스 완료와 혼동하지 않는다. 원래 주석·매크로·파일 배치를 바이너리만으로 유일하게 복구할 수 있다는 주장도 하지 않는다.
