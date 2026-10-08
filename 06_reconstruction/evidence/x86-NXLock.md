# x86 `src/driverkit/libDriver/Kernel/NXLock.m` (plan 298 (S5-P288), 2026-10-04)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. ObjC module "Kernel/NXLock.m" (objc.json module 0x2090ec). Final run `s5p288-it2`; 07 file SHA-256 `cb6a86ffdb661d49cc11362a1e40fd43f6569c8065d0cff9e87576674a88aebe`; diff `x86-NXLock.diff`.

- `__text` [0x1a8fd8, 0x1a90b7) 223 B, 4 methods (-[NXLock init], -[NXLock free], -[NXLock lock], -[NXLock unlock]). Front `c3 00 00 00`, back `00 55 89 e5`, next function 0x1a90b8.
- Sections: __TEXT,__text 223 B given by objc metadata; __OBJC,__cat_cls_meth 12 B inferred, verified by L1d; __OBJC,__cat_inst_meth 20 B inferred, verified by L1d; __OBJC,__message_refs 8 B literal (references checked by content); __OBJC,__class 40 B given by objc metadata; __OBJC,__meta_class 40 B given by objc metadata; __OBJC,__inst_meth 56 B given by objc metadata; __OBJC,__protocol 20 B inferred, verified by L1d; __OBJC,__class_names 30 B literal (references checked by content); __OBJC,__meth_var_types 11 B literal (references checked by content); __OBJC,__meth_var_names 28 B literal (references checked by content); __OBJC,__instance_vars 16 B given by objc metadata; __OBJC,__module_info 16 B given by objc metadata; __OBJC,__symbols 16 B given by objc metadata.
- Final OBJECT_MATCH (`09_validation/reconstruction/s5p288-it2-l1-NXLock-F-20261002.json`). Grade **A**.

Module "Kernel/NXLock.m": methods 0x1a8fd8-0x1a90b6, 4 methods; front NXConditionLock (00 x 3), next generalFuncsPrivate _IOInitGeneralFuncs 0x1a90b8 (00 x 1). Scratch s5p288-nxlock-1 (Darwin body + diagnostic #line) OBJECT_MATCH. Codex review of plans 298/299 verified (ranges, padding). s5p288-it2 from 07 with kr_run RUNIN: OBJECT_MATCH, relcheck 0.
