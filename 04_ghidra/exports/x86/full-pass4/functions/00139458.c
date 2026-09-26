/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00139458 */

undefined4 FUN_00139458(undefined4 *param_1)

{
  ushort uVar1;
  undefined4 *puVar2;
  undefined4 local_8;
  
  if (_fifo_alloc < DAT_001de6b8) {
    _fifo_alloc = _fifo_alloc + DAT_001de6b4;
    _kmem_alloc_wired(_kernel_map,&local_8,DAT_001de6b4);
    *(short *)((int)param_1 + 0x8a) = *(short *)((int)param_1 + 0x8a) + 1;
  }
  else {
    uVar1 = *(ushort *)(param_1 + 0x10);
    *(ushort *)(param_1 + 0x10) = uVar1 & 0xfffe;
    if ((uVar1 & 0x10) != 0) {
      *(ushort *)(param_1 + 0x10) = uVar1 & 0xffee;
      _wakeup(param_1);
    }
    puVar2 = &_fifo_alloc;
    while( true ) {
      _sleep((uint)puVar2);
      if ((*(ushort *)(param_1 + 0x10) & 1) == 0) break;
      *(ushort *)(param_1 + 0x10) = *(ushort *)(param_1 + 0x10) | 0x10;
      puVar2 = param_1;
    }
    *(byte *)(param_1 + 0x10) = *(byte *)(param_1 + 0x10) | 1;
    local_8 = 0;
  }
  return local_8;
}

