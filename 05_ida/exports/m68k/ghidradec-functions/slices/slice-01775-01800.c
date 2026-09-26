/* GHIDRADEC_FUNCTION index=1775 start=0x405ed0a */

/* WARNING: Removing unreachable block (ram,0x0405f00c) */
/* WARNING: Removing unreachable block (ram,0x0405f014) */
/* WARNING: Removing unreachable block (ram,0x0405f01a) */
/* WARNING: Removing unreachable block (ram,0x0405f040) */

int _vm_map_copy(int param_1,int param_2,uint param_3,int param_4,uint param_5,int param_6,
                int param_7)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  undefined4 uVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iStack_8;
  
  uVar8 = param_4 + param_5;
  uVar9 = param_3 + param_4;
  if ((uVar9 < param_3) || (uVar8 < param_5)) {
    return 3;
  }
  if (param_1 == param_2) {
    _lock_write(param_1);
    *(int *)(param_1 + 0x40) = *(int *)(param_1 + 0x40) + 1;
  }
  else if (param_2 < param_1) {
    _lock_write(param_2);
    *(int *)(param_2 + 0x40) = *(int *)(param_2 + 0x40) + 1;
    _lock_write(param_1);
    *(int *)(param_1 + 0x40) = *(int *)(param_1 + 0x40) + 1;
  }
  else {
    _lock_write(param_1);
    *(int *)(param_1 + 0x40) = *(int *)(param_1 + 0x40) + 1;
    _lock_write(param_2);
    *(int *)(param_2 + 0x40) = *(int *)(param_2 + 0x40) + 1;
  }
  iVar12 = 0;
  if ((*(int *)(param_2 + 0x28) != 0) && (*(int *)(param_1 + 0x28) != 0)) {
    iVar3 = _vm_map_check_protection(param_2,param_5,uVar8,1);
    if (iVar3 == 0) {
      iVar12 = 2;
      goto loc_405F05E;
    }
    if (param_6 == 0) {
      iVar3 = _vm_map_check_protection(param_1,param_3,uVar9,2);
      if (iVar3 == 0) {
        iVar12 = 2;
        goto loc_405F05E;
      }
    }
    else {
      iVar12 = _vm_map_insert(param_1,0,0,param_3,uVar9);
      if (iVar12 != 0) goto loc_405F05E;
    }
  }
  _vm_map_lookup_entry(param_2,param_5,&iStack_8);
  iVar3 = iStack_8;
  if (*(uint *)(iStack_8 + 8) < param_5) {
    __vm_map_clip_start(param_2 + 8,iStack_8,param_5);
  }
  _vm_map_lookup_entry(param_1,param_3,&iStack_8);
  iVar11 = iStack_8;
  if (*(uint *)(iStack_8 + 8) < param_3) {
    __vm_map_clip_start(param_1 + 8,iStack_8,param_3);
  }
  uVar5 = param_5;
  if ((iVar11 != iVar3) ||
     (_vm_map_lookup_entry(param_2,param_5,&iStack_8), iVar3 = iStack_8, iVar11 != iStack_8)) {
    while (uVar5 < uVar8) {
      if (uVar8 < *(uint *)(iVar3 + 0xc)) {
        __vm_map_clip_end(param_2 + 8,iVar3,uVar8);
      }
      if (uVar9 < *(uint *)(iVar11 + 0xc)) {
        __vm_map_clip_end(param_1 + 8,iVar11,uVar9);
      }
      uVar5 = *(int *)(iVar3 + 8) + (*(int *)(iVar11 + 0xc) - *(int *)(iVar11 + 8));
      if (uVar5 < *(uint *)(iVar3 + 0xc)) {
        __vm_map_clip_end(param_2 + 8,iVar3,uVar5);
      }
      uVar5 = *(int *)(iVar11 + 8) + (*(int *)(iVar3 + 0xc) - *(int *)(iVar3 + 8));
      if (uVar5 < *(uint *)(iVar11 + 0xc)) {
        __vm_map_clip_end(param_1 + 8,iVar11,uVar5);
      }
      if ((*(char *)(iVar3 + 0x18) < '\0') || (*(char *)(iVar11 + 0x18) < '\0')) {
        iVar2 = *(int *)(iVar11 + 0xc) - *(int *)(iVar11 + 8);
        if (*(char *)(iVar3 + 0x18) < '\0') {
          uVar7 = *(undefined4 *)(iVar3 + 0x14);
          iVar6 = *(int *)(iVar3 + 0x10);
        }
        else {
          uVar7 = *(undefined4 *)(iVar3 + 8);
          _lock_set_recursive(param_2);
          iVar6 = param_2;
        }
        if (*(char *)(iVar11 + 0x18) < '\0') {
          iVar10 = *(int *)(iVar11 + 0x10);
          iVar4 = *(int *)(iVar11 + 0x14);
          iVar1 = iVar2 + iVar4;
          if (iVar6 != iVar10) {
            _lock_write(iVar10);
            *(int *)(iVar10 + 0x40) = *(int *)(iVar10 + 0x40) + 1;
            _vm_map_delete(iVar10,iVar4,iVar1);
            _vm_map_insert(iVar10,0,0,iVar4,iVar1);
            _lock_done(iVar10);
          }
        }
        else {
          iVar4 = *(int *)(iVar11 + 8);
          _lock_set_recursive(param_1);
          iVar10 = param_1;
        }
        _vm_map_copy(iVar10,iVar6,iVar4,iVar2,uVar7,0,0);
        if (iVar10 == param_1) {
          _lock_clear_recursive(param_1);
        }
        if (iVar6 == param_2) {
          _lock_clear_recursive(param_2);
        }
      }
      else {
        _vm_map_copy_entry(param_2,param_1,iVar3,iVar11);
      }
      iVar11 = *(int *)(iVar11 + 4);
      uVar5 = *(uint *)(iVar3 + 0xc);
      iVar3 = *(int *)(iVar3 + 4);
    }
  }
