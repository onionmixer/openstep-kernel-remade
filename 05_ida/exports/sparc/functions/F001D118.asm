F001D118: 9de3bf98                 save    %sp, -0x68, %sp
F001D11C: 113c04cf                 sethi   %hi(_active_u), %o0
F001D120: d20221d8                 ld      [%o0+%lo(_active_u)], %o1
F001D124: d0026164                 ld      [%o1+0x164], %o0
F001D128: 80a22000                 cmp     %o0, 0
F001D12C: 02800012                 be      locret_F001D174
F001D130: b0102006                 mov     6, %i0
F001D134: d4126168                 lduh    [%o1+0x168], %o2
F001D138: 952aa010                 sll     %o2, 16, %o2
F001D13C: 913aa010                 sra     %o2, 16, %o0
F001D140: 9532a018                 srl     %o2, 24, %o2
F001D144: 932aa001                 sll     %o2, 1, %o1
F001D148: 9202400a                 add     %o1, %o2, %o1
F001D14C: 932a6002                 sll     %o1, 2, %o1
F001D150: 9222400a                 sub     %o1, %o2, %o1
F001D154: 932a6002                 sll     %o1, 2, %o1
F001D158: 153c04729412a1f0         set     _cdevsw, %o2
F001D160: 9202400a                 add     %o1, %o2, %o1
F001D164: d402600c                 ld      [%o1+0xC], %o2
F001D168: 9fc28000                 call    %o2
F001D16C: 92100019                 mov     %i1, %o1
F001D170: b0100008                 mov     %o0, %i0
F001D174: 81c7e008                 ret
F001D178: 81e80000                 restore
