# x86 `vm/vm_resident.c` (S5-P65..S5-P71, 2026-10-02)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. Plans 91.2, 95, 95.1, 95.2, 96, 96.1, 96.2, 97, 97.1. Run IDs `s5p65-pre-vm_resident`,
`s5p69-probe-1`, `s5p70-probe-1`, `s5p71-build-1`. 07_kernel file SHA-256 `1ea8dccba8c55e32aadd707e564bfbd5639e46ab70e01263ea34b38d7d533d9f`; diff `x86-vm_resident.diff`.

- Original `__text` [0x17a9b4, 0x17b9dd) 4137 B, 17 functions. Front 3 x `00` (= gap after confirmed
  `x86-vm_policy`), back 3 x `00` (= gap before confirmed `x86-vm_synchronize`; minimal fill to 2^2).
- Darwin as is: 4345 B. Changes, each checked against original bytes:
  1. Removed `vm_page_deactivate_first` (no such original symbol).
  2. Removed `round_page` from `PALLOC_PAGES` (the original `zdata_size` is `8*page_size` unrounded, 0x17abe9).
  3. `vm_page_deactivate` body from NeXTMach `vm_resident.c:1017-1038`, without Darwin's `age` helper.
  4. Authored `return(vavail);` (original 0x17adfd reads the third argument).
- Probes: probe 1 (changes 1–2) gives 4137 B and 15/17 MATCH; probe 2 (all four changes) gives O3c OBJECT_MATCH
  17/17.
- Final build `s5p71-build-1`: `-O3` `7a9fcea4…`, common variant `a423bca0…` (= probe 2), `-O2` differs; both
  `.i` identical.
  - L1 common variant OBJECT_MATCH 17/17 incl. `__data` 172 B (`09_validation/reconstruction/s5p71-build-l1-vm_resident-O3c-20261002.json`).
  - Plan 36.1: 255 relocations correspond (78 same, 141 local -> extern, 36 scattered -> extern), bytes outside
    equal; 25 commons <= gaps.
- Grade **A**; 17 functions high. All 122 files named in `vm_resident.i` exist in 07_kernel.
