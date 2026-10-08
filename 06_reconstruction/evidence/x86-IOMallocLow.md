# x86 `src/driverkit/IOMallocLow.c` (plan 293 (S5-P283), 2026-10-04)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. plan 293 (S5-P283). Final run `s5p283-it1`; 07 file SHA-256 `35de35cf20ba99816c433fdfed53ec334724820da7fedd015d5a8d92bc990ff0`; diff `x86-IOMallocLow.diff`.

- Object [0x1c87e0, 0x1c88eb) 267 B, 2 functions (_IOMallocLow, _IOFreeLow). Front `ec 5d c3 00`, back `00 55 89 e5`, next symbol 0x1c88ec.
- Final OBJECT_MATCH (`09_validation/reconstruction/s5p283-it1-l1-IOMallocLow-F-20261002.json`). Grade **A**.

Object [0x1c87e0, 0x1c88eb) 267 B + 00 1 B; front -[IOVPCodeDisplay setIntValues:forParameter:count:] (0x1c865c, 00 1 B), next _IOBreakToDebugger 0x1c88ec. __TEXT,__cstring "IOFreeLow: buf 0x%x not found\n" (31 B). _dmaBufQueue is a common symbol (8 B; original __common 0x1f7490). No Objective-C module record for IOMallocLow.m among the 76 modules (objc.json), so built as C. References by file name: Darwin 0.1 driverkit-1/libDriver/Kernel/IOMallocLow.m (text nearly the same); no Mach4/NeXTMach file of that name. Headers: SDK driverkit/i386/kernelDriver.h; SDK kernserv/queue.h read verbatim (stage_headers --public-sdk, plan 293) because the 07 nextdev_private copy (plan 141.2 KERNEL_PRIVATE branch to kern/queue.h) gives other queue_enter/queue_remove code (scratch s5p283-c1 NOT_MATCH 241 B); SDK macros match (s5p283-w3). Two codex reviews of plan 293 (verified: queue.h diagnosis, w1 wording, MODIFICATIONS step). it1 (s5p283-it1) from 07 OBJECT_MATCH, relcheck 0.
