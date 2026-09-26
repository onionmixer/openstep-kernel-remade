F004435C: 9de3bf98                 save    %sp, -0x68, %sp
F0044360: 80a62005                 cmp     %i0, 5! switch 6 cases
F0044364: 1880001e                 bgu     def_F0044378! jumptable F0044378 default case
F0044368: 053c0110                 sethi   %hi(jpt_F0044378), %g2
F004436C: 8410a380                 bset    %lo(jpt_F0044378), %g2
F0044370: 872e2002                 sll     %i0, 2, %g3
F0044374: c400c002                 ld      [%g3+%g2], %g2
F0044378: 81c08000                 jmp     %g2! switch jump
F004437C: 01000000                 nop
F0044398: 84102008                 mov     8, %g2! jumptable F0044378 case 1
F004439C: 10800014                 ba      locret_F00443EC
F00443A0: c4264000                 st      %g2, [%i1]
F00443A4: 84102009                 mov     9, %g2! jumptable F0044378 case 2
F00443A8: 10800011                 ba      locret_F00443EC
F00443AC: c4264000                 st      %g2, [%i1]
F00443B0: 8410200a                 mov     0xA, %g2! jumptable F0044378 case 3
F00443B4: 1080000e                 ba      locret_F00443EC
F00443B8: c4264000                 st      %g2, [%i1]
F00443BC: 8410200b                 mov     0xB, %g2! jumptable F0044378 case 4
F00443C0: 1080000b                 ba      locret_F00443EC
F00443C4: c4264000                 st      %g2, [%i1]
F00443C8: 8410200c                 mov     0xC, %g2! jumptable F0044378 case 5
F00443CC: 10800008                 ba      locret_F00443EC
F00443D0: c4264000                 st      %g2, [%i1]
F00443D4: 10800006                 ba      locret_F00443EC! jumptable F0044378 case 0
F00443D8: c0264000                 clr     [%i1]
F00443DC: 84102010                 mov     0x10, %g2! jumptable F0044378 default case
F00443E0: c4264000                 st      %g2, [%i1]
F00443E4: c0266004                 clr     [%i1+4]
F00443E8: f0266008                 st      %i0, [%i1+8]
F00443EC: 81c7e008                 ret
F00443F0: 81e80000                 restore
