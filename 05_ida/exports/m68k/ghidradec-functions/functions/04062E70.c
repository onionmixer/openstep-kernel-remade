
undefined4 _vnode_pagein(int param_1,undefined4 *param_2)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  bool bVar6;
  uint uStack_8;
  
  bVar6 = false;
  iVar1 = *(int *)(*(int *)(param_1 + 0x14) + 0x24);
  piVar2 = (int *)_vnode_pager_vget(iVar1);
  iVar5 = *(int *)(*(int *)(param_1 + 0x14) + 0x28) + *(int *)(param_1 + 0x18);
  if (*(char *)(iVar1 + 0xc) < '\0') {
    iVar3 = sub_4062AD4(iVar1,iVar5,1,&uStack_8);
    if (iVar3 == 5) {
      bVar6 = true;
    }
    else {
      iVar5 = (uStack_8 & 0xffffff) << (_page_shift & 0x3f);
      piVar2 = *(int **)((&unk_40B4E00)[uStack_8 >> 0x18] + 8);
    }
  }
  uVar4 = 1;
  if (!bVar6) {
    uVar4 = (**(code **)(piVar2[7] + 0x74))(piVar2,param_1,iVar5);
    if (param_2 != (undefined4 *)0x0) {
      *param_2 = *(undefined4 *)(*piVar2 + 0x30);
    }
  }
  _vnode_pager_vput(iVar1);
  return uVar4;
}
