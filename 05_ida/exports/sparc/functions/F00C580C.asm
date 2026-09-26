F00C580C: 9de3bf88                 save    %sp, -0x78, %sp
F00C5810: 213c04cc                 sethi   %hi(dword_F013303C), %l0
F00C5814: d004203c                 ld      [%l0+%lo(dword_F013303C)], %o0! id
F00C5818: 133c0504                 sethi   %hi(paLock), %o1! SEL
F00C581C: 4000b015                 call    _objc_msgSend
F00C5820: d2026000                 ld      [%o1+%lo(paLock)], %o1
F00C5824: 9010001c                 mov     %i4, %o0
F00C5828: 7ffffb8f                 call    sub_F00C4664
F00C582C: 9207bfec                 add     %fp, var_14, %o1
F00C5830: b0100008                 mov     %o0, %i0
F00C5834: d004203c                 ld      [%l0+%lo(dword_F013303C)], %o0! id
F00C5838: 133c0504                 sethi   %hi(paUnlock), %o1! SEL
F00C583C: 4000b00d                 call    _objc_msgSend
F00C5840: d2026244                 ld      [%o1+%lo(paUnlock)], %o1
F00C5844: 80a62000                 cmp     %i0, 0
F00C5848: 12800009                 bne     locret_F00C586C
F00C584C: 133c0504                 sethi   %hi(paSetcharvaluesF_0), %o1
F00C5850: 9410001a                 mov     %i2, %o2
F00C5854: d007bfec                 ld      [%fp+var_14], %o0! id
F00C5858: 9610001b                 mov     %i3, %o3
F00C585C: d20262d8                 ld      [%o1+%lo(paSetcharvaluesF_0)], %o1! SEL
F00C5860: 4000b004                 call    _objc_msgSend
F00C5864: 9810001d                 mov     %i5, %o4
F00C5868: b0100008                 mov     %o0, %i0
F00C586C: 81c7e008                 ret
F00C5870: 81e80000                 restore
