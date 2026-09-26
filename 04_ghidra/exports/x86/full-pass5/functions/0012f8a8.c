/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0012f8a8 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int * FUN_0012f8a8(void *param_1,int param_2)

{
  short sVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  
  piVar2 = (int *)(&_rtable)
                  [(byte)(*(byte *)((int)param_1 + 10) ^ *(byte *)((int)param_1 + 0xb) ^
                          *(byte *)((int)param_1 + 0xc) ^ *(byte *)((int)param_1 + 0xd) ^
                          *(byte *)((int)param_1 + 0xe) ^ *(byte *)((int)param_1 + 0xf) ^
                          *(byte *)((int)param_1 + 0x10) ^ *(byte *)((int)param_1 + 0x11) ^
                          *(byte *)((int)param_1 + 0x14) ^ *(byte *)((int)param_1 + 0x15) ^
                          *(byte *)((int)param_1 + 0x16) ^ *(byte *)((int)param_1 + 0x17) ^
                          *(byte *)((int)param_1 + 0x18) ^ *(byte *)((int)param_1 + 0x19) ^
                          *(byte *)((int)param_1 + 0x1a) ^ *(byte *)((int)param_1 + 0x1b)) & 0x3f];
  while( true ) {
    if (piVar2 == (int *)0x0) {
      return (int *)0x0;
    }
    iVar4 = _bcmp(piVar2 + 0x10,param_1,0x20);
    if ((iVar4 == 0) && (piVar2[0xc] == param_2)) break;
    piVar2 = (int *)piVar2[2];
  }
  sVar1 = *(short *)((int)piVar2 + 0x12);
  *(short *)((int)piVar2 + 0x12) = sVar1 + 1;
  if (sVar1 == 0) {
    piVar3 = (int *)*piVar2;
    if (piVar3 != (int *)0x0) {
      if (piVar3 == piVar2) {
        _rpfreelist = (int *)0x0;
      }
      else {
        if (_rpfreelist == piVar2) {
          _rpfreelist = piVar3;
        }
        *(int *)piVar2[1] = *piVar2;
        *(int *)(*piVar2 + 4) = piVar2[1];
      }
      piVar2[1] = 0;
      *piVar2 = 0;
      __rnfree = __rnfree + -1;
    }
    piVar3 = (int *)(*(int *)(piVar2[0xc] + 0x128) + 0x18);
    *piVar3 = *piVar3 + 1;
    __rreactive = __rreactive + 1;
  }
  else {
    __ractive = __ractive + 1;
  }
  piVar3 = (int *)*piVar2;
  if (piVar3 == (int *)0x0) {
    return piVar2;
  }
  if (piVar3 == piVar2) {
    _rpfreelist = (int *)0x0;
  }
  else {
    if (_rpfreelist == piVar2) {
      _rpfreelist = piVar3;
    }
    *(int *)piVar2[1] = *piVar2;
    *(int *)(*piVar2 + 4) = piVar2[1];
  }
  piVar2[1] = 0;
  *piVar2 = 0;
  __rnfree = __rnfree + -1;
  return piVar2;
}

