F003FA28: 9de3bf80                 save    %sp, -0x80, %sp
F003FA2C: a0100018                 mov     %i0, %l0
F003FA30: d0042028                 ld      [%l0+0x28], %o0
F003FA34: 80a22005                 cmp     %o0, 5
F003FA38: 12800028                 bne     locret_F003FAD8
F003FA3C: b0102006                 mov     6, %i0
F003FA40: 4000a18c                 call    _kalloc
F003FA44: 90102400                 mov     0x400, %o0
F003FA48: d027bff0                 st      %o0, [%fp+var_10]
F003FA4C: 92102005                 mov     5, %o1
F003FA50: 153c01059412a29c         set     _xdr_fhandle, %o2
F003FA58: 193c0107                 sethi   %hi(_xdr_rdlnres), %o4
F003FA5C: d0042024                 ld      [%l0+0x24], %o0
F003FA60: 981322b0                 bset    %lo(_xdr_rdlnres), %o4
F003FA64: d6042030                 ld      [%l0+0x30], %o3
F003FA68: 9a07bfe8                 add     %fp, var_18, %o5
F003FA6C: d0022128                 ld      [%o0+0x128], %o0
F003FA70: 9602e040                 inc     0x40, %o3 ! '@'
F003FA74: 7ffff340                 call    _rfscall
F003FA78: f423a05c                 st      %i2, [%sp+0x80+var_24]
F003FA7C: b0920000                 orcc    %o0, %g0, %i0
F003FA80: 32800014                 bne,a   loc_F003FAD0
F003FA84: d007bff0                 ld      [%fp+var_10], %o0
F003FA88: f007bfe8                 ld      [%fp+var_18], %i0
F003FA8C: 80a62000                 cmp     %i0, 0
F003FA90: 12800009                 bne     loc_F003FAB4
F003FA94: 80a62046                 cmp     %i0, 0x46 ! 'F'
F003FA98: d007bff0                 ld      [%fp+var_10], %o0
F003FA9C: 94102000                 mov     0, %o2
F003FAA0: d207bfec                 ld      [%fp+var_14], %o1
F003FAA4: 7fff4a1d                 call    _uiomove
F003FAA8: 96100019                 mov     %i1, %o3
F003FAAC: 10800008                 ba      loc_F003FACC
F003FAB0: b0100008                 mov     %o0, %i0
F003FAB4: 12800007                 bne     loc_F003FAD0
F003FAB8: d007bff0                 ld      [%fp+var_10], %o0
F003FABC: 7fff9690                 call    _btrash
F003FAC0: 90100010                 mov     %l0, %o0
F003FAC4: 7fffe6d9                 call    _nfs_invalidate_caches
F003FAC8: 90100010                 mov     %l0, %o0
F003FACC: d007bff0                 ld      [%fp+var_10], %o0
F003FAD0: 4000a1b4                 call    _kfree
F003FAD4: 92102400                 mov     0x400, %o1
F003FAD8: 81c7e008                 ret
F003FADC: 81e80000                 restore
