F00EC204: 9de3bf98                 save    %sp, -0x68, %sp
F00EC208: a0960000                 orcc    %i0, %g0, %l0
F00EC20C: 0280000f                 be      loc_F00EC248
F00EC210: 9410001a                 mov     %i2, %o2
F00EC214: 113c04bc                 sethi   %hi(__zoneAlloc), %o0
F00EC218: d6022104                 ld      [%o0+%lo(__zoneAlloc)], %o3
F00EC21C: d0040000                 ld      [%l0], %o0
F00EC220: 9fc2c000                 call    %o3
F00EC224: 92100019                 mov     %i1, %o1
F00EC228: b0100008                 mov     %o0, %i0
F00EC22C: d0040000                 ld      [%l0], %o0
F00EC230: d4022014                 ld      [%o0+0x14], %o2! __len
F00EC234: 90100018                 mov     %i0, %o0! __dst
F00EC238: 92100010                 mov     %l0, %o1! __src
F00EC23C: 7ffc6f65                 call    _memmove
F00EC240: 9406400a                 add     %i1, %o2, %o2
F00EC244: 30800002                 ba,a    locret_F00EC24C
F00EC248: b0102000                 mov     0, %i0
F00EC24C: 81c7e008                 ret
F00EC250: 81e80000                 restore
