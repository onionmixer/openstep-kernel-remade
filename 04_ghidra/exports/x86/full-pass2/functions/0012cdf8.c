/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0012cdf8 */

undefined4 _makefh(undefined4 *param_1,int param_2,int param_3)

{
  ushort uVar1;
  int iVar2;
  undefined4 uVar3;
  ushort *local_8;
  
  iVar2 = (**(code **)(*(int *)(param_2 + 0x1c) + 100))(param_2,&local_8);
  if ((iVar2 == 0) && (local_8 != (ushort *)0x0)) {
    if (**(ushort **)(param_3 + 0x28) + 8 + (uint)*local_8 < 0x21) {
      _bzero(param_1,0x20);
      *param_1 = *(undefined4 *)(*(int *)(param_2 + 0x24) + 0x14);
      param_1[1] = *(undefined4 *)(*(int *)(param_2 + 0x24) + 0x18);
      *(ushort *)(param_1 + 2) = *local_8;
      _bcopy(local_8 + 1,(void *)((int)param_1 + 10),(uint)*local_8);
      uVar1 = **(ushort **)(param_3 + 0x28);
      *(ushort *)(param_1 + 5) = uVar1;
      _bcopy((void *)(*(int *)(param_3 + 0x28) + 2),(void *)((int)param_1 + 0x16),(uint)uVar1);
      _kfree(local_8,*local_8 + 2);
      uVar3 = 0;
    }
    else {
      _kfree(local_8,*local_8 + 2);
      uVar3 = 0x47;
    }
  }
  else {
    uVar3 = 0x47;
  }
  return uVar3;
}

