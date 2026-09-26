F00CA080: 9de3bf98                 save    %sp, -0x68, %sp
F00CA084: 213c04cc                 sethi   %hi(dword_F01330BC), %l0
F00CA088: d00420bc                 ld      [%l0+%lo(dword_F01330BC)], %o0
F00CA08C: 80a22000                 cmp     %o0, 0
F00CA090: 1280000a                 bne     locret_F00CA0B8
F00CA094: 113c0506                 sethi   %hi(paNxlock), %o0
F00CA098: d00222a0                 ld      [%o0+%lo(paNxlock)], %o0! id
F00CA09C: 133c0504                 sethi   %hi(paNew), %o1! SEL
F00CA0A0: 40009df4                 call    _objc_msgSend
F00CA0A4: d2026238                 ld      [%o1+%lo(paNew)], %o1
F00CA0A8: 133c04cc                 sethi   %hi(dword_F01330C0), %o1
F00CA0AC: d02260c0                 st      %o0, [%o1+%lo(dword_F01330C0)]
F00CA0B0: 90102001                 mov     1, %o0
F00CA0B4: d02420bc                 st      %o0, [%l0+%lo(dword_F01330BC)]
F00CA0B8: 81c7e008                 ret
F00CA0BC: 81e80000                 restore
