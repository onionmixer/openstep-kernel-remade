F00B7F88: 9de3bf98                 save    %sp, -0x68, %sp
F00B7F8C: b2100018                 mov     %i0, %i1
F00B7F90: 840e60ff                 and     %i1, 0xFF, %g2
F00B7F94: 80a0a000                 cmp     %g2, 0
F00B7F98: 12800005                 bne     loc_F00B7FAC
F00B7F9C: 808e20e0                 btst    0xE0, %i0
F00B7FA0: 313c047b                 sethi   %hi(aFree), %i0! "FREE"
F00B7FA4: 1080002c                 ba      locret_F00B8054
F00B7FA8: b01622a0                 bset    %lo(aFree), %i0! "FREE"
F00B7FAC: 02800018                 be      loc_F00B800C
F00B7FB0: 808e200f                 btst    0xF, %i0
F00B7FB4: 12800017                 bne     loc_F00B8010
F00B7FB8: 073c047b                 sethi   -0xFEE1400, %g3
F00B7FBC: 80a0a020                 cmp     %g2, 0x20 ! ' '
F00B7FC0: 12800005                 bne     loc_F00B7FD4
F00B7FC4: 80a0a040                 cmp     %g2, 0x40 ! '@'
F00B7FC8: 313c047b                 sethi   %hi(aSelect), %i0! "SELECT"
F00B7FCC: 10800022                 ba      locret_F00B8054
F00B7FD0: b01622a8                 bset    %lo(aSelect), %i0! "SELECT"
F00B7FD4: 12800005                 bne     loc_F00B7FE8
F00B7FD8: 80a0a060                 cmp     %g2, 0x60 ! '`'
F00B7FDC: 313c047b                 sethi   %hi(aSelStop), %i0! "SEL&STOP"
F00B7FE0: 1080001d                 ba      locret_F00B8054
F00B7FE4: b01622b0                 bset    %lo(aSelStop), %i0! "SEL&STOP"
F00B7FE8: 32800005                 bne,a   loc_F00B7FFC
F00B7FEC: 313c047b                 sethi   -0xFEE1400, %i0
F00B7FF0: 313c047b                 sethi   %hi(aSelectSndmsg), %i0! "SELECT_SNDMSG"
F00B7FF4: 10800018                 ba      locret_F00B8054
F00B7FF8: b01622c0                 bset    %lo(aSelectSndmsg), %i0! "SELECT_SNDMSG"
F00B7FFC: 10800016                 ba      locret_F00B8054
F00B8000: b01622d0                 bset    0x2D0, %i0
F00B8004: 10800014                 ba      locret_F00B8054
F00B8008: f006001a                 ld      [%i0+%i2], %i0
F00B800C: 073c047b                 sethi   -0xFEE1400, %g3
F00B8010: c400e2dc                 ld      [%g3+0x2DC], %g2
F00B8014: 80a0a000                 cmp     %g2, 0
F00B8018: 0280000d                 be      loc_F00B804C
F00B801C: b0102000                 mov     0, %i0
F00B8020: b20e60ff                 and     %i1, 0xFF, %i1
F00B8024: b410e2dc                 or      %g3, 0x2DC, %i2
F00B8028: 8610001a                 mov     %i2, %g3
F00B802C: c448e004                 ldsb    [%g3+4], %g2
F00B8030: 80a08019                 cmp     %g2, %i1
F00B8034: 02bffff4                 be      loc_F00B8004
F00B8038: 8600e008                 inc     8, %g3
F00B803C: c400c000                 ld      [%g3], %g2
F00B8040: 80a0a000                 cmp     %g2, 0
F00B8044: 12bffffa                 bne     loc_F00B802C
F00B8048: b0062008                 inc     8, %i0
F00B804C: 313c047cb0162148         set     aBad, %i0! "<BAD>"
F00B8054: 81c7e008                 ret
F00B8058: 81e80000                 restore
