F00D4F7C: 9de3bf90                 save    %sp, -0x70, %sp
F00D4F80: d0062188                 ld      [%i0+0x188], %o0
F00D4F84: a2103fff                 mov     -1, %l1
F00D4F88: 80a22000                 cmp     %o0, 0
F00D4F8C: 028000d9                 be      locret_F00D52F0
F00D4F90: e0062168                 ld      [%i0+0x168], %l0
F00D4F94: 7fffb7af                 call    _ev_try_lock
F00D4F98: 90042014                 add     %l0, 0x14, %o0
F00D4F9C: 80a22000                 cmp     %o0, 0
F00D4FA0: 32800009                 bne,a   loc_F00D4FC4
F00D4FA4: d206218c                 ld      [%i0+0x18C], %o1
F00D4FA8: 90102001                 mov     1, %o0
F00D4FAC: d02e2211                 stb     %o0, [%i0+0x211]
F00D4FB0: 113c0505                 sethi   %hi(paSchedulenextpe), %o0! id
F00D4FB4: d2022308                 ld      [%o0+%lo(paSchedulenextpe)], %o1! SEL
F00D4FB8: 4000722e                 call    _objc_msgSend
F00D4FBC: 90100018                 mov     %i0, %o0
F00D4FC0: 308000cc                 ba,a    locret_F00D52F0
F00D4FC4: c02e2211                 clrb    [%i0+0x211]
F00D4FC8: 912a6002                 sll     %o1, 2, %o0
F00D4FCC: 90020009                 add     %o0, %o1, %o0
F00D4FD0: d2062180                 ld      [%i0+0x180], %o1
F00D4FD4: 912a2002                 sll     %o0, 2, %o0
F00D4FD8: 92020009                 add     %o0, %o1, %o1
F00D4FDC: d012600c                 lduh    [%o1+0xC], %o0
F00D4FE0: d4568000                 ldsh    [%i2], %o2
F00D4FE4: 912a2010                 sll     %o0, 16, %o0
F00D4FE8: 913a2010                 sra     %o0, 16, %o0
F00D4FEC: 80a28008                 cmp     %o2, %o0
F00D4FF0: 06800015                 bl      loc_F00D5044
F00D4FF4: 90100018                 mov     %i0, %o0
F00D4FF8: d012600e                 lduh    [%o1+0xE], %o0
F00D4FFC: 912a2010                 sll     %o0, 16, %o0
F00D5000: 913a2010                 sra     %o0, 16, %o0
F00D5004: 80a28008                 cmp     %o2, %o0
F00D5008: 1680000f                 bge     loc_F00D5044
F00D500C: 90100018                 mov     %i0, %o0
F00D5010: d0126010                 lduh    [%o1+0x10], %o0
F00D5014: d456a002                 ldsh    [%i2+2], %o2
F00D5018: 912a2010                 sll     %o0, 16, %o0
F00D501C: 913a2010                 sra     %o0, 16, %o0
F00D5020: 80a28008                 cmp     %o2, %o0
F00D5024: 06800008                 bl      loc_F00D5044
F00D5028: 90100018                 mov     %i0, %o0
F00D502C: d0126012                 lduh    [%o1+0x12], %o0
F00D5030: 912a2010                 sll     %o0, 16, %o0
F00D5034: 913a2010                 sra     %o0, 16, %o0
F00D5038: 80a28008                 cmp     %o2, %o0
F00D503C: 0680001f                 bl      loc_F00D50B8
F00D5040: 90100018                 mov     %i0, %o0! id
F00D5044: 133c0505                 sethi   %hi(paPointtoscreen), %o1
F00D5048: d20262ac                 ld      [%o1+%lo(paPointtoscreen)], %o1! SEL
F00D504C: 40007209                 call    _objc_msgSend
F00D5050: 9410001a                 mov     %i2, %o2
F00D5054: a2920000                 orcc    %o0, %g0, %l1
F00D5058: 36800019                 bge,a   loc_F00D50BC
F00D505C: d0168000                 lduh    [%i2], %o0
F00D5060: d4568000                 ldsh    [%i2], %o2
F00D5064: d0562190                 ldsh    [%i0+0x190], %o0
F00D5068: 80a28008                 cmp     %o2, %o0
F00D506C: 06800006                 bl      loc_F00D5084
F00D5070: 9210000a                 mov     %o2, %o1
F00D5074: d0562192                 ldsh    [%i0+0x192], %o0
F00D5078: 80a28008                 cmp     %o2, %o0
F00D507C: 24800004                 ble,a   loc_F00D508C
F00D5080: d456a002                 ldsh    [%i2+2], %o2
F00D5084: 92100008                 mov     %o0, %o1
F00D5088: d456a002                 ldsh    [%i2+2], %o2
F00D508C: d2368000                 sth     %o1, [%i2]
F00D5090: d0562194                 ldsh    [%i0+0x194], %o0
F00D5094: 80a28008                 cmp     %o2, %o0
F00D5098: 06800006                 bl      loc_F00D50B0
F00D509C: 9210000a                 mov     %o2, %o1
F00D50A0: d0562196                 ldsh    [%i0+0x196], %o0
F00D50A4: 80a28008                 cmp     %o2, %o0
F00D50A8: 24800004                 ble,a   loc_F00D50B8
F00D50AC: d236a002                 sth     %o1, [%i2+2]
F00D50B0: 92100008                 mov     %o0, %o1
F00D50B4: d236a002                 sth     %o1, [%i2+2]
F00D50B8: d0168000                 lduh    [%i2], %o0
F00D50BC: d03621a8                 sth     %o0, [%i0+0x1A8]
F00D50C0: d016a002                 lduh    [%i2+2], %o0
F00D50C4: d03621aa                 sth     %o0, [%i0+0x1AA]
F00D50C8: d0142018                 lduh    [%l0+0x18], %o0
F00D50CC: d2568000                 ldsh    [%i2], %o1
F00D50D0: 912a2010                 sll     %o0, 16, %o0
F00D50D4: 913a2010                 sra     %o0, 16, %o0
F00D50D8: 80a20009                 cmp     %o0, %o1
F00D50DC: 3280000a                 bne,a   loc_F00D5104
F00D50E0: d0168000                 lduh    [%i2], %o0
F00D50E4: d014201a                 lduh    [%l0+0x1A], %o0
F00D50E8: d256a002                 ldsh    [%i2+2], %o1
F00D50EC: 912a2010                 sll     %o0, 16, %o0
F00D50F0: 913a2010                 sra     %o0, 16, %o0
F00D50F4: 80a20009                 cmp     %o0, %o1
F00D50F8: 0280007c                 be      loc_F00D52E8
F00D50FC: 01000000                 nop
F00D5100: d0168000                 lduh    [%i2], %o0
F00D5104: d0342018                 sth     %o0, [%l0+0x18]
F00D5108: d016a002                 lduh    [%i2+2], %o0
F00D510C: 80a46000                 cmp     %l1, 0
F00D5110: d034201a                 sth     %o0, [%l0+0x1A]
F00D5114: 0680001d                 bl      loc_F00D5188
F00D5118: 113c0505                 sethi   %hi(paHidecursor_0), %o0! id
F00D511C: d202234c                 ld      [%o0+%lo(paHidecursor_0)], %o1! SEL
F00D5120: 400071d4                 call    _objc_msgSend
F00D5124: 90100018                 mov     %i0, %o0
F00D5128: e226218c                 st      %l1, [%i0+0x18C]
F00D512C: 912c6002                 sll     %l1, 2, %o0
F00D5130: 90020011                 add     %o0, %l1, %o0
F00D5134: d4062180                 ld      [%i0+0x180], %o2
F00D5138: 912a2002                 sll     %o0, 2, %o0
F00D513C: 94028008                 add     %o2, %o0, %o2
F00D5140: d012a00c                 lduh    [%o2+0xC], %o0
F00D5144: d0362190                 sth     %o0, [%i0+0x190]
F00D5148: d612a00e                 lduh    [%o2+0xE], %o3
F00D514C: 113c0505                 sethi   %hi(paShowcursor), %o0
F00D5150: d2022310                 ld      [%o0+%lo(paShowcursor)], %o1
F00D5154: d6362192                 sth     %o3, [%i0+0x192]
F00D5158: d812a010                 lduh    [%o2+0x10], %o4
F00D515C: 90100018                 mov     %i0, %o0
F00D5160: d6162192                 lduh    [%i0+0x192], %o3
F00D5164: d8362194                 sth     %o4, [%i0+0x194]
F00D5168: d412a012                 lduh    [%o2+0x12], %o2
F00D516C: 9602ffff                 inc     -1, %o3
F00D5170: d4362196                 sth     %o2, [%i0+0x196]
F00D5174: d4162196                 lduh    [%i0+0x196], %o2
F00D5178: d6362192                 sth     %o3, [%i0+0x192]
F00D517C: 9402bfff                 inc     -1, %o2
F00D5180: 10800005                 ba      loc_F00D5194
F00D5184: d4362196                 sth     %o2, [%i0+0x196]
F00D5188: 113c0505                 sethi   %hi(paMovecursor), %o0
F00D518C: d202229c                 ld      [%o0+%lo(paMovecursor)], %o1! SEL
F00D5190: 90100018                 mov     %i0, %o0! id
F00D5194: 400071b7                 call    _objc_msgSend
F00D5198: 01000000                 nop
F00D519C: d0042034                 ld      [%l0+0x34], %o0
F00D51A0: 80a22000                 cmp     %o0, 0
F00D51A4: 02800025                 be      loc_F00D5238
F00D51A8: 01000000                 nop
F00D51AC: d0042034                 ld      [%l0+0x34], %o0
F00D51B0: 808a2040                 btst    0x40, %o0 ! '@'
F00D51B4: 0280000a                 be      loc_F00D51DC
F00D51B8: 01000000                 nop
F00D51BC: d0042008                 ld      [%l0+8], %o0
F00D51C0: 808a2004                 btst    4, %o0
F00D51C4: 02800006                 be      loc_F00D51DC
F00D51C8: 90100018                 mov     %i0, %o0
F00D51CC: 133c0505                 sethi   %hi(paPosteventAtAtt), %o1
F00D51D0: d2026314                 ld      [%o1+%lo(paPosteventAtAtt)], %o1
F00D51D4: 10800015                 ba      loc_F00D5228
F00D51D8: 94102006                 mov     6, %o2
F00D51DC: d0042034                 ld      [%l0+0x34], %o0
F00D51E0: 808a2080                 btst    0x80, %o0
F00D51E4: 0280000a                 be      loc_F00D520C
F00D51E8: 01000000                 nop
F00D51EC: d0042008                 ld      [%l0+8], %o0
F00D51F0: 808a2001                 btst    1, %o0
F00D51F4: 02800006                 be      loc_F00D520C
F00D51F8: 90100018                 mov     %i0, %o0
F00D51FC: 133c0505                 sethi   %hi(paPosteventAtAtt), %o1
F00D5200: d2026314                 ld      [%o1+%lo(paPosteventAtAtt)], %o1
F00D5204: 10800009                 ba      loc_F00D5228
F00D5208: 94102007                 mov     7, %o2
F00D520C: d0042034                 ld      [%l0+0x34], %o0
F00D5210: 808a2020                 btst    0x20, %o0 ! ' '
F00D5214: 02800009                 be      loc_F00D5238
F00D5218: 90100018                 mov     %i0, %o0! id
F00D521C: 133c0505                 sethi   %hi(paPosteventAtAtt), %o1
F00D5220: d2026314                 ld      [%o1+%lo(paPosteventAtAtt)], %o1! SEL
F00D5224: 94102005                 mov     5, %o2
F00D5228: 9610001a                 mov     %i2, %o3
F00D522C: 9810001b                 mov     %i3, %o4
F00D5230: 40007190                 call    _objc_msgSend
F00D5234: 9a102000                 mov     0, %o5
F00D5238: d00c2033                 ldub    [%l0+0x33], %o0
F00D523C: 808a2001                 btst    1, %o0
F00D5240: 0280002a                 be      loc_F00D52E8
F00D5244: 01000000                 nop
F00D5248: d0142028                 lduh    [%l0+0x28], %o0
F00D524C: d2568000                 ldsh    [%i2], %o1
F00D5250: 912a2010                 sll     %o0, 16, %o0
F00D5254: 913a2010                 sra     %o0, 16, %o0
F00D5258: 80a24008                 cmp     %o1, %o0
F00D525C: 06800015                 bl      loc_F00D52B0
F00D5260: 01000000                 nop
F00D5264: d014202a                 lduh    [%l0+0x2A], %o0
F00D5268: 912a2010                 sll     %o0, 16, %o0
F00D526C: 913a2010                 sra     %o0, 16, %o0
F00D5270: 80a24008                 cmp     %o1, %o0
F00D5274: 1680000f                 bge     loc_F00D52B0
F00D5278: 01000000                 nop
F00D527C: d014202c                 lduh    [%l0+0x2C], %o0
F00D5280: d256a002                 ldsh    [%i2+2], %o1
F00D5284: 912a2010                 sll     %o0, 16, %o0
F00D5288: 913a2010                 sra     %o0, 16, %o0
F00D528C: 80a24008                 cmp     %o1, %o0
F00D5290: 06800008                 bl      loc_F00D52B0
F00D5294: 01000000                 nop
F00D5298: d014202e                 lduh    [%l0+0x2E], %o0
F00D529C: 912a2010                 sll     %o0, 16, %o0
F00D52A0: 913a2010                 sra     %o0, 16, %o0
F00D52A4: 80a24008                 cmp     %o1, %o0
F00D52A8: 06800010                 bl      loc_F00D52E8
F00D52AC: 01000000                 nop
F00D52B0: d00c2033                 ldub    [%l0+0x33], %o0
F00D52B4: 808a2001                 btst    1, %o0
F00D52B8: 0280000c                 be      loc_F00D52E8
F00D52BC: 90100018                 mov     %i0, %o0! id
F00D52C0: 94102009                 mov     9, %o2
F00D52C4: 9610001a                 mov     %i2, %o3
F00D52C8: 9810001b                 mov     %i3, %o4
F00D52CC: 133c0505                 sethi   %hi(paPosteventAtAtt), %o1
F00D52D0: d2026314                 ld      [%o1+%lo(paPosteventAtAtt)], %o1! SEL
F00D52D4: 40007167                 call    _objc_msgSend
F00D52D8: 9a102000                 mov     0, %o5
F00D52DC: d00c2033                 ldub    [%l0+0x33], %o0
F00D52E0: 900a20fe                 and     %o0, 0xFE, %o0
F00D52E4: d02c2033                 stb     %o0, [%l0+0x33]
F00D52E8: 7fffb6d8                 call    _ev_unlock
F00D52EC: 90042014                 add     %l0, 0x14, %o0
F00D52F0: 81c7e008                 ret
F00D52F4: 81e80000                 restore
