F00C51A4: 9de3bf90                 save    %sp, -0x70, %sp
F00C51A8: 7ffd08a4                 call    _strlen
F00C51AC: 9010001a                 mov     %i2, %o0
F00C51B0: a2022008                 add     %o0, 8, %l1
F00C51B4: 4000035f                 call    _IOMalloc
F00C51B8: 90100011                 mov     %l1, %o0
F00C51BC: a0920000                 orcc    %o0, %g0, %l0
F00C51C0: 02800019                 be      loc_F00C5224
F00C51C4: 90100010                 mov     %l0, %o0! __dst
F00C51C8: 7ffd08d8                 call    _strcpy
F00C51CC: 9210001a                 mov     %i2, %o1
F00C51D0: 90100010                 mov     %l0, %o0! name
F00C51D4: 133c03ea                 sethi   %hi(aVersion), %o1! "Version"
F00C51D8: 7ffd0028                 call    _strcat
F00C51DC: 92126178                 bset    %lo(aVersion), %o1! "Version"
F00C51E0: 4000b2c9                 call    _objc_getClass
F00C51E4: 90100010                 mov     %l0, %o0
F00C51E8: b0100008                 mov     %o0, %i0
F00C51EC: 90100010                 mov     %l0, %o0! __s
F00C51F0: 40000355                 call    _IOFree
F00C51F4: 92100011                 mov     %l1, %o1
F00C51F8: 80a62000                 cmp     %i0, 0
F00C51FC: 22800029                 be,a    locret_F00C52A0
F00C5200: b0103fff                 mov     -1, %i0
F00C5204: 7ffd088d                 call    _strlen
F00C5208: 9010001a                 mov     %i2, %o0
F00C520C: a2022014                 add     %o0, 0x14, %l1
F00C5210: 40000348                 call    _IOMalloc
F00C5214: 90100011                 mov     %l1, %o0
F00C5218: a0920000                 orcc    %o0, %g0, %l0
F00C521C: 12800004                 bne     loc_F00C522C
F00C5220: 90100010                 mov     %l0, %o0! __dst
F00C5224: 1080001f                 ba      locret_F00C52A0
F00C5228: b0103fff                 mov     -1, %i0
F00C522C: 133c03ea92126180         set     aDriverkitversi, %o1! "driverKitVersionFor"
F00C5234: 7ffd081b                 call    _memcpy
F00C5238: 94102014                 mov     0x14, %o2
F00C523C: 90100010                 mov     %l0, %o0! str
F00C5240: 7ffd000e                 call    _strcat
F00C5244: 9210001a                 mov     %i2, %o1
F00C5248: 4000b9d6                 call    _sel_getUid
F00C524C: 90100010                 mov     %l0, %o0
F00C5250: b4100008                 mov     %o0, %i2
F00C5254: 90100018                 mov     %i0, %o0! id
F00C5258: 133c0504                 sethi   %hi(paRespondsto), %o1
F00C525C: d2026270                 ld      [%o1+%lo(paRespondsto)], %o1! SEL
F00C5260: 4000b184                 call    _objc_msgSend
F00C5264: 9410001a                 mov     %i2, %o2
F00C5268: 912a2018                 sll     %o0, 24, %o0
F00C526C: 80a22000                 cmp     %o0, 0
F00C5270: 02800008                 be      loc_F00C5290
F00C5274: 90100018                 mov     %i0, %o0! id
F00C5278: 133c0506                 sethi   %hi(paPerform), %o1
F00C527C: d20261d4                 ld      [%o1+%lo(paPerform)], %o1! SEL
F00C5280: 4000b17c                 call    _objc_msgSend
F00C5284: 9410001a                 mov     %i2, %o2
F00C5288: 10800003                 ba      loc_F00C5294
F00C528C: b0100008                 mov     %o0, %i0
F00C5290: b0103fff                 mov     -1, %i0
F00C5294: 90100010                 mov     %l0, %o0
F00C5298: 4000032b                 call    _IOFree
F00C529C: 92100011                 mov     %l1, %o1
F00C52A0: 81c7e008                 ret
F00C52A4: 81e80000                 restore
