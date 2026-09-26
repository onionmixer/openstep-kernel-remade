F0021654: 9de3bf78                 save    %sp, -0x88, %sp
F0021658: 113c04cf                 sethi   %hi(dword_F0133DDC), %o0
F002165C: d00221dc                 ld      [%o0+%lo(dword_F0133DDC)], %o0
F0021660: d2022024                 ld      [%o0+0x24], %o1
F0021664: c027bfe0                 clr     [%fp+var_20]
F0021668: c027bfe4                 clr     [%fp+var_1C]
F002166C: 9007bfd8                 add     %fp, var_28, %o0
F0021670: d027bfe8                 st      %o0, [%fp+var_18]
F0021674: 90102001                 mov     1, %o0
F0021678: d027bfec                 st      %o0, [%fp+var_14]
F002167C: d0026004                 ld      [%o1+4], %o0
F0021680: d027bfd8                 st      %o0, [%fp+var_28]
F0021684: d0026008                 ld      [%o1+8], %o0
F0021688: d027bfdc                 st      %o0, [%fp+var_24]
F002168C: c027bff0                 clr     [%fp+var_10]
F0021690: c027bff4                 clr     [%fp+var_C]
F0021694: d0024000                 ld      [%o1], %o0
F0021698: d402600c                 ld      [%o1+0xC], %o2
F002169C: 4000002c                 call    _sendit
F00216A0: 9207bfe0                 add     %fp, var_20, %o1
F00216A4: 81c7e008                 ret
F00216A8: 81e80000                 restore
