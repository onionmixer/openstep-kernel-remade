F0087A34: 9de3bf98                 save    %sp, -0x68, %sp
F0087A38: 80a66000                 cmp     %i1, 0
F0087A3C: 02800004                 be      loc_F0087A4C
F0087A40: 80a62000                 cmp     %i0, 0
F0087A44: 1080002c                 ba      locret_F0087AF4
F0087A48: b0102000                 mov     0, %i0
F0087A4C: 02800029                 be      loc_F0087AF0
F0087A50: b2062010                 add     %i0, 0x10, %i1
F0087A54: d0064000                 ld      [%i1], %o0
F0087A58: 80a22000                 cmp     %o0, 0
F0087A5C: 12bffffe                 bne     loc_F0087A54
F0087A60: 01000000                 nop
F0087A64: 40003d11                 call    _simple_lock_try
F0087A68: 90100019                 mov     %i1, %o0
F0087A6C: 80a22000                 cmp     %o0, 0
F0087A70: 02bffff9                 be      loc_F0087A54
F0087A74: 01000000                 nop
F0087A78: 7fffff02                 call    _vm_object_collapse
F0087A7C: 90100018                 mov     %i0, %o0
F0087A80: d0562018                 ldsh    [%i0+0x18], %o0
F0087A84: 80a22001                 cmp     %o0, 1
F0087A88: 1480000e                 bg      loc_F0087AC0
F0087A8C: 01000000                 nop
F0087A90: d0062028                 ld      [%i0+0x28], %o0
F0087A94: 80a22000                 cmp     %o0, 0
F0087A98: 1280000a                 bne     loc_F0087AC0
F0087A9C: 01000000                 nop
F0087AA0: d0062020                 ld      [%i0+0x20], %o0
F0087AA4: 80a22000                 cmp     %o0, 0
F0087AA8: 12800006                 bne     loc_F0087AC0
F0087AAC: 01000000                 nop
F0087AB0: d006201c                 ld      [%i0+0x1C], %o0
F0087AB4: 80a22000                 cmp     %o0, 0
F0087AB8: 02800005                 be      loc_F0087ACC
F0087ABC: 90100018                 mov     %i0, %o0
F0087AC0: c0262010                 clr     [%i0+0x10]
F0087AC4: 1080000c                 ba      locret_F0087AF4
F0087AC8: b0102000                 mov     0, %i0
F0087ACC: 9206801c                 add     %i2, %i4, %o1
F0087AD0: ba02401d                 add     %o1, %i5, %i5
F0087AD4: 7fffffb4                 call    _vm_object_page_remove
F0087AD8: 9410001d                 mov     %i5, %o2
F0087ADC: d0062014                 ld      [%i0+0x14], %o0
F0087AE0: 80a74008                 cmp     %i5, %o0
F0087AE4: 38800002                 bgu,a   loc_F0087AEC
F0087AE8: fa262014                 st      %i5, [%i0+0x14]
F0087AEC: c0262010                 clr     [%i0+0x10]
F0087AF0: b0102001                 mov     1, %i0
F0087AF4: 81c7e008                 ret
F0087AF8: 81e80000                 restore
