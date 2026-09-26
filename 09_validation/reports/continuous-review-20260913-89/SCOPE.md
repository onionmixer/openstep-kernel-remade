# 89차 — 원본 전송·sense·상태 변환

88차의 큐/완료 연결은 검증된 분석 진척이다. 이번에는 그 사이의 doSdBuf,
setupScsiReq, genRwCdb, reqSense, logOpInfo와 원본 IOSCSIController 기본 메서드를
검토한다. 실제 controller의 runtime override를 확보된 기본 IMP와 혼동하지 않는다.

OPENSTEP 원본 x86 바이너리와 그 바이너리에서 나온 Ghidra full-pass5 출력·metadata·
참조, 이전 원본 분석의 보존 기록만 사용한다. 외부 프로젝트 코드와 `01_resources`,
복원 중인 `07_kernel`은 참고하지 않는다. 역사적 외부 코드 비교도 현재 증거가 아니다.

Ghidra 스킬의 원본 본문·참조 대조 절차를 보존 export에 적용했다.
원본·DB·export·이전 확정 보고서는 수정하지 않는다. 생성물은 분석 JSON·문서뿐이다.
모든 계산은 inline Python으로, 파일 변경은 apply_patch로 수행한다.
새 검증 프로그램·에뮬레이터·커널 구현이나 동적 실행은 만들거나 수행하지 않는다.
독립 계획 교차검토의 새 결과를 받지 못했으며, 이를 통과로 바꾸거나 과거 실패 요청을
재시도·우회하지 않는다.

선택 본문의 정적 계약·명령/데이터 경계와 실제 device/scheduler/메모리 계약을 분리한다.
전체 원본 분석 요건·경고/실패·누락 entry·native 전제가 해결되지 않았으므로 목표는
활성 상태로 유지한다. 복원·구현·빌드·포팅은 이 단계의 완료 조건이 아니다.
