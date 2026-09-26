# Scope

- original binary and full-pass5 references export only
- all direct unconditional callers of `_vm_fault_unwire`
- raw x86/32 decode with Python Capstone
- excluded: reference code, reconstruction, build, execution, indirect callers, aliases, and helper internals

