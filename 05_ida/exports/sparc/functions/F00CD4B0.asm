F00CD4B0: 9de3bf90                 save    %sp, -0x70, %sp
F00CD4B4: 80a6a017                 cmp     %i2, 0x17! switch 24 cases
F00CD4B8: 18800031                 bgu     def_F00CD4CC! jumptable F00CD4CC default case, cases 1-6,10-13,15,16,20-22
F00CD4BC: 053c0335                 sethi   %hi(jpt_F00CD4CC), %g2
F00CD4C0: 8410a0d4                 bset    %lo(jpt_F00CD4CC), %g2
F00CD4C4: 872ea002                 sll     %i2, 2, %g3
F00CD4C8: c400c002                 ld      [%g3+%g2], %g2
F00CD4CC: 81c08000                 jmp     %g2! switch jump
F00CD4D0: 01000000                 nop
F00CD534: 10800013                 ba      locret_F00CD580! jumptable F00CD4CC case 0
F00CD538: b0102000                 mov     0, %i0
F00CD53C: 10800011                 ba      locret_F00CD580! jumptable F00CD4CC case 18
F00CD540: b0103d30                 mov     -0x2D0, %i0
F00CD544: 1080000f                 ba      locret_F00CD580! jumptable F00CD4CC case 7
F00CD548: b0103d3e                 mov     -0x2C2, %i0
F00CD54C: 1080000d                 ba      locret_F00CD580! jumptable F00CD4CC case 19
F00CD550: b0103d41                 mov     -0x2BF, %i0
F00CD554: 1080000b                 ba      locret_F00CD580! jumptable F00CD4CC case 14
F00CD558: b0103d37                 mov     -0x2C9, %i0
F00CD55C: 10800009                 ba      locret_F00CD580! jumptable F00CD4CC case 9
F00CD560: b0103d38                 mov     -0x2C8, %i0
F00CD564: 10800007                 ba      locret_F00CD580! jumptable F00CD4CC case 8
F00CD568: b0103d42                 mov     -0x2BE, %i0
F00CD56C: 10800005                 ba      locret_F00CD580! jumptable F00CD4CC case 23
F00CD570: b0103d2c                 mov     -0x2D4, %i0
F00CD574: 10800003                 ba      locret_F00CD580! jumptable F00CD4CC case 17
F00CD578: b0103d31                 mov     -0x2CF, %i0
F00CD57C: b0103d36                 mov     -0x2CA, %i0! jumptable F00CD4CC default case, cases 1-6,10-13,15,16,20-22
F00CD580: 81c7e008                 ret
F00CD584: 81e80000                 restore
