F00232A0: 9de3bf98                 save    %sp, -0x68, %sp
F00232A4: b2100018                 mov     %i0, %i1
F00232A8: c4066008                 ld      [%i1+8], %g2
F00232AC: 8088a010                 btst    0x10, %g2
F00232B0: 12800008                 bne     locret_F00232D0
F00232B4: 053c04d4                 sethi   %hi(_unp_defer), %g2
F00232B8: c600a2c0                 ld      [%g2+%lo(_unp_defer)], %g3
F00232BC: f0066008                 ld      [%i1+8], %i0
F00232C0: 8600e001                 inc     %g3
F00232C4: c620a2c0                 st      %g3, [%g2+%lo(_unp_defer)]
F00232C8: b0162030                 bset    0x30, %i0 ! '0'
F00232CC: f0266008                 st      %i0, [%i1+8]
F00232D0: 81c7e008                 ret
F00232D4: 81e80000                 restore
