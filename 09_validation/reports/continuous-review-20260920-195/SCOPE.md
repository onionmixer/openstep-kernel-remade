# Scope — VM-object labelled allocation/deallocation direct-call boundary

Only original x86 `mach_kernel` bytes and full-pass5 binary-derived function exports are used. Python inventoried direct relative calls to selected allocation, deallocation, and termination entries, searched the latter two bodies for literal `[register+0x30]` operands, and decoded cited bytes with Capstone. This cannot resolve aliases, indirect/non-exported paths, helper effects, runtime reachability, object identity, or semantic labels.
