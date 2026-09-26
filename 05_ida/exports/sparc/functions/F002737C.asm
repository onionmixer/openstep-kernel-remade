F002737C: 9de3bf98                 save    %sp, -0x68, %sp
F0027380: a0100018                 mov     %i0, %l0
F0027384: d4042008                 ld      [%l0+8], %o2! size_t
F0027388: d6066008                 ld      [%i1+8], %o3
F002738C: 9002800b                 add     %o2, %o3, %o0
F0027390: 80a223ff                 cmp     %o0, 0x3FF
F0027394: 18800011                 bgu     locret_F00273D8
F0027398: b010203f                 mov     0x3F, %i0 ! '?'
F002739C: d2040000                 ld      [%l0], %o1
F00273A0: d0042004                 ld      [%l0+4], %o0
F00273A4: 4001b693                 call    _ovbcopy
F00273A8: 9202400b                 add     %o1, %o3, %o1
F00273AC: d0066004                 ld      [%i1+4], %o0! void *
F00273B0: d2040000                 ld      [%l0], %o1! void *
F00273B4: 4001b5d7                 call    _bcopy
F00273B8: d4066008                 ld      [%i1+8], %o2
F00273BC: d0042008                 ld      [%l0+8], %o0
F00273C0: d2066008                 ld      [%i1+8], %o1
F00273C4: b0102000                 mov     0, %i0
F00273C8: 90020009                 add     %o0, %o1, %o0
F00273CC: d2040000                 ld      [%l0], %o1
F00273D0: d0242008                 st      %o0, [%l0+8]
F00273D4: d2242004                 st      %o1, [%l0+4]
F00273D8: 81c7e008                 ret
F00273DC: 81e80000                 restore
