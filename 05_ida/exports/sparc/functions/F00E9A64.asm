F00E9A64: 9de3bf78                 save    %sp, -0x88, %sp
F00E9A68: 9010001b                 mov     %i3, %o0! __s1
F00E9A6C: e2070000                 ld      [%i4], %l1
F00E9A70: 133c03f2                 sethi   %hi(aIoFramebufferM), %o1! "IO_Framebuffer_Map"
F00E9A74: 7ffc79ce                 call    _strcmp
F00E9A78: 92126390                 bset    %lo(aIoFramebufferM), %o1! "IO_Framebuffer_Map"
F00E9A7C: 80a22000                 cmp     %o0, 0
F00E9A80: 1280000b                 bne     loc_F00E9AAC
F00E9A84: a010001c                 mov     %i4, %l0
F00E9A88: 113c0504                 sethi   %hi(paEnterlinearmod), %o0! id
F00E9A8C: d20223a8                 ld      [%o0+%lo(paEnterlinearmod)], %o1! SEL
F00E9A90: c0268000                 clr     [%i2]
F00E9A94: 40001f77                 call    _objc_msgSend
F00E9A98: 90100018                 mov     %i0, %o0
F00E9A9C: 90102001                 mov     1, %o0
F00E9AA0: d0270000                 st      %o0, [%i4]
F00E9AA4: 1080007d                 ba      locret_F00E9C98
F00E9AA8: b0102000                 mov     0, %i0
F00E9AAC: 9010001b                 mov     %i3, %o0! __s1
F00E9AB0: 133c03f2                 sethi   %hi(aIoFramebufferD), %o1! "IO_Framebuffer_Dimensions"
F00E9AB4: 7ffc79be                 call    _strcmp
F00E9AB8: 921263a8                 bset    %lo(aIoFramebufferD), %o1! "IO_Framebuffer_Dimensions"
F00E9ABC: 80a22000                 cmp     %o0, 0
F00E9AC0: 32800039                 bne,a   loc_F00E9BA4
F00E9AC4: 9010001b                 mov     %i3, %o0
F00E9AC8: 113c0504                 sethi   %hi(paDisplayinfo), %o0! id
F00E9ACC: d20223ac                 ld      [%o0+%lo(paDisplayinfo)], %o1! SEL
F00E9AD0: 40001f68                 call    _objc_msgSend
F00E9AD4: 90100018                 mov     %i0, %o0
F00E9AD8: d2020000                 ld      [%o0], %o1
F00E9ADC: d227bfd8                 st      %o1, [%fp+var_28]
F00E9AE0: d2022004                 ld      [%o0+4], %o1
F00E9AE4: d227bfdc                 st      %o1, [%fp+var_24]
F00E9AE8: d202200c                 ld      [%o0+0xC], %o1
F00E9AEC: d227bfe0                 st      %o1, [%fp+var_20]
F00E9AF0: d2022060                 ld      [%o0+0x60], %o1
F00E9AF4: d227bfe8                 st      %o1, [%fp+var_18]
F00E9AF8: d2022018                 ld      [%o0+0x18], %o1
F00E9AFC: 80a26004                 cmp     %o1, 4! switch 5 cases
F00E9B00: 18800016                 bgu     def_F00E9B14! jumptable F00E9B14 default case
F00E9B04: 113c03a6                 sethi   %hi(jpt_F00E9B14), %o0
F00E9B08: 9012231c                 bset    %lo(jpt_F00E9B14), %o0
F00E9B0C: 932a6002                 sll     %o1, 2, %o1
F00E9B10: d0024008                 ld      [%o1+%o0], %o0
F00E9B14: 81c20000                 jmp     %o0! switch jump
F00E9B18: 01000000                 nop
F00E9B30: 10800009                 ba      loc_F00E9B54! jumptable F00E9B14 case 0
F00E9B34: 90102002                 mov     2, %o0
F00E9B38: 10800007                 ba      loc_F00E9B54! jumptable F00E9B14 case 1
F00E9B3C: 90102008                 mov     8, %o0
F00E9B40: 10800005                 ba      loc_F00E9B54! jumptable F00E9B14 case 2
F00E9B44: 9010200c                 mov     0xC, %o0
F00E9B48: 10800003                 ba      loc_F00E9B54! jumptable F00E9B14 case 3
F00E9B4C: 9010200f                 mov     0xF, %o0
F00E9B50: 90102020                 mov     0x20, %o0 ! ' '! jumptable F00E9B14 case 4
F00E9B54: d027bfe4                 st      %o0, [%fp+var_1C]
F00E9B58: c0240000                 clr     [%l0]! jumptable F00E9B14 default case
F00E9B5C: 96102000                 mov     0, %o3
F00E9B60: 9407bff8                 add     %fp, var_8, %o2
F00E9B64: 92102000                 mov     0, %o1
F00E9B68: d0040000                 ld      [%l0], %o0
F00E9B6C: 80a20011                 cmp     %o0, %l1
F00E9B70: 02bfffcd                 be      loc_F00E9AA4
F00E9B74: 9602e001                 inc     %o3
F00E9B78: d002bfe0                 ld      [%o2-0x20], %o0
F00E9B7C: 80a2e004                 cmp     %o3, 4
F00E9B80: d022401a                 st      %o0, [%o1+%i2]
F00E9B84: 9402a004                 inc     4, %o2
F00E9B88: d0040000                 ld      [%l0], %o0! __s1
F00E9B8C: 92026004                 inc     4, %o1
F00E9B90: 90022001                 inc     %o0
F00E9B94: 04bffff5                 ble     loc_F00E9B68
F00E9B98: d0240000                 st      %o0, [%l0]
F00E9B9C: 1080003f                 ba      locret_F00E9C98
F00E9BA0: b0102000                 mov     0, %i0
F00E9BA4: 133c03f2                 sethi   %hi(aIoFramebufferR), %o1! "IO_Framebuffer_Register"
F00E9BA8: 7ffc7981                 call    _strcmp
F00E9BAC: 921263c8                 bset    %lo(aIoFramebufferR), %o1! "IO_Framebuffer_Register"
F00E9BB0: 80a22000                 cmp     %o0, 0
F00E9BB4: 32800013                 bne,a   loc_F00E9C00
F00E9BB8: 9010001b                 mov     %i3, %o0
F00E9BBC: 113c0504                 sethi   %hi(paRegisterwithed), %o0! id
F00E9BC0: d20223a4                 ld      [%o0+%lo(paRegisterwithed)], %o1! SEL
F00E9BC4: 40001f2b                 call    _objc_msgSend
F00E9BC8: 90100018                 mov     %i0, %o0
F00E9BCC: c0270000                 clr     [%i4]
F00E9BD0: 80a46000                 cmp     %l1, 0
F00E9BD4: 02800009                 be      loc_F00E9BF8
F00E9BD8: a0100008                 mov     %o0, %l0
F00E9BDC: 90102001                 mov     1, %o0
F00E9BE0: d0270000                 st      %o0, [%i4]
F00E9BE4: 113c0504                 sethi   %hi(paToken_0), %o0! id
F00E9BE8: d20223a0                 ld      [%o0+%lo(paToken_0)], %o1! SEL
F00E9BEC: 40001f21                 call    _objc_msgSend
F00E9BF0: 90100018                 mov     %i0, %o0! __s1
F00E9BF4: d0268000                 st      %o0, [%i2]
F00E9BF8: 10800028                 ba      locret_F00E9C98
F00E9BFC: b0100010                 mov     %l0, %i0
F00E9C00: 133c03f2                 sethi   %hi(aIogetdisplayin), %o1! "IOGetDisplayInfo"
F00E9C04: 7ffc796a                 call    _strcmp
F00E9C08: 921263e0                 bset    %lo(aIogetdisplayin), %o1! "IOGetDisplayInfo"
F00E9C0C: 80a22000                 cmp     %o0, 0
F00E9C10: 32800017                 bne,a   loc_F00E9C6C
F00E9C14: f027bff0                 st      %i0, [%fp+var_10]
F00E9C18: d0070000                 ld      [%i4], %o0
F00E9C1C: 80a22005                 cmp     %o0, 5
F00E9C20: 02800004                 be      loc_F00E9C30
F00E9C24: 113c0504                 sethi   -0xFEBF000, %o0! id
F00E9C28: 1080001c                 ba      locret_F00E9C98
F00E9C2C: b0103d3e                 mov     -0x2C2, %i0
F00E9C30: d20223ac                 ld      [%o0+0x3AC], %o1! SEL
F00E9C34: 40001f0f                 call    _objc_msgSend
F00E9C38: 90100018                 mov     %i0, %o0
F00E9C3C: d2020000                 ld      [%o0], %o1
F00E9C40: d2268000                 st      %o1, [%i2]
F00E9C44: d2022004                 ld      [%o0+4], %o1
F00E9C48: d226a004                 st      %o1, [%i2+4]
F00E9C4C: d2022010                 ld      [%o0+0x10], %o1
F00E9C50: d226a008                 st      %o1, [%i2+8]
F00E9C54: d2022018                 ld      [%o0+0x18], %o1
F00E9C58: d226a00c                 st      %o1, [%i2+0xC]
F00E9C5C: d002201c                 ld      [%o0+0x1C], %o0
F00E9C60: b0102000                 mov     0, %i0
F00E9C64: 1080000d                 ba      locret_F00E9C98
F00E9C68: d026a010                 st      %o0, [%i2+0x10]
F00E9C6C: 9007bff0                 add     %fp, var_10, %o0! objc_super *
F00E9C70: 133c0508                 sethi   %hi(stru_F014236C.super_class), %o1
F00E9C74: 9610001b                 mov     %i3, %o3
F00E9C78: d4026370                 ld      [%o1+%lo(stru_F014236C.super_class)], %o2
F00E9C7C: 9810001c                 mov     %i4, %o4
F00E9C80: 133c0504                 sethi   %hi(paGetintvaluesFo_0), %o1
F00E9C84: d427bff4                 st      %o2, [%fp+var_C]
F00E9C88: d20262c8                 ld      [%o1+%lo(paGetintvaluesFo_0)], %o1! SEL
F00E9C8C: 40001f3c                 call    _objc_msgSendSuper
F00E9C90: 9410001a                 mov     %i2, %o2
F00E9C94: b0100008                 mov     %o0, %i0
F00E9C98: 81c7e008                 ret
F00E9C9C: 81e80000                 restore
