F002A39C: 9de3bf88                 save    %sp, -0x78, %sp
F002A3A0: 40000691                 call    _if_private
F002A3A4: 90100018                 mov     %i0, %o0! __s1
F002A3A8: e002200c                 ld      [%o0+0xC], %l0
F002A3AC: 133c03d3921260f0         set     _IFCONTROL_AUTOADDR, %o1! "autoaddr"
F002A3B4: 7fff777e                 call    _strcmp
F002A3B8: 90100019                 mov     %i1, %o0
F002A3BC: 80a22000                 cmp     %o0, 0
F002A3C0: 1280000e                 bne     loc_F002A3F8
F002A3C4: 90100019                 mov     %i1, %o0
F002A3C8: d0568000                 ldsh    [%i2], %o0
F002A3CC: 80a22002                 cmp     %o0, 2
F002A3D0: 3280005c                 bne,a   locret_F002A540
F002A3D4: b010202f                 mov     0x2F, %i0 ! '/'
F002A3D8: 40000683                 call    _if_private
F002A3DC: 90100018                 mov     %i0, %o0
F002A3E0: 94100008                 mov     %o0, %o2
F002A3E4: 90100018                 mov     %i0, %o0! __s1
F002A3E8: 40001510                 call    _in_bootp
F002A3EC: 9210001a                 mov     %i2, %o1
F002A3F0: 10800054                 ba      locret_F002A540
F002A3F4: b0100008                 mov     %o0, %i0
F002A3F8: 133c03d3                 sethi   %hi(_IFCONTROL_SETADDR), %o1! "setaddr"
F002A3FC: 7fff776c                 call    _strcmp
F002A400: 921260e0                 bset    %lo(_IFCONTROL_SETADDR), %o1! "setaddr"
F002A404: 80a22000                 cmp     %o0, 0
F002A408: 12800029                 bne     loc_F002A4AC
F002A40C: 90100019                 mov     %i1, %o0
F002A410: d0568000                 ldsh    [%i2], %o0
F002A414: 80a22002                 cmp     %o0, 2
F002A418: 3280004a                 bne,a   locret_F002A540
F002A41C: b010202f                 mov     0x2F, %i0 ! '/'
F002A420: 4001b1e6                 call    _spltty
F002A424: 01000000                 nop
F002A428: b2100008                 mov     %o0, %i1
F002A42C: 40000686                 call    _if_flags
F002A430: 90100018                 mov     %i0, %o0
F002A434: 92122041                 or      %o0, 0x41, %o1
F002A438: 4000069b                 call    _if_flags_set
F002A43C: 90100018                 mov     %i0, %o0
F002A440: 40000653                 call    _if_init
F002A444: 90100010                 mov     %l0, %o0
F002A448: 40000667                 call    _if_private
F002A44C: 90100018                 mov     %i0, %o0
F002A450: d206a004                 ld      [%i2+4], %o1
F002A454: d2222008                 st      %o1, [%o0+8]
F002A458: 4000067b                 call    _if_flags
F002A45C: 90100018                 mov     %i0, %o0
F002A460: 13000010                 sethi   0x4000, %o1
F002A464: 808a0009                 btst    %o1, %o0
F002A468: 1280000d                 bne     loc_F002A49C
F002A46C: 01000000                 nop
F002A470: 4000065d                 call    _if_private
F002A474: 90100018                 mov     %i0, %o0
F002A478: d0022008                 ld      [%o0+8], %o0
F002A47C: d027bff4                 st      %o0, [%fp+var_C]
F002A480: 40000659                 call    _if_private
F002A484: 90100018                 mov     %i0, %o0
F002A488: 92100008                 mov     %o0, %o1
F002A48C: 90100018                 mov     %i0, %o0
F002A490: 9407bff4                 add     %fp, var_C, %o2
F002A494: 40000c38                 call    _arpwhohas
F002A498: 9606a004                 add     %i2, 4, %o3
F002A49C: 4001b222                 call    _splx
F002A4A0: 90100019                 mov     %i1, %o0! __s1
F002A4A4: 10800027                 ba      locret_F002A540
F002A4A8: b0102000                 mov     0, %i0
F002A4AC: 133c03d3                 sethi   %hi(_IFCONTROL_ADDMULTICAST), %o1! "add-multicast"
F002A4B0: 7fff773f                 call    _strcmp
F002A4B4: 92126130                 bset    %lo(_IFCONTROL_ADDMULTICAST), %o1! "add-multicast"
F002A4B8: 80a22000                 cmp     %o0, 0
F002A4BC: 02800008                 be      loc_F002A4DC
F002A4C0: 90100019                 mov     %i1, %o0! __s1
F002A4C4: 133c03d3                 sethi   %hi(_IFCONTROL_RMVMULTICAST), %o1! "rmv-multicast"
F002A4C8: 7fff7739                 call    _strcmp
F002A4CC: 92126140                 bset    %lo(_IFCONTROL_RMVMULTICAST), %o1! "rmv-multicast"
F002A4D0: 80a22000                 cmp     %o0, 0
F002A4D4: 12800016                 bne     loc_F002A52C
F002A4D8: 90100010                 mov     %l0, %o0
F002A4DC: d016a010                 lduh    [%i2+0x10], %o0
F002A4E0: 80a22002                 cmp     %o0, 2
F002A4E4: 12800017                 bne     locret_F002A540
F002A4E8: b010202f                 mov     0x2F, %i0 ! '/'
F002A4EC: 90102001                 mov     1, %o0
F002A4F0: d02fbfe8                 stb     %o0, [%fp+var_18]
F002A4F4: c02fbfe9                 clrb    [%fp+var_17]
F002A4F8: 9010205e                 mov     0x5E, %o0 ! '^'
F002A4FC: d02fbfea                 stb     %o0, [%fp+var_16]
F002A500: d20ea015                 ldub    [%i2+0x15], %o1
F002A504: 90100010                 mov     %l0, %o0
F002A508: 920a607f                 and     %o1, 0x7F, %o1
F002A50C: d22fbfeb                 stb     %o1, [%fp+var_15]
F002A510: d40ea016                 ldub    [%i2+0x16], %o2
F002A514: 92100019                 mov     %i1, %o1
F002A518: d42fbfec                 stb     %o2, [%fp+var_14]
F002A51C: d60ea017                 ldub    [%i2+0x17], %o3
F002A520: 9407bfe8                 add     %fp, var_18, %o2
F002A524: 10800004                 ba      loc_F002A534
F002A528: d62fbfed                 stb     %o3, [%fp+var_13]
F002A52C: 92100019                 mov     %i1, %o1
F002A530: 9410001a                 mov     %i2, %o2
F002A534: 400005b9                 call    _if_control
F002A538: 01000000                 nop
F002A53C: b0100008                 mov     %o0, %i0
F002A540: 81c7e008                 ret
F002A544: 81e80000                 restore
