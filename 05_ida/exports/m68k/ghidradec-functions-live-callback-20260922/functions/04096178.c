
int _rdmem(uint *param_1,int param_2,uint *param_3)

{
  int iVar1;
  
  iVar1 = _dbg_setjmp(unk_40B55CC);
  if (iVar1 == 0) {
    dword_40B5610 = unk_40B55CC;
    sub_409630E();
    if (param_2 == 2) {
      *param_3 = (int)*(sword *)param_1;
      *param_3 = *param_3 & 0xffff;
    }
    else if (param_2 < 3) {
      if (param_2 != 1) {
loc_409622C:
        dword_40B5610 = (undefined *)0x0;
                    /* WARNING: Subroutine does not return */
        _dbg_panic(aRdmemBadSize);
      }
      *param_3 = (int)*(char *)param_1;
      *param_3 = *param_3 & 0xff;
    }
    else {
      if (param_2 != 4) goto loc_409622C;
      *param_3 = *param_1;
    }
    sub_4096358();
    dword_40B5610 = (undefined *)0x0;
    iVar1 = 0;
  }
  else {
    sub_4096358();
  }
  return iVar1;
}

