/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00129b20 */

void _tcp_pulloutofband(int param_1,int param_2,int *param_3)

{
  byte *pbVar1;
  int iVar2;
  undefined1 *puVar3;
  int iVar4;
  
  iVar4 = *(ushort *)(param_2 + 0x26) - 1;
  do {
    if (iVar4 < 0) break;
    if (iVar4 < (short)param_3[2]) {
      puVar3 = (undefined1 *)((int)param_3 + iVar4 + param_3[1]);
      iVar2 = *(int *)(*(int *)(param_1 + 8) + 0x20);
      *(undefined1 *)(iVar2 + 0x69) = *puVar3;
      pbVar1 = (byte *)(iVar2 + 0x68);
      *pbVar1 = *pbVar1 | 1;
      _bcopy(puVar3 + 1,puVar3,((short)param_3[2] - iVar4) - 1);
      *(short *)(param_3 + 2) = (short)param_3[2] + -1;
      return;
    }
    iVar4 = iVar4 - (short)param_3[2];
    param_3 = (int *)*param_3;
  } while (param_3 != (int *)0x0);
                    /* WARNING: Subroutine does not return */
  _panic(s_tcp_pulloutofband_001dbe48);
}

