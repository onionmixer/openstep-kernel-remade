# x86 `driverkit/ddm.c` (S5-P56, 2026-10-02)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. Source: Darwin 0.1
`kernel/driverkit/ddm.c`, unchanged; options `UXPR=1`, `XPR_DEBUG=0` (plan 81); private headers from Darwin
`driverkit-139.1-1.tar.gz` (`-Isrc/components/driverkit-1`). Plan 82, 82.1, 82.2. Run IDs `s5p55-*`.

- Original `__text` [0x18494c, 0x184bb6) 618 B, 7 functions (all original symbols). Gaps: front 0 (`ret`
  0x18494b; the objects.tsv lower bound 0x18447c is only the end of the previous labelled run and
  `debugging.m` is an alternative source candidate, not a preceding object), back 2 x `00` (`_volopen` 0x184bb8).
- Final 07_kernel build `s5p55-build-1`: `-O3` `fc557038fdb43a2b…`, common variant `af1e2c096f6e0491…`, `-O2`
  differs; both `.i` identical. L1: 4 MATCH, 3 MATCH_UNVERIFIED (`_IOInitDDM`, `_IOAddDDMEntry`, `_IOClearDDM`,
  only `__bss`). `__data` 74 B (`_xprLocked`) equal.
- `__TEXT,__const` 12 B `40 00 00 00 41 00 00 00 42 00 00 00`: static `_timer_cnt_port_`
  (`machdep/i386/timer_inline.h:83`), no incoming relocation -> unverified.
- `__DATA,__bss` 20 B: `zerofill_check.py` (known `zerofill-known-s5p55-20261002.json`) 5 references (offsets
  12, 16 = `xprEnd`, `xprInitialized`), one delta 0x1e72b0, candidate [0x1e7574, 0x1e7588), negative check
  detected -> reference-inferred; bytes [0, 12) (`xxx` dummies of `outb/outw/outl`) placed only by continuity.
- Commons (plan 36.1 correspondence): `_IODDMMasks` 16/16, `_uxprGlobal` 16/16, `_xpr_lock` 4/4 (size/gap);
  41 relocations (19 same kind, 8 local -> extern, 14 scattered -> extern), bytes outside equal. 36.1's literal
  OBJECT_MATCH condition is not reached because of `__bss`/`__const` (dma precedent).
- Grade **P**; 4 functions high, 3 medium. `_IOInitDDM` holds the `XPR_DEBUG` branch (`IOMalloc` at 0x184964),
  byte-equal but MATCH_UNVERIFIED, so `XPR_DEBUG` stays a hypothesis.
- Adopted verbatim: 20 headers named in `ddm.i` (Darwin kernel, architecture and driverkit archives).
