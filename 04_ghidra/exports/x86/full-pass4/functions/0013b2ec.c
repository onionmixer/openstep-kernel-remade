/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0013b2ec */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_0013b2ec(int param_1,undefined4 param_2,undefined4 param_3)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  undefined1 local_14 [4];
  undefined1 local_10 [4];
  int local_c;
  undefined4 local_8;
  
  if (_maxswapdevice < 1) {
    iVar3 = _copyin(param_3,&local_8,4);
    if (iVar3 == 0) {
      iVar3 = _getvnodefp(local_8,&local_c);
      if (iVar3 == 0) {
        piVar1 = *(int **)(local_c + 0x18);
        if (piVar1[10] == 1) {
          *(short *)((int)piVar1 + 6) = *(short *)((int)piVar1 + 6) + 1;
          iVar3 = _kalloc(_page_size * 3);
          iVar7 = iVar3 + _page_size;
          iVar8 = iVar7 + _page_size;
          piVar4 = (int *)_kalloc(0x7c);
          _bzero(piVar4,0x7c);
          _swapfs_bit_map = _kmem_suballoc(_kernel_map,local_10,local_14,0x19000,0);
          _swapfs_rem_map = _kmem_suballoc(_kernel_map,local_10,local_14,0x19000,0);
          piVar4[0x13] = 1;
          iVar5 = _kmem_mb_alloc(_swapfs_bit_map,_page_size);
          piVar4[0x12] = iVar5;
          iVar5 = _kmem_mb_alloc(_swapfs_rem_map,_page_size);
          piVar4[0x10] = iVar5;
          piVar4[0x11] = 1;
          uVar2 = _page_size;
          uVar9 = _page_size >> 2;
          piVar4[0xe] = uVar9;
          piVar4[0xd] = uVar2 >> 3;
          piVar4[0x18] = -1;
          *(undefined1 *)(piVar4 + 0x19) = 0;
          piVar4[0x1d] = -1;
          piVar4[0x15] = 0;
          piVar4[0x14] = 0;
          *(undefined1 *)(piVar4 + 0x1e) = 0;
          piVar4[0xf] = (int)piVar1;
          piVar4[0x16] = iVar3;
          uVar6 = _pmap_kernel(iVar3);
          iVar3 = _pmap_resident_extract(uVar6);
          piVar4[0x17] = iVar3;
          piVar4[0x1a] = iVar7;
          uVar6 = _pmap_kernel(iVar7);
          iVar3 = _pmap_resident_extract(uVar6);
          piVar4[0x1b] = iVar3;
          piVar4[0x1c] = iVar8;
          _bzero((void *)piVar4[0x10],uVar9 << 2);
          *(undefined2 *)(piVar4 + 1) = 0;
          *(undefined2 *)((int)piVar4 + 6) = 1;
          *(undefined2 *)((int)piVar4 + 10) = 0;
          *(undefined2 *)(piVar4 + 2) = 0;
          piVar4[9] = param_1;
          piVar4[10] = 1;
          *(short *)(piVar4 + 0xb) = (short)piVar1[0xb];
          piVar4[8] = 0;
          piVar4[6] = 0;
          piVar4[5] = 0;
          *(byte *)(piVar4 + 1) = *(byte *)(piVar4 + 1) | 1;
          piVar4[7] = (int)&PTR_FUN_001dd8d8;
          *piVar4 = 0;
          _vm_info_init(piVar4);
          **(short **)(_active_u + 0x1c) = **(short **)(_active_u + 0x1c) + 1;
          *(undefined4 *)(*piVar4 + 0x30) = *(undefined4 *)(_active_u + 0x1c);
          piVar4[0xc] = (int)piVar4;
          **(short **)(_active_u + 0x1c) = **(short **)(_active_u + 0x1c) + 1;
          *(undefined4 *)(*piVar1 + 0x30) = *(undefined4 *)(_active_u + 0x1c);
          *(int **)(param_1 + 0x128) = piVar4;
          iVar3 = piVar1[9];
          *(undefined4 *)(param_1 + 0x14) = *(undefined4 *)(iVar3 + 0x14);
          *(undefined4 *)(param_1 + 0x18) = *(undefined4 *)(iVar3 + 0x18);
          *(uint *)(param_1 + 0x18) = *(uint *)(param_1 + 0x18) | 0xc000;
          _DAT_001da0dc = 1;
          _DAT_001da0de = 0;
          PTR__nosys_001da0e0 = FUN_0013b580;
          _maxswapdevice = _maxswapdevice + 1;
          _swapfs_enabled = 1;
          iVar3 = 0;
        }
        else {
          _vn_rele(piVar1);
          iVar3 = 0x14;
        }
      }
    }
  }
  else {
    iVar3 = 0x10;
  }
  return iVar3;
}

