
undefined4
_pmap_kgetport(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  word wVar1;
  int iVar2;
  sword sVar4;
  int *piVar3;
  undefined4 uVar5;
  undefined2 *puVar6;
  sword sStack_26;
  undefined2 uStack_24;
  undefined2 uStack_22;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  sStack_26 = 0;
  uVar5 = 0;
  if (word_40B356C == 0) {
    iVar2 = 0xf;
    puVar6 = &unk_40B3594;
    do {
      do {
        *puVar6 = 0xffff;
        puVar6 = puVar6 + -1;
        wVar1 = (word)((uint)iVar2 >> 0x10);
        sVar4 = (sword)iVar2 + -1;
        iVar2 = CONCAT22(wVar1,sVar4);
      } while (sVar4 != -1);
      iVar2 = (uint)wVar1 * 0x10000 + -1;
    } while (wVar1 != 0);
    word_40B356C = word_40B356C + 1;
  }
  uStack_20 = param_1[1];
  uStack_1c = param_1[2];
  uStack_18 = param_1[3];
  _uStack_24 = CONCAT22((sword)((uint)*param_1 >> 0x10),0x6f);
  piVar3 = (int *)_clntkudp_create(&uStack_24,100000,2,4,&word_40B356C);
  if (piVar3 != (int *)0x0) {
    uStack_14 = param_2;
    uStack_10 = param_3;
    uStack_c = param_4;
    uStack_8 = 0;
    iVar2 = (**(code **)piVar3[1])
                      (piVar3,3,_xdr_pmap,&uStack_14,_xdr_u_short,&sStack_26,dword_40AF01E,
                       dword_40AF022);
    if (iVar2 == 0) {
      if (sStack_26 == 0) {
        uVar5 = 0xffffffff;
      }
      else {
        *(sword *)((int)param_1 + 2) = sStack_26;
      }
    }
    else {
      uVar5 = 1;
    }
    (**(code **)(*(int *)(*piVar3 + 0x20) + 0x10))(*piVar3);
    (**(code **)(piVar3[1] + 0x10))(piVar3);
  }
  return uVar5;
}
