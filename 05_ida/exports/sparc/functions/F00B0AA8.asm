F00B0AA8: 9de3bf98                 save    %sp, -0x68, %sp
F00B0AAC: 86100018                 mov     %i0, %g3
F00B0AB0: c400e008                 ld      [%g3+8], %g2
F00B0AB4: 80a08019                 cmp     %g2, %i1
F00B0AB8: 3280000d                 bne,a   loc_F00B0AEC
F00B0ABC: 86100002                 mov     %g2, %g3
F00B0AC0: c4066004                 ld      [%i1+4], %g2
F00B0AC4: b0102000                 mov     0, %i0
F00B0AC8: 1080000d                 ba      locret_F00B0AFC
F00B0ACC: c420e008                 st      %g2, [%g3+8]
F00B0AD0: b0102000                 mov     0, %i0
F00B0AD4: 1080000a                 ba      locret_F00B0AFC
F00B0AD8: c420e004                 st      %g2, [%g3+4]
F00B0ADC: 80a08019                 cmp     %g2, %i1
F00B0AE0: 22bffffc                 be,a    loc_F00B0AD0
F00B0AE4: c400a004                 ld      [%g2+4], %g2
F00B0AE8: 86100002                 mov     %g2, %g3
F00B0AEC: 80a0e000                 cmp     %g3, 0
F00B0AF0: 32bffffb                 bne,a   loc_F00B0ADC
F00B0AF4: c400e004                 ld      [%g3+4], %g2
F00B0AF8: b0103fff                 mov     -1, %i0
F00B0AFC: 81c7e008                 ret
F00B0B00: 81e80000                 restore
