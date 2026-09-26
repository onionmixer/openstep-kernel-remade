F0064EA0: 9de3bf98                 save    %sp, -0x68, %sp
F0064EA4: 80a62000                 cmp     %i0, 0
F0064EA8: 02800008                 be      loc_F0064EC8
F0064EAC: 90100019                 mov     %i1, %o0! __dst
F0064EB0: 133c04bc92126190         set     _version, %o1! "NeXT Mach 4.2: Sun Apr 27 14:33:09 PDT "...
F0064EB8: 7ffe8a99                 call    _strncpy
F0064EBC: 94102200                 mov     0x200, %o2
F0064EC0: 10800003                 ba      locret_F0064ECC
F0064EC4: b0102000                 mov     0, %i0
F0064EC8: b0102004                 mov     4, %i0
F0064ECC: 81c7e008                 ret
F0064ED0: 81e80000                 restore
