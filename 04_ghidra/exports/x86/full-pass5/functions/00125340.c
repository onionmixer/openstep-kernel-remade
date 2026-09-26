/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00125340 */

void _in_pcbnotify(undefined4 *param_1,short *param_2,short param_3,int param_4,short param_5,
                  uint param_6,code *param_7)

{
  byte bVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  if (((param_6 < 0x16) && (*param_2 == 2)) && (iVar2 = *(int *)(param_2 + 2), iVar2 != 0)) {
    if (((param_6 - 0xe < 4) || (param_6 == 6)) || (param_6 == 1)) {
      param_3 = 0;
      param_5 = 0;
      param_4 = 0;
      if (param_6 != 6) {
        param_7 = _in_rtchange;
      }
    }
    bVar1 = (&_inetctlerrmap)[param_6];
    puVar3 = (undefined4 *)*param_1;
    while (puVar4 = puVar3, puVar4 != param_1) {
      if ((((puVar4[3] == iVar2) && (puVar4[7] != 0)) &&
          (((param_5 == 0 || (*(short *)(puVar4 + 6) == param_5)) &&
           ((param_4 == 0 || (puVar4[5] == param_4)))))) &&
         ((param_3 == 0 || (*(short *)(puVar4 + 4) == param_3)))) {
        if (bVar1 != 0) {
          *(ushort *)(puVar4[7] + 0x56) = (ushort)bVar1;
        }
        puVar3 = (undefined4 *)*puVar4;
        if (param_7 != (code *)0x0) {
          (*param_7)(puVar4);
        }
      }
      else {
        puVar3 = (undefined4 *)*puVar4;
      }
    }
  }
  return;
}

