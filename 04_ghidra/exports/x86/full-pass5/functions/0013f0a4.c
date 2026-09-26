/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0013f0a4 */

int FUN_0013f0a4(int param_1,int param_2)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
  iVar3 = *(int *)(param_1 + 0x50);
  iVar2 = _bmap(param_1,0,0,0x400,0);
  if ((iVar2 < 1) || (*(char *)(DAT_001e875c + 0x68) != '\0')) {
    iVar3 = 0x1c;
    if (*(char *)(DAT_001e875c + 0x68) != '\0') {
      iVar3 = (int)*(char *)(DAT_001e875c + 0x68);
    }
  }
  else {
    if (*(int *)(iVar3 + 0x34) < 0x400) {
                    /* WARNING: Subroutine does not return */
      _panic(s_DIRBLKSIZ_>_fsize_001ddec8);
    }
    *(undefined4 *)(param_1 + 0x6c) = 0x400;
    *(byte *)(param_1 + 0x44) = *(byte *)(param_1 + 0x44) | 0x42;
    *(short *)(param_2 + 0x66) = *(short *)(param_2 + 0x66) + 1;
    *(byte *)(param_2 + 0x44) = *(byte *)(param_2 + 0x44) | 0x40;
    _iupdat(param_2,1);
    iVar3 = _bread(*(undefined4 *)(param_1 + 0x40),
                   iVar2 << ((byte)*(undefined4 *)(iVar3 + 100) & 0x1f),
                   *(undefined4 *)(iVar3 + 0x34));
    if (*(char *)(DAT_001e875c + 0x68) == '\0') {
      puVar1 = *(undefined4 **)(iVar3 + 0x20);
      puVar4 = &_mastertemplate;
      puVar5 = puVar1;
      for (iVar2 = 6; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar5 = *puVar4;
        puVar4 = puVar4 + 1;
        puVar5 = puVar5 + 1;
      }
      *puVar1 = *(undefined4 *)(param_1 + 0x48);
      puVar1[3] = *(undefined4 *)(param_2 + 0x48);
      _byte_swap_dir_block_out(iVar3);
      _bwrite(iVar3);
      iVar3 = (int)*(char *)(DAT_001e875c + 0x68);
    }
    else {
      iVar3 = (int)*(char *)(DAT_001e875c + 0x68);
    }
  }
  return iVar3;
}

