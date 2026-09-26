/* GHIDRADEC_FUNCTION index=3150 start=0xf00ef01c */

uint __mapStrHash(undefined4 param_1,byte *param_2)

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
/* GHIDRADEC_FUNCTION index=3151 start=0xf00ef09c */

/* WARNING: Removing unreachable block (ram,0xf00ef0a8) */

undefined8 __mapObjectHash(undefined4 param_1,undefined4 param_2)

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
  uVar1 = param_2;
  _objc_msgSend(param_2,paHash);
  return CONCAT44(param_2,uVar1);
}
/* GHIDRADEC_FUNCTION index=3152 start=0xf00ef0b8 */

bool __mapPtrIsEqual(undefined4 param_1,int param_2,int param_3)

{
  return param_2 == param_3;
}
/* GHIDRADEC_FUNCTION index=3153 start=0xf00ef0c8 */

/* WARNING: Removing unreachable block (ram,0xf00ef0fc) */
/* WARNING: Removing unreachable block (ram,0xf00ef124) */

undefined8 __mapStrIsEqual(undefined4 param_1,char *param_2,char *param_3)

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
/* GHIDRADEC_FUNCTION index=3154 start=0xf00ef13c */

/* WARNING: Removing unreachable block (ram,0xf00ef14c) */

undefined8 __mapObjectIsEqual(undefined4 param_1,undefined4 param_2,undefined4 param_3)

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
  uVar1 = param_2;
  _objc_msgSend(param_2,paIsequal,param_3);
  return CONCAT44(param_2,(int)(char)uVar1);
}
/* GHIDRADEC_FUNCTION index=3155 start=0xf00ef164 */

void __mapNoFree(void)

{
  return;
}
/* GHIDRADEC_FUNCTION index=3156 start=0xf00ef16c */

/* WARNING: Removing unreachable block (ram,0xf00ef178) */

undefined8 __mapObjectFree(undefined4 param_1,undefined4 param_2)

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
  _objc_msgSend(param_2,paFree);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3157 start=0xf00ef188 */

undefined4 * _object_getClassName(int *param_1)

{
  undefined4 *puVar1;
  
  if (param_1 == (int *)0x0) {
    puVar1 = &aNil;
  }
  else {
    puVar1 = *(undefined4 **)(*param_1 + 8);
  }
  return puVar1;
}
/* GHIDRADEC_FUNCTION index=3158 start=0xf00ef1ac */

int _object_getIndexedIvars(int *param_1)

{
  return (int)param_1 + *(int *)(*param_1 + 0x14);
}
/* GHIDRADEC_FUNCTION index=3159 start=0xf00ef1bc */

/* WARNING: Removing unreachable block (ram,0xf00ef224) */
/* WARNING: Removing unreachable block (ram,0xf00ef214) */
/* WARNING: Removing unreachable block (ram,0xf00ef1d8) */

undefined8 __internal_class_createInstanceFromZone(int param_1,int param_2,int *param_3)

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
  if (param_1 == 0) {
    ___objc_error(0,aAllocatingNilO,0);
    iVar1 = iRam00000014;
  }
  else {
    iVar1 = *(int *)(param_1 + 0x14);
  }
  (*(code *)param_3[1])(param_3,param_2 + iVar1);
  if (param_3 == (int *)0x0) {
    ___objc_error(param_1,aFailedOutOfMem_0,*(undefined4 *)(param_1 + 8),param_2);
    param_3 = (int *)0x0;
  }
  else {
    _bzero(param_3,param_2 + iVar1);
    *param_3 = param_1;
  }
  return CONCAT44(param_2,param_3);
}
/* GHIDRADEC_FUNCTION index=3160 start=0xf00ef238 */
//Error decompiling function: _class_createInstanceFromZone @ 0xf00ef238
//Read pipe is bad
/* GHIDRADEC_FUNCTION index=3161 start=0xf00ef25c */

/* WARNING: Removing unreachable block (ram,0xf00ef270) */
/* WARNING: Removing unreachable block (ram,0xf00ef260) */

undefined8 __internal_class_createInstance(undefined4 param_1,undefined4 param_2)

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
  __internal_class_createInstanceFromZone(param_1,param_2,uVar1);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3162 start=0xf00ef280 */
//Error decompiling function: _class_createInstance @ 0xf00ef280
//Read pipe is bad
/* GHIDRADEC_FUNCTION index=3163 start=0xf00ef2a0 */

void _class_setVersion(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0xc) = param_2;
  return;
}
/* GHIDRADEC_FUNCTION index=3164 start=0xf00ef2a8 */

undefined4 _class_getVersion(int param_1)

{
  return *(undefined4 *)(param_1 + 0xc);
}
/* GHIDRADEC_FUNCTION index=3165 start=0xf00ef2b0 */

int * _class_getInstanceMethod(int param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  
  if (param_1 != 0) {
    if (param_2 == 0) {
      return (int *)0x0;
    }
    piVar3 = *(int **)(param_1 + 0x1c);
    while( true ) {
      if (piVar3 == (int *)0x0) {
        param_1 = *(int *)(param_1 + 4);
      }
      else {
        iVar1 = piVar3[1];
        while( true ) {
          piVar2 = piVar3 + 2;
          while (iVar1 = iVar1 + -1, -1 < iVar1) {
            if (param_2 == *piVar2) {
              return piVar2;
            }
            piVar2 = piVar2 + 3;
          }
          piVar3 = (int *)*piVar3;
          if (piVar3 == (int *)0x0) break;
          iVar1 = piVar3[1];
        }
        param_1 = *(int *)(param_1 + 4);
      }
      if (param_1 == 0) break;
      piVar3 = *(int **)(param_1 + 0x1c);
    }
  }
  return (int *)0x0;
}
/* GHIDRADEC_FUNCTION index=3166 start=0xf00ef32c */

int * _class_getClassMethod(undefined4 *param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  
  if (param_1 != (undefined4 *)0x0) {
    if (param_2 == 0) {
      return (int *)0x0;
    }
    if ((param_1[4] & 2) == 0) {
      param_1 = (undefined4 *)*param_1;
    }
    piVar3 = (int *)param_1[7];
    while( true ) {
      if (piVar3 == (int *)0x0) {
        param_1 = (undefined4 *)param_1[1];
      }
      else {
        iVar1 = piVar3[1];
        while( true ) {
          piVar2 = piVar3 + 2;
          while (iVar1 = iVar1 + -1, -1 < iVar1) {
            if (param_2 == *piVar2) {
              return piVar2;
            }
            piVar2 = piVar2 + 3;
          }
          piVar3 = (int *)*piVar3;
          if (piVar3 == (int *)0x0) break;
          iVar1 = piVar3[1];
        }
        param_1 = (undefined4 *)param_1[1];
      }
      if (param_1 == (undefined4 *)0x0) break;
      piVar3 = (int *)param_1[7];
    }
  }
  return (int *)0x0;
}
/* GHIDRADEC_FUNCTION index=3167 start=0xf00ef430 */

