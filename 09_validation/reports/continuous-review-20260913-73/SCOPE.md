# kalloc·zone 할당/해제의 전제와 실패 경계

72차 callout allocation 전제를 잇는다. kalloc_init/kalloc/kget/kfree, zinit/zone free-space selector, zalloc/zalloc_noblock 공통 본문, zget/zfree/zchange 전체를 보존 ASM/C와 원본으로 검토한다. 크기 table의 실제 데이터와 조건부 zone 선택, 초기 flags와 반환/실패/대기 경계를 분리한다.

Ghidra 스킬을 보존 export 읽기 전용 대조에 적용하고 계산은 모두 Python으로 한다. 원본 Mach-O 매핑·명령어·분기·데이터·해시·유한 산술과 JSON 증거만 생성한다. 새 실행 검증 프로그램·emulator·구현·동적 실행은 하지 않는다. 문서/정적 증거 추가는 apply_patch로 수행한다.

원본·참고 소스·DB·export·기존 확정 보고서·07_kernel을 보존한다. 신규 독립 계획 검토 미확보 상태이며 이전 실패 검토를 재요청·우회하지 않는다. zget_space 하위의 실제 backing 확보/회수·VM/pageable/lock/scheduler 전수 의미, 모든 zone writer와 native 경합, 실제 GCC 2.7 빌드/boot는 이번 보고서로 완료 처리하지 않는다. 전체 목표는 미완료다.
