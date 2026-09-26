# 80차 — 원본 vnode pager 생성·속성 인자·마지막 참조 callback

79차 OPEN_ITEMS의 vnode_dealloc 간접 호출, vattr buffer, vn_rele 및 pager 생성 경계를
이어 검토한다. vattr_null, vn_rele, vnode_alloc, vnode_pager_create, vnode_pager_setup와
원본 nlist에서 확인한 vnodeops 표의 +0x18/+0x4c 대상 본문을 선택했다.

다른 프로젝트·01_resources·07_kernel은 참고하지 않는다. 원본 OPENSTEP 바이너리와
그 바이너리의 보존 ASM/C·함수 metadata·참조·심볼 자료만 사용한다. 기존 외부 소스
비교나 도구가 가져온 구조체 타입은 현재 동작의 증명이 아니다.

Ghidra 스킬의 함수 본문·참조·원본 명령 대조 절차를 보존 export에 적용한다.
원본 및 DB, export, 이전 보고서는 수정하지 않는다. 새 독립 계획 교차검토를 받았다고
주장하지 않으며, 실패한 요청을 우회·재시도하지 않는다. 새 실행 검증 프로그램이나
커널 구현·복원·빌드·포팅은 작성하지 않는다. inline Python의 원본 byte mapping,
독립 명령 decoding, 유한 정수·인자 위치·폭·해시 계산과 분석 문서만 추가한다.

선택한 본문 전체 읽기와 원본 재디코딩은 하위 함수 전체·모든 writer·모든 간접 대상·
동적 실행·native 동시성 검증을 뜻하지 않는다. 이름이 있는 표를 조사한 결과와 실제
실행 가능한 표 집합의 완전성도 구분한다. 범위 밖 함수의 참조 instruction window를
검토한 것만으로 그 함수 전체 의미를 완료 처리하지 않는다.
