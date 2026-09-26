# 96차 범위

OPENSTEP x86 원본과 원본 유래 export/심볼/참조/메타데이터만 사용했다.
계산은 Python, 파일 편집은 apply_patch다. 신규 파일은 이 보고서 디렉터리의 문서·증거·해시뿐이다.
원본/DB/export/이전 확정 보고서는 변경하지 않았다. 다른 코드·복원·구현·빌드·포팅·native 실행은
현재 범위 밖이며 수행하지 않았다. 새 교차검토 미수신은 통과가 아니다.

## 선택 기준

95차 evidence에 남은 94차 literal store 후보의 parent 및 recovery target을 선택했다.
parent 주소 범위 안의 추가 synthetic fragment도 포함하여 본문 밖으로 분리된 종료 코드를
누락하지 않았다. 추가로 catch_trap, PCexception, REAL의 두 flag helper, PCemulatePROT를 포함했다.
선택된 정확한 주소/본문 범위/모든 명령/해시/경고는 evidence에 있다.

전체 선택 ASM을 읽고 파일 바이트로 명령 크기/본문 union/직접 목적지 및 핵심 operand를
재대조했다. C는 경고 전체와 PCexception/REAL/PROT/flag helper/0x1a3160의 선택 본문을
검토했다. 이번에 모든 선택 C의 모든 줄이나 모든 callee 의미를 읽었다고 주장하지 않는다.
raw decoder의 분기 대조도 선택된 전체 head 집합을 사용하여 fragment→parent 내부 head
연결을 허용하고 검증했다. 함수 시작 주소만으로 목적지를 제한하지 않는다.

## 증거 강도

- 원본 사실: 명령 bytes/폭/주소, literal store, FS 명령, branch/fallthrough, 파일 dispatch 표.
- 조건부 도출: 호출 인자의 thread 계보, saved EIP 보정, descriptor/offset 산식,
  명시적 stack MOV footprint와 미초기화 gap, BYTE 범위에 따른 지역 분기.
- 미확정: 모든 alias/등록·초기화 writer/전체 callee CFG, runtime descriptor·segment·thread·stack
  일치성, 동적 재현, 부분 write 원자성, 전체 커널 분석 완료.

기존 literal 목록의 해시를 검증했지만 전체 ASM offset survey를 새로 수행했다고 보고하지 않는다.
목록 내 남은 후보 0은 writer exhaustiveness가 아니다. C 프레임 초기화 누락은 기존 export의
특정 의미 누락으로 기록했으며, 원본 CS 폭/stack gap과 구분했다.
검증 스크립트·에뮬레이터·커널 구현 파일을 새로 만들지 않았다.
