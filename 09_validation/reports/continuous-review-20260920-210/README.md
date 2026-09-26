# `_pmap_kgetport` table closure is not evidence for the VM pmap initializer

Reports 171, 172, and 193 correctly record local instruction and table facts
for the export labelled `_pmap_kgetport` at `0x00135df4`. Their table-resolved
calls reach `0x00135bd8`, `0x001351c0`, and `0x00135c84`. Original-byte decoding
shows that those three bodies directly call only `0x001355a8`, `0x0015a824`,
and `0x00114db8` (with the latter two calls repeated as recorded below).

The separately labelled pmap bootstrap/management export cluster begins at
`0x0018ec70`, including `_pmap_bootstrap` at `0x0018eee8`. The resolved
`_pmap_kgetport` closure has no direct branch to any of the 34 `_pmap_`
exports in that cluster. Export labels are hypotheses, but the direct-branch
separation is an original-byte fact. Thus the `kgetport` table records cannot
serve as evidence for a VM pmap initializer, table, or lifetime.

This corrects the evidence classification in the Open Item 1 audit; it does
not invalidate the local table provenance reported earlier. It also does not
rule out unobserved indirect paths, identify either subsystem's semantics, or
prove a VM pmap runtime initializer or lifetime. Open Item 1 remains **in
progress**.
