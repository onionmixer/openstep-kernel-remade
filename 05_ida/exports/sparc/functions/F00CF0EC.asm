F00CF0EC: 9de3bf90                 save    %sp, -0x70, %sp
F00CF0F0: 7fffdb90                 call    _IOMalloc
F00CF0F4: 90102044                 mov     0x44, %o0! void *
F00CF0F8: b0100008                 mov     %o0, %i0
F00CF0FC: 7fff1757                 call    _bzero
F00CF100: 92102044                 mov     0x44, %o1 ! 'D'
F00CF104: 80a6a000                 cmp     %i2, 0
F00CF108: 3280000c                 bne,a   locret_F00CF138
F00CF10C: f4262018                 st      %i2, [%i0+0x18]
F00CF110: 113c0506                 sethi   %hi(paNxconditionloc), %o0
F00CF114: d002226c                 ld      [%o0+%lo(paNxconditionloc)], %o0! id
F00CF118: 133c0503                 sethi   %hi(paAlloc), %o1! SEL
F00CF11C: 400089d5                 call    _objc_msgSend
F00CF120: d20263f0                 ld      [%o1+%lo(paAlloc)], %o1
F00CF124: d026201c                 st      %o0, [%i0+0x1C]
F00CF128: 133c0503                 sethi   %hi(paInitwith), %o1
F00CF12C: d20263f4                 ld      [%o1+%lo(paInitwith)], %o1! SEL
F00CF130: 400089d0                 call    _objc_msgSend
F00CF134: 94102000                 mov     0, %o2
F00CF138: 81c7e008                 ret
F00CF13C: 81e80000                 restore