loc_405F05E:
  if (param_7 != 0) {
    _vm_map_delete(param_2,param_5,param_4 + param_5);
  }
  _lock_done(param_2);
  if (param_1 != param_2) {
    _lock_done(param_1);
  }
  return iVar12;
}
/* GHIDRADEC_FUNCTION index=1776 start=0x405f0a0 */

int _vm_map_fork(int param_1)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int *piVar6;
  int iVar7;
  int *piVar8;
  
  _lock_write(param_1);
  *(int *)(param_1 + 0x40) = *(int *)(param_1 + 0x40) + 1;
  uVar2 = _pmap_create(0);
  iVar3 = _vm_map_create(uVar2,*(undefined4 *)(param_1 + 0x10),*(undefined4 *)(param_1 + 0x14),
                         *(undefined4 *)(param_1 + 0x1c));
  piVar8 = *(int **)(param_1 + 0xc);
  if ((int *)(param_1 + 8) != piVar8) {
    piVar1 = (int *)(iVar3 + 8);
    do {
      if ((*(byte *)(piVar8 + 6) & 0x20) != 0) {
                    /* WARNING: Subroutine does not return */
        _panic(aVmMapForkEncou);
      }
      iVar7 = *(int *)((int)piVar8 + 0x22);
      if (iVar7 == 1) {
        piVar6 = (int *)__vm_map_entry_create(piVar1);
        *piVar6 = *piVar8;
        piVar6[1] = piVar8[1];
        piVar6[2] = piVar8[2];
        piVar6[3] = piVar8[3];
        piVar6[4] = piVar8[4];
        piVar6[5] = piVar8[5];
        piVar6[6] = piVar8[6];
        piVar6[7] = piVar8[7];
        piVar6[8] = piVar8[8];
        piVar6[9] = piVar8[9];
        *(undefined2 *)(piVar6 + 10) = *(undefined2 *)(piVar8 + 10);
        *(undefined2 *)((int)piVar6 + 0x26) = 0;
        piVar6[4] = 0;
        *(byte *)(piVar6 + 6) = *(byte *)(piVar6 + 6) & 0x7f;
        *(int *)(iVar3 + 0x18) = *(int *)(iVar3 + 0x18) + 1;
        *piVar6 = *piVar1;
        piVar6[1] = *(int *)(*piVar1 + 4);
        iVar7 = *piVar6;
        *(int **)piVar6[1] = piVar6;
        *(int **)(iVar7 + 4) = piVar6;
        if (*(char *)(piVar8 + 6) < '\0') {
          iVar7 = _vm_map_copy(iVar3,piVar8[4],piVar6[2],piVar6[3] - piVar6[2],piVar8[5],0,0);
          if (iVar7 != 0) {
            _printf(aVmMapForkCopyI);
          }
        }
        else {
          _vm_map_copy_entry(param_1,iVar3,piVar8,piVar6);
        }
      }
      else if ((iVar7 < 2) && (iVar7 == 0)) {
        if (-1 < *(char *)(piVar8 + 6)) {
          iVar4 = _vm_map_create(0,piVar8[2],piVar8[3],1);
          *(undefined4 *)(iVar4 + 0x28) = 0;
          piVar6 = (int *)(iVar4 + 8);
          piVar5 = (int *)__vm_map_entry_create(piVar6);
          *piVar5 = *piVar8;
          piVar5[1] = piVar8[1];
          piVar5[2] = piVar8[2];
          piVar5[3] = piVar8[3];
          piVar5[4] = piVar8[4];
          piVar5[5] = piVar8[5];
          piVar5[6] = piVar8[6];
          piVar5[7] = piVar8[7];
          piVar5[8] = piVar8[8];
          piVar5[9] = piVar8[9];
          *(undefined2 *)(piVar5 + 10) = *(undefined2 *)(piVar8 + 10);
          *(int *)(iVar4 + 0x18) = *(int *)(iVar4 + 0x18) + 1;
          *piVar5 = *piVar6;
          piVar5[1] = *(int *)(*piVar6 + 4);
          iVar7 = *piVar5;
          *(int **)piVar5[1] = piVar5;
          *(int **)(iVar7 + 4) = piVar5;
          *(byte *)(piVar8 + 6) = *(byte *)(piVar8 + 6) | 0x80;
          piVar8[4] = iVar4;
          piVar8[5] = piVar8[2];
        }
        piVar6 = (int *)__vm_map_entry_create(piVar1);
        *piVar6 = *piVar8;
        piVar6[1] = piVar8[1];
        piVar6[2] = piVar8[2];
        piVar6[3] = piVar8[3];
        piVar6[4] = piVar8[4];
        piVar6[5] = piVar8[5];
        piVar6[6] = piVar8[6];
        piVar6[7] = piVar8[7];
        piVar6[8] = piVar8[8];
        piVar6[9] = piVar8[9];
        *(undefined2 *)(piVar6 + 10) = *(undefined2 *)(piVar8 + 10);
        _vm_map_reference(piVar6[4]);
        *(int *)(iVar3 + 0x18) = *(int *)(iVar3 + 0x18) + 1;
        *piVar6 = *piVar1;
        piVar6[1] = *(int *)(*piVar1 + 4);
        iVar7 = *piVar6;
        *(int **)piVar6[1] = piVar6;
        *(int **)(iVar7 + 4) = piVar6;
        _pmap_copy(*(undefined4 *)(iVar3 + 0x20),*(undefined4 *)(param_1 + 0x20),piVar6[2],
                   piVar8[3] - piVar8[2],piVar8[2]);
      }
      piVar8 = (int *)piVar8[1];
    } while ((int *)(param_1 + 8) != piVar8);
  }
  *(undefined4 *)(iVar3 + 0x24) = *(undefined4 *)(param_1 + 0x24);
  _lock_done(param_1);
  return iVar3;
}
/* GHIDRADEC_FUNCTION index=1777 start=0x405f2da */

