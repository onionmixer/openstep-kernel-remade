
void _ipc_hash_local_delete(int param_1,uint param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  iVar1 = *(int *)(param_1 + 0xc);
  uVar2 = *(uint *)(param_1 + 0x10);
  uVar5 = (param_2 >> 6) % uVar2;
  while (param_3 != *(int *)(iVar1 + 0xc + uVar5 * 0x10)) {
    uVar5 = uVar5 + 1;
    if (uVar2 == uVar5) {
      uVar5 = 0;
    }
  }
  do {
    uVar4 = uVar5;
    if (param_3 == 0) {
      return;
    }
    do {
      while( true ) {
        uVar4 = uVar4 + 1;
        if (uVar2 == uVar4) {
          uVar4 = 0;
        }
        param_3 = *(int *)(iVar1 + 0xc + uVar4 * 0x10);
        if (param_3 == 0) goto loc_403CB04;
        uVar3 = (*(uint *)(iVar1 + 4 + param_3 * 0x10) >> 6) % uVar2;
        if (uVar4 < uVar5) break;
        if ((uVar4 < uVar3) || (uVar3 <= uVar5)) goto loc_403CB04;
      }
    } while ((uVar3 <= uVar4) || (uVar5 < uVar3));
loc_403CB04:
    *(int *)(iVar1 + 0xc + uVar5 * 0x10) = param_3;
    uVar5 = uVar4;
  } while( true );
}
