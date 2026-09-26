F004BF10: 9de3bf90                 save    %sp, -0x70, %sp
F004BF14: d0162044                 lduh    [%i0+0x44], %o0
F004BF18: 808a2001                 btst    1, %o0
F004BF1C: 0280000c                 be      loc_F004BF4C
F004BF20: a0102000                 mov     0, %l0
F004BF24: 90122010                 bset    0x10, %o0
F004BF28: d0362044                 sth     %o0, [%i0+0x44]
F004BF2C: 90100018                 mov     %i0, %o0! unsigned int
F004BF30: 7fff19d2                 call    _sleep
F004BF34: 9210200a                 mov     0xA, %o1
F004BF38: d0162044                 lduh    [%i0+0x44], %o0
F004BF3C: 808a2001                 btst    1, %o0
F004BF40: 12bffffa                 bne     loc_F004BF28
F004BF44: 90122010                 bset    0x10, %o0
F004BF48: d0162044                 lduh    [%i0+0x44], %o0
F004BF4C: 92122001                 or      %o0, 1, %o1
F004BF50: d0562066                 ldsh    [%i0+0x66], %o0
F004BF54: 80a22000                 cmp     %o0, 0
F004BF58: 02800006                 be      loc_F004BF70
F004BF5C: d2362044                 sth     %o1, [%i0+0x44]
F004BF60: d0062070                 ld      [%i0+0x70], %o0
F004BF64: 80a22017                 cmp     %o0, 0x17
F004BF68: 18800010                 bgu     loc_F004BFA8
F004BF6C: 90100018                 mov     %i0, %o0
F004BF70: 1100003f901223fe         set     0xFFFE, %o0
F004BF78: 940a4008                 and     %o1, %o0, %o2
F004BF7C: 808a6010                 btst    0x10, %o1
F004BF80: 02800099                 be      loc_F004C1E4
F004BF84: d4362044                 sth     %o2, [%i0+0x44]
F004BF88: 1100003f901223ef         set     0xFFEF, %o0
F004BF90: 900a8008                 and     %o2, %o0, %o0
F004BF94: d0362044                 sth     %o0, [%i0+0x44]
F004BF98: 7fff1b94                 call    _wakeup
F004BF9C: 90100018                 mov     %i0, %o0
F004BFA0: 108000a6                 ba      locret_F004C238
F004BFA4: b0102000                 mov     0, %i0
F004BFA8: 92102000                 mov     0, %o1
F004BFAC: 4000030f                 call    _blkatoff
F004BFB0: 9407bff4                 add     %fp, var_C, %o2
F004BFB4: a2920000                 orcc    %o0, %g0, %l1
F004BFB8: 12800006                 bne     loc_F004BFD0
F004BFBC: d407bff4                 ld      [%fp+var_C], %o2
F004BFC0: 113c04cf                 sethi   %hi(dword_F0133DDC), %o0
F004BFC4: d00221dc                 ld      [%o0+%lo(dword_F0133DDC)], %o0
F004BFC8: 1080008a                 ba      loc_F004C1F0
F004BFCC: e04a2038                 ldsb    [%o0+0x38], %l0
F004BFD0: d006a048                 ld      [%i2+0x48], %o0
F004BFD4: d202a00c                 ld      [%o2+0xC], %o1
F004BFD8: 80a24008                 cmp     %o1, %o0
F004BFDC: 02800085                 be      loc_F004C1F0
F004BFE0: 80a46000                 cmp     %l1, 0
F004BFE4: d052a012                 ldsh    [%o2+0x12], %o0
F004BFE8: 80a22002                 cmp     %o0, 2
F004BFEC: 1280000a                 bne     loc_F004C014
F004BFF0: 90100018                 mov     %i0, %o0
F004BFF4: d002a014                 ld      [%o2+0x14], %o0
F004BFF8: 133fffc0                 sethi   -0x10000, %o1
F004BFFC: 900a0009                 and     %o0, %o1, %o0
F004C000: 130b8b80                 sethi   0x2E2E0000, %o1
F004C004: 80a20009                 cmp     %o0, %o1
F004C008: 02800009                 be      loc_F004C02C
F004C00C: 9010001a                 mov     %i2, %o0
F004C010: 90100018                 mov     %i0, %o0
F004C014: 133c043a92126248         set     aMangledEntry, %o1! "mangled .. entry"
F004C01C: 4000035c                 call    sub_F004CD8C
F004C020: 94102000                 mov     0, %o2
F004C024: 10800072                 ba      loc_F004C1EC
F004C028: a0102016                 mov     0x16, %l0
F004C02C: d616a066                 lduh    [%i2+0x66], %o3
F004C030: 92102001                 mov     1, %o1
F004C034: d416a044                 lduh    [%i2+0x44], %o2
F004C038: 9602e001                 inc     %o3
F004C03C: d636a066                 sth     %o3, [%i2+0x66]
F004C040: 9412a040                 bset    0x40, %o2 ! '@'
F004C044: 40000940                 call    _iupdat
F004C048: d436a044                 sth     %o2, [%i2+0x44]
F004C04C: a006200c                 add     %i0, 0xC, %l0
F004C050: 90100010                 mov     %l0, %o0
F004C054: 133c043a                 sethi   %hi(asc_F010EA60), %o1! ".."
F004C058: 7fff66f4                 call    _dnlc_remove
F004C05C: 92126260                 bset    %lo(asc_F010EA60), %o1! ".."
F004C060: 90100010                 mov     %l0, %o0
F004C064: 133c043a                 sethi   %hi(asc_F010EA68), %o1! ".."
F004C068: d807bff4                 ld      [%fp+var_C], %o4
F004C06C: 92126268                 bset    %lo(asc_F010EA68), %o1! ".."
F004C070: d606a048                 ld      [%i2+0x48], %o3
F004C074: 9406a00c                 add     %i2, 0xC, %o2
F004C078: d623200c                 st      %o3, [%o4+0xC]
F004C07C: 7fff65b8                 call    _dnlc_enter
F004C080: 96102000                 mov     0, %o3
F004C084: 7fff61b9                 call    _bwrite
F004C088: 90100011                 mov     %l1, %o0
F004C08C: 113c04cf                 sethi   %hi(dword_F0133DDC), %o0
F004C090: d00221dc                 ld      [%o0+%lo(dword_F0133DDC)], %o0
F004C094: d04a2038                 ldsb    [%o0+0x38], %o0
F004C098: 80a22000                 cmp     %o0, 0
F004C09C: 02800004                 be      loc_F004C0AC
F004C0A0: a2102000                 mov     0, %l1
F004C0A4: 10800052                 ba      loc_F004C1EC
F004C0A8: a0100008                 mov     %o0, %l0
F004C0AC: d2162044                 lduh    [%i0+0x44], %o1
F004C0B0: 1100003fa01223fe         set     0xFFFE, %l0
F004C0B8: 920a4010                 and     %o1, %l0, %o1
F004C0BC: 808a6010                 btst    0x10, %o1
F004C0C0: 02800008                 be      loc_F004C0E0
F004C0C4: d2362044                 sth     %o1, [%i0+0x44]
F004C0C8: 1100003f901223ef         set     0xFFEF, %o0
F004C0D0: 900a4008                 and     %o1, %o0, %o0
F004C0D4: d0362044                 sth     %o0, [%i0+0x44]
F004C0D8: 7fff1b44                 call    _wakeup
F004C0DC: 90100018                 mov     %i0, %o0
F004C0E0: 80a66000                 cmp     %i1, 0
F004C0E4: 22800055                 be,a    locret_F004C238
F004C0E8: b0102000                 mov     0, %i0
F004C0EC: d016a044                 lduh    [%i2+0x44], %o0
F004C0F0: 920a0010                 and     %o0, %l0, %o1
F004C0F4: 808a6010                 btst    0x10, %o1
F004C0F8: 0280000e                 be      loc_F004C130
F004C0FC: d236a044                 sth     %o1, [%i2+0x44]
F004C100: 1100003f901223ef         set     0xFFEF, %o0
F004C108: 900a4008                 and     %o1, %o0, %o0
F004C10C: d036a044                 sth     %o0, [%i2+0x44]
F004C110: 7fff1b36                 call    _wakeup
F004C114: 9010001a                 mov     %i2, %o0
F004C118: 10800007                 ba      loc_F004C134
F004C11C: d0166044                 lduh    [%i1+0x44], %o0
F004C120: d0366044                 sth     %o0, [%i1+0x44]
F004C124: 90100019                 mov     %i1, %o0! unsigned int
F004C128: 7fff1954                 call    _sleep
F004C12C: 9210200a                 mov     0xA, %o1
F004C130: d0166044                 lduh    [%i1+0x44], %o0
F004C134: 808a2001                 btst    1, %o0
F004C138: 32bffffa                 bne,a   loc_F004C120
F004C13C: 90122010                 bset    0x10, %o0
F004C140: d0166044                 lduh    [%i1+0x44], %o0
F004C144: d2566066                 ldsh    [%i1+0x66], %o1
F004C148: 90122001                 bset    1, %o0
F004C14C: d0366044                 sth     %o0, [%i1+0x44]
F004C150: 80a26000                 cmp     %o1, 0
F004C154: 0280000a                 be      loc_F004C17C
F004C158: 90100009                 mov     %o1, %o0
F004C15C: 90023fff                 inc     -1, %o0
F004C160: d0366066                 sth     %o0, [%i1+0x66]
F004C164: 90100019                 mov     %i1, %o0
F004C168: d4166044                 lduh    [%i1+0x44], %o2
F004C16C: 92102001                 mov     1, %o1
F004C170: 9412a040                 bset    0x40, %o2 ! '@'
F004C174: 400008f4                 call    _iupdat
F004C178: d4366044                 sth     %o2, [%i1+0x44]
F004C17C: d2166044                 lduh    [%i1+0x44], %o1
F004C180: 1100003f901223fe         set     0xFFFE, %o0
F004C188: 920a4008                 and     %o1, %o0, %o1
F004C18C: 808a6010                 btst    0x10, %o1
F004C190: 0280000e                 be      loc_F004C1C8
F004C194: d2366044                 sth     %o1, [%i1+0x44]
F004C198: 1100003f901223ef         set     0xFFEF, %o0
F004C1A0: 900a4008                 and     %o1, %o0, %o0
F004C1A4: d0366044                 sth     %o0, [%i1+0x44]
F004C1A8: 7fff1b10                 call    _wakeup
F004C1AC: 90100019                 mov     %i1, %o0
F004C1B0: 10800007                 ba      loc_F004C1CC
F004C1B4: d016a044                 lduh    [%i2+0x44], %o0
F004C1B8: d036a044                 sth     %o0, [%i2+0x44]
F004C1BC: 9010001a                 mov     %i2, %o0! unsigned int
F004C1C0: 7fff192e                 call    _sleep
F004C1C4: 9210200a                 mov     0xA, %o1
F004C1C8: d016a044                 lduh    [%i2+0x44], %o0
F004C1CC: 808a2001                 btst    1, %o0
F004C1D0: 12bffffa                 bne     loc_F004C1B8
F004C1D4: 90122010                 bset    0x10, %o0
F004C1D8: d016a044                 lduh    [%i2+0x44], %o0
F004C1DC: 90122001                 bset    1, %o0
F004C1E0: d036a044                 sth     %o0, [%i2+0x44]
F004C1E4: 10800015                 ba      locret_F004C238
F004C1E8: b0102000                 mov     0, %i0
F004C1EC: 80a46000                 cmp     %l1, 0
F004C1F0: 22800005                 be,a    loc_F004C204
F004C1F4: d2162044                 lduh    [%i0+0x44], %o1
F004C1F8: 7fff619c                 call    _brelse
F004C1FC: 90100011                 mov     %l1, %o0
F004C200: d2162044                 lduh    [%i0+0x44], %o1
F004C204: 1100003f901223fe         set     0xFFFE, %o0
F004C20C: 920a4008                 and     %o1, %o0, %o1
F004C210: 808a6010                 btst    0x10, %o1
F004C214: 02800008                 be      loc_F004C234
F004C218: d2362044                 sth     %o1, [%i0+0x44]
F004C21C: 1100003f901223ef         set     0xFFEF, %o0
F004C224: 900a4008                 and     %o1, %o0, %o0
F004C228: d0362044                 sth     %o0, [%i0+0x44]
F004C22C: 7fff1aef                 call    _wakeup
F004C230: 90100018                 mov     %i0, %o0
F004C234: b0100010                 mov     %l0, %i0
F004C238: 81c7e008                 ret
F004C23C: 81e80000                 restore
