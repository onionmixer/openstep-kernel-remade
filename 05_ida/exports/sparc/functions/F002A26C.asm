F002A26C: 9de3bf70                 save    %sp, -0x90, %sp
F002A270: 400006dd                 call    _if_private
F002A274: 90100018                 mov     %i0, %o0
F002A278: d2168000                 lduh    [%i2], %o1
F002A27C: 80a26000                 cmp     %o1, 0
F002A280: 02800006                 be      loc_F002A298
F002A284: e202200c                 ld      [%o0+0xC], %l1
F002A288: 80a26002                 cmp     %o1, 2
F002A28C: 2280000a                 be,a    loc_F002A2B4
F002A290: d206a004                 ld      [%i2+4], %o1
F002A294: 3080001f                 ba,a    loc_F002A310
F002A298: 9006a002                 add     %i2, 2, %o0! void *
F002A29C: 9207bfe8                 add     %fp, var_18, %o1! void *
F002A2A0: 4001aa1c                 call    _bcopy
F002A2A4: 9410200e                 mov     0xE, %o2
F002A2A8: d017bff4                 lduh    [%fp+var_C], %o0
F002A2AC: 1080001d                 ba      loc_F002A320
F002A2B0: d037bff4                 sth     %o0, [%fp+var_C]
F002A2B4: 90100018                 mov     %i0, %o0
F002A2B8: 400006cb                 call    _if_private
F002A2BC: d227bfe4                 st      %o1, [%fp+var_1C]
F002A2C0: d0022008                 ld      [%o0+8], %o0
F002A2C4: d027bfdc                 st      %o0, [%fp+var_24]
F002A2C8: 400006c7                 call    _if_private
F002A2CC: 90100018                 mov     %i0, %o0
F002A2D0: 9207bfe0                 add     %fp, var_20, %o1
F002A2D4: d223a05c                 st      %o1, [%sp+0x90+var_34]
F002A2D8: 92100008                 mov     %o0, %o1
F002A2DC: 90100018                 mov     %i0, %o0
F002A2E0: 9407bfdc                 add     %fp, var_24, %o2
F002A2E4: 96100019                 mov     %i1, %o3
F002A2E8: 9807bfe4                 add     %fp, var_1C, %o4
F002A2EC: 40000ce8                 call    _arpresolve
F002A2F0: 9a07bfe8                 add     %fp, var_18, %o5
F002A2F4: 80a22000                 cmp     %o0, 0
F002A2F8: 12800004                 bne     loc_F002A308
F002A2FC: 90102800                 mov     0x800, %o0
F002A300: 10800025                 ba      locret_F002A394
F002A304: b0102000                 mov     0, %i0
F002A308: 10800006                 ba      loc_F002A320
F002A30C: d037bff4                 sth     %o0, [%fp+var_C]
F002A310: 400005e5                 call    _nb_free
F002A314: 90100019                 mov     %i1, %o0
F002A318: 1080001f                 ba      locret_F002A394
F002A31C: b010202f                 mov     0x2F, %i0 ! '/'
F002A320: 90100019                 mov     %i1, %o0
F002A324: 4000061a                 call    _nb_grow_top
F002A328: 9210200e                 mov     0xE, %o1
F002A32C: 90100019                 mov     %i1, %o0
F002A330: 9210200c                 mov     0xC, %o1
F002A334: 94102002                 mov     2, %o2
F002A338: 9607bff4                 add     %fp, var_C, %o3
F002A33C: 400005fb                 call    _nb_write
F002A340: a007bfe8                 add     %fp, var_18, %l0
F002A344: 90100011                 mov     %l1, %o0
F002A348: 92100019                 mov     %i1, %o1
F002A34C: 40000625                 call    _if_output
F002A350: 94100010                 mov     %l0, %o2
F002A354: a0920000                 orcc    %o0, %g0, %l0
F002A358: 12800009                 bne     loc_F002A37C
F002A35C: 01000000                 nop
F002A360: 400006bd                 call    _if_opackets
F002A364: 90100018                 mov     %i0, %o0
F002A368: 92022001                 add     %o0, 1, %o1
F002A36C: 400006d2                 call    _if_opackets_set
F002A370: 90100018                 mov     %i0, %o0
F002A374: 10800008                 ba      locret_F002A394
F002A378: b0100010                 mov     %l0, %i0
F002A37C: 400006be                 call    _if_oerrors
F002A380: 90100018                 mov     %i0, %o0
F002A384: 92022001                 add     %o0, 1, %o1
F002A388: 400006d3                 call    _if_oerrors_set
F002A38C: 90100018                 mov     %i0, %o0
F002A390: b0100010                 mov     %l0, %i0
F002A394: 81c7e008                 ret
F002A398: 81e80000                 restore
