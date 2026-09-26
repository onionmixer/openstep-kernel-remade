/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x18ae2c. */
int __cdecl getargs(char *__s1)
{
  char *v1; // edi
  char *v3; // ebx
  char v4; // al
  char *i; // ebx
  const char **v6; // esi
  _DWORD *v7; // edx
  int v8; // eax
  _DWORD *v9; // edx
  int v10; // eax
  int v11; // eax
  char v12; // [esp-4h] [ebp-1Ch]
  _DWORD *v13; // [esp+Ch] [ebp-Ch]
  _DWORD *v14; // [esp+Ch] [ebp-Ch]
  char v15; // [esp+10h] [ebp-8h]
  int v16; // [esp+14h] [ebp-4h] BYREF

  v1 = __s1; /*0x18ae35*/
  strncpy(boot_file, (const char *)0x110B8, 0x40u); /*0x18ae44*/
  if ( !*__s1 ) /*0x18ae4c*/
    return 1; /*0x18ae51*/
  while ( isargsep(*v1) ) /*0x18ae6a*/
    ++v1; /*0x18ae70*/
  while ( *v1 ) /*0x18b00e*/
  {
    if ( *v1 == 45 ) /*0x18ae77*/
    {
      v3 = init_args; /*0x18ae7d*/
      argstrcpy(v1, init_args); /*0x18ae88*/
      do /*0x18aef3*/
      {
        v4 = *v3; /*0x18ae90*/
        if ( *v3 == 100 ) /*0x18ae94*/
        {
          LOBYTE(boothowto) = boothowto | 4; /*0x18aec4*/
        }
        else if ( *v3 > 100 ) /*0x18ae96*/
        {
          if ( v4 == 102 ) /*0x18aea2*/
          {
            boothowto |= 0x200000u; /*0x18aed0*/
          }
          else if ( v4 == 115 ) /*0x18aea6*/
          {
            LOBYTE(boothowto) = boothowto | 2; /*0x18aeb8*/
          }
        }
        else if ( v4 == 97 ) /*0x18ae9a*/
        {
          LOBYTE(boothowto) = boothowto | 1; /*0x18aeac*/
        }
        if ( !*v3 ) /*0x18aeda*/
          break; /*0x18aede*/
        v12 = *v3++; /*0x18aee7*/
      }
      while ( !isargsep(v12) ); /*0x18aef3*/
    }
    else
    {
      for ( i = v1; !isargsep(*i); ++i ) /*0x18af04*/
      {
        if ( *i == 61 ) /*0x18af1b*/
          goto LABEL_27; /*0x18af1b*/
      }
      if ( *i != 61 ) /*0x18af23*/
        goto LABEL_40; /*0x18af23*/
LABEL_27:
      v15 = *i; /*0x18af29*/
      v6 = (const char **)&kernargs; /*0x18af2e*/
      if ( kernargs ) /*0x18af3a*/
      {
        v7 = &unk_1E19B8; /*0x18af40*/
        while ( 1 ) /*0x18af51*/
        {
          v13 = v7; /*0x18af51*/
          v8 = strncmp(v1, *v6, i - v1); /*0x18af54*/
          v9 = v13; /*0x18af5c*/
          if ( !v8 ) /*0x18af61*/
            break; /*0x18af61*/
          v7 = v13 + 2; /*0x18afcc*/
          v6 += 2; /*0x18afcf*/
          if ( !*v6 ) /*0x18afd2*/
            goto LABEL_40; /*0x18afd5*/
        }
        while ( 1 ) /*0x18af68*/
        {
          v14 = v9; /*0x18af68*/
          v10 = isargsep(*i); /*0x18af6b*/
          v9 = v14; /*0x18af73*/
          if ( !v10 ) /*0x18af78*/
            break; /*0x18af78*/
          ++i; /*0x18af7a*/
        }
        if ( *i == 61 && v15 != 61 ) /*0x18af89*/
        {
          v1 = i + 1; /*0x18aefc*/
        }
        else
        {
          v11 = getval(i, &v16); /*0x18af97*/
          if ( v11 ) /*0x18afa4*/
          {
            if ( v11 == 1 ) /*0x18afa9*/
              argstrcpy(i + 1, *v14); /*0x18afc1*/
          }
          else
          {
            *(_DWORD *)*v14 = v16; /*0x18afb5*/
          }
        }
      }
    }
LABEL_40:
    while ( !isargsep(*v1) ) /*0x18afea*/
      ++v1; /*0x18afec*/
    if ( !*v1 ) /*0x18aff0*/
      break; /*0x18aff0*/
    do /*0x18b009*/
    {
      if ( !isargsep(*v1) ) /*0x18affc*/
        break; /*0x18b006*/
      ++v1; /*0x18b008*/
    }
    while ( *v1 ); /*0x18b009*/
  }
  return 0; /*0x18b01c*/
}
