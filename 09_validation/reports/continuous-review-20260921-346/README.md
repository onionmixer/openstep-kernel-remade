# 346차 정적 검토 — deadcode-elimination delay warning 범위 감사

Restarted to delay deadcode elimination 경고는 full-pass5에서 세 완전 함수에만 존재한다. stack 공간 경고는 _execve(0x00104c54, 2,930 body bytes, 23 segments)와 _itrunc(0x00141014, 3,197 body bytes, 17 segments)에, ram 공간 경고는 __sel_registerName(0x001d00e8, 403 body bytes, 5 segments)에 붙는다.

이 경고는 decompiler 처리 순서를 나타낸다. 원본 바이트의 도달성, 타입, ABI, 자료 구조 또는 실행 동작을 판정하는 근거로 사용하지 않는다.
