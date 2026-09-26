F0068284: 9de3bf98                 save    %sp, -0x68, %sp
F0068288: 80a62000                 cmp     %i0, 0
F006828C: 12800006                 bne     loc_F00682A4
F0068290: a4063ff8                 add     %i0, -8, %l2
F0068294: 7fffffe7                 call    _malloc
F0068298: 90100019                 mov     %i1, %o0
F006829C: 10800017                 ba      locret_F00682F8
F00682A0: b0100008                 mov     %o0, %i0
F00682A4: a2066008                 add     %i1, 8, %l1
F00682A8: 7fffff72                 call    _kalloc
F00682AC: 90100011                 mov     %l1, %o0
F00682B0: a0920000                 orcc    %o0, %g0, %l0
F00682B4: 32800004                 bne,a   loc_F00682C4
F00682B8: e2240000                 st      %l1, [%l0]
F00682BC: 1080000f                 ba      locret_F00682F8
F00682C0: b0102000                 mov     0, %i0
F00682C4: d4063ff8                 ld      [%i0-8], %o2
F00682C8: 80a28019                 cmp     %o2, %i1
F00682CC: 08800005                 bleu    loc_F00682E0
F00682D0: 92042008                 add     %l0, 8, %o1! void *
F00682D4: 90100018                 mov     %i0, %o0
F00682D8: 10800003                 ba      loc_F00682E4
F00682DC: 94100019                 mov     %i1, %o2! size_t
F00682E0: 90100018                 mov     %i0, %o0! void *
F00682E4: 4000b20b                 call    _bcopy
F00682E8: b0042008                 add     %l0, 8, %i0
F00682EC: d2048000                 ld      [%l2], %o1
F00682F0: 7fffffac                 call    _kfree
F00682F4: 90100012                 mov     %l2, %o0
F00682F8: 81c7e008                 ret
F00682FC: 81e80000                 restore
