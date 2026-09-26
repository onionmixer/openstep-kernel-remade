# old IPC 송수신과 수신 버퍼 경계

report54의 수신 인터럽트·크기 처리 문제를 원본 wrapper와 queue receive에 연결한다. msg_send/receive, 오류 변환, kernel kmsg get/put, queue receive, 실제 bcopy/memcpy 본문을 정적으로 대조한다.

모든 계산·해시·주소 처리는 Python이다. 보존 Ghidra ASM/C/metadata와 원본 LC_SEGMENT 파일 mapping을 확인한다. 공개 Darwin 코드는 대응 및 차이의 근거이며 원본 ABI의 대체물이 아니다.

독립 계획 검토는 새로 확보되지 않았다. 새 실행/검증 프로그램·동적 실행·커널 구현은 하지 않는다. queue 송신, copyin/copyout의 port/VM 소유권, scheduler·allocator·동시성 전체는 이 범위의 완료 판정이 아니다.
