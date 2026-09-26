F005D308: 9de3bf98                 save    %sp, -0x68, %sp
F005D30C: 94100019                 mov     %i1, %o2
F005D310: 9610001a                 mov     %i2, %o3
F005D314: 80a76000                 cmp     %i5, 0
F005D318: 02800007                 be      loc_F005D334
F005D31C: d802c000                 ld      [%o3], %o4
F005D320: 133fe000                 sethi   -0x800000, %o1
F005D324: 920b0009                 and     %o4, %o1, %o1
F005D328: 11000400                 sethi   0x100000, %o0
F005D32C: 1080000a                 ba      loc_F005D354
F005D330: 90122002                 bset    2, %o0
F005D334: 110007c0                 sethi   0x1F0000, %o0
F005D338: 928b0008                 andcc   %o4, %o0, %o1
F005D33C: 12800009                 bne     loc_F005D360
F005D340: 11000400                 sethi   0x100000, %o0
F005D344: 133fe000                 sethi   -0x800000, %o1
F005D348: 920b0009                 and     %o4, %o1, %o1
F005D34C: 1100040090122001         set     0x100001, %o0
F005D354: 92124008                 bset    %o0, %o1
F005D358: 1080000f                 ba      loc_F005D394
F005D35C: d222c000                 st      %o1, [%o3]
F005D360: 80a24008                 cmp     %o1, %o0
F005D364: 12800006                 bne     loc_F005D37C
F005D368: 80a6e013                 cmp     %i3, 0x13
F005D36C: 0280000a                 be      loc_F005D394
F005D370: 90032001                 add     %o4, 1, %o0
F005D374: 10800008                 ba      loc_F005D394
F005D378: d022c000                 st      %o0, [%o3]
F005D37C: 02800003                 be      loc_F005D388
F005D380: 90032001                 add     %o4, 1, %o0
F005D384: d022c000                 st      %o0, [%o3]
F005D388: 90100018                 mov     %i0, %o0
F005D38C: 7ffffac6                 call    _ipc_right_check
F005D390: 9210001c                 mov     %i4, %o1
F005D394: 80a73fff                 cmp     %i4, -1
F005D398: 02800004                 be      locret_F005D3A8
F005D39C: 01000000                 nop
F005D3A0: 7ffff0b4                 call    _ipc_object_release
F005D3A4: 9010001c                 mov     %i4, %o0
F005D3A8: 81c7e008                 ret
F005D3AC: 81e80000                 restore
