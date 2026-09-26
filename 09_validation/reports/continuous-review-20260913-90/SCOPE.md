# 범위와 검증 방법

현재 사용자의 범위는 OPENSTEP 원본 kernel 분석만이다. 외부 Mach4/NeXTMach/Darwin 소스,
로컬 `01_resources`, 복원 코드 `07_kernel`은 열거나 참고하지 않는다. 기존 외부 비교는 이력일 뿐
현재 의미 증거로 사용하지 않는다. 소스 복원·빌드·포팅·동적 실행은 범위 밖이다.

선택 본문은 probe `0x1ac3d8`, 초기화 `0x1acbc8`, 문자열 필터 `0x1aceec`,
controller getter `0x1acbb8`, 기본 numberOfTargets/maxTransfer `0x1abf18/0x1ac044`,
ID map/setter `0x18347c/0x1ac2e4`, IODisk physical setter/등록 `0x1a57e8/0x1a5b58`,
sdopen/read/write `0x183488/0x1835d8/0x183790`, 제한 함수 `0x1840d0`,
일반/물리 조회 `0x1840ec/0x18414c`, physio `0x11eb50`이다.

기존 full-pass5 ASM/C/본문 범위와 원본 Mach-O 파일 매핑·독립 decode를 대조했다.
본문 byte 집합 일치, 명령 길이/경계, 직접 branch/CALL target, 선택한 중요 operand와
폭·signed/unsigned 분기·스택 호출 순서를 확인한다. 모든 비분기 operand의 export 문자열을
자동으로 동등 판정했다는 뜻은 아니다. 주요 의미는 별도 원본 operand 검사로 한정한다.

Objective-C의 이름·타입 encoding·IMP 목록은 원본 file 기록이다. runtime selector 정규화,
superclass 포인터 fixup, category 설치, module load와 실제 객체 isa를 대신하지 않는다.
protocol method descriptor는 IMP 목록과 형식이 다르므로 임의로 같은 stride로 decode하지 않는다.
__bss/__common 값은 파일 padding을 읽어 runtime 값으로 취급하지 않는다.

새 독립 계획 검토나 native 결과를 얻지 않았다. 과거 실패한 교차검토 요청을 재시도하거나
우회하지 않는다. 새 verifier/에뮬레이터/구현 소스를 만들지 않고 기존 원본 출력의 수동 검토와
임시 Python 산술·raw decode·해시 검사 결과만 문서/JSON으로 보존했다. 파일 편집은 apply_patch만 썼다.
자료 확보 완료, 선택 본문의 지역 계약 확인, 전체 kernel 의미 분석 완료는 서로 다른 판정이다.
