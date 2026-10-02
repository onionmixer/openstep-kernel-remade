# x86 NeXTMach batch 5 (S5-P123, 2026-10-02)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. plan 149.3. Run `s5p123-adopt-1` (files from 07 only, final template with `-DINET`). Files are NeXTMach `https://github.com/johnsonjh/NeXTMach.git f6bdb9c3268f0eadc545d41bcc0564453b17001e` (D013, D020); BSD headers are the SDK set (D021).

- `raw_usrreq` (`mk-108.1/net/raw_usrreq.c`): object [0x121554, 0x121a3c) 1256 B, 5 functions (_raw_init, _raw_input, _rawintr, _raw_ctlinput, _raw_usrreq); front `89 ec 5d c3`, back `55 89 e5 83`, next symbol 0x121a3c. Final OBJECT_MATCH (`09_validation/reconstruction/s5p123-adopt-1-l1-raw_usrreq-F-20261002.json`). Grade **A**.

- 2026-10-02 (plan 150): with `-DMULTICAST` the common `_rawcb` of raw_usrreq is 92 B (88 B before), equal to the original gap 0x1ea9f0 -> next symbol (92 B). All other bytes unchanged (`s5p124-regress-1`).
