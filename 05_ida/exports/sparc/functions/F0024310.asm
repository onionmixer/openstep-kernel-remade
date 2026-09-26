F0024310: 9de3bf98                 save    %sp, -0x68, %sp
F0024314: a0100018                 mov     %i0, %l0
F0024318: b0102000                 mov     0, %i0
F002431C: 193c0430                 sethi   %hi(_vfsNVFS), %o4
F0024320: d003208c                 ld      [%o4+%lo(_vfsNVFS)], %o0
F0024324: 133c042f921263d8         set     _vfssw, %o1
F002432C: 90220009                 sub     %o0, %o1, %o0
F0024330: 913a2003                 sra     %o0, 3, %o0
F0024334: 80a60008                 cmp     %i0, %o0
F0024338: 16800014                 bge     loc_F0024388
F002433C: 113c04bd                 sethi   %hi(unk_F012F404), %o0
F0024340: 96122004                 or      %o0, %lo(unk_F012F404), %o3
F0024344: 84102001                 mov     1, %g2
F0024348: 9a100009                 mov     %o1, %o5
F002434C: 953e2003                 sra     %i0, 3, %o2
F0024350: 912aa003                 sll     %o2, 3, %o0
F0024354: 90260008                 sub     %i0, %o0, %o0
F0024358: d20a800b                 ldub    [%o2+%o3], %o1
F002435C: 91288008                 sll     %g2, %o0, %o0
F0024360: 92124008                 bset    %o0, %o1
F0024364: d22a800b                 stb     %o1, [%o2+%o3]
F0024368: d003208c                 ld      [%o4+0x8C], %o0
F002436C: b0062001                 inc     %i0
F0024370: 9022000d                 sub     %o0, %o5, %o0
F0024374: 913a2003                 sra     %o0, 3, %o0
F0024378: 80a60008                 cmp     %i0, %o0
F002437C: 06bffff5                 bl      loc_F0024350
F0024380: 953e2003                 sra     %i0, 3, %o2
F0024384: 113c04bd                 sethi   -0xFED0C00, %o0
F0024388: 90122004                 bset    4, %o0
F002438C: 40000033                 call    _vfs_getnum
F0024390: 92102010                 mov     0x10, %o1
F0024394: b0100008                 mov     %o0, %i0
F0024398: 80a63fff                 cmp     %i0, -1
F002439C: 12800005                 bne     locret_F00243B0
F00243A0: b0062080                 inc     0x80, %i0
F00243A4: 40000005                 call    _vfs_fixedmajor
F00243A8: 90100010                 mov     %l0, %o0
F00243AC: b0100008                 mov     %o0, %i0
F00243B0: 81c7e008                 ret
F00243B4: 81e80000                 restore
