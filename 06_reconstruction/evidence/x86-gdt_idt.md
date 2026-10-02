# x86 machdep/i386 `gdt.c`, `idt.c` (S5-P17, 2026-10-01)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. Plan 42, 42.1, 42.2.
Sources: Darwin 0.1 `kernel/machdep/i386/gdt.c` verbatim; `idt.c` with one restoration edit (diff `x86-idt.diff`,
edited file SHA-256 `7a619567afbd55fc4c415ff00055153f5b454197009eea3fbc0d662e23c021c2`).

| file | original `__text` | `__data` | object SHA-256 (-O3 = -O4) | L1 -O3 | gaps | grade |
|---|---|---|---|---|---|---|
| gdt.c | 0x18a904–0x18aafa (502 B; `_locate_gdt`, `_gdt_init`) | 0x1e18b0, 260 B (256 B `gdt_store` zeros + `gdt`) | `8755a049be92a042c9e2af6402dd1b28f72a796f4c9e51797a43494f20e6e1b7` | OBJECT_MATCH, 0 diff, 20 text refs + 1 data ref | 2 x 00 / 2 x 00 | A |
| idt.c | 0x18b184–0x18b2ab (295 B; `_locate_idt`, `_idt_init`) | 0x1e1a04, 2052 B (`idt_pseudo` 256 entries + `idt`) | `c8fd75e607fc091ad7468a2c0618d4e583af7a650f6bb73420367842f7c55dee` | OBJECT_MATCH, 0 diff, 12 text refs + 257 data refs | 3 x 00 / 1 x 00 | A |

- `-O2` differs for both (gdt 486 B, idt 279 B) — another object fixing `-O3`.
- idt.c edit: `idt_copy` removed. Evidence: no `_idt_copy` symbol, no `idt_copy` bytes in the whole image file,
  original `_i386_init` has no IDT copy call (Darwin i386_init.c:159–163 'f00f' work-around absent). Symbol absence
  alone would not exclude a static or inlined variant; the object span and the L1 match show none is in this object.
- Unedited Darwin control (`s5p17-pre-1`): idt `__text` 378 B, `__data` 2061 B (+`"idt_copy"`), gdt identical to final.
- Source quirk preserved: idt.c:159–162 passes four arguments to the three-parameter `make_task_gate`
  (desc_inline.h:409–417); the original shows the same effect.
- 07_kernel: 112 files read, 110 already present, `gdt.c` and `idt.c` adopted.
