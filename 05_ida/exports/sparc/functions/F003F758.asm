F003F758: 9de3bf40                 save    %sp, -0xC0, %sp
F003F75C: 4000a245                 call    _kalloc
F003F760: 90102048                 mov     0x48, %o0 ! 'H'
F003F764: d2566014                 ldsh    [%i1+0x14], %o1
F003F768: 80a27fff                 cmp     %o1, -1
F003F76C: 12800016                 bne     loc_F003F7C4
F003F770: a2100008                 mov     %o0, %l1
F003F774: d006601c                 ld      [%i1+0x1C], %o0
F003F778: 80a23fff                 cmp     %o0, -1
F003F77C: 1280006f                 bne     loc_F003F938
F003F780: a0102016                 mov     0x16, %l0
F003F784: d0566038                 ldsh    [%i1+0x38], %o0
F003F788: 80a23fff                 cmp     %o0, -1
F003F78C: 1280006c                 bne     loc_F003F93C
F003F790: 90100011                 mov     %l1, %o0
F003F794: d006603c                 ld      [%i1+0x3C], %o0
F003F798: 80a23fff                 cmp     %o0, -1
F003F79C: 12800068                 bne     loc_F003F93C
F003F7A0: 90100011                 mov     %l1, %o0
F003F7A4: d0066030                 ld      [%i1+0x30], %o0
F003F7A8: 80a23fff                 cmp     %o0, -1
F003F7AC: 12800064                 bne     loc_F003F93C
F003F7B0: 90100011                 mov     %l1, %o0
F003F7B4: d0066034                 ld      [%i1+0x34], %o0
F003F7B8: 80a23fff                 cmp     %o0, -1
F003F7BC: 02800004                 be      loc_F003F7CC
F003F7C0: 01000000                 nop
F003F7C4: 1080005d                 ba      loc_F003F938
F003F7C8: a0102016                 mov     0x16, %l0
F003F7CC: 40000569                 call    _sync_vp
F003F7D0: 90100018                 mov     %i0, %o0
F003F7D4: d2066018                 ld      [%i1+0x18], %o1
F003F7D8: 80a27fff                 cmp     %o1, -1
F003F7DC: 22800012                 be,a    loc_F003F824
F003F7E0: d0066028                 ld      [%i1+0x28], %o0
F003F7E4: 4000b3c4                 call    _mfs_trunc
F003F7E8: 90100018                 mov     %i0, %o0
F003F7EC: 80a22000                 cmp     %o0, 0
F003F7F0: 22800005                 be,a    loc_F003F804
F003F7F4: d4060000                 ld      [%i0], %o2
F003F7F8: 4000055e                 call    _sync_vp
F003F7FC: 90100018                 mov     %i0, %o0
F003F800: d4060000                 ld      [%i0], %o2
F003F804: d2066018                 ld      [%i1+0x18], %o1
F003F808: 90100018                 mov     %i0, %o0
F003F80C: 7fff96fa                 call    _binvalfree
F003F810: d222a014                 st      %o1, [%o2+0x14]
F003F814: d2062030                 ld      [%i0+0x30], %o1
F003F818: d0066018                 ld      [%i1+0x18], %o0
F003F81C: d0226098                 st      %o0, [%o1+0x98]
F003F820: d0066028                 ld      [%i1+0x28], %o0
F003F824: 80a23fff                 cmp     %o0, -1
F003F828: 02800012                 be      loc_F003F870
F003F82C: 90100019                 mov     %i1, %o0
F003F830: d006602c                 ld      [%i1+0x2C], %o0
F003F834: 80a23fff                 cmp     %o0, -1
F003F838: 3280000e                 bne,a   loc_F003F870
F003F83C: 90100019                 mov     %i1, %o0
F003F840: 7fff4dd3                 call    _getthetime
F003F844: 9007bfb0                 add     %fp, var_50, %o0
F003F848: d007bfb0                 ld      [%fp+var_50], %o0
F003F84C: d0266020                 st      %o0, [%i1+0x20]
F003F850: d007bfb4                 ld      [%fp+var_4C], %o0
F003F854: d0266024                 st      %o0, [%i1+0x24]
F003F858: d007bfb0                 ld      [%fp+var_50], %o0
F003F85C: d0266028                 st      %o0, [%i1+0x28]
F003F860: 110003d090122240         set     0xF4240, %o0
F003F868: d026602c                 st      %o0, [%i1+0x2C]
F003F86C: 90100019                 mov     %i1, %o0
F003F870: 9207bfd8                 add     %fp, var_28, %o1
F003F874: 7ffff4c3                 call    _vattr_to_sattr
F003F878: a007bfb8                 add     %fp, var_48, %l0
F003F87C: 92100010                 mov     %l0, %o1! void *
F003F880: d0062030                 ld      [%i0+0x30], %o0! void *
F003F884: 94102020                 mov     0x20, %o2 ! ' '! size_t
F003F888: 400154a2                 call    _bcopy
F003F88C: 90022040                 inc     0x40, %o0 ! '@'
F003F890: 92102002                 mov     2, %o1
F003F894: 153c01089412a2f4         set     _xdr_saargs, %o2
F003F89C: 96100010                 mov     %l0, %o3
F003F8A0: 193c0107                 sethi   %hi(_xdr_attrstat), %o4
F003F8A4: d0062024                 ld      [%i0+0x24], %o0
F003F8A8: 98132254                 bset    %lo(_xdr_attrstat), %o4
F003F8AC: d0022128                 ld      [%o0+0x128], %o0
F003F8B0: 9a100011                 mov     %l1, %o5
F003F8B4: 7ffff3b0                 call    _rfscall
F003F8B8: f423a05c                 st      %i2, [%sp+0xC0+var_64]
F003F8BC: a0920000                 orcc    %o0, %g0, %l0
F003F8C0: 3280001d                 bne,a   loc_F003F934
F003F8C4: d0062030                 ld      [%i0+0x30], %o0
F003F8C8: e0044000                 ld      [%l1], %l0
F003F8CC: 80a42000                 cmp     %l0, 0
F003F8D0: 32800010                 bne,a   loc_F003F910
F003F8D4: d0062030                 ld      [%i0+0x30], %o0
F003F8D8: d2046038                 ld      [%l1+0x38], %o1
F003F8DC: 90100018                 mov     %i0, %o0
F003F8E0: d227bfa8                 st      %o1, [%fp+var_58]
F003F8E4: d404603c                 ld      [%l1+0x3C], %o2
F003F8E8: 96102002                 mov     2, %o3
F003F8EC: d427bfac                 st      %o2, [%fp+var_54]
F003F8F0: d4046018                 ld      [%l1+0x18], %o2
F003F8F4: 7fffe768                 call    _nfs_cache_check
F003F8F8: 9207bfa8                 add     %fp, var_58, %o1
F003F8FC: 90100018                 mov     %i0, %o0
F003F900: 7fffe77d                 call    _nfs_attrcache
F003F904: 92046004                 add     %l1, 4, %o1
F003F908: 1080000d                 ba      loc_F003F93C
F003F90C: 90100011                 mov     %l1, %o0
F003F910: 80a42046                 cmp     %l0, 0x46 ! 'F'
F003F914: 12800009                 bne     loc_F003F938
F003F918: c02220c0                 clr     [%o0+0xC0]
F003F91C: 7fff96f8                 call    _btrash
F003F920: 90100018                 mov     %i0, %o0
F003F924: 7fffe741                 call    _nfs_invalidate_caches
F003F928: 90100018                 mov     %i0, %o0
F003F92C: 10800004                 ba      loc_F003F93C
F003F930: 90100011                 mov     %l1, %o0
F003F934: c02220c0                 clr     [%o0+0xC0]
F003F938: 90100011                 mov     %l1, %o0
F003F93C: 4000a219                 call    _kfree
F003F940: 92102048                 mov     0x48, %o1 ! 'H'
F003F944: 81c7e008                 ret
F003F948: 91e80010                 restore %g0, %l0, %o0
