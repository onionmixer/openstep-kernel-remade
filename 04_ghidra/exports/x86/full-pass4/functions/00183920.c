/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00183920 */

undefined4 _sdstrategy(uint *param_1)

{
  undefined2 uVar1;
  int iVar2;
  int iVar3;
  undefined *puVar4;
  undefined4 uVar5;
  
  iVar2 = FUN_001840ec((int)*(short *)((int)param_1 + 0x1e));
  if (iVar2 != 0) {
    uVar5 = _kernel_map;
    if ((*param_1 & 0x4000010) == 0x10) {
      uVar5 = *(undefined4 *)(*(int *)(param_1[0xb] + 0x68) + 0xc);
    }
    iVar3 = _objc_msgSend(iVar2,PTR_s_blockSize_001f93a8);
    if (iVar3 != 0) {
      puVar4 = PTR_s_writeAsyncAt_length_buffer_pendi_001f93b0;
      if ((*param_1 & 1) != 0) {
        puVar4 = PTR_s_readAsyncAt_length_buffer_pendin_001f93ac;
      }
      iVar3 = _objc_msgSend(iVar2,puVar4,param_1[9],param_1[5],param_1[8],param_1,uVar5);
      if (iVar3 == 0) {
        return 0;
      }
      uVar1 = _objc_msgSend(iVar2,PTR_s_errnoFromReturn__001f93b4,iVar3);
      *(undefined2 *)(param_1 + 7) = uVar1;
      goto LAB_001839d1;
    }
  }
  *(undefined2 *)(param_1 + 7) = 6;
LAB_001839d1:
  *(byte *)param_1 = (byte)*param_1 | 4;
  _biodone(param_1);
  return 0xffffffff;
}

