# 232차 정적 검토 — `_unmount` entry-address의 `_sysent`-labelled data record

원본 OPENSTEP x86 `mach_kernel` 전체에서 `_unmount` entry `0x001193d4`의 little-endian dword를
Python으로 검색했다. 재부팅·QEMU·외부 소스·구현은 사용하지 않았다.

일치값은 두 개다. `0x001da530`은 initialized writable `__data`에 있고, `0x00201b18`은
`__meth_var_names`에 있다. 후자는 목적상 의미 있는 pointer alias라고 판정하지 않는다.

`_sysent` label `0x001da034`에서 8바이트 간격의 네 원시 record는 다음 dword 쌍을 보인다:
`(2,0x001192d0)`, `(2,0x0011932c)`, `(1,0x001193d4)`, `(0,0x001331cc)`.
각 **두 번째** dword는 현재 export label `_statfs`, `_fstatfs`, `_unmount`, `_async_daemon` entry와
일치한다. `_unix_syscall`은 index×8과 `_sysent` base를 더해 record 주소를 만들고, 첫 word를 읽은
뒤 record `+4`의 dword를 EDX에 넣어 `CALL EDX`를 실행한다. 이는 raw data와 raw reader 명령의
관찰이다. 첫 word는 signed load 뒤 4배로 변환되어 0이면 `0x00189a5c` call 구간을 건너뛰고,
0이 아니면 그 helper에 전달되는 값에 사용된다. 첫 word의 의미와 실제 dispatch invocation은
확정하지 않는다.

원시 word·block 분류와 Python 검산값은 [unmount-data-alias-evidence.json](unmount-data-alias-evidence.json)에,
재검증 해시는 [checkpoint.json](checkpoint.json)에 보존했다.
