/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001a6288 */

int FUN_001a6288(int param_1,undefined4 param_2,uint param_3,uint param_4,int *param_5,int *param_6)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  uint local_c;
  
  uVar1 = _objc_msgSend(param_1,PTR_s_name_001f9228);
  iVar2 = _objc_msgSend(*(undefined4 *)(param_1 + 0x184),PTR_s_isDiskReady__001f9384,1);
  if (iVar2 == -0x44e) {
    iVar2 = -0x44e;
  }
  else if (iVar2 == 0) {
    uVar4 = _objc_msgSend(param_1,PTR_s_blockSize_001f93a8);
    uVar5 = _objc_msgSend(param_1,PTR_s_diskSize_001f93d0);
    local_c = param_4 / uVar4;
    if (param_4 % uVar4 == 0) {
      if (uVar5 < local_c + param_3) {
        if (uVar5 <= param_3) {
          return -0x2c2;
        }
        local_c = uVar5 - param_3;
      }
      uVar4 = uVar4 / *(uint *)(param_1 + 0x18c);
      *param_5 = uVar4 * param_3 + *(int *)(param_1 + 0x188);
      *param_6 = local_c * uVar4 * *(int *)(param_1 + 0x18c);
      iVar2 = 0;
    }
    else {
      _IOLog("%s: Bytes requested not multiple of block size\n",uVar1);
      iVar2 = -0x2c2;
    }
  }
  else {
    uVar3 = _objc_msgSend(param_1,PTR_s_stringFromReturn__001f9490,iVar2);
    _IOLog("%s deviceRwCommon: bogus return from isDiskReady (%s)\n",uVar1,uVar3);
  }
  return iVar2;
}

