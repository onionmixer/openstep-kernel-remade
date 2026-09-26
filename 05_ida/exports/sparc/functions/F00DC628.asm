F00DC628: 9de3bf90                 save    %sp, -0x70, %sp
F00DC62C: f027bff0                 st      %i0, [%fp+var_10]
F00DC630: 9007bff0                 add     %fp, var_10, %o0! objc_super *
F00DC634: 133c0508                 sethi   %hi(stru_F01422CC.super_class), %o1
F00DC638: d40262d0                 ld      [%o1+%lo(stru_F01422CC.super_class)], %o2
F00DC63C: 9610001b                 mov     %i3, %o3
F00DC640: 133c0505                 sethi   %hi(paDmacompletedes), %o1
F00DC644: d427bff4                 st      %o2, [%fp+var_C]
F00DC648: d202609c                 ld      [%o1+%lo(paDmacompletedes)], %o1! SEL
F00DC64C: 400054cc                 call    _objc_msgSendSuper
F00DC650: 9410001a                 mov     %i2, %o2
F00DC654: d04e2078                 ldsb    [%i0+0x78], %o0
F00DC658: 80a22000                 cmp     %o0, 0
F00DC65C: 02800005                 be      locret_F00DC670
F00DC660: 113c0505                 sethi   %hi(paReturnrecorded), %o0! id
F00DC664: d2022034                 ld      [%o0+%lo(paReturnrecorded)], %o1! SEL
F00DC668: 40005482                 call    _objc_msgSend
F00DC66C: 90100018                 mov     %i0, %o0
F00DC670: 81c7e008                 ret
F00DC674: 81e80000                 restore
