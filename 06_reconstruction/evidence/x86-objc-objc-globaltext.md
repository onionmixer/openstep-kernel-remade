# x86 `src/objc-runtime/objc-globaltext.m` (plan 360 (S5-P346), 2026-10-07)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. ObjC module "objc-globaltext.m" (objc.json module (none)). Final run `s5p360-r1gt`; 07 file SHA-256 `44eb6c11c7121aca8f2dce2fed970ee6cf806788e6c7e7056169ae1af198b412`; diff `x86-objc-objc-globaltext.diff`.

- `__text` [0x1cde40, 0x1cdeb0) 112 B, 7 functions (0 methods) (_NXPtrPrototype, _NXStrPrototype, _NXPtrStructKeyPrototype, _NXStrStructKeyPrototype, _NXPtrValueMapPrototype, _NXStrValueMapPrototype, _NXObjectMapPrototype). Front `03 e8 8a e3 f3 ff 8d 65 f8 5b 5f 89 ec 5d c3 00`, back `55 89 e5 8b`, next function 0x1cdeb0.
- Sections: __TEXT,__text 112 B given by symbol.
- Final OBJECT_MATCH (`09_validation/reconstruction/s5p360-r1gt-l1-objc_globaltext-F-20261002.json`). Grade **A**.

Kernel ObjC runtime data-only module (D045, D046, D047), plan 360: 7 const NXHashTablePrototype/NXMapTablePrototype definitions (NXPtrPrototype .. NXObjectMapPrototype) placed in __TEXT,__text by #pragma CC_NO_MACH_TEXT_SECTIONS; no functions.tsv rows (data, not code). Last 4 bytes 00 are the last prototype field. Diagnostic s5p360-dgt; codex review of plan 360 verified. Final s5p360-r1gt from 07.
