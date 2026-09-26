F00290B4: 9de3bf80                 save    %sp, -0x80, %sp
F00290B8: a0100018                 mov     %i0, %l0
F00290BC: c027bfe0                 clr     [%fp+var_20]
F00290C0: c027bfe4                 clr     [%fp+var_1C]
F00290C4: 90100019                 mov     %i1, %o0
F00290C8: 9210001a                 mov     %i2, %o1
F00290CC: b207bfe8                 add     %fp, var_18, %i1
F00290D0: 7ffff87a                 call    _pn_get
F00290D4: 94100019                 mov     %i1, %o2
F00290D8: b0920000                 orcc    %o0, %g0, %i0
F00290DC: 12800033                 bne     locret_F00291A8
F00290E0: 90100010                 mov     %l0, %o0
F00290E4: 9210001a                 mov     %i2, %o1
F00290E8: 94102001                 mov     1, %o2
F00290EC: 96102000                 mov     0, %o3
F00290F0: 7ffff635                 call    _lookupname
F00290F4: 9807bfe4                 add     %fp, var_1C, %o4
F00290F8: b0920000                 orcc    %o0, %g0, %i0
F00290FC: 1280001d                 bne     loc_F0029170
F0029100: 90100019                 mov     %i1, %o0
F0029104: 92102001                 mov     1, %o1
F0029108: 9407bfe0                 add     %fp, var_20, %o2
F002910C: 7ffff640                 call    _lookuppn
F0029110: 96102000                 mov     0, %o3
F0029114: b0920000                 orcc    %o0, %g0, %i0
F0029118: 12800016                 bne     loc_F0029170
F002911C: d807bfe4                 ld      [%fp+var_1C], %o4
F0029120: da07bfe0                 ld      [%fp+var_20], %o5
F0029124: d2032024                 ld      [%o4+0x24], %o1
F0029128: d0036024                 ld      [%o5+0x24], %o0
F002912C: 80a24008                 cmp     %o1, %o0
F0029130: 12800010                 bne     loc_F0029170
F0029134: b0102012                 mov     0x12, %i0
F0029138: d002600c                 ld      [%o1+0xC], %o0
F002913C: 808a2001                 btst    1, %o0
F0029140: 1280000c                 bne     loc_F0029170
F0029144: b010201e                 mov     0x1E, %i0
F0029148: 113c04cf                 sethi   %hi(_active_u), %o0
F002914C: d00221d8                 ld      [%o0+%lo(_active_u)], %o0
F0029150: d602201c                 ld      [%o0+0x1C], %o3
F0029154: d203601c                 ld      [%o5+0x1C], %o1
F0029158: 9010000c                 mov     %o4, %o0
F002915C: d802602c                 ld      [%o1+0x2C], %o4
F0029160: d407bfec                 ld      [%fp+var_14], %o2
F0029164: 9fc30000                 call    %o4
F0029168: 9210000d                 mov     %o5, %o1
F002916C: b0100008                 mov     %o0, %i0
F0029170: 7ffff8de                 call    _pn_free
F0029174: 9007bfe8                 add     %fp, var_18, %o0
F0029178: d007bfe4                 ld      [%fp+var_1C], %o0
F002917C: 80a22000                 cmp     %o0, 0
F0029180: 22800005                 be,a    loc_F0029194
F0029184: d007bfe0                 ld      [%fp+var_20], %o0
F0029188: 7ffffe77                 call    _vn_rele
F002918C: 01000000                 nop
F0029190: d007bfe0                 ld      [%fp+var_20], %o0
F0029194: 80a22000                 cmp     %o0, 0
F0029198: 02800004                 be      locret_F00291A8
F002919C: 01000000                 nop
F00291A0: 7ffffe71                 call    _vn_rele
F00291A4: 01000000                 nop
F00291A8: 81c7e008                 ret
F00291AC: 81e80000                 restore
