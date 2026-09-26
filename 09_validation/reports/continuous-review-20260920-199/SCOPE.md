# Scope — `_smmap` static indirect dispatcher entry

Only original x86 `mach_kernel` bytes are used. Python decoded raw dwords in the static data table and calculated the entry index; Capstone decoded every cited dispatcher instruction. This does not establish trap entry, runtime index, ABI, execution, callback behavior, or lifetime.
