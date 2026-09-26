F0045484: 9de3bf98                 save    %sp, -0x68, %sp
F0045488: 90100018                 mov     %i0, %o0
F004548C: d2020000                 ld      [%o0], %o1
F0045490: 80a26000                 cmp     %o1, 0
F0045494: 12800005                 bne     loc_F00454A8
F0045498: 80a26001                 cmp     %o1, 1
F004549C: d2022004                 ld      [%o0+4], %o1
F00454A0: 10800006                 ba      loc_F00454B8
F00454A4: d4026004                 ld      [%o1+4], %o2
F00454A8: 12800008                 bne     loc_F00454C8
F00454AC: 80a26002                 cmp     %o1, 2
F00454B0: d2022004                 ld      [%o0+4], %o1
F00454B4: d4024000                 ld      [%o1], %o2
F00454B8: 9fc28000                 call    %o2
F00454BC: 92100019                 mov     %i1, %o1
F00454C0: 10800009                 ba      locret_F00454E4
F00454C4: b0100008                 mov     %o0, %i0
F00454C8: 02800006                 be      loc_F00454E0
F00454CC: 113c0437                 sethi   %hi(aXdrLongFailed), %o0! "xdr_long: FAILED\n"
F00454D0: 7fff3c62                 call    _printf
F00454D4: 90122298                 bset    %lo(aXdrLongFailed), %o0! "xdr_long: FAILED\n"
F00454D8: 10800003                 ba      locret_F00454E4
F00454DC: b0102000                 mov     0, %i0
F00454E0: b0102001                 mov     1, %i0
F00454E4: 81c7e008                 ret
F00454E8: 81e80000                 restore
