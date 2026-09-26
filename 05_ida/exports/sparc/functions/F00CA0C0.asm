F00CA0C0: 9de3bf98                 save    %sp, -0x68, %sp
F00CA0C4: 113c04cc                 sethi   %hi(dword_F01330C0), %o0
F00CA0C8: d00220c0                 ld      [%o0+%lo(dword_F01330C0)], %o0! id
F00CA0CC: 133c0504                 sethi   %hi(paLock), %o1! SEL
F00CA0D0: 40009de8                 call    _objc_msgSend
F00CA0D4: d2026000                 ld      [%o1+%lo(paLock)], %o1
F00CA0D8: 113c04cc                 sethi   %hi(dword_F01330B4), %o0
F00CA0DC: f02220b4                 st      %i0, [%o0+%lo(dword_F01330B4)]
F00CA0E0: 113c04cc                 sethi   %hi(dword_F01330B8), %o0
F00CA0E4: f22220b8                 st      %i1, [%o0+%lo(dword_F01330B8)]
F00CA0E8: 113c04f6                 sethi   %hi(_IOTask_kern), %o0
F00CA0EC: 133c0328                 sethi   %hi(sub_F00CA114), %o1
F00CA0F0: d00221b8                 ld      [%o0+%lo(_IOTask_kern)], %o0
F00CA0F4: 7ffeae50                 call    _kernel_thread
F00CA0F8: 92126114                 bset    %lo(sub_F00CA114), %o1
F00CA0FC: b0100008                 mov     %o0, %i0
F00CA100: 92102012                 mov     0x12, %o1
F00CA104: 7ffeaeb5                 call    _thread_priority
F00CA108: 94102000                 mov     0, %o2
F00CA10C: 81c7e008                 ret
F00CA110: 81e80000                 restore
