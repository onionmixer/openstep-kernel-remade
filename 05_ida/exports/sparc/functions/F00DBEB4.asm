F00DBEB4: 9de3bf88                 save    %sp, -0x78, %sp
F00DBEB8: 7fffa81e                 call    _IOMalloc
F00DBEBC: 90102028                 mov     0x28, %o0 ! '('
F00DBEC0: a0102000                 mov     0, %l0
F00DBEC4: a6102000                 mov     0, %l3
F00DBEC8: a4102000                 mov     0, %l2
F00DBECC: a2100008                 mov     %o0, %l1
F00DBED0: 113c04bb                 sethi   %hi(dword_F012EF3C), %o0
F00DBED4: d002233c                 ld      [%o0+%lo(dword_F012EF3C)], %o0! id
F00DBED8: 133c0504                 sethi   %hi(paUnlock), %o1
F00DBEDC: d2026244                 ld      [%o1+%lo(paUnlock)], %o1! SEL
F00DBEE0: 153c04bb                 sethi   %hi(dword_F012EF38), %o2
F00DBEE4: ea02a338                 ld      [%o2+%lo(dword_F012EF38)], %l5
F00DBEE8: 40005662                 call    _objc_msgSend
F00DBEEC: 293c0505                 sethi   -0xFEBEC00, %l4
F00DBEF0: 110003d0ac122240         set     0xF4240, %l6
F00DBEF8: ea24600c                 st      %l5, [%l1+0xC]
F00DBEFC: 90102028                 mov     0x28, %o0 ! '('
F00DBF00: 80a42000                 cmp     %l0, 0
F00DBF04: 04800006                 ble     loc_F00DBF1C
F00DBF08: d0246004                 st      %o0, [%l1+4]
F00DBF0C: 90100011                 mov     %l1, %o0
F00DBF10: 92102100                 mov     0x100, %o1
F00DBF14: 10800005                 ba      loc_F00DBF28
F00DBF18: 94100010                 mov     %l0, %o2
F00DBF1C: 90100011                 mov     %l1, %o0
F00DBF20: 92102000                 mov     0, %o1
F00DBF24: 94102000                 mov     0, %o2
F00DBF28: 7ffe27cd                 call    _msg_receive
F00DBF2C: 01000000                 nop
F00DBF30: 80a23f35                 cmp     %o0, -0xCB
F00DBF34: 0280002c                 be      loc_F00DBFE4
F00DBF38: 80a22000                 cmp     %o0, 0
F00DBF3C: 12800031                 bne     loc_F00DC000
F00DBF40: 01000000                 nop
F00DBF44: d0046014                 ld      [%l1+0x14], %o0
F00DBF48: 80a22000                 cmp     %o0, 0
F00DBF4C: 1280002d                 bne     loc_F00DC000
F00DBF50: 01000000                 nop
F00DBF54: e604601c                 ld      [%l1+0x1C], %l3
F00DBF58: d2046024                 ld      [%l1+0x24], %o1
F00DBF5C: e4046020                 ld      [%l1+0x20], %l2
F00DBF60: d0024000                 ld      [%o1], %o0
F00DBF64: d027bfe8                 st      %o0, [%fp+var_18]
F00DBF68: d2026004                 ld      [%o1+4], %o1
F00DBF6C: 9007bff0                 add     %fp, var_10, %o0
F00DBF70: 7ffe4998                 call    _microtime
F00DBF74: d227bfec                 st      %o1, [%fp+var_14]
F00DBF78: d207bfe8                 ld      [%fp+var_18], %o1
F00DBF7C: d007bff0                 ld      [%fp+var_10], %o0
F00DBF80: d407bfec                 ld      [%fp+var_14], %o2
F00DBF84: 92224008                 sub     %o1, %o0, %o1
F00DBF88: d007bff4                 ld      [%fp+var_C], %o0
F00DBF8C: d227bfe8                 st      %o1, [%fp+var_18]
F00DBF90: 94228008                 sub     %o2, %o0, %o2
F00DBF94: 80a2a000                 cmp     %o2, 0
F00DBF98: 16800006                 bge     loc_F00DBFB0
F00DBF9C: d427bfec                 st      %o2, [%fp+var_14]
F00DBFA0: 90027fff                 add     %o1, -1, %o0
F00DBFA4: d027bfe8                 st      %o0, [%fp+var_18]
F00DBFA8: 90028016                 add     %o2, %l6, %o0
F00DBFAC: d027bfec                 st      %o0, [%fp+var_14]
F00DBFB0: d007bfe8                 ld      [%fp+var_18], %o0
F00DBFB4: 921023e8                 mov     0x3E8, %o1! int
F00DBFB8: 952a2005                 sll     %o0, 5, %o2
F00DBFBC: 94228008                 sub     %o2, %o0, %o2
F00DBFC0: 952aa002                 sll     %o2, 2, %o2
F00DBFC4: 94028008                 add     %o2, %o0, %o2
F00DBFC8: d007bfec                 ld      [%fp+var_14], %o0! int
F00DBFCC: 7ffca98f                 call    _div
F00DBFD0: a12aa003                 sll     %o2, 3, %l0
F00DBFD4: a0040008                 add     %l0, %o0, %l0
F00DBFD8: 80a42000                 cmp     %l0, 0
F00DBFDC: 34bfffc8                 bg,a    loc_F00DBEFC
F00DBFE0: ea24600c                 st      %l5, [%l1+0xC]
F00DBFE4: 90100013                 mov     %l3, %o0! id
F00DBFE8: d2052090                 ld      [%l4+0x90], %o1! SEL
F00DBFEC: 94100012                 mov     %l2, %o2
F00DBFF0: 40005620                 call    _objc_msgSend
F00DBFF4: a0102000                 mov     0, %l0
F00DBFF8: 10bfffc1                 ba      loc_F00DBEFC
F00DBFFC: ea24600c                 st      %l5, [%l1+0xC]
F00DC000: 7fffb887                 call    _IOExitThread
F00DC004: 01000000                 nop
F00DC008: 81c7e008                 ret
F00DC00C: 81e80000                 restore
