F00810EC: 9de3bf90                 save    %sp, -0x70, %sp
F00810F0: b0102000                 mov     0, %i0
F00810F4: c027bff0                 clr     [%fp+var_10]
F00810F8: 92100019                 mov     %i1, %o1
F00810FC: 94102006                 mov     6, %o2
F0081100: 113c04d0                 sethi   %hi(_active_threads), %o0
F0081104: d0022260                 ld      [%o0+%lo(_active_threads)], %o0
F0081108: 96102000                 mov     0, %o3
F008110C: d002200c                 ld      [%o0+0xC], %o0
F0081110: 7fff9b3e                 call    _object_copyin
F0081114: 9807bff4                 add     %fp, var_C, %o4
F0081118: 80a22000                 cmp     %o0, 0
F008111C: 2280001b                 be,a    loc_F0081188
F0081120: b0102004                 mov     4, %i0
F0081124: 7fff9a56                 call    _convert_port_to_thread
F0081128: d007bff4                 ld      [%fp+var_C], %o0
F008112C: a0100008                 mov     %o0, %l0
F0081130: 7fff9b61                 call    _port_release
F0081134: d007bff4                 ld      [%fp+var_C], %o0
F0081138: 80a42000                 cmp     %l0, 0
F008113C: 02800012                 be      loc_F0081184
F0081140: 9010001b                 mov     %i3, %o0
F0081144: 9210001c                 mov     %i4, %o1
F0081148: 9410001d                 mov     %i5, %o2
F008114C: d8042084                 ld      [%l0+0x84], %o4
F0081150: 9607bff0                 add     %fp, var_10, %o3
F0081154: 40000016                 call    sub_F00811AC
F0081158: 98032044                 inc     0x44, %o4 ! 'D'
F008115C: d207bff0                 ld      [%fp+var_10], %o1
F0081160: 80a26000                 cmp     %o1, 0
F0081164: 02800004                 be      loc_F0081174
F0081168: 01000000                 nop
F008116C: 7ffe4af0                 call    _thread_psignal
F0081170: 90100010                 mov     %l0, %o0
F0081174: 7fffcc8e                 call    _thread_deallocate
F0081178: 90100010                 mov     %l0, %o0
F008117C: 10800004                 ba      loc_F008118C
F0081180: 213c04c3                 sethi   -0xFECF400, %l0
F0081184: b0102004                 mov     4, %i0
F0081188: 213c04c3                 sethi   -0xFECF400, %l0
F008118C: d0042360                 ld      [%l0+0x360], %o0
F0081190: 4001cab7                 call    _port_deallocate_EXTERNAL
F0081194: 9210001a                 mov     %i2, %o1
F0081198: d0042360                 ld      [%l0+0x360], %o0
F008119C: 4001cab4                 call    _port_deallocate_EXTERNAL
F00811A0: 92100019                 mov     %i1, %o1
F00811A4: 81c7e008                 ret
F00811A8: 81e80000                 restore
