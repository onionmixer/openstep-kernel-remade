
void _rtalloc(int *param_1)

{
  code *pcVar1;
  undefined4 *puVar2;
  bool bVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  undefined *puVar7;
  uint *puVar8;
  undefined *puVar9;
  uint uStack_c;
  uint uStack_8;
  
  puVar9 = (undefined *)(param_1 + 1);
  uVar6 = (uint)*(word *)puVar9;
  iVar4 = *param_1;
  if ((((iVar4 == 0) || (*(int *)(iVar4 + 0x2c) == 0)) || ((*(byte *)(iVar4 + 0x25) & 1) == 0)) &&
     (uVar6 < 0x11)) {
    (*(code *)(&_afswitch)[uVar6 * 2])(puVar9,&uStack_c);
    pcVar1 = (&off_40AE86A)[uVar6 * 2];
    puVar7 = _rthost;
    bVar3 = true;
    uVar5 = uStack_c;
loc_401D84C:
    for (puVar2 = *(undefined4 **)(puVar7 + (uVar5 & 7) * 4); puVar2 != (undefined4 *)0x0;
        puVar2 = (undefined4 *)*puVar2) {
      puVar8 = (uint *)(puVar2[1] + (int)puVar2);
      if (((uVar5 == *puVar8) && ((*(byte *)((int)puVar8 + 0x25) & 1) != 0)) &&
         ((*(byte *)(puVar8[0xb] + 0xd) & 1) != 0)) {
        if (bVar3) {
          iVar4 = _bcmp(puVar8 + 1,puVar9,0x10);
          if (iVar4 == 0) goto loc_401D8B0;
        }
        else if ((uVar6 == *(word *)(puVar8 + 1)) &&
                (iVar4 = (*pcVar1)(puVar8 + 1,puVar9), iVar4 != 0)) {
loc_401D8B0:
          *(sword *)((int)puVar8 + 0x26) = *(sword *)((int)puVar8 + 0x26) + 1;
          if (puVar9 == _wildcard) {
            word_40B6A14 = word_40B6A14 + 1;
          }
          *param_1 = (int)puVar8;
          return;
        }
      }
    }
    if (bVar3) {
      bVar3 = false;
      puVar7 = _rtnet;
      uVar5 = uStack_8;
      goto loc_401D84C;
    }
    if (puVar9 != _wildcard) {
      puVar9 = _wildcard;
      uVar5 = 0;
      goto loc_401D84C;
    }
    word_40B6A12 = word_40B6A12 + 1;
  }
  return;
}
