F00D2FB0: 9de3bf90                 save    %sp, -0x70, %sp
F00D2FB4: 90100018                 mov     %i0, %o0! id
F00D2FB8: 133c0505                 sethi   %hi(paSpecialkeyport_0), %o1
F00D2FBC: d2026304                 ld      [%o1+%lo(paSpecialkeyport_0)], %o1! SEL
F00D2FC0: 40007a2c                 call    _objc_msgSend
F00D2FC4: 9410001a                 mov     %i2, %o2! size_t
F00D2FC8: a2920000                 orcc    %o0, %g0, %l1
F00D2FCC: 02800018                 be      locret_F00D302C
F00D2FD0: 01000000                 nop
F00D2FD4: 7fffcbd7                 call    _IOMalloc
F00D2FD8: 90102038                 mov     0x38, %o0 ! '8'
F00D2FDC: a0920000                 orcc    %o0, %g0, %l0
F00D2FE0: 02800013                 be      locret_F00D302C
F00D2FE4: 113c03e5                 sethi   %hi(unk_F00F9688), %o0
F00D2FE8: 90122288                 bset    %lo(unk_F00F9688), %o0! void *
F00D2FEC: 92100010                 mov     %l0, %o1! void *
F00D2FF0: 7fff06c8                 call    _bcopy
F00D2FF4: 94102038                 mov     0x38, %o2 ! '8'
F00D2FF8: e2242010                 st      %l1, [%l0+0x10]
F00D2FFC: f424201c                 st      %i2, [%l0+0x1C]
F00D3000: f6242024                 st      %i3, [%l0+0x24]
F00D3004: f824202c                 st      %i4, [%l0+0x2C]
F00D3008: fa242034                 st      %i5, [%l0+0x34]
F00D300C: 90100018                 mov     %i0, %o0! id
F00D3010: 133c0505                 sethi   %hi(paSendiothreadas), %o1
F00D3014: 153c0505                 sethi   %hi(paPerformspecial), %o2
F00D3018: d20262fc                 ld      [%o1+%lo(paSendiothreadas)], %o1! SEL
F00D301C: 96100018                 mov     %i0, %o3
F00D3020: d402a300                 ld      [%o2+%lo(paPerformspecial)], %o2
F00D3024: 40007a13                 call    _objc_msgSend
F00D3028: 98100010                 mov     %l0, %o4
F00D302C: 81c7e008                 ret
F00D3030: 81e80000                 restore
