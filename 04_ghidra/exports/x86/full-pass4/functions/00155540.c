/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00155540 */

void _mach_port_gst_helper(int param_1,int *param_2,uint param_3,int param_4,uint *param_5)

{
  int iVar1;
  uint uVar2;
  
  do {
    do {
    } while (*param_2 != 0);
    LOCK();
    iVar1 = *param_2;
    *param_2 = 1;
    UNLOCK();
  } while (iVar1 == 1);
  LOCK();
  *param_2 = 0;
  UNLOCK();
  if (param_1 == param_2[0xc]) {
    uVar2 = *param_5;
    if (uVar2 < param_3) {
      *(int *)(param_4 + uVar2 * 4) = param_2[4];
    }
    *param_5 = uVar2 + 1;
  }
  return;
}

