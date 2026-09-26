F0091870: 9de3bf90                 save    %sp, -0x70, %sp
F0091874: d0062004                 ld      [%i0+4], %o0
F0091878: 80a22048                 cmp     %o0, 0x48 ! 'H'
F009187C: 1280002c                 bne     loc_F009192C
F0091880: 90103ed0                 mov     -0x130, %o0
F0091884: d0060000                 ld      [%i0], %o0
F0091888: 80a22000                 cmp     %o0, 0
F009188C: 16800028                 bge     loc_F009192C
F0091890: 90103ed0                 mov     -0x130, %o0
F0091894: d2062018                 ld      [%i0+0x18], %o1
F0091898: 1104480090122018         set     0x11200018, %o0
F00918A0: 920a7ffc                 and     %o1, -4, %o1
F00918A4: 80a24008                 cmp     %o1, %o0
F00918A8: 12800021                 bne     loc_F009192C
F00918AC: 90103ed0                 mov     -0x130, %o0
F00918B0: d0062020                 ld      [%i0+0x20], %o0
F00918B4: 133c0448                 sethi   %hi(dword_F01122B0), %o1
F00918B8: d20262b0                 ld      [%o1+%lo(dword_F01122B0)], %o1
F00918BC: 80a20009                 cmp     %o0, %o1
F00918C0: 1280001b                 bne     loc_F009192C
F00918C4: 90103ed0                 mov     -0x130, %o0
F00918C8: d0062028                 ld      [%i0+0x28], %o0
F00918CC: 133c0448                 sethi   %hi(dword_F01122B4), %o1
F00918D0: d20262b4                 ld      [%o1+%lo(dword_F01122B4)], %o1
F00918D4: 80a20009                 cmp     %o0, %o1
F00918D8: 12800015                 bne     loc_F009192C
F00918DC: 90103ed0                 mov     -0x130, %o0
F00918E0: d0062030                 ld      [%i0+0x30], %o0
F00918E4: 133c0448                 sethi   %hi(dword_F01122B8), %o1
F00918E8: d20262b8                 ld      [%o1+%lo(dword_F01122B8)], %o1
F00918EC: 80a20009                 cmp     %o0, %o1
F00918F0: 1280000f                 bne     loc_F009192C
F00918F4: 90103ed0                 mov     -0x130, %o0
F00918F8: d0062038                 ld      [%i0+0x38], %o0
F00918FC: 133c0448                 sethi   %hi(dword_F01122BC), %o1
F0091900: d20262bc                 ld      [%o1+%lo(dword_F01122BC)], %o1
F0091904: 80a20009                 cmp     %o0, %o1
F0091908: 12800009                 bne     loc_F009192C
F009190C: 90103ed0                 mov     -0x130, %o0
F0091910: d0062040                 ld      [%i0+0x40], %o0
F0091914: 133c0448                 sethi   %hi(dword_F01122C0), %o1
F0091918: d20262c0                 ld      [%o1+%lo(dword_F01122C0)], %o1
F009191C: 80a20009                 cmp     %o0, %o1
F0091920: 02800005                 be      loc_F0091934
F0091924: 01000000                 nop
F0091928: 90103ed0                 mov     -0x130, %o0
F009192C: 10800025                 ba      locret_F00919C0
F0091930: d026601c                 st      %o0, [%i1+0x1C]
F0091934: 7fff57f0                 call    _convert_port_to_task
F0091938: d006201c                 ld      [%i0+0x1C], %o0
F009193C: a0100008                 mov     %o0, %l0
F0091940: 7ffffa56                 call    _convert_port_to_dev
F0091944: d0062008                 ld      [%i0+8], %o0
F0091948: d4062024                 ld      [%i0+0x24], %o2
F009194C: d606202c                 ld      [%i0+0x2C], %o3
F0091950: da4e203c                 ldsb    [%i0+0x3C], %o5
F0091954: d2062044                 ld      [%i0+0x44], %o1
F0091958: 98062034                 add     %i0, 0x34, %o4 ! '4'
F009195C: d223a05c                 st      %o1, [%sp+0x70+var_14]
F0091960: 7ffffd63                 call    _kern_IOMapSparcDeviceMemory
F0091964: 92100010                 mov     %l0, %o1
F0091968: d026601c                 st      %o0, [%i1+0x1C]
F009196C: 7fff85cf                 call    _task_deallocate
F0091970: 90100010                 mov     %l0, %o0
F0091974: d006601c                 ld      [%i1+0x1C], %o0
F0091978: 80a22000                 cmp     %o0, 0
F009197C: 12800011                 bne     locret_F00919C0
F0091980: 01000000                 nop
F0091984: d006201c                 ld      [%i0+0x1C], %o0
F0091988: 80a22000                 cmp     %o0, 0
F009198C: 02800006                 be      loc_F00919A4
F0091990: 80a23fff                 cmp     %o0, -1
F0091994: 22800005                 be,a    loc_F00919A8
F0091998: 90102028                 mov     0x28, %o0 ! '('
F009199C: 7fff25e0                 call    _ipc_port_release_send
F00919A0: 01000000                 nop
F00919A4: 90102028                 mov     0x28, %o0 ! '('
F00919A8: d0266004                 st      %o0, [%i1+4]
F00919AC: 113c0448                 sethi   %hi(dword_F01122C4), %o0
F00919B0: d00222c4                 ld      [%o0+%lo(dword_F01122C4)], %o0
F00919B4: d0266020                 st      %o0, [%i1+0x20]
F00919B8: d0062034                 ld      [%i0+0x34], %o0
F00919BC: d0266024                 st      %o0, [%i1+0x24]
F00919C0: 81c7e008                 ret
F00919C4: 81e80000                 restore
