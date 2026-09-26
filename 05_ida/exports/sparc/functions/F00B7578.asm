F00B7578: 9de3bf98                 save    %sp, -0x68, %sp
F00B757C: 96102000                 mov     0, %o3
F00B7580: 912ae010                 sll     %o3, 16, %o0
F00B7584: 913a200e                 sra     %o0, 14, %o0
F00B7588: 90020018                 add     %o0, %i0, %o0
F00B758C: d20220b8                 ld      [%o0+0xB8], %o1
F00B7590: 80a26000                 cmp     %o1, 0
F00B7594: 0280002d                 be      loc_F00B7648
F00B7598: 9002e001                 add     %o3, 1, %o0
F00B759C: d00a6029                 ldub    [%o1+0x29], %o0
F00B75A0: 80a22000                 cmp     %o0, 0
F00B75A4: 3280000c                 bne,a   loc_F00B75D4
F00B75A8: d412605c                 lduh    [%o1+0x5C], %o2
F00B75AC: d05620b2                 ldsh    [%i0+0xB2], %o0
F00B75B0: 80a23fff                 cmp     %o0, -1
F00B75B4: 02800007                 be      loc_F00B75D0
F00B75B8: 912a2002                 sll     %o0, 2, %o0
F00B75BC: 90020018                 add     %o0, %i0, %o0
F00B75C0: d00220b8                 ld      [%o0+0xB8], %o0
F00B75C4: 80a24008                 cmp     %o1, %o0
F00B75C8: 12800020                 bne     loc_F00B7648
F00B75CC: 9002e001                 add     %o3, 1, %o0
F00B75D0: d412605c                 lduh    [%o1+0x5C], %o2
F00B75D4: 808aa020                 btst    0x20, %o2 ! ' '
F00B75D8: 0280001c                 be      loc_F00B7648
F00B75DC: 9002e001                 add     %o3, 1, %o0
F00B75E0: d0026058                 ld      [%o1+0x58], %o0
F00B75E4: 80a22000                 cmp     %o0, 0
F00B75E8: 02800004                 be      loc_F00B75F8
F00B75EC: 90023fff                 inc     -1, %o0
F00B75F0: 10800015                 ba      loc_F00B7644
F00B75F4: d0226058                 st      %o0, [%o1+0x58]
F00B75F8: d00620a0                 ld      [%i0+0xA0], %o0
F00B75FC: d0020000                 ld      [%o0], %o0
F00B7600: 808a2003                 btst    3, %o0
F00B7604: 02800006                 be      loc_F00B761C
F00B7608: 90102001                 mov     1, %o0
F00B760C: d0226058                 st      %o0, [%o1+0x58]
F00B7610: 7ffff5dc                 call    _espsvc
F00B7614: 90100018                 mov     %i0, %o0
F00B7618: 30800012                 ba,a    locret_F00B7660
F00B761C: 808aa010                 btst    0x10, %o2
F00B7620: 02800006                 be      loc_F00B7638
F00B7624: 90100018                 mov     %i0, %o0
F00B7628: 932ae010                 sll     %o3, 16, %o1
F00B762C: 4000005e                 call    _esp_disccmd_timeout
F00B7630: 933a6010                 sra     %o1, 16, %o1
F00B7634: 3080000b                 ba,a    locret_F00B7660
F00B7638: 4000000c                 call    _esp_curcmd_timeout
F00B763C: 90100018                 mov     %i0, %o0
F00B7640: 30800008                 ba,a    locret_F00B7660
F00B7644: 9002e001                 add     %o3, 1, %o0
F00B7648: 96100008                 mov     %o0, %o3
F00B764C: 912a2010                 sll     %o0, 16, %o0
F00B7650: 913a2010                 sra     %o0, 16, %o0
F00B7654: 80a2203f                 cmp     %o0, 0x3F ! '?'
F00B7658: 04bfffcb                 ble     loc_F00B7584
F00B765C: 912ae010                 sll     %o3, 16, %o0
F00B7660: 81c7e008                 ret
F00B7664: 81e80000                 restore
