F008DB6C: 9de3bf80                 save    %sp, -0x80, %sp
F008DB70: 9007bfe8                 add     %fp, var_18, %o0
F008DB74: d023a040                 st      %o0, [%sp+0x80+var_40]
F008DB78: 113c0504                 sethi   %hi(paRange_0), %o0
F008DB7C: d2022058                 ld      [%o0+%lo(paRange_0)], %o1! SEL
F008DB80: 90100018                 mov     %i0, %o0! id
F008DB84: 40018f3b                 call    _objc_msgSend
F008DB88: 01000000                 nop
F008DB8C: 00000008                 illtrap
F008DB90: c027bfe8                 clr     [%fp+var_18]
F008DB94: 113c0506                 sethi   %hi(paKernbusmemoryr), %o0
F008DB98: d0022284                 ld      [%o0+%lo(paKernbusmemoryr)], %o0! id
F008DB9C: c027bfe0                 clr     [%fp+var_20]
F008DBA0: d407bfec                 ld      [%fp+var_14], %o2
F008DBA4: 133c0503                 sethi   %hi(paAlloc), %o1
F008DBA8: d20263f0                 ld      [%o1+%lo(paAlloc)], %o1! SEL
F008DBAC: 40018f31                 call    _objc_msgSend
F008DBB0: d427bfe4                 st      %o2, [%fp+var_1C]
F008DBB4: 133c0504                 sethi   %hi(paInitwithrangeS_0), %o1
F008DBB8: 94100018                 mov     %i0, %o2
F008DBBC: 9607bfe0                 add     %fp, var_20, %o3
F008DBC0: 9810001a                 mov     %i2, %o4
F008DBC4: d2026088                 ld      [%o1+%lo(paInitwithrangeS_0)], %o1! SEL
F008DBC8: 40018f2a                 call    _objc_msgSend
F008DBCC: 9a10001b                 mov     %i3, %o5
F008DBD0: 81c7e008                 ret
F008DBD4: 91e80008                 restore %g0, %o0, %o0
