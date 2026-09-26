# Twenty map-record copy paths have an explicit post-copy `+0x30` increment

The exact `_vm_map`/`__vm_map` body set contains 22 `ECX=0xb; REP MOVSD`
record-copy sites. Twenty copy sites have a post-copy sequence in their shown
function body that loads a `+0x10` pointer, enters a `+0x34` exchange loop,
increments that pointer’s `+0x30`, and releases `+0x34`. There are twenty
distinct increment instructions because two fork control paths converge at
one increment site.

The 22-site inventory has two non-matching flows. At `0x00177db6`, the copy is
immediately followed by an explicit destination `+0x10 = 0` store (and an
explicit word `+0x28 = 0` store), so it does not use the ordinary `+0x30`
increment sequence. At `0x00177c78`, the shown post-copy path rewrites the
source record’s `+0x10`; a later, distinct copy at `0x00177cee` is the path
that reaches the converged increment at `0x00177d10`.

This expands report 204’s two map-delete split paths to the complete selected
bulk-copy inventory. It gives a static explanation for most copied-record
pointer-target increments and records the fork exceptions. It does not prove
that each `+0x10` pointer has one C type, that the exchange is a correct lock,
that all updates are balanced, or any runtime values and lifetimes. Open Item
1 remains **in progress**.
