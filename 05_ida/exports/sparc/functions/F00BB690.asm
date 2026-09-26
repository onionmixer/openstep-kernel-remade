F00BB690: 9de3bf98                 save    %sp, -0x68, %sp
F00BB694: 90100018                 mov     %i0, %o0! __s1
F00BB698: 133c047f                 sethi   %hi(aSunwTcx_0), %o1! "SUNW,tcx"
F00BB69C: 7ffd32c4                 call    _strcmp
F00BB6A0: 92126148                 bset    %lo(aSunwTcx_0), %o1! "SUNW,tcx"
F00BB6A4: 80a22000                 cmp     %o0, 0
F00BB6A8: 02800008                 be      loc_F00BB6C8
F00BB6AC: 90100018                 mov     %i0, %o0! __s1
F00BB6B0: 133c047f                 sethi   %hi(aTcx), %o1! "tcx"
F00BB6B4: 7ffd32be                 call    _strcmp
F00BB6B8: 92126158                 bset    %lo(aTcx), %o1! "tcx"
F00BB6BC: 80a22000                 cmp     %o0, 0
F00BB6C0: 12800006                 bne     locret_F00BB6D8
F00BB6C4: b0102000                 mov     0, %i0
F00BB6C8: 113c047f                 sethi   %hi(_ns24), %o0
F00BB6CC: f0022110                 ld      [%o0+%lo(_ns24)], %i0
F00BB6D0: b0062001                 inc     %i0
F00BB6D4: f0222110                 st      %i0, [%o0+%lo(_ns24)]
F00BB6D8: 81c7e008                 ret
F00BB6DC: 81e80000                 restore
