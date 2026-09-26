F00D73BC: 9de3bf58                 save    %sp, -0xA8, %sp
F00D73C0: 7ffe3fbc                 call    _task_self
F00D73C4: 01000000                 nop
F00D73C8: 400071e6                 call    _port_allocate_EXTERNAL
F00D73CC: 9207bfbc                 add     %fp, var_44, %o1
F00D73D0: 80a22000                 cmp     %o0, 0
F00D73D4: 02800006                 be      loc_F00D73EC
F00D73D8: e607bfbc                 ld      [%fp+var_44], %l3
F00D73DC: 113c03f0                 sethi   %hi(aAudioPortAlloc), %o0! "Audio: port_allocate"
F00D73E0: 7fffbb45                 call    _IOLog
F00D73E4: 90122100                 bset    %lo(aAudioPortAlloc), %o0! "Audio: port_allocate"
F00D73E8: e607bfbc                 ld      [%fp+var_44], %l3
F00D73EC: 113c03f0                 sethi   %hi(aEventdriver), %o0! "EventDriver"
F00D73F0: 40006a5b                 call    _objc_lookUpClass
F00D73F4: 90122318                 bset    %lo(aEventdriver), %o0! "EventDriver"
F00D73F8: a0920000                 orcc    %o0, %g0, %l0
F00D73FC: 32800008                 bne,a   loc_F00D741C
F00D7400: 113c0505                 sethi   -0xFEBEC00, %o0
F00D7404: 113c03f0                 sethi   %hi(aAudioObjcLooku), %o0! "Audio: objc_lookUpClass failure\n"
F00D7408: 7fffbb3b                 call    _IOLog
F00D740C: 90122328                 bset    %lo(aAudioObjcLooku), %o0! "Audio: objc_lookUpClass failure\n"
F00D7410: 7fffcb83                 call    _IOExitThread
F00D7414: 01000000                 nop
F00D7418: 113c0505                 sethi   -0xFEBEC00, %o0! id
F00D741C: d2022278                 ld      [%o0+0x278], %o1! SEL
F00D7420: 40006914                 call    _objc_msgSend
F00D7424: 90100010                 mov     %l0, %o0! id
F00D7428: 133c0505                 sethi   %hi(paEvPort), %o1! SEL
F00D742C: a0100008                 mov     %o0, %l0
F00D7430: 40006910                 call    _objc_msgSend
F00D7434: d2026274                 ld      [%o1+%lo(paEvPort)], %o1
F00D7438: a4100008                 mov     %o0, %l2
F00D743C: 90100010                 mov     %l0, %o0! id
F00D7440: 94100012                 mov     %l2, %o2
F00D7444: 96102000                 mov     0, %o3
F00D7448: 133c0505                 sethi   %hi(paSetspecialkeyp), %o1! SEL
F00D744C: e20262f8                 ld      [%o1+%lo(paSetspecialkeyp)], %l1
F00D7450: 98100013                 mov     %l3, %o4
F00D7454: 40006907                 call    _objc_msgSend
F00D7458: 92100011                 mov     %l1, %o1
F00D745C: 92920000                 orcc    %o0, %g0, %o1
F00D7460: 02800006                 be      loc_F00D7478
F00D7464: 113c03f0                 sethi   %hi(aAudioSetspecia), %o0! "Audio: SetSpecialKeyPort error %d\n"
F00D7468: 7fffbb23                 call    _IOLog
F00D746C: 90122350                 bset    %lo(aAudioSetspecia), %o0! "Audio: SetSpecialKeyPort error %d\n"
F00D7470: 7fffcb6b                 call    _IOExitThread
F00D7474: 01000000                 nop
F00D7478: 90100010                 mov     %l0, %o0! id
F00D747C: 92100011                 mov     %l1, %o1! SEL
F00D7480: 94100012                 mov     %l2, %o2
F00D7484: 96102001                 mov     1, %o3
F00D7488: 400068fa                 call    _objc_msgSend
F00D748C: 98100013                 mov     %l3, %o4
F00D7490: 92920000                 orcc    %o0, %g0, %o1
F00D7494: 02800006                 be      loc_F00D74AC
F00D7498: 113c03f0                 sethi   %hi(aAudioSetspecia), %o0! "Audio: SetSpecialKeyPort error %d\n"
F00D749C: 7fffbb16                 call    _IOLog
F00D74A0: 90122350                 bset    %lo(aAudioSetspecia), %o0! "Audio: SetSpecialKeyPort error %d\n"
F00D74A4: 7fffcb5e                 call    _IOExitThread
F00D74A8: 01000000                 nop
F00D74AC: aa102038                 mov     0x38, %l5 ! '8'
F00D74B0: 293c03f0                 sethi   -0xFF04000, %l4
F00D74B4: 1114dad9a4122179         set     0x536B6579, %l2
F00D74BC: 233c03f0                 sethi   -0xFF04000, %l1
F00D74C0: 213c0505                 sethi   -0xFEBEC00, %l0
F00D74C4: e627bfcc                 st      %l3, [%fp+var_34]
F00D74C8: ea27bfc4                 st      %l5, [%fp+var_3C]
F00D74CC: 9007bfc0                 add     %fp, var_40, %o0
F00D74D0: 92102000                 mov     0, %o1
F00D74D4: 7ffe3a62                 call    _msg_receive
F00D74D8: 94102000                 mov     0, %o2
F00D74DC: 92920000                 orcc    %o0, %g0, %o1
F00D74E0: 22800007                 be,a    loc_F00D74FC
F00D74E4: d207bfd4                 ld      [%fp+var_2C], %o1
F00D74E8: 7fffbb03                 call    _IOLog
F00D74EC: 90152378                 or      %l4, 0x378, %o0
F00D74F0: 7fffcb4b                 call    _IOExitThread
F00D74F4: 01000000                 nop
F00D74F8: d207bfd4                 ld      [%fp+var_2C], %o1
F00D74FC: 80a24012                 cmp     %o1, %l2
F00D7500: 22800007                 be,a    loc_F00D751C
F00D7504: d20420b8                 ld      [%l0+0xB8], %o1
F00D7508: 7fffbafb                 call    _IOLog
F00D750C: 901463a0                 or      %l1, 0x3A0, %o0! id
F00D7510: 7fffcb43                 call    _IOExitThread
F00D7514: 01000000                 nop
F00D7518: d20420b8                 ld      [%l0+0xB8], %o1! SEL
F00D751C: d407bfdc                 ld      [%fp+var_24], %o2
F00D7520: d607bfe4                 ld      [%fp+var_1C], %o3
F00D7524: d807bfec                 ld      [%fp+var_14], %o4
F00D7528: 400068d2                 call    _objc_msgSend
F00D752C: 90100018                 mov     %i0, %o0
F00D7530: 10bfffe6                 ba      loc_F00D74C8
F00D7534: e627bfcc                 st      %l3, [%fp+var_34]
