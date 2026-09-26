F006EF34: 9de3bf98                 save    %sp, -0x68, %sp
F006EF38: d2062120                 ld      [%i0+0x120], %o1
F006EF3C: 9006211c                 add     %i0, 0x11C, %o0
F006EF40: 80a20009                 cmp     %o0, %o1
F006EF44: 32800003                 bne,a   loc_F006EF50
F006EF48: f2226134                 st      %i1, [%o1+0x134]
F006EF4C: f226211c                 st      %i1, [%i0+0x11C]
F006EF50: d2266138                 st      %o1, [%i1+0x138]
F006EF54: 9006211c                 add     %i0, 0x11C, %o0
F006EF58: d0266134                 st      %o0, [%i1+0x134]
F006EF5C: f2262120                 st      %i1, [%i0+0x120]
F006EF60: f026612c                 st      %i0, [%i1+0x12C]
F006EF64: d0062124                 ld      [%i0+0x124], %o0
F006EF68: 90022001                 inc     %o0
F006EF6C: d0262124                 st      %o0, [%i0+0x124]
F006EF70: 400000df                 call    _quantum_set
F006EF74: 90100018                 mov     %i0, %o0
F006EF78: 81c7e008                 ret
F006EF7C: 81e80000                 restore
