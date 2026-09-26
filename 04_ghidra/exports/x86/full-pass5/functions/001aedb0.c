/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001aedb0 */

int FUN_001aedb0(int param_1,undefined4 param_2,int *param_3,undefined4 param_4,undefined4 param_5,
                int *param_6)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  
  if (((((*(byte *)(param_1 + 0x124) & 1) == 0) || (*param_3 != *(int *)(param_1 + 0x108))) ||
      (param_3[1] != *(int *)(param_1 + 0x10c))) ||
     ((param_3[2] != *(int *)(param_1 + 0x110) || (param_3[3] != *(int *)(param_1 + 0x114))))) {
    iVar1 = 7;
  }
  else {
    iVar1 = _objc_msgSend(*(undefined4 *)(param_1 + 0x128),
                          PTR_s_executeSCSI3Request_buffer_clien_001f9a4c,param_3,param_4,param_5);
    if (iVar1 == 2) {
      piVar4 = param_3 + 0x13;
      for (iVar3 = 6; iVar3 != 0; iVar3 = iVar3 + -1) {
        *param_6 = *piVar4;
        piVar4 = piVar4 + 1;
        param_6 = param_6 + 1;
      }
      *(short *)param_6 = (short)*piVar4;
    }
    else if ((iVar1 == 3) && ((*(byte *)(param_1 + 0x11c) & 1) != 0)) {
      iVar1 = _objc_msgSend(param_1,PTR_s_getSense__001f9a50,param_6);
      if (iVar1 == 0) {
        iVar1 = 2;
      }
      else {
        uVar2 = _IOFindNameForValue(iVar1,&_IOScStatusStrings);
        uVar2 = _objc_msgSend(param_1,PTR_s_name_001f9228,*(undefined4 *)(param_1 + 0x108),
                              *(undefined4 *)(param_1 + 0x110),uVar2);
        _IOLog("%s: Request Sense on target %d lun %d failed (%s)\n",uVar2);
        iVar1 = 3;
      }
    }
  }
  return iVar1;
}

