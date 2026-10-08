# x86 `src/driverkit/libDriver/Kernel/snd_server.m` (plan 342 (S5-P331), 2026-10-06)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. ObjC module "Kernel/snd_server.m" (objc.json module 0x2092ac). Final run `s5p342-sn1`; 07 file SHA-256 `0009fedd8f86928846eb1a4a4e0d310eb93c4fee236b4db49213a2f2f764c7e2`; diff `x86-snd_server.diff`.

- `__text` [0x1bc4e8, 0x1bd3e7) 3839 B, 4 functions (0 methods) ((static snd_set_stream_format), (static snd_stream_msg), (static snd_device_msg), _snd_server). Front `89 ec 5d c3`, back `00 55 89 e5`, next function 0x1bd3e8.
- Sections: __TEXT,__text 3839 B given by symbol; __TEXT,__cstring 35 B literal (references checked by content); __OBJC,__message_refs 36 B literal (references checked by content); __OBJC,__cls_refs 8 B literal (references checked by content); __OBJC,__class_names 41 B literal (references checked by content); __OBJC,__meth_var_names 156 B literal (references checked by content); __OBJC,__module_info 16 B given by objc metadata; __OBJC,__symbols 12 B given by objc metadata.
- Final OBJECT_MATCH (`09_validation/reconstruction/s5p342-sn1-l1-snd_server-F-20261002.json`). Grade **A**.

Module "Kernel/snd_server.m": __text [0x1bc4e8, 0x1bd3e7). Diagnostics s5p343-*q1 (scratchpad bodies with header overrides) gave the same verdict. Codex review of plan 342 (gpt-6.1-sol) verified (07_kernel placement simulated before coding; 7 SDK headers adopted). s5p342-sn1 from 07 with kr_run RUNIN: OBJECT_MATCH, relcheck 0.
