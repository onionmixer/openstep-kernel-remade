F003DE24: 9de3bf28                 save    %sp, -0xD8, %sp
F003DE28: 133c0434                 sethi   %hi(dword_F010D2C8), %o1! size_t
F003DE2C: d00262c8                 ld      [%o1+%lo(dword_F010D2C8)], %o0
F003DE30: 80a22000                 cmp     %o0, 0
F003DE34: 128000bf                 bne     locret_F003E130
F003DE38: b0102000                 mov     0, %i0
F003DE3C: a8102001                 mov     1, %l4
F003DE40: e82262c8                 st      %l4, [%o1+%lo(dword_F010D2C8)]
F003DE44: a607bfe8                 add     %fp, var_18, %l3
F003DE48: 90100013                 mov     %l3, %o0! void *
F003DE4C: 40015c03                 call    _bzero
F003DE50: 92102010                 mov     0x10, %o1
F003DE54: 7fffaf17                 call    _ifb_ifwithaf
F003DE58: 90102002                 mov     2, %o0
F003DE5C: a2920000                 orcc    %o0, %g0, %l1
F003DE60: 12800006                 bne     loc_F003DE78
F003DE64: 113c0434                 sethi   %hi(aWhoamiZeroIfp), %o0! "whoami: zero ifp\n"
F003DE68: 7fff59fc                 call    _printf
F003DE6C: 901222d0                 bset    %lo(aWhoamiZeroIfp), %o0! "whoami: zero ifp\n"
F003DE70: 108000b0                 ba      locret_F003E130
F003DE74: b0102041                 mov     0x41, %i0 ! 'A'
F003DE78: 4001a57e                 call    _initrootnet
F003DE7C: 01000000                 nop
F003DE80: 80a22000                 cmp     %o0, 0
F003DE84: 02800004                 be      loc_F003DE94
F003DE88: 113c0434                 sethi   %hi(aWhoamiInitroot), %o0! "whoami: initrootnet failed"
F003DE8C: 7fff5cb9                 call    _panic
F003DE90: 901222e8                 bset    %lo(aWhoamiInitroot), %o0! "whoami: initrootnet failed"
F003DE94: 90102000                 mov     0, %o0
F003DE98: 1330081a92126112         set     -0x3FDF96EE, %o1
F003DEA0: a407bfa8                 add     %fp, var_58, %l2
F003DEA4: 94100012                 mov     %l2, %o2
F003DEA8: 7fffc2c9                 call    _in_control
F003DEAC: 96100011                 mov     %l1, %o3
F003DEB0: b0920000                 orcc    %o0, %g0, %i0
F003DEB4: 02800009                 be      loc_F003DED8
F003DEB8: 113c0434                 sethi   %hi(aWhoamiInContro), %o0! "whoami: in_control 0x%x if_flags 0x%x\n"
F003DEBC: 90122308                 bset    %lo(aWhoamiInContro), %o0! "whoami: in_control 0x%x if_flags 0x%x\n"
F003DEC0: d454600c                 ldsh    [%l1+0xC], %o2! size_t
F003DEC4: 7fff59e5                 call    _printf
F003DEC8: 92100018                 mov     %i0, %o1
F003DECC: 113c0434                 sethi   %hi(aBadSiocgifbrda), %o0! "bad SIOCGIFBRDADDR in_control"
F003DED0: 7fff5ca8                 call    _panic
F003DED4: 90122330                 bset    %lo(aBadSiocgifbrda), %o0! "bad SIOCGIFBRDADDR in_control"
F003DED8: a007bfb8                 add     %fp, var_48, %l0
F003DEDC: 90100010                 mov     %l0, %o0! void *
F003DEE0: 92100013                 mov     %l3, %o1! void *
F003DEE4: 40015b0b                 call    _bcopy
F003DEE8: 94102010                 mov     0x10, %o2! size_t
F003DEEC: 90100010                 mov     %l0, %o0! void *
F003DEF0: 133c04bd92126114         set     unk_F012F514, %o1! void *
F003DEF8: 40015b06                 call    _bcopy
F003DEFC: 94102010                 mov     0x10, %o2
F003DF00: e827bfe0                 st      %l4, [%fp+var_20]
F003DF04: 90102000                 mov     0, %o0
F003DF08: 1330081a9212610d         set     -0x3FDF96F3, %o1
F003DF10: 94100012                 mov     %l2, %o2
F003DF14: 7fffc2ae                 call    _in_control
F003DF18: 96100011                 mov     %l1, %o3
F003DF1C: 80a22000                 cmp     %o0, 0
F003DF20: 22800006                 be,a    loc_F003DF38
F003DF24: 9007bfa4                 add     %fp, var_5C, %o0
F003DF28: 113c0434                 sethi   %hi(aBadSiocgifaddr), %o0! "bad SIOCGIFADDR in_control"
F003DF2C: 7fff5c91                 call    _panic
F003DF30: 90122350                 bset    %lo(aBadSiocgifaddr), %o0! "bad SIOCGIFADDR in_control"
F003DF34: 9007bfa4                 add     %fp, var_5C, %o0! void *
F003DF38: 9207bfe4                 add     %fp, var_1C, %o1! void *
F003DF3C: 94102004                 mov     4, %o2! size_t
F003DF40: a2102000                 mov     0, %l1
F003DF44: 2d3c0119                 sethi   -0xFFB9C00, %l6
F003DF48: d607bfbc                 ld      [%fp+var_44], %o3
F003DF4C: 2b000061                 sethi   0x18400, %l5
F003DF50: 40015af0                 call    _bcopy
F003DF54: d627bfa4                 st      %o3, [%fp+var_5C]
F003DF58: 90102003                 mov     3, %o0
F003DF5C: d027bfc8                 st      %o0, [%fp+var_38]
F003DF60: c027bfcc                 clr     [%fp+var_34]
F003DF64: 4000a843                 call    _kalloc
F003DF68: 90102100                 mov     0x100, %o0
F003DF6C: d027bfd0                 st      %o0, [%fp+var_30]
F003DF70: 4000a840                 call    _kalloc
F003DF74: 90102100                 mov     0x100, %o0
F003DF78: d027bfd4                 st      %o0, [%fp+var_2C]
F003DF7C: 113c0119a81220c8         set     _xdr_bp_whoami_res, %l4
F003DF84: a607bfd0                 add     %fp, var_30, %l3
F003DF88: a407bf98                 add     %fp, var_68, %l2
F003DF8C: 9007bfe8                 add     %fp, var_18, %o0
F003DF90: 921562ba                 or      %l5, 0x2BA, %o1
F003DF94: 94102001                 mov     1, %o2
F003DF98: da07bfc8                 ld      [%fp+var_38], %o5
F003DF9C: 96102001                 mov     1, %o3
F003DFA0: d807bfcc                 ld      [%fp+var_34], %o4
F003DFA4: da27bf98                 st      %o5, [%fp+var_68]
F003DFA8: d827bf9c                 st      %o4, [%fp+var_64]
F003DFAC: e823a05c                 st      %l4, [%sp+0xD8+var_7C]
F003DFB0: e623a060                 st      %l3, [%sp+0xD8+var_78]
F003DFB4: e423a064                 st      %l2, [%sp+0xD8+var_74]
F003DFB8: c023a068                 clr     [%sp+0xD8+var_70]
F003DFBC: 9815a0a8                 or      %l6, 0xA8, %o4
F003DFC0: 7fffff5f                 call    sub_F003DD3C
F003DFC4: 9a07bfe0                 add     %fp, var_20, %o5
F003DFC8: a0100008                 mov     %o0, %l0
F003DFCC: 80a42005                 cmp     %l0, 5
F003DFD0: 3280000e                 bne,a   loc_F003E008
F003DFD4: 90102014                 mov     0x14, %o0
F003DFD8: 80a46000                 cmp     %l1, 0
F003DFDC: 3280000b                 bne,a   loc_F003E008
F003DFE0: 90102014                 mov     0x14, %o0
F003DFE4: 113c0434                 sethi   %hi(aNoBootparamSer), %o0! "No bootparam server responding; still t"...
F003DFE8: 7fff599c                 call    _printf
F003DFEC: 90122370                 bset    %lo(aNoBootparamSer), %o0! "No bootparam server responding; still t"...
F003DFF0: 113c0434901223a0         set     aWhoamiPmapRmtc, %o0! "whoami: pmap_rmtcall status 0x%x\n"
F003DFF8: 7fff5998                 call    _printf
F003DFFC: 92102005                 mov     5, %o1
F003E000: a2102001                 mov     1, %l1
F003E004: 90102014                 mov     0x14, %o0
F003E008: d027bfc8                 st      %o0, [%fp+var_38]
F003E00C: 80a42005                 cmp     %l0, 5
F003E010: 02bfffdf                 be      loc_F003DF8C
F003E014: c027bfcc                 clr     [%fp+var_34]
F003E018: 80a46000                 cmp     %l1, 0
F003E01C: 02800006                 be      loc_F003E034
F003E020: 80a42000                 cmp     %l0, 0
F003E024: 113c0434                 sethi   %hi(aBootparamRespo_1), %o0! "Bootparam response received\n"
F003E028: 7fff598c                 call    _printf
F003E02C: 901223c8                 bset    %lo(aBootparamRespo_1), %o0! "Bootparam response received\n"
F003E030: 80a42000                 cmp     %l0, 0
F003E034: 02800006                 be      loc_F003E04C
F003E038: 113c0434                 sethi   %hi(aWhoamiRpcCallF), %o0! "whoami RPC call failed with status %d\n"
F003E03C: b0100010                 mov     %l0, %i0
F003E040: 901223e8                 bset    %lo(aWhoamiRpcCallF), %o0! "whoami RPC call failed with status %d\n"
F003E044: 10800033                 ba      loc_F003E110
F003E048: 92100018                 mov     %i0, %o1! void *
F003E04C: 7fff24fb                 call    _strlen
F003E050: d007bfd0                 ld      [%fp+var_30], %o0
F003E054: 94100008                 mov     %o0, %o2! size_t
F003E058: 113c04d1                 sethi   %hi(_hostnamelen), %o0
F003E05C: 80a2a100                 cmp     %o2, 0x100
F003E060: 08800005                 bleu    loc_F003E074
F003E064: d4222330                 st      %o2, [%o0+%lo(_hostnamelen)]
F003E068: 113c0435                 sethi   %hi(aWhoamiHostname), %o0! "whoami: hostname too long"
F003E06C: 1080001b                 ba      loc_F003E0D8
F003E070: 90122010                 bset    %lo(aWhoamiHostname), %o0! "whoami: hostname too long"
F003E074: 80a2a000                 cmp     %o2, 0
F003E078: 14800007                 bg      loc_F003E094
F003E07C: 213c04d1                 sethi   -0xFECBC00, %l0
F003E080: 113c0435                 sethi   %hi(aWhoamiNoHostNa), %o0! "whoami: no host name\n"
F003E084: 7fff5975                 call    _printf
F003E088: 90122030                 bset    %lo(aWhoamiNoHostNa), %o0! "whoami: no host name\n"
F003E08C: 10800023                 ba      loc_F003E118
F003E090: b0102006                 mov     6, %i0
F003E094: a0142230                 bset    0x230, %l0
F003E098: d007bfd0                 ld      [%fp+var_30], %o0! void *
F003E09C: 40015a9d                 call    _bcopy
F003E0A0: 92100010                 mov     %l0, %o1
F003E0A4: 113c043590122048         set     aHostnameS, %o0! "hostname: %s\n"
F003E0AC: 7fff596b                 call    _printf
F003E0B0: 92100010                 mov     %l0, %o1! void *
F003E0B4: 7fff24e1                 call    _strlen
F003E0B8: d007bfd4                 ld      [%fp+var_2C], %o0
F003E0BC: 94100008                 mov     %o0, %o2! size_t
F003E0C0: 113c04d1                 sethi   %hi(_domainnamelen), %o0
F003E0C4: 80a2a100                 cmp     %o2, 0x100
F003E0C8: 08800008                 bleu    loc_F003E0E8
F003E0CC: d4222200                 st      %o2, [%o0+%lo(_domainnamelen)]
F003E0D0: 113c043590122058         set     aWhoamiDomainna, %o0! "whoami: domainname too long"
F003E0D8: 7fff5960                 call    _printf
F003E0DC: b010203f                 mov     0x3F, %i0 ! '?'
F003E0E0: 1080000f                 ba      loc_F003E11C
F003E0E4: d007bfd0                 ld      [%fp+var_30], %o0
F003E0E8: 80a2a000                 cmp     %o2, 0
F003E0EC: 0480000b                 ble     loc_F003E118
F003E0F0: d007bfd4                 ld      [%fp+var_2C], %o0! void *
F003E0F4: 213c04d1a0142100         set     _domainname, %l0
F003E0FC: 40015a85                 call    _bcopy
F003E100: 92100010                 mov     %l0, %o1
F003E104: 113c043590122078         set     aDomainnameS, %o0! "domainname: %s\n"
F003E10C: 92100010                 mov     %l0, %o1
F003E110: 7fff5952                 call    _printf
F003E114: 01000000                 nop
F003E118: d007bfd0                 ld      [%fp+var_30], %o0
F003E11C: 4000a821                 call    _kfree
F003E120: 92102100                 mov     0x100, %o1
F003E124: d007bfd4                 ld      [%fp+var_2C], %o0
F003E128: 4000a81e                 call    _kfree
F003E12C: 92102100                 mov     0x100, %o1
F003E130: 81c7e008                 ret
F003E134: 81e80000                 restore
