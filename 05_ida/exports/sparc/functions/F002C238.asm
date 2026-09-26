F002C238: 9de3bf98                 save    %sp, -0x68, %sp
F002C23C: 80a62000                 cmp     %i0, 0
F002C240: 0280001f                 be      loc_F002C2BC
F002C244: a2102000                 mov     0, %l1
F002C248: 80a4401a                 cmp     %l1, %i2
F002C24C: 38800018                 bgu,a   loc_F002C2AC
F002C250: d0562008                 ldsh    [%i0+8], %o0
F002C254: d4562008                 ldsh    [%i0+8], %o2! size_t
F002C258: 9004400a                 add     %l1, %o2, %o0
F002C25C: 80a68008                 cmp     %i2, %o0
F002C260: 1a800012                 bcc     loc_F002C2A8
F002C264: 92268011                 sub     %i2, %l1, %o1
F002C268: a0228009                 sub     %o2, %o1, %l0
F002C26C: d0062004                 ld      [%i0+4], %o0
F002C270: 80a4001b                 cmp     %l0, %i3
F002C274: 08800003                 bleu    loc_F002C280
F002C278: 90060008                 add     %i0, %o0, %o0
F002C27C: a010001b                 mov     %i3, %l0
F002C280: 90020009                 add     %o0, %o1, %o0! void *
F002C284: 92100019                 mov     %i1, %o1! void *
F002C288: 4001a222                 call    _bcopy
F002C28C: 94100010                 mov     %l0, %o2
F002C290: b2064010                 add     %i1, %l0, %i1
F002C294: b6a6c010                 subcc   %i3, %l0, %i3
F002C298: 12800004                 bne     loc_F002C2A8
F002C29C: b4068010                 add     %i2, %l0, %i2
F002C2A0: 10800008                 ba      locret_F002C2C0
F002C2A4: b0102000                 mov     0, %i0
F002C2A8: d0562008                 ldsh    [%i0+8], %o0
F002C2AC: f0060000                 ld      [%i0], %i0
F002C2B0: 80a62000                 cmp     %i0, 0
F002C2B4: 12bfffe5                 bne     loc_F002C248
F002C2B8: a2044008                 add     %l1, %o0, %l1
F002C2BC: b0103fff                 mov     -1, %i0
F002C2C0: 81c7e008                 ret
F002C2C4: 81e80000                 restore
