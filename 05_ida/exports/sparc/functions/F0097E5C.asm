F0097E5C: 9de3bf98                 save    %sp, -0x68, %sp
F0097E60: 113bffff901223ff         set     -0x10000001, %o0
F0097E68: 80a64008                 cmp     %i1, %o0
F0097E6C: 08800010                 bleu    loc_F0097EAC
F0097E70: 113c04f6                 sethi   %hi(_etext), %o0
F0097E74: d00221e0                 ld      [%o0+%lo(_etext)], %o0
F0097E78: 80a64008                 cmp     %i1, %o0
F0097E7C: 1880000c                 bgu     loc_F0097EAC
F0097E80: 90100019                 mov     %i1, %o0
F0097E84: 400011d0                 call    _pmap_change_prot
F0097E88: 92102007                 mov     7, %o1
F0097E8C: 90100018                 mov     %i0, %o0! void *
F0097E90: 92100019                 mov     %i1, %o1! void *
F0097E94: 7ffff31f                 call    _bcopy
F0097E98: 9410001a                 mov     %i2, %o2! size_t
F0097E9C: 90100019                 mov     %i1, %o0
F0097EA0: 400011c9                 call    _pmap_change_prot
F0097EA4: 92102001                 mov     1, %o1
F0097EA8: 30800005                 ba,a    locret_F0097EBC
F0097EAC: 90100018                 mov     %i0, %o0! void *
F0097EB0: 92100019                 mov     %i1, %o1! void *
F0097EB4: 7ffff317                 call    _bcopy
F0097EB8: 9410001a                 mov     %i2, %o2
F0097EBC: 81c7e008                 ret
F0097EC0: 91e82000                 restore %g0, 0, %o0
