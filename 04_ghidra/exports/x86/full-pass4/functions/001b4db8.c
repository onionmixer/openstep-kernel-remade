/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001b4db8 */

int FUN_001b4db8(undefined4 **param_1,undefined4 param_2,undefined4 param_3,char param_4)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  undefined4 ***pppuVar6;
  undefined4 **ppuStack_34;
  undefined4 *puStack_30;
  undefined4 **ppuStack_2c;
  char local_1c;
  undefined4 *local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 *local_8;
  
  local_8 = (undefined4 **)0x0;
  local_c = (undefined4 *)0xffffffff;
  local_10 = 0;
  local_1c = '\0';
  if (param_4 != '\0') {
    ppuStack_2c = (undefined4 **)PTR_s_sampleRate_001f98b4;
    puStack_30 = param_1;
    ppuStack_34 = (undefined4 **)0x1b4df4;
    local_8 = (undefined4 *)_objc_msgSend();
    local_c = param_1[0x52];
    ppuStack_34 = (undefined4 **)PTR_s_channelCount_001f98b0;
    local_10 = _objc_msgSend(param_1);
  }
  uVar5 = 0;
  while( true ) {
    ppuStack_2c = (undefined4 **)PTR_s_dmaCount_001f98ac;
    puStack_30 = (undefined4 *)param_3;
    ppuStack_34 = (undefined4 **)0x1b4e25;
    uVar2 = _objc_msgSend();
    if (uVar2 >> 1 <= uVar5) break;
    ppuStack_2c = (undefined4 **)&local_10;
    puStack_30 = &local_c;
    ppuStack_34 = &local_8;
    cVar1 = _objc_msgSend(param_3,PTR_s_enqueueDescriptor_dataFormat_cha_001f98a8);
    if (cVar1 == '\0') break;
    uVar5 = uVar5 + 1;
  }
  ppuStack_2c = (undefined4 **)PTR_s_enqueueCount_001f98a4;
  puStack_30 = (undefined4 *)param_3;
  ppuStack_34 = (undefined4 **)0x1b4e61;
  iVar3 = _objc_msgSend();
  if (iVar3 != 0) {
    ppuStack_2c = (undefined4 **)local_8;
    puStack_30 = (undefined4 *)PTR_s__setSampleRate__001f98a0;
    ppuStack_34 = param_1;
    _objc_msgSend();
    _objc_msgSend(param_1,PTR_s__setDataEncoding__001f989c,local_c);
    _objc_msgSend(param_1,PTR_s__setChannelCount__001f9898,local_10);
    ppuStack_2c = (undefined4 **)PTR_s_descriptorSize_001f988c;
    puStack_30 = (undefined4 *)param_3;
    ppuStack_34 = (undefined4 **)0x1b4eaf;
    ppuStack_34 = (undefined4 **)_objc_msgSend();
    uVar4 = _objc_msgSend(param_3,PTR_s_channelBuffer_001f9890);
    cVar1 = _objc_msgSend(param_3,PTR_s_isRead_001f98fc,uVar4);
    uVar4 = _objc_msgSend(param_3,PTR_s_localChannel_001f9894,(int)cVar1);
    local_1c = _objc_msgSend(param_1,PTR_s_startDMAForChannel_read_buffer_b_001f9888,uVar4);
    if (local_1c == '\0') {
      while( true ) {
        ppuStack_2c = (undefined4 **)PTR_s_enqueueCount_001f98a4;
        puStack_30 = (undefined4 *)param_3;
        ppuStack_34 = (undefined4 **)0x1b4f85;
        iVar3 = _objc_msgSend();
        if (iVar3 == 0) break;
        ppuStack_2c = (undefined4 **)PTR_s_dequeueDescriptor_001f9870;
        puStack_30 = (undefined4 *)param_3;
        ppuStack_34 = (undefined4 **)0x1b4f99;
        _objc_msgSend();
      }
      ppuStack_2c = (undefined4 **)PTR_s_isRead_001f98fc;
      puStack_30 = (undefined4 *)param_3;
      ppuStack_34 = (undefined4 **)0x1b4fad;
      cVar1 = _objc_msgSend();
      ppuStack_34 = (undefined4 **)(int)cVar1;
      uVar4 = _objc_msgSend(param_3,PTR_s_localChannel_001f9894);
      _objc_msgSend(param_1,PTR_s_stopDMAForChannel_read__001f986c,uVar4);
      _objc_msgSend(param_3,PTR_s_freeDescriptors_001f9868);
      pppuVar6 = &ppuStack_2c;
      ppuStack_2c = (undefined4 **)0xffffffff;
    }
    else {
      ppuStack_2c = &local_18;
      puStack_30 = (undefined4 *)0x1b4f06;
      _IOGetTimestamp();
      puStack_30 = (undefined4 *)local_14;
      ppuStack_34 = (undefined4 **)local_18;
      _objc_msgSend(param_1,PTR_s__setOutputStartTime__001f9884);
      cVar1 = _objc_msgSend(param_3,PTR_s_isRead_001f98fc);
      puStack_30 = (undefined4 *)PTR_s__setOutputActive__001f987c;
      if (cVar1 != '\0') {
        puStack_30 = (undefined4 *)PTR_s__setInputActive__001f9880;
      }
      ppuStack_2c = (undefined4 **)0x1;
      ppuStack_34 = param_1;
      _objc_msgSend();
      ppuStack_2c = (undefined4 **)PTR_s__timeout_001f9878;
      puStack_30 = param_1;
      ppuStack_34 = (undefined4 **)0x1b4f5b;
      iVar3 = _objc_msgSend();
      if (iVar3 != -1) goto LAB_001b4fee;
      ppuStack_2c = (undefined4 **)PTR_s_descriptorSize_001f988c;
      puStack_30 = (undefined4 *)param_3;
      ppuStack_34 = (undefined4 **)0x1b4f74;
      ppuStack_34 = (undefined4 **)_objc_msgSend();
      pppuVar6 = &ppuStack_34;
    }
    *(undefined **)((int)pppuVar6 + -4) = PTR_s__setTimeout__001f9874;
    *(undefined4 ***)((int)pppuVar6 + -8) = param_1;
    *(undefined4 *)((int)pppuVar6 + -0xc) = 0x1b4fee;
    _objc_msgSend();
  }
LAB_001b4fee:
  return (int)local_1c;
}

