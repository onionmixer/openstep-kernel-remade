/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0012e528 */

void FUN_0012e528(undefined4 param_1,int *param_2,undefined4 param_3)

{
  int iVar1;
  void *pvVar2;
  int iVar3;
  int local_24 [2];
  int *local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  int local_8;
  
  iVar1 = FUN_0012dc2c(param_1,param_3);
  if (iVar1 == 0) {
    *param_2 = 0x46;
  }
  else {
    pvVar2 = (void *)_kalloc(0x400);
    param_2[2] = (int)pvVar2;
    _bzero(pvVar2,0x400);
    local_24[0] = param_2[2];
    local_24[1] = 0x400;
    local_1c = local_24;
    local_18 = 1;
    local_10 = 1;
    local_14 = 0;
    local_8 = 0x400;
    iVar3 = (**(code **)(*(int *)(iVar1 + 0x1c) + 0x44))
                      (iVar1,&local_1c,*(undefined4 *)(_active_u + 0x1c));
    if (iVar3 == 0) {
      param_2[1] = 0x400 - local_8;
    }
    else {
      _kfree(param_2[2],0x400);
      param_2[1] = 0;
      param_2[2] = 0;
    }
    *param_2 = iVar3;
    _vn_rele(iVar1);
  }
  return;
}

