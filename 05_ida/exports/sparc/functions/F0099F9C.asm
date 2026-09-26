F0099F9C: 9de3bf98                 save    %sp, -0x68, %sp
F0099FA0: 113c045c                 sethi   %hi(aItSSafeToTurnO), %o0! "It's safe to turn off the computer.\n"
F0099FA4: 40000009                 call    sub_F0099FC8
F0099FA8: 90122140                 bset    %lo(aItSSafeToTurnO), %o0! "It's safe to turn off the computer.\n"
F0099FAC: 40008b63                 call    _kmDisableAnimation
F0099FB0: 01000000                 nop
F0099FB4: 113c04d1                 sethi   %hi(dword_F013476C), %o0
F0099FB8: 400053c3                 call    _prom_enter_mon
F0099FBC: c022236c                 clr     [%o0+%lo(dword_F013476C)]
F0099FC0: 81c7e008                 ret
F0099FC4: 81e80000                 restore
