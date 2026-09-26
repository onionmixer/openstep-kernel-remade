F00E4CF0: 9de3bf58                 save    %sp, -0xA8, %sp
F00E4CF4: f227bfd4                 st      %i1, [%fp+var_2C]
F00E4CF8: f427bfdc                 st      %i2, [%fp+var_24]
F00E4CFC: f627bfe4                 st      %i3, [%fp+var_1C]
F00E4D00: f827bfec                 st      %i4, [%fp+var_14]
F00E4D04: fa27bff4                 st      %i5, [%fp+var_C]
F00E4D08: c02fbfbb                 clrb    [%fp+var_45]
F00E4D0C: 90102040                 mov     0x40, %o0 ! '@'
F00E4D10: d027bfbc                 st      %o0, [%fp+var_44]
F00E4D14: c027bfc0                 clr     [%fp+var_40]
F00E4D18: 901026a4                 mov     0x6A4, %o0
F00E4D1C: d027bfcc                 st      %o0, [%fp+var_34]
F00E4D20: 113c03e7                 sethi   %hi(dword_F00F9C2C), %o0
F00E4D24: d202202c                 ld      [%o0+%lo(dword_F00F9C2C)], %o1
F00E4D28: f027bfc8                 st      %i0, [%fp+var_38]
F00E4D2C: d227bfd0                 st      %o1, [%fp+var_30]
F00E4D30: 133c03e7                 sethi   %hi(dword_F00F9C30), %o1
F00E4D34: d4026030                 ld      [%o1+%lo(dword_F00F9C30)], %o2
F00E4D38: c027bfc4                 clr     [%fp+var_3C]
F00E4D3C: 133c03e7                 sethi   %hi(dword_F00F9C34), %o1
F00E4D40: d2026034                 ld      [%o1+%lo(dword_F00F9C34)], %o1
F00E4D44: d427bfd8                 st      %o2, [%fp+var_28]
F00E4D48: d227bfe0                 st      %o1, [%fp+var_20]
F00E4D4C: 133c03e7                 sethi   %hi(dword_F00F9C38), %o1
F00E4D50: d4026038                 ld      [%o1+%lo(dword_F00F9C38)], %o2
F00E4D54: 9007bfb8                 add     %fp, var_48, %o0
F00E4D58: 133c03e7                 sethi   %hi(dword_F00F9C3C), %o1
F00E4D5C: d427bfe8                 st      %o2, [%fp+var_18]
F00E4D60: d202603c                 ld      [%o1+%lo(dword_F00F9C3C)], %o1
F00E4D64: 941023e8                 mov     0x3E8, %o2
F00E4D68: d227bff0                 st      %o1, [%fp+var_10]
F00E4D6C: 7ffe03da                 call    _msg_send
F00E4D70: 92102021                 mov     0x21, %o1 ! '!'
F00E4D74: 81c7e008                 ret
F00E4D78: 91e80008                 restore %g0, %o0, %o0
