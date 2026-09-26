# VM pmap bootstrap globals: direct-literal writer boundary

Python scanned every exported instruction body and every byte position of the
original `__text` for five bootstrap-related 32-bit addresses. All 120 raw
literal occurrences are inside exported bodies. For `0x001f63f0`,
`0x001f7ae0`, and `0x001f7ae8`, the only direct absolute-memory writer found
for each selected address is respectively `0x0018ef90`, `0x0018ef10`, and
`0x0018ef08` in `_pmap_bootstrap`; all other direct literal uses are reads,
comparisons, or indexed-address consumers.

`0x001f7a80` and `0x001f7b00` are different: bootstrap materializes them into
`EDX` and `EAX` at `0x0018ef16` and `0x0018ef1b`, then the earlier 8-cell loop
stores through those registers. Later uses encode them as indexed bases. Thus
the direct-literal scan confirms the base materialization and reader set, but
cannot prove that no computed alias writes either buffer.

This narrows selected actual VM-pmap initializer globals to direct-literal
writer boundaries. It does not prove runtime execution, write ordering outside
the shown bootstrap path, all alias writers, global values after boot, or
lifetime. Open Item 1 remains **in progress**.
