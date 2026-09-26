F00398EC: 9de3bf90                 save    %sp, -0x70, %sp
F00398F0: 4000b9e0                 call    _kalloc
F00398F4: 90102048                 mov     0x48, %o0 ! 'H'
F00398F8: 92102001                 mov     1, %o1
F00398FC: d4062024                 ld      [%i0+0x24], %o2
F0039900: a0100008                 mov     %o0, %l0
F0039904: d6062030                 ld      [%i0+0x30], %o3
F0039908: 9a100010                 mov     %l0, %o5
F003990C: d802a128                 ld      [%o2+0x128], %o4
F0039910: 9602e040                 inc     0x40, %o3 ! '@'
F0039914: 153c01059412a29c         set     _xdr_fhandle, %o2
F003991C: f423a05c                 st      %i2, [%sp+0x70+var_14]
F0039920: 9010000c                 mov     %o4, %o0
F0039924: 193c0107                 sethi   %hi(_xdr_attrstat), %o4
F0039928: 40000b93                 call    _rfscall
F003992C: 98132254                 bset    %lo(_xdr_attrstat), %o4
F0039930: b4920000                 orcc    %o0, %g0, %i2
F0039934: 32800019                 bne,a   loc_F0039998
F0039938: 90100010                 mov     %l0, %o0
F003993C: f4040000                 ld      [%l0], %i2
F0039940: 80a6a000                 cmp     %i2, 0
F0039944: 1280000e                 bne     loc_F003997C
F0039948: 80a6a046                 cmp     %i2, 0x46 ! 'F'
F003994C: 90100018                 mov     %i0, %o0
F0039950: 92042004                 add     %l0, 4, %o1
F0039954: 40000035                 call    _nattr_to_vattr
F0039958: 94100019                 mov     %i1, %o2
F003995C: d0062024                 ld      [%i0+0x24], %o0
F0039960: d2022128                 ld      [%o0+0x128], %o1
F0039964: 1100003f                 sethi   0xFC00, %o0
F0039968: d2026028                 ld      [%o1+0x28], %o1
F003996C: 90122300                 bset    0x300, %o0
F0039970: 92124008                 bset    %o0, %o1
F0039974: 10800008                 ba      loc_F0039994
F0039978: d226600c                 st      %o1, [%i1+0xC]
F003997C: 12800007                 bne     loc_F0039998
F0039980: 90100010                 mov     %l0, %o0
F0039984: 7fffaede                 call    _btrash
F0039988: 90100018                 mov     %i0, %o0
F003998C: 7fffff27                 call    _nfs_invalidate_caches
F0039990: 90100018                 mov     %i0, %o0
F0039994: 90100010                 mov     %l0, %o0
F0039998: 4000ba02                 call    _kfree
F003999C: 92102048                 mov     0x48, %o1 ! 'H'
F00399A0: 81c7e008                 ret
F00399A4: 91e8001a                 restore %g0, %i2, %o0
