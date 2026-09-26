# 292차 정적 검토 — _xprt_register의 raw prologue·epilogue

원본 OPENSTEP x86 mach_kernel의 _xprt_register(0x00136ddc) 단일 7바이트 body를 원시 명령으로 확인했다. body에는 direct call·direct branch가 없고, 직접 E8 caller는 0x00137580 한 곳이다.
