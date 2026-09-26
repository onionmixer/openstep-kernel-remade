/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x11d558. */
off_t __cdecl lseek(int a1, off_t a2, int a3)
{
  _DWORD *v3; // ebx
  char v4; // dl
  off_t result; // rax
  int v6; // ecx
  int v7; // eax
  char v8; // dl
  _BYTE v9[24]; // [esp+Ch] [ebp-44h] BYREF
  int v10; // [esp+24h] [ebp-2Ch]
  int v11; // [esp+4Ch] [ebp-4h] BYREF

  v3 = *(_DWORD **)(dword_1E875C + 36); /*0x11d566*/
  v4 = getvnodefp(*v3, &v11); /*0x11d575*/
  LODWORD(result) = dword_1E875C; /*0x11d577*/
  *(_BYTE *)(dword_1E875C + 104) = v4; /*0x11d57c*/
  HIDWORD(result) = dword_1E875C; /*0x11d57f*/
  LOBYTE(result) = *(_BYTE *)(dword_1E875C + 104); /*0x11d588*/
  if ( (_BYTE)result ) /*0x11d58d*/
  {
    if ( (_BYTE)result != 22 ) /*0x11d591*/
      return result; /*0x11d591*/
    goto LABEL_3; /*0x11d591*/
  }
  v6 = *(_DWORD *)(v11 + 24); /*0x11d5a3*/
  if ( *(_DWORD *)(v6 + 40) == 8 ) /*0x11d5aa*/
  {
LABEL_3:
    *(_BYTE *)(dword_1E875C + 104) = 29; /*0x11d597*/
    return result; /*0x11d59b*/
  }
  v7 = v3[2]; /*0x11d5ac*/
  if ( v7 == 1 ) /*0x11d5b2*/
  {
    if ( (*(_BYTE *)(*(_DWORD *)active_u + 22) & 2) != 0 ) /*0x11d5db*/
    {
      LODWORD(result) = v3[1] + *(_DWORD *)(v11 + 28); /*0x11d5e0*/
      if ( (int)result < 0 ) /*0x11d5e3*/
        goto LABEL_20; /*0x11d5e3*/
    }
    *(_DWORD *)(v11 + 28) += v3[1]; /*0x11d5eb*/
  }
  else if ( v7 > 1 ) /*0x11d5b4*/
  {
    if ( v7 != 2 ) /*0x11d5c7*/
      goto LABEL_22; /*0x11d5c7*/
    v8 = (*(int (__stdcall **)(int, _BYTE *, _DWORD))(*(_DWORD *)(v6 + 28) + 20))(v6, v9, *(_DWORD *)(active_u + 28)); /*0x11d60a*/
    LODWORD(result) = dword_1E875C; /*0x11d60c*/
    *(_BYTE *)(dword_1E875C + 104) = v8; /*0x11d611*/
    HIDWORD(result) = dword_1E875C; /*0x11d614*/
    if ( *(_BYTE *)(dword_1E875C + 104) ) /*0x11d61a*/
      return result; /*0x11d61e*/
    if ( (*(_BYTE *)(*(_DWORD *)active_u + 22) & 2) != 0 ) /*0x11d62b*/
    {
      LODWORD(result) = v10 + v3[1]; /*0x11d630*/
      if ( (int)result < 0 ) /*0x11d633*/
        goto LABEL_20; /*0x11d633*/
    }
    *(_DWORD *)(v11 + 28) = v10 + v3[1]; /*0x11d63e*/
  }
  else
  {
    if ( v7 ) /*0x11d5b8*/
    {
LABEL_22:
      *(_BYTE *)(dword_1E875C + 104) = 22; /*0x11d66c*/
      goto LABEL_23; /*0x11d671*/
    }
    LODWORD(result) = *(_DWORD *)active_u; /*0x11d649*/
    if ( (*(_BYTE *)(*(_DWORD *)active_u + 22) & 2) != 0 && (int)v3[1] < 0 ) /*0x11d655*/
    {
LABEL_20:
      *(_BYTE *)(HIDWORD(result) + 104) = 22; /*0x11d657*/
      return result; /*0x11d65b*/
    }
    *(_DWORD *)(v11 + 28) = v3[1]; /*0x11d666*/
  }
LABEL_23:
  HIDWORD(result) = dword_1E875C; /*0x11d675*/
  LODWORD(result) = *(_DWORD *)(v11 + 28); /*0x11d67e*/
  *(_DWORD *)(dword_1E875C + 96) = result; /*0x11d681*/
  return result; /*0x11d687*/
}
