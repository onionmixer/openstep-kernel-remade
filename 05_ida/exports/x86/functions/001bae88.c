/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1bae88. */
int __cdecl sub_1BAE88(_DWORD *a1, int a2)
{
  int v3; // eax
  int v4; // eax
  int v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // eax
  __int16 v9; // ax
  int v10; // eax
  int v11; // eax
  int v12; // eax
  int v13; // eax
  int v14; // eax
  int v15; // eax
  int v16; // eax
  int v17; // eax
  int v18; // eax
  int v19; // eax
  id v20; // eax
  id v21; // eax
  id v22; // eax
  id v23; // eax
  int v24; // [esp-4h] [ebp-18h]
  int v25; // [esp-4h] [ebp-18h]
  int v26; // [esp-4h] [ebp-18h]
  id v27; // [esp+Ch] [ebp-8h]
  int v28; // [esp+10h] [ebp-4h]

  v27 = +[IOAudio _instance](aIoaudio, sel__instance); /*0x1baeaa*/
  *(_BYTE *)(a2 + 3) = 1; /*0x1baead*/
  *(_DWORD *)(a2 + 4) = 24; /*0x1baeb1*/
  *(_DWORD *)(a2 + 8) = 0; /*0x1baeb8*/
  *(_DWORD *)(a2 + 12) = 0; /*0x1baebf*/
  *(_DWORD *)(a2 + 16) = a1[4]; /*0x1baec9*/
  *(_DWORD *)(a2 + 20) = 0; /*0x1baecc*/
  if ( a1[5] ) /*0x1baed6*/
    return 0; /*0x1baedc*/
  if ( !v27 ) /*0x1baee8*/
    return 1; /*0x1baeea*/
  if ( !dword_1E53B8 )
  {
    kern_serv_port_death_proc(dword_1E8718, (int)audio_port_gone); /*0x1baf0d*/
    v3 = task_self(); /*0x1baf19*/
    if ( port_allocate_EXTERNAL(v3) )
      IOLog((int)"Audio: port_allocate");
    outPort = v28; /*0x1baf3b*/
    v4 = kern_serv_port_serv((int *)dword_1E8718, v28, (int)audioMessages, v28); /*0x1baf4e*/
    if ( v4 )
      IOLog((int)"Audio: createAudioPorts error %d\n", v4);
    v5 = task_self(); /*0x1baf69*/
    if ( port_allocate_EXTERNAL(v5) )
      IOLog((int)"Audio: port_allocate");
    inPort = v28; /*0x1baf8b*/
    v6 = kern_serv_port_serv((int *)dword_1E8718, v28, (int)audioMessages, v28); /*0x1baf9e*/
    if ( v6 )
      IOLog((int)"Audio: createAudioPorts error %d\n", v6);
    v7 = task_self(); /*0x1bafb9*/
    if ( port_allocate_EXTERNAL(v7) )
      IOLog((int)"Audio: port_allocate");
    sndPort = v28; /*0x1bafdb*/
    v8 = kern_serv_port_serv((int *)dword_1E8718, v28, (int)audioMessages, v28); /*0x1bafee*/
    if ( v8 )
      IOLog((int)"Audio: createAudioPorts error %d\n", v8);
    dword_1E53B8 = 1; /*0x1bb008*/
  }
  *(_BYTE *)(a2 + 3) = 0; /*0x1bb015*/
  *(_DWORD *)(a2 + 4) = 40; /*0x1bb019*/
  *(_DWORD *)(a2 + 20) = 1; /*0x1bb020*/
  *(_BYTE *)(a2 + 24) = 6; /*0x1bb027*/
  *(_BYTE *)(a2 + 25) = 32; /*0x1bb02b*/
  v9 = *(_WORD *)(a2 + 26) & 0xF000; /*0x1bb033*/
  LOBYTE(v9) = 3; /*0x1bb037*/
  *(_WORD *)(a2 + 26) = v9; /*0x1bb039*/
  *(_BYTE *)(a2 + 27) = *(_BYTE *)(a2 + 27) & 0xF | 0x10; /*0x1bb044*/
  v10 = IOHostPrivSelf(); /*0x1bb047*/
  if ( v10 )
  {
    if ( a1[7] == v10 )
    {
      if ( a1[9] )
      {
        if ( inPort )
        {
          kern_serv_port_gone((int *)dword_1E8718, inPort); /*0x1bb09f*/
          v24 = inPort; /*0x1bb0ad*/
          v11 = task_self(); /*0x1bb0ae*/
          if ( port_deallocate_EXTERNAL(v11, v24) )
            IOLog((int)"Audio: port_deallocate\n");
        }
        if ( outPort )
        {
          kern_serv_port_gone((int *)dword_1E8718, outPort); /*0x1bb0de*/
          v25 = outPort; /*0x1bb0ec*/
          v12 = task_self(); /*0x1bb0ed*/
          if ( port_deallocate_EXTERNAL(v12, v25) )
            IOLog((int)"Audio: port_deallocate\n");
        }
        if ( sndPort )
        {
          kern_serv_port_gone((int *)dword_1E8718, sndPort); /*0x1bb11d*/
          v26 = sndPort; /*0x1bb12b*/
          v13 = task_self(); /*0x1bb12c*/
          if ( port_deallocate_EXTERNAL(v13, v26) )
            IOLog((int)"Audio: port_deallocate\n");
        }
        v14 = task_self(); /*0x1bb14f*/
        if ( port_allocate_EXTERNAL(v14) )
          IOLog((int)"Audio: port_allocate");
        outPort = v28; /*0x1bb171*/
        v15 = kern_serv_port_serv((int *)dword_1E8718, v28, (int)audioMessages, v28); /*0x1bb184*/
        if ( v15 )
          IOLog((int)"Audio: createAudioPorts error %d\n", v15);
        v16 = task_self(); /*0x1bb19f*/
        if ( port_allocate_EXTERNAL(v16) )
          IOLog((int)"Audio: port_allocate");
        inPort = v28; /*0x1bb1c1*/
        v17 = kern_serv_port_serv((int *)dword_1E8718, v28, (int)audioMessages, v28); /*0x1bb1d4*/
        if ( v17 )
          IOLog((int)"Audio: createAudioPorts error %d\n", v17);
        v18 = task_self(); /*0x1bb1ef*/
        if ( port_allocate_EXTERNAL(v18) )
          IOLog((int)"Audio: port_allocate");
        sndPort = v28; /*0x1bb211*/
        v19 = kern_serv_port_serv((int *)dword_1E8718, v28, (int)audioMessages, v28); /*0x1bb224*/
        if ( v19 )
          IOLog((int)"Audio: createAudioPorts error %d\n", v19);
      }
      *(_DWORD *)(a2 + 28) = inPort; /*0x1bb244*/
      *(_DWORD *)(a2 + 32) = outPort; /*0x1bb24d*/
      *(_DWORD *)(a2 + 36) = sndPort; /*0x1bb256*/
    }
    else
    {
      *(_DWORD *)(a2 + 28) = 0; /*0x1bb069*/
      *(_DWORD *)(a2 + 32) = 0; /*0x1bb070*/
      *(_DWORD *)(a2 + 36) = 0; /*0x1bb077*/
    }
    v20 = objc_msgSend(v27, sel__outputChannel); /*0x1bb272*/
    objc_msgSend(v20, sel_setUserChannelPort_); /*0x1bb27b*/
    v21 = objc_msgSend(v27, sel__outputChannel); /*0x1bb299*/
    objc_msgSend(v21, sel_setUserSndPort_); /*0x1bb2a2*/
    v22 = objc_msgSend(v27, sel__inputChannel); /*0x1bb2c0*/
    objc_msgSend(v22, sel_setUserChannelPort_); /*0x1bb2c9*/
    v23 = objc_msgSend(v27, sel__inputChannel); /*0x1bb2ea*/
    objc_msgSend(v23, sel_setUserSndPort_); /*0x1bb2f3*/
    return 1; /*0x1bb2f8*/
  }
  else
  {
    IOLog((int)"Audio: cannot get kernel port (must run as root)\n");
    return 1; /*0x1bb05a*/
  }
}
