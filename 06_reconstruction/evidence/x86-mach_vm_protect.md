# x86 `src/mach/vm_protect.c` (plan 361 (S5-P347), 2026-10-07)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. plan 361 (S5-P347). Final run `s5p361-r1vmprotect`; 07 file SHA-256 `3a9061dba3e8a2275a78dc3d9381c84ffe18dcc3836236d66f7b555f70c3ad69`; diff `x86-mach_vm_protect.diff`.

- Object [0x1d0dac, 0x1d0e8b) 223 B, 1 functions (_vm_protect_EXTERNAL). Front `ec 5d c3 00`, back `00 55 89 e5`, next symbol 0x1d0e8c.
- Final OBJECT_MATCH (`09_validation/reconstruction/s5p361-r1vmprotect-l1-vm_protect-F-20261002.json`). Grade **A**.

Mach user-API stub (mig -i, Darwin MACH_FILES/MACH_OFILES rules) of the 4.2 SDK mach/mach.defs. __TEXT,__const request type descriptors and reply checks (static const msg_type_t/msg_type_long_t) placed inferred and verified by L1d, 0 byte differences. The generated mach_interface.h equals the SDK copy 07_kernel/nextdev/mach/mach_interface.h (sha256 b96918ad71dbdc2d1f1b0b31f9e7135b7297626b0c87e375fdf8b995199903a7); staging supplies it (no copy in src/mach). Diagnostic s5p361-dvmprotect; MIG runs s5p361-migi1 (diagnosis), s5p361-mig3 (final, stage/migi via plan 361.1); real-machine cc -M s5p361-depmach (port_allocate: 40 headers, all from 07). Codex reviews of plan 361 and 361.1 (gpt-6.1-sol) verified. Final s5p361-r1vmprotect from 07: OBJECT_MATCH, relcheck 0.
