/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001841f0 */

int _sgioctl(short param_1,int param_2,uint *param_3)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  undefined8 uVar6;
  uint *puVar7;
  uint *puVar8;
  undefined *puVar9;
  
  iVar2 = FUN_0018447c((int)param_1);
  if (iVar2 == 0) {
    return 6;
  }
  puVar9 = PTR_s_enableAutoSense_001f9404;
  if (param_2 != 0x20007302) {
    if (param_2 < 0x20007303) {
      if (param_2 == -0x7fef8cf4) {
        cVar1 = _suser();
        iVar2 = _objc_msgSend(iVar2,PTR_s_setSCSI3Target_lun_isRoot__001f93f8,*param_3,param_3[1],
                              param_3[2],param_3[3],(int)cVar1);
      }
      else {
        if (-0x7fef8cf4 < param_2) {
          if (param_2 == -0x3fab8cff) {
            puVar8 = (uint *)0x0;
            puVar7 = param_3;
          }
          else {
            if (param_2 != -0x3fa78cf2) {
              return 0x16;
            }
            puVar7 = (uint *)0x0;
            puVar8 = param_3;
          }
          iVar2 = FUN_0018449c(iVar2,puVar7,puVar8);
          return iVar2;
        }
        if (param_2 != -0x7ffd8d00) {
          if (param_2 != -0x7ffb8cfa) {
            return 0x16;
          }
          iVar2 = _objc_msgSend(iVar2,PTR_s_setController__001f93f4,*param_3);
          if (iVar2 != 0) {
            return 0x13;
          }
          return 0;
        }
        cVar1 = _suser();
        iVar2 = _objc_msgSend(iVar2,PTR_s_setTarget_lun_isRoot__001f93f0,(char)*param_3,
                              *(undefined1 *)((int)param_3 + 1),(int)cVar1);
      }
      if (iVar2 != 0) {
        return 0xd;
      }
      return 0;
    }
    if (param_2 == 0x40047307) {
      iVar2 = _objc_msgSend(iVar2,PTR_s_autoSense_001f940c);
      *param_3 = (uint)(iVar2 != 0);
      return 0;
    }
    if (0x40047307 < param_2) {
      if (param_2 == 0x40047309) {
        uVar3 = _objc_msgSend(iVar2,PTR_s_controller_001f939c,PTR_s_numberOfTargets_001f9410);
        uVar4 = _objc_msgSend(uVar3);
        *param_3 = uVar4;
        return 0;
      }
      if (0x40047308 < param_2) {
        if (param_2 != 0x4010730d) {
          return 0x16;
        }
        uVar6 = _objc_msgSend(iVar2,PTR_s_SCSI3_target_001f93fc);
        *(undefined8 *)param_3 = uVar6;
        uVar6 = _objc_msgSend(iVar2,PTR_s_SCSI3_lun_001f9400);
        *(undefined8 *)(param_3 + 2) = uVar6;
        return 0;
      }
      uVar3 = _objc_msgSend(iVar2,PTR_s_controller_001f939c,PTR_s_maxTransfer_001f9388);
      uVar4 = _objc_msgSend(uVar3);
      *param_3 = uVar4;
      return 0;
    }
    puVar9 = PTR_s_disableAutoSense_001f9408;
    if (param_2 != 0x20007303) {
      if (param_2 != 0x20007304) {
        return 0x16;
      }
      iVar5 = _suser();
      if (iVar5 != 0) {
        iVar2 = _objc_msgSend(iVar2,PTR_s_resetSCSIBus_001f9414);
        if (iVar2 != 0) {
          return 5;
        }
        return 0;
      }
      return (int)*(char *)(DAT_001e875c + 0x68);
    }
  }
  iVar2 = _objc_msgSend(iVar2,puVar9);
  if (iVar2 != 0) {
    return 0x16;
  }
  return 0;
}

