/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001ca2b8 */

undefined4 * FUN_001ca2b8(int *param_1,undefined4 param_2,int param_3)

{
  undefined4 *puVar1;
  int iVar2;
  int *piVar3;
  undefined4 *puVar4;
  int local_8;
  
  piVar3 = param_1;
  do {
    if (piVar3 == (int *)0x0) {
      do {
        if (param_1 == (int *)0x0) {
          return (undefined4 *)0x0;
        }
        for (puVar4 = (undefined4 *)param_1[7]; puVar4 != (undefined4 *)0x0;
            puVar4 = (undefined4 *)*puVar4) {
          iVar2 = 0;
          if (0 < (int)puVar4[1]) {
            do {
              if (puVar4[iVar2 * 3 + 2] == param_3) {
                return puVar4 + iVar2 * 3 + 2;
              }
              iVar2 = iVar2 + 1;
            } while (iVar2 < (int)puVar4[1]);
          }
        }
        param_1 = (int *)param_1[1];
      } while( true );
    }
    if (2 < *(int *)(*piVar3 + 0xc)) {
      for (puVar4 = (undefined4 *)piVar3[9]; puVar4 != (undefined4 *)0x0;
          puVar4 = (undefined4 *)*puVar4) {
        local_8 = 0;
        if (0 < (int)puVar4[1]) {
          do {
            puVar1 = (undefined4 *)
                     _objc_msgSend(puVar4[local_8 + 2],PTR_s_descriptionForInstanceMethod__001f9d10,
                                   param_3);
            if (puVar1 != (undefined4 *)0x0) {
              return puVar1;
            }
            local_8 = local_8 + 1;
          } while (local_8 < (int)puVar4[1]);
        }
        if (*(int *)(*piVar3 + 0xc) < 5) break;
      }
    }
    piVar3 = (int *)piVar3[1];
  } while( true );
}

