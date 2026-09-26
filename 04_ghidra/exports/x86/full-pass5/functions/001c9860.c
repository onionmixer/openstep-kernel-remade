/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001c9860 */

int FUN_001c9860(int param_1,undefined4 param_2,int param_3,uint param_4)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  
  if ((param_3 == 0) || (*(uint *)(param_1 + 8) < param_4)) {
    param_1 = 0;
  }
  else {
    if (*(uint *)(param_1 + 0xc) < *(int *)(param_1 + 8) + 1U) {
      *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + *(int *)(param_1 + 0xc) + 1;
      puVar1 = (undefined4 *)_objc_msgSend(param_1,PTR_s_zone_001f9d4c);
      uVar2 = _objc_msgSend(param_1,PTR_s_zone_001f9d4c,*(undefined4 *)(param_1 + 4),
                            *(int *)(param_1 + 0xc) * 4);
      uVar2 = (*(code *)*puVar1)(uVar2);
      *(undefined4 *)(param_1 + 4) = uVar2;
    }
    piVar3 = (int *)(param_4 * 4 + *(int *)(param_1 + 4));
    piVar5 = (int *)(*(int *)(param_1 + 8) * 4 + *(int *)(param_1 + 4));
    piVar4 = piVar5;
    for (; piVar3 < piVar5; piVar5 = piVar5 + -1) {
      piVar4 = piVar4 + -1;
      *piVar5 = *piVar4;
    }
    *piVar3 = param_3;
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
  }
  return param_1;
}

