F00C6440: 9de3bf90                 save    %sp, -0x70, %sp
F00C6444: fa27a058                 st      %i5, [%fp+arg_58]
F00C6448: 9010001b                 mov     %i3, %o0
F00C644C: 9210001c                 mov     %i4, %o1
F00C6450: d806213c                 ld      [%i0+0x13C], %o4
F00C6454: 170003d0                 sethi   0xF4000, %o3
F00C6458: 94102000                 mov     0, %o2
F00C645C: da062140                 ld      [%i0+0x140], %o5
F00C6460: 9612e240                 bset    0x240, %o3
F00C6464: e01fa058                 ldd     [%fp+arg_58], %l0
F00C6468: 98032001                 inc     %o4
F00C646C: d826213c                 st      %o4, [%i0+0x13C]
F00C6470: 9a03401a                 add     %o5, %i2, %o5
F00C6474: 7ffcfe5f                 call    __udivdi3
F00C6478: da262140                 st      %o5, [%i0+0x140]
F00C647C: 84100008                 mov     %o0, %g2
F00C6480: 86100009                 mov     %o1, %g3
F00C6484: 90100010                 mov     %l0, %o0
F00C6488: 92100011                 mov     %l1, %o1
F00C648C: 170003d0                 sethi   0xF4000, %o3
F00C6490: 94102000                 mov     0, %o2
F00C6494: d8062144                 ld      [%i0+0x144], %o4
F00C6498: 9612e240                 bset    0x240, %o3
F00C649C: 98030003                 add     %o4, %g3, %o4
F00C64A0: 7ffcfe54                 call    __udivdi3
F00C64A4: d8262144                 st      %o4, [%i0+0x144]
F00C64A8: d4062148                 ld      [%i0+0x148], %o2
F00C64AC: 94028009                 add     %o2, %o1, %o2
F00C64B0: d4262148                 st      %o2, [%i0+0x148]
F00C64B4: 81c7e008                 ret
F00C64B8: 81e80000                 restore
