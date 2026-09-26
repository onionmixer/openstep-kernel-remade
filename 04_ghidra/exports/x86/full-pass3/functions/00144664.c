/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00144664 */

undefined4 FUN_00144664(int param_1,short param_2,short param_3)

{
  int iVar1;
  
  if (param_2 == -1) {
    param_2 = *(short *)(param_1 + 0x68);
  }
  if (param_3 == -1) {
    param_3 = *(short *)(param_1 + 0x6a);
  }
  if ((((*(short *)(*(int *)(_active_u + 0x1c) + 2) != param_2) ||
       (*(short *)(param_1 + 0x68) != param_2)) || (iVar1 = _groupmember((int)param_3), iVar1 == 0))
     && (iVar1 = _suser(), iVar1 == 0)) {
    return 1;
  }
  *(short *)(param_1 + 0x68) = param_2;
  *(short *)(param_1 + 0x6a) = param_3;
  *(byte *)(param_1 + 0x44) = *(byte *)(param_1 + 0x44) | 0x40;
  if (*(short *)(*(int *)(_active_u + 0x1c) + 2) != 0) {
    *(ushort *)(param_1 + 100) = *(ushort *)(param_1 + 100) & 0xf3ff;
  }
  return 0;
}

