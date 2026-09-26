/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001aecb4 */

int FUN_001aecb4(int param_1,undefined4 param_2,byte *param_3,undefined4 param_4,undefined4 param_5,
                undefined4 *param_6)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  byte *pbVar4;
  
  if (((((*(byte *)(param_1 + 0x124) & 1) == 0) || (*(uint *)(param_1 + 0x108) != (uint)*param_3))
      || (*(int *)(param_1 + 0x10c) != 0)) ||
     ((*(uint *)(param_1 + 0x110) != (uint)param_3[1] || (*(int *)(param_1 + 0x114) != 0)))) {
    iVar1 = 7;
  }
  else {
    iVar1 = _objc_msgSend(*(undefined4 *)(param_1 + 0x128),
                          PTR_s_executeRequest_buffer_client__001f9a9c,param_3,param_4,param_5);
    if (iVar1 == 2) {
      pbVar4 = param_3 + 0x38;
      for (iVar3 = 6; iVar3 != 0; iVar3 = iVar3 + -1) {
        *param_6 = *(undefined4 *)pbVar4;
        pbVar4 = pbVar4 + 4;
        param_6 = param_6 + 1;
      }
      *(undefined2 *)param_6 = *(undefined2 *)pbVar4;
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

