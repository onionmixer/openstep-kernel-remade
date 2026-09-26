F00725A0: 9de3bf98                 save    %sp, -0x68, %sp
F00725A4: 2d3c04d3                 sethi   -0xFECB400, %l6
F00725A8: 293c0441                 sethi   -0xFEEFC00, %l4
F00725AC: 113c04f1aa122090         set     _stuck_threads, %l5
F00725B4: 7fffffac                 call    _do_runq_scan
F00725B8: 9015a3c0                 or      %l6, 0x3C0, %o0
F00725BC: a4920000                 orcc    %o0, %g0, %l2
F00725C0: 32800007                 bne,a   loc_F00725DC
F00725C4: d00521c0                 ld      [%l4+0x1C0], %o0
F00725C8: 113c04d8                 sethi   %hi(_master_processor), %o0
F00725CC: 7fffffa6                 call    _do_runq_scan
F00725D0: d00223d0                 ld      [%o0+%lo(_master_processor)], %o0
F00725D4: a4100008                 mov     %o0, %l2
F00725D8: d00521c0                 ld      [%l4+0x1C0], %o0
F00725DC: 80a22000                 cmp     %o0, 0
F00725E0: 04800027                 ble     loc_F007267C
F00725E4: 80a4a000                 cmp     %l2, 0
F00725E8: d00521c0                 ld      [%l4+0x1C0], %o0
F00725EC: 90023fff                 inc     -1, %o0
F00725F0: 932a2002                 sll     %o0, 2, %o1
F00725F4: e2024015                 ld      [%o1+%l5], %l1
F00725F8: d02521c0                 st      %o0, [%l4+0x1C0]
F00725FC: 40009163                 call    _splusclock
F0072600: c0224015                 clr     [%o1+%l5]
F0072604: a6100008                 mov     %o0, %l3
F0072608: a0046020                 add     %l1, 0x20, %l0 ! ' '
F007260C: d0040000                 ld      [%l0], %o0
F0072610: 80a22000                 cmp     %o0, 0
F0072614: 12bffffe                 bne     loc_F007260C
F0072618: 01000000                 nop
F007261C: 40009223                 call    _simple_lock_try
F0072620: 90100010                 mov     %l0, %o0
F0072624: 80a22000                 cmp     %o0, 0
F0072628: 02bffff9                 be      loc_F007260C
F007262C: 01000000                 nop
F0072630: d004604c                 ld      [%l1+0x4C], %o0
F0072634: 900a200f                 and     %o0, 0xF, %o0
F0072638: 80a22004                 cmp     %o0, 4
F007263C: 12800007                 bne     loc_F0072658
F0072640: 01000000                 nop
F0072644: 7ffffd01                 call    _update_priority
F0072648: 90100011                 mov     %l1, %o0
F007264C: 90100011                 mov     %l1, %o0
F0072650: 7ffffd94                 call    _thread_setrun
F0072654: 92102001                 mov     1, %o1
F0072658: c0246020                 clr     [%l1+0x20]
F007265C: 400091b2                 call    _splx
F0072660: 90100013                 mov     %l3, %o0
F0072664: 113c0441                 sethi   %hi(_stuck_count), %o0
F0072668: d00221c0                 ld      [%o0+%lo(_stuck_count)], %o0
F007266C: 80a22000                 cmp     %o0, 0
F0072670: 14bfffdf                 bg      loc_F00725EC
F0072674: d00521c0                 ld      [%l4+0x1C0], %o0
F0072678: 80a4a000                 cmp     %l2, 0
F007267C: 12bfffce                 bne     loc_F00725B4
F0072680: 01000000                 nop
F0072684: 81c7e008                 ret
F0072688: 81e80000                 restore