undefined4
_vm_map_lookup(int *param_1,uint param_2,uint param_3,int *param_4,undefined4 *param_5,int *param_6,
              uint *param_7,int *param_8,uint *param_9)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  int iStack_c;
  int iStack_8;
  
  iVar7 = *param_1;
  do {
    _lock_read(iVar7);
    iVar1 = *(int *)(iVar7 + 0x30);
    *param_4 = iVar1;
    if (((iVar7 + 8 == iVar1) || (param_2 < *(uint *)(iVar1 + 8))) ||
       (*(uint *)(iVar1 + 0xc) <= param_2)) {
      iVar1 = _vm_map_lookup_entry(iVar7,param_2,&iStack_8);
      if (iVar1 == 0) {
        _lock_done(iVar7);
        return 1;
      }
      *param_4 = iStack_8;
      iVar1 = iStack_8;
    }
    if ((*(byte *)(iVar1 + 0x18) & 0x20) != 0) {
      iVar1 = *(int *)(iVar1 + 0x10);
      *param_1 = iVar1;
      goto loc_405F452;
    }
    uVar5 = *(uint *)(iVar1 + 0x1a);
    if (param_3 != (uVar5 & param_3)) {
      _lock_done(iVar7);
      return 2;
    }
    iVar8 = -(int)-(*(sword *)(iVar1 + 0x26) != 0);
    *param_8 = iVar8;
    if (iVar8 != 0) {
      uVar5 = *(uint *)(iVar1 + 0x1a);
      param_3 = uVar5;
    }
    uVar4 = *(uint *)(iVar1 + 0x18) >> 0x1f ^ 1;
    uVar6 = param_2;
    iVar8 = iVar7;
    if (uVar4 == 0) {
      iVar8 = *(int *)(iVar1 + 0x10);
      uVar6 = *(int *)(iVar1 + 0x14) + (param_2 - *(int *)(iVar1 + 8));
      _lock_read(iVar8);
      iVar2 = _vm_map_lookup_entry(iVar8,uVar6,&iStack_c);
      iVar1 = iStack_c;
      if (iVar2 == 0) {
        _lock_done(iVar8);
        _lock_done(iVar7);
        return 1;
      }
    }
    if ((*(byte *)(iVar1 + 0x18) & 2) != 0) {
      if ((param_3 & 2) == 0) {
        uVar5 = uVar5 & 0xfffffffd;
        goto loc_405F436;
      }
      iVar2 = _lock_read_to_write(iVar8);
      if (iVar2 == 0) {
        _vm_object_shadow(iVar1 + 0x10,iVar1 + 0x14,*(int *)(iVar1 + 0xc) - *(int *)(iVar1 + 8));
        *(byte *)(iVar1 + 0x18) = *(byte *)(iVar1 + 0x18) & 0xfd;
        _lock_write_to_read(iVar8);
        goto loc_405F436;
      }
      goto loc_405F44A;
    }
loc_405F436:
    if (*(int *)(iVar1 + 0x10) != 0) goto loc_405F47E;
    iVar2 = _lock_read_to_write(iVar8);
    if (iVar2 == 0) {
      uVar3 = _vm_object_allocate(*(int *)(iVar1 + 0xc) - *(int *)(iVar1 + 8));
      *(undefined4 *)(iVar1 + 0x10) = uVar3;
      *(undefined4 *)(iVar1 + 0x14) = 0;
      _lock_write_to_read(iVar8);
loc_405F47E:
      *param_6 = *(int *)(iVar1 + 0x14) + (uVar6 - *(int *)(iVar1 + 8));
      *param_5 = *(undefined4 *)(iVar1 + 0x10);
      if (uVar4 == 0) {
        uVar4 = -(int)-(*(int *)(iVar8 + 0x2c) == 1);
      }
      *param_7 = uVar5;
      *param_9 = uVar4;
      return 0;
    }
loc_405F44A:
    iVar1 = iVar7;
    if (iVar7 != iVar8) {
loc_405F452:
      _lock_done(iVar7);
      iVar7 = iVar1;
    }
  } while( true );
}
/* GHIDRADEC_FUNCTION index=1778 start=0x405f4c0 */

