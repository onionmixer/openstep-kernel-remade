F0099C7C: 9de3bf48                 save    %sp, -0xB8, %sp
F0099C80: a407bfa8                 add     %fp, __dst, %l2
F0099C84: 90100012                 mov     %l2, %o0! __dst
F0099C88: 133c045c921260b8         set     aRestartOrHaltT, %o1! "Restart or halt?  Type r to restart,\no"...
F0099C90: 7ffdb584                 call    _memcpy
F0099C94: 9410204c                 mov     0x4C, %o2 ! 'L'
F0099C98: 7ffff3bc                 call    _splusclock
F0099C9C: a8102001                 mov     1, %l4
F0099CA0: a6100008                 mov     %o0, %l3
F0099CA4: 90100018                 mov     %i0, %o0! __s1
F0099CA8: 133c045c                 sethi   %hi(aRestart), %o1! "restart"
F0099CAC: 7ffdb940                 call    _strcmp
F0099CB0: 92126108                 bset    %lo(aRestart), %o1! "restart"
F0099CB4: 80a00008                 cmp     %g0, %o0
F0099CB8: a2603fff                 subc    %g0, -1, %l1
F0099CBC: 90100018                 mov     %i0, %o0! __s1
F0099CC0: 133c045c                 sethi   %hi(aPanic_0), %o1! "panic"
F0099CC4: 7ffdb93a                 call    _strcmp
F0099CC8: 92126110                 bset    %lo(aPanic_0), %o1! "panic"
F0099CCC: 80a00008                 cmp     %g0, %o0
F0099CD0: a0603fff                 subc    %g0, -1, %l0
F0099CD4: 80a46000                 cmp     %l1, 0
F0099CD8: 02800006                 be      loc_F0099CF0
F0099CDC: 90100019                 mov     %i1, %o0
F0099CE0: 40008e2e                 call    _DoAlert
F0099CE4: 92100012                 mov     %l2, %o1
F0099CE8: 10800005                 ba      loc_F0099CFC
F0099CEC: a2102001                 mov     1, %l1
F0099CF0: 133c045c                 sethi   %hi(unk_F0117118), %o1
F0099CF4: 40008e29                 call    _DoAlert
F0099CF8: 92126118                 bset    %lo(unk_F0117118), %o1
F0099CFC: 80a42000                 cmp     %l0, 0
F0099D00: 02800005                 be      loc_F0099D14
F0099D04: 80a46000                 cmp     %l1, 0
F0099D08: 40008927                 call    _kmdumplog
F0099D0C: 01000000                 nop
F0099D10: 80a46000                 cmp     %l1, 0
F0099D14: 02800013                 be      loc_F0099D60
F0099D18: 90100018                 mov     %i0, %o0
F0099D1C: 40008ea2                 call    _kmtrygetc
F0099D20: 01000000                 nop
F0099D24: b0100008                 mov     %o0, %i0
F0099D28: 80a62072                 cmp     %i0, 0x72 ! 'r'
F0099D2C: 12800005                 bne     loc_F0099D40
F0099D30: 80a62068                 cmp     %i0, 0x68 ! 'h'
F0099D34: 7fffffbf                 call    _reboot_mach
F0099D38: 90102000                 mov     0, %o0
F0099D3C: 80a62068                 cmp     %i0, 0x68 ! 'h'
F0099D40: 12800005                 bne     loc_F0099D54
F0099D44: 80a63fff                 cmp     %i0, -1
F0099D48: 7fffffba                 call    _reboot_mach
F0099D4C: 90102008                 mov     8, %o0
F0099D50: 80a63fff                 cmp     %i0, -1
F0099D54: 02bffff2                 be      loc_F0099D1C
F0099D58: 80a52000                 cmp     %l4, 0
F0099D5C: 30800008                 ba,a    loc_F0099D7C
F0099D60: 92100010                 mov     %l0, %o1
F0099D64: 7fff5041                 call    _miniMonLoop
F0099D68: 9410001a                 mov     %i2, %o2
F0099D6C: 80a42000                 cmp     %l0, 0
F0099D70: 12bffffc                 bne     loc_F0099D60
F0099D74: 90100018                 mov     %i0, %o0
F0099D78: 80a52000                 cmp     %l4, 0
F0099D7C: 02800009                 be      loc_F0099DA0
F0099D80: 113c04f7                 sethi   %hi(_nmi_stay), %o0
F0099D84: d00221e0                 ld      [%o0+%lo(_nmi_stay)], %o0
F0099D88: 80a22000                 cmp     %o0, 0
F0099D8C: 32800005                 bne,a   loc_F0099DA0
F0099D90: 113c04f7                 sethi   -0xFEC2400, %o0
F0099D94: 40008ab9                 call    _DoRestore
F0099D98: 01000000                 nop
F0099D9C: 113c04f7                 sethi   -0xFEC2400, %o0
F0099DA0: c02221e0                 clr     [%o0+0x1E0]
F0099DA4: 7ffff3e0                 call    _splx
F0099DA8: 90100013                 mov     %l3, %o0
F0099DAC: 81c7e008                 ret
F0099DB0: 81e80000                 restore
