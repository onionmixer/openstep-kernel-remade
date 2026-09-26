F00CA584: 9de3bf90                 save    %sp, -0x70, %sp
F00CA588: 9010001b                 mov     %i3, %o0! __dst
F00CA58C: 932ea001                 sll     %i2, 1, %o1
F00CA590: 9202401a                 add     %o1, %i2, %o1
F00CA594: 932a6003                 sll     %o1, 3, %o1
F00CA598: 9222401a                 sub     %o1, %i2, %o1
F00CA59C: 932a6002                 sll     %o1, 2, %o1
F00CA5A0: 92024018                 add     %o1, %i0, %o1
F00CA5A4: 92026130                 inc     0x130, %o1! __src
F00CA5A8: 7ffcf4dd                 call    _strncpy
F00CA5AC: 94102004                 mov     4, %o2
F00CA5B0: 81c7e008                 ret
F00CA5B4: 91e82000                 restore %g0, 0, %o0
