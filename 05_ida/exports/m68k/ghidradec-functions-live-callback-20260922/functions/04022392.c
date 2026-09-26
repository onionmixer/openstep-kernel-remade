
undefined4 _ip_setmoptions(undefined4 param_1,int *param_2,int param_3)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  undefined4 *puVar6;
  int *piVar7;
  uint *puVar8;
  int iStack_18;
  undefined2 uStack_14;
  uint uStack_10;
  
  iVar2 = _mfree;
  uVar4 = 0;
  if (*param_2 == 0) {
    *param_2 = _mfree;
    if (iVar2 == 0) {
      iVar2 = _m_more(1,0xe);
      *param_2 = iVar2;
    }
    else {
      if (*(sword *)(iVar2 + 10) != 0) {
                    /* WARNING: Subroutine does not return */
        _panic(&aMget);
      }
      *(undefined2 *)(*param_2 + 10) = 0xe;
      word_40B61CC = word_40B61CC + -1;
      word_40B61E8 = word_40B61E8 + 1;
      _mfree = *(int *)*param_2;
      *(undefined4 *)*param_2 = 0;
      *(undefined4 *)(*param_2 + 4) = 0xc;
    }
    iVar2 = *param_2;
    if (iVar2 == 0) {
      return 0x37;
    }
    puVar6 = (undefined4 *)(*(int *)(iVar2 + 4) + iVar2);
    *puVar6 = 0;
    *(undefined *)(puVar6 + 1) = 1;
    *(undefined *)((int)puVar6 + 5) = 1;
    *(undefined2 *)((int)puVar6 + 6) = 0;
  }
  piVar7 = (int *)(*(int *)(*param_2 + 4) + *param_2);
  switch(param_1) {
  case :
    if ((param_3 != 0) && (*(sword *)(param_3 + 8) == 4)) {
      iVar2 = *(int *)(param_3 + *(int *)(param_3 + 4));
      iVar3 = _in_ifaddr;
      if (iVar2 == 0) {
        *piVar7 = 0;
        goto loc_40226AE;
      }
      for (; (iVar3 != 0 && (iVar2 != *(int *)(iVar3 + 4))); iVar3 = *(int *)(iVar3 + 0x40)) {
      }
      iVar2 = 0;
      if (iVar3 != 0) {
        iVar2 = *(int *)(iVar3 + 0x20);
      }
      if (iVar2 != 0) {
        *piVar7 = iVar2;
        goto loc_40226AE;
      }
loc_4022678:
      uVar4 = 0x31;
      goto loc_40226AE;
    }
    break;
  case :
    if ((param_3 != 0) && (*(sword *)(param_3 + 8) == 1)) {
      *(undefined *)(piVar7 + 1) = *(undefined *)(param_3 + *(int *)(param_3 + 4));
      goto loc_40226AE;
    }
    break;
  case :
    if (((param_3 != 0) && (*(sword *)(param_3 + 8) == 1)) &&
       (bVar1 = *(byte *)(param_3 + *(int *)(param_3 + 4)), bVar1 < 2)) {
      *(byte *)((int)piVar7 + 5) = bVar1;
      goto loc_40226AE;
    }
    break;
  case :
    if (((param_3 != 0) && (*(sword *)(param_3 + 8) == 8)) &&
       (puVar8 = (uint *)(*(int *)(param_3 + 4) + param_3), (*puVar8 & 0xf0000000) == 0xe0000000)) {
      iVar2 = _in_ifaddr;
      if (puVar8[1] == 0) {
        iStack_18 = 0;
        uStack_14 = 2;
        uStack_10 = *puVar8;
        _rtalloc(&iStack_18);
        if (iStack_18 == 0) goto loc_4022678;
        uVar5 = *(uint *)(iStack_18 + 0x2c);
        _rtfree(iStack_18);
      }
      else {
        for (; (iVar2 != 0 && (puVar8[1] != *(uint *)(iVar2 + 4))); iVar2 = *(int *)(iVar2 + 0x40))
        {
        }
        uVar5 = 0;
        if (iVar2 != 0) {
          uVar5 = *(uint *)(iVar2 + 0x20);
        }
      }
      if (uVar5 != 0) {
        iVar2 = 0;
        if (*(word *)((int)piVar7 + 6) != 0) {
          do {
            if ((uVar5 == ((uint *)piVar7[iVar2 + 2])[1]) && (*(uint *)piVar7[iVar2 + 2] == *puVar8)
               ) break;
            iVar2 = iVar2 + 1;
          } while (iVar2 < (int)(uint)*(word *)((int)piVar7 + 6));
          if (iVar2 < (int)(uint)*(word *)((int)piVar7 + 6)) {
            uVar4 = 0x30;
            goto loc_40226AE;
          }
        }
        if (iVar2 == 0x14) {
          uVar4 = 0x3b;
        }
        else {
          iVar3 = _in_addmulti(*puVar8,uVar5);
          piVar7[iVar2 + 2] = iVar3;
          if (iVar3 == 0) {
            uVar4 = 0x37;
          }
          else {
            *(sword *)((int)piVar7 + 6) = *(sword *)((int)piVar7 + 6) + 1;
          }
        }
        goto loc_40226AE;
      }
      goto loc_4022678;
    }
    break;
  case :
    if (((param_3 != 0) && (*(sword *)(param_3 + 8) == 8)) &&
       (puVar8 = (uint *)(*(int *)(param_3 + 4) + param_3), (*puVar8 & 0xf0000000) == 0xe0000000)) {
      iVar2 = _in_ifaddr;
      if (puVar8[1] == 0) {
        iVar3 = 0;
      }
      else {
        for (; (iVar2 != 0 && (puVar8[1] != *(uint *)(iVar2 + 4))); iVar2 = *(int *)(iVar2 + 0x40))
        {
        }
        iVar3 = 0;
        if (iVar2 != 0) {
          iVar3 = *(int *)(iVar2 + 0x20);
        }
        if (iVar3 == 0) goto loc_4022678;
      }
      uVar5 = 0;
      if (*(word *)((int)piVar7 + 6) != 0) {
        do {
          if (((iVar3 == 0) || (iVar3 == *(int *)(piVar7[uVar5 + 2] + 4))) &&
             (*(uint *)piVar7[uVar5 + 2] == *puVar8)) break;
          uVar5 = uVar5 + 1;
        } while ((int)uVar5 < (int)(uint)*(word *)((int)piVar7 + 6));
      }
      if (*(word *)((int)piVar7 + 6) != uVar5) {
        _in_delmulti(piVar7[uVar5 + 2]);
        iVar2 = uVar5 + 1;
        if (iVar2 < (int)(uint)*(word *)((int)piVar7 + 6)) {
          do {
            piVar7[iVar2 + 1] = piVar7[iVar2 + 2];
            iVar2 = iVar2 + 1;
          } while (iVar2 < (int)(uint)*(word *)((int)piVar7 + 6));
        }
        *(sword *)((int)piVar7 + 6) = *(sword *)((int)piVar7 + 6) + -1;
        goto loc_40226AE;
      }
      goto loc_4022678;
    }
    break;
  :
    uVar4 = 0x2d;
    goto loc_40226AE;
  }
  uVar4 = 0x16;
loc_40226AE:
  if ((*piVar7 == 0) && (piVar7[1] == 0x1010000)) {
    _m_free(*param_2);
    *param_2 = 0;
  }
  return uVar4;
}

