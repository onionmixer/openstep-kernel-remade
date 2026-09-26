/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001971e4 */

undefined4 FUN_001971e4(int param_1)

{
  int iVar1;
  uint uVar2;
  byte *pbVar3;
  uint uVar4;
  undefined8 uVar5;
  undefined4 uVar6;
  byte local_54 [80];
  
  iVar1 = _ttynty(param_1);
  uVar4 = 0xffffffff;
  if (0 < *(int *)(param_1 + 0x18)) {
    do {
      if ((((*(uint *)(param_1 + 0x3c) & 0x2200020) == 0) &&
          ((*(uint *)(iVar1 + 0x10) & 0x10000000) != 0)) &&
         ((*(uint *)(iVar1 + 0x10) & 0x300) != 0x300)) {
        uVar6 = 0x80;
      }
      else {
        uVar6 = 0;
      }
      uVar2 = _ndqb(param_1 + 0x18,uVar6);
      if (uVar2 == 0) goto LAB_001972c3;
      uVar4 = 0x50;
      if (uVar2 < 0x50) {
        uVar4 = uVar2;
      }
      _q_to_b(param_1 + 0x18,local_54,uVar4);
      for (pbVar3 = local_54; pbVar3 < local_54 + uVar4; pbVar3 = pbVar3 + 1) {
        _objc_msgSend(_kmId,PTR_s_kmPutc__001f94a0,*pbVar3 & 0x7f);
      }
    } while (0 < *(int *)(param_1 + 0x18));
  }
  if (uVar4 == 0) {
LAB_001972c3:
    uVar4 = _getc((FILE *)(param_1 + 0x18));
    uVar5 = _ticks_to_ns_time(uVar4 & 0x7f,4);
    _ns_timeout(_ttrstrt,param_1,uVar5);
    *(byte *)(param_1 + 0x40) = *(byte *)(param_1 + 0x40) | 1;
  }
  else if (0 < *(int *)(param_1 + 0x18)) {
    _calloutDispatchUnique(FUN_001971e4,param_1);
  }
  uVar4 = *(uint *)(param_1 + 0x40);
  *(uint *)(param_1 + 0x40) = uVar4 & 0xffffffdf;
  if (*(int *)(param_1 + 0x18) <=
      (int)*(short *)(&_ttlowat + (*(byte *)(param_1 + 0x4a) & 0x1f) * 2)) {
    if ((uVar4 & 0x40) != 0) {
      *(uint *)(param_1 + 0x40) = uVar4 & 0xffffff9f;
      _wakeup(param_1 + 0x18);
    }
    if (*(int *)(param_1 + 0x2c) != 0) {
      _selwakeup(*(int *)(param_1 + 0x2c),*(uint *)(param_1 + 0x40) & 0x1000);
      _selthreadclear(param_1 + 0x2c);
      *(uint *)(param_1 + 0x40) = *(uint *)(param_1 + 0x40) & 0xffffefff;
    }
  }
  return 0;
}

