F00F0620: 9de3bf98                 save    %sp, -0x68, %sp
F00F0624: a0102000                 mov     0, %l0
F00F0628: 7fffff88                 call    sub_F00F0448
F00F062C: d0062004                 ld      [%i0+4], %o0
F00F0630: 92100008                 mov     %o0, %o1
F00F0634: d00a4000                 ldub    [%o1], %o0
F00F0638: 90023fd0                 inc     -0x30, %o0
F00F063C: 900a20ff                 and     %o0, 0xFF, %o0
F00F0640: 80a22009                 cmp     %o0, 9
F00F0644: 28bffffc                 bleu,a  loc_F00F0634
F00F0648: 92026001                 inc     %o1
F00F064C: 10800012                 ba      loc_F00F0694
F00F0650: d04a4000                 ldsb    [%o1], %o0
F00F0654: 7fffff7d                 call    sub_F00F0448
F00F0658: 90100009                 mov     %o1, %o0
F00F065C: 92100008                 mov     %o0, %o1
F00F0660: d04a4000                 ldsb    [%o1], %o0
F00F0664: 80a2202d                 cmp     %o0, 0x2D ! '-'
F00F0668: 32800004                 bne,a   loc_F00F0678
F00F066C: d00a4000                 ldub    [%o1], %o0
F00F0670: 92026001                 inc     %o1
F00F0674: d00a4000                 ldub    [%o1], %o0
F00F0678: 90023fd0                 inc     -0x30, %o0
F00F067C: 900a20ff                 and     %o0, 0xFF, %o0
F00F0680: 80a22009                 cmp     %o0, 9
F00F0684: 28bffffc                 bleu,a  loc_F00F0674
F00F0688: 92026001                 inc     %o1
F00F068C: a0042001                 inc     %l0
F00F0690: d04a4000                 ldsb    [%o1], %o0
F00F0694: 80a22000                 cmp     %o0, 0
F00F0698: 12bfffef                 bne     loc_F00F0654
F00F069C: 01000000                 nop
F00F06A0: 81c7e008                 ret
F00F06A4: 91e80010                 restore %g0, %l0, %o0
