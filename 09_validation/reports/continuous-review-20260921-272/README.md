# 272차 정적 검토 — _sync의 direct·indirect call 및 loop branch 경계

원본 OPENSTEP x86 mach_kernel의 _sync(0x00119294) 59바이트 body를 원시 명령으로
검토했다. body에는 0x0015f468을 향하는 direct rel32 call 한 개와 target을 확정할 수 없는
CALL EAX 간접 call 한 개가 있다. conditional branch 세 개 중 하나는 0x001192ac으로 향한다.

전체 __text의 직접 E8 rel32 target scan은 이 entry의 caller 한 개를 확인했고, _boot body의
0x00108bf0이다. 간접·computed caller edge는 포함하지 않는다. indirect call target, branch
조건·loop 의미, ABI·stack protocol·return convention은 확정하지 않는다.

원시 바이트와 caller/control-transfer evidence는
[sync-direct-indirect-call-evidence.json](sync-direct-indirect-call-evidence.json)에,
재검증 입력 해시는 [SCOPE.md](SCOPE.md)와 [checkpoint.json](checkpoint.json)에 보존한다.
