# No direct-relative branch in `__text` targets `_vm_page_init`

Report 170 had established that no exported direct `CALL rel32` targets
`0x0017b134`, the export-labelled `_vm_page_init` entry. This audit expands the
check over every original `__text` byte position and branch form with a
directly encoded displacement: `CALL rel32`, near `JMP rel32`, near conditional
branch `rel32`, short conditional/unconditional branch `rel8`, and loop-family
`rel8` branches.

Python found zero encodings of all these forms that resolve to `0x0017b134`.
The prior direct-call gap therefore is not explained by a direct tail jump or
conditional branch in the original text image. Together with report 170's
file-backed pointer-address audit, the static image leaves computed/BSS/
non-exported and runtime paths as the remaining possibilities for reaching the
template copy.

This result is only a static absence statement. It does not show that the copy
cannot execute, that the target is unreachable, or anything about template
bytes, allocator state, alias writers, or runtime page lifetime. Open Item 1
remains **in progress**.
