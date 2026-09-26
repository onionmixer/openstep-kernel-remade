F00C1950: 9de3bf90                 save    %sp, -0x70, %sp
F00C1954: c02e212c                 clrb    [%i0+0x12C]
F00C1958: c02e212d                 clrb    [%i0+0x12D]
F00C195C: c0262138                 clr     [%i0+0x138]
F00C1960: c0262140                 clr     [%i0+0x140]
F00C1964: 113c04fd                 sethi   %hi(_type5kbd_owner), %o0
F00C1968: c0222258                 clr     [%o0+%lo(_type5kbd_owner)]
F00C196C: 113c0506                 sethi   %hi(paNxlock), %o0
F00C1970: d00222a0                 ld      [%o0+%lo(paNxlock)], %o0! id
F00C1974: 133c0504                 sethi   %hi(paNew), %o1
F00C1978: d2026238                 ld      [%o1+%lo(paNew)], %o1! SEL
F00C197C: 4000bfbd                 call    _objc_msgSend
F00C1980: c0262144                 clr     [%i0+0x144]
F00C1984: d0262148                 st      %o0, [%i0+0x148]
F00C1988: 113c0504                 sethi   %hi(paDevicedescript_1), %o0! id
F00C198C: d2022158                 ld      [%o0+%lo(paDevicedescript_1)], %o1! SEL
F00C1990: 4000bfb8                 call    _objc_msgSend
F00C1994: 90100018                 mov     %i0, %o0! id
F00C1998: 133c0504                 sethi   %hi(paConfigtable_0), %o1! SEL
F00C199C: 4000bfb5                 call    _objc_msgSend
F00C19A0: d2026310                 ld      [%o1+%lo(paConfigtable_0)], %o1
F00C19A4: a0920000                 orcc    %o0, %g0, %l0
F00C19A8: 12800007                 bne     loc_F00C19C4
F00C19AC: 90100010                 mov     %l0, %o0
F00C19B0: 113c0483                 sethi   %hi(aType5keyboardK), %o0! "TYPE5Keyboard kbdInit: no configuration"...
F00C19B4: 400011d0                 call    _IOLog
F00C19B8: 90122320                 bset    %lo(aType5keyboardK), %o0! "TYPE5Keyboard kbdInit: no configuration"...
F00C19BC: 1080004b                 ba      locret_F00C1AE8
F00C19C0: b0102000                 mov     0, %i0
F00C19C4: 133c0504                 sethi   %hi(paValueforstring), %o1
F00C19C8: d20260e8                 ld      [%o1+%lo(paValueforstring)], %o1! SEL
F00C19CC: 153c0483                 sethi   %hi(aInterface), %o2! "Interface"
F00C19D0: 4000bfa8                 call    _objc_msgSend
F00C19D4: 9412a350                 bset    %lo(aInterface), %o2! "Interface"
F00C19D8: 80a22000                 cmp     %o0, 0
F00C19DC: 12800007                 bne     loc_F00C19F8
F00C19E0: 01000000                 nop
F00C19E4: 113c0483                 sethi   %hi(aType5keyboardK_0), %o0! "TYPE5Keyboard kbdInit: no Interface ID;"...
F00C19E8: 400011c3                 call    _IOLog
F00C19EC: 90122360                 bset    %lo(aType5keyboardK_0), %o0! "TYPE5Keyboard kbdInit: no Interface ID;"...
F00C19F0: 10800004                 ba      loc_F00C1A00
F00C19F4: 90102007                 mov     7, %o0
F00C19F8: 7ffffc0e                 call    _PCPatoi
F00C19FC: 01000000                 nop
F00C1A00: d0262130                 st      %o0, [%i0+0x130]
F00C1A04: 90100010                 mov     %l0, %o0! id
F00C1A08: 133c0504                 sethi   %hi(paValueforstring), %o1
F00C1A0C: d20260e8                 ld      [%o1+%lo(paValueforstring)], %o1! SEL
F00C1A10: 153c0483                 sethi   %hi(aHandlerId), %o2! "Handler ID"
F00C1A14: 4000bf97                 call    _objc_msgSend
F00C1A18: 9412a398                 bset    %lo(aHandlerId), %o2! "Handler ID"
F00C1A1C: 80a22000                 cmp     %o0, 0
F00C1A20: 12800007                 bne     loc_F00C1A3C
F00C1A24: 01000000                 nop
F00C1A28: 113c0483                 sethi   %hi(aType5keyboardK_1), %o0! "TYPE5Keyboard kbdInit: no Handler ID; u"...
F00C1A2C: 400011b2                 call    _IOLog
F00C1A30: 901223a8                 bset    %lo(aType5keyboardK_1), %o0! "TYPE5Keyboard kbdInit: no Handler ID; u"...
F00C1A34: 10800005                 ba      loc_F00C1A48
F00C1A38: c0262134                 clr     [%i0+0x134]
F00C1A3C: 7ffffbfd                 call    _PCPatoi
F00C1A40: 01000000                 nop
F00C1A44: d0262134                 st      %o0, [%i0+0x134]
F00C1A48: 113c0504                 sethi   %hi(paEnableallinter), %o0! id
F00C1A4C: d2022314                 ld      [%o0+%lo(paEnableallinter)], %o1! SEL
F00C1A50: 4000bf88                 call    _objc_msgSend
F00C1A54: 90100018                 mov     %i0, %o0
F00C1A58: 7ffe9616                 call    _task_self
F00C1A5C: 01000000                 nop
F00C1A60: 4000c905                 call    _port_set_allocate_EXTERNAL
F00C1A64: 92062128                 add     %i0, 0x128, %o1
F00C1A68: 92920000                 orcc    %o0, %g0, %o1
F00C1A6C: 02800007                 be      loc_F00C1A88
F00C1A70: 01000000                 nop
F00C1A74: 113c0483                 sethi   %hi(aKbdinitPortSet), %o0! "kbdInit: port_set_allocate returned %d"...
F00C1A78: 4000119f                 call    _IOLog
F00C1A7C: 901223e0                 bset    %lo(aKbdinitPortSet), %o0! "kbdInit: port_set_allocate returned %d"...
F00C1A80: 1080001a                 ba      locret_F00C1AE8
F00C1A84: b0102000                 mov     0, %i0
F00C1A88: 7ffe960a                 call    _task_self
F00C1A8C: 01000000                 nop
F00C1A90: 133c0504                 sethi   %hi(paInterruptport_0), %o1
F00C1A94: d2026308                 ld      [%o1+%lo(paInterruptport_0)], %o1! SEL
F00C1A98: a0100008                 mov     %o0, %l0
F00C1A9C: e2062128                 ld      [%i0+0x128], %l1
F00C1AA0: 4000bf74                 call    _objc_msgSend
F00C1AA4: 90100018                 mov     %i0, %o0
F00C1AA8: 94100008                 mov     %o0, %o2
F00C1AAC: 90100010                 mov     %l0, %o0
F00C1AB0: 4000c8ae                 call    _port_set_add_EXTERNAL
F00C1AB4: 92100011                 mov     %l1, %o1
F00C1AB8: 92920000                 orcc    %o0, %g0, %o1
F00C1ABC: 12800008                 bne     loc_F00C1ADC
F00C1AC0: 113c0484                 sethi   -0xFEDF000, %o0
F00C1AC4: 113c03069012206c         set     sub_F00C186C, %o0
F00C1ACC: 4000217d                 call    _IOForkThread
F00C1AD0: 92100018                 mov     %i0, %o1
F00C1AD4: 10800005                 ba      locret_F00C1AE8
F00C1AD8: b0102001                 mov     1, %i0
F00C1ADC: 40001186                 call    _IOLog
F00C1AE0: 90122008                 bset    8, %o0
F00C1AE4: b0103fff                 mov     -1, %i0
F00C1AE8: 81c7e008                 ret
F00C1AEC: 81e80000                 restore
