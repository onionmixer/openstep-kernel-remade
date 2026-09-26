/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001c9560 */

int FUN_001c9560(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  *(int *)(param_1 + 0xc) = param_3;
  if (param_3 != 0) {
    iVar1 = _objc_msgSend(param_1,PTR_s_zone_001f9d4c);
    uVar2 = _objc_msgSend(param_1,PTR_s_zone_001f9d4c,*(int *)(param_1 + 0xc) * 4);
    uVar2 = (**(code **)(iVar1 + 4))(uVar2);
    *(undefined4 *)(param_1 + 4) = uVar2;
  }
  return param_1;
}

