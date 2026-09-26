/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0010ba60 */

void _qsort(void *param_1,size_t param_2,size_t param_3,int *param_4)

{
  undefined1 uVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  int iVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  undefined1 *puVar7;
  
  if (1 < (int)param_2) {
    DAT_001dac08 = param_3;
    DAT_001dac04 = (code *)param_4;
    DAT_001dac0c = param_3 * 4;
    DAT_001dac10 = param_3 * 6;
    puVar2 = (undefined1 *)(param_2 * param_3 + (int)param_1);
    puVar3 = puVar2;
    puVar6 = param_1;
    if (3 < (int)param_2) {
      FUN_0010bb88(param_1,puVar2);
      puVar3 = (undefined1 *)((int)param_1 + DAT_001dac0c);
    }
    while (puVar5 = puVar6 + DAT_001dac08, puVar5 < puVar3) {
      (*DAT_001dac04)(puVar6,puVar5);
      puVar6 = puVar5;
    }
    if (param_1 != puVar6) {
      puVar5 = (undefined1 *)((int)param_1 + DAT_001dac08);
      for (puVar3 = param_1; puVar3 < puVar5; puVar3 = puVar3 + 1) {
        uVar1 = *puVar6;
        *puVar6 = *puVar3;
        puVar6 = puVar6 + 1;
        *puVar3 = uVar1;
      }
    }
    while (param_1 = (void *)((int)param_1 + DAT_001dac08), puVar6 = param_1, param_1 < puVar2) {
      do {
        puVar6 = puVar6 + -DAT_001dac08;
        iVar4 = (*DAT_001dac04)(puVar6,param_1);
      } while (0 < iVar4);
      puVar6 = puVar6 + DAT_001dac08;
      if (puVar6 != param_1) {
        for (puVar3 = (undefined1 *)((int)param_1 + (DAT_001dac08 - 1)); param_1 <= puVar3;
            puVar3 = puVar3 + -1) {
          uVar1 = *puVar3;
          puVar5 = puVar3;
          while (puVar7 = puVar5 + -DAT_001dac08, puVar6 <= puVar7) {
            *puVar5 = *puVar7;
            puVar5 = puVar7;
          }
          *puVar5 = uVar1;
        }
      }
    }
  }
  return;
}

