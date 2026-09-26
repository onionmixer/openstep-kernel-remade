F00D3034: 9de3bf90                 save    %sp, -0x70, %sp
F00D3038: 9010001a                 mov     %i2, %o0
F00D303C: 92102001                 mov     1, %o1
F00D3040: 7ffe4b25                 call    _msg_send
F00D3044: 94102000                 mov     0, %o2
F00D3048: a2920000                 orcc    %o0, %g0, %l1
F00D304C: 0280000c                 be      loc_F00D307C
F00D3050: a410001a                 mov     %i2, %l2
F00D3054: 90100018                 mov     %i0, %o0! id
F00D3058: 133c0504                 sethi   %hi(paName), %o1
F00D305C: d2026008                 ld      [%o1+%lo(paName)], %o1! SEL
F00D3060: 213c03ef                 sethi   %hi(aSPerformspecia), %l0! "%s: _performSpecialKeyMsg msg_send retu"...
F00D3064: 40007a03                 call    _objc_msgSend
F00D3068: a01421e8                 bset    %lo(aSPerformspecia), %l0! "%s: _performSpecialKeyMsg msg_send retu"...
F00D306C: 92100008                 mov     %o0, %o1
F00D3070: 90100010                 mov     %l0, %o0
F00D3074: 7fffcc20                 call    _IOLog
F00D3078: 94100011                 mov     %l1, %o2
F00D307C: 80a47f9a                 cmp     %l1, -0x66
F00D3080: 3280000a                 bne,a   loc_F00D30A8
F00D3084: 90100012                 mov     %l2, %o0
F00D3088: 113c0505                 sethi   %hi(paSetspecialkeyp), %o0! id
F00D308C: d20222f8                 ld      [%o0+%lo(paSetspecialkeyp)], %o1! SEL
F00D3090: d4062134                 ld      [%i0+0x134], %o2
F00D3094: 98102000                 mov     0, %o4
F00D3098: d606a01c                 ld      [%i2+0x1C], %o3
F00D309C: 400079f5                 call    _objc_msgSend
F00D30A0: 90100018                 mov     %i0, %o0
F00D30A4: 90100012                 mov     %l2, %o0
F00D30A8: 7fffcba7                 call    _IOFree
F00D30AC: 92102038                 mov     0x38, %o1 ! '8'
F00D30B0: 81c7e008                 ret
F00D30B4: 81e80000                 restore
