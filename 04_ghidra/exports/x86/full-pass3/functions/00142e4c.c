/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00142e4c */

void _bufstats(void)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  int aiStack_38 [5];
  int local_18;
  undefined4 *local_c;
  int local_8;
  
  iVar2 = -((int)(0x2000 / (ulonglong)_page_size) * 4 + 4);
  local_c = &_bfreelist;
  local_8 = 0;
  do {
    uVar5 = _page_size;
    local_18 = 0;
    uVar4 = 0;
    do {
      *(undefined4 *)(&stack0xffffffdc + uVar4 * 4 + iVar2) = 0;
      uVar4 = uVar4 + 1;
    } while (uVar4 <= (uint)(0x2000 / (ulonglong)uVar5));
    *(undefined4 *)((int)aiStack_38 + iVar2 + 0x10) = 0x142eca;
    uVar3 = _splbio();
    uVar5 = _page_size;
    for (puVar1 = (undefined4 *)local_c[3]; puVar1 != local_c; puVar1 = (undefined4 *)puVar1[3]) {
      *(int *)(&stack0xffffffdc + ((uint)puVar1[6] / uVar5) * 4 + iVar2) =
           *(int *)(&stack0xffffffdc + ((uint)puVar1[6] / uVar5) * 4 + iVar2) + 1;
      local_18 = local_18 + 1;
    }
    *(undefined4 *)((int)aiStack_38 + iVar2 + 0x10) = uVar3;
    *(undefined4 *)((int)aiStack_38 + iVar2 + 0xc) = 0x142f0d;
    _splx();
    *(int *)((int)aiStack_38 + iVar2 + 0xc) = local_18;
    *(undefined **)((int)aiStack_38 + iVar2 + 8) = (&PTR_s_LOCKED_001de120)[local_8];
    *(char **)((int)aiStack_38 + iVar2 + 4) = s__s__total__d_001de145;
    *(undefined4 *)((int)aiStack_38 + iVar2) = 0x142f26;
    _printf(*(char **)((int)aiStack_38 + iVar2 + 4));
    uVar5 = 0;
    do {
      if (*(int *)(&stack0xffffffdc + uVar5 * 4 + iVar2) != 0) {
        *(int *)((int)aiStack_38 + iVar2 + 0x10) = *(int *)(&stack0xffffffdc + uVar5 * 4 + iVar2);
        *(uint *)((int)aiStack_38 + iVar2 + 0xc) = uVar5 * _page_size;
        *(char **)((int)aiStack_38 + iVar2 + 8) = s____d__d_001de152;
        *(undefined4 *)((int)aiStack_38 + iVar2 + 4) = 0x142f5f;
        _printf(*(char **)((int)aiStack_38 + iVar2 + 8));
      }
      uVar5 = uVar5 + 1;
    } while (uVar5 <= (uint)(0x2000 / (ulonglong)_page_size));
    *(undefined **)((int)aiStack_38 + iVar2 + 0x10) = &DAT_001de15a;
    *(undefined4 *)((int)aiStack_38 + iVar2 + 0xc) = 0x142f7d;
    _printf(*(char **)((int)aiStack_38 + iVar2 + 0x10));
    local_c = local_c + 0x11;
    local_8 = local_8 + 1;
  } while (local_c < &_buf);
  return;
}

