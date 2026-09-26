# 범위

원본 OPENSTEP x86 mach_kernel와 독립 full-pass5 export만 사용했다. Python으로 모든 body segment의 VA-to-file bytes와 SHA-256, 모든 asm 전이 record의 원본 byte length, direct E8/E9/Jcc 상대변위 대상, raw RET byte 및 전체 __text의 직접 E8 caller scan을 검증했다.
