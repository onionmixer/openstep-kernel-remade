# 범위

원본 OPENSTEP x86 mach_kernel와 그 바이너리에서 생성된 독립 full-pass5 export만
사용했다. Python으로 VA-to-file mapping, 세 export body segment의 바이트·SHA-256, 모든
recorded direct branch/call target과 __text 내 직접 E8 rel32 target scan을 검증했다.

범위는 _setpgrp의 raw direct-control-transfer와 epilogue 경계다. operand type·의미,
branch 조건·callee 의미, ABI, parameter storage, indirect caller와 runtime 상태는 범위 밖이다.
