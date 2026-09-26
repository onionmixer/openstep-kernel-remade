F00B3124: 9de3bf98                 save    %sp, -0x68, %sp
F00B3128: d006600c                 ld      [%i1+0xC], %o0
F00B312C: 80a22000                 cmp     %o0, 0
F00B3130: 22800004                 be,a    loc_F00B3140
F00B3134: 113c0477                 sethi   -0xFEE2400, %o0
F00B3138: 1080001c                 ba      locret_F00B31A8
F00B313C: b0100008                 mov     %o0, %i0
F00B3140: d00221a0                 ld      [%o0+0x1A0], %o0
F00B3144: 80a22000                 cmp     %o0, 0
F00B3148: 02800007                 be      loc_F00B3164
F00B314C: 113c0477                 sethi   %hi(aCheckingDeviXU), %o0! "\tchecking devi <%x> unit <%d> name <%s"...
F00B3150: d406202c                 ld      [%i0+0x2C], %o2
F00B3154: 90122270                 bset    %lo(aCheckingDeviXU), %o0! "\tchecking devi <%x> unit <%d> name <%s"...
F00B3158: d606200c                 ld      [%i0+0xC], %o3
F00B315C: 7ffd853f                 call    _printf
F00B3160: 92100018                 mov     %i0, %o1! __s2
F00B3164: d006200c                 ld      [%i0+0xC], %o0! __s1
F00B3168: 7ffd5411                 call    _strcmp
F00B316C: d2064000                 ld      [%i1], %o1
F00B3170: 80a22000                 cmp     %o0, 0
F00B3174: 3280000d                 bne,a   locret_F00B31A8
F00B3178: b0102000                 mov     0, %i0
F00B317C: d2066008                 ld      [%i1+8], %o1
F00B3180: 80a27fff                 cmp     %o1, -1
F00B3184: 22800009                 be,a    locret_F00B31A8
F00B3188: f026600c                 st      %i0, [%i1+0xC]
F00B318C: d006202c                 ld      [%i0+0x2C], %o0
F00B3190: 80a24008                 cmp     %o1, %o0
F00B3194: 32800004                 bne,a   loc_F00B31A4
F00B3198: c026600c                 clr     [%i1+0xC]
F00B319C: 10800003                 ba      locret_F00B31A8
F00B31A0: f026600c                 st      %i0, [%i1+0xC]
F00B31A4: b0102000                 mov     0, %i0
F00B31A8: 81c7e008                 ret
F00B31AC: 81e80000                 restore
