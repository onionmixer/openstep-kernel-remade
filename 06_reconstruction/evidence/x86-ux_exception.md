# x86 `src/uxkern/ux_exception.c` (plan 219 (S5-P197), 2026-10-02)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. plan 219 (S5-P197). Final run `s5p197-it3`; 07 file SHA-256 `53674adf2b783ec9b52a6ed454e8b6cca70174d1fdbb5b2eadaf9ca43ed3d075`; diff `x86-ux_exception.diff`.

- Object [0x171cb4, 0x172038) 900 B, 4 functions ((static ux_handler), _ux_handler_init, _catch_exception_raise, (static ux_exception)). Front `c3 00 00 00`, back `55 89 e5 83`, next symbol 0x172038.
- Final L1 `09_validation/reconstruction/s5p197-it3-l1-ux_exception-F-20261002.json`: __text/__const 0 byte differences; __DATA,__bss reference-inferred only. Grade **P**.

Object extent [0x171cb4, 0x172038): linker 0x00 fill before 0x171cb4; vm_fault starts at 0x172038. Diagnosis 13 failed on machine/exception.h and the Mach 2.5 IPC headers of the NeXTMach text; the body was written from the original bytes. The codex review of plan 219 (slow first reply and a narrower second one, both checked) found no wrong fact (names and static status are inferences). Iterations: it1 ux_handler_init and ux_exception match; variants s5p197-v1 (message buffers declared in the loop block, m1), s5p197-v2..v4 (catch_exception_raise: task local, ret before signal, NULL thread handled in the else branch, e1); it2 ux_handler_init argument order (variants s5p197-v5: task computed in its own statement, f1); it3 all 4 functions match, extern relocation names match (relcheck 0); the two statics in __DATA,__bss are reference-inferred (zerofill_check).
