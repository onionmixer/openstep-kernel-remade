F00146F8: 9de3bf98                 save    %sp, -0x68, %sp
F00146FC: f427a04c                 st      %i2, [%fp+arg_4C]
F0014700: f627a050                 st      %i3, [%fp+arg_50]
F0014704: f827a054                 st      %i4, [%fp+arg_54]
F0014708: fa27a058                 st      %i5, [%fp+arg_58]
F001470C: b4102006                 mov     6, %i2
F0014710: 40000056                 call    sub_F0014868
F0014714: 90102006                 mov     6, %o0
F0014718: 80a62000                 cmp     %i0, 0
F001471C: 12800005                 bne     loc_F0014730
F0014720: 90100018                 mov     %i0, %o0
F0014724: 113c04d4b0122190         set     _cons, %i0
F001472C: 90100018                 mov     %i0, %o0
F0014730: 400014b8                 call    _ttycheckoutq
F0014734: 92102000                 mov     0, %o1
F0014738: 80a22000                 cmp     %o0, 0
F001473C: 22800002                 be,a    loc_F0014744
F0014740: b4102004                 mov     4, %i2
F0014744: 90100019                 mov     %i1, %o0
F0014748: 9207a04c                 add     %fp, arg_4C, %o1
F001474C: 9410001a                 mov     %i2, %o2
F0014750: 4000005f                 call    _prf
F0014754: 96100018                 mov     %i0, %o3
F0014758: 7fffff47                 call    _logwakeup
F001475C: b0102000                 mov     0, %i0
F0014760: 81c7e008                 ret
F0014764: 81e80000                 restore
