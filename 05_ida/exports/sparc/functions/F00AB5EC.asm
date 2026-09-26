F00AB5EC: 9de3bf98                 save    %sp, -0x68, %sp
F00AB5F0: 9410001a                 mov     %i2, %o2
F00AB5F4: d002a004                 ld      [%o2+4], %o0
F00AB5F8: 80a22003                 cmp     %o0, 3
F00AB5FC: 14800006                 bg      loc_F00AB614
F00AB600: 9610001b                 mov     %i3, %o3
F00AB604: d2028000                 ld      [%o2], %o1
F00AB608: 90102001                 mov     1, %o0
F00AB60C: 90220009                 sub     %o0, %o1, %o0
F00AB610: d0228000                 st      %o0, [%o2]
F00AB614: d2064000                 ld      [%i1], %o1
F00AB618: d0028000                 ld      [%o2], %o0
F00AB61C: 80a24008                 cmp     %o1, %o0
F00AB620: 12800005                 bne     loc_F00AB634
F00AB624: 90100018                 mov     %i0, %o0
F00AB628: 7ffffe90                 call    sub_F00AB068
F00AB62C: 92100019                 mov     %i1, %o1
F00AB630: 30800003                 ba,a    locret_F00AB63C
F00AB634: 7ffffef9                 call    sub_F00AB218
F00AB638: 92100019                 mov     %i1, %o1
F00AB63C: 81c7e008                 ret
F00AB640: 81e80000                 restore
