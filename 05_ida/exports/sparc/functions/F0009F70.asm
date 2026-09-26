F0009F70: 9de3bf98                 save    %sp, -0x68, %sp
F0009F74: 86100019                 mov     %i1, %g3
F0009F78: 8088e040                 btst    0x40, %g3 ! '@'
F0009F7C: 1280000c                 bne     loc_F0009FAC
F0009F80: 053c04d0                 sethi   -0xFECC000, %g2
F0009F84: 053c04cf                 sethi   %hi(_active_u), %g2
F0009F88: c400a1d8                 ld      [%g2+%lo(_active_u)], %g2
F0009F8C: c4008000                 ld      [%g2], %g2
F0009F90: c448a015                 ldsb    [%g2+0x15], %g2
F0009F94: 80a0a000                 cmp     %g2, 0
F0009F98: 34800003                 bg,a    loc_F0009FA4
F0009F9C: b2102001                 mov     1, %i1
F0009FA0: b2102000                 mov     0, %i1
F0009FA4: 1080000b                 ba      loc_F0009FD0
F0009FA8: b6102000                 mov     0, %i3
F0009FAC: c400a260                 ld      [%g2+0x260], %g2
F0009FB0: c400a04c                 ld      [%g2+0x4C], %g2
F0009FB4: 8088a080                 btst    0x80, %g2
F0009FB8: 02800005                 be      loc_F0009FCC
F0009FBC: b2102002                 mov     2, %i1
F0009FC0: 8088ef00                 btst    0xF00, %g3
F0009FC4: 22800002                 be,a    loc_F0009FCC
F0009FC8: b2102003                 mov     3, %i1
F0009FCC: b6102000                 mov     0, %i3
F0009FD0: 053c04d0b410a380         set     _dk_time, %i2
F0009FD8: 313c04d0b0162040         set     _cp_time, %i0
F0009FE0: b32e6002                 sll     %i1, 2, %i1
F0009FE4: c4064018                 ld      [%i1+%i0], %g2
F0009FE8: 073c04d0                 sethi   %hi(_dk_busy), %g3
F0009FEC: c600e050                 ld      [%g3+%lo(_dk_busy)], %g3
F0009FF0: 8400a001                 inc     %g2
F0009FF4: c4264018                 st      %g2, [%i1+%i0]
F0009FF8: 8538c01b                 sra     %g3, %i3, %g2
F0009FFC: 8088a001                 btst    1, %g2
F000A000: 02800005                 be      loc_F000A014
F000A004: b606e001                 inc     %i3
F000A008: c4068000                 ld      [%i2], %g2
F000A00C: 8400a001                 inc     %g2
F000A010: c4268000                 st      %g2, [%i2]
F000A014: 80a6e003                 cmp     %i3, 3
F000A018: 04bffff8                 ble     loc_F0009FF8
F000A01C: b406a004                 inc     4, %i2
F000A020: 81c7e008                 ret
F000A024: 81e80000                 restore
