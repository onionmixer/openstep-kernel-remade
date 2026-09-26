F0050874: 9de3bf50                 save    %sp, -0xB0, %sp
F0050878: ae100018                 mov     %i0, %l7
F005087C: b8100019                 mov     %i1, %i4
F0050880: a8102000                 mov     0, %l4
F0050884: 213c043c                 sethi   %hi(dword_F010F0BC), %l0
F0050888: d00420bc                 ld      [%l0+%lo(dword_F010F0BC)], %o0
F005088C: 80a22000                 cmp     %o0, 0
F0050890: 12800006                 bne     loc_F00508A8
F0050894: b2102000                 mov     0, %i1
F0050898: 7ffff4f4                 call    _ihinit
F005089C: 01000000                 nop
F00508A0: 90102001                 mov     1, %o0
F00508A4: d02420bc                 st      %o0, [%l0+%lo(dword_F010F0BC)]
F00508A8: d005c000                 ld      [%l7], %o0
F00508AC: d206a00c                 ld      [%i2+0xC], %o1
F00508B0: 98102003                 mov     3, %o4
F00508B4: 808a6001                 btst    1, %o1
F00508B8: 02800003                 be      loc_F00508C4
F00508BC: d602201c                 ld      [%o0+0x1C], %o3
F00508C0: 98102001                 mov     1, %o4
F00508C4: 213c04cf                 sethi   %hi(_active_u), %l0
F00508C8: d00421d8                 ld      [%l0+%lo(_active_u)], %o0
F00508CC: d402201c                 ld      [%o0+0x1C], %o2
F00508D0: 9210000c                 mov     %o4, %o1
F00508D4: d602c000                 ld      [%o3], %o3
F00508D8: 9fc2c000                 call    %o3
F00508DC: 90100017                 mov     %l7, %o0
F00508E0: b0920000                 orcc    %o0, %g0, %i0
F00508E4: 1280015d                 bne     locret_F0050E58
F00508E8: 01000000                 nop
F00508EC: d005c000                 ld      [%l7], %o0
F00508F0: d202201c                 ld      [%o0+0x1C], %o1
F00508F4: d2026080                 ld      [%o1+0x80], %o1
F00508F8: 9fc24000                 call    %o1
F00508FC: b6102001                 mov     1, %i3
F0050900: 92920000                 orcc    %o0, %g0, %o1
F0050904: 12800013                 bne     loc_F0050950
F0050908: 98102003                 mov     3, %o4
F005090C: d405c000                 ld      [%l7], %o2
F0050910: d006a00c                 ld      [%i2+0xC], %o0
F0050914: 808a2001                 btst    1, %o0
F0050918: 02800003                 be      loc_F0050924
F005091C: da02a01c                 ld      [%o2+0x1C], %o5
F0050920: 98102001                 mov     1, %o4
F0050924: d20421d8                 ld      [%l0+0x1D8], %o1
F0050928: d602601c                 ld      [%o1+0x1C], %o3
F005092C: 9010000a                 mov     %o2, %o0
F0050930: 9210000c                 mov     %o4, %o1
F0050934: d8036004                 ld      [%o5+4], %o4
F0050938: 9fc30000                 call    %o4
F005093C: 94102001                 mov     1, %o2
F0050940: 7fff5324                 call    _binval
F0050944: d005c000                 ld      [%l7], %o0
F0050948: 10800144                 ba      locret_F0050E58
F005094C: b010200f                 mov     0xF, %i0
F0050950: 7ffed72c                 call    _udiv
F0050954: 11000008                 sethi   0x2000, %o0
F0050958: 92100008                 mov     %o0, %o1
F005095C: d005c000                 ld      [%l7], %o0
F0050960: 7fff4ef0                 call    _bread
F0050964: 15000008                 sethi   0x2000, %o2
F0050968: ac100008                 mov     %o0, %l6
F005096C: d0058000                 ld      [%l6], %o0
F0050970: 808a2004                 btst    4, %o0
F0050974: 12800117                 bne     loc_F0050DD0
F0050978: 80a62000                 cmp     %i0, 0
F005097C: 113c043c                 sethi   %hi(_mounttab), %o0
F0050980: e80220ac                 ld      [%o0+%lo(_mounttab)], %l4
F0050984: 80a52000                 cmp     %l4, 0
F0050988: 22800018                 be,a    loc_F00509E8
F005098C: d005c000                 ld      [%l7], %o0
F0050990: d405200c                 ld      [%l4+0xC], %o2
F0050994: 80a2a000                 cmp     %o2, 0
F0050998: 22800010                 be,a    loc_F00509D8
F005099C: e8052020                 ld      [%l4+0x20], %l4
F00509A0: d005c000                 ld      [%l7], %o0
F00509A4: d252202c                 ldsh    [%o0+0x2C], %o1! size_t
F00509A8: d0552004                 ldsh    [%l4+4], %o0
F00509AC: 80a24008                 cmp     %o1, %o0
F00509B0: 3280000a                 bne,a   loc_F00509D8
F00509B4: e8052020                 ld      [%l4+0x20], %l4
F00509B8: d006a00c                 ld      [%i2+0xC], %o0
F00509BC: 808a2040                 btst    0x40, %o0 ! '@'
F00509C0: 3280004f                 bne,a   loc_F0050AFC
F00509C4: b210000a                 mov     %o2, %i1
F00509C8: a8102000                 mov     0, %l4
F00509CC: b0102010                 mov     0x10, %i0
F00509D0: 108000ff                 ba      loc_F0050DCC
F00509D4: b6102000                 mov     0, %i3
F00509D8: 80a52000                 cmp     %l4, 0
F00509DC: 32bfffee                 bne,a   loc_F0050994
F00509E0: d405200c                 ld      [%l4+0xC], %o2! size_t
F00509E4: d005c000                 ld      [%l7], %o0
F00509E8: 40010c29                 call    _vol_notify_cancel
F00509EC: d052202c                 ldsh    [%o0+0x2C], %o0
F00509F0: d006a00c                 ld      [%i2+0xC], %o0
F00509F4: 808a2040                 btst    0x40, %o0 ! '@'
F00509F8: 02800006                 be      loc_F0050A10
F00509FC: 900a3fbf                 and     %o0, -0x41, %o0
F0050A00: d026a00c                 st      %o0, [%i2+0xC]
F0050A04: 113c043c                 sethi   %hi(aMountfsIllegal), %o0! "mountfs: illegal remount request\n"
F0050A08: 10800063                 ba      loc_F0050B94
F0050A0C: 901220c0                 bset    %lo(aMountfsIllegal), %o0! "mountfs: illegal remount request\n"
F0050A10: 113c043c                 sethi   %hi(_mounttab), %o0
F0050A14: e80220ac                 ld      [%o0+%lo(_mounttab)], %l4
F0050A18: 80a52000                 cmp     %l4, 0
F0050A1C: 0280000a                 be      loc_F0050A44
F0050A20: 01000000                 nop
F0050A24: d005200c                 ld      [%l4+0xC], %o0
F0050A28: 80a22000                 cmp     %o0, 0
F0050A2C: 22800014                 be,a    loc_F0050A7C
F0050A30: e826a128                 st      %l4, [%i2+0x128]
F0050A34: e8052020                 ld      [%l4+0x20], %l4
F0050A38: 80a52000                 cmp     %l4, 0
F0050A3C: 32bffffb                 bne,a   loc_F0050A28
F0050A40: d005200c                 ld      [%l4+0xC], %o0
F0050A44: 40005d8b                 call    _kalloc
F0050A48: 90102024                 mov     0x24, %o0! void *
F0050A4C: a8100008                 mov     %o0, %l4
F0050A50: 40011102                 call    _bzero
F0050A54: 92102024                 mov     0x24, %o1 ! '$'
F0050A58: 80a52000                 cmp     %l4, 0
F0050A5C: 12800004                 bne     loc_F0050A6C
F0050A60: 133c043c                 sethi   -0xFEF1000, %o1
F0050A64: 108000da                 ba      loc_F0050DCC
F0050A68: b0102018                 mov     0x18, %i0
F0050A6C: d00260ac                 ld      [%o1+0xAC], %o0
F0050A70: d0252020                 st      %o0, [%l4+0x20]
F0050A74: e82260ac                 st      %l4, [%o1+0xAC]
F0050A78: e826a128                 st      %l4, [%i2+0x128]
F0050A7C: f4250000                 st      %i2, [%l4]
F0050A80: ec25200c                 st      %l6, [%l4+0xC]
F0050A84: 90103fff                 mov     -1, %o0
F0050A88: d0352004                 sth     %o0, [%l4+4]
F0050A8C: d005c000                 ld      [%l7], %o0
F0050A90: d0252008                 st      %o0, [%l4+8]
F0050A94: e205a020                 ld      [%l6+0x20], %l1
F0050A98: 11000046                 sethi   0x11800, %o0
F0050A9C: d204655c                 ld      [%l1+0x55C], %o1
F0050AA0: 90122154                 bset    0x154, %o0
F0050AA4: 80a24008                 cmp     %o1, %o0
F0050AA8: 328000c9                 bne,a   loc_F0050DCC
F0050AAC: b0102016                 mov     0x16, %i0
F0050AB0: d2046030                 ld      [%l1+0x30], %o1
F0050AB4: 11000008                 sethi   0x2000, %o0
F0050AB8: 80a24008                 cmp     %o1, %o0
F0050ABC: 348000c4                 bg,a    loc_F0050DCC
F0050AC0: b0102016                 mov     0x16, %i0
F0050AC4: 80a26563                 cmp     %o1, 0x563
F0050AC8: 18800004                 bgu     loc_F0050AD8
F0050ACC: 01000000                 nop
F0050AD0: 108000bf                 ba      loc_F0050DCC
F0050AD4: b0102016                 mov     0x16, %i0
F0050AD8: 7fff505c                 call    _geteblk
F0050ADC: d0046068                 ld      [%l1+0x68], %o0
F0050AE0: b2100008                 mov     %o0, %i1
F0050AE4: f225200c                 st      %i1, [%l4+0xC]
F0050AE8: d005a020                 ld      [%l6+0x20], %o0! void *
F0050AEC: d2066020                 ld      [%i1+0x20], %o1! void *
F0050AF0: 40011008                 call    _bcopy
F0050AF4: d4046068                 ld      [%l1+0x68], %o2
F0050AF8: d006a00c                 ld      [%i2+0xC], %o0
F0050AFC: 808a2001                 btst    1, %o0
F0050B00: 12800019                 bne     loc_F0050B64
F0050B04: 213c04cf                 sethi   %hi(dword_F0133DDC), %l0
F0050B08: d20421dc                 ld      [%l0+%lo(dword_F0133DDC)], %o1
F0050B0C: 90100016                 mov     %l6, %o0
F0050B10: 7fff4f16                 call    _bwrite
F0050B14: c02a6038                 clrb    [%o1+0x38]
F0050B18: d20421dc                 ld      [%l0+%lo(dword_F0133DDC)], %o1
F0050B1C: d04a6038                 ldsb    [%o1+0x38], %o0
F0050B20: 80a2201e                 cmp     %o0, 0x1E
F0050B24: 32800013                 bne,a   loc_F0050B70
F0050B28: d006a00c                 ld      [%i2+0xC], %o0
F0050B2C: c02a6038                 clrb    [%o1+0x38]
F0050B30: d005c000                 ld      [%l7], %o0
F0050B34: 133c04d4                 sethi   %hi(_rootvp), %o1
F0050B38: d20263a0                 ld      [%o1+%lo(_rootvp)], %o1
F0050B3C: 80a20009                 cmp     %o0, %o1
F0050B40: 32800006                 bne,a   loc_F0050B58
F0050B44: d006a00c                 ld      [%i2+0xC], %o0
F0050B48: 113c043c                 sethi   %hi(aRootDeviceIsPh), %o0! "Root device is physically write protect"...
F0050B4C: 7fff1189                 call    _panic
F0050B50: 901220e8                 bset    %lo(aRootDeviceIsPh), %o0! "Root device is physically write protect"...
F0050B54: d006a00c                 ld      [%i2+0xC], %o0
F0050B58: 90122001                 bset    1, %o0
F0050B5C: 10800004                 ba      loc_F0050B6C
F0050B60: d026a00c                 st      %o0, [%i2+0xC]
F0050B64: 7fff4f41                 call    _brelse
F0050B68: 90100016                 mov     %l6, %o0
F0050B6C: d006a00c                 ld      [%i2+0xC], %o0
F0050B70: ac102000                 mov     0, %l6
F0050B74: 808a2001                 btst    1, %o0
F0050B78: 0280000e                 be      loc_F0050BB0
F0050B7C: e2066020                 ld      [%i1+0x20], %l1
F0050B80: 808a2040                 btst    0x40, %o0 ! '@'
F0050B84: 22800008                 be,a    loc_F0050BA4
F0050B88: c02c60d0                 clrb    [%l1+0xD0]
F0050B8C: 113c043c90122130         set     aMountfsCanTRem, %o0! "mountfs: can't remount ro\n"
F0050B94: 7fff0eb1                 call    _printf
F0050B98: 01000000                 nop
F0050B9C: 1080008c                 ba      loc_F0050DCC
F0050BA0: b0102016                 mov     0x16, %i0
F0050BA4: 90102001                 mov     1, %o0
F0050BA8: 1080001a                 ba      loc_F0050C10
F0050BAC: d02c60d2                 stb     %o0, [%l1+0xD2]
F0050BB0: d04c60d1                 ldsb    [%l1+0xD1], %o0
F0050BB4: 80a22001                 cmp     %o0, 1
F0050BB8: 12800003                 bne     loc_F0050BC4
F0050BBC: 90102003                 mov     3, %o0
F0050BC0: 90102002                 mov     2, %o0
F0050BC4: d02c60d1                 stb     %o0, [%l1+0xD1]
F0050BC8: 90102001                 mov     1, %o0
F0050BCC: d02c60d0                 stb     %o0, [%l1+0xD0]
F0050BD0: c02c60d2                 clrb    [%l1+0xD2]
F0050BD4: d006a00c                 ld      [%i2+0xC], %o0
F0050BD8: 808a2040                 btst    0x40, %o0 ! '@'
F0050BDC: 0280000d                 be      loc_F0050C10
F0050BE0: 80a5a000                 cmp     %l6, 0
F0050BE4: 22800005                 be,a    loc_F0050BF8
F0050BE8: d206a00c                 ld      [%i2+0xC], %o1
F0050BEC: 7fff4f1f                 call    _brelse
F0050BF0: 90100016                 mov     %l6, %o0
F0050BF4: d206a00c                 ld      [%i2+0xC], %o1
F0050BF8: 90100014                 mov     %l4, %o0
F0050BFC: 920a7fbf                 and     %o1, -0x41, %o1
F0050C00: 4000013f                 call    _sbupdate
F0050C04: d226a00c                 st      %o1, [%i2+0xC]
F0050C08: 10800094                 ba      locret_F0050E58
F0050C0C: b0102000                 mov     0, %i0
F0050C10: d0046030                 ld      [%l1+0x30], %o0
F0050C14: d026a010                 st      %o0, [%i2+0x10]
F0050C18: e004609c                 ld      [%l1+0x9C], %l0
F0050C1C: d2046034                 ld      [%l1+0x34], %o1! int
F0050C20: 90043fff                 add     %l0, -1, %o0! int
F0050C24: 7ffed679                 call    _div
F0050C28: 90020009                 add     %o0, %o1, %o0
F0050C2C: aa100008                 mov     %o0, %l5
F0050C30: 40005d10                 call    _kalloc
F0050C34: 90100010                 mov     %l0, %o0
F0050C38: a6920000                 orcc    %o0, %g0, %l3
F0050C3C: 12800004                 bne     loc_F0050C4C
F0050C40: a0102000                 mov     0, %l0
F0050C44: 10800062                 ba      loc_F0050DCC
F0050C48: b010200c                 mov     0xC, %i0
F0050C4C: 80a40015                 cmp     %l0, %l5
F0050C50: 36800027                 bge,a   loc_F0050CEC
F0050C54: d04c60d2                 ldsb    [%l1+0xD2], %o0
F0050C58: d0046038                 ld      [%l1+0x38], %o0
F0050C5C: 90040008                 add     %l0, %o0, %o0
F0050C60: 80a20015                 cmp     %o0, %l5
F0050C64: 04800006                 ble     loc_F0050C7C
F0050C68: e4046030                 ld      [%l1+0x30], %l2
F0050C6C: d2046034                 ld      [%l1+0x34], %o1
F0050C70: 7ffed624                 call    _umul
F0050C74: 90254010                 sub     %l5, %l0, %o0
F0050C78: a4100008                 mov     %o0, %l2
F0050C7C: d0052008                 ld      [%l4+8], %o0
F0050C80: d2046098                 ld      [%l1+0x98], %o1
F0050C84: 94100012                 mov     %l2, %o2! size_t
F0050C88: d6046064                 ld      [%l1+0x64], %o3
F0050C8C: 92024010                 add     %o1, %l0, %o1
F0050C90: 7fff4e24                 call    _bread
F0050C94: 932a400b                 sll     %o1, %o3, %o1
F0050C98: ac100008                 mov     %o0, %l6
F0050C9C: d0058000                 ld      [%l6], %o0
F0050CA0: 808a2004                 btst    4, %o0
F0050CA4: 12800047                 bne     loc_F0050DC0
F0050CA8: 92100013                 mov     %l3, %o1! void *
F0050CAC: d005a020                 ld      [%l6+0x20], %o0! void *
F0050CB0: 40010f98                 call    _bcopy
F0050CB4: 94100012                 mov     %l2, %o2
F0050CB8: d2046060                 ld      [%l1+0x60], %o1
F0050CBC: 90100016                 mov     %l6, %o0
F0050CC0: 933c0009                 sra     %l0, %o1, %o1
F0050CC4: 932a6002                 sll     %o1, 2, %o1
F0050CC8: 92024011                 add     %o1, %l1, %o1
F0050CCC: 7fff4ee7                 call    _brelse
F0050CD0: e62262d8                 st      %l3, [%o1+0x2D8]
F0050CD4: d0046038                 ld      [%l1+0x38], %o0
F0050CD8: a0040008                 add     %l0, %o0, %l0
F0050CDC: 80a40015                 cmp     %l0, %l5
F0050CE0: 06bfffdf                 bl      loc_F0050C5C
F0050CE4: a604c012                 add     %l3, %l2, %l3
F0050CE8: d04c60d2                 ldsb    [%l1+0xD2], %o0
F0050CEC: 80a22000                 cmp     %o0, 0
F0050CF0: 32800005                 bne,a   loc_F0050D04
F0050CF4: d40c60d3                 ldub    [%l1+0xD3], %o2
F0050CF8: 40000101                 call    _sbupdate
F0050CFC: 90100014                 mov     %l4, %o0
F0050D00: d40c60d3                 ldub    [%l1+0xD3], %o2
F0050D04: d204603c                 ld      [%l1+0x3C], %o1! int
F0050D08: d0046028                 ld      [%l1+0x28], %o0! int
F0050D0C: 940abffc                 and     %o2, -4, %o2
F0050D10: 7ffed5fc                 call    _umul
F0050D14: d42c60d3                 stb     %o2, [%l1+0xD3]
F0050D18: 7ffed63c                 call    _div
F0050D1C: 92102064                 mov     0x64, %o1 ! 'd'
F0050D20: d024608c                 st      %o0, [%l1+0x8C]
F0050D24: 80a22064                 cmp     %o0, 0x64 ! 'd'
F0050D28: 04800004                 ble     loc_F0050D38
F0050D2C: d0246088                 st      %o0, [%l1+0x88]
F0050D30: 10800003                 ba      loc_F0050D3C
F0050D34: 90022064                 inc     0x64, %o0 ! 'd'
F0050D38: 912a2001                 sll     %o0, 1, %o0
F0050D3C: d0246088                 st      %o0, [%l1+0x88]
F0050D40: d004602c                 ld      [%l1+0x2C], %o0! int
F0050D44: 7ffed5ef                 call    _umul
F0050D48: d20460b8                 ld      [%l1+0xB8], %o1! int
F0050D4C: 7ffed62f                 call    _div
F0050D50: 92102064                 mov     0x64, %o1 ! 'd'
F0050D54: 80a22032                 cmp     %o0, 0x32 ! '2'
F0050D58: 04800004                 ble     loc_F0050D68
F0050D5C: d0246094                 st      %o0, [%l1+0x94]
F0050D60: 90102032                 mov     0x32, %o0 ! '2'
F0050D64: d0246094                 st      %o0, [%l1+0x94]
F0050D68: d4046094                 ld      [%l1+0x94], %o2
F0050D6C: 9010001c                 mov     %i4, %o0
F0050D70: d4246090                 st      %o2, [%l1+0x90]
F0050D74: d6052008                 ld      [%l4+8], %o3
F0050D78: 920460d4                 add     %l1, 0xD4, %o1
F0050D7C: d812e02c                 lduh    [%o3+0x2C], %o4
F0050D80: 941021ff                 mov     0x1FF, %o2
F0050D84: 9607bfb4                 add     %fp, var_4C, %o3
F0050D88: d8352004                 sth     %o4, [%l4+4]
F0050D8C: 992b2010                 sll     %o4, 16, %o4
F0050D90: 993b2010                 sra     %o4, 16, %o4
F0050D94: d826a014                 st      %o4, [%i2+0x14]
F0050D98: 40011c4b                 call    _copystr
F0050D9C: c026a018                 clr     [%i2+0x18]
F0050DA0: d407bfb4                 ld      [%fp+var_4C], %o2
F0050DA4: 92102200                 mov     0x200, %o1! size_t
F0050DA8: 9002a0d4                 add     %o2, 0xD4, %o0
F0050DAC: 90044008                 add     %l1, %o0, %o0! void *
F0050DB0: 4001102a                 call    _bzero
F0050DB4: 9222400a                 sub     %o1, %o2, %o1
F0050DB8: 10800028                 ba      locret_F0050E58
F0050DBC: b0102000                 mov     0, %i0
F0050DC0: d204609c                 ld      [%l1+0x9C], %o1
F0050DC4: 40005cf7                 call    _kfree
F0050DC8: 90100013                 mov     %l3, %o0
F0050DCC: 80a62000                 cmp     %i0, 0
F0050DD0: 22800002                 be,a    loc_F0050DD8
F0050DD4: b0102005                 mov     5, %i0
F0050DD8: 80a52000                 cmp     %l4, 0
F0050DDC: 32800002                 bne,a   loc_F0050DE4
F0050DE0: c025200c                 clr     [%l4+0xC]
F0050DE4: 80a66000                 cmp     %i1, 0
F0050DE8: 02800005                 be      loc_F0050DFC
F0050DEC: 80a5a000                 cmp     %l6, 0
F0050DF0: 7fff4e9e                 call    _brelse
F0050DF4: 90100019                 mov     %i1, %o0
F0050DF8: 80a5a000                 cmp     %l6, 0
F0050DFC: 02800005                 be      loc_F0050E10
F0050E00: 80a6e000                 cmp     %i3, 0
F0050E04: 7fff4e99                 call    _brelse
F0050E08: 90100016                 mov     %l6, %o0
F0050E0C: 80a6e000                 cmp     %i3, 0
F0050E10: 02800012                 be      locret_F0050E58
F0050E14: 98102003                 mov     3, %o4
F0050E18: d405c000                 ld      [%l7], %o2
F0050E1C: d006a00c                 ld      [%i2+0xC], %o0
F0050E20: 808a2001                 btst    1, %o0
F0050E24: 02800003                 be      loc_F0050E30
F0050E28: da02a01c                 ld      [%o2+0x1C], %o5
F0050E2C: 98102001                 mov     1, %o4
F0050E30: 113c04cf                 sethi   %hi(_active_u), %o0
F0050E34: d20221d8                 ld      [%o0+%lo(_active_u)], %o1
F0050E38: d602601c                 ld      [%o1+0x1C], %o3
F0050E3C: 9010000a                 mov     %o2, %o0
F0050E40: 9210000c                 mov     %o4, %o1
F0050E44: d8036004                 ld      [%o5+4], %o4
F0050E48: 9fc30000                 call    %o4
F0050E4C: 94102001                 mov     1, %o2
F0050E50: 7fff51e0                 call    _binval
F0050E54: d005c000                 ld      [%l7], %o0
F0050E58: 81c7e008                 ret
F0050E5C: 81e80000                 restore
