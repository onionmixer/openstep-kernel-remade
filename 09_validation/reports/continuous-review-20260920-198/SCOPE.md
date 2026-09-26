# Scope — selected-address whole-file occurrence classification

Only the original x86 `mach_kernel` bytes are used. Python scanned every raw file byte for selected 32-bit addresses, parsed Mach-O segment and `LC_SYMTAB` records, and decoded the matching nlist records. It does not establish runtime loader behavior, instruction semantics, aliases, computed addresses, or writes through pointers.
