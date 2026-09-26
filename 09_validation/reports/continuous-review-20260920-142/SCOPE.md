# Scope

- original binary and full-pass5 references export only
- all direct unconditional calls to `_vm_fault_copy_entry`
- raw x86/32 decode with Python Capstone
- excluded: reference code, reconstruction, build, execution, indirect callers, branch predicates, and callee internals

