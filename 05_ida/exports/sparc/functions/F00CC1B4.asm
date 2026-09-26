F00CC1B4: 9de3bf98                 save    %sp, -0x68, %sp
F00CC1B8: 113c04cc                 sethi   %hi(dword_F01330C8), %o0
F00CC1BC: d00220c8                 ld      [%o0+%lo(dword_F01330C8)], %o0
F00CC1C0: 80a22000                 cmp     %o0, 0
F00CC1C4: 02800008                 be      locret_F00CC1E4
F00CC1C8: 133c04cc                 sethi   %hi(dword_F01330D4), %o1
F00CC1CC: 173c0506                 sethi   %hi(paResetandenable), %o3
F00CC1D0: d80260d4                 ld      [%o1+%lo(dword_F01330D4)], %o4
F00CC1D4: 952e2018                 sll     %i0, 24, %o2
F00CC1D8: d202e038                 ld      [%o3+%lo(paResetandenable)], %o1
F00CC1DC: 9fc30000                 call    %o4
F00CC1E0: 953aa018                 sra     %o2, 24, %o2
F00CC1E4: 81c7e008                 ret
F00CC1E8: 81e80000                 restore
