/* GHIDRADEC_FUNCTION index=3125 start=0x4088078 */

undefined4 sub_4088078(undefined4 *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  if (param_1[7] != param_1[8]) {
    uVar3 = 0;
    if ((*(byte *)((int)param_1 + 0x2d) & 0x40) == 0) {
      uVar3 = 2;
    }
    sub_4087F1E(param_1[7],_page_size,uVar3,*(byte *)((int)param_1 + 0x2d) & 1);
    *(int *)(param_2 + 0x20) = *(int *)(param_2 + 0x20) - _page_size;
  }
  if ((*(byte *)((int)param_1 + 0x2d) & 0x40) == 0) {
    if (param_1[1] != 0) {
      _vm_deallocate(dword_40C6EBC,*param_1,param_1[1]);
    }
    if (*(char *)(param_1 + 0xb) < '\0') {
      _snd_reply_completed(param_1[6],*(undefined4 *)((int)param_1 + 0x2e));
    }
  }
  else if (param_1[1] != 0) {
    _snd_reply_recorded_data(param_1[6],*(undefined4 *)((int)param_1 + 0x2e),*param_1,param_1[1],0);
  }
  iVar1 = *(int *)(param_2 + 0xc);
  iVar2 = *(int *)(iVar1 + 0x32);
  if (iVar2 == param_2 + 0xc) {
    *(int *)(param_2 + 0x10) = iVar2;
  }
  else {
    *(int *)(iVar2 + 0x36) = param_2 + 0xc;
  }
  *(int *)(param_2 + 0xc) = iVar2;
  _kfree(iVar1,0x3e);
  return *(undefined4 *)(param_2 + 0xc);
}
/* GHIDRADEC_FUNCTION index=3126 start=0x408815a */

uint * sub_408815A(uint *param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  undefined4 *puVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint *puVar7;
  int iStack_8;
  
  puVar7 = (uint *)_kalloc(0x3e);
  *(byte *)(param_1 + 0xb) = *(byte *)(param_1 + 0xb) & 0xfd;
  _bcopy(param_1,puVar7,0x3e);
  *(byte *)((int)param_1 + 0x2d) = *(byte *)((int)param_1 + 0x2d) & 0xef;
  *(byte *)(param_1 + 0xb) = *(byte *)(param_1 + 0xb) & 0xdf;
  uVar1 = *param_1;
  uVar4 = param_1[4] - uVar1;
  *param_1 = uVar4 + uVar1;
  param_1[1] = param_1[2] - (uVar4 + uVar1);
  uVar2 = _page_mask;
  uVar6 = ~_page_mask;
  param_1[7] = uVar6 & *param_1;
  if (param_1[4] % _page_size == 0) {
    puVar7[2] = param_1[4];
    puVar7[1] = puVar7[2] - *puVar7;
    puVar7[8] = puVar7[2];
    puVar7[7] = puVar7[2];
  }
  else {
    iVar5 = (uVar6 & uVar2 + param_1[4]) - (uVar6 & uVar1);
    uVar2 = param_1[4];
    _vm_allocate(dword_40C6EBC,&iStack_8,iVar5,1);
    _vm_copy(dword_40C6EBC,uVar1 & ~_page_mask,iVar5,iStack_8);
    if ((*(byte *)((int)param_1 + 0x2d) & 8) != 0) {
      _vm_deallocate(dword_40C6EBC,iStack_8,iVar5);
      _kfree(puVar7,0x3e);
      *param_1 = uVar1;
      param_1[1] = param_1[2] - uVar1;
      return param_1;
    }
    if (_page_size <= uVar4) {
      _vm_deallocate(dword_40C6EBC,uVar1 & ~_page_mask,(uVar6 & uVar2) - (uVar6 & uVar1));
    }
    *puVar7 = iStack_8 + uVar1 % _page_size;
    puVar7[1] = uVar4;
    puVar7[2] = uVar4 + *puVar7;
    uVar1 = ~_page_mask & _page_mask + uVar4 + *puVar7;
    puVar7[7] = uVar1;
    puVar7[8] = uVar1;
  }
  puVar7[4] = puVar7[2];
  puVar7[3] = puVar7[4];
  *(byte *)((int)puVar7 + 0x2d) = *(byte *)((int)puVar7 + 0x2d) | 8;
  *(uint **)((int)puVar7 + 0x32) = param_1;
  *(uint **)((int)param_1 + 0x36) = puVar7;
  puVar3 = *(undefined4 **)((int)puVar7 + 0x36);
  if (puVar3 == (undefined4 *)(param_2 + 0xc)) {
    *puVar3 = puVar7;
  }
  else {
    *(uint **)((int)puVar3 + 0x32) = puVar7;
  }
  return puVar7;
}
/* GHIDRADEC_FUNCTION index=3127 start=0x408856e */

void sub_408856E(void)

{
  return;
}
/* GHIDRADEC_FUNCTION index=3128 start=0x4088588 */

