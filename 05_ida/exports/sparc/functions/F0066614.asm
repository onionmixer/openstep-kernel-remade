F0066614: 9de3bf98                 save    %sp, -0x68, %sp
F0066618: 4000c15c                 call    _splusclock
F006661C: a0062020                 add     %i0, 0x20, %l0 ! ' '
F0066620: a2100008                 mov     %o0, %l1
F0066624: d0040000                 ld      [%l0], %o0
F0066628: 80a22000                 cmp     %o0, 0
F006662C: 12bffffe                 bne     loc_F0066624
F0066630: 01000000                 nop
F0066634: 4000c21d                 call    _simple_lock_try
F0066638: 90100010                 mov     %l0, %o0
F006663C: 80a22000                 cmp     %o0, 0
F0066640: 02bffff9                 be      loc_F0066624
F0066644: 01000000                 nop
F0066648: d006214c                 ld      [%i0+0x14C], %o0
F006664C: 80a22000                 cmp     %o0, 0
F0066650: 22800005                 be,a    loc_F0066664
F0066654: d406204c                 ld      [%i0+0x4C], %o2
F0066658: 40000cff                 call    _reset_timeout
F006665C: 90062118                 add     %i0, 0x118, %o0
F0066660: d406204c                 ld      [%i0+0x4C], %o2
F0066664: 900aa00f                 and     %o2, 0xF, %o0
F0066668: 92023fff                 add     %o0, -1, %o1
F006666C: 80a2600e                 cmp     %o1, 0xE! switch 15 cases
F0066670: 18800021                 bgu     def_F0066684! jumptable F0066684 default case, cases 1,3,5,7,9,11,13
F0066674: 113c0199                 sethi   %hi(jpt_F0066684), %o0
F0066678: 9012228c                 bset    %lo(jpt_F0066684), %o0
F006667C: 932a6002                 sll     %o1, 2, %o1
F0066680: d0024008                 ld      [%o1+%o0], %o0
F0066684: 81c20000                 jmp     %o0! switch jump
F0066688: 01000000                 nop
F00666C8: 900abffe                 and     %o2, -2, %o0! jumptable F0066684 cases 0,8,10
F00666CC: 90122004                 bset    4, %o0
F00666D0: d026204c                 st      %o0, [%i0+0x4C]
F00666D4: c0262044                 clr     [%i0+0x44]
F00666D8: 90100018                 mov     %i0, %o0
F00666DC: 40002d71                 call    _thread_setrun
F00666E0: 92102001                 mov     1, %o1
F00666E4: 30800004                 ba,a    def_F0066684! jumptable F0066684 default case, cases 1,3,5,7,9,11,13
F00666E8: 900abffe                 and     %o2, -2, %o0! jumptable F0066684 cases 2,4,6,12,14
F00666EC: d026204c                 st      %o0, [%i0+0x4C]
F00666F0: c0262044                 clr     [%i0+0x44]
F00666F4: c0262020                 clr     [%i0+0x20]! jumptable F0066684 default case, cases 1,3,5,7,9,11,13
F00666F8: 4000c18b                 call    _splx
F00666FC: 90100011                 mov     %l1, %o0
F0066700: 81c7e008                 ret
F0066704: 81e80000                 restore
