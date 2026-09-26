# 실제 복원 커널 소스

여기에서만 실제 복원 코드를 편집한다. 아직 채택된 커널 구현은 없다.
최종 코드·헤더·생성 코드는 GCC 2.7에서 컴파일되어야 한다.
C89 스타일을 기본으로 [호환 규약](../08_build/GCC27_COMPATIBILITY.md)을 따른다.
`src/common/`, `src/arch/x86/`, `src/arch/sparc/`, `src/arch/future_arch/`,
`include/`, `config/`는 작업 시작을 위한 예약 구조이다.
최초 기반 소스를 채택할 때 원래 파일 경로를 최대한 유지하는 방향으로 조정할 수 있다.

채택 파일마다 `PROVENANCE.tsv`에 출처/원 경로/고정 revision/수정 내용/라이선스 표시를 남긴다.
재구성한 함수는 `06_reconstruction/functions.tsv`의 evidence와 연결한다.
generated headers/MIG output, 커널 config, linker 설정도 재현 가능하게 관리한다.
아직 검증하지 않은 API에 성공을 반환하는 stub을 두어 복원 완료처럼 보이게 하지 않는다.
빌드 산출물은 `08_build/artifacts/`에 둔다.
