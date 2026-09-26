F00EF730: 9de3be88                 save    %sp, -0x178, %sp
F00EF734: 40000d08                 call    __objc_headerCount
F00EF738: 01000000                 nop
F00EF73C: a6100008                 mov     %o0, %l3
F00EF740: 40000ca3                 call    __objc_headerVector
F00EF744: 90102000                 mov     0, %o0
F00EF748: 80a60019                 cmp     %i0, %i1
F00EF74C: 028000a1                 be      locret_F00EF9D0
F00EF750: ac100008                 mov     %o0, %l6
F00EF754: d0062004                 ld      [%i0+4], %o0
F00EF758: 80a20019                 cmp     %o0, %i1
F00EF75C: 0280000b                 be      loc_F00EF788
F00EF760: 133c0506                 sethi   %hi(paError), %o1
F00EF764: 90100018                 mov     %i0, %o0! id
F00EF768: d2026228                 ld      [%o1+%lo(paError)], %o1! SEL
F00EF76C: 153c03e89412a2f0         set     aSPoseasSTarget, %o2! "[%s poseAs:%s]: target not immediate su"...
F00EF774: d6062008                 ld      [%i0+8], %o3
F00EF778: 4000083e                 call    _objc_msgSend
F00EF77C: d8066008                 ld      [%i1+8], %o4
F00EF780: 10800094                 ba      locret_F00EF9D0
F00EF784: b0100008                 mov     %o0, %i0
F00EF788: d0062018                 ld      [%i0+0x18], %o0
F00EF78C: 80a22000                 cmp     %o0, 0
F00EF790: 0280000c                 be      loc_F00EF7C0
F00EF794: 153c03e8                 sethi   %hi(aSPoseasSSDefin), %o2! "[%s poseAs:%s]: %s defines new instance"...
F00EF798: 133c0506                 sethi   %hi(paError), %o1
F00EF79C: 90100018                 mov     %i0, %o0! id
F00EF7A0: d2026228                 ld      [%o1+%lo(paError)], %o1! SEL
F00EF7A4: 9412a320                 bset    %lo(aSPoseasSSDefin), %o2! "[%s poseAs:%s]: %s defines new instance"...
F00EF7A8: d6062008                 ld      [%i0+8], %o3! size
F00EF7AC: d8066008                 ld      [%i1+8], %o4
F00EF7B0: 40000830                 call    _objc_msgSend
F00EF7B4: 9a10000b                 mov     %o3, %o5
F00EF7B8: 10800086                 ba      locret_F00EF9D0
F00EF7BC: b0100008                 mov     %o0, %i0
F00EF7C0: 113c03f4921220c0         set     asc_F00FD0C0, %o1! "_%"
F00EF7C8: d01220c0                 lduh    [%o0+0xC0], %o0
F00EF7CC: d037bef8                 sth     %o0, [%fp+__s1]
F00EF7D0: d00a6002                 ldub    [%o1+2], %o0
F00EF7D4: d02fbefa                 stb     %o0, [%fp+var_106]
F00EF7D8: a007bef8                 add     %fp, __s1, %l0
F00EF7DC: 90100010                 mov     %l0, %o0! __s
F00EF7E0: 7ffc56a6                 call    _strcat
F00EF7E4: d2066008                 ld      [%i1+8], %o1! __src
F00EF7E8: 7ffc5f14                 call    _strlen
F00EF7EC: 90100010                 mov     %l0, %o0! __dst
F00EF7F0: 400000ec                 call    sub_F00EFBA0
F00EF7F4: 90022001                 inc     %o0
F00EF7F8: a4100008                 mov     %o0, %l2
F00EF7FC: 7ffc5f4b                 call    _strcpy
F00EF800: 92100010                 mov     %l0, %o1! data
F00EF804: 7fffffa8                 call    sub_F00EF6A4
F00EF808: 90100019                 mov     %i1, %o0
F00EF80C: 7fffffa6                 call    sub_F00EF6A4
F00EF810: 90100018                 mov     %i0, %o0! table
F00EF814: 4000092f                 call    _objc_getClasses
F00EF818: 01000000                 nop
F00EF81C: a2100008                 mov     %o0, %l1
F00EF820: 7ffff8df                 call    _NXHashRemove
F00EF824: 92100018                 mov     %i0, %o1! data
F00EF828: 90100011                 mov     %l1, %o0! table
F00EF82C: 7ffff8dc                 call    _NXHashRemove
F00EF830: 92100019                 mov     %i1, %o1! size_t
F00EF834: 90100018                 mov     %i0, %o0! id
F00EF838: 7ffff2e6                 call    _object_copy
F00EF83C: 92102000                 mov     0, %o1! data
F00EF840: a0100008                 mov     %o0, %l0
F00EF844: 90100011                 mov     %l1, %o0! table
F00EF848: 7ffff80c                 call    _NXHashInsert
F00EF84C: 92100010                 mov     %l0, %o1
F00EF850: d0062010                 ld      [%i0+0x10], %o0
F00EF854: 90122008                 bset    8, %o0
F00EF858: d0262010                 st      %o0, [%i0+0x10]
F00EF85C: d2060000                 ld      [%i0], %o1
F00EF860: d0026010                 ld      [%o1+0x10], %o0
F00EF864: 90122008                 bset    8, %o0
F00EF868: d0226010                 st      %o0, [%o1+0x10]
F00EF86C: d0066008                 ld      [%i1+8], %o0
F00EF870: d0262008                 st      %o0, [%i0+8]
F00EF874: d2060000                 ld      [%i0], %o1
F00EF878: d0064000                 ld      [%i1], %o0
F00EF87C: d0022008                 ld      [%o0+8], %o0
F00EF880: d0226008                 st      %o0, [%o1+8]
F00EF884: d006600c                 ld      [%i1+0xC], %o0
F00EF888: d026200c                 st      %o0, [%i0+0xC]
F00EF88C: 9007bef0                 add     %fp, var_110, %o0
F00EF890: d023a040                 st      %o0, [%sp+0x178+var_138]
F00EF894: 90100011                 mov     %l1, %o0! table
F00EF898: 7ffff953                 call    _NXInitHashState
F00EF89C: 01000000                 nop
F00EF8A0: 00000008                 illtrap
F00EF8A4: 90100011                 mov     %l1, %o0! table
F00EF8A8: 9207bef0                 add     %fp, var_110, %o1! state
F00EF8AC: 7ffff959                 call    _NXNextHashState
F00EF8B0: 9407beec                 add     %fp, var_114, %o2
F00EF8B4: 80a22000                 cmp     %o0, 0
F00EF8B8: 02800018                 be      loc_F00EF918
F00EF8BC: d007beec                 ld      [%fp+var_114], %o0
F00EF8C0: 80a22000                 cmp     %o0, 0
F00EF8C4: 22bffff9                 be,a    loc_F00EF8A8
F00EF8C8: 90100011                 mov     %l1, %o0
F00EF8CC: 80a20018                 cmp     %o0, %i0
F00EF8D0: 02bffff6                 be      loc_F00EF8A8
F00EF8D4: 90100011                 mov     %l1, %o0
F00EF8D8: d207beec                 ld      [%fp+var_114], %o1
F00EF8DC: 80a24010                 cmp     %o1, %l0
F00EF8E0: 22bffff3                 be,a    loc_F00EF8AC
F00EF8E4: 9207bef0                 add     %fp, var_110, %o1
F00EF8E8: d0026004                 ld      [%o1+4], %o0
F00EF8EC: 80a20019                 cmp     %o0, %i1
F00EF8F0: 12800007                 bne     loc_F00EF90C
F00EF8F4: d007beec                 ld      [%fp+var_114], %o0
F00EF8F8: f0226004                 st      %i0, [%o1+4]
F00EF8FC: d2024000                 ld      [%o1], %o1
F00EF900: d0060000                 ld      [%i0], %o0
F00EF904: 10bfffe8                 ba      loc_F00EF8A4
F00EF908: d0226004                 st      %o0, [%o1+4]
F00EF90C: d0022004                 ld      [%o0+4], %o0
F00EF910: 10bfffec                 ba      loc_F00EF8C0
F00EF914: d027beec                 st      %o0, [%fp+var_114]
F00EF918: a0102000                 mov     0, %l0
F00EF91C: 80a40013                 cmp     %l0, %l3
F00EF920: 1a800023                 bcc     loc_F00EF9AC
F00EF924: 9004a001                 add     %l2, 1, %o0
F00EF928: 2b3c03f4                 sethi   -0xFF03000, %l5
F00EF92C: 293c03f4                 sethi   -0xFF03000, %l4
F00EF930: 912c2001                 sll     %l0, 1, %o0
F00EF934: 90020010                 add     %o0, %l0, %o0
F00EF938: 912a2003                 sll     %o0, 3, %o0
F00EF93C: d0058008                 ld      [%l6+%o0], %o0! mhp
F00EF940: 921560c8                 or      %l5, 0xC8, %o1! segname
F00EF944: 941520d0                 or      %l4, 0xD0, %o2! sectname
F00EF948: 7ffde9bb                 call    _getsectdatafromheader
F00EF94C: 9607bee8                 add     %fp, var_118, %o3
F00EF950: 96920000                 orcc    %o0, %g0, %o3
F00EF954: 02800011                 be      loc_F00EF998
F00EF958: d007bee8                 ld      [%fp+var_118], %o0
F00EF95C: 94102000                 mov     0, %o2
F00EF960: 91322002                 srl     %o0, 2, %o0
F00EF964: 80a28008                 cmp     %o2, %o0
F00EF968: 1a80000c                 bcc     loc_F00EF998
F00EF96C: d007bee8                 ld      [%fp+var_118], %o0
F00EF970: 99322002                 srl     %o0, 2, %o4
F00EF974: 932aa002                 sll     %o2, 2, %o1
F00EF978: d002c009                 ld      [%o3+%o1], %o0
F00EF97C: 80a20019                 cmp     %o0, %i1
F00EF980: 22800002                 be,a    loc_F00EF988
F00EF984: f022c009                 st      %i0, [%o3+%o1]
F00EF988: 9402a001                 inc     %o2
F00EF98C: 80a2800c                 cmp     %o2, %o4
F00EF990: 2abffffa                 bcs,a   loc_F00EF978
F00EF994: 932aa002                 sll     %o2, 2, %o1! data
F00EF998: a0042001                 inc     %l0
F00EF99C: 80a40013                 cmp     %l0, %l3
F00EF9A0: 0abfffe5                 bcs     loc_F00EF934
F00EF9A4: 912c2001                 sll     %l0, 1, %o0
F00EF9A8: 9004a001                 add     %l2, 1, %o0
F00EF9AC: d0266008                 st      %o0, [%i1+8]
F00EF9B0: d0064000                 ld      [%i1], %o0
F00EF9B4: e4222008                 st      %l2, [%o0+8]
F00EF9B8: 90100011                 mov     %l1, %o0! table
F00EF9BC: 7ffff7af                 call    _NXHashInsert
F00EF9C0: 92100018                 mov     %i0, %o1! data
F00EF9C4: 90100011                 mov     %l1, %o0! table
F00EF9C8: 7ffff7ac                 call    _NXHashInsert
F00EF9CC: 92100019                 mov     %i1, %o1
F00EF9D0: 81c7e008                 ret
F00EF9D4: 81e80000                 restore
