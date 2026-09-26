/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001c8b88 */

int FUN_001c8b88(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                undefined4 param_5)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_001c8900(param_5);
  uVar2 = FUN_001c8920(iVar1 + 1);
  _objc_msgSend(param_1,PTR_s__initBare___001f9d54,param_3,param_4,uVar2);
  uVar2 = _objc_msgSend(param_1,PTR_s_zone_001f9d4c,*(undefined4 *)(param_1 + 0x10),8);
  uVar2 = _NXZoneCalloc(uVar2);
  *(undefined4 *)(param_1 + 0x14) = uVar2;
  return param_1;
}

