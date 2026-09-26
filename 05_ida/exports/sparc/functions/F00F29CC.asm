F00F29CC: 9de3bf90                 save    %sp, -0x70, %sp
F00F29D0: a6100018                 mov     %i0, %l3
F00F29D4: 113c04bc                 sethi   %hi(dword_F012F124), %o0
F00F29D8: f0022124                 ld      [%o0+%lo(dword_F012F124)], %i0
F00F29DC: 80a62000                 cmp     %i0, 0
F00F29E0: 1280005b                 bne     locret_F00F2B4C
F00F29E4: 01000000                 nop
F00F29E8: d004c000                 ld      [%l3], %o0
F00F29EC: 80a22000                 cmp     %o0, 0
F00F29F0: 0280000c                 be      loc_F00F2A20
F00F29F4: a2102000                 mov     0, %l1
F00F29F8: 133c04bc                 sethi   %hi(dword_F012F128), %o1
F00F29FC: d0026128                 ld      [%o1+%lo(dword_F012F128)], %o0
F00F2A00: 90022001                 inc     %o0
F00F2A04: d0226128                 st      %o0, [%o1+0x128]
F00F2A08: a2046001                 inc     %l1
F00F2A0C: 912c6002                 sll     %l1, 2, %o0
F00F2A10: d004c008                 ld      [%l3+%o0], %o0
F00F2A14: 80a22000                 cmp     %o0, 0
F00F2A18: 12bffffa                 bne     loc_F00F2A00
F00F2A1C: d0026128                 ld      [%o1+0x128], %o0
F00F2A20: 7ffff7a6                 call    __objc_create_zone
F00F2A24: 01000000                 nop
F00F2A28: 7ffff7a4                 call    __objc_create_zone
F00F2A2C: a0100008                 mov     %o0, %l0
F00F2A30: 133c04bc                 sethi   %hi(dword_F012F128), %o1
F00F2A34: d4026128                 ld      [%o1+%lo(dword_F012F128)], %o2
F00F2A38: 932aa001                 sll     %o2, 1, %o1
F00F2A3C: 9202400a                 add     %o1, %o2, %o1
F00F2A40: d4042004                 ld      [%l0+4], %o2
F00F2A44: 9fc28000                 call    %o2
F00F2A48: 932a6003                 sll     %o1, 3, %o1
F00F2A4C: b0920000                 orcc    %o0, %g0, %i0
F00F2A50: 12800006                 bne     loc_F00F2A68
F00F2A54: a2102000                 mov     0, %l1
F00F2A58: 113c03f4                 sethi   %hi(aUnableToAlloca_0), %o0! "unable to allocate module vector"
F00F2A5C: 7ffff7eb                 call    __objc_fatal
F00F2A60: 90122298                 bset    %lo(aUnableToAlloca_0), %o0! "unable to allocate module vector"
F00F2A64: a2102000                 mov     0, %l1
F00F2A68: 113c04bc                 sethi   %hi(dword_F012F128), %o0
F00F2A6C: d0022128                 ld      [%o0+%lo(dword_F012F128)], %o0
F00F2A70: 80a44008                 cmp     %l1, %o0
F00F2A74: 1a80002f                 bcc     loc_F00F2B30
F00F2A78: 113c03f4                 sethi   %hi(aObjc), %o0! "__OBJC"
F00F2A7C: aa1220c8                 or      %o0, %lo(aObjc), %l5! "__OBJC"
F00F2A80: 2d3c03f4                 sethi   -0xFF03000, %l6
F00F2A84: a807bff4                 add     %fp, var_C, %l4
F00F2A88: 932c6001                 sll     %l1, 1, %o1
F00F2A8C: 92024011                 add     %o1, %l1, %o1
F00F2A90: 932a6003                 sll     %o1, 3, %o1
F00F2A94: a12c6002                 sll     %l1, 2, %l0
F00F2A98: d004c010                 ld      [%l3+%l0], %o0
F00F2A9C: d0260009                 st      %o0, [%i0+%o1]
F00F2AA0: a4060009                 add     %i0, %o1, %l2
F00F2AA4: c024a010                 clr     [%l2+0x10]
F00F2AA8: d004c010                 ld      [%l3+%l0], %o0! mhp
F00F2AAC: 92100015                 mov     %l5, %o1! segname
F00F2AB0: 9415a1d8                 or      %l6, 0x1D8, %o2! sectname
F00F2AB4: 7ffddd60                 call    _getsectdatafromheader
F00F2AB8: 96100014                 mov     %l4, %o3! size
F00F2ABC: d024a004                 st      %o0, [%l2+4]
F00F2AC0: d007bff4                 ld      [%fp+var_C], %o0
F00F2AC4: 91322004                 srl     %o0, 4, %o0
F00F2AC8: d024a008                 st      %o0, [%l2+8]
F00F2ACC: 153c03f5                 sethi   %hi(aRuntimeSetup), %o2! "__runtime_setup"
F00F2AD0: d004c010                 ld      [%l3+%l0], %o0! mhp
F00F2AD4: 92100015                 mov     %l5, %o1! segname
F00F2AD8: 9412a000                 bset    %lo(aRuntimeSetup), %o2! "__runtime_setup"
F00F2ADC: 7ffddd56                 call    _getsectdatafromheader
F00F2AE0: 96100014                 mov     %l4, %o3
F00F2AE4: d024a00c                 st      %o0, [%l2+0xC]
F00F2AE8: 7fffff86                 call    sub_F00F2900
F00F2AEC: d004c010                 ld      [%l3+%l0], %o0
F00F2AF0: 80a22000                 cmp     %o0, 0
F00F2AF4: 22800005                 be,a    loc_F00F2B08
F00F2AF8: 912c6001                 sll     %l1, 1, %o0
F00F2AFC: d0022024                 ld      [%o0+0x24], %o0
F00F2B00: 10800006                 ba      loc_F00F2B18
F00F2B04: d024a014                 st      %o0, [%l2+0x14]
F00F2B08: 90020011                 add     %o0, %l1, %o0
F00F2B0C: 912a2003                 sll     %o0, 3, %o0
F00F2B10: 90060008                 add     %i0, %o0, %o0
F00F2B14: c0222014                 clr     [%o0+0x14]
F00F2B18: a2046001                 inc     %l1
F00F2B1C: 113c04bc                 sethi   %hi(dword_F012F128), %o0
F00F2B20: d0022128                 ld      [%o0+%lo(dword_F012F128)], %o0
F00F2B24: 80a44008                 cmp     %l1, %o0
F00F2B28: 0abfffd9                 bcs     loc_F00F2A8C
F00F2B2C: 932c6001                 sll     %l1, 1, %o1
F00F2B30: 133c04bc                 sethi   %hi(dword_F012F128), %o1
F00F2B34: 90100018                 mov     %i0, %o0! __base
F00F2B38: d2026128                 ld      [%o1+%lo(dword_F012F128)], %o1! __nel
F00F2B3C: 94102018                 mov     0x18, %o2! __width
F00F2B40: 173c03ca                 sethi   %hi(sub_F00F2974), %o3! __compar
F00F2B44: 7ffc84a5                 call    _qsort
F00F2B48: 9612e174                 bset    %lo(sub_F00F2974), %o3
F00F2B4C: 81c7e008                 ret
F00F2B50: 81e80000                 restore
