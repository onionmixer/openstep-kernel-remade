/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001701cc */

void FUN_001701cc(int *param_1,int param_2)

{
  int iVar1;
  
  if ((param_1[1] == 0x18) && (-1 < *param_1)) {
    iVar1 = _xxx_host_info(param_1[2],param_2 + 0x24);
    *(int *)(param_2 + 0x1c) = iVar1;
    if (iVar1 == 0) {
      *(undefined4 *)(param_2 + 4) = 0x38;
      *(undefined4 *)(param_2 + 0x20) = DAT_001e0438;
    }
  }
  else {
    *(undefined4 *)(param_2 + 0x1c) = 0xfffffed0;
  }
  return;
}

