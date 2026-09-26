F00DAD38: 9de3bf90                 save    %sp, -0x70, %sp
F00DAD3C: b52ea018                 sll     %i2, 24, %i2
F00DAD40: b53ea018                 sra     %i2, 24, %i2
F00DAD44: 80a6a000                 cmp     %i2, 0
F00DAD48: 02800012                 be      locret_F00DAD90
F00DAD4C: f4262050                 st      %i2, [%i0+0x50]
F00DAD50: d0062058                 ld      [%i0+0x58], %o0
F00DAD54: 80a22000                 cmp     %o0, 0
F00DAD58: 1280000e                 bne     locret_F00DAD90
F00DAD5C: 01000000                 nop
F00DAD60: 7fffac74                 call    _IOMalloc
F00DAD64: 90102040                 mov     0x40, %o0 ! '@'
F00DAD68: d0262058                 st      %o0, [%i0+0x58]
F00DAD6C: 7fffac71                 call    _IOMalloc
F00DAD70: 90102040                 mov     0x40, %o0 ! '@'
F00DAD74: d026205c                 st      %o0, [%i0+0x5C]
F00DAD78: d0062058                 ld      [%i0+0x58], %o0
F00DAD7C: 40001e32                 call    _audio_clear_peaks
F00DAD80: 92102010                 mov     0x10, %o1
F00DAD84: d006205c                 ld      [%i0+0x5C], %o0
F00DAD88: 40001e2f                 call    _audio_clear_peaks
F00DAD8C: 92102010                 mov     0x10, %o1
F00DAD90: 81c7e008                 ret
F00DAD94: 81e80000                 restore
