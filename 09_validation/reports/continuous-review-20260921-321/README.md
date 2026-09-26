# 321차 정적 검토 — _abort의 raw body inventory

원본 OPENSTEP x86 mach_kernel의 _abort(0x0017e220) 단일 13바이트 body를 원시 명령으로 검토했다. direct E8 call 1개가 있고 export body 안에는 branch와 plain RET가 없다. 직접 E8 caller는 4개다.
