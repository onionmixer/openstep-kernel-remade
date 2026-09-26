F003F3E0: 9de3bf10                 save    %sp, -0xF0, %sp
F003F3E4: a2100018                 mov     %i0, %l1
F003F3E8: d0046024                 ld      [%l1+0x24], %o0
F003F3EC: d0022128                 ld      [%o0+0x128], %o0
F003F3F0: e0022020                 ld      [%o0+0x20], %l0
F003F3F4: 80a4001b                 cmp     %l0, %i3
F003F3F8: 34800002                 bg,a    loc_F003F400
F003F3FC: a010001b                 mov     %i3, %l0
F003F400: f227bff0                 st      %i1, [%fp+var_10]
F003F404: d2046030                 ld      [%l1+0x30], %o1
F003F408: d0026040                 ld      [%o1+0x40], %o0
F003F40C: d027bfc0                 st      %o0, [%fp+var_40]
F003F410: d0026044                 ld      [%o1+0x44], %o0
F003F414: d027bfc4                 st      %o0, [%fp+var_3C]
F003F418: d0026048                 ld      [%o1+0x48], %o0
F003F41C: d027bfc8                 st      %o0, [%fp+var_38]
F003F420: d002604c                 ld      [%o1+0x4C], %o0
F003F424: 153c0105                 sethi   %hi(_xdr_writeargs), %o2
F003F428: d027bfcc                 st      %o0, [%fp+var_34]
F003F42C: d0026050                 ld      [%o1+0x50], %o0
F003F430: 9412a2c0                 bset    %lo(_xdr_writeargs), %o2
F003F434: d027bfd0                 st      %o0, [%fp+var_30]
F003F438: d0026054                 ld      [%o1+0x54], %o0
F003F43C: 193c0107                 sethi   %hi(_xdr_attrstat), %o4
F003F440: d027bfd4                 st      %o0, [%fp+var_2C]
F003F444: d0026058                 ld      [%o1+0x58], %o0
F003F448: 9607bfc0                 add     %fp, var_40, %o3
F003F44C: d027bfd8                 st      %o0, [%fp+var_28]
F003F450: d002605c                 ld      [%o1+0x5C], %o0
F003F454: 98132254                 bset    %lo(_xdr_attrstat), %o4
F003F458: d027bfdc                 st      %o0, [%fp+var_24]
F003F45C: f427bfe0                 st      %i2, [%fp+var_20]
F003F460: e027bfe8                 st      %l0, [%fp+var_18]
F003F464: e027bfec                 st      %l0, [%fp+var_14]
F003F468: f427bfe4                 st      %i2, [%fp+var_1C]
F003F46C: d0046024                 ld      [%l1+0x24], %o0
F003F470: 9a07bf78                 add     %fp, var_88, %o5
F003F474: d0022128                 ld      [%o0+0x128], %o0
F003F478: 92102008                 mov     8, %o1
F003F47C: 7ffff4be                 call    _rfscall
F003F480: f823a05c                 st      %i4, [%sp+0xF0+var_94]
F003F484: b0920000                 orcc    %o0, %g0, %i0
F003F488: 3280000b                 bne,a   loc_F003F4B4
F003F48C: b626c010                 sub     %i3, %l0, %i3
F003F490: f007bf78                 ld      [%fp+var_88], %i0
F003F494: 80a62046                 cmp     %i0, 0x46 ! 'F'
F003F498: 32800007                 bne,a   loc_F003F4B4
F003F49C: b626c010                 sub     %i3, %l0, %i3
F003F4A0: 7fff9817                 call    _btrash
F003F4A4: 90100011                 mov     %l1, %o0
F003F4A8: 7fffe860                 call    _nfs_invalidate_caches
F003F4AC: 90100011                 mov     %l1, %o0
F003F4B0: b626c010                 sub     %i3, %l0, %i3
F003F4B4: b2064010                 add     %i1, %l0, %i1
F003F4B8: 80a62000                 cmp     %i0, 0
F003F4BC: 12800006                 bne     loc_F003F4D4
F003F4C0: b4068010                 add     %i2, %l0, %i2
F003F4C4: 80a6e000                 cmp     %i3, 0
F003F4C8: 32bfffc9                 bne,a   loc_F003F3EC
F003F4CC: d0046024                 ld      [%l1+0x24], %o0
F003F4D0: 80a62000                 cmp     %i0, 0
F003F4D4: 12800006                 bne     loc_F003F4EC
F003F4D8: 80a6201c                 cmp     %i0, 0x1C
F003F4DC: 90100011                 mov     %l1, %o0
F003F4E0: 7fffe885                 call    _nfs_attrcache
F003F4E4: 9207bf7c                 add     %fp, var_84, %o1
F003F4E8: 80a6201c                 cmp     %i0, 0x1C
F003F4EC: 0280000c                 be      loc_F003F51C
F003F4F0: 80a6201c                 cmp     %i0, 0x1C
F003F4F4: 14800007                 bg      loc_F003F510
F003F4F8: 80a62045                 cmp     %i0, 0x45 ! 'E'
F003F4FC: 80a62000                 cmp     %i0, 0
F003F500: 0280001a                 be      locret_F003F568
F003F504: 01000000                 nop
F003F508: 1080000c                 ba      loc_F003F538
F003F50C: d2046024                 ld      [%l1+0x24], %o1
F003F510: 3280000a                 bne,a   loc_F003F538
F003F514: d2046024                 ld      [%l1+0x24], %o1
F003F518: 30800014                 ba,a    locret_F003F568
F003F51C: d2046024                 ld      [%l1+0x24], %o1
F003F520: 113c0435                 sethi   %hi(aNfsWriteErrorO), %o0! "NFS write error: on host %s remote file"...
F003F524: d2026128                 ld      [%o1+0x128], %o1
F003F528: 90122268                 bset    %lo(aNfsWriteErrorO), %o0! "NFS write error: on host %s remote file"...
F003F52C: 7fff544b                 call    _printf
F003F530: 92026034                 inc     0x34, %o1 ! '4'
F003F534: 3080000d                 ba,a    locret_F003F568
F003F538: 113c0435                 sethi   %hi(aNfsWriteErrorD), %o0! "NFS write error %d on host %s fh "
F003F53C: d4026128                 ld      [%o1+0x128], %o2
F003F540: 901222a0                 bset    %lo(aNfsWriteErrorD), %o0! "NFS write error %d on host %s fh "
F003F544: 92100018                 mov     %i0, %o1
F003F548: 7fff5444                 call    _printf
F003F54C: 9402a034                 inc     0x34, %o2 ! '4'
F003F550: d0046030                 ld      [%l1+0x30], %o0
F003F554: 40000007                 call    sub_F003F570
F003F558: 90022040                 inc     0x40, %o0 ! '@'
F003F55C: 113c0435                 sethi   %hi(asc_F010D6C8), %o0! "\n"
F003F560: 7fff543e                 call    _printf
F003F564: 901222c8                 bset    %lo(asc_F010D6C8), %o0! "\n"
F003F568: 81c7e008                 ret
F003F56C: 81e80000                 restore
