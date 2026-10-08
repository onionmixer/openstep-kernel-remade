# x86 `src/ipc/ipc_init.c` (plan 267 (S5-P253), 2026-10-04)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. plan 267 (S5-P253). Final run `s5p253-it1`; 07 file SHA-256 `88d5cadbe0e0475a6fb340e2803393a0aa2df3df8824907ccf9207777c304ef3`; diff `x86-ipc_init.diff`.

- Object [0x146dc0, 0x146f38) 376 B, 2 functions (_ipc_bootstrap, _ipc_init). Front `5d c3 00 00`, back `55 89 e5 8b`, next symbol 0x146f38.
- Final OBJECT_MATCH (`09_validation/reconstruction/s5p253-it1-l1-ipc_init-F-20261002.json`). Grade **A**.

Object extent [0x146dc0, 0x146f38) 376 B (ret at 0x146f37, no pad; front 00 00 after _ipc_hash_info): ipc_bootstrap, ipc_init; next ipc_kmsg_enqueue. __DATA,__data [0x1de6bc, 0x1de70d) 81 B (ipc_kernel_map_size 0x100000, ipc_space_max 0x205, ipc_tree_entry_max 0x10000, ipc_port_max 0x5a20, ipc_pset_max 0x4c8 -- equal to the 07 kern/mach_param.h formulas by Python -- and five strings; then 00 00 00 and ipc_marequest_max) -- given by symbol. Commons _ipc_kernel_map, _ipc_soft_map, _ipc_soft_task (original 0x1f622c, 0x1f6244, 0x1f6248). References by file name: Mach4 ipc/ipc_init.c (base, D022), Darwin 0.1 ipc/ipc_init.c (structure), NeXTMach mk-108.1 has no ipc_init.c but kern/ipc_globals.c holds ipc_init and the three globals (used for the soft-task lines; reported by the codex review, verified). Scratch builds s5p253-w1 (Mach4 as is: zone flags missing), w2, w3 (NeXTMach soft-task form) OBJECT_MATCH. it1 (s5p253-it1) from 07 OBJECT_MATCH, relcheck 0 mismatches.
