# x86 `src/driverkit/machdepFuncs.c` (plan 293 (S5-P283), 2026-10-04)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. plan 293 (S5-P283). Final run `s5p283-it2`; 07 file SHA-256 `76245f8eaafd502bbf2677a3e61ee3daf4ecc49578c5f67408d0765ad7591e72`; diff `x86-machdepFuncs.diff`.

- Object [0x1c88ec, 0x1c88f4) 8 B, 1 functions (_IOBreakToDebugger). Front `ec 5d c3 00`, back `00 00 00 00`, next symbol 0x1ca488.
- Final OBJECT_MATCH (`09_validation/reconstruction/s5p283-it2-l1-machdepFuncs-F-20261002.json`). Grade **A**.

Object [0x1c88ec, 0x1c88f4) 8 B (55 89 e5 cc 89 ec 5d c3); front IOMallocLow (00 at 0x1c88eb), then 00 12 B and sub_1C8900. No Objective-C module record for machdepFuncs.m among the 76 modules (objc.json), so built as C. References by file name: Darwin 0.1 driverkit-1/libDriver/i386/machdepFuncs.m (text nearly the same); no Mach4/NeXTMach file of that name. it2 (s5p283-it2) from 07 OBJECT_MATCH, relcheck 0 (no relocations).
