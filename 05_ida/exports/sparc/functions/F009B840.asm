F009B840: 9de3bf98                 save    %sp, -0x68, %sp
F009B844: 92100019                 mov     %i1, %o1
F009B848: f2024000                 ld      [%o1], %i1
F009B84C: 80a64018                 cmp     %i1, %i0
F009B850: 02800017                 be      locret_F009B8AC
F009B854: 01000000                 nop
F009B858: 7fffed87                 call    _swapl
F009B85C: 90100018                 mov     %i0, %o0
F009B860: 808e6003                 btst    3, %i1
F009B864: 02800012                 be      locret_F009B8AC
F009B868: 80a73fff                 cmp     %i4, -1
F009B86C: 02800010                 be      locret_F009B8AC
F009B870: 9010001b                 mov     %i3, %o0
F009B874: 9210001a                 mov     %i2, %o1
F009B878: 40002487                 call    _srmmu_tlbflush
F009B87C: 9410001c                 mov     %i4, %o2
F009B880: 920e7f00                 and     %i1, -0x100, %o1
F009B884: 900e3f00                 and     %i0, -0x100, %o0
F009B888: 80a24008                 cmp     %o1, %o0
F009B88C: 12800008                 bne     locret_F009B8AC
F009B890: 808e6080                 btst    0x80, %i1
F009B894: 02800006                 be      locret_F009B8AC
F009B898: 808e2080                 btst    0x80, %i0
F009B89C: 12800004                 bne     locret_F009B8AC
F009B8A0: 01000000                 nop
F009B8A4: 7fffe85c                 call    _pac_pageflush
F009B8A8: 91326008                 srl     %o1, 8, %o0
F009B8AC: 81c7e008                 ret
F009B8B0: 81e80000                 restore
