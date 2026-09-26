F00275D4: 9de3bf90                 save    %sp, -0x70, %sp
F00275D8: 90100018                 mov     %i0, %o0
F00275DC: 92102000                 mov     0, %o1
F00275E0: 94102001                 mov     1, %o2
F00275E4: 96102000                 mov     0, %o3
F00275E8: 7ffffcf7                 call    _lookupname
F00275EC: 9807bff4                 add     %fp, var_C, %o4
F00275F0: b0920000                 orcc    %o0, %g0, %i0
F00275F4: 12800016                 bne     locret_F002764C
F00275F8: d607bff4                 ld      [%fp+var_C], %o3
F00275FC: d002e028                 ld      [%o3+0x28], %o0
F0027600: 80a22002                 cmp     %o0, 2
F0027604: 1280000b                 bne     loc_F0027630
F0027608: b0102014                 mov     0x14, %i0
F002760C: 113c04cf                 sethi   %hi(_active_u), %o0
F0027610: d00221d8                 ld      [%o0+%lo(_active_u)], %o0
F0027614: d402201c                 ld      [%o0+0x1C], %o2
F0027618: d202e01c                 ld      [%o3+0x1C], %o1
F002761C: 9010000b                 mov     %o3, %o0
F0027620: d602601c                 ld      [%o1+0x1C], %o3
F0027624: 9fc2c000                 call    %o3
F0027628: 92102040                 mov     0x40, %o1 ! '@'
F002762C: b0100008                 mov     %o0, %i0
F0027630: 80a62000                 cmp     %i0, 0
F0027634: 02800005                 be      loc_F0027648
F0027638: d007bff4                 ld      [%fp+var_C], %o0
F002763C: 4000054a                 call    _vn_rele
F0027640: d007bff4                 ld      [%fp+var_C], %o0
F0027644: 30800002                 ba,a    locret_F002764C
F0027648: d0264000                 st      %o0, [%i1]
F002764C: 81c7e008                 ret
F0027650: 81e80000                 restore
