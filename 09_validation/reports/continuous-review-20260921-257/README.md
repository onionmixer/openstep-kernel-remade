# 257차 정적 검토 — _md_do_shutdown의 세 HLT self-loop

원본 OPENSTEP x86 mach_kernel의 _md_do_shutdown(0x0018cfc8) body를 검토했다. export-derived
warning instance 세 개와 대응하여 HLT 후 short JMP가 같은 HLT 주소로 돌아가는 원시 terminal
pair가 세 개 존재한다. pair의 HLT 주소는 각각 0x0018d08c, 0x0018d140, 0x0018d1c8이다.

각 loop의 도달 조건이나 shutdown 의미는 정적 byte 검토 범위 밖이다. 첫 두 loop의 앞 branch와
마지막 loop의 바로 앞 call·NOP도 원시 바이트로 보존했지만, call target·parameter·I/O·runtime
동작을 해석하지 않는다.

전체 __text의 직접 E8 rel32 scan은 이 entry의 caller 한 개를 확인했고, _boot body의
0x00108c91이다. 간접·계산된 caller edge는 포함하지 않는다. 원시 바이트와 segment hash는
[md-do-shutdown-self-loops-evidence.json](md-do-shutdown-self-loops-evidence.json)에,
재검증 입력 해시는 [SCOPE.md](SCOPE.md)와 [checkpoint.json](checkpoint.json)에 보존한다.
