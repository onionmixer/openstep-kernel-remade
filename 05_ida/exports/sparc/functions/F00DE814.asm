F00DE814: 9de3bf98                 save    %sp, -0x68, %sp
F00DE818: 90960000                 orcc    %i0, %g0, %o0! id
F00DE81C: 02800005                 be      loc_F00DE830
F00DE820: 94100019                 mov     %i1, %o2
F00DE824: 80a2a000                 cmp     %o2, 0
F00DE828: 12800004                 bne     loc_F00DE838
F00DE82C: 133c0505                 sethi   -0xFEBEC00, %o1! SEL
F00DE830: 10800005                 ba      locret_F00DE844
F00DE834: b01020ca                 mov     0xCA, %i0
F00DE838: 40004c0e                 call    _objc_msgSend
F00DE83C: d2026004                 ld      [%o1+4], %o1
F00DE840: b0102000                 mov     0, %i0
F00DE844: 81c7e008                 ret
F00DE848: 81e80000                 restore
