# 86차 원본 분석 계획 — 장치 제출과 주소 공간/이동

[85차 잔여](../continuous-review-20260913-85/OPEN_ITEMS.md)에 따라 sdstrategy,
pagemove, uiomove와 직접 연결된 disk lookup·pmap_pt_entry·copywithin/in/out를 분석한다.
copy fault recovery fragment와 Objective-C message dispatch를 원본 명령으로 연결하고,
selector 및 method 후보의 정적 원본 pointer를 추적한다.

1. 이전 checkpoint와 원본/export/보존 해시를 재검증한다.
2. 선택한 전체 함수/fragment의 경계·직접 전달·중요 operand를 원본에서 대조한다.
3. uio 주소 공간별 copy와 오류/진척, copy의 fault recovery와 segment prefix,
   pagemove PTE 저장·해제·CR3, disk 제출/완료 분기를 구별한다.
4. 원본 selector 참조와 metadata pointer를 읽되 class 소유권·실제 receiver·IMP의 실행은
   확정되지 않은 상태로 표시한다. __common/__bss를 파일의 runtime 값으로 읽지 않는다.
5. 정적 증거와 Python 정수 계산, 잔여 계약을 보존한다.

Ghidra 스킬의 본문·디컴파일·참조 대조 방식을 기존 export에 적용한다.
원본과 원본에서 추출한 자료만 사용한다. 다른 코드, 01_resources, 07_kernel은 참고하지 않는다.
라이브 DB나 기존 확정 보고서는 변경하지 않는다. 구현·복원·빌드·에뮬레이터·동적 실행을 추가하지 않는다.
계산은 Python만, 파일 변경은 apply_patch만 사용한다.

독립 계획 교차검토는 수신하지 않았다. 과거 실패를 재시도·우회하거나 계산을 검토 통과로
바꾸지 않는다. 원본의 지역 계약을 IRQ/native fault, 전역 수명 또는 전체 분석 완료로 확대하지 않는다.
synthetic fragment를 별도 C ABI 함수로 취급하지 않으며 TEST 접근 metadata만으로 write를 판정하지 않는다.
