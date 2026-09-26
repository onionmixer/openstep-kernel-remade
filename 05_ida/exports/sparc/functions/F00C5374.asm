F00C5374: 9de3bf90                 save    %sp, -0x70, %sp
F00C5378: e0070000                 ld      [%i4], %l0
F00C537C: 80a42000                 cmp     %l0, 0
F00C5380: 22800002                 be,a    loc_F00C5388
F00C5384: a0102200                 mov     0x200, %l0
F00C5388: 9010001b                 mov     %i3, %o0! __s1
F00C538C: 133c03ea                 sethi   %hi(aIoclassname), %o1! "IOClassName"
F00C5390: 7ffd0b87                 call    _strcmp
F00C5394: 921261c8                 bset    %lo(aIoclassname), %o1! "IOClassName"
F00C5398: 80a22000                 cmp     %o0, 0
F00C539C: 1280000b                 bne     loc_F00C53C8
F00C53A0: 9010001b                 mov     %i3, %o0
F00C53A4: 113c0504                 sethi   %hi(paClass), %o0! id
F00C53A8: d2022014                 ld      [%o0+%lo(paClass)], %o1! SEL
F00C53AC: 4000b131                 call    _objc_msgSend
F00C53B0: 90100018                 mov     %i0, %o0! id
F00C53B4: 133c0504                 sethi   %hi(paName), %o1! SEL
F00C53B8: 4000b12e                 call    _objc_msgSend
F00C53BC: d2026008                 ld      [%o1+%lo(paName)], %o1
F00C53C0: 10800011                 ba      loc_F00C5404
F00C53C4: b0100008                 mov     %o0, %i0
F00C53C8: 133c03ea                 sethi   %hi(aIodevicename), %o1! "IODeviceName"
F00C53CC: 7ffd0b78                 call    _strcmp
F00C53D0: 921261d8                 bset    %lo(aIodevicename), %o1! "IODeviceName"
F00C53D4: 80a22000                 cmp     %o0, 0
F00C53D8: 12800004                 bne     loc_F00C53E8
F00C53DC: 9010001b                 mov     %i3, %o0! __s
F00C53E0: 10800009                 ba      loc_F00C5404
F00C53E4: b0062008                 inc     8, %i0
F00C53E8: 133c03ea                 sethi   %hi(aIodevicekind), %o1! "IODeviceKind"
F00C53EC: 7ffd0b70                 call    _strcmp
F00C53F0: 921261e8                 bset    %lo(aIodevicekind), %o1! "IODeviceKind"
F00C53F4: 80a22000                 cmp     %o0, 0
F00C53F8: 32800011                 bne,a   locret_F00C543C
F00C53FC: b0103d39                 mov     -0x2C7, %i0
F00C5400: b00620a8                 inc     0xA8, %i0
F00C5404: 7ffd080d                 call    _strlen
F00C5408: 90100018                 mov     %i0, %o0
F00C540C: b6100008                 mov     %o0, %i3
F00C5410: 80a6c010                 cmp     %i3, %l0
F00C5414: 3a800002                 bcc,a   loc_F00C541C
F00C5418: b6043fff                 add     %l0, -1, %i3
F00C541C: 9006e001                 add     %i3, 1, %o0
F00C5420: d0270000                 st      %o0, [%i4]
F00C5424: 9010001a                 mov     %i2, %o0! __dst
F00C5428: 92100018                 mov     %i0, %o1! __src
F00C542C: 7ffd093c                 call    _strncpy
F00C5430: 9410001b                 mov     %i3, %o2
F00C5434: c02e801b                 clrb    [%i2+%i3]
F00C5438: b0102000                 mov     0, %i0
F00C543C: 81c7e008                 ret
F00C5440: 81e80000                 restore
