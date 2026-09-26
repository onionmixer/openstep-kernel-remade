# 81차 — 원본 vnode 설치·재사용과 pager packed 기록 writer

80차에서 남긴 표 저장 base와 vnode 포인터 관계를 생성/검색 본문에서 확인한다.
pagerfile 생성·등록, bitmap page 할당, packed 기록 검색/교체/flat·2단 배열 확장을
연결해 하위 블록 padding 초기화 여부와 실패 후 상태를 조사한다.

Ghidra 스킬의 함수 ASM/C·참조·원본 byte 대조를 보존 export에 적용한다.
외부 프로젝트, 01_resources, 복원 코드 07_kernel을 참고하지 않는다. 원본 nlist 이름만
원본 이름으로 구분하고 FUN/가져온 타입/디컴파일 변수와 실행 의미를 동일시하지 않는다.

원본·DB·기존 export·이전 보고서는 보존한다. 추가물은 이번 분석 문서와 JSON 근거뿐이다.
모든 계산은 Python으로 수행하며 inline 원본 mapping/decoding·유한 산술만 사용한다.
새 검증 실행 프로그램·커널 구현·빌드·포팅·동적 실행은 없다. 새 독립 계획 교차검토를
받았다고 주장하지 않으며, 과거 실패한 요청을 우회하거나 재시도하지 않는다.

선택 본문 전체와 보조 window를 구분한다. 0x17ce3d의 합성 fragment는 독립 ABI 함수가
아니며, sleep의 인자 읽기 window는 scheduler 전체 완료가 아니다. 선택한 writer가
초기화하는 범위를 확인해도 모든 writer·caller·간접 대상·native 동시성까지 완료하지 않는다.
