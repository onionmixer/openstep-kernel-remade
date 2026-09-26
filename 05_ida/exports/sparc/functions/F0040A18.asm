F0040A18: 9de3bf98                 save    %sp, -0x68, %sp
F0040A1C: 153c04d0                 sethi   %hi(_active_threads), %o2
F0040A20: d202a260                 ld      [%o2+%lo(_active_threads)], %o1
F0040A24: 90102001                 mov     1, %o0
F0040A28: d0226078                 st      %o0, [%o1+0x78]
F0040A2C: 4000cd61                 call    _stack_privilege
F0040A30: d002a260                 ld      [%o2+%lo(_active_threads)], %o0
F0040A34: 153c04bd                 sethi   %hi(dword_F012F528), %o2
F0040A38: d202a128                 ld      [%o2+%lo(dword_F012F528)], %o1
F0040A3C: 113c04cf                 sethi   %hi(dword_F0133DDC), %o0
F0040A40: d00221dc                 ld      [%o0+%lo(dword_F0133DDC)], %o0! jmp_buf
F0040A44: 92026001                 inc     %o1
F0040A48: d222a128                 st      %o1, [%o2+%lo(dword_F012F528)]
F0040A4C: 400158c2                 call    _setjmp
F0040A50: 90022028                 inc     0x28, %o0 ! '('
F0040A54: 80a22000                 cmp     %o0, 0
F0040A58: 0280002c                 be      loc_F0040B08
F0040A5C: 133c04bd                 sethi   %hi(dword_F012F528), %o1
F0040A60: d0026128                 ld      [%o1+%lo(dword_F012F528)], %o0
F0040A64: 80a22000                 cmp     %o0, 0
F0040A68: 12800013                 bne     loc_F0040AB4
F0040A6C: 90023fff                 inc     -1, %o0
F0040A70: 113c04ea                 sethi   %hi(_async_bufhead), %o0
F0040A74: d40223d8                 ld      [%o0+%lo(_async_bufhead)], %o2
F0040A78: 80a2a000                 cmp     %o2, 0
F0040A7C: 0280003c                 be      locret_F0040B6C
F0040A80: a0100008                 mov     %o0, %l0
F0040A84: d2028000                 ld      [%o2], %o1
F0040A88: 9010000a                 mov     %o2, %o0
F0040A8C: 92126004                 bset    4, %o1
F0040A90: d402200c                 ld      [%o0+0xC], %o2
F0040A94: d2220000                 st      %o1, [%o0]
F0040A98: 7fff918e                 call    _biodone
F0040A9C: d42423d8                 st      %o2, [%l0+0x3D8]
F0040AA0: d40423d8                 ld      [%l0+0x3D8], %o2
F0040AA4: 80a2a000                 cmp     %o2, 0
F0040AA8: 32bffff8                 bne,a   loc_F0040A88
F0040AAC: d2028000                 ld      [%o2], %o1
F0040AB0: 3080002f                 ba,a    locret_F0040B6C
F0040AB4: d0226128                 st      %o0, [%o1+0x128]
F0040AB8: 153c04bd                 sethi   %hi(dword_F012F524), %o2
F0040ABC: d202a124                 ld      [%o2+%lo(dword_F012F524)], %o1
F0040AC0: 80a22000                 cmp     %o0, 0
F0040AC4: 92027fff                 inc     -1, %o1
F0040AC8: 12800029                 bne     locret_F0040B6C
F0040ACC: d222a124                 st      %o1, [%o2+%lo(dword_F012F524)]
F0040AD0: 113c04ea                 sethi   %hi(_async_bufhead), %o0
F0040AD4: d40223d8                 ld      [%o0+%lo(_async_bufhead)], %o2
F0040AD8: 80a2a000                 cmp     %o2, 0
F0040ADC: 02800024                 be      locret_F0040B6C
F0040AE0: a0100008                 mov     %o0, %l0
F0040AE4: d202a00c                 ld      [%o2+0xC], %o1
F0040AE8: 9010000a                 mov     %o2, %o0
F0040AEC: 40000022                 call    sub_F0040B74
F0040AF0: d22423d8                 st      %o1, [%l0+0x3D8]
F0040AF4: d40423d8                 ld      [%l0+0x3D8], %o2
F0040AF8: 80a2a000                 cmp     %o2, 0
F0040AFC: 32bffffb                 bne,a   loc_F0040AE8
F0040B00: d202a00c                 ld      [%o2+0xC], %o1
F0040B04: 3080001a                 ba,a    locret_F0040B6C
F0040B08: 233c04bd                 sethi   %hi(dword_F012F524), %l1
F0040B0C: 213c04ea                 sethi   -0xFEC5800, %l0
F0040B10: d0046124                 ld      [%l1+%lo(dword_F012F524)], %o0
F0040B14: d20423d8                 ld      [%l0+0x3D8], %o1
F0040B18: 90022001                 inc     %o0
F0040B1C: 80a26000                 cmp     %o1, 0
F0040B20: 12800009                 bne     loc_F0040B44
F0040B24: d0246124                 st      %o0, [%l1+0x124]
F0040B28: 901423d8                 or      %l0, 0x3D8, %o0! unsigned int
F0040B2C: 7fff46d3                 call    _sleep
F0040B30: 9210201a                 mov     0x1A, %o1
F0040B34: d00423d8                 ld      [%l0+0x3D8], %o0
F0040B38: 80a22000                 cmp     %o0, 0
F0040B3C: 02bffffc                 be      loc_F0040B2C
F0040B40: 901423d8                 or      %l0, 0x3D8, %o0
F0040B44: d0046124                 ld      [%l1+0x124], %o0
F0040B48: d40423d8                 ld      [%l0+0x3D8], %o2
F0040B4C: 90023fff                 inc     -1, %o0
F0040B50: d0246124                 st      %o0, [%l1+0x124]
F0040B54: d202a00c                 ld      [%o2+0xC], %o1
F0040B58: 9010000a                 mov     %o2, %o0
F0040B5C: 40000006                 call    sub_F0040B74
F0040B60: d22423d8                 st      %o1, [%l0+0x3D8]
F0040B64: 10bfffec                 ba      loc_F0040B14
F0040B68: d0046124                 ld      [%l1+0x124], %o0
F0040B6C: 81c7e008                 ret
F0040B70: 81e80000                 restore
