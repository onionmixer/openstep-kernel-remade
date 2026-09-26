F006A348: 9de3bf98                 save    %sp, -0x68, %sp
F006A34C: 80a62000                 cmp     %i0, 0
F006A350: 22800007                 be,a    locret_F006A36C
F006A354: b0102000                 mov     0, %i0
F006A358: c4062030                 ld      [%i0+0x30], %g2
F006A35C: 80a0a000                 cmp     %g2, 0
F006A360: 12800003                 bne     locret_F006A36C
F006A364: b0062038                 inc     0x38, %i0 ! '8'
F006A368: b0102000                 mov     0, %i0
F006A36C: 81c7e008                 ret
F006A370: 81e80000                 restore
