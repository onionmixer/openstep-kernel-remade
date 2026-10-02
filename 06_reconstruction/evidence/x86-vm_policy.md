# x86 `vm/vm_policy.c` (S5-P65/66, 2026-10-02)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. Plans 91, 91.1, 91.2, 92, 92.1. Run IDs `s5p65-pre-vm_policy`, `s5p66-build-1`.
Source: Darwin 0.1 `kernel/vm/vm_policy.c`, unchanged (07_kernel SHA-256 `aca8ff478ff44ad77f626f9b28db8bb3678b11df7ba6a3b45952dbeb607b9761`; APSL and NeXT 1992 notice).

- Original `__text` [0x17a338, 0x17a9b1) 1657 B, 7 functions: `_vm_policy_apply`, static `deactivate_object`
  (Ghidra FUN_0017a4f0), static `deactivate_range` (FUN_0017a594), static `set_policy` (FUN_0017a6f4),
  `_vm_set_policy`, `_vm_fault_range`, `_vm_deactivate`. Front 2 x `00` (0x17a336, also the gap after confirmed
  `x86-vm_pager`), back 3 x `00` (minimal fill to 2^2; next range 0x17a9b4).
- Build `s5p66-build-1`: `-O3` = common variant `75be59ca…` (= probe), `-O2` `82faaabd…` differs; both `.i`
  identical (`64ea7426…`). Only `__text` (1657 B, 50 relocations): no data, common or bss, so plan 36.1 does not
  apply.
- L1 (`09_validation/reconstruction/s5p66-build-l1-vm_policy-O3-20261002.json`, ranges keyed by object symbol names): OBJECT_MATCH 7/7, 0 byte differences, 50 references
  verified.
- Grade **A**; 7 functions high. All 123 files named in `vm_policy.i` already exist in 07_kernel.
