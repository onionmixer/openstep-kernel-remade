
void _sec_to_tm(int param_1,int *param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined *puVar4;
  
  iVar1 = (int)(sword)((sword)(param_1 / 0x15180) + (sword)(param_1 >> 0x1f));
  iVar3 = param_1 + (iVar1 - (param_1 >> 0x1f)) * -0x15180;
  iVar1 = iVar1 - (param_1 >> 0x1f);
  if (iVar3 < 0) {
    iVar3 = iVar3 + 0x15180;
    iVar1 = iVar1 + -1;
  }
  *param_2 = iVar3 % 0x3c;
  param_2[1] = (iVar3 / 0x3c) % 0x3c;
  param_2[2] = (iVar3 / 0x3c) / 0x3c;
  if (iVar1 < 0) {
    uVar2 = 0x46;
    while (iVar1 < 0) {
      if ((uVar2 - 1 & 3) == 0) {
        iVar1 = iVar1 + 0x16e;
      }
      else {
        iVar1 = iVar1 + 0x16d;
      }
      uVar2 = uVar2 - 1;
    }
  }
  else {
    uVar2 = 0x46;
    while (0x16c < iVar1) {
      while( true ) {
        if ((uVar2 & 3) == 0) {
          iVar1 = iVar1 + -0x16e;
        }
        else {
          iVar1 = iVar1 + -0x16d;
        }
        uVar2 = uVar2 + 1;
        if ((uVar2 & 3) != 0) break;
        if (iVar1 < 0x16e) goto loc_4091550;
      }
    }
  }
loc_4091550:
  param_2[5] = uVar2;
  puVar4 = unk_40B28AA;
  if ((uVar2 & 3) == 0) {
    puVar4 = unk_40B28C2;
  }
  iVar3 = 0;
  for (; *(sword *)puVar4 <= iVar1; puVar4 = (undefined *)((int)puVar4 + 2)) {
    iVar1 = iVar1 - *(sword *)puVar4;
    iVar3 = iVar3 + 1;
  }
  param_2[4] = iVar3 + 1;
  param_2[3] = iVar1 + 1;
  return;
}
