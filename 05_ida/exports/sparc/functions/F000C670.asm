F000C670: 9de3bf98                 save    %sp, -0x68, %sp
F000C674: 80a62007                 cmp     %i0, 7! switch 8 cases
F000C678: 1880001b                 bgu     def_F000C68C! jumptable F000C68C default case, cases 4,7
F000C67C: 053c0031                 sethi   %hi(jpt_F000C68C), %g2
F000C680: 8410a294                 bset    %lo(jpt_F000C68C), %g2
F000C684: 872e2002                 sll     %i0, 2, %g3
F000C688: c400c002                 ld      [%g3+%g2], %g2
F000C68C: 81c08000                 jmp     %g2! switch jump
F000C690: 01000000                 nop
F000C6B4: 1080000d                 ba      locret_F000C6E8! jumptable F000C68C case 0
F000C6B8: b0102000                 mov     0, %i0
F000C6BC: 1080000b                 ba      locret_F000C6E8! jumptable F000C68C case 1
F000C6C0: b0102054                 mov     0x54, %i0 ! 'T'
F000C6C4: 10800009                 ba      locret_F000C6E8! jumptable F000C68C case 2
F000C6C8: b0102056                 mov     0x56, %i0 ! 'V'
F000C6CC: 10800007                 ba      locret_F000C6E8! jumptable F000C68C case 3
F000C6D0: b0102055                 mov     0x55, %i0 ! 'U'
F000C6D4: 10800005                 ba      locret_F000C6E8! jumptable F000C68C case 5
F000C6D8: b010200c                 mov     0xC, %i0
F000C6DC: 10800003                 ba      locret_F000C6E8! jumptable F000C68C case 6
F000C6E0: b010200d                 mov     0xD, %i0
F000C6E4: b0102053                 mov     0x53, %i0 ! 'S'! jumptable F000C68C default case, cases 4,7
F000C6E8: 81c7e008                 ret
F000C6EC: 81e80000                 restore
