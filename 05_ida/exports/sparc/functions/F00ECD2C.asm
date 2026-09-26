F00ECD2C: 9de3bf98                 save    %sp, -0x68, %sp
F00ECD30: 7ffe25bc                 call    _current_thread_EXTERNAL
F00ECD34: 01000000                 nop
F00ECD38: 94100008                 mov     %o0, %o2
F00ECD3C: 113c04bc92122048         set     unk_F012F048, %o1
F00ECD44: 80a26000                 cmp     %o1, 0
F00ECD48: 0280000a                 be      loc_F00ECD70
F00ECD4C: 01000000                 nop
F00ECD50: d0026010                 ld      [%o1+0x10], %o0
F00ECD54: 80a2000a                 cmp     %o0, %o2
F00ECD58: 2280000a                 be,a    loc_F00ECD80
F00ECD5C: d0024000                 ld      [%o1], %o0
F00ECD60: d2026014                 ld      [%o1+0x14], %o1
F00ECD64: 80a26000                 cmp     %o1, 0
F00ECD68: 32bffffb                 bne,a   loc_F00ECD54
F00ECD6C: d0026010                 ld      [%o1+0x10], %o0
F00ECD70: 7ffffec2                 call    sub_F00EC878
F00ECD74: 9010000a                 mov     %o2, %o0
F00ECD78: 92100008                 mov     %o0, %o1
F00ECD7C: d0024000                 ld      [%o1], %o0
F00ECD80: d0262074                 st      %o0, [%i0+0x74]
F00ECD84: f0224000                 st      %i0, [%o1]
F00ECD88: c0262078                 clr     [%i0+0x78]
F00ECD8C: 81c7e008                 ret
F00ECD90: 81e80000                 restore
