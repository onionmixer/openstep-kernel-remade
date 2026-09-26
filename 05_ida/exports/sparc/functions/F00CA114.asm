F00CA114: 9de3bf98                 save    %sp, -0x68, %sp
F00CA118: 113c04cc                 sethi   %hi(dword_F01330C0), %o0
F00CA11C: d00220c0                 ld      [%o0+%lo(dword_F01330C0)], %o0! id
F00CA120: 153c04cc                 sethi   %hi(dword_F01330B4), %o2
F00CA124: e202a0b4                 ld      [%o2+%lo(dword_F01330B4)], %l1
F00CA128: 133c0504                 sethi   %hi(paUnlock), %o1
F00CA12C: d2026244                 ld      [%o1+%lo(paUnlock)], %o1! SEL
F00CA130: 153c04cc                 sethi   %hi(dword_F01330B8), %o2! wired
F00CA134: 40009dcf                 call    _objc_msgSend
F00CA138: e002a0b8                 ld      [%o2+%lo(dword_F01330B8)], %l0
F00CA13C: 7ffeb0b9                 call    _current_thread_EXTERNAL
F00CA140: 01000000                 nop
F00CA144: 92100008                 mov     %o0, %o1! thread
F00CA148: 90102001                 mov     1, %o0! host_priv
F00CA14C: 7ffeaf66                 call    _thread_wire
F00CA150: 94102001                 mov     1, %o2
F00CA154: 9fc44000                 call    %l1
F00CA158: 90100010                 mov     %l0, %o0
F00CA15C: 40000030                 call    _IOExitThread
F00CA160: 01000000                 nop
F00CA164: 81c7e008                 ret
F00CA168: 81e80000                 restore
