# x86 `src/driverkit/libDriver/pcmcia/IOPCMCIADirectDevice.m` (plan 345 (S5-P334), 2026-10-06)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. ObjC module "pcmcia/IOPCMCIADirectDevice.m" (objc.json module 0x2092fc). Final run `s5p345-px1`; 07 file SHA-256 `399c879b9ab4e93e8e342234eb8e8b117742443dfbcd180c121e34124eb82f5e`; diff `x86-IOPCMCIADirectDevice.diff`.

- `__text` [0x1c1cb8, 0x1c2081) 969 B, 2 functions (2 methods) (-[IODirectDevice(IOPCMCIADirectDevice) mapAttributeMemoryTo:findSpace:], -[IODirectDevice(IOPCMCIADirectDevice) unmapAttributeMemory]). Front `5d c3 00 00`, back `00 00 00 55`, next function 0x1c2084.
- Sections: __TEXT,__text 969 B given by objc metadata; __TEXT,__cstring 72 B literal (references checked by content); __OBJC,__cat_inst_meth 32 B given by objc metadata; __OBJC,__message_refs 100 B literal (references checked by content); __OBJC,__cls_refs 8 B literal (references checked by content); __OBJC,__class_names 79 B literal (references checked by content); __OBJC,__meth_var_types 24 B literal (references checked by content); __OBJC,__meth_var_names 460 B literal (references checked by content); __OBJC,__category 20 B given by objc metadata; __OBJC,__module_info 16 B given by objc metadata; __OBJC,__symbols 16 B given by objc metadata.
- Final OBJECT_MATCH (`09_validation/reconstruction/s5p345-px1-l1-IOPCMCIADirectDevice-F-20261002.json`). Grade **A**.

Module "pcmcia/IOPCMCIADirectDevice.m": __text [0x1c1cb8, 0x1c2081). Diagnostics s5p347-* gave the same verdict. Codex second review of plans 345a/345b (gpt-6.1-sol) verified (setRegister movzx and five header adoptions added). s5p345-px1 from 07 with kr_run RUNIN: OBJECT_MATCH, relcheck 0.
