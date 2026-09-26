F00DBDB8: 9de3bf90                 save    %sp, -0x70, %sp
F00DBDBC: 9210001a                 mov     %i2, %o1
F00DBDC0: 94027da8                 add     %o1, -0x258, %o2
F00DBDC4: 80a2a004                 cmp     %o2, 4! switch 5 cases
F00DBDC8: 1880001b                 bgu     def_F00DBDE0! jumptable F00DBDE0 default case
F00DBDCC: 113c03f1                 sethi   -0xFF03C00, %o0
F00DBDD0: 113c036f901221e8         set     jpt_F00DBDE0, %o0
F00DBDD8: 932aa002                 sll     %o2, 2, %o1
F00DBDDC: d0024008                 ld      [%o1+%o0], %o0
F00DBDE0: 81c20000                 jmp     %o0! switch jump
F00DBDE4: 01000000                 nop
F00DBDFC: 10800010                 ba      locret_F00DBE3C! jumptable F00DBDE0 case 0
F00DBE00: c0262068                 clr     [%i0+0x68]
F00DBE04: 90102003                 mov     3, %o0! jumptable F00DBDE0 case 1
F00DBE08: 1080000d                 ba      locret_F00DBE3C
F00DBE0C: d0262068                 st      %o0, [%i0+0x68]
F00DBE10: 90102001                 mov     1, %o0! jumptable F00DBDE0 case 2
F00DBE14: 1080000a                 ba      locret_F00DBE3C
F00DBE18: d0262068                 st      %o0, [%i0+0x68]
F00DBE1C: 90102002                 mov     2, %o0! jumptable F00DBDE0 case 3
F00DBE20: 10800007                 ba      locret_F00DBE3C
F00DBE24: d0262068                 st      %o0, [%i0+0x68]
F00DBE28: 90102004                 mov     4, %o0! jumptable F00DBDE0 case 4
F00DBE2C: 10800004                 ba      locret_F00DBE3C
F00DBE30: d0262068                 st      %o0, [%i0+0x68]
F00DBE34: 7fffa8b0                 call    _IOLog! jumptable F00DBDE0 default case
F00DBE38: 90122148                 bset    0x148, %o0
F00DBE3C: 81c7e008                 ret
F00DBE40: 81e80000                 restore
