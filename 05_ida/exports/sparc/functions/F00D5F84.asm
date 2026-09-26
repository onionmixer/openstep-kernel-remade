F00D5F84: 9de3bf90                 save    %sp, -0x70, %sp
F00D5F88: f027bff0                 st      %i0, [%fp+var_10]
F00D5F8C: 133c0508                 sethi   %hi(stru_F014222C.super_class), %o1
F00D5F90: d4026230                 ld      [%o1+%lo(stru_F014222C.super_class)], %o2
F00D5F94: 9007bff0                 add     %fp, var_10, %o0! objc_super *
F00D5F98: 133c0504                 sethi   %hi(paInit), %o1
F00D5F9C: d202602c                 ld      [%o1+%lo(paInit)], %o1! SEL
F00D5FA0: 40006e77                 call    _objc_msgSendSuper
F00D5FA4: d427bff4                 st      %o2, [%fp+var_C]
F00D5FA8: d00624f4                 ld      [%i0+0x4F4], %o0
F00D5FAC: 80a22000                 cmp     %o0, 0
F00D5FB0: 12800009                 bne     loc_F00D5FD4
F00D5FB4: 90100018                 mov     %i0, %o0
F00D5FB8: 113c0506                 sethi   %hi(paNxlock), %o0
F00D5FBC: d00222a0                 ld      [%o0+%lo(paNxlock)], %o0! id
F00D5FC0: 133c0504                 sethi   %hi(paNew), %o1! SEL
F00D5FC4: 40006e2b                 call    _objc_msgSend
F00D5FC8: d2026238                 ld      [%o1+%lo(paNew)], %o1
F00D5FCC: d02624f4                 st      %o0, [%i0+0x4F4]
F00D5FD0: 90100018                 mov     %i0, %o0! id
F00D5FD4: 133c0505                 sethi   %hi(paSetkeymappingL), %o1
F00D5FD8: d2026264                 ld      [%o1+%lo(paSetkeymappingL)], %o1! SEL
F00D5FDC: 992f2018                 sll     %i4, 24, %o4
F00D5FE0: 9410001a                 mov     %i2, %o2
F00D5FE4: 9610001b                 mov     %i3, %o3
F00D5FE8: 40006e22                 call    _objc_msgSend
F00D5FEC: 993b2018                 sra     %o4, 24, %o4
F00D5FF0: 80a22000                 cmp     %o0, 0
F00D5FF4: 12800006                 bne     locret_F00D600C
F00D5FF8: 113c0503                 sethi   %hi(paFree), %o0! id
F00D5FFC: d20223fc                 ld      [%o0+%lo(paFree)], %o1! SEL
F00D6000: 40006e1c                 call    _objc_msgSend
F00D6004: 90100018                 mov     %i0, %o0
F00D6008: b0100008                 mov     %o0, %i0
F00D600C: 81c7e008                 ret
F00D6010: 81e80000                 restore
