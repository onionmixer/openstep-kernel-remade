F00C21F4: 9de3bf90                 save    %sp, -0x70, %sp
F00C21F8: 90100018                 mov     %i0, %o0! id
F00C21FC: 133c0504                 sethi   %hi(paSetdevicekind), %o1
F00C2200: 153c0484                 sethi   %hi(aSunmouse_0), %o2! "SUNMouse"
F00C2204: d2026250                 ld      [%o1+%lo(paSetdevicekind)], %o1! SEL
F00C2208: 4000bd9a                 call    _objc_msgSend
F00C220C: 9412a188                 bset    %lo(aSunmouse_0), %o2! "SUNMouse"
F00C2210: 113c0504                 sethi   %hi(paDevicedescript_1), %o0! id
F00C2214: d2022158                 ld      [%o0+%lo(paDevicedescript_1)], %o1! SEL
F00C2218: 4000bd96                 call    _objc_msgSend
F00C221C: 90100018                 mov     %i0, %o0! id
F00C2220: 133c0504                 sethi   %hi(paConfigtable_0), %o1! SEL
F00C2224: 4000bd93                 call    _objc_msgSend
F00C2228: d2026310                 ld      [%o1+%lo(paConfigtable_0)], %o1
F00C222C: 80a22000                 cmp     %o0, 0
F00C2230: 12800007                 bne     loc_F00C224C
F00C2234: 133c0504                 sethi   -0xFEBF000, %o1
F00C2238: 113c0484                 sethi   %hi(aSunmouseMousei), %o0! "SUNMouse mouseInit: no configuration ta"...
F00C223C: 40000fae                 call    _IOLog
F00C2240: 90122198                 bset    %lo(aSunmouseMousei), %o0! "SUNMouse mouseInit: no configuration ta"...
F00C2244: 10800042                 ba      locret_F00C234C
F00C2248: b0102000                 mov     0, %i0
F00C224C: d20260e8                 ld      [%o1+0xE8], %o1! SEL
F00C2250: 153c0484                 sethi   %hi(aResolution_0), %o2! "Resolution"
F00C2254: 4000bd87                 call    _objc_msgSend
F00C2258: 9412a1c8                 bset    %lo(aResolution_0), %o2! "Resolution"
F00C225C: 80a22000                 cmp     %o0, 0
F00C2260: 12800007                 bne     loc_F00C227C
F00C2264: 01000000                 nop
F00C2268: 113c0484                 sethi   %hi(aSunmouseMousei_0), %o0! "SUNMouse mouseInit: no resolution value"...
F00C226C: 40000fa2                 call    _IOLog
F00C2270: 901221d8                 bset    %lo(aSunmouseMousei_0), %o0! "SUNMouse mouseInit: no resolution value"...
F00C2274: 10800008                 ba      loc_F00C2294
F00C2278: 901020c8                 mov     0xC8, %o0
F00C227C: 7ffff9ed                 call    _PCPatoi
F00C2280: 01000000                 nop
F00C2284: 80a22000                 cmp     %o0, 0
F00C2288: 16800004                 bge     loc_F00C2298
F00C228C: d0262134                 st      %o0, [%i0+0x134]
F00C2290: 901020c8                 mov     0xC8, %o0
F00C2294: d0262134                 st      %o0, [%i0+0x134]
F00C2298: 113c0504                 sethi   %hi(paEnableallinter), %o0! id
F00C229C: d2022314                 ld      [%o0+%lo(paEnableallinter)], %o1! SEL
F00C22A0: 4000bd74                 call    _objc_msgSend
F00C22A4: 90100018                 mov     %i0, %o0
F00C22A8: 113c04cc                 sethi   %hi(dword_F0133028), %o0
F00C22AC: c0222028                 clr     [%o0+%lo(dword_F0133028)]
F00C22B0: 113c04cc90122018         set     unk_F0133018, %o0
F00C22B8: c02a200a                 clrb    [%o0+0xA]
F00C22BC: 7ffe93fd                 call    _task_self
F00C22C0: c02a2009                 clrb    [%o0+9]
F00C22C4: 4000c6ec                 call    _port_set_allocate_EXTERNAL
F00C22C8: 92062130                 add     %i0, 0x130, %o1
F00C22CC: 92920000                 orcc    %o0, %g0, %o1
F00C22D0: 02800007                 be      loc_F00C22EC
F00C22D4: 01000000                 nop
F00C22D8: 113c0484                 sethi   %hi(aMouseinitPortS), %o0! "mouseInit: port_set_allocate returned %"...
F00C22DC: 40000f86                 call    _IOLog
F00C22E0: 90122210                 bset    %lo(aMouseinitPortS), %o0! "mouseInit: port_set_allocate returned %"...
F00C22E4: 1080001a                 ba      locret_F00C234C
F00C22E8: b0102000                 mov     0, %i0
F00C22EC: 7ffe93f1                 call    _task_self
F00C22F0: 01000000                 nop
F00C22F4: 133c0504                 sethi   %hi(paInterruptport_0), %o1
F00C22F8: d2026308                 ld      [%o1+%lo(paInterruptport_0)], %o1! SEL
F00C22FC: a0100008                 mov     %o0, %l0
F00C2300: e2062130                 ld      [%i0+0x130], %l1
F00C2304: 4000bd5b                 call    _objc_msgSend
F00C2308: 90100018                 mov     %i0, %o0
F00C230C: 94100008                 mov     %o0, %o2
F00C2310: 90100010                 mov     %l0, %o0
F00C2314: 4000c695                 call    _port_set_add_EXTERNAL
F00C2318: 92100011                 mov     %l1, %o1
F00C231C: 92920000                 orcc    %o0, %g0, %o1
F00C2320: 12800008                 bne     loc_F00C2340
F00C2324: 113c0484                 sethi   -0xFEDF000, %o0
F00C2328: 113c030890122154         set     sub_F00C2154, %o0
F00C2330: 40001f64                 call    _IOForkThread
F00C2334: 92100018                 mov     %i0, %o1
F00C2338: 10800005                 ba      locret_F00C234C
F00C233C: b0102001                 mov     1, %i0
F00C2340: 40000f6d                 call    _IOLog
F00C2344: 90122240                 bset    0x240, %o0
F00C2348: b0103fff                 mov     -1, %i0
F00C234C: 81c7e008                 ret
F00C2350: 81e80000                 restore
