F007A498: 9de3bf98                 save    %sp, -0x68, %sp
F007A49C: f0060000                 ld      [%i0], %i0
F007A4A0: 80a62000                 cmp     %i0, 0
F007A4A4: 02800011                 be      locret_F007A4E8
F007A4A8: 01000000                 nop
F007A4AC: c40624b0                 ld      [%i0+0x4B0], %g2
F007A4B0: 80a08019                 cmp     %g2, %i1
F007A4B4: 22800002                 be,a    loc_F007A4BC
F007A4B8: c02624b0                 clr     [%i0+0x4B0]
F007A4BC: 86102000                 mov     0, %g3
F007A4C0: c406218c                 ld      [%i0+0x18C], %g2
F007A4C4: 80a08019                 cmp     %g2, %i1
F007A4C8: 12800005                 bne     loc_F007A4DC
F007A4CC: 8600e001                 inc     %g3
F007A4D0: c026218c                 clr     [%i0+0x18C]
F007A4D4: 10800005                 ba      locret_F007A4E8
F007A4D8: c0262190                 clr     [%i0+0x190]
F007A4DC: 80a0e031                 cmp     %g3, 0x31 ! '1'
F007A4E0: 04bffff8                 ble     loc_F007A4C0
F007A4E4: b0062010                 inc     0x10, %i0
F007A4E8: 81c7e008                 ret
F007A4EC: 81e80000                 restore
