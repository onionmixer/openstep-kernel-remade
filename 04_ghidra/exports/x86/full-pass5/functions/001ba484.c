/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001ba484 */

int FUN_001ba484(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  uint uVar6;
  int local_c;
  undefined *local_8;
  
  local_c = param_1;
  local_8 = PTR_s_AudioStream_001fa518;
  iVar2 = _objc_msgSendSuper(&local_c,PTR_s_initChannel_tag_user_owner_type__001f9750,param_3,
                             param_4,param_5,param_6,param_7);
  if (iVar2 == 0) {
    param_1 = 0;
  }
  else {
    *(undefined4 *)(param_1 + 0x7c) = 0x8000;
    *(undefined4 *)(param_1 + 0x78) = 0x8000;
    *(undefined4 *)(param_1 + 0x98) = 1;
    iVar2 = param_1 + 0x8c;
    *(int *)(param_1 + 0x90) = iVar2;
    *(int *)(param_1 + 0x8c) = iVar2;
    uVar6 = 0;
    while( true ) {
      uVar3 = _objc_msgSend(param_3,PTR_s_dmaCount_001f98ac);
      if (uVar3 <= uVar6) break;
      puVar4 = (undefined4 *)_IOMalloc(0x1c);
      *puVar4 = 0;
      puVar4[1] = 0;
      puVar4[3] = 0;
      puVar4[2] = 0;
      puVar4[4] = 0;
      if (*(int *)(param_1 + 0x8c) == iVar2) {
        *(undefined4 **)(param_1 + 0x8c) = puVar4;
        *(undefined4 **)(param_1 + 0x90) = puVar4;
        puVar4[5] = iVar2;
        puVar4[6] = iVar2;
      }
      else {
        iVar1 = *(int *)(param_1 + 0x90);
        puVar4[6] = iVar1;
        puVar4[5] = iVar2;
        *(undefined4 **)(param_1 + 0x90) = puVar4;
        *(undefined4 **)(iVar1 + 0x14) = puVar4;
      }
      uVar6 = uVar6 + 1;
    }
    uVar5 = _IOMalloc(_page_size * 8);
    *(undefined4 *)(param_1 + 0x70) = uVar5;
    uVar5 = _IOMalloc(_page_size * 4);
    *(undefined4 *)(param_1 + 0x74) = uVar5;
  }
  return param_1;
}

