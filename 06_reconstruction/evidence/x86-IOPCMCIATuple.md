# x86 `src/driverkit/libDriver/pcmcia/IOPCMCIATuple.m` (plan 345 (S5-P334), 2026-10-06)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. ObjC module "pcmcia/IOPCMCIATuple.m" (objc.json module 0x20931c). Final run `s5p345-pt1`; 07 file SHA-256 `96cfdaa132a5dea8e7585e1fa63cf5cd213ab94378fb560752a954f25a0897d7`; diff `x86-IOPCMCIATuple.diff`.

- `__text` [0x1c2234, 0x1c2387) 339 B, 5 functions (5 methods) (-[IOPCMCIATuple(Private) initWithKernTuple:], -[IOPCMCIATuple free], -[IOPCMCIATuple code], -[IOPCMCIATuple length], -[IOPCMCIATuple data]). Front `ec 5d c3 00`, back `00 55 89 e5`, next function 0x1c2388.
- Sections: __TEXT,__text 339 B given by objc metadata; __TEXT,__cstring 7 B literal (references checked by content); __OBJC,__cat_inst_meth 20 B given by objc metadata; __OBJC,__message_refs 20 B literal (references checked by content); __OBJC,__class 40 B given by objc metadata; __OBJC,__meta_class 40 B given by objc metadata; __OBJC,__inst_meth 56 B given by objc metadata; __OBJC,__class_names 52 B literal (references checked by content); __OBJC,__meth_var_types 47 B literal (references checked by content); __OBJC,__meth_var_names 55 B literal (references checked by content); __OBJC,__category 20 B given by objc metadata; __OBJC,__instance_vars 16 B given by objc metadata; __OBJC,__module_info 16 B given by objc metadata; __OBJC,__symbols 20 B given by objc metadata.
- Final OBJECT_MATCH (`09_validation/reconstruction/s5p345-pt1-l1-IOPCMCIATuple-F-20261002.json`). Grade **A**.

Module "pcmcia/IOPCMCIATuple.m": __text [0x1c2234, 0x1c2387). Diagnostics s5p347-* (scratchpad bodies) gave the same verdict. Codex review of plan 345 (gpt-6.1-sol) verified. s5p345-pt1 from 07 with kr_run RUNIN: OBJECT_MATCH, relcheck 0.
