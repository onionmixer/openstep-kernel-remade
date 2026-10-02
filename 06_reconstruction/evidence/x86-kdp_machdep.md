# x86 `machdep/i386/kdp_machdep.c` (S5-P54, 2026-10-02)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. Source: Darwin 0.1
`kernel/machdep/i386/kdp_machdep.c` plus two **authored** wrapper functions (D016, plan 48 W1-W6). Diff against
Darwin: `x86-kdp_machdep.diff`. Plan 80, 80.1, 80.2. Run IDs `s5p53-*`.

- Original `__text` [0x185a8c, 0x185e03) 887 B, 15 functions; `__const` 172 B at 0x1d13f4 (3 references) and
  `__data` 15 B at 0x1e1716 (1 reference), both inferred and byte-equal (L1d).
- Authored: `kdp_en_send_pkt` (original 0x185dc0, forwards both arguments to `_en_send_pkt` at 0x185dcb) and
  `kdp_en_recv_pkt` (0x185dd4, forwards three arguments to `_en_recv_pkt` at 0x185de3), placed before
  `kdp_us_spin` as in the original. W1: no definition in Darwin (which registers function pointers in
  `kern/kdp_udp.c:113-121`), NeXTMach or Mach4. Parameter types follow `driverkit-1/.../IOEthernetDebugger.m:175-195`
  and are not proven by the bytes. One variant.
- Final 07_kernel build `s5p53-build-1`: `-O3` = variant = `0df7708dfa2554b7…` (= probe 2), `-O2` `7d671d0a…`
  differs; both `.i` identical; 21 relocations; OBJECT_MATCH (15 functions + `__const` section start).
- Gaps: back 1 x `00` (miniMonMachdep, grade P, at 0x185e04); front 0 bytes, but the preceding byte 0x185a8b is
  `90`: `_vol_check_set_poll` returns at 0x1859d8, an unnamed function 0x1859dc..0x185a86 (`jmp`) is followed by
  that `90`; its ownership is not proven -> grade **A\*** (precedent `vm_pager`).
- Adopted verbatim (Darwin): 24 headers named in `kdp_machdep.i`, including BSD network headers (`bsd/net/if.h`,
  `bsd/sys/mbuf.h`, ...). Plan 79.2 shows these BSD structures differ from the OPENSTEP 4.2 SDK; this object's
  bytes do not depend on that, but the copies may be replaced once the BSD baseline is decided.
- Probe prediction discrepancy (W5, plan 80.1): the probe predicted "`__const` 4 B possible"; actual 172 B.
