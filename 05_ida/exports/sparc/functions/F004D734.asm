F004D734: 9de3bf98                 save    %sp, -0x68, %sp
F004D738: 7ffffe79                 call    sub_F004D11C
F004D73C: 90100018                 mov     %i0, %o0
F004D740: d006200c                 ld      [%i0+0xC], %o0
F004D744: 80a22000                 cmp     %o0, 0
F004D748: 16800008                 bge     loc_F004D768
F004D74C: 9010201f                 mov     0x1F, %o0
F004D750: 133c04eb                 sethi   %hi(dword_F013AD84), %o1
F004D754: d4026184                 ld      [%o1+%lo(dword_F013AD84)], %o2
F004D758: 90100018                 mov     %i0, %o0
F004D75C: 9fc28000                 call    %o2
F004D760: 92100019                 mov     %i1, %o1
F004D764: 30800005                 ba,a    locret_F004D778
F004D768: d026603c                 st      %o0, [%i1+0x3C]
F004D76C: 90100018                 mov     %i0, %o0
F004D770: 7fffff39                 call    sub_F004D454
F004D774: 92100019                 mov     %i1, %o1
F004D778: 81c7e008                 ret
F004D77C: 81e80000                 restore
