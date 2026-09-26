/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001438cc */

int FUN_001438cc(int param_1,int *param_2)

{
  ushort uVar1;
  int iVar2;
  
  iVar2 = _iget((int)*(short *)(*(int *)(param_1 + 0x128) + 4),
                *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x128) + 0xc) + 0x20),2);
  if (iVar2 == 0) {
    iVar2 = (int)*(char *)(DAT_001e875c + 0x68);
  }
  else {
    uVar1 = *(ushort *)(iVar2 + 0x44);
    *(ushort *)(iVar2 + 0x44) = uVar1 & 0xfffe;
    if ((uVar1 & 0x10) != 0) {
      *(ushort *)(iVar2 + 0x44) = uVar1 & 0xffee;
      _wakeup(iVar2);
    }
    *param_2 = iVar2 + 0xc;
    iVar2 = 0;
  }
  return iVar2;
}

