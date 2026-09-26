/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001b8d80 */

int FUN_001b8d80(int param_1,undefined4 param_2,int param_3,uint param_4)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  bool bVar4;
  int *piVar5;
  int *piVar6;
  uint local_8;
  
  local_8 = 0;
  bVar4 = false;
  _objc_msgSend(*(undefined4 *)(param_1 + 0x28),PTR_s_lock_001f9220);
  piVar6 = (int *)(param_1 + 0x2c);
  piVar1 = *(int **)(param_1 + 0x2c);
joined_r0x001b8db8:
  do {
    if (piVar6 == piVar1) {
LAB_001b8ef9:
      _objc_msgSend(*(undefined4 *)(param_1 + 0x28),PTR_s_unlock_001f9474);
      return param_1;
    }
    if (piVar1[8] == param_3) {
      if ((*(byte *)(piVar1 + 6) & 1) != 0) {
        _objc_msgSend(param_1,PTR_s_sendStatusMessage_forRegion__001f9740,0,piVar1);
      }
      piVar1[8] = 0;
    }
    _objc_msgSend(param_1,PTR_s_completeRegion_descriptor_size_u_001f973c,piVar1,param_3,param_4,
                  &local_8);
    if (piVar1[9] == param_3) {
LAB_001b8e2f:
      if (piVar1[0xd] != 0) goto LAB_001b8e35;
LAB_001b8e6a:
      if ((piVar1[0xc] == 0) && ((*(byte *)(piVar1 + 6) & 2) != 0)) {
        _objc_msgSend(param_1,PTR_s_sendStatusMessage_forRegion__001f9740,1,piVar1);
      }
    }
    else {
      if (piVar1[0xd] == 0) {
        if (piVar1[0xc] != 0) goto LAB_001b8e2f;
        if (param_4 <= local_8) goto LAB_001b8ef9;
        piVar1 = (int *)piVar1[0xf];
        goto joined_r0x001b8db8;
      }
LAB_001b8e35:
      if (((*(byte *)(piVar1 + 6) & 0x10) != 0) && ((!bVar4 || (*(int *)(param_1 + 0x1c) == 1)))) {
        _objc_msgSend(param_1,PTR_s_sendStatusMessage_forRegion__001f9740,4,piVar1);
        bVar4 = true;
      }
      if (piVar1[0xd] == 0) goto LAB_001b8e6a;
    }
    piVar2 = (int *)piVar1[0xf];
    piVar3 = (int *)piVar1[0x10];
    piVar5 = piVar6;
    if (piVar6 != piVar2) {
      piVar5 = piVar2 + 0xf;
    }
    piVar5[1] = (int)piVar3;
    piVar5 = piVar6;
    if (piVar6 != piVar3) {
      piVar5 = piVar3 + 0xf;
    }
    *piVar5 = (int)piVar2;
    _objc_msgSend(param_1,PTR_s_freeRegion__001f9738,piVar1);
    piVar1 = (int *)piVar1[0xf];
  } while( true );
}

