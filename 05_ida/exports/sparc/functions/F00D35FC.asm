F00D35FC: 9de3bf90                 save    %sp, -0x70, %sp
F00D3600: d0062214                 ld      [%i0+0x214], %o0! id
F00D3604: 133c0504                 sethi   %hi(paLock), %o1! SEL
F00D3608: 4000789a                 call    _objc_msgSend
F00D360C: d2026000                 ld      [%o1+%lo(paLock)], %o1
F00D3610: d0062214                 ld      [%i0+0x214], %o0! id
F00D3614: 133c0504                 sethi   %hi(paUnlock), %o1
F00D3618: d2026244                 ld      [%o1+%lo(paUnlock)], %o1! SEL
F00D361C: 40007895                 call    _objc_msgSend
F00D3620: c02e2212                 clrb    [%i0+0x212]
F00D3624: 92102001                 mov     1, %o1
F00D3628: d006214c                 ld      [%i0+0x14C], %o0
F00D362C: 7ffe49aa                 call    _msg_send
F00D3630: 94102000                 mov     0, %o2
F00D3634: a2100008                 mov     %o0, %l1
F00D3638: 80a47f99                 cmp     %l1, -0x67
F00D363C: 0280000d                 be      locret_F00D3670
F00D3640: 80a46000                 cmp     %l1, 0
F00D3644: 0280000b                 be      locret_F00D3670
F00D3648: 90100018                 mov     %i0, %o0! id
F00D364C: 133c0504                 sethi   %hi(paName), %o1
F00D3650: d2026008                 ld      [%o1+%lo(paName)], %o1! SEL
F00D3654: 213c03ef                 sethi   %hi(aSPerformkickev), %l0! "%s: _performKickEventConsumer msg_send "...
F00D3658: 40007886                 call    _objc_msgSend
F00D365C: a0142240                 bset    %lo(aSPerformkickev), %l0! "%s: _performKickEventConsumer msg_send "...
F00D3660: 92100008                 mov     %o0, %o1
F00D3664: 90100010                 mov     %l0, %o0
F00D3668: 7fffcaa3                 call    _IOLog
F00D366C: 94100011                 mov     %l1, %o2
F00D3670: 81c7e008                 ret
F00D3674: 81e80000                 restore
