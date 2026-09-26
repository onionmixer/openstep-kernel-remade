F0013920: 9de3bf98                 save    %sp, -0x68, %sp! int
F0013924: 273c04cf                 sethi   %hi(dword_F0133DDC), %l3
F0013928: d004e1dc                 ld      [%l3+%lo(dword_F0133DDC)], %o0
F001392C: 7ffff010                 call    _suser
F0013930: e4022024                 ld      [%o0+0x24], %l2
F0013934: 80a22000                 cmp     %o0, 0
F0013938: 02800015                 be      locret_F001398C
F001393C: 01000000                 nop
F0013940: d004a004                 ld      [%l2+4], %o0
F0013944: 80a220ff                 cmp     %o0, 0xFF
F0013948: 08800005                 bleu    loc_F001395C
F001394C: d204e1dc                 ld      [%l3+%lo(dword_F0133DDC)], %o1! int
F0013950: 90102016                 mov     0x16, %o0
F0013954: 1080000e                 ba      locret_F001398C
F0013958: d02a6038                 stb     %o0, [%o1+0x38]
F001395C: 233c04d1                 sethi   %hi(_hostnamelen), %l1
F0013960: d0246330                 st      %o0, [%l1+%lo(_hostnamelen)]
F0013964: 213c04d1                 sethi   %hi(_hostname), %l0
F0013968: d0048000                 ld      [%l2], %o0! int
F001396C: a0142230                 bset    %lo(_hostname), %l0
F0013970: d404a004                 ld      [%l2+4], %o2! int
F0013974: 400211b9                 call    _copyin
F0013978: 92100010                 mov     %l0, %o1
F001397C: d204e1dc                 ld      [%l3+0x1DC], %o1
F0013980: d02a6038                 stb     %o0, [%o1+0x38]
F0013984: d0046330                 ld      [%l1+%lo(_hostnamelen)], %o0
F0013988: c02a0010                 clrb    [%o0+%l0]
F001398C: 81c7e008                 ret
F0013990: 81e80000                 restore
