# Direct VM-object lifecycle boundary does not write `+0x30`

The allocation wrapper at `0x00178b80` has nine direct sites in eight exported functions. The function labelled `_vm_object_deallocate` has thirty direct sites in seventeen functions; its shown path reads a word at `+0x18`, decrements the copied value, writes it back, and only takes the branch to the labelled termination routine when the pre-decrement value equals one.

The labelled termination routine has three direct sites. Its shown final path decrements the global at `0x001f6f40`, loads `0x001f73b8`, and calls `0x0016b84c` with the current `ESI`. Neither the deallocation nor termination body contains a literal `[register+0x30]` operand. This separates the direct initial `+0x30` evidence from a visible direct lifecycle boundary, but does not prove that helpers, aliases, bulk operations, or indirect paths preserve it.

Open Item 1 remains **in progress**: the runtime value and lifetime of `+0x30` still require alias and helper analysis beyond this direct boundary.
