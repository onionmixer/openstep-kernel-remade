F00EEA94: 9de3bf88                 save    %sp, -0x78, %sp
F00EEA98: e406200c                 ld      [%i0+0xC], %l2
F00EEA9C: d0060000                 ld      [%i0], %o0
F00EEAA0: d4020000                 ld      [%o0], %o2
F00EEAA4: 90100018                 mov     %i0, %o0
F00EEAA8: 9fc28000                 call    %o2
F00EEAAC: 92100019                 mov     %i1, %o1
F00EEAB0: 94100008                 mov     %o0, %o2
F00EEAB4: 1300003f921263ff         set     0xFFFF, %o1
F00EEABC: 920a8009                 and     %o2, %o1, %o1
F00EEAC0: 9132a010                 srl     %o2, 16, %o0
F00EEAC4: 921a4008                 btog    %o0, %o1
F00EEAC8: 912a600c                 sll     %o1, 12, %o0
F00EEACC: 90220009                 sub     %o0, %o1, %o0
F00EEAD0: 912a2004                 sll     %o0, 4, %o0
F00EEAD4: 90020009                 add     %o0, %o1, %o0
F00EEAD8: 9002000a                 add     %o0, %o2, %o0
F00EEADC: 7ffc5f71                 call    _urem
F00EEAE0: d2062008                 ld      [%i0+8], %o1
F00EEAE4: a6100008                 mov     %o0, %l3
F00EEAE8: 912ce003                 sll     %l3, 3, %o0
F00EEAEC: 80a67fff                 cmp     %i1, -1
F00EEAF0: 12800005                 bne     loc_F00EEB04
F00EEAF4: a2048008                 add     %l2, %o0, %l1
F00EEAF8: 113c03f4                 sethi   %hi(aNxmapinsertInv), %o0! "*** NXMapInsert: invalid key: -1\n"
F00EEAFC: 10800082                 ba      loc_F00EED04
F00EEB00: 90122028                 bset    %lo(aNxmapinsertInv), %o0! "*** NXMapInsert: invalid key: -1\n"
F00EEB04: 113c04bc                 sethi   %hi(dword_F012F0C0), %o0
F00EEB08: d20220c0                 ld      [%o0+%lo(dword_F012F0C0)], %o1
F00EEB0C: 92026001                 inc     %o1
F00EEB10: d22220c0                 st      %o1, [%o0+%lo(dword_F012F0C0)]
F00EEB14: d0044000                 ld      [%l1], %o0
F00EEB18: 80a23fff                 cmp     %o0, -1
F00EEB1C: 3280000c                 bne,a   loc_F00EEB4C
F00EEB20: d2044000                 ld      [%l1], %o1
F00EEB24: 113c04bc                 sethi   %hi(dword_F012F0C4), %o0
F00EEB28: d20220c4                 ld      [%o0+%lo(dword_F012F0C4)], %o1
F00EEB2C: 92026001                 inc     %o1
F00EEB30: d22220c4                 st      %o1, [%o0+%lo(dword_F012F0C4)]
F00EEB34: f2244000                 st      %i1, [%l1]
F00EEB38: f4246004                 st      %i2, [%l1+4]
F00EEB3C: d0062004                 ld      [%i0+4], %o0
F00EEB40: 90022001                 inc     %o0
F00EEB44: 10800072                 ba      loc_F00EED0C
F00EEB48: d0262004                 st      %o0, [%i0+4]
F00EEB4C: 80a24019                 cmp     %o1, %i1
F00EEB50: 02800009                 be      loc_F00EEB74
F00EEB54: 90102001                 mov     1, %o0
F00EEB58: d0060000                 ld      [%i0], %o0
F00EEB5C: d6022004                 ld      [%o0+4], %o3
F00EEB60: 90100018                 mov     %i0, %o0
F00EEB64: 9fc2c000                 call    %o3
F00EEB68: 94100019                 mov     %i1, %o2
F00EEB6C: 10800003                 ba      loc_F00EEB78
F00EEB70: 80a22000                 cmp     %o0, 0
F00EEB74: 80a22000                 cmp     %o0, 0
F00EEB78: 0280000a                 be      loc_F00EEBA0
F00EEB7C: 133c04bc                 sethi   %hi(dword_F012F0C4), %o1
F00EEB80: f0046004                 ld      [%l1+4], %i0
F00EEB84: d00260c4                 ld      [%o1+%lo(dword_F012F0C4)], %o0
F00EEB88: 90022001                 inc     %o0
F00EEB8C: d02260c4                 st      %o0, [%o1+%lo(dword_F012F0C4)]
F00EEB90: 80a6001a                 cmp     %i0, %i2
F00EEB94: 3280005f                 bne,a   locret_F00EED10
F00EEB98: f4246004                 st      %i2, [%l1+4]
F00EEB9C: 3080005d                 ba,a    locret_F00EED10
F00EEBA0: d2062004                 ld      [%i0+4], %o1
F00EEBA4: d0062008                 ld      [%i0+8], %o0
F00EEBA8: 80a24008                 cmp     %o1, %o0
F00EEBAC: 12800006                 bne     loc_F00EEBC4
F00EEBB0: a0100013                 mov     %l3, %l0
F00EEBB4: 7fffff7f                 call    sub_F00EE9B0
F00EEBB8: 90100018                 mov     %i0, %o0
F00EEBBC: 10bfffb8                 ba      loc_F00EEA9C
F00EEBC0: e406200c                 ld      [%i0+0xC], %l2
F00EEBC4: 293c04bc                 sethi   -0xFED1000, %l4
F00EEBC8: 92042001                 add     %l0, 1, %o1
F00EEBCC: d0062008                 ld      [%i0+8], %o0
F00EEBD0: 80a24008                 cmp     %o1, %o0
F00EEBD4: 1a800003                 bcc     loc_F00EEBE0
F00EEBD8: 90102000                 mov     0, %o0
F00EEBDC: 90100009                 mov     %o1, %o0
F00EEBE0: a0100008                 mov     %o0, %l0
F00EEBE4: 80a40013                 cmp     %l0, %l3
F00EEBE8: 02800045                 be      loc_F00EECFC
F00EEBEC: d00520c8                 ld      [%l4+0xC8], %o0
F00EEBF0: 90022001                 inc     %o0
F00EEBF4: d02520c8                 st      %o0, [%l4+0xC8]
F00EEBF8: 912c2003                 sll     %l0, 3, %o0
F00EEBFC: a2048008                 add     %l2, %o0, %l1
F00EEC00: d0048008                 ld      [%l2+%o0], %o0
F00EEC04: 80a23fff                 cmp     %o0, -1
F00EEC08: 3280002e                 bne,a   loc_F00EECC0
F00EEC0C: d2044000                 ld      [%l1], %o1
F00EEC10: f227bff0                 st      %i1, [%fp+var_10]
F00EEC14: f427bff4                 st      %i2, [%fp+var_C]
F00EEC18: 80a67fff                 cmp     %i1, -1
F00EEC1C: 0280001b                 be      loc_F00EEC88
F00EEC20: a0100013                 mov     %l3, %l0
F00EEC24: 932c2003                 sll     %l0, 3, %o1
F00EEC28: a2048009                 add     %l2, %o1, %l1
F00EEC2C: d0048009                 ld      [%l2+%o1], %o0
F00EEC30: d027bfe8                 st      %o0, [%fp+var_18]
F00EEC34: d0046004                 ld      [%l1+4], %o0
F00EEC38: d027bfec                 st      %o0, [%fp+var_14]
F00EEC3C: d007bff0                 ld      [%fp+var_10], %o0
F00EEC40: d0248009                 st      %o0, [%l2+%o1]
F00EEC44: d007bff4                 ld      [%fp+var_C], %o0
F00EEC48: d0246004                 st      %o0, [%l1+4]
F00EEC4C: d007bfe8                 ld      [%fp+var_18], %o0
F00EEC50: d027bff0                 st      %o0, [%fp+var_10]
F00EEC54: d007bfec                 ld      [%fp+var_14], %o0
F00EEC58: d027bff4                 st      %o0, [%fp+var_C]
F00EEC5C: 92042001                 add     %l0, 1, %o1
F00EEC60: d0062008                 ld      [%i0+8], %o0
F00EEC64: 80a24008                 cmp     %o1, %o0
F00EEC68: 1a800003                 bcc     loc_F00EEC74
F00EEC6C: 90102000                 mov     0, %o0
F00EEC70: 90100009                 mov     %o1, %o0
F00EEC74: a0100008                 mov     %o0, %l0
F00EEC78: d007bff0                 ld      [%fp+var_10], %o0
F00EEC7C: 80a23fff                 cmp     %o0, -1
F00EEC80: 12bfffea                 bne     loc_F00EEC28
F00EEC84: 932c2003                 sll     %l0, 3, %o1
F00EEC88: d0062004                 ld      [%i0+4], %o0
F00EEC8C: 90022001                 inc     %o0
F00EEC90: d0262004                 st      %o0, [%i0+4]
F00EEC94: 912a2002                 sll     %o0, 2, %o0
F00EEC98: d4062008                 ld      [%i0+8], %o2
F00EEC9C: 932aa001                 sll     %o2, 1, %o1
F00EECA0: 9202400a                 add     %o1, %o2, %o1
F00EECA4: 80a20009                 cmp     %o0, %o1
F00EECA8: 2880001a                 bleu,a  locret_F00EED10
F00EECAC: b0102000                 mov     0, %i0
F00EECB0: 7fffff40                 call    sub_F00EE9B0
F00EECB4: 90100018                 mov     %i0, %o0
F00EECB8: 10800016                 ba      locret_F00EED10
F00EECBC: b0102000                 mov     0, %i0
F00EECC0: 80a24019                 cmp     %o1, %i1
F00EECC4: 02800009                 be      loc_F00EECE8
F00EECC8: 90102001                 mov     1, %o0
F00EECCC: d0060000                 ld      [%i0], %o0
F00EECD0: d6022004                 ld      [%o0+4], %o3
F00EECD4: 90100018                 mov     %i0, %o0
F00EECD8: 9fc2c000                 call    %o3
F00EECDC: 94100019                 mov     %i1, %o2
F00EECE0: 10800003                 ba      loc_F00EECEC
F00EECE4: 80a22000                 cmp     %o0, 0
F00EECE8: 80a22000                 cmp     %o0, 0
F00EECEC: 02bfffb8                 be      loc_F00EEBCC
F00EECF0: 92042001                 add     %l0, 1, %o1
F00EECF4: 10bfffa7                 ba      loc_F00EEB90
F00EECF8: f0046004                 ld      [%l1+4], %i0
F00EECFC: 113c03f490122050         set     aNxmapinsertBug, %o0! "**** NXMapInsert: bug\n"
F00EED04: 40000711                 call    __NXLogError
F00EED08: 01000000                 nop
F00EED0C: b0102000                 mov     0, %i0
F00EED10: 81c7e008                 ret
F00EED14: 81e80000                 restore
