F007C724: 9de3bf98                 save    %sp, -0x68, %sp
F007C728: d0062004                 ld      [%i0+4], %o0
F007C72C: 80a22020                 cmp     %o0, 0x20 ! ' '
F007C730: 1280000e                 bne     loc_F007C768
F007C734: 90103ed0                 mov     -0x130, %o0
F007C738: d0060000                 ld      [%i0], %o0
F007C73C: 80a22000                 cmp     %o0, 0
F007C740: 1680000a                 bge     loc_F007C768
F007C744: 90103ed0                 mov     -0x130, %o0
F007C748: d2062018                 ld      [%i0+0x18], %o1
F007C74C: 1104480090122018         set     0x11200018, %o0
F007C754: 920a7ffc                 and     %o1, -4, %o1! new_set
F007C758: 80a24008                 cmp     %o1, %o0
F007C75C: 02800005                 be      loc_F007C770
F007C760: 01000000                 nop
F007C764: 90103ed0                 mov     -0x130, %o0
F007C768: 1080001c                 ba      locret_F007C7D8
F007C76C: d026601c                 st      %o0, [%i1+0x1C]
F007C770: 7fffacc3                 call    _convert_port_to_thread
F007C774: d0062008                 ld      [%i0+8], %o0
F007C778: a2100008                 mov     %o0, %l1
F007C77C: 7fffa319                 call    _convert_port_to_pset
F007C780: d006201c                 ld      [%i0+0x1C], %o0
F007C784: a0100008                 mov     %o0, %l0
F007C788: 90100011                 mov     %l1, %o0! thread
F007C78C: 7fffe503                 call    _thread_assign
F007C790: 92100010                 mov     %l0, %o1
F007C794: d026601c                 st      %o0, [%i1+0x1C]
F007C798: 7fffca68                 call    _pset_deallocate
F007C79C: 90100010                 mov     %l0, %o0
F007C7A0: 7fffdf03                 call    _thread_deallocate
F007C7A4: 90100011                 mov     %l1, %o0
F007C7A8: d006601c                 ld      [%i1+0x1C], %o0
F007C7AC: 80a22000                 cmp     %o0, 0
F007C7B0: 1280000a                 bne     locret_F007C7D8
F007C7B4: 01000000                 nop
F007C7B8: d006201c                 ld      [%i0+0x1C], %o0
F007C7BC: 80a22000                 cmp     %o0, 0
F007C7C0: 02800006                 be      locret_F007C7D8
F007C7C4: 80a23fff                 cmp     %o0, -1
F007C7C8: 02800004                 be      locret_F007C7D8
F007C7CC: 01000000                 nop
F007C7D0: 7fff7a53                 call    _ipc_port_release_send
F007C7D4: 01000000                 nop
F007C7D8: 81c7e008                 ret
F007C7DC: 81e80000                 restore
