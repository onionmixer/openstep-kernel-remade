# Scope — separating `_pmap_kgetport` from VM pmap evidence

Only original x86 `mach_kernel` bytes and full-pass5 export bodies derived from
that binary are used. Python enumerated export labels, selected the separately
located `_pmap_` cluster at and above `0x0018ec70`, decoded listed direct
branches, and calculated raw file offsets. Labels locate hypotheses only; the
scope correction relies on resolved table targets and direct branch operands.

No claim is made about external RPC or VM source names, dynamic dispatch,
computed/indirect calls beyond the three already-resolved table cells, runtime
execution, table mutation, or object lifetime.
