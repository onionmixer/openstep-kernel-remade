/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00116970 */

void _sbcompress(short *param_1,undefined4 *param_2,undefined4 *param_3)

{
  short sVar1;
  uint uVar2;
  undefined4 *puVar3;
  
LAB_0011697f:
  do {
    while( true ) {
      puVar3 = param_2;
      if (puVar3 == (undefined4 *)0x0) {
        return;
      }
      sVar1 = *(short *)(puVar3 + 2);
      if (sVar1 != 0) break;
      param_2 = (undefined4 *)_m_free(puVar3);
    }
    if (((param_3 != (undefined4 *)0x0) && (uVar2 = param_3[1], uVar2 < 0x7d)) &&
       ((uint)puVar3[1] < 0x7d)) {
      if ((uVar2 + (int)*(short *)(param_3 + 2) + (int)sVar1 < 0x7d) &&
         (*(short *)((int)param_3 + 10) == *(short *)((int)puVar3 + 10))) {
        _bcopy((void *)(puVar3[1] + (int)puVar3),
               (void *)((int)param_3 + (int)*(short *)(param_3 + 2) + uVar2),(int)sVar1);
        *(short *)(param_3 + 2) = *(short *)(param_3 + 2) + *(short *)(puVar3 + 2);
        *param_1 = *param_1 + *(short *)(puVar3 + 2);
        param_2 = (undefined4 *)_m_free(puVar3);
        goto LAB_0011697f;
      }
    }
    *param_1 = *param_1 + *(short *)(puVar3 + 2);
    sVar1 = param_1[2];
    param_1[2] = sVar1 + 0x80;
    if (0x7c < (uint)puVar3[1]) {
      param_1[2] = sVar1 + 0x480;
    }
    if (param_3 == (undefined4 *)0x0) {
      *(undefined4 **)(param_1 + 6) = puVar3;
    }
    else {
      *param_3 = puVar3;
    }
    param_2 = (undefined4 *)*puVar3;
    *puVar3 = 0;
    param_3 = puVar3;
  } while( true );
}

