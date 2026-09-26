F007C5DC: 9de3bf98                 save    %sp, -0x68, %sp
F007C5E0: d0062004                 ld      [%i0+4], %o0
F007C5E4: 80a22028                 cmp     %o0, 0x28 ! '('
F007C5E8: 12800014                 bne     loc_F007C638
F007C5EC: 90103ed0                 mov     -0x130, %o0
F007C5F0: d0060000                 ld      [%i0], %o0
F007C5F4: 80a22000                 cmp     %o0, 0
F007C5F8: 16800010                 bge     loc_F007C638
F007C5FC: 90103ed0                 mov     -0x130, %o0
F007C600: d2062018                 ld      [%i0+0x18], %o1
F007C604: 1104480090122018         set     0x11200018, %o0
F007C60C: 920a7ffc                 and     %o1, -4, %o1
F007C610: 80a24008                 cmp     %o1, %o0
F007C614: 12800009                 bne     loc_F007C638
F007C618: 90103ed0                 mov     -0x130, %o0
F007C61C: d0062020                 ld      [%i0+0x20], %o0
F007C620: 133c0444                 sethi   %hi(dword_F01110AC), %o1
F007C624: d20260ac                 ld      [%o1+%lo(dword_F01110AC)], %o1! new_set
F007C628: 80a20009                 cmp     %o0, %o1
F007C62C: 02800005                 be      loc_F007C640
F007C630: 01000000                 nop
F007C634: 90103ed0                 mov     -0x130, %o0
F007C638: 10800019                 ba      locret_F007C69C
F007C63C: d026601c                 st      %o0, [%i1+0x1C]
F007C640: 7fffa368                 call    _convert_port_to_pset
F007C644: d006201c                 ld      [%i0+0x1C], %o0
F007C648: a0100008                 mov     %o0, %l0
F007C64C: 7fffa349                 call    _convert_port_to_processor
F007C650: d0062008                 ld      [%i0+8], %o0! processor
F007C654: d4062024                 ld      [%i0+0x24], %o2! wait
F007C658: 7fffbe8a                 call    _processor_assign
F007C65C: 92100010                 mov     %l0, %o1
F007C660: d026601c                 st      %o0, [%i1+0x1C]
F007C664: 7fffcab5                 call    _pset_deallocate
F007C668: 90100010                 mov     %l0, %o0
F007C66C: d006601c                 ld      [%i1+0x1C], %o0
F007C670: 80a22000                 cmp     %o0, 0
F007C674: 1280000a                 bne     locret_F007C69C
F007C678: 01000000                 nop
F007C67C: d006201c                 ld      [%i0+0x1C], %o0
F007C680: 80a22000                 cmp     %o0, 0
F007C684: 02800006                 be      locret_F007C69C
F007C688: 80a23fff                 cmp     %o0, -1
F007C68C: 02800004                 be      locret_F007C69C
F007C690: 01000000                 nop
F007C694: 7fff7aa2                 call    _ipc_port_release_send
F007C698: 01000000                 nop
F007C69C: 81c7e008                 ret
F007C6A0: 81e80000                 restore
