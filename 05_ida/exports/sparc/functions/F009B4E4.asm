F009B4E4: 9de3bf98                 save    %sp, -0x68, %sp
F009B4E8: 40000043                 call    _vik_mmu_print_sfsr
F009B4EC: 90100018                 mov     %i0, %o0
F009B4F0: 808e2002                 btst    2, %i0
F009B4F4: 22800007                 be,a    loc_F009B510
F009B4F8: 113c045e                 sethi   -0xFEE8800, %o0
F009B4FC: 113c045e90122010         set     aFaultVirtualAd_0, %o0! "\tFault Virtual Address = 0x%x\n"
F009B504: 7ffde455                 call    _printf
F009B508: 92100019                 mov     %i1, %o1
F009B50C: 113c045e                 sethi   -0xFEE8800, %o0! char *
F009B510: 7ffde452                 call    _printf
F009B514: 90122030                 bset    0x30, %o0 ! '0'
F009B518: 80a6a000                 cmp     %i2, 0
F009B51C: 36800006                 bge,a   loc_F009B534
F009B520: 11010000                 sethi   0x4000000, %o0
F009B524: 113c045e                 sethi   %hi(aMultipleErrors), %o0! "\tMultiple Errors\n"
F009B528: 7ffde44c                 call    _printf
F009B52C: 90122048                 bset    %lo(aMultipleErrors), %o0! "\tMultiple Errors\n"
F009B530: 11010000                 sethi   0x4000000, %o0
F009B534: 808e8008                 btst    %o0, %i2
F009B538: 02800004                 be      loc_F009B548
F009B53C: 113c045e                 sethi   %hi(aAsynchronousEr), %o0! "\tAsynchronous Error\n"
F009B540: 7ffde446                 call    _printf
F009B544: 90122060                 bset    %lo(aAsynchronousEr), %o0! "\tAsynchronous Error\n"
F009B548: 11080000                 sethi   0x20000000, %o0
F009B54C: 808e8008                 btst    %o0, %i2
F009B550: 02800004                 be      loc_F009B560
F009B554: 113c045e                 sethi   %hi(aCacheConsisten), %o0! "\tCache Consistency Error\n"
F009B558: 7ffde440                 call    _printf
F009B55C: 90122078                 bset    %lo(aCacheConsisten), %o0! "\tCache Consistency Error\n"
F009B560: 11020000                 sethi   0x8000000, %o0
F009B564: 808e8008                 btst    %o0, %i2
F009B568: 02800004                 be      loc_F009B578
F009B56C: 113c045e                 sethi   %hi(aEParityError), %o0! "\tE$ Parity Error\n"
F009B570: 7ffde43a                 call    _printf
F009B574: 90122098                 bset    %lo(aEParityError), %o0! "\tE$ Parity Error\n"
F009B578: 11008000                 sethi   0x2000000, %o0
F009B57C: 808e8008                 btst    %o0, %i2
F009B580: 0280001b                 be      locret_F009B5EC
F009B584: 808ea040                 btst    0x40, %i2 ! '@'
F009B588: 113c045e                 sethi   %hi(aRequestedTrans), %o0! "\tRequested transaction: %s CCOP %x at "...
F009B58C: 02800005                 be      loc_F009B5A0
F009B590: 941220b0                 or      %o0, %lo(aRequestedTrans), %o2! "\tRequested transaction: %s CCOP %x at "...
F009B594: 113c045e                 sethi   %hi(aSupv_1), %o0! "supv "
F009B598: 10800004                 ba      loc_F009B5A8
F009B59C: 921220e0                 or      %o0, %lo(aSupv_1), %o1! "supv "
F009B5A0: 113c045e921220e8         set     aUser_2, %o1! "user "
F009B5A8: 9010000a                 mov     %o2, %o0! char *
F009B5AC: 15007fe0                 sethi   0x1FF8000, %o2
F009B5B0: 940e800a                 and     %i2, %o2, %o2
F009B5B4: 960ea00f                 and     %i2, 0xF, %o3
F009B5B8: 7ffde428                 call    _printf
F009B5BC: 9810001b                 mov     %i3, %o4
F009B5C0: 1100001f90122380         set     0x7F80, %o0
F009B5C8: 900e8008                 and     %i2, %o0, %o0
F009B5CC: 91322007                 srl     %o0, 7, %o0
F009B5D0: 133c045d92126360         set     _mod_err_type, %o1
F009B5D8: 912a2002                 sll     %o0, 2, %o0
F009B5DC: d2020009                 ld      [%o0+%o1], %o1
F009B5E0: 113c045e                 sethi   %hi(aErrorTypeS), %o0! "\tError type: %s\n"
F009B5E4: 7ffde41d                 call    _printf
F009B5E8: 901220f0                 bset    %lo(aErrorTypeS), %o0! "\tError type: %s\n"
F009B5EC: 81c7e008                 ret
F009B5F0: 81e80000                 restore
