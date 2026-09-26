
uint * _zget_space(undefined8 *param_1,uint param_2,undefined4 param_3)

{
  uint *puVar1;
  uint *puVar2;
  uint *puVar3;
  uint uVar4;
  int iVar5;
  uint unaff_D3;
  uint *puVar6;
  int iStack_8;
  
  iStack_8 = 0;
  if (param_1 == (undefined8 *)0x0) {
    param_1 = &__zone_default_space;
  }
  if (param_2 < 0x11) {
    uVar4 = 0x10;
  }
  else {
    uVar4 = param_2 + 0xf & 0xfffffff0;
  }
  do {
    puVar3 = (uint *)sub_4054F1C(param_1,uVar4);
    if (puVar3 != (uint *)0x0) {
      puVar2 = (uint *)puVar3[2];
      if (puVar3[1] - uVar4 < 0x10) {
        uVar4 = *puVar3;
        *puVar2 = uVar4;
        if (uVar4 != 0) {
          *(uint **)(*puVar3 + 8) = puVar2;
        }
        *(int *)((int)param_1 + 0xc) = *(int *)((int)param_1 + 0xc) + -1;
      }
      else {
        puVar1 = (uint *)((int)puVar3 + uVar4);
        puVar1[1] = puVar3[1] - uVar4;
        uVar4 = *puVar3;
        *puVar1 = uVar4;
        if (uVar4 != 0) {
          *(uint **)(uVar4 + 8) = puVar1;
        }
        puVar1[2] = (uint)puVar2;
        *puVar2 = (uint)puVar1;
        uVar4 = puVar1[1] >> (*(uint *)(param_1 + 2) & 0x3f);
        if ((int)*(uint *)(param_1 + 3) < (int)uVar4) {
          uVar4 = *(uint *)(param_1 + 3);
        }
        puVar6 = (uint *)(uVar4 * 0x10 + *(int *)((int)param_1 + 0x14) + -0x10);
        puVar2 = (uint *)*puVar6;
        if ((puVar2 == (uint *)0x0) || (puVar1 < puVar2)) {
          *puVar6 = (uint)puVar1;
        }
      }
loc_40556AE:
      if (iStack_8 == 0) {
        return puVar3;
      }
      _kmem_free(_zone_map,iStack_8,unaff_D3);
      return puVar3;
    }
    if (iStack_8 != 0) {
      puVar3 = (uint *)_zone_free_space_add(param_1,uVar4,iStack_8,unaff_D3);
      iStack_8 = 0;
      goto loc_40556AE;
    }
    unaff_D3 = ~_page_mask & _page_mask + uVar4;
    if (unaff_D3 <= _zdata_size) {
      _zdata_size = _zdata_size - unaff_D3;
      puVar3 = (uint *)_zone_free_space_add(param_1,uVar4,_zdata + _zdata_size,unaff_D3);
      goto loc_40556AE;
    }
    iVar5 = _kmem_alloc_zone(_zone_map,&iStack_8,unaff_D3,param_3);
    if (iVar5 != 0) {
      return (uint *)0x0;
    }
  } while( true );
}
