F0022CCC: 9de3bf98                 save    %sp, -0x68, %sp
F0022CD0: d2564000                 ldsh    [%i1], %o1
F0022CD4: d0560000                 ldsh    [%i0], %o0
F0022CD8: 80a24008                 cmp     %o1, %o0
F0022CDC: 02800004                 be      loc_F0022CEC
F0022CE0: d6062008                 ld      [%i0+8], %o3
F0022CE4: 1080001b                 ba      locret_F0022D50
F0022CE8: b0102029                 mov     0x29, %i0 ! ')'
F0022CEC: d4066008                 ld      [%i1+8], %o2
F0022CF0: d422e00c                 st      %o2, [%o3+0xC]
F0022CF4: d0560000                 ldsh    [%i0], %o0
F0022CF8: 80a22001                 cmp     %o0, 1
F0022CFC: 0280000b                 be      loc_F0022D28
F0022D00: 80a22002                 cmp     %o0, 2
F0022D04: 12800010                 bne     loc_F0022D44
F0022D08: 113c042f                 sethi   -0xFEF4400, %o0
F0022D0C: d202a010                 ld      [%o2+0x10], %o1
F0022D10: 90100018                 mov     %i0, %o0
F0022D14: d222e014                 st      %o1, [%o3+0x14]
F0022D18: 7ffff4ad                 call    _soisconnected
F0022D1C: d622a010                 st      %o3, [%o2+0x10]
F0022D20: 1080000c                 ba      locret_F0022D50
F0022D24: b0102000                 mov     0, %i0
F0022D28: d622a00c                 st      %o3, [%o2+0xC]
F0022D2C: 7ffff4a8                 call    _soisconnected
F0022D30: 90100019                 mov     %i1, %o0
F0022D34: 7ffff4a6                 call    _soisconnected
F0022D38: 90100018                 mov     %i0, %o0! char *
F0022D3C: 10800005                 ba      locret_F0022D50
F0022D40: b0102000                 mov     0, %i0
F0022D44: 7fffc90b                 call    _panic
F0022D48: 90122158                 bset    0x158, %o0
F0022D4C: b0102000                 mov     0, %i0
F0022D50: 81c7e008                 ret
F0022D54: 81e80000                 restore
