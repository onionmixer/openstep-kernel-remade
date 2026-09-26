F00BB638: 9de3bf98                 save    %sp, -0x68, %sp
F00BB63C: 90100018                 mov     %i0, %o0! __s1
F00BB640: 133c047f                 sethi   %hi(aSunwSx), %o1! "SUNW,sx"
F00BB644: 7ffd32da                 call    _strcmp
F00BB648: 92126100                 bset    %lo(aSunwSx), %o1! "SUNW,sx"
F00BB64C: 80a22000                 cmp     %o0, 0
F00BB650: 02800008                 be      loc_F00BB670
F00BB654: 90100018                 mov     %i0, %o0! __s1
F00BB658: 133c047f                 sethi   %hi(aSx), %o1! "sx"
F00BB65C: 7ffd32d4                 call    _strcmp
F00BB660: 92126108                 bset    %lo(aSx), %o1! "sx"
F00BB664: 80a22000                 cmp     %o0, 0
F00BB668: 12800003                 bne     locret_F00BB674
F00BB66C: b0102000                 mov     0, %i0
F00BB670: b0102001                 mov     1, %i0
F00BB674: 81c7e008                 ret
F00BB678: 81e80000                 restore
