F0029AC4: 9de3bf98                 save    %sp, -0x68, %sp
F0029AC8: d016200c                 lduh    [%i0+0xC], %o0
F0029ACC: e0062018                 ld      [%i0+0x18], %l0
F0029AD0: 900a3fbe                 and     %o0, -0x42, %o0
F0029AD4: 80a42000                 cmp     %l0, 0
F0029AD8: 02800009                 be      loc_F0029AFC
F0029ADC: d036200c                 sth     %o0, [%i0+0xC]
F0029AE0: 90102000                 mov     0, %o0! int
F0029AE4: 7fffce82                 call    _pfctlinput
F0029AE8: 92100010                 mov     %l0, %o1
F0029AEC: e0042024                 ld      [%l0+0x24], %l0
F0029AF0: 80a42000                 cmp     %l0, 0
F0029AF4: 12bffffc                 bne     loc_F0029AE4
F0029AF8: 90102000                 mov     0, %o0
F0029AFC: 40000004                 call    _if_qflush
F0029B00: 9006201c                 add     %i0, 0x1C, %o0
F0029B04: 81c7e008                 ret
F0029B08: 81e80000                 restore
