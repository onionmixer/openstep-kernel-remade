F00C7D14: 9de3bf90                 save    %sp, -0x70, %sp
F00C7D18: 113c0506                 sethi   %hi(paFreepartitions), %o0! id
F00C7D1C: d2022154                 ld      [%o0+%lo(paFreepartitions)], %o1! SEL
F00C7D20: 4000a6d4                 call    _objc_msgSend
F00C7D24: 90100018                 mov     %i0, %o0
F00C7D28: c02e21a8                 clrb    [%i0+0x1A8]
F00C7D2C: f027bff0                 st      %i0, [%fp+var_10]
F00C7D30: 9007bff0                 add     %fp, var_10, %o0! objc_super *
F00C7D34: 133c0507                 sethi   %hi(stru_F0141F0C.ext), %o1
F00C7D38: d4026338                 ld      [%o1+%lo(stru_F0141F0C.ext)], %o2
F00C7D3C: b52ea018                 sll     %i2, 24, %i2
F00C7D40: 133c0506                 sethi   %hi(paSetformattedin), %o1
F00C7D44: d427bff4                 st      %o2, [%fp+var_C]
F00C7D48: d20261ac                 ld      [%o1+%lo(paSetformattedin)], %o1! SEL
F00C7D4C: 4000a70c                 call    _objc_msgSendSuper
F00C7D50: 953ea018                 sra     %i2, 24, %o2
F00C7D54: 81c7e008                 ret
F00C7D58: 81e80000                 restore
