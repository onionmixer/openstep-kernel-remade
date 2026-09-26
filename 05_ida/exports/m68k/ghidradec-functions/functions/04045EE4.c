
uint _mach_port_names_helper
               (int param_1,uint *param_2,undefined4 param_3,int param_4,int param_5,int *param_6)

{
  int iVar1;
  bool bVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  uVar4 = *param_2;
  uVar5 = param_2[2];
  uVar3 = uVar4 & 0x50000;
  if (uVar3 != 0) {
    bVar2 = false;
    if ((-1 < *(int *)(param_2[1] + 4)) &&
       (uVar3 = *(int *)(param_2[1] + 8) - param_1, (int)uVar3 < 0)) {
      bVar2 = true;
    }
    if (bVar2) {
      if ((uVar4 & 0x400000) != 0) {
        return uVar3;
      }
      uVar4 = uVar4 & 0xffc0ffff | 0x100000;
      if (uVar5 != 0) {
        uVar4 = uVar4 + 1;
      }
      uVar5 = 0;
    }
  }
  uVar3 = uVar4 & 0x1f0000;
  if ((uVar4 & 0x400000) == 0) {
    if (uVar5 != 0) {
      uVar3 = uVar3 | 0x80000000;
    }
  }
  else {
    uVar3 = uVar3 | 0x20000000;
  }
  if ((uVar4 & 0x200000) != 0) {
    uVar3 = uVar3 | 0x40000000;
  }
  iVar1 = *param_6;
  *(undefined4 *)(param_4 + iVar1 * 4) = param_3;
  *(uint *)(param_5 + iVar1 * 4) = uVar3;
  *param_6 = iVar1 + 1;
  return uVar3;
}
