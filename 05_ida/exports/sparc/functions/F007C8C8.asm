F007C8C8: 9de3bf98                 save    %sp, -0x68, %sp
F007C8CC: d0062004                 ld      [%i0+4], %o0
F007C8D0: 80a22028                 cmp     %o0, 0x28 ! '('
F007C8D4: 12800014                 bne     loc_F007C924
F007C8D8: 90103ed0                 mov     -0x130, %o0
F007C8DC: d0060000                 ld      [%i0], %o0
F007C8E0: 80a22000                 cmp     %o0, 0
F007C8E4: 16800010                 bge     loc_F007C924
F007C8E8: 90103ed0                 mov     -0x130, %o0
F007C8EC: d2062018                 ld      [%i0+0x18], %o1
F007C8F0: 1104480090122018         set     0x11200018, %o0
F007C8F8: 920a7ffc                 and     %o1, -4, %o1
F007C8FC: 80a24008                 cmp     %o1, %o0
F007C900: 12800009                 bne     loc_F007C924
F007C904: 90103ed0                 mov     -0x130, %o0
F007C908: d0062020                 ld      [%i0+0x20], %o0
F007C90C: 133c0444                 sethi   %hi(dword_F01110B8), %o1
F007C910: d20260b8                 ld      [%o1+%lo(dword_F01110B8)], %o1! new_set
F007C914: 80a20009                 cmp     %o0, %o1
F007C918: 02800005                 be      loc_F007C92C
F007C91C: 01000000                 nop
F007C920: 90103ed0                 mov     -0x130, %o0
F007C924: 1080001d                 ba      locret_F007C998
F007C928: d026601c                 st      %o0, [%i1+0x1C]
F007C92C: 7fffabf2                 call    _convert_port_to_task
F007C930: d0062008                 ld      [%i0+8], %o0
F007C934: a2100008                 mov     %o0, %l1
F007C938: 7fffa2aa                 call    _convert_port_to_pset
F007C93C: d006201c                 ld      [%i0+0x1C], %o0
F007C940: a0100008                 mov     %o0, %l0
F007C944: 90100011                 mov     %l1, %o0! task
F007C948: d4062024                 ld      [%i0+0x24], %o2! assign_threads
F007C94C: 7fffdd4f                 call    _task_assign
F007C950: 92100010                 mov     %l0, %o1
F007C954: d026601c                 st      %o0, [%i1+0x1C]
F007C958: 7fffc9f8                 call    _pset_deallocate
F007C95C: 90100010                 mov     %l0, %o0
F007C960: 7fffd9d2                 call    _task_deallocate
F007C964: 90100011                 mov     %l1, %o0
F007C968: d006601c                 ld      [%i1+0x1C], %o0
F007C96C: 80a22000                 cmp     %o0, 0
F007C970: 1280000a                 bne     locret_F007C998
F007C974: 01000000                 nop
F007C978: d006201c                 ld      [%i0+0x1C], %o0
F007C97C: 80a22000                 cmp     %o0, 0
F007C980: 02800006                 be      locret_F007C998
F007C984: 80a23fff                 cmp     %o0, -1
F007C988: 02800004                 be      locret_F007C998
F007C98C: 01000000                 nop
F007C990: 7fff79e3                 call    _ipc_port_release_send
F007C994: 01000000                 nop
F007C998: 81c7e008                 ret
F007C99C: 81e80000                 restore
