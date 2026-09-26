F0039210: 9de3bf98                 save    %sp, -0x68, %sp
F0039214: 400176a0                 call    _splnet
F0039218: 01000000                 nop
F003921C: d2060000                 ld      [%i0], %o1
F0039220: 153c04bd                 sethi   %hi(dword_F012F4E8), %o2
F0039224: d402a0e8                 ld      [%o2+%lo(dword_F012F4E8)], %o2
F0039228: 80a2400a                 cmp     %o1, %o2
F003922C: 02800008                 be      loc_F003924C
F0039230: a0100008                 mov     %o0, %l0
F0039234: d0062004                 ld      [%i0+4], %o0
F0039238: 133c04d5                 sethi   %hi(_loifp), %o1
F003923C: d2026268                 ld      [%o1+%lo(_loifp)], %o1
F0039240: 80a20009                 cmp     %o0, %o1
F0039244: 12800004                 bne     loc_F0039254
F0039248: 01000000                 nop
F003924C: 10800013                 ba      loc_F0039298
F0039250: c0262010                 clr     [%i0+0x10]
F0039254: 4000005c                 call    _igmp_sendreport
F0039258: 90100018                 mov     %i0, %o0
F003925C: 113c04d9                 sethi   %hi(_in_ifaddr), %o0
F0039260: d2022070                 ld      [%o0+%lo(_in_ifaddr)], %o1
F0039264: 113c04d9                 sethi   %hi(_ipstat), %o0
F0039268: d00220d0                 ld      [%o0+%lo(_ipstat)], %o0
F003926C: d2026004                 ld      [%o1+4], %o1
F0039270: d4060000                 ld      [%i0], %o2
F0039274: 90020009                 add     %o0, %o1, %o0
F0039278: 9002000a                 add     %o0, %o2, %o0
F003927C: 7fff3589                 call    _urem
F0039280: 92102032                 mov     0x32, %o1 ! '2'
F0039284: 90022001                 inc     %o0
F0039288: d0262010                 st      %o0, [%i0+0x10]
F003928C: 133c0432                 sethi   %hi(dword_F010C9CC), %o1
F0039290: 90102001                 mov     1, %o0
F0039294: d02261cc                 st      %o0, [%o1+%lo(dword_F010C9CC)]
F0039298: 400176a3                 call    _splx
F003929C: 90100010                 mov     %l0, %o0
F00392A0: 81c7e008                 ret
F00392A4: 81e80000                 restore
