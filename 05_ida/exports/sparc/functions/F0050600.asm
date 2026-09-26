F0050600: 9de3bf98                 save    %sp, -0x68, %sp
F0050604: b0064018                 add     %i1, %i0, %i0
F0050608: 80a64018                 cmp     %i1, %i0
F005060C: 1a800010                 bcc     loc_F005064C
F0050610: 8610001b                 mov     %i3, %g3
F0050614: c40e4000                 ldub    [%i1], %g2
F0050618: c40e8002                 ldub    [%i2+%g2], %g2
F005061C: 8088801b                 btst    %i3, %g2
F0050620: 3280000c                 bne,a   locret_F0050650
F0050624: b0260019                 sub     %i0, %i1, %i0
F0050628: b2066001                 inc     %i1
F005062C: 80a64018                 cmp     %i1, %i0
F0050630: 3a800008                 bcc,a   locret_F0050650
F0050634: b0260019                 sub     %i0, %i1, %i0
F0050638: c40e4000                 ldub    [%i1], %g2
F005063C: c40e8002                 ldub    [%i2+%g2], %g2
F0050640: 80888003                 btst    %g3, %g2
F0050644: 22bffffa                 be,a    loc_F005062C
F0050648: b2066001                 inc     %i1
F005064C: b0260019                 sub     %i0, %i1, %i0
F0050650: 81c7e008                 ret
F0050654: 81e80000                 restore
