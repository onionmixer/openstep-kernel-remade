F00D39B0: 9de3bf90                 save    %sp, -0x70, %sp
F00D39B4: d04e2210                 ldsb    [%i0+0x210], %o0
F00D39B8: 80a22001                 cmp     %o0, 1
F00D39BC: 12800006                 bne     loc_F00D39D4
F00D39C0: 113c0354                 sethi   %hi(sub_F00D52F8), %o0
F00D39C4: 901222f8                 bset    %lo(sub_F00D52F8), %o0
F00D39C8: 7ffe69eb                 call    _ns_untimeout
F00D39CC: 92100018                 mov     %i0, %o1
F00D39D0: 113c0354                 sethi   -0xFF2B000, %o0
F00D39D4: 901222f8                 bset    0x2F8, %o0
F00D39D8: 92100018                 mov     %i0, %o1
F00D39DC: 9410001a                 mov     %i2, %o2
F00D39E0: 9610001b                 mov     %i3, %o3
F00D39E4: 7ffe69dc                 call    _ns_abstimeout
F00D39E8: 98102004                 mov     4, %o4
F00D39EC: 90102001                 mov     1, %o0
F00D39F0: d02e2210                 stb     %o0, [%i0+0x210]
F00D39F4: 81c7e008                 ret
F00D39F8: 81e80000                 restore
