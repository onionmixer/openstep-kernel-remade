/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0011a208 */

/* WARNING: Removing unreachable block (ram,0x0011a266) */

void _bawrite(uint *param_1)

{
  uint uVar1;
  
  uVar1 = *param_1;
  *param_1 = uVar1 & 0xfffffdf8 | 0x100;
  uVar1 = uVar1 & 0x200;
  if (uVar1 == 0) {
    *(int *)(_active_u + 0x1a0) = *(int *)(_active_u + 0x1a0) + 1;
  }
  if ((int)param_1[5] <= (int)param_1[6]) {
    (**(code **)(*(int *)(param_1[0x10] + 0x1c) + 0x54))(param_1);
    if (uVar1 != 0) {
      *(byte *)param_1 = (byte)*param_1 | 0x80;
    }
    return;
  }
                    /* WARNING: Subroutine does not return */
  _panic(s_bwrite_001db583);
}

