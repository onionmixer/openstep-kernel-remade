F00EF238: 9de3bf98                 save    %sp, -0x68, %sp
F00EF23C: 113c04bc                 sethi   %hi(__zoneAlloc), %o0
F00EF240: d6022104                 ld      [%o0+%lo(__zoneAlloc)], %o3
F00EF244: 90100018                 mov     %i0, %o0
F00EF248: 92100019                 mov     %i1, %o1
F00EF24C: 9fc2c000                 call    %o3
F00EF250: 9410001a                 mov     %i2, %o2
F00EF254: 81c7e008                 ret
F00EF258: 91e80008                 restore %g0, %o0, %o0
