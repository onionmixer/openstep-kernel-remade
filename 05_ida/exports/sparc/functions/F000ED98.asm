F000ED98: 9de3bf98                 save    %sp, -0x68, %sp
F000ED9C: 80a62000                 cmp     %i0, 0
F000EDA0: 32800003                 bne,a   locret_F000EDAC
F000EDA4: f0062084                 ld      [%i0+0x84], %i0
F000EDA8: b0102000                 mov     0, %i0
F000EDAC: 81c7e008                 ret
F000EDB0: 81e80000                 restore
