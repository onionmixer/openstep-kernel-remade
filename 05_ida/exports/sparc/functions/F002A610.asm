F002A610: 9de3bf98                 save    %sp, -0x68, %sp
F002A614: 400005f4                 call    _if_private
F002A618: 90100018                 mov     %i0, %o0
F002A61C: 400005e7                 call    _if_getbuf
F002A620: d002200c                 ld      [%o0+0xC], %o0
F002A624: b0920000                 orcc    %o0, %g0, %i0
F002A628: 22800004                 be,a    locret_F002A638
F002A62C: b0102000                 mov     0, %i0
F002A630: 4000054e                 call    _nb_shrink_top
F002A634: 9210200e                 mov     0xE, %o1
F002A638: 81c7e008                 ret
F002A63C: 81e80000                 restore
