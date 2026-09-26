F005CD78: 9de3bf98                 save    %sp, -0x68, %sp
F005CD7C: 9206fff0                 add     %i3, -0x10, %o1
F005CD80: 80a26005                 cmp     %o1, 5! switch 6 cases
F005CD84: 18800035                 bgu     def_F005CD9C! jumptable F005CD9C default case
F005CD88: f0068000                 ld      [%i2], %i0
F005CD8C: 113c0173901221a4         set     jpt_F005CD9C, %o0
F005CD94: 932a6002                 sll     %o1, 2, %o1
F005CD98: d0024008                 ld      [%o1+%o0], %o0
F005CD9C: 81c20000                 jmp     %o0! switch jump
F005CDA0: 01000000                 nop
F005CDBC: 10800022                 ba      loc_F005CE44! jumptable F005CD9C cases 0,4,5
F005CDC0: 11000080                 sethi   0x20000, %o0
F005CDC4: 11000400                 sethi   0x100000, %o0! jumptable F005CD9C cases 1-3
F005CDC8: 808e0008                 btst    %o0, %i0
F005CDCC: 32800027                 bne,a   locret_F005CE68
F005CDD0: b0102001                 mov     1, %i0
F005CDD4: 11000140                 sethi   0x50000, %o0
F005CDD8: 808e0008                 btst    %o0, %i0
F005CDDC: 22800023                 be,a    locret_F005CE68
F005CDE0: b0102000                 mov     0, %i0
F005CDE4: f406a004                 ld      [%i2+4], %i2
F005CDE8: d0068000                 ld      [%i2], %o0
F005CDEC: 80a22000                 cmp     %o0, 0
F005CDF0: 12bffffe                 bne     loc_F005CDE8
F005CDF4: 01000000                 nop
F005CDF8: 4000e82c                 call    _simple_lock_try
F005CDFC: 9010001a                 mov     %i2, %o0
F005CE00: 80a22000                 cmp     %o0, 0
F005CE04: 02bffff9                 be      loc_F005CDE8
F005CE08: 01000000                 nop
F005CE0C: d006a008                 ld      [%i2+8], %o0
F005CE10: c0268000                 clr     [%i2]
F005CE14: 80a22000                 cmp     %o0, 0
F005CE18: 06800008                 bl      loc_F005CE38
F005CE1C: 80a6e012                 cmp     %i3, 0x12
F005CE20: 11001000                 sethi   0x400000, %o0
F005CE24: 808e0008                 btst    %o0, %i0
F005CE28: 02800010                 be      locret_F005CE68
F005CE2C: b0102001                 mov     1, %i0
F005CE30: 1080000e                 ba      locret_F005CE68
F005CE34: b0102000                 mov     0, %i0
F005CE38: 12800003                 bne     loc_F005CE44
F005CE3C: 11000040                 sethi   0x10000, %o0
F005CE40: 11000100                 sethi   0x40000, %o0
F005CE44: 808e0008                 btst    %o0, %i0
F005CE48: 12800008                 bne     locret_F005CE68
F005CE4C: b0102001                 mov     1, %i0
F005CE50: 10800006                 ba      locret_F005CE68
F005CE54: b0102000                 mov     0, %i0
F005CE58: 113c043d                 sethi   %hi(aIpcRightCopyin), %o0! jumptable F005CD9C default case
F005CE5C: 7ffee0c5                 call    _panic
F005CE60: 901222f8                 bset    %lo(aIpcRightCopyin), %o0! "ipc_right_copyin_check: strange rights"
F005CE64: b0102001                 mov     1, %i0
F005CE68: 81c7e008                 ret
F005CE6C: 81e80000                 restore
