# 원본 PD 생성·슬롯 반환·backing 회수

원본 `pmap_create`/`pmap_destroy`/`pmap_update`를 연속 실행하여, 실제 새 PD backing의 부분 사용과 최종 회수를 검토했다. 기존 PT를 PD라고 바꾸어 이름 붙인 시험이 아니다. 전체 커널 분석이나 복원 구현 완료를 뜻하지 않는다.

## 실행과 검증 범위

- 실행 root A/B, zone bit0 모드, 슬롯 반환 순서를 조합한 8개 사례와 60개 호출 단계를 검증했다.
- 원본 instruction head 88,248개, 쓰기 30,248개, kernel PDE 복사 4,096개를 기록했다.
- 각 PD의 kernel PDE 복사는 원본 source 주소·값, destination KVA·물리 주소, 실제 write와 연결했다. 새 PD는 실행 CR3로 활성화하지 않았다.
- 기록 변조 36개를 모두 거부했다. 같은 backend에서 실행·감사·변조 대조·근거 검증을 다시 수행하여 산출물 6개의 SHA-256이 모두 일치했다. 이는 독립 backend나 실기기 재현을 뜻하지 않는다.

기본 반환 순서에서의 원본 상태 변화는 다음과 같다. 반대 순서도 별도 실행했다.

| 단계 | PD alloc_count | bitmap | free-PD 항목 수 | backing |
|---|---:|---:|---:|---|
| 첫 슬롯 생성 | 1 | 1 | 1 | wired |
| 부분 사용 GC | 1 | 1 | 1 | 유지 |
| 두 번째 슬롯 생성 | 2 | 3 | 0 | 동일 backing 공유 |
| 첫 슬롯 반환 | 1 | 2 | 1 | wired 유지 |
| 부분 사용 GC | 1 | 2 | 1 | 유지 |
| 마지막 슬롯 반환 | 0 | 0 | 1 | 아직 wired |
| 빈 PD GC | 0 | 0 | 0 | 원본 경로로 free |

free-PD는 완전히 빈 페이지만의 큐가 아니다. 사용 가능한 슬롯이 남은 부분 사용 페이지도 들어가며, GC는 사용 중인 슬롯이 없는 항목만 회수한다.

## 새로 확인한 중요한 차이

원본 kernel-PDE 복사가 두 backing hardware PTE를 dirty하게 만든다. 마지막 GC에는 PG 물리 조회가 세 번 있으며, 그중 두 번은 각 dirty PTE 처리에 해당한다. PG 상태 바이트는 관찰 지점에서 `22→02→08`로 진행하며 descriptor attribute는 최종 3이다. 기존 clean-PT 회수의 `28`을 적용하면 틀린다.

`kmem_free`가 반환한 뒤 PD 총수가 감소한다. backing KVA의 두 PTE는 정확히 0이 되고 low/high view 모두 매핑이 없어진다. 해제된 backing 내용 자체는 지워지지 않는다. free pmap/EXT 역시 zone 링크가 덮어쓰는 부분 외에는 잔존 필드가 남는다.

zone `+0xc`는 tail이 아닌 **last_insert**이며 `+0x10`이 free-elements head다. 최초 잘못된 synthetic seed로 발생한 실패를 [별도 기록](failed-create-slot1-zone-seed.json)에 보존했다. [교차검토](CROSS_REVIEW.md) 후 seed를 수정하고 fresh 실행했다. 실행 중 상태 보정은 없었다.

## 근거와 해석 한계

[계획](PLAN.md), [실행 요약](pd-summary.json), [독립 감사](pd-audit.json), [변조 대조](negative-controls.json), [원본·소스 식별](source-basis.json), [이전 자료 보존](preservation.json), [재현성](reproducibility.json), [checkpoint](checkpoint.json)를 분리했다. 원본 Ghidra export는 스킬에 따라 읽기 전용으로 대조했다. 모든 계산은 Python으로 수행했다.

감사는 PD 수명·critical copy/EA·쓰기 수/폭·stack CALL/RET·상태 재생을 대상으로 한다. 공통 wired allocation의 일부 endpoint는 검증된 report31과 교차 비교한다. 모든 CPU/GPR/flags/EA를 새로 독립 구현한 검증은 아니다. 기록 변조를 거부한 결과를 실제 커널 오류 발견이나 실기기 실행 증명으로 표현하지 않는다.

기존 `sleepable` 파라미터 이름은 참조 행과의 호환을 위해 유지했다. 실제 이번 입력은 zone bit0의 complex-lock 경로이며, 참고 Darwin 헤더의 `pageable`에 대응한다. bit1의 sleep-if-empty 경로를 검증한 것이 아니다.

단일 PD backing, synthetic 부트/map/object/zone 전제이며 multi-backing queue 순회·PD 실제 활성화·비동기 IRQ·native RF·자원 부족·경합은 미검증이다. 원본 binary/DB/export와 이전 보고서는 변경하지 않았으며 `07_kernel` 구현이나 GCC 2.7 실컴파일을 수행하지 않았다. [남은 전체 범위](OPEN_ITEMS.md)를 유지한다.
