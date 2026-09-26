/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x121a3c. */
int __cdecl rtalloc(int *a1)
{
  void *v1; // edi
  int result; // eax
  _DWORD *v3; // esi
  char *v4; // ebx
  _DWORD *v5; // [esp+Ch] [ebp-20h]
  unsigned int v6; // [esp+10h] [ebp-1Ch]
  int v7; // [esp+14h] [ebp-18h]
  int v8; // [esp+18h] [ebp-14h]
  int (*v9)(); // [esp+1Ch] [ebp-10h]
  int v10; // [esp+20h] [ebp-Ch]
  _DWORD v11[2]; // [esp+24h] [ebp-8h] BYREF

  v1 = a1 + 1; /*0x121a48*/
  v6 = *((unsigned __int16 *)a1 + 2); /*0x121a52*/
  result = *a1; /*0x121a58*/
  if ( (!*a1 || !*(_DWORD *)(result + 44) || (*(_BYTE *)(result + 36) & 1) == 0) && v6 <= 0x10 ) /*0x121a72*/
  {
    (*(&afswitch + 2 * v6))((int)(a1 + 1), (int)v11); /*0x121a8d*/
    v9 = off_1DB794[2 * v6]; /*0x121a95*/
    v10 = v11[0]; /*0x121a9b*/
    v5 = &rthost; /*0x121a9e*/
    v8 = 1; /*0x121aa5*/
    v7 = splnet(); /*0x121ab1*/
    while ( 1 ) /*0x121ac0*/
    {
      v3 = (_DWORD *)v5[v10 & 7]; /*0x121ac0*/
      if ( v3 ) /*0x121ac5*/
        break; /*0x121ac5*/
LABEL_19:
      if ( v8 ) /*0x121b4a*/
      {
        v8 = 0; /*0x121b4c*/
        v10 = v11[1]; /*0x121b56*/
        v5 = &rtnet; /*0x121b59*/
      }
      else
      {
        if ( v1 == &wildcard ) /*0x121b6e*/
        {
          result = splx(v7); /*0x121b88*/
          ++word_1E98B6; /*0x121b8d*/
          return result; /*0x121b8d*/
        }
        v1 = &wildcard; /*0x121b70*/
        v10 = 0; /*0x121b75*/
      }
    }
    while ( 1 ) /*0x121aca*/
    {
      v4 = (char *)v3 + v3[1]; /*0x121aca*/
      if ( *(_DWORD *)v4 == v10 && (v4[36] & 1) != 0 && (*(_BYTE *)(*((_DWORD *)v4 + 11) + 12) & 1) != 0 ) /*0x121ae1*/
      {
        if ( v8 ) /*0x121ae7*/
        {
          if ( !bcmp(v4 + 4, v1, 0x10u) ) /*0x121b0f*/
            goto LABEL_15; /*0x121b19*/
        }
        else if ( v6 == *((unsigned __int16 *)v4 + 2) && ((int (__cdecl *)(char *, void *))v9)(v4 + 4, v1) ) /*0x121afa*/
        {
LABEL_15:
          ++*((_WORD *)v4 + 19); /*0x121b1b*/
          result = splx(v7); /*0x121b23*/
          if ( v1 == &wildcard ) /*0x121b2e*/
            ++word_1E98B8; /*0x121b30*/
          *a1 = (int)v4; /*0x121b3a*/
          return result; /*0x121b3c*/
        }
      }
      v3 = (_DWORD *)*v3; /*0x121b40*/
      if ( !v3 ) /*0x121b44*/
        goto LABEL_19; /*0x121b44*/
    }
  }
  return result; /*0x121b97*/
}
