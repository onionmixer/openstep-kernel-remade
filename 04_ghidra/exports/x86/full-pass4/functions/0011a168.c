/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0011a168 */

void _bwrite(uint *param_1)

{
  uint uVar1;
  
  uVar1 = *param_1;
  *param_1 = uVar1 & 0xfffffdf8;
  if ((uVar1 & 0x200) == 0) {
    *(int *)(_active_u + 0x1a0) = *(int *)(_active_u + 0x1a0) + 1;
  }
  if ((int)param_1[6] < (int)param_1[5]) {
                    /* WARNING: Subroutine does not return */
    _panic(s_bwrite_001db583);
  }
  (**(code **)(*(int *)(param_1[0x10] + 0x1c) + 0x54))(param_1);
  if ((uVar1 & 0x100) == 0) {
    _biowait(param_1);
    _brelse(param_1);
  }
  else if ((uVar1 & 0x200) != 0) {
    *(byte *)param_1 = (byte)*param_1 | 0x80;
  }
  return;
}

