
uint _od_canon_remap(undefined4 param_1,undefined4 param_2,int param_3,int param_4)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  byte *pbVar7;
  sword *psStack_8;
  
  uVar1 = _od_errmsg_filter;
  uVar6 = 0;
  _od_errmsg_filter = 9;
  _kmem_alloc_wired(_kernel_map,&psStack_8,0x400);
  iVar2 = _od_cmd(((param_3 + -0x40c3ec8) * -0x2593f69b >> 1) << 3,2,
                  (0x4d50 - **(int **)(param_3 + 0xba)) *
                  (int)*(sword *)(*(int **)(param_3 + 0xba) + 1),psStack_8,0x400,0,0,0,0,0);
  if ((((iVar2 == 0) && (*psStack_8 == -0x1fe)) && (uVar6 = (uint)(word)psStack_8[1], param_4 == 0))
     && (iVar2 = 0, uVar6 != 0)) {
    iVar5 = 4;
    do {
      pbVar7 = (byte *)(iVar5 + (int)psStack_8);
      iVar4 = (uint)pbVar7[3] +
              (int)*(sword *)(*(int *)(param_3 + 0xba) + 4) *
              CONCAT31((int3)((uint)pbVar7[1] * 0x100 + (uint)*pbVar7 * 0x10000 >> 8),pbVar7[2]);
      if ((iVar4 != 0) && (*(int *)(param_3 + 0xbe) <= iVar4)) {
        iVar3 = _od_locate_alt(param_1,param_2,param_3,iVar4 - *(int *)(param_3 + 0xbe),iVar4);
        if (iVar3 == -1) {
          iVar4 = _od_remap(param_1,param_2,param_3,iVar4);
          if (iVar4 == 0) break;
        }
      }
      iVar5 = iVar5 + 4;
      iVar2 = iVar2 + 1;
    } while (iVar2 < (int)uVar6);
  }
  _kmem_free(_kernel_map,psStack_8,0x400);
  _od_errmsg_filter = uVar1;
  return uVar6;
}
