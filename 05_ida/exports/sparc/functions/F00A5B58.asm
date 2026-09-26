F00A5B58: 9de3bf98                 save    %sp, -0x68, %sp
F00A5B5C: 133c0466                 sethi   %hi(_mon_clock_on), %o1
F00A5B60: d04a6140                 ldsb    [%o1+%lo(_mon_clock_on)], %o0
F00A5B64: 80a22000                 cmp     %o0, 0
F00A5B68: 1280000a                 bne     locret_F00A5B90
F00A5B6C: 90102001                 mov     1, %o0
F00A5B70: d02a6140                 stb     %o0, [%o1+%lo(_mon_clock_on)]
F00A5B74: 9010200e                 mov     0xE, %o0
F00A5B78: 133c0428                 sethi   %hi(_mon_clock14_vec), %o1
F00A5B7C: 40000016                 call    _write_scb_int
F00A5B80: 92126010                 bset    %lo(_mon_clock14_vec), %o1
F00A5B84: 90102080                 mov     0x80, %o0
F00A5B88: 7ffffdf9                 call    _set_clk_mode
F00A5B8C: 92102000                 mov     0, %o1
F00A5B90: 81c7e008                 ret
F00A5B94: 81e80000                 restore
