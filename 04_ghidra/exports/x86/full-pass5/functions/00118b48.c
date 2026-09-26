/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00118b48 */

void _unp_gc(void)

{
  short sVar1;
  undefined4 *puVar2;
  uint uVar3;
  int iVar4;
  undefined4 *puVar5;
  
  if (_unp_gcing != 0) {
    return;
  }
  _unp_gcing = 1;
LAB_00118b63:
  _unp_defer = 0;
  for (puVar2 = _file_list; puVar5 = _file_list, (undefined4 **)puVar2 != &_file_list;
      puVar2 = (undefined4 *)*puVar2) {
    puVar2[2] = puVar2[2] & 0xffffffcf;
  }
joined_r0x00118b98:
  while ((undefined4 **)puVar5 == &_file_list) {
    puVar5 = _file_list;
    if (_unp_defer == 0) {
      _unp_defer = 0;
      puVar2 = _file_list;
      while ((undefined4 **)puVar2 != &_file_list) {
        sVar1 = *(short *)((int)puVar2 + 0xe);
        puVar5 = puVar2;
        if ((*(short *)(puVar2 + 4) == sVar1) && ((*(byte *)(puVar2 + 2) & 0x10) == 0)) {
          while (puVar5 = _file_list, _file_list = puVar5, sVar1 != 0) {
            _unp_discard(puVar2);
            sVar1 = *(short *)(puVar2 + 4);
          }
        }
        puVar2 = (undefined4 *)*puVar5;
      }
      _unp_gcing = 0;
      return;
    }
  }
  if (*(short *)((int)puVar5 + 0xe) != 0) {
    uVar3 = puVar5[2];
    if ((uVar3 & 0x20) == 0) {
      if (((uVar3 & 0x10) != 0) || (*(short *)(puVar5 + 4) == *(short *)((int)puVar5 + 0xe)))
      goto LAB_00118c19;
      puVar5[2] = uVar3 | 0x10;
    }
    else {
      puVar5[2] = uVar3 & 0xffffffdf;
      _unp_defer = _unp_defer + -1;
    }
    if ((((*(short *)(puVar5 + 3) == 2) && (iVar4 = puVar5[6], iVar4 != 0)) &&
        (*(undefined **)(*(int *)(iVar4 + 0xc) + 4) == &_unixdomain)) &&
       ((*(byte *)(*(int *)(iVar4 + 0xc) + 10) & 0x10) != 0)) {
      if ((*(byte *)(iVar4 + 0x38) & 1) != 0) goto code_r0x00118bf5;
      _unp_scan(*(undefined4 *)(iVar4 + 0x30),_unp_mark);
    }
  }
LAB_00118c19:
  puVar5 = (undefined4 *)*puVar5;
  goto joined_r0x00118b98;
code_r0x00118bf5:
  _sbwait(iVar4 + 0x24);
  goto LAB_00118b63;
}

