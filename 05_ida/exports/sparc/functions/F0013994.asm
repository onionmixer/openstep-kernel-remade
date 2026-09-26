F0013994: 9de3bf98                 save    %sp, -0x68, %sp! int
F0013998: 213c04cf                 sethi   %hi(dword_F0133DDC), %l0
F001399C: d00421dc                 ld      [%l0+%lo(dword_F0133DDC)], %o0
F00139A0: d2022024                 ld      [%o0+0x24], %o1
F00139A4: 113c04d1                 sethi   %hi(_domainnamelen), %o0
F00139A8: d0022200                 ld      [%o0+%lo(_domainnamelen)], %o0
F00139AC: d4026004                 ld      [%o1+4], %o2
F00139B0: 90022001                 inc     %o0
F00139B4: 80a28008                 cmp     %o2, %o0
F00139B8: 38800002                 bgu,a   loc_F00139C0
F00139BC: 94100008                 mov     %o0, %o2! int
F00139C0: 113c04d1                 sethi   %hi(_domainname), %o0! int
F00139C4: d2024000                 ld      [%o1], %o1! int
F00139C8: 400211c1                 call    _copyout
F00139CC: 90122100                 bset    %lo(_domainname), %o0
F00139D0: d20421dc                 ld      [%l0+0x1DC], %o1
F00139D4: d02a6038                 stb     %o0, [%o1+0x38]
F00139D8: 81c7e008                 ret
F00139DC: 81e80000                 restore
