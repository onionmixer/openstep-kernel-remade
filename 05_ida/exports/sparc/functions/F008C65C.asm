F008C65C: 9de3bf98                 save    %sp, -0x68, %sp
F008C660: 40000017                 call    sub_F008C6BC
F008C664: 213c04c3                 sethi   %hi(dword_F0130FF0), %l0
F008C668: 4000daac                 call    _probeNativeDevices
F008C66C: 01000000                 nop
F008C670: 4000dd3f                 call    _probeHardware
F008C674: 01000000                 nop
F008C678: 4000dd40                 call    _probeDirectDevices
F008C67C: 01000000                 nop
F008C680: 4000002a                 call    sub_F008C728
F008C684: 01000000                 nop
F008C688: d00423f0                 ld      [%l0+%lo(dword_F0130FF0)], %o0! id
F008C68C: 133c0504                 sethi   %hi(paLock), %o1! SEL
F008C690: 40019478                 call    _objc_msgSend
F008C694: d2026000                 ld      [%o1+%lo(paLock)], %o1
F008C698: d00423f0                 ld      [%l0+%lo(dword_F0130FF0)], %o0! id
F008C69C: 133c0504                 sethi   %hi(paUnlockwith), %o1
F008C6A0: d2026004                 ld      [%o1+%lo(paUnlockwith)], %o1! SEL
F008C6A4: 40019473                 call    _objc_msgSend
F008C6A8: 94102001                 mov     1, %o2
F008C6AC: 4000f6dc                 call    _IOExitThread
F008C6B0: 01000000                 nop
F008C6B4: 81c7e008                 ret
F008C6B8: 81e80000                 restore
