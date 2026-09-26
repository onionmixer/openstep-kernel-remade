F00B8DC8: 9de3bf98                 save    %sp, -0x68, %sp
F00B8DCC: d016205c                 lduh    [%i0+0x5C], %o0
F00B8DD0: 808a2001                 btst    1, %o0
F00B8DD4: 02800010                 be      locret_F00B8E14
F00B8DD8: a0100018                 mov     %i0, %l0
F00B8DDC: 808a2004                 btst    4, %o0
F00B8DE0: 32800007                 bne,a   loc_F00B8DFC
F00B8DE4: c0242040                 clr     [%l0+0x40]
F00B8DE8: 113c04f6                 sethi   %hi(_dvmamap), %o0
F00B8DEC: d00222f8                 ld      [%o0+%lo(_dvmamap)], %o0
F00B8DF0: 7fff851c                 call    _mb_mapfree
F00B8DF4: 9206203c                 add     %i0, 0x3C, %o1 ! '<'
F00B8DF8: c0242040                 clr     [%l0+0x40]
F00B8DFC: c024203c                 clr     [%l0+0x3C]
F00B8E00: d214205c                 lduh    [%l0+0x5C], %o1
F00B8E04: 1100003f901223fe         set     0xFFFE, %o0
F00B8E0C: 920a4008                 and     %o1, %o0, %o1
F00B8E10: d234205c                 sth     %o1, [%l0+0x5C]
F00B8E14: 81c7e008                 ret
F00B8E18: 81e80000                 restore
