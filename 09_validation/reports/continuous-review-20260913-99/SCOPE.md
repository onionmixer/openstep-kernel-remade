# 99차 범위·검토 계획

현재 사용자 지시에 따라 OPENSTEP 원본 커널만 분석한다. 외부 프로젝트 소스와
`01_resources`, `07_kernel`은 열지 않았으며 이전 외부 비교 결론을 근거로 승계하지 않는다.
복원·구현·빌드·포팅·실행·에뮬레이션은 하지 않는다. 모든 계산은 Python이다.

## 적용 순서

1. 98차 checkpoint, 입력 및 범위 내 기존 보존 파일의 해시를 확인한다.
2. 기존 Ghidra ASM/C/metadata와 원본 Mach-O file mapping을 대조한다.
3. PCB/task 초기화 → bitmap 변경 → thread별 TSS 전파를 추적한다.
4. 호출 인자와 선택한 할당·해제·복사 함수의 지역 계약을 분리해 검토한다.
5. 원본 Objective-C caller의 selector 문자열과 물리적인 stack 인자를 확인한다.
6. Python으로 분기·명령 폭·table·복사 범위 산식을 검사하고 증거/문서/보존을 재검증한다.

Ghidra 스킬은 함수 본문·호출·참조·제어 흐름을 대조하는 절차에 적용했다.
기존 export만 사용했으며 live Ghidra/IDA DB를 수정하지 않았다.
새로운 독립 Codex 계획 교차검토는 받지 않았다. 기존 실패를 검토 통과로 취급하거나
우회 재시도하지 않는다. 이번 산출물은 분석 보고서이며 구현 코드가 아니다.

## 선택 본문

| 주소 | 선택 이유 |
|---|---|
| 0x18d520 | PCB template·embedded TSS 초기화 |
| 0x18d5c4 | task machine state K 생성 |
| 0x18d7d4 | task_map_io_ports의 gate·bitmap 수정 |
| 0x18d610 | thread별 TSS 확장·전파 |
| 0x18dce0 | bootstrap의 동일/상이한 bitmap 처리 |
| 0x1013e4 | memcpy의 길이·DF·접근 범위 |
| 0x101630 | memset의 원본 table과 store 폭 |
| 0x15a75c | kalloc의 class 선택·실패 반환 |
| 0x15a824 | kfree의 NULL/size 지역 검사 |
| 0x16b790 | zalloc wrapper의 EAX 전달 |
| 0x16b84c | zfree의 free-list 삽입 |
| 0x16b8aa | panic 뒤 fallthrough fragment |
| 0x173d1c | kmem_alloc_wired의 오류·output 조건 |
| 0x182190 | 원본 Objective-C I/O Ports caller |

13개 일반 본문과 fragment 1개의 1,037개 명령/2,858바이트를 재디코드했다.
직접 분기 105개, 직접 CALL 53개, 간접 JMP 3개, 핵심 명령 128개,
memset static footprint 경로 46개와 selector 참조 5개를 확인했다.
경고 2행은 export의 경고 수이지 원본 결함 수가 아니다.
입력 48개와 기존 보존 경로 887개를 검증한다.

분기 목적지·본문 byte union의 일치는 모든 callee 및 간접 caller의 의미 완료가 아니다.
memset의 MOV 목적지 구간 조사는 기존 무조건 CFG 경로의 정적 집계이며 CPU 실행이 아니다.
Python 산식 검사는 실제 주소 유효성, allocator 초기값, 동시성, CPU I/O permission 결과를
관찰하거나 증명한 것으로 해석하지 않는다.

[결과](README.md) · [원본 증거](object-lifetime-evidence.json) · [미완료](OPEN_ITEMS.md)
