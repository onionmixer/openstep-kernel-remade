/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001ab89c */

undefined4 FUN_001ab89c(int param_1,undefined4 param_2,undefined4 param_3,void *param_4)

{
  undefined4 uVar1;
  uint uVar2;
  byte *pbVar3;
  size_t sVar4;
  
  if ((*(byte *)(param_1 + 0x128) & 1) == 0) {
    _nb_free(param_3);
    uVar1 = 0x32;
  }
  else {
    uVar2 = _nb_size(param_3);
    if (*(uint *)(param_1 + 0x138) < uVar2) {
      uVar1 = _nb_size(param_3);
      uVar1 = _objc_msgSend(param_1,PTR_s_name_001f9228,uVar1);
      _IOLog("%s: netOutput bad frame size=%d\n",uVar1);
      _nb_free(param_3);
      uVar1 = 0x28;
    }
    else {
      sVar4 = 0;
      if ((*(char *)((int)param_4 + 8) < '\0') &&
         ((sVar4 = *(byte *)((int)param_4 + 0xe) & 0x1f, (*(byte *)((int)param_4 + 0xe) & 1) != 0 ||
          (0x10 < sVar4 - 2)))) {
        sVar4 = 0xffffffff;
      }
      if (-1 < (int)sVar4) {
        sVar4 = sVar4 + 0xe;
      }
      if ((int)sVar4 < 0) {
        uVar1 = _objc_msgSend(param_1,PTR_s_name_001f9228);
        _IOLog("%s: bad mac header\n",uVar1);
        _nb_free(param_3);
        uVar1 = 0x28;
      }
      else {
        _nb_grow_top(param_3,sVar4);
        pbVar3 = (byte *)_nb_map(param_3);
        _bcopy(param_4,pbVar3,sVar4);
        *pbVar3 = *pbVar3 & 0xf0;
        _objc_msgSend(param_1,PTR_s_transmit__001f9b3c,param_3);
        uVar1 = 0;
      }
    }
  }
  return uVar1;
}

