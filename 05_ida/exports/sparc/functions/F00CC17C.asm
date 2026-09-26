F00CC17C: 9de3bf98                 save    %sp, -0x68, %sp
F00CC180: 113c04cc                 sethi   %hi(dword_F01330C8), %o0
F00CC184: d00220c8                 ld      [%o0+%lo(dword_F01330C8)], %o0
F00CC188: 80a22000                 cmp     %o0, 0
F00CC18C: 02800008                 be      locret_F00CC1AC
F00CC190: 94100018                 mov     %i0, %o2
F00CC194: 133c04cc                 sethi   %hi(dword_F01330D0), %o1
F00CC198: d80260d0                 ld      [%o1+%lo(dword_F01330D0)], %o4
F00CC19C: 173c0506                 sethi   %hi(paSendpacketLeng), %o3
F00CC1A0: d202e014                 ld      [%o3+%lo(paSendpacketLeng)], %o1
F00CC1A4: 9fc30000                 call    %o4
F00CC1A8: 96100019                 mov     %i1, %o3
F00CC1AC: 81c7e008                 ret
F00CC1B0: 81e80000                 restore
