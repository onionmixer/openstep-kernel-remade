# Scope

- original binary and full-pass5 references export only
- all direct unconditional callers of `_vm_map_deallocate`
- Python Capstone raw decode; first instruction after each call
- excluded: reference code, reconstruction, build, execution, later caller paths, and helper internals

