F003C0BC: 9de3bf98                 save    %sp, -0x68, %sp
F003C0C0: d0064000                 ld      [%i1], %o0
F003C0C4: a0102000                 mov     0, %l0
F003C0C8: 80a40008                 cmp     %l0, %o0
F003C0CC: 3a800011                 bcc,a   locret_F003C110
F003C0D0: b0102000                 mov     0, %i0
F003C0D4: 90100018                 mov     %i0, %o0
F003C0D8: d4066004                 ld      [%i1+4], %o2
F003C0DC: 932c2004                 sll     %l0, 4, %o1
F003C0E0: 7fffffe7                 call    sub_F003C07C
F003C0E4: 92028009                 add     %o2, %o1, %o1
F003C0E8: 80a22000                 cmp     %o0, 0
F003C0EC: 22800004                 be,a    loc_F003C0FC
F003C0F0: d0064000                 ld      [%i1], %o0
F003C0F4: 10800007                 ba      locret_F003C110
F003C0F8: b0102001                 mov     1, %i0
F003C0FC: a0042001                 inc     %l0
F003C100: 80a40008                 cmp     %l0, %o0
F003C104: 0abffff5                 bcs     loc_F003C0D8
F003C108: 90100018                 mov     %i0, %o0
F003C10C: b0102000                 mov     0, %i0
F003C110: 81c7e008                 ret
F003C114: 81e80000                 restore
