F00F2C60: 9de3bf98                 save    %sp, -0x68, %sp
F00F2C64: 98102000                 mov     0, %o4
F00F2C68: 113c04bc                 sethi   %hi(dword_F012F128), %o0
F00F2C6C: d0022128                 ld      [%o0+%lo(dword_F012F128)], %o0
F00F2C70: 80a30008                 cmp     %o4, %o0
F00F2C74: 1a80002c                 bcc     loc_F00F2D24
F00F2C78: 113c04bc                 sethi   %hi(dword_F012F124), %o0
F00F2C7C: da022124                 ld      [%o0+%lo(dword_F012F124)], %o5
F00F2C80: 073c04bc                 sethi   %hi(dword_F012F128), %g3
F00F2C84: d000e128                 ld      [%g3+%lo(dword_F012F128)], %o0
F00F2C88: 9e023fff                 add     %o0, -1, %o7
F00F2C8C: 912b2001                 sll     %o4, 1, %o0
F00F2C90: 9002000c                 add     %o0, %o4, %o0
F00F2C94: 912a2003                 sll     %o0, 3, %o0
F00F2C98: d0034008                 ld      [%o5+%o0], %o0
F00F2C9C: 80a20018                 cmp     %o0, %i0
F00F2CA0: 3280001c                 bne,a   loc_F00F2D10
F00F2CA4: 98032001                 inc     %o4
F00F2CA8: 9610000c                 mov     %o4, %o3
F00F2CAC: 80a3000f                 cmp     %o4, %o7
F00F2CB0: 1a800017                 bcc     loc_F00F2D0C
F00F2CB4: 90100003                 mov     %g3, %o0
F00F2CB8: d0022128                 ld      [%o0+0x128], %o0
F00F2CBC: 84023fff                 add     %o0, -1, %g2
F00F2CC0: 912ae001                 sll     %o3, 1, %o0
F00F2CC4: 9002000b                 add     %o0, %o3, %o0
F00F2CC8: 912a2003                 sll     %o0, 3, %o0
F00F2CCC: 9202000d                 add     %o0, %o5, %o1
F00F2CD0: d4026018                 ld      [%o1+0x18], %o2
F00F2CD4: d4234008                 st      %o2, [%o5+%o0]
F00F2CD8: d002601c                 ld      [%o1+0x1C], %o0
F00F2CDC: d0226004                 st      %o0, [%o1+4]
F00F2CE0: d0026020                 ld      [%o1+0x20], %o0
F00F2CE4: d0226008                 st      %o0, [%o1+8]
F00F2CE8: d0026024                 ld      [%o1+0x24], %o0
F00F2CEC: d022600c                 st      %o0, [%o1+0xC]
F00F2CF0: d0026028                 ld      [%o1+0x28], %o0
F00F2CF4: d0226010                 st      %o0, [%o1+0x10]
F00F2CF8: d002602c                 ld      [%o1+0x2C], %o0
F00F2CFC: 9602e001                 inc     %o3
F00F2D00: 80a2c002                 cmp     %o3, %g2
F00F2D04: 0abfffef                 bcs     loc_F00F2CC0
F00F2D08: d0226014                 st      %o0, [%o1+0x14]
F00F2D0C: 98032001                 inc     %o4
F00F2D10: 113c04bc                 sethi   %hi(dword_F012F128), %o0
F00F2D14: d0022128                 ld      [%o0+%lo(dword_F012F128)], %o0
F00F2D18: 80a30008                 cmp     %o4, %o0
F00F2D1C: 0abfffdd                 bcs     loc_F00F2C90
F00F2D20: 912b2001                 sll     %o4, 1, %o0
F00F2D24: 213c04bc                 sethi   %hi(dword_F012F128), %l0
F00F2D28: d0042128                 ld      [%l0+%lo(dword_F012F128)], %o0
F00F2D2C: 90023fff                 inc     -1, %o0
F00F2D30: 7ffff6e2                 call    __objc_create_zone
F00F2D34: d0242128                 st      %o0, [%l0+%lo(dword_F012F128)]
F00F2D38: 7ffff6e0                 call    __objc_create_zone
F00F2D3C: a2100008                 mov     %o0, %l1
F00F2D40: 253c04bc                 sethi   %hi(dword_F012F124), %l2
F00F2D44: d2042128                 ld      [%l0+%lo(dword_F012F128)], %o1
F00F2D48: 952a6001                 sll     %o1, 1, %o2
F00F2D4C: 94028009                 add     %o2, %o1, %o2
F00F2D50: d6044000                 ld      [%l1], %o3
F00F2D54: d204a124                 ld      [%l2+%lo(dword_F012F124)], %o1
F00F2D58: 9fc2c000                 call    %o3
F00F2D5C: 952aa003                 sll     %o2, 3, %o2
F00F2D60: d024a124                 st      %o0, [%l2+%lo(dword_F012F124)]
F00F2D64: 81c7e008                 ret
F00F2D68: 81e80000                 restore
