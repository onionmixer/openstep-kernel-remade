/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00118964 */

void _unp_drop(int *param_1,undefined2 param_2)

{
  short sVar1;
  int iVar2;
  undefined4 *puVar3;
  int *piVar4;
  int *piVar5;
  
  iVar2 = *param_1;
  *(undefined2 *)(iVar2 + 0x56) = param_2;
  puVar3 = (undefined4 *)param_1[3];
  if (puVar3 != (undefined4 *)0x0) {
    param_1[3] = 0;
    sVar1 = *(short *)*param_1;
    if (sVar1 == 1) {
      _soisdisconnected((short *)*param_1);
      puVar3[3] = 0;
      _soisdisconnected(*puVar3);
    }
    else if (sVar1 == 2) {
      piVar4 = (int *)puVar3[4];
      if ((int *)puVar3[4] == param_1) {
        puVar3[4] = param_1[5];
      }
      else {
        do {
          piVar5 = piVar4;
          if (piVar5 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
            _panic(s_unp_disconnect_001db411);
          }
          piVar4 = (int *)piVar5[5];
        } while ((int *)piVar5[5] != param_1);
        piVar5[5] = param_1[5];
      }
      param_1[5] = 0;
      *(byte *)(*param_1 + 6) = *(byte *)(*param_1 + 6) & 0xfd;
    }
  }
  if (*(int *)(iVar2 + 0x10) != 0) {
    *(undefined4 *)(iVar2 + 8) = 0;
    _m_freem(param_1[6]);
    _kfree(param_1,0x24);
    _sofree(iVar2);
  }
  return;
}