void _vm_map_lookup_done(undefined4 param_1,int param_2)

{
  if (*(char *)(param_2 + 0x18) < '\0') {
    _lock_done(*(undefined4 *)(param_2 + 0x10));
  }
  _lock_done(param_1);
  return;
}
/* GHIDRADEC_FUNCTION index=1779 start=0x405f4e8 */

undefined4
_vm_map_machine_attribute
          (int param_1,uint param_2,int param_3,undefined4 param_4,undefined4 param_5)

{
  undefined4 uVar1;
  
  if ((param_2 < *(uint *)(param_1 + 0x10)) || (*(uint *)(param_1 + 0x14) < param_3 + param_2)) {
    uVar1 = 4;
  }
  else {
    _lock_write(param_1);
    *(int *)(param_1 + 0x40) = *(int *)(param_1 + 0x40) + 1;
    uVar1 = _pmap_attribute(*(undefined4 *)(param_1 + 0x20),param_2,param_3,param_4,param_5);
    _lock_done(param_1);
  }
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=1780 start=0x405f548 */

undefined4
_vm_region(int param_1,int *param_2,uint *param_3,undefined4 *param_4,undefined4 *param_5,
          undefined4 *param_6,int *param_7,undefined4 *param_8,int *param_9)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iStack_8;
  
  if (param_1 == 0) {
    uVar2 = 4;
  }
  else {
    iVar4 = *param_2;
    _lock_read(param_1);
    iVar3 = _vm_map_lookup_entry(param_1,iVar4,&iStack_8);
    iVar4 = iStack_8;
    if ((iVar3 == 0) && (iVar4 = *(int *)(iStack_8 + 4), param_1 + 8 == *(int *)(iStack_8 + 4))) {
      _lock_done(param_1);
      uVar2 = 3;
    }
    else {
      iVar3 = *(int *)(iVar4 + 8);
      *param_4 = *(undefined4 *)(iVar4 + 0x1a);
      *param_5 = *(undefined4 *)(iVar4 + 0x1e);
      *param_6 = *(undefined4 *)(iVar4 + 0x22);
      *param_2 = iVar3;
      *param_3 = *(int *)(iVar4 + 0xc) - iVar3;
      iVar3 = *(int *)(iVar4 + 0x14);
      if ((char)*(byte *)(iVar4 + 0x18) < '\0') {
        iVar4 = *(int *)(iVar4 + 0x10);
        _lock_read(iVar4);
        _vm_map_lookup_entry(iVar4,iVar3,&iStack_8);
        uVar1 = *(int *)(iStack_8 + 0xc) - iVar3;
        if (uVar1 < *param_3) {
          *param_3 = uVar1;
        }
        uVar2 = _vm_object_name(*(undefined4 *)(iStack_8 + 0x10));
        *param_8 = uVar2;
        *param_9 = *(int *)(iStack_8 + 0x14) + (iVar3 - *(int *)(iStack_8 + 8));
        *param_7 = -(int)-(*(int *)(iVar4 + 0x2c) != 1);
        _lock_done(iVar4);
      }
      else if ((*(byte *)(iVar4 + 0x18) & 0x20) == 0) {
        *param_7 = 0;
        uVar2 = _vm_object_name(*(undefined4 *)(iVar4 + 0x10));
        *param_8 = uVar2;
        *param_9 = iVar3;
      }
      else {
        *param_7 = 0;
        *param_8 = 0;
        *param_9 = iVar3;
      }
      _lock_done(param_1);
      uVar2 = 0;
    }
  }
  return uVar2;
}
/* GHIDRADEC_FUNCTION index=1781 start=0x405f68e */

