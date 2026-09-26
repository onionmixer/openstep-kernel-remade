# 347차 정적 검토 — __bios32 read-only-address write warning의 원본 opcode 대조

두 Read-only address warning은 0x00187108의 __bios32에 있다. 원본 0x0018711a 바이트 66 A3 66 71 18 00은 AX를 절대 주소 0x00187166에 쓰고, 0x00187123 바이트 A3 62 71 18 00은 EAX를 절대 주소 0x00187162에 쓴다.

같은 함수에는 0x00187161의 far CALL과 0x001871d0의 C3 RET가 있다. 이 기록은 원본 명령의 절대 쓰기만 다루며, decompiler가 해당 주소를 read-only로 분류한 이유나 실제 메모리 권한·실행 동작을 판정하지 않는다.
