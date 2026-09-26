F00C6760: 9de3bf90                 save    %sp, -0x70, %sp
F00C6764: d04e2116                 ldsb    [%i0+0x116], %o0
F00C6768: 80a22000                 cmp     %o0, 0
F00C676C: 02800044                 be      locret_F00C687C
F00C6770: 113c0506                 sethi   %hi(paNxlock), %o0
F00C6774: d00222a0                 ld      [%o0+%lo(paNxlock)], %o0! id
F00C6778: 133c0504                 sethi   %hi(paNew), %o1
F00C677C: d2026238                 ld      [%o1+%lo(paNew)], %o1! SEL
F00C6780: 4000ac3c                 call    _objc_msgSend
F00C6784: c0262108                 clr     [%i0+0x108]
F00C6788: d026211c                 st      %o0, [%i0+0x11C]
F00C678C: c026213c                 clr     [%i0+0x13C]
F00C6790: c0262140                 clr     [%i0+0x140]
F00C6794: c0262144                 clr     [%i0+0x144]
F00C6798: c0262148                 clr     [%i0+0x148]
F00C679C: c026214c                 clr     [%i0+0x14C]
F00C67A0: c0262150                 clr     [%i0+0x150]
F00C67A4: c0262154                 clr     [%i0+0x154]
F00C67A8: c0262158                 clr     [%i0+0x158]
F00C67AC: c026215c                 clr     [%i0+0x15C]
F00C67B0: c0262160                 clr     [%i0+0x160]
F00C67B4: c0262164                 clr     [%i0+0x164]
F00C67B8: c0262168                 clr     [%i0+0x168]
F00C67BC: c026216c                 clr     [%i0+0x16C]
F00C67C0: c0262170                 clr     [%i0+0x170]
F00C67C4: f027bff0                 st      %i0, [%fp+var_10]
F00C67C8: 133c0507                 sethi   %hi(stru_F0141EBC.ext), %o1
F00C67CC: d40262e8                 ld      [%o1+%lo(stru_F0141EBC.ext)], %o2
F00C67D0: 9007bff0                 add     %fp, var_10, %o0! objc_super *
F00C67D4: 133c0504                 sethi   %hi(paRegisterdevice), %o1
F00C67D8: d202625c                 ld      [%o1+%lo(paRegisterdevice)], %o1! SEL
F00C67DC: 4000ac68                 call    _objc_msgSendSuper
F00C67E0: d427bff4                 st      %o2, [%fp+var_C]
F00C67E4: a8920000                 orcc    %o0, %g0, %l4
F00C67E8: 02800025                 be      locret_F00C687C
F00C67EC: 113c0504                 sethi   %hi(paClass), %o0
F00C67F0: e6022014                 ld      [%o0+%lo(paClass)], %l3
F00C67F4: 90100018                 mov     %i0, %o0! id
F00C67F8: 4000ac1e                 call    _objc_msgSend
F00C67FC: 92100013                 mov     %l3, %o1
F00C6800: 133c0504                 sethi   %hi(paConformsto), %o1
F00C6804: 153c0516                 sethi   %hi(stru_F0145938), %o2
F00C6808: d2026018                 ld      [%o1+%lo(paConformsto)], %o1! SEL
F00C680C: 4000ac19                 call    _objc_msgSend
F00C6810: 9412a138                 bset    %lo(stru_F0145938), %o2
F00C6814: 912a2018                 sll     %o0, 24, %o0
F00C6818: 80a22000                 cmp     %o0, 0
F00C681C: 32800014                 bne,a   loc_F00C686C
F00C6820: d0062118                 ld      [%i0+0x118], %o0
F00C6824: 113c0504                 sethi   %hi(paName), %o0
F00C6828: e2022008                 ld      [%o0+%lo(paName)], %l1
F00C682C: 213c03eaa0142360         set     aWarningSClassS, %l0! "Warning: %s, class %s, does not conform"...
F00C6834: 90100018                 mov     %i0, %o0! id
F00C6838: 4000ac0e                 call    _objc_msgSend
F00C683C: 92100011                 mov     %l1, %o1! SEL
F00C6840: a4100008                 mov     %o0, %l2
F00C6844: 90100018                 mov     %i0, %o0! id
F00C6848: 4000ac0a                 call    _objc_msgSend
F00C684C: 92100013                 mov     %l3, %o1! SEL
F00C6850: 4000ac08                 call    _objc_msgSend
F00C6854: 92100011                 mov     %l1, %o1
F00C6858: 94100008                 mov     %o0, %o2
F00C685C: 90100010                 mov     %l0, %o0
F00C6860: 7ffffe25                 call    _IOLog
F00C6864: 92100012                 mov     %l2, %o1
F00C6868: 30800005                 ba,a    locret_F00C687C
F00C686C: d2522022                 ldsh    [%o0+0x22], %o1
F00C6870: d4522020                 ldsh    [%o0+0x20], %o2
F00C6874: 400006ac                 call    _volCheckRegister
F00C6878: 90100018                 mov     %i0, %o0
F00C687C: 81c7e008                 ret
F00C6880: 91e80014                 restore %g0, %l4, %o0
