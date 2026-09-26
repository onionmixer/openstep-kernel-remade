F004002C: 9de3bf58                 save    %sp, -0xA8, %sp
F0040030: c027bfc4                 clr     [%fp+var_3C]
F0040034: 90100018                 mov     %i0, %o0
F0040038: 92100019                 mov     %i1, %o1
F004003C: 9407bfcc                 add     %fp, var_34, %o2
F0040040: 9610001a                 mov     %i2, %o3
F0040044: 98102000                 mov     0, %o4
F0040048: 7ffffee7                 call    sub_F003FBE4
F004004C: 9a102000                 mov     0, %o5
F0040050: a0920000                 orcc    %o0, %g0, %l0
F0040054: 1280000e                 bne     loc_F004008C
F0040058: a4102000                 mov     0, %l2
F004005C: d007bfcc                 ld      [%fp+var_34], %o0
F0040060: d402201c                 ld      [%o0+0x1C], %o2
F0040064: d402a070                 ld      [%o2+0x70], %o2
F0040068: 9fc28000                 call    %o2
F004006C: 9207bfc8                 add     %fp, var_38, %o1
F0040070: 80a22000                 cmp     %o0, 0
F0040074: 12800005                 bne     loc_F0040088
F0040078: a4102000                 mov     0, %l2
F004007C: d007bfc8                 ld      [%fp+var_38], %o0
F0040080: e407bfcc                 ld      [%fp+var_34], %l2
F0040084: d027bfcc                 st      %o0, [%fp+var_34]
F0040088: 80a42000                 cmp     %l0, 0
F004008C: 1280007a                 bne     loc_F0040274
F0040090: 80a42000                 cmp     %l0, 0
F0040094: d007bfcc                 ld      [%fp+var_34], %o0
F0040098: 80a22000                 cmp     %o0, 0
F004009C: 02800076                 be      loc_F0040274
F00400A0: 80a42000                 cmp     %l0, 0
F00400A4: 7ffff560                 call    _rlock
F00400A8: d0062030                 ld      [%i0+0x30], %o0
F00400AC: 7fff971e                 call    _dnlc_purge_vp
F00400B0: d007bfcc                 ld      [%fp+var_34], %o0
F00400B4: d207bfcc                 ld      [%fp+var_34], %o1
F00400B8: d0126006                 lduh    [%o1+6], %o0
F00400BC: 80a22001                 cmp     %o0, 1
F00400C0: 08800031                 bleu    loc_F0040184
F00400C4: a007bfd0                 add     %fp, var_30, %l0
F00400C8: d0026030                 ld      [%o1+0x30], %o0
F00400CC: d002207c                 ld      [%o0+0x7C], %o0
F00400D0: 80a22000                 cmp     %o0, 0
F00400D4: 3280002d                 bne,a   loc_F0040188
F00400D8: 90100010                 mov     %l0, %o0
F00400DC: 7ffff524                 call    _newname
F00400E0: 01000000                 nop
F00400E4: a2100008                 mov     %o0, %l1
F00400E8: 7ffff56d                 call    _runlock
F00400EC: d0062030                 ld      [%i0+0x30], %o0
F00400F0: 90100018                 mov     %i0, %o0
F00400F4: 92100019                 mov     %i1, %o1
F00400F8: 94100018                 mov     %i0, %o2
F00400FC: 96100011                 mov     %l1, %o3
F0040100: 400000a9                 call    sub_F00403A4
F0040104: 9810001a                 mov     %i2, %o4
F0040108: a0100008                 mov     %o0, %l0
F004010C: 7ffff546                 call    _rlock
F0040110: d0062030                 ld      [%i0+0x30], %o0
F0040114: 80a42000                 cmp     %l0, 0
F0040118: 02800005                 be      loc_F004012C
F004011C: 90100011                 mov     %l1, %o0
F0040120: 4000a020                 call    _kfree
F0040124: 921020ff                 mov     0xFF, %o1
F0040128: 30800041                 ba,a    loc_F004022C
F004012C: d0162006                 lduh    [%i0+6], %o0
F0040130: d207bfcc                 ld      [%fp+var_34], %o1
F0040134: 90022001                 inc     %o0
F0040138: d0362006                 sth     %o0, [%i0+6]
F004013C: d0026030                 ld      [%o1+0x30], %o0
F0040140: f022207c                 st      %i0, [%o0+0x7C]
F0040144: d0026030                 ld      [%o1+0x30], %o0
F0040148: e2222078                 st      %l1, [%o0+0x78]
F004014C: d0026030                 ld      [%o1+0x30], %o0
F0040150: d0022074                 ld      [%o0+0x74], %o0
F0040154: 80a22000                 cmp     %o0, 0
F0040158: 22800005                 be,a    loc_F004016C
F004015C: d0168000                 lduh    [%i2], %o0
F0040160: 7fff3e2e                 call    _crfree
F0040164: 01000000                 nop
F0040168: d0168000                 lduh    [%i2], %o0
F004016C: d207bfcc                 ld      [%fp+var_34], %o1
F0040170: 90022001                 inc     %o0
F0040174: d0368000                 sth     %o0, [%i2]
F0040178: d0026030                 ld      [%o1+0x30], %o0
F004017C: 1080002c                 ba      loc_F004022C
F0040180: f4222074                 st      %i2, [%o0+0x74]
F0040184: 90100010                 mov     %l0, %o0
F0040188: d607bfcc                 ld      [%fp+var_34], %o3
F004018C: 92100019                 mov     %i1, %o1
F0040190: da02e030                 ld      [%o3+0x30], %o5
F0040194: 94100018                 mov     %i0, %o2
F0040198: 1700003f                 sethi   0xFC00, %o3
F004019C: d8136060                 lduh    [%o5+0x60], %o4
F00401A0: 9612e3ef                 bset    0x3EF, %o3
F00401A4: 980b000b                 and     %o4, %o3, %o4
F00401A8: 7ffff28f                 call    _setdiropargs
F00401AC: d8336060                 sth     %o4, [%o5+0x60]
F00401B0: 9210200a                 mov     0xA, %o1
F00401B4: 153c01089412a208         set     _xdr_diropargs, %o2
F00401BC: 96100010                 mov     %l0, %o3
F00401C0: 193c0115                 sethi   %hi(_xdr_enum), %o4
F00401C4: d0062024                 ld      [%i0+0x24], %o0
F00401C8: 98132348                 bset    %lo(_xdr_enum), %o4
F00401CC: d0022128                 ld      [%o0+0x128], %o0
F00401D0: 9a07bfc4                 add     %fp, var_3C, %o5
F00401D4: 7ffff168                 call    _rfscall
F00401D8: f423a05c                 st      %i2, [%sp+0xA8+var_4C]
F00401DC: d2062030                 ld      [%i0+0x30], %o1
F00401E0: a0100008                 mov     %o0, %l0
F00401E4: d007bfcc                 ld      [%fp+var_34], %o0
F00401E8: c02260c0                 clr     [%o1+0xC0]
F00401EC: d0022030                 ld      [%o0+0x30], %o0
F00401F0: 80a42000                 cmp     %l0, 0
F00401F4: 12800007                 bne     loc_F0040210
F00401F8: c02220c0                 clr     [%o0+0xC0]
F00401FC: d007bfc4                 ld      [%fp+var_3C], %o0
F0040200: 80a22046                 cmp     %o0, 0x46 ! 'F'
F0040204: 02800006                 be      loc_F004021C
F0040208: 01000000                 nop
F004020C: 30800008                 ba,a    loc_F004022C
F0040210: 80a42046                 cmp     %l0, 0x46 ! 'F'
F0040214: 12800006                 bne     loc_F004022C
F0040218: 01000000                 nop
F004021C: 7fff94b8                 call    _btrash
F0040220: 90100018                 mov     %i0, %o0
F0040224: 7fffe501                 call    _nfs_invalidate_caches
F0040228: 90100018                 mov     %i0, %o0
F004022C: 7ffff51c                 call    _runlock
F0040230: d0062030                 ld      [%i0+0x30], %o0
F0040234: 80a4a000                 cmp     %l2, 0
F0040238: 02800007                 be      loc_F0040254
F004023C: 90100012                 mov     %l2, %o0
F0040240: 92103fff                 mov     -1, %o1
F0040244: 7fff9424                 call    _bflush
F0040248: 94103fff                 mov     -1, %o2
F004024C: 10800007                 ba      loc_F0040268
F0040250: 90100012                 mov     %l2, %o0
F0040254: 92103fff                 mov     -1, %o1
F0040258: d007bfcc                 ld      [%fp+var_34], %o0
F004025C: 7fff941e                 call    _bflush
F0040260: 94103fff                 mov     -1, %o2
F0040264: d007bfcc                 ld      [%fp+var_34], %o0
F0040268: 7fffa23f                 call    _vn_rele
F004026C: 01000000                 nop
F0040270: 80a42000                 cmp     %l0, 0
F0040274: 22800002                 be,a    locret_F004027C
F0040278: e007bfc4                 ld      [%fp+var_3C], %l0
F004027C: 81c7e008                 ret
F0040280: 91e80010                 restore %g0, %l0, %o0
