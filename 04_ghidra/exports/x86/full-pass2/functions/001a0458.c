/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001a0458 */

void FUN_001a0458(int param_1,undefined4 param_2,uint *param_3)

{
  undefined4 uVar1;
  uint uVar2;
  byte bVar3;
  uint uVar4;
  byte bVar5;
  bool bVar6;
  int local_c;
  int local_8;
  
  _objc_msgSend(*(undefined4 *)(param_1 + 0x124),PTR_s_lock_001f9220);
  bVar5 = 0;
  bVar6 = (param_3[2] & 1) != 0;
  if (bVar6) {
    bVar5 = 4;
  }
  if ((param_3[2] & 2) != 0) {
    bVar5 = bVar5 | 1;
  }
  if (*(char *)(param_1 + 0x19c) == '\0') {
    local_8 = (int)*(char *)((int)param_3 + 9);
    local_c = -(int)*(char *)((int)param_3 + 10);
  }
  else {
    local_8 = -(int)*(char *)((int)param_3 + 9);
    local_c = (int)*(char *)((int)param_3 + 10);
  }
  uVar2 = (param_3[1] - *(int *)(param_1 + 0x130)) - (uint)(*param_3 < *(uint *)(param_1 + 300));
  uVar4 = *param_3 - *(uint *)(param_1 + 300) >> 0x10 | uVar2 * 0x10000;
  if ((uVar2 >> 0x10 != 0) || (0xffff < uVar4)) {
    uVar4 = 0xffff;
  }
  *(uint *)(param_1 + 300) = *param_3;
  *(uint *)(param_1 + 0x130) = param_3[1];
  _objc_msgSend(param_1,PTR_s_scalePointerInX_andY_over_atRes__001f9548,&local_8,&local_c,uVar4,
                *(undefined4 *)(param_1 + 0x134));
  bVar3 = bVar5;
  if (*(int *)(param_1 + 0x144) == 0) {
    if (bVar5 != 0) {
      bVar3 = 4;
    }
  }
  else if ((*(int *)(param_1 + 0x144) == 1) && (bVar3 = bVar6, (bVar5 & 1) != 0)) {
    bVar3 = bVar6 | 4;
  }
  _objc_msgSend(*(undefined4 *)(param_1 + 0x124),PTR_s_unlock_001f9474);
  uVar1 = _objc_msgSend(param_1,PTR_s_owner_001f94f8,PTR_s_relativePointerEvent_deltaX_delt_001f954c
                        ,bVar3,local_8,local_c,*param_3,param_3[1]);
  _objc_msgSend(uVar1);
  return;
}

