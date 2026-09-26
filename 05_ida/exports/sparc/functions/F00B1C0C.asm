F00B1C0C: 9de3bf98                 save    %sp, -0x68, %sp
F00B1C10: 213c04d4                 sethi   %hi(_cons_tp), %l0
F00B1C14: 113c04d4a4122190         set     _cons, %l2
F00B1C1C: e4242290                 st      %l2, [%l0+%lo(_cons_tp)]
F00B1C20: 113c0483                 sethi   %hi(_kbddev), %o0
F00B1C24: 92103fff                 mov     -1, %o1
F00B1C28: d2322224                 sth     %o1, [%o0+%lo(_kbddev)]
F00B1C2C: 113c04fb                 sethi   %hi(_mousedev), %o0
F00B1C30: d2322240                 sth     %o1, [%o0+%lo(_mousedev)]
F00B1C34: 113c04fb                 sethi   %hi(_fbdev), %o0
F00B1C38: 40000016                 call    _consconfig
F00B1C3C: d2322238                 sth     %o1, [%o0+%lo(_fbdev)]
F00B1C40: 233c04fb                 sethi   %hi(_rconsdev), %l1
F00B1C44: d0146248                 lduh    [%l1+%lo(_rconsdev)], %o0
F00B1C48: 900a207f                 and     %o0, 0x7F, %o0
F00B1C4C: 80a22002                 cmp     %o0, 2
F00B1C50: 0280000b                 be      loc_F00B1C7C
F00B1C54: 932a2004                 sll     %o0, 4, %o1
F00B1C58: 92024008                 add     %o1, %o0, %o1
F00B1C5C: 932a6003                 sll     %o1, 3, %o1
F00B1C60: 113c04fb90122260         set     _zs_tty, %o0
F00B1C68: 92024008                 add     %o1, %o0, %o1! __src
F00B1C6C: d2242290                 st      %o1, [%l0+0x290]
F00B1C70: 90100012                 mov     %l2, %o0! __dst
F00B1C74: 7ffd558b                 call    _memcpy
F00B1C78: 94102088                 mov     0x88, %o2
F00B1C7C: d2042290                 ld      [%l0+0x290], %o1
F00B1C80: d0146248                 lduh    [%l1+0x248], %o0
F00B1C84: d0326038                 sth     %o0, [%o1+0x38]
F00B1C88: 81c7e008                 ret
F00B1C8C: 81e80000                 restore
