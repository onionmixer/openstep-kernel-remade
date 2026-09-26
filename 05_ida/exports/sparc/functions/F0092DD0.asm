F0092DD0: 9de3bf98                 save    %sp, -0x68, %sp
F0092DD4: 912e2010                 sll     %i0, 16, %o0
F0092DD8: 40000017                 call    sub_F0092E34
F0092DDC: 913a2010                 sra     %o0, 16, %o0
F0092DE0: 94920000                 orcc    %o0, %g0, %o2
F0092DE4: 02800007                 be      loc_F0092E00
F0092DE8: 113c0504                 sethi   %hi(paBlocksize), %o0! id
F0092DEC: d2022188                 ld      [%o0+%lo(paBlocksize)], %o1! SEL
F0092DF0: 40017aa0                 call    _objc_msgSend
F0092DF4: 9010000a                 mov     %o2, %o0
F0092DF8: 10800003                 ba      locret_F0092E04
F0092DFC: b0100008                 mov     %o0, %i0
F0092E00: b0103fff                 mov     -1, %i0
F0092E04: 81c7e008                 ret
F0092E08: 81e80000                 restore
