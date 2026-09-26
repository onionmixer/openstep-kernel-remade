F0091CE0: 9de3bf98                 save    %sp, -0x68, %sp
F0091CE4: d0062004                 ld      [%i0+4], %o0
F0091CE8: 80a22018                 cmp     %o0, 0x18
F0091CEC: 12800006                 bne     loc_F0091D04
F0091CF0: 90103ed0                 mov     -0x130, %o0
F0091CF4: d0060000                 ld      [%i0], %o0
F0091CF8: 80a22000                 cmp     %o0, 0
F0091CFC: 16800004                 bge     loc_F0091D0C
F0091D00: 90103ed0                 mov     -0x130, %o0
F0091D04: 1080000e                 ba      locret_F0091D3C
F0091D08: d026601c                 st      %o0, [%i1+0x1C]
F0091D0C: 7fff4d60                 call    _convert_port_to_host
F0091D10: d0062008                 ld      [%i0+8], %o0
F0091D14: 7fff7301                 call    _kern_PMGetPowerEvent
F0091D18: 92066024                 add     %i1, 0x24, %o1 ! '$'
F0091D1C: 80a22000                 cmp     %o0, 0
F0091D20: 12800007                 bne     locret_F0091D3C
F0091D24: d026601c                 st      %o0, [%i1+0x1C]
F0091D28: 90102028                 mov     0x28, %o0 ! '('
F0091D2C: d0266004                 st      %o0, [%i1+4]
F0091D30: 113c0448                 sethi   %hi(dword_F01122F4), %o0
F0091D34: d00222f4                 ld      [%o0+%lo(dword_F01122F4)], %o0
F0091D38: d0266020                 st      %o0, [%i1+0x20]
F0091D3C: 81c7e008                 ret
F0091D40: 81e80000                 restore
