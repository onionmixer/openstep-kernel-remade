/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0017a594 */

void FUN_0017a594(int param_1,uint param_2,uint param_3,undefined4 param_4)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int local_8;
  
  _lock_read(param_1);
  local_8 = *(int *)(param_1 + 0x10);
  if (local_8 != param_1 + 0xc) {
    do {
      if ((*(byte *)(local_8 + 0x18) & 5) == 0) {
        uVar5 = *(uint *)(local_8 + 8);
        if ((uVar5 <= param_3) && (uVar6 = *(uint *)(local_8 + 0xc), param_2 < uVar6)) {
          if (param_2 < uVar5) {
            param_2 = uVar5;
          }
          uVar7 = param_3;
          if (uVar6 < param_3) {
            uVar7 = uVar6;
          }
          puVar3 = *(undefined4 **)(local_8 + 0x10);
          uVar5 = (param_2 + *(int *)(local_8 + 0x14)) - uVar5;
          uVar6 = (uVar7 + uVar5) - param_2;
          if (puVar3 != (undefined4 *)0x0) {
            piVar1 = puVar3 + 4;
            do {
              do {
              } while (*piVar1 != 0);
              LOCK();
              iVar2 = *piVar1;
              *piVar1 = 1;
              UNLOCK();
            } while (iVar2 == 1);
            for (puVar4 = (undefined4 *)*puVar3; puVar3 != puVar4; puVar4 = (undefined4 *)puVar4[2])
            {
              if ((uVar5 <= (uint)puVar4[6]) && ((uint)puVar4[6] < uVar6)) {
                _vm_policy_apply(puVar3,puVar4,param_4);
              }
            }
            uVar6 = uVar6 - uVar5;
            uVar7 = puVar3[5];
            if ((uVar7 != 0) && (uVar7 < uVar6)) {
              uVar6 = uVar7;
            }
            FUN_0017a4f0(puVar3[8],uVar5 + puVar3[9],uVar5 + puVar3[9] + uVar6,param_4);
            LOCK();
            puVar3[4] = 0;
            UNLOCK();
            _thread_wakeup_prim(puVar3,0,0);
          }
        }
      }
      else {
        FUN_0017a594(*(undefined4 *)(local_8 + 0x10),param_2,param_3,param_4);
      }
      local_8 = *(int *)(local_8 + 4);
    } while (local_8 != param_1 + 0xc);
  }
  _lock_done(param_1);
  return;
}

