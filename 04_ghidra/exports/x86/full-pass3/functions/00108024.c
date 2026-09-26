/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00108024 */

int _setregid(gid_t param_1,gid_t param_2)

{
  short sVar1;
  uint *puVar2;
  int iVar3;
  undefined4 uVar4;
  short sVar5;
  uint uVar6;
  short sVar7;
  
  puVar2 = *(uint **)(DAT_001e875c + 0x24);
  uVar6 = *puVar2;
  if (uVar6 == 0xffffffff) {
    uVar6 = (uint)*(ushort *)(*(int *)(_active_u + 0x1c) + 8);
  }
  sVar5 = (short)uVar6;
  if (((*(short *)(*(int *)(_active_u + 0x1c) + 8) != sVar5) &&
      (*(short *)(*(int *)(_active_u + 0x1c) + 4) != sVar5)) && (iVar3 = _suser(), iVar3 == 0)) {
    return 0;
  }
  uVar6 = puVar2[1];
  if (uVar6 == 0xffffffff) {
    uVar6 = (uint)*(ushort *)(*(int *)(_active_u + 0x1c) + 4);
  }
  sVar7 = (short)uVar6;
  if (((*(short *)(*(int *)(_active_u + 0x1c) + 8) != sVar7) &&
      (*(short *)(*(int *)(_active_u + 0x1c) + 4) != sVar7)) && (iVar3 = _suser(), iVar3 == 0)) {
    return 0;
  }
  _lock_write(_active_u + 0x20);
  uVar4 = _crcopy(*(undefined4 *)(_active_u + 0x1c));
  *(undefined4 *)(_active_u + 0x1c) = uVar4;
  sVar1 = *(short *)(*(int *)(_active_u + 0x1c) + 8);
  if (sVar1 != sVar5) {
    _leavegroup((int)sVar1);
    _entergroup((int)sVar5);
    *(short *)(*(int *)(_active_u + 0x1c) + 8) = sVar5;
  }
  *(short *)(*(int *)(_active_u + 0x1c) + 4) = sVar7;
  iVar3 = _lock_done(_active_u + 0x20);
  return iVar3;
}

