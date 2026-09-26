F007E2FC: 9de3bf98                 save    %sp, -0x68, %sp
F007E300: d0062004                 ld      [%i0+4], %o0
F007E304: 80a22018                 cmp     %o0, 0x18
F007E308: 12800007                 bne     loc_F007E324
F007E30C: 90103ed0                 mov     -0x130, %o0
F007E310: d0060000                 ld      [%i0], %o0
F007E314: 80a22000                 cmp     %o0, 0
F007E318: 16800005                 bge     loc_F007E32C
F007E31C: 01000000                 nop
F007E320: 90103ed0                 mov     -0x130, %o0
F007E324: 10800009                 ba      locret_F007E348
F007E328: d026601c                 st      %o0, [%i1+0x1C]
F007E32C: 7fffa5d4                 call    _convert_port_to_thread
F007E330: d0062008                 ld      [%i0+8], %o0! target_act
F007E334: 7fffd958                 call    _thread_terminate
F007E338: a0100008                 mov     %o0, %l0
F007E33C: d026601c                 st      %o0, [%i1+0x1C]
F007E340: 7fffd81b                 call    _thread_deallocate
F007E344: 90100010                 mov     %l0, %o0
F007E348: 81c7e008                 ret
F007E34C: 81e80000                 restore
