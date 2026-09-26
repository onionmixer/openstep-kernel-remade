/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0011bc10 */

undefined4 _vno_select(int param_1,undefined4 param_2)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  
  iVar1 = *(int *)(param_1 + 0x18);
  uVar2 = *(uint *)(iVar1 + 0x28);
  if ((uVar2 == 4) || (((3 < uVar2 && (uVar2 < 10)) && (7 < uVar2)))) {
    uVar3 = (**(code **)(*(int *)(iVar1 + 0x1c) + 0x10))
                      (iVar1,param_2,*(undefined4 *)(param_1 + 0x20));
  }
  else {
    uVar3 = 1;
  }
  return uVar3;
}

