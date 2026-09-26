/* GHIDRADEC_FUNCTION index=150 start=0x4006ebc */

void _leavepgrp(int param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  
  iVar1 = _get_posix_proc((int)*(sword *)(param_1 + 0x30));
  piVar3 = (int *)(*(int *)(iVar1 + 0xe) + 4);
  while( true ) {
    if (*piVar3 == 0) {
                    /* WARNING: Subroutine does not return */
      _panic(aLeavepgrpCanTF);
    }
    if (param_1 == *piVar3) break;
    iVar2 = _get_posix_proc((int)*(sword *)(*piVar3 + 0x30));
    piVar3 = (int *)(iVar2 + 10);
  }
  *piVar3 = *(int *)(iVar1 + 10);
  if (*(int *)(*(int *)(iVar1 + 0xe) + 4) == 0) {
    _pgdelete(*(int *)(iVar1 + 0xe));
  }
  *(undefined4 *)(iVar1 + 0xe) = 0;
  *(undefined2 *)(param_1 + 0x2e) = 0;
  return;
}
/* GHIDRADEC_FUNCTION index=151 start=0x4006f34 */

void _pgdelete(int *param_1)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  
  piVar1 = &_pgrphash + (param_1[3] & 0x3f);
  if ((*(int *)(param_1[2] + 8) != 0) &&
     (piVar2 = (int *)_ttynty(*(int *)(param_1[2] + 8)), param_1 == (int *)piVar2[3])) {
    piVar2[3] = 0;
    *(undefined2 *)(*piVar2 + 0x42) = 0;
  }
  do {
    piVar2 = piVar1;
    if (*piVar2 == 0) {
                    /* WARNING: Subroutine does not return */
      _panic(aPgdeleteCanTFi);
    }
    piVar1 = (int *)*piVar2;
  } while (param_1 != (int *)*piVar2);
  *piVar2 = *param_1;
  iVar3 = *(int *)param_1[2];
  *(int *)param_1[2] = iVar3 + -1;
  if (iVar3 == 1) {
    if (*(int *)(param_1[2] + 8) != 0) {
      iVar3 = _ttynty(*(int *)(param_1[2] + 8));
      *(undefined4 *)(iVar3 + 8) = 0;
    }
    _kfree(param_1[2],0xe);
  }
  _kfree(param_1,0x14);
  return;
}
/* GHIDRADEC_FUNCTION index=152 start=0x4006fe8 */

void _fixjobc(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar1 = *(int *)(param_2 + 8);
  iVar3 = _get_posix_proc((int)*(sword *)(*(int *)(param_1 + 0x42) + 0x30));
  if ((param_2 != *(int *)(iVar3 + 0xe)) && (iVar1 == *(int *)(*(int *)(iVar3 + 0xe) + 8))) {
    if (param_3 == 0) {
      iVar3 = *(int *)(param_2 + 0x10);
      *(int *)(param_2 + 0x10) = iVar3 + -1;
      if (iVar3 == 1) {
        sub_40070AE(param_2);
      }
    }
    else {
      *(int *)(param_2 + 0x10) = *(int *)(param_2 + 0x10) + 1;
    }
  }
  for (iVar3 = *(int *)(param_1 + 0x46); iVar3 != 0; iVar3 = *(int *)(iVar3 + 0x4a)) {
    iVar4 = _get_posix_proc((int)*(sword *)(iVar3 + 0x30));
    iVar4 = *(int *)(iVar4 + 0xe);
    if (((param_2 != iVar4) && (iVar1 == *(int *)(iVar4 + 8))) &&
       (*(char *)(iVar3 + 0x13) != '\x05')) {
      if (param_3 == 0) {
        iVar2 = *(int *)(iVar4 + 0x10);
        *(int *)(iVar4 + 0x10) = iVar2 + -1;
        if (iVar2 == 1) {
          sub_40070AE(iVar4);
        }
      }
      else {
        *(int *)(iVar4 + 0x10) = *(int *)(iVar4 + 0x10) + 1;
      }
    }
  }
  return;
}
/* GHIDRADEC_FUNCTION index=153 start=0x4007128 */

uint * _get_posix_proc(uint param_1)

{
  uint *puVar1;
  undefined auStack_54 [80];
  
  puVar1 = *(uint **)(_posix_proc_hash + (param_1 & 0x3f) * 4);
  while( true ) {
    if (puVar1 == (uint *)0x0) {
      _sprintf(auStack_54,aGetPosixProcNo,param_1);
                    /* WARNING: Subroutine does not return */
      _panic(auStack_54);
    }
    if (param_1 == *puVar1) break;
    puVar1 = *(uint **)((int)puVar1 + 0x1a);
  }
  return puVar1;
}
/* GHIDRADEC_FUNCTION index=154 start=0x4007178 */

undefined4 * _alloc_posix_proc(void)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)_kalloc(0x1e);
  _bzero(puVar1,0x1e);
  *puVar1 = 0;
  return puVar1;
}
/* GHIDRADEC_FUNCTION index=155 start=0x40071a2 */

void _free_posix_proc(undefined4 param_1)

{
  _kfree(param_1,0x1e);
  return;
}
/* GHIDRADEC_FUNCTION index=156 start=0x40071b8 */

undefined4 _insert_posix_proc(uint *param_1,uint param_2)

{
  uint *puVar1;
  
  puVar1 = *(uint **)(_posix_proc_hash + (param_2 & 0x3f) * 4);
  while( true ) {
    if (puVar1 == (uint *)0x0) {
      *param_1 = param_2;
      *(undefined4 *)((int)param_1 + 0x1a) =
           *(undefined4 *)(_posix_proc_hash + (param_2 & 0x3f) * 4);
      *(uint **)(_posix_proc_hash + (param_2 & 0x3f) * 4) = param_1;
      return 1;
    }
    if (param_2 == *puVar1) break;
    puVar1 = *(uint **)((int)puVar1 + 0x1a);
  }
  return 0;
}
/* GHIDRADEC_FUNCTION index=157 start=0x4007202 */

uint * _new_posix_proc(uint param_1)

{
  uint *puVar1;
  
  puVar1 = *(uint **)(_posix_proc_hash + (param_1 & 0x3f) * 4);
  while( true ) {
    if (puVar1 == (uint *)0x0) {
      puVar1 = (uint *)_kalloc(0x1e);
      *puVar1 = param_1;
      *(undefined4 *)((int)puVar1 + 0x1a) = *(undefined4 *)(_posix_proc_hash + (param_1 & 0x3f) * 4)
      ;
      *(uint **)(_posix_proc_hash + (param_1 & 0x3f) * 4) = puVar1;
      return puVar1;
    }
    if (param_1 == *puVar1) break;
    puVar1 = *(uint **)((int)puVar1 + 0x1a);
  }
  return (uint *)0x0;
}
/* GHIDRADEC_FUNCTION index=158 start=0x400725a */

