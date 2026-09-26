F00B1A6C: 9de3bf98                 save    %sp, -0x68, %sp
F00B1A70: 113c04d4                 sethi   %hi(_cons_tp), %o0
F00B1A74: d0022290                 ld      [%o0+%lo(_cons_tp)], %o0
F00B1A78: d4122038                 lduh    [%o0+0x38], %o2
F00B1A7C: 952aa010                 sll     %o2, 16, %o2
F00B1A80: 913aa010                 sra     %o2, 16, %o0
F00B1A84: 9532a018                 srl     %o2, 24, %o2
F00B1A88: 932aa001                 sll     %o2, 1, %o1
F00B1A8C: 9202400a                 add     %o1, %o2, %o1
F00B1A90: 932a6002                 sll     %o1, 2, %o1
F00B1A94: 9222400a                 sub     %o1, %o2, %o1
F00B1A98: 932a6002                 sll     %o1, 2, %o1
F00B1A9C: 153c04729412a1f0         set     _cdevsw, %o2
F00B1AA4: 9202400a                 add     %o1, %o2, %o1
F00B1AA8: d402600c                 ld      [%o1+0xC], %o2
F00B1AAC: 9fc28000                 call    %o2
F00B1AB0: 92100019                 mov     %i1, %o1
F00B1AB4: 81c7e008                 ret
F00B1AB8: 91e80008                 restore %g0, %o0, %o0
