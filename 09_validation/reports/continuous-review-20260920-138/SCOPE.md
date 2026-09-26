# Scope

- original binary and full-pass5 references export only
- `_task_terminate` direct deallocate path; 128-byte pre-call XCHG candidate scan for all direct callers
- raw x86/32 decode and counts with Python Capstone
- excluded: reference code, reconstruction, build, execution, helper internals, and other lock forms

