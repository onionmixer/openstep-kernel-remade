# Scope — callback reset boundary and reader-entry audit

Only original x86 `mach_kernel` bytes and full-pass5 binary-derived function exports are used. Python searched all 5,253 exported bodies for direct relative calls to the reader, setter, and reset entries, and for explicit destination operands of form `[register+0x43]`. Capstone decoded cited bytes. This does not resolve indirect/non-exported callers or writers, interpret the lookup at `0x001ce960`, or claim execution, table state, or lifetime.
