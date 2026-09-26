F00A5B98: 9de3bf98                 save    %sp, -0x68, %sp
F00A5B9C: 133c0466                 sethi   %hi(_mon_clock_on), %o1
F00A5BA0: d04a6140                 ldsb    [%o1+%lo(_mon_clock_on)], %o0
F00A5BA4: 80a22000                 cmp     %o0, 0
F00A5BA8: 02800009                 be      locret_F00A5BCC
F00A5BAC: 90102000                 mov     0, %o0
F00A5BB0: c02a6140                 clrb    [%o1+%lo(_mon_clock_on)]
F00A5BB4: 7ffffdee                 call    _set_clk_mode
F00A5BB8: 92102080                 mov     0x80, %o1
F00A5BBC: 9010200e                 mov     0xE, %o0
F00A5BC0: 133c0428                 sethi   %hi(_kclock14_vec), %o1
F00A5BC4: 40000004                 call    _write_scb_int
F00A5BC8: 92126000                 bset    %lo(_kclock14_vec), %o1
F00A5BCC: 81c7e008                 ret
F00A5BD0: 81e80000                 restore
