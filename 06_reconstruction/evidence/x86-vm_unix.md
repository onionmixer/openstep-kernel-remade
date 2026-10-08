# x86 `src/vm/vm_unix.c` (plan 221 (S5-P199), 2026-10-02)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. plan 221 (S5-P199). Final run `s5p199-it2`; 07 file SHA-256 `69ee5717ad60c57bc26fa35e8126dd289f745fc14bb4b2f47f49b0774af79594`; diff `x86-vm_unix.diff`.

- Object [0x17bd28, 0x17c4e0) 1976 B, 16 functions (_useracc, _vslock, _vsunlock, _swapon, _procdup, _chgprot, _unix_pid, _task_by_unix_pid, _task_by_pid, _vm_object_special, _device_pagein, _device_pageout, _device_dealloc, _fake_u, _gc_init, _gc_control). Front `89 ec 5d c3`, back `55 89 e5 6a`, next symbol 0x17c4e0.
- Final OBJECT_MATCH (`09_validation/reconstruction/s5p199-it2-l1-vm_unix-F-20261002.json`). Grade **A**.

Object extent [0x17bd28, 0x17c4e0) between the confirmed vm_synchronize and vm_user. Diagnosis 13 failed on kern/ipc_globals.h; diagnosis build s5p199-d2 (NeXTMach text with header fixes, not 07) stopped on the Mach 2.5 u-area fields and kern_obj_t. The codex review of plan 221 found no wrong fact (the absence of a kern_obj_t cast is a reconstruction choice). Iterations: it1 only procdup differs; variants s5p199-v1 (conditional expression forms, no effect), s5p199-v2 (local inherit flag set by an if, l1), s5p199-v3 (file table size from the child's uu_lastfile); it2 all 16 functions match, extern relocation names match (relcheck 0).
