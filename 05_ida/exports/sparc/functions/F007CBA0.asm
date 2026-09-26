F007CBA0: 9de3bf98                 save    %sp, -0x68, %sp
F007CBA4: d0062004                 ld      [%i0+4], %o0
F007CBA8: 80a22028                 cmp     %o0, 0x28 ! '('
F007CBAC: 12800014                 bne     loc_F007CBFC
F007CBB0: 90103ed0                 mov     -0x130, %o0
F007CBB4: d0060000                 ld      [%i0], %o0
F007CBB8: 80a22000                 cmp     %o0, 0
F007CBBC: 16800010                 bge     loc_F007CBFC
F007CBC0: 90103ed0                 mov     -0x130, %o0
F007CBC4: d2062018                 ld      [%i0+0x18], %o1
F007CBC8: 1104480090122018         set     0x11200018, %o0
F007CBD0: 920a7ffc                 and     %o1, -4, %o1
F007CBD4: 80a24008                 cmp     %o1, %o0
F007CBD8: 12800009                 bne     loc_F007CBFC
F007CBDC: 90103ed0                 mov     -0x130, %o0
F007CBE0: d0062020                 ld      [%i0+0x20], %o0
F007CBE4: 133c0444                 sethi   %hi(dword_F01110D8), %o1
F007CBE8: d20260d8                 ld      [%o1+%lo(dword_F01110D8)], %o1
F007CBEC: 80a20009                 cmp     %o0, %o1
F007CBF0: 02800005                 be      loc_F007CC04
F007CBF4: 01000000                 nop
F007CBF8: 90103ed0                 mov     -0x130, %o0
F007CBFC: 1080001d                 ba      locret_F007CC70
F007CC00: d026601c                 st      %o0, [%i1+0x1C]
F007CC04: 7fffab9e                 call    _convert_port_to_thread
F007CC08: d0062008                 ld      [%i0+8], %o0
F007CC0C: a2100008                 mov     %o0, %l1
F007CC10: 7fffa1f4                 call    _convert_port_to_pset
F007CC14: d006201c                 ld      [%i0+0x1C], %o0
F007CC18: a0100008                 mov     %o0, %l0
F007CC1C: 90100011                 mov     %l1, %o0
F007CC20: d4062024                 ld      [%i0+0x24], %o2
F007CC24: 7fffe435                 call    _thread_max_priority
F007CC28: 92100010                 mov     %l0, %o1
F007CC2C: d026601c                 st      %o0, [%i1+0x1C]
F007CC30: 7fffc942                 call    _pset_deallocate
F007CC34: 90100010                 mov     %l0, %o0
F007CC38: 7fffdddd                 call    _thread_deallocate
F007CC3C: 90100011                 mov     %l1, %o0
F007CC40: d006601c                 ld      [%i1+0x1C], %o0
F007CC44: 80a22000                 cmp     %o0, 0
F007CC48: 1280000a                 bne     locret_F007CC70
F007CC4C: 01000000                 nop
F007CC50: d006201c                 ld      [%i0+0x1C], %o0
F007CC54: 80a22000                 cmp     %o0, 0
F007CC58: 02800006                 be      locret_F007CC70
F007CC5C: 80a23fff                 cmp     %o0, -1
F007CC60: 02800004                 be      locret_F007CC70
F007CC64: 01000000                 nop
F007CC68: 7fff792d                 call    _ipc_port_release_send
F007CC6C: 01000000                 nop
F007CC70: 81c7e008                 ret
F007CC74: 81e80000                 restore
