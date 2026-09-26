
void sub_408462A(uint *param_1,uint param_2,int param_3,uint param_4,uint param_5,uint param_6,
                undefined4 *param_7)

{
  undefined4 *puVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  word wVar5;
  sword sVar6;
  
  uVar3 = _pmap_kernel();
  param_3 = param_3 + -1;
  if (param_3 != -1) {
    do {
      *param_1 = param_2;
      param_1[1] = param_4;
      param_1[2] = param_6;
      param_1[10] = param_5;
      iVar4 = _pmap_resident_extract(uVar3,param_2 & ~_page_mask);
      uVar2 = param_2 % _page_size + iVar4;
      param_1[4] = uVar2;
      param_1[5] = param_4 + uVar2;
      param_1[9] = (uint)param_1;
      puVar1 = (undefined4 *)param_7[1];
      if (puVar1 == param_7) {
        *param_7 = param_1;
      }
      else {
        puVar1[0xb] = param_1;
      }
      param_1[0xc] = (uint)puVar1;
      param_1[0xb] = (uint)param_7;
      param_7[1] = param_1;
      param_1 = param_1 + 0xe;
      param_2 = param_4 + param_2;
      wVar5 = (word)((uint)param_3 >> 0x10);
      sVar6 = (sword)param_3 + -1;
      param_3 = CONCAT22(wVar5,sVar6);
    } while ((sVar6 != -1) || (param_3 = (uint)wVar5 * 0x10000 + -1, wVar5 != 0));
  }
  return;
}

