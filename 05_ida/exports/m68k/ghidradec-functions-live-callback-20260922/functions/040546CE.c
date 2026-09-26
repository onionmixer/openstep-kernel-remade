
undefined8 _calloutEntryRemove(int *param_1)

{
  uint uVar1;
  int unaff_D2;
  char in_XF;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  
  uVar1 = param_1[7];
  if (uVar1 == 1) {
    *(int *)(*param_1 + 4) = param_1[1];
    *(int *)param_1[1] = *param_1;
    dword_40B4DD0 = dword_40B4DD0 + -1;
    param_1[7] = 0;
    bVar5 = param_1 < &unk_40B45B4;
    bVar4 = SBORROW4((int)param_1,0x40b45b4);
    bVar2 = (int)(param_1 + -0x102d16d) < 0;
    bVar3 = param_1 == &unk_40B45B4;
    bVar6 = bVar5;
    if (!bVar5) {
      bVar5 = param_1 < &DAT_40b4db4;
      bVar4 = SBORROW4((int)param_1,0x40b4db4);
      bVar2 = (int)(param_1 + -0x102d36d) < 0;
      bVar3 = param_1 == &DAT_40b4db4;
      bVar6 = false;
      if (bVar5) {
        *param_1 = (int)&dword_40B4DB8;
        param_1[1] = (int)dword_40B4DBC;
        *(int **)param_1[1] = param_1;
        dword_40B4DBC = param_1;
        bVar2 = (int)param_1 < 0;
        bVar3 = param_1 == (int *)0x0;
        bVar4 = false;
        bVar6 = false;
      }
    }
  }
  else {
    bVar5 = 2 < uVar1;
    bVar4 = SBORROW4(2,uVar1);
    bVar2 = (int)(2 - uVar1) < 0;
    bVar3 = false;
    bVar6 = bVar5;
    if (uVar1 == 2) {
      *(int *)(*param_1 + 4) = param_1[1];
      *(int *)param_1[1] = *param_1;
      param_1[7] = 0;
      bVar5 = param_1 < &unk_40B45B4;
      bVar4 = SBORROW4((int)param_1,0x40b45b4);
      bVar2 = (int)(param_1 + -0x102d16d) < 0;
      bVar3 = param_1 == &unk_40B45B4;
      bVar6 = bVar5;
      if (!bVar5) {
        bVar5 = param_1 < &DAT_40b4db4;
        bVar4 = SBORROW4((int)param_1,0x40b4db4);
        bVar2 = (int)(param_1 + -0x102d36d) < 0;
        bVar3 = param_1 == &DAT_40b4db4;
        bVar6 = false;
        if (bVar5) {
          *param_1 = (int)&dword_40B4DB8;
          param_1[1] = (int)dword_40B4DBC;
          *(int **)param_1[1] = param_1;
          dword_40B4DBC = param_1;
          bVar2 = (int)param_1 < 0;
          bVar3 = param_1 == (int *)0x0;
          bVar4 = false;
          bVar6 = false;
        }
      }
    }
  }
  return CONCAT44(CONCAT22((sword)(uVar1 >> 0x10),
                           (word)(byte)(bVar5 << 4 | bVar2 << 3 | bVar3 << 2 | bVar4 << 1 | bVar6)),
                  (int)(sword)(word)(byte)(in_XF << 4 | (unaff_D2 < 0) << 3 | (unaff_D2 == 0) << 2))
  ;
}

