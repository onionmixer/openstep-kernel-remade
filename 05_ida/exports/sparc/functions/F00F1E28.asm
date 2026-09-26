F00F1E28: 9de3bf98                 save    %sp, -0x68, %sp
F00F1E2C: 113c04cf                 sethi   %hi(dword_F0133CEC), %o0
F00F1E30: d00220ec                 ld      [%o0+%lo(dword_F0133CEC)], %o0
F00F1E34: 80a22000                 cmp     %o0, 0
F00F1E38: 12800050                 bne     loc_F00F1F78
F00F1E3C: 113c04cf                 sethi   -0xFECC400, %o0
F00F1E40: 94102000                 mov     0, %o2
F00F1E44: 113c04bc                 sethi   %hi(dword_F012F128), %o0
F00F1E48: 92100008                 mov     %o0, %o1
F00F1E4C: d0022128                 ld      [%o0+%lo(dword_F012F128)], %o0
F00F1E50: 80a28008                 cmp     %o2, %o0
F00F1E54: 1a800010                 bcc     loc_F00F1E94
F00F1E58: 173c04cf                 sethi   -0xFECC400, %o3
F00F1E5C: 113c04bc                 sethi   %hi(dword_F012F124), %o0
F00F1E60: da022124                 ld      [%o0+%lo(dword_F012F124)], %o5
F00F1E64: d8026128                 ld      [%o1+0x128], %o4
F00F1E68: 912aa001                 sll     %o2, 1, %o0
F00F1E6C: 9002000a                 add     %o0, %o2, %o0
F00F1E70: 912a2003                 sll     %o0, 3, %o0
F00F1E74: 90034008                 add     %o5, %o0, %o0
F00F1E78: d202e0e8                 ld      [%o3+0xE8], %o1
F00F1E7C: d0022008                 ld      [%o0+8], %o0
F00F1E80: 92024008                 add     %o1, %o0, %o1
F00F1E84: 9402a001                 inc     %o2
F00F1E88: 80a2800c                 cmp     %o2, %o4
F00F1E8C: 0abffff7                 bcs     loc_F00F1E68
F00F1E90: d222e0e8                 st      %o1, [%o3+0xE8]
F00F1E94: 7ffffa89                 call    __objc_create_zone
F00F1E98: 01000000                 nop
F00F1E9C: 7ffffa87                 call    __objc_create_zone
F00F1EA0: a0100008                 mov     %o0, %l0
F00F1EA4: 133c04cf                 sethi   %hi(dword_F0133CE8), %o1
F00F1EA8: d20260e8                 ld      [%o1+%lo(dword_F0133CE8)], %o1
F00F1EAC: 92026001                 inc     %o1
F00F1EB0: d4042004                 ld      [%l0+4], %o2
F00F1EB4: 9fc28000                 call    %o2
F00F1EB8: 932a6002                 sll     %o1, 2, %o1
F00F1EBC: 133c04cf                 sethi   %hi(dword_F0133CEC), %o1
F00F1EC0: 80a22000                 cmp     %o0, 0
F00F1EC4: 12800005                 bne     loc_F00F1ED8
F00F1EC8: d02260ec                 st      %o0, [%o1+%lo(dword_F0133CEC)]
F00F1ECC: 113c03f4                 sethi   %hi(aUnableToAlloca_0), %o0! "unable to allocate module vector"
F00F1ED0: 7fffface                 call    __objc_fatal
F00F1ED4: 90122298                 bset    %lo(aUnableToAlloca_0), %o0! "unable to allocate module vector"
F00F1ED8: 94102000                 mov     0, %o2
F00F1EDC: 113c04cf                 sethi   %hi(dword_F0133CEC), %o0
F00F1EE0: d60220ec                 ld      [%o0+%lo(dword_F0133CEC)], %o3
F00F1EE4: 113c04bc                 sethi   %hi(dword_F012F128), %o0
F00F1EE8: d0022128                 ld      [%o0+%lo(dword_F012F128)], %o0
F00F1EEC: 80a28008                 cmp     %o2, %o0
F00F1EF0: 3a800021                 bcc,a   loc_F00F1F74
F00F1EF4: c022c000                 clr     [%o3]
F00F1EF8: 053c04bc                 sethi   %hi(dword_F012F124), %g2
F00F1EFC: 073c04bc                 sethi   -0xFED1000, %g3
F00F1F00: d000a124                 ld      [%g2+%lo(dword_F012F124)], %o0
F00F1F04: 932aa001                 sll     %o2, 1, %o1
F00F1F08: 98100009                 mov     %o1, %o4
F00F1F0C: 9202400a                 add     %o1, %o2, %o1
F00F1F10: 932a6003                 sll     %o1, 3, %o1
F00F1F14: 90020009                 add     %o0, %o1, %o0
F00F1F18: da022004                 ld      [%o0+4], %o5
F00F1F1C: 92102000                 mov     0, %o1
F00F1F20: d0022008                 ld      [%o0+8], %o0
F00F1F24: 80a24008                 cmp     %o1, %o0
F00F1F28: 1a80000d                 bcc     loc_F00F1F5C
F00F1F2C: 9003000a                 add     %o4, %o2, %o0
F00F1F30: 992a2003                 sll     %o0, 3, %o4
F00F1F34: 912a6004                 sll     %o1, 4, %o0
F00F1F38: 90034008                 add     %o5, %o0, %o0
F00F1F3C: d022c000                 st      %o0, [%o3]
F00F1F40: 92026001                 inc     %o1
F00F1F44: d000a124                 ld      [%g2+0x124], %o0
F00F1F48: 9002000c                 add     %o0, %o4, %o0
F00F1F4C: d0022008                 ld      [%o0+8], %o0
F00F1F50: 80a24008                 cmp     %o1, %o0
F00F1F54: 0abffff8                 bcs     loc_F00F1F34
F00F1F58: 9602e004                 inc     4, %o3
F00F1F5C: 9402a001                 inc     %o2
F00F1F60: d000e128                 ld      [%g3+0x128], %o0
F00F1F64: 80a28008                 cmp     %o2, %o0
F00F1F68: 0abfffe7                 bcs     loc_F00F1F04
F00F1F6C: d000a124                 ld      [%g2+0x124], %o0
F00F1F70: c022c000                 clr     [%o3]
F00F1F74: 113c04cf                 sethi   -0xFECC400, %o0
F00F1F78: f00220ec                 ld      [%o0+0xEC], %i0
F00F1F7C: 81c7e008                 ret
F00F1F80: 81e80000                 restore
