F00B3DBC: 9de3bf98                 save    %sp, -0x68, %sp
F00B3DC0: d0162008                 lduh    [%i0+8], %o0
F00B3DC4: d20e200a                 ldub    [%i0+0xA], %o1
F00B3DC8: d416205c                 lduh    [%i0+0x5C], %o2
F00B3DCC: e0062004                 ld      [%i0+4], %l0
F00B3DD0: 912a2003                 sll     %o0, 3, %o0
F00B3DD4: 808aa001                 btst    1, %o2
F00B3DD8: 02800011                 be      loc_F00B3E1C
F00B3DDC: a2124008                 or      %o1, %o0, %l1
F00B3DE0: d00420a0                 ld      [%l0+0xA0], %o0
F00B3DE4: d0020000                 ld      [%o0], %o0
F00B3DE8: 9132201c                 srl     %o0, 28, %o0
F00B3DEC: 80a22009                 cmp     %o0, 9
F00B3DF0: 08800004                 bleu    loc_F00B3E00
F00B3DF4: 80a2200a                 cmp     %o0, 0xA
F00B3DF8: 02800003                 be      loc_F00B3E04
F00B3DFC: 13100000                 sethi   0x40000000, %o1
F00B3E00: 13004000                 sethi   0x1000000, %o1
F00B3E04: d0062040                 ld      [%i0+0x40], %o0
F00B3E08: 80a20009                 cmp     %o0, %o1
F00B3E0C: 0a800004                 bcs     loc_F00B3E1C
F00B3E10: 01000000                 nop
F00B3E14: 10800029                 ba      locret_F00B3EB8
F00B3E18: b0103fff                 mov     -1, %i0
F00B3E1C: 7fff8bba                 call    _splr
F00B3E20: d0040000                 ld      [%l0], %o0
F00B3E24: 932c6010                 sll     %l1, 16, %o1
F00B3E28: a33a6010                 sra     %o1, 16, %l1
F00B3E2C: 932c6002                 sll     %l1, 2, %o1
F00B3E30: 94024010                 add     %o1, %l0, %o2
F00B3E34: d202a0b8                 ld      [%o2+0xB8], %o1
F00B3E38: 80a26000                 cmp     %o1, 0
F00B3E3C: 02800005                 be      loc_F00B3E50
F00B3E40: a4100008                 mov     %o0, %l2
F00B3E44: 7fff8bb8                 call    _splx
F00B3E48: b0102000                 mov     0, %i0
F00B3E4C: 3080001b                 ba,a    locret_F00B3EB8
F00B3E50: f022a0b8                 st      %i0, [%o2+0xB8]
F00B3E54: d2042084                 ld      [%l0+0x84], %o1
F00B3E58: 90100018                 mov     %i0, %o0
F00B3E5C: 92026001                 inc     %o1
F00B3E60: 40000d3e                 call    _esp_init_cmd
F00B3E64: d2242084                 st      %o1, [%l0+0x84]
F00B3E68: d0062014                 ld      [%i0+0x14], %o0
F00B3E6C: 808a2001                 btst    1, %o0
F00B3E70: 1280000d                 bne     loc_F00B3EA4
F00B3E74: 90100010                 mov     %l0, %o0
F00B3E78: d0042080                 ld      [%l0+0x80], %o0
F00B3E7C: 80a22000                 cmp     %o0, 0
F00B3E80: 1280000b                 bne     loc_F00B3EAC
F00B3E84: 01000000                 nop
F00B3E88: d00c2041                 ldub    [%l0+0x41], %o0
F00B3E8C: 80a22000                 cmp     %o0, 0
F00B3E90: 12800007                 bne     loc_F00B3EAC
F00B3E94: 90100010                 mov     %l0, %o0
F00B3E98: 40000197                 call    _esp_ustart
F00B3E9C: 92100011                 mov     %l1, %o1
F00B3EA0: 30800003                 ba,a    loc_F00B3EAC
F00B3EA4: 40000c8a                 call    _esp_runpoll
F00B3EA8: 92100011                 mov     %l1, %o1
F00B3EAC: 7fff8b9e                 call    _splx
F00B3EB0: 90100012                 mov     %l2, %o0
F00B3EB4: b0102001                 mov     1, %i0
F00B3EB8: 81c7e008                 ret
F00B3EBC: 81e80000                 restore
