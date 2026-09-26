F001503C: 9de3bf98                 save    %sp, -0x68, %sp
F0015040: 10800007                 ba      loc_F001505C
F0015044: d00e0000                 ldub    [%i0], %o0
F0015048: 913a2018                 sra     %o0, 24, %o0
F001504C: 92100019                 mov     %i1, %o1
F0015050: 400000a8                 call    sub_F00152F0
F0015054: 9410001a                 mov     %i2, %o2
F0015058: d00e0000                 ldub    [%i0], %o0
F001505C: 912a2018                 sll     %o0, 24, %o0
F0015060: 80a22000                 cmp     %o0, 0
F0015064: 12bffff9                 bne     loc_F0015048
F0015068: b0062001                 inc     %i0
F001506C: 81c7e008                 ret
F0015070: 81e80000                 restore
