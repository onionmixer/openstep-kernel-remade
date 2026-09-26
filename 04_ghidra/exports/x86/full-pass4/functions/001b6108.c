/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001b6108 */

int FUN_001b6108(undefined4 param_1,undefined4 param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  
  uVar5 = 0;
  while( true ) {
    uVar1 = _objc_msgSend(DAT_001e5390,PTR_s_count_001f92d8);
    if (uVar1 <= uVar5) {
      return 0;
    }
    iVar2 = _objc_msgSend(DAT_001e5390,PTR_s_objectAt__001f92e8,uVar5);
    uVar3 = _objc_msgSend(iVar2,PTR_s_audioDevice_001f990c,PTR_s__inputChannel_001f9908);
    iVar4 = _objc_msgSend(uVar3);
    if ((iVar2 == iVar4) &&
       (iVar4 = _objc_msgSend(iVar2,PTR_s_userSndPort_001f9904), iVar4 == param_3)) break;
    uVar5 = uVar5 + 1;
  }
  return iVar2;
}

