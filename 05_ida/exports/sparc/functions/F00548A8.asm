F00548A8: 9de3bf98                 save    %sp, -0x68, %sp
F00548AC: 91366006                 srl     %i1, 6, %o0
F00548B0: f2062018                 ld      [%i0+0x18], %i1
F00548B4: f0062014                 ld      [%i0+0x14], %i0
F00548B8: 7ffec7fa                 call    _urem
F00548BC: 92100019                 mov     %i1, %o1
F00548C0: 10800005                 ba      loc_F00548D4
F00548C4: 92100008                 mov     %o0, %o1
F00548C8: 80a24019                 cmp     %o1, %i1
F00548CC: 22800002                 be,a    loc_F00548D4
F00548D0: 92102000                 mov     0, %o1
F00548D4: 912a6004                 sll     %o1, 4, %o0
F00548D8: 90060008                 add     %i0, %o0, %o0
F00548DC: d002200c                 ld      [%o0+0xC], %o0
F00548E0: 80a22000                 cmp     %o0, 0
F00548E4: 32bffff9                 bne,a   loc_F00548C8
F00548E8: 92026001                 inc     %o1
F00548EC: 912a6004                 sll     %o1, 4, %o0
F00548F0: 90060008                 add     %i0, %o0, %o0
F00548F4: f422200c                 st      %i2, [%o0+0xC]
F00548F8: 81c7e008                 ret
F00548FC: 81e80000                 restore
