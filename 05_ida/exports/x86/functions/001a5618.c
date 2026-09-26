/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a5618. */
void __cdecl _IOCopyMemory(unsigned int a1, char *a2, signed int a3, unsigned int a4)
{
  unsigned int v4; // ebx
  int v5; // edx
  int v6; // ecx
  char *v7; // edi
  _WORD *v8; // esi
  int v9; // edx
  int v10; // eax
  char *v11; // [esp+14h] [ebp+8h]
  char *v12; // [esp+18h] [ebp+Ch]

  v4 = a4; /*0x1a561e*/
  if ( a1 && a2 && (char *)a1 != a2 && a3 ) /*0x1a5645*/
  {
    if ( !a4 ) /*0x1a564d*/
      v4 = 1; /*0x1a564f*/
    if ( v4 > 2 ) /*0x1a5657*/
      v4 = 4; /*0x1a5659*/
    if ( v4 == 1 ) /*0x1a5661*/
    {
      qmemcpy(a2, (const void *)a1, a3); /*0x1a566c*/
      return; /*0x1a566c*/
    }
    v5 = (v4 - 1) & a1; /*0x1a567a*/
    if ( v5 ) /*0x1a567c*/
    {
      qmemcpy(a2, (const void *)a1, v4 - v5); /*0x1a568a*/
      a3 -= v4 - v5; /*0x1a568c*/
      a2 += v4 - v5; /*0x1a568f*/
      a1 += v4 - v5; /*0x1a5692*/
    }
    if ( v4 == 2 ) /*0x1a5698*/
    {
      v6 = a3 >> 1; /*0x1a569f*/
      v7 = a2; /*0x1a56a1*/
      v8 = (_WORD *)a1; /*0x1a56a4*/
      while ( v6 ) /*0x1a56a7*/
      {
        *(_WORD *)v7 = *v8++; /*0x1a56a7*/
        v7 += 2; /*0x1a56a7*/
        --v6; /*0x1a56a7*/
      }
    }
    else
    {
      qmemcpy(a2, (const void *)a1, 4 * (a3 >> 2)); /*0x1a56ba*/
    }
    v9 = (v4 - 1) & a3; /*0x1a56c2*/
    if ( v9 ) /*0x1a56c4*/
    {
      v10 = a3 & ~(v4 - 1); /*0x1a56c8*/
      v11 = (char *)(v10 + a1); /*0x1a56cb*/
      v12 = &a2[v10]; /*0x1a56ce*/
      if ( v9 != 2 ) /*0x1a56d4*/
      {
        if ( v9 <= 2 ) /*0x1a56d6*/
        {
          if ( v9 != 1 ) /*0x1a56db*/
            return; /*0x1a56db*/
LABEL_27:
          *v12 = *v11; /*0x1a56fd*/
          return; /*0x1a5705*/
        }
        if ( v9 != 3 ) /*0x1a56e3*/
          return; /*0x1a56e3*/
        v12[2] = v11[2]; /*0x1a56ee*/
      }
      v12[1] = v11[1]; /*0x1a56fa*/
      goto LABEL_27; /*0x1a56fa*/
    }
  }
}
