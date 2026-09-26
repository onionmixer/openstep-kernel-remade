F00C4070: 9de3bf88                 save    %sp, -0x78, %sp
F00C4074: f027bff0                 st      %i0, [%fp+var_10]
F00C4078: 133c0507                 sethi   %hi(stru_F0141E1C.super_class), %o1
F00C407C: d4026220                 ld      [%o1+%lo(stru_F0141E1C.super_class)], %o2
F00C4080: 9007bff0                 add     %fp, var_10, %o0! objc_super *
F00C4084: 133c0504                 sethi   %hi(paInit), %o1
F00C4088: d202602c                 ld      [%o1+%lo(paInit)], %o1! SEL
F00C408C: 4000b63c                 call    _objc_msgSendSuper
F00C4090: d427bff4                 st      %o2, [%fp+var_C]
F00C4094: 9006207f                 add     %i0, 0x7F, %o0
F00C4098: 92100018                 mov     %i0, %o1
F00C409C: c02a2010                 clrb    [%o0+0x10]
F00C40A0: 90023fff                 inc     -1, %o0
F00C40A4: 80a20009                 cmp     %o0, %o1
F00C40A8: 36bffffe                 bge,a   loc_F00C40A0
F00C40AC: c02a2010                 clrb    [%o0+0x10]
F00C40B0: 133c0503                 sethi   %hi(paAlloc), %o1
F00C40B4: e40263f0                 ld      [%o1+%lo(paAlloc)], %l2
F00C40B8: 133c0504                 sethi   %hi(paInsertresource), %o1! SEL
F00C40BC: e8026378                 ld      [%o1+%lo(paInsertresource)], %l4
F00C40C0: 113c0506                 sethi   %hi(paKernbusitemres), %o0
F00C40C4: d00222b8                 ld      [%o0+%lo(paKernbusitemres)], %o0! id
F00C40C8: 4000b5ea                 call    _objc_msgSend
F00C40CC: 92100012                 mov     %l2, %o1
F00C40D0: 133c0504                 sethi   %hi(paClass), %o1
F00C40D4: e6026014                 ld      [%o1+%lo(paClass)], %l3
F00C40D8: a2100008                 mov     %o0, %l1
F00C40DC: 133c0504                 sethi   %hi(paInitwithitemco), %o1! SEL
F00C40E0: e0026374                 ld      [%o1+%lo(paInitwithitemco)], %l0
F00C40E4: 113c0506                 sethi   %hi(paSparckernbusin), %o0
F00C40E8: d00222bc                 ld      [%o0+%lo(paSparckernbusin)], %o0! id
F00C40EC: 4000b5e1                 call    _objc_msgSend
F00C40F0: 92100013                 mov     %l3, %o1
F00C40F4: 96100008                 mov     %o0, %o3
F00C40F8: 90100011                 mov     %l1, %o0! id
F00C40FC: 92100010                 mov     %l0, %o1! SEL
F00C4100: 94102080                 mov     0x80, %o2
F00C4104: 4000b5db                 call    _objc_msgSend
F00C4108: 98100018                 mov     %i0, %o4
F00C410C: 94100008                 mov     %o0, %o2
F00C4110: 90100018                 mov     %i0, %o0! id
F00C4114: 92100014                 mov     %l4, %o1! SEL
F00C4118: 173c04ba                 sethi   %hi(aIrqLevels_3), %o3! "IRQ Levels"
F00C411C: 4000b5d5                 call    _objc_msgSend
F00C4120: 9612e1d8                 bset    %lo(aIrqLevels_3), %o3! "IRQ Levels"
F00C4124: c027bfe8                 clr     [%fp+var_18]
F00C4128: c027bfec                 clr     [%fp+var_14]
F00C412C: 113c0506                 sethi   %hi(paKernbusrangere), %o0
F00C4130: d00222c0                 ld      [%o0+%lo(paKernbusrangere)], %o0! id
F00C4134: 4000b5cf                 call    _objc_msgSend
F00C4138: 92100012                 mov     %l2, %o1
F00C413C: 92100013                 mov     %l3, %o1! SEL
F00C4140: a4100008                 mov     %o0, %l2
F00C4144: 113c0506                 sethi   %hi(paKernbusmemoryr_0), %o0
F00C4148: d00222c4                 ld      [%o0+%lo(paKernbusmemoryr_0)], %o0! id
F00C414C: 153c0504                 sethi   %hi(paInitwithextent), %o2
F00C4150: e002a37c                 ld      [%o2+%lo(paInitwithextent)], %l0
F00C4154: 4000b5c7                 call    _objc_msgSend
F00C4158: a207bfe8                 add     %fp, var_18, %l1
F00C415C: 96100008                 mov     %o0, %o3
F00C4160: 90100012                 mov     %l2, %o0! id
F00C4164: 92100010                 mov     %l0, %o1! SEL
F00C4168: 94100011                 mov     %l1, %o2
F00C416C: 4000b5c1                 call    _objc_msgSend
F00C4170: 98100018                 mov     %i0, %o4
F00C4174: 94100008                 mov     %o0, %o2
F00C4178: 90100018                 mov     %i0, %o0! id
F00C417C: 92100014                 mov     %l4, %o1! SEL
F00C4180: 173c04ba                 sethi   %hi(aMemoryMaps_3), %o3! "Memory Maps"
F00C4184: 4000b5bb                 call    _objc_msgSend
F00C4188: 9612e1e8                 bset    %lo(aMemoryMaps_3), %o3! "Memory Maps"
F00C418C: 90100018                 mov     %i0, %o0! id
F00C4190: 4000b5b8                 call    _objc_msgSend
F00C4194: 92100013                 mov     %l3, %o1
F00C4198: a4100008                 mov     %o0, %l2
F00C419C: 90100018                 mov     %i0, %o0! id
F00C41A0: 133c0504                 sethi   %hi(paBusid_0), %o1
F00C41A4: 153c0504                 sethi   %hi(paRegisterbusins), %o2
F00C41A8: d2026380                 ld      [%o1+%lo(paBusid_0)], %o1! SEL
F00C41AC: 213c04ba                 sethi   %hi(aSparc_3), %l0! "SPARC"
F00C41B0: e202a384                 ld      [%o2+%lo(paRegisterbusins)], %l1
F00C41B4: 4000b5af                 call    _objc_msgSend
F00C41B8: a01421f8                 bset    %lo(aSparc_3), %l0! "SPARC"
F00C41BC: 98100008                 mov     %o0, %o4
F00C41C0: 90100012                 mov     %l2, %o0! id
F00C41C4: 92100011                 mov     %l1, %o1! SEL
F00C41C8: 94100018                 mov     %i0, %o2
F00C41CC: 4000b5a9                 call    _objc_msgSend
F00C41D0: 96100010                 mov     %l0, %o3
F00C41D4: 113c04ba                 sethi   %hi(aSparcBusSuppor), %o0! "SPARC bus support enabled\n"
F00C41D8: 7ffd4120                 call    _printf
F00C41DC: 90122200                 bset    %lo(aSparcBusSuppor), %o0! "SPARC bus support enabled\n"
F00C41E0: 113c04cc                 sethi   %hi(dword_F013302C), %o0
F00C41E4: d002202c                 ld      [%o0+%lo(dword_F013302C)], %o0! id
F00C41E8: 133c0504                 sethi   %hi(paAddobject), %o1
F00C41EC: d20260a4                 ld      [%o1+%lo(paAddobject)], %o1! SEL
F00C41F0: 4000b5a0                 call    _objc_msgSend
F00C41F4: 94100018                 mov     %i0, %o2
F00C41F8: 133c030f92126398         set     _checkSharedIrqLevels, %o1
F00C4200: 113c04fb                 sethi   %hi(_top_devinfo), %o0
F00C4204: d0022088                 ld      [%o0+%lo(_top_devinfo)], %o0
F00C4208: 7fffb2ae                 call    _walk_devs
F00C420C: 94062010                 add     %i0, 0x10, %o2
F00C4210: 81c7e008                 ret
F00C4214: 81e80000                 restore
