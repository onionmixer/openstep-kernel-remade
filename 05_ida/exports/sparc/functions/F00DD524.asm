F00DD524: 9de3bf90                 save    %sp, -0x70, %sp
F00DD528: f42e2094                 stb     %i2, [%i0+0x94]
F00DD52C: b52ea018                 sll     %i2, 24, %i2
F00DD530: 80a6a000                 cmp     %i2, 0
F00DD534: 02800012                 be      locret_F00DD57C
F00DD538: 01000000                 nop
F00DD53C: d006209c                 ld      [%i0+0x9C], %o0
F00DD540: 80a22000                 cmp     %o0, 0
F00DD544: 1280000e                 bne     locret_F00DD57C
F00DD548: 01000000                 nop
F00DD54C: 7fffa279                 call    _IOMalloc
F00DD550: 90102040                 mov     0x40, %o0 ! '@'
F00DD554: d026209c                 st      %o0, [%i0+0x9C]
F00DD558: 7fffa276                 call    _IOMalloc
F00DD55C: 90102040                 mov     0x40, %o0 ! '@'
F00DD560: d02620a0                 st      %o0, [%i0+0xA0]
F00DD564: d006209c                 ld      [%i0+0x9C], %o0
F00DD568: 40001437                 call    _audio_clear_peaks
F00DD56C: 92102010                 mov     0x10, %o1
F00DD570: d00620a0                 ld      [%i0+0xA0], %o0
F00DD574: 40001434                 call    _audio_clear_peaks
F00DD578: 92102010                 mov     0x10, %o1
F00DD57C: 81c7e008                 ret
F00DD580: 81e80000                 restore
