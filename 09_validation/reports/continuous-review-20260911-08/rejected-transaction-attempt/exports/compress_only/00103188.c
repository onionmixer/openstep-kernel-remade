
int _acct(char *param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined1 uVar3;
  int in_EAX;
  int iVar4;
  int iVar5;
  uint uVar6;
  undefined1 *puVar7;
  int local_4c;
  int local_48;
  int local_3c;
  int local_34;
  
  if (_savacctp != 0) {
    (**(code **)(*(int *)(*(int *)(_savacctp + 0x24) + 4) + 0xc))();
    in_EAX = (_acctresume * local_3c) / 100;
    if (in_EAX < local_34) {
      _acctp = _savacctp;
      _savacctp = 0;
      in_EAX = _printf(s_Accounting_resumed_001da600);
    }
  }
  iVar2 = _acctp;
  if (_acctp != 0) {
    *(short *)(_acctp + 6) = *(short *)(_acctp + 6) + 1;
    (**(code **)(*(int *)(*(int *)(iVar2 + 0x24) + 4) + 0xc))();
    if ((_acctsuspend * local_3c) / 100 < local_34) {
      uVar6 = 0;
      do {
        (&_acctbuf)[uVar6] = *(undefined1 *)(uVar6 + 8 + _active_u);
        iVar5 = _active_u;
        uVar6 = uVar6 + 1;
      } while (uVar6 < 10);
      iVar4 = _compress(*(int *)(_active_u + 0x170),*(int *)(_active_u + 0x174));
      DAT_001e908a = (undefined2)iVar4;
      iVar4 = _compress(*(int *)(iVar5 + 0x178),*(int *)(iVar5 + 0x17c));
      DAT_001e908c = (undefined2)iVar4;
      _microtime(&local_4c);
      _timevalsub(&local_4c,_active_u + 0x23c);
      iVar4 = _compress(local_4c,local_48);
      DAT_001e908e = (undefined2)iVar4;
      DAT_001e9090 = *(undefined4 *)(_active_u + 0x23c);
      DAT_001e9094 = *(undefined2 *)(*(int *)(_active_u + 0x1c) + 6);
      DAT_001e9096 = *(undefined2 *)(*(int *)(_active_u + 0x1c) + 8);
      local_4c = *(int *)(iVar5 + 0x178);
      local_48 = *(int *)(iVar5 + 0x17c);
      _timevaladd();
      iVar4 = local_4c * _hz + local_48 / _tick;
      if (iVar4 == 0) {
        DAT_001e9098 = 0;
      }
      else {
        DAT_001e9098 = (undefined2)
                       ((*(int *)(iVar5 + 0x184) + *(int *)(iVar5 + 0x188) + *(int *)(iVar5 + 0x18c)
                        ) / iVar4);
      }
      iVar5 = _compress(*(int *)(iVar5 + 0x19c) + *(int *)(iVar5 + 0x1a0),0);
      DAT_001e909a = (undefined2)iVar5;
      if (*(int *)(_active_u + 0x168) == 0) {
        DAT_001e909c = 0xffff;
      }
      else {
        DAT_001e909c = *(undefined2 *)(_active_u + 0x16c);
      }
      DAT_001e909e = *(undefined1 *)(_active_u + 0x244);
      uVar1 = *(undefined4 *)(_active_u + 0x1c);
      *(undefined4 *)(_active_u + 0x1c) = _acctcred;
      uVar3 = _vn_rdwr(1,iVar2,&_acctbuf,0x20,0,1);
      *(undefined1 *)(DAT_001e875c + 0x68) = uVar3;
      *(undefined4 *)(_active_u + 0x1c) = uVar1;
      puVar7 = &stack0xffffff94;
    }
    else {
      _savacctp = _acctp;
      _acctp = 0;
      _printf(s_Accounting_suspended_001da614);
      puVar7 = &stack0xffffff90;
    }
    *(undefined4 *)(puVar7 + -4) = 0x10341b;
    in_EAX = _vn_rele();
  }
  return in_EAX;
}

