F00F3608: 80a22000                 cmp     %o0, 0
F00F360C: 12800006                 bne     loc_F00F3624
F00F3610: 053c04bc                 sethi   -0xFED1000, %g2
F00F3614: 10800030                 ba      locret_F00F36D4
F00F3618: 90102000                 mov     0, %o0
F00F361C: 1080002e                 ba      locret_F00F36D4
F00F3620: 90102001                 mov     1, %o0
F00F3624: d400a16c                 ld      [%g2+0x16C], %o2
F00F3628: 80a2a000                 cmp     %o2, 0
F00F362C: 02800029                 be      loc_F00F36D0
F00F3630: 053c04bc                 sethi   %hi(unk_F012F150), %g2
F00F3634: 9a10a150                 or      %g2, %lo(unk_F012F150), %o5
F00F3638: c402a00c                 ld      [%o2+0xC], %g2
F00F363C: 80a20002                 cmp     %o0, %g2
F00F3640: 0a800006                 bcs     loc_F00F3658
F00F3644: 80a2800d                 cmp     %o2, %o5
F00F3648: c402a010                 ld      [%o2+0x10], %g2
F00F364C: 80a20002                 cmp     %o0, %g2
F00F3650: 0abffff3                 bcs     loc_F00F361C
F00F3654: 80a2800d                 cmp     %o2, %o5
F00F3658: 3280001b                 bne,a   loc_F00F36C4
F00F365C: d402a018                 ld      [%o2+0x18], %o2
F00F3660: 92102000                 mov     0, %o1
F00F3664: c402a004                 ld      [%o2+4], %g2
F00F3668: 80a24002                 cmp     %o1, %g2
F00F366C: 3a800016                 bcc,a   loc_F00F36C4
F00F3670: d402a018                 ld      [%o2+0x18], %o2
F00F3674: d802a014                 ld      [%o2+0x14], %o4
F00F3678: d602a004                 ld      [%o2+4], %o3
F00F367C: 852a6002                 sll     %o1, 2, %g2
F00F3680: c6030002                 ld      [%o4+%g2], %g3
F00F3684: 80a0e000                 cmp     %g3, 0
F00F3688: 2280000b                 be,a    loc_F00F36B4
F00F368C: 92026001                 inc     %o1
F00F3690: c400e004                 ld      [%g3+4], %g2
F00F3694: 80a20002                 cmp     %o0, %g2
F00F3698: 2280000f                 be,a    locret_F00F36D4
F00F369C: 90102001                 mov     1, %o0
F00F36A0: c600c000                 ld      [%g3], %g3
F00F36A4: 80a0e000                 cmp     %g3, 0
F00F36A8: 32bffffb                 bne,a   loc_F00F3694
F00F36AC: c400e004                 ld      [%g3+4], %g2
F00F36B0: 92026001                 inc     %o1
F00F36B4: 80a2400b                 cmp     %o1, %o3
F00F36B8: 0abffff2                 bcs     loc_F00F3680
F00F36BC: 852a6002                 sll     %o1, 2, %g2
F00F36C0: d402a018                 ld      [%o2+0x18], %o2
F00F36C4: 80a2a000                 cmp     %o2, 0
F00F36C8: 32bfffdd                 bne,a   loc_F00F363C
F00F36CC: c402a00c                 ld      [%o2+0xC], %g2
F00F36D0: 90102000                 mov     0, %o0
F00F36D4: 81c3e008                 retl
F00F36D8: 01000000                 nop
