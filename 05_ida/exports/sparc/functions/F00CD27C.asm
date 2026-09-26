F00CD27C: 9de3bf90                 save    %sp, -0x70, %sp
F00CD280: d006222c                 ld      [%i0+0x22C], %o0! id
F00CD284: 133c0504                 sethi   %hi(paLock), %o1
F00CD288: d2026000                 ld      [%o1+%lo(paLock)], %o1! SEL
F00CD28C: 40009179                 call    _objc_msgSend
F00CD290: e207a05c                 ld      [%fp+arg_5C], %l1
F00CD294: 113c0504                 sethi   %hi(paNumberoftarget), %o0! id
F00CD298: d20221f0                 ld      [%o0+%lo(paNumberoftarget)], %o1! SEL
F00CD29C: a0102000                 mov     0, %l0
F00CD2A0: 40009174                 call    _objc_msgSend
F00CD2A4: 90100018                 mov     %i0, %o0
F00CD2A8: 9210001b                 mov     %i3, %o1
F00CD2AC: 80a24008                 cmp     %o1, %o0
F00CD2B0: 36800026                 bge,a   loc_F00CD348
F00CD2B4: a0102001                 mov     1, %l0
F00CD2B8: 90100018                 mov     %i0, %o0! id
F00CD2BC: 133c0506                 sethi   %hi(paSearchreserveq), %o1! SEL
F00CD2C0: 9410001a                 mov     %i2, %o2
F00CD2C4: 9610001b                 mov     %i3, %o3
F00CD2C8: 9810001c                 mov     %i4, %o4
F00CD2CC: 9a10001d                 mov     %i5, %o5
F00CD2D0: 40009168                 call    _objc_msgSend
F00CD2D4: d2026000                 ld      [%o1+%lo(paSearchreserveq)], %o1
F00CD2D8: 80a22000                 cmp     %o0, 0
F00CD2DC: 02800008                 be      loc_F00CD2FC
F00CD2E0: 01000000                 nop
F00CD2E4: 10800019                 ba      loc_F00CD348
F00CD2E8: a0102001                 mov     1, %l0
F00CD2EC: d226212c                 st      %o1, [%i0+0x12C]
F00CD2F0: d4226014                 st      %o2, [%o1+0x14]
F00CD2F4: 10800012                 ba      loc_F00CD33C
F00CD2F8: d4226018                 st      %o2, [%o1+0x18]
F00CD2FC: 7fffe30d                 call    _IOMalloc
F00CD300: 90102020                 mov     0x20, %o0 ! ' '
F00CD304: 92100008                 mov     %o0, %o1
F00CD308: f43a4000                 std     %i2, [%o1]
F00CD30C: f83a6008                 std     %i4, [%o1+8]
F00CD310: e2226010                 st      %l1, [%o1+0x10]
F00CD314: 94062128                 add     %i0, 0x128, %o2
F00CD318: d0062128                 ld      [%i0+0x128], %o0
F00CD31C: 80a28008                 cmp     %o2, %o0
F00CD320: 22bffff3                 be,a    loc_F00CD2EC
F00CD324: d2262128                 st      %o1, [%i0+0x128]
F00CD328: d006212c                 ld      [%i0+0x12C], %o0
F00CD32C: d0226018                 st      %o0, [%o1+0x18]
F00CD330: d4226014                 st      %o2, [%o1+0x14]
F00CD334: d226212c                 st      %o1, [%i0+0x12C]
F00CD338: d2222014                 st      %o1, [%o0+0x14]
F00CD33C: d0062228                 ld      [%i0+0x228], %o0
F00CD340: 90022001                 inc     %o0
F00CD344: d0262228                 st      %o0, [%i0+0x228]
F00CD348: d006222c                 ld      [%i0+0x22C], %o0! id
F00CD34C: 133c0504                 sethi   %hi(paUnlock), %o1! SEL
F00CD350: 40009148                 call    _objc_msgSend
F00CD354: d2026244                 ld      [%o1+%lo(paUnlock)], %o1
F00CD358: 81c7e008                 ret
F00CD35C: 91e80010                 restore %g0, %l0, %o0
