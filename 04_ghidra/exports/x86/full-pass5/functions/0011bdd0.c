/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0011bdd0 */

undefined4 _vno_lockrelease(int param_1)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  bool bVar5;
  undefined4 uVar6;
  int iVar7;
  undefined2 local_18;
  undefined2 local_16;
  undefined4 local_14;
  undefined4 local_10;
  
  uVar2 = *(uint *)(*_active_u + 0x28);
  if ((uVar2 & 0x20000000) != 0) {
    bVar5 = false;
    *(uint *)(*_active_u + 0x28) = uVar2 & 0xdfffffff;
    iVar3 = *(int *)(param_1 + 0x18);
    for (iVar7 = _active_u[0x56]; -1 < iVar7; iVar7 = iVar7 + -1) {
      iVar4 = *(int *)(_active_u[0x54] + iVar7 * 4);
      if (iVar4 != 0) {
        bVar1 = *(byte *)(iVar7 + _active_u[0x55]);
        if ((bVar1 & 4) != 0) {
          if (*(int *)(iVar4 + 0x18) == iVar3) {
            bVar5 = true;
            *(byte *)(iVar7 + _active_u[0x55]) = bVar1 & 0xfb;
          }
          else {
            *(uint *)(*_active_u + 0x28) = *(uint *)(*_active_u + 0x28) | 0x20000000;
          }
        }
      }
    }
    if (bVar5) {
      local_18 = 3;
      local_16 = 0;
      local_14 = 0;
      local_10 = 0;
      uVar6 = (**(code **)(*(int *)(iVar3 + 0x1c) + 0x60))
                        (iVar3,&local_18,8,_active_u[7],(int)*(short *)(*_active_u + 0x30));
      return uVar6;
    }
  }
  return 0;
}

