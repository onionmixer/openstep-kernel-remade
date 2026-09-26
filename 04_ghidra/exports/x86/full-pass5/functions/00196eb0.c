/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00196eb0 */

int _kmioctl(undefined4 param_1,int param_2,undefined4 *param_3,undefined4 param_4)

{
  int iVar1;
  undefined *puVar2;
  undefined2 local_c;
  undefined2 local_a;
  undefined2 local_8;
  undefined2 local_6;
  
  puVar2 = PTR_s_restore_001f94c8;
  if (param_2 == 0x20006b02) {
LAB_00196f3e:
    iVar1 = _objc_msgSend(_kmId,puVar2);
  }
  else {
    if (param_2 < 0x20006b03) {
      if (param_2 == -0x7ff78b99) {
        return 0x16;
      }
      if (param_2 < -0x7ff78b98) {
        if (param_2 == -0x7ffb94f7) {
          param_3 = (undefined4 *)*param_3;
          puVar2 = PTR_s_animationCtl__001f94a4;
LAB_00196f57:
          iVar1 = _objc_msgSend(_kmId,puVar2,param_3);
          return iVar1;
        }
      }
      else {
        puVar2 = PTR_s_drawRect__001f94cc;
        if ((param_2 == -0x7ff394fb) || (puVar2 = PTR_s_eraseRect__001f94d0, param_2 == -0x7ff394fa)
           ) goto LAB_00196f57;
      }
    }
    else {
      puVar2 = PTR_s_disableCons_001f94d4;
      if (param_2 == 0x20006b08) goto LAB_00196f3e;
      if (param_2 < 0x20006b09) {
        puVar2 = PTR_s_dumpMsgBuf_001f94d8;
        if (param_2 == 0x20006b03) goto LAB_00196f3e;
      }
      else {
        puVar2 = PTR_s_getStatus__001f94dc;
        if (param_2 == 0x40046b0a) goto LAB_00196f57;
        if (param_2 == 0x40086b0b) {
          _objc_msgSend(_kmId,PTR_s_getScreenSize__001f94c4,&local_c);
          *(undefined2 *)param_3 = local_c;
          *(undefined2 *)((int)param_3 + 2) = local_a;
          *(undefined2 *)(param_3 + 1) = local_8;
          *(undefined2 *)((int)param_3 + 6) = local_6;
          return 0;
        }
      }
    }
    iVar1 = (*(code *)(&PTR__nullioctl_001daff8)[DAT_001e9817 * 0xc])
                      (&_cons,param_2,param_3,param_4);
    if ((iVar1 < 0) && (iVar1 = _ttioctl(&_cons,param_2,param_3,param_4), iVar1 < 0)) {
      iVar1 = 0x19;
    }
  }
  return iVar1;
}

