F00711E0: 9de3bf98                 save    %sp, -0x68, %sp
F00711E4: 40009669                 call    _splusclock
F00711E8: a0062020                 add     %i0, 0x20, %l0 ! ' '
F00711EC: a2100008                 mov     %o0, %l1
F00711F0: d0040000                 ld      [%l0], %o0
F00711F4: 80a22000                 cmp     %o0, 0
F00711F8: 12bffffe                 bne     loc_F00711F0
F00711FC: 01000000                 nop
F0071200: 4000972a                 call    _simple_lock_try
F0071204: 90100010                 mov     %l0, %o0
F0071208: 80a22000                 cmp     %o0, 0
F007120C: 02bffff9                 be      loc_F00711F0
F0071210: 01000000                 nop
F0071214: f2262194                 st      %i1, [%i0+0x194]
F0071218: c0262020                 clr     [%i0+0x20]
F007121C: 400096c2                 call    _splx
F0071220: 90100011                 mov     %l1, %o0
F0071224: 81c7e008                 ret
F0071228: 81e80000                 restore
