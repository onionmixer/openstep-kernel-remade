F00DBBD8: 9de3bf90                 save    %sp, -0x70, %sp
F00DBBDC: d0062038                 ld      [%i0+0x38], %o0
F00DBBE0: 80a22000                 cmp     %o0, 0
F00DBBE4: 22800007                 be,a    loc_F00DBC00
F00DBBE8: d006203c                 ld      [%i0+0x3C], %o0
F00DBBEC: 7ffe2db1                 call    _task_self
F00DBBF0: 01000000                 nop
F00DBBF4: 4000601e                 call    _port_deallocate_EXTERNAL
F00DBBF8: d2062038                 ld      [%i0+0x38], %o1
F00DBBFC: d006203c                 ld      [%i0+0x3C], %o0
F00DBC00: 80a22000                 cmp     %o0, 0
F00DBC04: 22800007                 be,a    loc_F00DBC20
F00DBC08: d0062040                 ld      [%i0+0x40], %o0
F00DBC0C: 7ffe2da9                 call    _task_self
F00DBC10: 01000000                 nop
F00DBC14: 40006016                 call    _port_deallocate_EXTERNAL
F00DBC18: d206203c                 ld      [%i0+0x3C], %o1
F00DBC1C: d0062040                 ld      [%i0+0x40], %o0
F00DBC20: 80a22000                 cmp     %o0, 0
F00DBC24: 22800007                 be,a    loc_F00DBC40
F00DBC28: 113c0505                 sethi   -0xFEBEC00, %o0
F00DBC2C: 7ffe2da1                 call    _task_self
F00DBC30: 01000000                 nop
F00DBC34: 4000600e                 call    _port_deallocate_EXTERNAL
F00DBC38: d2062040                 ld      [%i0+0x40], %o1
F00DBC3C: 113c0505                 sethi   -0xFEBEC00, %o0! id
F00DBC40: d2022048                 ld      [%o0+0x48], %o1! SEL
F00DBC44: 4000570b                 call    _objc_msgSend
F00DBC48: 90100018                 mov     %i0, %o0
F00DBC4C: 7ffe2d99                 call    _task_self
F00DBC50: 01000000                 nop
F00DBC54: 40006006                 call    _port_deallocate_EXTERNAL
F00DBC58: d206200c                 ld      [%i0+0xC], %o1
F00DBC5C: 80a22000                 cmp     %o0, 0
F00DBC60: 02800006                 be      loc_F00DBC78
F00DBC64: 113c03f1                 sethi   %hi(aAudioStreamPor), %o0! "Audio: stream port_deallocate: %s\n"
F00DBC68: 901220f8                 bset    %lo(aAudioStreamPor), %o0! "Audio: stream port_deallocate: %s\n"
F00DBC6C: 133c03f1                 sethi   %hi(aMachErr), %o1! "MACH ERR"
F00DBC70: 7fffa921                 call    _IOLog
F00DBC74: 92126020                 bset    %lo(aMachErr), %o1! "MACH ERR"
F00DBC78: 113c0503                 sethi   %hi(paFree), %o0
F00DBC7C: e00223fc                 ld      [%o0+%lo(paFree)], %l0
F00DBC80: d0062028                 ld      [%i0+0x28], %o0! id
F00DBC84: 400056fb                 call    _objc_msgSend
F00DBC88: 92100010                 mov     %l0, %o1
F00DBC8C: d0062034                 ld      [%i0+0x34], %o0
F00DBC90: 80a22000                 cmp     %o0, 0
F00DBC94: 22800005                 be,a    loc_F00DBCA8
F00DBC98: f027bff0                 st      %i0, [%fp+var_10]
F00DBC9C: 7fffa8aa                 call    _IOFree
F00DBCA0: 13000008                 sethi   0x2000, %o1
F00DBCA4: f027bff0                 st      %i0, [%fp+var_10]
F00DBCA8: 133c0508                 sethi   %hi(stru_F014227C.ext), %o1
F00DBCAC: d40262a8                 ld      [%o1+%lo(stru_F014227C.ext)], %o2
F00DBCB0: 9007bff0                 add     %fp, var_10, %o0! objc_super *
F00DBCB4: 92100010                 mov     %l0, %o1! SEL
F00DBCB8: 40005731                 call    _objc_msgSendSuper
F00DBCBC: d427bff4                 st      %o2, [%fp+var_C]
F00DBCC0: 81c7e008                 ret
F00DBCC4: 91e80008                 restore %g0, %o0, %o0
