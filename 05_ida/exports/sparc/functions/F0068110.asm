F0068110: 9de3bf98                 save    %sp, -0x68, %sp
F0068114: 92102000                 mov     0, %o1
F0068118: 113c04f0                 sethi   %hi(_k_zone_maxsize), %o0
F006811C: d00220b0                 ld      [%o0+%lo(_k_zone_maxsize)], %o0
F0068120: 94100018                 mov     %i0, %o2
F0068124: 80a28008                 cmp     %o2, %o0
F0068128: 1880000e                 bgu     loc_F0068160
F006812C: a0102000                 mov     0, %l0
F0068130: 113c043e                 sethi   %hi(_k_zone_elemsize), %o0
F0068134: d40222a8                 ld      [%o0+%lo(_k_zone_elemsize)], %o2
F0068138: 80a28018                 cmp     %o2, %i0
F006813C: 1a800009                 bcc     loc_F0068160
F0068140: 92100010                 mov     %l0, %o1
F0068144: 961222a8                 or      %o0, %lo(_k_zone_elemsize), %o3
F0068148: 90102000                 mov     0, %o0
F006814C: 90022004                 inc     4, %o0
F0068150: d402000b                 ld      [%o0+%o3], %o2
F0068154: 80a28018                 cmp     %o2, %i0
F0068158: 0abffffd                 bcs     loc_F006814C
F006815C: 92026001                 inc     %o1
F0068160: 113c04f0                 sethi   %hi(_k_zone_maxsize), %o0
F0068164: d00220b0                 ld      [%o0+%lo(_k_zone_maxsize)], %o0
F0068168: 80a28008                 cmp     %o2, %o0
F006816C: 18800008                 bgu     loc_F006818C
F0068170: 932a6002                 sll     %o1, 2, %o1
F0068174: 113c04f090122070         set     _k_zone, %o0
F006817C: 400043e0                 call    _zget
F0068180: d0024008                 ld      [%o1+%o0], %o0
F0068184: 10800005                 ba      locret_F0068198
F0068188: a0100008                 mov     %o0, %l0
F006818C: 113c043e                 sethi   %hi(aKget), %o0! "kget"
F0068190: 7ffeb3f8                 call    _panic
F0068194: 901222f8                 bset    %lo(aKget), %o0! "kget"
F0068198: 81c7e008                 ret
F006819C: 91e80010                 restore %g0, %l0, %o0
