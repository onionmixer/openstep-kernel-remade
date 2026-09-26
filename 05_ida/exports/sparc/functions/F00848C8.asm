F00848C8: 9de3bf90                 save    %sp, -0x70, %sp
F00848CC: a0102004                 mov     4, %l0
F00848D0: 7fff913d                 call    _lock_write
F00848D4: 90100018                 mov     %i0, %o0
F00848D8: d006204c                 ld      [%i0+0x4C], %o0
F00848DC: 90022001                 inc     %o0
F00848E0: d026204c                 st      %o0, [%i0+0x4C]
F00848E4: d0062014                 ld      [%i0+0x14], %o0
F00848E8: 80a64008                 cmp     %i1, %o0
F00848EC: 2a800002                 bcs,a   loc_F00848F4
F00848F0: b2100008                 mov     %o0, %i1
F00848F4: d0062018                 ld      [%i0+0x18], %o0
F00848F8: 80a68008                 cmp     %i2, %o0
F00848FC: 38800002                 bgu,a   loc_F0084904
F0084900: b4100008                 mov     %o0, %i2
F0084904: 80a6401a                 cmp     %i1, %i2
F0084908: 38800002                 bgu,a   loc_F0084910
F008490C: b210001a                 mov     %i2, %i1
F0084910: 90100018                 mov     %i0, %o0
F0084914: 92100019                 mov     %i1, %o1
F0084918: 7ffffee4                 call    _vm_map_lookup_entry
F008491C: 9407bff4                 add     %fp, var_C, %o2
F0084920: 80a22000                 cmp     %o0, 0
F0084924: 0280000a                 be      loc_F008494C
F0084928: d207bff4                 ld      [%fp+var_C], %o1
F008492C: d0026008                 ld      [%o1+8], %o0
F0084930: 80a64008                 cmp     %i1, %o0
F0084934: 0880000a                 bleu    loc_F008495C
F0084938: 9006200c                 add     %i0, 0xC, %o0
F008493C: 7fffff75                 call    __vm_map_clip_start
F0084940: 94100019                 mov     %i1, %o2
F0084944: 10800006                 ba      loc_F008495C
F0084948: d207bff4                 ld      [%fp+var_C], %o1
F008494C: d007bff4                 ld      [%fp+var_C], %o0
F0084950: d0022004                 ld      [%o0+4], %o0
F0084954: d027bff4                 st      %o0, [%fp+var_C]
F0084958: d207bff4                 ld      [%fp+var_C], %o1
F008495C: d002600c                 ld      [%o1+0xC], %o0
F0084960: 80a68008                 cmp     %i2, %o0
F0084964: 1a800004                 bcc     loc_F0084974
F0084968: 9006200c                 add     %i0, 0xC, %o0
F008496C: 7fffffa1                 call    __vm_map_clip_end
F0084970: 9410001a                 mov     %i2, %o2
F0084974: d207bff4                 ld      [%fp+var_C], %o1
F0084978: d0026008                 ld      [%o1+8], %o0
F008497C: 80a20019                 cmp     %o0, %i1
F0084980: 1280001e                 bne     loc_F00849F8
F0084984: 01000000                 nop
F0084988: d002600c                 ld      [%o1+0xC], %o0
F008498C: 80a2001a                 cmp     %o0, %i2
F0084990: 1280001a                 bne     loc_F00849F8
F0084994: 01000000                 nop
F0084998: d6026018                 ld      [%o1+0x18], %o3
F008499C: 80a2e000                 cmp     %o3, 0
F00849A0: 06800016                 bl      loc_F00849F8
F00849A4: 113c04f4                 sethi   %hi(_vm_submap_object), %o0
F00849A8: d4026010                 ld      [%o1+0x10], %o2
F00849AC: d0022350                 ld      [%o0+%lo(_vm_submap_object)], %o0
F00849B0: 80a28008                 cmp     %o2, %o0
F00849B4: 12800011                 bne     loc_F00849F8
F00849B8: 11040000                 sethi   0x10000000, %o0
F00849BC: 808ac008                 btst    %o0, %o3
F00849C0: 1280000e                 bne     loc_F00849F8
F00849C4: 01000000                 nop
F00849C8: c0226010                 clr     [%o1+0x10]
F00849CC: 400007bb                 call    _vm_object_deallocate
F00849D0: 9010000a                 mov     %o2, %o0
F00849D4: 9010001b                 mov     %i3, %o0
F00849D8: a0102000                 mov     0, %l0
F00849DC: d207bff4                 ld      [%fp+var_C], %o1
F00849E0: 17080000                 sethi   0x20000000, %o3
F00849E4: d4026018                 ld      [%o1+0x18], %o2
F00849E8: d0226010                 st      %o0, [%o1+0x10]
F00849EC: 9412800b                 bset    %o3, %o2
F00849F0: 7ffffdf4                 call    _vm_map_reference
F00849F4: d4226018                 st      %o2, [%o1+0x18]
F00849F8: 7fff918f                 call    _lock_done
F00849FC: 90100018                 mov     %i0, %o0
F0084A00: 81c7e008                 ret
F0084A04: 91e80010                 restore %g0, %l0, %o0
