F00D0348: 9de3bf78                 save    %sp, -0x88, %sp
F00D034C: f6262128                 st      %i3, [%i0+0x128]
F00D0350: c0262118                 clr     [%i0+0x118]
F00D0354: c0262120                 clr     [%i0+0x120]
F00D0358: 113c0506                 sethi   %hi(paNxlock), %o0
F00D035C: d00222a0                 ld      [%o0+%lo(paNxlock)], %o0! id
F00D0360: 133c0504                 sethi   %hi(paNew), %o1
F00D0364: d2026238                 ld      [%o1+%lo(paNew)], %o1! SEL
F00D0368: 191fffff                 sethi   0x7FFFFC00, %o4
F00D036C: d606211c                 ld      [%i0+0x11C], %o3
F00D0370: 981323ff                 bset    0x3FF, %o4
F00D0374: d4062124                 ld      [%i0+0x124], %o2
F00D0378: 960ac00c                 and     %o3, %o4, %o3
F00D037C: d626211c                 st      %o3, [%i0+0x11C]
F00D0380: 940a800c                 and     %o2, %o4, %o2
F00D0384: 4000853b                 call    _objc_msgSend
F00D0388: d4262124                 st      %o2, [%i0+0x124]
F00D038C: d026212c                 st      %o0, [%i0+0x12C]
F00D0390: c0262130                 clr     [%i0+0x130]
F00D0394: a007bfd8                 add     %fp, var_28, %l0
F00D0398: 90100010                 mov     %l0, %o0! char *
F00D039C: 133c03ed92126278         set     aSgD, %o1! "sg%d"
F00D03A4: 7ffd10f1                 call    _sprintf
F00D03A8: 9410001a                 mov     %i2, %o2
F00D03AC: 90100018                 mov     %i0, %o0! id
F00D03B0: 133c0504                 sethi   %hi(paSetname), %o1
F00D03B4: d202624c                 ld      [%o1+%lo(paSetname)], %o1! SEL
F00D03B8: 4000852e                 call    _objc_msgSend
F00D03BC: 94100010                 mov     %l0, %o2
F00D03C0: 90100018                 mov     %i0, %o0! id
F00D03C4: 133c0504                 sethi   %hi(paSetdevicekind), %o1
F00D03C8: 153c03ed                 sethi   %hi(aScsigeneric), %o2! "SCSIGeneric"
F00D03CC: d2026250                 ld      [%o1+%lo(paSetdevicekind)], %o1! SEL
F00D03D0: 40008528                 call    _objc_msgSend
F00D03D4: 9412a280                 bset    %lo(aScsigeneric), %o2! "SCSIGeneric"
F00D03D8: 113c0504                 sethi   %hi(paName), %o0
F00D03DC: d2022008                 ld      [%o0+%lo(paName)], %o1! SEL
F00D03E0: 113c0504                 sethi   %hi(paSetlocation), %o0! id
F00D03E4: e0022254                 ld      [%o0+%lo(paSetlocation)], %l0
F00D03E8: 40008522                 call    _objc_msgSend
F00D03EC: 9010001b                 mov     %i3, %o0
F00D03F0: 94100008                 mov     %o0, %o2
F00D03F4: 90100018                 mov     %i0, %o0! id
F00D03F8: 4000851e                 call    _objc_msgSend
F00D03FC: 92100010                 mov     %l0, %o1
F00D0400: 90100018                 mov     %i0, %o0! id
F00D0404: 133c0504                 sethi   %hi(paSetunit), %o1
F00D0408: d2026248                 ld      [%o1+%lo(paSetunit)], %o1! SEL
F00D040C: 40008519                 call    _objc_msgSend
F00D0410: 9410001a                 mov     %i2, %o2
F00D0414: 113c0504                 sethi   %hi(paRegisterdevice), %o0! id
F00D0418: d202225c                 ld      [%o0+%lo(paRegisterdevice)], %o1! SEL
F00D041C: 40008515                 call    _objc_msgSend
F00D0420: 90100018                 mov     %i0, %o0
F00D0424: 81c7e008                 ret
F00D0428: 91e82000                 restore %g0, 0, %o0
