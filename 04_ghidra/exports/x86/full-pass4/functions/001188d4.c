/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001188d4 */

void _unp_disconnect(int *param_1)

{
  short sVar1;
  undefined4 *puVar2;
  int *piVar3;
  int *piVar4;
  
  puVar2 = (undefined4 *)param_1[3];
  if (puVar2 != (undefined4 *)0x0) {
    param_1[3] = 0;
    sVar1 = *(short *)*param_1;
    if (sVar1 == 1) {
      _soisdisconnected((short *)*param_1);
      puVar2[3] = 0;
      _soisdisconnected(*puVar2);
    }
    else if (sVar1 == 2) {
      piVar3 = (int *)puVar2[4];
      if ((int *)puVar2[4] == param_1) {
        puVar2[4] = param_1[5];
      }
      else {
        do {
          piVar4 = piVar3;
          if (piVar4 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
            _panic(s_unp_disconnect_001db411);
          }
          piVar3 = (int *)piVar4[5];
        } while ((int *)piVar4[5] != param_1);
        piVar4[5] = param_1[5];
      }
      param_1[5] = 0;
      *(byte *)(*param_1 + 6) = *(byte *)(*param_1 + 6) & 0xfd;
    }
  }
  return;
}

