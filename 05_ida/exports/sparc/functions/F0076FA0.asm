F0076FA0: 9de3bf98                 save    %sp, -0x68, %sp
F0076FA4: 40007ef9                 call    _splusclock
F0076FA8: 01000000                 nop
F0076FAC: a2100008                 mov     %o0, %l1
F0076FB0: 113c04c3a0122320         set     dword_F0130F20, %l0
F0076FB8: d0040000                 ld      [%l0], %o0
F0076FBC: 80a22000                 cmp     %o0, 0
F0076FC0: 12bffffe                 bne     loc_F0076FB8
F0076FC4: 01000000                 nop
F0076FC8: 40007fb8                 call    _simple_lock_try
F0076FCC: 90100010                 mov     %l0, %o0
F0076FD0: 80a22000                 cmp     %o0, 0
F0076FD4: 02bffff9                 be      loc_F0076FB8
F0076FD8: 01000000                 nop
F0076FDC: d0062020                 ld      [%i0+0x20], %o0
F0076FE0: 80a22000                 cmp     %o0, 0
F0076FE4: 12800015                 bne     loc_F0077038
F0076FE8: 113c04c3                 sethi   -0xFECF400, %o0
F0076FEC: f226200c                 st      %i1, [%i0+0xC]
F0076FF0: 98102000                 mov     0, %o4
F0076FF4: 9a102000                 mov     0, %o5
F0076FF8: d83e2018                 std     %o4, [%i0+0x18]
F0076FFC: 133c04c39212632c         set     dword_F0130F2C, %o1
F0077004: d2260000                 st      %o1, [%i0]
F0077008: d0026004                 ld      [%o1+4], %o0
F007700C: 153c04c3                 sethi   %hi(dword_F0130F3C), %o2
F0077010: d0262004                 st      %o0, [%i0+4]
F0077014: f0220000                 st      %i0, [%o0]
F0077018: d002a33c                 ld      [%o2+%lo(dword_F0130F3C)], %o0
F007701C: f0226004                 st      %i0, [%o1+4]
F0077020: 90022001                 inc     %o0
F0077024: d022a33c                 st      %o0, [%o2+%lo(dword_F0130F3C)]
F0077028: 90102001                 mov     1, %o0
F007702C: 400000df                 call    sub_F00773A8
F0077030: d0262020                 st      %o0, [%i0+0x20]
F0077034: 30800002                 ba,a    loc_F007703C
F0077038: c0222320                 clr     [%o0+0x320]
F007703C: 40007f3a                 call    _splx
F0077040: 90100011                 mov     %l1, %o0
F0077044: 81c7e008                 ret
F0077048: 81e80000                 restore
