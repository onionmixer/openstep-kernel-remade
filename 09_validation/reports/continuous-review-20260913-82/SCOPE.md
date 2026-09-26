# 82차 원본 분석 범위와 검증 계획

81차의 [미완료 항목](../continuous-review-20260913-81/OPEN_ITEMS.md)을 잇는다.
OPENSTEP 원본 x86 바이너리와 그 바이너리에서 얻은 export·심볼·참조만 사용한다.
외부 코드, `01_resources`, 복원 코드 `07_kernel`은 열거나 근거로 사용하지 않는다.

## 선정 범위

- 등록·제거: `mach_swapon`, `vnode_pager_shutdown`, 호출자 `unmount_all`.
- 선택·기록 사용: `vswap_allocate`, `vnode_pagein`, `vnode_pageout`, `vnode_has_page`.
- 참조·잠금: `vnode_pager_vget`, `vnode_pager_vput`, `lock_init`, `lock_done`.
- high-water 갱신: `vnode_pager_truncate`.
- 이전 원본 근거의 제한적 연결: findpage sentinel 반복, file_init 등록 writer,
  FUN_0017cd58 교체 실패, 원본 vnodeops 표. 이 연결을 상위 호출 전제 증명으로 확대하지 않는다.

## 작업 방법

1. 이전 checkpoint·입력·보존 파일의 해시를 현재 파일과 재대조한다.
2. 선택 함수의 전체 ASM/C를 읽고, 원본 Mach-O 주소 mapping과 별도 명령어 디코딩으로
   본문 바이트·분기·CALL·핵심 피연산자 폭과 순서를 확인한다.
3. 전체 export의 선택 대상 참조를 조사하되 간접 참조·동적 별칭의 완전성은 주장하지 않는다.
4. 모든 주소·비트·크기·개수·해시는 Python으로만 계산한다. 유한 정수 예시는
   도달 가능한 native 상태를 증명하는 실행 실험이 아니다.
5. 확정된 본문 계약, 디컴파일 차이, 상위 전제가 필요한 추론, 미완료 분석을 구분해
   보고서·증거 JSON·보존 목록·checkpoint에 기록하고 다시 검증한다.

이전 독립 계획 교차검토의 미수신 상태를 성공으로 바꾸지 않는다. 실패한 검토 요청을
재시도하거나 우회하지 않는다. 이번에는 새 verifier·emulator·구현 코드를 만들지 않고,
원본 읽기와 일회성 Python 디코딩·정수/증거 계산 및 문서화만 한다.
Ghidra 스킬의 함수 본문·참조 대조 절차를 기존 export에 적용하며 live DB/UI는 변경하지 않는다.
원본/DB/export/이전 확정 보고서는 보존한다. 전체 목표 완료는 별도 전역 검증이 필요하다.
