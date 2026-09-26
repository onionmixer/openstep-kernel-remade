F00E4D7C: 9de3bf50                 save    %sp, -0xB0, %sp
F00E4D80: f227bfcc                 st      %i1, [%fp+var_34]
F00E4D84: f427bfd4                 st      %i2, [%fp+var_2C]
F00E4D88: f627bfdc                 st      %i3, [%fp+var_24]
F00E4D8C: f827bfe4                 st      %i4, [%fp+var_1C]
F00E4D90: fa27bff4                 st      %i5, [%fp+var_C]
F00E4D94: c02fbfb3                 clrb    [%fp+var_4D]
F00E4D98: 90102048                 mov     0x48, %o0 ! 'H'
F00E4D9C: d027bfb4                 st      %o0, [%fp+var_4C]
F00E4DA0: c027bfb8                 clr     [%fp+var_48]
F00E4DA4: f027bfc0                 st      %i0, [%fp+var_40]
F00E4DA8: c027bfbc                 clr     [%fp+var_44]
F00E4DAC: 133c03e7                 sethi   %hi(dword_F00F9C40), %o1
F00E4DB0: d4026040                 ld      [%o1+%lo(dword_F00F9C40)], %o2
F00E4DB4: 901026a5                 mov     0x6A5, %o0
F00E4DB8: 133c03e7                 sethi   %hi(dword_F00F9C44), %o1
F00E4DBC: d2026044                 ld      [%o1+%lo(dword_F00F9C44)], %o1
F00E4DC0: d427bfc8                 st      %o2, [%fp+var_38]
F00E4DC4: d227bfd0                 st      %o1, [%fp+var_30]
F00E4DC8: 133c03e7                 sethi   %hi(dword_F00F9C48), %o1
F00E4DCC: d4026048                 ld      [%o1+%lo(dword_F00F9C48)], %o2
F00E4DD0: d027bfc4                 st      %o0, [%fp+var_3C]
F00E4DD4: 133c03e7                 sethi   %hi(dword_F00F9C4C), %o1
F00E4DD8: d202604c                 ld      [%o1+%lo(dword_F00F9C4C)], %o1
F00E4DDC: d427bfd8                 st      %o2, [%fp+var_28]
F00E4DE0: d227bfe0                 st      %o1, [%fp+var_20]
F00E4DE4: 133c03e7                 sethi   %hi(dword_F00F9C50), %o1
F00E4DE8: d4026050                 ld      [%o1+%lo(dword_F00F9C50)], %o2
F00E4DEC: 9007bfb0                 add     %fp, var_50, %o0
F00E4DF0: 92126050                 bset    %lo(dword_F00F9C50), %o1
F00E4DF4: d6026004                 ld      [%o1+4], %o3
F00E4DF8: d427bfe8                 st      %o2, [%fp+var_18]
F00E4DFC: d4026008                 ld      [%o1+8], %o2
F00E4E00: d627bfec                 st      %o3, [%fp+var_14]
F00E4E04: d427bff0                 st      %o2, [%fp+var_10]
F00E4E08: d207a05c                 ld      [%fp+arg_5C], %o1
F00E4E0C: 941023e8                 mov     0x3E8, %o2
F00E4E10: d227bff0                 st      %o1, [%fp+var_10]
F00E4E14: 7ffe03b0                 call    _msg_send
F00E4E18: 92102021                 mov     0x21, %o1 ! '!'
F00E4E1C: 81c7e008                 ret
F00E4E20: 91e80008                 restore %g0, %o0, %o0
