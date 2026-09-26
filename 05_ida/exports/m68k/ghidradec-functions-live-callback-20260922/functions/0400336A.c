
int _compress(int param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = 0;
  uVar3 = 0;
  uVar1 = param_1 * 0x40;
  if (param_2 != 0) {
    uVar1 = param_2 / 0x3d09 + uVar1;
  }
  for (; 0x1fff < (int)uVar1; uVar1 = (int)uVar1 >> 3) {
    iVar2 = iVar2 + 1;
    uVar3 = uVar1 & 4;
  }
  if ((uVar3 != 0) && (uVar1 = uVar1 + 1, 0x1fff < (int)uVar1)) {
    uVar1 = (int)uVar1 >> 3;
    iVar2 = iVar2 + 1;
  }
  return uVar1 + iVar2 * 0x2000;
}

