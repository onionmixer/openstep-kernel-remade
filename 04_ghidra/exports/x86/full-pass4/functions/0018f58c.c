/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0018f58c */

void FUN_0018f58c(uint *param_1)

{
  undefined4 *puVar1;
  uint *puVar2;
  uint uVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
  FUN_0018f40c(param_1);
  if (*param_1 == 0) {
                    /* WARNING: Subroutine does not return */
    _panic(s_pmap_create_page_directory_001e24f0);
  }
  if (*param_1 == (*param_1 & 0xfffff000)) {
    uVar3 = *param_1;
    puVar2 = (uint *)((uVar3 >> 0x16) * 4 + *_kernel_pmap);
    if ((((*puVar2 & 1) == 0) ||
        (puVar2 = (uint *)((uVar3 >> 10 & 0xffc) + (*puVar2 & 0xfffff000)), puVar2 == (uint *)0x0))
       || ((*puVar2 & 1) == 0)) {
      uVar3 = 0;
    }
    else {
      uVar3 = (uVar3 & 0xfff) + (*puVar2 & 0xfffff000);
    }
    param_1[1] = uVar3;
    puVar4 = (undefined4 *)*_kernel_pmap;
    puVar1 = puVar4 + 0x100;
    puVar5 = (undefined4 *)(*param_1 + 0xc00);
    for (; puVar4 < puVar1; puVar4 = puVar4 + 1) {
      *puVar5 = *puVar4;
      puVar5 = puVar5 + 1;
    }
    return;
  }
                    /* WARNING: Subroutine does not return */
  _panic(s_pmap_create_page_directory_1_001e250b);
}

