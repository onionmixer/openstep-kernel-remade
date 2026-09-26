F00B1A1C: 9de3bf98                 save    %sp, -0x68, %sp
F00B1A20: 113c04d4                 sethi   %hi(_cons_tp), %o0
F00B1A24: d0022290                 ld      [%o0+%lo(_cons_tp)], %o0
F00B1A28: d4122038                 lduh    [%o0+0x38], %o2
F00B1A2C: 952aa010                 sll     %o2, 16, %o2
F00B1A30: 913aa010                 sra     %o2, 16, %o0
F00B1A34: 9532a018                 srl     %o2, 24, %o2
F00B1A38: 932aa001                 sll     %o2, 1, %o1
F00B1A3C: 9202400a                 add     %o1, %o2, %o1
F00B1A40: 932a6002                 sll     %o1, 2, %o1
F00B1A44: 9222400a                 sub     %o1, %o2, %o1
F00B1A48: 932a6002                 sll     %o1, 2, %o1
F00B1A4C: 153c04729412a1f0         set     _cdevsw, %o2
F00B1A54: 9202400a                 add     %o1, %o2, %o1
F00B1A58: d4026008                 ld      [%o1+8], %o2
F00B1A5C: 9fc28000                 call    %o2
F00B1A60: 92100019                 mov     %i1, %o1
F00B1A64: 81c7e008                 ret
F00B1A68: 91e80008                 restore %g0, %o0, %o0
