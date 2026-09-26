F00A47E4: 9de3bf98                 save    %sp, -0x68, %sp
F00A47E8: 153c0465                 sethi   %hi(dword_F01197AC), %o2
F00A47EC: d202a3ac                 ld      [%o2+%lo(dword_F01197AC)], %o1
F00A47F0: 80a26000                 cmp     %o1, 0
F00A47F4: 12800006                 bne     loc_F00A480C
F00A47F8: 113c04f4                 sethi   -0xFEC3000, %o0
F00A47FC: 113c04f390122030         set     _mem_region, %o0
F00A4804: 1080000a                 ba      loc_F00A482C
F00A4808: d022a3ac                 st      %o0, [%o2+%lo(dword_F01197AC)]
F00A480C: 90122330                 bset    0x330, %o0
F00A4810: 80a24008                 cmp     %o1, %o0
F00A4814: 08800006                 bleu    loc_F00A482C
F00A4818: 113c0465                 sethi   %hi(aMoreThanDDisco), %o0! "more than %d discontiguous memory chunk"...
F00A481C: 901223b0                 bset    %lo(aMoreThanDDisco), %o0! "more than %d discontiguous memory chunk"...
F00A4820: 7ffdbf8e                 call    _printf
F00A4824: 92102040                 mov     0x40, %o1 ! '@'
F00A4828: 3080000d                 ba,a    locret_F00A485C
F00A482C: 193c0465                 sethi   %hi(dword_F01197AC), %o4
F00A4830: 96060019                 add     %i0, %i1, %o3
F00A4834: d20323ac                 ld      [%o4+%lo(dword_F01197AC)], %o1
F00A4838: 153c04f4                 sethi   %hi(_num_regions), %o2
F00A483C: d002a330                 ld      [%o2+%lo(_num_regions)], %o0
F00A4840: f0226010                 st      %i0, [%o1+0x10]
F00A4844: f0226014                 st      %i0, [%o1+0x14]
F00A4848: d6226018                 st      %o3, [%o1+0x18]
F00A484C: 90022001                 inc     %o0
F00A4850: d022a330                 st      %o0, [%o2+%lo(_num_regions)]
F00A4854: 9202601c                 inc     0x1C, %o1
F00A4858: d22323ac                 st      %o1, [%o4+%lo(dword_F01197AC)]
F00A485C: 81c7e008                 ret
F00A4860: 81e80000                 restore
