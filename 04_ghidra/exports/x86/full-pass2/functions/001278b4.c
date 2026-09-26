/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001278b4 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * _ip_insertoptions(undefined4 *param_1,int param_2,int *param_3)

{
  size_t sVar1;
  short *psVar2;
  int iVar3;
  uint uVar4;
  undefined4 *puVar5;
  int iVar6;
  undefined4 uVar7;
  undefined4 *puVar8;
  int *piVar9;
  void *pvVar10;
  short local_c;
  
  piVar9 = (int *)(param_2 + *(int *)(param_2 + 4));
  pvVar10 = (void *)((int)param_1 + param_1[1]);
  iVar6 = (int)*(short *)(param_2 + 8);
  sVar1 = iVar6 - 4;
  iVar3 = *piVar9;
  if (iVar3 != 0) {
    *(int *)((int)pvVar10 + 0x10) = iVar3;
  }
  uVar4 = param_1[1];
  local_c = (short)sVar1;
  if ((uVar4 < 0x7c) && (iVar6 + 8U <= uVar4)) {
    param_1[1] = uVar4 - sVar1;
    *(short *)(param_1 + 2) = *(short *)(param_1 + 2) + local_c;
    _ovbcopy(pvVar10,(int)param_1 + param_1[1],0x14);
  }
  else {
    uVar7 = _splimp();
    puVar8 = _mfree;
    if (_mfree == (undefined4 *)0x0) {
      puVar8 = (undefined4 *)_m_more(0,2);
    }
    else {
      if (*(short *)((int)_mfree + 10) != 0) {
                    /* WARNING: Subroutine does not return */
        _panic(&DAT_001dbe10);
      }
      *(undefined2 *)((int)_mfree + 10) = 2;
      _DAT_001e917c = _DAT_001e917c + -1;
      _DAT_001e9180 = _DAT_001e9180 + 1;
      puVar5 = (undefined4 *)*_mfree;
      *_mfree = 0;
      _mfree = puVar5;
      puVar8[1] = 0xc;
    }
    _splx(uVar7);
    if (puVar8 == (undefined4 *)0x0) {
      return param_1;
    }
    *(short *)(param_1 + 2) = *(short *)(param_1 + 2) + -0x14;
    param_1[1] = param_1[1] + 0x14;
    *puVar8 = param_1;
    puVar8[1] = 0x68 - sVar1;
    *(short *)(puVar8 + 2) = local_c + 0x14;
    _bcopy(pvVar10,(void *)((int)puVar8 + puVar8[1]),0x14);
    param_1 = puVar8;
  }
  iVar3 = param_1[1];
  _bcopy(piVar9 + 1,(void *)((int)param_1 + iVar3 + 0x14),sVar1);
  *param_3 = iVar6 + 0x10;
  psVar2 = (short *)((int)param_1 + iVar3 + 2);
  *psVar2 = *psVar2 + local_c;
  return param_1;
}

