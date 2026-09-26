F00EF01C: 80a26000                 cmp     %o1, 0
F00EF020: 0280001d                 be      locret_F00EF094
F00EF024: 90102000                 mov     0, %o0
F00EF028: c40a4000                 ldub    [%o1], %g2
F00EF02C: 80a0a000                 cmp     %g2, 0
F00EF030: 02800019                 be      locret_F00EF094
F00EF034: 86100002                 mov     %g2, %g3
F00EF038: 92026001                 inc     %o1
F00EF03C: c40a4000                 ldub    [%o1], %g2
F00EF040: 80a0a000                 cmp     %g2, 0
F00EF044: 02800014                 be      locret_F00EF094
F00EF048: 9018c008                 btog    %g3, %o0
F00EF04C: 8528a008                 sll     %g2, 8, %g2
F00EF050: 901a0002                 btog    %g2, %o0
F00EF054: 92026001                 inc     %o1
F00EF058: c40a4000                 ldub    [%o1], %g2
F00EF05C: 80a0a000                 cmp     %g2, 0
F00EF060: 0280000d                 be      locret_F00EF094
F00EF064: 8528a010                 sll     %g2, 16, %g2
F00EF068: 901a0002                 btog    %g2, %o0
F00EF06C: 92026001                 inc     %o1
F00EF070: c40a4000                 ldub    [%o1], %g2
F00EF074: 80a0a000                 cmp     %g2, 0
F00EF078: 02800007                 be      locret_F00EF094
F00EF07C: 8528a018                 sll     %g2, 24, %g2
F00EF080: 92026001                 inc     %o1
F00EF084: c60a4000                 ldub    [%o1], %g3
F00EF088: 80a0e000                 cmp     %g3, 0
F00EF08C: 12bfffeb                 bne     loc_F00EF038
F00EF090: 901a0002                 btog    %g2, %o0
F00EF094: 81c3e008                 retl
F00EF098: 01000000                 nop
