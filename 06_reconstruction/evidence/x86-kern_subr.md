# x86 kern_subr (S5-P120, 2026-10-02)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. plan 146. Run `s5p120-adopt-1` (files from 07 only, final template with `-DINET`). Files are NeXTMach `https://github.com/johnsonjh/NeXTMach.git f6bdb9c3268f0eadc545d41bcc0564453b17001e` (D013, D020); BSD headers are the SDK set (D021).

- `kern_subr` (`mk-108.1/bsd/kern_subr.c`; edits: uwritec gains the Darwin default case: c = 0 and panic("uwritec: bogus uio_segflg") (original 0x10a554-0x10a55b, string at 0x1daa5d)): object [0x10a384, 0x10a587) 515 B, 3 functions (_uiomove, _ureadc, _uwritec); front `5d c3 00 00`, back `00 55 89 e5`, next symbol 0x10a588. Final OBJECT_MATCH (`09_validation/reconstruction/s5p120-adopt-1-l1-kern_subr-F-20261002.json`). Grade **A**.
