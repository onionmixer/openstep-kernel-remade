F0047398: 9de3bf58                 save    %sp, -0xA8, %sp
F004739C: a0100018                 mov     %i0, %l0
F00473A0: 912e6010                 sll     %i1, 16, %o0
F00473A4: 913a2010                 sra     %o0, 16, %o0
F00473A8: 92100010                 mov     %l0, %o1! size_t
F00473AC: 40000146                 call    sub_F00478C4
F00473B0: 9410001a                 mov     %i2, %o2
F00473B4: b0920000                 orcc    %o0, %g0, %i0
F00473B8: 32800050                 bne,a   loc_F00474F8
F00473BC: 90100018                 mov     %i0, %o0
F00473C0: 80a42000                 cmp     %l0, 0
F00473C4: 0280000a                 be      loc_F00473EC
F00473C8: 01000000                 nop
F00473CC: d0042028                 ld      [%l0+0x28], %o0
F00473D0: 80a22008                 cmp     %o0, 8
F00473D4: 12800006                 bne     loc_F00473EC
F00473D8: 01000000                 nop
F00473DC: 7fffff7f                 call    _fifosp
F00473E0: 90100010                 mov     %l0, %o0
F00473E4: 10800023                 ba      loc_F0047470
F00473E8: b0100008                 mov     %o0, %i0
F00473EC: 40008321                 call    _kalloc
F00473F0: 90102068                 mov     0x68, %o0! void *
F00473F4: b0100008                 mov     %o0, %i0
F00473F8: 40013698                 call    _bzero
F00473FC: 92102068                 mov     0x68, %o1 ! 'h'
F0047400: 113c0438901223c8         set     _spec_vnodeops, %o0
F0047408: 80a42000                 cmp     %l0, 0
F004740C: 02800019                 be      loc_F0047470
F0047410: d0262020                 st      %o0, [%i0+0x20]
F0047414: 113c04cf                 sethi   %hi(_active_u), %o0
F0047418: d00221d8                 ld      [%o0+%lo(_active_u)], %o0
F004741C: d204201c                 ld      [%l0+0x1C], %o1
F0047420: d402201c                 ld      [%o0+0x1C], %o2
F0047424: d6026014                 ld      [%o1+0x14], %o3
F0047428: 90100010                 mov     %l0, %o0
F004742C: 9fc2c000                 call    %o3
F0047430: 9207bfb8                 add     %fp, var_48, %o1
F0047434: 80a22000                 cmp     %o0, 0
F0047438: 3280000f                 bne,a   loc_F0047474
F004743C: e0262038                 st      %l0, [%i0+0x38]
F0047440: d007bfd8                 ld      [%fp+var_28], %o0
F0047444: d026204c                 st      %o0, [%i0+0x4C]
F0047448: d007bfdc                 ld      [%fp+var_24], %o0
F004744C: d0262050                 st      %o0, [%i0+0x50]
F0047450: d007bfe0                 ld      [%fp+var_20], %o0
F0047454: d0262054                 st      %o0, [%i0+0x54]
F0047458: d007bfe4                 ld      [%fp+var_1C], %o0
F004745C: d0262058                 st      %o0, [%i0+0x58]
F0047460: d007bfe8                 ld      [%fp+var_18], %o0
F0047464: d026205c                 st      %o0, [%i0+0x5C]
F0047468: d007bfec                 ld      [%fp+var_14], %o0
F004746C: d0262060                 st      %o0, [%i0+0x60]
F0047470: e0262038                 st      %l0, [%i0+0x38]
F0047474: f2362042                 sth     %i1, [%i0+0x42]
F0047478: f2362030                 sth     %i1, [%i0+0x30]
F004747C: 90102001                 mov     1, %o0
F0047480: d036200a                 sth     %o0, [%i0+0xA]
F0047484: 80a42000                 cmp     %l0, 0
F0047488: 02800014                 be      loc_F00474D8
F004748C: f0262034                 st      %i0, [%i0+0x34]
F0047490: d0142006                 lduh    [%l0+6], %o0
F0047494: d2042028                 ld      [%l0+0x28], %o1
F0047498: 90022001                 inc     %o0
F004749C: d0342006                 sth     %o0, [%l0+6]
F00474A0: d226202c                 st      %o1, [%i0+0x2C]
F00474A4: d0042024                 ld      [%l0+0x24], %o0
F00474A8: d0262028                 st      %o0, [%i0+0x28]
F00474AC: d0042028                 ld      [%l0+0x28], %o0
F00474B0: 80a22003                 cmp     %o0, 3
F00474B4: 1280000e                 bne     loc_F00474EC
F00474B8: 912e6010                 sll     %i1, 16, %o0
F00474BC: 7fffff8a                 call    _bdevvp
F00474C0: 913a2010                 sra     %o0, 16, %o0
F00474C4: d026203c                 st      %o0, [%i0+0x3C]
F00474C8: d0022030                 ld      [%o0+0x30], %o0
F00474CC: d0022048                 ld      [%o0+0x48], %o0
F00474D0: 10800007                 ba      loc_F00474EC
F00474D4: d0262048                 st      %o0, [%i0+0x48]
F00474D8: 90102003                 mov     3, %o0
F00474DC: d026202c                 st      %o0, [%i0+0x2C]
F00474E0: c0262028                 clr     [%i0+0x28]
F00474E4: 90062004                 add     %i0, 4, %o0
F00474E8: d026203c                 st      %o0, [%i0+0x3C]
F00474EC: 40000036                 call    sub_F00475C4
F00474F0: 90100018                 mov     %i0, %o0
F00474F4: 90100018                 mov     %i0, %o0
F00474F8: 932e6010                 sll     %i1, 16, %o1
F00474FC: 7fffff82                 call    _set_blocksize
F0047500: 933a6010                 sra     %o1, 16, %o1
F0047504: 81c7e008                 ret
F0047508: 91ee2004                 restore %i0, 4, %o0
