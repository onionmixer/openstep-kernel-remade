F004CCF8: 9de3bf98                 save    %sp, -0x68, %sp
F004CCFC: d2166004                 lduh    [%i1+4], %o1
F004CD00: b40ea3ff                 and     %i2, 0x3FF, %i2
F004CD04: 90102400                 mov     0x400, %o0
F004CD08: 808a6003                 btst    3, %o1
F004CD0C: 12800018                 bne     loc_F004CD6C
F004CD10: 9022001a                 sub     %o0, %i2, %o0
F004CD14: 94100009                 mov     %o1, %o2
F004CD18: 80a28008                 cmp     %o2, %o0
F004CD1C: 14800015                 bg      loc_F004CD70
F004CD20: 90100018                 mov     %i0, %o0
F004CD24: d2166006                 lduh    [%i1+6], %o1
F004CD28: 90026004                 add     %o1, 4, %o0
F004CD2C: 900a3ffc                 and     %o0, -4, %o0
F004CD30: 90022008                 inc     8, %o0
F004CD34: 80a28008                 cmp     %o2, %o0
F004CD38: 0a80000d                 bcs     loc_F004CD6C
F004CD3C: 80a260ff                 cmp     %o1, 0xFF
F004CD40: 1880000b                 bgu     loc_F004CD6C
F004CD44: 113c043a                 sethi   %hi(_dirchk), %o0
F004CD48: d0022208                 ld      [%o0+%lo(_dirchk)], %o0
F004CD4C: 80a22000                 cmp     %o0, 0
F004CD50: 2280000d                 be,a    locret_F004CD84
F004CD54: b0102000                 mov     0, %i0
F004CD58: 40000018                 call    sub_F004CDB8
F004CD5C: 90066008                 add     %i1, 8, %o0
F004CD60: 80a22000                 cmp     %o0, 0
F004CD64: 22800008                 be,a    locret_F004CD84
F004CD68: b0102000                 mov     0, %i0
F004CD6C: 90100018                 mov     %i0, %o0
F004CD70: 133c043a92126348         set     aMangledEntry_0, %o1! "mangled entry"
F004CD78: 40000005                 call    sub_F004CD8C
F004CD7C: 9410001b                 mov     %i3, %o2
F004CD80: b0102001                 mov     1, %i0
F004CD84: 81c7e008                 ret
F004CD88: 81e80000                 restore
