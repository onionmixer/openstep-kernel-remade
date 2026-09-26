/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00104568 */

int _close(int param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = DAT_001e875c;
  uVar1 = **(uint **)(DAT_001e875c + 0x24);
  if (((uVar1 < (uint)_active_u[0x57]) &&
      (iVar2 = *(int *)(_active_u[0x54] + uVar1 * 4), iVar2 != 0)) && (iVar2 != -0x10000)) {
    _vno_lockrelease(iVar2);
    iVar4 = _active_u[0x55];
    if ((*(byte *)(iVar4 + uVar1) & 2) != 0) {
      _munmapfd(uVar1);
    }
    *(undefined4 *)(_active_u[0x54] + uVar1 * 4) = 0;
    while( true ) {
      if ((_active_u[0x56] < 0) || (*(int *)(_active_u[0x54] + _active_u[0x56] * 4) != 0)) break;
      _active_u[0x56] = _active_u[0x56] + -1;
    }
    *(byte *)(iVar4 + uVar1) = 0;
    _closef(iVar2);
    iVar3 = DAT_001e875c;
    iVar4 = *_active_u;
    if ((((*(byte *)(*_active_u + 0x16) & 2) != 0) &&
        (iVar4 = iVar3, *(char *)(DAT_001e875c + 0x68) == '\x1c')) &&
       ((*(byte *)(iVar2 + 9) & 0x10) != 0)) {
      *(undefined1 *)(DAT_001e875c + 0x68) = 0;
    }
  }
  else {
    *(undefined1 *)(DAT_001e875c + 0x68) = 9;
  }
  return iVar4;
}

