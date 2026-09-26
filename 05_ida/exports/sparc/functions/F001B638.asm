F001B638: 9de3bf98                 save    %sp, -0x68, %sp
F001B63C: b00e20ff                 and     %i0, 0xFF, %i0
F001B640: b12e2004                 sll     %i0, 4, %i0
F001B644: 113c04bc90122204         set     unk_F012F204, %o0
F001B64C: b0060008                 add     %i0, %o0, %i0
F001B650: d2062008                 ld      [%i0+8], %o1
F001B654: d0026024                 ld      [%o1+0x24], %o0
F001B658: 80a22000                 cmp     %o0, 0
F001B65C: 0280000e                 be      loc_F001B694
F001B660: 90100009                 mov     %o1, %o0
F001B664: d44a6047                 ldsb    [%o1+0x47], %o2
F001B668: 932aa001                 sll     %o2, 1, %o1
F001B66C: 9202400a                 add     %o1, %o2, %o1
F001B670: 932a6004                 sll     %o1, 4, %o1
F001B674: 153c042e9412a0cc         set     _linesw, %o2
F001B67C: 9202400a                 add     %o1, %o2, %o1
F001B680: d402600c                 ld      [%o1+0xC], %o2
F001B684: 9fc28000                 call    %o2
F001B688: 92100019                 mov     %i1, %o1
F001B68C: 10800003                 ba      locret_F001B698
F001B690: b0100008                 mov     %o0, %i0
F001B694: b0102005                 mov     5, %i0
F001B698: 81c7e008                 ret
F001B69C: 81e80000                 restore
