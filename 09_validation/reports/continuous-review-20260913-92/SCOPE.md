# 검토 범위와 방법

OPENSTEP 원본 kernel과 원본에서 얻은 full-pass5 ASM/C·본문 범위·심볼·참조만 사용했다.
`01_resources`의 외부 코드와 `07_kernel`은 열거나 참고하지 않았다.
외부 비교 이력은 현재 의미 증거가 아니다. 구현·복원·빌드·포팅·동적 실행은 범위 밖이다.

일반 본문: vm_map_pageable, pmap_extract, vm_fault_wire/unwire/wire_fast,
lock_set_recursive/write_to_read/clear_recursive, copyin/copyout,
pmap_change_wiring, vm_page_unwire, pmap_pageable.
synthetic fragment: copy 복구 `0x189b18/0x189e70` 및 기존 panic 뒤 조각
`0x175c87/0x175db8/0x175ec4/0x17364e/0x190baf`.
조각의 확대된 C 출력은 독립 ABI 함수 또는 추가 본문 byte로 중복 집계하지 않는다.

원본 SHA와 Mach-O 매핑, 선택 본문의 byte 합집합/명령 경계·길이,
직접 branch/CALL target, 중요 operand/폭/signedness/순서, 원본 문자열/전역 section을 대조했다.
모든 비분기 export operand 문자열을 자동 동등성 검사했다는 뜻은 아니다.
중요 의미는 별도 명시 operand 검사와 전체 선택 본문 읽기의 범위로 한정한다.
__common/__bss는 runtime 값으로 읽지 않았다. 일반 vm_fault/pmap_enter/allocator 내부와
trap handler의 native 복구 계약은 선택한 caller의 이름만으로 확정하지 않는다.

계산은 Python만, 편집은 apply_patch만 사용했다. 새 독립 계획 교차검토 미수신을
통과로 취급하지 않으며 과거 실패 요청을 재시도·우회하지 않았다.
새 구현/검증 스크립트 파일·에뮬레이터·live DB 변경은 없다.
선택 지역 계약의 확인과 전체 kernel 의미·경계·ABI 분석 완료를 구분한다.
