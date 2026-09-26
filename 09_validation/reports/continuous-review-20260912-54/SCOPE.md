# 관리 요청 dispatch/MIG 정적 검토 범위

report53에서 발견한 원형 함수 포인터를 실제 handler 및 요청 stub에 연결한다.

- `_kern_serv_handler`, 일반 dispatch `FUN_0016c758`, shutdown/load_objc stub 본문을 검토한다.
- `_kern_server_main`은 원형 복사, boot listener 획득, 수신 및 fallback 호출 창을 별도로 검토한다. 전체 main·하위 IPC 서비스 의미 검증으로 확대하지 않는다.
- 원본 바이트·분기·테이블과 보존 Ghidra 출력, SDK의 old IPC 헤더 및 참조 소스의 대응을 구분한다.
- 계산은 Python만 사용한다. 기존 디코더와 inline 읽기 전용 진단으로 증거를 생성한다.
- 독립 계획 검토가 새로 확보되지 않았다. 새 검증 프로그램, 동적 실행, 커널 복원 구현 및 GCC 2.7 완료 판정은 하지 않는다.
