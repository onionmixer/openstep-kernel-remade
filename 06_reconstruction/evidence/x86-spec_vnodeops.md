# x86 `src/bsd/specfs/spec_vnodeops.c` (plan 370 (S5-P353), 2026-10-07)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. plan 370 (S5-P353). Final run `s5p370-r1sp`; 07 file SHA-256 `144ad73ba4c43ff95c8293fc26641982dfa94462171d30f6af02e308184bc16d`; diff `x86-spec_vnodeops.diff`.

- Object [0x139ba8, 0x13a588) 2528 B, 19 functions ((static spec_open), (static spec_close), (static spec_rdwr), (static spec_ioctl), (static spec_select), (static spec_inactive), (static spec_getattr), _spec_setattr, _spec_access, _spec_link, (static spec_devblocksize), _spec_fsync, (static spec_dump), (static spec_noop), _spec_lockctl, _spec_fid, (static spec_cmp), _spec_realvp, (static spec_strategy)). Front `89 ec 5d c3`, back `55 89 e5 83`, next symbol 0x13a588.
- Final OBJECT_MATCH (`09_validation/reconstruction/s5p370-r1sp-l1-spec_vnodeops-F-20261002.json`). Grade **A**.

spec_vnodeops [0x139ba8, 0x13a588) 2528 B, 19 functions, __data 228 B. Register residue of plan 354 (spec_open, error in %ebx instead of %eax) explained by GCC dumps (s5p370-spdg): implicit-int set_blocksize call (call_value) made the error pseudo conflict with %eax; declaring it void gives the original caller-save form (0x139cf5/0x139cfd). Diagnostics s5p354-* (plan 354), s5p370-spe1..e8, spf. Codex review of plan 370 (gpt-6.1-sol) verified. Final s5p370-r1sp from 07: OBJECT_MATCH, relcheck 0.
