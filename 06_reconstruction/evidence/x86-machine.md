# x86 `kern/machine.c` and options `MACH_KDB`, `NORMA_ETHER` (S5-P41, 2026-10-02)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. Source: Darwin 0.1
`kernel/kern/machine.c`, unchanged. Plan 67, 67.1, 67.2. Run IDs `s5p42-*`.

- Options added to `06_reconstruction/config_options.tsv` (both hypothesis, value 0; generated headers
  `07_kernel/generated/mach_kdb.h`, `norma_ether.h`): `MACH_KDB` — no option in Darwin `conf/MASTER*`, users only
  `kern/exception.c` (and an include in `bsd/sys/reboot.h`); the original has no `_debug_user_with_kdb`,
  `_thread_kdb_return`, `_db_printf` and no "No exception server, calling kdb" string. `NORMA_ETHER` — not in the
  RELEASE tags (`MASTER.i386:72`); only included by `machine.c`, value unused, so no byte evidence.
- Regression `s5p42-regress-1`: the 55 confirmed + 4 partial objects rebuilt after the `meta_features.h` change,
  59/59 SHA-256 equal to the baseline (`08_build/runs/tools/s5p42-regress-baseline.json`).
- Original `__text` [0x15de68, 0x15dfe4) 380 B, 6 functions. Gaps 0/0 (`ret` 0x15de67, `_mfs_init` 0x15dfe4).
  `processor_assign` is the `#else NCPUS > 1` definition (`machine.c:723`), `NCPUS=1`.
- Final 07_kernel build `s5p42-build-1`: `-fno-common` `-O3` = `-O2` = `39a4e686c55a538a…` (bytes/references 0
  differences; 4 references unverified because `__common` 64 B is ambiguous; `_cpu_up`/`_cpu_down` show `DIFF`
  only because `l1_compare.py` treats the empty `__data` section as one byte, `sect_of` line 68); common variant
  `67e04b32e60e1060…` OBJECT_MATCH 6/6, 17 references; both `.i` identical.
- Plan 36.1: 17 relocations with equal positions/width/pcrel/type: 11 extern -> extern, 4 scattered -> extern,
  2 local -> extern; bytes outside relocations equal; commons (size/gap) `_action_lock` 4/4, `_action_queue` 8/8,
  `_machine_info` 20/20, `_machine_slot` 32/32. Grade **A**.
- Adopted verbatim: `bsd/sys/reboot.h` (also UC notice), `bsd/machine/reboot.h`, `bsd/i386/reboot.h`.
