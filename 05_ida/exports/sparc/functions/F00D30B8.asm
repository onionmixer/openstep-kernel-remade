F00D30B8: 9de3bf88                 save    %sp, -0x78, %sp
F00D30BC: d04e21d2                 ldsb    [%i0+0x1D2], %o0
F00D30C0: d6062180                 ld      [%i0+0x180], %o3
F00D30C4: 80a22000                 cmp     %o0, 0
F00D30C8: 912ea002                 sll     %i2, 2, %o0
F00D30CC: 9002001a                 add     %o0, %i2, %o0
F00D30D0: 02800034                 be      locret_F00D31A0
F00D30D4: 952a2002                 sll     %o0, 2, %o2
F00D30D8: d2062168                 ld      [%i0+0x168], %o1
F00D30DC: d0126018                 lduh    [%o1+0x18], %o0
F00D30E0: d037bfe8                 sth     %o0, [%fp+var_18]
F00D30E4: d012601a                 lduh    [%o1+0x1A], %o0
F00D30E8: d037bfea                 sth     %o0, [%fp+var_16]
F00D30EC: d002c00a                 ld      [%o3+%o2], %o0
F00D30F0: 80a22000                 cmp     %o0, 0
F00D30F4: 0280002b                 be      locret_F00D31A0
F00D30F8: 80a6e002                 cmp     %i3, 2
F00D30FC: 22800010                 be,a    loc_F00D313C
F00D3100: 113c0505                 sethi   -0xFEBEC00, %o0
F00D3104: 18800005                 bgu     loc_F00D3118
F00D3108: 80a6e001                 cmp     %i3, 1
F00D310C: 02800014                 be      loc_F00D315C
F00D3110: 01000000                 nop
F00D3114: 30800023                 ba,a    locret_F00D31A0
F00D3118: 80a6e003                 cmp     %i3, 3
F00D311C: 02800005                 be      loc_F00D3130
F00D3120: 80a6e004                 cmp     %i3, 4
F00D3124: 02800014                 be      loc_F00D3174
F00D3128: 113c0505                 sethi   -0xFEBEC00, %o0
F00D312C: 3080001d                 ba,a    locret_F00D31A0
F00D3130: 113c0505                 sethi   %hi(paMovecursorFram), %o0
F00D3134: 10800003                 ba      loc_F00D3140
F00D3138: d20222f4                 ld      [%o0+%lo(paMovecursorFram)], %o1
F00D313C: d20222f0                 ld      [%o0+0x2F0], %o1! SEL
F00D3140: d002c00a                 ld      [%o3+%o2], %o0! id
F00D3144: d6062168                 ld      [%i0+0x168], %o3
F00D3148: 9806a100                 add     %i2, 0x100, %o4
F00D314C: d602e01c                 ld      [%o3+0x1C], %o3
F00D3150: 400079c8                 call    _objc_msgSend
F00D3154: 9407bfe8                 add     %fp, var_18, %o2
F00D3158: 30800012                 ba,a    locret_F00D31A0
F00D315C: d002c00a                 ld      [%o3+%o2], %o0! id
F00D3160: 133c0505                 sethi   %hi(paHidecursor), %o1
F00D3164: d20262ec                 ld      [%o1+%lo(paHidecursor)], %o1! SEL
F00D3168: 400079c2                 call    _objc_msgSend
F00D316C: 9406a100                 add     %i2, 0x100, %o2
F00D3170: 3080000c                 ba,a    locret_F00D31A0
F00D3174: d20222e8                 ld      [%o0+0x2E8], %o1! SEL
F00D3178: 113c0505                 sethi   %hi(paSetbrightnessT), %o0! id
F00D317C: e00222e4                 ld      [%o0+%lo(paSetbrightnessT)], %l0
F00D3180: e202c00a                 ld      [%o3+%o2], %l1
F00D3184: 400079bb                 call    _objc_msgSend
F00D3188: 90100018                 mov     %i0, %o0
F00D318C: 94100008                 mov     %o0, %o2
F00D3190: 90100011                 mov     %l1, %o0! id
F00D3194: 92100010                 mov     %l0, %o1! SEL
F00D3198: 400079b6                 call    _objc_msgSend
F00D319C: 9606a100                 add     %i2, 0x100, %o3
F00D31A0: 81c7e008                 ret
F00D31A4: 81e80000                 restore
