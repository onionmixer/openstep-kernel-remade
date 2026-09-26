F006E388: 9de3bf98                 save    %sp, -0x68, %sp
F006E38C: 4000a55f                 call    _clock_value
F006E390: 90102001                 mov     1, %o0
F006E394: 173c04be                 sethi   %hi(qword_F012F920), %o3
F006E398: d402e120                 ld      [%o3+%lo(qword_F012F920)], %o2
F006E39C: a4100008                 mov     %o0, %l2
F006E3A0: a6100009                 mov     %o1, %l3
F006E3A4: 80a2a000                 cmp     %o2, 0
F006E3A8: 12800006                 bne     loc_F006E3C0
F006E3AC: 9012e120                 or      %o3, %lo(qword_F012F920), %o0
F006E3B0: d0022004                 ld      [%o0+4], %o0
F006E3B4: 80a22000                 cmp     %o0, 0
F006E3B8: 22800002                 be,a    loc_F006E3C0
F006E3BC: e43ae120                 std     %l2, [%o3+%lo(qword_F012F920)]
F006E3C0: 213c04be                 sethi   %hi(qword_F012F920), %l0
F006E3C4: d01c2120                 ldd     [%l0+%lo(qword_F012F920)], %o0
F006E3C8: 94102000                 mov     0, %o2
F006E3CC: 961023e8                 mov     0x3E8, %o3
F006E3D0: 92a4c009                 subcc   %l3, %o1, %o1
F006E3D4: 90648008                 subc    %l2, %o0, %o0
F006E3D8: 7ffe5e86                 call    __udivdi3
F006E3DC: 01000000                 nop
F006E3E0: e43c2120                 std     %l2, [%l0+%lo(qword_F012F920)]
F006E3E4: 81c7e008                 ret
F006E3E8: 91e80009                 restore %g0, %o1, %o0
