# Scope — exact VM-map 11-dword bulk-copy inventory

Only original x86 `mach_kernel` bytes and full-pass5 exact `_vm_map*`/`__vm_map*` bodies are used. Python selected every `REP MOVSD` preceded by `ECX=0xb`, calculated copied-byte coverage, and examined the next fifteen exported instructions for explicit `+0x28` stores. This does not resolve alias identity, branch reachability, later writes, or runtime values.
