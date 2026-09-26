# VM pmap bootstrap static-layout and indirect-table writer

This static-only report extends the scoped VM pmap cluster established in
report 210.  In the original x86 kernel, `_pmap_bootstrap` stores
`0x001f7a60` in global `0x001f63f0`; it then writes three fields through that
static address: offset `+0`, offset `+4`, and offset `+8`.  The `+0` field is
first assigned the result of the direct call at `0x0018efae`, then advanced by
`0x00000c00`; `+8` is assigned one.  Later, `+4` receives the translated
address used as the CR3 source immediately afterward.

The common helper at `0x0018ecc0`, invoked by `_pmap_bootstrap` and
`_pmap_map`, loads `0x001f63f0`, dereferences its `+0` field, computes a
four-byte upper-index slot using a 22-bit shift, and writes successive entries
through that slot.  Its loop count comes from `0x001f7ae0`; each iteration
writes one dword, advances the slot by four bytes, and advances the aligned
address portion by `0x1000`.  These are byte-verified control/data-flow facts,
not a source-level type declaration or a proof of runtime values.

The final bootstrap loop copies `0x400` bytes (256 dwords, calculated with
Python) from the memory referenced by that `+0` field to its first argument.
Static evidence therefore identifies a concrete bootstrap-owned indirect-table
initializer and its field writes.  It still cannot establish the runtime page
size initializer value, runtime allocation results, or lifetime transitions.

