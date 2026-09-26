F008420C: 9de3bf98                 save    %sp, -0x68, %sp
F0084210: 80a62000                 cmp     %i0, 0
F0084214: 02800020                 be      locret_F0084294
F0084218: a0062034                 add     %i0, 0x34, %l0 ! '4'
F008421C: d0040000                 ld      [%l0], %o0
F0084220: 80a22000                 cmp     %o0, 0
F0084224: 12bffffe                 bne     loc_F008421C
F0084228: 01000000                 nop
F008422C: 40004b1f                 call    _simple_lock_try
F0084230: 90100010                 mov     %l0, %o0
F0084234: 80a22000                 cmp     %o0, 0
F0084238: 02bffff9                 be      loc_F008421C
F008423C: 01000000                 nop
F0084240: d0062030                 ld      [%i0+0x30], %o0
F0084244: c0262034                 clr     [%i0+0x34]
F0084248: 90023fff                 inc     -1, %o0
F008424C: 80a22000                 cmp     %o0, 0
F0084250: 14800011                 bg      locret_F0084294
F0084254: d0262030                 st      %o0, [%i0+0x30]
F0084258: 7fff92db                 call    _lock_write
F008425C: 90100018                 mov     %i0, %o0
F0084260: d006204c                 ld      [%i0+0x4C], %o0
F0084264: 90022001                 inc     %o0
F0084268: d026204c                 st      %o0, [%i0+0x4C]
F008426C: 90100018                 mov     %i0, %o0
F0084270: d2062014                 ld      [%i0+0x14], %o1
F0084274: 400003d4                 call    _vm_map_delete
F0084278: d4062018                 ld      [%i0+0x18], %o2
F008427C: 40006188                 call    _pmap_destroy
F0084280: d0062024                 ld      [%i0+0x24], %o0
F0084284: 113c04f4                 sethi   %hi(_vm_map_zone), %o0
F0084288: d0022388                 ld      [%o0+%lo(_vm_map_zone)], %o0
F008428C: 7fffd3d1                 call    _zfree
F0084290: 92100018                 mov     %i0, %o1
F0084294: 81c7e008                 ret
F0084298: 81e80000                 restore
