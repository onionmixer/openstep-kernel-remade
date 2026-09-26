
int _adb_system_info(undefined4 *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  
  iVar2 = dword_40B0830;
  if (dword_40B0830 == 0) {
    iVar3 = 0;
  }
  else {
    iVar3 = 0;
    iVar4 = 0;
    iVar5 = dword_40B0830;
    puVar6 = param_1;
    do {
      *puVar6 = 2;
      iVar1 = iVar5 * 10;
      *(undefined4 *)((int)param_1 + iVar4 + 4) = *(undefined4 *)((int)&unk_40B4E92 + iVar1);
      *(uint *)((int)param_1 + iVar4 + 0xc) = (uint)*(byte *)((int)&unk_40B4E92 + iVar1 + 4);
      iVar1 = *(int *)((int)&unk_40B4E92 + iVar1);
      if (iVar1 == 3) {
        *(undefined4 *)((int)param_1 + iVar4 + 8) = 2;
      }
      else if (iVar1 < 4) {
        if (iVar1 == 2) {
          *(undefined4 *)((int)param_1 + iVar4 + 8) = 1;
        }
        else {
loc_4064880:
          *(undefined4 *)((int)param_1 + iVar4 + 8) = 0;
        }
      }
      else {
        if (iVar1 != 4) goto loc_4064880;
        *(undefined4 *)((int)param_1 + iVar4 + 8) = 3;
      }
      iVar5 = *(int *)((int)&dword_40B4E98 + iVar5 * 10);
      iVar4 = iVar4 + 0x10;
      puVar6 = puVar6 + 4;
      iVar3 = iVar3 + 1;
    } while ((param_2 != iVar3) && (iVar2 != iVar5));
  }
  return iVar3;
}

