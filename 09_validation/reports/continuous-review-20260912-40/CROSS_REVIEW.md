# Planning cross-review

Before diagnostic coding, independent reviewer `/root/vm_contract_review27` inspected the preserved report32 prefix and original removal listings. Root independently read those listings and decoded the canonical prefix fields with Python.

Accepted findings:

- EXT offset is zero, so helper arguments must be `[PMAP, 0, 0x800000, 1]`, not the copied VM range. Full PT scan must be observed.
- `dirty_prefix.prefix` omits report32 `points` and `zero_chunks`. Use fixed common-field equality and a freshly computed projection hash; do not claim whole-row equality.
- Aging reads the first PDE while copied DATA uses the next PDE. Preserve the neighbor's original Accessed bit; do not clear both to simplify the fixture.
- Original `191333` compares VM size against section length, leading to CR3 reload. Only the first TLB counter increments; this is not the smaller public-remove INVLPG path.
- Newly emptied PT is queued after the free-PT sweep. It remains allocated/wired until a later eligible call; current-call backing free would be a failure.
- Age is committed before removal and is not reset by the retirement sequence. Saved next must lead to active-head termination despite EXT links being rewritten to the free queue.

These are planning findings, not execution results. No reviewer statement alone constitutes acceptance. Native exception-frame/RF and complete boot ownership remain outside this bounded test.

## Post-coding counterexamples and root reproduction

Root independently reproduced each accepted corrupted-record counterexample before editing the auditor:

- First `18fa13` local-VA store changed from `0x2000` to `0x6000`: later loop stores hid the corruption from full snapshots. Added exact local-stack write sequence, addresses, values, interval ordering and overlapping-write checks across the complete scan.
- Swapped `1912e3`/`1912eb` checkpoint PC and CPU EIP: added exact `trace[trace_index] == point.pc` binding.
- Altered aging ECX, AL or ESI: added store EA, old/new byte operands, threshold-stack value and selected CMP flags checks.
- Altered `191040` ESI to a different PDE: added ordered PDE clear addresses and explicit dirty/reference/PV-owner/EXT operand identities.

Root's own initial audit also incorrectly assumed the pre-input physical-segment bytes were all zero. The count is zero, but bootstrap values remain at `1f6e74` and `1f6e78`. The auditor now anchors these bytes to finalized report33's matching pre-input state. Execution inputs were not changed to satisfy the incorrect audit.

The revised full matrix passed, and negative controls cover all reported failures. The reviewer separately rechecked representative A/B remove/equal/accessed rows and rejection of the last address mutations, with no further mandatory issue found in the stated narrow scope. This is not a claim that all record fields or all CPU instructions have independent semantics models.
