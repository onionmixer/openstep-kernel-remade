/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001397b0 */

int _makespecvp(short param_1,int param_2)

{
  void *pvVar1;
  undefined4 uVar2;
  
  while( true ) {
    pvVar1 = (void *)FUN_00139a30((int)param_1,0,param_2);
    if (pvVar1 == (void *)0x0) break;
    if ((*(ushort *)((int)pvVar1 + 0x40) & 1) == 0) goto LAB_00139850;
    *(ushort *)((int)pvVar1 + 0x40) = *(ushort *)((int)pvVar1 + 0x40) | 0x10;
    _sleep((uint)pvVar1);
  }
  pvVar1 = (void *)_kalloc(0x68);
  _bzero(pvVar1,0x68);
  *(undefined ***)((int)pvVar1 + 0x20) = &_spec_vnodeops;
  *(int *)((int)pvVar1 + 0x2c) = param_2;
  if (param_2 == 3) {
    uVar2 = _specvp(0,(int)param_1,3);
    *(undefined4 *)((int)pvVar1 + 0x3c) = uVar2;
  }
  *(undefined4 *)((int)pvVar1 + 0x38) = 0;
  *(short *)((int)pvVar1 + 0x42) = param_1;
  *(short *)((int)pvVar1 + 0x30) = param_1;
  *(undefined2 *)((int)pvVar1 + 10) = 1;
  *(void **)((int)pvVar1 + 0x34) = pvVar1;
  *(undefined4 *)((int)pvVar1 + 0x28) = 0;
  FUN_00139860(pvVar1);
LAB_00139850:
  return (int)pvVar1 + 4;
}

