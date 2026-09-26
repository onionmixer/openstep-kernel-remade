F00AEBC0: 9de3bf98                 save    %sp, -0x68, %sp
F00AEBC4: b8102000                 mov     0, %i4
F00AEBC8: 80a7001a                 cmp     %i4, %i2
F00AEBCC: 36800012                 bge,a   locret_F00AEC14
F00AEBD0: b0102000                 mov     0, %i0
F00AEBD4: 86102000                 mov     0, %g3
F00AEBD8: f600c018                 ld      [%g3+%i0], %i3
F00AEBDC: c400c019                 ld      [%g3+%i1], %g2
F00AEBE0: 80a6c002                 cmp     %i3, %g2
F00AEBE4: 08800004                 bleu    loc_F00AEBF4
F00AEBE8: 01000000                 nop
F00AEBEC: 1080000a                 ba      locret_F00AEC14
F00AEBF0: b0102001                 mov     1, %i0
F00AEBF4: 1a800004                 bcc     loc_F00AEC04
F00AEBF8: b8072001                 inc     %i4
F00AEBFC: 10800006                 ba      locret_F00AEC14
F00AEC00: b0103fff                 mov     -1, %i0
F00AEC04: 80a7001a                 cmp     %i4, %i2
F00AEC08: 06bffff4                 bl      loc_F00AEBD8
F00AEC0C: 8600e004                 inc     4, %g3
F00AEC10: b0102000                 mov     0, %i0
F00AEC14: 81c7e008                 ret
F00AEC18: 81e80000                 restore
