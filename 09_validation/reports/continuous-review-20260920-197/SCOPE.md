# Scope — selected absolute-address bytes across complete `__text`

Only the original x86 `mach_kernel` bytes and binary-derived function body ranges are used. Python searched every byte position in original `__text` for each selected little-endian 32-bit address and calculated body membership. A byte occurrence is not automatically an executable memory operand, so this audit cannot prove writer closure or exclude aliases and computed addresses.
