/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001c9808 */

int FUN_001c9808(int param_1,undefined4 param_2,uint param_3)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  if (param_3 < *(uint *)(param_1 + 8)) {
    param_1 = 0;
  }
  else {
    puVar1 = (undefined4 *)_objc_msgSend(param_1,PTR_s_zone_001f9d4c);
    uVar2 = _objc_msgSend(param_1,PTR_s_zone_001f9d4c,*(undefined4 *)(param_1 + 4),param_3 * 4);
    uVar2 = (*(code *)*puVar1)(uVar2);
    *(undefined4 *)(param_1 + 4) = uVar2;
    *(uint *)(param_1 + 0xc) = param_3;
  }
  return param_1;
}