int _vm_move(undefined4 param_1,uint param_2,undefined4 param_3,int param_4,undefined4 param_5,
            int *param_6)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iStack_8;
  
  if (param_4 == 0) {
    *param_6 = 0;
    iVar3 = 0;
  }
  else {
    uVar1 = ~_page_mask & param_2;
    iVar2 = (~_page_mask & _page_mask + param_2 + param_4) - uVar1;
    iStack_8 = 0;
    iVar3 = _vm_allocate(param_3,&iStack_8,iVar2,1);
    if (iVar3 == 0) {
      iVar3 = _vm_map_copy(param_3,param_1,iStack_8,iVar2,uVar1,0,param_5);
      if (iVar3 == 0) {
        *param_6 = iStack_8 + (param_2 - uVar1);
      }
      else {
        _vm_deallocate(param_3,iStack_8,iVar2);
      }
    }
  }
  return iVar3;
}
/* GHIDRADEC_FUNCTION index=1782 start=0x405f72c */

undefined4 _vm_map_pmap_EXTERNAL(int param_1)

{
  return *(undefined4 *)(param_1 + 0x20);
}
/* GHIDRADEC_FUNCTION index=1783 start=0x405f73c */

int _vm_mem_ppi(uint param_1)

{
  undefined *puVar1;
  int iVar2;
  
  iVar2 = 0;
  puVar1 = _mem_region;
  while( true ) {
    if (_mem_region + _num_regions * 0x1c <= puVar1) {
                    /* WARNING: Subroutine does not return */
      _panic(&aMemPpi);
    }
    if ((*(uint *)(puVar1 + 0x14) <= param_1) && (param_1 < *(uint *)(puVar1 + 0x18))) break;
    iVar2 = *(int *)(puVar1 + 0xc) + iVar2;
    puVar1 = puVar1 + 0x1c;
  }
  return iVar2 + (param_1 - *(uint *)(puVar1 + 0x14) >> (_page_shift & 0x3f));
}
/* GHIDRADEC_FUNCTION index=1784 start=0x405f7a8 */

undefined4 _vm_valid_page(uint param_1)

