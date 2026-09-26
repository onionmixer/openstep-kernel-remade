F001CB50: 9de3bf98                 save    %sp, -0x68, %sp
F001CB54: 4001e819                 call    _spltty
F001CB58: 01000000                 nop
F001CB5C: d8066008                 ld      [%i1+8], %o4
F001CB60: 80a32000                 cmp     %o4, 0
F001CB64: 02800006                 be      loc_F001CB7C
F001CB68: a2100008                 mov     %o0, %l1
F001CB6C: d0064000                 ld      [%i1], %o0
F001CB70: 80a22000                 cmp     %o0, 0
F001CB74: 16800013                 bge     loc_F001CBC0
F001CB78: 808b203f                 btst    0x3F, %o4 ! '?'
F001CB7C: 193c043c                 sethi   %hi(_cfreelist), %o4
F001CB80: e003238c                 ld      [%o4+%lo(_cfreelist)], %l0
F001CB84: 80a42000                 cmp     %l0, 0
F001CB88: 02800015                 be      loc_F001CBDC
F001CB8C: 90042004                 add     %l0, 4, %o0! void *
F001CB90: d6040000                 ld      [%l0], %o3
F001CB94: 153c043c                 sethi   %hi(_cfreecount), %o2
F001CB98: d202a390                 ld      [%o2+%lo(_cfreecount)], %o1
F001CB9C: d623238c                 st      %o3, [%o4+%lo(_cfreelist)]
F001CBA0: 92027fcc                 inc     -0x34, %o1! size_t
F001CBA4: d222a390                 st      %o1, [%o2+%lo(_cfreecount)]
F001CBA8: c0240000                 clr     [%l0]
F001CBAC: 4001e0ab                 call    _bzero
F001CBB0: 92102008                 mov     8, %o1
F001CBB4: 9804200c                 add     %l0, 0xC, %o4
F001CBB8: 10800016                 ba      loc_F001CC10
F001CBBC: d8266004                 st      %o4, [%i1+4]
F001CBC0: 12800015                 bne     loc_F001CC14
F001CBC4: 808e2100                 btst    0x100, %i0
F001CBC8: 173c043c                 sethi   %hi(_cfreelist), %o3
F001CBCC: d002e38c                 ld      [%o3+%lo(_cfreelist)], %o0
F001CBD0: 80a22000                 cmp     %o0, 0
F001CBD4: 12800006                 bne     loc_F001CBEC
F001CBD8: d0233fc0                 st      %o0, [%o4-0x40]
F001CBDC: 4001e852                 call    _splx
F001CBE0: 90100011                 mov     %l1, %o0
F001CBE4: 10800024                 ba      locret_F001CC74
F001CBE8: b0103fff                 mov     -1, %i0
F001CBEC: a0100008                 mov     %o0, %l0
F001CBF0: 9804200c                 add     %l0, 0xC, %o4
F001CBF4: d4040000                 ld      [%l0], %o2
F001CBF8: 133c043c                 sethi   %hi(_cfreecount), %o1
F001CBFC: d0026390                 ld      [%o1+%lo(_cfreecount)], %o0
F001CC00: d422e38c                 st      %o2, [%o3+0x38C]
F001CC04: 90023fcc                 inc     -0x34, %o0
F001CC08: d0226390                 st      %o0, [%o1+%lo(_cfreecount)]
F001CC0C: c0240000                 clr     [%l0]
F001CC10: 808e2100                 btst    0x100, %i0
F001CC14: 0280000f                 be      loc_F001CC50
F001CC18: 900b203f                 and     %o4, 0x3F, %o0
F001CC1C: 94920000                 orcc    %o0, %g0, %o2
F001CC20: 16800003                 bge     loc_F001CC2C
F001CC24: 920b3fc0                 and     %o4, -0x40, %o1
F001CC28: 94022007                 add     %o0, 7, %o2
F001CC2C: 953aa003                 sra     %o2, 3, %o2
F001CC30: 96028009                 add     %o2, %o1, %o3
F001CC34: 952aa003                 sll     %o2, 3, %o2
F001CC38: 9422000a                 sub     %o0, %o2, %o2
F001CC3C: 90102001                 mov     1, %o0
F001CC40: d20ae004                 ldub    [%o3+4], %o1
F001CC44: 912a000a                 sll     %o0, %o2, %o0
F001CC48: 92124008                 bset    %o0, %o1
F001CC4C: d22ae004                 stb     %o1, [%o3+4]
F001CC50: f02b0000                 stb     %i0, [%o4]
F001CC54: 98032001                 inc     %o4
F001CC58: d8266008                 st      %o4, [%i1+8]
F001CC5C: d2064000                 ld      [%i1], %o1
F001CC60: 90100011                 mov     %l1, %o0
F001CC64: 92026001                 inc     %o1
F001CC68: 4001e82f                 call    _splx
F001CC6C: d2264000                 st      %o1, [%i1]
F001CC70: b0102000                 mov     0, %i0
F001CC74: 81c7e008                 ret
F001CC78: 81e80000                 restore
