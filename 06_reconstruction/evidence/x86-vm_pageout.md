# x86 `vm/vm_pageout.c` (S5-P65, S5-P72..S5-P75, 2026-10-02)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. Plans 91.2, 98-101 (98.1, 98.2, 99.1, 99.2, 100.1, 100.2, 101.1). Run IDs
`s5p65-pre-vm_pageout`, `s5p72-probe-1/2`, `s5p73-probe-1`, `s5p74-probe-1`, `s5p75-build-1`. 07_kernel file
SHA-256 `29715f7bb46eeb940b3d02ee209262dd3daf3ceba73c044579272d007f2c3647`; diff `x86-vm_pageout.diff` (probe diffs `x86-vm_pageout-probe1..4.diff`).

- Object [0x179d44, 0x17a240) 1276 B: `_vm_pageout_scan` 864 B, `_vm_pageout` 410 B + compiler alignment `90 90`
  (0x17a23e). Front 3 x `00` (= gap after confirmed `x86-vm_object`), back 0 B (confirmed `x86-vm_pager`).
- Darwin as is: 1408 B. Restoration edits, each matched against the original bytes:
  - `vm_pageout`: no `self` local, `stack_privilege` or sched stores; reserved set to 3 (NeXTMach form).
  - `vm_pageout_scan`: no yield block, no `pages_cleaned`.
  - Data `vm_page_free_min_sanity` 128 KB (NeXTMach `vm_pageout.c:75`; original 0x20000).
- Probe 4 / final build `s5p75-build-1`: `-O3` = `-O2` `4d60fe86…`, common variant `cd58704a…`; both `.i`
  identical. L1 OBJECT_MATCH 2/2 for both variants (99 references); `__text`, `__data` 8 B and the two commons
  placed by symbols.
- Grade **A**; 2 functions high. All 93 files named in `vm_pageout.i` exist in 07_kernel.
- Consequence: the `90 90` before `x86-vm_pager` (0x17a23e) belongs to this object, so vm_pager's front boundary
  is proven and vm_pager is re-judged **A** (was A*), plan 101.1.
