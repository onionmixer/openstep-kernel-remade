F007A560: 9de3bf90                 save    %sp, -0x70, %sp
F007A564: 213c04d0                 sethi   %hi(_active_threads), %l0
F007A568: d0042260                 ld      [%l0+%lo(_active_threads)], %o0
F007A56C: d202200c                 ld      [%o0+0xC], %o1
F007A570: 113c0442                 sethi   %hi(_kernel_task), %o0
F007A574: d0022250                 ld      [%o0+%lo(_kernel_task)], %o0
F007A578: 80a24008                 cmp     %o1, %o0
F007A57C: 02800029                 be      loc_F007A620
F007A580: f0060000                 ld      [%i0], %i0
F007A584: d006201c                 ld      [%i0+0x1C], %o0
F007A588: 80a64008                 cmp     %i1, %o0
F007A58C: 32800004                 bne,a   loc_F007A59C
F007A590: d20624c0                 ld      [%i0+0x4C0], %o1
F007A594: 10800036                 ba      locret_F007A66C
F007A598: b0102000                 mov     0, %i0
F007A59C: 900624c0                 add     %i0, 0x4C0, %o0
F007A5A0: 80a20009                 cmp     %o0, %o1
F007A5A4: 0280000e                 be      loc_F007A5DC
F007A5A8: 94100008                 mov     %o0, %o2
F007A5AC: d0024000                 ld      [%o1], %o0
F007A5B0: 80a20019                 cmp     %o0, %i1
F007A5B4: 32800007                 bne,a   loc_F007A5D0
F007A5B8: d2026008                 ld      [%o1+8], %o1
F007A5BC: d0026004                 ld      [%o1+4], %o0
F007A5C0: 80a2001a                 cmp     %o0, %i2
F007A5C4: 2280002a                 be,a    locret_F007A66C
F007A5C8: b0102005                 mov     5, %i0
F007A5CC: d2026008                 ld      [%o1+8], %o1
F007A5D0: 80a28009                 cmp     %o2, %o1
F007A5D4: 32bffff7                 bne,a   loc_F007A5B0
F007A5D8: d0024000                 ld      [%o1], %o0
F007A5DC: 7fffb6a5                 call    _kalloc
F007A5E0: 90102010                 mov     0x10, %o0
F007A5E4: 92100008                 mov     %o0, %o1
F007A5E8: f2224000                 st      %i1, [%o1]
F007A5EC: f4226004                 st      %i2, [%o1+4]
F007A5F0: d40624c4                 ld      [%i0+0x4C4], %o2
F007A5F4: 900624c0                 add     %i0, 0x4C0, %o0
F007A5F8: 80a2000a                 cmp     %o0, %o2
F007A5FC: 32800003                 bne,a   loc_F007A608
F007A600: d222a008                 st      %o1, [%o2+8]
F007A604: d22624c0                 st      %o1, [%i0+0x4C0]
F007A608: d422600c                 st      %o2, [%o1+0xC]
F007A60C: 900624c0                 add     %i0, 0x4C0, %o0
F007A610: d0226008                 st      %o0, [%o1+8]
F007A614: d22624c4                 st      %o1, [%i0+0x4C4]
F007A618: 10800015                 ba      locret_F007A66C
F007A61C: b0102000                 mov     0, %i0
F007A620: 90100009                 mov     %o1, %o0
F007A624: 9210001a                 mov     %i2, %o1
F007A628: 40000363                 call    _get_kern_port
F007A62C: 9407bff4                 add     %fp, var_C, %o2
F007A630: 80a22000                 cmp     %o0, 0
F007A634: 1280000e                 bne     locret_F007A66C
F007A638: b0100008                 mov     %o0, %i0
F007A63C: d0042260                 ld      [%l0+0x260], %o0
F007A640: 92100019                 mov     %i1, %o1
F007A644: d002200c                 ld      [%o0+0xC], %o0
F007A648: 4000035b                 call    _get_kern_port
F007A64C: 9407bff0                 add     %fp, var_10, %o2
F007A650: 80a22000                 cmp     %o0, 0
F007A654: 12800006                 bne     locret_F007A66C
F007A658: b0100008                 mov     %o0, %i0
F007A65C: d007bff4                 ld      [%fp+var_C], %o0
F007A660: 40000315                 call    _port_request_notification
F007A664: d207bff0                 ld      [%fp+var_10], %o1
F007A668: b0102000                 mov     0, %i0
F007A66C: 81c7e008                 ret
F007A670: 81e80000                 restore
