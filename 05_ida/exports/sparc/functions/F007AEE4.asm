F007AEE4: 9de3bf98                 save    %sp, -0x68, %sp
F007AEE8: 153c04d0                 sethi   %hi(_active_threads), %o2
F007AEEC: d002a260                 ld      [%o2+%lo(_active_threads)], %o0
F007AEF0: d202200c                 ld      [%o0+0xC], %o1
F007AEF4: 90102001                 mov     1, %o0
F007AEF8: d0226050                 st      %o0, [%o1+0x50]
F007AEFC: d002a260                 ld      [%o2+%lo(_active_threads)], %o0
F007AF00: e202200c                 ld      [%o0+0xC], %l1
F007AF04: 293c04c3                 sethi   %hi(unk_F0130F48), %l4
F007AF08: d0046088                 ld      [%l1+0x88], %o0
F007AF0C: 7fffa099                 call    _port_allocate
F007AF10: 92152348                 or      %l4, %lo(unk_F0130F48), %o1
F007AF14: 92920000                 orcc    %o0, %g0, %o1
F007AF18: 22800006                 be,a    loc_F007AF30
F007AF1C: 90100011                 mov     %l1, %o0
F007AF20: 133c0443                 sethi   %hi(aPortAllocate), %o1! "port_allocate"
F007AF24: 40000069                 call    sub_F007B0C8
F007AF28: 92126270                 bset    %lo(aPortAllocate), %o1! "port_allocate"
F007AF2C: 90100011                 mov     %l1, %o0
F007AF30: 213c04c3                 sethi   %hi(dword_F0130F4C), %l0
F007AF34: d2052348                 ld      [%l4+0x348], %o1! which_port
F007AF38: 4000011f                 call    _get_kern_port
F007AF3C: 9414234c                 or      %l0, %lo(dword_F0130F4C), %o2
F007AF40: 90100011                 mov     %l1, %o0! task
F007AF44: d404234c                 ld      [%l0+%lo(dword_F0130F4C)], %o2! special_port
F007AF48: 7fffb145                 call    _task_set_special_port
F007AF4C: 92102002                 mov     2, %o1
F007AF50: 92920000                 orcc    %o0, %g0, %o1
F007AF54: 02800004                 be      loc_F007AF64
F007AF58: 133c0443                 sethi   %hi(aTaskSetSpecial), %o1! "task_set_special_port"
F007AF5C: 4000005b                 call    sub_F007B0C8
F007AF60: 92126280                 bset    %lo(aTaskSetSpecial), %o1! "task_set_special_port"
F007AF64: d0046088                 ld      [%l1+0x88], %o0
F007AF68: 273c0443                 sethi   %hi(_pn_register_port), %l3
F007AF6C: 7fffa081                 call    _port_allocate
F007AF70: 9214e240                 or      %l3, %lo(_pn_register_port), %o1
F007AF74: 92920000                 orcc    %o0, %g0, %o1
F007AF78: 22800006                 be,a    loc_F007AF90
F007AF7C: 90100011                 mov     %l1, %o0
F007AF80: 133c0443                 sethi   %hi(aPortAllocate_0), %o1! "port_allocate"
F007AF84: 40000051                 call    sub_F007B0C8
F007AF88: 92126298                 bset    %lo(aPortAllocate_0), %o1! "port_allocate"
F007AF8C: 90100011                 mov     %l1, %o0
F007AF90: 153c04f2                 sethi   %hi(_pn_register_port_k), %o2
F007AF94: d204e240                 ld      [%l3+0x240], %o1
F007AF98: 40000107                 call    _get_kern_port
F007AF9C: 9412a3f0                 bset    %lo(_pn_register_port_k), %o2
F007AFA0: 253c04c3                 sethi   %hi(unk_F0130F50), %l2
F007AFA4: d0046088                 ld      [%l1+0x88], %o0
F007AFA8: 7fffa147                 call    _port_set_allocate
F007AFAC: 9214a350                 or      %l2, %lo(unk_F0130F50), %o1
F007AFB0: 92920000                 orcc    %o0, %g0, %o1
F007AFB4: 02800004                 be      loc_F007AFC4
F007AFB8: 133c0443                 sethi   %hi(aPortSetAllocat), %o1! "port_set_allocate"
F007AFBC: 40000043                 call    sub_F007B0C8
F007AFC0: 921262a8                 bset    %lo(aPortSetAllocat), %o1! "port_set_allocate"
F007AFC4: d0046088                 ld      [%l1+0x88], %o0
F007AFC8: d204a350                 ld      [%l2+0x350], %o1
F007AFCC: 7fffa168                 call    _port_set_add
F007AFD0: d4052348                 ld      [%l4+0x348], %o2
F007AFD4: 92920000                 orcc    %o0, %g0, %o1
F007AFD8: 02800004                 be      loc_F007AFE8
F007AFDC: 133c0443                 sethi   %hi(aPortSetAdd), %o1! "port_set_add"
F007AFE0: 4000003a                 call    sub_F007B0C8
F007AFE4: 921262c0                 bset    %lo(aPortSetAdd), %o1! "port_set_add"
F007AFE8: d0046088                 ld      [%l1+0x88], %o0
F007AFEC: d204a350                 ld      [%l2+0x350], %o1
F007AFF0: 7fffa15f                 call    _port_set_add
F007AFF4: d404e240                 ld      [%l3+0x240], %o2
F007AFF8: 92920000                 orcc    %o0, %g0, %o1
F007AFFC: 02800004                 be      loc_F007B00C
F007B000: 133c0443                 sethi   %hi(aPortSetAdd_0), %o1! "port_set_add"
F007B004: 40000031                 call    sub_F007B0C8
F007B008: 921262d0                 bset    %lo(aPortSetAdd_0), %o1! "port_set_add"
F007B00C: 7fffb419                 call    _kalloc
F007B010: 11000008                 sethi   0x2000, %o0
F007B014: a0100008                 mov     %o0, %l0
F007B018: 133c04c390126354         set     dword_F0130F54, %o0
F007B020: d0222004                 st      %o0, [%o0+4]
F007B024: d0226354                 st      %o0, [%o1+0x354]
F007B028: ae100012                 mov     %l2, %l7
F007B02C: 2d000008                 sethi   0x2000, %l6
F007B030: 2b3c0443                 sethi   -0xFEEF400, %l5
F007B034: a4100014                 mov     %l4, %l2
F007B038: 233c0443                 sethi   -0xFEEF400, %l1
F007B03C: ec242004                 st      %l6, [%l0+4]
F007B040: 90100010                 mov     %l0, %o0! char *
F007B044: 92102000                 mov     0, %o1
F007B048: d605e350                 ld      [%l7+0x350], %o3
F007B04C: 94102000                 mov     0, %o2
F007B050: 7fffab83                 call    _msg_receive
F007B054: d624200c                 st      %o3, [%l0+0xC]
F007B058: 92920000                 orcc    %o0, %g0, %o1
F007B05C: 22800006                 be,a    loc_F007B074
F007B060: d204200c                 ld      [%l0+0xC], %o1
F007B064: 7ffe657d                 call    _printf
F007B068: 901562e0                 or      %l5, 0x2E0, %o0
F007B06C: 10bffff5                 ba      loc_F007B040
F007B070: ec242004                 st      %l6, [%l0+4]
F007B074: d004e240                 ld      [%l3+0x240], %o0
F007B078: 80a24008                 cmp     %o1, %o0
F007B07C: 12800006                 bne     loc_F007B094
F007B080: d004a348                 ld      [%l2+0x348], %o0
F007B084: 4000001c                 call    sub_F007B0F4
F007B088: 90100010                 mov     %l0, %o0
F007B08C: 10bfffed                 ba      loc_F007B040
F007B090: ec242004                 st      %l6, [%l0+4]
F007B094: 80a24008                 cmp     %o1, %o0
F007B098: 12800006                 bne     loc_F007B0B0
F007B09C: 01000000                 nop
F007B0A0: 40000037                 call    sub_F007B17C
F007B0A4: 90100010                 mov     %l0, %o0! char *
F007B0A8: 10bfffe6                 ba      loc_F007B040
F007B0AC: ec242004                 st      %l6, [%l0+4]
F007B0B0: 7ffe656a                 call    _printf
F007B0B4: 90146310                 or      %l1, 0x310, %o0
F007B0B8: 10bfffe2                 ba      loc_F007B040
F007B0BC: ec242004                 st      %l6, [%l0+4]
