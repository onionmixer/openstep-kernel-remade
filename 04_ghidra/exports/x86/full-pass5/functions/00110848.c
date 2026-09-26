/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00110848 */

undefined4 _ttycheckoutq(int param_1,int param_2)

{
  short sVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  sVar1 = *(short *)(&_tthiwat + (*(byte *)(param_1 + 0x4a) & 0x1f) * 2);
  uVar3 = _spltty();
  iVar2 = *(int *)(param_1 + 0x18);
  if (sVar1 + 200 < iVar2) {
    while (sVar1 < iVar2) {
      uVar4 = _spltty();
      if (((*(uint *)(param_1 + 0x40) & 0x4000121) == 0) &&
         (*(code **)(param_1 + 0x24) != (code *)0x0)) {
        (**(code **)(param_1 + 0x24))(param_1);
      }
      _splx(uVar4);
      if (param_2 == 0) {
        _splx(uVar3);
        return 0;
      }
      *(byte *)(param_1 + 0x40) = *(byte *)(param_1 + 0x40) | 0x40;
      _sleep(param_1 + 0x18);
      iVar2 = *(int *)(param_1 + 0x18);
    }
  }
  _splx(uVar3);
  return 1;
}

