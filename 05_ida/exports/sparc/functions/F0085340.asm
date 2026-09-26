F0085340: 9de3bf98                 save    %sp, -0x68, %sp
F0085344: a0100018                 mov     %i0, %l0
F0085348: 7fff8e9f                 call    _lock_write
F008534C: 90100010                 mov     %l0, %o0
F0085350: d004204c                 ld      [%l0+0x4C], %o0
F0085354: 90022001                 inc     %o0
F0085358: d024204c                 st      %o0, [%l0+0x4C]
F008535C: d0042014                 ld      [%l0+0x14], %o0
F0085360: 80a64008                 cmp     %i1, %o0
F0085364: 2a800002                 bcs,a   loc_F008536C
F0085368: b2100008                 mov     %o0, %i1
F008536C: d0042018                 ld      [%l0+0x18], %o0
F0085370: 80a68008                 cmp     %i2, %o0
F0085374: 38800002                 bgu,a   loc_F008537C
F0085378: b4100008                 mov     %o0, %i2
F008537C: 80a6401a                 cmp     %i1, %i2
F0085380: 38800002                 bgu,a   loc_F0085388
F0085384: b210001a                 mov     %i2, %i1
F0085388: 90100010                 mov     %l0, %o0
F008538C: 92100019                 mov     %i1, %o1
F0085390: 7fffff8d                 call    _vm_map_delete
F0085394: 9410001a                 mov     %i2, %o2
F0085398: b0100008                 mov     %o0, %i0
F008539C: 7fff8f26                 call    _lock_done
F00853A0: 90100010                 mov     %l0, %o0
F00853A4: 81c7e008                 ret
F00853A8: 81e80000                 restore
