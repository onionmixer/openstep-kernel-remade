F00B7E30: 9de3bf98                 save    %sp, -0x68, %sp
F00B7E34: e2062020                 ld      [%i0+0x20], %l1
F00B7E38: d2162008                 lduh    [%i0+8], %o1
F00B7E3C: 113c047b                 sethi   %hi(aCmdDumpForTarg), %o0! "\tCmd dump for Target %d Lun %d:\n"
F00B7E40: d40e200a                 ldub    [%i0+0xA], %o2
F00B7E44: 7ffd7205                 call    _printf
F00B7E48: 90122180                 bset    %lo(aCmdDumpForTarg), %o0! "\tCmd dump for Target %d Lun %d:\n"
F00B7E4C: 113c047b                 sethi   %hi(aCdb), %o0! "\tcdb=["
F00B7E50: 7ffd7202                 call    _printf
F00B7E54: 901221a8                 bset    %lo(aCdb), %o0! "\tcdb=["
F00B7E58: d00e2063                 ldub    [%i0+0x63], %o0
F00B7E5C: a0102000                 mov     0, %l0
F00B7E60: 80a40008                 cmp     %l0, %o0
F00B7E64: 3680000c                 bge,a   loc_F00B7E94
F00B7E68: d00e2029                 ldub    [%i0+0x29], %o0
F00B7E6C: 253c047b                 sethi   -0xFEE1400, %l2
F00B7E70: 9014a1b0                 or      %l2, 0x1B0, %o0! char *
F00B7E74: d20c4000                 ldub    [%l1], %o1
F00B7E78: 7ffd71f8                 call    _printf
F00B7E7C: a0042001                 inc     %l0
F00B7E80: d00e2063                 ldub    [%i0+0x63], %o0
F00B7E84: 80a40008                 cmp     %l0, %o0
F00B7E88: 06bffffa                 bl      loc_F00B7E70
F00B7E8C: a2046001                 inc     %l1
F00B7E90: d00e2029                 ldub    [%i0+0x29], %o0
F00B7E94: 808a2010                 btst    0x10, %o0
F00B7E98: 22800009                 be,a    loc_F00B7EBC
F00B7E9C: 113c047b                 sethi   -0xFEE1400, %o0
F00B7EA0: d006201c                 ld      [%i0+0x1C], %o0
F00B7EA4: d24a0000                 ldsb    [%o0], %o1
F00B7EA8: 113c047b                 sethi   %hi(aStatus0xX), %o0! " ]; Status=0x%x\n"
F00B7EAC: 7ffd71eb                 call    _printf
F00B7EB0: 901221b8                 bset    %lo(aStatus0xX), %o0! " ]; Status=0x%x\n"
F00B7EB4: 10800005                 ba      loc_F00B7EC8
F00B7EB8: d20e2029                 ldub    [%i0+0x29], %o1
F00B7EBC: 7ffd71e7                 call    _printf
F00B7EC0: 901221d0                 bset    0x1D0, %o0
F00B7EC4: d20e2029                 ldub    [%i0+0x29], %o1
F00B7EC8: 113c047c                 sethi   %hi(_state_bits), %o0
F00B7ECC: d40223b0                 ld      [%o0+%lo(_state_bits)], %o2
F00B7ED0: d6062014                 ld      [%i0+0x14], %o3
F00B7ED4: d80e202a                 ldub    [%i0+0x2A], %o4
F00B7ED8: 113c047b                 sethi   %hi(aPktState0xBPkt), %o0! "\tpkt_state 0x%b pkt_flags 0x%x pkt_sta"...
F00B7EDC: 7ffd71df                 call    _printf
F00B7EE0: 901221d8                 bset    %lo(aPktState0xBPkt), %o0! "\tpkt_state 0x%b pkt_flags 0x%x pkt_sta"...
F00B7EE4: d216205c                 lduh    [%i0+0x5C], %o1
F00B7EE8: 113c047b                 sethi   %hi(aCmdFlags0xXCmd), %o0! "\tcmd_flags=0x%x cmd_timeout %d\n"
F00B7EEC: d4062058                 ld      [%i0+0x58], %o2
F00B7EF0: 7ffd71da                 call    _printf
F00B7EF4: 90122210                 bset    %lo(aCmdFlags0xXCmd), %o0! "\tcmd_flags=0x%x cmd_timeout %d\n"
F00B7EF8: 40000004                 call    _esp_dump_datasegs
F00B7EFC: 90100018                 mov     %i0, %o0
F00B7F00: 81c7e008                 ret
F00B7F04: 81e80000                 restore
