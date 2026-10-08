# x86 `src/objc-runtime/objc-zone.c` (plan 360 (S5-P346), 2026-10-07)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. ObjC module "objc-zone.c" (objc.json module (none)). Final run `s5p360-r1zone`; 07 file SHA-256 `1adee3b38e25ceef3ba87feb817695430b67ac36e8a99fa58af14423fb030a6f`; diff `x86-objc-objc-zone.diff`.

- `__text` [0x1cdeb0, 0x1cdf30) 128 B, 9 functions (0 methods) ((static kern_realloc), (static kern_malloc), (static kern_free), (static kern_destroy), _NXDefaultMallocZone, _NXZoneFromPtr, _NXCreateZone, _NXNameZone, _NXZoneCalloc). Front `80 ca 1c 00 1c cb 1c 00 44 cb 1c 00 00 00 00 00`, back `55 89 e5 8b`, next function 0x1cdf30.
- Sections: __TEXT,__text 128 B given by symbol; __DATA,__data 16 B given by symbol.
- Final OBJECT_MATCH (`09_validation/reconstruction/s5p360-r1zone-l1-objc_zone-F-20261002.json`). Grade **A**.

Kernel ObjC runtime NXZone layer (D024, D027), plan 360. Static names kern_* are reconstruction choices (not in the original symbol table). __DATA,__data KernelZone [0x1e55e4, 0x1e55f4) = {0x1cdeb0, 0x1cdec4, 0x1cded4, 0x1cdee8} matched with its relocations; the preceding word 0x1e55e0 is _zoneRealloc of objc-globaldata.m (not part of this object). Diagnostic s5p360-dzone; codex review of plan 360 verified (wording corrected to name the near-Darwin parts). Final s5p360-r1zone from 07.
