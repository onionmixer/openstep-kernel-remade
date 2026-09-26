F00CCFE4: 9de3bf68                 save    %sp, -0x98, %sp
F00CCFE8: 90062128                 add     %i0, 0x128, %o0
F00CCFEC: d026212c                 st      %o0, [%i0+0x12C]
F00CCFF0: d0262128                 st      %o0, [%i0+0x128]
F00CCFF4: 113c0504                 sethi   %hi(paClass), %o0! id
F00CCFF8: d2022014                 ld      [%o0+%lo(paClass)], %o1! SEL
F00CCFFC: 4000921d                 call    _objc_msgSend
F00CD000: 90100018                 mov     %i0, %o0! id
F00CD004: 133c0504                 sethi   %hi(paDevicestyle), %o1! SEL
F00CD008: 4000921a                 call    _objc_msgSend
F00CD00C: d202633c                 ld      [%o1+%lo(paDevicestyle)], %o1
F00CD010: 80a22000                 cmp     %o0, 0
F00CD014: 1280001c                 bne     loc_F00CD084
F00CD018: 113c0504                 sethi   -0xFEBF000, %o0
F00CD01C: f027bff0                 st      %i0, [%fp+var_10]
F00CD020: 9007bff0                 add     %fp, var_10, %o0! objc_super *
F00CD024: 133c0508                 sethi   %hi(stru_F014213C.super_class), %o1
F00CD028: d6026140                 ld      [%o1+%lo(stru_F014213C.super_class)], %o3
F00CD02C: 9410001a                 mov     %i2, %o2
F00CD030: 133c0504                 sethi   %hi(paInitfromdevice), %o1
F00CD034: d20262fc                 ld      [%o1+%lo(paInitfromdevice)], %o1! SEL
F00CD038: 40009251                 call    _objc_msgSendSuper
F00CD03C: d627bff4                 st      %o3, [%fp+var_C]
F00CD040: 80a22000                 cmp     %o0, 0
F00CD044: 12800004                 bne     loc_F00CD054
F00CD048: 113c0506                 sethi   -0xFEBE800, %o0! id
F00CD04C: 1080003f                 ba      locret_F00CD148
F00CD050: b0102000                 mov     0, %i0
F00CD054: d202206c                 ld      [%o0+0x6C], %o1! SEL
F00CD058: 40009206                 call    _objc_msgSend
F00CD05C: 90100018                 mov     %i0, %o0
F00CD060: 80a22000                 cmp     %o0, 0
F00CD064: 02800008                 be      loc_F00CD084
F00CD068: 113c0504                 sethi   -0xFEBF000, %o0
F00CD06C: 113c0503                 sethi   %hi(paFree), %o0! id
F00CD070: d20223fc                 ld      [%o0+%lo(paFree)], %o1! SEL
F00CD074: 400091ff                 call    _objc_msgSend
F00CD078: 90100018                 mov     %i0, %o0! id
F00CD07C: 10800033                 ba      locret_F00CD148
F00CD080: b0102000                 mov     0, %i0
F00CD084: d2022248                 ld      [%o0+0x248], %o1! SEL
F00CD088: 213c04bb                 sethi   %hi(dword_F012ECE8), %l0
F00CD08C: d40420e8                 ld      [%l0+%lo(dword_F012ECE8)], %o2
F00CD090: 400091f8                 call    _objc_msgSend
F00CD094: 90100018                 mov     %i0, %o0
F00CD098: a207bfd8                 add     %fp, var_28, %l1
F00CD09C: 90100011                 mov     %l1, %o0! char *
F00CD0A0: 133c03ec                 sethi   %hi(aScD), %o1! "sc%d"
F00CD0A4: d40420e8                 ld      [%l0+%lo(dword_F012ECE8)], %o2
F00CD0A8: 92126228                 bset    %lo(aScD), %o1! "sc%d"
F00CD0AC: 9602a001                 add     %o2, 1, %o3
F00CD0B0: 7ffd1dae                 call    _sprintf
F00CD0B4: d62420e8                 st      %o3, [%l0+%lo(dword_F012ECE8)]
F00CD0B8: 90100018                 mov     %i0, %o0! id
F00CD0BC: 133c0504                 sethi   %hi(paSetname), %o1
F00CD0C0: d202624c                 ld      [%o1+%lo(paSetname)], %o1! SEL
F00CD0C4: 400091eb                 call    _objc_msgSend
F00CD0C8: 94100011                 mov     %l1, %o2
F00CD0CC: 90100018                 mov     %i0, %o0! id
F00CD0D0: 133c0504                 sethi   %hi(paSetdevicekind), %o1
F00CD0D4: 153c03ec                 sethi   %hi(aSc), %o2! "sc"
F00CD0D8: d2026250                 ld      [%o1+%lo(paSetdevicekind)], %o1! SEL
F00CD0DC: 400091e5                 call    _objc_msgSend
F00CD0E0: 9412a230                 bset    %lo(aSc), %o2! "sc"
F00CD0E4: 90100018                 mov     %i0, %o0! id
F00CD0E8: 133c0504                 sethi   %hi(paGetdmaalignmen), %o1
F00CD0EC: d2026180                 ld      [%o1+%lo(paGetdmaalignmen)], %o1! SEL
F00CD0F0: 400091e0                 call    _objc_msgSend
F00CD0F4: 9407bfc8                 add     %fp, var_38, %o2
F00CD0F8: d007bfc8                 ld      [%fp+var_38], %o0
F00CD0FC: d0262230                 st      %o0, [%i0+0x230]
F00CD100: d207bfcc                 ld      [%fp+var_34], %o1
F00CD104: 80a24008                 cmp     %o1, %o0
F00CD108: 38800002                 bgu,a   loc_F00CD110
F00CD10C: d2262230                 st      %o1, [%i0+0x230]
F00CD110: d207bfd0                 ld      [%fp+var_30], %o1
F00CD114: d0062230                 ld      [%i0+0x230], %o0
F00CD118: 80a24008                 cmp     %o1, %o0
F00CD11C: 38800002                 bgu,a   loc_F00CD124
F00CD120: d2262230                 st      %o1, [%i0+0x230]
F00CD124: d207bfd4                 ld      [%fp+var_2C], %o1
F00CD128: d0062230                 ld      [%i0+0x230], %o0
F00CD12C: 80a24008                 cmp     %o1, %o0
F00CD130: 38800002                 bgu,a   loc_F00CD138
F00CD134: d2262230                 st      %o1, [%i0+0x230]
F00CD138: d0062230                 ld      [%i0+0x230], %o0
F00CD13C: 80a22001                 cmp     %o0, 1
F00CD140: 22800002                 be,a    locret_F00CD148
F00CD144: c0262230                 clr     [%i0+0x230]
F00CD148: 81c7e008                 ret
F00CD14C: 81e80000                 restore
