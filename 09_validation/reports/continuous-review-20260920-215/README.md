# Callback reset restores a statically filtered table target

`_IORemoveFromCdevsw` computes `EDI = 0x001e2f38 + 44 * supplied_index`,
sets `ESI=0x001e5100`, sets `ECX=11`, and executes `REP MOVSD`. The 44-byte
source is file-backed `__DATA,__data`, not BSS/common memory. Python reads its
dword at source `+0x20` as `0x0010cca4`; the complete source contents and hash
are recorded below.

The `_smmap` callback reader loads a selected cell's `+0x20` field, compares it
to `0x0010ccb0`, then to `0x0010cca4`, and jumps to `0x0010719e` on equality
before the shown `CALL ESI` at `0x00106fae`. Consequently, a reset cell's
copied `+0x20` value takes this explicit filtered branch in the shown static
reader path.

This proves neither the meaning of the two fixed values nor that a reset and
reader address the same cell at runtime. It does establish a concrete
file-backed reset source and a static reset-to-filtered-target data path. It
does not prove index validity, table lifetime, indirect writers, or callback
execution. Open Item 1 remains **in progress**.
