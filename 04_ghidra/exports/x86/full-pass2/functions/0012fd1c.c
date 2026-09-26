/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0012fd1c */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 _rlock_timeout(uint param_1,int param_2)

{
  ushort uVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  code *pcVar6;
  uint uVar7;
  
  while( true ) {
    uVar1 = *(ushort *)(param_1 + 0x60);
    if (((uVar1 & 1) == 0) || (*(int *)(param_1 + 0x68) == _active_threads)) {
      *(int *)(param_1 + 0x68) = _active_threads;
      *(short *)(param_1 + 0x6c) = *(short *)(param_1 + 0x6c) + 1;
      *(byte *)(param_1 + 0x60) = *(byte *)(param_1 + 0x60) | 1;
      return 0;
    }
    if ((uVar1 & 0x20) != 0) {
      __rlockretimeout = __rlockretimeout + 1;
      return 1;
    }
    *(ushort *)(param_1 + 0x60) = uVar1 | 2;
    uVar2 = _splhigh();
    iVar3 = param_2 * _hz;
    pcVar6 = FUN_0012fdd0;
    uVar7 = param_1;
    _timeout(0x12fdd0);
    uVar5 = 10;
    uVar4 = param_1;
    _sleep(param_1);
    iVar3 = _untimeout(FUN_0012fdd0,param_1,uVar4,uVar5,pcVar6,uVar7,iVar3);
    if (iVar3 == 0) break;
    _splx(uVar2);
  }
  __rlocktimeout = __rlocktimeout + 1;
  *(byte *)(param_1 + 0x60) = *(byte *)(param_1 + 0x60) | 0x20;
  _splx(uVar2);
  return 1;
}

