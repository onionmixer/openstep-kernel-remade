/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001b7d3c */

undefined4
FUN_001b7d3c(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            )

{
  uint *puVar1;
  uint *puVar2;
  uint uVar3;
  uint *puVar4;
  int *piVar5;
  undefined4 uVar6;
  uint uVar7;
  uint uVar8;
  uint local_8;
  
  local_8 = 0;
  _objc_msgSend(*(undefined4 *)(param_1 + 0x10),PTR_s_lock_001f9220);
  uVar3 = _objc_msgSend(*(undefined4 *)(param_1 + 0xc),PTR_s_count_001f92d8);
  if (uVar3 != 0) {
    puVar1 = *(uint **)(param_1 + 0x2c);
    if ((uint *)(param_1 + 0x2c) != puVar1) {
      puVar2 = (uint *)puVar1[2];
      piVar5 = (int *)puVar1[3];
      puVar4 = puVar2;
      if ((uint *)(param_1 + 0x2c) != puVar2) {
        puVar4 = puVar2 + 2;
      }
      puVar4[1] = (uint)piVar5;
      if ((int *)(param_1 + 0x2c) != piVar5) {
        piVar5 = piVar5 + 2;
      }
      *piVar5 = (int)puVar2;
      uVar8 = 0;
      if (uVar3 != 0) {
        do {
          uVar6 = _objc_msgSend(*(undefined4 *)(param_1 + 0xc),PTR_s_objectAt__001f92e8,uVar8);
          uVar7 = _objc_msgSend(uVar6,PTR_s_mixBuffer_maxCount_rate_format_c_001f976c,puVar1[1],
                                *(undefined4 *)(param_1 + 0x40),param_3,param_4,param_5,puVar1,
                                local_8 == 0,uVar3);
          if (local_8 < uVar7) {
            local_8 = uVar7;
          }
          uVar8 = uVar8 + 1;
        } while (uVar8 < uVar3);
      }
      _objc_msgSend(*(undefined4 *)(param_1 + 0x10),PTR_s_unlock_001f9474);
      if (local_8 == 0) {
        uVar3 = *(uint *)(param_1 + 0x2c);
        if (param_1 + 0x2cU == uVar3) {
          *(uint **)(param_1 + 0x2c) = puVar1;
          *(uint **)(param_1 + 0x30) = puVar1;
          puVar1[2] = uVar3;
          puVar1[3] = uVar3;
        }
        else {
          puVar1[3] = param_1 + 0x2cU;
          puVar1[2] = uVar3;
          *(uint **)(param_1 + 0x2c) = puVar1;
          *(uint **)(uVar3 + 0xc) = puVar1;
        }
        return 0;
      }
      *puVar1 = local_8;
      uVar3 = param_1 + 0x24;
      if (*(uint *)(param_1 + 0x24) == uVar3) {
        *(uint **)(param_1 + 0x24) = puVar1;
        *(uint **)(param_1 + 0x28) = puVar1;
        puVar1[2] = uVar3;
        puVar1[3] = uVar3;
      }
      else {
        uVar8 = *(uint *)(param_1 + 0x28);
        puVar1[3] = uVar8;
        puVar1[2] = uVar3;
        *(uint **)(param_1 + 0x28) = puVar1;
        *(uint **)(uVar8 + 8) = puVar1;
      }
      *(int *)(param_1 + 0x34) = *(int *)(param_1 + 0x34) + 1;
      return 1;
    }
  }
  _objc_msgSend(*(undefined4 *)(param_1 + 0x10),PTR_s_unlock_001f9474);
  return 0;
}

