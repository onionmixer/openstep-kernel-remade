F007C498: 9de3bf98                 save    %sp, -0x68, %sp
F007C49C: d0062004                 ld      [%i0+4], %o0
F007C4A0: 80a22018                 cmp     %o0, 0x18
F007C4A4: 12800007                 bne     loc_F007C4C0
F007C4A8: 90103ed0                 mov     -0x130, %o0
F007C4AC: d0060000                 ld      [%i0], %o0
F007C4B0: 80a22000                 cmp     %o0, 0
F007C4B4: 16800005                 bge     loc_F007C4C8
F007C4B8: 01000000                 nop
F007C4BC: 90103ed0                 mov     -0x130, %o0
F007C4C0: 10800009                 ba      locret_F007C4E4
F007C4C4: d026601c                 st      %o0, [%i1+0x1C]
F007C4C8: 7fffa3c6                 call    _convert_port_to_pset
F007C4CC: d0062008                 ld      [%i0+8], %o0! set
F007C4D0: 7fffcb91                 call    _processor_set_destroy
F007C4D4: a0100008                 mov     %o0, %l0
F007C4D8: d026601c                 st      %o0, [%i1+0x1C]
F007C4DC: 7fffcb17                 call    _pset_deallocate
F007C4E0: 90100010                 mov     %l0, %o0
F007C4E4: 81c7e008                 ret
F007C4E8: 81e80000                 restore
