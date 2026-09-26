F00C1C9C: 9de3bf88                 save    %sp, -0x78, %sp
F00C1CA0: 113c0483                 sethi   %hi(_kbddev+1), %o0
F00C1CA4: d40a2225                 ldub    [%o0+%lo(_kbddev+1)], %o2
F00C1CA8: 9007bfec                 add     %fp, var_14, %o0
F00C1CAC: 932aa004                 sll     %o2, 4, %o1
F00C1CB0: 9202400a                 add     %o1, %o2, %o1
F00C1CB4: 932a6003                 sll     %o1, 3, %o1
F00C1CB8: 153c04fb9412a260         set     _zs_tty, %o2
F00C1CC0: 9202400a                 add     %o1, %o2, %o1
F00C1CC4: 7ffffc8c                 call    sub_F00C0EF4
F00C1CC8: d227bfec                 st      %o1, [%fp+var_14]
F00C1CCC: b52ea018                 sll     %i2, 24, %i2
F00C1CD0: 80a6a000                 cmp     %i2, 0
F00C1CD4: 02800005                 be      loc_F00C1CE8
F00C1CD8: 92100008                 mov     %o0, %o1
F00C1CDC: d00a602a                 ldub    [%o1+0x2A], %o0
F00C1CE0: 10800004                 ba      loc_F00C1CF0
F00C1CE4: 90122008                 bset    8, %o0
F00C1CE8: d00a602a                 ldub    [%o1+0x2A], %o0
F00C1CEC: 900a3ff7                 and     %o0, -9, %o0
F00C1CF0: d02a602a                 stb     %o0, [%o1+0x2A]
F00C1CF4: 7ffffe46                 call    sub_F00C160C
F00C1CF8: d007bfec                 ld      [%fp+var_14], %o0
F00C1CFC: 81c7e008                 ret
F00C1D00: 81e80000                 restore
