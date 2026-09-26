# Scope — selected page-template copy bodies and direct callers

Only original x86 `mach_kernel` bytes and full-pass5 bodies derived from that
binary are used. Python counted `12 * 4` copied bytes, scanned the full binary
for the template literal, enumerated the two matching copy sequences, found
direct relative calls to `_vm_page_alloc_sequential`, and calculated raw file
offsets as `VA - 0x00100000`.

The result does not infer data structure types, semantic field meaning, caller
execution, indirect/computed callers, loader/common initialization, or object
lifetime.
