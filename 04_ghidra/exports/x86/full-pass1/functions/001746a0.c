/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001746a0 */

int _vm_map_create(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  
  iVar2 = _zalloc(_vm_map_zone);
  if (iVar2 == 0) {
                    /* WARNING: Subroutine does not return */
    _panic(s_vm_map_create_001e0aa2);
  }
  iVar1 = iVar2 + 0xc;
  *(int *)(iVar2 + 0x10) = iVar1;
  *(int *)(iVar2 + 0xc) = iVar1;
  *(undefined4 *)(iVar2 + 0x1c) = 0;
  *(undefined4 *)(iVar2 + 0x20) = param_4;
  *(undefined4 *)(iVar2 + 0x28) = 0;
  *(undefined4 *)(iVar2 + 0x30) = 1;
  *(undefined4 *)(iVar2 + 0x24) = param_1;
  *(undefined4 *)(iVar2 + 0x2c) = 1;
  *(undefined4 *)(iVar2 + 0x14) = param_2;
  *(undefined4 *)(iVar2 + 0x18) = param_3;
  *(undefined4 *)(iVar2 + 0x48) = 0;
  *(undefined4 *)(iVar2 + 0x44) = 0;
  *(int *)(iVar2 + 0x40) = iVar1;
  *(int *)(iVar2 + 0x38) = iVar1;
  *(undefined4 *)(iVar2 + 0x4c) = 0;
  _lock_init(iVar2,1);
  *(undefined4 *)(iVar2 + 0x4c) = 0;
  *(undefined4 *)(iVar2 + 0x34) = 0;
  *(undefined4 *)(iVar2 + 0x3c) = 0;
  return iVar2;
}

