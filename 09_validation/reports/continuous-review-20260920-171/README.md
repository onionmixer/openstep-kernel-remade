# `_pmap_kgetport` 세 간접 target의 allocation·static-slot provenance

Open item 1의 pmap-prefix 간접 call writer 공백을 원본 바이트로 더 좁혔다. export label상
`_pmap_kgetport`가 `0x001353b0`에서 받은 raw 반환값을 EBX로 쓰는 사실(168차)에서 시작한다.

`0x001353c8 PUSH 0x78; CALL 0x0015a75c`의 반환 base는 EBX에 놓이고 zero helper를 거친다.
`0x001353d9 LEA EDX,[EBX+4]`가 local return 후보가 되며, success branch는
`0x001354f7 MOV EAX,[EBP-0x3c]; RET`로 이 `base+4`를 돌려준다. 실패 cleanup은
`0x00135538 XOR EAX,EAX; RET`다.

success base의 `+8`에는 `0x001dcdc4`가, `+4`에는 `0x00134f94`의 반환값이 저장된다.
후자의 helper는 별도 0x28-byte base의 `+0x20`에 `0x001dcd88`을 저장하고 그 base를
EAX로 반환한다. 따라서 `_pmap_kgetport`에서 받는 `P = base + 4`에 대해 raw load chain은
다음처럼 축약된다.

| indirect call | raw pointer path | static table value | target |
|---|---|---:|---:|
| `0x00135ebe` | `[P+4] = base+8 = 0x001dcdc4`; then `[0x001dcdc4]` | `0x00135bd8` | `0x00135bd8` |
| `0x00135ef5` | `[P] = second base`; `[second base+0x20]=0x001dcd88`; then `+0x10` | `0x001351c0` | `0x001351c0` |
| `0x00135efe` | `[P+4] = 0x001dcdc4`; then `+0x10` | `0x00135c84` | `0x00135c84` |

세 table dword는 원본 file-backed `__DATA`에서 직접 읽었다. 이는 해당 call target address의
정적 provenance를 확정하지만, target의 ABI·의미, allocation helper의 실패/side effect,
runtime table overwrite 또는 pmap 자료형을 결론내리지 않는다.

원시 명령, table bytes 및 Python 계산은
[pmap-kgetport-static-targets.json](pmap-kgetport-static-targets.json)에 기록했다.
