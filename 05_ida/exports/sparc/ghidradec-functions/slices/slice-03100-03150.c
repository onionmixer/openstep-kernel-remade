/* GHIDRADEC_FUNCTION index=3100 start=0xf00ecde8 */

void _NXSetExceptionRaiser(void *param_1)

{
  off_F012EF84 = param_1;
  return;
}
/* GHIDRADEC_FUNCTION index=3101 start=0xf00ecdf4 */

void * _NXGetExceptionRaiser(void)

{
  return off_F012EF84;
}
/* GHIDRADEC_FUNCTION index=3102 start=0xf00ece00 */

void __NXRaiseError(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
  if (!in_DECOMPILE_MODE) {
    *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
    *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
    *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
    *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
    *(undefined4 *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = unaff_i4;
    *(undefined4 *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = unaff_i5;
    *(undefined4 *)((in_CWP * 0x10 + 6) * 4 + 0x8000) = unaff_fp;
    *(undefined4 *)((in_CWP * 0x10 + 7) * 4 + 0x8000) = unaff_i7;
    *(undefined4 *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = unaff_l0;
    *(undefined4 *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = unaff_l1;
    *(undefined4 *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = unaff_l4;
    *(undefined4 *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = unaff_l5;
    *(undefined4 *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = unaff_l6;
    *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_l7;
  }
  (*off_F012EF84)(param_1,param_2,param_3);
                    /* WARNING: Subroutine does not return */
  _abort();
}
/* GHIDRADEC_FUNCTION index=3103 start=0xf00ece2c */

/* WARNING: Removing unreachable block (ram,0xf00ece74) */
/* WARNING: Removing unreachable block (ram,0xf00eceb4) */
/* WARNING: Removing unreachable block (ram,0xf00ece30) */

void _NXDefaultExceptionRaiser(uint *param_1,undefined4 param_2,undefined4 param_3)

{
  uint *puVar1;
  uint *puVar2;
  undefined *puVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
  if (!in_DECOMPILE_MODE) {
    *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
    *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
    *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
    *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
    *(undefined4 *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = unaff_i4;
    *(undefined4 *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = unaff_i5;
    *(undefined4 *)((in_CWP * 0x10 + 6) * 4 + 0x8000) = unaff_fp;
    *(undefined4 *)((in_CWP * 0x10 + 7) * 4 + 0x8000) = unaff_i7;
    *(undefined4 *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = unaff_l0;
    *(undefined4 *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = unaff_l1;
    *(undefined4 *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = unaff_l4;
    *(undefined4 *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = unaff_l5;
    *(undefined4 *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = unaff_l6;
    *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_l7;
  }
  puVar1 = param_1;
  _current_thread_EXTERNAL();
  puVar3 = unk_F012F048;
  puVar2 = DAT_f012f058;
  do {
    if (puVar2 == puVar1) {
loc_F00ECE80:
      uVar4 = *(uint *)puVar3;
      while( true ) {
        while (uVar4 == 0) {
          if (__NXUncaughtExceptionHandler != (code *)0x0) {
            (*__NXUncaughtExceptionHandler)(param_1,param_2,param_3);
          }
          _panic(aUncaughtExcept);
          uVar4 = *(uint *)puVar3;
        }
        if ((uVar4 & 1) == 0) break;
        iVar5 = ((int)(uVar4 - 1) / 2) * 0xc;
        iVar6 = iVar5 + *(uint *)((int)puVar3 + 4);
        *(uint *)puVar3 = *(uint *)(iVar5 + *(uint *)((int)puVar3 + 4));
        *(int *)((int)puVar3 + 0xc) = (int)((iVar6 - *(uint *)((int)puVar3 + 4)) * -0x55555555) >> 2
        ;
        (**(code **)(iVar6 + 4))(*(undefined4 *)(iVar6 + 8),param_1,param_2,param_3);
        uVar4 = *(uint *)puVar3;
      }
      *(uint **)(uVar4 + 0x78) = param_1;
      *(undefined4 *)(uVar4 + 0x7c) = param_2;
      *(undefined4 *)(uVar4 + 0x80) = param_3;
      *(uint *)puVar3 = *(uint *)(uVar4 + 0x74);
                    /* WARNING: Subroutine does not return */
      _longjmp(uVar4,1);
    }
    puVar3 = *(undefined **)((int)puVar3 + 0x14);
    if ((uint *)puVar3 == (uint *)0x0) {
      sub_F00EC878();
      puVar3 = (undefined *)puVar1;
      goto loc_F00ECE80;
    }
    puVar2 = *(uint **)((int)puVar3 + 0x10);
  } while( true );
}
/* GHIDRADEC_FUNCTION index=3104 start=0xf00ecf70 */

/* WARNING: Removing unreachable block (ram,0xf00ecfc8) */
/* WARNING: Removing unreachable block (ram,0xf00ecf8c) */

qword _NXAllocErrorData(int param_1,int *param_2)

{
  undefined4 *puVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  uint uVar2;
  uint uVar3;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
  if (!in_DECOMPILE_MODE) {
    *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
    *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
    *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
    *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
    *(undefined4 *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = unaff_i4;
    *(undefined4 *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = unaff_i5;
    *(undefined4 *)((in_CWP * 0x10 + 6) * 4 + 0x8000) = unaff_fp;
    *(undefined4 *)((in_CWP * 0x10 + 7) * 4 + 0x8000) = unaff_i7;
    *(undefined4 *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = unaff_l0;
    *(undefined4 *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = unaff_l1;
    *(undefined4 *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = unaff_l4;
    *(undefined4 *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = unaff_l5;
    *(undefined4 *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = unaff_l6;
    *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_l7;
  }
  do {
    do {
    } while (dword_F012F06C != 0);
    puVar1 = &dword_F012F06C;
    _simple_lock_try();
  } while (puVar1 == (undefined4 *)0x0);
  uVar2 = param_1 + dword_F012F068 + 7;
  uVar3 = uVar2 & 0xfffffff8;
  if ((int)dword_F012EF80 < (int)uVar3) {
    _realloc(dword_F012F064,uVar3);
    dword_F012EF80 = uVar3;
  }
  *param_2 = dword_F012F064 + dword_F012F068;
  dword_F012F068 = uVar3;
  dword_F012F06C = 0;
  return CONCAT44(param_2,uVar2) & 0xfffffffffffffff8;
}
/* GHIDRADEC_FUNCTION index=3105 start=0xf00ed004 */

void _NXResetErrorData(void)

{
  dword_F012F068 = 0;
  return;
}
/* GHIDRADEC_FUNCTION index=3106 start=0xf00ed164 */

/* WARNING: Removing unreachable block (ram,0xf00ed19c) */
/* WARNING: Removing unreachable block (ram,0xf00ed188) */

undefined8 _NXCreateHashTable(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  undefined4 unaff_l0;
  undefined *puVar2;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  undefined auStackX_0 [92];
  
  if (!in_DECOMPILE_MODE) {
    *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
    *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
    *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
    *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
    *(undefined4 *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = unaff_i4;
    *(undefined4 *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = unaff_i5;
    *(undefined4 *)((in_CWP * 0x10 + 6) * 4 + 0x8000) = unaff_fp;
    *(undefined4 *)((in_CWP * 0x10 + 7) * 4 + 0x8000) = unaff_i7;
    *(undefined4 *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = unaff_l0;
    *(undefined4 *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = unaff_l1;
    *(undefined4 *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = unaff_l4;
    *(undefined4 *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = unaff_l5;
    *(undefined4 *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = unaff_l6;
    *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_l7;
  }
  *(undefined4 *)((int)register0x00000038 + -0x18) = *param_1;
  *(undefined4 *)((int)register0x00000038 + -0x14) = param_1[1];
  *(undefined4 *)((int)register0x00000038 + -0x10) = param_1[2];
  uVar1 = param_1[3];
  *(undefined4 *)((int)register0x00000038 + -0xc) = uVar1;
  puVar2 = (undefined *)((int)register0x00000038 + -0x18);
  _NXDefaultMallocZone();
  _NXCreateHashTableFromZone(puVar2,param_2,param_3,uVar1);
  return CONCAT44(param_2,puVar2);
}
/* GHIDRADEC_FUNCTION index=3107 start=0xf00ed1ac */

/* WARNING: Removing unreachable block (ram,0xf00ed2f0) */
/* WARNING: Removing unreachable block (ram,0xf00ed2d4) */
/* WARNING: Removing unreachable block (ram,0xf00ed298) */
/* WARNING: Removing unreachable block (ram,0xf00ed270) */
/* WARNING: Removing unreachable block (ram,0xf00ed254) */
/* WARNING: Removing unreachable block (ram,0xf00ed268) */
/* WARNING: Removing unreachable block (ram,0xf00ed28c) */
/* WARNING: Removing unreachable block (ram,0xf00ed2a4) */
/* WARNING: Removing unreachable block (ram,0xf00ed2dc) */
/* WARNING: Removing unreachable block (ram,0xf00ed2c0) */
/* WARNING: Removing unreachable block (ram,0xf00ed1d8) */

undefined8 _NXCreateHashTableFromZone(int *param_1,int param_2,int param_3,int *param_4)

{
  int iVar1;
  undefined *puVar2;
  int iVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int *piVar4;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
  if (!in_DECOMPILE_MODE) {
    *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
    *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
    *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
    *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
    *(undefined4 *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = unaff_i4;
    *(undefined4 *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = unaff_i5;
    *(undefined4 *)((in_CWP * 0x10 + 6) * 4 + 0x8000) = unaff_fp;
    *(undefined4 *)((in_CWP * 0x10 + 7) * 4 + 0x8000) = unaff_i7;
    *(undefined4 *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = unaff_l0;
    *(undefined4 *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = unaff_l1;
    *(undefined4 *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = unaff_l4;
    *(undefined4 *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = unaff_l5;
    *(undefined4 *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = unaff_l6;
    *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_l7;
  }
  piVar4 = param_4;
  (*(code *)param_4[1])(param_4,0x14);
  if (dword_F012F080 == 0) {
    sub_F00ED0E8();
    iVar1 = *param_1;
  }
  else {
    iVar1 = *param_1;
  }
  if (iVar1 == 0) {
    *param_1 = (int)_NXPtrHash;
    iVar1 = param_1[1];
  }
  else {
    iVar1 = param_1[1];
  }
  if (iVar1 == 0) {
    param_1[1] = (int)_NXPtrIsEqual;
    iVar1 = param_1[2];
  }
  else {
    iVar1 = param_1[2];
  }
  if (iVar1 == 0) {
    param_1[2] = (int)_NXNoEffectFree;
    iVar1 = param_1[3];
  }
  else {
    iVar1 = param_1[3];
  }
  if (iVar1 == 0) {
    iVar1 = dword_F012F080;
    _NXHashGet(dword_F012F080,param_1);
    if (iVar1 == 0) {
      _NXDefaultMallocZone();
      iVar3 = iVar1;
      _NXDefaultMallocZone();
      (**(code **)(iVar1 + 4))();
      _memmove();
      _NXHashInsert(dword_F012F080,iVar3);
      iVar1 = dword_F012F080;
      _NXHashGet(dword_F012F080,param_1);
      if (iVar1 == 0) {
        puVar2 = aNxcreatehashta_0;
        goto loc_F00ED2C0;
      }
      *piVar4 = iVar1;
    }
    else {
      *piVar4 = iVar1;
    }
    piVar4[1] = 0;
    piVar4[4] = param_3;
    iVar1 = param_2;
    sub_F00ED010();
    iVar1 = iVar1 + 1;
    sub_F00ED034();
    piVar4[2] = iVar1;
    _NXZoneCalloc(param_4,iVar1,8);
    piVar4[3] = (int)param_4;
  }
  else {
    puVar2 = aNxcreatehashta;
loc_F00ED2C0:
    piVar4 = (int *)0x0;
    __NXLogError(puVar2);
  }
  return CONCAT44(param_2,piVar4);
}
/* GHIDRADEC_FUNCTION index=3108 start=0xf00ed3d0 */

/* WARNING: Removing unreachable block (ram,0xf00ed3e0) */
/* WARNING: Removing unreachable block (ram,0xf00ed3e8) */
/* WARNING: Removing unreachable block (ram,0xf00ed3d8) */

undefined8 _NXFreeHashTable(int param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
  if (!in_DECOMPILE_MODE) {
    *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
    *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
    *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
    *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
    *(undefined4 *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = unaff_i4;
    *(undefined4 *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = unaff_i5;
    *(undefined4 *)((in_CWP * 0x10 + 6) * 4 + 0x8000) = unaff_fp;
    *(undefined4 *)((in_CWP * 0x10 + 7) * 4 + 0x8000) = unaff_i7;
    *(undefined4 *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = unaff_l0;
    *(undefined4 *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = unaff_l1;
    *(undefined4 *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = unaff_l4;
    *(undefined4 *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = unaff_l5;
    *(undefined4 *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = unaff_l6;
    *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_l7;
  }
  sub_F00ED358(param_1,1);
  _free(*(undefined4 *)(param_1 + 0xc));
  _free(param_1);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3109 start=0xf00ed3f8 */

/* WARNING: Removing unreachable block (ram,0xf00ed400) */

undefined8 _NXEmptyHashTable(int param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
  if (!in_DECOMPILE_MODE) {
    *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
    *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
    *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
    *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
    *(undefined4 *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = unaff_i4;
    *(undefined4 *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = unaff_i5;
    *(undefined4 *)((in_CWP * 0x10 + 6) * 4 + 0x8000) = unaff_fp;
    *(undefined4 *)((in_CWP * 0x10 + 7) * 4 + 0x8000) = unaff_i7;
    *(undefined4 *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = unaff_l0;
    *(undefined4 *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = unaff_l1;
    *(undefined4 *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = unaff_l4;
    *(undefined4 *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = unaff_l5;
    *(undefined4 *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = unaff_l6;
    *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_l7;
  }
  sub_F00ED358(param_1,0);
  *(undefined4 *)(param_1 + 4) = 0;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3110 start=0xf00ed414 */

/* WARNING: Removing unreachable block (ram,0xf00ed41c) */

undefined8 _NXResetHashTable(int param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
  if (!in_DECOMPILE_MODE) {
    *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
    *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
    *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
    *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
    *(undefined4 *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = unaff_i4;
    *(undefined4 *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = unaff_i5;
    *(undefined4 *)((in_CWP * 0x10 + 6) * 4 + 0x8000) = unaff_fp;
    *(undefined4 *)((in_CWP * 0x10 + 7) * 4 + 0x8000) = unaff_i7;
    *(undefined4 *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = unaff_l0;
    *(undefined4 *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = unaff_l1;
    *(undefined4 *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = unaff_l4;
    *(undefined4 *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = unaff_l5;
    *(undefined4 *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = unaff_l6;
    *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_l7;
  }
  sub_F00ED358(param_1,1);
  *(undefined4 *)(param_1 + 4) = 0;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3111 start=0xf00ed430 */

/* WARNING: Removing unreachable block (ram,0xf00ed44c) */
/* WARNING: Removing unreachable block (ram,0xf00ed46c) */
/* WARNING: Removing unreachable block (ram,0xf00ed440) */

undefined8 _NXIsEqualHashTable(int param_1,int param_2)

{
  code *pcVar1;
  int iVar2;
  int iVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar4;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  undefined auStackX_0 [92];
  
  if (!in_DECOMPILE_MODE) {
    *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
    *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
    *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
    *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
    *(undefined4 *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = unaff_i4;
    *(undefined4 *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = unaff_i5;
    *(undefined4 *)((in_CWP * 0x10 + 6) * 4 + 0x8000) = unaff_fp;
    *(undefined4 *)((in_CWP * 0x10 + 7) * 4 + 0x8000) = unaff_i7;
    *(undefined4 *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = unaff_l0;
    *(undefined4 *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = unaff_l1;
    *(undefined4 *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = unaff_l4;
    *(undefined4 *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = unaff_l5;
    *(undefined4 *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = unaff_l6;
    *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_l7;
  }
  if (param_1 == param_2) {
    uVar4 = 1;
  }
  else {
    iVar2 = param_1;
    _NXCountHashTable();
    iVar3 = param_2;
    _NXCountHashTable();
    if (iVar2 == iVar3) {
      _NXInitHashState((undefined *)((int)register0x00000038 + -0x10),param_1);
                    /* WARNING: Does not return */
      pcVar1 = (code *)IllegalInstructionTrap(8);
      (*pcVar1)();
    }
    uVar4 = 0;
  }
  return CONCAT44(param_2,uVar4);
}
/* GHIDRADEC_FUNCTION index=3112 start=0xf00ed4bc */

/* WARNING: Removing unreachable block (ram,0xf00ed4d8) */
/* WARNING: Removing unreachable block (ram,0xf00ed4f8) */
/* WARNING: Removing unreachable block (ram,0xf00ed4cc) */

undefined8 _NXCompareHashTables(int param_1,int param_2)

{
  code *pcVar1;
  int iVar2;
  int iVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar4;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  undefined auStackX_0 [92];
  
  if (!in_DECOMPILE_MODE) {
    *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
    *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
    *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
    *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
    *(undefined4 *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = unaff_i4;
    *(undefined4 *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = unaff_i5;
    *(undefined4 *)((in_CWP * 0x10 + 6) * 4 + 0x8000) = unaff_fp;
    *(undefined4 *)((in_CWP * 0x10 + 7) * 4 + 0x8000) = unaff_i7;
    *(undefined4 *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = unaff_l0;
    *(undefined4 *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = unaff_l1;
    *(undefined4 *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = unaff_l4;
    *(undefined4 *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = unaff_l5;
    *(undefined4 *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = unaff_l6;
    *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_l7;
  }
  if (param_1 == param_2) {
    uVar4 = 1;
  }
  else {
    iVar2 = param_1;
    _NXCountHashTable();
    iVar3 = param_2;
    _NXCountHashTable();
    if (iVar2 == iVar3) {
      _NXInitHashState((undefined *)((int)register0x00000038 + -0x10),param_1);
                    /* WARNING: Does not return */
      pcVar1 = (code *)IllegalInstructionTrap(8);
      (*pcVar1)();
    }
    uVar4 = 0;
  }
  return CONCAT44(param_2,uVar4);
}
/* GHIDRADEC_FUNCTION index=3113 start=0xf00ed548 */

/* WARNING: Removing unreachable block (ram,0xf00ed55c) */

void _NXCopyHashTable(undefined4 param_1)

{
  code *pcVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  undefined auStackX_0 [92];
  
  if (!in_DECOMPILE_MODE) {
    *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
    *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
    *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
    *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
    *(undefined4 *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = unaff_i4;
    *(undefined4 *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = unaff_i5;
    *(undefined4 *)((in_CWP * 0x10 + 6) * 4 + 0x8000) = unaff_fp;
    *(undefined4 *)((in_CWP * 0x10 + 7) * 4 + 0x8000) = unaff_i7;
    *(undefined4 *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = unaff_l0;
    *(undefined4 *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = unaff_l1;
    *(undefined4 *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = unaff_l4;
    *(undefined4 *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = unaff_l5;
    *(undefined4 *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = unaff_l6;
    *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_l7;
  }
  _NXInitHashState((undefined *)((int)register0x00000038 + -0x10),param_1);
                    /* WARNING: Does not return */
  pcVar1 = (code *)IllegalInstructionTrap(8);
  (*pcVar1)();
}
/* GHIDRADEC_FUNCTION index=3114 start=0xf00ed5e4 */

undefined4 _NXCountHashTable(int param_1)

{
  return *(undefined4 *)(param_1 + 4);
}
/* GHIDRADEC_FUNCTION index=3115 start=0xf00ed5ec */

/* WARNING: Removing unreachable block (ram,0xf00ed604) */

undefined8 _NXHashMember(int *param_1,int param_2)

{
  int iVar1;
  undefined4 unaff_l0;
  int iVar2;
  undefined4 unaff_l1;
  int *piVar3;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar4;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
  if (!in_DECOMPILE_MODE) {
    *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
    *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
    *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
    *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
    *(undefined4 *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = unaff_i4;
    *(undefined4 *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = unaff_i5;
    *(undefined4 *)((in_CWP * 0x10 + 6) * 4 + 0x8000) = unaff_fp;
    *(undefined4 *)((in_CWP * 0x10 + 7) * 4 + 0x8000) = unaff_i7;
    *(undefined4 *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = unaff_l0;
    *(undefined4 *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = unaff_l1;
    *(undefined4 *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = unaff_l4;
    *(undefined4 *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = unaff_l5;
    *(undefined4 *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = unaff_l6;
    *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_l7;
  }
  iVar1 = param_1[4];
  (**(code **)*param_1)(iVar1,param_2);
  .urem();
  iVar2 = *(int *)(iVar1 * 8 + param_1[3]);
  iVar1 = iVar1 * 8 + param_1[3];
  if (iVar2 == 0) {
loc_F00ED6B0:
    uVar4 = 0;
  }
  else if (iVar2 == 1) {
    if (param_2 != *(int *)(iVar1 + 4)) {
      iVar1 = param_1[4];
      (**(code **)(*param_1 + 4))(iVar1,param_2);
      uVar4 = 0;
      if (iVar1 == 0) goto locret_F00ED6B4;
    }
    uVar4 = 1;
  }
  else {
    piVar3 = *(int **)(iVar1 + 4);
    do {
      iVar2 = iVar2 + -1;
      if (iVar2 == -1) goto loc_F00ED6B0;
      if (param_2 == *piVar3) {
        uVar4 = 1;
        goto locret_F00ED6B4;
      }
      iVar1 = param_1[4];
      (**(code **)(*param_1 + 4))(iVar1,param_2);
      piVar3 = piVar3 + 1;
    } while (iVar1 == 0);
    uVar4 = 1;
  }
locret_F00ED6B4:
  return CONCAT44(param_2,uVar4);
}
/* GHIDRADEC_FUNCTION index=3116 start=0xf00ed6bc */

/* WARNING: Removing unreachable block (ram,0xf00ed6d8) */

undefined8 _NXHashGet(int *param_1,int param_2)

{
  int iVar1;
  undefined4 unaff_l0;
  int iVar2;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int *piVar3;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
  if (!in_DECOMPILE_MODE) {
    *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
    *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
    *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
    *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
    *(undefined4 *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = unaff_i4;
    *(undefined4 *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = unaff_i5;
    *(undefined4 *)((in_CWP * 0x10 + 6) * 4 + 0x8000) = unaff_fp;
    *(undefined4 *)((in_CWP * 0x10 + 7) * 4 + 0x8000) = unaff_i7;
    *(undefined4 *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = unaff_l0;
    *(undefined4 *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = unaff_l1;
    *(undefined4 *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = unaff_l4;
    *(undefined4 *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = unaff_l5;
    *(undefined4 *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = unaff_l6;
    *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_l7;
  }
  iVar1 = param_1[4];
  (**(code **)*param_1)(iVar1,param_2);
  .urem();
  iVar2 = *(int *)(iVar1 * 8 + param_1[3]);
  iVar1 = iVar1 * 8 + param_1[3];
  if (iVar2 != 0) {
    if (iVar2 == 1) {
      if (param_2 == *(int *)(iVar1 + 4)) {
        iVar1 = *(int *)(iVar1 + 4);
      }
      else {
        iVar2 = param_1[4];
        (**(code **)(*param_1 + 4))(iVar2,param_2);
        if (iVar2 == 0) {
          iVar1 = 0;
        }
        else {
          iVar1 = *(int *)(iVar1 + 4);
        }
      }
      goto locret_F00ED784;
    }
    piVar3 = *(int **)(iVar1 + 4);
    while (iVar2 = iVar2 + -1, iVar2 != -1) {
      if (param_2 == *piVar3) {
        iVar1 = *piVar3;
        goto locret_F00ED784;
      }
      iVar1 = param_1[4];
      (**(code **)(*param_1 + 4))(iVar1,param_2);
      if (iVar1 != 0) {
        iVar1 = *piVar3;
        goto locret_F00ED784;
      }
      piVar3 = piVar3 + 1;
    }
  }
  iVar1 = 0;
locret_F00ED784:
  return CONCAT44(param_2,iVar1);
}
/* GHIDRADEC_FUNCTION index=3117 start=0xf00ed878 */

/* WARNING: Removing unreachable block (ram,0xf00ed9c4) */
/* WARNING: Removing unreachable block (ram,0xf00ed998) */
/* WARNING: Removing unreachable block (ram,0xf00ed8a8) */
/* WARNING: Removing unreachable block (ram,0xf00ed928) */
/* WARNING: Removing unreachable block (ram,0xf00ed9b8) */
/* WARNING: Removing unreachable block (ram,0xf00ed9f8) */
/* WARNING: Removing unreachable block (ram,0xf00ed890) */

undefined8 _NXHashInsert(int *param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  undefined4 unaff_l0;
  int iVar3;
  int *piVar4;
  undefined4 unaff_l1;
  int iVar5;
  undefined4 unaff_l3;
  int *piVar6;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
  if (!in_DECOMPILE_MODE) {
    *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
    *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
    *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
    *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
    *(undefined4 *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = unaff_i4;
    *(undefined4 *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = unaff_i5;
    *(undefined4 *)((in_CWP * 0x10 + 6) * 4 + 0x8000) = unaff_fp;
    *(undefined4 *)((in_CWP * 0x10 + 7) * 4 + 0x8000) = unaff_i7;
    *(undefined4 *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = unaff_l0;
    *(undefined4 *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = unaff_l1;
    *(undefined4 *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = unaff_l4;
    *(undefined4 *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = unaff_l5;
    *(undefined4 *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = unaff_l6;
    *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_l7;
  }
  iVar1 = param_1[4];
  (**(code **)*param_1)(iVar1,param_2);
  .urem();
  iVar1 = iVar1 * 8;
  iVar3 = param_1[3];
  piVar6 = (int *)(iVar1 + iVar3);
  iVar5 = *(int *)(iVar1 + iVar3);
  piVar2 = param_1;
  _NXZoneFromPtr();
  if (iVar5 == 0) {
    *(int *)(iVar1 + iVar3) = *(int *)(iVar1 + iVar3) + 1;
    piVar6[1] = param_2;
    param_1[1] = param_1[1] + 1;
  }
  else {
    if (iVar5 == 1) {
      if (param_2 == piVar6[1]) {
        iVar1 = piVar6[1];
      }
      else {
        iVar1 = param_1[4];
        (**(code **)(*param_1 + 4))(iVar1,param_2);
        if (iVar1 == 0) {
          _NXZoneCalloc(piVar2,2,4);
          piVar2[1] = piVar6[1];
          *piVar2 = param_2;
          goto loc_F00ED9CC;
        }
        iVar1 = piVar6[1];
      }
      piVar6[1] = param_2;
      goto locret_F00EDA04;
    }
    piVar4 = (int *)piVar6[1];
    while (iVar5 = iVar5 + -1, iVar5 != -1) {
      if (param_2 == *piVar4) {
        iVar1 = *piVar4;
loc_F00ED974:
        *piVar4 = param_2;
        goto locret_F00EDA04;
      }
      iVar1 = param_1[4];
      (**(code **)(*param_1 + 4))(iVar1,param_2);
      if (iVar1 != 0) {
        iVar1 = *piVar4;
        goto loc_F00ED974;
      }
      piVar4 = piVar4 + 1;
    }
    _NXZoneCalloc(piVar2,*piVar6 + 1,4);
    if (*piVar6 != 0) {
      _memmove(piVar2 + 1,piVar6[1],*piVar6 << 2);
    }
    *piVar2 = param_2;
    _free(piVar6[1]);
loc_F00ED9CC:
    *piVar6 = *piVar6 + 1;
    piVar6[1] = (int)piVar2;
    iVar1 = param_1[1];
    param_1[1] = iVar1 + 1U;
    if (iVar1 + 1U <= (uint)param_1[2]) {
      iVar1 = 0;
      goto locret_F00EDA04;
    }
    sub_F00ED78C(param_1);
  }
  iVar1 = 0;
locret_F00EDA04:
  return CONCAT44(param_2,iVar1);
}
/* GHIDRADEC_FUNCTION index=3118 start=0xf00eda0c */

/* WARNING: Removing unreachable block (ram,0xf00edb54) */
/* WARNING: Removing unreachable block (ram,0xf00edb28) */
/* WARNING: Removing unreachable block (ram,0xf00eda40) */
/* WARNING: Removing unreachable block (ram,0xf00edabc) */
/* WARNING: Removing unreachable block (ram,0xf00edb48) */
/* WARNING: Removing unreachable block (ram,0xf00edb88) */
/* WARNING: Removing unreachable block (ram,0xf00eda28) */

undefined8 _NXHashInsertIfAbsent(int *param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  undefined4 unaff_l0;
  int iVar3;
  undefined4 unaff_l1;
  int iVar4;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  int *piVar5;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int *piVar6;
  int iVar7;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
  if (!in_DECOMPILE_MODE) {
    *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
    *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
    *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
    *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
    *(undefined4 *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = unaff_i4;
    *(undefined4 *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = unaff_i5;
    *(undefined4 *)((in_CWP * 0x10 + 6) * 4 + 0x8000) = unaff_fp;
    *(undefined4 *)((in_CWP * 0x10 + 7) * 4 + 0x8000) = unaff_i7;
    *(undefined4 *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = unaff_l0;
    *(undefined4 *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = unaff_l1;
    *(undefined4 *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = unaff_l4;
    *(undefined4 *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = unaff_l5;
    *(undefined4 *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = unaff_l6;
    *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_l7;
  }
  iVar1 = param_1[4];
  (**(code **)*param_1)(iVar1,param_2);
  .urem();
  iVar1 = iVar1 * 8;
  iVar4 = param_1[3];
  piVar5 = (int *)(iVar1 + iVar4);
  iVar3 = *(int *)(iVar1 + iVar4);
  piVar2 = param_1;
  _NXZoneFromPtr();
  iVar7 = param_2;
  if (iVar3 == 0) {
    *(int *)(iVar1 + iVar4) = *(int *)(iVar1 + iVar4) + 1;
    piVar5[1] = param_2;
    param_1[1] = param_1[1] + 1;
    goto locret_F00EDB94;
  }
  if (iVar3 == 1) {
    if (param_2 == piVar5[1]) {
      iVar7 = piVar5[1];
      goto locret_F00EDB94;
    }
    iVar1 = param_1[4];
    (**(code **)(*param_1 + 4))(iVar1,param_2);
    if (iVar1 != 0) {
      iVar7 = piVar5[1];
      goto locret_F00EDB94;
    }
    _NXZoneCalloc(piVar2,2,4);
    piVar2[1] = piVar5[1];
    *piVar2 = param_2;
  }
  else {
    piVar6 = (int *)piVar5[1];
    while (iVar3 = iVar3 + -1, iVar3 != -1) {
      if (param_2 == *piVar6) {
        iVar7 = *piVar6;
        goto locret_F00EDB94;
      }
      iVar1 = param_1[4];
      (**(code **)(*param_1 + 4))(iVar1,param_2);
      if (iVar1 != 0) {
        iVar7 = *piVar6;
        goto locret_F00EDB94;
      }
      piVar6 = piVar6 + 1;
    }
    _NXZoneCalloc(piVar2,*piVar5 + 1,4);
    if (*piVar5 != 0) {
      _memmove(piVar2 + 1,piVar5[1],*piVar5 << 2);
    }
    *piVar2 = param_2;
    _free(piVar5[1]);
  }
  *piVar5 = *piVar5 + 1;
  piVar5[1] = (int)piVar2;
  iVar1 = param_1[1];
  param_1[1] = iVar1 + 1U;
  if ((uint)param_1[2] < iVar1 + 1U) {
    sub_F00ED78C(param_1);
  }
locret_F00EDB94:
  return CONCAT44(param_2,iVar7);
}
/* GHIDRADEC_FUNCTION index=3119 start=0xf00edb9c */

/* WARNING: Removing unreachable block (ram,0xf00edd9c) */
/* WARNING: Removing unreachable block (ram,0xf00edd64) */
/* WARNING: Removing unreachable block (ram,0xf00edbcc) */
/* WARNING: Removing unreachable block (ram,0xf00edd30) */
/* WARNING: Removing unreachable block (ram,0xf00edd94) */
/* WARNING: Removing unreachable block (ram,0xf00edcc4) */
/* WARNING: Removing unreachable block (ram,0xf00edbb4) */

undefined8 _NXHashRemove(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  int iVar6;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
  if (!in_DECOMPILE_MODE) {
    *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
    *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
    *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
    *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
    *(undefined4 *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = unaff_i4;
    *(undefined4 *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = unaff_i5;
    *(undefined4 *)((in_CWP * 0x10 + 6) * 4 + 0x8000) = unaff_fp;
    *(undefined4 *)((in_CWP * 0x10 + 7) * 4 + 0x8000) = unaff_i7;
    *(undefined4 *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = unaff_l0;
    *(undefined4 *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = unaff_l1;
    *(undefined4 *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = unaff_l4;
    *(undefined4 *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = unaff_l5;
    *(undefined4 *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = unaff_l6;
    *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_l7;
  }
  iVar1 = param_1[4];
  (**(code **)*param_1)(iVar1,param_2);
  .urem();
  piVar5 = (int *)(iVar1 * 8 + param_1[3]);
  iVar1 = *(int *)(iVar1 * 8 + param_1[3]);
  piVar4 = param_1;
  _NXZoneFromPtr();
  if (iVar1 == 0) {
loc_F00EDDD8:
    iVar6 = 0;
    goto locret_F00EDDDC;
  }
  if (iVar1 == 1) {
    if (param_2 == piVar5[1]) {
      iVar6 = piVar5[1];
    }
    else {
      iVar1 = param_1[4];
      (**(code **)(*param_1 + 4))(iVar1,param_2);
      if (iVar1 == 0) {
        iVar6 = 0;
        goto locret_F00EDDDC;
      }
      iVar6 = piVar5[1];
    }
    param_1[1] = param_1[1] + -1;
    *piVar5 = *piVar5 + -1;
    piVar5[1] = 0;
    param_2 = iVar6;
    goto locret_F00EDDDC;
  }
  piVar3 = (int *)piVar5[1];
  if (iVar1 != 2) {
    while (iVar1 = iVar1 + -1, iVar1 != -1) {
      if (param_2 == *piVar3) {
        iVar2 = *piVar5;
loc_F00EDD1C:
        iVar6 = *piVar3;
        if (iVar2 == 1) {
          piVar4 = (int *)0x0;
        }
        else {
          _NXZoneCalloc(piVar4,iVar2 + -1,4);
        }
        if (*piVar5 + -1 != iVar1) {
          _memmove(piVar4,piVar5[1],((*piVar5 - iVar1) + -1) * 4);
        }
        if (iVar1 != 0) {
          _memmove(piVar4 + *piVar5 + (-1 - iVar1),*piVar5 * 4 + piVar5[1] + iVar1 * -4);
        }
        _free(piVar5[1]);
        param_1[1] = param_1[1] + -1;
        *piVar5 = *piVar5 + -1;
        piVar5[1] = (int)piVar4;
        param_2 = iVar6;
        goto locret_F00EDDDC;
      }
      iVar6 = param_1[4];
      (**(code **)(*param_1 + 4))(iVar6,param_2);
      if (iVar6 != 0) {
        iVar2 = *piVar5;
        goto loc_F00EDD1C;
      }
      piVar3 = piVar3 + 1;
    }
    goto loc_F00EDDD8;
  }
  if (param_2 == *piVar3) {
    iVar1 = piVar3[1];
loc_F00EDC80:
    piVar5[1] = iVar1;
    iVar6 = *piVar3;
  }
  else {
    iVar1 = param_1[4];
    (**(code **)(*param_1 + 4))(iVar1,param_2);
    if (iVar1 != 0) {
      iVar1 = piVar3[1];
      goto loc_F00EDC80;
    }
    if (param_2 == piVar3[1]) {
      iVar1 = *piVar3;
    }
    else {
      iVar1 = param_1[4];
      (**(code **)(*param_1 + 4))(iVar1,param_2);
      if (iVar1 == 0) {
        iVar6 = 0;
        goto locret_F00EDDDC;
      }
      iVar1 = *piVar3;
    }
    piVar5[1] = iVar1;
    iVar6 = piVar3[1];
  }
  _free(piVar3);
  param_1[1] = param_1[1] + -1;
  *piVar5 = *piVar5 + -1;
  param_2 = iVar6;
locret_F00EDDDC:
  return CONCAT44(param_2,iVar6);
}
/* GHIDRADEC_FUNCTION index=3120 start=0xf00edde4 */

undefined4 * _NXInitHashState(undefined4 *puStackX_40,int param_2)

{
  *puStackX_40 = *(undefined4 *)(param_2 + 8);
  puStackX_40[1] = 0;
  return puStackX_40;
}
/* GHIDRADEC_FUNCTION index=3121 start=0xf00ede10 */

undefined4 _NXNextHashState(int param_1,int *param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  
  iVar1 = param_2[1];
  iVar2 = *(int *)(param_1 + 0xc);
  if (iVar1 == 0) {
    do {
      iVar1 = *param_2 + -1;
      if (*param_2 == 0) {
        return 0;
      }
      *param_2 = iVar1;
      iVar1 = *(int *)(iVar2 + iVar1 * 8);
      param_2[1] = iVar1;
    } while (iVar1 == 0);
    iVar1 = param_2[1];
  }
  param_2[1] = iVar1 + -1;
  piVar3 = (int *)(iVar2 + *param_2 * 8);
  if (*piVar3 == 1) {
    iVar1 = piVar3[1];
  }
  else {
    iVar1 = *(int *)(piVar3[1] + param_2[1] * 4);
  }
  *param_3 = iVar1;
  return 1;
}
/* GHIDRADEC_FUNCTION index=3122 start=0xf00ede9c */

uint _NXPtrHash(undefined4 param_1,uint param_2)

{
  return param_2 >> 0x10 ^ param_2;
}
/* GHIDRADEC_FUNCTION index=3123 start=0xf00edea8 */

uint _NXStrHash(undefined4 param_1,byte *param_2)

{
  byte bVar1;
  uint uVar2;
  byte *pbVar3;
  
  uVar2 = 0;
  if (param_2 != (byte *)0x0) {
    bVar1 = *param_2;
    while (bVar1 != 0) {
      uVar2 = bVar1 ^ uVar2;
      if (param_2[1] == 0) {
        return uVar2;
      }
      uVar2 = uVar2 ^ (uint)param_2[1] << 8;
      if (param_2[2] == 0) {
        return uVar2;
      }
      uVar2 = uVar2 ^ (uint)param_2[2] << 0x10;
      pbVar3 = param_2 + 3;
      if (*pbVar3 == 0) {
        return uVar2;
      }
      param_2 = param_2 + 4;
      uVar2 = uVar2 ^ (uint)*pbVar3 << 0x18;
      bVar1 = *param_2;
    }
  }
  return uVar2;
}
/* GHIDRADEC_FUNCTION index=3124 start=0xf00edf28 */

bool _NXPtrIsEqual(undefined4 param_1,int param_2,int param_3)

{
  return param_2 == param_3;
}
/* GHIDRADEC_FUNCTION index=3125 start=0xf00edf38 */

/* WARNING: Removing unreachable block (ram,0xf00edf6c) */
/* WARNING: Removing unreachable block (ram,0xf00edf94) */

undefined8 _NXStrIsEqual(undefined4 param_1,char *param_2,char *param_3)

{
  char *pcVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  uint uVar2;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
  if (!in_DECOMPILE_MODE) {
    *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
    *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
    *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
    *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
    *(undefined4 *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = unaff_i4;
    *(undefined4 *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = unaff_i5;
    *(undefined4 *)((in_CWP * 0x10 + 6) * 4 + 0x8000) = unaff_fp;
    *(undefined4 *)((in_CWP * 0x10 + 7) * 4 + 0x8000) = unaff_i7;
    *(undefined4 *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = unaff_l0;
    *(undefined4 *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = unaff_l1;
    *(undefined4 *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = unaff_l4;
    *(undefined4 *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = unaff_l5;
    *(undefined4 *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = unaff_l6;
    *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_l7;
  }
  if (param_2 == param_3) {
    uVar2 = 1;
  }
  else {
    pcVar1 = param_3;
    if ((param_2 == (char *)0x0) || (pcVar1 = param_2, param_3 == (char *)0x0)) {
      _strlen(pcVar1);
      uVar2 = (uint)(pcVar1 == (char *)0x0);
    }
    else {
      uVar2 = 0;
      if (*param_2 == *param_3) {
        _strcmp(param_2,param_3);
        uVar2 = (uint)(pcVar1 == (char *)0x0);
      }
    }
  }
  return CONCAT44(param_2,uVar2);
}
/* GHIDRADEC_FUNCTION index=3126 start=0xf00edfac */

void _NXNoEffectFree(void)

{
  return;
}
/* GHIDRADEC_FUNCTION index=3127 start=0xf00edfb4 */

/* WARNING: Removing unreachable block (ram,0xf00edfb8) */

undefined8 _NXReallyFree(undefined4 param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
  if (!in_DECOMPILE_MODE) {
    *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
    *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
    *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
    *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
    *(undefined4 *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = unaff_i4;
    *(undefined4 *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = unaff_i5;
    *(undefined4 *)((in_CWP * 0x10 + 6) * 4 + 0x8000) = unaff_fp;
    *(undefined4 *)((in_CWP * 0x10 + 7) * 4 + 0x8000) = unaff_i7;
    *(undefined4 *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = unaff_l0;
    *(undefined4 *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = unaff_l1;
    *(undefined4 *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = unaff_l4;
    *(undefined4 *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = unaff_l5;
    *(undefined4 *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = unaff_l6;
    *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_l7;
  }
  _free(param_2);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3128 start=0xf00edfc8 */

/* WARNING: Removing unreachable block (ram,0xf00edfd0) */

undefined8 _hashPtrStructKey(undefined4 param_1,undefined4 *param_2)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
  if (!in_DECOMPILE_MODE) {
    *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
    *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
    *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
    *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
    *(undefined4 *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = unaff_i4;
    *(undefined4 *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = unaff_i5;
    *(undefined4 *)((in_CWP * 0x10 + 6) * 4 + 0x8000) = unaff_fp;
    *(undefined4 *)((in_CWP * 0x10 + 7) * 4 + 0x8000) = unaff_i7;
    *(undefined4 *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = unaff_l0;
    *(undefined4 *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = unaff_l1;
    *(undefined4 *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = unaff_l4;
    *(undefined4 *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = unaff_l5;
    *(undefined4 *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = unaff_l6;
    *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_l7;
  }
  _NXPtrHash(param_1,*param_2);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3129 start=0xf00edfe0 */

/* WARNING: Removing unreachable block (ram,0xf00edfec) */

undefined8 _isEqualPtrStructKey(undefined4 param_1,undefined4 *param_2,undefined4 *param_3)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
  if (!in_DECOMPILE_MODE) {
    *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
    *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
    *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
    *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
    *(undefined4 *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = unaff_i4;
    *(undefined4 *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = unaff_i5;
    *(undefined4 *)((in_CWP * 0x10 + 6) * 4 + 0x8000) = unaff_fp;
    *(undefined4 *)((in_CWP * 0x10 + 7) * 4 + 0x8000) = unaff_i7;
    *(undefined4 *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = unaff_l0;
    *(undefined4 *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = unaff_l1;
    *(undefined4 *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = unaff_l4;
    *(undefined4 *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = unaff_l5;
    *(undefined4 *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = unaff_l6;
    *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_l7;
  }
  _NXPtrIsEqual(param_1,*param_2,*param_3);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3130 start=0xf00edffc */

/* WARNING: Removing unreachable block (ram,0xf00ee004) */

undefined8 _hashStrStructKey(undefined4 param_1,undefined4 *param_2)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
  if (!in_DECOMPILE_MODE) {
    *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
    *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
    *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
    *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
    *(undefined4 *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = unaff_i4;
    *(undefined4 *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = unaff_i5;
    *(undefined4 *)((in_CWP * 0x10 + 6) * 4 + 0x8000) = unaff_fp;
    *(undefined4 *)((in_CWP * 0x10 + 7) * 4 + 0x8000) = unaff_i7;
    *(undefined4 *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = unaff_l0;
    *(undefined4 *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = unaff_l1;
    *(undefined4 *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = unaff_l4;
    *(undefined4 *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = unaff_l5;
    *(undefined4 *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = unaff_l6;
    *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_l7;
  }
  _NXStrHash(param_1,*param_2);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3131 start=0xf00ee014 */

/* WARNING: Removing unreachable block (ram,0xf00ee020) */

undefined8 _isEqualStrStructKey(undefined4 param_1,undefined4 *param_2,undefined4 *param_3)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
  if (!in_DECOMPILE_MODE) {
    *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
    *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
    *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
    *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
    *(undefined4 *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = unaff_i4;
    *(undefined4 *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = unaff_i5;
    *(undefined4 *)((in_CWP * 0x10 + 6) * 4 + 0x8000) = unaff_fp;
    *(undefined4 *)((in_CWP * 0x10 + 7) * 4 + 0x8000) = unaff_i7;
    *(undefined4 *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = unaff_l0;
    *(undefined4 *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = unaff_l1;
    *(undefined4 *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = unaff_l4;
    *(undefined4 *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = unaff_l5;
    *(undefined4 *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = unaff_l6;
    *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_l7;
  }
  _NXStrIsEqual(param_1,*param_2,*param_3);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3132 start=0xf00ee140 */

//Decompiler native message:  Marshaling error: Attribute metatype is not present
//Decompiling function: _NXUniqueString @ 0xf00ee140
/* GHIDRADEC_FUNCTION index=3133 start=0xf00ee204 */

//Decompiler native message:  Marshaling error: Attribute metatype is not present
//Decompiling function: _NXUniqueStringNoCopy @ 0xf00ee204
/* GHIDRADEC_FUNCTION index=3134 start=0xf00ee280 */

/* WARNING: Removing unreachable block (ram,0xf00ee2b4) */
/* WARNING: Removing unreachable block (ram,0xf00ee2a8) */
/* WARNING: Removing unreachable block (ram,0xf00ee2d0) */
/* WARNING: Removing unreachable block (ram,0xf00ee294) */

undefined8 _NXUniqueStringWithLength(undefined4 param_1,int param_2)

{
  undefined *puVar1;
  undefined4 unaff_l0;
  undefined *puVar2;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  undefined auStackX_0 [92];
  
  if (!in_DECOMPILE_MODE) {
    *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
    *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
    *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
    *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
    *(undefined4 *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = unaff_i4;
    *(undefined4 *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = unaff_i5;
    *(undefined4 *)((in_CWP * 0x10 + 6) * 4 + 0x8000) = unaff_fp;
    *(undefined4 *)((in_CWP * 0x10 + 7) * 4 + 0x8000) = unaff_i7;
    *(undefined4 *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = unaff_l0;
    *(undefined4 *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = unaff_l1;
    *(undefined4 *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = unaff_l4;
    *(undefined4 *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = unaff_l5;
    *(undefined4 *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = unaff_l6;
    *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_l7;
  }
  puVar1 = (undefined *)(param_2 + 1);
  puVar2 = (undefined *)((int)register0x00000038 + -0x108);
  if (0x100 < (int)puVar1) {
    _malloc();
    puVar2 = puVar1;
  }
  _memmove(puVar2,param_1,param_2);
  puVar2[param_2] = 0;
  puVar1 = puVar2;
  _NXUniqueString(puVar2);
  if (0x100 < param_2 + 1) {
    _free(puVar2);
  }
  return CONCAT44(param_2,puVar1);
}
/* GHIDRADEC_FUNCTION index=3135 start=0xf00ee2e0 */

/* WARNING: Removing unreachable block (ram,0xf00ee2fc) */
/* WARNING: Removing unreachable block (ram,0xf00ee2e4) */

undefined8 _NXCopyStringBufferFromZone(int param_1,int param_2)

{
  int iVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
  if (!in_DECOMPILE_MODE) {
    *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
    *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
    *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
    *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
    *(undefined4 *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = unaff_i4;
    *(undefined4 *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = unaff_i5;
    *(undefined4 *)((in_CWP * 0x10 + 6) * 4 + 0x8000) = unaff_fp;
    *(undefined4 *)((in_CWP * 0x10 + 7) * 4 + 0x8000) = unaff_i7;
    *(undefined4 *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = unaff_l0;
    *(undefined4 *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = unaff_l1;
    *(undefined4 *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = unaff_l4;
    *(undefined4 *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = unaff_l5;
    *(undefined4 *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = unaff_l6;
    *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_l7;
  }
  _strlen(param_1);
  iVar1 = param_2;
  (**(code **)(param_2 + 4))(param_2,param_1 + 1);
  _strcpy();
  return CONCAT44(param_2,iVar1);
}
/* GHIDRADEC_FUNCTION index=3136 start=0xf00ee30c */

/* WARNING: Removing unreachable block (ram,0xf00ee31c) */
/* WARNING: Removing unreachable block (ram,0xf00ee310) */

undefined8 _NXCopyStringBuffer(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
  if (!in_DECOMPILE_MODE) {
    *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
    *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
    *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
    *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
    *(undefined4 *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = unaff_i4;
    *(undefined4 *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = unaff_i5;
    *(undefined4 *)((in_CWP * 0x10 + 6) * 4 + 0x8000) = unaff_fp;
    *(undefined4 *)((in_CWP * 0x10 + 7) * 4 + 0x8000) = unaff_i7;
    *(undefined4 *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = unaff_l0;
    *(undefined4 *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = unaff_l1;
    *(undefined4 *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = unaff_l4;
    *(undefined4 *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = unaff_l5;
    *(undefined4 *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = unaff_l6;
    *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_l7;
  }
  uVar1 = param_1;
  _NXDefaultMallocZone();
  _NXCopyStringBufferFromZone(param_1,uVar1);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3137 start=0xf00ee3f4 */

/* WARNING: Removing unreachable block (ram,0xf00ee4f8) */
/* WARNING: Removing unreachable block (ram,0xf00ee4b4) */
/* WARNING: Removing unreachable block (ram,0xf00ee49c) */
/* WARNING: Removing unreachable block (ram,0xf00ee4c8) */
/* WARNING: Removing unreachable block (ram,0xf00ee508) */
/* WARNING: Removing unreachable block (ram,0xf00ee450) */

undefined8 _NXCreateMapTableFromZone(int *param_1,undefined4 param_2,int *param_3)

{
  int iVar1;
  undefined *puVar2;
  int *piVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int *piVar6;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  undefined auStackX_0 [92];
  
  if (!in_DECOMPILE_MODE) {
    *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
    *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
    *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
    *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
    *(undefined4 *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = unaff_i4;
    *(undefined4 *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = unaff_i5;
    *(undefined4 *)((in_CWP * 0x10 + 6) * 4 + 0x8000) = unaff_fp;
    *(undefined4 *)((in_CWP * 0x10 + 7) * 4 + 0x8000) = unaff_i7;
    *(undefined4 *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = unaff_l0;
    *(undefined4 *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = unaff_l1;
    *(undefined4 *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = unaff_l4;
    *(undefined4 *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = unaff_l5;
    *(undefined4 *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = unaff_l6;
    *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_l7;
  }
  piVar6 = param_3;
  (*(code *)param_3[1])(param_3,0x10);
  if (dword_F012F0A8 == (undefined *)0x0) {
    *(undefined4 *)((int)register0x00000038 + -0x18) = unk_F012F098._0_4_;
    *(undefined4 *)((int)register0x00000038 + -0x14) = unk_F012F098._4_4_;
    *(undefined4 *)((int)register0x00000038 + -0x10) = unk_F012F098._8_4_;
    *(undefined4 *)((int)register0x00000038 + -0xc) = unk_F012F098._12_4_;
    puVar2 = (undefined *)((int)register0x00000038 + -0x18);
    _NXCreateHashTable(puVar2,0,0);
    iVar1 = *param_1;
    dword_F012F0A8 = puVar2;
  }
  else {
    iVar1 = *param_1;
  }
  if ((((iVar1 == 0) || (param_1[1] == 0)) || (param_1[2] == 0)) || (param_1[3] != 0)) {
    __NXLogError(aNxcreatemaptab);
    piVar6 = (int *)0x0;
  }
  else {
    puVar2 = dword_F012F0A8;
    _NXHashGet(dword_F012F0A8,param_1);
    if (puVar2 == (undefined *)0x0) {
      piVar3 = (int *)0x10;
      _malloc();
      *piVar3 = *param_1;
      piVar3[1] = param_1[1];
      piVar3[2] = param_1[2];
      piVar3[3] = param_1[3];
      _NXHashInsert(dword_F012F0A8,piVar3);
      *piVar6 = (int)piVar3;
    }
    else {
      *piVar6 = (int)puVar2;
    }
    piVar6[1] = 0;
    uVar4 = param_2;
    sub_F00EE32C();
    iVar1 = 1 << ((char)uVar4 + 1U & 0x1f);
    iVar5 = iVar1 + -1;
    piVar6[2] = iVar5;
    (*(code *)param_3[1])(param_3,iVar5 * 8);
    piVar3 = param_3;
    for (iVar1 = iVar1 + -2; iVar1 != -1; iVar1 = iVar1 + -1) {
      *piVar3 = -1;
      piVar3[1] = 0;
      piVar3 = piVar3 + 2;
    }
    piVar6[3] = (int)param_3;
  }
  return CONCAT44(param_2,piVar6);
}
/* GHIDRADEC_FUNCTION index=3138 start=0xf00ee570 */

/* WARNING: Removing unreachable block (ram,0xf00ee5a4) */
/* WARNING: Removing unreachable block (ram,0xf00ee594) */

undefined8 _NXCreateMapTable(undefined4 *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 unaff_l0;
  undefined *puVar2;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  undefined auStackX_0 [92];
  
  if (!in_DECOMPILE_MODE) {
    *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
    *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
    *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
    *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
    *(undefined4 *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = unaff_i4;
    *(undefined4 *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = unaff_i5;
    *(undefined4 *)((in_CWP * 0x10 + 6) * 4 + 0x8000) = unaff_fp;
    *(undefined4 *)((in_CWP * 0x10 + 7) * 4 + 0x8000) = unaff_i7;
    *(undefined4 *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = unaff_l0;
    *(undefined4 *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = unaff_l1;
    *(undefined4 *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = unaff_l4;
    *(undefined4 *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = unaff_l5;
    *(undefined4 *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = unaff_l6;
    *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_l7;
  }
  *(undefined4 *)((int)register0x00000038 + -0x18) = *param_1;
  *(undefined4 *)((int)register0x00000038 + -0x14) = param_1[1];
  *(undefined4 *)((int)register0x00000038 + -0x10) = param_1[2];
  uVar1 = param_1[3];
  *(undefined4 *)((int)register0x00000038 + -0xc) = uVar1;
  puVar2 = (undefined *)((int)register0x00000038 + -0x18);
  _NXDefaultMallocZone();
  _NXCreateMapTableFromZone(puVar2,param_2,uVar1);
  return CONCAT44(param_2,puVar2);
}
/* GHIDRADEC_FUNCTION index=3139 start=0xf00ee5b4 */

/* WARNING: Removing unreachable block (ram,0xf00ee5c0) */
/* WARNING: Removing unreachable block (ram,0xf00ee5c8) */
/* WARNING: Removing unreachable block (ram,0xf00ee5b8) */

undefined8 _NXFreeMapTable(int param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
  if (!in_DECOMPILE_MODE) {
    *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
    *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
    *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
    *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
    *(undefined4 *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = unaff_i4;
    *(undefined4 *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = unaff_i5;
    *(undefined4 *)((in_CWP * 0x10 + 6) * 4 + 0x8000) = unaff_fp;
    *(undefined4 *)((in_CWP * 0x10 + 7) * 4 + 0x8000) = unaff_i7;
    *(undefined4 *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = unaff_l0;
    *(undefined4 *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = unaff_l1;
    *(undefined4 *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = unaff_l4;
    *(undefined4 *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = unaff_l5;
    *(undefined4 *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = unaff_l6;
    *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_l7;
  }
  _NXResetMapTable(param_1);
  _free(*(undefined4 *)(param_1 + 0xc));
  _free(param_1);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3140 start=0xf00ee5d8 */

undefined8 _NXResetMapTable(int *param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
  int *piVar1;
  undefined4 unaff_l1;
  int iVar2;
  code *pcVar3;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
  if (!in_DECOMPILE_MODE) {
    *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
    *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
    *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
    *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
    *(undefined4 *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = unaff_i4;
    *(undefined4 *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = unaff_i5;
    *(undefined4 *)((in_CWP * 0x10 + 6) * 4 + 0x8000) = unaff_fp;
    *(undefined4 *)((in_CWP * 0x10 + 7) * 4 + 0x8000) = unaff_i7;
    *(undefined4 *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = unaff_l0;
    *(undefined4 *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = unaff_l1;
    *(undefined4 *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = unaff_l4;
    *(undefined4 *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = unaff_l5;
    *(undefined4 *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = unaff_l6;
    *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_l7;
  }
  piVar1 = (int *)param_1[3];
  iVar2 = param_1[2];
  pcVar3 = *(code **)(*param_1 + 8);
  while (iVar2 = iVar2 + -1, iVar2 != -1) {
    if (*piVar1 != -1) {
      (*pcVar3)(param_1,*piVar1,piVar1[1]);
      *piVar1 = -1;
      piVar1[1] = 0;
    }
    piVar1 = piVar1 + 2;
  }
  param_1[1] = 0;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3141 start=0xf00ee638 */

/* WARNING: Removing unreachable block (ram,0xf00ee674) */
/* WARNING: Removing unreachable block (ram,0xf00ee694) */
/* WARNING: Removing unreachable block (ram,0xf00ee65c) */

undefined8 _NXCompareMapTables(int param_1,int param_2)

{
  int iVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar2;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  undefined auStackX_0 [92];
  
  if (!in_DECOMPILE_MODE) {
    *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
    *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
    *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
    *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
    *(undefined4 *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = unaff_i4;
    *(undefined4 *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = unaff_i5;
    *(undefined4 *)((in_CWP * 0x10 + 6) * 4 + 0x8000) = unaff_fp;
    *(undefined4 *)((in_CWP * 0x10 + 7) * 4 + 0x8000) = unaff_i7;
    *(undefined4 *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = unaff_l0;
    *(undefined4 *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = unaff_l1;
    *(undefined4 *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = unaff_l4;
    *(undefined4 *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = unaff_l5;
    *(undefined4 *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = unaff_l6;
    *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_l7;
  }
  if (param_1 == param_2) {
    uVar2 = 1;
  }
  else if (*(int *)(param_1 + 4) == *(int *)(param_2 + 4)) {
    iVar1 = param_1;
    _NXInitMapState();
    *(int *)((int)register0x00000038 + -0xc) = iVar1;
    do {
      iVar1 = param_1;
      _NXNextMapState(param_1,(undefined *)((int)register0x00000038 + -0xc),
                      (undefined *)((int)register0x00000038 + -0x10),
                      (undefined *)((int)register0x00000038 + -0x14));
      if (iVar1 == 0) {
        uVar2 = 1;
        goto locret_F00EE6AC;
      }
      iVar1 = param_2;
      _NXMapMember(param_2,*(undefined4 *)((int)register0x00000038 + -0x10),
                   (undefined *)((int)register0x00000038 + -0x14));
    } while (iVar1 != -1);
    uVar2 = 0;
  }
  else {
    uVar2 = 0;
  }
locret_F00EE6AC:
  return CONCAT44(param_2,uVar2);
}
/* GHIDRADEC_FUNCTION index=3142 start=0xf00ee6b4 */

undefined4 _NXCountMapTable(int param_1)

{
  return *(undefined4 *)(param_1 + 4);
}
/* GHIDRADEC_FUNCTION index=3143 start=0xf00ee6bc */

/* WARNING: Removing unreachable block (ram,0xf00ee708) */

undefined8 _NXMapMember(int *param_1,int param_2,int *param_3)

{
  uint uVar1;
  uint uVar2;
  int *piVar3;
  uint uVar4;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int iVar5;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int *piVar6;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
  if (!in_DECOMPILE_MODE) {
    *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
    *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
    *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
    *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
    *(undefined4 *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = unaff_i4;
    *(undefined4 *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = unaff_i5;
    *(undefined4 *)((in_CWP * 0x10 + 6) * 4 + 0x8000) = unaff_fp;
    *(undefined4 *)((in_CWP * 0x10 + 7) * 4 + 0x8000) = unaff_i7;
    *(undefined4 *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = unaff_l0;
    *(undefined4 *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = unaff_l1;
    *(undefined4 *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = unaff_l4;
    *(undefined4 *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = unaff_l5;
    *(undefined4 *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = unaff_l6;
    *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_l7;
  }
  iVar5 = param_1[3];
  piVar6 = param_1;
  (**(code **)*param_1)(param_1,param_2);
  uVar2 = ((uint)piVar6 & 0xffff ^ (uint)piVar6 >> 0x10) * 0xfff1 + (int)piVar6;
  .urem(uVar2,param_1[2]);
  piVar6 = (int *)(iVar5 + uVar2 * 8);
  if (*(int *)(iVar5 + uVar2 * 8) == -1) {
loc_F00EE824:
    iVar5 = -1;
  }
  else {
    dword_F012F0AC = dword_F012F0AC + 1;
    if (*piVar6 == param_2) {
      piVar3 = (int *)0x1;
    }
    else {
      piVar3 = param_1;
      (**(code **)(*param_1 + 4))(param_1,*piVar6,param_2);
    }
    uVar1 = uVar2;
    if (piVar3 == (int *)0x0) {
      do {
        uVar4 = 0;
        if (uVar1 + 1 < (uint)param_1[2]) {
          uVar4 = uVar1 + 1;
        }
        if (uVar4 == uVar2) goto loc_F00EE824;
        DAT_f012f0b4 = DAT_f012f0b4 + 1;
        piVar6 = (int *)(iVar5 + uVar4 * 8);
        if (*(int *)(iVar5 + uVar4 * 8) == -1) {
          iVar5 = -1;
          goto locret_F00EE828;
        }
        if (*piVar6 == param_2) {
          piVar3 = (int *)0x1;
        }
        else {
          piVar3 = param_1;
          (**(code **)(*param_1 + 4))(param_1,*piVar6,param_2);
        }
        uVar1 = uVar4;
      } while (piVar3 == (int *)0x0);
      *param_3 = piVar6[1];
      iVar5 = *piVar6;
    }
    else {
      *param_3 = piVar6[1];
      dword_F012F0B0 = dword_F012F0B0 + 1;
      iVar5 = *piVar6;
    }
  }
locret_F00EE828:
  return CONCAT44(param_2,iVar5);
}
/* GHIDRADEC_FUNCTION index=3144 start=0xf00ee830 */

/* WARNING: Removing unreachable block (ram,0xf00ee878) */

undefined8 _NXMapGet(int *param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  int *piVar3;
  uint uVar4;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int *piVar5;
  int iVar6;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar7;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  undefined auStackX_0 [92];
  
  if (!in_DECOMPILE_MODE) {
    *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
    *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
    *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
    *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
    *(undefined4 *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = unaff_i4;
    *(undefined4 *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = unaff_i5;
    *(undefined4 *)((in_CWP * 0x10 + 6) * 4 + 0x8000) = unaff_fp;
    *(undefined4 *)((in_CWP * 0x10 + 7) * 4 + 0x8000) = unaff_i7;
    *(undefined4 *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = unaff_l0;
    *(undefined4 *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = unaff_l1;
    *(undefined4 *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = unaff_l4;
    *(undefined4 *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = unaff_l5;
    *(undefined4 *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = unaff_l6;
    *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_l7;
  }
  iVar6 = param_1[3];
  piVar5 = param_1;
  (**(code **)*param_1)(param_1,param_2);
  uVar2 = ((uint)piVar5 & 0xffff ^ (uint)piVar5 >> 0x10) * 0xfff1 + (int)piVar5;
  .urem(uVar2,param_1[2]);
  piVar5 = (int *)(iVar6 + uVar2 * 8);
  if (*(int *)(iVar6 + uVar2 * 8) == -1) {
loc_F00EE994:
    iVar6 = -1;
  }
  else {
    dword_F012F0AC = dword_F012F0AC + 1;
    if (*piVar5 == param_2) {
      piVar3 = (int *)0x1;
    }
    else {
      piVar3 = param_1;
      (**(code **)(*param_1 + 4))(param_1,*piVar5,param_2);
    }
    uVar1 = uVar2;
    if (piVar3 == (int *)0x0) {
      do {
        uVar4 = 0;
        if (uVar1 + 1 < (uint)param_1[2]) {
          uVar4 = uVar1 + 1;
        }
        if (uVar4 == uVar2) goto loc_F00EE994;
        DAT_f012f0b4 = DAT_f012f0b4 + 1;
        piVar5 = (int *)(iVar6 + uVar4 * 8);
        if (*(int *)(iVar6 + uVar4 * 8) == -1) {
          iVar6 = -1;
          goto loc_F00EE998;
        }
        if (*piVar5 == param_2) {
          piVar3 = (int *)0x1;
        }
        else {
          piVar3 = param_1;
          (**(code **)(*param_1 + 4))(param_1,*piVar5,param_2);
        }
        uVar1 = uVar4;
      } while (piVar3 == (int *)0x0);
      *(int *)((int)register0x00000038 + -0xc) = piVar5[1];
      iVar6 = *piVar5;
    }
    else {
      *(int *)((int)register0x00000038 + -0xc) = piVar5[1];
      dword_F012F0B0 = dword_F012F0B0 + 1;
      iVar6 = *piVar5;
    }
  }
loc_F00EE998:
  uVar7 = 0;
  if (iVar6 != -1) {
    uVar7 = *(undefined4 *)((int)register0x00000038 + -0xc);
  }
  return CONCAT44(param_2,uVar7);
}
/* GHIDRADEC_FUNCTION index=3145 start=0xf00eea94 */

/* WARNING: Removing unreachable block (ram,0xf00eecb0) */
/* WARNING: Removing unreachable block (ram,0xf00eed04) */
/* WARNING: Removing unreachable block (ram,0xf00eebb4) */
/* WARNING: Removing unreachable block (ram,0xf00eeadc) */

undefined8 _NXMapInsert(int *param_1,int param_2,int param_3)

{
  uint uVar1;
  undefined *puVar2;
  int *piVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int *piVar7;
  int iVar8;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  undefined auStackX_0 [92];
  
  if (!in_DECOMPILE_MODE) {
    *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
    *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
    *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
    *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
    *(undefined4 *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = unaff_i4;
    *(undefined4 *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = unaff_i5;
    *(undefined4 *)((in_CWP * 0x10 + 6) * 4 + 0x8000) = unaff_fp;
    *(undefined4 *)((in_CWP * 0x10 + 7) * 4 + 0x8000) = unaff_i7;
    *(undefined4 *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = unaff_l0;
    *(undefined4 *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = unaff_l1;
    *(undefined4 *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = unaff_l4;
    *(undefined4 *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = unaff_l5;
    *(undefined4 *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = unaff_l6;
    *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_l7;
  }
  iVar8 = param_1[3];
  while( true ) {
    piVar7 = param_1;
    (**(code **)*param_1)(param_1,param_2);
    uVar1 = ((uint)piVar7 & 0xffff ^ (uint)piVar7 >> 0x10) * 0xfff1 + (int)piVar7;
    .urem(uVar1,param_1[2]);
    piVar7 = (int *)(iVar8 + uVar1 * 8);
    if (param_2 == -1) break;
    dword_F012F0C0 = dword_F012F0C0 + 1;
    if (*piVar7 == -1) {
      dword_F012F0C4 = dword_F012F0C4 + 1;
      *piVar7 = param_2;
      piVar7[1] = param_3;
      param_1[1] = param_1[1] + 1;
      goto loc_F00EED0C;
    }
    if (*piVar7 == param_2) {
      piVar3 = (int *)0x1;
    }
    else {
      piVar3 = param_1;
      (**(code **)(*param_1 + 4))(param_1,*piVar7,param_2);
    }
    if (piVar3 != (int *)0x0) {
      iVar8 = piVar7[1];
      dword_F012F0C4 = dword_F012F0C4 + 1;
      goto loc_F00EEB90;
    }
    uVar6 = uVar1;
    if (param_1[1] != param_1[2]) goto loc_F00EEBCC;
    sub_F00EE9B0(param_1);
    iVar8 = param_1[3];
  }
  puVar2 = aNxmapinsertInv;
loc_F00EED04:
  __NXLogError(puVar2);
loc_F00EED0C:
  iVar8 = 0;
  goto locret_F00EED10;
  while( true ) {
    DAT_f012f0c8 = DAT_f012f0c8 + 1;
    piVar7 = (int *)(iVar8 + uVar4 * 8);
    if (*(int *)(iVar8 + uVar4 * 8) == -1) {
      *(int *)((int)register0x00000038 + -0x10) = param_2;
      *(int *)((int)register0x00000038 + -0xc) = param_3;
      iVar5 = param_2;
      while (iVar5 != -1) {
        iVar5 = uVar1 * 8;
        *(undefined4 *)((int)register0x00000038 + -0x18) = *(undefined4 *)(iVar8 + iVar5);
        *(undefined4 *)((int)register0x00000038 + -0x14) = *(undefined4 *)(iVar8 + iVar5 + 4);
        *(undefined4 *)(iVar8 + iVar5) = *(undefined4 *)((int)register0x00000038 + -0x10);
        *(undefined4 *)(iVar8 + iVar5 + 4) = *(undefined4 *)((int)register0x00000038 + -0xc);
        *(undefined4 *)((int)register0x00000038 + -0x10) =
             *(undefined4 *)((int)register0x00000038 + -0x18);
        *(undefined4 *)((int)register0x00000038 + -0xc) =
             *(undefined4 *)((int)register0x00000038 + -0x14);
        uVar6 = uVar1 + 1;
        uVar1 = 0;
        if (uVar6 < (uint)param_1[2]) {
          uVar1 = uVar6;
        }
        iVar5 = *(int *)((int)register0x00000038 + -0x10);
      }
      iVar8 = param_1[1];
      param_1[1] = iVar8 + 1;
      uVar1 = (iVar8 + 1) * 4;
      if (uVar1 < (uint)(param_1[2] * 3) || uVar1 + param_1[2] * -3 == 0) {
        iVar8 = 0;
      }
      else {
        sub_F00EE9B0(param_1);
        iVar8 = 0;
      }
      goto locret_F00EED10;
    }
    if (*piVar7 == param_2) {
      piVar3 = (int *)0x1;
    }
    else {
      piVar3 = param_1;
      (**(code **)(*param_1 + 4))(param_1,*piVar7,param_2);
    }
    uVar6 = uVar4;
    if (piVar3 != (int *)0x0) break;
loc_F00EEBCC:
    uVar4 = 0;
    if (uVar6 + 1 < (uint)param_1[2]) {
      uVar4 = uVar6 + 1;
    }
    if (uVar4 == uVar1) {
      puVar2 = aNxmapinsertBug;
      goto loc_F00EED04;
    }
  }
  iVar8 = piVar7[1];
loc_F00EEB90:
  if (iVar8 != param_3) {
    piVar7[1] = param_3;
  }
locret_F00EED10:
  return CONCAT44(param_2,iVar8);
}
/* GHIDRADEC_FUNCTION index=3146 start=0xf00eed18 */

/* WARNING: Removing unreachable block (ram,0xf00eef9c) */
/* WARNING: Removing unreachable block (ram,0xf00eee8c) */
/* WARNING: Removing unreachable block (ram,0xf00eee78) */
/* WARNING: Removing unreachable block (ram,0xf00eef5c) */
/* WARNING: Removing unreachable block (ram,0xf00eef78) */
/* WARNING: Removing unreachable block (ram,0xf00eed60) */

undefined8 _NXMapRemove(int *param_1,int param_2)

{
  uint uVar1;
  int *piVar2;
  uint uVar3;
  undefined *puVar4;
  int iVar5;
  uint uVar6;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int *piVar7;
  undefined4 *puVar8;
  int iVar9;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  int iVar10;
  undefined4 unaff_l6;
  uint uVar11;
  undefined4 unaff_l7;
  int iVar12;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  undefined auStackX_0 [92];
  
  if (!in_DECOMPILE_MODE) {
    *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
    *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
    *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
    *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
    *(undefined4 *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = unaff_i4;
    *(undefined4 *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = unaff_i5;
    *(undefined4 *)((in_CWP * 0x10 + 6) * 4 + 0x8000) = unaff_fp;
    *(undefined4 *)((in_CWP * 0x10 + 7) * 4 + 0x8000) = unaff_i7;
    *(undefined4 *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = unaff_l0;
    *(undefined4 *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = unaff_l1;
    *(undefined4 *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = unaff_l4;
    *(undefined4 *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = unaff_l5;
    *(undefined4 *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = unaff_l6;
    *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_l7;
  }
  iVar10 = param_1[3];
  piVar7 = param_1;
  (**(code **)*param_1)(param_1,param_2);
  uVar1 = ((uint)piVar7 & 0xffff ^ (uint)piVar7 >> 0x10) * 0xfff1 + (int)piVar7;
  .urem(uVar1,param_1[2]);
  piVar7 = (int *)(iVar10 + uVar1 * 8);
  uVar11 = 1;
  iVar9 = 0;
  iVar12 = 0;
  if (*(int *)(iVar10 + uVar1 * 8) != -1) {
    dword_F012F0CC = dword_F012F0CC + 1;
    iVar5 = *piVar7;
    if (iVar5 == param_2) {
      piVar2 = (int *)0x1;
    }
    else {
      piVar2 = param_1;
      (**(code **)(*param_1 + 4))(param_1,iVar5,param_2);
    }
    uVar3 = uVar1;
    if (piVar2 != (int *)0x0) {
      iVar9 = 1;
      iVar12 = piVar7[1];
    }
    while( true ) {
      uVar6 = uVar3 + 1;
      uVar3 = 0;
      if (uVar6 < (uint)param_1[2]) {
        uVar3 = uVar6;
      }
      if (uVar3 == uVar1) break;
      iVar5 = *(int *)(iVar10 + uVar3 * 8);
      if (iVar5 == -1) break;
      if (iVar5 == param_2) {
        piVar7 = (int *)0x1;
      }
      else {
        piVar7 = param_1;
        (**(code **)(*param_1 + 4))(param_1,iVar5,param_2);
      }
      uVar11 = uVar11 + 1;
      if (piVar7 != (int *)0x0) {
        iVar9 = iVar9 + 1;
        iVar12 = *(int *)(iVar10 + uVar3 * 8 + 4);
      }
    }
    if (iVar9 != 0) {
      if (iVar9 != 1) {
        __NXLogError(aNxmapremoveInc);
      }
      if (uVar11 < 0x11) {
        puVar4 = (undefined *)((int)register0x00000038 + -0x88);
      }
      else {
        puVar4 = (undefined *)((uVar11 - 1) * 8);
        _malloc();
      }
      iVar9 = 0;
      uVar3 = uVar11;
      while (uVar3 = uVar3 - 1, uVar3 != 0xffffffff) {
        iVar5 = *(int *)(iVar10 + uVar1 * 8);
        puVar8 = (undefined4 *)(iVar10 + uVar1 * 8);
        if (iVar5 == param_2) {
          piVar7 = (int *)0x1;
        }
        else {
          piVar7 = param_1;
          (**(code **)(*param_1 + 4))(param_1,iVar5,param_2);
        }
        if (piVar7 == (int *)0x0) {
          *(undefined4 *)(puVar4 + iVar9 * 8) = *puVar8;
          *(undefined4 *)(puVar4 + iVar9 * 8 + 4) = puVar8[1];
          iVar9 = iVar9 + 1;
          *puVar8 = 0xffffffff;
        }
        else {
          *puVar8 = 0xffffffff;
        }
        puVar8[1] = 0;
        uVar6 = uVar1 + 1;
        uVar1 = 0;
        if (uVar6 < (uint)param_1[2]) {
          uVar1 = uVar6;
        }
      }
      param_1[1] = param_1[1] - uVar11;
      if (iVar9 != uVar11 - 1) {
        __NXLogError(aNxmapremoveBug);
      }
      while( true ) {
        iVar9 = iVar9 + -1;
        if (iVar9 == -1) break;
        _NXMapInsert(param_1,*(undefined4 *)(puVar4 + iVar9 * 8),
                     *(undefined4 *)(puVar4 + iVar9 * 8 + 4));
      }
      if (0x10 < uVar11) {
        _free(puVar4);
      }
      goto locret_F00EEFA8;
    }
  }
  iVar12 = 0;
locret_F00EEFA8:
  return CONCAT44(param_2,iVar12);
}
/* GHIDRADEC_FUNCTION index=3147 start=0xf00eefb0 */

undefined4 _NXInitMapState(int param_1)

{
  return *(undefined4 *)(param_1 + 8);
}
/* GHIDRADEC_FUNCTION index=3148 start=0xf00eefb8 */

undefined4 _NXNextMapState(int param_1,int *param_2,int *param_3,undefined4 *param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 0xc);
  iVar2 = *param_2;
  while( true ) {
    *param_2 = iVar2 + -1;
    if (iVar2 + -1 == -1) {
      return 0;
    }
    iVar2 = *param_2;
    iVar1 = *(int *)(iVar3 + iVar2 * 8);
    if (iVar1 != -1) break;
    iVar2 = *param_2;
  }
  *param_3 = iVar1;
  *param_4 = *(undefined4 *)(iVar3 + iVar2 * 8 + 4);
  return 1;
}
/* GHIDRADEC_FUNCTION index=3149 start=0xf00ef010 */

uint __mapPtrHash(undefined4 param_1,uint param_2)

{
  return param_2 >> 0x10 ^ param_2;
}

