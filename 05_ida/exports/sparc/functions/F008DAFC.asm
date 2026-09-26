F008DAFC: 9de3bf78                 save    %sp, -0x88, %sp
F008DB00: 9007bfe8                 add     %fp, var_18, %o0
F008DB04: d023a040                 st      %o0, [%sp+0x88+var_48]
F008DB08: 113c0504                 sethi   %hi(paRange_0), %o0
F008DB0C: d2022058                 ld      [%o0+%lo(paRange_0)], %o1! SEL
F008DB10: 90100018                 mov     %i0, %o0! id
F008DB14: 40018f57                 call    _objc_msgSend
F008DB18: 01000000                 nop
F008DB1C: 00000008                 illtrap
F008DB20: c027bfe8                 clr     [%fp+var_18]
F008DB24: 113c0506                 sethi   %hi(paKernbusmemoryr), %o0
F008DB28: d0022284                 ld      [%o0+%lo(paKernbusmemoryr)], %o0! id
F008DB2C: c027bfe0                 clr     [%fp+var_20]
F008DB30: d407bfec                 ld      [%fp+var_14], %o2
F008DB34: 133c0503                 sethi   %hi(paAlloc), %o1
F008DB38: d20263f0                 ld      [%o1+%lo(paAlloc)], %o1! SEL
F008DB3C: 40018f4d                 call    _objc_msgSend
F008DB40: d427bfe4                 st      %o2, [%fp+var_1C]
F008DB44: f823a05c                 st      %i4, [%sp+0x88+var_2C]
F008DB48: 133c0504                 sethi   %hi(paInitwithrangeS_1), %o1
F008DB4C: 94100018                 mov     %i0, %o2
F008DB50: 9607bfe0                 add     %fp, var_20, %o3
F008DB54: 9810001a                 mov     %i2, %o4
F008DB58: d2026084                 ld      [%o1+%lo(paInitwithrangeS_1)], %o1! SEL
F008DB5C: 40018f45                 call    _objc_msgSend
F008DB60: 9a10001b                 mov     %i3, %o5
F008DB64: 81c7e008                 ret
F008DB68: 91e80008                 restore %g0, %o0, %o0
