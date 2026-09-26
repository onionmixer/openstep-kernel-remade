F001D260: 9de3bf98                 save    %sp, -0x68, %sp
F001D264: 113c04cf                 sethi   %hi(_active_u), %o0
F001D268: d40221d8                 ld      [%o0+%lo(_active_u)], %o2
F001D26C: d202a164                 ld      [%o2+0x164], %o1
F001D270: 80a26000                 cmp     %o1, 0
F001D274: 02800013                 be      loc_F001D2C0
F001D278: 901221d8                 bset    %lo(_active_u), %o0
F001D27C: d412a168                 lduh    [%o2+0x168], %o2
F001D280: 952aa010                 sll     %o2, 16, %o2
F001D284: 913aa010                 sra     %o2, 16, %o0
F001D288: 9532a018                 srl     %o2, 24, %o2
F001D28C: 932aa001                 sll     %o2, 1, %o1
F001D290: 9202400a                 add     %o1, %o2, %o1
F001D294: 932a6002                 sll     %o1, 2, %o1
F001D298: 9222400a                 sub     %o1, %o2, %o1
F001D29C: 932a6002                 sll     %o1, 2, %o1
F001D2A0: 153c04729412a1f0         set     _cdevsw, %o2
F001D2A8: 9202400a                 add     %o1, %o2, %o1
F001D2AC: d402601c                 ld      [%o1+0x1C], %o2
F001D2B0: 9fc28000                 call    %o2
F001D2B4: 92100019                 mov     %i1, %o1
F001D2B8: 10800006                 ba      locret_F001D2D0
F001D2BC: b0100008                 mov     %o0, %i0
F001D2C0: d2022004                 ld      [%o0+4], %o1
F001D2C4: b0102000                 mov     0, %i0
F001D2C8: 90102006                 mov     6, %o0
F001D2CC: d02a6038                 stb     %o0, [%o1+0x38]
F001D2D0: 81c7e008                 ret
F001D2D4: 81e80000                 restore
