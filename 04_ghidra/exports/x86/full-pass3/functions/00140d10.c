/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00140d10 */

void _idrop(int param_1)

{
  ushort uVar1;
  short sVar2;
  
  if ((*(byte *)(param_1 + 0x44) & 1) == 0) {
                    /* WARNING: Subroutine does not return */
    _panic(s_idrop_001de023);
  }
  uVar1 = *(ushort *)(param_1 + 0x44);
  *(ushort *)(param_1 + 0x44) = uVar1 & 0xfffe;
  if ((uVar1 & 0x10) != 0) {
    *(ushort *)(param_1 + 0x44) = uVar1 & 0xffee;
    _wakeup(param_1);
  }
  sVar2 = *(short *)(param_1 + 0x12);
  *(short *)(param_1 + 0x12) = sVar2 + -1;
  if (sVar2 == 1) {
    *(undefined2 *)(param_1 + 0x44) = 0;
    if (_ifreeh == 0) {
      _ifreeh = param_1;
      *(int **)(param_1 + 0x60) = &_ifreeh;
    }
    else {
      *_ifreet = param_1;
      *(int **)(param_1 + 0x60) = _ifreet;
    }
    *(undefined4 *)(param_1 + 0x5c) = 0;
    _ifreet = (int *)(param_1 + 0x5c);
  }
  return;
}

