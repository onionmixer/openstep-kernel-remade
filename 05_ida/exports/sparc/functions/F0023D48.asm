F0023D48: 9de3bf90                 save    %sp, -0x70, %sp
F0023D4C: a2102000                 mov     0, %l1
F0023D50: 400110c8                 call    _kalloc
F0023D54: 9010212c                 mov     0x12C, %o0
F0023D58: 213c04d4                 sethi   %hi(_rootvfs), %l0
F0023D5C: d0242160                 st      %o0, [%l0+%lo(_rootvfs)]
F0023D60: 113c04d4a61222e0         set     _rootfs, %l3
F0023D68: 7fffffe1                 call    _vfssw_lookup
F0023D6C: 90100013                 mov     %l3, %o0
F0023D70: a4920000                 orcc    %o0, %g0, %l2
F0023D74: 02800016                 be      loc_F0023DCC
F0023D78: d0042160                 ld      [%l0+%lo(_rootvfs)], %o0
F0023D7C: c0220000                 clr     [%o0]
F0023D80: d204a004                 ld      [%l2+4], %o1
F0023D84: d2222004                 st      %o1, [%o0+4]
F0023D88: c022200c                 clr     [%o0+0xC]
F0023D8C: c022201c                 clr     [%o0+0x1C]
F0023D90: c0222128                 clr     [%o0+0x128]
F0023D94: c0222120                 clr     [%o0+0x120]
F0023D98: 133c04cf                 sethi   %hi(_active_u), %o1
F0023D9C: d40261d8                 ld      [%o1+%lo(_active_u)], %o2
F0023DA0: d6022004                 ld      [%o0+4], %o3
F0023DA4: d402a01c                 ld      [%o2+0x1C], %o2
F0023DA8: 133c04d4                 sethi   %hi(_rootvp), %o1
F0023DAC: d812a002                 lduh    [%o2+2], %o4
F0023DB0: 921263a0                 bset    %lo(_rootvp), %o1
F0023DB4: d8322124                 sth     %o4, [%o0+0x124]
F0023DB8: d602e018                 ld      [%o3+0x18], %o3
F0023DBC: 9fc2c000                 call    %o3
F0023DC0: 9404e010                 add     %l3, 0x10, %o2
F0023DC4: 1080002b                 ba      loc_F0023E70
F0023DC8: a2100008                 mov     %o0, %l1
F0023DCC: 133c042f                 sethi   %hi(_vfssw), %o1
F0023DD0: 153c0430                 sethi   %hi(_vfsNVFS), %o2
F0023DD4: d002a08c                 ld      [%o2+%lo(_vfsNVFS)], %o0
F0023DD8: a41263d8                 or      %o1, %lo(_vfssw), %l2
F0023DDC: 80a48008                 cmp     %l2, %o0
F0023DE0: 1a800025                 bcc     loc_F0023E74
F0023DE4: 80a46000                 cmp     %l1, 0
F0023DE8: ae100010                 mov     %l0, %l7
F0023DEC: 2d3c04cf                 sethi   -0xFECC400, %l6
F0023DF0: 2b3c04d4                 sethi   -0xFECB000, %l5
F0023DF4: 293c04d4                 sethi   -0xFECB000, %l4
F0023DF8: a610000a                 mov     %o2, %l3
F0023DFC: a004a004                 add     %l2, 4, %l0
F0023E00: d0040000                 ld      [%l0], %o0
F0023E04: 80a22000                 cmp     %o0, 0
F0023E08: 02800016                 be      loc_F0023E60
F0023E0C: d004e08c                 ld      [%l3+0x8C], %o0
F0023E10: d005e160                 ld      [%l7+0x160], %o0
F0023E14: c0220000                 clr     [%o0]
F0023E18: d2040000                 ld      [%l0], %o1
F0023E1C: d2222004                 st      %o1, [%o0+4]
F0023E20: c022200c                 clr     [%o0+0xC]
F0023E24: c022201c                 clr     [%o0+0x1C]
F0023E28: c0222128                 clr     [%o0+0x128]
F0023E2C: c0222120                 clr     [%o0+0x120]
F0023E30: d205a1d8                 ld      [%l6+0x1D8], %o1
F0023E34: d6022004                 ld      [%o0+4], %o3
F0023E38: d402601c                 ld      [%o1+0x1C], %o2
F0023E3C: d812a002                 lduh    [%o2+2], %o4
F0023E40: 921563a0                 or      %l5, 0x3A0, %o1
F0023E44: d8322124                 sth     %o4, [%o0+0x124]
F0023E48: d602e018                 ld      [%o3+0x18], %o3
F0023E4C: 9fc2c000                 call    %o3
F0023E50: 941522f0                 or      %l4, 0x2F0, %o2
F0023E54: a2920000                 orcc    %o0, %g0, %l1
F0023E58: 02800007                 be      loc_F0023E74
F0023E5C: d004e08c                 ld      [%l3+0x8C], %o0
F0023E60: a404a008                 inc     8, %l2
F0023E64: 80a48008                 cmp     %l2, %o0
F0023E68: 0abfffe6                 bcs     loc_F0023E00
F0023E6C: a0042008                 inc     8, %l0
F0023E70: 80a46000                 cmp     %l1, 0
F0023E74: 02800008                 be      loc_F0023E94
F0023E78: 113c042f                 sethi   %hi(aVfsMountrootEr), %o0! "vfs_mountroot: error=%d\n"
F0023E7C: 901221f0                 bset    %lo(aVfsMountrootEr), %o0! "vfs_mountroot: error=%d\n"
F0023E80: 7fffc1f6                 call    _printf
F0023E84: 92100011                 mov     %l1, %o1
F0023E88: 113c042f                 sethi   %hi(aVfsMountrootCa), %o0! "vfs_mountroot: cannot mount root"
F0023E8C: 7fffc4b9                 call    _panic
F0023E90: 90122210                 bset    %lo(aVfsMountrootCa), %o0! "vfs_mountroot: cannot mount root"
F0023E94: 113c04d4                 sethi   %hi(_rootvfs), %o0
F0023E98: d0022160                 ld      [%o0+%lo(_rootvfs)], %o0
F0023E9C: d4022004                 ld      [%o0+4], %o2
F0023EA0: 233c04d4                 sethi   %hi(_rootdir), %l1
F0023EA4: d402a008                 ld      [%o2+8], %o2
F0023EA8: 9fc28000                 call    %o2
F0023EAC: 92146158                 or      %l1, %lo(_rootdir), %o1
F0023EB0: 80a22000                 cmp     %o0, 0
F0023EB4: 02800006                 be      loc_F0023ECC
F0023EB8: 213c04cf                 sethi   -0xFECC400, %l0
F0023EBC: 113c042f                 sethi   %hi(aVfsMountrootCa_0), %o0! "vfs_mountroot: cannot find root vnode"
F0023EC0: 7fffc4ac                 call    _panic
F0023EC4: 90122238                 bset    %lo(aVfsMountrootCa_0), %o0! "vfs_mountroot: cannot find root vnode"
F0023EC8: 213c04cf                 sethi   -0xFECC400, %l0
F0023ECC: d20421d8                 ld      [%l0+0x1D8], %o1
F0023ED0: d0046158                 ld      [%l1+0x158], %o0
F0023ED4: d022615c                 st      %o0, [%o1+0x15C]
F0023ED8: d00421d8                 ld      [%l0+0x1D8], %o0
F0023EDC: d202215c                 ld      [%o0+0x15C], %o1
F0023EE0: d0126006                 lduh    [%o1+6], %o0
F0023EE4: 90022001                 inc     %o0
F0023EE8: d0326006                 sth     %o0, [%o1+6]
F0023EEC: d00421d8                 ld      [%l0+0x1D8], %o0
F0023EF0: 133c04d4                 sethi   %hi(_rootname), %o1
F0023EF4: c0222160                 clr     [%o0+0x160]
F0023EF8: d04a6380                 ldsb    [%o1+%lo(_rootname)], %o0
F0023EFC: 80a22000                 cmp     %o0, 0
F0023F00: 02800018                 be      loc_F0023F60
F0023F04: 90126380                 or      %o1, %lo(_rootname), %o0
F0023F08: 92102001                 mov     1, %o1
F0023F0C: 94102001                 mov     1, %o2
F0023F10: 96102000                 mov     0, %o3
F0023F14: 40000aac                 call    _lookupname
F0023F18: 9807bff4                 add     %fp, var_C, %o4
F0023F1C: 80a22000                 cmp     %o0, 0
F0023F20: 32800011                 bne,a   loc_F0023F64
F0023F24: 213c04d4                 sethi   -0xFECB000, %l0
F0023F28: d00421d8                 ld      [%l0+0x1D8], %o0
F0023F2C: d207bff4                 ld      [%fp+var_C], %o1
F0023F30: d002215c                 ld      [%o0+0x15C], %o0
F0023F34: 4000130c                 call    _vn_rele
F0023F38: d2246158                 st      %o1, [%l1+0x158]
F0023F3C: d00421d8                 ld      [%l0+0x1D8], %o0
F0023F40: 40001309                 call    _vn_rele
F0023F44: d002215c                 ld      [%o0+0x15C], %o0
F0023F48: d00421d8                 ld      [%l0+0x1D8], %o0
F0023F4C: d2046158                 ld      [%l1+0x158], %o1
F0023F50: d222215c                 st      %o1, [%o0+0x15C]
F0023F54: d0126006                 lduh    [%o1+6], %o0
F0023F58: 90022001                 inc     %o0
F0023F5C: d0326006                 sth     %o0, [%o1+6]
F0023F60: 213c04d4                 sethi   -0xFECB000, %l0
F0023F64: 113c04d4                 sethi   %hi(_rootvp), %o0
F0023F68: d00223a0                 ld      [%o0+%lo(_rootvp)], %o0! __dst
F0023F6C: a01422e0                 bset    0x2E0, %l0
F0023F70: d0242098                 st      %o0, [%l0+0x98]
F0023F74: d2048000                 ld      [%l2], %o1! __src
F0023F78: 7fff8d6c                 call    _strcpy
F0023F7C: 90100010                 mov     %l0, %o0
F0023F80: c0242094                 clr     [%l0+0x94]
F0023F84: 90102001                 mov     1, %o0
F0023F88: d0242090                 st      %o0, [%l0+0x90]
F0023F8C: 81c7e008                 ret
F0023F90: 81e80000                 restore
