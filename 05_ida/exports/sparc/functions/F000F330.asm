F000F330: 9de3bf98                 save    %sp, -0x68, %sp
F000F334: 2b3c04cf901561dc         set     dword_F0133DDC, %o0
F000F33C: d2023ffc                 ld      [%o0-4], %o1
F000F340: d002601c                 ld      [%o1+0x1C], %o0
F000F344: e6122006                 lduh    [%o0+6], %l3
F000F348: d0024000                 ld      [%o1], %o0
F000F34C: d20561dc                 ld      [%l5+0x1DC], %o1
F000F350: d0522030                 ldsh    [%o0+0x30], %o0
F000F354: d2026024                 ld      [%o1+0x24], %o1
F000F358: 7ffffdf2                 call    _get_posix_proc
F000F35C: e0024000                 ld      [%o1], %l0
F000F360: 932c2010                 sll     %l0, 16, %o1
F000F364: a33a6010                 sra     %o1, 16, %l1
F000F368: 80a46000                 cmp     %l1, 0
F000F36C: 16800006                 bge     loc_F000F384
F000F370: a8100008                 mov     %o0, %l4
F000F374: d20561dc                 ld      [%l5+0x1DC], %o1
F000F378: 90102016                 mov     0x16, %o0
F000F37C: 10800032                 ba      locret_F000F444
F000F380: d02a6038                 stb     %o0, [%o1+0x38]
F000F384: 4000017a                 call    _suser
F000F388: e4152006                 lduh    [%l4+6], %l2
F000F38C: 80a22000                 cmp     %o0, 0
F000F390: 22800006                 be,a    loc_F000F3A8
F000F394: 912ce010                 sll     %l3, 16, %o0
F000F398: a4100010                 mov     %l0, %l2
F000F39C: a2100010                 mov     %l0, %l1
F000F3A0: 10800010                 ba      loc_F000F3E0
F000F3A4: a6100012                 mov     %l2, %l3
F000F3A8: 913a2010                 sra     %o0, 16, %o0
F000F3AC: 80a44008                 cmp     %l1, %o0
F000F3B0: 2280000c                 be,a    loc_F000F3E0
F000F3B4: a2100010                 mov     %l0, %l1
F000F3B8: 912ca010                 sll     %l2, 16, %o0
F000F3BC: 913a2010                 sra     %o0, 16, %o0
F000F3C0: 80a44008                 cmp     %l1, %o0
F000F3C4: 12800004                 bne     loc_F000F3D4
F000F3C8: d20561dc                 ld      [%l5+0x1DC], %o1
F000F3CC: 10800005                 ba      loc_F000F3E0
F000F3D0: a2100010                 mov     %l0, %l1
F000F3D4: 90102001                 mov     1, %o0
F000F3D8: 1080001b                 ba      locret_F000F444
F000F3DC: d02a6038                 stb     %o0, [%o1+0x38]
F000F3E0: 213c04cf                 sethi   %hi(dword_F0133DDC), %l0
F000F3E4: d00421dc                 ld      [%l0+%lo(dword_F0133DDC)], %o0
F000F3E8: c02a2038                 clrb    [%o0+0x38]
F000F3EC: a01421dc                 bset    %lo(dword_F0133DDC), %l0
F000F3F0: d0043ffc                 ld      [%l0-4], %o0
F000F3F4: 40016674                 call    _lock_write
F000F3F8: 90022020                 inc     0x20, %o0 ! ' '
F000F3FC: d0043ffc                 ld      [%l0-4], %o0
F000F400: 4000019c                 call    _crcopy
F000F404: d002201c                 ld      [%o0+0x1C], %o0
F000F408: d2043ffc                 ld      [%l0-4], %o1
F000F40C: d022601c                 st      %o0, [%o1+0x1C]
F000F410: d0043ffc                 ld      [%l0-4], %o0
F000F414: d002201c                 ld      [%o0+0x1C], %o0
F000F418: e6352004                 sth     %l3, [%l4+4]
F000F41C: e6322006                 sth     %l3, [%o0+6]
F000F420: d0043ffc                 ld      [%l0-4], %o0
F000F424: d202201c                 ld      [%o0+0x1C], %o1
F000F428: d0020000                 ld      [%o0], %o0
F000F42C: e2326002                 sth     %l1, [%o1+2]
F000F430: e232202c                 sth     %l1, [%o0+0x2C]
F000F434: d0043ffc                 ld      [%l0-4], %o0
F000F438: 400166ff                 call    _lock_done
F000F43C: 90022020                 inc     0x20, %o0 ! ' '
F000F440: e4352006                 sth     %l2, [%l4+6]
F000F444: 81c7e008                 ret
F000F448: 81e80000                 restore
