F003C5D8: 9de3bf80                 save    %sp, -0x80, %sp
F003C5DC: 133c0433                 sethi   %hi(_MAXCLIENTS), %o1
F003C5E0: d0026180                 ld      [%o1+%lo(_MAXCLIENTS)], %o0
F003C5E4: a0102000                 mov     0, %l0
F003C5E8: 90022003                 inc     3, %o0
F003C5EC: 80a40008                 cmp     %l0, %o0
F003C5F0: 1a800010                 bcc     loc_F003C630
F003C5F4: d0226180                 st      %o0, [%o1+%lo(_MAXCLIENTS)]
F003C5F8: 273c04cf                 sethi   -0xFECC400, %l3
F003C5FC: a4100009                 mov     %o1, %l2
F003C600: a207bff8                 add     %fp, var_8, %l1
F003C604: d204e1d8                 ld      [%l3+0x1D8], %o1
F003C608: 90100018                 mov     %i0, %o0
F003C60C: d202601c                 ld      [%o1+0x1C], %o1
F003C610: 7fffff67                 call    sub_F003C3AC
F003C614: a0042001                 inc     %l0
F003C618: d0247fe8                 st      %o0, [%l1-0x18]
F003C61C: d004a180                 ld      [%l2+0x180], %o0
F003C620: 80a40008                 cmp     %l0, %o0
F003C624: 0abffff8                 bcs     loc_F003C604
F003C628: a2046004                 inc     4, %l1
F003C62C: 133c0433                 sethi   -0xFEF3400, %o1
F003C630: d0026180                 ld      [%o1+0x180], %o0
F003C634: a0102000                 mov     0, %l0
F003C638: 80a40008                 cmp     %l0, %o0
F003C63C: 1a80000e                 bcc     loc_F003C674
F003C640: b007bff8                 add     %fp, var_8, %i0
F003C644: a2100009                 mov     %o1, %l1
F003C648: d0063fe8                 ld      [%i0-0x18], %o0
F003C64C: 80a22000                 cmp     %o0, 0
F003C650: 22800005                 be,a    loc_F003C664
F003C654: d0046180                 ld      [%l1+0x180], %o0
F003C658: 40000026                 call    sub_F003C6F0
F003C65C: 01000000                 nop
F003C660: d0046180                 ld      [%l1+0x180], %o0
F003C664: a0042001                 inc     %l0
F003C668: 80a40008                 cmp     %l0, %o0
F003C66C: 0abffff7                 bcs     loc_F003C648
F003C670: b0062004                 inc     4, %i0
F003C674: 313c0433                 sethi   %hi(_MAXCLIENTS), %i0
F003C678: d2062180                 ld      [%i0+%lo(_MAXCLIENTS)], %o1
F003C67C: a0102000                 mov     0, %l0
F003C680: 912a6004                 sll     %o1, 4, %o0
F003C684: 90020009                 add     %o0, %o1, %o0
F003C688: 912a2002                 sll     %o0, 2, %o0
F003C68C: 90020009                 add     %o0, %o1, %o0
F003C690: 912a2002                 sll     %o0, 2, %o0
F003C694: 90220009                 sub     %o0, %o1, %o0
F003C698: 4000ae76                 call    _kalloc
F003C69C: 912a2005                 sll     %o0, 5, %o0
F003C6A0: d2062180                 ld      [%i0+%lo(_MAXCLIENTS)], %o1
F003C6A4: 80a40009                 cmp     %l0, %o1
F003C6A8: 1a800010                 bcc     locret_F003C6E8
F003C6AC: a2100008                 mov     %o0, %l1
F003C6B0: 11000008a6122260         set     0x2260, %l3
F003C6B8: a4100018                 mov     %i0, %l2
F003C6BC: 113c04eab0122160         set     _chtable, %i0
F003C6C4: 92100011                 mov     %l1, %o1
F003C6C8: a2044013                 add     %l1, %l3, %l1
F003C6CC: d0062008                 ld      [%i0+8], %o0
F003C6D0: 400018a8                 call    _clntkudp_realloc
F003C6D4: a0042001                 inc     %l0
F003C6D8: d004a180                 ld      [%l2+0x180], %o0
F003C6DC: 80a40008                 cmp     %l0, %o0
F003C6E0: 0abffff9                 bcs     loc_F003C6C4
F003C6E4: b006200c                 inc     0xC, %i0
F003C6E8: 81c7e008                 ret
F003C6EC: 81e80000                 restore
