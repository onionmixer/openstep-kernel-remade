/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00107e60 */

void __setuid(void)

{
  short sVar1;
  short sVar2;
  short sVar3;
  int iVar4;
  int iVar5;
  short sVar6;
  short sVar7;
  
  sVar1 = *(short *)(_active_u[7] + 6);
  sVar2 = **(short **)(DAT_001e875c + 0x24);
  iVar4 = _get_posix_proc((int)*(short *)(*_active_u + 0x30));
  if (sVar2 < 0) {
    *(undefined1 *)(DAT_001e875c + 0x68) = 0x16;
  }
  else {
    sVar3 = *(short *)(iVar4 + 6);
    iVar5 = _suser();
    sVar7 = sVar2;
    sVar6 = sVar2;
    if (((iVar5 == 0) && (sVar7 = sVar1, sVar6 = sVar3, sVar2 != sVar1)) && (sVar2 != sVar3)) {
      *(undefined1 *)(DAT_001e875c + 0x68) = 1;
    }
    else {
      *(undefined1 *)(DAT_001e875c + 0x68) = 0;
      _lock_write(_active_u + 8);
      iVar5 = _crcopy(_active_u[7]);
      _active_u[7] = iVar5;
      iVar5 = _active_u[7];
      *(short *)(iVar4 + 4) = sVar7;
      *(short *)(iVar5 + 6) = sVar7;
      iVar5 = *_active_u;
      *(short *)(_active_u[7] + 2) = sVar2;
      *(short *)(iVar5 + 0x2c) = sVar2;
      _lock_done(_active_u + 8);
      *(short *)(iVar4 + 6) = sVar6;
    }
  }
  return;
}

