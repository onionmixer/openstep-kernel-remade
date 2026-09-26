
void _ipc_table_fill(uint *param_1,uint param_2,int param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint *puVar5;
  uint *puVar6;
  uint uVar7;
  
  uVar3 = _page_size;
  uVar4 = param_4 * param_3;
  uVar7 = 0;
  uVar2 = 1;
  puVar5 = param_1;
  uVar1 = _page_size;
  if (param_2 != 0) {
    do {
      uVar1 = _page_size;
      if (uVar3 <= uVar2) break;
      puVar6 = puVar5;
      if (uVar4 < uVar2 || uVar4 - uVar2 == 0) {
        puVar6 = puVar5 + 1;
        *puVar5 = uVar2 / param_4;
        uVar7 = uVar7 + 1;
      }
      uVar2 = uVar2 * 2;
      puVar5 = puVar6;
      uVar1 = _page_size;
    } while (uVar7 < param_2);
  }
  do {
    if (param_2 <= uVar7) {
      return;
    }
    uVar3 = 0;
    puVar5 = param_1 + uVar7;
    do {
      if (param_2 <= uVar7) break;
      puVar6 = puVar5;
      if (uVar4 < uVar2 || uVar4 - uVar2 == 0) {
        puVar6 = puVar5 + 1;
        *puVar5 = uVar2 / param_4;
        uVar7 = uVar7 + 1;
      }
      uVar3 = uVar3 + 1;
      uVar2 = uVar1 + uVar2;
      puVar5 = puVar6;
    } while (uVar3 < 0xf);
    uVar1 = uVar1 * 2;
  } while( true );
}

