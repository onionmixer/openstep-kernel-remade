F0022FEC: 9de3bf98                 save    %sp, -0x68, %sp
F0022FF0: 133c04d4                 sethi   %hi(_unp_gcing), %o1
F0022FF4: d00262c8                 ld      [%o1+%lo(_unp_gcing)], %o0
F0022FF8: 80a22000                 cmp     %o0, 0
F0022FFC: 12800078                 bne     locret_F00231DC
F0023000: 90102001                 mov     1, %o0
F0023004: d02262c8                 st      %o0, [%o1+%lo(_unp_gcing)]
F0023008: 113c04d4                 sethi   -0xFECB000, %o0
F002300C: c02222c0                 clr     [%o0+0x2C0]
F0023010: 113c04d0                 sethi   %hi(_file_list), %o0
F0023014: e0022058                 ld      [%o0+%lo(_file_list)], %l0
F0023018: 90122058                 bset    %lo(_file_list), %o0
F002301C: 80a40008                 cmp     %l0, %o0
F0023020: 0280000b                 be      loc_F002304C
F0023024: 293c04d0                 sethi   -0xFECC000, %l4
F0023028: 92100008                 mov     %o0, %o1
F002302C: d0042008                 ld      [%l0+8], %o0
F0023030: 900a3fcf                 and     %o0, -0x31, %o0
F0023034: d0242008                 st      %o0, [%l0+8]
F0023038: e0040000                 ld      [%l0], %l0
F002303C: 80a40009                 cmp     %l0, %o1
F0023040: 32bffffc                 bne,a   loc_F0023030
F0023044: d0042008                 ld      [%l0+8], %o0
F0023048: 293c04d0                 sethi   -0xFECC000, %l4
F002304C: aa152058                 or      %l4, 0x58, %l5
F0023050: 233c04d4                 sethi   -0xFECB000, %l1
F0023054: 113c042ea61223b8         set     _unixdomain, %l3
F002305C: e0052058                 ld      [%l4+0x58], %l0
F0023060: 80a40015                 cmp     %l0, %l5
F0023064: 02800039                 be      loc_F0023148
F0023068: 113c04d0                 sethi   %hi(_file_list), %o0
F002306C: a4122058                 or      %o0, %lo(_file_list), %l2
F0023070: d454200e                 ldsh    [%l0+0xE], %o2
F0023074: 80a2a000                 cmp     %o2, 0
F0023078: 22800031                 be,a    loc_F002313C
F002307C: e0040000                 ld      [%l0], %l0
F0023080: d2042008                 ld      [%l0+8], %o1
F0023084: 808a6020                 btst    0x20, %o1 ! ' '
F0023088: 02800007                 be      loc_F00230A4
F002308C: d00462c0                 ld      [%l1+0x2C0], %o0
F0023090: 920a7fdf                 and     %o1, -0x21, %o1
F0023094: d2242008                 st      %o1, [%l0+8]
F0023098: 90023fff                 inc     -1, %o0
F002309C: 1080000b                 ba      loc_F00230C8
F00230A0: d02462c0                 st      %o0, [%l1+0x2C0]
F00230A4: 808a6010                 btst    0x10, %o1
F00230A8: 32800025                 bne,a   loc_F002313C
F00230AC: e0040000                 ld      [%l0], %l0
F00230B0: d0542010                 ldsh    [%l0+0x10], %o0
F00230B4: 80a28008                 cmp     %o2, %o0
F00230B8: 22800021                 be,a    loc_F002313C
F00230BC: e0040000                 ld      [%l0], %l0
F00230C0: 90126010                 or      %o1, 0x10, %o0
F00230C4: d0242008                 st      %o0, [%l0+8]
F00230C8: d054200c                 ldsh    [%l0+0xC], %o0
F00230CC: 80a22002                 cmp     %o0, 2
F00230D0: 3280001b                 bne,a   loc_F002313C
F00230D4: e0040000                 ld      [%l0], %l0
F00230D8: d4042018                 ld      [%l0+0x18], %o2
F00230DC: 80a2a000                 cmp     %o2, 0
F00230E0: 22800017                 be,a    loc_F002313C
F00230E4: e0040000                 ld      [%l0], %l0
F00230E8: d202a00c                 ld      [%o2+0xC], %o1
F00230EC: d0026004                 ld      [%o1+4], %o0
F00230F0: 80a20013                 cmp     %o0, %l3
F00230F4: 32800012                 bne,a   loc_F002313C
F00230F8: e0040000                 ld      [%l0], %l0
F00230FC: d012600a                 lduh    [%o1+0xA], %o0
F0023100: 808a2010                 btst    0x10, %o0
F0023104: 2280000e                 be,a    loc_F002313C
F0023108: e0040000                 ld      [%l0], %l0
F002310C: d012a038                 lduh    [%o2+0x38], %o0
F0023110: 808a2001                 btst    1, %o0
F0023114: 22800006                 be,a    loc_F002312C
F0023118: d002a030                 ld      [%o2+0x30], %o0
F002311C: 7ffff491                 call    _sbwait
F0023120: 9002a024                 add     %o2, 0x24, %o0 ! '$'
F0023124: 10bfffba                 ba      loc_F002300C
F0023128: 113c04d4                 sethi   -0xFECB000, %o0
F002312C: 133c008c                 sethi   %hi(_unp_mark), %o1
F0023130: 40000035                 call    _unp_scan
F0023134: 921262a0                 bset    %lo(_unp_mark), %o1
F0023138: e0040000                 ld      [%l0], %l0
F002313C: 80a40012                 cmp     %l0, %l2
F0023140: 32bfffcd                 bne,a   loc_F0023074
F0023144: d454200e                 ldsh    [%l0+0xE], %o2
F0023148: d00462c0                 ld      [%l1+0x2C0], %o0
F002314C: 80a22000                 cmp     %o0, 0
F0023150: 12bfffc4                 bne     loc_F0023060
F0023154: e0052058                 ld      [%l4+0x58], %l0
F0023158: 113c04d0                 sethi   %hi(_file_list), %o0
F002315C: e0022058                 ld      [%o0+%lo(_file_list)], %l0
F0023160: 92122058                 or      %o0, %lo(_file_list), %o1
F0023164: 80a40009                 cmp     %l0, %o1
F0023168: 2280001c                 be,a    loc_F00231D8
F002316C: 113c04d4                 sethi   -0xFECB000, %o0
F0023170: a4100008                 mov     %o0, %l2
F0023174: a2100009                 mov     %o1, %l1
F0023178: d254200e                 ldsh    [%l0+0xE], %o1
F002317C: d0542010                 ldsh    [%l0+0x10], %o0
F0023180: 80a24008                 cmp     %o1, %o0
F0023184: 32800011                 bne,a   loc_F00231C8
F0023188: e0040000                 ld      [%l0], %l0
F002318C: d0042008                 ld      [%l0+8], %o0
F0023190: 808a2010                 btst    0x10, %o0
F0023194: 3280000d                 bne,a   loc_F00231C8
F0023198: e0040000                 ld      [%l0], %l0
F002319C: 80a26000                 cmp     %o1, 0
F00231A0: 22800009                 be,a    loc_F00231C4
F00231A4: e004a058                 ld      [%l2+0x58], %l0
F00231A8: 4000004c                 call    _unp_discard
F00231AC: 90100010                 mov     %l0, %o0
F00231B0: d0542010                 ldsh    [%l0+0x10], %o0
F00231B4: 80a22000                 cmp     %o0, 0
F00231B8: 12bffffc                 bne     loc_F00231A8
F00231BC: 01000000                 nop
F00231C0: e004a058                 ld      [%l2+0x58], %l0
F00231C4: e0040000                 ld      [%l0], %l0
F00231C8: 80a40011                 cmp     %l0, %l1
F00231CC: 32bfffec                 bne,a   loc_F002317C
F00231D0: d254200e                 ldsh    [%l0+0xE], %o1
F00231D4: 113c04d4                 sethi   -0xFECB000, %o0
F00231D8: c02222c8                 clr     [%o0+0x2C8]
F00231DC: 81c7e008                 ret
F00231E0: 81e80000                 restore
