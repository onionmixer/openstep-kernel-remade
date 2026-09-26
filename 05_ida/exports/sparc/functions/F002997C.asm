F002997C: 9de3bf98                 save    %sp, -0x68, %sp
F0029980: 113c04d0                 sethi   %hi(_ifnet), %o0
F0029984: e00220b8                 ld      [%o0+%lo(_ifnet)], %l0
F0029988: 80a42000                 cmp     %l0, 0
F002998C: 0280001e                 be      loc_F0029A04
F0029990: a2100018                 mov     %i0, %l1
F0029994: d014200c                 lduh    [%l0+0xC], %o0
F0029998: 808a2010                 btst    0x10, %o0
F002999C: 22800017                 be,a    loc_F00299F8
F00299A0: e004205c                 ld      [%l0+0x5C], %l0
F00299A4: f0042018                 ld      [%l0+0x18], %i0
F00299A8: 80a62000                 cmp     %i0, 0
F00299AC: 22800013                 be,a    loc_F00299F8
F00299B0: e004205c                 ld      [%l0+0x5C], %l0
F00299B4: d2160000                 lduh    [%i0], %o1
F00299B8: d0144000                 lduh    [%l1], %o0
F00299BC: 80a24008                 cmp     %o1, %o0
F00299C0: 3280000a                 bne,a   loc_F00299E8
F00299C4: f0062024                 ld      [%i0+0x24], %i0
F00299C8: 90062012                 add     %i0, 0x12, %o0! void *
F00299CC: 92046002                 add     %l1, 2, %o1! void *
F00299D0: 7fff7163                 call    _bcmp
F00299D4: 9410200e                 mov     0xE, %o2
F00299D8: 80a22000                 cmp     %o0, 0
F00299DC: 0280000b                 be      locret_F0029A08
F00299E0: 01000000                 nop
F00299E4: f0062024                 ld      [%i0+0x24], %i0
F00299E8: 80a62000                 cmp     %i0, 0
F00299EC: 32bffff3                 bne,a   loc_F00299B8
F00299F0: d2160000                 lduh    [%i0], %o1
F00299F4: e004205c                 ld      [%l0+0x5C], %l0
F00299F8: 80a42000                 cmp     %l0, 0
F00299FC: 32bfffe7                 bne,a   loc_F0029998
F0029A00: d014200c                 lduh    [%l0+0xC], %o0
F0029A04: b0102000                 mov     0, %i0
F0029A08: 81c7e008                 ret
F0029A0C: 81e80000                 restore