void sub_4088588(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(sword *)(*(int *)(param_1 + 0x10) + 4) * 0x166;
  _bzero(_st_std + iVar2,0x166);
  *(int *)(_st_std + iVar2) = param_1;
  *(uint *)(_st_std + iVar2 + 0x10) = iVar2 + 0x40c6856U & 0xfffffff0;
  *(uint *)(_st_std + iVar2 + 4) = iVar2 + 0x40c6805U & 0xfffffff0;
  *(uint *)(_st_std + iVar2 + 8) = iVar2 + 0x40c687fU & 0xfffffff0;
  *(uint *)(_st_std + iVar2 + 0xc) = iVar2 + 0x40c6896U & 0xfffffff0;
  *(undefined2 *)(_st_std + iVar2 + 0x66) = 0;
  iVar1 = iVar2 + 0x40c67ee;
  *(int *)(_st_std + iVar2 + 0x82) = iVar1;
  *(int *)iVar1 = iVar1;
  _st_std[iVar2 + 0x7d] = 0;
  return;
}
/* GHIDRADEC_FUNCTION index=3129 start=0x4088782 */

void sub_4088782(int *param_1,undefined4 param_2)

{
  uint uVar1;
  undefined uStack_56;
  uint3 uStack_55;
  undefined uStack_52;
  undefined4 uStack_4a;
  int iStack_46;
  undefined4 uStack_42;
  undefined4 uStack_3e;
  
  _bzero(&uStack_56,0x52);
  iStack_46 = param_1[1];
  uStack_56 = 0x12;
  uVar1 = (uint)_uStack_55 >> 8;
  _uStack_55 = CONCAT31((uint3)uVar1 & 0x1fffff |
                        (uint3)(((uint)*(byte *)(*param_1 + 0x1d) << 0x1d) >> 8),0x42);
  uStack_42 = 0x42;
  uStack_4a = 0;
  uStack_3e = 0x78;
  sub_40895AC(param_1,&uStack_56,param_2);
  return;
}
/* GHIDRADEC_FUNCTION index=3130 start=0x40887ea */

void sub_40887EA(int *param_1,undefined4 param_2)

{
  undefined uStack_56;
  uint uStack_55;
  undefined4 uStack_46;
  undefined4 uStack_3e;
  undefined4 uStack_1a;
  
  _bzero(&uStack_56,0x52);
  uStack_56 = 0;
  uStack_55 = uStack_55 & 0x1fffffff | (uint)*(byte *)(*param_1 + 0x1d) << 0x1d;
  uStack_3e = 0x78;
  uStack_46 = 0;
  uStack_1a = 0;
  sub_40895AC(param_1,&uStack_56,param_2);
  return;
}
/* GHIDRADEC_FUNCTION index=3131 start=0x4088840 */

void sub_4088840(int *param_1)

{
  undefined uStack_56;
  undefined4 uStack_55;
  undefined4 uStack_3e;
  
  _bzero(&uStack_56,0x52);
  uStack_56 = 0x10;
  uStack_55._0_1_ =
       uStack_55._0_1_ & 0x1f | (byte)(((uint)*(byte *)(*param_1 + 0x1d) << 0x1d) >> 0x18);
  uStack_55 = (uint)uStack_55._0_1_ << 0x18;
  uStack_55 = CONCAT31(uStack_55._0_3_,1);
  uStack_3e = 0x78;
  sub_40895AC(param_1,&uStack_56,0);
  return;
}
/* GHIDRADEC_FUNCTION index=3132 start=0x4088898 */

void sub_4088898(int *param_1)

{
  undefined uStack_56;
  uint uStack_55;
  undefined4 uStack_46;
  undefined4 uStack_3e;
  undefined4 uStack_1a;
  
  _bzero(&uStack_56,0x52);
  uStack_56 = 1;
  uStack_55 = uStack_55 & 0x1fffffff | (uint)*(byte *)(*param_1 + 0x1d) << 0x1d;
  uStack_3e = 300;
  uStack_46 = 0;
  uStack_1a = 0;
  sub_40895AC(param_1,&uStack_56,0);
  return;
}
/* GHIDRADEC_FUNCTION index=3133 start=0x40888f0 */

void sub_40888F0(int *param_1,undefined4 param_2)

{
  uint uVar1;
  undefined uStack_56;
  uint3 uStack_55;
  undefined uStack_52;
  undefined4 uStack_4a;
  int iStack_46;
  undefined4 uStack_42;
  undefined4 uStack_3e;
  
  _bzero(&uStack_56,0x52);
  iStack_46 = param_1[4];
  uStack_56 = 3;
  uVar1 = (uint)_uStack_55 >> 8;
  _uStack_55 = CONCAT31((uint3)uVar1 & 0x1fffff |
                        (uint3)(((uint)*(byte *)(*param_1 + 0x1d) << 0x1d) >> 8),0x1a);
  uStack_42 = 0x1a;
  uStack_4a = 0;
  uStack_3e = 0x78;
  sub_40895AC(param_1,&uStack_56,param_2);
  return;
}
/* GHIDRADEC_FUNCTION index=3134 start=0x4088958 */

