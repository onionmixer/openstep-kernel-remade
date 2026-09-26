
void sub_40846D2(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  byte *pbVar4;
  int iVar5;
  undefined4 *puVar6;
  int *piVar7;
  
  piVar7 = &dword_40C6DFC;
  if (param_1 == 0) {
    piVar7 = &dword_40C6DF8;
  }
  iVar1 = *piVar7;
  iVar5 = 0;
  puVar2 = (undefined4 *)(&unk_40B50B0)[param_1 * 2];
  puVar6 = puVar2;
  for (; puVar2 != &unk_40B50B0 + param_1 * 2; puVar2 = (undefined4 *)puVar2[0xb]) {
    if (puVar2 < puVar6) {
      puVar6 = puVar2;
    }
    iVar5 = iVar5 + 1;
  }
  if ((iVar5 != 0) && (iVar5 == *(int *)((int)&unk_40B517C + param_1 * 4))) {
    _kfree(puVar6,iVar5 * 0x38);
    (&dword_40B50B4)[param_1 * 2] = &unk_40B50B0 + param_1 * 2;
    (&unk_40B50B0)[param_1 * 2] = &unk_40B50B0 + param_1 * 2;
    *(undefined4 *)((int)&unk_40B517C + param_1 * 4) = 0;
  }
  iVar5 = 0;
  puVar2 = (undefined4 *)(&unk_40B50A0)[param_1 * 2];
  puVar6 = puVar2;
  for (; puVar2 != &unk_40B50A0 + param_1 * 2; puVar2 = (undefined4 *)puVar2[0xb]) {
    if (puVar2 < puVar6) {
      puVar6 = puVar2;
    }
    iVar5 = iVar5 + 1;
  }
  if ((iVar5 != 0) && (iVar5 == *(int *)((int)&unk_40B5174 + param_1 * 4))) {
    _kfree(puVar6,iVar5 * 0x38);
    (&dword_40B50A4)[param_1 * 2] = &unk_40B50A0 + param_1 * 2;
    (&unk_40B50A0)[param_1 * 2] = &unk_40B50A0 + param_1 * 2;
    *(undefined4 *)((int)&unk_40B5174 + param_1 * 4) = 0;
  }
  if ((((*(int *)((int)&unk_40B5174 + param_1 * 4) == 0) &&
       (*(int *)((int)&unk_40B517C + param_1 * 4) == 0)) &&
      (iVar5 = *(int *)((int)&unk_40B5164 + param_1 * 4), iVar5 != 0)) &&
     (iVar3 = *(int *)((int)&unk_40B516C + param_1 * 4), iVar3 != 0)) {
    _kfree(iVar5,~_page_mask & _page_mask + iVar3);
    *(undefined4 *)((int)&unk_40B5164 + param_1 * 4) = 0;
    *(undefined4 *)((int)&unk_40B516C + param_1 * 4) = 0;
    if (iVar1 != 0) {
      pbVar4 = (byte *)(iVar1 + 0x24);
      *pbVar4 = *pbVar4 & 0xf7;
    }
  }
  return;
}
