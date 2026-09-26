F00D9AE4: 9de3bf90                 save    %sp, -0x70, %sp
F00D9AE8: 113c0506                 sethi   %hi(paIoaudio), %o0
F00D9AEC: d00222d4                 ld      [%o0+%lo(paIoaudio)], %o0! id
F00D9AF0: 133c0505                 sethi   %hi(paSetinstance), %o1
F00D9AF4: d20260dc                 ld      [%o1+%lo(paSetinstance)], %o1! SEL
F00D9AF8: 40005f5e                 call    _objc_msgSend
F00D9AFC: 94102000                 mov     0, %o2
F00D9B00: d0062174                 ld      [%i0+0x174], %o0
F00D9B04: 7fffb110                 call    _IOFree
F00D9B08: 92102020                 mov     0x20, %o1 ! ' '
F00D9B0C: f027bff0                 st      %i0, [%fp+var_10]
F00D9B10: 133c0508                 sethi   %hi(stru_F014222C.ext), %o1
F00D9B14: d4026258                 ld      [%o1+%lo(stru_F014222C.ext)], %o2
F00D9B18: 9007bff0                 add     %fp, var_10, %o0! objc_super *
F00D9B1C: 133c0503                 sethi   %hi(paFree), %o1
F00D9B20: d20263fc                 ld      [%o1+%lo(paFree)], %o1! SEL
F00D9B24: 40005f96                 call    _objc_msgSendSuper
F00D9B28: d427bff4                 st      %o2, [%fp+var_C]
F00D9B2C: 81c7e008                 ret
F00D9B30: 91e80008                 restore %g0, %o0, %o0
