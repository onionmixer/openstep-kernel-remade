F0068300: 9de3bf98                 save    %sp, -0x68, %sp
F0068304: 80a62000                 cmp     %i0, 0
F0068308: 02800005                 be      locret_F006831C
F006830C: 01000000                 nop
F0068310: d2063ff8                 ld      [%i0-8], %o1
F0068314: 7fffffa3                 call    _kfree
F0068318: 90063ff8                 add     %i0, -8, %o0
F006831C: 81c7e008                 ret
F0068320: 81e80000                 restore
