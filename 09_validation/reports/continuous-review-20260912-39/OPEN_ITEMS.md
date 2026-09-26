# 보고서39 이후 잔여 의무

이번에 진전된 것은 pmap_update의 signed tick gate/aging 표 index/age byte/PDE 선택
및 회수 결정 경계다. 선택된 합성 입력의 원본 실행과 산술·분기·피연산자·쓰기 대조를
완료했지만 전체 함수의 실환경 동작 또는 실제 회수 완료로 일반화하지 않는다.

## 이 경계에서 남은 분석

- 001912f6 이후 실제 pmap_remove/페이지·PV/queue/소유권 변화 및 전체 반환까지 연결.
- nonempty free PD queue의 alloc_count별 보존/회수, 실제 backing과 zone 반환.
- 여러 active node의 순회·삭제 중 next 보존과 실제 page-table pair 구성.
- 실제 scheduler tick 진행·호출 간격·last=0 경유 연속 호출·동시성에서의 도달 가능성.
- high segmentation/paging에서 음수 index 주소의 실제 접근 결과. flat UC의 mapping
  실패는 real kernel fault 증거가 아니다.
- 하드웨어 A-bit 생성/clear 이후의 TLB/cache와 실제 참조 재검출.
- 모든 GPR·일반 메모리 EA 및 모든 CPU 명령 의미의 전수 검증. 현재는 소비하는
  경계 operand와 exact branch/write 계약에 한정된다.

## 계속 유지하는 전체 범위

[보고서36 전체 잔여 의무](../continuous-review-20260912-36/OPEN_ITEMS.md),
[보고서37 RF 실패](../continuous-review-20260912-37/README.md),
[보고서38 독립 CPU 대조 미실행](../continuous-review-20260912-38/README.md)을 유지한다.
원본 GC 상태 이전→실제 fault/handler/IRETD/retry, VM/pager/COW/자원부족·경합,
boot/CPU문맥/FPU/스케줄러/IPC/MIG/BSD/VFS/network/DriverKit/kernserv,
타입·ABI·함수 경계·fragment/경고·IDA 독립 대조·공개 소스 계보,
실제 GCC2.7 컴파일·Mach-O 링크·부팅 및 후속 아키텍처 분석은 여전히 별도 의무다.
