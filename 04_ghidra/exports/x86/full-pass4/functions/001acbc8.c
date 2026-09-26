/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001acbc8 */

undefined4
FUN_001acbc8(int param_1,undefined4 param_2,undefined4 param_3,undefined1 param_4,undefined1 param_5
            ,undefined4 param_6)

{
  char *pcVar1;
  byte bVar2;
  int iVar3;
  undefined4 uVar4;
  char *pcVar5;
  int local_110;
  undefined4 local_10c;
  char local_108 [80];
  char local_b8 [31];
  char acStack_99 [81];
  byte local_48;
  char local_47;
  undefined1 local_40 [8];
  undefined1 local_38 [16];
  undefined1 local_28 [36];
  
  *(undefined4 *)(param_1 + 0x184) = param_6;
  *(undefined1 *)(param_1 + 0x188) = param_4;
  *(undefined1 *)(param_1 + 0x189) = param_5;
  _objc_msgSend(param_1,PTR_s_setUnit__001f9478,param_3);
  _sprintf(local_b8,"sd%d",param_3);
  _objc_msgSend(param_1,PTR_s_setName__001f947c,local_b8);
  _bzero(&local_48,0x41);
  iVar3 = _objc_msgSend(param_1,PTR_s_sdInquiry__001f9aa4,&local_48);
  if (iVar3 != 0) {
    if (iVar3 == 1) {
      return 2;
    }
    return 3;
  }
  if ((local_48 & 0xe0) == 0) {
    bVar2 = local_48 & 0x1f;
    if (bVar2 < 6) {
      if ((3 < bVar2) || ((local_48 & 0x1f) == 0)) {
LAB_001acc90:
        *(byte *)(param_1 + 0x1bc) = local_48 & 0x1f;
        if (local_47 < '\0') {
          _objc_msgSend(param_1,PTR_s_setRemovable__001f9ca4,1);
        }
        pcVar1 = acStack_99 + 1;
        iVar3 = FUN_001aceec(local_40,pcVar1,8,0x50);
        pcVar5 = pcVar1 + iVar3;
        if (acStack_99[iVar3] != ' ') {
          *pcVar5 = ' ';
          pcVar5 = acStack_99 + iVar3 + 2;
        }
        iVar3 = FUN_001aceec(local_38,pcVar5,0x10,(int)pcVar1 - (int)(pcVar5 + -0x50));
        pcVar5 = pcVar5 + iVar3;
        if (pcVar5[-1] != ' ') {
          *pcVar5 = ' ';
          pcVar5 = pcVar5 + 1;
        }
        iVar3 = FUN_001aceec(local_28,pcVar5,4,(int)pcVar1 - (int)(pcVar5 + -0x50));
        pcVar5[iVar3] = '\0';
        _objc_msgSend(param_1,PTR_s_setDriveName__001f9c78,pcVar1);
        uVar4 = _objc_msgSend(param_6,PTR_s_name_001f9228);
        _sprintf(local_108,"Target %d LUN %d at %s",(uint)*(byte *)(param_1 + 0x188),
                 (uint)*(byte *)(param_1 + 0x189),uVar4);
        _objc_msgSend(param_1,PTR_s_setLocation__001f9484,local_108);
        _IOLog("%s: %s\n",local_b8,pcVar1);
        _objc_msgSend(param_1,PTR_s_updateReadyState_001f9cbc);
        _objc_msgSend(param_1,PTR_s_scsiStartStop_inhibitRetry__001f9ab4,0,1);
        _objc_msgSend(param_1,PTR_s_setFormattedInternal__001f9ca0,0);
        _objc_msgSend(param_1,PTR_s_updatePhysicalParameters_001f93e4);
        _bzero(pcVar1,0x50);
        iVar3 = FUN_001aceec(local_40,pcVar1,8,0x50);
        pcVar5 = pcVar1 + iVar3;
        if (acStack_99[iVar3] != ' ') {
          *pcVar5 = ' ';
          pcVar5 = acStack_99 + iVar3 + 2;
        }
        iVar3 = FUN_001aceec(local_38,pcVar5,0x10,(int)pcVar1 - (int)(pcVar5 + -0x50));
        pcVar5 = pcVar5 + iVar3;
        if (pcVar5[-1] != ' ') {
          *pcVar5 = ' ';
          pcVar5 = pcVar5 + 1;
        }
        iVar3 = FUN_001aceec(local_28,pcVar5,0x20,(int)pcVar1 - (int)(pcVar5 + -0x50));
        pcVar5[iVar3] = '\0';
        _objc_msgSend(param_1,PTR_s_setDriveName__001f9c78,pcVar1);
        uVar4 = _objc_msgSend(param_6,PTR_s_name_001f9228);
        _sprintf(local_108,"Target %d LUN %d at %s",(uint)*(byte *)(param_1 + 0x188),
                 (uint)*(byte *)(param_1 + 0x189),uVar4);
        _objc_msgSend(param_1,PTR_s_setLocation__001f9484,local_108);
        local_110 = param_1;
        local_10c = _objc_getOrigClass("IODisk",PTR_s_init_001f924c);
        _objc_msgSendSuper(&local_110);
        return 0;
      }
    }
    else if (bVar2 == 7) goto LAB_001acc90;
  }
  return 1;
}

