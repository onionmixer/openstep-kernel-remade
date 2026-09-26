F001F978: 9de3bf80                 save    %sp, -0x80, %sp
F001F97C: d0162038                 lduh    [%i0+0x38], %o0
F001F980: a0062024                 add     %i0, 0x24, %l0 ! '$'
F001F984: 808a2001                 btst    1, %o0
F001F988: 0280000c                 be      loc_F001F9B8
F001F98C: e406200c                 ld      [%i0+0xC], %l2
F001F990: 90042014                 add     %l0, 0x14, %o0! unsigned int
F001F994: d4142014                 lduh    [%l0+0x14], %o2
F001F998: 9210201a                 mov     0x1A, %o1
F001F99C: 9412a002                 bset    2, %o2
F001F9A0: 7fffcb36                 call    _sleep
F001F9A4: d4342014                 sth     %o2, [%l0+0x14]
F001F9A8: d0142014                 lduh    [%l0+0x14], %o0
F001F9AC: 808a2001                 btst    1, %o0
F001F9B0: 32bffff9                 bne,a   loc_F001F994
F001F9B4: 90042014                 add     %l0, 0x14, %o0
F001F9B8: d0142014                 lduh    [%l0+0x14], %o0
F001F9BC: 90122001                 bset    1, %o0
F001F9C0: 4001dc7e                 call    _spltty
F001F9C4: d0342014                 sth     %o0, [%l0+0x14]
F001F9C8: a2100008                 mov     %o0, %l1
F001F9CC: 40000251                 call    _socantrcvmore
F001F9D0: 90100018                 mov     %i0, %o0
F001F9D4: d0142014                 lduh    [%l0+0x14], %o0
F001F9D8: 900a3ffe                 and     %o0, -2, %o0
F001F9DC: 808a2002                 btst    2, %o0
F001F9E0: 02800006                 be      loc_F001F9F8
F001F9E4: d0342014                 sth     %o0, [%l0+0x14]
F001F9E8: 900a3ffd                 and     %o0, -3, %o0
F001F9EC: d0342014                 sth     %o0, [%l0+0x14]
F001F9F0: 7fffccfe                 call    _wakeup
F001F9F4: 90042014                 add     %l0, 0x14, %o0
F001F9F8: d0040000                 ld      [%l0], %o0
F001F9FC: d027bfe0                 st      %o0, [%fp+var_20]
F001FA00: d0042004                 ld      [%l0+4], %o0
F001FA04: d027bfe4                 st      %o0, [%fp+var_1C]
F001FA08: d0042008                 ld      [%l0+8], %o0
F001FA0C: d027bfe8                 st      %o0, [%fp+var_18]
F001FA10: d004200c                 ld      [%l0+0xC], %o0
F001FA14: d027bfec                 st      %o0, [%fp+var_14]
F001FA18: d2042010                 ld      [%l0+0x10], %o1
F001FA1C: 90100010                 mov     %l0, %o0! void *
F001FA20: d227bff0                 st      %o1, [%fp+var_10]
F001FA24: d4022014                 ld      [%o0+0x14], %o2
F001FA28: 92102018                 mov     0x18, %o1! size_t
F001FA2C: 4001d50b                 call    _bzero
F001FA30: d427bff4                 st      %o2, [%fp+var_C]
F001FA34: 4001dcbc                 call    _splx
F001FA38: 90100011                 mov     %l1, %o0
F001FA3C: d014a00a                 lduh    [%l2+0xA], %o0
F001FA40: 808a2010                 btst    0x10, %o0
F001FA44: 02800009                 be      loc_F001FA68
F001FA48: 01000000                 nop
F001FA4C: d004a004                 ld      [%l2+4], %o0
F001FA50: d2022010                 ld      [%o0+0x10], %o1
F001FA54: 80a26000                 cmp     %o1, 0
F001FA58: 02800004                 be      loc_F001FA68
F001FA5C: 01000000                 nop
F001FA60: 9fc24000                 call    %o1
F001FA64: d007bfec                 ld      [%fp+var_14], %o0
F001FA68: 400002a8                 call    _sbrelease
F001FA6C: 9007bfe0                 add     %fp, var_20, %o0
F001FA70: 81c7e008                 ret
F001FA74: 81e80000                 restore
