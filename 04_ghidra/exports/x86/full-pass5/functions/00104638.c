/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00104638 */

int _fstat(int param_1,stat *param_2)

{
  uint *puVar1;
  uint uVar2;
  int iVar3;
  undefined1 uVar4;
  int iVar5;
  undefined1 local_44 [64];
  
  iVar5 = DAT_001e875c;
  puVar1 = *(uint **)(DAT_001e875c + 0x24);
  uVar2 = *puVar1;
  if (((uVar2 < *(uint *)(_active_u + 0x15c)) &&
      (iVar3 = *(int *)(*(int *)(_active_u + 0x150) + uVar2 * 4), iVar3 != 0)) &&
     (iVar3 != -0x10000)) {
    if (*(short *)(iVar3 + 0xc) == 1) {
      uVar4 = _vno_stat(*(undefined4 *)(iVar3 + 0x18),local_44);
    }
    else {
      if (*(short *)(iVar3 + 0xc) != 2) {
                    /* WARNING: Subroutine does not return */
        _panic(s_fstat_001da650);
      }
      uVar4 = _soo_stat(*(undefined4 *)(iVar3 + 0x18),local_44);
    }
    *(undefined1 *)(DAT_001e875c + 0x68) = uVar4;
    iVar5 = DAT_001e875c;
    if (*(char *)(DAT_001e875c + 0x68) == '\0') {
      uVar4 = _copyout(local_44,puVar1[1],0x40);
      iVar5 = DAT_001e875c;
      *(undefined1 *)(DAT_001e875c + 0x68) = uVar4;
    }
  }
  else {
    *(undefined1 *)(DAT_001e875c + 0x68) = 9;
  }
  return iVar5;
}

