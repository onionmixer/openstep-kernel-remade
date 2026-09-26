/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0010bb88 */

void FUN_0010bb88(undefined1 *param_1,undefined1 *param_2)

{
  undefined1 uVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  int iVar5;
  undefined1 *puVar6;
  undefined1 *puVar7;
  int iVar8;
  int local_18;
  undefined1 *local_8;
  
  iVar5 = (int)param_2 - (int)param_1;
  do {
    local_8 = param_1 + DAT_001dac08 * (iVar5 / DAT_001dac08 >> 1);
    if (DAT_001dac10 <= iVar5) {
      iVar5 = (*DAT_001dac04)(param_1,local_8);
      puVar3 = local_8;
      if (0 < iVar5) {
        puVar3 = param_1;
      }
      puVar6 = param_2 + -DAT_001dac08;
      iVar5 = (*DAT_001dac04)(puVar3,puVar6);
      if (0 < iVar5) {
        puVar2 = param_1;
        if (puVar3 == param_1) {
          puVar2 = local_8;
        }
        iVar5 = (*DAT_001dac04)(puVar2,puVar6);
        puVar3 = puVar2;
        if (iVar5 < 0) {
          puVar3 = puVar6;
        }
      }
      if (puVar3 != local_8) {
        local_18 = DAT_001dac08;
        puVar6 = local_8;
        do {
          uVar1 = *puVar6;
          *puVar6 = *puVar3;
          puVar6 = puVar6 + 1;
          *puVar3 = uVar1;
          puVar3 = puVar3 + 1;
          local_18 = local_18 + -1;
        } while (local_18 != 0);
      }
    }
    puVar3 = param_2 + -DAT_001dac08;
    puVar6 = param_1;
    while( true ) {
      while ((puVar2 = puVar3, puVar6 < local_8 &&
             (iVar5 = (*DAT_001dac04)(puVar6,local_8), iVar5 < 1))) {
        puVar3 = puVar2;
        puVar6 = puVar6 + DAT_001dac08;
      }
      for (; local_8 < puVar2; puVar2 = puVar2 + -DAT_001dac08) {
        iVar5 = (*DAT_001dac04)(local_8,puVar2);
        if (0 < iVar5) {
          puVar7 = puVar6 + DAT_001dac08;
          puVar3 = puVar2;
          puVar4 = puVar2;
          if (local_8 != puVar6) {
            puVar3 = puVar2 + -DAT_001dac08;
            puVar4 = local_8;
          }
          goto LAB_0010bcb2;
        }
      }
      if (local_8 == puVar6) break;
      puVar3 = puVar2 + -DAT_001dac08;
      puVar2 = local_8;
      puVar7 = puVar6;
      puVar4 = puVar6;
LAB_0010bcb2:
      local_8 = puVar4;
      local_18 = DAT_001dac08;
      puVar4 = puVar6;
      do {
        uVar1 = *puVar4;
        *puVar4 = *puVar2;
        puVar4 = puVar4 + 1;
        *puVar2 = uVar1;
        puVar2 = puVar2 + 1;
        local_18 = local_18 + -1;
        puVar6 = puVar7;
      } while (local_18 != 0);
    }
    puVar3 = local_8 + DAT_001dac08;
    iVar8 = (int)local_8 - (int)param_1;
    iVar5 = (int)param_2 - (int)puVar3;
    if (iVar5 < iVar8) {
      if (DAT_001dac0c <= iVar5) {
        FUN_0010bb88(puVar3,param_2);
      }
      param_2 = local_8;
      iVar5 = iVar8;
      puVar3 = param_1;
    }
    else if (DAT_001dac0c <= iVar8) {
      FUN_0010bb88(param_1,local_8);
    }
    param_1 = puVar3;
    if (iVar5 < DAT_001dac0c) {
      return;
    }
  } while( true );
}

