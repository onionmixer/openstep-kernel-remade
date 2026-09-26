F00D1F40: 9de3bf90                 save    %sp, -0x70, %sp
F00D1F44: 113c0506                 sethi   %hi(paNxlock), %o0
F00D1F48: e20222a0                 ld      [%o0+%lo(paNxlock)], %l1
F00D1F4C: 113c0504                 sethi   %hi(paNew), %o0
F00D1F50: e0022238                 ld      [%o0+%lo(paNew)], %l0
F00D1F54: 90100011                 mov     %l1, %o0! id
F00D1F58: 40007e46                 call    _objc_msgSend
F00D1F5C: 92100010                 mov     %l0, %o1! SEL
F00D1F60: d0262110                 st      %o0, [%i0+0x110]
F00D1F64: 90100011                 mov     %l1, %o0! id
F00D1F68: 40007e42                 call    _objc_msgSend
F00D1F6C: 92100010                 mov     %l0, %o1! SEL
F00D1F70: d0262170                 st      %o0, [%i0+0x170]
F00D1F74: 90100011                 mov     %l1, %o0! id
F00D1F78: 40007e3e                 call    _objc_msgSend
F00D1F7C: 92100010                 mov     %l0, %o1
F00D1F80: 7ffe54cc                 call    _task_self
F00D1F84: d0262214                 st      %o0, [%i0+0x214]
F00D1F88: 400086f6                 call    _port_allocate_EXTERNAL
F00D1F8C: 92062134                 add     %i0, 0x134, %o1
F00D1F90: 80a22000                 cmp     %o0, 0
F00D1F94: 3280005b                 bne,a   locret_F00D2100
F00D1F98: b0102000                 mov     0, %i0
F00D1F9C: 7ffe54c5                 call    _task_self
F00D1FA0: 01000000                 nop
F00D1FA4: 400086ef                 call    _port_allocate_EXTERNAL
F00D1FA8: 92062138                 add     %i0, 0x138, %o1
F00D1FAC: 80a22000                 cmp     %o0, 0
F00D1FB0: 32800054                 bne,a   locret_F00D2100
F00D1FB4: b0102000                 mov     0, %i0
F00D1FB8: 7ffe54be                 call    _task_self
F00D1FBC: 01000000                 nop
F00D1FC0: 400086e8                 call    _port_allocate_EXTERNAL
F00D1FC4: 9206213c                 add     %i0, 0x13C, %o1
F00D1FC8: 80a22000                 cmp     %o0, 0
F00D1FCC: 3280004d                 bne,a   locret_F00D2100
F00D1FD0: b0102000                 mov     0, %i0
F00D1FD4: 7fffe0b0                 call    _IOGetKernPort
F00D1FD8: d0062134                 ld      [%i0+0x134], %o0
F00D1FDC: 213c043e                 sethi   %hi(_ev_port_list), %l0
F00D1FE0: d0242290                 st      %o0, [%l0+%lo(_ev_port_list)]
F00D1FE4: d0062138                 ld      [%i0+0x138], %o0
F00D1FE8: 7fffe0ab                 call    _IOGetKernPort
F00D1FEC: a0142290                 bset    %lo(_ev_port_list), %l0
F00D1FF0: d0242004                 st      %o0, [%l0+4]
F00D1FF4: 7fffe0a8                 call    _IOGetKernPort
F00D1FF8: d006213c                 ld      [%i0+0x13C], %o0
F00D1FFC: 7ffe54ad                 call    _task_self
F00D2000: d0262140                 st      %o0, [%i0+0x140]
F00D2004: 4000879c                 call    _port_set_allocate_EXTERNAL
F00D2008: 92062148                 add     %i0, 0x148, %o1
F00D200C: 80a22000                 cmp     %o0, 0
F00D2010: 3280003c                 bne,a   locret_F00D2100
F00D2014: b0102000                 mov     0, %i0
F00D2018: 7ffe54a6                 call    _task_self
F00D201C: 01000000                 nop
F00D2020: d2062148                 ld      [%i0+0x148], %o1
F00D2024: 40008751                 call    _port_set_add_EXTERNAL
F00D2028: d4062134                 ld      [%i0+0x134], %o2
F00D202C: 80a22000                 cmp     %o0, 0
F00D2030: 32800034                 bne,a   locret_F00D2100
F00D2034: b0102000                 mov     0, %i0
F00D2038: 7ffe549e                 call    _task_self
F00D203C: 01000000                 nop
F00D2040: d2062148                 ld      [%i0+0x148], %o1
F00D2044: 40008749                 call    _port_set_add_EXTERNAL
F00D2048: d4062138                 ld      [%i0+0x138], %o2
F00D204C: 80a22000                 cmp     %o0, 0
F00D2050: 3280002c                 bne,a   locret_F00D2100
F00D2054: b0102000                 mov     0, %i0
F00D2058: 7ffe5496                 call    _task_self
F00D205C: 01000000                 nop
F00D2060: d2062148                 ld      [%i0+0x148], %o1
F00D2064: 40008741                 call    _port_set_add_EXTERNAL
F00D2068: d406213c                 ld      [%i0+0x13C], %o2
F00D206C: 80a22000                 cmp     %o0, 0
F00D2070: 02800004                 be      loc_F00D2080
F00D2074: 90062174                 add     %i0, 0x174, %o0
F00D2078: 10800022                 ba      locret_F00D2100
F00D207C: b0102000                 mov     0, %i0
F00D2080: d0262178                 st      %o0, [%i0+0x178]
F00D2084: d0262174                 st      %o0, [%i0+0x174]
F00D2088: f027bff0                 st      %i0, [%fp+var_10]
F00D208C: 133c0508                 sethi   %hi(stru_F01421DC.super_class), %o1
F00D2090: d40261e0                 ld      [%o1+%lo(stru_F01421DC.super_class)], %o2
F00D2094: 9007bff0                 add     %fp, var_10, %o0! objc_super *
F00D2098: 133c0504                 sethi   %hi(paInit), %o1
F00D209C: d202602c                 ld      [%o1+%lo(paInit)], %o1! SEL
F00D20A0: 40007e37                 call    _objc_msgSendSuper
F00D20A4: d427bff4                 st      %o2, [%fp+var_C]
F00D20A8: 90102064                 mov     0x64, %o0 ! 'd'
F00D20AC: d03621a8                 sth     %o0, [%i0+0x1A8]
F00D20B0: d03621aa                 sth     %o0, [%i0+0x1AA]
F00D20B4: 113c03479012201c         set     sub_F00D1C1C, %o0
F00D20BC: 7fffe001                 call    _IOForkThread
F00D20C0: 92100018                 mov     %i0, %o1
F00D20C4: a0100008                 mov     %o0, %l0
F00D20C8: 7fffe038                 call    _IOSetThreadPolicy
F00D20CC: 92102002                 mov     2, %o1
F00D20D0: 90100010                 mov     %l0, %o0
F00D20D4: 7fffe026                 call    _IOSetThreadPriority
F00D20D8: 9210201c                 mov     0x1C, %o1
F00D20DC: d04e2108                 ldsb    [%i0+0x108], %o0
F00D20E0: 80a22000                 cmp     %o0, 0
F00D20E4: 12800007                 bne     locret_F00D2100
F00D20E8: 113c0504                 sethi   %hi(paRegisterdevice), %o0! id
F00D20EC: d202225c                 ld      [%o0+%lo(paRegisterdevice)], %o1! SEL
F00D20F0: 40007de0                 call    _objc_msgSend
F00D20F4: 90100018                 mov     %i0, %o0
F00D20F8: 90102001                 mov     1, %o0
F00D20FC: d02e2108                 stb     %o0, [%i0+0x108]
F00D2100: 81c7e008                 ret
F00D2104: 81e80000                 restore