void sub_4088958(int *param_1,int param_2,undefined4 param_3)

{
  uint uVar1;
  undefined uStack_56;
  uint3 uStack_55;
  undefined uStack_52;
  undefined4 uStack_4a;
  int iStack_46;
  undefined4 uStack_42;
  undefined4 uStack_3e;
  
  _bzero(&uStack_56,0x52);
  uStack_56 = 0x15;
  uVar1 = (uint)_uStack_55 >> 8;
  uStack_42 = *(undefined4 *)(param_2 + 0x3c);
  _uStack_55 = CONCAT31((uint3)uVar1 & 0x1fffff |
                        (uint3)(((uint)*(byte *)(*param_1 + 0x1d) << 0x1d) >> 8),(char)uStack_42);
  iStack_46 = param_2;
  uStack_4a = 1;
  uStack_3e = 0x78;
  sub_40895AC(param_1,&uStack_56,param_3);
  return;
}
/* GHIDRADEC_FUNCTION index=3135 start=0x40889c2 */

void sub_40889C2(int *param_1,int param_2,undefined4 param_3)

{
  uint uVar1;
  undefined uStack_56;
  uint3 uStack_55;
  undefined uStack_52;
  undefined4 uStack_4a;
  int iStack_46;
  undefined4 uStack_42;
  undefined4 uStack_3e;
  
  _bzero(&uStack_56,0x52);
  uStack_56 = 0x1a;
  uVar1 = (uint)_uStack_55 >> 8;
  uStack_42 = *(undefined4 *)(param_2 + 0x3c);
  _uStack_55 = CONCAT31((uint3)uVar1 & 0x1fffff |
                        (uint3)(((uint)*(byte *)(*param_1 + 0x1d) << 0x1d) >> 8),(char)uStack_42);
  iStack_46 = param_2;
  uStack_4a = 0;
  uStack_3e = 0x78;
  sub_40895AC(param_1,&uStack_56,param_3);
  return;
}
/* GHIDRADEC_FUNCTION index=3136 start=0x4088a60 */

int sub_4088A60(undefined8 param_1,int param_2)

{
  undefined4 uVar1;
  int *piVar2;
  undefined *puVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  undefined4 uStack_c;
  undefined *puStack_8;
  
  piVar2 = (int *)param_1;
  iVar4 = (param_1._3_4_ >> 0x1b) * 0x166;
  iVar7 = 0;
  if (1 < param_1._3_4_ >> 0x1b) {
    return 6;
  }
  if (piVar2[1] != 1) {
    return 0x16;
  }
  if (*(int *)(*piVar2 + 4) == 0) {
    return 0;
  }
  iVar5 = _kmem_alloc_wired(_kernel_map,&puStack_8,0x52);
  if (iVar5 != 0) {
    return 0xc;
  }
  iVar5 = _kmem_alloc_wired(_kernel_map,&uStack_c,*(undefined4 *)(*piVar2 + 4));
  puVar3 = puStack_8;
  if (iVar5 != 0) {
    _kmem_free(_kernel_map,puStack_8,0x52);
    return 0xc;
  }
  _bzero(puStack_8,0x52);
  *(uint *)(puVar3 + 1) =
       *(uint *)(puVar3 + 1) & 0x1fffffff |
       (uint)*(byte *)(*(int *)(_st_std + iVar4) + 0x1d) << 0x1d;
  if ((_st_std[iVar4 + 0x67] & 4) == 0) {
    uVar1 = *(undefined4 *)(*piVar2 + 4);
    *(undefined4 *)(puStack_8 + 0x14) = uVar1;
    *(sword *)(puVar3 + 2) = (sword)((uint)uVar1 >> 8);
    puVar3[4] = (char)uVar1;
    if (param_2 == 0) {
      puVar3[1] = (byte)(((uint)(byte)puVar3[1] << 0x1e) >> 0x1e) | 2 | puVar3[1] & 0xfc;
    }
  }
  else {
    uVar6 = (*(uint *)(_st_std + iVar4 + 0x70) + *(int *)(*piVar2 + 4) + -1) /
            *(uint *)(_st_std + iVar4 + 0x70);
    *(sword *)(puVar3 + 2) = (sword)(uVar6 >> 8);
    puVar3[4] = (char)uVar6;
    *(uint *)(puVar3 + 1) = *(uint *)(puVar3 + 1) & 0xfcffffff | 0x1000000;
    *(undefined4 *)(puStack_8 + 0x14) = *(undefined4 *)(*piVar2 + 4);
  }
  if (*(uint3 *)(puVar3 + 2) < 0x1000000) {
    *(undefined4 *)(puStack_8 + 0x10) = uStack_c;
    *(undefined4 *)(puStack_8 + 0x18) = 0x78;
    *(undefined4 *)(puStack_8 + 0x3c) = 0;
    if (param_2 == 0) {
      *puVar3 = 8;
      *(undefined4 *)(puStack_8 + 0xc) = 0;
    }
    else {
      *puVar3 = 10;
      *(undefined4 *)(puStack_8 + 0xc) = 1;
    }
    if ((param_2 != 1) ||
       (iVar7 = _copyinmsg(*(undefined4 *)*piVar2,uStack_c,((undefined4 *)*piVar2)[1]), iVar7 == 0))
    {
      iVar4 = sub_40895AC(_st_std + iVar4,puStack_8,0);
      if (iVar4 == 0) {
        if ((*(int *)(puStack_8 + 0x3c) != 0) && (param_2 == 0)) {
          iVar7 = _copyoutmsg(uStack_c,*(undefined4 *)*piVar2,*(int *)(puStack_8 + 0x3c));
        }
        if (*(int *)(puStack_8 + 0x1c) == 0) goto loc_4088C56;
      }
      iVar7 = 5;
    }
  }
  else {
    iVar7 = 0x16;
  }
loc_4088C56:
  *(int *)((int)piVar2 + 0x12) = *(int *)(*piVar2 + 4) - *(int *)(puStack_8 + 0x3c);
  _kmem_free(_kernel_map,puStack_8,0x52);
  _kmem_free(_kernel_map,uStack_c,*(undefined4 *)(*piVar2 + 4));
  *(char *)(dword_40B57D4 + 100) = (char)iVar7;
  return iVar7;
}
/* GHIDRADEC_FUNCTION index=3137 start=0x4089042 */

