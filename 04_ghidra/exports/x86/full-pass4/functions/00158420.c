/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00158420 */

undefined4 _ipc_kobject_notify(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar1 = *(int *)(param_1 + 8);
  *(undefined4 *)(param_2 + 0x1c) = 0xfffffecf;
  iVar2 = *(int *)(param_1 + 0x14);
  if ((0x40 < iVar2) && ((iVar2 < 0x43 || ((iVar2 < 0x49 && (0x44 < iVar2)))))) {
    if (*(short *)(iVar1 + 8) == 0xc) {
      uVar3 = _ds_notify(param_1);
      return uVar3;
    }
    return 0;
  }
  return 0;
}

