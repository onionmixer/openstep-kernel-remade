F00C0170: 9de3bf90                 save    %sp, -0x70, %sp
F00C0174: 9210001c                 mov     %i4, %o1
F00C0178: f8068000                 ld      [%i2], %i4
F00C017C: 9010001d                 mov     %i5, %o0
F00C0180: e206c000                 ld      [%i3], %l1
F00C0184: 80a72000                 cmp     %i4, 0
F00C0188: 16800003                 bge     loc_F00C0194
F00C018C: 9410001c                 mov     %i4, %o2
F00C0190: 9420001c                 neg     %i4, %o2
F00C0194: 80a46000                 cmp     %l1, 0
F00C0198: 16800003                 bge     loc_F00C01A4
F00C019C: a0100011                 mov     %l1, %l0
F00C01A0: a0200011                 neg     %l1, %l0
F00C01A4: 80a26000                 cmp     %o1, 0
F00C01A8: 12800003                 bne     loc_F00C01B4
F00C01AC: 94028010                 add     %o2, %l0, %o2
F00C01B0: 92102002                 mov     2, %o1
F00C01B4: a12aa005                 sll     %o2, 5, %l0
F00C01B8: a024000a                 sub     %l0, %o2, %l0
F00C01BC: 7ffd18d1                 call    _umul
F00C01C0: a12c2001                 sll     %l0, 1, %l0
F00C01C4: 92100008                 mov     %o0, %o1
F00C01C8: 7ffd190e                 call    _udiv
F00C01CC: 90100010                 mov     %l0, %o0
F00C01D0: d256213c                 ldsh    [%i0+0x13C], %o1
F00C01D4: 96100008                 mov     %o0, %o3
F00C01D8: 80a2c009                 cmp     %o3, %o1
F00C01DC: 0880001a                 bleu    locret_F00C0244
F00C01E0: a0102001                 mov     1, %l0
F00C01E4: d4062138                 ld      [%i0+0x138], %o2
F00C01E8: 80a4000a                 cmp     %l0, %o2
F00C01EC: 3680000c                 bge,a   loc_F00C021C
F00C01F0: a0043fff                 inc     -1, %l0
F00C01F4: 92062002                 add     %i0, 2, %o1
F00C01F8: d052613c                 ldsh    [%o1+0x13C], %o0
F00C01FC: 80a2c008                 cmp     %o3, %o0
F00C0200: 28800007                 bleu,a  loc_F00C021C
F00C0204: a0043fff                 inc     -1, %l0
F00C0208: a0042001                 inc     %l0
F00C020C: 80a4000a                 cmp     %l0, %o2
F00C0210: 06bffffa                 bl      loc_F00C01F8
F00C0214: 92026002                 inc     2, %o1
F00C0218: a0043fff                 inc     -1, %l0
F00C021C: a12c2001                 sll     %l0, 1, %l0
F00C0220: a0040018                 add     %l0, %i0, %l0
F00C0224: d2542164                 ldsh    [%l0+0x164], %o1
F00C0228: 7ffd18b6                 call    _umul
F00C022C: 9010001c                 mov     %i4, %o0
F00C0230: d0268000                 st      %o0, [%i2]
F00C0234: d2542164                 ldsh    [%l0+0x164], %o1
F00C0238: 7ffd18b2                 call    _umul
F00C023C: 90100011                 mov     %l1, %o0
F00C0240: d026c000                 st      %o0, [%i3]
F00C0244: 81c7e008                 ret
F00C0248: 81e80000                 restore
