F006F4FC: 9de3bf98                 save    %sp, -0x68, %sp
F006F500: a0960000                 orcc    %i0, %g0, %l0
F006F504: 02800005                 be      loc_F006F518
F006F508: 90067fff                 add     %i1, -1, %o0
F006F50C: 80a22003                 cmp     %o0, 3
F006F510: 08800004                 bleu    loc_F006F520
F006F514: b0042158                 add     %l0, 0x158, %i0
F006F518: 10800010                 ba      locret_F006F558
F006F51C: b0102004                 mov     4, %i0
F006F520: d0060000                 ld      [%i0], %o0
F006F524: 80a22000                 cmp     %o0, 0
F006F528: 12bffffe                 bne     loc_F006F520
F006F52C: 01000000                 nop
F006F530: 40009e5e                 call    _simple_lock_try
F006F534: 90100018                 mov     %i0, %o0
F006F538: 80a22000                 cmp     %o0, 0
F006F53C: 02bffff9                 be      loc_F006F520
F006F540: 01000000                 nop
F006F544: c0242158                 clr     [%l0+0x158]
F006F548: d0042168                 ld      [%l0+0x168], %o0
F006F54C: b0102000                 mov     0, %i0
F006F550: 90120019                 bset    %i1, %o0
F006F554: d0242168                 st      %o0, [%l0+0x168]
F006F558: 81c7e008                 ret
F006F55C: 81e80000                 restore
