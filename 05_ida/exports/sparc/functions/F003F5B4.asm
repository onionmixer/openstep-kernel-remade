F003F5B4: 9de3bf08                 save    %sp, -0xF8, %sp
F003F5B8: a0100018                 mov     %i0, %l0
F003F5BC: d0042024                 ld      [%l0+0x24], %o0
F003F5C0: d0022128                 ld      [%o0+0x128], %o0
F003F5C4: e202201c                 ld      [%o0+0x1C], %l1
F003F5C8: 80a4401b                 cmp     %l1, %i3
F003F5CC: 34800002                 bg,a    loc_F003F5D4
F003F5D0: a210001b                 mov     %i3, %l1
F003F5D4: f227bfbc                 st      %i1, [%fp+var_44]
F003F5D8: d2042030                 ld      [%l0+0x30], %o1
F003F5DC: d0026040                 ld      [%o1+0x40], %o0
F003F5E0: d027bfc8                 st      %o0, [%fp+var_38]
F003F5E4: d0026044                 ld      [%o1+0x44], %o0
F003F5E8: d027bfcc                 st      %o0, [%fp+var_34]
F003F5EC: d0026048                 ld      [%o1+0x48], %o0
F003F5F0: d027bfd0                 st      %o0, [%fp+var_30]
F003F5F4: d002604c                 ld      [%o1+0x4C], %o0
F003F5F8: 153c0106                 sethi   %hi(_xdr_readargs), %o2
F003F5FC: d027bfd4                 st      %o0, [%fp+var_2C]
F003F600: d0026050                 ld      [%o1+0x50], %o0
F003F604: 9412a28c                 bset    %lo(_xdr_readargs), %o2
F003F608: d027bfd8                 st      %o0, [%fp+var_28]
F003F60C: d0026054                 ld      [%o1+0x54], %o0
F003F610: 193c0107                 sethi   %hi(_xdr_rdresult), %o4
F003F614: d027bfdc                 st      %o0, [%fp+var_24]
F003F618: d0026058                 ld      [%o1+0x58], %o0
F003F61C: 9607bfc8                 add     %fp, var_38, %o3
F003F620: d027bfe0                 st      %o0, [%fp+var_20]
F003F624: d002605c                 ld      [%o1+0x5C], %o0
F003F628: 98132194                 bset    %lo(_xdr_rdresult), %o4
F003F62C: d027bfe4                 st      %o0, [%fp+var_1C]
F003F630: f427bfe8                 st      %i2, [%fp+var_18]
F003F634: e227bff0                 st      %l1, [%fp+var_10]
F003F638: e227bfec                 st      %l1, [%fp+var_14]
F003F63C: d0042024                 ld      [%l0+0x24], %o0
F003F640: 9a07bf70                 add     %fp, var_90, %o5
F003F644: d0022128                 ld      [%o0+0x128], %o0
F003F648: 92102006                 mov     6, %o1
F003F64C: 7ffff44a                 call    _rfscall
F003F650: fa23a05c                 st      %i5, [%sp+0xF8+var_9C]
F003F654: b0920000                 orcc    %o0, %g0, %i0
F003F658: 12800020                 bne     loc_F003F6D8
F003F65C: 01000000                 nop
F003F660: f007bf70                 ld      [%fp+var_90], %i0
F003F664: 80a62046                 cmp     %i0, 0x46 ! 'F'
F003F668: 12800016                 bne     loc_F003F6C0
F003F66C: 80a62000                 cmp     %i0, 0
F003F670: d2042024                 ld      [%l0+0x24], %o1
F003F674: 113c0435                 sethi   %hi(aNfsReadErrorEs), %o0! "NFS read error ESTALE to host %10s fh "
F003F678: d2026128                 ld      [%o1+0x128], %o1
F003F67C: 901222d8                 bset    %lo(aNfsReadErrorEs), %o0! "NFS read error ESTALE to host %10s fh "
F003F680: 7fff53f6                 call    _printf
F003F684: 92026034                 inc     0x34, %o1 ! '4'
F003F688: d0042030                 ld      [%l0+0x30], %o0
F003F68C: 7fffffb9                 call    sub_F003F570
F003F690: 90022040                 inc     0x40, %o0 ! '@'
F003F694: 113c0435                 sethi   %hi(asc_F010D700), %o0! "\n"
F003F698: 7fff53f0                 call    _printf
F003F69C: 90122300                 bset    %lo(asc_F010D700), %o0! "\n"
F003F6A0: 80a62046                 cmp     %i0, 0x46 ! 'F'
F003F6A4: 12800007                 bne     loc_F003F6C0
F003F6A8: 80a62000                 cmp     %i0, 0
F003F6AC: 7fff9794                 call    _btrash
F003F6B0: 90100010                 mov     %l0, %o0
F003F6B4: 7fffe7dd                 call    _nfs_invalidate_caches
F003F6B8: 90100010                 mov     %l0, %o0
F003F6BC: 80a62000                 cmp     %i0, 0
F003F6C0: 12800006                 bne     loc_F003F6D8
F003F6C4: 80a62000                 cmp     %i0, 0
F003F6C8: d007bfb8                 ld      [%fp+var_48], %o0
F003F6CC: b626c008                 sub     %i3, %o0, %i3
F003F6D0: b2064008                 add     %i1, %o0, %i1
F003F6D4: b4068008                 add     %i2, %o0, %i2
F003F6D8: 12800007                 bne     loc_F003F6F4
F003F6DC: 80a6e000                 cmp     %i3, 0
F003F6E0: 02800005                 be      loc_F003F6F4
F003F6E4: d007bfb8                 ld      [%fp+var_48], %o0
F003F6E8: 80a20011                 cmp     %o0, %l1
F003F6EC: 22bfffb5                 be,a    loc_F003F5C0
F003F6F0: d0042024                 ld      [%l0+0x24], %o0
F003F6F4: 80a62000                 cmp     %i0, 0
F003F6F8: 12800006                 bne     locret_F003F710
F003F6FC: f6270000                 st      %i3, [%i4]
F003F700: 90100010                 mov     %l0, %o0
F003F704: d407a05c                 ld      [%fp+arg_5C], %o2
F003F708: 7fffe8c8                 call    _nattr_to_vattr
F003F70C: 9207bf74                 add     %fp, var_8C, %o1
F003F710: 81c7e008                 ret
F003F714: 81e80000                 restore
