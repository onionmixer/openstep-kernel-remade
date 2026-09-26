F00C44C0: 9de3bf10                 save    %sp, -0xF0, %sp
F00C44C4: 113c0504                 sethi   %hi(paBus_0), %o0
F00C44C8: e6022344                 ld      [%o0+%lo(paBus_0)], %l3
F00C44CC: e0062024                 ld      [%i0+0x24], %l0
F00C44D0: 90100018                 mov     %i0, %o0! id
F00C44D4: 4000b4e7                 call    _objc_msgSend
F00C44D8: 92100013                 mov     %l3, %o1
F00C44DC: 133c0504                 sethi   %hi(paLookupresource), %o1
F00C44E0: d2026128                 ld      [%o1+%lo(paLookupresource)], %o1! SEL
F00C44E4: 4000b4e3                 call    _objc_msgSend
F00C44E8: 9410001a                 mov     %i2, %o2
F00C44EC: a2920000                 orcc    %o0, %g0, %l1
F00C44F0: 32800005                 bne,a   loc_F00C4504
F00C44F4: 113c0506                 sethi   -0xFEBE800, %o0
F00C44F8: 113c04ba                 sethi   %hi(aSCouldnTLocate_1), %o0! "%s: Couldn't locate resource object\n"
F00C44FC: 1080000f                 ba      loc_F00C4538
F00C4500: 90122268                 bset    %lo(aSCouldnTLocate_1), %o0! "%s: Couldn't locate resource object\n"
F00C4504: d0022288                 ld      [%o0+0x288], %o0! id
F00C4508: 133c0503                 sethi   %hi(paAlloc), %o1! SEL
F00C450C: 4000b4d9                 call    _objc_msgSend
F00C4510: d20263f0                 ld      [%o1+%lo(paAlloc)], %o1
F00C4514: 133c0504                 sethi   %hi(paInit), %o1! SEL
F00C4518: 4000b4d6                 call    _objc_msgSend
F00C451C: d202602c                 ld      [%o1+%lo(paInit)], %o1
F00C4520: d404201c                 ld      [%l0+0x1C], %o2
F00C4524: 80a2a000                 cmp     %o2, 0
F00C4528: 12800008                 bne     loc_F00C4548
F00C452C: a4100008                 mov     %o0, %l2
F00C4530: 113c04ba90122290         set     aSCouldnTLocate_2, %o0! "%s: Couldn't locate irq level in device"...
F00C4538: 7ffd4048                 call    _printf
F00C453C: 9210001a                 mov     %i2, %o1! SEL
F00C4540: 1080002e                 ba      locret_F00C45F8
F00C4544: b0102000                 mov     0, %i0
F00C4548: 90100018                 mov     %i0, %o0! id
F00C454C: e0028000                 ld      [%o2], %l0
F00C4550: 4000b4c8                 call    _objc_msgSend
F00C4554: 92100013                 mov     %l3, %o1
F00C4558: 133c0504                 sethi   %hi(paClass), %o1! SEL
F00C455C: 4000b4c5                 call    _objc_msgSend
F00C4560: d2026014                 ld      [%o1+%lo(paClass)], %o1
F00C4564: 133c0504                 sethi   %hi(paIsirqshared), %o1
F00C4568: d2026370                 ld      [%o1+%lo(paIsirqshared)], %o1! SEL
F00C456C: 4000b4c1                 call    _objc_msgSend
F00C4570: 94100010                 mov     %l0, %o2
F00C4574: 912a2018                 sll     %o0, 24, %o0
F00C4578: 80a22000                 cmp     %o0, 0
F00C457C: 02800005                 be      loc_F00C4590
F00C4580: 133c0504                 sethi   %hi(paShareitem), %o1
F00C4584: 90100011                 mov     %l1, %o0
F00C4588: 10800005                 ba      loc_F00C459C
F00C458C: d202612c                 ld      [%o1+%lo(paShareitem)], %o1
F00C4590: 90100011                 mov     %l1, %o0! id
F00C4594: 133c0504                 sethi   %hi(paReserveitem), %o1
F00C4598: d2026130                 ld      [%o1+%lo(paReserveitem)], %o1! SEL
F00C459C: 4000b4b5                 call    _objc_msgSend
F00C45A0: 94100010                 mov     %l0, %o2
F00C45A4: 94100008                 mov     %o0, %o2
F00C45A8: 133c0504                 sethi   %hi(paAddobject), %o1
F00C45AC: d20260a4                 ld      [%o1+%lo(paAddobject)], %o1! SEL
F00C45B0: 4000b4b0                 call    _objc_msgSend
F00C45B4: 90100012                 mov     %l2, %o0
F00C45B8: 80a22000                 cmp     %o0, 0
F00C45BC: 1280000f                 bne     locret_F00C45F8
F00C45C0: b0100012                 mov     %l2, %i0
F00C45C4: 113c04ba901222d0         set     aSCouldnTReserv_1, %o0! "%s: Couldn't reserve %d\n"
F00C45CC: 9210001a                 mov     %i2, %o1
F00C45D0: 7ffd4022                 call    _printf
F00C45D4: 94100010                 mov     %l0, %o2
F00C45D8: 113c0504                 sethi   %hi(paFreeobjects), %o0! id
F00C45DC: d20220cc                 ld      [%o0+%lo(paFreeobjects)], %o1! SEL
F00C45E0: 4000b4a4                 call    _objc_msgSend
F00C45E4: 90100012                 mov     %l2, %o0! id
F00C45E8: 133c0503                 sethi   %hi(paFree), %o1! SEL
F00C45EC: 4000b4a1                 call    _objc_msgSend
F00C45F0: d20263fc                 ld      [%o1+%lo(paFree)], %o1
F00C45F4: b0100008                 mov     %o0, %i0
F00C45F8: 81c7e008                 ret
F00C45FC: 81e80000                 restore