void sub_4089042(int *param_1,int param_2,int param_3)

{
  int iVar1;
  int *piVar2;
  undefined4 *puVar3;
  int *piVar4;
  
  piVar4 = (int *)((int)param_1 + 0x7e);
  if (piVar4 == (int *)*piVar4) {
                    /* WARNING: Subroutine does not return */
    _panic(aStdoneNoBufOnS);
  }
  *(undefined *)((int)param_1 + 0x7d) = 0;
  iVar1 = *piVar4;
  piVar2 = *(int **)(iVar1 + 0x4a);
  puVar3 = *(undefined4 **)(iVar1 + 0x4e);
  if (piVar2 == piVar4) {
    *(undefined4 **)((int)param_1 + 0x82) = puVar3;
  }
  else {
    *(undefined4 **)((int)piVar2 + 0x4e) = puVar3;
  }
  if (puVar3 == (undefined4 *)((int)param_1 + 0x7e)) {
    *puVar3 = piVar2;
  }
  else {
    *(int **)((int)puVar3 + 0x4a) = piVar2;
  }
  *(int *)(iVar1 + 0x3c) = *(int *)(iVar1 + 0x14) - param_2;
  *(int *)(iVar1 + 0x1c) = param_3;
  if (param_3 == 2) {
    *(undefined *)(iVar1 + 0x20) = 2;
  }
  else {
    *(undefined *)(iVar1 + 0x20) = *(undefined *)(*param_1 + 0x4e);
  }
  if ((int *)((int)param_1 + 0x7e) != *(int **)((int)param_1 + 0x7e)) {
    _scsi_dstart(*param_1);
  }
  if ((*(word *)((int)param_1 + 0x66) & 1) == 0) {
    *(byte *)(iVar1 + 0x48) = *(byte *)(iVar1 + 0x48) | 1;
    _wakeup(iVar1);
  }
  else {
    *(word *)((int)param_1 + 0x66) = *(word *)((int)param_1 + 0x66) & 0xfffe;
  }
  return;
}
/* GHIDRADEC_FUNCTION index=3138 start=0x408935a */

undefined4 sub_408935A(undefined8 param_1)

