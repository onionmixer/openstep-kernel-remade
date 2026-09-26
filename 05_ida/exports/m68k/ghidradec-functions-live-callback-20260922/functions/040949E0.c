
void _addupc(int param_1,int param_2,sword param_3)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  sword sStack_6;
  
  if (param_2 != 0) {
    iVar3 = param_2;
    do {
      uVar2 = param_1 - *(int *)(iVar3 + 0x10);
      uVar1 = *(uint *)(iVar3 + 8);
      uVar2 = ((*(int *)(iVar3 + 0x14) * (uVar2 & 0xffff) >> 0x10) +
               *(int *)(iVar3 + 0x14) * (uVar2 >> 0x10) & 0xfffffffe) + uVar1;
      if ((uVar1 <= uVar2) && (uVar2 < *(int *)(iVar3 + 0xc) + uVar1)) {
        iVar3 = _copyinmsg(uVar2,&sStack_6,2);
        if (iVar3 != 0) {
          *(undefined4 *)(param_2 + 0x14) = 0;
          return;
        }
        sStack_6 = param_3 + sStack_6;
        _copyoutmsg(&sStack_6,uVar2,2);
        return;
      }
      iVar3 = *(int *)(iVar3 + 4);
    } while (iVar3 != 0);
  }
  return;
}

