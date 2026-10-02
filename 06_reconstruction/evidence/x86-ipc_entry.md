# x86 `ipc/ipc_entry.c` (S5-P28, 2026-10-01)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. Source: Darwin 0.1
`kernel/ipc/ipc_entry.c` with restoration edits (diff `x86-ipc_entry.diff`), using the one-argument prototype of plan 53.
Plan 54, 54.1, 54.2.

- Original `__text` [0x145e44, 0x146906) 2754 B, 7 functions; `__common` `_ipc_tree_entry_zone` 4 B (0x1f621c).
  Gaps: front 0 (UFS `_ufs_nlinks` ends at 0x145e44), back 2 x `00` (next `_ipc_hash_lookup` 0x146908).
- Unedited Darwin 2826 B. Edits (probe `s5p28-probe-1`, then 07_kernel `s5p28-build-1`, identical SHA-256):
  one-argument `ipc_entry_grow_table` and its two calls; target-size path (lines 631-652), `psize` and assertion
  term removed. Comment/unused declaration/disabled assertion text is not provable from bytes (MACH_ASSERT=0).
- `-O3` SHA-256 `0a9241a629103e68e921ad9741aff2c52dd17a693ff157739eec9a634c20c33c`: OBJECT_MATCH 7/7; variant without `-fno-common` (`1618924b4bdf68a2cc02f3decf27ded397b2734e4202082ce3de74d7657db6be`) OBJECT_MATCH; 56 relocations
  correspond, bytes outside relocation fields equal; common 4 B = gap. `-O2` differs (2554 B). Grade **A**.
