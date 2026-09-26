F0090B24: 9de3bf88                 save    %sp, -0x78, %sp
F0090B28: 80a62000                 cmp     %i0, 0
F0090B2C: 12800004                 bne     loc_F0090B3C
F0090B30: a206a001                 add     %i2, 1, %l1
F0090B34: 1080002d                 ba      locret_F0090BE8
F0090B38: b0103d3f                 mov     -0x2C1, %i0
F0090B3C: 4000d4fd                 call    _IOMalloc
F0090B40: 90100011                 mov     %l1, %o0
F0090B44: b0920000                 orcc    %o0, %g0, %i0
F0090B48: 12800004                 bne     loc_F0090B58
F0090B4C: 90100019                 mov     %i1, %o0! void *
F0090B50: 10800026                 ba      locret_F0090BE8
F0090B54: b0103d25                 mov     -0x2DB, %i0
F0090B58: 92100018                 mov     %i0, %o1! void *
F0090B5C: 40000fed                 call    _bcopy
F0090B60: 9410001a                 mov     %i2, %o2
F0090B64: 113c0506                 sethi   %hi(paNxconditionloc), %o0
F0090B68: d002226c                 ld      [%o0+%lo(paNxconditionloc)], %o0! id
F0090B6C: 133c0503                 sethi   %hi(paAlloc), %o1
F0090B70: d20263f0                 ld      [%o1+%lo(paAlloc)], %o1! SEL
F0090B74: 4001833f                 call    _objc_msgSend
F0090B78: c02e001a                 clrb    [%i0+%i2]
F0090B7C: a0100008                 mov     %o0, %l0
F0090B80: 133c0503                 sethi   %hi(paInitwith), %o1
F0090B84: d20263f4                 ld      [%o1+%lo(paInitwith)], %o1! SEL
F0090B88: 4001833a                 call    _objc_msgSend
F0090B8C: 94102000                 mov     0, %o2
F0090B90: e027bfe8                 st      %l0, [%fp+var_18]
F0090B94: f027bfec                 st      %i0, [%fp+var_14]
F0090B98: 113c030e90122328         set     _configureThread, %o0
F0090BA0: 4000e548                 call    _IOForkThread
F0090BA4: 9207bfe8                 add     %fp, var_18, %o1
F0090BA8: 90100010                 mov     %l0, %o0! id
F0090BAC: 133c0503                 sethi   %hi(paLockwhen), %o1
F0090BB0: d20263f8                 ld      [%o1+%lo(paLockwhen)], %o1! SEL
F0090BB4: 4001832f                 call    _objc_msgSend
F0090BB8: 94102001                 mov     1, %o2
F0090BBC: 113c0503                 sethi   %hi(paFree), %o0! id
F0090BC0: d20223fc                 ld      [%o0+%lo(paFree)], %o1! SEL
F0090BC4: 4001832b                 call    _objc_msgSend
F0090BC8: 90100010                 mov     %l0, %o0
F0090BCC: 90100018                 mov     %i0, %o0
F0090BD0: 4000d4dd                 call    _IOFree
F0090BD4: 92100011                 mov     %l1, %o1
F0090BD8: d04fbff0                 ldsb    [%fp+var_10], %o0
F0090BDC: 80a00008                 cmp     %g0, %o0
F0090BE0: b0403fff                 addc    %g0, -1, %i0
F0090BE4: b00e3d40                 and     %i0, -0x2C0, %i0
F0090BE8: 81c7e008                 ret
F0090BEC: 81e80000                 restore
