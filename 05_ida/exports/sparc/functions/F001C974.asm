F001C974: 9de3bf98                 save    %sp, -0x68, %sp
F001C978: 4001e890                 call    _spltty
F001C97C: a0100018                 mov     %i0, %l0
F001C980: d2040000                 ld      [%l0], %o1
F001C984: 80a26000                 cmp     %o1, 0
F001C988: 14800006                 bg      loc_F001C9A0
F001C98C: 96100008                 mov     %o0, %o3
F001C990: 1080001a                 ba      loc_F001C9F8
F001C994: b0200009                 neg     %o1, %i0
F001C998: 10800018                 ba      loc_F001C9F8
F001C99C: b0224008                 sub     %o1, %o0, %i0
F001C9A0: d4042004                 ld      [%l0+4], %o2
F001C9A4: 9002a034                 add     %o2, 0x34, %o0 ! '4'
F001C9A8: b00a3fc0                 and     %o0, -0x40, %i0
F001C9AC: b026000a                 sub     %i0, %o2, %i0
F001C9B0: 80a24018                 cmp     %o1, %i0
F001C9B4: 26800002                 bl,a    loc_F001C9BC
F001C9B8: b0100009                 mov     %o1, %i0
F001C9BC: 80a66000                 cmp     %i1, 0
F001C9C0: 0280000e                 be      loc_F001C9F8
F001C9C4: 9210000a                 mov     %o2, %o1
F001C9C8: 94024018                 add     %o1, %i0, %o2
F001C9CC: 80a2400a                 cmp     %o1, %o2
F001C9D0: 1a80000a                 bcc     loc_F001C9F8
F001C9D4: 01000000                 nop
F001C9D8: d04a4000                 ldsb    [%o1], %o0
F001C9DC: 808a0019                 btst    %i1, %o0
F001C9E0: 32bfffee                 bne,a   loc_F001C998
F001C9E4: d0042004                 ld      [%l0+4], %o0
F001C9E8: 92026001                 inc     %o1
F001C9EC: 80a2400a                 cmp     %o1, %o2
F001C9F0: 2abffffb                 bcs,a   loc_F001C9DC
F001C9F4: d04a4000                 ldsb    [%o1], %o0
F001C9F8: 4001e8cb                 call    _splx
F001C9FC: 9010000b                 mov     %o3, %o0
F001CA00: 81c7e008                 ret
F001CA04: 81e80000                 restore
