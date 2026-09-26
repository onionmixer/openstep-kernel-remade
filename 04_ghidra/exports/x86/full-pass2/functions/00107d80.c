/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00107d80 */

int _setreuid(uid_t param_1,uid_t param_2)

{
  uint *puVar1;
  int iVar2;
  short sVar3;
  uint uVar4;
  short sVar5;
  
  puVar1 = *(uint **)(DAT_001e875c + 0x24);
  uVar4 = *puVar1;
  if (uVar4 == 0xffffffff) {
    uVar4 = (uint)*(ushort *)(_active_u[7] + 6);
  }
  sVar5 = (short)uVar4;
  if (((*(short *)(_active_u[7] + 6) != sVar5) && (*(short *)(_active_u[7] + 2) != sVar5)) &&
     (iVar2 = _suser(), iVar2 == 0)) {
    return 0;
  }
  uVar4 = puVar1[1];
  if (uVar4 == 0xffffffff) {
    uVar4 = (uint)*(ushort *)(_active_u[7] + 2);
  }
  sVar3 = (short)uVar4;
  if (((*(short *)(_active_u[7] + 6) != sVar3) && (*(short *)(_active_u[7] + 2) != sVar3)) &&
     (iVar2 = _suser(), iVar2 == 0)) {
    return 0;
  }
  _lock_write(_active_u + 8);
  iVar2 = _crcopy(_active_u[7]);
  _active_u[7] = iVar2;
  *(short *)(*_active_u + 0x2c) = sVar3;
  *(short *)(_active_u[7] + 6) = sVar5;
  *(short *)(_active_u[7] + 2) = sVar3;
  iVar2 = _lock_done(_active_u + 8);
  return iVar2;
}

