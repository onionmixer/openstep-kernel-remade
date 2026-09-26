/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00196878 */

undefined4 FUN_00196878(int param_1,undefined4 param_2,uint *param_3)

{
  ushort uVar1;
  ushort uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  uint local_10;
  undefined4 local_c;
  uint local_8;
  
  local_8 = param_3[2];
  if (*(int *)(param_1 + 0x114) == 3) {
    uVar3 = 0x10;
  }
  else {
    local_10 = *param_3 & 0xfffffffc;
    local_c._0_2_ = (short)param_3[1];
    uVar2 = (short)local_c + 3;
    local_c._2_2_ = (ushort)(param_3[1] >> 0x10);
    uVar1 = local_c._2_2_;
    local_c = CONCAT22(local_c._2_2_,uVar2) & 0xfffffffc;
    iVar5 = (uint)(uVar2 >> 2) * (uint)uVar1;
    local_8 = _kalloc(iVar5);
    iVar4 = _copyin(param_3[2],local_8,iVar5);
    if (iVar4 == 0) {
      uVar3 = (**(code **)(*(int *)(param_1 + 0x10c) + 0xc))(*(int *)(param_1 + 0x10c),&local_10);
    }
    else {
      uVar3 = 0xffffffff;
    }
    _kfree(local_8,iVar5);
  }
  return uVar3;
}

