F00506A0: 9de3bf98                 save    %sp, -0x68, %sp
F00506A4: 84100018                 mov     %i0, %g2
F00506A8: b0068019                 add     %i2, %i1, %i0
F00506AC: 80a68018                 cmp     %i2, %i0
F00506B0: 3a80000c                 bcc,a   locret_F00506E0
F00506B4: b026001a                 sub     %i0, %i2, %i0
F00506B8: 8608a0ff                 and     %g2, 0xFF, %g3
F00506BC: c40e8000                 ldub    [%i2], %g2
F00506C0: 80a08003                 cmp     %g2, %g3
F00506C4: 22800007                 be,a    locret_F00506E0
F00506C8: b026001a                 sub     %i0, %i2, %i0
F00506CC: b406a001                 inc     %i2
F00506D0: 80a68018                 cmp     %i2, %i0
F00506D4: 2abffffb                 bcs,a   loc_F00506C0
F00506D8: c40e8000                 ldub    [%i2], %g2
F00506DC: b026001a                 sub     %i0, %i2, %i0
F00506E0: 81c7e008                 ret
F00506E4: 81e80000                 restore
