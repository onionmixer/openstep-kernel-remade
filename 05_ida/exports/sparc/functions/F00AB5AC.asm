F00AB5AC: 9de3bf98                 save    %sp, -0x68, %sp
F00AB5B0: d2064000                 ld      [%i1], %o1
F00AB5B4: 9410001a                 mov     %i2, %o2
F00AB5B8: d0028000                 ld      [%o2], %o0
F00AB5BC: 80a24008                 cmp     %o1, %o0
F00AB5C0: 12800006                 bne     loc_F00AB5D8
F00AB5C4: 9610001b                 mov     %i3, %o3
F00AB5C8: 90100018                 mov     %i0, %o0
F00AB5CC: 7ffffea7                 call    sub_F00AB068
F00AB5D0: 92100019                 mov     %i1, %o1
F00AB5D4: 30800004                 ba,a    locret_F00AB5E4
F00AB5D8: 90100018                 mov     %i0, %o0
F00AB5DC: 7fffff0f                 call    sub_F00AB218
F00AB5E0: 92100019                 mov     %i1, %o1
F00AB5E4: 81c7e008                 ret
F00AB5E8: 81e80000                 restore
