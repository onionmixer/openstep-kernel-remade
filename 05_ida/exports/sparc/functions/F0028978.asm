F0028978: 9de3bf98                 save    %sp, -0x68, %sp
F002897C: 053c04d0                 sethi   %hi(_file_list), %g2
F0028980: f200a058                 ld      [%g2+%lo(_file_list)], %i1
F0028984: 8610a058                 or      %g2, %lo(_file_list), %g3
F0028988: 80a64003                 cmp     %i1, %g3
F002898C: 02800021                 be      locret_F0028A10
F0028990: 852e2010                 sll     %i0, 16, %g2
F0028994: b138a010                 sra     %g2, 16, %i0
F0028998: b4100003                 mov     %g3, %i2
F002899C: c456600e                 ldsh    [%i1+0xE], %g2
F00289A0: 80a0a000                 cmp     %g2, 0
F00289A4: 22800018                 be,a    loc_F0028A04
F00289A8: f2064000                 ld      [%i1], %i1
F00289AC: c456600c                 ldsh    [%i1+0xC], %g2
F00289B0: 80a0a001                 cmp     %g2, 1
F00289B4: 32800014                 bne,a   loc_F0028A04
F00289B8: f2064000                 ld      [%i1], %i1
F00289BC: c6066018                 ld      [%i1+0x18], %g3
F00289C0: 80a0e000                 cmp     %g3, 0
F00289C4: 22800010                 be,a    loc_F0028A04
F00289C8: f2064000                 ld      [%i1], %i1
F00289CC: c400e028                 ld      [%g3+0x28], %g2
F00289D0: 80a0a004                 cmp     %g2, 4
F00289D4: 02800004                 be      loc_F00289E4
F00289D8: 80a0a009                 cmp     %g2, 9
F00289DC: 3280000a                 bne,a   loc_F0028A04
F00289E0: f2064000                 ld      [%i1], %i1
F00289E4: c450e02c                 ldsh    [%g3+0x2C], %g2
F00289E8: 80a08018                 cmp     %g2, %i0
F00289EC: 32800006                 bne,a   loc_F0028A04
F00289F0: f2064000                 ld      [%i1], %i1
F00289F4: c4066008                 ld      [%i1+8], %g2
F00289F8: 8408bffc                 and     %g2, -4, %g2
F00289FC: c4266008                 st      %g2, [%i1+8]
F0028A00: f2064000                 ld      [%i1], %i1
F0028A04: 80a6401a                 cmp     %i1, %i2
F0028A08: 32bfffe6                 bne,a   loc_F00289A0
F0028A0C: c456600e                 ldsh    [%i1+0xE], %g2
F0028A10: 81c7e008                 ret
F0028A14: 81e80000                 restore
