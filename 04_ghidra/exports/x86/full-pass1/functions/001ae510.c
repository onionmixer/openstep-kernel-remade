/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001ae510 */

undefined4 FUN_001ae510(int param_1,undefined4 param_2,uint *param_3,undefined4 *param_4)

{
  int iVar1;
  short *psVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  
  iVar1 = _objc_msgSend(param_1,PTR_s_blockSize_001f93a8);
  _bzero(param_4,0x54);
  *(undefined1 *)param_4 = *(undefined1 *)(param_1 + 0x188);
  *(undefined1 *)((int)param_4 + 1) = *(undefined1 *)(param_1 + 0x189);
  uVar5 = *param_3;
  if (uVar5 == 1) {
    *(undefined1 *)((int)param_4 + 0xe) = 0;
    uVar5 = param_3[2];
    uVar4 = param_3[1];
    uVar3 = 0;
  }
  else {
    if (uVar5 != 0) {
      if (4 < uVar5) {
        return 0;
      }
      psVar2 = (short *)param_3[5];
      if (*psVar2 == *(short *)(param_1 + 0x188)) {
        for (iVar1 = 0x15; iVar1 != 0; iVar1 = iVar1 + -1) {
          *param_4 = *(undefined4 *)psVar2;
          psVar2 = psVar2 + 2;
          param_4 = param_4 + 1;
        }
        return 0;
      }
      psVar2[0xe] = 7;
      psVar2[0xf] = 0;
      param_3[10] = 0xfffffd3e;
      _objc_msgSend(param_1,PTR_s_sdIoComplete__001f9a6c,param_3);
      return 7;
    }
    *(undefined1 *)((int)param_4 + 0xe) = 1;
    uVar5 = param_3[2];
    uVar4 = param_3[1];
    uVar3 = 1;
  }
  _objc_msgSend(param_1,PTR_s_genRwCdb_readFlag_block_blockCnt_001f9a68,(int)param_4 + 2,uVar3,uVar4
                ,uVar5);
  param_3[5] = 0;
  param_4[4] = iVar1 * param_3[2];
  param_4[5] = 0x1e;
  *(byte *)(param_4 + 6) = *(byte *)(param_4 + 6) | 1;
  return 0;
}

