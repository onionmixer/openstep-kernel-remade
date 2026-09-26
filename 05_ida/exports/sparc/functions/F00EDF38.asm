F00EDF38: 9de3bf98                 save    %sp, -0x68, %sp
F00EDF3C: 80a6401a                 cmp     %i1, %i2
F00EDF40: 12800004                 bne     loc_F00EDF50
F00EDF44: 80a66000                 cmp     %i1, 0
F00EDF48: 10800017                 ba      locret_F00EDFA4
F00EDF4C: b0102001                 mov     1, %i0
F00EDF50: 12800004                 bne     loc_F00EDF60
F00EDF54: 80a6a000                 cmp     %i2, 0
F00EDF58: 10800005                 ba      loc_F00EDF6C
F00EDF5C: 9010001a                 mov     %i2, %o0
F00EDF60: 32800008                 bne,a   loc_F00EDF80
F00EDF64: d24e4000                 ldsb    [%i1], %o1! __s2
F00EDF68: 90100019                 mov     %i1, %o0! __s
F00EDF6C: 7ffc6533                 call    _strlen
F00EDF70: 01000000                 nop
F00EDF74: 80a00008                 cmp     %g0, %o0
F00EDF78: 1080000b                 ba      locret_F00EDFA4
F00EDF7C: b0603fff                 subc    %g0, -1, %i0
F00EDF80: d04e8000                 ldsb    [%i2], %o0
F00EDF84: 80a24008                 cmp     %o1, %o0
F00EDF88: 12800007                 bne     locret_F00EDFA4
F00EDF8C: b0102000                 mov     0, %i0
F00EDF90: 90100019                 mov     %i1, %o0! __s1
F00EDF94: 7ffc6886                 call    _strcmp
F00EDF98: 9210001a                 mov     %i2, %o1
F00EDF9C: 80a00008                 cmp     %g0, %o0
F00EDFA0: b0603fff                 subc    %g0, -1, %i0
F00EDFA4: 81c7e008                 ret
F00EDFA8: 81e80000                 restore
