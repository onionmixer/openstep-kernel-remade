F007956C: 9de3bf98                 save    %sp, -0x68, %sp
F0079570: 113c04f2a01223a8         set     _zget_space_lock, %l0
F0079578: d0040000                 ld      [%l0], %o0
F007957C: 80a22000                 cmp     %o0, 0
F0079580: 12bffffe                 bne     loc_F0079578
F0079584: 01000000                 nop
F0079588: 40007648                 call    _simple_lock_try
F007958C: 90100010                 mov     %l0, %o0
F0079590: 80a22000                 cmp     %o0, 0
F0079594: 02bffff9                 be      loc_F0079578
F0079598: 01000000                 nop
F007959C: 7ffffbeb                 call    _zone_free_space_reclaim
F00795A0: 01000000                 nop
F00795A4: 81c7e008                 ret
F00795A8: 81e80000                 restore