void _delete_posix_proc(int param_1)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  undefined auStack_54 [80];
  
  piVar1 = (int *)(_posix_proc_hash + (*(word *)(param_1 + 0x30) & 0x3f) * 4);
  iVar2 = *piVar1;
  while( true ) {
    if (iVar2 == 0) {
      _sprintf(auStack_54,aDeletePosixPro,(int)*(sword *)(param_1 + 0x30));
                    /* WARNING: Subroutine does not return */
      _panic(auStack_54);
    }
    piVar3 = (int *)*piVar1;
    if ((int)*(sword *)(param_1 + 0x30) == *piVar3) break;
    piVar1 = (int *)((int)piVar3 + 0x1a);
    iVar2 = *piVar1;
  }
  *piVar1 = *(int *)((int)piVar3 + 0x1a);
  _kfree(piVar3,0x1e);
  return;
}
/* GHIDRADEC_FUNCTION index=159 start=0x40072cc */

undefined4 _proc_from_thread(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = **(undefined4 **)(*(int *)(param_1 + 0xc) + 0x30);
  }
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=160 start=0x40072ea */

undefined4 _utask_from_thread(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = *(undefined4 *)(*(int *)(param_1 + 0xc) + 0x30);
  }
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=161 start=0x4007306 */

undefined4 _uthread_from_thread(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = *(undefined4 *)(param_1 + 0x80);
  }
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=162 start=0x400731e */

undefined4 _setprivexec(void)

{
  int *piVar1;
  
  piVar1 = *(int **)(dword_40B57D4 + 0x24);
  *(int *)(*(int *)(_active_threads + 0x80) + 0x5c) = *(int *)(*_active_u + 0x16) >> 0x1f;
  *(byte *)(*_active_u + 0x16) = *(byte *)(*_active_u + 0x16) & 0x7f | (*piVar1 != 0) << 7;
  return 0;
}
/* GHIDRADEC_FUNCTION index=163 start=0x4007370 */

void _getpid(void)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(_active_threads + 0x80);
  iVar1 = *_active_u;
  *(int *)(iVar2 + 0x5c) = (int)*(sword *)(iVar1 + 0x30);
  *(int *)(iVar2 + 0x60) = (int)*(sword *)(iVar1 + 0x32);
  return;
}
/* GHIDRADEC_FUNCTION index=164 start=0x40073a0 */