/* WARNING: Removing unreachable block (ram,0xf00ef44c) */

undefined8 _class_getInstanceVariable(int param_1,int param_2)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar1;
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
  if (param_1 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = 0;
    if (param_2 != 0) {
      sub_F00EF3B8(param_1);
      iVar1 = param_1;
    }
  }
  return CONCAT44(param_2,iVar1);
}
/* GHIDRADEC_FUNCTION index=3168 start=0xf00ef550 */

/* WARNING: Removing unreachable block (ram,0xf00ef558) */

undefined8 __objc_flush_caches(undefined4 param_1,undefined4 param_2)

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
  sub_F00EF468(param_1,1);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3169 start=0xf00ef568 */

/* WARNING: Removing unreachable block (ram,0xf00ef57c) */

undefined8 _class_addMethods(int param_1,undefined4 *param_2)

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
  *param_2 = *(undefined4 *)(param_1 + 0x1c);
  *(undefined4 **)(param_1 + 0x1c) = param_2;
  sub_F00EF468(param_1,0);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3170 start=0xf00ef58c */

/* WARNING: Removing unreachable block (ram,0xf00ef594) */

undefined8 _class_addClassMethods(undefined4 *param_1,undefined4 param_2)

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
  _class_addMethods(*param_1,param_2);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3171 start=0xf00ef5a4 */

/* WARNING: Removing unreachable block (ram,0xf00ef5f8) */

