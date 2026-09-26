F007C270: 9de3bf98                 save    %sp, -0x68, %sp
F007C274: d0062004                 ld      [%i0+4], %o0
F007C278: 80a22018                 cmp     %o0, 0x18
F007C27C: 1280000a                 bne     loc_F007C2A4
F007C280: 90103ed0                 mov     -0x130, %o0
F007C284: d0060000                 ld      [%i0], %o0
F007C288: 80a22000                 cmp     %o0, 0
F007C28C: 06800006                 bl      loc_F007C2A4
F007C290: 90103ed0                 mov     -0x130, %o0
F007C294: 7fffa437                 call    _convert_port_to_processor
F007C298: d0062008                 ld      [%i0+8], %o0! processor
F007C29C: 7fffcbff                 call    _processor_start
F007C2A0: 01000000                 nop
F007C2A4: d026601c                 st      %o0, [%i1+0x1C]
F007C2A8: 81c7e008                 ret
F007C2AC: 81e80000                 restore
