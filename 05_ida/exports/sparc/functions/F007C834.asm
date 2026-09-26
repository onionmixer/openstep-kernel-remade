F007C834: 9de3bf90                 save    %sp, -0x70, %sp
F007C838: d0062004                 ld      [%i0+4], %o0
F007C83C: 80a22018                 cmp     %o0, 0x18
F007C840: 12800008                 bne     loc_F007C860
F007C844: 90103ed0                 mov     -0x130, %o0
F007C848: d0060000                 ld      [%i0], %o0
F007C84C: 23200000                 sethi   0x80000000, %l1
F007C850: 808a0011                 btst    %l1, %o0
F007C854: 02800005                 be      loc_F007C868
F007C858: 01000000                 nop
F007C85C: 90103ed0                 mov     -0x130, %o0
F007C860: 10800018                 ba      locret_F007C8C0
F007C864: d026601c                 st      %o0, [%i1+0x1C]
F007C868: 7fffac85                 call    _convert_port_to_thread
F007C86C: d0062008                 ld      [%i0+8], %o0! thread
F007C870: a0100008                 mov     %o0, %l0
F007C874: 7fffe4d3                 call    _thread_get_assignment
F007C878: 9207bff4                 add     %fp, var_C, %o1
F007C87C: d026601c                 st      %o0, [%i1+0x1C]
F007C880: 7fffdecb                 call    _thread_deallocate
F007C884: 90100010                 mov     %l0, %o0
F007C888: d006601c                 ld      [%i1+0x1C], %o0
F007C88C: 80a22000                 cmp     %o0, 0
F007C890: 1280000c                 bne     locret_F007C8C0
F007C894: 92102028                 mov     0x28, %o1 ! '('
F007C898: d0064000                 ld      [%i1], %o0
F007C89C: d2266004                 st      %o1, [%i1+4]
F007C8A0: 90120011                 bset    %l1, %o0
F007C8A4: d0264000                 st      %o0, [%i1]
F007C8A8: 113c0444                 sethi   %hi(dword_F01110B4), %o0
F007C8AC: d20220b4                 ld      [%o0+%lo(dword_F01110B4)], %o1
F007C8B0: d007bff4                 ld      [%fp+var_C], %o0
F007C8B4: 7fffa32d                 call    _convert_pset_name_to_port
F007C8B8: d2266020                 st      %o1, [%i1+0x20]
F007C8BC: d0266024                 st      %o0, [%i1+0x24]
F007C8C0: 81c7e008                 ret
F007C8C4: 81e80000                 restore
