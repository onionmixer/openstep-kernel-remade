F00B8244: 9de3bf90                 save    %sp, -0x70, %sp
F00B8248: 113c047c                 sethi   %hi(_scsi_options), %o0
F00B824C: d0022158                 ld      [%o0+%lo(_scsi_options)], %o0
F00B8250: 808a2002                 btst    2, %o0
F00B8254: 02800007                 be      loc_F00B8270
F00B8258: e207a05c                 ld      [%fp+arg_5C], %l1
F00B825C: 113c047c90122178         set     aMakeDeviceSD, %o0! "make device %s%d\n"
F00B8264: 9210001b                 mov     %i3, %o1! size_t
F00B8268: 7ffd70fc                 call    _printf
F00B826C: 9410001c                 mov     %i4, %o2
F00B8270: 7ffebf80                 call    _kalloc
F00B8274: 90102020                 mov     0x20, %o0 ! ' '
F00B8278: a0920000                 orcc    %o0, %g0, %l0
F00B827C: 12800004                 bne     loc_F00B828C
F00B8280: 90100010                 mov     %l0, %o0! void *
F00B8284: 10800072                 ba      locret_F00B844C
F00B8288: b0102000                 mov     0, %i0
F00B828C: 7fff72f3                 call    _bzero
F00B8290: 92102020                 mov     0x20, %o1 ! ' '! size_t
F00B8294: f0242004                 st      %i0, [%l0+4]
F00B8298: fa342008                 sth     %i5, [%l0+8]
F00B829C: e22c200a                 stb     %l1, [%l0+0xA]
F00B82A0: 7ffebf74                 call    _kalloc
F00B82A4: 90102038                 mov     0x38, %o0! void *
F00B82A8: 80a22000                 cmp     %o0, 0
F00B82AC: 02800034                 be      loc_F00B837C
F00B82B0: d024200c                 st      %o0, [%l0+0xC]
F00B82B4: 7fff72e9                 call    _bzero
F00B82B8: 92102038                 mov     0x38, %o1 ! '8'
F00B82BC: 7ffebf6d                 call    _kalloc
F00B82C0: 90102008                 mov     8, %o0
F00B82C4: d204200c                 ld      [%l0+0xC], %o1
F00B82C8: d022601c                 st      %o0, [%o1+0x1C]
F00B82CC: d204200c                 ld      [%l0+0xC], %o1! size_t
F00B82D0: d002601c                 ld      [%o1+0x1C], %o0
F00B82D4: 80a22000                 cmp     %o0, 0
F00B82D8: 12800004                 bne     loc_F00B82E8
F00B82DC: 01000000                 nop
F00B82E0: 10800025                 ba      loc_F00B8374
F00B82E4: 90100009                 mov     %o1, %o0! void *
F00B82E8: 7fff72dc                 call    _bzero
F00B82EC: 92102008                 mov     8, %o1
F00B82F0: d004200c                 ld      [%l0+0xC], %o0
F00B82F4: f2220000                 st      %i1, [%o0]
F00B82F8: d2066008                 ld      [%i1+8], %o1
F00B82FC: 80a26000                 cmp     %o1, 0
F00B8300: 02800004                 be      loc_F00B8310
F00B8304: d004200c                 ld      [%l0+0xC], %o0
F00B8308: d2222004                 st      %o1, [%o0+4]
F00B830C: d004200c                 ld      [%l0+0xC], %o0
F00B8310: d0266008                 st      %o0, [%i1+8]
F00B8314: d004200c                 ld      [%l0+0xC], %o0
F00B8318: f622200c                 st      %i3, [%o0+0xC]
F00B831C: d004200c                 ld      [%l0+0xC], %o0
F00B8320: f822202c                 st      %i4, [%o0+0x2C]
F00B8324: d0060000                 ld      [%i0], %o0
F00B8328: d204200c                 ld      [%l0+0xC], %o1
F00B832C: 913a2008                 sra     %o0, 8, %o0
F00B8330: d202601c                 ld      [%o1+0x1C], %o1
F00B8334: 900a200f                 and     %o0, 0xF, %o0
F00B8338: d0224000                 st      %o0, [%o1]
F00B833C: d206a004                 ld      [%i2+4], %o1
F00B8340: 9fc24000                 call    %o1
F00B8344: 90100010                 mov     %l0, %o0
F00B8348: 80a22000                 cmp     %o0, 0
F00B834C: 36800011                 bge,a   loc_F00B8390
F00B8350: d00c201c                 ldub    [%l0+0x1C], %o0
F00B8354: d004200c                 ld      [%l0+0xC], %o0
F00B8358: d0022004                 ld      [%o0+4], %o0
F00B835C: d0266008                 st      %o0, [%i1+8]
F00B8360: d004200c                 ld      [%l0+0xC], %o0
F00B8364: d002201c                 ld      [%o0+0x1C], %o0
F00B8368: 7ffebf8e                 call    _kfree
F00B836C: 92102008                 mov     8, %o1
F00B8370: d004200c                 ld      [%l0+0xC], %o0
F00B8374: 7ffebf8b                 call    _kfree
F00B8378: 92102038                 mov     0x38, %o1 ! '8'
F00B837C: 90100010                 mov     %l0, %o0
F00B8380: 7ffebf88                 call    _kfree
F00B8384: 92102020                 mov     0x20, %o1 ! ' '
F00B8388: 10800031                 ba      locret_F00B844C
F00B838C: b0102000                 mov     0, %i0
F00B8390: 80a22000                 cmp     %o0, 0
F00B8394: 0280000d                 be      loc_F00B83C8
F00B8398: 113c047c                 sethi   %hi(aSDAtSDTargetDL), %o0! "%s%d at %s%d target %d lun %d\n"
F00B839C: 90122190                 bset    %lo(aSDAtSDTargetDL), %o0! "%s%d at %s%d target %d lun %d\n"
F00B83A0: 9210001b                 mov     %i3, %o1
F00B83A4: d606600c                 ld      [%i1+0xC], %o3
F00B83A8: 9410001c                 mov     %i4, %o2
F00B83AC: d806602c                 ld      [%i1+0x2C], %o4
F00B83B0: 9a10001d                 mov     %i5, %o5
F00B83B4: 7ffd70a9                 call    _printf
F00B83B8: e223a05c                 st      %l1, [%sp+0x70+var_14]
F00B83BC: d206a008                 ld      [%i2+8], %o1
F00B83C0: 9fc24000                 call    %o1
F00B83C4: 90100010                 mov     %l0, %o0
F00B83C8: 113c04fc                 sethi   %hi(_sd_root), %o0
F00B83CC: d20220a8                 ld      [%o0+%lo(_sd_root)], %o1
F00B83D0: 80a26000                 cmp     %o1, 0
F00B83D4: 22800009                 be,a    loc_F00B83F8
F00B83D8: e02220a8                 st      %l0, [%o0+%lo(_sd_root)]
F00B83DC: 10800003                 ba      loc_F00B83E8
F00B83E0: d0024000                 ld      [%o1], %o0
F00B83E4: d0024000                 ld      [%o1], %o0
F00B83E8: 80a22000                 cmp     %o0, 0
F00B83EC: 32bffffe                 bne,a   loc_F00B83E4
F00B83F0: d2024000                 ld      [%o1], %o1
F00B83F4: e0224000                 st      %l0, [%o1]
F00B83F8: d2062018                 ld      [%i0+0x18], %o1
F00B83FC: 113c02e290122180         set     _scsi_std_pktalloc, %o0
F00B8404: 80a24008                 cmp     %o1, %o0
F00B8408: 32800011                 bne,a   locret_F00B844C
F00B840C: b0102001                 mov     1, %i0
F00B8410: 113c04fc                 sethi   %hi(_nscsi_devices), %o0
F00B8414: d00220a0                 ld      [%o0+%lo(_nscsi_devices)], %o0
F00B8418: 133c047c                 sethi   %hi(_scsi_ncmds_per_dev), %o1
F00B841C: e0026150                 ld      [%o1+%lo(_scsi_ncmds_per_dev)], %l0
F00B8420: 90022001                 inc     %o0
F00B8424: 7ffd3837                 call    _umul
F00B8428: 92100010                 mov     %l0, %o1
F00B842C: 133c04fc                 sethi   %hi(_scsi_ncmds), %o1
F00B8430: d20260b8                 ld      [%o1+%lo(_scsi_ncmds)], %o1
F00B8434: 80a20009                 cmp     %o0, %o1
F00B8438: 04800005                 ble     locret_F00B844C
F00B843C: b0102001                 mov     1, %i0
F00B8440: 40000124                 call    _scsi_addcmds
F00B8444: 90100010                 mov     %l0, %o0
F00B8448: b0102001                 mov     1, %i0
F00B844C: 81c7e008                 ret
F00B8450: 81e80000                 restore
