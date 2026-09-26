# Decompiler issue boundary

The same displacement `+0x28` appears under both a map pointer and an entry pointer. This report
uses dataflow at each cited instruction: `EDI` is the map argument in insert, while `EAX`/`EBX`/
`ESI` are the allocated or traversed entry at the word accesses. It makes no claim that unrelated
`+0x28` instructions in VM object, pager, or pmap code access either structure.

The static evidence shows arithmetic and calls, not an observed runtime schedule or value trace.
