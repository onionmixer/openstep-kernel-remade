F005CCC0: 9de3bf98                 save    %sp, -0x68, %sp
F005CCC4: e0068000                 ld      [%i2], %l0
F005CCC8: 11000140                 sethi   0x50000, %o0
F005CCCC: 808c0008                 btst    %o0, %l0
F005CCD0: 02800011                 be      loc_F005CD14
F005CCD4: 94100019                 mov     %i1, %o2
F005CCD8: e206a004                 ld      [%i2+4], %l1
F005CCDC: 90100018                 mov     %i0, %o0
F005CCE0: 9610001a                 mov     %i2, %o3
F005CCE4: 7ffffc70                 call    _ipc_right_check
F005CCE8: 92100011                 mov     %l1, %o1
F005CCEC: 80a22000                 cmp     %o0, 0
F005CCF0: 02800008                 be      loc_F005CD10
F005CCF4: 11001000                 sethi   0x400000, %o0
F005CCF8: 808c0008                 btst    %o0, %l0
F005CCFC: 22800006                 be,a    loc_F005CD14
F005CD00: e0068000                 ld      [%i2], %l0
F005CD04: c0262008                 clr     [%i0+8]
F005CD08: 1080001a                 ba      locret_F005CD70
F005CD0C: b010200f                 mov     0xF, %i0
F005CD10: c0244000                 clr     [%l1]
F005CD14: 110007c0                 sethi   0x1F0000, %o0
F005CD18: 920c0008                 and     %l0, %o0, %o1
F005CD1C: 11001000                 sethi   0x400000, %o0
F005CD20: 808c0008                 btst    %o0, %l0
F005CD24: 02800004                 be      loc_F005CD34
F005CD28: d606a008                 ld      [%i2+8], %o3
F005CD2C: 10800005                 ba      loc_F005CD40
F005CD30: 11080000                 sethi   0x20000000, %o0
F005CD34: 80a2e000                 cmp     %o3, 0
F005CD38: 02800003                 be      loc_F005CD44
F005CD3C: 11200000                 sethi   0x80000000, %o0
F005CD40: 92124008                 bset    %o0, %o1
F005CD44: 11000800                 sethi   0x200000, %o0
F005CD48: 808c0008                 btst    %o0, %l0
F005CD4C: 02800003                 be      loc_F005CD58
F005CD50: 11100000                 sethi   0x40000000, %o0
F005CD54: 92124008                 bset    %o0, %o1
F005CD58: d226c000                 st      %o1, [%i3]
F005CD5C: 1100003f901223ff         set     0xFFFF, %o0
F005CD64: 900c0008                 and     %l0, %o0, %o0
F005CD68: d0270000                 st      %o0, [%i4]
F005CD6C: b0102000                 mov     0, %i0
F005CD70: 81c7e008                 ret
F005CD74: 81e80000                 restore
