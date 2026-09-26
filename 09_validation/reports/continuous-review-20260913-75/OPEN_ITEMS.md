# 남은 OPENSTEP 원본 분석

75차는 페이지 크기 설정, zdata 예약·clearing, zone 이전의 호출 순서를 좁혔다.
실제 부팅·전체 메모리 지도·모든 callee 의미를 완료한 것은 아니다.

## 가까운 후속

- `zone_free_space_reclaim`(0x16ab34) 및 GC producer: 페이지 경계별 분할·hint/link/count,
  반환 리스트의 소유권과 VM 해제, 이후 더 낮은 주소 재할당이 add 경로에 들어오는지 검토한다.
- `_i386_init`의 메모리 상하한 producer(0x18acf8), pmap bootstrap(0x18eee8),
  `_start` 이전 loader/entry 경로와 `__common` 초기화를 원본에서 연결한다.
  default descriptor·hint가 비어 있다는 전제와 zdata/record 배열의 실제 mapping을
  확보하지 않은 채 zone+0x3c 초기값을 무조건 0으로 확정하지 않는다.
- `page_size/page_mask/page_shift`, region cursor/상한/count, bucket_count의 간접 writer와
  부팅 사이에 호출되는 함수의 변경 여부를 검토한다. 직접 MOV 검색만으로 writer 전수를
  찾았다고 주장하지 않는다. region allocator의 정상 정렬·범위·공간 조건도 필요하다.
- kmem_suballoc, VM map/object/page의 오류·reference·rollback, thread_sleep의 전달 lock
  해제와 복귀 계약은 74차에서 남긴 범위 그대로다. panic과 초기 context 전환의 실제
  비복귀·fault·인터럽트 처리도 호출 명령 존재만으로 완료하지 않는다.
- memset 표의 지역적으로 도달하지 않는 entry·별도 fragment를 전역 code/data 및
  진입점 ledger와 대조한다. 이번 zero-fill 경로 검증은 모든 int fill·unsigned size에 대한
  일반 라이브러리 동작 보장이 아니다.

## 전역 미완료 범위

원본 함수별/경로별 의미 ledger, 함수 밖 코드·fragment·data 분류, ABI/타입/호출 규약,
Ghidra 경고와 IDA 실패/해석의 독립 검토가 계속 필요하다. callout/clock/IRQ,
scheduler/context/FPU/fault, IPC/권리/notification, VM/pager/COW/page 상태·오류·대기,
PD/GC/reuse/CR3, 장치/MMIO/TLB/cache, BSD/VFS/UFS/network/DriverKit/kernserv/Objective-C의
남은 원본 경로도 닫힌 것으로 취급하지 않는다.

다른 프로젝트의 코드를 참고하지 않으며 소스 복원·구현·빌드·포팅은 현재 목표 밖이다.
의미 있는 원본 정적 분석이 남아 있으므로 목표는 완료도 차단도 아니다.