{
  undefined *puVar1;
  
  puVar1 = _mem_region;
  while( true ) {
    if (_mem_region + _num_regions * 0x1c <= puVar1) {
      return 0;
    }
    if ((*(uint *)(puVar1 + 0x14) <= param_1) && (param_1 < *(uint *)(puVar1 + 0x18))) break;
    puVar1 = puVar1 + 0x1c;
  }
  return 1;
}
/* GHIDRADEC_FUNCTION index=1785 start=0x405f7f0 */

int _vm_phys_to_vm_page(uint param_1)

{
  undefined *puVar1;
  
  puVar1 = _mem_region;
  if (_mem_region < _mem_region + _num_regions * 0x1c) {
    do {
      if ((*(uint *)((int)puVar1 + 0x14) <= param_1) && (param_1 < *(uint *)((int)puVar1 + 0x18))) {
        return *(int *)puVar1 +
               ((param_1 >> (_page_shift & 0x3f)) - *(int *)((int)puVar1 + 4)) * 0x2e;
      }
      puVar1 = (undefined *)((int)puVar1 + 0x1c);
    } while (puVar1 < _mem_region + _num_regions * 0x1c);
  }
  return 0;
}
/* GHIDRADEC_FUNCTION index=1786 start=0x405f85c */

void _vm_region_to_vm_page(undefined4 param_1)

{
  _vm_phys_to_vm_page(param_1);
  return;
}
/* GHIDRADEC_FUNCTION index=1787 start=0x405f86e */

void _vm_alloc_from_regions(int param_1,int param_2)

{
  uint uVar1;
  uint *puVar2;
  undefined *puVar3;
  
  puVar3 = _mem_region;
  if (_mem_region < _mem_region + _num_regions * 0x1c) {
    puVar2 = &dword_40C2C40;
    do {
      uVar1 = param_1 + (-param_2 & param_2 + (*puVar2 - 1));
      if (uVar1 <= *(uint *)(puVar3 + 0x18)) {
        *puVar2 = uVar1;
        return;
      }
      puVar2 = puVar2 + 7;
      puVar3 = puVar3 + 0x1c;
    } while (puVar3 < _mem_region + _num_regions * 0x1c);
  }
                    /* WARNING: Subroutine does not return */
  _panic(aVmMemAllocFrom);
}
/* GHIDRADEC_FUNCTION index=1788 start=0x405f8de */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _vm_object_init(void)

{
  int iVar1;
  undefined4 *puVar2;
  
  _vm_object_zone = _zinit(0x52,~_page_mask & _page_mask + 0x80000,0,0,&aObjects);
  _object_hash_zone = _zinit(0xc,0x19000,0,0,aObjectHashZone);
  dword_40C2DA4 = &_vm_object_cached_list;
  _vm_object_cached_list = &_vm_object_cached_list;
  dword_40C31B0 = &_vm_object_list;
  _vm_object_list = &_vm_object_list;
  _vm_object_count = 0;
  iVar1 = 0;
  puVar2 = &_vm_object_hashtable;
  do {
    puVar2[1] = puVar2;
    *puVar2 = puVar2;
    puVar2 = puVar2 + 2;
    iVar1 = iVar1 + 1;
  } while (iVar1 < 0x80);
  _vm_cache_max = (_mem_size >> 0x14) * 0x32;
  if (0x9c4 < _vm_cache_max) {
    _vm_cache_max = 0x9c4;
  }
  word_40C31CC = 1;
  word_40C31CE = 0;
  dword_40C31C8 = 0;
  word_40C31F8 = 0;
  dword_40C31D0 = 0;
  dword_40C31DC = 0;
  dword_40C31E4 = 0;
  dword_40C31E8 = 0;
  _unk_40C31FC = (word)(byte_40C31FD & 0xf7);
  unk_40C31FA = unk_40C31FA & 0xcf | 8;
  dword_40C31E0 = 0;
  dword_40C31D4 = 0;
  dword_40C31D8 = 0;
  dword_40C3206 = 0;
  byte_40C31FB = byte_40C31FB & 0xf0;
  _unk_40C31FC = _unk_40C31FC & 0x2f | 0x20;
  _kernel_object = _kernel_object_store;
  __vm_object_allocate(0x4000000,_kernel_object_store);
  _vm_submap_object = _vm_submap_object_store;
  __vm_object_allocate(0x4000000,_vm_submap_object_store);
  return;
}
/* GHIDRADEC_FUNCTION index=1789 start=0x405fa6c */

