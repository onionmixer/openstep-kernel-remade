F0030434: 9de3bf98                 save    %sp, -0x68, %sp
F0030438: a0100018                 mov     %i0, %l0
F003043C: 9010001a                 mov     %i2, %o0
F0030440: 1320081a92126110         set     -0x7FDF96F0, %o1
F0030448: d614200c                 lduh    [%l0+0xC], %o3
F003044C: 94100019                 mov     %i1, %o2
F0030450: 960afffe                 and     %o3, -2, %o3
F0030454: 7fffe602                 call    _ifioctl
F0030458: d6366010                 sth     %o3, [%i1+0x10]
F003045C: 80a22000                 cmp     %o0, 0
F0030460: 32800023                 bne,a   locret_F00304EC
F0030464: b0100008                 mov     %o0, %i0
F0030468: 90066010                 add     %i1, 0x10, %o0! void *
F003046C: 92102010                 mov     0x10, %o1! size_t
F0030470: d614200c                 lduh    [%l0+0xC], %o3
F0030474: 153fffd0                 sethi   -0xC000, %o2
F0030478: 942ac00a                 andn    %o3, %o2, %o2
F003047C: d434200c                 sth     %o2, [%l0+0xC]
F0030480: 40019276                 call    _bzero
F0030484: 01000000                 nop
F0030488: 90102002                 mov     2, %o0
F003048C: d0366010                 sth     %o0, [%i1+0x10]
F0030490: 9010001a                 mov     %i2, %o0
F0030494: 1320081a92126116         set     -0x7FDF96EA, %o1
F003049C: 7fffe5f0                 call    _ifioctl
F00304A0: 94100019                 mov     %i1, %o2
F00304A4: 80a22000                 cmp     %o0, 0
F00304A8: 32800011                 bne,a   locret_F00304EC
F00304AC: b0100008                 mov     %o0, %i0
F00304B0: 9010001a                 mov     %i2, %o0
F00304B4: 1320081a9212610c         set     -0x7FDF96F4, %o1
F00304BC: d606c000                 ld      [%i3], %o3
F00304C0: 94100019                 mov     %i1, %o2
F00304C4: 7fffe5e6                 call    _ifioctl
F00304C8: d622a014                 st      %o3, [%o2+0x14]
F00304CC: 80a22000                 cmp     %o0, 0
F00304D0: 12800007                 bne     locret_F00304EC
F00304D4: b0100008                 mov     %o0, %i0
F00304D8: b0102000                 mov     0, %i0
F00304DC: d014200c                 lduh    [%l0+0xC], %o0
F00304E0: 133fffe0                 sethi   -0x8000, %o1
F00304E4: 90120009                 bset    %o1, %o0
F00304E8: d034200c                 sth     %o0, [%l0+0xC]
F00304EC: 81c7e008                 ret
F00304F0: 81e80000                 restore
