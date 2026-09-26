# Page template has two static 48-byte copy bodies

The `0x001f7440` template literal occurs in two exported bodies, not just
`_vm_page_init`. Both bodies set a source register to the template, set
`ECX=12`, and execute `REP MOVSD`, which Python calculates as a 48-byte copy.
`_vm_page_init` copies to `EDI=EDX` at `0x0017b150`; independently,
`_vm_page_alloc_sequential` copies to `EDI=EDX` at `0x0017b384`. Each
immediately stores its current `EAX` at the destination `EDX+0x24`.

The original file has three template-literal occurrences: these two `__text`
instructions and one non-code symbol-record occurrence already classified in
report 201. `_vm_page_alloc_sequential` has five direct relative callers in
four exported bodies, including two sites in `_vm_fault`. Consequently, the
absence of a direct call to the `_vm_page_init` entry cannot establish that the
template copy itself lacks static caller paths.

This establishes two selected copy bodies and direct caller candidates for one
of them. It does not prove invocation, the destination object identity, common
initial bytes, computed callers, post-copy writes beyond the shown `+0x24`, or
runtime lifetime. Open Item 1 remains **in progress**.
