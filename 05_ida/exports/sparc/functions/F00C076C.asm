F00C076C: 9de3bf90                 save    %sp, -0x70, %sp
F00C0770: a0100018                 mov     %i0, %l0
F00C0774: b0103d3e                 mov     -0x2C2, %i0
F00C0778: 9010001b                 mov     %i3, %o0! __s1
F00C077C: e2070000                 ld      [%i4], %l1
F00C0780: 133c0483                 sethi   %hi(aEvsCurrentmous), %o1! "Evs_CurrentMouseScaling"
F00C0784: 7ffd1e8a                 call    _strcmp
F00C0788: 92126100                 bset    %lo(aEvsCurrentmous), %o1! "Evs_CurrentMouseScaling"
F00C078C: 80a22000                 cmp     %o0, 0
F00C0790: 12800011                 bne     loc_F00C07D4
F00C0794: 9010001b                 mov     %i3, %o0
F00C0798: 90047fff                 add     %l1, -1, %o0
F00C079C: 91322001                 srl     %o0, 1, %o0
F00C07A0: d0268000                 st      %o0, [%i2]
F00C07A4: 90100010                 mov     %l0, %o0! id
F00C07A8: 9410001a                 mov     %i2, %o2
F00C07AC: 133c0504                 sethi   %hi(paPointerscaling_0), %o1
F00C07B0: d20262f8                 ld      [%o1+%lo(paPointerscaling_0)], %o1! SEL
F00C07B4: 4000c42f                 call    _objc_msgSend
F00C07B8: 9606a004                 add     %i2, 4, %o3
F00C07BC: d0068000                 ld      [%i2], %o0
F00C07C0: b0102000                 mov     0, %i0
F00C07C4: 912a2001                 sll     %o0, 1, %o0! __s1
F00C07C8: 90022001                 inc     %o0
F00C07CC: 10800036                 ba      locret_F00C08A4
F00C07D0: d0270000                 st      %o0, [%i4]
F00C07D4: 133c0483                 sethi   %hi(aEvsCurrentmous_0), %o1! "Evs_CurrentMouseHandedness"
F00C07D8: 7ffd1e75                 call    _strcmp
F00C07DC: 92126118                 bset    %lo(aEvsCurrentmous_0), %o1! "Evs_CurrentMouseHandedness"
F00C07E0: 80a22000                 cmp     %o0, 0
F00C07E4: 32800012                 bne,a   loc_F00C082C
F00C07E8: 9010001b                 mov     %i3, %o0
F00C07EC: 80a46000                 cmp     %l1, 0
F00C07F0: 0280002d                 be      locret_F00C08A4
F00C07F4: 90102001                 mov     1, %o0
F00C07F8: d0270000                 st      %o0, [%i4]
F00C07FC: d0042124                 ld      [%l0+0x124], %o0! id
F00C0800: 133c0504                 sethi   %hi(paLock), %o1! SEL
F00C0804: 4000c41b                 call    _objc_msgSend
F00C0808: d2026000                 ld      [%o1+%lo(paLock)], %o1
F00C080C: d4042134                 ld      [%l0+0x134], %o2
F00C0810: 113c0504                 sethi   %hi(paUnlock), %o0
F00C0814: d2022244                 ld      [%o0+%lo(paUnlock)], %o1! SEL
F00C0818: d4268000                 st      %o2, [%i2]
F00C081C: d0042124                 ld      [%l0+0x124], %o0! id
F00C0820: 4000c414                 call    _objc_msgSend
F00C0824: b0102000                 mov     0, %i0
F00C0828: 3080001f                 ba,a    locret_F00C08A4
F00C082C: 133c0483                 sethi   %hi(aEvsEventdevice_1), %o1! "Evs_EventDeviceInfo"
F00C0830: 7ffd1e5f                 call    _strcmp
F00C0834: 92126138                 bset    %lo(aEvsEventdevice_1), %o1! "Evs_EventDeviceInfo"
F00C0838: 80a22000                 cmp     %o0, 0
F00C083C: 3280000c                 bne,a   loc_F00C086C
F00C0840: e027bff0                 st      %l0, [%fp+var_10]
F00C0844: c0270000                 clr     [%i4]
F00C0848: 92102004                 mov     4, %o1
F00C084C: d2268000                 st      %o1, [%i2]
F00C0850: 90102002                 mov     2, %o0
F00C0854: d026a008                 st      %o0, [%i2+8]
F00C0858: c026a004                 clr     [%i2+4]
F00C085C: c026a00c                 clr     [%i2+0xC]
F00C0860: d2270000                 st      %o1, [%i4]
F00C0864: 10800010                 ba      locret_F00C08A4
F00C0868: b0102000                 mov     0, %i0
F00C086C: 9007bff0                 add     %fp, var_10, %o0! objc_super *
F00C0870: 9410001a                 mov     %i2, %o2
F00C0874: 133c0507                 sethi   %hi(stru_F0141D7C.super_class), %o1
F00C0878: d8026180                 ld      [%o1+%lo(stru_F0141D7C.super_class)], %o4
F00C087C: 9610001b                 mov     %i3, %o3
F00C0880: 133c0504                 sethi   %hi(paGetintvaluesFo_0), %o1
F00C0884: d827bff4                 st      %o4, [%fp+var_C]
F00C0888: d20262c8                 ld      [%o1+%lo(paGetintvaluesFo_0)], %o1! SEL
F00C088C: 4000c43c                 call    _objc_msgSendSuper
F00C0890: 9810001c                 mov     %i4, %o4
F00C0894: b0100008                 mov     %o0, %i0
F00C0898: 80a63d39                 cmp     %i0, -0x2C7
F00C089C: 22800002                 be,a    locret_F00C08A4
F00C08A0: b0103d3e                 mov     -0x2C2, %i0
F00C08A4: 81c7e008                 ret
F00C08A8: 81e80000                 restore
