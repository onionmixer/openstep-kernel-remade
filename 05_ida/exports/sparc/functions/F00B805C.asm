F00B805C: 9de3bf90                 save    %sp, -0x70, %sp
F00B8060: a0100018                 mov     %i0, %l0
F00B8064: b0102000                 mov     0, %i0
F00B8068: 113c04fca21220d0         set     _scsibuscookies, %l1
F00B8070: d4040000                 ld      [%l0], %o2
F00B8074: 92102000                 mov     0, %o1
F00B8078: d0024011                 ld      [%o1+%l1], %o0
F00B807C: 80a28008                 cmp     %o2, %o0
F00B8080: 02800007                 be      loc_F00B809C
F00B8084: 80a62010                 cmp     %i0, 0x10
F00B8088: b0062001                 inc     %i0
F00B808C: 80a6200f                 cmp     %i0, 0xF
F00B8090: 04bffffa                 ble     loc_F00B8078
F00B8094: 92026004                 inc     4, %o1
F00B8098: 80a62010                 cmp     %i0, 0x10
F00B809C: 02800016                 be      loc_F00B80F4
F00B80A0: 113c04fc                 sethi   %hi(_scsi_spl), %o0
F00B80A4: 7fff7b18                 call    _splr
F00B80A8: d00220c0                 ld      [%o0+%lo(_scsi_spl)], %o0
F00B80AC: 952e2002                 sll     %i0, 2, %o2
F00B80B0: 133c04fc                 sethi   %hi(_scsibusctlrs), %o1
F00B80B4: d6028011                 ld      [%o2+%l1], %o3
F00B80B8: 92126110                 bset    %lo(_scsibusctlrs), %o1
F00B80BC: d2028009                 ld      [%o2+%o1], %o1
F00B80C0: da142004                 lduh    [%l0+4], %o5
F00B80C4: d40c2006                 ldub    [%l0+6], %o2
F00B80C8: 9810001b                 mov     %i3, %o4
F00B80CC: d423a05c                 st      %o2, [%sp+0x70+var_14]
F00B80D0: a0100008                 mov     %o0, %l0
F00B80D4: 9010000b                 mov     %o3, %o0
F00B80D8: 94100019                 mov     %i1, %o2
F00B80DC: 4000005a                 call    sub_F00B8244
F00B80E0: 9610001a                 mov     %i2, %o3
F00B80E4: b0100008                 mov     %o0, %i0
F00B80E8: 7fff7b0f                 call    _splx
F00B80EC: 90100010                 mov     %l0, %o0
F00B80F0: 30800002                 ba,a    locret_F00B80F8
F00B80F4: b0102000                 mov     0, %i0
F00B80F8: 81c7e008                 ret
F00B80FC: 81e80000                 restore
