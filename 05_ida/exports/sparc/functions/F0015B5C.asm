F0015B5C: 9de3bf90                 save    %sp, -0x70, %sp! int
F0015B60: 133c03d292126398         set     unk_F00F4B98, %o1! __src
F0015B68: 113c04cf                 sethi   %hi(dword_F0133DDC), %o0! __dst
F0015B6C: e00221dc                 ld      [%o0+%lo(dword_F0133DDC)], %l0
F0015B70: 941020d0                 mov     0xD0, %o2! int
F0015B74: a6042058                 add     %l0, 0x58, %l3 ! 'X'
F0015B78: e2042024                 ld      [%l0+0x24], %l1
F0015B7C: 7fffc5c9                 call    _memcpy
F0015B80: 90100013                 mov     %l3, %o0
F0015B84: d0044000                 ld      [%l1], %o0
F0015B88: 80a22100                 cmp     %o0, 0x100
F0015B8C: 04800003                 ble     loc_F0015B98
F0015B90: 90102100                 mov     0x100, %o0
F0015B94: d0244000                 st      %o0, [%l1]
F0015B98: d2046004                 ld      [%l1+4], %o1
F0015B9C: d0044000                 ld      [%l1], %o0
F0015BA0: 80a26000                 cmp     %o1, 0
F0015BA4: 9002201f                 inc     0x1F, %o0
F0015BA8: 02800009                 be      loc_F0015BCC
F0015BAC: a5322005                 srl     %o0, 5, %l2
F0015BB0: 90100009                 mov     %o1, %o0! int
F0015BB4: 92100013                 mov     %l3, %o1! int
F0015BB8: 40020928                 call    _copyin
F0015BBC: 952ca002                 sll     %l2, 2, %o2! int
F0015BC0: 80a22000                 cmp     %o0, 0
F0015BC4: 12800035                 bne     loc_F0015C98
F0015BC8: d0242124                 st      %o0, [%l0+0x124]
F0015BCC: d0046008                 ld      [%l1+8], %o0! int
F0015BD0: 80a22000                 cmp     %o0, 0
F0015BD4: 02800007                 be      loc_F0015BF0
F0015BD8: 92042078                 add     %l0, 0x78, %o1 ! 'x'! int
F0015BDC: 4002091f                 call    _copyin
F0015BE0: 952ca002                 sll     %l2, 2, %o2! int
F0015BE4: 80a22000                 cmp     %o0, 0
F0015BE8: 1280002c                 bne     loc_F0015C98
F0015BEC: d0242124                 st      %o0, [%l0+0x124]
F0015BF0: d004600c                 ld      [%l1+0xC], %o0! int
F0015BF4: 80a22000                 cmp     %o0, 0
F0015BF8: 02800007                 be      loc_F0015C14
F0015BFC: 92042098                 add     %l0, 0x98, %o1! int
F0015C00: 40020916                 call    _copyin
F0015C04: 952ca002                 sll     %l2, 2, %o2! int
F0015C08: 80a22000                 cmp     %o0, 0
F0015C0C: 12800023                 bne     loc_F0015C98
F0015C10: d0242124                 st      %o0, [%l0+0x124]
F0015C14: d0046010                 ld      [%l1+0x10], %o0! int
F0015C18: 80a22000                 cmp     %o0, 0
F0015C1C: 0280001f                 be      loc_F0015C98
F0015C20: a2042118                 add     %l0, 0x118, %l1
F0015C24: 92100011                 mov     %l1, %o1! int
F0015C28: 4002090c                 call    _copyin
F0015C2C: 94102008                 mov     8, %o2
F0015C30: 80a22000                 cmp     %o0, 0
F0015C34: 12800019                 bne     loc_F0015C98
F0015C38: d0242124                 st      %o0, [%l0+0x124]
F0015C3C: 7ffff642                 call    _itimerfix
F0015C40: 90100011                 mov     %l1, %o0
F0015C44: 80a22000                 cmp     %o0, 0
F0015C48: 02800004                 be      loc_F0015C58
F0015C4C: 90102016                 mov     0x16, %o0
F0015C50: 10800012                 ba      loc_F0015C98
F0015C54: d0242124                 st      %o0, [%l0+0x124]
F0015C58: d0042118                 ld      [%l0+0x118], %o0
F0015C5C: 80a22000                 cmp     %o0, 0
F0015C60: 32800009                 bne,a   loc_F0015C84
F0015C64: a007bff0                 add     %fp, var_10, %l0
F0015C68: d004211c                 ld      [%l0+0x11C], %o0
F0015C6C: 80a22000                 cmp     %o0, 0
F0015C70: 32800005                 bne,a   loc_F0015C84
F0015C74: a007bff0                 add     %fp, var_10, %l0
F0015C78: 90102001                 mov     1, %o0
F0015C7C: 10800007                 ba      loc_F0015C98
F0015C80: d0242120                 st      %o0, [%l0+0x120]
F0015C84: 7ffff4c2                 call    _getthetime
F0015C88: 90100010                 mov     %l0, %o0
F0015C8C: 9004e0c0                 add     %l3, 0xC0, %o0
F0015C90: 7ffff67b                 call    _timevaladd
F0015C94: 92100010                 mov     %l0, %o1
F0015C98: 40000004                 call    _selcont
F0015C9C: 01000000                 nop
F0015CA0: 81c7e008                 ret
F0015CA4: 81e80000                 restore
