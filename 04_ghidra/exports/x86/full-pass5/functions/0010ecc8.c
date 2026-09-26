/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0010ecc8 */

undefined4 _ttselect(int param_1,int param_2)

{
  int *piVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  
  piVar2 = (int *)_ttynty(param_1);
  uVar3 = _spltty();
  if (param_2 == 1) {
    piVar1 = (int *)*piVar2;
    if ((*(byte *)((int)piVar1 + 0x3f) & 0x20) != 0) {
      _ttypend(piVar1);
    }
    iVar4 = piVar1[3];
    if (((*(byte *)(piVar1 + 0xf) & 0x22) != 0) &&
       (iVar4 = iVar4 + *piVar1, iVar4 < (int)(uint)*(byte *)((int)piVar2 + 0x15))) {
      iVar4 = 0;
    }
    if ((0 < iVar4) || ((-1 < (short)piVar2[4] && ((*(byte *)(param_1 + 0x40) & 0x10) == 0)))) {
LAB_0010ed80:
      _splx(uVar3);
      return 1;
    }
    iVar4 = _selthreadcache(param_1 + 0x28);
    if (iVar4 != 0) {
      *(uint *)(param_1 + 0x40) = *(uint *)(param_1 + 0x40) | 0x800;
    }
  }
  else if (param_2 == 2) {
    if (*(int *)(param_1 + 0x18) <=
        (int)*(short *)(&_ttlowat + (*(byte *)(param_1 + 0x4a) & 0x1f) * 2)) goto LAB_0010ed80;
    iVar4 = _selthreadcache(param_1 + 0x2c);
    if (iVar4 != 0) {
      *(uint *)(param_1 + 0x40) = *(uint *)(param_1 + 0x40) | 0x1000;
    }
  }
  _splx(uVar3);
  return 0;
}

