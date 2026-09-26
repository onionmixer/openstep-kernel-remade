F0069BB8: 9de3bf90                 save    %sp, -0x70, %sp
F0069BBC: 80a62000                 cmp     %i0, 0
F0069BC0: 32800004                 bne,a   loc_F0069BD0
F0069BC4: d4064000                 ld      [%i1], %o2
F0069BC8: 10800040                 ba      locret_F0069CC8
F0069BCC: b0102016                 mov     0x16, %i0
F0069BD0: 932aa005                 sll     %o2, 5, %o1
F0069BD4: 9222400a                 sub     %o1, %o2, %o1
F0069BD8: 912a6006                 sll     %o1, 6, %o0
F0069BDC: 90220009                 sub     %o0, %o1, %o0
F0069BE0: 912a2003                 sll     %o0, 3, %o0
F0069BE4: 9002000a                 add     %o0, %o2, %o0
F0069BE8: d2066004                 ld      [%i1+4], %o1
F0069BEC: 912a2006                 sll     %o0, 6, %o0! int
F0069BF0: 4000b3e6                 call    _splusclock
F0069BF4: b0020009                 add     %o0, %o1, %i0
F0069BF8: 230003d092146240         set     0xF4240, %o1! int
F0069C00: 153c043e                 sethi   %hi(_timedelta), %o2
F0069C04: e002a3f0                 ld      [%o2+%lo(_timedelta)], %l0
F0069C08: b2100008                 mov     %o0, %i1
F0069C0C: 7ffe727f                 call    _div
F0069C10: 90100010                 mov     %l0, %o0
F0069C14: d027bff0                 st      %o0, [%fp+var_10]
F0069C18: 90100010                 mov     %l0, %o0
F0069C1C: 7ffe7323                 call    _rem
F0069C20: 92146240                 or      %l1, 0x240, %o1
F0069C24: 80a42000                 cmp     %l0, 0
F0069C28: 12800011                 bne     loc_F0069C6C
F0069C2C: d027bff4                 st      %o0, [%fp+var_C]
F0069C30: 113c043e                 sethi   %hi(_bigadj), %o0
F0069C34: d00223fc                 ld      [%o0+%lo(_bigadj)], %o0
F0069C38: 80a60008                 cmp     %i0, %o0
F0069C3C: 08800009                 bleu    loc_F0069C60
F0069C40: 113c043e                 sethi   %hi(_tickadj), %o0
F0069C44: d20223f8                 ld      [%o0+%lo(_tickadj)], %o1
F0069C48: 912a6002                 sll     %o1, 2, %o0
F0069C4C: 90020009                 add     %o0, %o1, %o0
F0069C50: 912a2001                 sll     %o0, 1, %o0
F0069C54: 133c043e                 sethi   %hi(_tickdelta), %o1
F0069C58: 10800005                 ba      loc_F0069C6C
F0069C5C: d02263f4                 st      %o0, [%o1+%lo(_tickdelta)]
F0069C60: d20223f8                 ld      [%o0+0x3F8], %o1
F0069C64: 113c043e                 sethi   %hi(_tickdelta), %o0
F0069C68: d22223f4                 st      %o1, [%o0+%lo(_tickdelta)]
F0069C6C: 113c043e                 sethi   %hi(_tickdelta), %o0
F0069C70: e00223f4                 ld      [%o0+%lo(_tickdelta)], %l0
F0069C74: 90100018                 mov     %i0, %o0
F0069C78: 7ffe730a                 call    _urem
F0069C7C: 92100010                 mov     %l0, %o1
F0069C80: 80a22000                 cmp     %o0, 0
F0069C84: 22800009                 be,a    loc_F0069CA8
F0069C88: 113c043e                 sethi   -0xFEF0800, %o0
F0069C8C: 90100018                 mov     %i0, %o0
F0069C90: 7ffe725c                 call    _udiv
F0069C94: 92100010                 mov     %l0, %o1
F0069C98: 7ffe721a                 call    _umul
F0069C9C: 92100010                 mov     %l0, %o1
F0069CA0: b0100008                 mov     %o0, %i0
F0069CA4: 113c043e                 sethi   -0xFEF0800, %o0
F0069CA8: f02223f0                 st      %i0, [%o0+0x3F0]
F0069CAC: 4000b41e                 call    _splx
F0069CB0: 90100019                 mov     %i1, %o0
F0069CB4: d007bff0                 ld      [%fp+var_10], %o0
F0069CB8: d0268000                 st      %o0, [%i2]
F0069CBC: d007bff4                 ld      [%fp+var_C], %o0
F0069CC0: b0102000                 mov     0, %i0
F0069CC4: d026a004                 st      %o0, [%i2+4]
F0069CC8: 81c7e008                 ret
F0069CCC: 81e80000                 restore
