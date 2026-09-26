F00845D0: 9de3bf90                 save    %sp, -0x70, %sp
F00845D4: e206c000                 ld      [%i3], %l1
F00845D8: a0100018                 mov     %i0, %l0
F00845DC: 7fff91fa                 call    _lock_write
F00845E0: 90100010                 mov     %l0, %o0
F00845E4: d004204c                 ld      [%l0+0x4C], %o0
F00845E8: 90022001                 inc     %o0
F00845EC: 80a76000                 cmp     %i5, 0
F00845F0: 0280003d                 be      loc_F00846E4
F00845F4: d024204c                 st      %o0, [%l0+0x4C]
F00845F8: d2042014                 ld      [%l0+0x14], %o1
F00845FC: 80a44009                 cmp     %l1, %o1
F0084600: 2a800002                 bcs,a   loc_F0084608
F0084604: a2100009                 mov     %o1, %l1
F0084608: d0042018                 ld      [%l0+0x18], %o0
F008460C: 80a44008                 cmp     %l1, %o0
F0084610: 1880001b                 bgu     loc_F008467C
F0084614: 80a44009                 cmp     %l1, %o1
F0084618: 12800009                 bne     loc_F008463C
F008461C: 90100010                 mov     %l0, %o0
F0084620: fa042040                 ld      [%l0+0x40], %i5
F0084624: 9004200c                 add     %l0, 0xC, %o0
F0084628: 80a74008                 cmp     %i5, %o0
F008462C: 3280000c                 bne,a   loc_F008465C
F0084630: e207600c                 ld      [%i5+0xC], %l1
F0084634: 1080000b                 ba      loc_F0084660
F0084638: 9604200c                 add     %l0, 0xC, %o3
F008463C: 92100011                 mov     %l1, %o1
F0084640: 7fffff9a                 call    _vm_map_lookup_entry
F0084644: 9407bff4                 add     %fp, var_C, %o2
F0084648: 80a22000                 cmp     %o0, 0
F008464C: 02800003                 be      loc_F0084658
F0084650: d007bff4                 ld      [%fp+var_C], %o0
F0084654: e202200c                 ld      [%o0+0xC], %l1
F0084658: fa07bff4                 ld      [%fp+var_C], %i5
F008465C: 9604200c                 add     %l0, 0xC, %o3
F0084660: d0042018                 ld      [%l0+0x18], %o0
F0084664: 9404401c                 add     %l1, %i4, %o2
F0084668: 80a28008                 cmp     %o2, %o0
F008466C: 18800004                 bgu     loc_F008467C
F0084670: 80a28011                 cmp     %o2, %l1
F0084674: 3a800006                 bcc,a   loc_F008468C
F0084678: d2076004                 ld      [%i5+4], %o1
F008467C: 7fff926e                 call    _lock_done
F0084680: 90100010                 mov     %l0, %o0
F0084684: 10800021                 ba      locret_F0084708
F0084688: b0102003                 mov     3, %i0
F008468C: 80a2400b                 cmp     %o1, %o3
F0084690: 22800009                 be,a    loc_F00846B4
F0084694: e226c000                 st      %l1, [%i3]
F0084698: d0026008                 ld      [%o1+8], %o0
F008469C: 80a2000a                 cmp     %o0, %o2
F00846A0: 3a800005                 bcc,a   loc_F00846B4
F00846A4: e226c000                 st      %l1, [%i3]
F00846A8: ba100009                 mov     %o1, %i5
F00846AC: 10bfffed                 ba      loc_F0084660
F00846B0: e207600c                 ld      [%i5+0xC], %l1
F00846B4: b004203c                 add     %l0, 0x3C, %i0 ! '<'
F00846B8: d0060000                 ld      [%i0], %o0
F00846BC: 80a22000                 cmp     %o0, 0
F00846C0: 12bffffe                 bne     loc_F00846B8
F00846C4: 01000000                 nop
F00846C8: 400049f8                 call    _simple_lock_try
F00846CC: 90100018                 mov     %i0, %o0
F00846D0: 80a22000                 cmp     %o0, 0
F00846D4: 02bffff9                 be      loc_F00846B8
F00846D8: 01000000                 nop
F00846DC: fa242038                 st      %i5, [%l0+0x38]
F00846E0: c024203c                 clr     [%l0+0x3C]
F00846E4: 90100010                 mov     %l0, %o0
F00846E8: 92100019                 mov     %i1, %o1
F00846EC: 9410001a                 mov     %i2, %o2
F00846F0: 96100011                 mov     %l1, %o3
F00846F4: 7ffffeea                 call    _vm_map_insert
F00846F8: 9802c01c                 add     %o3, %i4, %o4
F00846FC: b0100008                 mov     %o0, %i0
F0084700: 7fff924d                 call    _lock_done
F0084704: 90100010                 mov     %l0, %o0
F0084708: 81c7e008                 ret
F008470C: 81e80000                 restore
