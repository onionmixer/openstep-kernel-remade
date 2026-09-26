# Scope

- original binary and full-pass5 references export only
- first 128 raw bytes before every direct `_vm_map_deallocate` caller site
- Python Capstone scan for direct lock helper calls
- excluded: reference code, reconstruction, build, execution, earlier code, indirect calls, and runtime locks

