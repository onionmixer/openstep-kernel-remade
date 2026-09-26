# Scope — page-template field whole-file raw-address classification

Only original x86 `mach_kernel` bytes are used. Python searched the full file for selected little-endian 32-bit page-template addresses and parsed any non-text occurrence as a Mach-O `LC_SYMTAB` nlist record. It does not establish execution, instruction semantics, aliases, computed pointers, bulk writes, or runtime state.
