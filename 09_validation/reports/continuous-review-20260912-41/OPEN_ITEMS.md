# 남은 전체 분석

[report40의 전체 미완료 목록](../continuous-review-20260912-40/OPEN_ITEMS.md)을 유지한다. 이번 보고서로 해소한 것은 단일 신규 PD backing의 두 슬롯 생성/반환과 부분 사용 유지·빈 PD 회수의 제한된 경로다.

## 가까운 후속 검토

- 여러 PD backing이 섞인 free-PD 큐에서 사용 중인 항목 건너뛰기, 중간 항목 해제, queue-head 재시작을 실제 실행으로 연결한다. 단일 항목 결과를 다중 항목 검증으로 확대하지 않는다.
- PD 반환 슬롯 재할당, pmap_reference/마지막 참조 해제, nonzero software-only pmap_create, allocation failure와 올바른 호출자 전제.
- 새 PD를 실제 CR3로 활성화한 후 task/context/TLB 수명 검증. 현재 시험은 기존 root만 실행한다.
- report40 aging 퇴역 상태에서 다음 eligible 호출의 PT backing 해제를 동일 상태로 연결한다. 이번 PD 경로로 그 의무를 대체하지 않는다.
- legacy `sleepable` 입력 이름에 의존한 과거 설명을 별도 소비자 검토에서 구분한다. zone bit0와 bit1의 의미 및 실제 대기/확장 경로는 동일하지 않다. 고정된 이전 증거 파일은 수정하지 않는다.

## 계속 남는 전체 의무

native IDT/RF/frame/IRETD 및 실제 회수 후 fault/retry, scheduler/context/FPU/시간 연속성과 경합, memory discovery·전체 소유권, 다중 PV/alias/replacement, shortage/pageout/pager/COW/shadow/busy/absent/error/wait, 장치/MMIO/interrupt/native TLB/cache 분석은 별도 미완료다.

IPC/MIG/BSD/VFS/UFS/network/DriverKit/kernserv, 전체 함수별 의미 검증 원장·타입/ABI/경계/fragments/경고, 독립 IDA 바이트·DB·export, 공개 소스 계보도 전체 범위에 포함된다. GCC 2.7 실제 툴체인·컴파일·Mach-O 링크·부팅 및 후속 아키텍처별 검증은 아직 수행하지 않았다.
