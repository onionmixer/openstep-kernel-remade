F001D0B4: 9de3bf98                 save    %sp, -0x68, %sp
F001D0B8: 113c04cf                 sethi   %hi(_active_u), %o0
F001D0BC: d20221d8                 ld      [%o0+%lo(_active_u)], %o1
F001D0C0: d0026164                 ld      [%o1+0x164], %o0
F001D0C4: 80a22000                 cmp     %o0, 0
F001D0C8: 02800012                 be      locret_F001D110
F001D0CC: b0102006                 mov     6, %i0
F001D0D0: d4126168                 lduh    [%o1+0x168], %o2
F001D0D4: 952aa010                 sll     %o2, 16, %o2
F001D0D8: 913aa010                 sra     %o2, 16, %o0
F001D0DC: 9532a018                 srl     %o2, 24, %o2
F001D0E0: 932aa001                 sll     %o2, 1, %o1
F001D0E4: 9202400a                 add     %o1, %o2, %o1
F001D0E8: 932a6002                 sll     %o1, 2, %o1
F001D0EC: 9222400a                 sub     %o1, %o2, %o1
F001D0F0: 932a6002                 sll     %o1, 2, %o1
F001D0F4: 153c04729412a1f0         set     _cdevsw, %o2
F001D0FC: 9202400a                 add     %o1, %o2, %o1
F001D100: d4026008                 ld      [%o1+8], %o2
F001D104: 9fc28000                 call    %o2
F001D108: 92100019                 mov     %i1, %o1
F001D10C: b0100008                 mov     %o0, %i0
F001D110: 81c7e008                 ret
F001D114: 81e80000                 restore
