F00388E4: 9de3bf88                 save    %sp, -0x78, %sp
F00388E8: 80a62001                 cmp     %i0, 1
F00388EC: 0280000a                 be      loc_F0038914
F00388F0: 92100019                 mov     %i1, %o1
F00388F4: 80a62015                 cmp     %i0, 0x15
F00388F8: 18800023                 bgu     locret_F0038984
F00388FC: 113c0432                 sethi   %hi(_inetctlerrmap), %o0
F0038900: 90122010                 bset    %lo(_inetctlerrmap), %o0
F0038904: d00e0008                 ldub    [%i0+%o0], %o0
F0038908: 80a22000                 cmp     %o0, 0
F003890C: 0280001e                 be      locret_F0038984
F0038910: 01000000                 nop
F0038914: 80a6a000                 cmp     %i2, 0
F0038918: 0280000f                 be      loc_F0038954
F003891C: 113c04d9                 sethi   %hi(_udb), %o0
F0038920: 90122100                 bset    %lo(_udb), %o0
F0038924: d80e8000                 ldub    [%i2], %o4
F0038928: 9607bff4                 add     %fp, var_C, %o3
F003892C: d406a00c                 ld      [%i2+0xC], %o2
F0038930: 9a100018                 mov     %i0, %o5
F0038934: d427bff4                 st      %o2, [%fp+var_C]
F0038938: 980b200f                 and     %o4, 0xF, %o4
F003893C: 992b2002                 sll     %o4, 2, %o4
F0038940: 9406800c                 add     %i2, %o4, %o2
F0038944: d412a002                 lduh    [%o2+2], %o2
F0038948: 053c00e2                 sethi   -0xFFC7800, %g2
F003894C: 1080000b                 ba      loc_F0038978
F0038950: d816800c                 lduh    [%i2+%o4], %o4
F0038954: 90122100                 bset    0x100, %o0
F0038958: 94102000                 mov     0, %o2
F003895C: 9607bff4                 add     %fp, var_C, %o3
F0038960: 1b3c04d9                 sethi   %hi(_zeroin_addr), %o5
F0038964: c4036150                 ld      [%o5+%lo(_zeroin_addr)], %g2
F0038968: 98102000                 mov     0, %o4
F003896C: 9a100018                 mov     %i0, %o5
F0038970: c427bff4                 st      %g2, [%fp+var_C]
F0038974: 053c00e2                 sethi   -0xFFC7800, %g2
F0038978: 8410a0c0                 bset    0xC0, %g2
F003897C: 7fffe106                 call    _in_pcbnotify
F0038980: c423a05c                 st      %g2, [%sp+0x78+var_1C]
F0038984: 81c7e008                 ret
F0038988: 81e80000                 restore
