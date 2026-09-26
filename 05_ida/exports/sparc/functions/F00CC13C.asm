F00CC13C: 9de3bf98                 save    %sp, -0x68, %sp
F00CC140: 96100019                 mov     %i1, %o3
F00CC144: c022c000                 clr     [%o3]
F00CC148: 113c04cc                 sethi   %hi(dword_F01330C8), %o0
F00CC14C: d00220c8                 ld      [%o0+%lo(dword_F01330C8)], %o0
F00CC150: 80a22000                 cmp     %o0, 0
F00CC154: 02800008                 be      locret_F00CC174
F00CC158: 94100018                 mov     %i0, %o2
F00CC15C: 133c04cc                 sethi   %hi(dword_F01330CC), %o1
F00CC160: da0260cc                 ld      [%o1+%lo(dword_F01330CC)], %o5
F00CC164: 193c0506                 sethi   %hi(paReceivepacketL), %o4
F00CC168: d2032018                 ld      [%o4+%lo(paReceivepacketL)], %o1
F00CC16C: 9fc34000                 call    %o5
F00CC170: 9810001a                 mov     %i2, %o4
F00CC174: 81c7e008                 ret
F00CC178: 81e80000                 restore
