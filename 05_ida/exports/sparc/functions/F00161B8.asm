F00161B8: 9de3bf98                 save    %sp, -0x68, %sp
F00161BC: 113c04cf                 sethi   %hi(_active_u), %o0
F00161C0: d00221d8                 ld      [%o0+%lo(_active_u)], %o0
F00161C4: d0020000                 ld      [%o0], %o0
F00161C8: d2022014                 ld      [%o0+0x14], %o1
F00161CC: 11000010                 sethi   0x4000, %o0
F00161D0: 808a4008                 btst    %o0, %o1
F00161D4: 02800007                 be      loc_F00161F0
F00161D8: 9410001a                 mov     %i2, %o2
F00161DC: d2062008                 ld      [%i0+8], %o1
F00161E0: 11000008                 sethi   0x2000, %o0
F00161E4: 808a4008                 btst    %o0, %o1
F00161E8: 32800002                 bne,a   loc_F00161F0
F00161EC: d232a010                 sth     %o1, [%o2+0x10]
F00161F0: 80a66000                 cmp     %i1, 0
F00161F4: 12800005                 bne     loc_F0016208
F00161F8: 113c007a                 sethi   -0xFFE1800, %o0
F00161FC: 113c007c                 sethi   %hi(_soreceive), %o0
F0016200: 10800003                 ba      loc_F001620C
F0016204: 9a1220c4                 or      %o0, %lo(_soreceive), %o5
F0016208: 9a12236c                 or      %o0, 0x36C, %o5
F001620C: d0062018                 ld      [%i0+0x18], %o0
F0016210: 92102000                 mov     0, %o1
F0016214: 96102000                 mov     0, %o3
F0016218: 9fc34000                 call    %o5
F001621C: 98102000                 mov     0, %o4
F0016220: 81c7e008                 ret
F0016224: 91e80008                 restore %g0, %o0, %o0
