F002B958: 9de3bf98                 save    %sp, -0x68, %sp
F002B95C: 40000117                 call    _if_getbuf
F002B960: 90100018                 mov     %i0, %o0
F002B964: a4920000                 orcc    %o0, %g0, %l2
F002B968: 0280001f                 be      loc_F002B9E4
F002B96C: 01000000                 nop
F002B970: 40000049                 call    _nb_map
F002B974: 90100019                 mov     %i1, %o0
F002B978: a2100008                 mov     %o0, %l1
F002B97C: 40000046                 call    _nb_map
F002B980: 90100012                 mov     %l2, %o0
F002B984: a0100008                 mov     %o0, %l0
F002B988: 40000054                 call    _nb_size
F002B98C: 90100019                 mov     %i1, %o0
F002B990: 94100008                 mov     %o0, %o2! size_t
F002B994: 90100011                 mov     %l1, %o0! void *
F002B998: 4001a45e                 call    _bcopy
F002B99C: 92100010                 mov     %l0, %o1
F002B9A0: 4000004e                 call    _nb_size
F002B9A4: 90100012                 mov     %l2, %o0
F002B9A8: a0100008                 mov     %o0, %l0
F002B9AC: 4000004b                 call    _nb_size
F002B9B0: 90100019                 mov     %i1, %o0
F002B9B4: a0240008                 sub     %l0, %o0, %l0
F002B9B8: 90100012                 mov     %l2, %o0
F002B9BC: 4000007d                 call    _nb_shrink_bot
F002B9C0: 92100010                 mov     %l0, %o1
F002B9C4: 40000038                 call    _nb_free
F002B9C8: 90100019                 mov     %i1, %o0
F002B9CC: 90100018                 mov     %i0, %o0
F002B9D0: 92100012                 mov     %l2, %o1
F002B9D4: 40000083                 call    _if_output
F002B9D8: 9410001a                 mov     %i2, %o2
F002B9DC: 10800005                 ba      locret_F002B9F0
F002B9E0: b0100008                 mov     %o0, %i0
F002B9E4: 40000030                 call    _nb_free
F002B9E8: 90100019                 mov     %i1, %o0
F002B9EC: b0102001                 mov     1, %i0
F002B9F0: 81c7e008                 ret
F002B9F4: 81e80000                 restore
