F0091E2C: 9de3bf98                 save    %sp, -0x68, %sp
F0091E30: d0062004                 ld      [%i0+4], %o0
F0091E34: 80a22018                 cmp     %o0, 0x18
F0091E38: 1280000a                 bne     loc_F0091E60
F0091E3C: 90103ed0                 mov     -0x130, %o0
F0091E40: d0060000                 ld      [%i0], %o0
F0091E44: 80a22000                 cmp     %o0, 0
F0091E48: 06800006                 bl      loc_F0091E60
F0091E4C: 90103ed0                 mov     -0x130, %o0
F0091E50: 7fff4d0f                 call    _convert_port_to_host
F0091E54: d0062008                 ld      [%i0+8], %o0
F0091E58: 7fff72d5                 call    _kern_PMRestoreDefaults
F0091E5C: 01000000                 nop
F0091E60: d026601c                 st      %o0, [%i1+0x1C]
F0091E64: 81c7e008                 ret
F0091E68: 81e80000                 restore
