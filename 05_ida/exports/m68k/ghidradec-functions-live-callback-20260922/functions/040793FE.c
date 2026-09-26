
undefined4 _od_write_label(int param_1,undefined4 param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined2 uVar5;
  int iVar4;
  undefined4 uVar6;
  int iVar7;
  undefined2 *puVar8;
  int iVar9;
  word wStack_14;
  undefined auStack_a [5];
  char cStack_5;
  
  uVar6 = 1;
  piVar1 = *(int **)(param_1 + 0xae);
  if ((*piVar1 == 0x4e655854) || (*piVar1 == 0x646c5632)) {
    wStack_14 = 0x1c48;
    puVar8 = (undefined2 *)((int)piVar1 + 0x1c46);
  }
  else {
    wStack_14 = 0x230;
    puVar8 = (undefined2 *)((int)piVar1 + 0x22e);
  }
  iVar3 = ((param_1 + -0x40c3ec8) * -0x2593f69b >> 1) << 3;
  if (piVar1[9] < 0) {
    for (iVar7 = 3; *(int *)(*(int *)(param_1 + 0xb6) + 0x18 + iVar7 * 4) == -1; iVar7 = iVar7 + -1)
    {
    }
    iVar9 = iVar7 + 1;
  }
  else {
    iVar7 = 0;
    iVar9 = 4;
  }
  if (iVar7 < iVar9) {
    do {
      iVar2 = *(int *)(*(int *)(param_1 + 0xb6) + 0x18 + iVar7 * 4);
      if (iVar2 != -1) {
        if (-1 < *(sword *)(param_1 + 0xd8)) {
          return 0x14;
        }
        if (((*(sword *)(piVar1 + 0x1c) == 0) || (iVar2 < *(sword *)(piVar1 + 0x1c))) ||
           (piVar1[0x19] * piVar1[0x18] * piVar1[0x1a] - (int)*(sword *)((int)piVar1 + 0x72) < iVar2
           )) {
          piVar1[1] = iVar2;
          *puVar8 = 0;
          uVar5 = _checksum_16(piVar1,wStack_14 >> 1);
          *puVar8 = uVar5;
          iVar4 = _od_cmd(iVar3,1,iVar2,piVar1,0x1c48,&cStack_5,0,0,0,param_2);
          if ((iVar4 == 0) &&
             ((((*piVar1 == 0x4e655854 || (*piVar1 == 0x646c5632)) ||
               (iVar4 = _od_cmd(iVar3,1,iVar2 + 4,*(undefined4 *)(param_1 + 0xb2),0x3000,&cStack_5,0
                                ,0,0,param_2), iVar4 == 0)) &&
              (iVar4 = _od_cmd(iVar3,1,piVar1[0x19] + iVar2,*(undefined4 *)(param_1 + 0xc6),
                               *(undefined4 *)(param_1 + 0xca),&cStack_5,0,0,0,param_2), iVar4 == 0)
              ))) {
            if ((piVar1[9] < 0) && (_dma_recover_wl != 0)) {
              uVar6 = _kalloc(0x400);
              _od_cmd(iVar3,2,iVar2,uVar6,0x400,auStack_a,0,0,0,param_2);
              _kfree(uVar6,0x400);
            }
            uVar6 = 0;
          }
          else if ((iVar4 == 5) && (cStack_5 == '\x13')) {
            return 0x13;
          }
        }
      }
      iVar7 = iVar7 + 1;
    } while (iVar7 < iVar9);
  }
  return uVar6;
}

