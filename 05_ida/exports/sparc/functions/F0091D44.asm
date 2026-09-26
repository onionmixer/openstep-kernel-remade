F0091D44: 9de3bf98                 save    %sp, -0x68, %sp
F0091D48: d0062004                 ld      [%i0+4], %o0
F0091D4C: 80a22018                 cmp     %o0, 0x18
F0091D50: 12800006                 bne     loc_F0091D68
F0091D54: 90103ed0                 mov     -0x130, %o0
F0091D58: d0060000                 ld      [%i0], %o0
F0091D5C: 80a22000                 cmp     %o0, 0
F0091D60: 16800004                 bge     loc_F0091D70
F0091D64: 90103ed0                 mov     -0x130, %o0
F0091D68: 1080000e                 ba      locret_F0091DA0
F0091D6C: d026601c                 st      %o0, [%i1+0x1C]
F0091D70: 7fff4d47                 call    _convert_port_to_host
F0091D74: d0062008                 ld      [%i0+8], %o0
F0091D78: 7fff72f3                 call    _kern_PMGetPowerStatus
F0091D7C: 92066024                 add     %i1, 0x24, %o1 ! '$'
F0091D80: 80a22000                 cmp     %o0, 0
F0091D84: 12800007                 bne     locret_F0091DA0
F0091D88: d026601c                 st      %o0, [%i1+0x1C]
F0091D8C: 90102030                 mov     0x30, %o0 ! '0'
F0091D90: d0266004                 st      %o0, [%i1+4]
F0091D94: 113c0448                 sethi   %hi(dword_F01122F8), %o0
F0091D98: d00222f8                 ld      [%o0+%lo(dword_F01122F8)], %o0
F0091D9C: d0266020                 st      %o0, [%i1+0x20]
F0091DA0: 81c7e008                 ret
F0091DA4: 81e80000                 restore
