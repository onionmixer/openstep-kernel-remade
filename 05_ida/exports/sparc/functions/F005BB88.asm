F005BB88: 9de3bf90                 save    %sp, -0x70, %sp
F005BB8C: 27001000                 sethi   0x400000, %l3
F005BB90: 113fefffaa1223ff         set     -0x400001, %l5
F005BB98: 1100003fa81223ff         set     0xFFFF, %l4
F005BBA0: 90100018                 mov     %i0, %o0
F005BBA4: 92100019                 mov     %i1, %o1
F005BBA8: 7fffffb5                 call    _ipc_right_lookup_write
F005BBAC: 9407bff4                 add     %fp, var_C, %o2
F005BBB0: 80a22000                 cmp     %o0, 0
F005BBB4: 3280006c                 bne,a   locret_F005BD64
F005BBB8: b0100008                 mov     %o0, %i0
F005BBBC: d607bff4                 ld      [%fp+var_C], %o3
F005BBC0: e202c000                 ld      [%o3], %l1
F005BBC4: 110001c0                 sethi   0x70000, %o0
F005BBC8: 808c4008                 btst    %o0, %l1
F005BBCC: 02800044                 be      loc_F005BCDC
F005BBD0: 90100018                 mov     %i0, %o0
F005BBD4: e002e004                 ld      [%o3+4], %l0
F005BBD8: 94100019                 mov     %i1, %o2
F005BBDC: 400000b2                 call    _ipc_right_check
F005BBE0: 92100010                 mov     %l0, %o1
F005BBE4: 80a22000                 cmp     %o0, 0
F005BBE8: 12800037                 bne     loc_F005BCC4
F005BBEC: 808c4013                 btst    %l3, %l1
F005BBF0: 80a6e000                 cmp     %i3, 0
F005BBF4: 12800012                 bne     loc_F005BC3C
F005BBF8: d607bff4                 ld      [%fp+var_C], %o3
F005BBFC: 808c4013                 btst    %l3, %l1
F005BC00: 1280000b                 bne     loc_F005BC2C
F005BC04: a4102000                 mov     0, %l2
F005BC08: d607bff4                 ld      [%fp+var_C], %o3
F005BC0C: d002e008                 ld      [%o3+8], %o0
F005BC10: 80a22000                 cmp     %o0, 0
F005BC14: 02800006                 be      loc_F005BC2C
F005BC18: 90100018                 mov     %i0, %o0
F005BC1C: 92100010                 mov     %l0, %o1
F005BC20: 40000053                 call    _ipc_right_dncancel
F005BC24: 94100019                 mov     %i1, %o2
F005BC28: a4100008                 mov     %o0, %l2
F005BC2C: c0240000                 clr     [%l0]
F005BC30: c0262008                 clr     [%i0+8]
F005BC34: 1080004b                 ba      loc_F005BD60
F005BC38: e4270000                 st      %l2, [%i4]
F005BC3C: d002e008                 ld      [%o3+8], %o0
F005BC40: 80a22000                 cmp     %o0, 0
F005BC44: 02800007                 be      loc_F005BC60
F005BC48: 90100018                 mov     %i0, %o0
F005BC4C: 92100010                 mov     %l0, %o1
F005BC50: 40000047                 call    _ipc_right_dncancel
F005BC54: 94100019                 mov     %i1, %o2
F005BC58: 10800003                 ba      loc_F005BC64
F005BC5C: a4100008                 mov     %o0, %l2
F005BC60: a4102000                 mov     0, %l2
F005BC64: 90100010                 mov     %l0, %o0
F005BC68: 92100019                 mov     %i1, %o1
F005BC6C: 9410001b                 mov     %i3, %o2
F005BC70: 7ffffa27                 call    _ipc_port_dnrequest
F005BC74: 9607bff0                 add     %fp, var_10, %o3
F005BC78: 80a22000                 cmp     %o0, 0
F005BC7C: 0280000a                 be      loc_F005BCA4
F005BC80: d207bff4                 ld      [%fp+var_C], %o1
F005BC84: c0262008                 clr     [%i0+8]
F005BC88: 7ffffa35                 call    _ipc_port_dngrow
F005BC8C: 90100010                 mov     %l0, %o0
F005BC90: 80a22000                 cmp     %o0, 0
F005BC94: 22bfffc4                 be,a    loc_F005BBA4
F005BC98: 90100018                 mov     %i0, %o0
F005BC9C: 10800032                 ba      locret_F005BD64
F005BCA0: b0100008                 mov     %o0, %i0
F005BCA4: d007bff0                 ld      [%fp+var_10], %o0
F005BCA8: c0240000                 clr     [%l0]
F005BCAC: d0226008                 st      %o0, [%o1+8]
F005BCB0: 900c4015                 and     %l1, %l5, %o0
F005BCB4: d0224000                 st      %o0, [%o1]
F005BCB8: c0262008                 clr     [%i0+8]
F005BCBC: 10800029                 ba      loc_F005BD60
F005BCC0: e4270000                 st      %l2, [%i4]
F005BCC4: 02800005                 be      loc_F005BCD8
F005BCC8: d007bff4                 ld      [%fp+var_C], %o0
F005BCCC: c0262008                 clr     [%i0+8]
F005BCD0: 10800025                 ba      locret_F005BD64
F005BCD4: b010200f                 mov     0xF, %i0
F005BCD8: e2020000                 ld      [%o0], %l1
F005BCDC: 11000400                 sethi   0x100000, %o0
F005BCE0: 808c4008                 btst    %o0, %l1
F005BCE4: 02800018                 be      loc_F005BD44
F005BCE8: 80a6a000                 cmp     %i2, 0
F005BCEC: 02800016                 be      loc_F005BD44
F005BCF0: 80a6e000                 cmp     %i3, 0
F005BCF4: 02800014                 be      loc_F005BD44
F005BCF8: 900c4014                 and     %l1, %l4, %o0
F005BCFC: 92022001                 add     %o0, 1, %o1
F005BD00: 80a24008                 cmp     %o1, %o0
F005BD04: 08800004                 bleu    loc_F005BD14
F005BD08: 80a24014                 cmp     %o1, %l4
F005BD0C: 08800005                 bleu    loc_F005BD20
F005BD10: 9010001b                 mov     %i3, %o0
F005BD14: c0262008                 clr     [%i0+8]
F005BD18: 10800013                 ba      locret_F005BD64
F005BD1C: b0102013                 mov     0x13, %i0
F005BD20: 92100019                 mov     %i1, %o1
F005BD24: d607bff4                 ld      [%fp+var_C], %o3
F005BD28: 94046001                 add     %l1, 1, %o2
F005BD2C: d422c000                 st      %o2, [%o3]
F005BD30: c0262008                 clr     [%i0+8]
F005BD34: 7ffff586                 call    _ipc_notify_dead_name
F005BD38: a4102000                 mov     0, %l2
F005BD3C: 10800009                 ba      loc_F005BD60
F005BD40: e4270000                 st      %l2, [%i4]
F005BD44: c0262008                 clr     [%i0+8]
F005BD48: 110005c0                 sethi   0x170000, %o0
F005BD4C: 808c4008                 btst    %o0, %l1
F005BD50: 02800005                 be      locret_F005BD64
F005BD54: b0102011                 mov     0x11, %i0
F005BD58: 10800003                 ba      locret_F005BD64
F005BD5C: b0102004                 mov     4, %i0
F005BD60: b0102000                 mov     0, %i0
F005BD64: 81c7e008                 ret
F005BD68: 81e80000                 restore
