F00268C0: 9de3bf98                 save    %sp, -0x68, %sp
F00268C4: e0062018                 ld      [%i0+0x18], %l0
F00268C8: d0062008                 ld      [%i0+8], %o0
F00268CC: 80a42000                 cmp     %l0, 0
F00268D0: 0280003b                 be      locret_F00269BC
F00268D4: b20e4008                 and     %i1, %o0, %i1
F00268D8: 80a66000                 cmp     %i1, 0
F00268DC: 02800038                 be      locret_F00269BC
F00268E0: 808e6080                 btst    0x80, %i1
F00268E4: 0280001b                 be      loc_F0026950
F00268E8: e2142004                 lduh    [%l0+4], %l1
F00268EC: 808c6008                 btst    8, %l1
F00268F0: 32800006                 bne,a   loc_F0026908
F00268F4: d0142008                 lduh    [%l0+8], %o0
F00268F8: 113c0430                 sethi   %hi(aVnoBsdUnlockSh), %o0! "vno_bsd_unlock: SHLOCK"
F00268FC: 7fffba1d                 call    _panic
F0026900: 901220d0                 bset    %lo(aVnoBsdUnlockSh), %o0! "vno_bsd_unlock: SHLOCK"
F0026904: d0142008                 lduh    [%l0+8], %o0
F0026908: 90023fff                 inc     -1, %o0
F002690C: d0342008                 sth     %o0, [%l0+8]
F0026910: 912a2010                 sll     %o0, 16, %o0
F0026914: 80a22000                 cmp     %o0, 0
F0026918: 3280000c                 bne,a   loc_F0026948
F002691C: d0062008                 ld      [%i0+8], %o0
F0026920: 808c6010                 btst    0x10, %l1
F0026924: d2142004                 lduh    [%l0+4], %o1
F0026928: 1100003f901223f7         set     0xFFF7, %o0
F0026930: 920a4008                 and     %o1, %o0, %o1
F0026934: 02800004                 be      loc_F0026944
F0026938: d2342004                 sth     %o1, [%l0+4]
F002693C: 7fffb12b                 call    _wakeup
F0026940: 90042008                 add     %l0, 8, %o0
F0026944: d0062008                 ld      [%i0+8], %o0
F0026948: 900a3f7f                 and     %o0, -0x81, %o0
F002694C: d0262008                 st      %o0, [%i0+8]
F0026950: 808e6100                 btst    0x100, %i1
F0026954: 0280001a                 be      locret_F00269BC
F0026958: 808c6004                 btst    4, %l1
F002695C: 32800006                 bne,a   loc_F0026974
F0026960: d014200a                 lduh    [%l0+0xA], %o0
F0026964: 113c0430                 sethi   %hi(aVnoBsdUnlockEx), %o0! "vno_bsd_unlock: EXLOCK"
F0026968: 7fffba02                 call    _panic
F002696C: 901220e8                 bset    %lo(aVnoBsdUnlockEx), %o0! "vno_bsd_unlock: EXLOCK"
F0026970: d014200a                 lduh    [%l0+0xA], %o0
F0026974: 90023fff                 inc     -1, %o0
F0026978: d034200a                 sth     %o0, [%l0+0xA]
F002697C: 912a2010                 sll     %o0, 16, %o0
F0026980: 80a22000                 cmp     %o0, 0
F0026984: 3280000c                 bne,a   loc_F00269B4
F0026988: d0062008                 ld      [%i0+8], %o0
F002698C: 808c6010                 btst    0x10, %l1
F0026990: d2142004                 lduh    [%l0+4], %o1
F0026994: 1100003f901223eb         set     0xFFEB, %o0
F002699C: 920a4008                 and     %o1, %o0, %o1
F00269A0: 02800004                 be      loc_F00269B0
F00269A4: d2342004                 sth     %o1, [%l0+4]
F00269A8: 7fffb110                 call    _wakeup
F00269AC: 9004200a                 add     %l0, 0xA, %o0
F00269B0: d0062008                 ld      [%i0+8], %o0
F00269B4: 900a3eff                 and     %o0, -0x101, %o0
F00269B8: d0262008                 st      %o0, [%i0+8]
F00269BC: 81c7e008                 ret
F00269C0: 81e80000                 restore
