F002DF58: 9de3bf98                 save    %sp, -0x68, %sp
F002DF5C: a4100018                 mov     %i0, %l2
F002DF60: a2103fff                 mov     -1, %l1
F002DF64: 133c0431                 sethi   %hi(dword_F010C424), %o1
F002DF68: d0026024                 ld      [%o1+%lo(dword_F010C424)], %o0
F002DF6C: 80a22000                 cmp     %o0, 0
F002DF70: 02800009                 be      loc_F002DF94
F002DF74: a0102000                 mov     0, %l0
F002DF78: c0226024                 clr     [%o1+%lo(dword_F010C424)]
F002DF7C: 113c00b5                 sethi   %hi(_arptimer), %o0
F002DF80: 133c043e                 sethi   %hi(_hz), %o1
F002DF84: d40263e0                 ld      [%o1+%lo(_hz)], %o2
F002DF88: 901220cc                 bset    %lo(_arptimer), %o0! int
F002DF8C: 7fff7027                 call    _timeout
F002DF90: 92102000                 mov     0, %o1
F002DF94: d0064000                 ld      [%i1], %o0
F002DF98: 7fff6242                 call    _urem
F002DF9C: 92102013                 mov     0x13, %o1
F002DFA0: 932a2001                 sll     %o0, 1, %o1
F002DFA4: 92024008                 add     %o1, %o0, %o1
F002DFA8: 952a6004                 sll     %o1, 4, %o2
F002DFAC: 94228009                 sub     %o2, %o1, %o2
F002DFB0: 952aa002                 sll     %o2, 2, %o2
F002DFB4: 113c04d590122270         set     _arptab, %o0
F002DFBC: b0028008                 add     %o2, %o0, %i0
F002DFC0: 94102000                 mov     0, %o2
F002DFC4: 92100018                 mov     %i0, %o1
F002DFC8: d00a600b                 ldub    [%o1+0xB], %o0
F002DFCC: 80a22000                 cmp     %o0, 0
F002DFD0: 02800019                 be      loc_F002E034
F002DFD4: 808a2004                 btst    4, %o0
F002DFD8: 3280000c                 bne,a   loc_F002E008
F002DFDC: 9402a001                 inc     %o2
F002DFE0: 80a42000                 cmp     %l0, 0
F002DFE4: 22800007                 be,a    loc_F002E000
F002DFE8: e20a600a                 ldub    [%o1+0xA], %l1
F002DFEC: d00a600a                 ldub    [%o1+0xA], %o0
F002DFF0: 80a20011                 cmp     %o0, %l1
F002DFF4: 24800005                 ble,a   loc_F002E008
F002DFF8: 9402a001                 inc     %o2
F002DFFC: e20a600a                 ldub    [%o1+0xA], %l1
F002E000: a0100009                 mov     %o1, %l0
F002E004: 9402a001                 inc     %o2
F002E008: 92026014                 inc     0x14, %o1
F002E00C: 80a2a008                 cmp     %o2, 8
F002E010: 04bfffee                 ble     loc_F002DFC8
F002E014: b0062014                 inc     0x14, %i0
F002E018: 80a42000                 cmp     %l0, 0
F002E01C: 12800004                 bne     loc_F002E02C
F002E020: b0100010                 mov     %l0, %i0
F002E024: 10800009                 ba      locret_F002E048
F002E028: b0102000                 mov     0, %i0
F002E02C: 7fffffba                 call    _arptfree
F002E030: 90100018                 mov     %i0, %o0
F002E034: d0064000                 ld      [%i1], %o0
F002E038: d0260000                 st      %o0, [%i0]
F002E03C: 90102001                 mov     1, %o0
F002E040: d02e200b                 stb     %o0, [%i0+0xB]
F002E044: e4262010                 st      %l2, [%i0+0x10]
F002E048: 81c7e008                 ret
F002E04C: 81e80000                 restore
