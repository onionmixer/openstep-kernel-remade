F00B308C: 9de3bf98                 save    %sp, -0x68, %sp
F00B3090: a0960000                 orcc    %i0, %g0, %l0
F00B3094: 02800022                 be      locret_F00B311C
F00B3098: b0102000                 mov     0, %i0
F00B309C: 7ffd50e7                 call    _strlen
F00B30A0: 90100010                 mov     %l0, %o0
F00B30A4: 10800005                 ba      loc_F00B30B8
F00B30A8: b0040008                 add     %l0, %o0, %i0
F00B30AC: 80a2203a                 cmp     %o0, 0x3A ! ':'
F00B30B0: 02800007                 be      loc_F00B30CC
F00B30B4: 90100018                 mov     %i0, %o0
F00B30B8: b0063fff                 inc     -1, %i0
F00B30BC: 80a60010                 cmp     %i0, %l0
F00B30C0: 32bffffb                 bne,a   loc_F00B30AC
F00B30C4: d04e0000                 ldsb    [%i0], %o0
F00B30C8: 90100018                 mov     %i0, %o0
F00B30CC: 80a20010                 cmp     %o0, %l0
F00B30D0: 02800006                 be      loc_F00B30E8
F00B30D4: b0062001                 inc     %i0
F00B30D8: f04e0000                 ldsb    [%i0], %i0
F00B30DC: 80a62000                 cmp     %i0, 0
F00B30E0: 12800004                 bne     loc_F00B30F0
F00B30E4: 92100018                 mov     %i0, %o1
F00B30E8: 1080000d                 ba      locret_F00B311C
F00B30EC: b0102000                 mov     0, %i0
F00B30F0: 90027f9f                 add     %o1, -0x61, %o0
F00B30F4: 900a20ff                 and     %o0, 0xFF, %o0
F00B30F8: 80a22019                 cmp     %o0, 0x19
F00B30FC: 18800004                 bgu     loc_F00B310C
F00B3100: 90027fd0                 add     %o1, -0x30, %o0
F00B3104: 10800006                 ba      locret_F00B311C
F00B3108: b0063f9f                 inc     -0x61, %i0
F00B310C: 900a20ff                 and     %o0, 0xFF, %o0
F00B3110: 80a22009                 cmp     %o0, 9
F00B3114: 28800002                 bleu,a  locret_F00B311C
F00B3118: b0063fd0                 inc     -0x30, %i0
F00B311C: 81c7e008                 ret
F00B3120: 81e80000                 restore
