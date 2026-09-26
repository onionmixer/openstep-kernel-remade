F00697B8: 9de3bf98                 save    %sp, -0x68, %sp
F00697BC: 80a66000                 cmp     %i1, 0
F00697C0: 113c04d0                 sethi   %hi(_active_threads), %o0
F00697C4: e0022260                 ld      [%o0+%lo(_active_threads)], %l0
F00697C8: 02800009                 be      loc_F00697EC
F00697CC: a2102000                 mov     0, %l1
F00697D0: d00420e0                 ld      [%l0+0xE0], %o0
F00697D4: 90020018                 add     %o0, %i0, %o0
F00697D8: 80a22000                 cmp     %o0, 0
F00697DC: 1680000c                 bge     loc_F006980C
F00697E0: d02420e0                 st      %o0, [%l0+0xE0]
F00697E4: 10800008                 ba      loc_F0069804
F00697E8: 900420e0                 add     %l0, 0xE0, %o0
F00697EC: d00420f0                 ld      [%l0+0xF0], %o0
F00697F0: 90020018                 add     %o0, %i0, %o0
F00697F4: 80a22000                 cmp     %o0, 0
F00697F8: 16800005                 bge     loc_F006980C
F00697FC: d02420f0                 st      %o0, [%l0+0xF0]
F0069800: 900420f0                 add     %l0, 0xF0, %o0
F0069804: 40003855                 call    _timer_normalize
F0069808: 01000000                 nop
F006980C: 80a66000                 cmp     %i1, 0
F0069810: 02800004                 be      loc_F0069820
F0069814: 113c04d2                 sethi   -0xFECB800, %o0
F0069818: 1080000a                 ba      loc_F0069840
F006981C: 96102000                 mov     0, %o3
F0069820: 901221b0                 bset    0x1B0, %o0
F0069824: 932c6002                 sll     %l1, 2, %o1
F0069828: d0024008                 ld      [%o1+%o0], %o0
F006982C: d0022114                 ld      [%o0+0x114], %o0
F0069830: 80a22002                 cmp     %o0, 2
F0069834: 02800003                 be      loc_F0069840
F0069838: 96102002                 mov     2, %o3
F006983C: 96102001                 mov     1, %o3
F0069840: 952c6005                 sll     %l1, 5, %o2
F0069844: 113c04d190122360         set     _machine_slot, %o0
F006984C: 932ae002                 sll     %o3, 2, %o1
F0069850: 94028008                 add     %o2, %o0, %o2
F0069854: 9202400a                 add     %o1, %o2, %o1
F0069858: d0026010                 ld      [%o1+0x10], %o0
F006985C: 90022001                 inc     %o0
F0069860: d0226010                 st      %o0, [%o1+0x10]
F0069864: d004204c                 ld      [%l0+0x4C], %o0
F0069868: 808a2080                 btst    0x80, %o0
F006986C: 12800007                 bne     loc_F0069888
F0069870: 113c04d0                 sethi   -0xFECC000, %o0
F0069874: 90100011                 mov     %l1, %o0
F0069878: 92100010                 mov     %l0, %o1
F006987C: 40001457                 call    _thread_quantum_update
F0069880: 94102001                 mov     1, %o2
F0069884: 113c04d0                 sethi   -0xFECC000, %o0
F0069888: d00220c8                 ld      [%o0+0xC8], %o0
F006988C: 80a44008                 cmp     %l1, %o0
F0069890: 1280002c                 bne     locret_F0069940
F0069894: 153c043e                 sethi   %hi(_timedelta), %o2
F0069898: d202a3f0                 ld      [%o2+%lo(_timedelta)], %o1
F006989C: 80a26000                 cmp     %o1, 0
F00698A0: 0280000d                 be      loc_F00698D4
F00698A4: 173c043e                 sethi   -0xFEF0800, %o3
F00698A8: 16800006                 bge     loc_F00698C0
F00698AC: 113c043e                 sethi   %hi(_tickdelta), %o0
F00698B0: d00223f4                 ld      [%o0+%lo(_tickdelta)], %o0
F00698B4: b0260008                 sub     %i0, %o0, %i0
F00698B8: 10800005                 ba      loc_F00698CC
F00698BC: 90024008                 add     %o1, %o0, %o0
F00698C0: d00223f4                 ld      [%o0+0x3F4], %o0
F00698C4: b0060008                 add     %i0, %o0, %i0
F00698C8: 90224008                 sub     %o1, %o0, %o0
F00698CC: d022a3f0                 st      %o0, [%o2+0x3F0]
F00698D0: 173c043e                 sethi   -0xFEF0800, %o3
F00698D4: 9412e3e8                 or      %o3, 0x3E8, %o2
F00698D8: d002a004                 ld      [%o2+4], %o0
F00698DC: b0020018                 add     %o0, %i0, %i0
F00698E0: 110003d09012223f         set     0xF423F, %o0
F00698E8: 80a60008                 cmp     %i0, %o0
F00698EC: 04800009                 ble     loc_F0069910
F00698F0: f022a004                 st      %i0, [%o2+4]
F00698F4: 113ffc2f901221c0         set     -0xF4240, %o0
F00698FC: d202e3e8                 ld      [%o3+0x3E8], %o1
F0069900: 90060008                 add     %i0, %o0, %o0
F0069904: d022a004                 st      %o0, [%o2+4]
F0069908: 92026001                 inc     %o1
F006990C: d222e3e8                 st      %o1, [%o3+0x3E8]
F0069910: 113c043f                 sethi   %hi(_mtime), %o0
F0069914: d4022000                 ld      [%o0+%lo(_mtime)], %o2
F0069918: 80a2a000                 cmp     %o2, 0
F006991C: 02800009                 be      locret_F0069940
F0069920: 133c043e                 sethi   %hi(_time), %o1
F0069924: d00263e8                 ld      [%o1+%lo(_time)], %o0
F0069928: d022a008                 st      %o0, [%o2+8]
F006992C: 901263e8                 or      %o1, %lo(_time), %o0
F0069930: d0022004                 ld      [%o0+4], %o0
F0069934: d022a004                 st      %o0, [%o2+4]
F0069938: d00263e8                 ld      [%o1+%lo(_time)], %o0
F006993C: d0228000                 st      %o0, [%o2]
F0069940: 81c7e008                 ret
F0069944: 81e80000                 restore
