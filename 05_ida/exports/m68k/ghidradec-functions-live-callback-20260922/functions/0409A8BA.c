
undefined4 _allocbuf(int param_1,int param_2)

{
  int iVar1;
  uint *puVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  puVar2 = dword_40B58B0;
  iVar5 = _m68k_page_size * ((param_2 + -1 + _m68k_page_size) / _m68k_page_size);
  iVar1 = *(int *)(param_1 + 0x18);
  if (iVar1 != iVar5) {
    if (iVar5 < iVar1) {
      if (dword_40B58B0 != &DAT_40b58a4) {
        *(uint *)(dword_40B58B0[4] + 0xc) = dword_40B58B0[3];
        *(uint *)(puVar2[3] + 0x10) = puVar2[4];
        *puVar2 = *puVar2 | 8;
        _pagemove(iVar5 + *(int *)(param_1 + 0x20),puVar2[8],*(int *)(param_1 + 0x18) - iVar5);
        puVar2[6] = *(int *)(param_1 + 0x18) - iVar5;
        *(int *)(param_1 + 0x18) = iVar5;
        *(byte *)((int)puVar2 + 1) = *(byte *)((int)puVar2 + 1) | 1;
        puVar2[5] = 0;
        _brelse(puVar2);
      }
    }
    else if (iVar5 - iVar1 != 0 && iVar1 <= iVar5) {
      do {
        iVar4 = iVar5 - *(int *)(param_1 + 0x18);
        iVar3 = _getnewbuf();
        iVar1 = *(int *)(iVar3 + 0x18);
        if (iVar1 <= iVar4) {
          iVar4 = iVar1;
        }
        _pagemove(*(int *)(iVar3 + 0x20) + (iVar1 - iVar4),
                  *(int *)(param_1 + 0x18) + *(int *)(param_1 + 0x20),iVar4);
        *(int *)(param_1 + 0x18) = iVar4 + *(int *)(param_1 + 0x18);
        iVar4 = *(int *)(iVar3 + 0x18) - iVar4;
        *(int *)(iVar3 + 0x18) = iVar4;
        if (iVar4 < *(int *)(iVar3 + 0x14)) {
          *(int *)(iVar3 + 0x14) = iVar4;
        }
        if (*(int *)(iVar3 + 0x18) < 1) {
          *(undefined4 *)(*(int *)(iVar3 + 8) + 4) = *(undefined4 *)(iVar3 + 4);
          *(undefined4 *)(*(int *)(iVar3 + 4) + 8) = *(undefined4 *)(iVar3 + 8);
          *(int *)(iVar3 + 4) = dword_40B58A8;
          *(undefined4 **)(iVar3 + 8) = &DAT_40b58a4;
          *(int *)(dword_40B58A8 + 8) = iVar3;
          dword_40B58A8 = iVar3;
          *(undefined2 *)(iVar3 + 0x1e) = 0xffff;
          *(undefined2 *)(iVar3 + 0x1c) = 0;
          *(byte *)(iVar3 + 1) = *(byte *)(iVar3 + 1) | 1;
        }
        _brelse(iVar3);
      } while (iVar5 - *(int *)(param_1 + 0x18) != 0 && *(int *)(param_1 + 0x18) <= iVar5);
    }
  }
  *(int *)(param_1 + 0x14) = param_2;
  return 1;
}

