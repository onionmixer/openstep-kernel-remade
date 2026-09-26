# 포트 compat copyout의 권한·참조 경계

report56의 내부 실패 처리를 object copyout/destroy/destination 변환에 연결하고, 실제 `ipc_right_copyout`과 space reference 본문까지 검토한다.

원본 바이트·callee 호출 인자·반환값 사용·직접 참조 갱신과 공개 소스의 계약을 구분한다. 성장 helper, reverse lookup, notification, port 최종 release의 전이적 구현 및 경쟁은 이 단계에서 완료하지 않는다.

Ghidra 보존 export를 읽기 전용으로 사용하고 계산·해시·주소·집계는 Python만 사용한다. 신규 독립 계획 검토는 확보되지 않았다. 새 실행/검증 프로그램·동적 실행·커널 구현·GCC 2.7 실빌드는 하지 않는다.
