/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0012cba0 */

void _nfs_getfh(void)

{
  uint *puVar1;
  uint uVar2;
  bool bVar3;
  undefined1 uVar4;
  int iVar5;
  undefined4 local_30;
  int local_2c;
  int local_28;
  undefined1 local_24 [32];
  
  puVar1 = *(uint **)(DAT_001e875c + 0x24);
  bVar3 = false;
  iVar5 = _suser();
  if (iVar5 == 0) {
    *(undefined1 *)(DAT_001e875c + 0x68) = 1;
    return;
  }
  uVar2 = *puVar1;
  if (uVar2 < 0x100) {
    bVar3 = true;
    iVar5 = _getf(uVar2);
    if ((iVar5 == 0) || (*(undefined ***)(iVar5 + 0x14) != &_vnodefops)) {
      *(undefined1 *)(DAT_001e875c + 0x68) = 0x16;
      return;
    }
    local_2c = *(int *)(iVar5 + 0x18);
    local_28 = 0;
  }
  else {
    uVar4 = _lookupname(uVar2,0,1,&local_28,&local_2c);
    *(undefined1 *)(DAT_001e875c + 0x68) = uVar4;
    if (*(char *)(DAT_001e875c + 0x68) == '\x11') {
      uVar4 = _lookupname(*puVar1,0,1,0,&local_2c);
      *(undefined1 *)(DAT_001e875c + 0x68) = uVar4;
      local_28 = 0;
    }
    if (*(char *)(DAT_001e875c + 0x68) != '\0') {
      return;
    }
    if (local_2c == 0) {
      if (local_28 != 0) {
        _vn_rele(local_28);
      }
      *(undefined1 *)(DAT_001e875c + 0x68) = 2;
    }
    if (*(char *)(DAT_001e875c + 0x68) != '\0') {
      return;
    }
  }
  iVar5 = _findexivp(&local_30,local_28,local_2c);
  if (iVar5 == 0) {
    iVar5 = _makefh(local_24,local_2c,local_30);
    if (iVar5 == 0) {
      iVar5 = _copyout(local_24,puVar1[1],0x20);
    }
  }
  if ((!bVar3) && (_vn_rele(local_2c), local_28 != 0)) {
    _vn_rele(local_28);
  }
  *(char *)(DAT_001e875c + 0x68) = (char)iVar5;
  return;
}

