F00D4634: 9de3bf80                 save    %sp, -0x80, %sp
F00D4638: 7fffc6a9                 call    _IOGetTimestamp
F00D463C: 9007bfe8                 add     %fp, var_18, %o0
F00D4640: 90100018                 mov     %i0, %o0! id
F00D4644: 133c0504                 sethi   %hi(paRelativepointe), %o1
F00D4648: d41fbfe8                 ldd     [%fp+var_18], %o2
F00D464C: 9810001c                 mov     %i4, %o4
F00D4650: d20262ec                 ld      [%o1+%lo(paRelativepointe)], %o1! SEL
F00D4654: d623a05c                 st      %o3, [%sp+0x80+var_24]
F00D4658: 9a10000a                 mov     %o2, %o5
F00D465C: 9410001a                 mov     %i2, %o2
F00D4660: 40007484                 call    _objc_msgSend
F00D4664: 9610001b                 mov     %i3, %o3
F00D4668: 81c7e008                 ret
F00D466C: 91e80008                 restore %g0, %o0, %o0
