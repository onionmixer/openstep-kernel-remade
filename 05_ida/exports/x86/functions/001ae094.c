/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1ae094. */
id __cdecl sub_1AE094(id *a1, char a2)
{
  char *v2; // ecx
  id *v3; // eax
  id result; // eax
  char *v5; // ebx
  char *v6; // esi
  char *v7; // eax
  _DWORD *v8; // eax
  char *v9; // ebx
  int v10; // esi
  char *v11; // ecx
  char *v12; // eax
  char **v13; // eax
  int v14; // eax
  int v15; // [esp+Ch] [ebp-Ch]
  id *v16; // [esp+10h] [ebp-8h]

  if ( a2 ) /*0x1ae0a8*/
    v2 = (char *)(a1 + 106); /*0x1ae0aa*/
  else
    v2 = (char *)(a1 + 108); /*0x1ae0b4*/
  v3 = *(id **)v2; /*0x1ae0ba*/
  if ( v2 == *(char **)v2 )
    return (id)IOLog((int)"sdThreadDequeue: Empty queue!\n");
  v16 = *(id **)v2; /*0x1ae0d0*/
  v5 = (char *)v3[11]; /*0x1ae0d3*/
  v6 = (char *)v3[12]; /*0x1ae0d6*/
  v7 = v2; /*0x1ae0d9*/
  if ( v2 != v5 ) /*0x1ae0dd*/
    v7 = v5 + 44; /*0x1ae0df*/
  *((_DWORD *)v7 + 1) = v6; /*0x1ae0e2*/
  v8 = v2; /*0x1ae0e5*/
  if ( v2 != v6 ) /*0x1ae0e9*/
    v8 = v6 + 44; /*0x1ae0eb*/
  *v8 = v5; /*0x1ae0ee*/
  if ( a2 ) /*0x1ae0f4*/
  {
    objc_msgSend(a1[112], sel_lock); /*0x1ae104*/
    a1[113] = (char *)a1[113] + 1; /*0x1ae109*/
    if ( *v16 == (id)4 ) /*0x1ae118*/
    {
      *((_BYTE *)a1 + 456) = 1; /*0x1ae11a*/
      volCheckEjecting((int)a1, 2); /*0x1ae124*/
    }
    objc_msgSend(a1[112], sel_unlockWith_, a1[113]); /*0x1ae141*/
  }
  result = *v16; /*0x1ae14c*/
  switch ( (unsigned int)*v16 ) /*0x1ae157*/
  {
    case 0u: /*0x1ae157*/
    case 1u: /*0x1ae157*/
    case 2u: /*0x1ae157*/
    case 3u: /*0x1ae157*/
      objc_msgSend(a1[110], sel_unlock); /*0x1ae2a2*/
      objc_msgSend(a1, sel_doSdBuf_, v16); /*0x1ae2b3*/
      result = objc_msgSend(a1[110], sel_lock); /*0x1ae2c6*/
      break; /*0x1ae2ce*/
    case 4u: /*0x1ae157*/
      objc_msgSend(a1[110], sel_unlock); /*0x1ae23a*/
      objc_msgSend(a1[112], sel_lockWhen_, 1); /*0x1ae24f*/
      objc_msgSend(a1[112], sel_unlock); /*0x1ae262*/
      objc_msgSend(a1, sel_doSdBuf_, v16); /*0x1ae273*/
      result = objc_msgSend(a1[110], sel_lock); /*0x1ae289*/
      break; /*0x1ae291*/
    case 5u: /*0x1ae157*/
      v9 = (char *)(a1 + 106); /*0x1ae180*/
      if ( a1[106] != a1 + 106 ) /*0x1ae18c*/
      {
        do /*0x1ae209*/
        {
          v10 = *(_DWORD *)v9; /*0x1ae190*/
          v11 = *(char **)(*(_DWORD *)v9 + 44); /*0x1ae192*/
          v15 = *(_DWORD *)(*(_DWORD *)v9 + 48); /*0x1ae198*/
          v12 = (char *)(a1 + 106); /*0x1ae19b*/
          if ( v9 != v11 ) /*0x1ae19f*/
            v12 = v11 + 44; /*0x1ae1a1*/
          *((_DWORD *)v12 + 1) = v15; /*0x1ae1a7*/
          v13 = (char **)(a1 + 106); /*0x1ae1aa*/
          if ( v9 != (char *)v15 ) /*0x1ae1ae*/
            v13 = (char **)(v15 + 44); /*0x1ae1b3*/
          *v13 = v11; /*0x1ae1b6*/
          objc_msgSend(a1[110], sel_unlock); /*0x1ae1c6*/
          *(_DWORD *)(v10 + 40) = -1102; /*0x1ae1cb*/
          v14 = *(_DWORD *)(v10 + 20); /*0x1ae1d5*/
          if ( v14 ) /*0x1ae1da*/
            *(_DWORD *)(v14 + 28) = 16; /*0x1ae1dc*/
          objc_msgSend(a1, sel_sdIoComplete_, v10); /*0x1ae1ec*/
          objc_msgSend(a1[110], sel_lock); /*0x1ae1ff*/
        }
        while ( *(char **)v9 != v9 ); /*0x1ae209*/
      }
      goto LABEL_23; /*0x1ae209*/
    case 6u: /*0x1ae157*/
LABEL_23:
      v16[10] = nullptr; /*0x1ae20b*/
      result = objc_msgSend(a1, sel_sdIoComplete_, v16); /*0x1ae21e*/
      break; /*0x1ae226*/
    case 7u: /*0x1ae157*/
      objc_msgSend(a1[110], sel_unlock); /*0x1ae2de*/
      v16[10] = nullptr; /*0x1ae2e6*/
      objc_msgSend(a1, sel_sdIoComplete_, v16); /*0x1ae2f6*/
      result = (id)IOExitThread(); /*0x1ae2fb*/
      break; /*0x1ae2fb*/
    default:
      break;
  }
  if ( a2 ) /*0x1ae307*/
  {
    objc_msgSend(a1[112], sel_lock); /*0x1ae317*/
    a1[113] = (char *)a1[113] - 1; /*0x1ae31c*/
    return objc_msgSend(a1[112], sel_unlockWith_, a1[113]); /*0x1ae337*/
  }
  return result; /*0x1ae33f*/
}
