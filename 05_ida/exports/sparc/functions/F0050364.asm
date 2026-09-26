F0050364: 9de3bf98                 save    %sp, -0x68, %sp
F0050368: d6062038                 ld      [%i0+0x38], %o3
F005036C: 80a2e002                 cmp     %o3, 2
F0050370: 22800015                 be,a    loc_F00503C4
F0050374: 973ea002                 sra     %i2, 2, %o3
F0050378: 14800007                 bg      loc_F0050394
F005037C: 80a2e004                 cmp     %o3, 4
F0050380: 80a2e001                 cmp     %o3, 1
F0050384: 22800018                 be,a    loc_F00503E4
F0050388: 913ea003                 sra     %i2, 3, %o0
F005038C: 1080001c                 ba      loc_F00503FC
F0050390: 113c043b                 sethi   -0xFEF1400, %o0
F0050394: 02800007                 be      loc_F00503B0
F0050398: 80a2e008                 cmp     %o3, 8
F005039C: 12800018                 bne     loc_F00503FC
F00503A0: 113c043b                 sethi   -0xFEF1400, %o0
F00503A4: 901020ff                 mov     0xFF, %o0
F00503A8: 10800017                 ba      locret_F0050404
F00503AC: d02e401a                 stb     %o0, [%i1+%i2]
F00503B0: 973ea001                 sra     %i2, 1, %o3
F00503B4: 940ea001                 and     %i2, 1, %o2
F00503B8: 952aa002                 sll     %o2, 2, %o2
F00503BC: 10800005                 ba      loc_F00503D0
F00503C0: 9010200f                 mov     0xF, %o0
F00503C4: 940ea003                 and     %i2, 3, %o2
F00503C8: 952aa001                 sll     %o2, 1, %o2
F00503CC: 90102003                 mov     3, %o0
F00503D0: d20e400b                 ldub    [%i1+%o3], %o1
F00503D4: 912a000a                 sll     %o0, %o2, %o0! char *
F00503D8: 92124008                 bset    %o0, %o1
F00503DC: 1080000a                 ba      locret_F0050404
F00503E0: d22e400b                 stb     %o1, [%i1+%o3]
F00503E4: 920ea007                 and     %i2, 7, %o1
F00503E8: d40e4008                 ldub    [%i1+%o0], %o2
F00503EC: 932ac009                 sll     %o3, %o1, %o1
F00503F0: 94128009                 bset    %o1, %o2
F00503F4: 10800004                 ba      locret_F0050404
F00503F8: d42e4008                 stb     %o2, [%i1+%o0]
F00503FC: 7fff135d                 call    _panic
F0050400: 90122190                 bset    0x190, %o0
F0050404: 81c7e008                 ret
F0050408: 81e80000                 restore
