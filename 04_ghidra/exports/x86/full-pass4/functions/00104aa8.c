/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00104aa8 */

int _flock(int param_1,int param_2)

{
  uint *puVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined1 uVar5;
  int iVar6;
  
  iVar6 = DAT_001e875c;
  puVar1 = *(uint **)(DAT_001e875c + 0x24);
  if (*puVar1 < *(uint *)(_active_u + 0x15c)) {
    iVar2 = *(int *)(_active_u + 0x150);
    iVar3 = *(int *)(iVar2 + *puVar1 * 4);
    if ((iVar3 != 0) && (iVar3 != -0x10000)) {
      if (*(short *)(iVar3 + 0xc) != 1) {
        *(undefined1 *)(DAT_001e875c + 0x68) = 0x2d;
        return iVar2;
      }
      uVar4 = puVar1[1];
      if ((uVar4 & 8) != 0) {
        iVar6 = _vno_bsd_unlock(iVar3,0x180);
        return iVar6;
      }
      if ((uVar4 & 2) == 0) {
        if ((uVar4 & 1) == 0) {
          *(undefined1 *)(DAT_001e875c + 0x68) = 0x16;
          return uVar4;
        }
      }
      else {
        puVar1[1] = uVar4 & 0xfffffffe;
      }
      uVar5 = _vno_bsd_lock(iVar3,puVar1[1]);
      iVar6 = DAT_001e875c;
      *(undefined1 *)(DAT_001e875c + 0x68) = uVar5;
      return iVar6;
    }
  }
  *(undefined1 *)(DAT_001e875c + 0x68) = 9;
  return iVar6;
}

