F00E9F14: 9de3bf90                 save    %sp, -0x70, %sp
F00E9F18: 9010001b                 mov     %i3, %o0! __s1
F00E9F1C: 133c03f3                 sethi   %hi(aIoFramebufferP), %o1! "IO_Framebuffer_Pixel_Encoding"
F00E9F20: 7ffc78a3                 call    _strcmp
F00E9F24: 921260a0                 bset    %lo(aIoFramebufferP), %o1! "IO_Framebuffer_Pixel_Encoding"
F00E9F28: 80a22000                 cmp     %o0, 0
F00E9F2C: 32800011                 bne,a   loc_F00E9F70
F00E9F30: f027bff0                 st      %i0, [%fp+var_10]
F00E9F34: d0070000                 ld      [%i4], %o0
F00E9F38: 80a22040                 cmp     %o0, 0x40 ! '@'
F00E9F3C: 02800004                 be      loc_F00E9F4C
F00E9F40: 113c0504                 sethi   -0xFEBF000, %o0! id
F00E9F44: 10800016                 ba      locret_F00E9F9C
F00E9F48: b0103d3e                 mov     -0x2C2, %i0
F00E9F4C: d20223ac                 ld      [%o0+0x3AC], %o1! SEL
F00E9F50: 40001e48                 call    _objc_msgSend
F00E9F54: 90100018                 mov     %i0, %o0
F00E9F58: 92022020                 add     %o0, 0x20, %o1 ! ' '! __src
F00E9F5C: 9010001a                 mov     %i2, %o0! __dst
F00E9F60: 7ffc766f                 call    _strncpy
F00E9F64: 94102040                 mov     0x40, %o2 ! '@'
F00E9F68: 1080000d                 ba      locret_F00E9F9C
F00E9F6C: b0102000                 mov     0, %i0
F00E9F70: 9007bff0                 add     %fp, var_10, %o0! objc_super *
F00E9F74: 9410001a                 mov     %i2, %o2
F00E9F78: 133c0508                 sethi   %hi(stru_F014236C.super_class), %o1
F00E9F7C: d6026370                 ld      [%o1+%lo(stru_F014236C.super_class)], %o3
F00E9F80: 9810001c                 mov     %i4, %o4
F00E9F84: 133c0504                 sethi   %hi(paGetcharvaluesF_0), %o1
F00E9F88: d627bff4                 st      %o3, [%fp+var_C]
F00E9F8C: d20262d0                 ld      [%o1+%lo(paGetcharvaluesF_0)], %o1! SEL
F00E9F90: 40001e7b                 call    _objc_msgSendSuper
F00E9F94: 9610001b                 mov     %i3, %o3
F00E9F98: b0100008                 mov     %o0, %i0
F00E9F9C: 81c7e008                 ret
F00E9FA0: 81e80000                 restore
