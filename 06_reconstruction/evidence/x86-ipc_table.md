# x86 `ipc/ipc_table.c` (S5-P12, 2026-10-01)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`.
Source: Darwin 0.1 `kernel/ipc/ipc_table.c` with a restoration edit (`x86-ipc_table.diff`).
Plan: `02_plan/RECONSTRUCTION_PLAN.md` 35, 35.1, 35.2, 36, 36.1, 36.2.

- Original: `__text` 0x151934–0x151be6 (690 B, five functions), `__data` `ipc_table_entries_size` = 128 and
  `ipc_table_dnrequests_size` = 64 at 0x1dea94, `__common` `ipc_table_dnrequests` 0x1f6328 and
  `ipc_table_entries` 0x1f632c (4 B each, order opposite to the source definitions).
- Restoration edit: 512 → 128, and the increment cap of `ipc_table_fill` removed (the original doubles
  unconditionally at 0x1519b5 and in the two inlined copies at 0x151a6b, 0x151b1f). My first plan
  ("only 512 → 128") was wrong (plan 35.1).
- Build `s5p12-build-1` (`-fno-common`, `-O3` = `-O4`, `-O2` differs): `__text` 0 byte differences,
  `__data` placed at 0x1dea94 and equal; the object's `__common` keeps definition order, so it cannot be
  placed with one Delta and four references stayed unverified (plan 35.2).
- Common-symbol variant `s5p12-common-1` (same command without `-fno-common`, identical preprocessed
  input): the two globals become undefined common symbols of size 4; the 28 relocations sit at the same
  addresses with the same width/pcrel/type, non-field bytes are identical, and the four references become
  external VANILLA relocations by name. L1: OBJECT_MATCH, all references verified
  (`09_validation/reconstruction/s5p12-l1-O3common-20261001.json`). Common sizes 4 ≤ original gaps 4.
  Scope (plan 36.1): the references recomputed with the reconstructed names equal the original fields;
  whether the original object used `-fno-common`, and the `__common` layout rule, are not decided here (S6).
- Boundary certificate: alignment 2^2, front `00`×2, back `00`×2 → grade **A**.
