
undefined4 sub_4036A22(undefined4 param_1,int param_2,uint param_3,undefined4 param_4)

{
  word wVar1;
  word wVar2;
  int iVar3;
  
  wVar1 = *(word *)(param_2 + 4);
  if (((wVar1 & 3) == 0) && ((int)(uint)wVar1 <= (int)(0x400 - (param_3 & 0x3ff)))) {
    wVar2 = *(word *)(param_2 + 6);
    if ((((wVar2 + 4 & 0xfffffffc) + 8 <= (uint)wVar1) && (wVar2 < 0x100)) &&
       ((_dirchk == 0 || (iVar3 = sub_4036ADA(param_2 + 8,(uint)wVar2), iVar3 == 0)))) {
      return 0;
    }
  }
  sub_4036AAC(param_1,aMangledEntry_0,param_4);
  return 1;
}

