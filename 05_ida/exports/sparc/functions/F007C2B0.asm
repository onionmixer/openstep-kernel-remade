F007C2B0: 9de3bf98                 save    %sp, -0x68, %sp
F007C2B4: d0062004                 ld      [%i0+4], %o0
F007C2B8: 80a22018                 cmp     %o0, 0x18
F007C2BC: 1280000a                 bne     loc_F007C2E4
F007C2C0: 90103ed0                 mov     -0x130, %o0
F007C2C4: d0060000                 ld      [%i0], %o0
F007C2C8: 80a22000                 cmp     %o0, 0
F007C2CC: 06800006                 bl      loc_F007C2E4
F007C2D0: 90103ed0                 mov     -0x130, %o0
F007C2D4: 7fffa427                 call    _convert_port_to_processor
F007C2D8: d0062008                 ld      [%i0+8], %o0! processor
F007C2DC: 7fffcbf6                 call    _processor_exit
F007C2E0: 01000000                 nop
F007C2E4: d026601c                 st      %o0, [%i1+0x1C]
F007C2E8: 81c7e008                 ret
F007C2EC: 81e80000                 restore
