F00A9178: 9de3bf98                 save    %sp, -0x68, %sp! int
F00A917C: 113c04cf                 sethi   %hi(dword_F0133DDC), %o0
F00A9180: d00221dc                 ld      [%o0+%lo(dword_F0133DDC)], %o0
F00A9184: d0022024                 ld      [%o0+0x24], %o0
F00A9188: d2020000                 ld      [%o0], %o1
F00A918C: 80a26000                 cmp     %o1, 0
F00A9190: 02800006                 be      loc_F00A91A8
F00A9194: 113c042b                 sethi   %hi(_nsysent), %o0
F00A9198: d00221c8                 ld      [%o0+%lo(_nsysent)], %o0
F00A919C: 80a24008                 cmp     %o1, %o0
F00A91A0: 0a800005                 bcs     loc_F00A91B4
F00A91A4: 932a6003                 sll     %o1, 3, %o1
F00A91A8: 113c042a                 sethi   %hi(unk_F010AA00), %o0
F00A91AC: 10800005                 ba      loc_F00A91C0
F00A91B0: a0122200                 or      %o0, %lo(unk_F010AA00), %l0
F00A91B4: 113c042a90122008         set     _sysent, %o0
F00A91BC: a0024008                 add     %o1, %o0, %l0
F00A91C0: 193c04cf                 sethi   %hi(dword_F0133DDC), %o4! int
F00A91C4: d00321dc                 ld      [%o4+%lo(dword_F0133DDC)], %o0
F00A91C8: c02a2038                 clrb    [%o0+0x38]
F00A91CC: d6540000                 ldsh    [%l0], %o3
F00A91D0: 80a2e005                 cmp     %o3, 5
F00A91D4: 34800002                 bg,a    loc_F00A91DC
F00A91D8: 96102005                 mov     5, %o3
F00A91DC: d20321dc                 ld      [%o4+0x1DC], %o1
F00A91E0: d0026024                 ld      [%o1+0x24], %o0
F00A91E4: 972ae002                 sll     %o3, 2, %o3! int
F00A91E8: 92026004                 inc     4, %o1
F00A91EC: 10800007                 ba      loc_F00A9208
F00A91F0: 94022004                 add     %o0, 4, %o2
F00A91F4: d0224000                 st      %o0, [%o1]
F00A91F8: d00321dc                 ld      [%o4+0x1DC], %o0
F00A91FC: 9402a004                 inc     4, %o2
F00A9200: d0022024                 ld      [%o0+0x24], %o0
F00A9204: 92026004                 inc     4, %o1
F00A9208: 9002000b                 add     %o0, %o3, %o0
F00A920C: 80a28008                 cmp     %o2, %o0
F00A9210: 28bffff9                 bleu,a  loc_F00A91F4
F00A9214: d0028000                 ld      [%o2], %o0
F00A9218: d4540000                 ldsh    [%l0], %o2
F00A921C: 80a2a005                 cmp     %o2, 5
F00A9220: 04800010                 ble     loc_F00A9260
F00A9224: 233c04cf                 sethi   %hi(dword_F0133DDC), %l1
F00A9228: d20461dc                 ld      [%l1+%lo(dword_F0133DDC)], %o1
F00A922C: 9402bffb                 inc     -5, %o2
F00A9230: d0024000                 ld      [%o1], %o0
F00A9234: 952aa002                 sll     %o2, 2, %o2! int
F00A9238: d0022044                 ld      [%o0+0x44], %o0! int
F00A923C: 92026018                 inc     0x18, %o1! int
F00A9240: 7fffbb86                 call    _copyin
F00A9244: 9002205c                 inc     0x5C, %o0 ! '\'
F00A9248: 80a22000                 cmp     %o0, 0
F00A924C: 02800005                 be      loc_F00A9260
F00A9250: d20461dc                 ld      [%l1+%lo(dword_F0133DDC)], %o1
F00A9254: 9010200e                 mov     0xE, %o0
F00A9258: 1080000a                 ba      locret_F00A9280
F00A925C: d02a6038                 stb     %o0, [%o1+0x38]
F00A9260: 153c04cf                 sethi   %hi(dword_F0133DDC), %o2
F00A9264: d202a1dc                 ld      [%o2+%lo(dword_F0133DDC)], %o1
F00A9268: 90026004                 add     %o1, 4, %o0
F00A926C: d0226024                 st      %o0, [%o1+0x24]
F00A9270: d002a1dc                 ld      [%o2+%lo(dword_F0133DDC)], %o0
F00A9274: d2042004                 ld      [%l0+4], %o1
F00A9278: 9fc24000                 call    %o1
F00A927C: d0022024                 ld      [%o0+0x24], %o0
F00A9280: 81c7e008                 ret
F00A9284: 81e80000                 restore
