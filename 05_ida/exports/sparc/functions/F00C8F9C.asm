F00C8F9C: 9de3bf90                 save    %sp, -0x70, %sp
F00C8FA0: a2103d42                 mov     -0x2BE, %l1
F00C8FA4: 7ffff3e3                 call    _IOMalloc
F00C8FA8: 912ee003                 sll     %i3, 3, %o0
F00C8FAC: 94102000                 mov     0, %o2
F00C8FB0: 80a2801b                 cmp     %o2, %i3
F00C8FB4: 1a80000c                 bcc     loc_F00C8FE4
F00C8FB8: a0100008                 mov     %o0, %l0
F00C8FBC: 92100010                 mov     %l0, %o1
F00C8FC0: d0068000                 ld      [%i2], %o0
F00C8FC4: 9402a001                 inc     %o2
F00C8FC8: d0224000                 st      %o0, [%o1]
F00C8FCC: d006a004                 ld      [%i2+4], %o0
F00C8FD0: 80a2801b                 cmp     %o2, %i3
F00C8FD4: d0226004                 st      %o0, [%o1+4]
F00C8FD8: b406a008                 inc     8, %i2
F00C8FDC: 0abffff9                 bcs     loc_F00C8FC0
F00C8FE0: 92026008                 inc     8, %o1
F00C8FE4: 113c0506                 sethi   %hi(paDelegate), %o0! id
F00C8FE8: d2022118                 ld      [%o0+%lo(paDelegate)], %o1! SEL
F00C8FEC: 4000a221                 call    _objc_msgSend
F00C8FF0: 90100018                 mov     %i0, %o0! id
F00C8FF4: 133c0506                 sethi   %hi(paAllocateranges), %o1
F00C8FF8: 193c03eb                 sethi   %hi(aMemoryMaps), %o4! "Memory Maps"
F00C8FFC: 94100010                 mov     %l0, %o2
F00C9000: 9610001b                 mov     %i3, %o3
F00C9004: d2026108                 ld      [%o1+%lo(paAllocateranges)], %o1! SEL
F00C9008: 4000a21a                 call    _objc_msgSend
F00C900C: 981323e8                 bset    %lo(aMemoryMaps), %o4! "Memory Maps"
F00C9010: 80a22000                 cmp     %o0, 0
F00C9014: 2280000d                 be,a    loc_F00C9048
F00C9018: 90100010                 mov     %l0, %o0
F00C901C: f0062010                 ld      [%i0+0x10], %i0
F00C9020: d206200c                 ld      [%i0+0xC], %o1
F00C9024: 80a26000                 cmp     %o1, 0
F00C9028: 22800006                 be,a    loc_F00C9040
F00C902C: c026200c                 clr     [%i0+0xC]
F00C9030: d0062008                 ld      [%i0+8], %o0
F00C9034: 7ffff3c4                 call    _IOFree
F00C9038: 932a6003                 sll     %o1, 3, %o1
F00C903C: c026200c                 clr     [%i0+0xC]
F00C9040: a2102000                 mov     0, %l1
F00C9044: 90100010                 mov     %l0, %o0
F00C9048: 7ffff3bf                 call    _IOFree
F00C904C: 932ee003                 sll     %i3, 3, %o1
F00C9050: 81c7e008                 ret
F00C9054: 91e80011                 restore %g0, %l1, %o0
