F00773A8: 9de3bf98                 save    %sp, -0x68, %sp
F00773AC: 113c04c3                 sethi   %hi(dword_F0130F20), %o0
F00773B0: c0222320                 clr     [%o0+%lo(dword_F0130F20)]
F00773B4: 193c04c39013233c         set     dword_F0130F3C, %o0
F00773BC: 92102001                 mov     1, %o1
F00773C0: 153c04c3                 sethi   %hi(dword_F0130F40), %o2
F00773C4: 1b3c04c3                 sethi   %hi(dword_F0130F44), %o5
F00773C8: d602a340                 ld      [%o2+%lo(dword_F0130F40)], %o3
F00773CC: a2136344                 or      %o5, %lo(dword_F0130F44), %l1
F00773D0: c403233c                 ld      [%o4+0x33C], %g2
F00773D4: d8036344                 ld      [%o5+%lo(dword_F0130F44)], %o4
F00773D8: 9602c002                 add     %o3, %g2, %o3
F00773DC: 80a3000b                 cmp     %o4, %o3
F00773E0: 26800003                 bl,a    loc_F00773EC
F00773E4: a0102001                 mov     1, %l0
F00773E8: a0102000                 mov     0, %l0
F00773EC: 7fffe704                 call    _thread_wakeup_prim
F00773F0: 94102000                 mov     0, %o2
F00773F4: 80a42000                 cmp     %l0, 0
F00773F8: 02800005                 be      locret_F007740C
F00773FC: 90100011                 mov     %l1, %o0
F0077400: 92102001                 mov     1, %o1
F0077404: 7fffe6fe                 call    _thread_wakeup_prim
F0077408: 94102000                 mov     0, %o2
F007740C: 81c7e008                 ret
F0077410: 81e80000                 restore
