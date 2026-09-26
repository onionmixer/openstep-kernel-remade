/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00118cac */

void _unp_scan(undefined4 *param_1,code *param_2)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  
  do {
    puVar4 = param_1;
    if (param_1 == (undefined4 *)0x0) {
      return;
    }
    for (; puVar4 != (undefined4 *)0x0; puVar4 = (undefined4 *)*puVar4) {
      if ((*(short *)((int)puVar4 + 10) == 0xc) && (*(short *)(puVar4 + 2) != 0)) {
        uVar2 = (uint)(int)*(short *)(puVar4 + 2) >> 2;
        puVar4 = (undefined4 *)((int)puVar4 + puVar4[1]);
        iVar3 = 0;
        if (uVar2 != 0) {
          do {
            uVar1 = *puVar4;
            puVar4 = puVar4 + 1;
            (*param_2)(uVar1);
            iVar3 = iVar3 + 1;
          } while (iVar3 < (int)uVar2);
        }
        break;
      }
    }
    param_1 = (undefined4 *)param_1[0x1f];
  } while( true );
}

