F003CC74: 9de3bf98                 save    %sp, -0x68, %sp
F003CC78: 113c0434                 sethi   %hi(_rpfreelist), %o0
F003CC7C: e0022048                 ld      [%o0+%lo(_rpfreelist)], %l0
F003CC80: 80a42000                 cmp     %l0, 0
F003CC84: 02800019                 be      locret_F003CCE8
F003CC88: a2100008                 mov     %o0, %l1
F003CC8C: 273c04d2                 sethi   -0xFECB800, %l3
F003CC90: 253c0434                 sethi   -0xFEF3000, %l2
F003CC94: d0046048                 ld      [%l1+0x48], %o0
F003CC98: d2020000                 ld      [%o0], %o1
F003CC9C: 90100010                 mov     %l0, %o0
F003CCA0: 4000015d                 call    sub_F003D214
F003CCA4: d2246048                 st      %o1, [%l1+0x48]
F003CCA8: 400000e1                 call    _rp_rmhash
F003CCAC: 90100010                 mov     %l0, %o0
F003CCB0: 40000175                 call    _rinactive
F003CCB4: 90100010                 mov     %l0, %o0
F003CCB8: 4000bf3b                 call    _mfs_uncache
F003CCBC: 9004200c                 add     %l0, 0xC, %o0
F003CCC0: d004e250                 ld      [%l3+0x250], %o0
F003CCC4: 4000f143                 call    _zfree
F003CCC8: d204200c                 ld      [%l0+0xC], %o1
F003CCCC: d004a04c                 ld      [%l2+0x4C], %o0
F003CCD0: 4000f140                 call    _zfree
F003CCD4: 92100010                 mov     %l0, %o1
F003CCD8: e0046048                 ld      [%l1+0x48], %l0
F003CCDC: 80a42000                 cmp     %l0, 0
F003CCE0: 12bfffee                 bne     loc_F003CC98
F003CCE4: d0046048                 ld      [%l1+0x48], %o0
F003CCE8: 81c7e008                 ret
F003CCEC: 81e80000                 restore
