F00E30F0: 9de3bf90                 save    %sp, -0x70, %sp
F00E30F4: d4062004                 ld      [%i0+4], %o2
F00E30F8: 80a2a06c                 cmp     %o2, 0x6C ! 'l'
F00E30FC: 12800005                 bne     loc_F00E3110
F00E3100: d00e2003                 ldub    [%i0+3], %o0
F00E3104: 80a22001                 cmp     %o0, 1
F00E3108: 22800005                 be,a    loc_F00E311C
F00E310C: d0062018                 ld      [%i0+0x18], %o0
F00E3110: 90103ed0                 mov     -0x130, %o0
F00E3114: 10800030                 ba      locret_F00E31D4
F00E3118: d026601c                 st      %o0, [%i1+0x1C]
F00E311C: 133c03e6                 sethi   %hi(dword_F00F99F4), %o1
F00E3120: d20261f4                 ld      [%o1+%lo(dword_F00F99F4)], %o1
F00E3124: 80a20009                 cmp     %o0, %o1
F00E3128: 12800017                 bne     loc_F00E3184
F00E312C: 90103ed0                 mov     -0x130, %o0
F00E3130: d0062020                 ld      [%i0+0x20], %o0
F00E3134: 133c03e6                 sethi   %hi(dword_F00F99F8), %o1
F00E3138: d20261f8                 ld      [%o1+%lo(dword_F00F99F8)], %o1
F00E313C: 80a20009                 cmp     %o0, %o1
F00E3140: 12800011                 bne     loc_F00E3184
F00E3144: 90103ed0                 mov     -0x130, %o0
F00E3148: d0062064                 ld      [%i0+0x64], %o0
F00E314C: 133c03e6                 sethi   %hi(dword_F00F99FC), %o1
F00E3150: d20261fc                 ld      [%o1+%lo(dword_F00F99FC)], %o1
F00E3154: 80a20009                 cmp     %o0, %o1
F00E3158: 1280000b                 bne     loc_F00E3184
F00E315C: 90103ed0                 mov     -0x130, %o0
F00E3160: 90102040                 mov     0x40, %o0 ! '@'
F00E3164: d027bff4                 st      %o0, [%fp+var_C]
F00E3168: d006200c                 ld      [%i0+0xC], %o0
F00E316C: 94062024                 add     %i0, 0x24, %o2 ! '$'
F00E3170: d206201c                 ld      [%i0+0x1C], %o1
F00E3174: 98066024                 add     %i1, 0x24, %o4 ! '$'
F00E3178: d6062068                 ld      [%i0+0x68], %o3
F00E317C: 7fffc867                 call    _EvGetParameterInt
F00E3180: 9a07bff4                 add     %fp, var_C, %o5
F00E3184: d026601c                 st      %o0, [%i1+0x1C]
F00E3188: d006601c                 ld      [%i1+0x1C], %o0
F00E318C: 80a22000                 cmp     %o0, 0
F00E3190: 12800011                 bne     locret_F00E31D4
F00E3194: 113c03e6                 sethi   %hi(dword_F00F9A00), %o0
F00E3198: d2022200                 ld      [%o0+%lo(dword_F00F9A00)], %o1
F00E319C: d407bff4                 ld      [%fp+var_C], %o2
F00E31A0: d2266020                 st      %o1, [%i1+0x20]
F00E31A4: 113fffc09012200f         set     -0xFFF1, %o0
F00E31AC: 920a4008                 and     %o1, %o0, %o1
F00E31B0: 900aafff                 and     %o2, 0xFFF, %o0
F00E31B4: 912a2004                 sll     %o0, 4, %o0
F00E31B8: 92124008                 bset    %o0, %o1
F00E31BC: d2266020                 st      %o1, [%i1+0x20]
F00E31C0: 952aa002                 sll     %o2, 2, %o2
F00E31C4: 9402a024                 inc     0x24, %o2 ! '$'
F00E31C8: 90102001                 mov     1, %o0
F00E31CC: d02e6003                 stb     %o0, [%i1+3]
F00E31D0: d4266004                 st      %o2, [%i1+4]
F00E31D4: 81c7e008                 ret
F00E31D8: 81e80000                 restore
