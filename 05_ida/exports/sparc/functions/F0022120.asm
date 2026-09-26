F0022120: 9de3bf90                 save    %sp, -0x70, %sp! int
F0022124: 253c04cf                 sethi   %hi(dword_F0133DDC), %l2
F0022128: d004a1dc                 ld      [%l2+%lo(dword_F0133DDC)], %o0
F002212C: e6022024                 ld      [%o0+0x24], %l3
F0022130: 400000a8                 call    _getsock
F0022134: d004c000                 ld      [%l3], %o0
F0022138: a0920000                 orcc    %o0, %g0, %l0
F002213C: 0280003c                 be      locret_F002222C
F0022140: a807bff4                 add     %fp, var_C, %l4
F0022144: 92100014                 mov     %l4, %o1! int
F0022148: d004e008                 ld      [%l3+8], %o0! int
F002214C: 4001d7c3                 call    _copyin
F0022150: 94102004                 mov     4, %o2
F0022154: d204a1dc                 ld      [%l2+%lo(dword_F0133DDC)], %o1
F0022158: d02a6038                 stb     %o0, [%o1+0x38]
F002215C: d004a1dc                 ld      [%l2+%lo(dword_F0133DDC)], %o0
F0022160: d04a2038                 ldsb    [%o0+0x38], %o0
F0022164: 80a22000                 cmp     %o0, 0
F0022168: 12800031                 bne     locret_F002222C
F002216C: 90102001                 mov     1, %o0
F0022170: e2042018                 ld      [%l0+0x18], %l1
F0022174: 7fffee21                 call    _m_getclr
F0022178: 92102008                 mov     8, %o1
F002217C: a0920000                 orcc    %o0, %g0, %l0
F0022180: 12800006                 bne     loc_F0022198
F0022184: 90100011                 mov     %l1, %o0
F0022188: d204a1dc                 ld      [%l2+0x1DC], %o1
F002218C: 90102037                 mov     0x37, %o0 ! '7'
F0022190: 10800027                 ba      locret_F002222C
F0022194: d02a6038                 stb     %o0, [%o1+0x38]
F0022198: 9210200f                 mov     0xF, %o1
F002219C: d802200c                 ld      [%o0+0xC], %o4
F00221A0: 94102000                 mov     0, %o2
F00221A4: da03201c                 ld      [%o4+0x1C], %o5! int
F00221A8: 96100010                 mov     %l0, %o3! int
F00221AC: 9fc34000                 call    %o5
F00221B0: 98102000                 mov     0, %o4! int
F00221B4: d204a1dc                 ld      [%l2+0x1DC], %o1
F00221B8: d02a6038                 stb     %o0, [%o1+0x38]
F00221BC: d004a1dc                 ld      [%l2+0x1DC], %o0
F00221C0: d04a2038                 ldsb    [%o0+0x38], %o0
F00221C4: 80a22000                 cmp     %o0, 0
F00221C8: 12800017                 bne     loc_F0022224
F00221CC: d007bff4                 ld      [%fp+var_C], %o0
F00221D0: d2542008                 ldsh    [%l0+8], %o1
F00221D4: 80a20009                 cmp     %o0, %o1
F00221D8: 34800002                 bg,a    loc_F00221E0
F00221DC: d227bff4                 st      %o1, [%fp+var_C]
F00221E0: d204e004                 ld      [%l3+4], %o1! int
F00221E4: d0042004                 ld      [%l0+4], %o0! int
F00221E8: d407bff4                 ld      [%fp+var_C], %o2! int
F00221EC: 4001d7b8                 call    _copyout
F00221F0: 90040008                 add     %l0, %o0, %o0
F00221F4: d204a1dc                 ld      [%l2+0x1DC], %o1
F00221F8: d02a6038                 stb     %o0, [%o1+0x38]
F00221FC: d004a1dc                 ld      [%l2+0x1DC], %o0
F0022200: d04a2038                 ldsb    [%o0+0x38], %o0
F0022204: 80a22000                 cmp     %o0, 0
F0022208: 12800007                 bne     loc_F0022224
F002220C: 90100014                 mov     %l4, %o0! int
F0022210: d204e008                 ld      [%l3+8], %o1! int
F0022214: 4001d7ae                 call    _copyout
F0022218: 94102004                 mov     4, %o2
F002221C: d204a1dc                 ld      [%l2+0x1DC], %o1
F0022220: d02a6038                 stb     %o0, [%o1+0x38]
F0022224: 7fffee90                 call    _m_freem
F0022228: 90100010                 mov     %l0, %o0
F002222C: 81c7e008                 ret
F0022230: 81e80000                 restore
