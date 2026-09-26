/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001ca16c */

undefined4 FUN_001ca16c(int *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  char cVar2;
  int iVar3;
  
  do {
    if (param_1 == (int *)0x0) {
      return 0;
    }
    if (2 < *(int *)(*param_1 + 0xc)) {
      for (puVar1 = (undefined4 *)param_1[9]; puVar1 != (undefined4 *)0x0;
          puVar1 = (undefined4 *)*puVar1) {
        iVar3 = 0;
        if (0 < (int)puVar1[1]) {
          do {
            cVar2 = _objc_msgSend(puVar1[iVar3 + 2],PTR_s_conformsTo__001f9238,param_3);
            if (cVar2 != '\0') {
              return 1;
            }
            iVar3 = iVar3 + 1;
          } while (iVar3 < (int)puVar1[1]);
        }
        if (*(int *)(*param_1 + 0xc) < 5) break;
      }
    }
    param_1 = (int *)param_1[1];
  } while( true );
}

