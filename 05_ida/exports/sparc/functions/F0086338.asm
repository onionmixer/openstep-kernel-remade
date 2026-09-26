F0086338: 9de3bf98                 save    %sp, -0x68, %sp
F008633C: 153c04f3                 sethi   %hi(_mem_region), %o2
F0086340: 113c04f4                 sethi   %hi(_num_regions), %o0
F0086344: d2022330                 ld      [%o0+%lo(_num_regions)], %o1
F0086348: 9412a030                 bset    %lo(_mem_region), %o2
F008634C: 912a6003                 sll     %o1, 3, %o0
F0086350: 90220009                 sub     %o0, %o1, %o0
F0086354: 912a2002                 sll     %o0, 2, %o0
F0086358: 9202000a                 add     %o0, %o2, %o1
F008635C: 80a28009                 cmp     %o2, %o1
F0086360: 1a800017                 bcc     loc_F00863BC
F0086364: 98102000                 mov     0, %o4
F0086368: 113c04f4                 sethi   %hi(_page_shift), %o0
F008636C: c4022348                 ld      [%o0+%lo(_page_shift)], %g2
F0086370: 9a100009                 mov     %o1, %o5
F0086374: 9202a00c                 add     %o2, 0xC, %o1
F0086378: d6026008                 ld      [%o1+8], %o3
F008637C: 80a6000b                 cmp     %i0, %o3
F0086380: 0a80000a                 bcs     loc_F00863A8
F0086384: 9402a01c                 inc     0x1C, %o2
F0086388: d002600c                 ld      [%o1+0xC], %o0
F008638C: 80a60008                 cmp     %i0, %o0
F0086390: 3a800007                 bcc,a   loc_F00863AC
F0086394: d0024000                 ld      [%o1], %o0
F0086398: b026000b                 sub     %i0, %o3, %i0
F008639C: b1360002                 srl     %i0, %g2, %i0
F00863A0: 1080000a                 ba      locret_F00863C8
F00863A4: b0030018                 add     %o4, %i0, %i0
F00863A8: d0024000                 ld      [%o1], %o0
F00863AC: 80a2800d                 cmp     %o2, %o5
F00863B0: 98030008                 add     %o4, %o0, %o4
F00863B4: 0abffff1                 bcs     loc_F0086378
F00863B8: 9202601c                 inc     0x1C, %o1
F00863BC: 113c0446                 sethi   %hi(aMemPpi), %o0! "mem_ppi"
F00863C0: 7ffe3b6c                 call    _panic
F00863C4: 901222e0                 bset    %lo(aMemPpi), %o0! "mem_ppi"
F00863C8: 81c7e008                 ret
F00863CC: 81e80000                 restore
