F0028818: 9de3bf90                 save    %sp, -0x70, %sp
F002881C: 90100018                 mov     %i0, %o0
F0028820: 4000007e                 call    _getvnodefp
F0028824: 9207bff4                 add     %fp, var_C, %o1
F0028828: 80a22000                 cmp     %o0, 0
F002882C: 32800010                 bne,a   locret_F002886C
F0028830: b0100008                 mov     %o0, %i0
F0028834: d407bff4                 ld      [%fp+var_C], %o2
F0028838: d202a018                 ld      [%o2+0x18], %o1
F002883C: d0026024                 ld      [%o1+0x24], %o0
F0028840: d002200c                 ld      [%o0+0xC], %o0
F0028844: 808a2001                 btst    1, %o0
F0028848: 12800009                 bne     locret_F002886C
F002884C: b010201e                 mov     0x1E, %i0
F0028850: d002601c                 ld      [%o1+0x1C], %o0
F0028854: d6022018                 ld      [%o0+0x18], %o3
F0028858: d402a020                 ld      [%o2+0x20], %o2
F002885C: 90100009                 mov     %o1, %o0
F0028860: 9fc2c000                 call    %o3
F0028864: 92100019                 mov     %i1, %o1
F0028868: b0100008                 mov     %o0, %i0
F002886C: 81c7e008                 ret
F0028870: 81e80000                 restore
