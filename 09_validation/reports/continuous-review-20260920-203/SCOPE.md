# Scope — `_smmap` callback-byte producer path

Only original x86 `mach_kernel` bytes and full-pass5 binary-derived function bodies are
used. Python scanned all 5,253 exported function bodies for the literal `+0x43`
operand, classified modifying `+0x42` operands, calculated file offsets from the
Mach base, and read the cited bytes.  The decompiler names are identifiers only;
the conclusions below follow the cited machine instructions.

This report establishes a constructor-path producer for the byte used by `_smmap`.
It is not a complete alias, bulk-copy, or runtime-state closure for every object
which could reach `_smmap`.
