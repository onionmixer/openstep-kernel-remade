F00F09A0: 9de3bf98                 save    %sp, -0x68, %sp
F00F09A4: 7ffff9f9                 call    _object_getClassName
F00F09A8: 90100018                 mov     %i0, %o0
F00F09AC: 94100008                 mov     %o0, %o2
F00F09B0: 90102003                 mov     3, %o0! __x
F00F09B4: 133c03f4                 sethi   %hi(aObjcErrorS), %o1! "objc error: %s "
F00F09B8: 7ffc8f7f                 call    _log
F00F09BC: 92126178                 bset    %lo(aObjcErrorS), %o1! "objc error: %s "
F00F09C0: 90102003                 mov     3, %o0! __s
F00F09C4: 92100019                 mov     %i1, %o1
F00F09C8: 7ffc8f9b                 call    _vlog
F00F09CC: 9410001a                 mov     %i2, %o2
F00F09D0: 7ffc5a9a                 call    _strlen
F00F09D4: 90100019                 mov     %i1, %o0
F00F09D8: 90020019                 add     %o0, %i1, %o0
F00F09DC: d04a3fff                 ldsb    [%o0-1], %o0
F00F09E0: 80a2200a                 cmp     %o0, 0xA
F00F09E4: 02800005                 be      loc_F00F09F8
F00F09E8: 90102003                 mov     3, %o0! __x
F00F09EC: 133c03eb                 sethi   %hi(asc_F00FAC48), %o1! "\n"
F00F09F0: 7ffc8f71                 call    _log
F00F09F4: 92126048                 bset    %lo(asc_F00FAC48), %o1! "\n"
F00F09F8: 7ffe6e5e                 call    _abort
