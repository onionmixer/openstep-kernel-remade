F00406A4: 9de3bf60                 save    %sp, -0xA0, %sp
F00406A8: a007bfd0                 add     %fp, var_30, %l0
F00406AC: 90100010                 mov     %l0, %o0
F00406B0: 92100019                 mov     %i1, %o1
F00406B4: 7ffff14c                 call    _setdiropargs
F00406B8: 94100018                 mov     %i0, %o2
F00406BC: 7ffff3da                 call    _rlock
F00406C0: d0062030                 ld      [%i0+0x30], %o0
F00406C4: 7fff9598                 call    _dnlc_purge_vp
F00406C8: 90100018                 mov     %i0, %o0
F00406CC: 9210200f                 mov     0xF, %o1
F00406D0: 153c01089412a208         set     _xdr_diropargs, %o2
F00406D8: 193c0115                 sethi   %hi(_xdr_enum), %o4
F00406DC: 96100010                 mov     %l0, %o3
F00406E0: d0062024                 ld      [%i0+0x24], %o0
F00406E4: 98132348                 bset    %lo(_xdr_enum), %o4
F00406E8: d0022128                 ld      [%o0+0x128], %o0
F00406EC: 9a07bfcc                 add     %fp, var_34, %o5
F00406F0: 7ffff021                 call    _rfscall
F00406F4: f423a05c                 st      %i2, [%sp+0xA0+var_44]
F00406F8: d2062030                 ld      [%i0+0x30], %o1
F00406FC: a0100008                 mov     %o0, %l0
F0040700: c02260c0                 clr     [%o1+0xC0]
F0040704: 7ffff3e6                 call    _runlock
F0040708: d0062030                 ld      [%i0+0x30], %o0
F004070C: 80a42000                 cmp     %l0, 0
F0040710: 1280000a                 bne     locret_F0040738
F0040714: 01000000                 nop
F0040718: e007bfcc                 ld      [%fp+var_34], %l0
F004071C: 80a42046                 cmp     %l0, 0x46 ! 'F'
F0040720: 12800006                 bne     locret_F0040738
F0040724: 01000000                 nop
F0040728: 7fff9375                 call    _btrash
F004072C: 90100018                 mov     %i0, %o0
F0040730: 7fffe3be                 call    _nfs_invalidate_caches
F0040734: 90100018                 mov     %i0, %o0
F0040738: 81c7e008                 ret
F004073C: 91e80010                 restore %g0, %l0, %o0
