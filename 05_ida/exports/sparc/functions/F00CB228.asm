F00CB228: 9de3bf90                 save    %sp, -0x70, %sp
F00CB22C: f027bff0                 st      %i0, [%fp+var_10]
F00CB230: 133c0508                 sethi   %hi(stru_F014209C.ext), %o1
F00CB234: d40260c8                 ld      [%o1+%lo(stru_F014209C.ext)], %o2
F00CB238: 9007bff0                 add     %fp, var_10, %o0! objc_super *
F00CB23C: 133c0504                 sethi   %hi(paInit), %o1
F00CB240: d202602c                 ld      [%o1+%lo(paInit)], %o1! SEL
F00CB244: 400099ce                 call    _objc_msgSendSuper
F00CB248: d427bff4                 st      %o2, [%fp+var_C]
F00CB24C: 113c0506                 sethi   %hi(paNxconditionloc), %o0
F00CB250: d002226c                 ld      [%o0+%lo(paNxconditionloc)], %o0! id
F00CB254: 133c0503                 sethi   %hi(paAlloc), %o1! SEL
F00CB258: 40009986                 call    _objc_msgSend
F00CB25C: d20263f0                 ld      [%o1+%lo(paAlloc)], %o1
F00CB260: 133c0503                 sethi   %hi(paInitwith), %o1
F00CB264: d20263f4                 ld      [%o1+%lo(paInitwith)], %o1! SEL
F00CB268: 40009982                 call    _objc_msgSend
F00CB26C: 94102003                 mov     3, %o2
F00CB270: d0262008                 st      %o0, [%i0+8]
F00CB274: 7ffffc08                 call    _IOGetKernPort
F00CB278: 9010001a                 mov     %i2, %o0
F00CB27C: d0262004                 st      %o0, [%i0+4]
F00CB280: 81c7e008                 ret
F00CB284: 81e80000                 restore