undefined8 _class_removeMethods(int param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
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
  if (*(undefined4 **)(param_1 + 0x1c) == param_2) {
    *(undefined4 *)(param_1 + 0x1c) = *param_2;
  }
  else {
    puVar1 = (undefined4 *)**(undefined4 **)(param_1 + 0x1c);
    puVar3 = *(undefined4 **)(param_1 + 0x1c);
    while (puVar2 = puVar1, puVar2 != (undefined4 *)0x0) {
      if (puVar2 == param_2) {
        *puVar3 = *puVar2;
        puVar1 = (undefined4 *)0x0;
      }
      else {
        puVar1 = (undefined4 *)*puVar2;
        puVar3 = puVar2;
      }
    }
  }
  sub_F00EF468(param_1,0);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3172 start=0xf00ef608 */

void __class_removeProtocols(int param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  if (*(undefined4 **)(param_1 + 0x24) == param_2) {
    *(undefined4 *)(param_1 + 0x24) = *param_2;
  }
  else {
    puVar1 = (undefined4 *)**(undefined4 **)(param_1 + 0x24);
    puVar3 = *(undefined4 **)(param_1 + 0x24);
    while (puVar2 = puVar1, puVar2 != (undefined4 *)0x0) {
      if (puVar2 == param_2) {
        *puVar3 = *puVar2;
        puVar1 = (undefined4 *)0x0;
      }
      else {
        puVar1 = (undefined4 *)*puVar2;
        puVar3 = puVar2;
      }
    }
  }
  return;
}
/* GHIDRADEC_FUNCTION index=3173 start=0xf00ef65c */

/* WARNING: Removing unreachable block (ram,0xf00ef690) */
/* WARNING: Removing unreachable block (ram,0xf00ef678) */

undefined8 _objc_getOrigClass(int param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar1;
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
  iVar1 = 0;
  if (dword_F012F0DC != 0) {
    iVar1 = dword_F012F0DC;
    _NXMapGet(dword_F012F0DC,param_1);
  }
  if (iVar1 == 0) {
    _objc_getClass(param_1);
    iVar1 = param_1;
  }
  return CONCAT44(param_2,iVar1);
}
/* GHIDRADEC_FUNCTION index=3174 start=0xf00ef730 */

/* WARNING: Removing unreachable block (ram,0xf00ef7b0) */
/* WARNING: Removing unreachable block (ram,0xf00ef848) */
/* WARNING: Removing unreachable block (ram,0xf00ef82c) */
/* WARNING: Removing unreachable block (ram,0xf00ef814) */
/* WARNING: Removing unreachable block (ram,0xf00ef804) */
/* WARNING: Removing unreachable block (ram,0xf00ef7f0) */
/* WARNING: Removing unreachable block (ram,0xf00ef7e0) */
/* WARNING: Removing unreachable block (ram,0xf00ef740) */
/* WARNING: Removing unreachable block (ram,0xf00ef7e8) */
/* WARNING: Removing unreachable block (ram,0xf00ef7fc) */
/* WARNING: Removing unreachable block (ram,0xf00ef80c) */
/* WARNING: Removing unreachable block (ram,0xf00ef820) */
/* WARNING: Removing unreachable block (ram,0xf00ef838) */
/* WARNING: Removing unreachable block (ram,0xf00ef898) */
/* WARNING: Removing unreachable block (ram,0xf00ef778) */
/* WARNING: Removing unreachable block (ram,0xf00ef734) */

undefined8 _class_poseAs(int *param_1,int *param_2)

{
  code *pcVar1;
  int *piVar2;
  int *piVar3;
  undefined4 unaff_l0;
  undefined *puVar4;
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
  __objc_headerCount();
  __objc_headerVector(0);
  if (param_1 != param_2) {
    if ((int *)param_1[1] == param_2) {
      if (param_1[6] == 0) {
        *(undefined2 *)((int)register0x00000038 + -0x108) = 0x5f25;
        *(undefined *)((int)register0x00000038 + -0x106) = 0;
        puVar4 = (undefined *)((int)register0x00000038 + -0x108);
        _strcat(puVar4,param_2[2]);
        _strlen(puVar4);
        sub_F00EFBA0(puVar4 + 1);
        _strcpy();
        sub_F00EF6A4(param_2);
        piVar2 = param_1;
        sub_F00EF6A4(param_1);
        _objc_getClasses();
        _NXHashRemove();
        _NXHashRemove(piVar2,param_2);
        piVar3 = param_1;
        _object_copy(param_1,0);
        _NXHashInsert(piVar2,piVar3);
        param_1[4] = param_1[4] | 8;
        *(uint *)(*param_1 + 0x10) = *(uint *)(*param_1 + 0x10) | 8;
        param_1[2] = param_2[2];
        *(undefined4 *)(*param_1 + 8) = *(undefined4 *)(*param_2 + 8);
        param_1[3] = param_2[3];
        _NXInitHashState((undefined *)((int)register0x00000038 + -0x110),piVar2);
                    /* WARNING: Does not return */
        pcVar1 = (code *)IllegalInstructionTrap(8);
        (*pcVar1)();
      }
      _objc_msgSend(param_1,paError,aSPoseasSSDefin,param_1[2],param_2[2],param_1[2]);
    }
    else {
      _objc_msgSend(param_1,paError,aSPoseasSTarget,param_1[2],param_2[2]);
    }
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3175 start=0xf00efad4 */

/* WARNING: Removing unreachable block (ram,0xf00efb34) */
/* WARNING: Removing unreachable block (ram,0xf00efb08) */
/* WARNING: Removing unreachable block (ram,0xf00efb90) */
/* WARNING: Removing unreachable block (ram,0xf00efaf0) */

undefined8 __class_install_relationships(undefined4 *param_1,int param_2)

{
  bool bVar1;
  int iVar2;
  int *piVar3;
  undefined4 unaff_l0;
  int *piVar4;
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
  piVar4 = (int *)*param_1;
  piVar4[3] = param_2;
  iVar2 = param_1[1];
  bVar1 = false;
  if (iVar2 != 0) {
    _objc_getClass();
    if (iVar2 == 0) {
      bVar1 = true;
    }
    else {
      param_1[1] = iVar2;
    }
  }
  piVar3 = (int *)*piVar4;
  _objc_getClass();
  if (piVar3 == (int *)0x0) {
    bVar1 = true;
  }
  else {
    *piVar4 = *piVar3;
  }
  piVar3 = (int *)piVar4[1];
  if (piVar3 == (int *)0x0) {
    piVar4[1] = (int)param_1;
  }
  else {
    _objc_getClass();
    if (piVar3 == (int *)0x0) {
      bVar1 = true;
    }
    else {
      piVar4[1] = *piVar3;
    }
  }
  if (param_1[8] == 0) {
    param_1[8] = _emptyCache;
    iVar2 = piVar4[8];
  }
  else {
    iVar2 = piVar4[8];
  }
  if (iVar2 == 0) {
    piVar4[8] = (int)_emptyCache;
  }
  if (bVar1) {
    __objc_fatal(aPleaseLinkAppr);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3176 start=0xf00efbe4 */

/* WARNING: Removing unreachable block (ram,0xf00efcc0) */
/* WARNING: Removing unreachable block (ram,0xf00efcb8) */
/* WARNING: Removing unreachable block (ram,0xf00efcf4) */
/* WARNING: Removing unreachable block (ram,0xf00efc18) */

undefined8 _class_respondsToMethod(int param_1,int *param_2)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  uint uVar6;
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
  if (param_2 == (int *)0x0) {
    uVar6 = 0;
  }
  else {
    piVar1 = param_2;
    do {
      uVar6 = (uint)piVar1 & **(uint **)(param_1 + 0x20);
      piVar1 = (int *)(uVar6 * 4);
      piVar3 = (int *)(*(uint **)(param_1 + 0x20) + 2)[uVar6];
      if (piVar3 == (int *)0x0) {
        piVar3 = *(int **)(param_1 + 0x1c);
        iVar5 = param_1;
        while( true ) {
          if (piVar3 == (int *)0x0) {
            iVar5 = *(int *)(iVar5 + 4);
          }
          else {
            iVar4 = piVar3[1];
            while( true ) {
              piVar2 = piVar3 + 2;
              while (iVar4 = iVar4 + -1, -1 < iVar4) {
                piVar1 = (int *)*piVar2;
                if (param_2 == piVar1) {
                  sub_F00F00E4(param_1);
                  uVar6 = 1;
                  goto locret_F00EFD00;
                }
                piVar2 = piVar2 + 3;
              }
              piVar3 = (int *)*piVar3;
              if (piVar3 == (int *)0x0) break;
              iVar4 = piVar3[1];
            }
            iVar5 = *(int *)(iVar5 + 4);
          }
          if (iVar5 == 0) break;
          piVar3 = *(int **)(iVar5 + 0x1c);
        }
        _NXDefaultMallocZone();
        piVar3 = piVar1;
        _NXDefaultMallocZone();
        (*(code *)piVar1[1])();
        *piVar3 = (int)param_2;
        piVar3[1] = (int)&asc_F00FA528;
        piVar3[2] = (int)__objc_msgForward;
        sub_F00F00E4(param_1);
        uVar6 = 0;
        goto locret_F00EFD00;
      }
      piVar1 = (int *)(uVar6 + 1);
    } while ((int *)*piVar3 != param_2);
    uVar6 = (uint)((code *)piVar3[2] != __objc_msgForward);
  }
locret_F00EFD00:
  return CONCAT44(param_2,uVar6);
}
/* GHIDRADEC_FUNCTION index=3177 start=0xf00efd08 */

/* WARNING: Removing unreachable block (ram,0xf00efd78) */
/* WARNING: Removing unreachable block (ram,0xf00efd2c) */

undefined8 _class_lookupMethod(uint param_1,uint param_2)

{
  uint *puVar1;
  uint *puVar2;
  uint uVar3;
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
  if (param_2 == 0) {
    _objc_msgSend(param_1,paError,aInvalidSelecto,0);
    puVar1 = *(uint **)(param_1 + 0x20);
  }
  else {
    puVar1 = *(uint **)(param_1 + 0x20);
  }
  uVar3 = param_2;
  do {
    puVar2 = (uint *)puVar1[(uVar3 & *puVar1) + 2];
    if (puVar2 == (uint *)0x0) {
      __class_lookupMethodAndLoadCache(param_1,param_2);
      goto locret_F00EFD84;
    }
    uVar3 = (uVar3 & *puVar1) + 1;
  } while (*puVar2 != param_2);
  param_1 = puVar2[2];
locret_F00EFD84:
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3178 start=0xf00efd8c */

int _class_lookupMethodInMethodList(int param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = *(int *)(param_1 + 4);
  piVar2 = (int *)(param_1 + 8);
  while( true ) {
    iVar1 = iVar1 + -1;
    if (iVar1 < 0) {
      return 0;
    }
    if (param_2 == *piVar2) break;
    piVar2 = piVar2 + 3;
  }
  return piVar2[2];
}
/* GHIDRADEC_FUNCTION index=3179 start=0xf00efdc8 */

/* WARNING: Removing unreachable block (ram,0xf00efdd8) */
/* WARNING: Removing unreachable block (ram,0xf00efdd0) */

undefined8 __cache_create(undefined4 *param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
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
  _NXDefaultMallocZone();
  puVar2 = puVar1;
  _NXDefaultMallocZone();
  (*(code *)puVar1[1])();
  iVar3 = 0;
  do {
    iVar4 = iVar3 + 1;
    puVar2[iVar3 + 2] = 0;
    iVar3 = iVar4;
  } while (iVar4 < 4);
  puVar2[1] = 0;
  *puVar2 = 3;
  param_1[8] = puVar2;
  uVar5 = param_1[4];
  param_1[4] = uVar5 & 0xffffffdf;
  if (dword_F012F0D4 != 0) {
    param_1[4] = uVar5 & 0xffffff9f;
  }
  return CONCAT44(param_2,puVar2);
}
/* GHIDRADEC_FUNCTION index=3180 start=0xf00f0238 */

undefined * __objc_getFreedObjectClass(void)

{
  return unk_F00FA360;
}
/* GHIDRADEC_FUNCTION index=3181 start=0xf00f0244 */

/* WARNING: Removing unreachable block (ram,0xf00f0310) */
/* WARNING: Removing unreachable block (ram,0xf00f034c) */
/* WARNING: Removing unreachable block (ram,0xf00f0288) */
/* WARNING: Removing unreachable block (ram,0xf00f0308) */
/* WARNING: Removing unreachable block (ram,0xf00f0334) */
/* WARNING: Removing unreachable block (ram,0xf00f0280) */

undefined8 __class_lookupMethodAndLoadCache(int *param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  undefined4 unaff_l0;
  int *piVar3;
  undefined4 unaff_l1;
  int *piVar4;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  code *pcVar5;
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
  if (param_1 != (int *)unk_F00FA360) {
    if (((param_1[4] & 2U) != 0) && ((param_1[4] & 4U) == 0)) {
      _objc_getClass(param_1[2]);
      sub_F00EFA04();
    }
    pcVar5 = __objc_msgForward;
    piVar2 = (int *)param_1[7];
    piVar4 = param_1;
    do {
      piVar3 = (int *)0x0;
      if (piVar2 != (int *)0x0) {
        iVar1 = piVar2[1];
        while( true ) {
          piVar3 = piVar2 + 2;
          while (iVar1 = iVar1 + -1, -1 < iVar1) {
            if (param_2 == *piVar3) goto loc_F00F02EC;
            piVar3 = piVar3 + 3;
          }
          piVar2 = (int *)*piVar2;
          if (piVar2 == (int *)0x0) break;
          iVar1 = piVar2[1];
        }
        piVar3 = (int *)0x0;
      }
loc_F00F02EC:
      if (piVar3 != (int *)0x0) {
        sub_F00F00E4(param_1,piVar3);
        pcVar5 = (code *)piVar3[2];
        goto locret_F00F0358;
      }
      piVar4 = (int *)piVar4[1];
      if (piVar4 == (int *)0x0) goto loc_f00f0308;
      piVar2 = (int *)piVar4[7];
    } while( true );
  }
  pcVar5 = sub_F00EF9D8;
locret_F00F0358:
  return CONCAT44(param_2,pcVar5);
loc_f00f0308:
  piVar4 = param_1;
  _NXDefaultMallocZone();
  piVar2 = piVar4;
  _NXDefaultMallocZone();
  (*(code *)piVar4[1])();
  *piVar2 = param_2;
  piVar2[1] = (int)&asc_F00FA528;
  piVar2[2] = (int)__objc_msgForward;
  sub_F00F00E4(param_1);
  goto locret_F00F0358;
}
/* GHIDRADEC_FUNCTION index=3182 start=0xf00f0620 */

/* WARNING: Removing unreachable block (ram,0xf00f0654) */
/* WARNING: Removing unreachable block (ram,0xf00f0628) */

undefined8 _method_getNumberOfArguments(int param_1,undefined4 param_2)

{
  char cVar1;
  char *pcVar2;
  undefined4 unaff_l0;
  int iVar3;
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
  iVar3 = 0;
  pcVar2 = *(char **)(param_1 + 4);
  sub_F00F0448();
  for (; (byte)(*pcVar2 - 0x30U) < 10; pcVar2 = pcVar2 + 1) {
  }
  cVar1 = *pcVar2;
  while (cVar1 != '\0') {
    sub_F00F0448();
    if (*pcVar2 == '-') goto loc_F00F0674;
    cVar1 = *pcVar2;
    while ((byte)(cVar1 - 0x30U) < 10) {
loc_F00F0674:
      pcVar2 = pcVar2 + 1;
      cVar1 = *pcVar2;
    }
    iVar3 = iVar3 + 1;
    cVar1 = *pcVar2;
  }
  return CONCAT44(param_2,iVar3);
}
/* GHIDRADEC_FUNCTION index=3183 start=0xf00f06a8 */

/* WARNING: Removing unreachable block (ram,0xf00f06b0) */

undefined8 _method_getSizeOfArguments(int param_1,undefined4 param_2)

{
  char cVar1;
  char *pcVar2;
  undefined4 unaff_l0;
  int iVar3;
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
  iVar3 = 0;
  pcVar2 = *(char **)(param_1 + 4);
  sub_F00F0448();
  cVar1 = *pcVar2;
  while ((byte)(cVar1 - 0x30U) < 10) {
    iVar3 = iVar3 * 10 + -0x30 + (int)cVar1;
    pcVar2 = pcVar2 + 1;
    cVar1 = *pcVar2;
  }
  return CONCAT44(param_2,iVar3);
}
/* GHIDRADEC_FUNCTION index=3184 start=0xf00f0708 */

/* WARNING: Removing unreachable block (ram,0xf00f0748) */
/* WARNING: Removing unreachable block (ram,0xf00f0824) */
/* WARNING: Removing unreachable block (ram,0xf00f0714) */

undefined8 _method_getArgumentInfo(int param_1,int param_2,undefined4 *param_3,int *param_4)

{
  char cVar1;
  char cVar2;
  char *pcVar3;
  undefined4 unaff_l0;
  int iVar4;
  undefined4 unaff_l1;
  int iVar5;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar6;
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
  iVar5 = 0;
  iVar4 = 0;
  pcVar3 = *(char **)(param_1 + 4);
  sub_F00F0448();
  for (; (byte)(*pcVar3 - 0x30U) < 10; pcVar3 = pcVar3 + 1) {
  }
  cVar1 = *pcVar3;
  while (cVar1 != '\0') {
    if (iVar5 == param_2) {
      cVar1 = *pcVar3;
      goto loc_F00F0810;
    }
    sub_F00F0448();
    if (iVar5 == 0) {
      cVar1 = *pcVar3;
      if (cVar1 == '-') {
        pcVar3 = pcVar3 + 1;
      }
      cVar2 = *pcVar3;
      while ((byte)(cVar2 - 0x30U) < 10) {
        iVar4 = iVar4 * 10 + -0x30 + (int)cVar2;
        pcVar3 = pcVar3 + 1;
        cVar2 = *pcVar3;
      }
      if (cVar1 == '-') {
        iVar4 = -iVar4;
      }
    }
    else {
      if (*pcVar3 == '-') goto loc_F00F07E0;
      cVar1 = *pcVar3;
      while ((byte)(cVar1 - 0x30U) < 10) {
loc_F00F07E0:
        pcVar3 = pcVar3 + 1;
        cVar1 = *pcVar3;
      }
    }
    iVar5 = iVar5 + 1;
    cVar1 = *pcVar3;
  }
  cVar1 = *pcVar3;
loc_F00F0810:
  if (cVar1 == '\0') {
    *param_3 = 0;
  }
  else {
    iVar6 = 0;
    *param_3 = pcVar3;
    sub_F00F0448();
    if (param_2 != 0) {
      cVar1 = *pcVar3;
      if (cVar1 == '-') {
        pcVar3 = pcVar3 + 1;
      }
      cVar2 = *pcVar3;
      while ((byte)(cVar2 - 0x30U) < 10) {
        iVar6 = iVar6 * 10 + -0x30 + (int)cVar2;
        pcVar3 = pcVar3 + 1;
        cVar2 = *pcVar3;
      }
      if (cVar1 == '-') {
        iVar6 = -iVar6;
      }
      *param_4 = iVar6 - iVar4;
      goto locret_F00F08B0;
    }
  }
  *param_4 = 0;
locret_F00F08B0:
  return CONCAT44(param_2,iVar5);
}
/* GHIDRADEC_FUNCTION index=3185 start=0xf00f08b8 */

/* WARNING: Removing unreachable block (ram,0xf00f08e8) */
/* WARNING: Removing unreachable block (ram,0xf00f08d8) */

undefined8 __objc_create_zone(undefined4 param_1,undefined4 param_2)

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
  if (dword_F012F0E0 == 0) {
    iVar1 = 0x2000;
    _NXCreateZone(0x2000,0x2000,1);
    dword_F012F0E0 = iVar1;
    _NXNameZone();
  }
  return CONCAT44(param_2,dword_F012F0E0);
}
/* GHIDRADEC_FUNCTION index=3186 start=0xf00f0900 */

/* WARNING: Removing unreachable block (ram,0xf00f0938) */

undefined8
___objc_error(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
             undefined4 param_5,undefined4 param_6)

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
  *(undefined4 *)((int)register0x00000038 + 0x4c) = param_3;
  *(undefined4 *)((int)register0x00000038 + 0x50) = param_4;
  *(undefined4 *)((int)register0x00000038 + 0x54) = param_5;
  *(undefined4 *)((int)register0x00000038 + 0x58) = param_6;
  (*(code *)__error)(param_1,param_2,(undefined *)((int)register0x00000038 + 0x4c));
  __objc_error(param_1,param_2,(undefined *)((int)register0x00000038 + 0x4c));
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3187 start=0xf00f0948 */

/* WARNING: Removing unreachable block (ram,0xf00f0970) */
/* WARNING: Removing unreachable block (ram,0xf00f0990) */
/* WARNING: Removing unreachable block (ram,0xf00f0968) */

undefined8
__NXLogError(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            ,undefined4 param_6)

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
  *(undefined4 *)((int)register0x00000038 + 0x48) = param_2;
  *(undefined4 *)((int)register0x00000038 + 0x4c) = param_3;
  *(undefined4 *)((int)register0x00000038 + 0x50) = param_4;
  *(undefined4 *)((int)register0x00000038 + 0x54) = param_5;
  *(undefined4 *)((int)register0x00000038 + 0x58) = param_6;
  _vlog(3,param_1,(undefined *)((int)register0x00000038 + 0x48));
  iVar1 = param_1;
  _strlen();
  if (*(char *)(iVar1 + param_1 + -1) != '\n') {
    _log(3,&asc_F00FAC48);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3188 start=0xf00f09a0 */

/* WARNING: Removing unreachable block (ram,0xf00f09d0) */
/* WARNING: Removing unreachable block (ram,0xf00f09b8) */
/* WARNING: Removing unreachable block (ram,0xf00f09c8) */
/* WARNING: Removing unreachable block (ram,0xf00f09f0) */
/* WARNING: Removing unreachable block (ram,0xf00f09a4) */

void __objc_error(undefined4 param_1,int param_2,undefined4 param_3)

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
  _object_getClassName(param_1);
  _log(3,aObjcErrorS,param_1);
  _vlog(3,param_2,param_3);
  iVar1 = param_2;
  _strlen();
  if (*(char *)(iVar1 + param_2 + -1) != '\n') {
    _log(3,&asc_F00FAC48);
  }
                    /* WARNING: Subroutine does not return */
  _abort();
}
/* GHIDRADEC_FUNCTION index=3189 start=0xf00f0a08 */

/* WARNING: Removing unreachable block (ram,0xf00f0a20) */
/* WARNING: Removing unreachable block (ram,0xf00f0a14) */

undefined8 __objc_fatal(undefined4 param_1,undefined4 param_2)

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
  _printf(aObjcFatalS,param_1);
  _panic(aObjectiveCFata);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3190 start=0xf00f0a30 */

/* WARNING: Removing unreachable block (ram,0xf00f0a58) */
/* WARNING: Removing unreachable block (ram,0xf00f0a78) */
/* WARNING: Removing unreachable block (ram,0xf00f0a50) */

undefined8
__objc_inform(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
             undefined4 param_5,undefined4 param_6)

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
  *(undefined4 *)((int)register0x00000038 + 0x48) = param_2;
  *(undefined4 *)((int)register0x00000038 + 0x4c) = param_3;
  *(undefined4 *)((int)register0x00000038 + 0x50) = param_4;
  *(undefined4 *)((int)register0x00000038 + 0x54) = param_5;
  *(undefined4 *)((int)register0x00000038 + 0x58) = param_6;
  _vlog(3,param_1,(undefined *)((int)register0x00000038 + 0x48));
  iVar1 = param_1;
  _strlen();
  if (*(char *)(iVar1 + param_1 + -1) != '\n') {
    _log(3,&asc_F00FAC48);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3191 start=0xf00f0ac8 */

void _NXPtrValueMapPrototype(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)IllegalInstructionTrap(0);
  (*pcVar1)();
}
/* GHIDRADEC_FUNCTION index=3192 start=0xf00f0ad8 */

void _NXStrValueMapPrototype(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)IllegalInstructionTrap(0);
  (*pcVar1)();
}
/* GHIDRADEC_FUNCTION index=3193 start=0xf00f0ae8 */

void _NXObjectMapPrototype(void)

{
  code *pcVar1;
  
                    /* WARNING: Does not return */
  pcVar1 = (code *)IllegalInstructionTrap(0);
  (*pcVar1)();
}
/* GHIDRADEC_FUNCTION index=3194 start=0xf00f0b4c */

undefined * _NXDefaultMallocZone(void)

{
  return _KernelZone;
}
/* GHIDRADEC_FUNCTION index=3195 start=0xf00f0b58 */

undefined * _NXZoneFromPtr(void)

{
  return _KernelZone;
}
/* GHIDRADEC_FUNCTION index=3196 start=0xf00f0b64 */

undefined * _NXCreateZone(void)

{
  return _KernelZone;
}
/* GHIDRADEC_FUNCTION index=3197 start=0xf00f0b70 */

void _NXNameZone(void)

{
  return;
}
/* GHIDRADEC_FUNCTION index=3198 start=0xf00f0b78 */

/* WARNING: Removing unreachable block (ram,0xf00f0b80) */

undefined8 _NXZoneCalloc(undefined4 param_1,undefined4 param_2,undefined4 param_3)

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
  uVar1 = param_2;
  _calloc(param_2,param_3);
  return CONCAT44(param_2,uVar1);
}
/* GHIDRADEC_FUNCTION index=3199 start=0xf00f0d3c */

/* WARNING: Removing unreachable block (ram,0xf00f1554) */
/* WARNING: Removing unreachable block (ram,0xf00f1428) */
/* WARNING: Removing unreachable block (ram,0xf00f13ac) */
/* WARNING: Removing unreachable block (ram,0xf00f12d4) */
/* WARNING: Removing unreachable block (ram,0xf00f11b8) */
/* WARNING: Removing unreachable block (ram,0xf00f1140) */
/* WARNING: Removing unreachable block (ram,0xf00f10b0) */
/* WARNING: Removing unreachable block (ram,0xf00f0f54) */
/* WARNING: Removing unreachable block (ram,0xf00f0fac) */
/* WARNING: Removing unreachable block (ram,0xf00f0eb4) */
/* WARNING: Removing unreachable block (ram,0xf00f0e5c) */
/* WARNING: Removing unreachable block (ram,0xf00f0e14) */
/* WARNING: Removing unreachable block (ram,0xf00f0dac) */
/* WARNING: Removing unreachable block (ram,0xf00f0e0c) */
/* WARNING: Removing unreachable block (ram,0xf00f0e30) */
/* WARNING: Removing unreachable block (ram,0xf00f0e9c) */
/* WARNING: Removing unreachable block (ram,0xf00f0f98) */
/* WARNING: Removing unreachable block (ram,0xf00f0ef4) */
/* WARNING: Removing unreachable block (ram,0xf00f0ffc) */
/* WARNING: Removing unreachable block (ram,0xf00f110c) */
/* WARNING: Removing unreachable block (ram,0xf00f11a8) */
/* WARNING: Removing unreachable block (ram,0xf00f127c) */
/* WARNING: Removing unreachable block (ram,0xf00f1314) */
/* WARNING: Removing unreachable block (ram,0xf00f140c) */
/* WARNING: Removing unreachable block (ram,0xf00f14b8) */
/* WARNING: Removing unreachable block (ram,0xf00f157c) */
/* WARNING: Removing unreachable block (ram,0xf00f0d58) */

undefined8 _objc_registerModule(int *param_1,code *param_2)

{
  bool bVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  uint uVar5;
  uint *puVar6;
  uint uVar7;
  undefined4 unaff_l0;
  int iVar8;
  undefined4 unaff_l1;
  uint uVar9;
  undefined4 unaff_l3;
  int *piVar10;
  undefined4 unaff_l4;
  int iVar11;
  int iVar12;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar13;
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
  bVar1 = false;
  piVar2 = param_1;
  _getsectdatafromheader(param_1,&aObjc,aModuleInfo,(undefined *)((int)register0x00000038 + -0xc));
  *(undefined4 *)((int)register0x00000038 + -0x10) = *(undefined4 *)((int)register0x00000038 + -0xc)
  ;
  if (piVar2 != (int *)0x0) {
    iVar3 = *(int *)((int)register0x00000038 + -0x10);
    piVar4 = piVar2;
    do {
      if (iVar3 == 0) break;
      iVar11 = 0;
      iVar3 = piVar4[3];
      if (*(sword *)(iVar3 + 8) == 0) {
        iVar3 = piVar4[1];
      }
      else {
        iVar12 = 0;
        do {
          iVar3 = *(int *)(iVar12 + iVar3 + 0xc);
          _objc_lookUpClass();
          if (iVar3 != 0) {
            bVar1 = true;
          }
          iVar11 = iVar11 + 1;
          iVar3 = piVar4[3];
          iVar12 = iVar11 * 4;
        } while (iVar11 < (int)(uint)*(word *)(iVar3 + 8));
        iVar3 = piVar4[1];
      }
      *(int *)((int)register0x00000038 + -0x10) = *(int *)((int)register0x00000038 + -0x10) - iVar3;
      piVar4 = (int *)((int)piVar4 + piVar4[1]);
      iVar3 = *(int *)((int)register0x00000038 + -0x10);
    } while (piVar4 != (int *)0x0);
  }
  if (bVar1) {
    uVar13 = 1;
  }
  else {
    __objc_addHeader(param_1,0);
    sub_F00F0CC0(param_1);
    piVar4 = param_1;
    _getsectdatafromheader
              (param_1,&aObjc,aMessageRefs,(undefined *)((int)register0x00000038 + -0x10));
    uVar5 = *(uint *)((int)register0x00000038 + -0x10);
    if (piVar4 != (int *)0x0) {
      uVar9 = 0;
      if (uVar5 >> 2 != 0) {
        iVar3 = 0;
        while( true ) {
          iVar11 = *(int *)((int)piVar4 + iVar3);
          _sel_registerName();
          if (*(int *)((int)piVar4 + iVar3) != iVar11) {
            *(int *)((int)piVar4 + iVar3) = iVar11;
          }
          uVar9 = uVar9 + 1;
          if (uVar5 >> 2 <= uVar9) break;
          iVar3 = uVar9 * 4;
        }
      }
    }
    piVar4 = param_1;
    _getsectdatafromheader(param_1,&aObjc,aProtocol,(undefined *)((int)register0x00000038 + -0x10));
    uVar5 = 0;
    if (piVar4 != (int *)0x0) {
      while( true ) {
        uVar9 = *(uint *)((int)register0x00000038 + -0x10);
        .udiv(uVar9,0x14);
        if (uVar9 <= uVar5) break;
        puVar6 = (uint *)piVar4[uVar5 * 5 + 3];
        if (puVar6 != (uint *)0x0) {
          for (uVar9 = 0; uVar9 < *puVar6; uVar9 = uVar9 + 1) {
            uVar7 = puVar6[uVar9 * 2 + 1];
            _sel_registerName();
            if (puVar6[uVar9 * 2 + 1] != uVar7) {
              puVar6[uVar9 * 2 + 1] = uVar7;
            }
          }
        }
        puVar6 = (uint *)piVar4[uVar5 * 5 + 4];
        if (puVar6 == (uint *)0x0) {
          uVar5 = uVar5 + 1;
        }
        else {
          for (uVar9 = 0; uVar9 < *puVar6; uVar9 = uVar9 + 1) {
            uVar7 = puVar6[uVar9 * 2 + 1];
            _sel_registerName();
            if (puVar6[uVar9 * 2 + 1] != uVar7) {
              puVar6[uVar9 * 2 + 1] = uVar7;
            }
          }
          uVar5 = uVar5 + 1;
        }
      }
      uVar13 = *(undefined4 *)((int)register0x00000038 + -0x10);
      .udiv(uVar13,0x14);
      _objc_msgSend(paProtocol_0,paFixupNumelemen,piVar4,uVar13);
    }
    *(undefined4 *)((int)register0x00000038 + -0x10) =
         *(undefined4 *)((int)register0x00000038 + -0xc);
    if (piVar2 != (int *)0x0) {
      iVar3 = *(int *)((int)register0x00000038 + -0x10);
      piVar4 = piVar2;
      do {
        if (iVar3 == 0) break;
        iVar11 = 0;
        iVar3 = piVar4[3];
        if (*(sword *)(iVar3 + 8) == 0) {
          iVar3 = *(int *)((int)register0x00000038 + -0x10);
        }
        else {
          iVar12 = 0;
          do {
            _objc_addClass(*(undefined4 *)(iVar12 + iVar3 + 0xc));
            iVar11 = iVar11 + 1;
            iVar3 = piVar4[3];
            iVar12 = iVar11 * 4;
          } while (iVar11 < (int)(uint)*(word *)(iVar3 + 8));
          iVar3 = *(int *)((int)register0x00000038 + -0x10);
        }
        *(int *)((int)register0x00000038 + -0x10) = iVar3 - piVar4[1];
        piVar4 = (int *)((int)piVar4 + piVar4[1]);
        iVar3 = *(int *)((int)register0x00000038 + -0x10);
      } while (piVar4 != (int *)0x0);
    }
    *(undefined4 *)((int)register0x00000038 + -0x10) =
         *(undefined4 *)((int)register0x00000038 + -0xc);
    if (piVar2 != (int *)0x0) {
      iVar3 = *(int *)((int)register0x00000038 + -0x10);
      piVar4 = piVar2;
      do {
        if (iVar3 == 0) break;
        iVar12 = 0;
        iVar3 = piVar4[3];
        iVar11 = *(int *)((int)register0x00000038 + -0x10);
        if (*(sword *)(iVar3 + 8) != 0) {
          iVar11 = 0;
          do {
            piVar10 = *(int **)(iVar11 + iVar3 + 0xc);
            iVar3 = piVar10[7];
            if (iVar3 == 0) {
              iVar3 = *piVar10;
            }
            else {
              for (uVar5 = 0; uVar5 < *(uint *)(iVar3 + 4); uVar5 = uVar5 + 1) {
                iVar8 = uVar5 * 0xc + 8;
                iVar11 = *(int *)(iVar3 + iVar8);
                _sel_registerName();
                if (*(int *)(iVar3 + iVar8) != iVar11) {
                  *(int *)(iVar3 + iVar8) = iVar11;
                }
              }
              iVar3 = *piVar10;
            }
            iVar3 = *(int *)(iVar3 + 0x1c);
            if (iVar3 != 0) {
              for (uVar5 = 0; uVar5 < *(uint *)(iVar3 + 4); uVar5 = uVar5 + 1) {
                iVar8 = uVar5 * 0xc + 8;
                iVar11 = *(int *)(iVar3 + iVar8);
                _sel_registerName();
                if (*(int *)(iVar3 + iVar8) != iVar11) {
                  *(int *)(iVar3 + iVar8) = iVar11;
                }
              }
            }
            __class_install_relationships(piVar10,*piVar4);
            if (*(int *)(*piVar10 + 0xc) == 3 || *(int *)(*piVar10 + 0xc) == 4) {
              if (piVar10[9] != 0) {
                piVar10[9] = piVar10[9] + -4;
                *(int *)(*piVar10 + 0x24) = *(int *)(*piVar10 + 0x24) + -4;
              }
              iVar3 = *piVar10;
            }
            else {
              iVar3 = *piVar10;
            }
            if ((*(int *)(iVar3 + 0xc) == 3) && (piVar10[9] != 0)) {
              __objc_inform(aUnableToInstal);
              __objc_inform(aClassSMustBeRe,piVar10[2]);
              piVar10[9] = 0;
              *(undefined4 *)(*piVar10 + 0x24) = 0;
            }
            iVar12 = iVar12 + 1;
            iVar3 = piVar4[3];
            iVar11 = iVar12 * 4;
          } while (iVar12 < (int)(uint)*(word *)(iVar3 + 8));
          iVar11 = *(int *)((int)register0x00000038 + -0x10);
        }
        *(int *)((int)register0x00000038 + -0x10) = iVar11 - piVar4[1];
        piVar4 = (int *)((int)piVar4 + piVar4[1]);
        iVar3 = *(int *)((int)register0x00000038 + -0x10);
      } while (piVar4 != (int *)0x0);
    }
    *(undefined4 *)((int)register0x00000038 + -0x10) =
         *(undefined4 *)((int)register0x00000038 + -0xc);
    if (piVar2 != (int *)0x0) {
      iVar3 = *(int *)((int)register0x00000038 + -0x10);
      piVar4 = piVar2;
      do {
        if (iVar3 == 0) break;
        iVar3 = piVar4[3];
        uVar5 = (uint)*(word *)(iVar3 + 8);
        iVar11 = *(int *)((int)register0x00000038 + -0x10);
        if (uVar5 < uVar5 + *(word *)(iVar3 + 10)) {
          do {
            iVar11 = *(int *)(uVar5 * 4 + iVar3 + 0xc);
            iVar3 = *(int *)(iVar11 + 8);
            if (iVar3 == 0) {
              iVar3 = *(int *)(iVar11 + 0xc);
            }
            else {
              for (uVar9 = 0; uVar9 < *(uint *)(iVar3 + 4); uVar9 = uVar9 + 1) {
                iVar8 = uVar9 * 0xc + 8;
                iVar12 = *(int *)(iVar3 + iVar8);
                _sel_registerName();
                if (*(int *)(iVar3 + iVar8) != iVar12) {
                  *(int *)(iVar3 + iVar8) = iVar12;
                }
              }
              iVar3 = *(int *)(iVar11 + 0xc);
            }
            if (iVar3 == 0) {
              iVar3 = piVar4[3];
            }
            else {
              for (uVar9 = 0; uVar9 < *(uint *)(iVar3 + 4); uVar9 = uVar9 + 1) {
                iVar12 = uVar9 * 0xc + 8;
                iVar11 = *(int *)(iVar3 + iVar12);
                _sel_registerName();
                if (*(int *)(iVar3 + iVar12) != iVar11) {
                  *(int *)(iVar3 + iVar12) = iVar11;
                }
              }
              iVar3 = piVar4[3];
            }
            __objc_add_category(*(undefined4 *)(uVar5 * 4 + iVar3 + 0xc),*piVar4);
            uVar5 = uVar5 + 1;
            iVar3 = piVar4[3];
          } while ((int)uVar5 < (int)((uint)*(word *)(iVar3 + 8) + (uint)*(word *)(iVar3 + 10)));
          iVar11 = *(int *)((int)register0x00000038 + -0x10);
        }
        *(int *)((int)register0x00000038 + -0x10) = iVar11 - piVar4[1];
        piVar4 = (int *)((int)piVar4 + piVar4[1]);
        iVar3 = *(int *)((int)register0x00000038 + -0x10);
      } while (piVar4 != (int *)0x0);
    }
    *(undefined4 *)((int)register0x00000038 + -0x10) =
         *(undefined4 *)((int)register0x00000038 + -0xc);
    if (piVar2 != (int *)0x0) {
      iVar3 = *(int *)((int)register0x00000038 + -0x10);
      piVar4 = piVar2;
      do {
        if (iVar3 == 0) break;
        iVar3 = *(int *)((int)register0x00000038 + -0x10);
        if (*piVar4 == 1) {
          uVar7 = *(uint *)piVar4[3];
          uVar5 = 0;
          uVar9 = ((uint *)piVar4[3])[1];
          if (uVar7 != 0) {
            iVar3 = 0;
            while( true ) {
              iVar11 = *(int *)(uVar9 + iVar3);
              _sel_registerName();
              if (*(int *)(uVar9 + iVar3) != iVar11) {
                *(int *)(uVar9 + iVar3) = iVar11;
              }
              uVar5 = uVar5 + 1;
              if (uVar7 <= uVar5) break;
              iVar3 = uVar5 * 4;
            }
          }
          iVar3 = *(int *)((int)register0x00000038 + -0x10);
        }
        *(int *)((int)register0x00000038 + -0x10) = iVar3 - piVar4[1];
        piVar4 = (int *)((int)piVar4 + piVar4[1]);
        iVar3 = *(int *)((int)register0x00000038 + -0x10);
      } while (piVar4 != (int *)0x0);
    }
    piVar4 = param_1;
    _getsectdatafromheader(param_1,&aObjc,aClsRefs,(undefined *)((int)register0x00000038 + -0x10));
    if (piVar4 != (int *)0x0) {
      for (uVar5 = 0; uVar5 < *(uint *)((int)register0x00000038 + -0x10) >> 2; uVar5 = uVar5 + 1) {
        iVar3 = piVar4[uVar5];
        _objc_getClass();
        piVar4[uVar5] = iVar3;
      }
    }
    *(undefined4 *)((int)register0x00000038 + -0x10) =
         *(undefined4 *)((int)register0x00000038 + -0xc);
    if (piVar2 != (int *)0x0) {
      iVar3 = *(int *)((int)register0x00000038 + -0x10);
      piVar4 = piVar2;
      do {
        if (iVar3 == 0) break;
        iVar12 = 0;
        iVar3 = piVar4[3];
        iVar11 = *(int *)((int)register0x00000038 + -0x10);
        if (*(sword *)(iVar3 + 8) != 0) {
          do {
            if (param_2 != (code *)0x0) {
              (*param_2)(*(undefined4 *)(iVar12 * 4 + iVar3 + 0xc),0);
            }
            sub_F00F0BBC(*(undefined4 *)(iVar12 * 4 + piVar4[3] + 0xc),param_1);
            iVar12 = iVar12 + 1;
            iVar3 = piVar4[3];
          } while (iVar12 < (int)(uint)*(word *)(iVar3 + 8));
          iVar11 = *(int *)((int)register0x00000038 + -0x10);
        }
        *(int *)((int)register0x00000038 + -0x10) = iVar11 - piVar4[1];
        piVar4 = (int *)((int)piVar4 + piVar4[1]);
        iVar3 = *(int *)((int)register0x00000038 + -0x10);
      } while (piVar4 != (int *)0x0);
    }
    *(undefined4 *)((int)register0x00000038 + -0x10) =
         *(undefined4 *)((int)register0x00000038 + -0xc);
    if (piVar2 != (int *)0x0) {
      iVar3 = *(int *)((int)register0x00000038 + -0x10);
      do {
        if (iVar3 == 0) {
          uVar13 = 0;
          goto locret_F00F15C8;
        }
        iVar3 = piVar2[3];
        uVar5 = (uint)*(word *)(iVar3 + 8);
        iVar11 = *(int *)((int)register0x00000038 + -0x10);
        if (uVar5 < uVar5 + *(word *)(iVar3 + 10)) {
          do {
            if (param_2 == (code *)0x0) {
              iVar3 = piVar2[3];
            }
            else {
              _objc_getClass(*(undefined4 *)(*(int *)(uVar5 * 4 + iVar3 + 0xc) + 4));
              (*param_2)();
              iVar3 = piVar2[3];
            }
            sub_F00F0BFC(*(undefined4 *)(uVar5 * 4 + iVar3 + 0xc),param_1);
            uVar5 = uVar5 + 1;
            iVar3 = piVar2[3];
          } while ((int)uVar5 < (int)((uint)*(word *)(iVar3 + 8) + (uint)*(word *)(iVar3 + 10)));
          iVar11 = *(int *)((int)register0x00000038 + -0x10);
        }
        *(int *)((int)register0x00000038 + -0x10) = iVar11 - piVar2[1];
        piVar2 = (int *)((int)piVar2 + piVar2[1]);
        iVar3 = *(int *)((int)register0x00000038 + -0x10);
      } while (piVar2 != (int *)0x0);
    }
    uVar13 = 0;
  }
locret_F00F15C8:
  return CONCAT44(param_2,uVar13);
}

