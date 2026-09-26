/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001ad61c */

int FUN_001ad61c(undefined4 param_1,undefined4 param_2,undefined4 param_3,uint param_4,uint param_5,
                undefined4 param_6,undefined4 param_7,int param_8,undefined4 *param_9)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  undefined4 *puVar7;
  
  iVar2 = _objc_msgSend(param_1,PTR_s_isDiskReady__001f9384,1);
  if (iVar2 == -0x44e) {
    iVar2 = -0x44e;
  }
  else if (iVar2 == 0) {
    cVar1 = _objc_msgSend(param_1,PTR_s_isFormatted_001f9398);
    if (cVar1 == '\0') {
      iVar2 = -0x44d;
    }
    else {
      uVar4 = _objc_msgSend(param_1,PTR_s_blockSize_001f93a8);
      uVar5 = _objc_msgSend(param_1,PTR_s_diskSize_001f93d0);
      uVar6 = param_5 / uVar4;
      if (param_5 % uVar4 == 0) {
        if (uVar5 < param_4 + uVar6) {
          if (uVar5 <= param_4) {
            return -0x2c2;
          }
          uVar6 = uVar5 - param_4;
        }
        puVar7 = (undefined4 *)_objc_msgSend(param_1,PTR_s_allocSdBuf__001f9ac0,param_8);
        *puVar7 = param_3;
        puVar7[1] = param_4;
        puVar7[2] = uVar6;
        puVar7[3] = param_6;
        puVar7[4] = param_7;
        *(byte *)(puVar7 + 8) = *(byte *)(puVar7 + 8) | 1;
        iVar2 = _objc_msgSend(param_1,PTR_s_enqueueSdBuf__001f9abc,puVar7);
        if (param_8 == 0) {
          *param_9 = puVar7[9];
          _objc_msgSend(param_1,PTR_s_freeSdBuf__001f9ab8,puVar7);
        }
      }
      else {
        iVar2 = -1;
      }
    }
  }
  else {
    uVar3 = _objc_msgSend(param_1,PTR_s_stringFromReturn__001f9490,iVar2);
    uVar3 = _objc_msgSend(param_1,PTR_s_name_001f9228,uVar3);
    _IOLog("%s deviceRwCommon: bogus return from isDiskReady (%s)\n",uVar3);
  }
  return iVar2;
}

