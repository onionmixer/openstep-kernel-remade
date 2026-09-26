F00BAC54: 9de3bf98                 save    %sp, -0x68, %sp
F00BAC58: 90100018                 mov     %i0, %o0! __s1
F00BAC5C: 133c047e                 sethi   %hi(unk_F011FB48), %o1! __s2
F00BAC60: 7ffd3553                 call    _strcmp
F00BAC64: 92126348                 bset    %lo(unk_F011FB48), %o1
F00BAC68: 80a22000                 cmp     %o0, 0
F00BAC6C: 12800007                 bne     locret_F00BAC88
F00BAC70: b0102000                 mov     0, %i0
F00BAC74: 133c04fc                 sethi   %hi(_nzs), %o1
F00BAC78: d0026150                 ld      [%o1+%lo(_nzs)], %o0
F00BAC7C: b0102001                 mov     1, %i0
F00BAC80: 90022002                 inc     2, %o0
F00BAC84: d0226150                 st      %o0, [%o1+%lo(_nzs)]
F00BAC88: 81c7e008                 ret
F00BAC8C: 81e80000                 restore
