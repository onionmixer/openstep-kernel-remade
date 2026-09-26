/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001ad8b0 */

void FUN_001ad8b0(int param_1,undefined4 param_2,uint *param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  undefined4 *puVar6;
  byte *pbVar7;
  char *pcVar8;
  undefined *puVar9;
  byte local_74 [2];
  byte local_72;
  undefined1 local_58 [28];
  undefined4 local_3c;
  char local_38;
  uint local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20 [7];
  
  uVar5 = 100;
  uVar1 = _objc_msgSend(param_1,PTR_s_name_001f9228);
  param_3[0xd] = 10;
  param_3[0xe] = 5;
  param_3[0xf] = 10;
  if (param_3[0xd] == 0) {
LAB_001addd7:
    uVar5 = 0xfffffd36;
  }
  else {
    if (param_3[0xe] != 0) {
      while (param_3[0xf] != 0) {
        iVar2 = _objc_msgSend(param_1,PTR_s_setupScsiReq_scsiReq__001f9aa0,param_3,local_58);
        if (iVar2 != 0) {
          return;
        }
        local_74[0] = local_74[0] & 0x7f;
        uVar5 = _objc_msgSend(*(undefined4 *)(param_1 + 0x184),
                              PTR_s_executeRequest_buffer_client__001f9a9c,local_58,param_3[3],
                              param_3[4]);
        if (uVar5 == 0) {
          if ((*param_3 < 2) &&
             (iVar2 = _objc_msgSend(param_1,PTR_s_blockSize_001f93a8),
             local_34 != param_3[2] * iVar2)) {
            uVar4 = param_3[0xe];
            param_3[0xe] = uVar4 - 1;
            if (uVar4 != 1 && -1 < (int)(uVar4 - 1)) {
              _IOLog("%s: TRANSFER COUNT ERROR.  Expected = %d Received %d; Retrying.\n",uVar1,
                     param_3[2] * iVar2,param_3[9]);
              _objc_msgSend(param_1,PTR_s_logOpInfo_sense__001f9a98,param_3,0);
              goto LAB_001add6a;
            }
            _IOLog("%s: TRANSFER COUNT ERROR;  FATAL.\n",uVar1);
            _objc_msgSend(param_1,PTR_s_logOpInfo_sense__001f9a98,param_3,local_74);
            uVar5 = 0xf;
          }
          else if (((*(byte *)(param_1 + 0x18a) & 2) != 0) &&
                  ((puVar9 = PTR_s_addToBytesRead_totalTime_latentT_001f9a94, *param_3 == 0 ||
                   (puVar9 = PTR_s_addToBytesWritten_totalTime_late_001f9a90, *param_3 == 1)))) {
            _objc_msgSend(param_1,puVar9,local_34,local_30,local_2c,local_28,local_24);
          }
          break;
        }
        if ((param_3[8] & 2) != 0) break;
        if (9 < uVar5) {
          if (uVar5 < 0x14) {
            if (uVar5 < 0xe) {
              if (uVar5 == 0xd) goto LAB_001adac4;
              goto LAB_001add20;
            }
LAB_001adaa1:
            uVar3 = _IOFindNameForValue(uVar5,&_IOScStatusStrings);
            _IOLog("%s: %s : FATAL ERROR\n",uVar1,uVar3);
          }
          else {
            if (uVar5 == 100) goto LAB_001adaa1;
LAB_001add20:
            uVar4 = param_3[0xe];
            param_3[0xe] = uVar4 - 1;
            if (uVar4 != 1 && -1 < (int)(uVar4 - 1)) {
              uVar3 = _IOFindNameForValue(uVar5,&_IOScStatusStrings);
              _IOLog("%s: %s; Retrying.\n",uVar1,uVar3);
LAB_001add62:
              _objc_msgSend(param_1,PTR_s_logOpInfo_sense__001f9a98,param_3,local_74);
              goto LAB_001add6a;
            }
            puVar9 = &_IOScStatusStrings;
            uVar4 = uVar5;
LAB_001ade04:
            uVar3 = _IOFindNameForValue(uVar4,puVar9);
            _IOLog("%s: %s; FATAL.\n",uVar1,uVar3);
          }
          _objc_msgSend(param_1,PTR_s_logOpInfo_sense__001f9a98,param_3,local_74);
          break;
        }
        if ((6 < uVar5) || (uVar5 == 1)) goto LAB_001adaa1;
        if ((uVar5 == 0) || (3 < uVar5)) goto LAB_001add20;
LAB_001adac4:
        if (local_38 != '\x02') {
          if (local_38 == '\b') {
            uVar4 = param_3[0xd];
            param_3[0xd] = uVar4 - 1;
            if (uVar4 == 1 || (int)(uVar4 - 1) < 0) {
              pcVar8 = "%s: BUSY STATUS; FATAL.\n";
              goto LAB_001ade4d;
            }
            _IOLog("%s: BUSY STATUS; Retrying.\n",uVar1);
            _IOSleep(1000);
            goto LAB_001add6a;
          }
          _IOLog("%s: BOGUS SCSI STATUS (0x%x): FATAL.\n",uVar1,local_38);
          _objc_msgSend(param_1,PTR_s_logOpInfo_sense__001f9a98,param_3,local_74);
          uVar5 = 0xd;
          break;
        }
        if (uVar5 == 2) {
          puVar6 = local_20;
          pbVar7 = local_74;
          for (iVar2 = 6; iVar2 != 0; iVar2 = iVar2 + -1) {
            *(undefined4 *)pbVar7 = *puVar6;
            puVar6 = puVar6 + 1;
            pbVar7 = pbVar7 + 4;
          }
          *(undefined2 *)pbVar7 = *(undefined2 *)puVar6;
        }
        else {
          uVar5 = _objc_msgSend(param_1,PTR_s_reqSense__001f9a8c,local_74);
          if (uVar5 != 0) {
            _IOLog("%s: REQUEST SENSE ERROR;  FATAL.\n",uVar1);
            break;
          }
        }
        switch(local_72 & 0xf) {
        case 0:
        case 1:
        case 3:
        case 4:
          uVar4 = param_3[0xe];
          param_3[0xe] = uVar4 - 1;
          if (uVar4 == 1 || (int)(uVar4 - 1) < 0) {
            puVar9 = &_IOSCSISenseStrings;
            uVar4 = local_72 & 0xf;
            goto LAB_001ade04;
          }
          uVar3 = _IOFindNameForValue(local_72 & 0xf,&_IOSCSISenseStrings);
          _IOLog("%s: %s; Retrying.\n",uVar1,uVar3);
          goto LAB_001add62;
        case 2:
          uVar4 = param_3[0xf];
          param_3[0xf] = uVar4 - 1;
          if (uVar4 == 1 || (int)(uVar4 - 1) < 0) {
            pcVar8 = "%s: NOT READY; FATAL.\n";
LAB_001ade4d:
            _IOLog(pcVar8,uVar1);
            _objc_msgSend(param_1,PTR_s_logOpInfo_sense__001f9a98,param_3,local_74);
            goto LAB_001addbe;
          }
          _IOLog("%s: NOT READY; Retrying.\n",uVar1);
          _objc_msgSend(param_1,PTR_s_logOpInfo_sense__001f9a98,param_3,local_74);
          _IOSleep(1000);
          break;
        default:
          uVar3 = _IOFindNameForValue(local_72 & 0xf,&_IOSCSISenseStrings);
          _IOLog("%s: %s; FATAL.\n",uVar1,uVar3);
          _objc_msgSend(param_1,PTR_s_logOpInfo_sense__001f9a98,param_3,local_74);
          uVar5 = 2;
          goto LAB_001addbe;
        case 6:
          uVar4 = param_3[0xe];
          param_3[0xe] = uVar4 - 1;
          if (uVar4 == 1 || (int)(uVar4 - 1) < 0) {
            pcVar8 = "%s: UNIT ATTENTION; FATAL.\n";
            goto LAB_001ade4d;
          }
          _IOLog("%s: UNIT ATTENTION; Retrying.\n",uVar1);
          _objc_msgSend(param_1,PTR_s_logOpInfo_sense__001f9a98,param_3,local_74);
          break;
        case 7:
          _IOLog("%s: WRITE PROTECTED. FATAL.\n",uVar1);
          _objc_msgSend(param_1,PTR_s_logOpInfo_sense__001f9a98,param_3,local_74);
          uVar5 = 0x11;
          goto LAB_001addbe;
        }
LAB_001add6a:
        if ((*(byte *)(param_1 + 0x18a) & 2) != 0) {
          puVar9 = PTR_s_incrementReadRetries_001f9a88;
          if ((*param_3 != 0) && (puVar9 = PTR_s_incrementWriteRetries_001f9a84, *param_3 != 1)) {
            puVar9 = PTR_s_incrementOtherRetries_001f9a80;
          }
          _objc_msgSend(param_1,puVar9);
        }
        if (param_3[0xd] == 0) goto LAB_001addd7;
        if (param_3[0xe] == 0) break;
      }
    }
LAB_001addbe:
    if (((param_3[0xd] == 0) || (param_3[0xe] == 0)) || (param_3[0xf] == 0)) goto LAB_001addd7;
    if (uVar5 == 0) {
      uVar5 = 0;
    }
    else {
      uVar5 = _objc_msgSend(*(undefined4 *)(param_1 + 0x184),PTR_s_returnFromScStatus__001f9a7c,
                            uVar5);
    }
    if (uVar5 == 0) goto LAB_001adf2c;
  }
  if (((*(byte *)(param_1 + 0x18a) & 2) != 0) &&
     (((puVar9 = PTR_s_incrementReadErrors_001f9a78, *param_3 == 0 ||
       (puVar9 = PTR_s_incrementWriteErrors_001f9a74, *param_3 == 1)) ||
      (puVar9 = PTR_s_incrementOtherErrors_001f9a70, (param_3[8] & 2) == 0)))) {
    _objc_msgSend(param_1,puVar9);
  }
LAB_001adf2c:
  if (param_3[5] != 0) {
    *(undefined4 *)(param_3[5] + 0x1c) = local_3c;
    *(char *)(param_3[5] + 0x20) = local_38;
    *(uint *)(param_3[5] + 0x24) = local_34;
  }
  param_3[9] = local_34;
  param_3[10] = uVar5;
  _objc_msgSend(param_1,PTR_s_sdIoComplete__001f9a6c,param_3);
  return;
}

