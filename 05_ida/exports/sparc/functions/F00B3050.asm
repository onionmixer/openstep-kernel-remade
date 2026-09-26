F00B3050: 9de3bf98                 save    %sp, -0x68, %sp
F00B3054: 10800007                 ba      loc_F00B3070
F00B3058: c40e0000                 ldub    [%i0], %g2
F00B305C: 8538a018                 sra     %g2, 24, %g2
F00B3060: 80a0a03a                 cmp     %g2, 0x3A ! ':'
F00B3064: 02800008                 be      locret_F00B3084
F00B3068: 01000000                 nop
F00B306C: c40e0000                 ldub    [%i0], %g2
F00B3070: 8528a018                 sll     %g2, 24, %g2
F00B3074: 80a0a000                 cmp     %g2, 0
F00B3078: 12bffff9                 bne     loc_F00B305C
F00B307C: b0062001                 inc     %i0
F00B3080: b0102000                 mov     0, %i0
F00B3084: 81c7e008                 ret
F00B3088: 81e80000                 restore
