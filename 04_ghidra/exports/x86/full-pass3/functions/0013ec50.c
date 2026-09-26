/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0013ec50 */

int _diraddentry(int param_1,char *param_2,int param_3,int param_4,int param_5,undefined4 param_6)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0x30) == *(int *)(param_5 + 0x30)) {
    if (((*(ushort *)(param_5 + 100) & 0xf000) == 0x4000) &&
       (iVar1 = FUN_0013e9f8(param_5,param_6,param_1), iVar1 != 0)) {
      return iVar1;
    }
    iVar1 = FUN_0013ed2c(param_1,param_4);
    if (iVar1 == 0) {
      *(undefined2 *)(*(int *)(param_4 + 0x10) + 6) = (undefined2)param_3;
      _strncpy((char *)(*(int *)(param_4 + 0x10) + 8),param_2,param_3 + 4U & 0xfffffffc);
      **(undefined4 **)(param_4 + 0x10) = *(undefined4 *)(param_5 + 0x48);
      _dnlc_enter(param_1 + 0xc,param_2,param_5 + 0xc,0);
      _byte_swap_dir_block_out(*(undefined4 *)(param_4 + 0xc));
      _bwrite(*(undefined4 *)(param_4 + 0xc));
      *(undefined4 *)(param_4 + 0xc) = 0;
      if (*(char *)(DAT_001e875c + 0x68) == '\0') {
        *(byte *)(param_1 + 0x44) = *(byte *)(param_1 + 0x44) | 0x42;
        *(undefined4 *)(param_1 + 0x4c) = 0;
        iVar1 = 0;
      }
      else {
        iVar1 = (int)*(char *)(DAT_001e875c + 0x68);
      }
    }
  }
  else {
    iVar1 = 0x12;
  }
  return iVar1;
}

