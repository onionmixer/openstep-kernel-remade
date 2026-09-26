F008F118: 9de3bf90                 save    %sp, -0x70, %sp
F008F11C: c4062008                 ld      [%i0+8], %g2
F008F120: 80a0a000                 cmp     %g2, 0
F008F124: 02800004                 be      loc_F008F134
F008F128: 80a6a000                 cmp     %i2, 0
F008F12C: 12800005                 bne     loc_F008F140
F008F130: 8418801a                 btog    %i2, %g2
F008F134: f4262008                 st      %i2, [%i0+8]
F008F138: c4062008                 ld      [%i0+8], %g2
F008F13C: 8418801a                 btog    %i2, %g2
F008F140: 80a00002                 cmp     %g0, %g2
F008F144: b0403fff                 addc    %g0, -1, %i0
F008F148: b00e8018                 and     %i2, %i0, %i0
F008F14C: 81c7e008                 ret
F008F150: 81e80000                 restore
