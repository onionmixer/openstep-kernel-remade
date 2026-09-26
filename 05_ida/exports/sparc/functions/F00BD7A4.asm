F00BD7A4: 9de3bf98                 save    %sp, -0x68, %sp
F00BD7A8: 40001157                 call    _TYPE5StealKeyEvent
F00BD7AC: 01000000                 nop
F00BD7B0: 80a22000                 cmp     %o0, 0
F00BD7B4: 02800007                 be      locret_F00BD7D0
F00BD7B8: b0103fff                 mov     -1, %i0
F00BD7BC: 7ffffdc4                 call    sub_F00BCECC
F00BD7C0: 01000000                 nop
F00BD7C4: 80a22100                 cmp     %o0, 0x100
F00BD7C8: 32800002                 bne,a   locret_F00BD7D0
F00BD7CC: b0100008                 mov     %o0, %i0
F00BD7D0: 81c7e008                 ret
F00BD7D4: 81e80000                 restore
