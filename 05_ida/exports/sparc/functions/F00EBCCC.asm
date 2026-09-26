F00EBCCC: 9de3bf90                 save    %sp, -0x70, %sp
F00EBCD0: d0060000                 ld      [%i0], %o0! m
F00EBCD4: 40000d77                 call    _class_getInstanceMethod
F00EBCD8: 9210001a                 mov     %i2, %o1
F00EBCDC: 80a22000                 cmp     %o0, 0
F00EBCE0: 02800005                 be      locret_F00EBCF4
F00EBCE4: b0102000                 mov     0, %i0
F00EBCE8: 40001270                 call    _method_getSizeOfArguments
F00EBCEC: 01000000                 nop
F00EBCF0: b0100008                 mov     %o0, %i0
F00EBCF4: 81c7e008                 ret
F00EBCF8: 81e80000                 restore
