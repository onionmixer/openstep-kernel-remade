F00DAE14: 9de3bf90                 save    %sp, -0x70, %sp
F00DAE18: f027bff0                 st      %i0, [%fp+var_10]
F00DAE1C: 133c0508                 sethi   %hi(stru_F014227C.ext), %o1
F00DAE20: d40262a8                 ld      [%o1+%lo(stru_F014227C.ext)], %o2
F00DAE24: 9007bff0                 add     %fp, var_10, %o0! objc_super *
F00DAE28: e207a05c                 ld      [%fp+arg_5C], %l1
F00DAE2C: 133c0504                 sethi   %hi(paInit), %o1! SEL
F00DAE30: e002602c                 ld      [%o1+%lo(paInit)], %l0
F00DAE34: d427bff4                 st      %o2, [%fp+var_C]
F00DAE38: 40005ad1                 call    _objc_msgSendSuper
F00DAE3C: 92100010                 mov     %l0, %o1
F00DAE40: 113c0505                 sethi   %hi(paAudiodevice), %o0! id
F00DAE44: d2022224                 ld      [%o0+%lo(paAudiodevice)], %o1! SEL
F00DAE48: f4262004                 st      %i2, [%i0+4]
F00DAE4C: 40005a89                 call    _objc_msgSend
F00DAE50: 9010001a                 mov     %i2, %o0
F00DAE54: d0262008                 st      %o0, [%i0+8]
F00DAE58: f6262018                 st      %i3, [%i0+0x18]
F00DAE5C: 1100001590122222         set     0x5622, %o0
F00DAE64: d0262064                 st      %o0, [%i0+0x64]
F00DAE68: c0262068                 clr     [%i0+0x68]
F00DAE6C: 90102002                 mov     2, %o0
F00DAE70: d026206c                 st      %o0, [%i0+0x6C]
F00DAE74: 9406202c                 add     %i0, 0x2C, %o2 ! ','
F00DAE78: d4262030                 st      %o2, [%i0+0x30]
F00DAE7C: 113c0506                 sethi   %hi(paNxlock), %o0
F00DAE80: d00222a0                 ld      [%o0+%lo(paNxlock)], %o0! id
F00DAE84: 133c0503                 sethi   %hi(paAlloc), %o1
F00DAE88: d20263f0                 ld      [%o1+%lo(paAlloc)], %o1! SEL
F00DAE8C: 40005a79                 call    _objc_msgSend
F00DAE90: d426202c                 st      %o2, [%i0+0x2C]
F00DAE94: 40005a77                 call    _objc_msgSend
F00DAE98: 92100010                 mov     %l0, %o1
F00DAE9C: 7ffe3105                 call    _task_self
F00DAEA0: d0262028                 st      %o0, [%i0+0x28]
F00DAEA4: 4000632f                 call    _port_allocate_EXTERNAL
F00DAEA8: 9210001c                 mov     %i4, %o1
F00DAEAC: 80a22000                 cmp     %o0, 0
F00DAEB0: 1280000b                 bne     loc_F00DAEDC
F00DAEB4: 113c03f0                 sethi   -0xFF04000, %o0
F00DAEB8: d0070000                 ld      [%i4], %o0
F00DAEBC: 92102002                 mov     2, %o1
F00DAEC0: 94102000                 mov     0, %o2
F00DAEC4: 7fffbcf9                 call    _IOConvertPort
F00DAEC8: d026200c                 st      %o0, [%i0+0xC]
F00DAECC: d0262010                 st      %o0, [%i0+0x10]
F00DAED0: fa262014                 st      %i5, [%i0+0x14]
F00DAED4: 1080000b                 ba      locret_F00DAF00
F00DAED8: e226201c                 st      %l1, [%i0+0x1C]
F00DAEDC: 901223f0                 bset    0x3F0, %o0
F00DAEE0: 133c03f1                 sethi   %hi(aMachErr), %o1! "MACH ERR"
F00DAEE4: 7fffac84                 call    _IOLog
F00DAEE8: 92126020                 bset    %lo(aMachErr), %o1! "MACH ERR"
F00DAEEC: 113c0503                 sethi   %hi(paFree), %o0! id
F00DAEF0: d20223fc                 ld      [%o0+%lo(paFree)], %o1! SEL
F00DAEF4: 40005a5f                 call    _objc_msgSend
F00DAEF8: 90100018                 mov     %i0, %o0
F00DAEFC: b0102000                 mov     0, %i0
F00DAF00: 81c7e008                 ret
F00DAF04: 81e80000                 restore
