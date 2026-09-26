F00D0D18: 9de3bf90                 save    %sp, -0x70, %sp
F00D0D1C: 9010001b                 mov     %i3, %o0! __s1
F00D0D20: e0070000                 ld      [%i4], %l0
F00D0D24: 133c03ee                 sethi   %hi(aIogetdisplaypo), %o1! "IOGetDisplayPort"
F00D0D28: 7ffcdd21                 call    _strcmp
F00D0D2C: 921262d8                 bset    %lo(aIogetdisplaypo), %o1! "IOGetDisplayPort"
F00D0D30: 80a22000                 cmp     %o0, 0
F00D0D34: 02800008                 be      loc_F00D0D54
F00D0D38: 9010001b                 mov     %i3, %o0! __s1
F00D0D3C: 133c03ee                 sethi   %hi(aIoDisplayGetpo), %o1! "IO_Display_GetPort"
F00D0D40: 7ffcdd1b                 call    _strcmp
F00D0D44: 921262f0                 bset    %lo(aIoDisplayGetpo), %o1! "IO_Display_GetPort"
F00D0D48: 80a22000                 cmp     %o0, 0
F00D0D4C: 32800012                 bne,a   loc_F00D0D94
F00D0D50: f027bff0                 st      %i0, [%fp+var_10]
F00D0D54: 80a42000                 cmp     %l0, 0
F00D0D58: 12800004                 bne     loc_F00D0D68
F00D0D5C: 113c0505                 sethi   -0xFEBEC00, %o0! id
F00D0D60: 10800018                 ba      locret_F00D0DC0
F00D0D64: b0103d3e                 mov     -0x2C2, %i0
F00D0D68: d202235c                 ld      [%o0+0x35C], %o1! SEL
F00D0D6C: 400082c1                 call    _objc_msgSend
F00D0D70: 90100018                 mov     %i0, %o0
F00D0D74: 92102001                 mov     1, %o1
F00D0D78: 7fffe54c                 call    _IOConvertPort
F00D0D7C: 94102002                 mov     2, %o2
F00D0D80: d0268000                 st      %o0, [%i2]
F00D0D84: 90102001                 mov     1, %o0
F00D0D88: d0270000                 st      %o0, [%i4]
F00D0D8C: 1080000d                 ba      locret_F00D0DC0
F00D0D90: b0102000                 mov     0, %i0
F00D0D94: 9007bff0                 add     %fp, var_10, %o0! objc_super *
F00D0D98: 9410001a                 mov     %i2, %o2
F00D0D9C: 133c0508                 sethi   %hi(stru_F014218C.ext), %o1
F00D0DA0: d60261b8                 ld      [%o1+%lo(stru_F014218C.ext)], %o3
F00D0DA4: 9810001c                 mov     %i4, %o4
F00D0DA8: 133c0504                 sethi   %hi(paGetintvaluesFo_0), %o1
F00D0DAC: d627bff4                 st      %o3, [%fp+var_C]
F00D0DB0: d20262c8                 ld      [%o1+%lo(paGetintvaluesFo_0)], %o1! SEL
F00D0DB4: 400082f2                 call    _objc_msgSendSuper
F00D0DB8: 9610001b                 mov     %i3, %o3
F00D0DBC: b0100008                 mov     %o0, %i0
F00D0DC0: 81c7e008                 ret
F00D0DC4: 81e80000                 restore
