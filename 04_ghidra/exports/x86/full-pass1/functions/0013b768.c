/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0013b768 */

int _alloc(int param_1,int param_2,uint param_3)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = *(int *)(param_1 + 0x50);
  if ((*(uint *)(iVar4 + 0x30) < param_3) || ((param_3 & ~*(uint *)(iVar4 + 0x4c)) != 0)) {
    _printf(s_dev___0x_x__bsize____d__size_____001dd964,(int)*(short *)(param_1 + 0x46),
            *(uint *)(iVar4 + 0x30),param_3,iVar4 + 0xd4);
                    /* WARNING: Subroutine does not return */
    _panic(s_alloc__bad_size_001dd990);
  }
  if (((*(uint *)(iVar4 + 0x30) != param_3) || (*(int *)(iVar4 + 0xc4) != 0)) &&
     ((*(short *)(*(int *)(_active_u + 0x1c) + 2) == 0 ||
      (0 < ((*(int *)(iVar4 + 0xc4) << ((byte)*(undefined4 *)(iVar4 + 0x60) & 0x1f)) +
           *(int *)(iVar4 + 0xcc)) - (*(int *)(iVar4 + 0x28) * *(int *)(iVar4 + 0x3c)) / 100)))) {
    if (*(int *)(iVar4 + 0x24) <= param_2) {
      param_2 = 0;
    }
    if (param_2 == 0) {
      uVar1 = *(uint *)(param_1 + 0x48) / *(uint *)(iVar4 + 0xb8);
    }
    else {
      uVar1 = param_2 / *(int *)(iVar4 + 0xbc);
    }
    iVar2 = _hashalloc(param_1,uVar1,param_2,param_3,_alloccg);
    if (0 < iVar2) {
      iVar3 = (**(code **)(*(int *)(param_1 + 0x28) + 0x80))(param_1 + 0xc);
      *(int *)(param_1 + 0xcc) = *(int *)(param_1 + 0xcc) + (int)param_3 / iVar3;
      *(byte *)(param_1 + 0x44) = *(byte *)(param_1 + 0x44) | 0x42;
      iVar4 = _getblk(*(undefined4 *)(param_1 + 0x40),
                      iVar2 << ((byte)*(undefined4 *)(iVar4 + 100) & 0x1f),param_3);
      _blkclr(*(undefined4 *)(iVar4 + 0x20),*(undefined4 *)(iVar4 + 0x14));
      *(undefined4 *)(iVar4 + 0x28) = 0;
      return iVar4;
    }
  }
  _fsfull(iVar4,1);
  return 0;
}

