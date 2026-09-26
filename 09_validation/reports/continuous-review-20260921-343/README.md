# 343차 정적 검토 — Subroutine does not return 직접 종단 호출 연쇄

0x00105ac0의 종단 CALL은 원본 상대변위로 0x00105ad8의 _exit 진입점을 가리킨다. _exit의 원본 명령은 0x00105af0에서 CALL을 수행한 뒤 0x00105afa의 EB F4로 다시 0x00105af0으로 점프하는 직접 루프를 가진다.

0x0017e220의 _abort는 13바이트 wrapper이며, 원본 E8 상대 호출로 0x0010ca6c의 _panic을 호출하고 함수 body 내 RET가 없다. 이는 두 호출 연쇄의 정적 구조이며, 호출 대상의 실행 결과나 런타임 비반환을 단정하지 않는다.
