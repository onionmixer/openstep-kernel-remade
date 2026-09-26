F00CA768: 9de3bf78                 save    %sp, -0x88, %sp
F00CA76C: 113c0504                 sethi   %hi(paInit), %o0
F00CA770: d202202c                 ld      [%o0+%lo(paInit)], %o1! SEL
F00CA774: e207a05c                 ld      [%fp+arg_5C], %l1
F00CA778: 113c0508                 sethi   %hi(stru_F014204C.super_class), %o0
F00CA77C: d4022050                 ld      [%o0+%lo(stru_F014204C.super_class)], %o2
F00CA780: f027bff0                 st      %i0, [%fp+var_10]
F00CA784: e007a060                 ld      [%fp+arg_60], %l0
F00CA788: 9007bff0                 add     %fp, var_10, %o0! objc_super *
F00CA78C: 40009c7c                 call    _objc_msgSendSuper
F00CA790: d427bff4                 st      %o2, [%fp+var_C]
F00CA794: f823a05c                 st      %i4, [%sp+0x88+var_2C]
F00CA798: fa23a060                 st      %i5, [%sp+0x88+var_28]
F00CA79C: e223a064                 st      %l1, [%sp+0x88+var_24]
F00CA7A0: e023a068                 st      %l0, [%sp+0x88+var_20]
F00CA7A4: c023a06c                 clr     [%sp+0x88+var_1C]
F00CA7A8: f423a070                 st      %i2, [%sp+0x88+var_18]
F00CA7AC: 113c032990122280         set     sub_F00CA680, %o0
F00CA7B4: 92102000                 mov     0, %o1
F00CA7B8: 153c0329                 sethi   %hi(sub_F00CA6B8), %o2
F00CA7BC: 173c0329                 sethi   %hi(sub_F00CA6F4), %o3
F00CA7C0: 193c0329                 sethi   %hi(sub_F00CA72C), %o4
F00CA7C4: 9412a2b8                 bset    %lo(sub_F00CA6B8), %o2
F00CA7C8: 9612e2f4                 bset    %lo(sub_F00CA6F4), %o3
F00CA7CC: 9813232c                 bset    %lo(sub_F00CA72C), %o4
F00CA7D0: 7ffd8601                 call    _if_attach
F00CA7D4: 9a10001b                 mov     %i3, %o5
F00CA7D8: d0262004                 st      %o0, [%i0+4]
F00CA7DC: 81c7e008                 ret
F00CA7E0: 81e80000                 restore
