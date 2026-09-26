F00BF4A0: 9de3bf90                 save    %sp, -0x70, %sp
F00BF4A4: 113c0482901222f0         set     aType5keyboard0_0, %o0! "TYPE5Keyboard0"
F00BF4AC: 4000145d                 call    _IOGetObjectForDeviceName
F00BF4B0: 9206212c                 add     %i0, 0x12C, %o1
F00BF4B4: 94920000                 orcc    %o0, %g0, %o2
F00BF4B8: 0280000b                 be      locret_F00BF4E4
F00BF4BC: 90100018                 mov     %i0, %o0! id
F00BF4C0: 133c0504                 sethi   %hi(paStringfromretu), %o1
F00BF4C4: d2026260                 ld      [%o1+%lo(paStringfromretu)], %o1! SEL
F00BF4C8: 213c0482                 sethi   %hi(aInitkeyboardCa), %l0! "initKeyboard: Can't find TYPE5Keyboard0"...
F00BF4CC: 4000c8e9                 call    _objc_msgSend
F00BF4D0: a0142300                 bset    %lo(aInitkeyboardCa), %l0! "initKeyboard: Can't find TYPE5Keyboard0"...
F00BF4D4: 92100008                 mov     %o0, %o1
F00BF4D8: 40001b07                 call    _IOLog
F00BF4DC: 90100010                 mov     %l0, %o0
F00BF4E0: b0102000                 mov     0, %i0
F00BF4E4: 81c7e008                 ret
F00BF4E8: 81e80000                 restore