{
  undefined2 *puVar1;
  undefined *puVar2;
  int iVar3;
  undefined4 uVar4;
  undefined *puStack_8;
  
  puVar1 = (undefined2 *)param_1;
  iVar3 = _kmem_alloc_wired(_kernel_map,&puStack_8,0x52);
  puVar2 = puStack_8;
  if (iVar3 != 0) {
    return 0xc;
  }
  _bzero(puStack_8,0x52);
  *(uint *)(puVar2 + 1) =
       *(uint *)(puVar2 + 1) & 0x1fffffff |
       (uint)*(byte *)(*(int *)(_st_std + (sword)((word)((qword)param_1 >> 0x18) >> 0xb) * 0x166) +
                      0x1d) << 0x1d;
  *(undefined4 *)(puStack_8 + 0x18) = 0x78;
  switch(*puVar1) {
  case :
    *puVar2 = 0x10;
    break;
  case :
    *puVar2 = 0x11;
    puVar2[1] = puVar2[1] & 0xfd | 1;
    *(int *)(puStack_8 + 0x18) = *(int *)(puVar1 + 1) * 600;
    break;
  case :
    *puVar2 = 0x11;
    puVar2[1] = puVar2[1] & 0xfd | 1;
    *(int *)(puStack_8 + 0x18) = *(int *)(puVar1 + 1) * 600;
    goto loc_40894A0;
  case :
    *puVar2 = 0x11;
    puVar2[1] = puVar2[1] & 0xfc;
    *(undefined4 *)(puStack_8 + 0x18) = 0x3c;
    break;
  case :
    *puVar2 = 0x11;
    puVar2[1] = puVar2[1] & 0xfc;
    *(undefined4 *)(puStack_8 + 0x18) = 0x3c;
loc_40894A0:
    iVar3 = -*(int *)(puVar1 + 1);
    goto loc_40894A6;
  case :
    *puVar2 = 1;
    goto loc_40894BE;
  case :
    *puVar2 = 0x1b;
loc_40894BE:
    *(undefined4 *)(puStack_8 + 0x18) = 300;
    goto loc_40894D2;
  :
    uVar4 = 0x16;
    goto loc_40894F0;
  }
  iVar3 = *(int *)(puVar1 + 1);
loc_40894A6:
  *(sword *)(puVar2 + 2) = (sword)((uint)iVar3 >> 8);
  puVar2[4] = (char)iVar3;
loc_40894D2:
  *(undefined4 *)(puStack_8 + 0x10) = 0;
  *(undefined4 *)(puStack_8 + 0x3c) = 0;
  uVar4 = sub_40895AC(_st_std + (sword)((word)((qword)param_1 >> 0x18) >> 0xb) * 0x166,puStack_8,0);
loc_40894F0:
  _kmem_free(_kernel_map,puStack_8,0x52);
  return uVar4;
}
/* GHIDRADEC_FUNCTION index=3139 start=0x4089510 */

int sub_4089510(int param_1,int param_2,undefined4 param_3)

{
  undefined *puVar1;
  uint *puVar2;
  int iVar3;
  
  *(undefined4 *)(*(int *)(param_1 + 0xc) + 0x3c) = 0xc;
  iVar3 = sub_40889C2(param_1,*(undefined4 *)(param_1 + 0xc),param_3);
  if (iVar3 == 0) {
    puVar1 = *(undefined **)(param_1 + 0xc);
    *puVar1 = 0;
    puVar1[1] = 0;
    puVar1[2] = puVar1[2] & 0x7f;
    puVar1[3] = 8;
    puVar2 = (uint *)(*(int *)(param_1 + 0xc) + 9);
    *puVar2 = *puVar2 & 0xff | param_2 << 8;
    puVar2 = (uint *)(*(int *)(param_1 + 0xc) + 4);
    *puVar2 = *puVar2 & 0xff000000;
    iVar3 = sub_4088958(param_1,*(undefined4 *)(param_1 + 0xc),param_3);
    if (iVar3 == 0) {
      if (param_2 == 0) {
        *(word *)(param_1 + 0x66) = *(word *)(param_1 + 0x66) & 0xfffb;
      }
      else {
        *(word *)(param_1 + 0x66) = *(word *)(param_1 + 0x66) | 4;
        *(int *)(param_1 + 0x70) = param_2;
      }
      iVar3 = 0;
    }
  }
  return iVar3;
}
/* GHIDRADEC_FUNCTION index=3140 start=0x40895ac */

