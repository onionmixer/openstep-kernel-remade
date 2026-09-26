
undefined4 _xdrmbuf_getmbuf(int param_1,undefined4 *param_2,uint *param_3)

{
  undefined4 *puVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = _xdr_u_int(param_1,param_3);
  if (iVar2 != 0) {
    puVar1 = *(undefined4 **)(param_1 + 0x10);
    iVar2 = (int)*(sword *)(puVar1 + 2) - *(int *)(param_1 + 0x14);
    puVar1[1] = iVar2 + puVar1[1];
    *(sword *)(puVar1 + 2) = *(sword *)(puVar1 + 2) - (sword)iVar2;
    *param_2 = puVar1;
    uVar3 = 0;
    for (; puVar1 != (undefined4 *)0x0; puVar1 = (undefined4 *)*puVar1) {
      uVar3 = (int)*(sword *)(puVar1 + 2) + uVar3;
    }
    if (*param_3 <= uVar3) {
      return 1;
    }
    _printf(aXdrmbufGetmbuf);
  }
  return 0;
}

