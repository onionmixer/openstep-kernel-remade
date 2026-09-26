F00F2B60: 9de3bf98                 save    %sp, -0x68, %sp
F00F2B64: 233c04bc                 sethi   %hi(dword_F012F128), %l1
F00F2B68: d0046128                 ld      [%l1+%lo(dword_F012F128)], %o0
F00F2B6C: 90022001                 inc     %o0
F00F2B70: d0246128                 st      %o0, [%l1+%lo(dword_F012F128)]
F00F2B74: 253c04bc                 sethi   %hi(dword_F012F124), %l2
F00F2B78: d004a124                 ld      [%l2+%lo(dword_F012F124)], %o0! __dst
F00F2B7C: 80a22000                 cmp     %o0, 0
F00F2B80: 1280000e                 bne     loc_F00F2BB8
F00F2B84: 01000000                 nop
F00F2B88: 7ffff74c                 call    __objc_create_zone
F00F2B8C: 01000000                 nop
F00F2B90: 7ffff74a                 call    __objc_create_zone
F00F2B94: a0100008                 mov     %o0, %l0
F00F2B98: d4046128                 ld      [%l1+%lo(dword_F012F128)], %o2
F00F2B9C: 932aa001                 sll     %o2, 1, %o1
F00F2BA0: 9202400a                 add     %o1, %o2, %o1
F00F2BA4: d4042004                 ld      [%l0+4], %o2
F00F2BA8: 9fc28000                 call    %o2
F00F2BAC: 932a6003                 sll     %o1, 3, %o1
F00F2BB0: 1080001c                 ba      loc_F00F2C20
F00F2BB4: d024a124                 st      %o0, [%l2+%lo(dword_F012F124)]
F00F2BB8: 7ffff740                 call    __objc_create_zone
F00F2BBC: e604a124                 ld      [%l2+0x124], %l3
F00F2BC0: 7ffff73e                 call    __objc_create_zone
F00F2BC4: a0100008                 mov     %o0, %l0
F00F2BC8: 233c04bc                 sethi   %hi(dword_F012F128), %l1
F00F2BCC: d4046128                 ld      [%l1+%lo(dword_F012F128)], %o2
F00F2BD0: 932aa001                 sll     %o2, 1, %o1
F00F2BD4: 9202400a                 add     %o1, %o2, %o1
F00F2BD8: d4042004                 ld      [%l0+4], %o2
F00F2BDC: 9fc28000                 call    %o2
F00F2BE0: 932a6003                 sll     %o1, 3, %o1
F00F2BE4: d024a124                 st      %o0, [%l2+0x124]
F00F2BE8: d2046128                 ld      [%l1+%lo(dword_F012F128)], %o1
F00F2BEC: 92027fff                 inc     -1, %o1
F00F2BF0: 952a6001                 sll     %o1, 1, %o2
F00F2BF4: 94028009                 add     %o2, %o1, %o2! __n
F00F2BF8: 92100013                 mov     %l3, %o1! __src
F00F2BFC: 7ffc51a9                 call    _memcpy
F00F2C00: 952aa003                 sll     %o2, 3, %o2
F00F2C04: 7ffff72d                 call    __objc_create_zone
F00F2C08: 01000000                 nop
F00F2C0C: 7ffff72b                 call    __objc_create_zone
F00F2C10: a0100008                 mov     %o0, %l0
F00F2C14: d4042008                 ld      [%l0+8], %o2
F00F2C18: 9fc28000                 call    %o2
F00F2C1C: 92100013                 mov     %l3, %o1
F00F2C20: 113c04bc                 sethi   %hi(dword_F012F128), %o0
F00F2C24: d2022128                 ld      [%o0+%lo(dword_F012F128)], %o1
F00F2C28: 113c04bc                 sethi   %hi(dword_F012F124), %o0
F00F2C2C: d4022124                 ld      [%o0+%lo(dword_F012F124)], %o2
F00F2C30: 912a6001                 sll     %o1, 1, %o0
F00F2C34: 90020009                 add     %o0, %o1, %o0
F00F2C38: 912a2003                 sll     %o0, 3, %o0
F00F2C3C: 9002000a                 add     %o0, %o2, %o0
F00F2C40: f0223fe8                 st      %i0, [%o0-0x18]
F00F2C44: c0223fec                 clr     [%o0-0x14]
F00F2C48: c0223ff0                 clr     [%o0-0x10]
F00F2C4C: c0223ff4                 clr     [%o0-0xC]
F00F2C50: c0223ff8                 clr     [%o0-8]
F00F2C54: c0223ffc                 clr     [%o0-4]
F00F2C58: 81c7e008                 ret
F00F2C5C: 81e80000                 restore
