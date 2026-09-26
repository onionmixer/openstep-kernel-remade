F00139E0: 9de3bf98                 save    %sp, -0x68, %sp! int
F00139E4: 273c04cf                 sethi   %hi(dword_F0133DDC), %l3
F00139E8: d004e1dc                 ld      [%l3+%lo(dword_F0133DDC)], %o0
F00139EC: 7fffefe0                 call    _suser
F00139F0: e4022024                 ld      [%o0+0x24], %l2
F00139F4: 80a22000                 cmp     %o0, 0
F00139F8: 02800015                 be      locret_F0013A4C
F00139FC: 01000000                 nop
F0013A00: d004a004                 ld      [%l2+4], %o0
F0013A04: 80a220ff                 cmp     %o0, 0xFF
F0013A08: 08800005                 bleu    loc_F0013A1C
F0013A0C: d204e1dc                 ld      [%l3+%lo(dword_F0133DDC)], %o1! int
F0013A10: 90102016                 mov     0x16, %o0
F0013A14: 1080000e                 ba      locret_F0013A4C
F0013A18: d02a6038                 stb     %o0, [%o1+0x38]
F0013A1C: 233c04d1                 sethi   %hi(_domainnamelen), %l1
F0013A20: d0246200                 st      %o0, [%l1+%lo(_domainnamelen)]
F0013A24: 213c04d1                 sethi   %hi(_domainname), %l0
F0013A28: d0048000                 ld      [%l2], %o0! int
F0013A2C: a0142100                 bset    %lo(_domainname), %l0
F0013A30: d404a004                 ld      [%l2+4], %o2! int
F0013A34: 40021189                 call    _copyin
F0013A38: 92100010                 mov     %l0, %o1
F0013A3C: d204e1dc                 ld      [%l3+0x1DC], %o1
F0013A40: d02a6038                 stb     %o0, [%o1+0x38]
F0013A44: d0046200                 ld      [%l1+%lo(_domainnamelen)], %o0
F0013A48: c02a0010                 clrb    [%o0+%l0]
F0013A4C: 81c7e008                 ret
F0013A50: 81e80000                 restore
