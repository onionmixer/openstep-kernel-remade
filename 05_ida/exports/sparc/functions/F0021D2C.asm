F0021D2C: 9de3bf98                 save    %sp, -0x68, %sp! int
F0021D30: 253c04cf                 sethi   %hi(dword_F0133DDC), %l2
F0021D34: d004a1dc                 ld      [%l2+%lo(dword_F0133DDC)], %o0
F0021D38: e0022024                 ld      [%o0+0x24], %l0
F0021D3C: d0040000                 ld      [%l0], %o0
F0021D40: 400001a4                 call    _getsock
F0021D44: a2102000                 mov     0, %l1
F0021D48: a6920000                 orcc    %o0, %g0, %l3
F0021D4C: 0280002b                 be      locret_F0021DF8
F0021D50: 01000000                 nop
F0021D54: d0042010                 ld      [%l0+0x10], %o0
F0021D58: 80a22070                 cmp     %o0, 0x70 ! 'p'
F0021D5C: 04800004                 ble     loc_F0021D6C
F0021D60: d204a1dc                 ld      [%l2+%lo(dword_F0133DDC)], %o1
F0021D64: 10800024                 ba      loc_F0021DF4
F0021D68: 90102016                 mov     0x16, %o0
F0021D6C: d004200c                 ld      [%l0+0xC], %o0
F0021D70: 80a22000                 cmp     %o0, 0
F0021D74: 02800019                 be      loc_F0021DD8
F0021D78: 90102001                 mov     1, %o0
F0021D7C: 7fffeef8                 call    _m_get
F0021D80: 9210200a                 mov     0xA, %o1
F0021D84: a2920000                 orcc    %o0, %g0, %l1
F0021D88: 32800005                 bne,a   loc_F0021D9C
F0021D8C: d004200c                 ld      [%l0+0xC], %o0
F0021D90: d204a1dc                 ld      [%l2+0x1DC], %o1
F0021D94: 10800018                 ba      loc_F0021DF4
F0021D98: 90102037                 mov     0x37, %o0 ! '7'! int
F0021D9C: d2046004                 ld      [%l1+4], %o1! int
F0021DA0: d4042010                 ld      [%l0+0x10], %o2! int
F0021DA4: 4001d8ad                 call    _copyin
F0021DA8: 92044009                 add     %l1, %o1, %o1
F0021DAC: d204a1dc                 ld      [%l2+0x1DC], %o1
F0021DB0: d02a6038                 stb     %o0, [%o1+0x38]
F0021DB4: d004a1dc                 ld      [%l2+0x1DC], %o0
F0021DB8: d04a2038                 ldsb    [%o0+0x38], %o0
F0021DBC: 80a22000                 cmp     %o0, 0
F0021DC0: 22800005                 be,a    loc_F0021DD4
F0021DC4: d0042010                 ld      [%l0+0x10], %o0
F0021DC8: 7fffef3b                 call    _m_free
F0021DCC: 90100011                 mov     %l1, %o0
F0021DD0: 3080000a                 ba,a    locret_F0021DF8
F0021DD4: d0346008                 sth     %o0, [%l1+8]
F0021DD8: d004e018                 ld      [%l3+0x18], %o0
F0021DDC: d2042004                 ld      [%l0+4], %o1
F0021DE0: d4042008                 ld      [%l0+8], %o2
F0021DE4: 7ffff725                 call    _sosetopt
F0021DE8: 96100011                 mov     %l1, %o3
F0021DEC: 133c04cf                 sethi   %hi(dword_F0133DDC), %o1
F0021DF0: d20261dc                 ld      [%o1+%lo(dword_F0133DDC)], %o1
F0021DF4: d02a6038                 stb     %o0, [%o1+0x38]
F0021DF8: 81c7e008                 ret
F0021DFC: 81e80000                 restore
