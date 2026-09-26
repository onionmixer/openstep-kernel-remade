/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00135cb4 */

int FUN_00135cb4(undefined4 param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined2 *puVar5;
  ushort uVar6;
  
  iVar2 = _m_get(1,8);
  if (iVar2 == 0) {
    _printf(s_bindresvport__couldn_t_alloc_mbu_001dce66);
    iVar3 = 0x37;
  }
  else {
    puVar5 = (undefined2 *)(iVar2 + *(int *)(iVar2 + 4));
    *puVar5 = 2;
    *(undefined4 *)(puVar5 + 2) = 0;
    *(undefined2 *)(iVar2 + 8) = 0x10;
    uVar4 = _crdup(*(undefined4 *)(_active_u + 0x1c));
    uVar1 = *(undefined4 *)(_active_u + 0x1c);
    *(undefined4 *)(_active_u + 0x1c) = uVar4;
    *(undefined2 *)(*(int *)(_active_u + 0x1c) + 2) = 0;
    iVar3 = 0x30;
    uVar6 = 0x3ff;
    do {
      if (uVar6 < 0x200) break;
      puVar5[1] = uVar6 >> 8 | uVar6 << 8;
      iVar3 = _sobind(param_1,iVar2);
      uVar6 = uVar6 - 1;
    } while (iVar3 == 0x30);
    _m_freem(iVar2);
    *(undefined4 *)(_active_u + 0x1c) = uVar1;
    _crfree(uVar4);
  }
  return iVar3;
}

