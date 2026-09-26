F002BA10: 9de3bf98                 save    %sp, -0x68, %sp
F002BA14: a2062004                 add     %i0, 4, %l1
F002BA18: 4000f196                 call    _kalloc
F002BA1C: 90100011                 mov     %l1, %o0
F002BA20: a0920000                 orcc    %o0, %g0, %l0
F002BA24: 0280000d                 be      loc_F002BA58
F002BA28: 153c00ae                 sethi   %hi(sub_F002B9F8), %o2
F002BA2C: e2240000                 st      %l1, [%l0]
F002BA30: 90042004                 add     %l0, 4, %o0
F002BA34: 92100018                 mov     %i0, %o1
F002BA38: 9412a1f8                 bset    %lo(sub_F002B9F8), %o2
F002BA3C: 4000000a                 call    _nb_alloc_wrapper
F002BA40: 96100010                 mov     %l0, %o3
F002BA44: 80a22000                 cmp     %o0, 0
F002BA48: 12800005                 bne     locret_F002BA5C
F002BA4C: b0100008                 mov     %o0, %i0
F002BA50: 7fffffea                 call    sub_F002B9F8
F002BA54: 90100010                 mov     %l0, %o0
F002BA58: b0102000                 mov     0, %i0
F002BA5C: 81c7e008                 ret
F002BA60: 81e80000                 restore
