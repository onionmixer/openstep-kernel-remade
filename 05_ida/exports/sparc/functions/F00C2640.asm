F00C2640: 9de3bf98                 save    %sp, -0x68, %sp
F00C2644: 40000160                 call    sub_F00C2BC4
F00C2648: 90100018                 mov     %i0, %o0
F00C264C: a0920000                 orcc    %o0, %g0, %l0
F00C2650: 02800010                 be      locret_F00C2690
F00C2654: 01000000                 nop
F00C2658: d0040000                 ld      [%l0], %o0
F00C265C: 80a22000                 cmp     %o0, 0
F00C2660: 02800004                 be      loc_F00C2670
F00C2664: 01000000                 nop
F00C2668: 7ffe96ce                 call    _kfree
F00C266C: d2542004                 ldsh    [%l0+4], %o1! size_t
F00C2670: 7ffd55cb                 call    _ttyclose
F00C2674: 90100018                 mov     %i0, %o0
F00C2678: 90100010                 mov     %l0, %o0! void *
F00C267C: 7fff49f7                 call    _bzero
F00C2680: 92102034                 mov     0x34, %o1 ! '4'! size_t
F00C2684: 90100010                 mov     %l0, %o0! void *
F00C2688: 7fff49f4                 call    _bzero
F00C268C: 92102018                 mov     0x18, %o1
F00C2690: 81c7e008                 ret
F00C2694: 81e80000                 restore
