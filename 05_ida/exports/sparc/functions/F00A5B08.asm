F00A5B08: 9de3bf98                 save    %sp, -0x68, %sp
F00A5B0C: 113c0466                 sethi   %hi(_mon_clock_on), %o0
F00A5B10: 133c0008                 sethi   %hi(dword_F00021E0), %o1
F00A5B14: d60261e0                 ld      [%o1+%lo(dword_F00021E0)], %o3
F00A5B18: 153c0428                 sethi   %hi(_kclock14_vec), %o2
F00A5B1C: d622a000                 st      %o3, [%o2+%lo(_kclock14_vec)]
F00A5B20: 921261e0                 bset    %lo(dword_F00021E0), %o1
F00A5B24: d6026004                 ld      [%o1+4], %o3
F00A5B28: c02a2140                 clrb    [%o0+%lo(_mon_clock_on)]
F00A5B2C: d8026008                 ld      [%o1+8], %o4
F00A5B30: 9412a000                 bset    %lo(_kclock14_vec), %o2
F00A5B34: d622a004                 st      %o3, [%o2+4]
F00A5B38: d202600c                 ld      [%o1+0xC], %o1
F00A5B3C: 90102000                 mov     0, %o0
F00A5B40: d822a008                 st      %o4, [%o2+8]
F00A5B44: d222a00c                 st      %o1, [%o2+0xC]
F00A5B48: 7ffffe09                 call    _set_clk_mode
F00A5B4C: 92102080                 mov     0x80, %o1
F00A5B50: 81c7e008                 ret
F00A5B54: 81e80000                 restore
