F0091B94: 9de3bf90                 save    %sp, -0x70, %sp
F0091B98: d0062004                 ld      [%i0+4], %o0
F0091B9C: 80a22028                 cmp     %o0, 0x28 ! '('
F0091BA0: 12800012                 bne     loc_F0091BE8
F0091BA4: 90103ed0                 mov     -0x130, %o0
F0091BA8: d0060000                 ld      [%i0], %o0
F0091BAC: 80a22000                 cmp     %o0, 0
F0091BB0: 0680000d                 bl      loc_F0091BE4
F0091BB4: 133c0448                 sethi   %hi(dword_F01122D8), %o1
F0091BB8: d0062018                 ld      [%i0+0x18], %o0
F0091BBC: d20262d8                 ld      [%o1+%lo(dword_F01122D8)], %o1
F0091BC0: 80a20009                 cmp     %o0, %o1
F0091BC4: 12800009                 bne     loc_F0091BE8
F0091BC8: 90103ed0                 mov     -0x130, %o0
F0091BCC: d0062020                 ld      [%i0+0x20], %o0
F0091BD0: 133c0448                 sethi   %hi(dword_F01122DC), %o1
F0091BD4: d20262dc                 ld      [%o1+%lo(dword_F01122DC)], %o1
F0091BD8: 80a20009                 cmp     %o0, %o1
F0091BDC: 02800005                 be      loc_F0091BF0
F0091BE0: 13000004                 sethi   0x1000, %o1
F0091BE4: 90103ed0                 mov     -0x130, %o0
F0091BE8: 1080001b                 ba      locret_F0091C54
F0091BEC: d026601c                 st      %o0, [%i1+0x1C]
F0091BF0: d0062008                 ld      [%i0+8], %o0
F0091BF4: 7fff4da6                 call    _convert_port_to_host
F0091BF8: d227bff4                 st      %o1, [%fp+var_C]
F0091BFC: d206201c                 ld      [%i0+0x1C], %o1
F0091C00: 9606602c                 add     %i1, 0x2C, %o3 ! ','
F0091C04: d4062024                 ld      [%i0+0x24], %o2
F0091C08: 7ffffbfa                 call    _kern_IOGetDriverConfig
F0091C0C: 9807bff4                 add     %fp, var_C, %o4
F0091C10: 80a22000                 cmp     %o0, 0
F0091C14: 12800010                 bne     locret_F0091C54
F0091C18: d026601c                 st      %o0, [%i1+0x1C]
F0091C1C: 113c0448                 sethi   %hi(dword_F01122E0), %o0
F0091C20: d20222e0                 ld      [%o0+%lo(dword_F01122E0)], %o1
F0091C24: d2266020                 st      %o1, [%i1+0x20]
F0091C28: 901222e0                 bset    %lo(dword_F01122E0), %o0
F0091C2C: d2022004                 ld      [%o0+4], %o1
F0091C30: d2266024                 st      %o1, [%i1+0x24]
F0091C34: d2022008                 ld      [%o0+8], %o1
F0091C38: d007bff4                 ld      [%fp+var_C], %o0
F0091C3C: d2266028                 st      %o1, [%i1+0x28]
F0091C40: d0266028                 st      %o0, [%i1+0x28]
F0091C44: 90022003                 inc     3, %o0
F0091C48: 900a3ffc                 and     %o0, -4, %o0
F0091C4C: 9002202c                 inc     0x2C, %o0 ! ','
F0091C50: d0266004                 st      %o0, [%i1+4]
F0091C54: 81c7e008                 ret
F0091C58: 81e80000                 restore
