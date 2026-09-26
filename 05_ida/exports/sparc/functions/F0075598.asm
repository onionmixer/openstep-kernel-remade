F0075598: 9de3bf98                 save    %sp, -0x68, %sp
F007559C: 80a62000                 cmp     %i0, 0
F00755A0: 12800004                 bne     loc_F00755B0
F00755A4: 01000000                 nop
F00755A8: 1080002b                 ba      locret_F0075654
F00755AC: b0102004                 mov     4, %i0
F00755B0: 40008576                 call    _splusclock
F00755B4: a2102000                 mov     0, %l1
F00755B8: a4100008                 mov     %o0, %l2
F00755BC: a0062020                 add     %i0, 0x20, %l0 ! ' '
F00755C0: d0040000                 ld      [%l0], %o0
F00755C4: 80a22000                 cmp     %o0, 0
F00755C8: 12bffffe                 bne     loc_F00755C0
F00755CC: 01000000                 nop
F00755D0: 40008636                 call    _simple_lock_try
F00755D4: 90100010                 mov     %l0, %o0
F00755D8: 80a22000                 cmp     %o0, 0
F00755DC: 02bffff9                 be      loc_F00755C0
F00755E0: 01000000                 nop
F00755E4: d006208c                 ld      [%i0+0x8C], %o0
F00755E8: 80a22000                 cmp     %o0, 0
F00755EC: 04800015                 ble     loc_F0075640
F00755F0: 90023fff                 inc     -1, %o0
F00755F4: 80a22000                 cmp     %o0, 0
F00755F8: 12800013                 bne     loc_F0075644
F00755FC: d026208c                 st      %o0, [%i0+0x8C]
F0075600: d0062040                 ld      [%i0+0x40], %o0
F0075604: 90023fff                 inc     -1, %o0
F0075608: 80a22000                 cmp     %o0, 0
F007560C: 1280000e                 bne     loc_F0075644
F0075610: d0262040                 st      %o0, [%i0+0x40]
F0075614: d006204c                 ld      [%i0+0x4C], %o0
F0075618: 920a3fed                 and     %o0, -0x13, %o1
F007561C: 808a2005                 btst    5, %o0
F0075620: 12800009                 bne     loc_F0075644
F0075624: d226204c                 st      %o1, [%i0+0x4C]
F0075628: 90126004                 or      %o1, 4, %o0
F007562C: d026204c                 st      %o0, [%i0+0x4C]
F0075630: 90100018                 mov     %i0, %o0
F0075634: 7ffff19b                 call    _thread_setrun
F0075638: 92102001                 mov     1, %o1
F007563C: 30800002                 ba,a    loc_F0075644
F0075640: a2102005                 mov     5, %l1
F0075644: c0262020                 clr     [%i0+0x20]
F0075648: 400085b7                 call    _splx
F007564C: 90100012                 mov     %l2, %o0
F0075650: b0100011                 mov     %l1, %i0
F0075654: 81c7e008                 ret
F0075658: 81e80000                 restore