undefined4 _vm_object_allocate(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = _zalloc(_vm_object_zone);
  __vm_object_allocate(param_1,uVar1);
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=1790 start=0x405fa9e */

void __vm_object_allocate(undefined4 param_1,int param_2)

{
  _bcopy(_vm_object_template,param_2,0x52);
  *(int *)(param_2 + 4) = param_2;
  *(int *)param_2 = param_2;
  *(undefined4 *)(param_2 + 0x10) = param_1;
  if (dword_40C31B0 == &_vm_object_list) {
    _vm_object_list = param_2;
  }
  else {
    dword_40C31B0[2] = param_2;
  }
  *(undefined4 **)(param_2 + 0xc) = dword_40C31B0;
  *(int **)(param_2 + 8) = &_vm_object_list;
  dword_40C31B0 = (undefined4 *)param_2;
  _vm_object_count = _vm_object_count + 1;
  return;
}
/* GHIDRADEC_FUNCTION index=1791 start=0x405fb04 */

void _vm_object_reference(int param_1)

{
  if (param_1 != 0) {
    *(sword *)(param_1 + 0x14) = *(sword *)(param_1 + 0x14) + 1;
  }
  return;
}
/* GHIDRADEC_FUNCTION index=1792 start=0x405fb18 */

void _vm_object_deallocate(int param_1)

{
  int iVar1;
  sword sVar2;
  
  while( true ) {
    if (param_1 == 0) {
      return;
    }
    sVar2 = *(sword *)(param_1 + 0x14);
    *(sword *)(param_1 + 0x14) = sVar2 + -1;
    if (sVar2 != 1) break;
    if ((*(byte *)(param_1 + 0x42) & 0x10) != 0) {
      if (0 < *(sword *)(param_1 + 0x16)) {
        iVar1 = param_1;
        if (dword_40C2DA4 != &_vm_object_cached_list) {
          *(int *)((int)dword_40C2DA4 + 0x46) = param_1;
          iVar1 = _vm_object_cached_list;
        }
        _vm_object_cached_list = iVar1;
        *(undefined4 **)(param_1 + 0x4a) = dword_40C2DA4;
        *(int **)(param_1 + 0x46) = &_vm_object_cached_list;
        _vm_object_cached = _vm_object_cached + 1;
        dword_40C2DA4 = (undefined4 *)param_1;
        _vm_object_deactivate_pages(param_1);
        _vm_object_cache_trim();
        return;
      }
      *(byte *)(param_1 + 0x42) = *(byte *)(param_1 + 0x42) & 0xef;
    }
    _vm_object_remove(*(undefined4 *)(param_1 + 0x24));
    iVar1 = *(int *)(param_1 + 0x1c);
    _vm_object_terminate(param_1);
    param_1 = iVar1;
  }
  return;
}
/* GHIDRADEC_FUNCTION index=1793 start=0x405fbbc */

void _vm_object_terminate(undefined4 *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
  iVar2 = param_1[7];
  if (iVar2 != 0) {
    if (param_1 == *(undefined4 **)(iVar2 + 0x18)) {
      *(undefined4 *)(iVar2 + 0x18) = 0;
    }
    else if (*(undefined4 **)(iVar2 + 0x18) != (undefined4 *)0x0) {
                    /* WARNING: Subroutine does not return */
      _panic(aVmObjectTermin);
    }
  }
  while (*(sword *)(param_1 + 0x10) != 0) {
    _thread_sleep(param_1,0,0);
  }
  puVar1 = (undefined4 *)*param_1;
  while (puVar4 = puVar1, puVar4 != param_1) {
    if ((*(byte *)((int)puVar4 + 0x1e) & 0x40) != 0) {
      puVar1 = (undefined4 *)*puVar4;
      puVar3 = (undefined4 *)puVar4[1];
      puVar5 = puVar3;
      if (puVar1 != &_vm_page_queue_active) {
        puVar1[1] = puVar3;
        puVar5 = dword_40C2C14;
      }
      dword_40C2C14 = puVar5;
      *puVar3 = puVar1;
      *(byte *)((int)puVar4 + 0x1e) = *(byte *)((int)puVar4 + 0x1e) & 0xbf;
      _vm_page_active_count = _vm_page_active_count + -1;
    }
    if (*(char *)((int)puVar4 + 0x1e) < '\0') {
      puVar1 = (undefined4 *)*puVar4;
      puVar3 = (undefined4 *)puVar4[1];
      puVar5 = puVar3;
      if (puVar1 != &_vm_page_queue_inactive) {
        puVar1[1] = puVar3;
        puVar5 = dword_40C23DC;
      }
      dword_40C23DC = puVar5;
      *puVar3 = puVar1;
      *(byte *)((int)puVar4 + 0x1e) = *(byte *)((int)puVar4 + 0x1e) & 0x7f;
      _vm_page_inactive_count = _vm_page_inactive_count + -1;
    }
    puVar1 = (undefined4 *)puVar4[2];
    if ((*(byte *)((int)puVar4 + 0x1e) & 0x10) != 0) {
      _vm_page_free(puVar4);
    }
  }
  if (param_1[9] != 0) {
    _vm_pager_deallocate(param_1[9]);
  }
  if (*(sword *)(param_1 + 0x10) != 0) {
                    /* WARNING: Subroutine does not return */
    _panic(aVmObjectDeallo);
  }
  while (param_1 != (undefined4 *)*param_1) {
    _vm_page_free(*param_1);
  }
  puVar1 = (undefined4 *)param_1[2];
  puVar4 = (undefined4 *)param_1[3];
  puVar3 = puVar4;
  if ((undefined4 **)puVar1 != &_vm_object_list) {
    puVar1[3] = puVar4;
    puVar3 = dword_40C31B0;
  }
  dword_40C31B0 = puVar3;
  if ((undefined4 **)puVar4 != &_vm_object_list) {
    puVar4[2] = puVar1;
    puVar1 = _vm_object_list;
  }
  _vm_object_list = puVar1;
  _vm_object_count = _vm_object_count + -1;
  _zfree(_vm_object_zone,param_1);
  return;
}
/* GHIDRADEC_FUNCTION index=1794 start=0x405fd08 */

void _vm_object_destroy(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = _vm_object_lookup(param_1);
  if (iVar1 != 0) {
    _vm_object_deallocate(iVar1);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=1795 start=0x405fd28 */

void _vm_object_deactivate_pages(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  puVar1 = (undefined4 *)*param_1;
  while (puVar2 = puVar1, puVar2 != param_1) {
    puVar1 = (undefined4 *)puVar2[2];
    if (-1 < *(char *)((int)puVar2 + 0x1e)) {
      _vm_page_deactivate(puVar2);
    }
  }
  return;
}
/* GHIDRADEC_FUNCTION index=1796 start=0x405fd60 */

void _vm_object_cache_trim(void)

{
  int iVar1;
  int iVar2;
  
  while( true ) {
    iVar1 = _vm_object_cached_list;
    if (_vm_object_cached <= _vm_cache_max) {
      return;
    }
    iVar2 = _vm_object_lookup(*(undefined4 *)(_vm_object_cached_list + 0x24));
    if (iVar2 != iVar1) break;
    _vm_object_cache_object(iVar1,0);
  }
                    /* WARNING: Subroutine does not return */
  _panic(aVmObjectDeacti);
}
/* GHIDRADEC_FUNCTION index=1797 start=0x405fdae */

undefined4 _vm_object_cache_object(int param_1,byte param_2)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    uVar1 = 4;
  }
  else {
    *(uint *)(param_1 + 0x42) = *(uint *)(param_1 + 0x42) & 0xefffffff | (param_2 & 1) << 0x1c;
    _vm_object_deallocate(param_1);
    uVar1 = 0;
  }
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=1798 start=0x405fdda */

void _vm_object_shutdown(void)

{
  _vm_object_cache_clear();
  return;
}
/* GHIDRADEC_FUNCTION index=1799 start=0x405fde8 */

void _vm_object_pmap_copy(undefined4 *param_1,uint param_2,uint param_3)

{
  undefined4 *puVar1;
  
  if (param_1 != (undefined4 *)0x0) {
    for (puVar1 = (undefined4 *)*param_1; puVar1 != param_1; puVar1 = (undefined4 *)puVar1[2]) {
      if (((param_2 <= (uint)puVar1[6]) && ((uint)puVar1[6] < param_3)) &&
         ((*(byte *)((int)puVar1 + 0x21) & 0x20) == 0)) {
        _pmap_copy_on_write(*(undefined4 *)((int)puVar1 + 0x22));
        *(byte *)((int)puVar1 + 0x21) = *(byte *)((int)puVar1 + 0x21) | 0x20;
      }
    }
  }
  return;
}

