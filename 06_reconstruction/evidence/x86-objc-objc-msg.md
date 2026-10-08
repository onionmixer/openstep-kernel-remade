# x86 `src/objc-runtime/objc-msg.s` (plan 360 (S5-P346), 2026-10-07)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. ObjC module "objc-msg.s" (objc.json module (none)). Final run `s5p360-r1msg`; 07 file SHA-256 `b61b3e6ad7eb2c30718ed1353d791a951fd8ef2b9bcc7c631664a13ed49560c4`; diff `x86-objc-objc-msg.diff`.

- `__text` [0x1ce960, 0x1cec2d) 717 B, 4 functions (0 methods) (_objc_msgSend, _objc_msgSendSuper, __objc_msgForward, _objc_msgSendv). Front `c3 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00`, back `00 00 00 55`, next function 0x1cec30.
- Sections: __TEXT,__text 717 B given by symbol; __OBJC,__meth_var_names 10 B literal (references checked by content); __OBJC,__message_refs 4 B literal (references checked by content); __TEXT,__cstring 31 B literal (references checked by content).
- Final OBJECT_MATCH (`09_validation/reconstruction/s5p360-r1msg-l1-objc_msg-F-20261002.json`). Grade **A**.

Kernel ObjC runtime message dispatch (D045, D046, D047), plan 360. objc-msg.s includes objc-msg-i386-lock.s because objc-config.h leaves OBJC_COLLECTING_CACHE undefined under -DKERNEL; original 0x1ce964 andl __objc_multithread_mask (0x1e5604) confirms the lock variant. __text 717 B then 3 x 00 to 0x1cec30; also __OBJC,__meth_var_names 10 B, __OBJC,__message_refs 4 B, __cstring 31 B (literal, checked by content). Diagnostic s5p360-dmsg; codex review of plan 360 verified (corrected nolock -> lock). Final s5p360-r1msg from 07.
