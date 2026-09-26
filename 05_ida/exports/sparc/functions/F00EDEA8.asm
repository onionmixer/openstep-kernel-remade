F00EDEA8: 80a26000                 cmp     %o1, 0
F00EDEAC: 0280001d                 be      locret_F00EDF20
F00EDEB0: 90102000                 mov     0, %o0
F00EDEB4: c40a4000                 ldub    [%o1], %g2
F00EDEB8: 80a0a000                 cmp     %g2, 0
F00EDEBC: 02800019                 be      locret_F00EDF20
F00EDEC0: 86100002                 mov     %g2, %g3
F00EDEC4: 92026001                 inc     %o1
F00EDEC8: c40a4000                 ldub    [%o1], %g2
F00EDECC: 80a0a000                 cmp     %g2, 0
F00EDED0: 02800014                 be      locret_F00EDF20
F00EDED4: 9018c008                 btog    %g3, %o0
F00EDED8: 8528a008                 sll     %g2, 8, %g2
F00EDEDC: 901a0002                 btog    %g2, %o0
F00EDEE0: 92026001                 inc     %o1
F00EDEE4: c40a4000                 ldub    [%o1], %g2
F00EDEE8: 80a0a000                 cmp     %g2, 0
F00EDEEC: 0280000d                 be      locret_F00EDF20
F00EDEF0: 8528a010                 sll     %g2, 16, %g2
F00EDEF4: 901a0002                 btog    %g2, %o0
F00EDEF8: 92026001                 inc     %o1
F00EDEFC: c40a4000                 ldub    [%o1], %g2
F00EDF00: 80a0a000                 cmp     %g2, 0
F00EDF04: 02800007                 be      locret_F00EDF20
F00EDF08: 8528a018                 sll     %g2, 24, %g2
F00EDF0C: 92026001                 inc     %o1
F00EDF10: c60a4000                 ldub    [%o1], %g3
F00EDF14: 80a0e000                 cmp     %g3, 0
F00EDF18: 12bfffeb                 bne     loc_F00EDEC4
F00EDF1C: 901a0002                 btog    %g2, %o0
F00EDF20: 81c3e008                 retl
F00EDF24: 01000000                 nop
