F001552C: 9de3bf78                 save    %sp, -0x88, %sp
F0015530: 113c04cf                 sethi   %hi(dword_F0133DDC), %o0
F0015534: d00221dc                 ld      [%o0+%lo(dword_F0133DDC)], %o0
F0015538: d2022024                 ld      [%o0+0x24], %o1
F001553C: d0026004                 ld      [%o1+4], %o0
F0015540: d027bfd8                 st      %o0, [%fp+var_28]
F0015544: d2026008                 ld      [%o1+8], %o1
F0015548: 9007bfe0                 add     %fp, var_20, %o0
F001554C: d227bfdc                 st      %o1, [%fp+var_24]
F0015550: 9207bfd8                 add     %fp, var_28, %o1
F0015554: d227bfe0                 st      %o1, [%fp+var_20]
F0015558: 92102001                 mov     1, %o1
F001555C: d227bfe4                 st      %o1, [%fp+var_1C]
F0015560: 4000004f                 call    _rwuio
F0015564: 92102000                 mov     0, %o1
F0015568: 81c7e008                 ret
F001556C: 81e80000                 restore
