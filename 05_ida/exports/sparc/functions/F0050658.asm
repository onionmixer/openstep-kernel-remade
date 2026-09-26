F0050658: 9de3bf98                 save    %sp, -0x68, %sp
F005065C: 84100018                 mov     %i0, %g2
F0050660: b0068019                 add     %i2, %i1, %i0
F0050664: 80a68018                 cmp     %i2, %i0
F0050668: 3a80000c                 bcc,a   locret_F0050698
F005066C: b026001a                 sub     %i0, %i2, %i0
F0050670: 8608a0ff                 and     %g2, 0xFF, %g3
F0050674: c40e8000                 ldub    [%i2], %g2
F0050678: 80a08003                 cmp     %g2, %g3
F005067C: 32800007                 bne,a   locret_F0050698
F0050680: b026001a                 sub     %i0, %i2, %i0
F0050684: b406a001                 inc     %i2
F0050688: 80a68018                 cmp     %i2, %i0
F005068C: 2abffffb                 bcs,a   loc_F0050678
F0050690: c40e8000                 ldub    [%i2], %g2
F0050694: b026001a                 sub     %i0, %i2, %i0
F0050698: 81c7e008                 ret
F005069C: 81e80000                 restore
