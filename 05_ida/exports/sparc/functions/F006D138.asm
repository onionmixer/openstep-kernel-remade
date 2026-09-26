F006D138: 9de3bf98                 save    %sp, -0x68, %sp
F006D13C: f0060000                 ld      [%i0], %i0
F006D140: 80a62000                 cmp     %i0, 0
F006D144: 0280000e                 be      loc_F006D17C
F006D148: 11020000                 sethi   0x8000000, %o0
F006D14C: d2062038                 ld      [%i0+0x38], %o1
F006D150: 808a4008                 btst    %o0, %o1
F006D154: 2280000b                 be,a    locret_F006D180
F006D158: b0102000                 mov     0, %i0
F006D15C: 7ffffdcb                 call    _vmp_get
F006D160: 90100018                 mov     %i0, %o0
F006D164: 40000127                 call    _vmp_push
F006D168: 90100018                 mov     %i0, %o0
F006D16C: 7ffffde2                 call    _vmp_put
F006D170: 90100018                 mov     %i0, %o0
F006D174: 10800003                 ba      locret_F006D180
F006D178: f0062034                 ld      [%i0+0x34], %i0
F006D17C: b0102000                 mov     0, %i0
F006D180: 81c7e008                 ret
F006D184: 81e80000                 restore
