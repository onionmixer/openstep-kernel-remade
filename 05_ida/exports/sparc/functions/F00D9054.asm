F00D9054: 9de3bf90                 save    %sp, -0x70, %sp
F00D9058: a4100018                 mov     %i0, %l2
F00D905C: a2102000                 mov     0, %l1
F00D9060: 80a4401c                 cmp     %l1, %i4
F00D9064: 1a800012                 bcc     locret_F00D90AC
F00D9068: b0102001                 mov     1, %i0
F00D906C: 273c0505                 sethi   -0xFEBEC00, %l3
F00D9070: a0102000                 mov     0, %l0
F00D9074: d204e0fc                 ld      [%l3+0xFC], %o1! SEL
F00D9078: d404001a                 ld      [%l0+%i2], %o2
F00D907C: 90100012                 mov     %l2, %o0! id
F00D9080: d604001b                 ld      [%l0+%i3], %o3
F00D9084: 400061fb                 call    _objc_msgSend
F00D9088: 9810001d                 mov     %i5, %o4
F00D908C: 912a2018                 sll     %o0, 24, %o0
F00D9090: 80a22000                 cmp     %o0, 0
F00D9094: 22800002                 be,a    loc_F00D909C
F00D9098: b0102000                 mov     0, %i0
F00D909C: a2046001                 inc     %l1
F00D90A0: 80a4401c                 cmp     %l1, %i4
F00D90A4: 0abffff4                 bcs     loc_F00D9074
F00D90A8: a0042004                 inc     4, %l0
F00D90AC: 81c7e008                 ret
F00D90B0: 81e80000                 restore
