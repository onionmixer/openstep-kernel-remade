
undefined4 _sbappendaddr(word *param_1,undefined4 *param_2,undefined4 *param_3,int param_4)

{
  word wVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  undefined4 *puVar6;
  
  piVar4 = _mfree;
  iVar5 = 0x10;
  for (puVar6 = param_3; puVar6 != (undefined4 *)0x0; puVar6 = (undefined4 *)*puVar6) {
    iVar5 = *(sword *)(puVar6 + 2) + iVar5;
  }
  if (param_4 != 0) {
    iVar5 = *(sword *)(param_4 + 8) + iVar5;
  }
  iVar3 = (uint)param_1[1] - (uint)*param_1;
  if ((int)((uint)param_1[3] - (uint)param_1[2]) < (int)((uint)param_1[1] - (uint)*param_1)) {
    iVar3 = (uint)param_1[3] - (uint)param_1[2];
  }
  if (iVar5 <= iVar3) {
    if (_mfree == (int *)0x0) {
      piVar4 = (int *)_m_more(0,8);
    }
    else {
      if (*(sword *)((int)_mfree + 10) != 0) {
                    /* WARNING: Subroutine does not return */
        _panic(&aMget);
      }
      *(undefined2 *)((int)_mfree + 10) = 8;
      word_40B61CC = word_40B61CC + -1;
      word_40B61DC = word_40B61DC + 1;
      piVar2 = (int *)*_mfree;
      *_mfree = 0;
      _mfree = piVar2;
      piVar4[1] = 0xc;
    }
    if (piVar4 != (int *)0x0) {
      puVar6 = (undefined4 *)(piVar4[1] + (int)piVar4);
      *puVar6 = *param_2;
      puVar6[1] = param_2[1];
      puVar6[2] = param_2[2];
      puVar6[3] = param_2[3];
      *(undefined2 *)(piVar4 + 2) = 0x10;
      if ((param_4 != 0) && (*(sword *)(param_4 + 8) != 0)) {
        iVar5 = _m_copy(param_4,0,(int)*(sword *)(param_4 + 8));
        *piVar4 = iVar5;
        if (iVar5 == 0) {
          _m_freem(piVar4);
          return 0;
        }
        *param_1 = *(sword *)(iVar5 + 8) + *param_1;
        wVar1 = param_1[2];
        param_1[2] = wVar1 + 0x80;
        if (0x7c < *(uint *)(*piVar4 + 4)) {
          param_1[2] = wVar1 + 0x480;
        }
      }
      *param_1 = *(sword *)(piVar4 + 2) + *param_1;
      wVar1 = param_1[2];
      param_1[2] = wVar1 + 0x80;
      if (0x7c < (uint)piVar4[1]) {
        param_1[2] = wVar1 + 0x480;
      }
      iVar5 = *(int *)(param_1 + 6);
      if (iVar5 == 0) {
        *(int **)(param_1 + 6) = piVar4;
      }
      else {
        iVar3 = *(int *)(iVar5 + 0x7c);
        while (iVar3 != 0) {
          iVar5 = *(int *)(iVar5 + 0x7c);
          iVar3 = *(int *)(iVar5 + 0x7c);
        }
        *(int **)(iVar5 + 0x7c) = piVar4;
      }
      if ((int *)*piVar4 != (int *)0x0) {
        piVar4 = (int *)*piVar4;
      }
      if (param_3 != (undefined4 *)0x0) {
        _sbcompress(param_1,param_3,piVar4);
      }
      return 1;
    }
  }
  return 0;
}
