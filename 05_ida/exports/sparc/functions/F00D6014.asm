F00D6014: 9de3baa0                 save    %sp, -0x560, %sp
F00D6018: 90100018                 mov     %i0, %o0! id
F00D601C: 133c0505                 sethi   %hi(paParsekeymappin), %o1
F00D6020: d2026260                 ld      [%o1+%lo(paParsekeymappin)], %o1! SEL
F00D6024: 9410001a                 mov     %i2, %o2
F00D6028: 9610001b                 mov     %i3, %o3
F00D602C: 40006e11                 call    _objc_msgSend
F00D6030: 9807bb00                 add     %fp, var_500, %o4
F00D6034: 80a22000                 cmp     %o0, 0
F00D6038: 32800004                 bne,a   loc_F00D6048
F00D603C: d00624f4                 ld      [%i0+0x4F4], %o0! id
F00D6040: 10800019                 ba      locret_F00D60A4
F00D6044: b0102000                 mov     0, %i0
F00D6048: 133c0504                 sethi   %hi(paLock), %o1! SEL
F00D604C: 40006e09                 call    _objc_msgSend
F00D6050: d2026000                 ld      [%o1+%lo(paLock)], %o1
F00D6054: d40624ec                 ld      [%i0+0x4EC], %o2! size_t
F00D6058: 80a2a000                 cmp     %o2, 0
F00D605C: 0280000a                 be      loc_F00D6084
F00D6060: 9007bb00                 add     %fp, var_500, %o0
F00D6064: d04e24fc                 ldsb    [%i0+0x4FC], %o0
F00D6068: 80a22001                 cmp     %o0, 1
F00D606C: 12800006                 bne     loc_F00D6084
F00D6070: 9007bb00                 add     %fp, var_500, %o0
F00D6074: d20624f0                 ld      [%i0+0x4F0], %o1
F00D6078: 7fffbfb3                 call    _IOFree
F00D607C: 9010000a                 mov     %o2, %o0
F00D6080: 9007bb00                 add     %fp, var_500, %o0! void *
F00D6084: 92062004                 add     %i0, 4, %o1! void *
F00D6088: 7ffefaa2                 call    _bcopy
F00D608C: 941024f0                 mov     0x4F0, %o2
F00D6090: d00624f4                 ld      [%i0+0x4F4], %o0! id
F00D6094: 133c0504                 sethi   %hi(paUnlock), %o1
F00D6098: d2026244                 ld      [%o1+%lo(paUnlock)], %o1! SEL
F00D609C: 40006df5                 call    _objc_msgSend
F00D60A0: f82e24fc                 stb     %i4, [%i0+0x4FC]
F00D60A4: 81c7e008                 ret
F00D60A8: 81e80000                 restore
