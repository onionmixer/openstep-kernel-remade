/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001ca1e0 */

undefined4 * FUN_001ca1e0(int *param_1,undefined4 param_2,int param_3)

{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined *puVar6;
  int local_8;
  
  piVar1 = (int *)*param_1;
  do {
    if (piVar1 == (int *)0x0) {
      iVar3 = *param_1;
      do {
        if (iVar3 == 0) {
          return (undefined4 *)0x0;
        }
        for (puVar2 = *(undefined4 **)(iVar3 + 0x1c); puVar2 != (undefined4 *)0x0;
            puVar2 = (undefined4 *)*puVar2) {
          iVar5 = 0;
          if (0 < (int)puVar2[1]) {
            do {
              if (puVar2[iVar5 * 3 + 2] == param_3) {
                return puVar2 + iVar5 * 3 + 2;
              }
              iVar5 = iVar5 + 1;
            } while (iVar5 < (int)puVar2[1]);
          }
        }
        iVar3 = *(int *)(iVar3 + 4);
      } while( true );
    }
    if (2 < *(int *)(*piVar1 + 0xc)) {
      for (puVar2 = (undefined4 *)piVar1[9]; puVar2 != (undefined4 *)0x0;
          puVar2 = (undefined4 *)*puVar2) {
        for (local_8 = 0; local_8 < (int)puVar2[1]; local_8 = local_8 + 1) {
          puVar6 = PTR_s_descriptionForInstanceMethod__001f9d10;
          if ((*(byte *)(piVar1 + 4) & 2) != 0) {
            puVar6 = PTR_s_descriptionForClassMethod__001f9d14;
          }
          puVar4 = (undefined4 *)_objc_msgSend(puVar2[local_8 + 2],puVar6,param_3);
          if (puVar4 != (undefined4 *)0x0) {
            return puVar4;
          }
        }
        if (*(int *)(*piVar1 + 0xc) < 5) break;
      }
    }
    piVar1 = (int *)piVar1[1];
  } while( true );
}

