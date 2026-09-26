/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00104800 */

undefined4 * _falloc(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  
  iVar3 = 0;
  do {
    _expand_fdlist(*(undefined4 *)(*(int *)(_active_threads + 0xc) + 0x38),iVar3);
    if (*(int *)(*(int *)(_active_u + 0x150) + iVar3 * 4) == 0) {
      *(int *)(DAT_001e875c + 0x60) = iVar3;
      *(undefined1 *)(iVar3 + *(int *)(_active_u + 0x154)) = 0;
      if (*(int *)(_active_u + 0x158) < iVar3) {
        *(int *)(_active_u + 0x158) = iVar3;
      }
      *(undefined4 *)(*(int *)(_active_u + 0x150) + iVar3 * 4) = 0xffff0000;
      goto LAB_00104887;
    }
    iVar3 = iVar3 + 1;
  } while (iVar3 < 0x100);
  *(undefined1 *)(DAT_001e875c + 0x68) = 0x18;
  iVar3 = -1;
LAB_00104887:
  if (iVar3 < 0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    puVar2 = (undefined4 *)_zalloc(_file_zone);
    puVar1 = puVar2;
    if ((undefined4 **)DAT_001e89dc != &_file_list) {
      *DAT_001e89dc = puVar2;
      puVar1 = _file_list;
    }
    _file_list = puVar1;
    puVar2[1] = DAT_001e89dc;
    *puVar2 = &_file_list;
    DAT_001e89dc = puVar2;
    *(undefined2 *)((int)puVar2 + 0xe) = 1;
    puVar2[6] = 0;
    puVar2[7] = 0;
    puVar2[5] = 0;
    **(short **)(_active_u + 0x1c) = **(short **)(_active_u + 0x1c) + 1;
    puVar2[8] = *(undefined4 *)(_active_u + 0x1c);
  }
  return puVar2;
}

