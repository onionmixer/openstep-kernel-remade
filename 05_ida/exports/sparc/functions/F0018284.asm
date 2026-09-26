F0018284: 9de3bf98                 save    %sp, -0x68, %sp
F0018288: 40000b98                 call    _ttynty
F001828C: 9010001a                 mov     %i2, %o0
F0018290: a0100008                 mov     %o0, %l0
F0018294: d0042010                 ld      [%l0+0x10], %o0
F0018298: 808a2800                 btst    0x800, %o0
F001829C: 0280007c                 be      locret_F001848C
F00182A0: 11080000                 sethi   0x20000000, %o0
F00182A4: d206a03c                 ld      [%i2+0x3C], %o1
F00182A8: 808a4008                 btst    %o0, %o1
F00182AC: 02800005                 be      loc_F00182C0
F00182B0: 113c04d0                 sethi   -0xFECC000, %o0
F00182B4: 7fffff5f                 call    _ttypend
F00182B8: 9010001a                 mov     %i2, %o0
F00182BC: 113c04d0                 sethi   -0xFECC000, %o0
F00182C0: d2022218                 ld      [%o0+0x218], %o1
F00182C4: d406a03c                 ld      [%i2+0x3C], %o2
F00182C8: 92024019                 add     %o1, %i1, %o1
F00182CC: 808aa020                 btst    0x20, %o2 ! ' '
F00182D0: 02800040                 be      loc_F00183D0
F00182D4: d2222218                 st      %o1, [%o0+0x218]
F00182D8: d2068000                 ld      [%i2], %o1
F00182DC: 90024019                 add     %o1, %i1, %o0
F00182E0: 80a22400                 cmp     %o0, 0x400
F00182E4: 0480000a                 ble     loc_F001830C
F00182E8: 90102400                 mov     0x400, %o0
F00182EC: b2a20009                 subcc   %o0, %o1, %i1
F00182F0: 2c800002                 bneg,a  loc_F00182F8
F00182F4: b2102000                 mov     0, %i1
F00182F8: 90102004                 mov     4, %o0! __x
F00182FC: d456a038                 ldsh    [%i2+0x38], %o2
F0018300: 133c042e                 sethi   %hi(aTtyDRawInputOv_0), %o1! "tty%d: raw input overrun\n"
F0018304: 7ffff12c                 call    _log
F0018308: 92126018                 bset    %lo(aTtyDRawInputOv_0), %o1! "tty%d: raw input overrun\n"
F001830C: 90100018                 mov     %i0, %o0
F0018310: 92100019                 mov     %i1, %o1
F0018314: 4000125a                 call    _b_to_q
F0018318: 9410001a                 mov     %i2, %o2
F001831C: 90264008                 sub     %i1, %o0, %o0
F0018320: 80a22000                 cmp     %o0, 0
F0018324: 2480000a                 ble,a   loc_F001834C
F0018328: d206a03c                 ld      [%i2+0x3C], %o1
F001832C: 4000088d                 call    _ttcheckwakeup
F0018330: 90100010                 mov     %l0, %o0
F0018334: 80a22000                 cmp     %o0, 0
F0018338: 22800005                 be,a    loc_F001834C
F001833C: d206a03c                 ld      [%i2+0x3C], %o1
F0018340: 40000899                 call    _ttwakeup
F0018344: 9010001a                 mov     %i2, %o0
F0018348: d206a03c                 ld      [%i2+0x3C], %o1
F001834C: 11002000                 sethi   0x800000, %o0
F0018350: 902a4008                 andn    %o1, %o0, %o0
F0018354: 808a6008                 btst    8, %o1
F0018358: 0280000a                 be      loc_F0018380
F001835C: d026a03c                 st      %o0, [%i2+0x3C]
F0018360: 90100018                 mov     %i0, %o0
F0018364: 92100019                 mov     %i1, %o1
F0018368: 40001245                 call    _b_to_q
F001836C: 9406a018                 add     %i2, 0x18, %o2
F0018370: 153c04d0                 sethi   %hi(_tk_nout), %o2
F0018374: d202a220                 ld      [%o2+%lo(_tk_nout)], %o1
F0018378: 92024008                 add     %o1, %o0, %o1
F001837C: d222a220                 st      %o1, [%o2+%lo(_tk_nout)]
F0018380: d0042010                 ld      [%l0+0x10], %o0
F0018384: 808a2010                 btst    0x10, %o0
F0018388: 0280001c                 be      loc_F00183F8
F001838C: 11100000                 sethi   0x40000000, %o0
F0018390: d206a03c                 ld      [%i2+0x3C], %o1
F0018394: 808a4008                 btst    %o0, %o1
F0018398: 2280000b                 be,a    loc_F00183C4
F001839C: d006a040                 ld      [%i2+0x40], %o0
F00183A0: d20ea052                 ldub    [%i2+0x52], %o1
F00183A4: 80a260ff                 cmp     %o1, 0xFF
F00183A8: 22800015                 be,a    loc_F00183FC
F00183AC: d0068000                 ld      [%i2], %o0
F00183B0: d00ea051                 ldub    [%i2+0x51], %o0
F00183B4: 80a24008                 cmp     %o1, %o0
F00183B8: 32800011                 bne,a   loc_F00183FC
F00183BC: d0068000                 ld      [%i2], %o0
F00183C0: d006a040                 ld      [%i2+0x40], %o0
F00183C4: 900a3eff                 and     %o0, -0x101, %o0
F00183C8: 1080000c                 ba      loc_F00183F8
F00183CC: d026a040                 st      %o0, [%i2+0x40]
F00183D0: b2867fff                 inccc   -1, %i1
F00183D4: 2c80000a                 bneg,a  loc_F00183FC
F00183D8: d0068000                 ld      [%i2], %o0
F00183DC: d00e0000                 ldub    [%i0], %o0
F00183E0: 92100010                 mov     %l0, %o1
F00183E4: 4000002c                 call    _ttcooked
F00183E8: b0062001                 inc     %i0
F00183EC: b2867fff                 inccc   -1, %i1
F00183F0: 3cbffffc                 bpos,a  loc_F00183E0
F00183F4: d00e0000                 ldub    [%i0], %o0
F00183F8: d0068000                 ld      [%i2], %o0
F00183FC: d206a00c                 ld      [%i2+0xC], %o1! FILE *
F0018400: 90020009                 add     %o0, %o1, %o0
F0018404: 80a221ff                 cmp     %o0, 0x1FF
F0018408: 0480001f                 ble     loc_F0018484
F001840C: 01000000                 nop
F0018410: d006a03c                 ld      [%i2+0x3C], %o0
F0018414: 808a2022                 btst    0x22, %o0 ! '"'
F0018418: 12800005                 bne     loc_F001842C
F001841C: 808a2001                 btst    1, %o0
F0018420: 80a26000                 cmp     %o1, 0
F0018424: 04800018                 ble     loc_F0018484
F0018428: 808a2001                 btst    1, %o0
F001842C: 22800013                 be,a    loc_F0018478
F0018430: d006a040                 ld      [%i2+0x40], %o0
F0018434: d00ea052                 ldub    [%i2+0x52], %o0
F0018438: 80a220ff                 cmp     %o0, 0xFF
F001843C: 2280000f                 be,a    loc_F0018478
F0018440: d006a040                 ld      [%i2+0x40], %o0
F0018444: 912a2018                 sll     %o0, 24, %o0
F0018448: 913a2018                 sra     %o0, 24, %o0! int
F001844C: 400011c1                 call    _putc
F0018450: 9206a018                 add     %i2, 0x18, %o1
F0018454: 80a22000                 cmp     %o0, 0
F0018458: 32800008                 bne,a   loc_F0018478
F001845C: d006a040                 ld      [%i2+0x40], %o0
F0018460: d206a040                 ld      [%i2+0x40], %o1
F0018464: 9010001a                 mov     %i2, %o0
F0018468: 92126400                 bset    0x400, %o1
F001846C: 7ffff9c3                 call    _ttstart
F0018470: d226a040                 st      %o1, [%i2+0x40]
F0018474: d006a040                 ld      [%i2+0x40], %o0
F0018478: 13002000                 sethi   0x800000, %o1
F001847C: 90120009                 bset    %o1, %o0
F0018480: d026a040                 st      %o0, [%i2+0x40]
F0018484: 7ffff9bd                 call    _ttstart
F0018488: 9010001a                 mov     %i2, %o0
F001848C: 81c7e008                 ret
F0018490: 81e80000                 restore
