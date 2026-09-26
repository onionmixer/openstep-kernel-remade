/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0017a820 */

undefined4 _vm_deactivate(int param_1,uint param_2,uint param_3,undefined4 param_4)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  int local_c;
  uint local_8;
  
  if (param_1 == 0) {
    uVar5 = 5;
  }
  else {
    if (param_3 == 0) {
      param_3 = *(int *)(param_1 + 0x18) - *(int *)(param_1 + 0x14);
    }
    if (param_2 == 0) {
      param_2 = *(uint *)(param_1 + 0x14);
    }
    _lock_read(param_1);
    local_c = *(int *)(param_1 + 0x10);
    local_8 = param_2;
    if (local_c != param_1 + 0xc) {
      do {
        if ((*(byte *)(local_c + 0x18) & 5) == 0) {
          uVar6 = *(uint *)(local_c + 8);
          if ((uVar6 <= param_3) && (uVar7 = *(uint *)(local_c + 0xc), local_8 < uVar7)) {
            if (local_8 < uVar6) {
              local_8 = uVar6;
            }
            uVar8 = param_3;
            if (uVar7 < param_3) {
              uVar8 = uVar7;
            }
            puVar3 = *(undefined4 **)(local_c + 0x10);
            uVar6 = (local_8 + *(int *)(local_c + 0x14)) - uVar6;
            uVar7 = (uVar8 + uVar6) - local_8;
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
              for (puVar4 = (undefined4 *)*puVar3; puVar3 != puVar4;
                  puVar4 = (undefined4 *)puVar4[2]) {
                if ((uVar6 <= (uint)puVar4[6]) && ((uint)puVar4[6] < uVar7)) {
                  _vm_policy_apply(puVar3,puVar4,param_4);
                }
              }
              uVar7 = uVar7 - uVar6;
              uVar8 = puVar3[5];
              if ((uVar8 != 0) && (uVar8 < uVar7)) {
                uVar7 = uVar8;
              }
              FUN_0017a4f0(puVar3[8],uVar6 + puVar3[9],uVar6 + puVar3[9] + uVar7,param_4);
              LOCK();
              puVar3[4] = 0;
              UNLOCK();
              _thread_wakeup_prim(puVar3,0,0);
            }
          }
        }
        else {
          FUN_0017a594(*(undefined4 *)(local_c + 0x10),local_8,param_3,param_4);
        }
        local_c = *(int *)(local_c + 4);
      } while (local_c != param_1 + 0xc);
    }
    _lock_done(param_1);
    uVar5 = 0;
  }
  return uVar5;
}

