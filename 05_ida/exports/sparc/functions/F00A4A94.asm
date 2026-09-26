F00A4A94: 9de3bf98                 save    %sp, -0x68, %sp
F00A4A98: 92100018                 mov     %i0, %o1
F00A4A9C: 80a26003                 cmp     %o1, 3
F00A4AA0: 12800005                 bne     loc_F00A4AB4
F00A4AA4: 90100019                 mov     %i1, %o0
F00A4AA8: 7fffc30e                 call    _mmu_flushpagectx
F00A4AAC: 9210001a                 mov     %i2, %o1
F00A4AB0: 30800013                 ba,a    locret_F00A4AFC
F00A4AB4: 80a26002                 cmp     %o1, 2
F00A4AB8: 12800005                 bne     loc_F00A4ACC
F00A4ABC: 80a26001                 cmp     %o1, 1
F00A4AC0: 7fffc2fc                 call    _mmu_flushseg
F00A4AC4: 9210001a                 mov     %i2, %o1
F00A4AC8: 3080000d                 ba,a    locret_F00A4AFC
F00A4ACC: 12800005                 bne     loc_F00A4AE0
F00A4AD0: 80a26000                 cmp     %o1, 0
F00A4AD4: 7fffc2f1                 call    _mmu_flushrgn
F00A4AD8: 9210001a                 mov     %i2, %o1
F00A4ADC: 30800008                 ba,a    locret_F00A4AFC
F00A4AE0: 12800005                 bne     loc_F00A4AF4
F00A4AE4: 113c0465                 sethi   -0xFEE6C00, %o0
F00A4AE8: 7fffc2dd                 call    _mmu_flushctx
F00A4AEC: 9010001a                 mov     %i2, %o0! char *
F00A4AF0: 30800003                 ba,a    locret_F00A4AFC
F00A4AF4: 7ffdc19f                 call    _panic
F00A4AF8: 901223f8                 bset    0x3F8, %o0
F00A4AFC: 81c7e008                 ret
F00A4B00: 81e80000                 restore
