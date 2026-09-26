
int _in_bootp_initnet(int param_1,int param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  undefined2 *puVar3;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  iVar1 = _socreate(2,param_3,2,0);
  if (iVar1 == 0) {
    if ((*(word *)(param_1 + 0xc) & 1) == 0) {
      *(word *)(param_2 + 0x10) = *(word *)(param_1 + 0xc) | 1;
      iVar1 = _ifioctl(*param_3,0x80206910,param_2);
      if (iVar1 != 0) {
        return iVar1;
      }
    }
    else if (*(sword *)(param_1 + 0xc) < 0) {
      iVar1 = _ifioctl(*param_3,0xc020690d,param_2);
      if (iVar1 != 0) {
        return iVar1;
      }
      *(word *)(param_1 + 0xc) = *(word *)(param_1 + 0xc) & 0xbfff;
      return -1;
    }
    *(word *)(param_1 + 0xc) = *(word *)(param_1 + 0xc) | 0x4000;
    _bzero(&uStack_14,0x10);
    uStack_14 = CONCAT22(2,uStack_14._2_2_);
    *(undefined4 *)(param_2 + 0x10) = uStack_14;
    *(undefined4 *)(param_2 + 0x14) = uStack_10;
    *(undefined4 *)(param_2 + 0x18) = uStack_c;
    *(undefined4 *)(param_2 + 0x1c) = uStack_8;
    iVar1 = _ifioctl(*param_3,0x8020690c,param_2);
    if (iVar1 == 0) {
      iVar2 = _m_get(1,8);
      if (iVar2 == 0) {
        iVar1 = 0x37;
      }
      else {
        *(undefined2 *)(iVar2 + 8) = 0x10;
        puVar3 = (undefined2 *)(*(int *)(iVar2 + 4) + iVar2);
        *puVar3 = 2;
        puVar3[1] = 0x44;
        *(undefined4 *)(puVar3 + 2) = 0;
        iVar1 = _sobind(*param_3,iVar2);
        _m_freem(iVar2);
        if (iVar1 == 0) {
          *(word *)(*param_3 + 6) = *(word *)(*param_3 + 6) | 0x100;
          iVar1 = 0;
        }
      }
    }
  }
  else {
    *param_3 = 0;
  }
  return iVar1;
}

