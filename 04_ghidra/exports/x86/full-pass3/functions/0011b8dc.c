/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0011b8dc */

undefined4 * FUN_0011b8dc(int param_1,char *param_2,size_t param_3,int param_4,int param_5)

{
  undefined4 *puVar1;
  int iVar2;
  
  puVar1 = (undefined4 *)(&_nc_hash)[param_4 * 2];
  do {
    if (puVar1 == &_nc_hash + param_4 * 2) {
      return (undefined4 *)0x0;
    }
    if ((((puVar1[5] == param_1) && (param_3 == (int)*(char *)(puVar1 + 6))) &&
        (*(char *)((int)puVar1 + 0x19) == *param_2)) &&
       (iVar2 = _bcmp((void *)((int)puVar1 + 0x19),param_2,param_3), iVar2 == 0)) {
      if (param_5 == -1) {
        return puVar1;
      }
      iVar2 = puVar1[0xf];
      if (iVar2 == param_5) {
        return puVar1;
      }
      if (((*(short *)(param_5 + 2) == *(short *)(iVar2 + 2)) &&
          (*(short *)(param_5 + 4) == *(short *)(iVar2 + 4))) &&
         (iVar2 = _bcmp((void *)(param_5 + 10),(void *)(iVar2 + 10),0x20), iVar2 == 0)) {
        return puVar1;
      }
    }
    puVar1 = (undefined4 *)*puVar1;
  } while( true );
}

