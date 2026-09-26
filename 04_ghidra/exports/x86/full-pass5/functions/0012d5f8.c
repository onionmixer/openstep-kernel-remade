/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0012d5f8 */

void FUN_0012d5f8(int param_1,int *param_2,undefined4 param_3)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int *piVar5;
  uint local_30;
  int local_28;
  int local_24;
  undefined4 local_20;
  int *local_1c;
  undefined4 local_18;
  uint local_14;
  undefined4 local_10;
  int local_8;
  
  iVar1 = FUN_0012dc2c(param_1,param_3);
  if (iVar1 == 0) {
    param_2[1] = 0x46;
  }
  else {
    if (*(int *)(iVar1 + 0x28) == 2) {
      local_28 = (**(code **)(*(int *)(iVar1 + 0x1c) + 0x1c))
                           (iVar1,0x100,*(undefined4 *)(_active_u + 0x1c));
      if (local_28 == 0) {
        uVar2 = *(uint *)(param_1 + 0x24);
        if (uVar2 == 0) {
          param_2[3] = 0;
          param_2[4] = 0;
          param_2[5] = 0;
          *param_2 = 0;
        }
        else {
          if (0x2000 < uVar2) {
            uVar2 = 0x2000;
          }
          *(uint *)(param_1 + 0x24) = uVar2;
          while( true ) {
            iVar3 = _kalloc(*(undefined4 *)(param_1 + 0x24));
            param_2[5] = iVar3;
            param_2[-1] = *(int *)(param_1 + 0x24);
            *param_2 = *(int *)(param_1 + 0x24);
            local_30 = *(uint *)(param_1 + 0x20) & 0xfffffc00;
            param_2[2] = local_30;
            local_24 = param_2[5];
            local_20 = *(undefined4 *)(param_1 + 0x24);
            local_1c = &local_24;
            local_18 = 1;
            local_10 = 1;
            local_8 = *(int *)(param_1 + 0x24);
            local_14 = local_30;
            local_28 = (**(code **)(*(int *)(iVar1 + 0x1c) + 0x3c))
                                 (iVar1,&local_1c,*(undefined4 *)(_active_u + 0x1c));
            if (local_28 != 0) break;
            if (local_8 == 0) {
              param_2[3] = *(int *)(param_1 + 0x24);
              param_2[4] = 0;
            }
            else {
              param_2[3] = *(int *)(param_1 + 0x24) - local_8;
              param_2[4] = 1;
            }
            uVar2 = 0;
            for (piVar5 = (int *)param_2[5];
                (uVar2 < (uint)param_2[3] &&
                ((*(ushort *)(piVar5 + 1) + local_30 <= *(uint *)(param_1 + 0x20) || (*piVar5 == 0))
                )); piVar5 = (int *)((int)piVar5 + uVar4)) {
              uVar4 = (uint)*(ushort *)(piVar5 + 1);
              uVar2 = uVar2 + uVar4;
              local_30 = local_30 + uVar4;
            }
            if (uVar2 == 0) goto LAB_0012d7b8;
            param_2[3] = param_2[3] - uVar2;
            *param_2 = *param_2 - uVar2;
            param_2[2] = local_30;
            iVar3 = param_2[5];
            param_2[5] = iVar3 + uVar2;
            if ((param_2[3] != 0) || (param_2[4] != 0)) goto LAB_0012d7b8;
            _kfree((iVar3 + uVar2 + *param_2) - param_2[-1],param_2[-1]);
            *(int *)(param_1 + 0x20) = param_2[2];
          }
          param_2[3] = 0;
        }
      }
    }
    else {
      _printf(s_rfs_readdir__attempt_to_read_non_001dbfc6);
      local_28 = 0x14;
    }
LAB_0012d7b8:
    param_2[1] = local_28;
    _vn_rele(iVar1);
  }
  return;
}

