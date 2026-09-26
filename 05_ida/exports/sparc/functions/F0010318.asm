F0010318: 9de3bf98                 save    %sp, -0x68, %sp! int
F001031C: 213c04cf                 sethi   %hi(dword_F0133DDC), %l0
F0010320: d20421dc                 ld      [%l0+%lo(dword_F0133DDC)], %o1
F0010324: d4026024                 ld      [%o1+0x24], %o2! int
F0010328: d0028000                 ld      [%o2], %o0
F001032C: 80a22005                 cmp     %o0, 5
F0010330: 08800004                 bleu    loc_F0010340
F0010334: 961421dc                 or      %l0, %lo(dword_F0133DDC), %o3! int
F0010338: 1080000a                 ba      loc_F0010360
F001033C: 90102016                 mov     0x16, %o0
F0010340: 912a2003                 sll     %o0, 3, %o0
F0010344: d202fffc                 ld      [%o3-4], %o1
F0010348: 90022260                 inc     0x260, %o0
F001034C: 90024008                 add     %o1, %o0, %o0! int
F0010350: d202a004                 ld      [%o2+4], %o1! int
F0010354: 40021f5e                 call    _copyout
F0010358: 94102008                 mov     8, %o2
F001035C: d20421dc                 ld      [%l0+0x1DC], %o1
F0010360: d02a6038                 stb     %o0, [%o1+0x38]
F0010364: 81c7e008                 ret
F0010368: 81e80000                 restore
