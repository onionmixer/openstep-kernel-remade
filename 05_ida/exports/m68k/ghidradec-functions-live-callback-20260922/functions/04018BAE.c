
undefined4 * sub_4018BAE(int param_1,char *param_2,int param_3,int param_4,int param_5)

{
  undefined4 *puVar1;
  int iVar2;
  
  puVar1 = (undefined4 *)(&_nc_hash)[param_4 * 2];
  do {
    if (&_nc_hash + param_4 * 2 == puVar1) {
      return (undefined4 *)0x0;
    }
    if ((((param_1 == puVar1[5]) && (param_3 == *(char *)(puVar1 + 6))) &&
        (*(char *)((int)puVar1 + 0x19) == *param_2)) &&
       (iVar2 = _bcmp((int)puVar1 + 0x19,param_2,param_3), iVar2 == 0)) {
      if (param_5 == -1) {
        return puVar1;
      }
      iVar2 = *(int *)((int)puVar1 + 0x3a);
      if (param_5 == iVar2) {
        return puVar1;
      }
      if (((*(sword *)(iVar2 + 2) == *(sword *)(param_5 + 2)) &&
          (*(sword *)(iVar2 + 4) == *(sword *)(param_5 + 4))) &&
         (iVar2 = _bcmp(param_5 + 10,iVar2 + 10,0x20), iVar2 == 0)) {
        return puVar1;
      }
    }
    puVar1 = (undefined4 *)*puVar1;
  } while( true );
}

