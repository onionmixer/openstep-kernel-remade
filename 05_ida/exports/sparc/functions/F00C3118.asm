F00C3118: 9de3bf98                 save    %sp, -0x68, %sp
F00C311C: 113c0506                 sethi   %hi(paList), %o0
F00C3120: d0022288                 ld      [%o0+%lo(paList)], %o0! id
F00C3124: 133c0503                 sethi   %hi(paAlloc), %o1
F00C3128: d20263f0                 ld      [%o1+%lo(paAlloc)], %o1! SEL
F00C312C: 4000b9d1                 call    _objc_msgSend
F00C3130: aa102000                 mov     0, %l5
F00C3134: 133c0504                 sethi   %hi(paInit), %o1
F00C3138: d202602c                 ld      [%o1+%lo(paInit)], %o1! SEL
F00C313C: 4000b9cd                 call    _objc_msgSend
F00C3140: a4102001                 mov     1, %l2
F00C3144: 133c04fd                 sethi   %hi(_autoConfigTables), %o1
F00C3148: 400002b7                 call    sub_F00C3C24
F00C314C: d0226390                 st      %o0, [%o1+%lo(_autoConfigTables)]
F00C3150: 40000b78                 call    _IOMalloc
F00C3154: 90102080                 mov     0x80, %o0
F00C3158: a6100008                 mov     %o0, %l3
F00C315C: 113c0504                 sethi   %hi(paValueforstring), %o0
F00C3160: e80220e8                 ld      [%o0+%lo(paValueforstring)], %l4
F00C3164: 40000288                 call    _findBootConfigString
F00C3168: 90100012                 mov     %l2, %o0
F00C316C: 94920000                 orcc    %o0, %g0, %o2
F00C3170: 02800033                 be      loc_F00C323C
F00C3174: 113c0506                 sethi   %hi(paIoconfigtable), %o0
F00C3178: d0022298                 ld      [%o0+%lo(paIoconfigtable)], %o0! id
F00C317C: 133c0504                 sethi   %hi(paNewforconfigda), %o1! SEL
F00C3180: 4000b9bc                 call    _objc_msgSend
F00C3184: d202615c                 ld      [%o1+%lo(paNewforconfigda)], %o1
F00C3188: a2100008                 mov     %o0, %l1
F00C318C: 92100014                 mov     %l4, %o1! SEL
F00C3190: 153c04b9                 sethi   %hi(aFamily), %o2! "Family"
F00C3194: 4000b9b7                 call    _objc_msgSend
F00C3198: 9412a1e0                 bset    %lo(aFamily), %o2! "Family"
F00C319C: a0920000                 orcc    %o0, %g0, %l0
F00C31A0: 0280001f                 be      loc_F00C321C
F00C31A4: 133c04b9                 sethi   %hi(aBus_0), %o1! "Bus"
F00C31A8: 7ffd1401                 call    _strcmp
F00C31AC: 921261e8                 bset    %lo(aBus_0), %o1! "Bus"
F00C31B0: 80a22000                 cmp     %o0, 0
F00C31B4: 1280001a                 bne     loc_F00C321C
F00C31B8: 80a42000                 cmp     %l0, 0
F00C31BC: 90100011                 mov     %l1, %o0! id
F00C31C0: 92100014                 mov     %l4, %o1! SEL
F00C31C4: 153c04b9                 sethi   %hi(aBusType_0), %o2! "Bus Type"
F00C31C8: 4000b9aa                 call    _objc_msgSend
F00C31CC: 9412a1f0                 bset    %lo(aBusType_0), %o2! "Bus Type"
F00C31D0: 94100008                 mov     %o0, %o2
F00C31D4: 90100013                 mov     %l3, %o0! char *
F00C31D8: 133c04b9                 sethi   %hi(aSkernbus), %o1! "%sKernBus"
F00C31DC: 7ffd4563                 call    _sprintf
F00C31E0: 92126200                 bset    %lo(aSkernbus), %o1! "%sKernBus"
F00C31E4: 90100013                 mov     %l3, %o0! name
F00C31E8: 133c04b9                 sethi   %hi(aSparckernbus_0), %o1! "SPARCKernBus"
F00C31EC: 7ffd13f0                 call    _strcmp
F00C31F0: 92126210                 bset    %lo(aSparckernbus_0), %o1! "SPARCKernBus"
F00C31F4: 80a22000                 cmp     %o0, 0
F00C31F8: 22800002                 be,a    loc_F00C3200
F00C31FC: aa102001                 mov     1, %l5
F00C3200: 4000bac1                 call    _objc_getClass
F00C3204: 90100013                 mov     %l3, %o0! id
F00C3208: 133c0504                 sethi   %hi(paProbebus), %o1
F00C320C: d202632c                 ld      [%o1+%lo(paProbebus)], %o1! SEL
F00C3210: 4000b998                 call    _objc_msgSend
F00C3214: 94100011                 mov     %l1, %o2
F00C3218: 80a42000                 cmp     %l0, 0
F00C321C: 02800006                 be      loc_F00C3234
F00C3220: 90100011                 mov     %l1, %o0! id
F00C3224: 133c0504                 sethi   %hi(paFreestring), %o1
F00C3228: d20260f4                 ld      [%o1+%lo(paFreestring)], %o1! SEL
F00C322C: 4000b991                 call    _objc_msgSend
F00C3230: 94100010                 mov     %l0, %o2
F00C3234: 10bfffcc                 ba      loc_F00C3164
F00C3238: a404a001                 inc     %l2
F00C323C: 80a56000                 cmp     %l5, 0
F00C3240: 3280000a                 bne,a   loc_F00C3268
F00C3244: 113c0506                 sethi   -0xFEBE800, %o0
F00C3248: 113c04b9                 sethi   %hi(aSparckernbus_1), %o0! "SPARCKernBus"
F00C324C: 4000baae                 call    _objc_getClass
F00C3250: 90122220                 bset    %lo(aSparckernbus_1), %o0! "SPARCKernBus"
F00C3254: 133c0504                 sethi   %hi(paProbebus), %o1
F00C3258: d202632c                 ld      [%o1+%lo(paProbebus)], %o1! SEL
F00C325C: 4000b985                 call    _objc_msgSend
F00C3260: 94102000                 mov     0, %o2
F00C3264: 113c0506                 sethi   -0xFEBE800, %o0
F00C3268: e0022294                 ld      [%o0+0x294], %l0
F00C326C: 153c04b9                 sethi   %hi(aSparc), %o2! "SPARC"
F00C3270: 113c0504                 sethi   %hi(paLookupbusclass), %o0! id
F00C3274: d20220ec                 ld      [%o0+%lo(paLookupbusclass)], %o1! SEL
F00C3278: 9412a230                 bset    %lo(aSparc), %o2! "SPARC"
F00C327C: 4000b97d                 call    _objc_msgSend
F00C3280: 90100010                 mov     %l0, %o0
F00C3284: 133c04fd                 sethi   %hi(_defaultBusClass), %o1
F00C3288: 80a22000                 cmp     %o0, 0
F00C328C: 1280000a                 bne     loc_F00C32B4
F00C3290: d02263a0                 st      %o0, [%o1+%lo(_defaultBusClass)]
F00C3294: 90100013                 mov     %l3, %o0! char *
F00C3298: 133c04b992126238         set     aMissingSKernel, %o1! "Missing %s kernel bus class"
F00C32A0: 153c04b9                 sethi   %hi(aSparc_0), %o2! "SPARC"
F00C32A4: 7ffd4531                 call    _sprintf
F00C32A8: 9412a258                 bset    %lo(aSparc_0), %o2! "SPARC"
F00C32AC: 7ffd47b1                 call    _panic
F00C32B0: 90100013                 mov     %l3, %o0
F00C32B4: 90100010                 mov     %l0, %o0! id
F00C32B8: 153c04b99412a260         set     aSparc_1, %o2! "SPARC"
F00C32C0: a4102001                 mov     1, %l2
F00C32C4: 133c0504                 sethi   %hi(paLookupbusinsta), %o1
F00C32C8: d20260f0                 ld      [%o1+%lo(paLookupbusinsta)], %o1! SEL
F00C32CC: 4000b969                 call    _objc_msgSend
F00C32D0: 96102000                 mov     0, %o3
F00C32D4: 133c04fd                 sethi   %hi(_defaultBus), %o1
F00C32D8: d0226398                 st      %o0, [%o1+%lo(_defaultBus)]
F00C32DC: 113c0506                 sethi   %hi(paIodevice_0), %o0
F00C32E0: 133c0504                 sethi   %hi(paDriverkitversi_0), %o1
F00C32E4: d0022270                 ld      [%o0+%lo(paIodevice_0)], %o0! id
F00C32E8: 213c04b9                 sethi   %hi(aDriverkitVersi), %l0! "DriverKit version %d\n"
F00C32EC: d2026330                 ld      [%o1+%lo(paDriverkitversi_0)], %o1! SEL
F00C32F0: 4000b960                 call    _objc_msgSend
F00C32F4: a0142268                 bset    %lo(aDriverkitVersi), %l0! "DriverKit version %d\n"
F00C32F8: 92100008                 mov     %o0, %o1
F00C32FC: 7ffd44d7                 call    _printf
F00C3300: 90100010                 mov     %l0, %o0
F00C3304: 40000220                 call    _findBootConfigString
F00C3308: 90100012                 mov     %l2, %o0
F00C330C: 94920000                 orcc    %o0, %g0, %o2
F00C3310: 22800005                 be,a    loc_F00C3324
F00C3314: 90100013                 mov     %l3, %o0
F00C3318: 40000007                 call    sub_F00C3334
F00C331C: a404a001                 inc     %l2
F00C3320: 30bffff9                 ba,a    loc_F00C3304
F00C3324: 40000b08                 call    _IOFree
F00C3328: 92102080                 mov     0x80, %o1
F00C332C: 81c7e008                 ret
F00C3330: 81e80000                 restore
