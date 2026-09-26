F00AE620: 9de3bf80                 save    %sp, -0x80, %sp
F00AE624: 80a6e001                 cmp     %i3, 1
F00AE628: 02800015                 be      loc_F00AE67C
F00AE62C: 9210001a                 mov     %i2, %o1
F00AE630: 80a6e001                 cmp     %i3, 1
F00AE634: 14800006                 bg      loc_F00AE64C
F00AE638: 80a6e002                 cmp     %i3, 2
F00AE63C: 80a6e000                 cmp     %i3, 0
F00AE640: 02800008                 be      loc_F00AE660
F00AE644: 9007bff4                 add     %fp, var_C, %o0
F00AE648: 3080004c                 ba,a    locret_F00AE778
F00AE64C: 02800017                 be      loc_F00AE6A8
F00AE650: 80a6e003                 cmp     %i3, 3
F00AE654: 0280002a                 be      loc_F00AE6FC
F00AE658: 9007bff4                 add     %fp, var_C, %o0
F00AE65C: 30800047                 ba,a    locret_F00AE778
F00AE660: d6062014                 ld      [%i0+0x14], %o3
F00AE664: 9fc2c000                 call    %o3
F00AE668: 94100018                 mov     %i0, %o2
F00AE66C: d207bff4                 ld      [%fp+var_C], %o1
F00AE670: 7fffff03                 call    sub_F00AE27C
F00AE674: 90100019                 mov     %i1, %o0
F00AE678: 30800040                 ba,a    locret_F00AE778
F00AE67C: 9007bff4                 add     %fp, var_C, %o0
F00AE680: d6062014                 ld      [%i0+0x14], %o3
F00AE684: 9fc2c000                 call    %o3
F00AE688: 94100018                 mov     %i0, %o2
F00AE68C: 90100018                 mov     %i0, %o0
F00AE690: 92100019                 mov     %i1, %o1
F00AE694: d607bff4                 ld      [%fp+var_C], %o3
F00AE698: 9407bff0                 add     %fp, var_10, %o2
F00AE69C: 7fffff13                 call    _unpacksingle
F00AE6A0: d627bff0                 st      %o3, [%fp+var_10]
F00AE6A4: 30800035                 ba,a    locret_F00AE778
F00AE6A8: 9007bff4                 add     %fp, var_C, %o0
F00AE6AC: 2100003fa01423fe         set     0xFFFE, %l0
F00AE6B4: a00a4010                 and     %o1, %l0, %l0
F00AE6B8: 92100010                 mov     %l0, %o1
F00AE6BC: d6062014                 ld      [%i0+0x14], %o3
F00AE6C0: 9fc2c000                 call    %o3
F00AE6C4: 94100018                 mov     %i0, %o2
F00AE6C8: 9007bfec                 add     %fp, var_14, %o0
F00AE6CC: 92042001                 add     %l0, 1, %o1
F00AE6D0: d6062014                 ld      [%i0+0x14], %o3
F00AE6D4: 9fc2c000                 call    %o3
F00AE6D8: 94100018                 mov     %i0, %o2
F00AE6DC: 90100018                 mov     %i0, %o0
F00AE6E0: 92100019                 mov     %i1, %o1
F00AE6E4: d807bff4                 ld      [%fp+var_C], %o4
F00AE6E8: 9407bff0                 add     %fp, var_10, %o2
F00AE6EC: d607bfec                 ld      [%fp+var_14], %o3
F00AE6F0: 7fffff3e                 call    _unpackdouble
F00AE6F4: d827bff0                 st      %o4, [%fp+var_10]
F00AE6F8: 30800020                 ba,a    locret_F00AE778
F00AE6FC: 2100003fa01423fc         set     0xFFFC, %l0
F00AE704: a00a4010                 and     %o1, %l0, %l0
F00AE708: 92100010                 mov     %l0, %o1
F00AE70C: d6062014                 ld      [%i0+0x14], %o3
F00AE710: 9fc2c000                 call    %o3
F00AE714: 94100018                 mov     %i0, %o2
F00AE718: 9007bfec                 add     %fp, var_14, %o0
F00AE71C: 92042001                 add     %l0, 1, %o1
F00AE720: d6062014                 ld      [%i0+0x14], %o3
F00AE724: 9fc2c000                 call    %o3
F00AE728: 94100018                 mov     %i0, %o2
F00AE72C: 9007bfe8                 add     %fp, var_18, %o0
F00AE730: 92042002                 add     %l0, 2, %o1
F00AE734: d6062014                 ld      [%i0+0x14], %o3
F00AE738: 9fc2c000                 call    %o3
F00AE73C: 94100018                 mov     %i0, %o2
F00AE740: 9007bfe4                 add     %fp, var_1C, %o0
F00AE744: 92042003                 add     %l0, 3, %o1
F00AE748: d6062014                 ld      [%i0+0x14], %o3
F00AE74C: 9fc2c000                 call    %o3
F00AE750: 94100018                 mov     %i0, %o2
F00AE754: d607bfec                 ld      [%fp+var_14], %o3
F00AE758: 90100018                 mov     %i0, %o0
F00AE75C: c407bff4                 ld      [%fp+var_C], %g2
F00AE760: 92100019                 mov     %i1, %o1
F00AE764: d807bfe8                 ld      [%fp+var_18], %o4
F00AE768: 9407bff0                 add     %fp, var_10, %o2
F00AE76C: da07bfe4                 ld      [%fp+var_1C], %o5
F00AE770: 7fffff65                 call    sub_F00AE504
F00AE774: c427bff0                 st      %g2, [%fp+var_10]
F00AE778: 81c7e008                 ret
F00AE77C: 81e80000                 restore
