# `_vm_object_deallocate`의 xchg·refcount·helper 경계

Open item 2의 deallocate lock 순서를 raw instruction으로 좁혔다. Export label상
`_vm_object_deallocate` (`0x00178c64`)의 3개 body fragment를 Python/Capstone으로 해독했다.

입력 ESI가 zero이면 `0x00178c6e JE 0x00178d57`로 RET epilogue에 간다. nonzero 경로는
먼저 global `0x001f6f2c`에 대해 `MOV EAX,1; XCHG` (`0x00178c7d..0x00178c82`)를 시도하고,
그 뒤 `ESI+0x10` 주소에 대해 같은 one-valued XCHG (`0x00178c9a..0x00178c9f`)를 시도한다.
각 시도 전에는 zero가 될 때까지 read/test loop가 있다.

두 xchg 뒤 원본은 `WORD[ESI+0x18]`을 AX로 읽고, CX를 하나 줄여 같은 word에 쓰며,
**old** AX가 1인지 비교한다. old AX가 1이 아니면 먼저 `XCHG [ESI+0x10],0`
(`0x00178cbc`), 다음 `XCHG [0x001f6f2c],0` (`0x00178cc1`)을 실행하고 RET로 간다.

old AX=1의 cleanup 분기는 두 visible 순서를 보인다.

- byte `ESI+0x46`의 bit 3가 set이고 `WORD[ESI+0x1a] > 0`인 경로는 list updates 뒤
  global zero-xchg (`0x00178d0b`), `CALL 0x00179084`, object-slot zero-xchg
  (`0x00178d1c`), `CALL 0x001790dc`, RET 순서다.
- 나머지 경로는 필요하면 flag를 clear하고 `CALL 0x00179764`를 수행한 뒤 global
  zero-xchg (`0x00178d3b`), `CALL 0x00178d60` 순서다. helper가 반환한 EBX를 ESI로 옮겨
  nonzero이면 `0x00178c74` acquisition loop로 되돌아간다.

후자에는 `CALL 0x00178d60` 전후 visible body 안에서 original `ESI+0x10`에 대한
zero-xchg가 없다. 그 helper 내부의 release 여부는 이 증거로 알 수 없다. 따라서 이
보고서는 xchg protocol의 순서만 기록하며 lock type, ownership, helper side effect 또는
전체 deallocate lifetime을 주장하지 않는다.

상세 instruction 목록과 Python 집계는
[vm-object-deallocate-xchg-flow.json](vm-object-deallocate-xchg-flow.json)에 있다.
