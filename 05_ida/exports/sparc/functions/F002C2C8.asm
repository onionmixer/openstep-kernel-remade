F002C2C8: 9de3bf98                 save    %sp, -0x68, %sp
F002C2CC: a0102000                 mov     0, %l0
F002C2D0: 80a66000                 cmp     %i1, 0
F002C2D4: 02800007                 be      loc_F002C2F0
F002C2D8: 92100019                 mov     %i1, %o1
F002C2DC: d0526008                 ldsh    [%o1+8], %o0
F002C2E0: d2024000                 ld      [%o1], %o1
F002C2E4: 80a26000                 cmp     %o1, 0
F002C2E8: 12bffffd                 bne     loc_F002C2DC
F002C2EC: a0040008                 add     %l0, %o0, %l0
F002C2F0: d056200a                 ldsh    [%i0+0xA], %o0
F002C2F4: 80a40008                 cmp     %l0, %o0
F002C2F8: 24800006                 ble,a   loc_F002C310
F002C2FC: d2062040                 ld      [%i0+0x40], %o1
F002C300: 7fffc659                 call    _m_freem
F002C304: 90100019                 mov     %i1, %o0
F002C308: 1080001f                 ba      locret_F002C384
F002C30C: b0102028                 mov     0x28, %i0 ! '('
F002C310: 9fc24000                 call    %o1
F002C314: 90100018                 mov     %i0, %o0
F002C318: a2920000                 orcc    %o0, %g0, %l1
F002C31C: 02800017                 be      loc_F002C378
F002C320: 01000000                 nop
F002C324: 7ffffddc                 call    _nb_map
F002C328: 01000000                 nop
F002C32C: 92100008                 mov     %o0, %o1
F002C330: 90100019                 mov     %i1, %o0
F002C334: 94102000                 mov     0, %o2
F002C338: 7fffffc0                 call    _mbuf_read
F002C33C: 96100010                 mov     %l0, %o3
F002C340: 7ffffde6                 call    _nb_size
F002C344: 90100011                 mov     %l1, %o0
F002C348: 92220010                 sub     %o0, %l0, %o1
F002C34C: 7ffffe19                 call    _nb_shrink_bot
F002C350: 90100011                 mov     %l1, %o0
F002C354: 7fffc644                 call    _m_freem
F002C358: 90100019                 mov     %i1, %o0
F002C35C: 90100018                 mov     %i0, %o0
F002C360: 92100011                 mov     %l1, %o1
F002C364: d6022034                 ld      [%o0+0x34], %o3
F002C368: 9fc2c000                 call    %o3
F002C36C: 9410001a                 mov     %i2, %o2
F002C370: 10800005                 ba      locret_F002C384
F002C374: b0100008                 mov     %o0, %i0
F002C378: 7fffc63b                 call    _m_freem
F002C37C: 90100019                 mov     %i1, %o0
F002C380: b0102037                 mov     0x37, %i0 ! '7'
F002C384: 81c7e008                 ret
F002C388: 81e80000                 restore
