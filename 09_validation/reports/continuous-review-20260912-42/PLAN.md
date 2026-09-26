# PD 참조 수명과 반환 슬롯 재사용 — 구현 전 계획

전체 분석 목표는 그대로 유지한다. report41은 단일 backing의 생성·반환·회수 증거이며 다중 backing, native 실행, 전체 함수 의미 검증 또는 GCC 2.7 빌드의 증명이 아니다.

이번 경로는 report41의 fresh setup/원본 create_slot1 종료까지 정확히 같은 실행 prefix에서 시작한다. snapshot을 emulator에 복원하거나 기존 PT를 PD로 바꾸지 않는다. 보존 producer의 Python 호출 관찰기를 사용하여 다음 호출 전 실행을 중단하고 live emulator를 이어 사용한다. 출력만 이번 디렉터리로 전달하며 원본 코드·이전 자료·DB는 수정하지 않는다.

## 원본에서 확인한 계약

- `18f644` pmap_create는 size가 0이 아니면 NULL을 반환한다. software-only pmap 객체를 생성하는 경로로 오해하지 않는다.
- `18f7b4` pmap_reference와 `18f69c` pmap_destroy는 NULL을 허용한다. 비NULL 참조 증가는 lock 안의 `18f7e0`, 감소는 `18f6d2`에 있다.
- 마지막 참조가 아닌 destroy는 PD bitmap·count·free-PD 큐·zone을 반환하지 않는다. 마지막 destroy만 슬롯과 pmap zone element를 반환한다.
- 유효한 사용자 매핑이 없는 pmap만 destroy하는 호출자 전제를 유지한다. 새 PD를 CR3로 활성화하지 않는다.
- 반환 슬롯의 재사용은 새 backing 할당이 아닌 bitmap의 첫 빈 비트 선택이며 pmap struct bzero와 kernel PDE 재복사를 구분한다. PD 전체가 다시 zero된다고 가정하지 않는다.

## 시험 및 감사 계획

root A/B, zone bit0 모드, 선택 슬롯 양쪽을 조합한다. nullable 호출과 nonzero size 호출, 참조 증가·비최종 감소·최종 감소·슬롯 재생성을 같은 원본 상태에서 연결한다. 각 단계의 caller 입력 외 상태 수정은 금지한다.

원본 instruction/write/stack/선택 CPU 지점과 kernel PDE 복사를 기록한다. prefix는 보존 report41과 정확 비교하고 독립 consumer로 보존 근거를 재확인한다. 신규 경로는 전체 물리 쓰기 재생, 호출 순서, refcount/lock의 exact store와 주소, PD·zone endpoint, kernel copy source/주소/값 및 기존 backing 유지로 검증한다. nullable/nonzero 경로는 stack 외 쓰기 없음과 원본 분기를 확인한다.

계획의 독립 Codex 교차검토를 받은 뒤 코딩한다. 검토자의 주장을 원본과 실제 결과로 별도 확인하며 그대로 신뢰하지 않는다. 정상 자료뿐 아니라 기록 변조 대조, 동일 backend 재실행, 원본 및 이전 자료 해시 보존을 검사한다. 계산은 모두 Python으로 수행한다.

이번 계획은 다중 PD backing 큐 순회·재시작, 재사용 PD 활성화, 부족/경합, native RF, 전체 커널 의미 검증과 GCC 2.7 실빌드 의무를 해소하지 않는다.
