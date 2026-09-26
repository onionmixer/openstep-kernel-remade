F00D4814: 9de3bf78                 save    %sp, -0x88, %sp
F00D4818: 7fffc631                 call    _IOGetTimestamp
F00D481C: 9007bfe8                 add     %fp, var_18, %o0
F00D4820: 9010205a                 mov     0x5A, %o0 ! 'Z'
F00D4824: d023a05c                 st      %o0, [%sp+0x88+var_2C]
F00D4828: 90100018                 mov     %i0, %o0! id
F00D482C: 133c0505                 sethi   %hi(paAbsolutepointe), %o1
F00D4830: b92f2018                 sll     %i4, 24, %i4
F00D4834: 993f2018                 sra     %i4, 24, %o4
F00D4838: d41fbfe8                 ldd     [%fp+var_18], %o2
F00D483C: 9a10001d                 mov     %i5, %o5
F00D4840: d2026280                 ld      [%o1+%lo(paAbsolutepointe)], %o1! SEL
F00D4844: d43ba060                 std     %o2, [%sp+0x88+var_28]
F00D4848: 9410001a                 mov     %i2, %o2
F00D484C: 40007409                 call    _objc_msgSend
F00D4850: 9610001b                 mov     %i3, %o3
F00D4854: 81c7e008                 ret
F00D4858: 81e80000                 restore
