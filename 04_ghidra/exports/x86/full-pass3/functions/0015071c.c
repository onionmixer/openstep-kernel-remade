/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0015071c */

undefined4 _ipc_space_create(uint *param_1,undefined4 *param_2)

{
  uint uVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  void *pvVar4;
  undefined4 *puVar5;
  uint uVar6;
  
  puVar2 = (undefined4 *)_zalloc(_ipc_space_zone);
  if (puVar2 == (undefined4 *)0x0) {
    uVar3 = 6;
  }
  else {
    pvVar4 = (void *)_ipc_table_alloc(*param_1 << 4);
    if (pvVar4 == (void *)0x0) {
      _zfree(_ipc_space_zone,puVar2);
      uVar3 = 6;
    }
    else {
      uVar1 = *param_1;
      _bzero(pvVar4,uVar1 << 4);
      uVar6 = 0;
      if (uVar1 != 0) {
        do {
          puVar5 = (undefined4 *)(uVar6 * 0x10 + (int)pvVar4);
          *puVar5 = 0xff000000;
          uVar6 = uVar6 + 1;
          puVar5[2] = uVar6;
        } while (uVar6 < uVar1);
      }
      *(undefined4 *)((int)pvVar4 + uVar1 * 0x10 + -8) = 0;
      *puVar2 = 0;
      puVar2[1] = 2;
      puVar2[2] = 0;
      puVar2[3] = 1;
      puVar2[4] = 0;
      puVar2[5] = pvVar4;
      puVar2[6] = uVar1;
      puVar2[7] = param_1 + 1;
      _ipc_splay_tree_init(puVar2 + 8);
      puVar2[0xe] = 0;
      puVar2[0xf] = 0;
      puVar2[0x10] = 0;
      puVar2[0x11] = 0;
      *param_2 = puVar2;
      uVar3 = 0;
    }
  }
  return uVar3;
}

