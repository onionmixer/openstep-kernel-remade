/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0017d998 */

undefined4 * _vnode_alloc(int param_1)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 *puVar6;
  uint uVar7;
  int local_4c;
  undefined4 *local_48;
  
  local_48 = (undefined4 *)0x0;
  puVar6 = (undefined4 *)0x0;
  local_4c = 0;
  if (DAT_001e7290 < 2) {
    if (DAT_001e7290 == 1) {
      puVar6 = DAT_001e7288;
    }
  }
  else {
    uVar2 = 0;
    do {
      if ((undefined4 **)DAT_001e7288 != &DAT_001e7288) {
        puVar4 = DAT_001e7288;
        do {
          if ((((1 < (int)uVar2) || (puVar4[0xb] != 0)) &&
              (((uVar2 & 1) != 0 || (*(undefined ***)(puVar4[2] + 0x1c) == &_ufs_vnodeops)))) &&
             (local_4c < (int)puVar4[6])) {
            puVar6 = puVar4;
            local_4c = puVar4[6];
          }
          puVar4 = (undefined4 *)*puVar4;
        } while ((undefined4 **)puVar4 != &DAT_001e7288);
      }
    } while ((puVar6 == (undefined4 *)0x0) && (uVar2 = uVar2 + 1, (int)uVar2 < 4));
  }
  if (puVar6 != (undefined4 *)0x0) {
    local_48 = (undefined4 *)_zalloc_noblock(_vstruct_zone);
    if (local_48 == (undefined4 *)0x0) {
      local_48 = (undefined4 *)0x0;
    }
    else {
      uVar2 = (param_1 + _page_mask & ~_page_mask) >> ((byte)_page_shift & 0x1f);
      local_48[4] = uVar2;
      if (uVar2 == 0) {
        local_48[2] = 0;
      }
      else {
        uVar7 = uVar2 * 4;
        if (0x40 < uVar7) {
          uVar7 = (uVar2 - 1 >> 4) * 4 + 4;
        }
        uVar3 = _kalloc_noblock(uVar7);
        local_48[2] = uVar3;
        if ((void *)local_48[2] == (void *)0x0) {
          _zfree(_vstruct_zone,local_48);
          return (undefined4 *)0x0;
        }
        iVar1 = local_48[4];
        if ((uint)(iVar1 * 4) < 0x41) {
          iVar5 = 0;
          if (0 < iVar1) {
            do {
              *(undefined1 *)(local_48[2] + iVar5 * 4) = 0;
              iVar5 = iVar5 + 1;
            } while (iVar5 < (int)local_48[4]);
          }
        }
        else {
          _bzero((void *)local_48[2],(iVar1 - 1U >> 4) * 4 + 4);
        }
      }
      *local_48 = 0;
      *(undefined2 *)((int)local_48 + 0xe) = 1;
      local_48[5] = puVar6[2];
      *(byte *)(local_48 + 3) = *(byte *)(local_48 + 3) | 1;
      local_48[1] = puVar6;
      puVar6[3] = puVar6[3] + 1;
      do {
      } while (_vstruct_lock != 0);
      LOCK();
      UNLOCK();
      *(short *)((int)local_48 + 0xe) = *(short *)((int)local_48 + 0xe) + -1;
      LOCK();
      _vstruct_lock = 0;
      UNLOCK();
    }
  }
  return local_48;
}

