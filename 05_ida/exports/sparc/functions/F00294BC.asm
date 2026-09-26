F00294BC: 9de3bf38                 save    %sp, -0xC8, %sp! int
F00294C0: 233c04cf                 sethi   %hi(dword_F0133DDC), %l1
F00294C4: d00461dc                 ld      [%l1+%lo(dword_F0133DDC)], %o0
F00294C8: e4022024                 ld      [%o0+0x24], %l2
F00294CC: 9207bf9c                 add     %fp, var_64, %o1
F00294D0: 1100003f                 sethi   0xFC00, %o0
F00294D4: d4048000                 ld      [%l2], %o2
F00294D8: 901223ff                 bset    0x3FF, %o0
F00294DC: 7fffeb66                 call    _vafsidtovfs
F00294E0: 900a8008                 and     %o2, %o0, %o0
F00294E4: d20461dc                 ld      [%l1+%lo(dword_F0133DDC)], %o1
F00294E8: d02a6038                 stb     %o0, [%o1+0x38]
F00294EC: d00461dc                 ld      [%l1+%lo(dword_F0133DDC)], %o0
F00294F0: d04a2038                 ldsb    [%o0+0x38], %o0
F00294F4: 80a22000                 cmp     %o0, 0
F00294F8: 12800021                 bne     locret_F002957C
F00294FC: d007bf9c                 ld      [%fp+var_64], %o0
F0029500: d4022004                 ld      [%o0+4], %o2
F0029504: d402a00c                 ld      [%o2+0xC], %o2! int
F0029508: 9fc28000                 call    %o2
F002950C: 9207bfb8                 add     %fp, var_48, %o1
F0029510: d20461dc                 ld      [%l1+0x1DC], %o1! size_t
F0029514: d02a6038                 stb     %o0, [%o1+0x38]
F0029518: d00461dc                 ld      [%l1+0x1DC], %o0
F002951C: d04a2038                 ldsb    [%o0+0x38], %o0
F0029520: 80a22000                 cmp     %o0, 0
F0029524: 12800016                 bne     locret_F002957C
F0029528: a007bfa0                 add     %fp, var_60, %l0
F002952C: 90100010                 mov     %l0, %o0! void *
F0029530: 4001ae4a                 call    _bzero
F0029534: 92102014                 mov     0x14, %o1
F0029538: d007bfc8                 ld      [%fp+var_38], %o0
F002953C: 7fff73f1                 call    _umul
F0029540: d207bfbc                 ld      [%fp+var_44], %o1
F0029544: 92100008                 mov     %o0, %o1
F0029548: 908261ff                 addcc   %o1, 0x1FF, %o0
F002954C: 2c800002                 bneg,a  loc_F0029554
F0029550: 900263fe                 add     %o1, 0x3FE, %o0
F0029554: 913a2009                 sra     %o0, 9, %o0
F0029558: d027bfa0                 st      %o0, [%fp+var_60]
F002955C: d207bfd0                 ld      [%fp+var_30], %o1
F0029560: 90100010                 mov     %l0, %o0! int
F0029564: d227bfa4                 st      %o1, [%fp+var_5C]
F0029568: d204a004                 ld      [%l2+4], %o1! int
F002956C: 4001bad8                 call    _copyout
F0029570: 94102014                 mov     0x14, %o2
F0029574: d20461dc                 ld      [%l1+0x1DC], %o1
F0029578: d02a6038                 stb     %o0, [%o1+0x38]
F002957C: 81c7e008                 ret
F0029580: 81e80000                 restore
