
void _km_switch_to_vm(void)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
  iVar1 = _mon_global;
  if ((dword_40B1BC6 == 0) && ((byte_40B6953 & 1) != 0)) {
    dword_40B1BC6 = 1;
    iVar3 = 0;
    iVar4 = 0;
    do {
      if (*(int *)((int)&unk_40B6978 + iVar4) != 0) {
        uVar2 = _map_addr(*(undefined4 *)((int)&unk_40B6970 + iVar4),
                          *(int *)((int)&unk_40B6978 + iVar4));
        *(undefined4 *)((int)&dword_40B6974 + iVar4) = uVar2;
      }
      iVar4 = iVar4 + 0xc;
      iVar3 = iVar3 + 1;
    } while (iVar3 < 6);
    if (0x2b < *(sword *)(iVar1 + 0x30c)) {
      *(undefined4 *)(iVar1 + 0x35c) = dword_40B6974;
      *(undefined4 *)(iVar1 + 0x368) = dword_40B6980;
      *(int *)(iVar1 + 0x374) = dword_40B698C;
      *(undefined4 *)(iVar1 + 0x380) = dword_40B6998;
      *(undefined4 *)(iVar1 + 0x38c) = dword_40B69A4;
      *(undefined4 *)(iVar1 + 0x398) = dword_40B69B0;
    }
    if (dword_40B6990 == 0) {
      _kmem_alloc_wired(_kernel_map,&dword_40B698C,(0x6a0 / _km_coni) * 0xd2);
      if (dword_40B698C != 0) {
        dword_40B6990 = (0x6a0 / _km_coni) * 0xd2;
        word_40B68E2 = 0x32;
        word_40B68E6 = 0xf;
        dword_40B68EC = dword_40B698C;
        unk_40B6904 = unk_40B6904 | 0x10;
      }
    }
  }
  return;
}

