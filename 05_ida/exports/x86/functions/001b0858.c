/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1b0858. */
int __cdecl sub_1B0858(_DWORD *a1)
{
  unsigned int v1; // edi
  _DWORD *v2; // ebx
  _DWORD *v3; // esi
  int v4; // eax
  const char *v5; // eax
  int v6; // eax
  int v7; // eax
  const char *v8; // eax
  id v10; // [esp-8h] [ebp-21Ch]
  int v11; // [esp-8h] [ebp-21Ch]
  id v12; // [esp-8h] [ebp-21Ch]
  int v13; // [esp-4h] [ebp-218h]
  int v14; // [esp+Ch] [ebp-208h]
  unsigned int v15; // [esp+10h] [ebp-204h]
  _BYTE v16[512]; // [esp+14h] [ebp-200h] BYREF

  v1 = 512; /*0x1b0864*/
  v2 = v16; /*0x1b0869*/
  v15 = 0; /*0x1b086f*/
  v3 = nullptr; /*0x1b0879*/
  while ( 1 )
  {
    v2[3] = a1[82]; /*0x1b0885*/
    v2[1] = v1; /*0x1b0888*/
    v4 = msg_receive(v2, 4096, 0); /*0x1b0893*/
    if ( v4 == -202 ) /*0x1b08a0*/
      return IOExitThread(); /*0x1b0aae*/
    if ( v4 > -202 )
    {
      if ( v4 ) /*0x1b08b6*/
        goto LABEL_11; /*0x1b08b6*/
      v14 = v2[3]; /*0x1b090f*/
      if ( a1[79] == v14 )
      {
        v6 = v2[7]; /*0x1b0920*/
        if ( a1[81] == v6 && v6 ) /*0x1b0931*/
          objc_msgSend(a1, sel_evClose_token_, a1[77], a1[69]); /*0x1b0950*/
      }
      else
      {
        v7 = 0; /*0x1b0960*/
        if ( v2[5] == 1 ) /*0x1b0966*/
        {
          if ( a1[77] == v14 ) /*0x1b0977*/
          {
            objc_msgSend(a1, sel__ioOpHandler_, v2 + 7); /*0x1b0988*/
            v7 = 1; /*0x1b098d*/
          }
        }
        else
        {
          v15 = 5120; /*0x1b099c*/
          v3 = (_DWORD *)IOMalloc(0x1400u); /*0x1b09b0*/
          v7 = Event_server(v2, v3); /*0x1b09b7*/
        }
        if ( v7 )
        {
          if ( v2[4] )
          {
            if ( !v3 ) /*0x1b09ec*/
              goto LABEL_30; /*0x1b09ec*/
            if ( v15 < v3[1] )
            {
              v11 = v3[1]; /*0x1b0a04*/
              v8 = (const char *)objc_msgSend(a1, sel_name); /*0x1b0a10*/
              IOLog((int)"%s: reply msg overflow (%d > %d)\n", v8, v11, v15);
            }
            if ( msg_send(v3, 0, 0) )
            {
              v12 = objc_msgSend(a1, sel_name); /*0x1b0a4b*/
              IOLog((int)"%s: error on msg_send (%d)\n", v12);
            }
          }
        }
        else
        {
          v10 = objc_msgSend(a1, sel_name); /*0x1b09da*/
          IOLog((int)"%s: invalid message ID %d\n", v10);
        }
        if ( v3 ) /*0x1b0a5b*/
        {
          IOFree((int)v3, v15); /*0x1b0a65*/
          v3 = nullptr; /*0x1b0a6a*/
          v15 = 0; /*0x1b0a6c*/
        }
LABEL_30:
        if ( v1 > 0x200 ) /*0x1b0a7f*/
        {
          IOFree((int)v2, v1); /*0x1b0a83*/
          v1 = 512; /*0x1b0a88*/
          v2 = v16; /*0x1b0a8d*/
        }
      }
    }
    else if ( v4 == -204 )
    {
      if ( v1 > 0x200 ) /*0x1b08c2*/
        IOFree((int)v2, v1); /*0x1b08c6*/
      v1 = v2[1]; /*0x1b08ce*/
      v2 = (_DWORD *)IOMalloc(v1); /*0x1b08d7*/
    }
    else
    {
LABEL_11:
      v13 = v4; /*0x1b08e4*/
      v5 = (const char *)objc_msgSend(a1, sel_name); /*0x1b08f0*/
      IOLog((int)"%s: error on msg_receive (%d)\n", v5, v13);
    }
  }
}
