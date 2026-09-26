# Scope

- original binary and full-pass5 references/function export only
- every exported direct unconditional call targeting `_vm_map_copy`
- raw x86/32 decode with Python Capstone
- excluded: reference code, reconstruction, build, execution, indirect calls, and helper internals

