F00219AC: 9de3bf78                 save    %sp, -0x88, %sp
F00219B0: 113c04cf                 sethi   %hi(dword_F0133DDC), %o0
F00219B4: d00221dc                 ld      [%o0+%lo(dword_F0133DDC)], %o0
F00219B8: d4022024                 ld      [%o0+0x24], %o2
F00219BC: c027bfe0                 clr     [%fp+var_20]
F00219C0: c027bfe4                 clr     [%fp+var_1C]
F00219C4: 9007bfd8                 add     %fp, var_28, %o0
F00219C8: d027bfe8                 st      %o0, [%fp+var_18]
F00219CC: 90102001                 mov     1, %o0
F00219D0: d027bfec                 st      %o0, [%fp+var_14]
F00219D4: d002a004                 ld      [%o2+4], %o0
F00219D8: d027bfd8                 st      %o0, [%fp+var_28]
F00219DC: d002a008                 ld      [%o2+8], %o0
F00219E0: 9207bfe0                 add     %fp, var_20, %o1
F00219E4: d027bfdc                 st      %o0, [%fp+var_24]
F00219E8: c027bff0                 clr     [%fp+var_10]
F00219EC: c027bff4                 clr     [%fp+var_C]
F00219F0: d0028000                 ld      [%o2], %o0
F00219F4: 96102000                 mov     0, %o3
F00219F8: d402a00c                 ld      [%o2+0xC], %o2
F00219FC: 4000003a                 call    _recvit
F0021A00: 98102000                 mov     0, %o4
F0021A04: 81c7e008                 ret
F0021A08: 81e80000                 restore
