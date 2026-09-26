/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0017c17c */

undefined4
_vm_object_special(short param_1,code *param_2,undefined4 param_3,int param_4,int param_5)

{
  uint uVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int iVar4;
  byte bVar5;
  uint uVar6;
  size_t sVar7;
  int iVar8;
  int *piVar9;
  undefined4 *local_14;
  
  uVar1 = ~_page_mask & param_5 + _page_mask;
  uVar6 = uVar1 >> ((byte)_page_shift & 0x1f);
  uVar2 = _vm_object_allocate(uVar1);
  sVar7 = uVar6 * 0x30 + 0x10;
  puVar3 = (undefined4 *)_kalloc(sVar7);
  _bzero(puVar3,sVar7);
  *puVar3 = 1;
  puVar3[1] = uVar2;
  puVar3[2] = puVar3;
  puVar3[3] = sVar7;
  local_14 = puVar3 + 4;
  iVar8 = 0;
  if (0 < (int)uVar6) {
    piVar9 = puVar3 + 0xd;
    do {
      *(undefined2 *)(piVar9 + -2) = 1;
      iVar4 = (*param_2)((int)param_1,(iVar8 << ((byte)_page_shift & 0x1f)) + param_4,param_3);
      bVar5 = (byte)_page_shift;
      *piVar9 = iVar4 << (bVar5 & 0x1f);
      _vm_page_insert(local_14,uVar2,iVar8 << (bVar5 & 0x1f));
      iVar8 = iVar8 + 1;
      piVar9 = piVar9 + 0xc;
      local_14 = local_14 + 0xc;
    } while (iVar8 < (int)uVar6);
  }
  _vm_object_setpager(uVar2,puVar3,0,0);
  return uVar2;
}

