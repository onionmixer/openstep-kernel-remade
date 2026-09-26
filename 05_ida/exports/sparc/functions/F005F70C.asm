F005F70C: 9de3bf90                 save    %sp, -0x70, %sp
F005F710: 90100018                 mov     %i0, %o0
F005F714: 92100019                 mov     %i1, %o1
F005F718: 7ffff0d9                 call    _ipc_right_lookup_write
F005F71C: 9407bff4                 add     %fp, var_C, %o2
F005F720: 80a22000                 cmp     %o0, 0
F005F724: 02800004                 be      loc_F005F734
F005F728: d407bff4                 ld      [%fp+var_C], %o2
F005F72C: 10800022                 ba      locret_F005F7B4
F005F730: b0100008                 mov     %o0, %i0
F005F734: d2028000                 ld      [%o2], %o1
F005F738: 110000c0                 sethi   0x30000, %o0
F005F73C: 808a4008                 btst    %o0, %o1
F005F740: 32800005                 bne,a   loc_F005F754
F005F744: f202a004                 ld      [%o2+4], %i1
F005F748: c0262008                 clr     [%i0+8]
F005F74C: 1080001a                 ba      locret_F005F7B4
F005F750: b0102011                 mov     0x11, %i0
F005F754: d0064000                 ld      [%i1], %o0
F005F758: 80a22000                 cmp     %o0, 0
F005F75C: 12bffffe                 bne     loc_F005F754
F005F760: 01000000                 nop
F005F764: 4000ddd1                 call    _simple_lock_try
F005F768: 90100019                 mov     %i1, %o0
F005F76C: 80a22000                 cmp     %o0, 0
F005F770: 02bffff9                 be      loc_F005F754
F005F774: 01000000                 nop
F005F778: c0262008                 clr     [%i0+8]
F005F77C: d2066008                 ld      [%i1+8], %o1
F005F780: 80a26000                 cmp     %o1, 0
F005F784: 1680000a                 bge     loc_F005F7AC
F005F788: 1100003f                 sethi   0xFC00, %o0
F005F78C: 901223ff                 bset    0x3FF, %o0
F005F790: 900a4008                 and     %o1, %o0, %o0
F005F794: d0268000                 st      %o0, [%i2]
F005F798: d0066014                 ld      [%i1+0x14], %o0
F005F79C: d026c000                 st      %o0, [%i3]
F005F7A0: c0264000                 clr     [%i1]
F005F7A4: 10800004                 ba      locret_F005F7B4
F005F7A8: b0102000                 mov     0, %i0
F005F7AC: c0264000                 clr     [%i1]
F005F7B0: b0102011                 mov     0x11, %i0
F005F7B4: 81c7e008                 ret
F005F7B8: 81e80000                 restore
