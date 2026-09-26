# Scope

- original binary and full-pass5 references/function export only
- all exported direct unconditional calls targeting `_vm_map_fork`
- raw x86/32 decode with Python Capstone
- excluded: reference code, reconstruction, build, execution, indirect calls, and callee internals