void _getpgrp(void)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = *(int **)(dword_40B57D4 + 0x24);
  if (*piVar1 == 0) {
    *piVar1 = (int)*(sword *)(*_active_u + 0x30);
  }
  iVar2 = _pfind(*piVar1);
  if (iVar2 == 0) {
    *(undefined *)(dword_40B57D4 + 100) = 3;
  }
  else {
    *(int *)(dword_40B57D4 + 0x5c) = (int)*(sword *)(iVar2 + 0x2e);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=165 start=0x40073ee */

void _getuid(void)

{
  *(int *)(dword_40B57D4 + 0x5c) = (int)*(sword *)(*(int *)(_active_u + 0x1a) + 6);
  *(int *)(dword_40B57D4 + 0x60) = (int)*(sword *)(*(int *)(_active_u + 0x1a) + 2);
  return;
}
/* GHIDRADEC_FUNCTION index=166 start=0x4007426 */

void _getgid(void)

{
  *(int *)(dword_40B57D4 + 0x5c) = (int)*(sword *)(*(int *)(_active_u + 0x1a) + 8);
  *(int *)(dword_40B57D4 + 0x60) = (int)*(sword *)(*(int *)(_active_u + 0x1a) + 4);
  return;
}
/* GHIDRADEC_FUNCTION index=167 start=0x400745e */

void _getposix(void)

{
  *(uint *)(dword_40B57D4 + 0x5c) = (*(uint *)(*_active_u + 0x16) & 0x7fffffff) >> 0x1e;
  return;
}
/* GHIDRADEC_FUNCTION index=168 start=0x400747e */

void _setposix(void)

{
  uint uVar1;
  
  uVar1 = **(uint **)(dword_40B57D4 + 0x24);
  if (uVar1 < 2) {
    *(int *)(dword_40B57D4 + 0x5c) = (*(int *)(*_active_u + 0x16) << 1) >> 0x1f;
    *(uint *)(*_active_u + 0x16) = *(uint *)(*_active_u + 0x16) & 0xbfffffff | (uVar1 & 1) << 0x1e;
  }
  else {
    *(undefined4 *)(dword_40B57D4 + 0x5c) = 0xffffffff;
    *(undefined *)(dword_40B57D4 + 100) = 0x16;
  }
  return;
}
/* GHIDRADEC_FUNCTION index=169 start=0x40074d8 */

void _getgroups(void)

{
  uint *puVar1;
  undefined uVar2;
  int *piVar3;
  uint uVar4;
  sword *psVar5;
  int iVar6;
  int aiStack_44 [16];
  
  puVar1 = *(uint **)(dword_40B57D4 + 0x24);
  for (uVar4 = *(int *)((int)_active_u + 0x1a) + 0x2a;
      (*(int *)((int)_active_u + 0x1a) + 10U < uVar4 && (*(sword *)(uVar4 - 2) == -1));
      uVar4 = uVar4 - 2) {
  }
  uVar4 = (int)((uVar4 - 10) - *(int *)((int)_active_u + 0x1a)) >> 1;
  if (*puVar1 < uVar4) {
    *(undefined *)(dword_40B57D4 + 100) = 0x16;
  }
  else {
    *puVar1 = uVar4;
    if ((*(byte *)(*_active_u + 0x16) & 0x40) == 0) {
      psVar5 = (sword *)(*(int *)((int)_active_u + 0x1a) + 10);
      for (piVar3 = aiStack_44; piVar3 < aiStack_44 + uVar4; piVar3 = piVar3 + 1) {
        *piVar3 = (int)*psVar5;
        uVar4 = *puVar1;
        psVar5 = psVar5 + 1;
      }
      iVar6 = *puVar1 << 2;
      uVar4 = puVar1[1];
      piVar3 = aiStack_44;
    }
    else {
      iVar6 = uVar4 * 2;
      uVar4 = puVar1[1];
      piVar3 = (int *)(*(int *)((int)_active_u + 0x1a) + 10);
    }
    uVar2 = _copyoutmsg(piVar3,uVar4,iVar6);
    *(undefined *)(dword_40B57D4 + 100) = uVar2;
    if (*(char *)(dword_40B57D4 + 100) == '\0') {
      *(uint *)(dword_40B57D4 + 0x5c) = *puVar1;
    }
  }
  return;
}
/* GHIDRADEC_FUNCTION index=170 start=0x40075b4 */

void _setpgrp(void)

{
  int *piVar1;
  sword sVar2;
  int iVar3;
  int iVar4;
  
  piVar1 = *(int **)(dword_40B57D4 + 0x24);
  if (*piVar1 == 0) {
    *piVar1 = (int)*(sword *)(*_active_u + 0x30);
  }
  iVar3 = _pfind(*piVar1);
  if (iVar3 == 0) {
    *(undefined *)(dword_40B57D4 + 100) = 3;
  }
  else {
    sVar2 = *(sword *)(*(int *)((int)_active_u + 0x1a) + 2);
    if (((sVar2 != *(sword *)(iVar3 + 0x2c)) && (sVar2 != 0)) &&
       (iVar4 = _inferior(iVar3), iVar4 == 0)) {
      *(undefined *)(dword_40B57D4 + 100) = 1;
      return;
    }
    _enterpgrp(iVar3,piVar1[1],0);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=171 start=0x4007644 */

void _setreuid(void)

{
  int *piVar1;
  sword sVar4;
  int iVar2;
  sword sVar5;
  undefined4 uVar3;
  
  piVar1 = *(int **)(dword_40B57D4 + 0x24);
  iVar2 = *piVar1;
  if (iVar2 == -1) {
    sVar4 = *(sword *)(*(int *)((int)_active_u + 0x1a) + 6);
  }
  else {
    sVar4 = (sword)iVar2;
  }
  if (((sVar4 != *(sword *)(*(int *)((int)_active_u + 0x1a) + 6)) &&
      (sVar4 != *(sword *)(*(int *)((int)_active_u + 0x1a) + 2))) && (iVar2 = _suser(), iVar2 == 0))
  {
    return;
  }
  iVar2 = piVar1[1];
  if (iVar2 == -1) {
    sVar5 = *(sword *)(*(int *)((int)_active_u + 0x1a) + 2);
  }
  else {
    sVar5 = (sword)iVar2;
  }
  if (((sVar5 != *(sword *)(*(int *)((int)_active_u + 0x1a) + 6)) &&
      (sVar5 != *(sword *)(*(int *)((int)_active_u + 0x1a) + 2))) && (iVar2 = _suser(), iVar2 == 0))
  {
    return;
  }
  _lock_write((int)_active_u + 0x1e);
  uVar3 = _crcopy(*(undefined4 *)((int)_active_u + 0x1a));
  *(undefined4 *)((int)_active_u + 0x1a) = uVar3;
  *(sword *)(*_active_u + 0x2c) = sVar5;
  *(sword *)(*(int *)((int)_active_u + 0x1a) + 6) = sVar4;
  *(sword *)(*(int *)((int)_active_u + 0x1a) + 2) = sVar5;
  _lock_done((int)_active_u + 0x1e);
  return;
}
/* GHIDRADEC_FUNCTION index=172 start=0x4007738 */

void __setuid(void)

{
  sword sVar1;
  sword sVar2;
  sword sVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  sword sVar7;
  sword sVar8;
  
  sVar1 = *(sword *)(*(int *)((int)_active_u + 0x1a) + 6);
  sVar2 = *(sword *)(*(int *)(dword_40B57D4 + 0x24) + 2);
  iVar4 = _get_posix_proc((int)*(sword *)(*_active_u + 0x30));
  if (sVar2 < 0) {
    *(undefined *)(dword_40B57D4 + 100) = 0x16;
  }
  else {
    sVar3 = *(sword *)(iVar4 + 6);
    iVar5 = _suser();
    sVar8 = sVar2;
    sVar7 = sVar2;
    if (((iVar5 == 0) && (sVar8 = sVar1, sVar7 = sVar3, sVar1 != sVar2)) && (sVar3 != sVar2)) {
      *(undefined *)(dword_40B57D4 + 100) = 1;
    }
    else {
      *(undefined *)(dword_40B57D4 + 100) = 0;
      _lock_write((int)_active_u + 0x1e);
      uVar6 = _crcopy(*(undefined4 *)((int)_active_u + 0x1a));
      *(undefined4 *)((int)_active_u + 0x1a) = uVar6;
      iVar5 = *(int *)((int)_active_u + 0x1a);
      *(sword *)(iVar4 + 4) = sVar8;
      *(sword *)(iVar5 + 6) = sVar8;
      iVar5 = *_active_u;
      *(sword *)(*(int *)((int)_active_u + 0x1a) + 2) = sVar2;
      *(sword *)(iVar5 + 0x2c) = sVar2;
      _lock_done((int)_active_u + 0x1e);
      *(sword *)(iVar4 + 6) = sVar7;
    }
  }
  return;
}
/* GHIDRADEC_FUNCTION index=173 start=0x4007820 */

void __setgid(void)

{
  sword sVar1;
  sword sVar2;
  sword sVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  sword sVar7;
  sword sVar8;
  
  sVar1 = *(sword *)(*(int *)((int)_active_u + 0x1a) + 8);
  sVar2 = *(sword *)(*(int *)(dword_40B57D4 + 0x24) + 2);
  iVar4 = _get_posix_proc((int)*(sword *)(*_active_u + 0x30));
  if (sVar2 < 0) {
    *(undefined *)(dword_40B57D4 + 100) = 0x16;
  }
  else {
    sVar3 = *(sword *)(iVar4 + 8);
    iVar5 = _suser();
    sVar8 = sVar2;
    sVar7 = sVar2;
    if (((iVar5 == 0) && (sVar8 = sVar1, sVar7 = sVar3, sVar1 != sVar2)) && (sVar3 != sVar2)) {
      *(undefined *)(dword_40B57D4 + 100) = 1;
    }
    else {
      *(undefined *)(dword_40B57D4 + 100) = 0;
      _lock_write((int)_active_u + 0x1e);
      uVar6 = _crcopy(*(undefined4 *)((int)_active_u + 0x1a));
      *(undefined4 *)((int)_active_u + 0x1a) = uVar6;
      *(sword *)(*(int *)((int)_active_u + 0x1a) + 8) = sVar8;
      *(sword *)(*(int *)((int)_active_u + 0x1a) + 4) = sVar2;
      _lock_done((int)_active_u + 0x1e);
      *(sword *)(iVar4 + 8) = sVar7;
    }
  }
  return;
}
/* GHIDRADEC_FUNCTION index=174 start=0x40078fe */

void _setregid(void)

{
  int *piVar1;
  sword sVar2;
  sword sVar5;
  int iVar3;
  sword sVar6;
  undefined4 uVar4;
  
  piVar1 = *(int **)(dword_40B57D4 + 0x24);
  iVar3 = *piVar1;
  if (iVar3 == -1) {
    sVar5 = *(sword *)(*(int *)(_active_u + 0x1a) + 8);
  }
  else {
    sVar5 = (sword)iVar3;
  }
  if (((sVar5 != *(sword *)(*(int *)(_active_u + 0x1a) + 8)) &&
      (sVar5 != *(sword *)(*(int *)(_active_u + 0x1a) + 4))) && (iVar3 = _suser(), iVar3 == 0)) {
    return;
  }
  iVar3 = piVar1[1];
  if (iVar3 == -1) {
    sVar6 = *(sword *)(*(int *)(_active_u + 0x1a) + 4);
  }
  else {
    sVar6 = (sword)iVar3;
  }
  if (((sVar6 != *(sword *)(*(int *)(_active_u + 0x1a) + 8)) &&
      (sVar6 != *(sword *)(*(int *)(_active_u + 0x1a) + 4))) && (iVar3 = _suser(), iVar3 == 0)) {
    return;
  }
  _lock_write(_active_u + 0x1e);
  uVar4 = _crcopy(*(undefined4 *)(_active_u + 0x1a));
  *(undefined4 *)(_active_u + 0x1a) = uVar4;
  sVar2 = *(sword *)(*(int *)(_active_u + 0x1a) + 8);
  if (sVar5 != sVar2) {
    _leavegroup((int)sVar2);
    _entergroup((int)sVar5);
    *(sword *)(*(int *)(_active_u + 0x1a) + 8) = sVar5;
  }
  *(sword *)(*(int *)(_active_u + 0x1a) + 4) = sVar6;
  _lock_done(_active_u + 0x1e);
  return;
}
/* GHIDRADEC_FUNCTION index=175 start=0x4007a10 */

void _setgroups(void)

{
  uint uVar1;
  uint *puVar2;
  undefined4 uVar3;
  int iVar4;
  undefined uVar5;
  undefined4 *puVar6;
  undefined2 *puVar7;
  undefined4 auStack_44 [16];
  undefined2 *puVar8;
  
  puVar2 = *(uint **)(dword_40B57D4 + 0x24);
  iVar4 = _suser();
  if (iVar4 != 0) {
    if (*puVar2 < 0x11) {
      iVar4 = _crdup(*(undefined4 *)(_active_u + 0x1a));
      uVar5 = _copyinmsg(puVar2[1],auStack_44,*puVar2 << 2);
      *(undefined *)(dword_40B57D4 + 100) = uVar5;
      if (*(char *)(dword_40B57D4 + 100) == '\0') {
        uVar1 = *puVar2;
        puVar7 = (undefined2 *)(iVar4 + 10);
        for (puVar6 = auStack_44; puVar6 < auStack_44 + uVar1; puVar6 = puVar6 + 1) {
          *puVar7 = (sword)*puVar6;
          uVar1 = *puVar2;
          puVar7 = puVar7 + 1;
        }
        uVar3 = *(undefined4 *)(_active_u + 0x1a);
        *(int *)(_active_u + 0x1a) = iVar4;
        _crfree(uVar3);
        puVar7 = (undefined2 *)(*(int *)(_active_u + 0x1a) + 10 + *puVar2 * 2);
        if (puVar7 < (undefined2 *)(*(int *)(_active_u + 0x1a) + 0x2a)) {
          do {
            puVar8 = puVar7 + 1;
            *puVar7 = 0xffff;
            puVar7 = puVar8;
          } while (puVar8 < (undefined2 *)(*(int *)(_active_u + 0x1a) + 0x2a));
        }
      }
      else {
        _crfree(iVar4);
      }
    }
    else {
      *(undefined *)(dword_40B57D4 + 100) = 0x16;
    }
  }
  return;
}
/* GHIDRADEC_FUNCTION index=176 start=0x4007afa */

void _leavegroup(sword param_1)

{
  sword *psVar1;
  
  psVar1 = (sword *)(*(int *)(_active_u + 0x1a) + 10);
  while( true ) {
    if ((sword *)(*(int *)(_active_u + 0x1a) + 0x2a) <= psVar1) {
      return;
    }
    if (param_1 == *psVar1) break;
    psVar1 = psVar1 + 1;
  }
  for (; psVar1 < (sword *)(*(int *)(_active_u + 0x1a) + 0x28); psVar1 = psVar1 + 1) {
    *psVar1 = psVar1[1];
  }
  *psVar1 = -1;
  return;
}
/* GHIDRADEC_FUNCTION index=177 start=0x4007b44 */

undefined4 _entergroup(sword param_1)

{
  sword *psVar1;
  
  psVar1 = (sword *)(*(int *)(_active_u + 0x1a) + 10);
  if (psVar1 < (sword *)(*(int *)(_active_u + 0x1a) + 0x2a)) {
    do {
      if (param_1 == *psVar1) {
        return 0;
      }
      if (*psVar1 == -1) {
        *psVar1 = param_1;
        return 0;
      }
      psVar1 = psVar1 + 1;
    } while (psVar1 < (sword *)(*(int *)(_active_u + 0x1a) + 0x2a));
  }
  return 0xffffffff;
}
/* GHIDRADEC_FUNCTION index=178 start=0x4007b90 */

undefined4 _groupmember(sword param_1)

{
  int iVar1;
  undefined4 uVar2;
  sword *psVar3;
  
  iVar1 = *(int *)(_active_u + 0x1a);
  if (param_1 == *(sword *)(iVar1 + 4)) {
loc_4007BA8:
    uVar2 = 1;
  }
  else {
    for (psVar3 = (sword *)(iVar1 + 10); (psVar3 < (sword *)(iVar1 + 0x2a) && (*psVar3 != -1));
        psVar3 = psVar3 + 1) {
      if (param_1 == *psVar3) goto loc_4007BA8;
    }
    uVar2 = 0;
  }
  return uVar2;
}
/* GHIDRADEC_FUNCTION index=179 start=0x4007bd0 */

undefined4 _suser(void)

{
  undefined4 uVar1;
  
  if (**(int **)(*(int *)(_active_threads + 0xc) + 0x30) == 0) {
    uVar1 = 0;
  }
  else if (*(sword *)(*(int *)(_active_u + 0x1a) + 2) == 0) {
    *(word *)(_active_u + 0x23a) = *(word *)(_active_u + 0x23a) | 2;
    uVar1 = 1;
  }
  else {
    *(undefined *)(dword_40B57D4 + 100) = 1;
    uVar1 = 0;
  }
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=180 start=0x4007c16 */

sword * _crget(void)

{
  sword *psVar1;
  
  psVar1 = (sword *)_kalloc(0x2a);
  _bzero(psVar1,0x2a);
  *psVar1 = *psVar1 + 1;
  _cractive = _cractive + 1;
  return psVar1;
}
/* GHIDRADEC_FUNCTION index=181 start=0x4007c46 */

byte _crfree(sword *param_1)

{
  sword sVar1;
  byte bVar2;
  bool bVar3;
  bool bVar4;
  
  sVar1 = *param_1;
  *param_1 = sVar1 + -1;
  if (sVar1 == 1) {
    _kfree(param_1,0x2a);
    bVar4 = _cractive == 0;
    bVar3 = SBORROW4(_cractive,1);
    _cractive = _cractive + -1;
    bVar2 = bVar4 << 4 | (_cractive < 0) << 3 | (_cractive == 0) << 2 | bVar3 << 1 | bVar4;
  }
  else {
    bVar2 = (sVar1 == 0) << 4 | ((sword)(sVar1 + -1) < 0) << 3 | SBORROW2(sVar1,1) << 1 | sVar1 == 0
    ;
  }
  return bVar2;
}
/* GHIDRADEC_FUNCTION index=182 start=0x4007c8c */

undefined4 * _crcopy(undefined4 *param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)_crget();
  *puVar1 = *param_1;
  puVar1[1] = param_1[1];
  puVar1[2] = param_1[2];
  puVar1[3] = param_1[3];
  puVar1[4] = param_1[4];
  puVar1[5] = param_1[5];
  puVar1[6] = param_1[6];
  puVar1[7] = param_1[7];
  puVar1[8] = param_1[8];
  puVar1[9] = param_1[9];
  *(undefined2 *)(puVar1 + 10) = *(undefined2 *)(param_1 + 10);
  _crfree(param_1);
  *(undefined2 *)puVar1 = 1;
  return puVar1;
}
/* GHIDRADEC_FUNCTION index=183 start=0x4007cd4 */

void _crdup(undefined4 *param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)_crget();
  *puVar1 = *param_1;
  puVar1[1] = param_1[1];
  puVar1[2] = param_1[2];
  puVar1[3] = param_1[3];
  puVar1[4] = param_1[4];
  puVar1[5] = param_1[5];
  puVar1[6] = param_1[6];
  puVar1[7] = param_1[7];
  puVar1[8] = param_1[8];
  puVar1[9] = param_1[9];
  *(undefined2 *)(puVar1 + 10) = *(undefined2 *)(param_1 + 10);
  *(undefined2 *)puVar1 = 1;
  return;
}
/* GHIDRADEC_FUNCTION index=184 start=0x4007d0a */

void _setsid(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *_active_u;
  iVar2 = _get_posix_proc((int)*(sword *)(iVar1 + 0x30));
  if (((int)*(sword *)(iVar1 + 0x30) != *(int *)(*(int *)(iVar2 + 0xe) + 0xc)) &&
     (iVar2 = _pgfind((int)*(sword *)(iVar1 + 0x30)), iVar2 == 0)) {
    _enterpgrp(iVar1,(int)*(sword *)(iVar1 + 0x30),1);
    *(int *)(dword_40B57D4 + 0x5c) = (int)*(sword *)(iVar1 + 0x30);
    return;
  }
  *(undefined *)(dword_40B57D4 + 100) = 1;
  return;
}
/* GHIDRADEC_FUNCTION index=185 start=0x4007d80 */

void _setpgid(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  piVar1 = *(int **)(dword_40B57D4 + 0x24);
  iVar3 = *_active_u;
  if (piVar1[1] < 0) {
    *(undefined *)(dword_40B57D4 + 100) = 0x16;
    return;
  }
  iVar2 = _get_posix_proc((int)*(sword *)(iVar3 + 0x30));
  iVar4 = *piVar1;
  iVar5 = iVar2;
  if ((iVar4 != 0) && (*(sword *)(iVar3 + 0x30) != iVar4)) {
    iVar3 = _pfind(iVar4);
    if ((iVar3 == 0) || (iVar4 = _inferior(iVar3), iVar4 == 0)) {
      *(undefined *)(dword_40B57D4 + 100) = 3;
      return;
    }
    iVar5 = _get_posix_proc((int)*(sword *)(iVar3 + 0x30));
    if (*(int *)(*(int *)(iVar5 + 0xe) + 8) != *(int *)(*(int *)(iVar2 + 0xe) + 8))
    goto loc_4007E78;
    if (*(int *)(iVar3 + 0x28) < 0) {
      *(undefined *)(dword_40B57D4 + 100) = 0xd;
      return;
    }
  }
  if (iVar3 == *(int *)(*(int *)(*(int *)(iVar5 + 0xe) + 8) + 4)) {
loc_4007E78:
    *(undefined *)(dword_40B57D4 + 100) = 1;
    return;
  }
  iVar4 = piVar1[1];
  if (iVar4 == 0) {
    piVar1[1] = (int)*(sword *)(iVar3 + 0x30);
  }
  else if ((*(sword *)(iVar3 + 0x30) != iVar4) &&
          ((iVar4 = _pgfind(iVar4), iVar4 == 0 ||
           (*(int *)(iVar4 + 8) != *(int *)(*(int *)(iVar2 + 0xe) + 8))))) goto loc_4007E78;
  _enterpgrp(iVar3,piVar1[1],0);
  return;
}
/* GHIDRADEC_FUNCTION index=186 start=0x4007e9e */

void _getpriority(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  piVar1 = *(int **)(dword_40B57D4 + 0x24);
  iVar3 = 0x15;
  iVar2 = *piVar1;
  if (iVar2 == 1) {
    if (piVar1[1] == 0) {
      piVar1[1] = (int)*(sword *)(*_active_u + 0x2e);
    }
    if (_allproc != 0) {
      iVar2 = _allproc;
      do {
        if ((piVar1[1] == (int)*(sword *)(iVar2 + 0x2e)) && (*(char *)(iVar2 + 0x15) < iVar3)) {
          iVar3 = (int)*(char *)(iVar2 + 0x15);
        }
        iVar2 = *(int *)(iVar2 + 8);
      } while (iVar2 != 0);
    }
loc_4007F8C:
    if (iVar3 == 0x15) {
      *(undefined *)(dword_40B57D4 + 100) = 3;
    }
    else {
      *(int *)(dword_40B57D4 + 0x5c) = iVar3;
    }
  }
  else {
    if (iVar2 < 2) {
      if (iVar2 == 0) {
        if (piVar1[1] == 0) {
          iVar2 = *_active_u;
        }
        else {
          iVar2 = _pfind(piVar1[1]);
        }
        if (iVar2 != 0) {
          iVar3 = (int)*(char *)(iVar2 + 0x15);
        }
        goto loc_4007F8C;
      }
    }
    else if (iVar2 == 2) {
      if (piVar1[1] == 0) {
        piVar1[1] = (int)*(sword *)(*(int *)((int)_active_u + 0x1a) + 2);
      }
      if (_allproc != 0) {
        iVar2 = _allproc;
        do {
          if ((piVar1[1] == (int)*(sword *)(iVar2 + 0x2c)) && (*(char *)(iVar2 + 0x15) < iVar3)) {
            iVar3 = (int)*(char *)(iVar2 + 0x15);
          }
          iVar2 = *(int *)(iVar2 + 8);
        } while (iVar2 != 0);
      }
      goto loc_4007F8C;
    }
    *(undefined *)(dword_40B57D4 + 100) = 0x16;
  }
  return;
}
/* GHIDRADEC_FUNCTION index=187 start=0x4007fb4 */

void _setpriority(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  piVar1 = *(int **)(dword_40B57D4 + 0x24);
  iVar3 = 0;
  iVar2 = *piVar1;
  if (iVar2 == 1) {
    iVar2 = _allproc;
    if (piVar1[1] == 0) {
      piVar1[1] = (int)*(sword *)(*_active_u + 0x2e);
      iVar2 = _allproc;
    }
    for (; iVar2 != 0; iVar2 = *(int *)(iVar2 + 8)) {
      if ((int)*(sword *)(iVar2 + 0x2e) == piVar1[1]) {
        _donice(iVar2,piVar1[2]);
        iVar3 = iVar3 + 1;
      }
    }
loc_40080B0:
    if (iVar3 == 0) {
      *(undefined *)(dword_40B57D4 + 100) = 3;
    }
  }
  else {
    if (iVar2 < 2) {
      if (iVar2 == 0) {
        if (piVar1[1] == 0) {
          iVar2 = *_active_u;
        }
        else {
          iVar2 = _pfind(piVar1[1]);
        }
        if (iVar2 != 0) {
          _donice(iVar2,piVar1[2]);
          iVar3 = 1;
        }
        goto loc_40080B0;
      }
    }
    else if (iVar2 == 2) {
      iVar2 = _allproc;
      if (piVar1[1] == 0) {
        piVar1[1] = (int)*(sword *)(*(int *)((int)_active_u + 0x1a) + 2);
        iVar2 = _allproc;
      }
      for (; iVar2 != 0; iVar2 = *(int *)(iVar2 + 8)) {
        if ((int)*(sword *)(iVar2 + 0x2c) == piVar1[1]) {
          _donice(iVar2,piVar1[2]);
          iVar3 = iVar3 + 1;
        }
      }
      goto loc_40080B0;
    }
    *(undefined *)(dword_40B57D4 + 100) = 0x16;
  }
  return;
}
/* GHIDRADEC_FUNCTION index=188 start=0x40080ca */

void _donice(int param_1,int param_2)

{
  sword sVar1;
  sword sVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  sVar1 = *(sword *)(*(int *)(_active_u + 0x1a) + 2);
  if ((((sVar1 == 0) || (sVar2 = *(sword *)(*(int *)(_active_u + 0x1a) + 6), sVar2 == 0)) ||
      (*(sword *)(param_1 + 0x2c) == sVar1)) || (*(sword *)(param_1 + 0x2c) == sVar2)) {
    if (0x14 < param_2) {
      param_2 = 0x14;
    }
    if (param_2 < -0x14) {
      param_2 = -0x14;
    }
    if ((param_2 < *(char *)(param_1 + 0x15)) && (iVar4 = _suser(), iVar4 == 0)) {
      *(undefined *)(dword_40B57D4 + 100) = 0xd;
    }
    else {
      iVar4 = *(int *)(param_1 + 0x66);
      iVar6 = param_2;
      if (param_2 < 0) {
        iVar6 = param_2 + 1;
      }
      iVar3 = (*(int *)(iVar4 + 0x40) + (int)(*(char *)(param_1 + 0x15) / '\x02')) - (iVar6 >> 1);
      *(char *)(param_1 + 0x15) = (char)param_2;
      _task_priority(iVar4,iVar3,0);
      for (iVar6 = *(int *)(iVar4 + 0x18); iVar6 != iVar4 + 0x18; iVar6 = *(int *)(iVar6 + 0x10)) {
        if (*(int *)(iVar6 + 0x50) < iVar3) {
          _thread_max_priority(iVar6,*(undefined4 *)(iVar6 + 0x178),iVar3);
        }
        iVar5 = _thread_priority(iVar6,iVar3,1);
        if (iVar5 != 0) goto loc_4008130;
      }
    }
  }
  else {
loc_4008130:
    *(undefined *)(dword_40B57D4 + 100) = 1;
  }
  return;
}
/* GHIDRADEC_FUNCTION index=189 start=0x40081c2 */

void _setrlimit(void)

{
  uint *puVar1;
  uint uVar2;
  undefined uVar4;
  int iVar3;
  int *piVar5;
  uint uStack_10;
  int iStack_c;
  int iStack_8;
  
  puVar1 = *(uint **)(dword_40B57D4 + 0x24);
  if (*puVar1 < 6) {
    piVar5 = (int *)(*puVar1 * 8 + 0x256 + (int)_active_u);
    uVar4 = _copyinmsg(puVar1[1],&iStack_c,8);
    *(undefined *)(dword_40B57D4 + 100) = uVar4;
    if (*(char *)(dword_40B57D4 + 100) == '\0') {
      if (((piVar5[1] < iStack_c) || (piVar5[1] < iStack_8)) && (iVar3 = _suser(), iVar3 == 0)) {
        return;
      }
      if (*puVar1 == 3) {
        if (*piVar5 < iStack_c) {
          uVar2 = ~_page_mask;
          uStack_10 = uVar2 & *(int *)(*_active_u + 0x82) - iStack_c;
          iVar3 = _vm_allocate(*(undefined4 *)(*(int *)(_active_threads + 0xc) + 8),&uStack_10,
                               (uVar2 & _page_mask + iStack_c) - (uVar2 & *piVar5 + _page_mask),0);
        }
        else {
          uVar2 = ~_page_mask;
          uStack_10 = uVar2 & *(int *)(*_active_u + 0x82) - *piVar5;
          iVar3 = _vm_deallocate(*(undefined4 *)(*(int *)(_active_threads + 0xc) + 8),uStack_10,
                                 (uVar2 & _page_mask + *piVar5) - (uVar2 & iStack_c + _page_mask));
        }
        if (iVar3 != 0) {
          *(undefined *)(dword_40B57D4 + 100) = 0x16;
          return;
        }
      }
      *piVar5 = iStack_c;
      piVar5[1] = iStack_8;
    }
  }
  else {
    *(undefined *)(dword_40B57D4 + 100) = 0x16;
  }
  return;
}
/* GHIDRADEC_FUNCTION index=190 start=0x4008306 */

void _getrlimit(void)

{
  uint uVar1;
  undefined uVar2;
  
  uVar1 = **(uint **)(dword_40B57D4 + 0x24);
  if (uVar1 < 6) {
    uVar2 = _copyoutmsg(_active_u + uVar1 * 8 + 0x256,(*(uint **)(dword_40B57D4 + 0x24))[1],8);
    *(undefined *)(dword_40B57D4 + 100) = uVar2;
  }
  else {
    *(undefined *)(dword_40B57D4 + 100) = 0x16;
  }
  return;
}
/* GHIDRADEC_FUNCTION index=191 start=0x4008350 */

void _getrusage(void)

{
  int *piVar1;
  int iVar2;
  undefined uVar3;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  piVar1 = *(int **)(dword_40B57D4 + 0x24);
  iVar2 = *piVar1;
  if (iVar2 == -1) {
    iVar2 = _active_u + 0x1ae;
  }
  else {
    if (iVar2 != 0) {
      *(undefined *)(dword_40B57D4 + 100) = 0x16;
      return;
    }
    _thread_read_times(_active_threads,&uStack_c,&uStack_14);
    iVar2 = _active_u;
    *(undefined4 *)(_active_u + 0x166) = uStack_c;
    *(undefined4 *)(iVar2 + 0x16a) = uStack_8;
    iVar2 = _active_u;
    *(undefined4 *)(_active_u + 0x16e) = uStack_14;
    *(undefined4 *)(iVar2 + 0x172) = uStack_10;
    iVar2 = _active_u + 0x166;
  }
  uVar3 = _copyoutmsg(iVar2,piVar1[1],0x48);
  *(undefined *)(dword_40B57D4 + 100) = uVar3;
  return;
}
/* GHIDRADEC_FUNCTION index=192 start=0x40083e8 */

void _ruadd(int param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  
  _timevaladd(param_1,param_2);
  _timevaladd(param_1 + 8,param_2 + 8);
  if (*(int *)(param_1 + 0x10) < *(int *)(param_2 + 0x10)) {
    *(int *)(param_1 + 0x10) = *(int *)(param_2 + 0x10);
  }
  iVar1 = 0xc;
  piVar2 = (int *)(param_1 + 0x14);
  piVar3 = (int *)(param_2 + 0x14);
  do {
    *piVar2 = *piVar3 + *piVar2;
    iVar1 = iVar1 + -1;
    piVar2 = piVar2 + 1;
    piVar3 = piVar3 + 1;
  } while (0 < iVar1);
  return;
}
/* GHIDRADEC_FUNCTION index=193 start=0x400843e */

void _boot(undefined4 param_1,uint param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint *puVar4;
  
  _md_prepare_for_shutdown(param_1,param_2,param_3);
  iVar2 = _acctp;
  if ((((param_2 & 4) == 0) && (_waittime < 0)) && (dword_40B57DC != 0)) {
    _waittime = 0;
    if (_acctp != 0) {
      _acctp = 0;
      _vn_rele(iVar2);
    }
    _sync();
    _unmount_all();
    _if_down_all();
    iVar2 = 0;
    iVar3 = 0;
    do {
      iVar1 = 0;
      for (puVar4 = _buf + _nbuf * 0x11 + -0x11; _buf <= puVar4; puVar4 = puVar4 + -0x11) {
        if ((*puVar4 & 10) == 8) {
          iVar1 = iVar1 + 1;
        }
      }
      if (iVar1 == 0) break;
      _printf(&aD,iVar1);
      if (iVar3 != iVar1) {
        iVar2 = 0;
      }
      _delay(iVar2 * 40000);
      iVar2 = iVar2 + 1;
      iVar3 = iVar1;
    } while (iVar2 < 0x14);
  }
  _md_shutdown_devices(param_1,param_2,param_3);
  _md_do_shutdown(param_1,param_2,param_3);
  return;
}
/* GHIDRADEC_FUNCTION index=194 start=0x400853e */

void _unmount_all(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined8 *puVar4;
  
  _proc_shutdown();
  _kill_tasks();
  _mfs_cache_clear();
  _vm_object_cache_clear();
  _fd_shutdown();
  _vm_object_shutdown();
  _vnode_pager_shutdown();
  puVar2 = (undefined4 *)*_rootvfs;
  while (puVar2 != (undefined4 *)0x0) {
    _printf(aUnmountingS,puVar2 + 8);
    puVar1 = (undefined4 *)*puVar2;
    iVar3 = _dounmount(puVar2);
    if (iVar3 == 0) {
      puVar4 = (undefined8 *)&aDone;
    }
    else {
      puVar4 = &aFailed;
    }
    _printf(puVar4);
    puVar2 = puVar1;
  }
  _vn_rele(_rootdir);
  iVar3 = _dounmount(_rootvfs);
  if (iVar3 != 0) {
    _printf(aRootUnmountFai);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=195 start=0x40085ec */

void _kill_tasks(void)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 *puVar6;
  
  uVar4 = _pmap_create(0,0,0,1);
  iVar5 = _vm_map_create(uVar4);
  puVar3 = _all_psets;
  while (puVar6 = puVar3, (undefined4 **)puVar6 != &_all_psets) {
    puVar3 = dword_40B6788;
    if (puVar6 != (undefined4 *)_default_pset) {
      _processor_set_destroy(puVar6);
      puVar3 = _all_psets;
    }
  }
  while (iVar2 = dword_40B676C, dword_40B6774 != 0) {
    dword_40B676C = iVar2;
    _pset_remove_task(_default_pset,iVar2);
    iVar1 = *(int *)(iVar2 + 8);
    if ((iVar1 != _kernel_map) && (iVar5 != iVar1)) {
      *(int *)(iVar2 + 8) = iVar5;
      _vm_map_reference(iVar5);
      _vm_map_remove(iVar1,*(undefined4 *)(iVar1 + 0x10),*(undefined4 *)(iVar1 + 0x14));
    }
  }
  dword_40B676C = iVar2;
  return;
}
/* GHIDRADEC_FUNCTION index=196 start=0x40086a6 */

void _proc_shutdown(void)

{
  int iVar1;
  int iVar2;
  bool bVar3;
  int iVar4;
  int iVar5;
  
  iVar1 = *(int *)(*(int *)(_active_threads + 0xc) + 0x34);
  iVar4 = _pfind(1);
  if ((iVar4 != 0) && (iVar1 != iVar4)) {
    _task_suspend(*(undefined4 *)(iVar4 + 0x66));
  }
  iVar4 = _pfind(2);
  if ((iVar4 != 0) && (iVar1 != iVar4)) {
    _task_suspend(*(undefined4 *)(iVar4 + 0x66));
  }
  _printf(aKillingAllProc);
  for (iVar4 = _allproc; iVar4 != 0; iVar4 = *(int *)(iVar4 + 8)) {
    if (((*(sword *)(iVar4 + 0x32) != 0) && ((*(byte *)(iVar4 + 0x2b) & 2) == 0)) &&
       (iVar1 != iVar4)) {
      _psignal(iVar4,0xf);
    }
  }
  _ns_sleep(0,2000000000);
  _ns_sleep(0,2000000000);
  for (iVar4 = _allproc; iVar4 != 0; iVar4 = *(int *)(iVar4 + 8)) {
    if (((*(sword *)(iVar4 + 0x32) != 0) && ((*(byte *)(iVar4 + 0x2b) & 2) == 0)) &&
       (iVar1 != iVar4)) {
      _psignal(iVar4,9);
    }
  }
  _ns_sleep(0,1000000000);
  iVar4 = _allproc;
  while (iVar4 != 0) {
    if (((*(sword *)(iVar4 + 0x32) == 0) || ((*(byte *)(iVar4 + 0x2b) & 2) != 0)) ||
       (iVar1 == iVar4)) {
      iVar4 = *(int *)(iVar4 + 8);
    }
    else if (*(int *)(iVar4 + 0x76) == 0) {
      *(int *)(iVar4 + 0x76) = _active_threads;
      _printf(&asc_40A6047);
      _do_exit(iVar4,1);
      iVar4 = _allproc;
    }
    else {
      _thread_block();
      iVar4 = _allproc;
    }
  }
  _printf(&asc_40A6049);
  iVar1 = _allproc;
  while (iVar4 = iVar1, iVar4 != 0) {
    iVar1 = *(int *)(*(int *)(iVar4 + 0x66) + 0x30);
    bVar3 = false;
    iVar5 = 0;
    if (*(uint *)(iVar1 + 0x14e) < 0x80000000) {
      do {
        iVar2 = *(int *)(*(int *)(iVar1 + 0x146) + iVar5 * 4);
        if ((iVar2 != 0) && (iVar2 != -0x10000)) {
          _vno_lockrelease(iVar2);
          *(undefined4 *)(*(int *)(iVar1 + 0x146) + iVar5 * 4) = 0;
          _closef(iVar2);
          bVar3 = true;
        }
        *(undefined *)(iVar5 + *(int *)(iVar1 + 0x14a)) = 0;
        iVar5 = iVar5 + 1;
      } while (iVar5 <= *(int *)(iVar1 + 0x14e));
    }
    iVar5 = *(int *)(iVar1 + 0x156);
    if (iVar5 != 0) {
      *(int *)(iVar1 + 0x156) = 0;
      _vn_rele(iVar5);
      bVar3 = true;
    }
    iVar5 = *(int *)(iVar1 + 0x15a);
    if (iVar5 != 0) {
      *(int *)(iVar1 + 0x15a) = 0;
      _vn_rele(iVar5);
      bVar3 = true;
    }
    iVar1 = _allproc;
    if (!bVar3) {
      iVar1 = *(int *)(iVar4 + 8);
    }
  }
  _thread_wakeup_prim(&_reaper_queue,0,0);
  _ns_sleep(0,2000000000);
  _printf(aContinuing);
  return;
}
/* GHIDRADEC_FUNCTION index=197 start=0x40088ee */

void _fd_shutdown(void)

{
  undefined4 *puVar1;
  sword sVar2;
  undefined4 *puVar3;
  
  puVar1 = _file_list;
  while (puVar3 = puVar1, (undefined4 **)puVar3 != &_file_list) {
    puVar1 = (undefined4 *)*puVar3;
    sVar2 = *(sword *)((int)puVar3 + 0xe);
    while (0 < sVar2) {
      _closef(puVar3);
      sVar2 = *(sword *)((int)puVar3 + 0xe);
    }
  }
  return;
}
/* GHIDRADEC_FUNCTION index=198 start=0x4008932 */

void _sigvec(void)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
  undefined uVar4;
  int iStack_10;
  undefined4 uStack_c;
  uint uStack_8;
  
  piVar2 = *(int **)(dword_40B57D4 + 0x24);
  iVar1 = *piVar2;
  if (((iVar1 - 1U < 0x1f) && (iVar1 != 9)) && (iVar1 != 0x11)) {
    if (piVar2[2] != 0) {
      iStack_10 = *(int *)((int)_active_u + iVar1 * 4 + 0x2a);
      uStack_c = *(undefined4 *)((int)_active_u + iVar1 * 4 + 0xae);
      uVar3 = 1 << (iVar1 - 1U & 0x3f);
      uStack_8 = (uint)((uVar3 & *(uint *)((int)_active_u + 0x132)) != 0);
      if ((uVar3 & *(uint *)((int)_active_u + 0x136)) != 0) {
        uStack_8 = uStack_8 | 2;
      }
      uVar4 = _copyoutmsg(&iStack_10,piVar2[2],0xc);
      *(undefined *)(dword_40B57D4 + 100) = uVar4;
      if (*(char *)(dword_40B57D4 + 100) != '\0') {
        return;
      }
    }
    if (piVar2[1] != 0) {
      uVar4 = _copyinmsg(piVar2[1],&iStack_10,0xc);
      *(undefined *)(dword_40B57D4 + 100) = uVar4;
      if (*(char *)(dword_40B57D4 + 100) == '\0') {
        if (((iVar1 == 0x13) && (iStack_10 == 1)) && ((*(byte *)(*_active_u + 0x16) & 0x40) == 0)) {
          *(undefined *)(dword_40B57D4 + 100) = 0x16;
        }
        else {
          _setsigvec(iVar1,&iStack_10);
        }
      }
    }
  }
  else {
    *(undefined *)(dword_40B57D4 + 100) = 0x16;
  }
  return;
}
/* GHIDRADEC_FUNCTION index=199 start=0x4008a40 */

undefined4 _setsigvec(uint param_1,uint *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  uint uVar4;
  uint uVar5;
  bool bVar6;
  
  uVar4 = 1 << (param_1 - 1 & 0x3f);
  iVar1 = *_active_u;
  *(uint *)((int)_active_u + param_1 * 4 + 0x2a) = *param_2;
  if ((*(byte *)(*_active_u + 0x16) & 0x40) == 0) {
    uVar5 = param_2[1] & 0xfffafeff;
  }
  else {
    uVar5 = param_2[1] & 0xfffefeff;
  }
  *(uint *)((int)_active_u + param_1 * 4 + 0xae) = uVar5;
  if ((*(byte *)((int)param_2 + 0xb) & 2) == 0) {
    *(uint *)((int)_active_u + 0x136) = ~uVar4 & *(uint *)((int)_active_u + 0x136);
  }
  else {
    *(uint *)((int)_active_u + 0x136) = uVar4 | *(uint *)((int)_active_u + 0x136);
  }
  if ((*(byte *)((int)param_2 + 0xb) & 1) == 0) {
    *(uint *)((int)_active_u + 0x132) = ~uVar4 & *(uint *)((int)_active_u + 0x132);
  }
  else {
    *(uint *)((int)_active_u + 0x132) = uVar4 | *(uint *)((int)_active_u + 0x132);
  }
  uVar5 = *param_2;
  bVar6 = 1 < uVar5;
  if ((uVar5 == 1) ||
     ((((*(byte *)(iVar1 + 0x16) & 0x40) != 0 && (uVar5 == 0)) &&
      (bVar6 = 0x14 < param_1, param_1 == 0x14)))) {
    *(uint *)(iVar1 + 0x18) = ~uVar4 & *(uint *)(iVar1 + 0x18);
    if ((uVar4 & 0x1ef8) != 0) {
      puVar3 = (undefined4 *)(*(int *)(iVar1 + 0x66) + 0x18);
      for (puVar2 = (undefined4 *)*puVar3; bVar6 = puVar2 < puVar3, puVar2 != puVar3;
          puVar2 = (undefined4 *)puVar2[4]) {
        *(uint *)(puVar2[0x20] + 0x72) = ~uVar4 & *(uint *)(puVar2[0x20] + 0x72);
      }
    }
    *(uint *)(iVar1 + 0x20) = uVar4 | *(uint *)(iVar1 + 0x20);
  }
  else {
    *(uint *)(iVar1 + 0x20) = ~uVar4 & *(uint *)(iVar1 + 0x20);
    if (*param_2 != 0) {
      uVar5 = uVar4 | *(uint *)(iVar1 + 0x24);
      *(uint *)(iVar1 + 0x24) = uVar5;
      goto loc_4008B58;
    }
    if ((*(byte *)(iVar1 + 0x16) & 0x40) != 0) {
      *(undefined4 *)((int)_active_u + param_1 * 4 + 0x2a) = 0;
    }
  }
  uVar5 = ~uVar4 & *(uint *)(iVar1 + 0x24);
  *(uint *)(iVar1 + 0x24) = uVar5;
loc_4008B58:
  return CONCAT22(~(word)(uVar4 >> 0x10),
                  (word)(byte)(bVar6 << 4 | ((int)uVar5 < 0) << 3 | (uVar5 == 0) << 2));
}

