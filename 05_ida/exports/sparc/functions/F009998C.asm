F009998C: 9de3bf98                 save    %sp, -0x68, %sp
F0099990: 053c04f6                 sethi   %hi(_sbusmap), %g2
F0099994: c400a320                 ld      [%g2+%lo(_sbusmap)], %g2
F0099998: 80a64002                 cmp     %i1, %g2
F009999C: 0280000a                 be      loc_F00999C4
F00999A0: 053c04f6                 sethi   %hi(_bigsbusmap), %g2
F00999A4: c400a2f0                 ld      [%g2+%lo(_bigsbusmap)], %g2
F00999A8: 80a64002                 cmp     %i1, %g2
F00999AC: 02800006                 be      loc_F00999C4
F00999B0: 053c04f6                 sethi   %hi(_mbutlmap), %g2
F00999B4: c400a310                 ld      [%g2+%lo(_mbutlmap)], %g2
F00999B8: 80a64002                 cmp     %i1, %g2
F00999BC: 32800018                 bne,a   locret_F0099A1C
F00999C0: b0102000                 mov     0, %i0
F00999C4: 84063ffe                 add     %i0, -2, %g2
F00999C8: 80a0a0fd                 cmp     %g2, 0xFD
F00999CC: 18800004                 bgu     loc_F00999DC
F00999D0: 053c04f6                 sethi   %hi(_sbusmap), %g2
F00999D4: 10800012                 ba      locret_F0099A1C
F00999D8: f000a320                 ld      [%g2+%lo(_sbusmap)], %i0
F00999DC: 053ffc04                 sethi   -0xFF000, %g2
F00999E0: 84060002                 add     %i0, %g2, %g2
F00999E4: 80a0a5ff                 cmp     %g2, 0x5FF
F00999E8: 18800004                 bgu     loc_F00999F8
F00999EC: 053c04f6                 sethi   %hi(_bigsbusmap), %g2
F00999F0: 1080000b                 ba      locret_F0099A1C
F00999F4: f000a2f0                 ld      [%g2+%lo(_bigsbusmap)], %i0
F00999F8: 053ffc028410a200         set     -0xFF600, %g2
F0099A00: 84060002                 add     %i0, %g2, %g2
F0099A04: 80a0a1ff                 cmp     %g2, 0x1FF
F0099A08: 18800004                 bgu     loc_F0099A18
F0099A0C: 053c04f6                 sethi   %hi(_mbutlmap), %g2
F0099A10: 10800003                 ba      locret_F0099A1C
F0099A14: f000a310                 ld      [%g2+%lo(_mbutlmap)], %i0
F0099A18: b0102000                 mov     0, %i0
F0099A1C: 81c7e008                 ret
F0099A20: 81e80000                 restore
