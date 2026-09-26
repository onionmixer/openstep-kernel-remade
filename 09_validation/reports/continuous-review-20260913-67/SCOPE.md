# 메시지 전체·부분 cleanup과 buffer free

보고서 66의 후속이다. ipc_kmsg_clean_body/clean/clean_partial/free와 ipc_object_destroy의 전체 원본 본문을 검토한다. copyin의 선택된 caller window에서 partial-clean ABI와 변환 완료 index 전달을 확인한다. 전체 copyin caller 집합과 권한 destroy·VM·DriverKit/network release의 전이적 완결은 제외한다.

Ghidra 스킬은 보존 export 읽기 전용 분석에 적용한다. 모든 계산은 Python이며 새 파일은 정적 증거·문서뿐이다. 원본·참고 소스·DB·export·기존 확정 보고서·07_kernel을 변경하지 않는다. 새 독립 계획 검토가 확보되지 않아 구현·새 실행 검증 프로그램·동적 실행으로 전환하지 않으며, 이전 실패 검토의 재요청·우회도 하지 않는다. 전체 분석 및 GCC 2.7 최종 요구는 계속 미완료다.
