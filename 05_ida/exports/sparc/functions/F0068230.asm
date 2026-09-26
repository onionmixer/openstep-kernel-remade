F0068230: 9de3bf98                 save    %sp, -0x68, %sp
F0068234: a0062008                 add     %i0, 8, %l0
F0068238: 7fffff8e                 call    _kalloc
F006823C: 90100010                 mov     %l0, %o0! void *
F0068240: b0920000                 orcc    %o0, %g0, %i0
F0068244: 22800006                 be,a    locret_F006825C
F0068248: b0102000                 mov     0, %i0
F006824C: 4000b303                 call    _bzero
F0068250: 92100010                 mov     %l0, %o1
F0068254: e0260000                 st      %l0, [%i0]
F0068258: b0062008                 inc     8, %i0
F006825C: 81c7e008                 ret
F0068260: 81e80000                 restore