undefined4 sub_40895AC(undefined4 param_1,undefined *param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = sub_4089628(param_1,param_2,param_3);
  if ((iVar1 == 0) && (*(int *)(param_2 + 0x1c) != 0)) {
    if (param_3 == 0) {
      _printf(aStCmd0xXSrIoSt,*param_2,*(int *)(param_2 + 0x1c));
      if (*(int *)(param_2 + 0x1c) == 2) {
        _printf(aSenseKey0xXSen,param_2[0x24] & 0xf,param_2[0x2e]);
      }
    }
    uVar2 = 5;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}
/* GHIDRADEC_FUNCTION index=3141 start=0x4089628 */

int sub_4089628(int *param_1,char *param_2,int param_3)

{
  undefined4 *puVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = *param_1;
  if (param_3 == 1) {
    param_1[0x1a] = 0x32;
  }
  else {
    param_1[0x1a] = 0;
  }
  puVar1 = *(undefined4 **)((int)param_1 + 0x82);
  if (puVar1 == (undefined4 *)((int)param_1 + 0x7e)) {
    *puVar1 = param_2;
  }
  else {
    *(char **)((int)puVar1 + 0x4a) = param_2;
  }
  *(undefined4 **)(param_2 + 0x4e) = puVar1;
  *(int *)(param_2 + 0x4a) = (int)param_1 + 0x7e;
  *(char **)((int)param_1 + 0x82) = param_2;
  iVar4 = 0;
  if (param_3 == 0) {
    param_2[0x48] = param_2[0x48] & 0xfe;
  }
  else {
    *(word *)((int)param_1 + 0x66) = *(word *)((int)param_1 + 0x66) | 1;
  }
  if ((*(byte *)(iVar3 + 0x24) & 0x20) == 0) {
    iVar4 = _scsi_dstart(iVar3);
  }
  if (iVar4 == 0) {
    if (param_3 == 0) {
      bVar2 = param_2[0x48];
      while ((bVar2 & 1) == 0) {
        _sleep(param_2,0x14);
        bVar2 = param_2[0x48];
      }
    }
    else {
      iVar3 = 0;
      *(word *)((int)param_1 + 0x66) = *(word *)((int)param_1 + 0x66) | 1;
      do {
        iVar3 = iVar3 + 1;
        if (iVar3 < 0x3e9) {
          _delay(1000);
        }
        else {
          _scsi_timeout(*(undefined4 *)(*param_1 + 0x18));
          iVar3 = 0;
        }
      } while ((*(byte *)((int)param_1 + 0x67) & 1) != 0);
    }
    if ((*(int *)(param_2 + 0x1c) != 0) && (param_3 != 0)) {
      iVar4 = 5;
    }
  }
  else {
    *(word *)((int)param_1 + 0x66) = *(word *)((int)param_1 + 0x66) & 0xfffe;
  }
  puVar1 = (undefined4 *)param_1[4];
  *(undefined4 *)(param_2 + 0x22) = *puVar1;
  *(undefined4 *)(param_2 + 0x26) = puVar1[1];
  *(undefined4 *)(param_2 + 0x2a) = puVar1[2];
  *(undefined4 *)(param_2 + 0x2e) = puVar1[3];
  *(undefined4 *)(param_2 + 0x32) = puVar1[4];
  *(undefined4 *)(param_2 + 0x36) = puVar1[5];
  *(undefined2 *)(param_2 + 0x3a) = *(undefined2 *)(puVar1 + 6);
  if (((iVar4 == 0) && (*(int *)(param_2 + 0x1c) == 0)) && (*param_2 == '\n')) {
    *(word *)((int)param_1 + 0x66) = *(word *)((int)param_1 + 0x66) | 8;
  }
  else {
    *(word *)((int)param_1 + 0x66) = *(word *)((int)param_1 + 0x66) & 0xfff7;
  }
  return iVar4;
}
/* GHIDRADEC_FUNCTION index=3142 start=0x4089c56 */

void sub_4089C56(void)

{
  uint uVar1;
  undefined uStack_24;
  uint uStack_23;
  
  if (_evOpenCalled == 0) {
    _nvram_check(&uStack_24);
    uVar1 = (uStack_23 & 0xfffffff) >> 0x16;
  }
  else if ((_autoDimmed == 0) ||
          (uVar1 = _dimmedBrightness, (int)_curBright <= (int)_dimmedBrightness)) {
    uVar1 = _curBright;
  }
  _vidSetBrightness(uVar1);
  return;
}
/* GHIDRADEC_FUNCTION index=3143 start=0x4089eb6 */

int sub_4089EB6(void)

{
  int iVar1;
  uint uStack_8;
  
  if (_dma_chip == 0x139) {
    uStack_8 = _slot_id + 0xb000000;
  }
  else {
    uStack_8 = _slot_id + 0xc000000;
  }
  uStack_8 = uStack_8 & 0xff000000;
  iVar1 = _vm_allocate(*(undefined4 *)(*(int *)(_active_threads + 0xc) + 8),&uStack_8,0x1000000,0);
  if (iVar1 == 0) {
    _pmap_tt(_active_threads,1,uStack_8,0x1000000,0);
    if (_dma_chip == 0x139) {
      iVar1 = _slot_id + 0xb000000;
    }
    else {
      iVar1 = _slot_id + 0xc000000;
    }
  }
  else {
    iVar1 = 0;
  }
  return iVar1;
}
/* GHIDRADEC_FUNCTION index=3144 start=0x4089f58 */

void sub_4089F58(void)

{
  uint uVar1;
  
  if (_dma_chip == 0x139) {
    uVar1 = _slot_id + 0xb000000;
  }
  else {
    uVar1 = _slot_id + 0xc000000;
  }
  _vm_deallocate(*(undefined4 *)(*(int *)(_active_threads + 0xc) + 8),uVar1 & 0xff000000,0x1000000);
  _pmap_tt(_active_threads,0,0,0,0);
  return;
}
/* GHIDRADEC_FUNCTION index=3145 start=0x4089fba */

void sub_4089FBA(void)

{
  bool bVar1;
  sword sVar2;
  uint uVar3;
  int *piVar4;
  sword sVar6;
  int iVar5;
  sword sVar7;
  uint uVar8;
  uint *puVar9;
  uint *puVar10;
  uint *puVar11;
  uint *puVar12;
  uint *puVar13;
  uint *puVar14;
  int iStack_c;
  
  piVar4 = dword_40B518C;
  uVar8 = dword_40B518C[9];
  if (*(sword *)(dword_40B518C + 9) < (sword)*(word *)(dword_40B518C + 0xd)) {
    uVar8 = uVar8 & 0xffff | (uint)*(word *)(dword_40B518C + 0xd) << 0x10;
  }
  if (*(sword *)((int)dword_40B518C + 0x36) < (sword)uVar8) {
    uVar8 = CONCAT22((sword)(uVar8 >> 0x10),*(sword *)((int)dword_40B518C + 0x36));
  }
  sVar7 = *(sword *)(dword_40B518C + 0xc) +
          (*(sword *)(dword_40B518C + 8) - *(sword *)(dword_40B518C + 0xc) & 0xfff0U);
  sVar2 = sVar7 + 0x20;
  dword_40B518C[3] = CONCAT22(sVar7,sVar2);
  piVar4[4] = uVar8;
  iStack_c = 0x46;
  if (_dma_chip == 0x139) {
    iStack_c = 0x48;
  }
  sVar6 = (sword)(uVar8 >> 0x10);
  iVar5 = iStack_c * ((int)sVar6 - (int)*(sword *)(piVar4 + 0xd)) * 4;
  if (_dma_chip == 0x139) {
    iVar5 = iVar5 + 0xb000000;
  }
  else {
    iVar5 = iVar5 + 0xc000000;
  }
  puVar14 = (uint *)(((int)sVar7 - (int)*(sword *)(piVar4 + 0xc) >> 4) * 4 + _slot_id + iVar5);
  iVar5 = (*(word *)(dword_40B518C + 8) & 0xf) * 2;
  uVar3 = (*(word *)(dword_40B518C + 8) & 0xf) * -2 + 0x20;
  puVar11 = (uint *)(dword_40B518C + 0x92);
  puVar13 = (uint *)(dword_40B518C +
                    *dword_40B518C * 0x10 + (sword)(sVar6 - *(sword *)(dword_40B518C + 9)) + 0x12);
  puVar12 = (uint *)(dword_40B518C +
                    *dword_40B518C * 0x10 + (sword)(sVar6 - *(sword *)(dword_40B518C + 9)) + 0x52);
  bVar1 = *(sword *)((int)dword_40B518C + 0x32) < sVar2;
  sVar2 = (sword)uVar8;
  if (sVar7 < *(sword *)(dword_40B518C + 0xc)) {
    if ((!bVar1) && (sVar7 = (sVar2 - sVar6) + -1, sVar7 != -1)) {
      puVar14 = puVar14 + 1;
      do {
        uVar8 = *puVar14;
        *puVar11 = uVar8;
        *puVar14 = *puVar13 << (uVar3 & 0x3f) | ~(*puVar12 << (uVar3 & 0x3f)) & uVar8;
        puVar14 = puVar14 + iStack_c;
        sVar7 = sVar7 + -1;
        puVar11 = puVar11 + 1;
        puVar12 = puVar12 + 1;
        puVar13 = puVar13 + 1;
      } while (sVar7 != -1);
    }
  }
  else if (bVar1) {
    sVar2 = sVar2 - sVar6;
    while (sVar2 = sVar2 + -1, sVar2 != -1) {
      uVar8 = *puVar14;
      *puVar11 = uVar8;
      *puVar14 = *puVar13 >> iVar5 | ~(*puVar12 >> iVar5) & uVar8;
      puVar14 = puVar14 + iStack_c;
      puVar11 = puVar11 + 1;
      puVar13 = puVar13 + 1;
      puVar12 = puVar12 + 1;
    }
  }
  else {
    sVar7 = (sVar2 - sVar6) + -1;
    if (sVar7 != -1) {
      puVar9 = puVar14 + 1;
      do {
        uVar8 = *puVar14;
        puVar10 = puVar11 + 1;
        *puVar11 = uVar8;
        *puVar14 = *puVar13 >> iVar5 | ~(*puVar12 >> iVar5) & uVar8;
        uVar8 = *puVar9;
        puVar11 = puVar11 + 2;
        *puVar10 = uVar8;
        *puVar9 = *puVar13 << (uVar3 & 0x3f) | ~(*puVar12 << (uVar3 & 0x3f)) & uVar8;
        puVar9 = puVar9 + iStack_c;
        puVar14 = puVar14 + iStack_c;
        sVar7 = sVar7 + -1;
        puVar12 = puVar12 + 1;
        puVar13 = puVar13 + 1;
      } while (sVar7 != -1);
    }
  }
  return;
}
/* GHIDRADEC_FUNCTION index=3146 start=0x408a18e */

void sub_408A18E(void)

{
  bool bVar1;
  bool bVar2;
  sword sVar4;
  int iVar3;
  word wVar5;
  sword sVar6;
  uint unaff_D6;
  int iVar7;
  uint *puVar8;
  uint *puVar9;
  uint *puVar10;
  uint unaff_A5;
  
  iVar7 = 0x46;
  if (_dma_chip == 0x139) {
    iVar7 = 0x48;
  }
  sVar6 = (sword)((uint)*(undefined4 *)(dword_40B518C + 0x10) >> 0x10);
  iVar3 = iVar7 * ((int)sVar6 - (int)*(sword *)(dword_40B518C + 0x34)) * 4;
  sVar4 = (sword)((uint)*(undefined4 *)(dword_40B518C + 0xc) >> 0x10);
  if (_dma_chip == 0x139) {
    iVar3 = iVar3 + 0xb000000;
  }
  else {
    iVar3 = iVar3 + 0xc000000;
  }
  puVar10 = (uint *)(((int)sVar4 - (int)*(sword *)(dword_40B518C + 0x30) >> 4) * 4 +
                    _slot_id + iVar3);
  puVar9 = (uint *)(dword_40B518C + 0x248);
  bVar1 = sVar4 < *(sword *)(dword_40B518C + 0x30);
  if (!bVar1) {
    unaff_D6 = *(uint *)(unk_40B2340 + ((int)*(sword *)(dword_40B518C + 0x28) - (int)sVar4) * 4);
  }
  sVar4 = (sword)*(undefined4 *)(dword_40B518C + 0xc);
  bVar2 = *(sword *)(dword_40B518C + 0x32) < sVar4;
  if (!bVar2) {
    unaff_A5 = ~*(uint *)(unk_40B2340 +
                         (0x10 - ((int)sVar4 - (int)*(sword *)(dword_40B518C + 0x2a))) * 4);
  }
  sVar4 = (sword)*(undefined4 *)(dword_40B518C + 0x10);
  if (bVar1) {
    if ((!bVar2) && (iVar3 = ((int)sVar4 - (int)sVar6) + -1, iVar3 != -1)) {
      do {
        do {
          puVar8 = puVar9 + 1;
          puVar10[1] = unaff_A5 & *puVar9 | ~unaff_A5 & puVar10[1];
          puVar10 = puVar10 + iVar7;
          wVar5 = (word)((uint)iVar3 >> 0x10);
          sVar6 = (sword)iVar3 + -1;
          iVar3 = CONCAT22(wVar5,sVar6);
          puVar9 = puVar8;
        } while (sVar6 != -1);
        iVar3 = (uint)wVar5 * 0x10000 + -1;
      } while (wVar5 != 0);
    }
  }
  else if (bVar2) {
    iVar3 = ((int)sVar4 - (int)sVar6) + -1;
    if (iVar3 != -1) {
      do {
        do {
          puVar8 = puVar9 + 1;
          *puVar10 = unaff_D6 & *puVar9 | ~unaff_D6 & *puVar10;
          puVar10 = puVar10 + iVar7;
          wVar5 = (word)((uint)iVar3 >> 0x10);
          sVar6 = (sword)iVar3 + -1;
          iVar3 = CONCAT22(wVar5,sVar6);
          puVar9 = puVar8;
        } while (sVar6 != -1);
        iVar3 = (uint)wVar5 * 0x10000 + -1;
      } while (wVar5 != 0);
    }
  }
  else {
    iVar3 = ((int)sVar4 - (int)sVar6) + -1;
    if (iVar3 != -1) {
      do {
        do {
          puVar8 = puVar9 + 1;
          *puVar10 = unaff_D6 & *puVar9 | ~unaff_D6 & *puVar10;
          puVar9 = puVar9 + 2;
          puVar10[1] = unaff_A5 & *puVar8 | ~unaff_A5 & puVar10[1];
          puVar10 = puVar10 + iVar7;
          wVar5 = (word)((uint)iVar3 >> 0x10);
          sVar6 = (sword)iVar3 + -1;
          iVar3 = CONCAT22(wVar5,sVar6);
        } while (sVar6 != -1);
        iVar3 = (uint)wVar5 * 0x10000 + -1;
      } while (wVar5 != 0);
    }
  }
  return;
}
/* GHIDRADEC_FUNCTION index=3147 start=0x408a330 */

void sub_408A330(int param_1)

{
  *_brightness = unk_40B2380[param_1] | 0x40;
  return;
}
/* GHIDRADEC_FUNCTION index=3148 start=0x408a352 */

void sub_408A352(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  
  iVar1 = _slot_id;
  puVar3 = (undefined4 *)(_slot_id + 0x2200080);
  uVar2 = 0x538;
  if (_dma_chip != 0x139) {
    uVar2 = 0xd30;
  }
  _install_scanned_intr(uVar2,sub_408A3BC,0);
  if (_dma_chip == 0x139) {
    *(undefined4 *)(iVar1 + 0x2004184) = 0xea;
  }
  else {
    *puVar3 = 0x6000000;
  }
  return;
}
/* GHIDRADEC_FUNCTION index=3149 start=0x408a3bc */

void sub_408A3BC(void)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)(_slot_id + 0x2200080);
  if (_dma_chip == 0x139) {
    *(undefined4 *)(_slot_id + 0x2000180) = 0x100000;
  }
  else {
    *puVar1 = 0x5000000;
  }
  if (dword_40B2286 != (code *)0x0) {
    (*dword_40B2286)(dword_40B5188);
  }
  if (_dma_chip != 0x139) {
    *puVar1 = 0x6000000;
  }
  return;
}

