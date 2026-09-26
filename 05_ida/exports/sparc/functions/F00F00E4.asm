F00F00E4: 9de3bf98                 save    %sp, -0x68, %sp
F00F00E8: e0062020                 ld      [%i0+0x20], %l0
F00F00EC: e2040000                 ld      [%l0], %l1
F00F00F0: d0042004                 ld      [%l0+4], %o0
F00F00F4: 96022001                 add     %o0, 1, %o3
F00F00F8: 952ae002                 sll     %o3, 2, %o2
F00F00FC: 92046001                 add     %l1, 1, %o1
F00F0100: 912a6001                 sll     %o1, 1, %o0
F00F0104: 90020009                 add     %o0, %o1, %o0
F00F0108: 80a28008                 cmp     %o2, %o0
F00F010C: 08800012                 bleu    loc_F00F0154
F00F0110: e4064000                 ld      [%i1], %l2
F00F0114: d0062010                 ld      [%i0+0x10], %o0
F00F0118: 808a2020                 btst    0x20, %o0 ! ' '
F00F011C: 02800006                 be      loc_F00F0134
F00F0120: 01000000                 nop
F00F0124: 4000001a                 call    sub_F00F018C
F00F0128: 90100018                 mov     %i0, %o0
F00F012C: 10800007                 ba      loc_F00F0148
F00F0130: d0042004                 ld      [%l0+4], %o0
F00F0134: 7fffff45                 call    sub_F00EFE48
F00F0138: 90100018                 mov     %i0, %o0
F00F013C: a0100008                 mov     %o0, %l0
F00F0140: e2040000                 ld      [%l0], %l1
F00F0144: d0042004                 ld      [%l0+4], %o0
F00F0148: 90022001                 inc     %o0
F00F014C: 10800003                 ba      loc_F00F0158
F00F0150: d0242004                 st      %o0, [%l0+4]
F00F0154: d6242004                 st      %o3, [%l0+4]
F00F0158: 96042008                 add     %l0, 8, %o3
F00F015C: 920c8011                 and     %l2, %l1, %o1
F00F0160: 912a6002                 sll     %o1, 2, %o0
F00F0164: d402c008                 ld      [%o3+%o0], %o2
F00F0168: 80a2a000                 cmp     %o2, 0
F00F016C: 02800006                 be      locret_F00F0184
F00F0170: f222c008                 st      %i1, [%o3+%o0]
F00F0174: b210000a                 mov     %o2, %i1
F00F0178: 92026001                 inc     %o1
F00F017C: 10bffff9                 ba      loc_F00F0160
F00F0180: 920a4011                 and     %o1, %l1, %o1
F00F0184: 81c7e008                 ret
F00F0188: 81e80000                 restore
