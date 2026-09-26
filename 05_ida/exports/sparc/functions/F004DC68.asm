F004DC68: 9de3bf98                 save    %sp, -0x68, %sp
F004DC6C: 113c04eb901221b0         set     _ihead, %o0
F004DC74: 921021ff                 mov     0x1FF, %o1
F004DC78: d0220000                 st      %o0, [%o0]
F004DC7C: d0222004                 st      %o0, [%o0+4]
F004DC80: 92827fff                 inccc   -1, %o1
F004DC84: 1cbffffd                 bpos    loc_F004DC78
F004DC88: 90022008                 inc     8, %o0
F004DC8C: 113c04eb                 sethi   %hi(_ifreeh), %o0
F004DC90: c02221a0                 clr     [%o0+%lo(_ifreeh)]
F004DC94: 113c04eb                 sethi   %hi(_ifreet), %o0
F004DC98: c02221a8                 clr     [%o0+%lo(_ifreet)]
F004DC9C: 113c04d4                 sethi   %hi(_inode_list), %o0
F004DCA0: c0222140                 clr     [%o0+%lo(_inode_list)]
F004DCA4: 901020e8                 mov     0xE8, %o0
F004DCA8: 1300009192027268         set     0x23668, %o1
F004DCB0: 193c043b                 sethi   %hi(aInodeStructure), %o4! "inode structures"
F004DCB4: 932a6004                 sll     %o1, 4, %o1
F004DCB8: 94102000                 mov     0, %o2
F004DCBC: 96102000                 mov     0, %o3
F004DCC0: 4000a89e                 call    _zinit
F004DCC4: 98132018                 bset    %lo(aInodeStructure), %o4! "inode structures"
F004DCC8: 133c04ef                 sethi   %hi(_inode_zone), %o1
F004DCCC: d02261b0                 st      %o0, [%o1+%lo(_inode_zone)]
F004DCD0: 81c7e008                 ret
F004DCD4: 81e80000                 restore
