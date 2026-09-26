F003A964: 9de3bf78                 save    %sp, -0x88, %sp
F003A968: 90100018                 mov     %i0, %o0
F003A96C: 400005ad                 call    sub_F003C020
F003A970: 9210001a                 mov     %i2, %o1! size_t
F003A974: b0920000                 orcc    %o0, %g0, %i0
F003A978: 12800004                 bne     loc_F003A988
F003A97C: 90102046                 mov     0x46, %o0 ! 'F'
F003A980: 10800028                 ba      locret_F003AA20
F003A984: d0264000                 st      %o0, [%i1]
F003A988: 4000b5ba                 call    _kalloc
F003A98C: 90102400                 mov     0x400, %o0! void *
F003A990: d0266008                 st      %o0, [%i1+8]
F003A994: 40016931                 call    _bzero
F003A998: 92102400                 mov     0x400, %o1
F003A99C: d0066008                 ld      [%i1+8], %o0
F003A9A0: a0102400                 mov     0x400, %l0
F003A9A4: d027bff0                 st      %o0, [%fp+var_10]
F003A9A8: e027bff4                 st      %l0, [%fp+var_C]
F003A9AC: 9007bff0                 add     %fp, var_10, %o0
F003A9B0: d027bfd8                 st      %o0, [%fp+var_28]
F003A9B4: 90102001                 mov     1, %o0
F003A9B8: d027bfdc                 st      %o0, [%fp+var_24]
F003A9BC: d027bfe4                 st      %o0, [%fp+var_1C]
F003A9C0: c027bfe0                 clr     [%fp+var_20]
F003A9C4: e027bfec                 st      %l0, [%fp+var_14]
F003A9C8: d206201c                 ld      [%i0+0x1C], %o1
F003A9CC: 113c04cf                 sethi   %hi(_active_u), %o0
F003A9D0: d40221d8                 ld      [%o0+%lo(_active_u)], %o2
F003A9D4: d6026044                 ld      [%o1+0x44], %o3
F003A9D8: 90100018                 mov     %i0, %o0
F003A9DC: d402a01c                 ld      [%o2+0x1C], %o2
F003A9E0: 9fc2c000                 call    %o3
F003A9E4: 9207bfd8                 add     %fp, var_28, %o1
F003A9E8: b4920000                 orcc    %o0, %g0, %i2
F003A9EC: 02800008                 be      loc_F003AA0C
F003A9F0: d007bfec                 ld      [%fp+var_14], %o0
F003A9F4: d0066008                 ld      [%i1+8], %o0
F003A9F8: 4000b5ea                 call    _kfree
F003A9FC: 92102400                 mov     0x400, %o1
F003AA00: c0266004                 clr     [%i1+4]
F003AA04: 10800004                 ba      loc_F003AA14
F003AA08: c0266008                 clr     [%i1+8]
F003AA0C: 90240008                 sub     %l0, %o0, %o0
F003AA10: d0266004                 st      %o0, [%i1+4]
F003AA14: f4264000                 st      %i2, [%i1]
F003AA18: 7fffb853                 call    _vn_rele
F003AA1C: 90100018                 mov     %i0, %o0
F003AA20: 81c7e008                 ret
F003AA24: 81e80000                 restore
