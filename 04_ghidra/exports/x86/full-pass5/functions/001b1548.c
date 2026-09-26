/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001b1548 */

int FUN_001b1548(int param_1,undefined4 param_2,int param_3,int param_4,int param_5,
                undefined4 *param_6)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_c;
  undefined4 local_8;
  
  if ((param_3 == *(int *)(param_1 + 0x114)) && (*(char *)(param_1 + 0x1d0) != '\0')) {
    if ((param_4 == 0) ||
       (((param_5 == 0 || (*(int *)(param_1 + 0x150) != 0)) || (*(int *)(param_1 + 0x154) != 0)))) {
      iVar1 = -0x2c2;
    }
    else {
      iVar1 = _createEventShmem(param_4,param_5,&local_8,&local_c,param_1 + 0x15c);
      if (iVar1 == 0) {
        _objc_msgSend(*(undefined4 *)(param_1 + 0x110),PTR_s_lock_001f9220);
        *(int *)(param_1 + 0x160) = param_5;
        *(int *)(param_1 + 0x150) = param_4;
        *(undefined4 *)(param_1 + 0x158) = local_c;
        *param_6 = local_c;
        *(undefined4 *)(param_1 + 0x154) = local_8;
        _objc_msgSend(param_1,PTR_s_initShmem_001f99f8);
        _objc_msgSend(*(undefined4 *)(param_1 + 0x110),PTR_s_unlock_001f9474);
        _objc_msgSend(param_1,PTR_s__resetMouseParameters_001f9a08);
        _objc_msgSend(param_1,PTR_s__resetKeyboardParameters_001f9a04);
        _objc_msgSend(*(undefined4 *)(param_1 + 0x110),PTR_s_lock_001f9220);
        _objc_msgSend(param_1,PTR_s_scheduleNextPeriodicEvent_001f99f4);
        _objc_msgSend(*(undefined4 *)(param_1 + 0x110),PTR_s_unlock_001f9474);
        iVar1 = 0;
      }
      else {
        uVar2 = _objc_msgSend(param_1,PTR_s_name_001f9228,iVar1);
        _IOLog("%s: createEventShmem fails (%d).\n",uVar2);
      }
    }
  }
  else {
    iVar1 = -0x2c1;
  }
  return iVar1;
}

