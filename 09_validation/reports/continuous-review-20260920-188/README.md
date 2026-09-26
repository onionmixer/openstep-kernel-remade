# callback table byte-index reader의 static bound gap

187차의 raw table bound(43 cells, stride 44)를 reader path에 대조했다. `_smmap` label의
callback derivation은 `MOVZX EAX,byte [EAX+0x43]`, 두 `LEA`로 `EDX=11*EAX`를 만든 뒤
`MOV ESI,[EDX*4+0x001e2f58]`를 수행한다. byte load와 indexed load 사이에는 byte value를
43과 비교하거나 mask하는 instruction이 없다.

Python address calculation에서 valid cell index는 0..42이고 reader field address range은
`0x001e2f58`부터 마지막 `0x001e3690`이다. index 43의 첫 out-of-range field address는
`0x001e369c+0x20 = 0x001e36bc`이며, byte maximum 255의 field address는 `0x001e5b2c`다.
reader 뒤의 zero/두 fixed-address compare는 **load 뒤**에 있으므로 table range gate가 아니다.

따라서 callback target이 43-cell table 안에서 읽힌다는 것은 byte input이 0..42라는 별도
runtime precondition을 필요로 한다. 이 보고서는 out-of-range access나 callback 실행을
관측했다는 주장이 아니다. source byte provenance, enclosing object validity, table 인접
memory mapping, runtime guards on callers, and callback lifetime remain unproven.

원시 reader·Python range calculation은 [callback-byte-index-boundary.json](callback-byte-index-boundary.json)에 기록했다.
