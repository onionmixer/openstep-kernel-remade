F004D780: 9de3bf98                 save    %sp, -0x68, %sp
F004D784: 7ffffe66                 call    sub_F004D11C
F004D788: 90100018                 mov     %i0, %o0
F004D78C: d006200c                 ld      [%i0+0xC], %o0
F004D790: 80a22000                 cmp     %o0, 0
F004D794: 36800008                 bge,a   loc_F004D7B4
F004D798: c026603c                 clr     [%i1+0x3C]
F004D79C: 133c04eb                 sethi   %hi(_ds_call), %o1
F004D7A0: d4026180                 ld      [%o1+%lo(_ds_call)], %o2
F004D7A4: 90100018                 mov     %i0, %o0
F004D7A8: 9fc28000                 call    %o2
F004D7AC: 92100019                 mov     %i1, %o1
F004D7B0: 30800004                 ba,a    locret_F004D7C0
F004D7B4: 90100018                 mov     %i0, %o0
F004D7B8: 7fffff27                 call    sub_F004D454
F004D7BC: 92100019                 mov     %i1, %o1
F004D7C0: 81c7e008                 ret
F004D7C4: 81e80000                 restore
