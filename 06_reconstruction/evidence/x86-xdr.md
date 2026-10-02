# x86 `rpc/xdr.c` (S5-P121, 2026-10-02)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. Plan 147. Runs `s5p118-diag-11` (diagnosis), `s5p121-it1` (from 07). File: NeXTMach `https://github.com/johnsonjh/NeXTMach.git f6bdb9c3268f0eadc545d41bcc0564453b17001e` `mk-108.1/rpc/xdr.c` verbatim (SHA-256 `d01aea4505336215454192f385e3a97a4575cda74b1c3e32d51be2f59403d395`).

- Object [0x1379b8, 0x138132) 1914 B, 15 functions; front `c3 00 00 00`, back `00 00 55 89`, next symbol 0x138134.
- L1 (`09_validation/reconstruction/s5p121-it1-l1-xdr-F-20261002.json`): `__text` 0 byte and 0 reference differences (60 references), `__data` 412 B verified by L1d; 12 MATCH, 3 MATCH_UNVERIFIED (`_xdr_opaque`, `_xdr_bytes`, `_xdr_string`) whose only unverified dependency is `__bss`.
- `__bss` 16 B (static buffer, no symbol): `zerofill_check.py` -> reference-inferred at [0x1e5a20, 0x1e5a30): 3 references, one Delta, aligned, inside the original zero-fill `__bss`, no image symbol inside, no overlap with known placements (`zerofill-known-s5p88`), negative check detected (`09_validation/reconstruction/s5p121-zerofill-check-xdr-20261002.json`). Circumstantial, not proof of ownership. Added to `zerofill-known-s5p121-20261002.json`.
- Grade **P**; 12 functions high, 3 medium.
