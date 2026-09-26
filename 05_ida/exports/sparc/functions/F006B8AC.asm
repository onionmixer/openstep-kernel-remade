F006B8AC: 9de3bf98                 save    %sp, -0x68, %sp
F006B8B0: d0062028                 ld      [%i0+0x28], %o0
F006B8B4: 80a227a7                 cmp     %o0, 0x7A7
F006B8B8: 32800005                 bne,a   locret_F006B8CC
F006B8BC: b0102000                 mov     0, %i0
F006B8C0: 7fffff51                 call    sub_F006B604
F006B8C4: 90100018                 mov     %i0, %o0
F006B8C8: b0102001                 mov     1, %i0
F006B8CC: 81c7e008                 ret
F006B8D0: 81e80000                 restore
