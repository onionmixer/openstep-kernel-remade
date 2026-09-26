F00C573C: 9de3bf88                 save    %sp, -0x78, %sp
F00C5740: 213c04cc                 sethi   %hi(dword_F013303C), %l0
F00C5744: d004203c                 ld      [%l0+%lo(dword_F013303C)], %o0! id
F00C5748: 133c0504                 sethi   %hi(paLock), %o1! SEL
F00C574C: 4000b049                 call    _objc_msgSend
F00C5750: d2026000                 ld      [%o1+%lo(paLock)], %o1
F00C5754: 9010001c                 mov     %i4, %o0
F00C5758: 7ffffbc3                 call    sub_F00C4664
F00C575C: 9207bfec                 add     %fp, var_14, %o1
F00C5760: b0100008                 mov     %o0, %i0
F00C5764: d004203c                 ld      [%l0+%lo(dword_F013303C)], %o0! id
F00C5768: 133c0504                 sethi   %hi(paUnlock), %o1! SEL
F00C576C: 4000b041                 call    _objc_msgSend
F00C5770: d2026244                 ld      [%o1+%lo(paUnlock)], %o1
F00C5774: 80a62000                 cmp     %i0, 0
F00C5778: 12800009                 bne     locret_F00C579C
F00C577C: 133c0504                 sethi   %hi(paGetcharvaluesF_0), %o1
F00C5780: 9410001a                 mov     %i2, %o2
F00C5784: d007bfec                 ld      [%fp+var_14], %o0! id
F00C5788: 9610001b                 mov     %i3, %o3
F00C578C: d20262d0                 ld      [%o1+%lo(paGetcharvaluesF_0)], %o1! SEL
F00C5790: 4000b038                 call    _objc_msgSend
F00C5794: 9810001d                 mov     %i5, %o4
F00C5798: b0100008                 mov     %o0, %i0
F00C579C: 81c7e008                 ret
F00C57A0: 81e80000                 restore
