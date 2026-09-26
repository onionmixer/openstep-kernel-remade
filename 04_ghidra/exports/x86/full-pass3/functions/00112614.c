/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00112614 */

undefined4 _ptcselect(byte param_1,int param_2)

{
  int *piVar1;
  uint *puVar2;
  undefined4 uVar3;
  int iVar4;
  
  piVar1 = *(int **)(&DAT_001e56d0 + (uint)param_1 * 0x10);
  puVar2 = *(uint **)(&DAT_001e56d4 + (uint)param_1 * 0x10);
  if ((piVar1[0x10] & 0x10U) == 0) {
    return 1;
  }
  if (param_2 == 1) {
    uVar3 = _spltty();
    if ((((piVar1[0x10] & 4U) != 0) && (piVar1[6] != 0)) && ((piVar1[0x10] & 0x100U) == 0)) {
      _splx(uVar3);
      return 1;
    }
    _splx(uVar3);
  }
  else {
    if (1 < param_2) {
      if (param_2 != 2) {
        return 0;
      }
      if ((piVar1[0x10] & 4U) != 0) {
        if ((*puVar2 & 0x20) == 0) {
          if (*piVar1 + piVar1[3] < 0x3fe) {
            return 1;
          }
          if ((piVar1[3] == 0) && ((*(byte *)(piVar1 + 0xf) & 0x22) == 0)) {
            return 1;
          }
        }
        else if (piVar1[3] == 0) {
          return 1;
        }
      }
      iVar4 = _selthreadcache(puVar2 + 2);
      if (iVar4 == 0) {
        return 0;
      }
      *(byte *)puVar2 = (byte)*puVar2 | 2;
      return 0;
    }
    if (param_2 != 0) {
      return 0;
    }
  }
  if (((*(byte *)(piVar1 + 0x10) & 4) != 0) &&
     ((((*puVar2 & 8) != 0 && ((byte)puVar2[3] != 0)) ||
      (((char)*puVar2 < '\0' && (*(byte *)((int)puVar2 + 0xd) != 0)))))) {
    return 1;
  }
  iVar4 = _selthreadcache(puVar2 + 1);
  if (iVar4 != 0) {
    *(byte *)puVar2 = (byte)*puVar2 | 1;
  }
  return 0;
}

