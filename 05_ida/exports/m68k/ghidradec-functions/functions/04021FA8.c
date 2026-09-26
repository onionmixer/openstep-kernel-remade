
undefined4 * _ip_insertoptions(undefined4 *param_1,int param_2,int *param_3)

{
  int iVar1;
  uint uVar2;
  sword *psVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  sword sVar7;
  int iVar8;
  int iVar9;
  int *piVar10;
  
  piVar10 = (int *)(*(int *)(param_2 + 4) + param_2);
  iVar9 = param_1[1] + (int)param_1;
  iVar8 = (int)*(sword *)(param_2 + 8);
  iVar4 = iVar8 + -4;
  iVar1 = *piVar10;
  if (iVar1 != 0) {
    *(int *)(iVar9 + 0x10) = iVar1;
  }
  puVar6 = _mfree;
  uVar2 = param_1[1];
  sVar7 = (sword)iVar4;
  if ((uVar2 < 0x7c) && (iVar8 + 8U <= uVar2)) {
    param_1[1] = uVar2 - iVar4;
    *(sword *)(param_1 + 2) = sVar7 + *(sword *)(param_1 + 2);
    _ovbcopy(iVar9,param_1[1] + (int)param_1,0x14);
  }
  else {
    if (_mfree == (undefined4 *)0x0) {
      puVar6 = (undefined4 *)_m_more(0,2);
    }
    else {
      if (*(sword *)((int)_mfree + 10) != 0) {
                    /* WARNING: Subroutine does not return */
        _panic(&aMget);
      }
      *(undefined2 *)((int)_mfree + 10) = 2;
      word_40B61CC = word_40B61CC + -1;
      word_40B61D0 = word_40B61D0 + 1;
      puVar5 = (undefined4 *)*_mfree;
      *_mfree = 0;
      _mfree = puVar5;
      puVar6[1] = 0xc;
    }
    if (puVar6 == (undefined4 *)0x0) {
      return param_1;
    }
    *(sword *)(param_1 + 2) = *(sword *)(param_1 + 2) + -0x14;
    param_1[1] = param_1[1] + 0x14;
    *puVar6 = param_1;
    puVar6[1] = 0x68 - iVar4;
    *(sword *)(puVar6 + 2) = sVar7 + 0x14;
    _bcopy(iVar9,puVar6[1] + (int)puVar6,0x14);
    param_1 = puVar6;
  }
  iVar1 = param_1[1];
  _bcopy(piVar10 + 1,(int)param_1 + iVar1 + 0x14,iVar4);
  *param_3 = iVar8 + 0x10;
  psVar3 = (sword *)((int)param_1 + iVar1 + 2);
  *psVar3 = sVar7 + *psVar3;
  return param_1;
}
