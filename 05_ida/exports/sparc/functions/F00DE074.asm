F00DE074: 9de3bf98                 save    %sp, -0x68, %sp
F00DE078: 90960000                 orcc    %i0, %g0, %o0! id
F00DE07C: 02800007                 be      loc_F00DE098
F00DE080: 94100019                 mov     %i1, %o2
F00DE084: 133c0505                 sethi   %hi(paSetexclusiveus), %o1! SEL
F00DE088: 40004dfa                 call    _objc_msgSend
F00DE08C: d202601c                 ld      [%o1+%lo(paSetexclusiveus)], %o1
F00DE090: 10800003                 ba      locret_F00DE09C
F00DE094: b0102000                 mov     0, %i0
F00DE098: b01020ca                 mov     0xCA, %i0
F00DE09C: 81c7e008                 ret
F00DE0A0: 81e80000                 restore
