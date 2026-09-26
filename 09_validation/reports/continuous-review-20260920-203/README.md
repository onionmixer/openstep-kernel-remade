# `_smmap`’s `+0x43` callback byte has a verified constructor-path producer

At `0x00106f5b`, `_smmap` reads a byte at `EAX+0x43` after loading `EAX` from
`[ESI+0x30]`.  The immediate preceding instructions trace `ESI` from the successful
`_getvnodefp` result: `_smmap` loads `[returned_file+0x18]`, then its `+0x30` pointer.
It reads the adjacent word at `EAX+0x42` before the byte and uses the byte to select
the callback-table cell at `0x001e2f58 + 44 * byte_value`.

The two binary functions labelled `_specvp` and `_makespecvp` allocate/clear a
0x68-byte backing allocation, write their 16-bit input to backing `+0x42`, write the
backing pointer at backing `+0x34`, and return `backing+4`.  Relative to that returned
pointer, the backing pointer is therefore at `+0x30`.  The byte `_smmap` reads at
backing `+0x43` is the high-addressed byte of the same little-endian 16-bit store at
backing `+0x42`.  This is an original-instruction path from the constructor input to
the callback selector; no separate byte-store instruction is required.

Across all exported bodies, Python found eight literal `+0x43` operands in six
functions, and all eight are `MOVZX` reads.  It found seven modifying literal
`+0x42` operands in six functions.  Only the two constructor stores above are tied
to this backing/returned-pointer layout by their own surrounding instructions.
The remaining operands may describe different layouts and are not attributed to
this path.

This resolves the earlier narrow gap of a **constructor-path byte source**.  It does
not prove that every `_smmap` input is produced by these constructors, all aliases or
bulk copies, the callback-table entry's runtime contents, bounds under memory
corruption, or callback/object lifetime.  Open Item 1 remains **in progress**.
