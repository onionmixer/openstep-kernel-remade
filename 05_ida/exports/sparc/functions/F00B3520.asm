F00B3520: 9de3bf98                 save    %sp, -0x68, %sp
F00B3524: 273c0477                 sethi   %hi(dword_F011DFB8), %l3
F00B3528: d004e3b8                 ld      [%l3+%lo(dword_F011DFB8)], %o0
F00B352C: 80a22000                 cmp     %o0, 0
F00B3530: 02800007                 be      loc_F00B354C
F00B3534: 80a66000                 cmp     %i1, 0
F00B3538: d206200c                 ld      [%i0+0xC], %o1
F00B353C: 113c0478                 sethi   %hi(aObioEncodeRegE), %o0! "obio_encode_reg(): encoding <%s> "
F00B3540: 7ffd8446                 call    _printf
F00B3544: 90122070                 bset    %lo(aObioEncodeRegE), %o0! "obio_encode_reg(): encoding <%s> "
F00B3548: 80a66000                 cmp     %i1, 0
F00B354C: 02800014                 be      loc_F00B359C
F00B3550: 80a62000                 cmp     %i0, 0
F00B3554: 02800012                 be      loc_F00B359C
F00B3558: c02e4000                 clrb    [%i1]
F00B355C: d0060000                 ld      [%i0], %o0
F00B3560: 80a22000                 cmp     %o0, 0
F00B3564: 32800004                 bne,a   loc_F00B3574
F00B3568: d2062028                 ld      [%i0+0x28], %o1
F00B356C: 10800037                 ba      locret_F00B3648
F00B3570: b0103fff                 mov     -1, %i0
F00B3574: 90026001                 add     %o1, 1, %o0
F00B3578: 80a22001                 cmp     %o0, 1
F00B357C: 1880000a                 bgu     loc_F00B35A4
F00B3580: d004e3b8                 ld      [%l3+0x3B8], %o0
F00B3584: 80a22000                 cmp     %o0, 0
F00B3588: 02800005                 be      loc_F00B359C
F00B358C: 113c0478                 sethi   %hi(aObioEncodeRegI), %o0! "obio_encode_reg(): Invalid nodeid in <%"...
F00B3590: d206200c                 ld      [%i0+0xC], %o1
F00B3594: 7ffd8431                 call    _printf
F00B3598: 90122098                 bset    %lo(aObioEncodeRegI), %o0! "obio_encode_reg(): Invalid nodeid in <%"...
F00B359C: 1080002b                 ba      locret_F00B3648
F00B35A0: b0102000                 mov     0, %i0
F00B35A4: 90100009                 mov     %o1, %o0
F00B35A8: 133c0478                 sethi   %hi(aReg_2), %o1! "reg"
F00B35AC: 7ffff6d5                 call    _getproplen
F00B35B0: 921260c8                 bset    %lo(aReg_2), %o1! "reg"
F00B35B4: a4100008                 mov     %o0, %l2
F00B35B8: d0062028                 ld      [%i0+0x28], %o0
F00B35BC: 133c0478                 sethi   %hi(aReg_3), %o1! "reg"
F00B35C0: 7ffff6d6                 call    _getlongprop
F00B35C4: 921260d0                 bset    %lo(aReg_3), %o1! "reg"
F00B35C8: a2920000                 orcc    %o0, %g0, %l1
F00B35CC: 3280000b                 bne,a   loc_F00B35F8
F00B35D0: e0044000                 ld      [%l1], %l0
F00B35D4: d004e3b8                 ld      [%l3+0x3B8], %o0
F00B35D8: 80a22000                 cmp     %o0, 0
F00B35DC: 0280001a                 be      loc_F00B3644
F00B35E0: 113c0478                 sethi   %hi(aNoAddrQualifie), %o0! "no addr qualifier (reg) for nodeid <%x>"...
F00B35E4: d2062028                 ld      [%i0+0x28], %o1
F00B35E8: 7ffd841c                 call    _printf
F00B35EC: 901220d8                 bset    %lo(aNoAddrQualifie), %o0! "no addr qualifier (reg) for nodeid <%x>"...
F00B35F0: 10800016                 ba      locret_F00B3648
F00B35F4: b0102001                 mov     1, %i0
F00B35F8: 90100011                 mov     %l1, %o0
F00B35FC: f0046004                 ld      [%l1+4], %i0
F00B3600: 7ffed2e8                 call    _kfree
F00B3604: 92100012                 mov     %l2, %o1
F00B3608: 90100019                 mov     %i1, %o0! char *
F00B360C: 133c047892126108         set     aXX, %o1! "%x,%x"
F00B3614: 94100010                 mov     %l0, %o2
F00B3618: 7ffd8454                 call    _sprintf
F00B361C: 96100018                 mov     %i0, %o3
F00B3620: d004e3b8                 ld      [%l3+0x3B8], %o0
F00B3624: 80a22000                 cmp     %o0, 0
F00B3628: 02800007                 be      loc_F00B3644
F00B362C: 113c0478                 sethi   %hi(aAddrXRegAddrXR), %o0! "addr %x, reg_addr %x returning <%s>\n"
F00B3630: 90122110                 bset    %lo(aAddrXRegAddrXR), %o0! "addr %x, reg_addr %x returning <%s>\n"
F00B3634: 92100018                 mov     %i0, %o1
F00B3638: d4046004                 ld      [%l1+4], %o2
F00B363C: 7ffd8407                 call    _printf
F00B3640: 96100019                 mov     %i1, %o3
F00B3644: b0102001                 mov     1, %i0
F00B3648: 81c7e008                 ret
F00B364C: 81e80000                 restore
