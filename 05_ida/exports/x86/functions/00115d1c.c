/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x115d1c. */
int __cdecl sosetopt(int a1, int a2, int a3, int a4)
{
  int v4; // edi
  int v5; // ebx
  int v6; // eax
  int (__cdecl *v7)(int, int, int, int, int *); // edi
  int v9; // eax

  v4 = 0; /*0x115d28*/
  v5 = a4; /*0x115d2a*/
  if ( a2 != 0xFFFF ) /*0x115d34*/
  {
    v6 = *(_DWORD *)(a1 + 12); /*0x115d36*/
    if ( v6 ) /*0x115d3b*/
    {
      v7 = *(int (__cdecl **)(int, int, int, int, int *))(v6 + 24); /*0x115d41*/
      if ( v7 ) /*0x115d46*/
        return v7(1, a1, a2, a3, &a4); /*0x115d5a*/
    }
    goto LABEL_43; /*0x115d46*/
  }
  if ( a3 != 32 ) /*0x115d63*/
  {
    if ( a3 > 32 ) /*0x115d65*/
    {
      if ( a3 != 256 ) /*0x115d8e*/
      {
        if ( a3 > 256 ) /*0x115d90*/
        {
          if ( a3 > 4102 || a3 < 4097 ) /*0x115db6*/
            goto LABEL_43; /*0x115db6*/
          if ( a4 && *(_WORD *)(a4 + 8) > 3u ) /*0x115e0d*/
          {
            switch ( a3 ) /*0x115e2b*/
            {
              case 4097: /*0x115e2b*/
              case 4098: /*0x115e2b*/
                if ( a3 == 4097 ) /*0x115e59*/
                  v9 = a1 + 60; /*0x115e5b*/
                else
                  v9 = a1 + 36; /*0x115e60*/
                if ( !sbreserve(v9, *(_DWORD *)(*(_DWORD *)(a4 + 4) + a4)) ) /*0x115e64*/
                  v4 = 55; /*0x115e70*/
                break; /*0x115e75*/
              case 4099: /*0x115e2b*/
                *(_WORD *)(a1 + 68) = *(_WORD *)(*(_DWORD *)(a4 + 4) + a4); /*0x115e7f*/
                break; /*0x115e83*/
              case 4100: /*0x115e2b*/
                *(_WORD *)(a1 + 44) = *(_WORD *)(*(_DWORD *)(a4 + 4) + a4); /*0x115e8f*/
                break; /*0x115e93*/
              case 4101: /*0x115e2b*/
                *(_WORD *)(a1 + 70) = *(_WORD *)(*(_DWORD *)(a4 + 4) + a4); /*0x115e9f*/
                break; /*0x115ea3*/
              case 4102: /*0x115e2b*/
                *(_WORD *)(a1 + 46) = *(_WORD *)(*(_DWORD *)(a4 + 4) + a4); /*0x115eaf*/
                break; /*0x115eb3*/
            }
            goto LABEL_44; /*0x115eb3*/
          }
          goto LABEL_32; /*0x115e0d*/
        }
        if ( a3 != 64 ) /*0x115d95*/
        {
          if ( a3 != 128 ) /*0x115d9d*/
            goto LABEL_43; /*0x115d9d*/
          if ( !a4 || *(_WORD *)(a4 + 8) != 8 ) /*0x115dc9*/
            goto LABEL_32; /*0x115dc9*/
          *(_WORD *)(a1 + 4) = *(_WORD *)(*(_DWORD *)(a4 + 4) + a4 + 4); /*0x115dd3*/
        }
      }
    }
    else if ( a3 != 4 ) /*0x115d6a*/
    {
      if ( a3 > 4 ) /*0x115d6c*/
      {
        if ( a3 != 8 && a3 != 16 ) /*0x115d80*/
          goto LABEL_43; /*0x115d80*/
      }
      else if ( a3 != 1 ) /*0x115d71*/
      {
LABEL_43:
        v4 = 42; /*0x115eb8*/
        goto LABEL_44; /*0x115eb8*/
      }
    }
  }
  if ( !v5 || *(_WORD *)(v5 + 8) <= 3u ) /*0x115de0*/
  {
LABEL_32:
    v4 = 22; /*0x115e0f*/
    goto LABEL_44; /*0x115e14*/
  }
  if ( *(_DWORD *)(*(_DWORD *)(v5 + 4) + v5) ) /*0x115de5*/
    *(_WORD *)(a1 + 2) |= a3; /*0x115deb*/
  else
    *(_WORD *)(a1 + 2) &= ~(_WORD)a3; /*0x115df9*/
LABEL_44:
  if ( v5 ) /*0x115ebf*/
    m_free(v5); /*0x115ec2*/
  return v4; /*0x115ecc*/
}
