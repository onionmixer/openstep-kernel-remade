
void sub_408771E(void)

{
  undefined4 *puVar1;
  uint uVar2;
  int *piVar3;
  int *piVar4;
  undefined4 *puVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int *piVar9;
  undefined4 uVar10;
  word wVar11;
  sword sVar13;
  int *piVar14;
  int iVar12;
  
  iVar7 = (int)dword_40C6EAC;
  puVar1 = *(undefined4 **)((int)dword_40C6EAC + 0x14);
  if ((undefined4 **)puVar1 == &dword_40C6EAC) {
    dword_40C6EB0 = &dword_40C6EAC;
  }
  else {
    puVar1[6] = &dword_40C6EAC;
  }
  piVar9 = (int *)((int)dword_40C6EAC + 0x14);
  piVar3 = (int *)((int)dword_40C6EAC + 0x18);
  dword_40C6EAC = puVar1;
  *piVar3 = (int)piVar9;
  *piVar9 = (int)piVar9;
  iVar12 = *(int *)(iVar7 + 0x2e) + -1;
  if (-1 < iVar12) {
    do {
      iVar8 = _kalloc(0x38);
      *(int *)(iVar8 + 0x24) = iVar8;
      piVar3 = *(int **)(iVar7 + 0x18);
      if (piVar3 == piVar9) {
        *piVar3 = iVar8;
      }
      else {
        piVar3[0xb] = iVar8;
      }
      *(int **)(iVar8 + 0x30) = piVar3;
      *(int *)(iVar8 + 0x2c) = iVar7 + 0x14;
      *(int *)(iVar7 + 0x18) = iVar8;
      *(undefined4 *)(iVar8 + 0x28) = 0x4087ba2;
      wVar11 = (word)((uint)iVar12 >> 0x10);
      sVar13 = (sword)iVar12 + -1;
      iVar12 = CONCAT22(wVar11,sVar13);
    } while ((sVar13 != -1) || (iVar12 = (uint)wVar11 * 0x10000 + -1, wVar11 != 0));
  }
  iVar12 = iVar7 + 4;
  _lock_write(iVar12);
  piVar9 = *(int **)(iVar7 + 0xc);
  piVar4 = (int *)(iVar7 + 0xc);
  piVar3 = (int *)*piVar4;
  piVar14 = piVar9;
  while (piVar4 != piVar3) {
    *(byte *)(iVar7 + 0x24) = *(byte *)(iVar7 + 0x24) & 0xfd;
    iVar8 = piVar9[7];
    if (_page_size <= piVar9[4] - iVar8) {
      iVar6 = (~_page_mask & piVar9[4]) - iVar8;
      uVar10 = 2;
      if ((*(byte *)((int)piVar9 + 0x2d) & 0x40) != 0) {
        uVar10 = 1;
      }
      sub_4087F1E(iVar8,iVar6,uVar10,*(byte *)((int)piVar9 + 0x2d) & 1);
      piVar9[7] = iVar6 + piVar9[7];
      *(int *)(iVar7 + 0x20) = *(int *)(iVar7 + 0x20) - iVar6;
    }
    if (((*(byte *)((int)piVar9 + 0x2d) & 2) != 0) &&
       (*(byte *)((int)piVar9 + 0x2d) = *(byte *)((int)piVar9 + 0x2d) & 0xfd,
       (*(byte *)(piVar9 + 0xb) & 4) != 0)) {
      _snd_reply_overflow(piVar9[6],*(undefined4 *)((int)piVar9 + 0x2e));
    }
    if (((*(byte *)((int)piVar9 + 0x2d) & 0x10) != 0) && ((*(byte *)(piVar9 + 0xb) & 0x40) != 0)) {
      *(byte *)(piVar9 + 0xb) = *(byte *)(piVar9 + 0xb) & 0xbf;
      _snd_reply_started(piVar9[6],*(undefined4 *)((int)piVar9 + 0x2e));
    }
    if (((*(byte *)((int)piVar9 + 0x2d) & 0x10) != 0) && ((*(byte *)(piVar9 + 0xb) & 2) != 0)) {
      piVar9 = (int *)sub_408815A(piVar9,iVar7);
      piVar14 = piVar9;
    }
    if ((*(byte *)((int)piVar9 + 0x2d) & 0x20) == 0) {
      if (((*(byte *)((int)piVar9 + 0x2d) & 8) == 0) ||
         ((uint)piVar9[7] < (piVar9[2] & ~_page_mask))) {
        if ((((*(byte *)(iVar7 + 0x24) & 0x34) == 0) &&
            ((int *)(iVar7 + 0x14) != *(int **)(iVar7 + 0x14))) &&
           (((uint)piVar9[10] <= piVar9[8] - (~_page_mask & piVar9[3]) ||
            ((uint)piVar9[2] <= (uint)piVar9[8])))) {
          *(byte *)((int)piVar9 + 0x2d) = *(byte *)((int)piVar9 + 0x2d) & 0xfb;
          sub_4087D98(iVar7,piVar9);
        }
        if ((((uint)piVar14[2] <= (uint)piVar14[8]) ||
            ((*(byte *)((int)piVar14 + 0x2d) & 0x20) != 0)) &&
           (*(int **)((int)piVar14 + 0x32) != piVar4)) {
          piVar14 = *(int **)((int)piVar14 + 0x32);
        }
        if ((((*(byte *)((int)piVar14 + 0x2d) & 0x20) == 0) && ((uint)piVar14[8] < (uint)piVar14[2])
            ) && (*(uint *)(iVar7 + 0x20) < (uint)piVar14[9])) {
          sub_4087FDE(piVar14[8]);
          iVar6 = _page_size;
          iVar8 = _page_size + piVar14[8];
          piVar14[8] = iVar8;
          if ((uint)piVar14[2] < (uint)(piVar14[10] + iVar8)) {
            piVar14[10] = piVar14[10] - iVar6;
          }
          *(int *)(iVar7 + 0x20) = _page_size + *(int *)(iVar7 + 0x20);
          _lock_done(iVar12);
          _lock_write(iVar12);
        }
        else {
          _lock_done(iVar12);
          if ((*(byte *)(iVar7 + 0x24) & 2) == 0) {
            _assert_wait(iVar7,1);
            _thread_block();
          }
          _lock_write(iVar12);
        }
      }
      else {
        piVar9 = (int *)sub_4088078(piVar9,iVar7);
        _lock_done(iVar12);
        _lock_write(iVar12);
        piVar14 = piVar9;
      }
    }
    else {
      *(byte *)((int)piVar9 + 0x2d) = *(byte *)((int)piVar9 + 0x2d) | 4;
      iVar8 = piVar9[8] - (~_page_mask & _page_mask + piVar9[3]);
      if (0 < iVar8) {
        uVar10 = 0;
        if ((*(byte *)((int)piVar9 + 0x2d) & 0x40) == 0) {
          uVar10 = 2;
        }
        sub_4087F1E(~_page_mask & _page_mask + piVar9[3],iVar8,uVar10,1);
        *(int *)(iVar7 + 0x20) = *(int *)(iVar7 + 0x20) - iVar8;
        piVar9[8] = ~_page_mask & _page_mask + piVar9[3];
      }
      uVar2 = piVar9[8];
      if (uVar2 < (uint)piVar9[2]) {
        _vm_deallocate(dword_40C6EBC,uVar2,piVar9[2] - uVar2);
        piVar9[2] = piVar9[8];
      }
      piVar9[7] = piVar9[8];
      if (piVar9[3] == piVar9[4]) {
        *(byte *)((int)piVar9 + 0x2d) = *(byte *)((int)piVar9 + 0x2d) | 8;
      }
      piVar9[2] = piVar9[3];
      piVar9[1] = piVar9[2] - *piVar9;
      *(byte *)(piVar9 + 0xb) = *(byte *)(piVar9 + 0xb) & 0x7f;
      *(byte *)((int)piVar9 + 0x2d) = *(byte *)((int)piVar9 + 0x2d) & 0xdf;
      *(byte *)((int)piVar9 + 0x2d) = *(byte *)((int)piVar9 + 0x2d) | 4;
      piVar3 = *(int **)((int)piVar9 + 0x32);
      if ((piVar3 != piVar4) && ((*(byte *)(piVar3 + 0xb) & 0x40) == 0)) {
        *(byte *)((int)piVar3 + 0x2d) = *(byte *)((int)piVar3 + 0x2d) | 4;
      }
      if ((*(byte *)(piVar9 + 0xb) & 0x20) != 0) {
        _snd_reply_aborted(piVar9[6],*(undefined4 *)((int)piVar9 + 0x2e));
      }
    }
    piVar3 = (int *)*piVar4;
  }
  puVar5 = (undefined4 *)(iVar7 + 0x14);
  puVar1 = (undefined4 *)*puVar5;
  while (puVar5 != puVar1) {
    iVar12 = *(int *)(iVar7 + 0x14);
    puVar1 = *(undefined4 **)(iVar12 + 0x2c);
    if (puVar1 == puVar5) {
      *(undefined4 **)(iVar7 + 0x18) = puVar5;
    }
    else {
      puVar1[0xc] = puVar5;
    }
    *(undefined4 **)(iVar7 + 0x14) = puVar1;
    _kfree(iVar12,0x38);
    puVar1 = (undefined4 *)*puVar5;
  }
  *(undefined4 *)(iVar7 + 0x1c) = 0;
  _lock_done(iVar7 + 4);
  _thread_wakeup_prim(iVar7,0,0);
  _thread_terminate(_active_threads);
  _thread_halt_self();
  return;
}

