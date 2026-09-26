F00C0F4C: 9de3bf98                 save    %sp, -0x68, %sp
F00C0F50: 113c0483                 sethi   %hi(_kbdwriteenable), %o0
F00C0F54: d0022284                 ld      [%o0+%lo(_kbdwriteenable)], %o0
F00C0F58: 80a22000                 cmp     %o0, 0
F00C0F5C: 2280000f                 be,a    loc_F00C0F98
F00C0F60: 912e6018                 sll     %i1, 24, %o0
F00C0F64: 7fff5715                 call    _spltty
F00C0F68: 01000000                 nop
F00C0F6C: a0100008                 mov     %o0, %l0
F00C0F70: 912e6018                 sll     %i1, 24, %o0
F00C0F74: 913a2018                 sra     %o0, 24, %o0! int
F00C0F78: 7ffd6ef6                 call    _putc
F00C0F7C: 92062018                 add     %i0, 0x18, %o1
F00C0F80: d2062024                 ld      [%i0+0x24], %o1
F00C0F84: 9fc24000                 call    %o1
F00C0F88: 90100018                 mov     %i0, %o0
F00C0F8C: 7fff5766                 call    _splx
F00C0F90: 90100010                 mov     %l0, %o0
F00C0F94: 912e6018                 sll     %i1, 24, %o0
F00C0F98: 913a2018                 sra     %o0, 24, %o0
F00C0F9C: 80a2200b                 cmp     %o0, 0xB
F00C0FA0: 12800005                 bne     loc_F00C0FB4
F00C0FA4: 80a2200a                 cmp     %o0, 0xA
F00C0FA8: 113c0483                 sethi   %hi(_kbdclick), %o0
F00C0FAC: 10800006                 ba      locret_F00C0FC4
F00C0FB0: c0222288                 clr     [%o0+%lo(_kbdclick)]
F00C0FB4: 12800004                 bne     locret_F00C0FC4
F00C0FB8: 133c0483                 sethi   %hi(_kbdclick), %o1
F00C0FBC: 90102001                 mov     1, %o0
F00C0FC0: d0226288                 st      %o0, [%o1+%lo(_kbdclick)]
F00C0FC4: 81c7e008                 ret
F00C0FC8: 81e80000                 restore
